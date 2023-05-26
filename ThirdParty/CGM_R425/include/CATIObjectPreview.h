#ifndef CATIObjectPreview_H
#define CATIObjectPreview_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATInteractiveInterfaces.h"
#include "CATBaseUnknown.h"

class CATPixelImage;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIObjectPreview ;
#else
extern "C" const IID IID_CATIObjectPreview ;
#endif


class ExportedByCATInteractiveInterfaces CATIObjectPreview : public CATBaseUnknown
{
  CATDeclareInterface;

public:
      /**
	*   Constructs a preview of any object.
	*   @param iWidth
	*   The width of the returned image
	*   @param iHeigth
	*   The height of the returned image
	*   @param oPreview
	*   The preview as a CATPixelImage
	*   @return
	*   The eror code
	*/
  virtual HRESULT GetObjectPreview(float iWidth, float iHeight, CATPixelImage *& oPreview) = 0;
   
      /**
	*   Informs whether the preview is imbedded (S_OK) or not (S_FALSE)
	*   E_FAIL means that the information could not be retreived
	*/
  virtual HRESULT IsImbedded() = 0;

};
CATDeclareHandler(CATIObjectPreview, CATBaseUnknown);

#endif








