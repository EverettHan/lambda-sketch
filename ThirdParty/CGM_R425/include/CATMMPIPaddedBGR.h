#ifndef CATMMPIPADDEDBGR_H
#define CATMMPIPADDEDBGR_H


#include "CATMMediaPixelImage.h"

#include "CATPixelImage.h"

struct ExportedByCATMMediaPixelImage ImgBufferParam {
  unsigned int w;           /*in Pixels*/
  unsigned int h;           /*in Pixels*/
  unsigned int bufferSz;    /*in Bytes*/
  unsigned int lineSz;      /*in Bytes*/
  unsigned int paddingsize; /*in Bytes*/

  ImgBufferParam();
  ImgBufferParam(unsigned int iW, unsigned iH);
  ImgBufferParam(const CATPixelImage& iPixelImage);

  void SetImage(const CATPixelImage& iPixelImage);

  void SetAsPaddedBGR();
};

/**
 * @ingroup groupPixelImageTransfo
 * @brief Support conversion into BGR.
 **/
class ExportedByCATMMediaPixelImage CATMMPIPaddedBGR
{
public:
  static bool CheckSupportImageForConversion(const CATPixelImage& iPixelImage);
  static bool CheckSupportImageForConversion(const CATPixelImageFormat& iFormat);
  static bool ComputePaddedBGR(unsigned int w, unsigned int h, ImgBufferParam &ioDIBParams);
  static bool ComputePaddedBGR(const CATPixelImage& iPixelImage, ImgBufferParam &ioDIBParams);
  static bool ConvertBuffer(const CATPixelImage& iPixelImage, const ImgBufferParam &iDIBParams, unsigned char* iopDestBuffer);
  static unsigned char* BuildAndConvertBuffer(const CATPixelImage& iPixelImage, ImgBufferParam *ioDIBParams=NULL);

  /**
   * Return a padded buffer from an input buffer.
   * If specific iOptDestWidth or iOptDestHeight is requested, input buffer will be cropped
   *   or extended with iBGRBackgroundColor but input image will not resized to fit new dimensions.
   *
   *        +------------------+ Requested buffer dimensions
   *        |                  |
   *        |              .---+-- Filled data with iOptBGRBackgroundColor
   *        |             X    |
   *        +------------------+--------+ Input buffer
   *        |                  |        |
   *        |                  |        |
   *        |                  |      .-+------ Cropped data
   *        |                  |     /  |
   *        |         X        |    X   |
   *        |        /         |        |
   *        |       /          |        |
   *        +------/-----------+--------+
   *              /
   *       Kept data
   *
   * Even if input buffer does not require padding because of its width, a new buffer will be returned if it has been given.
   *
   * @param ipSrc_NotPaddedBGRpixels the inout buffer to pad.
   *
   * @param iSrcWidth,iSrcHeight,iSrcFormat,iSrcBytesPerPixel  width, height, format and bytes per pixel of ipSrc_NotPaddedBGRpixels
   *
   * @param iopDest_PaddedBGRpixels returned buffer of a padded image. Will be generated if empty or if expected size differ from ioDestSize. Will be potentially deleted if required.
   *
   * @param ioDestSize size of given buffer iopDest_PaddedBGRpixels if so. And returns size of used image buffer iopDest_PaddedBGRpixels even if iTryKeepDestBuffer is true.
   *
   * @param iTryKeepDestBuffer if set to true and if ioDestSize is greater than required, iopDest_PaddedBGRpixels will not be deleted and replaced by new one. Is optional.
   *
   * @param iOptDestWidth,iOptDestHeight  requested width and height of returned buffer. Are optional.
   *
   * @param iOptBGRBackgroundColor: background color to fill if destination width  is greater than width  of input buffer
   *                                                      or if destination height is greater than height of input buffer. Is optional. By default, white will be used.
   */
  static bool UpdateOrRenewDestPaddedBGRBuffer(/*inputs*/  const unsigned char *ipSrc_NotPaddedBGRpixels, unsigned int  iSrcWidth  , unsigned int  iSrcHeight,
                                                            CATPixelImageFormat iSrcFormat, unsigned int iSrcBytesPerPixel,
                                               /*outputs*/      unsigned char *&iopDest_PaddedBGRpixels, unsigned int &ioDestSize,
                                  /*other specifications*/                 bool iOptTryKeepDestBuffer=false,
                                                                   unsigned int iOptDestWidth=0, unsigned int iOptDestHeight=0,
                                                                   unsigned int iOptBGRBackgroundColor=0xFF);

  static const unsigned char __FillColorForPadding;
  static const unsigned int  __Bytes_24bpp;
  static const unsigned int   __bits_24bpp;

private:
  static void CopyColorAndIncrement(unsigned char *&iopDest_PaddedBGRpixels, const unsigned int iBGRBackgroundColor, const unsigned int sizeInPixels);

};

#endif

