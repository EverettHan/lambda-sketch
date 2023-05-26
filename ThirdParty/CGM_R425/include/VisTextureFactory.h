#ifndef VISTEXTUREFACTORY_H_
#define VISTEXTUREFACTORY_H_



#include "SGInfra.h"

#include "IVisTexturePtr.h"
#include "VisSparseTexture.h"
#include "vBasisTools.h"

#include <cstdint>

class CATPixelImage;
class CATTexturePixelImage;
class VisTextureFactoryImpl;

//To remove some wonderful define...
#undef true
#undef false


namespace OpenGLSharing
{
#ifdef _WINDOWS_SOURCE
  typedef HGLRC Context;
#else
  typedef void* Context;
#endif

  typedef void* Fence;

  typedef unsigned int TextureName;


  /// Using std::function here would be the best choice
  /// But this will break all build on Windows, it seems
  /// <functional> includes std::list indirectly and for some
  /// reason, some random header file has done a using namespace std 
  /// somewhere, which is the root cause of this issue.
  /// For now we stitch the code with old-school C lke callback.
  using SyncFunction = void(*)(unsigned int iDeviceIndex, void* iSyncFence, void* iUserData);
  struct SyncCallback
  {
    void* syncData = nullptr;
    SyncFunction syncFunction = {};
  };
}

namespace VulkanSharing
{

  struct MemoryObject
  {
    void* memoryHandle = nullptr;
    uint64_t size = 0;
    uint64_t offset = 0;
    uint32_t memoryTypeIndex = 0;
  };

  using Semaphore = void*;
  struct TimelineSemaphore
  {
    Semaphore handle = {};
    uint64_t initalValue = 0; // initalValue of the semaphore when it was created
    uint64_t waitValue = 0;
    uint64_t signalValue = 0;
  };

}

class ExportedBySGInfra VisTextureFactory
{
  friend class VisOpenGLInterop;
  friend class VisVulkanInterop;
  friend class VisTextureFactoryCache;
  friend class vRETexture;
  friend class XCTVulkanInterop;

public :
  using EUsageFormat = VKL::EUsageFormat;

 /** This method is used to put create a texture array. This method is mainly used for CPU procedural texture.
  *  This function doesn't support PixelImage with DXT format. (Not a drawback for procedural because we can't compress DXT in software (patent) ).
  *  If you want to update the texture content @see IVisTexture
  *  All your images must have the same size and the same format.
  *  @warning This is a NRE feature only.
  *  @param param Use the getParameter method to get the id of the sampler name in the shader.
  *  @param iImages The pixel images you want to set. Data are copied in an internal array. This is a tabular of CATPixelImage pointer.
  *  @param iNbLayer The number of slice in the array.
  *  @param iGenerateMipMap True to ask the mipmap generation else false.
  *  @param iKeepCPU True to ask keeping the CPU data (could be used for persistence).
  */
  static IVisTexturePtr CreateTextureLayer(const CATPixelImage ** iImages, unsigned int iNbLayer, bool iGenerateMipMap = true, bool iKeepCPU = true);
  

  /** This method is used to create a 3D Texture.
  *  This function doesn't support PixelImage with DXT format.
  *  If you want to update the texture content @see IVisTexture
  *  All your images must have the same size and the same format.
  *  @warning This is a NRE feature only.
  *  @param param Use the getParameter method to get the id of the sampler name in the shader.
  *  @param iImages The pixel images you want to set. Data are copied in an internal array. This is a tabular of CATPixelImage pointer.
  *  @param iNbLayer The number of input CATPixelImage
  *  @param iGenerateMipMap True to ask the mipmap generation else false.
  *  @param iKeepCPU True to ask keeping the CPU data (could be used for persistence).
  */
  static IVisTexturePtr CreateTexture3D(const CATPixelImage ** iImages, unsigned int iNbImages, bool iGenerateMipMap = true, bool iKeepCPU = true);

