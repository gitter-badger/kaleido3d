#include "Kaleido3D.h"
#include "AssetManager.h"
#include <Core/File.h>
#include <Core/LogUtil.h>
#include <Core/Image.h>
#include <Core/Variant.h>

#include <fstream>
#include <algorithm>

#if K3DPLATFORM_OS_WIN
#include <strsafe.h>
#endif

namespace k3d {

	std::string AssetManager::s_envAssetPath;

	AssetManager::AssetManager() : m_pThreadPool(nullptr)
	{
		m_IsLoading = false;
		m_HasPendingObject = false;
		m_NumPendingObject.store(0, std::memory_order_release);
	}

	void AssetManager::Init()
	{
		if (m_pThreadPool == nullptr)
			m_pThreadPool = new std::thread_pool(2);

		LOG_MESSAGE("AssetManager Initialized With two workers.");

#if K3DPLATFORM_OS_WIN
		char _path[2048] = { 0 };
		DWORD _len = GetEnvironmentVariableA("Kaleido3D_Dir", _path, 2048);
		if (_len > 0) {
			Log::Message("Kaleido3D_Dir Found. \"%s\"", _path);
			s_envAssetPath = _path;
			m_SearchPaths.push_back(_path);
		}
		else {
			Log::Error("Kaleido3D_Dir Not Found.");
		}
#endif
		//m_SearchPaths
	}

	void AssetManager::Shutdown()
	{
		if (m_pThreadPool)
		{
			delete m_pThreadPool;
			m_pThreadPool = nullptr;
		}
		LOG_MESSAGE("AssetManager Shutdown.");
	}

	void AssetManager::LoadAssetDescFile(const char *fileName)
	{
		std::ifstream ifs(fileName);
		if (!ifs.good())
		{
			Log::Fatal("AssetManager::LoadAssetDescFile failed. Cannot find file %s.", fileName);
			return;
		}
		ifs.close();
	}

	void AssetManager::AddSearchPath(const char *path)
	{
		typedef std::vector<string>::const_iterator VSCIter;
		VSCIter pos = std::find(m_SearchPaths.begin(), m_SearchPaths.end(), string(path));
		if (pos == m_SearchPaths.end())
		{
			m_SearchPaths.push_back(string(path));
		}
	}

	void AssetManager::CommitAsynResourceTask(
		const char *fileName,
		BytesPackage &bp,
		std::semaphore &sp,
		std::function<void()> callback)
	{
		auto result = m_pThreadPool->enqueue(
			[&bp, &sp](const char *name, std::function<void()> _callback)
		{
			//    ++m_NumPendingObject;
			MemMapFile file;
			bool opened = file.Open(name, IORead);
			assert(opened == true);
			if (opened)
			{
				int64 bytes_length = file.GetSize();
				bp.Bytes.assign(bytes_length + 1, '\0');
				//bp.Bytes.assign()
				file.Read((char*)&bp.Bytes[0], bytes_length);
				file.Close();

				_callback();
			}
			else
			{
				Log::Error("AssetManager::CommitAsynResourceTask failed. Cannot find file %s.", name);
			}
			sp.notify();

			//    --m_NumPendingObject;
		},
			fileName,
			callback
			);
	}

	void AssetManager::CommitAsynResourceTask(const char *fileName, BytesPackage &bp, std::semaphore &sp)
	{
		auto result = m_pThreadPool->enqueue(
			[&bp, &sp](const char *name)
		{
			//    ++m_NumPendingObject;
			MemMapFile file;
			bool opened = file.Open(name, IORead);
			if (opened)
			{
				int bytes_length = (int)file.GetSize();
				bp.Bytes.reserve(bytes_length);
				file.Read((char*)&bp.Bytes[0], bytes_length);
				file.Close();
			}
			else
			{
				Log::Error("AssetManager::CommitSynResourceTask failed. Cannot find file %s.", name);
			}
			sp.notify();
			//    --m_NumPendingObject;
		},
			fileName
			);
	}

	void AssetManager::CommitAsynResourceTask(const char *fileName, BytesPackage &bp, std::atomic<bool> &finished)
	{
		auto result = m_pThreadPool->enqueue(
			[&bp, &finished](const char *name)
		{
			//    ++m_NumPendingObject;
			MemMapFile file;
			bool opened = file.Open(name, IORead);
			if (opened)
			{
				int bytes_length = (int)file.GetSize();
				bp.Bytes.reserve(bytes_length);
				file.Read((char*)&bp.Bytes[0], bytes_length);
				file.Close();
			}
			else
			{
				Log::Error("AssetManager::CommitSynResourceTask failed. Cannot find file %s.", name);
			}
			finished.store(true, std::memory_order_release);

			//    --m_NumPendingObject;
		},
			fileName
			);
	}

	void AssetManager::CommitSynResourceTask(const char *fileName, BytesPackage &bp)
	{
		File file;
		if (file.Open(fileName, IORead))
		{
			int64 length = file.GetSize();
			bp.Bytes.resize(length);
			int64 __read = file.Read((char*)&bp.Bytes[0], length);
			assert(__read == length);
			file.Close();
		}
	}

	void AssetManager::AppendMesh(SpMesh meshPtr)
	{
		Debug::Out("AssetManager","Mesh (%s) Appended.", meshPtr->MeshName());
		Debug::Out("AssetManager", meshPtr->DumpMeshInfo());
		m_MeshMap[meshPtr->MeshName()] = meshPtr;
	}

	void AssetManager::Free(char *byte_ptr)
	{
		::free(byte_ptr);
	}

	std::shared_ptr<Mesh> AssetManager::FindMesh(const char *meshName)
	{
		MapMeshIter iter = m_MeshMap.find(string(meshName));
		if (iter == m_MeshMap.end())
			return std::shared_ptr<Mesh>();
		return (iter->second);
	}

	std::shared_ptr<Image> AssetManager::FindImage(const char *imgName)
	{
		MapImageIter iter = m_ImageMap.find(string(imgName));
		if (iter == m_ImageMap.end())
			return std::shared_ptr<Image>();
		return (iter->second);
	}


	AssetManager::SpIODevice  AssetManager::OpenAsset(const char *assetPath, IOFlag flag, bool fastMode)
	{
		std::string rawPath = AssetPath(assetPath);
		SpIODevice fileObj = nullptr;
		if (fastMode) 
		{
			fileObj = SpIODevice(new MemMapFile);
		}
		else 
		{
			fileObj = SpIODevice(new File);
		}
		
		if(fileObj->Open(rawPath.c_str(), flag))
			return fileObj;
		Debug::Out("AssetManager","Cann't find file (%s).", rawPath.c_str());
		fileObj->Close();
		return nullptr;
	}

	std::string AssetManager::AssetPath(const char * assetRelativePath)
	{
		if(s_envAssetPath.empty()) {
			Log::Error("Kaleido3D_Dir Not Found.");
			return "";
		}
		return s_envAssetPath + assetRelativePath;
	}
}