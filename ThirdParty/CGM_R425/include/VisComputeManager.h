#ifndef VISCOMPUTEMANAGER_H_
#define VISCOMPUTEMANAGER_H_

#include "CATVisFoundation.h"
#include "VisGPGPUEncapsulation.h"
#include "CATSysErrorDef.h"
#include "VisComputeProgram.h"
#include "VisSparseTexture.h"
#include "IVisTextureFormat.h"
#include "CATDataType.h"
#include <vector>
#include <string>
#include <memory>
#include <variant>
#include <cstdlib>
#include <functional>


class VisComputeResourceManager;
class IVisTexture;
class IVisTexturePtr;
class CATPixelImage;

struct IVisTextureUpdateData;

class ExportedByCATVisFoundation VisComputeManager
{

public :

  static VisComputeManager * GetInstance();

  // appelé par le VisComputeProgram pour passer l'effet au pass system
  // vDSFXEffect* GetEffect(VisProgramHandle ihandle);

  // set de parametres
  /** @deprecated */
#ifdef PREPARECONTEXT_MIGRATION
  virtual HRESULT SetProgramParameter(const VisProgramHandle &iProgram, const char* iName, float value) const = 0;
  virtual HRESULT SetProgramParameter(const VisProgramHandle &iProgram, const char* iName, float r, float g, float b, float a) const = 0;
  virtual HRESULT SetProgramParameter(const VisProgramHandle &iProgram, const char* iName, float r, float g, float b) const = 0;
  virtual HRESULT SetProgramParameter(const VisProgramHandle &iProgram, const char* iName, float r, float g) const = 0;
  virtual HRESULT SetProgramParameter(const VisProgramHandle &iProgram, const char* iName, float* data) const = 0;
#endif

  virtual HRESULT SetProgramParameter(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, float value) const = 0;
  virtual HRESULT SetProgramParameter(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, float r, float g, float b, float a) const = 0;
  virtual HRESULT SetProgramParameter(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, float r, float g, float b) const = 0;
  virtual HRESULT SetProgramParameter(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, float r, float g) const = 0;
  virtual HRESULT SetProgramParameter(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, float* data) const = 0;


#ifdef PREPARECONTEXT_MIGRATION
  virtual HRESULT SetProgramTexture(const VisProgramHandle &iProgram, const char* iName, IVisTexturePtr &value) const = 0;
  virtual HRESULT SetProgramTexture(const VisProgramHandle &iProgram, const char* iName, const char* val, int forceReload) const = 0;
#endif

  virtual HRESULT SetProgramTexture(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, IVisTexturePtr value) const = 0;
  virtual HRESULT SetProgramTexture(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, const char* val, int forceReload) const = 0;

#ifdef PREPARECONTEXT_MIGRATION
  virtual HRESULT SetProgramImage( const VisProgramHandle &iProgram, const char* iName, const VisImageHandle & iImage) const = 0;
  virtual HRESULT SetProgramBuffer(const VisProgramHandle &iProgram, const char* iName, const VisBufferHandle & iBuffer) const = 0;
#endif

  virtual HRESULT SetProgramImage( const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, const VisImageHandle & iImage) const = 0;
  virtual HRESULT SetProgramBuffer(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, const char* iName, const VisBufferHandle & iBuffer) const = 0;


#ifdef PREPARECONTEXT_MIGRATION
	virtual HRESULT CreateProgram(const CATString & iFileName, VisProgramHandle &oProgram) = 0;
#endif
 
	virtual HRESULT CreateImage(IVisTexturePtr iArgument, VisImageHandle& oImage) = 0;
	virtual HRESULT CreateBuffer(const ComputeBufferUsage::Type iUsage, const size_t iSizeInBytes, const void * iDataPtr, VisBufferHandle & oBuffer) = 0;
  virtual HRESULT CreateBufferFromGraphics(const unsigned int iGraphicBuffer, VisBufferHandle & oBuffer) = 0;

  virtual HRESULT DeleteBuffer(const VisBufferHandle & handle) = 0;
  virtual HRESULT DeleteImage(const VisImageHandle & handle) = 0;

#ifdef PREPARECONTEXT_MIGRATION
#endif

  virtual HRESULT UpdateBuffer( VisComputeContext iComputeContext, const VisBufferHandle& ibuffer, const void * idata, unsigned int iStartOffset, unsigned int iByteCount) const = 0;
  virtual HRESULT UpdateTexture(VisComputeContext iComputeContext, IVisTexturePtr const& itexture, IVisTextureUpdateData const&) const = 0;

