#ifndef VISSPARSETEXTURE_H_
#define VISSPARSETEXTURE_H_

#include <cstddef>
#include <stdint.h>
#include <vector>

#include "SGInfra.h"
#include "IVisTextureFormat.h"

struct ExportedBySGInfra VisSparseTexture
{
  /*  Sparse texture memory is divided into tiles.
  *   It describes the layout of the chosen tile
  */
  struct Page
  {
    uint32_t XSize;
    uint32_t YSize;
    uint32_t ZSize;
  };

  /*  It describes a region of a sparse texture memory, basically it is an axis aligned box.
  *   Offsets: it specifies the texel offsets along the x, y, and z axis within the texture array.
  *   Dimensions: It specifies the dimensions (from the offset) of the region in x, y, z directions.
  *   MipmapLevel: It specifies the mipmap level
  */
  struct Region
  {
    uint32_t XOffset;
    uint32_t YOffset;
    uint32_t ZOffset;

    uint32_t Width;
    uint32_t Height;
    uint32_t Depth;

    uint32_t MipmapLevel;
  };

  /*  This structure describes a sparse texture.
  *
  *   IVisTextureFormat::Type: is the format of the texture
  *   Page: Describes the layout of tiles for the texture (with respect to the chosen format)
  *   Dimensions: Describe dimension of your sparse texture
  */
  struct Desc
  {
    IVisTextureFormat::Type Format;
    Page                    PageLayout;
    uint32_t            Width;
    uint32_t            Height;
    union
    {
      uint32_t Depth;     //Default is 1
      uint32_t ArraySize;
    };
    uint32_t  MipLevels;
  };


  /*  It describes a sparse texture memory update.
  *   With sparse texture, a memory update can upload data to GPU (commitment), or unload data from GPU (uncommitment)
  *   
  *   Data: The memory you want to commit (ignore it in case of unload)
  *   Region: The region of the sparse texture affected byt the operation
  *   Commit: Specify if the operation upload or unload the memory
  */
  struct CommitmentData
  {
    void*     data;
    Region    region;
    uint32_t  dataSize;
    bool      commit;
  };

  /*  It is a wrapper to allow the user to group memory updates
  */
  struct ExportedBySGInfra UpdateDesc
  {
    std::vector<CommitmentData> commits;
  };

  /** Function to fill a sparse array descriptor
  *   @param oDesc is the filled descriptor
  *   @param iFormat specifies the format of the texture
  *   @param iPageLayout specifies the chosen page layout
  *   @param iWidth specifies the width of the texture
  *   @param iHeight specifies the height of the texture
  *   @param iNbLayer specifies the number of slice/layer of the texture
  *   @param iMipLevels specifies the number of mipmap level of the texture
  */
  static void CreateSparseArrayDesc(VisSparseTexture::Desc& oDesc, const IVisTextureFormat::Type iFormat, const Page& iPageLayout, const uint32_t iWidth, const uint32_t iHeight, const uint32_t iNbLayer, const uint32_t iMipLevels = 1);
  
    /** Function to fill a commitment data structure
  *   @param iRegion is region of the commitment
  *   @param iData specifies the commitment associated data
  *   @param iDataSize specifies the size of the data, in bytes
  *   @param iCommit specifies if the commitment must commit or uncommit the data specified by the region
  *
  *   @warning if you specified iCommit to false, the iData and iDataSize parameters will be ignored
  */
  static void CreateCommitmentData(CommitmentData& oCommitmentData, const Region& iRegion, void* const iData = NULL, const uint32_t iDataSize = 0u, const bool iCommit = false);
  
  /** Function to fill a sparse array descriptor
  *   @param oRegion is the filled region
  *   @param iXOffset is the offset along the x axis
  *   @param iYOffset is the offset along the y axis
  *   @param iZOffset is the offset along the z axis
  *   @param iWidth is the width of the region from the xOffset
  *   @param iHeight is the height of the region from the yOffset
  *   @param iDepth is the depth of the region from the zOffset
  *   @param iMipLevel is the level of mipmap
  */
  static void CreateRegion(VisSparseTexture::Region& oRegion, const uint32_t iXOffset, const uint32_t iYOffset, const uint32_t iZOffset, const uint32_t iWidth, const uint32_t iHeight, const uint32_t iDepth, const uint32_t iMipLevel);
  
  /** Function to add a commitment data structure to an update desc
  *   @param updateDesc is the filled update desc
  *   @param iRegion if the region associated to the update
  *   @param iData is the data associated to the update
  *   @param iDataSize is the data's size associated to the update
  *   @param iCommit specifies if the update is a commitment or an uncommitment
  */
  static void AddCommitmentData(UpdateDesc& iUpdateDesc, const Region& iRegion, void* const iData = NULL, const uint32_t iDataSize = 0u, const bool iCommit = false);
  
  /** Function to add a commitment data structure to an update desc
  *   @param updateDesc is the filled update desc
  *   @param iCommitmentData specifies the commitment description
  */
  static void AddCommitmentData(UpdateDesc& iUpdateDesc, const CommitmentData& iCommitmentData);

  static uint32_t GetRegionElementCount(const Region& iRegion);

};

ExportedBySGInfra bool  operator==(const VisSparseTexture::Region& iL, const VisSparseTexture::Region& iR);
ExportedBySGInfra bool  operator!=(const VisSparseTexture::Region& iL, const VisSparseTexture::Region& iR);
ExportedBySGInfra bool  operator==(const VisSparseTexture::Page& iL, const VisSparseTexture::Page& iR);
ExportedBySGInfra bool  operator!=(const VisSparseTexture::Page& iL, const VisSparseTexture::Page& iR);

#endif //VISSPARSETEXTURE_H_

