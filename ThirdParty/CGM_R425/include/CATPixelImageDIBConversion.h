#ifndef CATPixelImageDIBConversion_H
#define CATPixelImageDIBConversion_H

//#include "CATViz.h"
#include "CATMMediaPixelImage.h"

class CATPixelImage;

ExportedByCATMMediaPixelImage void GetDIBPixelsFromPixelImage(const CATPixelImage* iprPixelImage,
															  unsigned char* iprPixels,
															  const int iWidth,
															  const int iHeight,
															  const int iRasterWidth,
															  const int iByteWidth);


#endif  // CATPixelImageDIBConversion_H
