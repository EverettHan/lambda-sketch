#ifndef CATMMPIRGBAHelper_H
#define CATMMPIRGBAHelper_H

#include "CATMMediaPixelImage.h"

#include "CATMMPIPixelColor.h"


class ExportedByCATMMediaPixelImage CATMMPIRGBAHelper
{
public:
  static CATMMPIPixelColor CreateRGBAPixelColor(unsigned char iR, unsigned char iG, unsigned char iB, unsigned char iA);
};

#endif