  /*
  ** Creates a 2D texture array from a list of DDS files. All DDS must have the same format & size. Returns NULL if failed.
  ** @param iPaths List of files to load (full path)
  ** @param iNbLayer Number of files to load (also texture array size)
  ** @param iGenerateMip Whether to force mip map generation
  **
  */
  static IVisTexturePtr CreateTextureLayerFromFiles(const char * iPaths[], unsigned int iNbLayer, bool iGenerateMipMap = true, bool iKeepCPU = true);

 /** This method is used to put create a texture array. This method is mainly used for CPU procedural texture.
  *  This method only takes one image as input and replicate it to match iNbSlices.
  *  This function doesn't support PixelImage with DXT format. (Not a drawback for procedural because we can't compress DXT in software (patent) ).
  *  If you want to update the texture content @see IVisTexture
  *  @warning This is a NRE feature only.
  *  @param param Use the getParameter method to get the id of the sampler name in the shader.
  *  @param iImage The pixel image you want to set. Data are copied in an internal array.
  *  @param iNbLayer The number of slice in the array.
  *  @param iGenerateMipMap True to ask the mipmap generation else false.
  *  @param iKeepCPU True to ask keeping the CPU data (could be used for persistence).
  */
  static IVisTexturePtr CreateTextureLayer(const CATPixelImage * iImage, unsigned int iNbLayer, bool iGenerateMipMap = true, bool iKeepCPU = true);


  /** This method is used to create a GPU texture. It has no CPU counter part. It can be used to grab the framebuffer content
  *  inside it and after draw it with a CATGraphicMaterial.
  *  @warning This is a NRE feature only.
  *  @param iFormat The texture format. If the format doesn't match the Frambuffer format for a Grab (and no convertion is acceptable), the result is undefined.
  *  @param iWidth The width in pixel.
  *  @param iHeight The height in pixel.
  *  @param iMipMapAlloc The number of mipmaps to allocate (0 means we try the maximum number, 1 means there will be no mipmap).
  *  @return the newly created texture or NULL in case of error.
  */
  static IVisTexturePtr CreateTextureGPUOnly(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight, unsigned int iMipMapAlloc = 1);

  /** This method is used to create a GPU texture. It has no CPU counter part. It can be used to grab the framebuffer content
   *  inside it and after draw it with a CATGraphicMaterial.
   *  @warning This is a NRE feature only.
   *  @param iFormat The texture format. If the format doesn't match the Framebuffer format for a Grab (and no convertion is acceptable), the result is undefined.
   *  @param iWidth The width in pixel.
   *  @param iHeight The height in pixel.
   *  @param iDepth The number of slices.
   *  @param iMipMapAlloc The number of mipmaps to allocate (0 means we try the maximum number, 1 means there will be no mipmap).
   *  @return the newly created texture or NULL in case of error.
   */
  static IVisTexturePtr CreateTextureLayerGPUOnly(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight, unsigned int iDepth = 1, unsigned int iMipMapAlloc = 1);

  /** This method is used to create a GPU 3D texture. It has no CPU counter part. It can be used to grab the framebuffer content
  *  inside it and after draw it with a CATGraphicMaterial.
  *  @warning This is a NRE feature only.
  *  @param iFormat The texture format. If the format doesn't match the Framebuffer format for a Grab (and no convertion is acceptable), the result is undefined.
  *  @param iWidth The width in pixel.
  *  @param iHeight The height in pixel.
  *  @param iDepth The depth in pixel.
  *  @param iMipMapAlloc The number of mipmaps to allocate (0 means we try the maximum number, 1 means there will be no mipmap).
  *  @return the newly created texture or NULL in case of error.
  */
  static IVisTexturePtr CreateTexture3DGPUOnly(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight, unsigned int iDepth, unsigned int iMipMapAlloc = 1);

  /** This method is used to create a GPU texture cube. It has no CPU counter part. It can be used to grab the framebuffer content
   *  inside it and after draw it with a CATGraphicMaterial.
   *  @warning This is a NRE feature only.
   *  @param iFormat The texture format. If the format doesn't match the Framebuffer format for a Grab (and no convertion is acceptable), the result is undefined.
   *  @param iSize The width and height in pixel of each cube face.
   *  @param iMipMapAlloc The number of mipmaps to allocate (0 means we try the maximum number, 1 means there will be no mipmap).
   *  @return the newly created texture cube or NULL in case of error.
   */
  static IVisTexturePtr CreateTextureCubeGPUOnly(const IVisTextureFormat::Type iFormat, unsigned int iSize, unsigned int iMipMapAlloc = 1);

