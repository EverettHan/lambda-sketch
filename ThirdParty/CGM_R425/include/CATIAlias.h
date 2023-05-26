/* -*-c++-*- */
#ifndef CATIAlias_h
#define CATIAlias_h


// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "CATOMY.h"
extern ExportedByCATOMY IID IID_CATIAlias ;

/**
* Interface to access the external name of an object.
*/
class ExportedByCATOMY CATIAlias : public CATBaseUnknown
{
  CATDeclareInterface;

    public:


    /**
	 * Sets an alias to the object.
	 * @param iName
	 *         alias to associate to the object.
	 */	
	virtual void SetAlias(const CATUnicodeString&  iName ) = 0;

    /**
	 * Returns alias of the object.
	 */	
    virtual CATUnicodeString GetAlias() = 0;


};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIAlias , CATBaseUnknown ) ;


#endif
