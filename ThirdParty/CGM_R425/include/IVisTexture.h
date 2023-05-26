#ifndef IVISTEXTURE_H_
#define IVISTEXTURE_H_

#include "SGInfra.h"

#include "CATSysErrorDef.h"
#include "IVisTextureFormat.h"
#include "VisSparseTexture.h"
#include "vBasisTools.h"
#include "vSmartPtr.h"
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <limits>


class CATPixelImage;
class IVisTexturePtr;

struct IVisTextureType
{
  enum Type
  {
    eUnknownType = -1,
    eTexture2D,
    eTexture3D,
    eTextureCube
  };
};

struct IVisTextureHeader
{
  unsigned int Width = 0;
  unsigned int Height = 0;
  union
  {
    unsigned int Depth = 1;
    unsigned int ArraySize;
  };
  IVisTextureType::Type TextureType = IVisTextureType::Type::eUnknownType;
  unsigned int MipLevels = 1;
  IVisTextureFormat::Type Format = IVisTextureFormat::Type::eUndefined;  
};

/**
* @struct This represents all the data needed to update a texture
* @ This is a NRE class only.
*/
struct IVisTextureUpdateData
{
    
  static constexpr std::uint32_t kRemainingMipLevels = 0xffffffff;
  static constexpr std::uint32_t kRemainingSlices = 0xffffffff;

  IVisTextureUpdateData() = default;
    
  // Provide a desc for the texture because this struct can be used to create a texture.
  // If m_hasDesc is false, these values are ignored
  std::uint32_t m_width = 0; // This should be the width of the texture and not the mip level
  std::uint32_t m_height = 0; // This should be the height of the texture and not the mip level
  std::uint32_t m_depth = 0; // This should be the depth of the texture and not the mip level
  std::uint32_t m_arraySlices = 1; // Total array slices
  std::uint32_t m_mipLevels = 1; // Total mip levels
  IVisTextureFormat::Type m_format = IVisTextureFormat::Type::eUndefined;
  
  // Data to update
  // Data layout is always assumed in this order:
  // ===============================================
  //  MipSlice|ArraySlice|Face|Depth|Height|Width
  // ===============================================
  // This data should not be modified outside once set, the shared_ptr allows one to put a callback
  // to know when the buffer can be reused, this callback will be called from main thread.
  std::shared_ptr<byte_t> m_data;
  // Indicates the total size of data
  std::size_t m_dataSize = 0;
  // This is the first mip level that is updated
  std::uint32_t m_baseMipToUpdate = 0;
  // The total mip levels after the first mip level, kRemainingMipLevels means all levels after the first level
  std::uint32_t m_nbMipsToUpdate = kRemainingMipLevels;
  // The first slice to update. If texture has 6 faces (cubemap), this can be an index to a face,
    // If the texture is a cubemap array the total array size is 6 * m_arraySlices
    // so a valid value of m_baseSliceToUpdate is between [0, 6 * m_arraySlices)
  std::uint32_t m_baseSliceToUpdate = 0;
  // Total number of slices to update. If texture has 6 faces (cubemap), and also is an array
  // the total array size is 6 * ArraySize, so a valid value of m_nbSlicesToUpdate is between 
  // [1, 6 * m_arraySlices) or kRemainingSlices. 
  // For non array cubemap, this can be [1, 6]
  // Use kRemainingSlices to update rest of the slices starting from m_baseSliceToUpdate.
  std::uint32_t m_nbSlicesToUpdate = kRemainingSlices;

  // Set to true if the desc has valid values
  bool m_hasDesc = false;
  bool m_highFrequencyUpdate = false;
  bool m_generateGPUMipMaps = false;
};

struct IVisTextureData
{
  std::shared_ptr<byte_t> data;
  std::size_t size = 0;
  std::uint32_t baseMipRead = 0;
  std::uint32_t nbMipsRead = 0;
};
/** @class This represent a texture. For now, it only supports Texture Array.
 *  You can use this class with the CATGraphicMaterial class.
 *  @warning This is a NRE class only.
 */
class ExportedBySGInfra IVisTexture : public VKL::vSmartPtrObject
{
  friend class VisTextureD3DInterop;
 
  friend class CATVisSceneImpl;
  friend class CATVisReflectionProbe;
  friend class CATGraphicMaterial;
  friend class Vis3DXMSerializer;
  friend class CAT3DXMTemplate;
  friend class IVisTexturePtr;
  friend class CATCacheOfDestroyedElements;
public :

  static constexpr std::uint32_t kAllMipLevels = 0xffffffff;

  typedef IVisTextureFormat::Type TextureFormat;
  typedef IVisTextureType::Type TextureType;
  typedef struct IVisTextureUpdateData TextureUpdateData;

  // file buffer type
  enum ETextureFileType
  {
    eNoFile, // no file buffer
    eBasisFile,
    eKTX2File
  };
 
