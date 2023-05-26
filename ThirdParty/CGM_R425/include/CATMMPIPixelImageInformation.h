#ifndef CATMMPIPIXELIMAGEINFORMATION_H
#define CATMMPIPIXELIMAGEINFORMATION_H

#include "CATMMediaPixelImage.h"

#include "CATPixelImage.h"
#include "CATMMPIHandler.h"


/**
 * @ingroup groupMultimediaPixelImage
 * @brief Pixel Image informations.
 **/
class ExportedByCATMMediaPixelImage CATMMPIPixelImageInformation
{
  CATMMPIPixelImageInformation(const CATMMPIConstImageHdl& iHandler);

public:
  CATMMPIPixelImageInformation(const CATPixelImage* ipImage);
  virtual ~CATMMPIPixelImageInformation();

  /**
   * Returns true if all pixels are opaque.
   */
  bool                            HasUselessAlphaChannel() const ;
  bool                            CanBeConsideredAsBW() const;

private:
  const CATMMPIConstImageHdl      _handler;
};

#endif
