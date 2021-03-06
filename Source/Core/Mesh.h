#ifndef __k3dMesh_h__
#define __k3dMesh_h__
#pragma once

#include <Math/kMath.hpp>
#include <Math/kGeometry.hpp>
#include <Interface/IReflectable.h>
#include <sstream>

namespace kMath {
	typedef tVectorN<float, 2> Vec2f;
	typedef tVectorN<float, 3> Vec3f;
	typedef tVectorN<float, 4> Vec4f;
}

namespace k3d {

	enum MVersion {
		VERSION_1_0 = 201402u,
		VERSION_1_1 = 201501u
	};
	
	/**
	*  Mesh Header <<POD>>
	*/
	struct MeshHeader {
		MVersion     Version;
	};
	
	struct KALIGN(4) Vertex4F
	{
		float PosX, PosY, PosZ, PosW;
	};

	struct KALIGN(4) Vertex3F
	{
		float PosX, PosY, PosZ;
	};

	struct KALIGN(4) Vertex3F3F
	{
		float PosX, PosY, PosZ;
		float NorX, NorY, NorZ;
	};

	struct KALIGN(4) Vertex3F2F
	{
		float PosX, PosY, PosZ;
		float U, V;
	};

	struct KALIGN(4) Vertex3F3F2F
	{
		float PosX, PosY, PosZ;
		float NorX, NorY, NorZ;
		float U, V;
	};

	struct KALIGN(4) Normal3F
	{
		float x, y, z;
	};

	struct KALIGN(4) TexCoord2F
	{
		float u, v;
	};

	enum class VtxFormat : uint32 {
		POS3_F32 = 0,
		POS4_F32,
		POS3_F32_UV2_F32,
		POS3_F32_NOR3_F32,
		POS3_F32_NOR3_F32_UV2_F32,
		POS3_F32_NOR3_F32_UV2X2_F32,
		POS3_F32_NOR3_F32_UV2X3_F32,
		PER_INSTANCE // all components are seperated
	};

	enum class PrimType : uint32 {
		POINTS = 0,
		TRIANGLES,
		TRIANGLE_STRIPS
	};

	class Mesh : public IReflectable {
	public:

		Mesh();
		~Mesh();

		void    Release();

		void    SetMeshName(const char* meshName);
		void    SetBBox(float maxCorner[3], float minCorner[3]) {
				m_MaxCorner.init(maxCorner);
				m_MinCorner.init(minCorner);
		}
		void	SetMaterialID(uint32 matID) { m_MaterialID = matID; }

		const char * MeshName() const {	return m_MeshName; }
		bool		IsLoaded() const { return m_IsLoaded; }

		kMath::AABB GetBoundingBox() const { return kMath::AABB(m_MaxCorner, m_MinCorner); }
		uint32		GetMaterialID() const { return m_MaterialID; }
		
		int			GetIndexNum() const	{ return m_NumIndices; }
		uint32*		GetIndexBuffer() const { return m_IndexData; }
		void		SetIndexBuffer(std::vector<uint32> & indexBuffer);

		PrimType	GetPrimType() const { return m_PrimType; }
		void		SetPrimType(PrimType const & type) { m_PrimType = type; }

		int			GetVertexNum() const { return m_NumVertices; }
		VtxFormat	GetVertexFormat() const { return m_VtxFmt; }
		void		SetVertexFormat(VtxFormat const & fmt) { m_VtxFmt = fmt; }

		float *		GetVertexBuffer() const { return (float*)&m_P3Buffer[0]; }
		void		SetVertexBuffer(void* dataPtr);
		void		SetVertexNum(int num) { m_NumVertices = num; }

		Mesh *		Reflect() override { return new Mesh; }

		std::string DumpMeshInfo() 
		{
			std::ostringstream meshInfo;
			meshInfo << "[Mesh]\n"
				<< "\tName:" << this->MeshName()
				<< "\n\tFormat:" << VtxFormatToString(this->GetVertexFormat())
				<< "\n\tPrimitiveType:" << PrimTypeToString(this->GetPrimType())
				<< "\n\tNumVertices:" << this->GetVertexNum()
				<< "\n\tNumIndices:" << this->GetIndexNum()
				<< "\n";
			return meshInfo.str();
		}

		KOBJECT_CLASSNAME(Mesh)

		friend class AssetManager;

		friend class Archive& operator << (class Archive & arch, const Mesh & mesh);
		friend class Archive& operator >> (class Archive & arch, Mesh & mesh);

	public:

		static uint32	GetVertexByteWidth(VtxFormat format, uint32 vertexNum)
		{
			static uint32 elementByteWidth[] = {
				sizeof(Vertex3F),
				sizeof(Vertex4F),
				sizeof(Vertex3F2F),
				sizeof(Vertex3F3F),
				sizeof(Vertex3F3F2F)
			};
			if (format > VtxFormat::POS3_F32_NOR3_F32_UV2_F32)
				return 0;
			return elementByteWidth[(uint32)format] * vertexNum;
		}

		static uint32	GetVertexStride(VtxFormat format)
		{
			static uint32 elementByteStride[] = {
				sizeof(Vertex3F),
				sizeof(Vertex4F),
				sizeof(Vertex3F2F),
				sizeof(Vertex3F3F),
				sizeof(Vertex3F3F2F)
			};
			if (format > VtxFormat::POS3_F32_NOR3_F32_UV2_F32)
				return 0;
			return elementByteStride[(uint32)format];
		}

		static std::string VtxFormatToString(VtxFormat format)
		{
			static std::string vtxFormatStr[] = {
				"Vertex3F",
				"Vertex4F",
				"Vertex3F2F",
				"Vertex3F3F",
				"Vertex3F3F2F"
			};
			if (format > VtxFormat::POS3_F32_NOR3_F32_UV2_F32)
				return "Unknown";
			return vtxFormatStr[(uint32)format];
		}

		static std::string PrimTypeToString(PrimType primType)
		{
			static std::string primTypeStr[] = {
				"POINTS",
				"TRIANGLES",
				"TRIANGLE_STRIPS"
			};
			return primTypeStr[(uint32)primType];
		}

	private:
		Mesh(const Mesh &) = delete;
		Mesh& operator = (const Mesh &) = delete;

		bool                m_IsLoaded;
		char                m_MeshName[96];
				
		// IndexBuffer
		PrimType				m_PrimType;
		uint32					m_NumIndices;
		uint32*					m_IndexData;

		// VertexBuffer
		VtxFormat				m_VtxFmt;
		uint32					m_NumVertices;
		union {
			Vertex3F3F2F*		m_P3N3T2Buffer;
			Vertex3F3F*			m_P3N3Buffer;
			Vertex3F*			m_P3Buffer;
			Vertex4F*			m_P4Buffer;
		};

		uint32			m_MaterialID;
		kMath::Vec3f	m_MaxCorner;
		kMath::Vec3f	m_MinCorner;
	};

	typedef std::shared_ptr<Mesh> SpMesh;
}

#endif
