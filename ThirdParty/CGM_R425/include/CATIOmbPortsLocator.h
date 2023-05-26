// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//
// CATIOmbPortsLocator.h
// Define the CATIOmbPortsLocator interface
//
//===================================================================
//
// Usage notes:
//	The interface is implemented by references to provide an access
//	to their aggregated ports 
//
//===================================================================
//
//	Nov 2006	Creation: LPQ

/**
 * @level Private
 * @usage U3
 */

#ifndef CATIOmbPortsLocator_H
#define CATIOmbPortsLocator_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATIOmbPortNamingInterface_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbPortsLocator;
#else
extern "C" const IID IID_CATIOmbPortsLocator;
#endif

/**
 * Interface dedicated to allow OMB to retrieve ports under a reference
 */
class ExportedByCATObjectModelerBase CATIOmbPortsLocator : public CATBaseUnknown
{
	CATDeclareInterface;

public:
	/**
	 * Find the port given its name in a resolution context
	 * <b>Role</b>:<br>
	 * This interface is implemented by a reference to provide access to the ports aggregated under it.
	 *
	 * @param iName
	 *		The functional name
	 * @param oPort
	 *		The port whose name is iName
	 * @returns
	 *		E_FAIL if no port of the given name could be found
	 */
	virtual HRESULT GetPortFromName( CATUnicodeString &iName, CATIOmbPortNamingInterface_var &opPort ) = 0;
};

CATDeclareHandler( CATIOmbPortsLocator, CATBaseUnknown );

#endif