  /** Update a specific slice in a procedural texture array.
   *  if you want to update several slices, just call the method several times.
   *  @param param Use the getParameter method to get the id of the sampler name in the shader.
   *  @param iImage is the new image you want to put. Must have the same format and size as the previous texture. If not, undefined behavior.
   *  @param iSliceToUpdate is the slice you want to update. Begin to 1. So last slice is n. If you set 0, nothing will happen.
   *  @param iHighFrequencyUpdate must be set to true if you often update the slice (each two or three frames for example). Setting true, will
   *         improve performances but memory cost will be increased (depending on texture size). If it is a one shot update, keep to false.
   *         If you are not sure, ask the Visualization Team before using it. We will be happy to help you !
   *  @param iGenerateMipmap is used to ask the mipmap generation. If false, we won't generate mipmaps. If true, generation is done.
   *         Generating mipmap can cost a lot of CPU time.
   */
  virtual void Update(const CATPixelImage * iImage, unsigned int iSliceToUpdate, bool iHighFrequencyUpdate = false, bool iGenerateMipmap = false) = 0;
  
  /**
   * Update the image of specific mip of a specific slice of a procedural texture array.
   *
   * @param iData The raw data on the image.
   * @param iFormat The format of the image.
   * @param width The widht of the image in pixels.
   * @param height The height of the image in pixels.
   * @param iSliceToUpdate The idx of the slice to update.
   * @param iMipToUpdate The mipmap level to update.
   * @param iHighFrequencyUpdate must be set to true if you often update the slice (each two or three frames for example). Setting true, will
   *         improve performances but memory cost will be increased (depending on texture size). If it is a one shot update, keep to false.
   *         If you are not sure, ask the Visualization Team before using it. We will be happy to help you !
   * @param iGenerateMipmapInGPU If you do not plan to update each mip level, set this to true to avoid having uninitialized mip slices. 
   *                             This will only work for gpu textures.
   */
  virtual void Update(void *iData, IVisTextureFormat::Type iFormat, unsigned int width, unsigned int height, unsigned int iSliceToUpdate, unsigned int iMipToUpdate, bool iHighFrequencyUpdate, bool iGenerateMipmapInGPU = false) = 0;

  /**
   * Update a mip level of a 2D or 3D texture, or a mip level of a specific slice of a 2D texture array.
   *
   * @param iParams The struct which contains all the parameters needed to update the texture.
   */
  virtual void Update(const IVisTextureUpdateData &iUpdateData) = 0;

  /**
  * update the content of the texture, with a basis file.
  *
  * @param BasisFileName The path of the basis texture to update with.
  */
  virtual void Update(const char *BasisfileName, VKL::EUsageFormat iFormat, bool iHighFrequencyUpdate = false) = 0;

  virtual void UpdateSparsely(const VisSparseTexture::UpdateDesc & iDesc) = 0;

  /**
  * Unlink external vulkan/gl texture from External context, this ensures that the texture
  * is not treated as an external texture anymore in NRE
  * This is required if the IVisTexture is still valid, but the external context has been
  * or needs to be destroyed.
  */
  virtual void UnlinkExternalTexture() = 0;
  /**
  * Sync updated external vulkan texture
  * This is  a synchronization/copy of external texture to NRE 
  */
  virtual void UpdateExternalTexture(uint64_t iSemaphoreValueToWaitOn, uint64_t iSemaphoreValueToSignal) = 0;

  virtual void SetName(const char* iName) = 0;

  /**
  * Allow to specify a name that will be used for debugging.
  * Typically this name will be used as a basis for Nsight debugging.
  * However, the name in the debugger may not be exactly this name. 
  * The render engine is free to append additional info.
  * Calling the function again will change the name.
  * This call is NOT pipelined. 
  * 
  */
  virtual void SetDebugName(const char* iName) = 0;

  /** Get the texture format.
   *  @return the texture format (eUnknownFormat if the format is not managed by VisTextureFactory)
   */
  virtual TextureFormat GetFormat() const = 0;

  /** Get the texture format.
   *  @return the texture type (eUnknownType if the format is not managed by VisTextureFactory)
   */
  virtual TextureType   GetType() const = 0;

  /** Get the texture size.
   *  @param oSize is the buffer to return the texture size.
   *  @return the number of slices if the texture is an array (a "TextureCube" is considered as having 6 slices)
   */
  virtual unsigned int  GetSize(unsigned int oSize[3]) const = 0;

    /** Get the texture mipmap level count.
   *  @return the number of mipmap level
   */
  virtual unsigned int  GetMipmapLevelCount() const = 0;


  /** Compute and return the size in byte of a mipmap of a slice. This call supports all kind of texture types.
   *  @param iMipmapLevel The mipmap level you want to get. [0 ; Max-1].
   *  @return the size in bytes.
   */
  virtual unsigned int GetSizeInBytes(unsigned int iMipmapLevel) const = 0;

