// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//
// CATIOmbPortNamingInterface.h
// Define the CATIOmbPortNamingInterface interface
//
//===================================================================
//
// Usage notes:
//	The interface is implemented by the ports to retrieve their name
//
//===================================================================
//
//	Nov 2006	Creation: LPQ

/**
 * @level Private
 * @usage U3
 */

#ifndef CATIOmbPortNamingInterface_H
#define CATIOmbPortNamingInterface_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbPortNamingInterface;
#else
extern "C" const IID IID_CATIOmbPortNamingInterface;
#endif

/**
 * Interface dedicated to provide OMB with an access to the name of a port
 */
class ExportedByCATObjectModelerBase CATIOmbPortNamingInterface : public CATBaseUnknown
{
	CATDeclareInterface;

public:
	/**
	 * Returns the name of a port
	 * <b>Role</b>:<br>
	 * Two ports are functionally equivalent, if they have the same name. The name returned by this
	 * method is used for this equivalent.
	 *
	 * @param oName
	 *		The functional name
	 * @returns
	 *		E_FAIL if problem
	 */
	virtual HRESULT GetPortName( CATUnicodeString &oName ) const = 0;
};

CATDeclareHandler( CATIOmbPortNamingInterface, CATBaseUnknown );

#endif

