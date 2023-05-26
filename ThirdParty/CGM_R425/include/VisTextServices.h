//===================================================================
// COPYRIGHT Dassault Systemes 2022-10-14
//===================================================================

#ifndef VISTEXTSERVICES_H
#define VISTEXTSERVICES_H

#include "IUnknown.h"
#include "SGInfra.h"
#include "CATFreeTypeTextGP.h"
#include <vector>

class CAT2DAnnotationTextGP;
class CAT3DAnnotationTextGP;
class l_VisTextServices;
class CATPixelImage;

class ExportedBySGInfra VisTextServices
{
public:
  /*
  * For the zoom effect on AnnotationTextGP it is implemented by fixed sizes of font height.
  * This function outputs multiple CATPixelImage in different font height from input CAT2DAnnotationTextGP.
  * @param iGP
  *   Input CAT2DAnnotationTextGP
  * @param oPixelImage
  *   Output std::vector of CATPixelImage pointers
  */
  static HRESULT Get2DAnnotationImages(CAT2DAnnotationTextGP* iGP, std::vector<CATPixelImage*>& oPixelImages);
  /*
  * For the zoom effect on AnnotationTextGP it is implemented by fixed sizes of font height.
  * This function outputs multiple CATPixelImage in different font height from input CAT3DAnnotationTextGP.
  * @param iGP
  *   Input CAT3DAnnotationTextGP
  * @param oPixelImage
  *   Output std::vector of CATPixelImage pointers
  */
  static HRESULT Get3DAnnotationImages(CAT3DAnnotationTextGP* iGP, std::vector<CATPixelImage*>& oPixelImages);

  /*
  * This function outputs CATPixelImage from input FreeTypeTextGP.
  * @param iGP
  *   Input CATFreeTypeTextGP
  * @param oPixelImage
  *   Output CATPixelImage 
  * @param oWidth
  *   Output final width of the iamge to be stretched by application
  * @param oHeight
  *   Output final height of the image to be stretched by application
  */
  static HRESULT GetFreeTypeTextGPImages(CATFreeTypeTextGP* iGP, CATPixelImage*& oPixelImages, int &oWidth, int &oHeight);

private:
  VisTextServices() {};
  ~VisTextServices() {};
  static l_VisTextServices* pLVisTextServices;
};

//-----------------------------------------------------------------------

#endif
