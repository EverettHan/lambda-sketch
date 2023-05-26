/* -*-c++-*- */
#ifndef CATIAscendant_h
#define CATIAscendant_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Protected
* @usage U5
*/

#include "CATBaseUnknown.h"
#include "AC0XXLNK.h"



extern ExportedByAC0XXLNK IID IID_CATIAscendant ;

/**
* Interface to manage ascendant relation.
*/

class ExportedByAC0XXLNK CATIAscendant : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	/**
	* Returns parent in object's hierarchy.
	*/
	virtual CATBaseUnknown_var GetFather () = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIAscendant, CATBaseUnknown ) ;


#endif
