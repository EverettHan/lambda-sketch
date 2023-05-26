#ifndef CATMMIRESIZE_H
#define CATMMIRESIZE_H


#include "CATMMediaRasterProcessor_Base.h"

#include "CATPixelImage.h"
#include "CATMMPIPixelColor.h"


/**
 * @ingroup groupPixelImageTransfo
 **/
class ExportedByCATMMediaRasterProcessor_Base CATMMIResize
{
public:
  /**
   * Create a new centered and zoomed image to fit a bigger or smaller image in a rectangle by keeping the same ratio of input image.
   *
   * @param iImage: the input image to fit in rectangle.
   *
   * @param iWidthRect : width  of the rectangle to fit.
   *
   * @param iheightRect: height of the rectangle to fit.
   *
   * @param iOptBackgroundColor: optional background color used (if needed) to fill rectangle.
   * If no color is given and is required, the color of left-upper corner will be used.
   * If color's CATMMPIPixelColorSpec differs from the one used by input CATPixelImage, the
   * returned image specification will respect the one from input background color.
   *
   * @return : a pointer to new created image that have to be released.
   * If Input image has the right ratio and no change of PixelImageFormat has been required, the a pointer to input image wich has been AddRef.
   * Returns NULL if failed.
   */
  static CATPixelImage* CenterAndFitInRectangleByKeepingRatio(CATPixelImage& iImage, int iWidthRect, int iHeightRect, CATMMPIPixelColor* iOptBackgroundColor=NULL);
};

#endif
