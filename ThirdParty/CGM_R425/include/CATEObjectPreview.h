/* -*-c++-*- */
#ifndef _CATEObjectPreview_h
#define _CATEObjectPreview_h
// COPYRIGHT DASSAULT SYSTEMES 2002, All rights reserved
//--------------------------------------------------------------------------
// Object Preview Access
//--------------------------------------------------------------------------

#include "CATInteractiveInterfaces.h"
#include "CATIObjectPreview.h"

class CATPixelImage;

/**
 * Default implementation for the interface <tt>CATIObjectPreview</tt>.
 */
// NOTICE for derived classes: CATEObjectPreview is a BOA adapter, so your derived class CATxxx must declare:
//   CATImplementClass(CATxxx, Implementation, CATIObjectPreview, CATNull);
//   CATImplementBOA(CATIObjectPreview, CATxxx);
// or
//   CATImplementClass(CATxxx, DataExtension, CATIObjectPreview, zzz);
//   CATImplementBOA(CATIObjectPreview, CATxxx);
// in the cpp instead of TIE_CATIObjectPreview(CATxxx).
class ExportedByCATInteractiveInterfaces CATEObjectPreview : public CATIObjectPreview
{
public:
  CATEObjectPreview();
  virtual ~CATEObjectPreview();

  // Interface CATIObjectPreview

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
  virtual HRESULT GetObjectPreview(float iWidth, float iHeight, CATPixelImage *& oPreview);
   
      /**
	*   Informs whether the preview is imbedded (S_OK) or not (S_FALSE)
	*   E_FAIL means that the information could not be retreived
	*/
  virtual HRESULT IsImbedded();

private:
  CATEObjectPreview(const CATEObjectPreview &Object); // Prohibited
  CATEObjectPreview &operator=(const CATEObjectPreview &Object); // Prohibited
};

#endif