  /** Get the data pointer of the texture. You must delete it !
   *  This method doesn't support Multi GPU !
   *  @param iMipmapLevel The mipmap level you want to get. [0 ; Max-1].
   *  @param iHighFrequencyUpdate must be set to true if you often update the slice (each two or three frames for example). Setting true, will
   *         improve performances but memory cost will be increased (depending on texture size). If it is a one shot update, keep to false.
   *         If you are not sure, ask the Visualization Team before using it. We will be happy to help you !
   *  @return the data. You must delete the data.
   *  @deprecated In favor of GetMipData;
   */
  virtual void* GetData(unsigned int iMipmapLevel, bool iHighFrequencyUpdate = false) const = 0;

  /** Get the data pointer of the texture. You must delete it !
  * This method returns the pointer to start of data
  * @deprecated In favor of GetMipData();
  */
  virtual void* GetRawData() const = 0;

  /** Get a copy of the mip level data, you do not nee
   *  This method doesn't support Multi GPU !
   *  @param iMipmapLevel The mipmap level you want to get. [0 ; Max-1]. If iMipmapLevel == kAllMipLevels, the whole texture data is returned
   */
  virtual IVisTextureData GetMipData(std::uint32_t iMipmapLevel = kAllMipLevels) const = 0;

  /** This function allow to get an hash from the current texture data (if it's available on CPU side).
  *  @param oHash Retrieves the computed hash
  *  @return true if the hash is available for this object
  */
  virtual bool ComputeHash(unsigned int& oHash) const = 0;

  
  virtual bool IsSparse() const = 0;
  
  
  /** This function allow to know if two IVisTexture point into the same material.
   *  @param iSrc is the other IVisTexture to compare.
   *  @return true if the same material is pointed
   */
  virtual bool IsEqual(const IVisTexture& iSrc) const = 0;

  /** This function allow to know if two IVisTexture point into the same material.
  *  @param iSrc is the other IVisTexture to compare.
  *  @return true if the same material is pointed
  */
  virtual bool IsEqual(const IVisTexturePtr& iSrc) const = 0;
  
  /** This function return true if the texture is transparent
  * The texture is transparent if its internal format have a alpha channel.
  * If the texture is created with a CATTexturePixelImage we check the alpha channel
  */
  virtual bool IsTransparent() const = 0;

  /** This function return true if the texture has a valid header
  * It will return IVisTextureHeader for current texture
  */
  virtual bool GetHeader(IVisTextureHeader& header) const = 0;
  
  /**
  * Set the file path which was used to create this texture.
  *
  * @param iFileName The path of the file used to create this texture.
  */
  virtual void SetFileName(const char *iFileName) = 0;

  /**
  * Get the path of the file which has been used to create this texture.
  *
  * @return The path of the file which has been used to create this texture.
  */
  virtual const char * GetFileName() const = 0;

  /**
   * @deprecated: use GetTextureFileType instead.
   * 
   * Check if the texture is a basis texture.
   *
   * @return true if this texture is a basis or KTX2 texture, false otherwise
   */
  virtual bool IsBasisTexture() const = 0;

  /**
   * If the texture is a basis or KTX2 texture (and therefore has a file buffer), get the corresponding file type.
   *
   * @return the texture file type. ETextureFileType::eNoFile if not a basis or KTX2 texture.
   */
  virtual ETextureFileType GetTextureFileType() const = 0;

  /**
   * get the basis or KTX2 file buffer which has been used to create/update this texture
   *
   * @return A ptr on the basis / KTX2 raw buffer.
   */
  virtual void const* GetFileBuffer() const = 0;

 /**
   * Get the basis or KTX2 file buffer size.
   *
   * @return The basis / KTX2 raw buffer's size in bytes.
   */
  virtual size_t GetFileBufferSize() const = 0;

  /**
   * Get the basis or KTX2 usage for this texture.
   * In function of the usage, the basis / KTX2 texture is transcoded to the most efficient format. (BC1 for RGB, BC3 for RGB, BC5 for normalmaps...)
   *
   * @return the basis / KTX2 usage of this texture.
   */
  virtual VKL::EUsageFormat GetTextureUsage() const = 0;

private :
  //This section contains advanced feature reserved for specific usage


  /** This function create a new IVisTexture that points into the same material. So the reference IVisTexture and the new one will be different
   *  but will point into the same vMaterial. It's like a new pointer into the same inside material.
   *  @return a new IVisTexture or NULL in case of error
   */
  virtual IVisTexture * ShareLink() const = 0;

  // D3D/OGL interoperability 
  virtual HRESULT DeleteD3DTextureInterop() const = 0;
  virtual HRESULT LockD3DTextureInterop() const = 0;
  virtual HRESULT UnlockD3DTextureInterop() const = 0;
  
protected :

  IVisTexture();
  virtual ~IVisTexture();
};

#endif //IVISTEXTURE_H_
