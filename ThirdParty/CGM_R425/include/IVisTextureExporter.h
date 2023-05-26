#ifndef IVISTEXTUREEXPORTER_H_
#define IVISTEXTUREEXPORTER_H_

#include "SGInfra.h"

#include "CATPixelImage.h"
#include "IVisTexture.h"
#include "IVisTexturePtr.h"

class ExportedBySGInfra IVisTextureExporter
{
public :

  /*
  ** Converts an IVisTexture to a CATPixelImage. Supported IVisTexture formats are:
  ** - eR8_UNORM
  ** - eR8G8_UNORM
  ** - eR8G8B8_UNORM
  ** - eR8G8B8A8_UNORM
  ** - eR32_FLOAT
  ** - eR32G32B32_FLOAT
  ** - eR32G32B32A32_FLOAT
  ** - eDXT1
  ** - eDXT3
  ** - eDXT5
  **
  ** @param iTexture the texture you wish to convert
  ** @return the CATPixelImage which is the result of the conversion
  */
  static CATPixelImage * Export(const IVisTexture & iTexture);
  static CATPixelImage * Export(const IVisTexturePtr & iTexture);

  /*
  ** Same as Export() but the 4-th channel (alpha) is forced to be omitted.
  */
  static CATPixelImage * ExportOmitAlpha(const IVisTexture & iTexture);
  static CATPixelImage * ExportOmitAlpha(const IVisTexturePtr & iTexture);

  // Exports IVisTexture to DDS buffer.
  // Caller needs to delete [] oData
  static HRESULT ExportDDS(const IVisTexturePtr & iTexture, char*& oData, size_t& oSize);

  // Exports IVisTexture to basis buffer.
  // Caller needs to delete [] oData
  static HRESULT ExportBasis(const IVisTexturePtr & iTexture, char*& oData, size_t& oSize);

  enum class ImageType
  {
    ePng,
    eDDS,
    eBasis
  };

  // Exports non compressed RGBA formats to png,
  // Exports compressed, volume, cubemap texture to DDS,
  // Caller needs to delete []oData
  static HRESULT Export(const IVisTexturePtr & iTexture, char*& oData, size_t& oSize, ImageType& oType);

private :

  template<typename T>
  static CATPixelImage* _CreatePixelImage(const unsigned int iWidth, const unsigned int iHeight,
    const CATPixelImageFormat& iOutFormat, const IVisTexture& iTexture);

  template<typename T>
  static void _CopyData(const T* const iSrc, T* const oDst,
    const int iNcompSrc, const int iNcompDst, unsigned int iNpixels);

};

class TextureFormatUtils
{
private:
  TextureFormatUtils() = delete;
  ~TextureFormatUtils() = delete;
  TextureFormatUtils(const TextureFormatUtils& other) = delete;
  TextureFormatUtils(TextureFormatUtils&& other) noexcept = delete;
public:
  static unsigned int _FormatToNcomponents(const IVisTexture::TextureFormat& iFormat);
  static unsigned int _FormatToNcomponents(const CATPixelImageFormat& iFormat);
  static bool _IsHdr(const IVisTexture::TextureFormat& iFormat);
};

#endif // IVISTEXTUREEXPORTER_H_