  /** This method is used to create a texture from a CATPixelImage. This method is mainly used for CPU procedural texture.
   *  This function doesn't support PixelImage with DXT format. (Not a drawback for procedural because we can't compress DXT in software (patent) ).
   *  If you want to update the texture content @see IVisTexture
   *  @warning This is a NRE feature only.
   *  @param iImage The pixel image you want to set. Data are copied in an internal array.
   *  @param iGenerateMipMap True to ask the mipmap generation else false.
   */  
  static IVisTexturePtr CreateTexture(const CATPixelImage * iImage, bool iGenerateMipMap = true, bool iKeepCPU = true);

  /** This method is used to create a sparse texture from a VisSparseTexture::Desc.
   *  If you want to update the sparse texture content, look at VisSparseTexture.h for more details about VisSparseTexture::Desc
   *  @param VisSparseTexture::Desc The structure to desribe the sparse texture
   */  
  static IVisTexturePtr CreateSparseTexture(const VisSparseTexture::Desc & iDesc);

  /** This method is used to create a texture from a CATTexturePixelImage. This method is mainly used for CPU procedural texture.
   *  If you want to update the texture content @see IVisTexture
   *  @warning This is a NRE feature only.
   *  @param iImage The texture pixel image you want to set. Data are copied in an internal array.
   *  @param iForceMipMap True to ask the mipmap generation if the given iImage doesn't have mipmaps.
   *  @param iKeepCPU True to ask keeping the CPU data (could be used for persistence).
   */
  static IVisTexturePtr CreateTexture(const CATTexturePixelImage * iImage, bool iForceMipMap = true, bool iKeepCPU = true);

  /** This method is used to create a texture from a file on disk.
   *  If you want to update the texture content @see IVisTexture
   *  @warning This is a NRE feature only.
   *  @param iFilePath The texture path.
   *  @param iForceMipMap True to ask the mipmap generation if the loaded image doesn't have mipmaps.
   *  @param iKeepCPU True to ask keeping the CPU data (could be used for persistence).
   */
  static IVisTexturePtr CreateTextureFromFile(const char* iFilePath, bool iForceMipMap = true, bool iKeepCPU = true, EUsageFormat iFormat = EUsageFormat::eNoTranscode);

  static IVisTexturePtr CreateTextureFromBuffer(void const* data, int size, bool iForceMipMap = true, bool iKeepCPU = true, EUsageFormat iFormat = EUsageFormat::eNoTranscode);

  static IVisTextureFormat::Type  _UsageToIVisTextureFormat(EUsageFormat iFormat);


private :

  static IVisTexturePtr CreateTextureFromExternalGLCtx(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight, 
    OpenGLSharing::Context iContext, OpenGLSharing::Fence iFence, OpenGLSharing::TextureName iTexName, OpenGLSharing::SyncCallback Callback = {});

  static IVisTexturePtr CreateTextureFromExternalVKCtx(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight,
    const VulkanSharing::MemoryObject& iMemoryObject, VulkanSharing::Semaphore iSyncPrimitive);

  static IVisTexturePtr CreateTextureFromExternalVKCtx(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight,
    const VulkanSharing::MemoryObject& iMemoryObject, VulkanSharing::TimelineSemaphore iSyncPrimitive);
  /**
   * Remove a texture from the cache
   *
   * @param iFilenameKey the path of the texture to remove
   * @return true on success, false otherwise
   */
  static bool RemoveFromCache(const char *iFilenameKey);


  static void CleanUnusedItems();

  static unsigned int GetNumberOfItems();

  static void _Init();

  static VisTextureFactoryImpl * s_impl;

};


#endif //VISTEXTUREFACTORY_H_
