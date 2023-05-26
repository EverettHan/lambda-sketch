/* -*-c++-*- */
#ifndef CATIUserId_h
#define CATIUserId_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Required
  * 
  */

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "AC0XXLNK.h"
extern ExportedByAC0XXLNK IID IID_CATIUserId ;

/**
* Interface to access a container user identifier.
* <br> An implementation of this interface is supplied and you must use it as is. You should not reimplement it.

*/

class ExportedByAC0XXLNK CATIUserId : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

    /**
	 * Sets a user identifier to an applicative container.
	 * <br><b>Note:</b> This method should not be called on an applicative container for which the caller 
	 * is not responsible (ie an applicative container that the caller has created using the @href CATCreateApplicativeContainer global function) 
	 * By calling this method on an applicative container that doesn't belong to him, the caller can 
	 * corrupt the corresponding V5 document.
	 * @param iId
	 *         The identifier to associate with the container.
	 */	
    virtual void SetUserId (const CATUnicodeString&  iId ) = 0;

    /**
	 * Returns a user identifier of a container.
	 * @return 
	 *			The identifier of the container.
	 */	
    virtual CATUnicodeString GetUserId () = 0;


};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIUserId , CATBaseUnknown ) ;


#endif
