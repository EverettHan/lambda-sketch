#pragma once
#include "VisREKernelTools.h"
#include "vCommonTypes.h"
#include <cstddef>
#include <memory>
#include <vector>
#include <cstdint>

namespace basist
{
  class basisu_transcoder;
  class ktx2_transcoder;
  enum class transcoder_texture_format;
  struct basisu_image_level_info;
  struct ktx2_image_level_info;
}

namespace VKL
{

  /**
   * In function of their usage, basis textures are transcoded to the most efficient format.
   */
  enum EUsageFormat
  {
    eNoTranscode = 0,
    eColorRGB, // BC1
    eColorRGBA, // BC3
    eColorRGBHQ, // eBC7
    eNormalMap, // eBC5
    eGrayScale // eBC4
  };

  /**
   * Helper class to load a .basis file
   */
  class ExportedByVisREKernelTools vBasisImage
  {
  public:
    bool               isValidHeader() const;
    bool               load(const char* iFilePath);
    bool               getImage(unsigned int iMipLevel, unsigned int iSlice, byte_t* oData, EUsageFormat iFormat, bool iFlipY = true) const;
    [[nodiscard]] int  getNumSlices() const;
    [[nodiscard]] int  getNumMipLevels() const;
    [[nodiscard]] int  getWidth() const;
    [[nodiscard]] int  getHeight() const;
    [[nodiscard]] bool isCubemap() const;
    [[nodiscard]] bool isVolume() const;
    [[nodiscard]] bool isKTX2() const;
    [[nodiscard]] bool isEncodedWithYFlip() const;

    [[nodiscard]] inline byte_t const* getBasisFileRawData() const
    {
      return m_basisFileRawData.get();
    }

    [[nodiscard]] inline std::shared_ptr<byte_t> getBasisFileRawData()
    {
      return m_basisFileRawData;
    }

    [[nodiscard]] std::size_t getBasisFileSize() const
    {
      return m_basisFileSize;
    }

    [[nodiscard]] std::size_t getTextureFullSize(EUsageFormat iFormat) const;
    void                      setBasisFileRawData(std::shared_ptr<byte_t> iRawData, std::uint32_t iSize);

    // This is delcared here to export the function
    // so that the unique_ptr destructors are not inlined
    // and do not cause link issues
    ~vBasisImage();
  private:
    bool _loadFullFile(const char* iPath, std::shared_ptr<byte_t>& oData, std::uint32_t& oOutputSize) const;
    bool _analysis();
    bool _analysisBasis();
    bool _analysisKTX2();
    bool _getImageBasis(unsigned int iMipLevel, unsigned int iSlice, byte_t* oData, EUsageFormat iFormat, bool iFlipY) const;
    bool _getImageKTX2(unsigned int iMipLevel, unsigned int iSlice, byte_t* oData, EUsageFormat iFormat, bool iFlipY) const;
    void _flipImage(byte_t* ioData, std::size_t iSize, unsigned int iPhysWidth, unsigned int iPhysHeight,
                    basist::transcoder_texture_format iFormat) const;

    // nbBytesPerPixel, nbBlocksOrPixels
    using SizeInfo = std::pair<std::uint32_t, std::uint32_t>;

    static SizeInfo _getSize(basist::ktx2_image_level_info const&, basist::transcoder_texture_format iFormat);
    static SizeInfo _getSize(basist::basisu_image_level_info const&, basist::transcoder_texture_format iFormat);
    
    std::shared_ptr<byte_t> m_basisFileRawData;

    std::uint32_t m_basisFileSize = 0;
    unsigned int  m_width         = 0;
    unsigned int  m_height        = 0;
    unsigned int  m_numSlices     = 0;
    unsigned int  m_numMipLevels  = 0;
    bool          m_cubemap       = false;
    bool          m_volume        = false;
    bool          m_ktx2          = false;
    bool          m_flipY         = false; // whether the file was encoded with y_flip flag set to true or not. Only useful for basis file : currently not supported by BasisUniversal for KTX2 files.

    // without shared_ptr I am getting a compilation error 
    // even when the class destructor is declared and exported
    std::shared_ptr<basist::basisu_transcoder> m_basisTranscoder;
    std::shared_ptr<basist::ktx2_transcoder>   m_ktx2Transcoder;
  };
}
