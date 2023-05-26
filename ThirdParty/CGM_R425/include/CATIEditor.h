/* -*-c++-*- */
#ifndef CATIEditor_h
#define CATIEditor_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Protected
  * @usage U5
  */

#include "CATBaseUnknown.h"


class CATFrmEditor ;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIEditor ;

/**
* Interface to manage objects interactivelly.
* <br><b> Role: </b> this interface is dedicated to create and return the editor associated with the document.
* @see CATFrmEditor
*/

class ExportedByAD0XXBAS CATIEditor : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	/**
	* Returns the editor associated with the document.
	* <br><b> Note: </b> this method is called in File/New or File/Open dialog box.
	*/
  virtual CATFrmEditor* GetEditor ()=0 ;
};

CATDeclareHandler (CATIEditor,CATBaseUnknown) ;

#endif



