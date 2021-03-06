#pragma once 
#include "DXCommon.h"
#include "Interface/IRunnable.h"
#include "Infrastructure/Shader.h"

namespace k3d
{
  namespace d3d12
  {
    class ShaderCompileWorker : public IRunnable
    {
    public:
      ShaderCompileWorker(const char * File, const char * Level, const char * entryPoint)
        : mShaderFilePath(File)
        , mShaderModel(Level)
        , mShaderEntryPoint(entryPoint)
      {
      }

      void OnRun () override;
    protected:
      void CompileFromFile (D3D_SHADER_MACRO * macro, ID3DInclude * include);

    private:
      std::string mShaderFilePath;
      std::string mShaderEntryPoint;
      std::string mShaderModel;
      PtrBlob mShaderByteCode;
    };
  }
}