#ifndef CATMMPIPixelImageAccess_H
#define CATMMPIPixelImageAccess_H

#include "CATMMediaPixelImage.h"
#include "CATPixelImage.h"
#include "CATMMPIPixelColor.h"

class CATMMPIImagePixelIterator;
class CATMMPIConstImageHdl;
class CATMMPIImageHdl;

/**
 * @ingroup groupPixelImageBufferAccess
 */
class ExportedByCATMMediaPixelImage CATMMPIPixelImageAccess
{
  friend class lCATPixelImage;
  friend class CATMMPIPixelImageInformation;
  static CATMMPIImagePixelIterator*       GetIteratorFromHdl(CATMMPIImageHdl& iImage);
  static const CATMMPIImagePixelIterator* GetIteratorFromConstHdl(const CATMMPIConstImageHdl& iImage);

public:
  static CATMMPIImagePixelIterator*       GetIterator(CATPixelImage &iPixelImage);
  static CATBoolean                       GetPixelImageColorAt(CATPixelImage &iPixelImage, const int &iX, const int &iY, CATMMPIPixelColor &oColor);
  static bool                             CheckHandler(const CATMMPIConstImageHdl& iImage);
};

#endif