  // These are free functions not accepting compute context, they are allowed for texture
  // because Globe has no compute context when they work with textures.
  virtual HRESULT UpdateTexture(IVisTexturePtr const& itexture, IVisTextureUpdateData const&) const = 0;
  virtual HRESULT UpdateTexture(IVisTexturePtr const& itexture, const CATPixelImage* iImage, unsigned int iSliceToUpdate, bool iHighFrequencyUpdate = false, bool iGenerateMipmap = false) const = 0;
  virtual HRESULT UpdateTexture(IVisTexturePtr const& itexture, void* iData, IVisTextureFormat::Type iFormat, unsigned int width, unsigned int height, unsigned int iSliceToUpdate, unsigned int iMipToUpdate, bool iHighFrequencyUpdate, bool iGenerateMipmapInGPU) const = 0;
  virtual HRESULT UpdateSparseTexture(IVisTexturePtr const& itexture, const VisSparseTexture::UpdateDesc& iDesc) const = 0;


  virtual HRESULT MemoryBarrier(VisComputeContext iComputeContext, const ComputeMemoryBarrier::Type mask) const = 0;
  virtual HRESULT LaunchProgram(void* exeCtx, const VisProgramHandle & iProgram,int nx, int ny,int nz) const = 0;

  //Deprecated, do not use !
  virtual HRESULT MapBuffer(    VisComputeContext iComputeContext, const VisBufferHandle & iBuffer,const ComputeMapFlags::Type & iMapFlag, size_t iOffset, size_t iSizeInBytes, void *& oPtrBuffer) const = 0;
  virtual HRESULT UnmapBuffer(  VisComputeContext iComputeContext, const VisBufferHandle & iBuffer) const = 0;

  struct ReadBack
  {
    struct BufferDesc
    {
      VisBufferHandle handle;
      std::size_t     offset;
      std::size_t     size;
    };

    using vCallback = std::function<void(void)>;
    
    // This struct should be only temporary, and replaced directly by std::variant<void*, std::shared_ptr<void>>
    // For now it would cause a compilation error with the code of Globe ( GlobeEngine\VUEngine.m\src\vuTileCompute.cpp )
    // which uses readDataDestination as an argument which expects a void*;
    // hence this struct which provides the conversion operator to void*
    struct ReadDataPtr
    {
      std::variant<void*, std::shared_ptr<void>> m_pData;
      ReadDataPtr& operator=(void* ipData)
      {
        m_pData = ipData;
        return *this;
      }
      ReadDataPtr& operator=(std::shared_ptr<void> ipData)
      {
        m_pData = ipData;
        return *this;
      }
      operator void* () const
      {
#ifndef _IOS_SOURCE
        return std::get<void*>(m_pData);
#else
        void* const* ppData = std::get_if<void*>(&m_pData);
        return ppData ? *ppData : nullptr;
#endif
      }
      operator std::shared_ptr<void>() const
      {
#ifndef _IOS_SOURCE
        return std::get<std::shared_ptr<void>>(m_pData);
#else
        std::shared_ptr<void> const* ppData = std::get_if<std::shared_ptr<void>>(&m_pData);
        return ppData ? *ppData : nullptr;
#endif
      }
      operator std::variant<void*, std::shared_ptr<void>>() const
      {
        return m_pData;
      }
    };

    struct CallbackDesc
    {
      vCallback callbackFunction;
      ReadDataPtr readDataDestination;
      // a shared_ptr should be used to ensure survival of the allocated data at readback actual execution
    };

  };


  virtual HRESULT ReadBack(VisComputeContext iComputeContext,    const ReadBack::BufferDesc & iBufferDesc, const ReadBack::CallbackDesc & iCBDesc) const = 0;
  virtual HRESULT ReadBackSLI(VisComputeContext iComputeContext, const ReadBack::BufferDesc & iBufferDesc, const ReadBack::CallbackDesc & iCBDesc0, const ReadBack::CallbackDesc & iCBDesc1) const = 0;

  virtual HRESULT GenerateMips(VisComputeContext iComputeContext, const IVisTexturePtr &iValue) const = 0;


protected :

  friend class VisComputeProgram;

  virtual HRESULT CreateProgram(const CATString & iFileName, VisProgramHandle &oProgram) = 0;
  virtual HRESULT DeleteProgram(const VisProgramHandle & handle) = 0;
  virtual void TouchMaterial(const VisPrepareContext iPrepareContext, const VisProgramHandle &iProgram, VisShaderOptions iShaderOptions) const = 0;

  VisComputeManager(); 
  virtual ~VisComputeManager();

  static VisComputeManager * s_instance;

  //VisComputeResourceManager *_resourceManager;
};


#endif // VISCOMPUTEMANAGER_H_
