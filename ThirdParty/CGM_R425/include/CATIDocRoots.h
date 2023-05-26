/* -*-c++-*- */
#ifndef CATIDocRoots_h
#define CATIDocRoots_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Protected
  * @usage U3
  */

#include "CATBaseUnknown_var.h"
class CATListValCATBaseUnknown_var;
#include "AD0XXBAS.h"

extern ExportedByAD0XXBAS IID IID_CATIDocRoots ;

/**
* Interface allowing access to document's root element.
* <b> Note: </b> V5 documents should not implement
* this interface which is only used for import in ProductStructure.
* <br> To get the root element of a document, use GetRootContainer of CATInit.
*
* @see CATInit
*/

class ExportedByAD0XXBAS CATIDocRoots : public CATBaseUnknown
{
  CATDeclareInterface;

public:
    /**
	* Returns the root element.
	* @return
	*      it's suppose to return a list of objects, but nowadays there
	*      is only one root in each document and it's the first element returned
	*      in the list.
	*/
	virtual CATListValCATBaseUnknown_var* GiveDocRoots() =0 ;
    
	/** @nodoc */
	virtual void                          FeedDocRoots(CATBaseUnknown_var root)=0 ;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDocRoots, CATBaseUnknown ) ;


#endif
