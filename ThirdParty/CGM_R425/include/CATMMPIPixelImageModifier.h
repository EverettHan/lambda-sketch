#ifndef CATMMPIPIXELIMAGEPODIFIER_H
#define CATMMPIPIXELIMAGEPODIFIER_H

#include "CATMMediaPixelImage.h"

#include "CATPixelImage.h"
#include "CATMMPIPixelColor.h"

/**
 * @ingroup groupPixelImageBufferAccess
 */
class ExportedByCATMMediaPixelImage CATMMPIPixelImageModifier
{
public:
  static bool InitializeImageWithColor(CATPixelImage& ioPixelImage, const CATMMPIPixelColor &iColor);
  static bool ChangeFullyTransparentToColor(CATPixelImage& ioPixelImage, const CATMMPIPixelColor &iColor);
};

#endif
