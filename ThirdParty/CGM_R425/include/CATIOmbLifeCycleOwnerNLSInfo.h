// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbLifeCycleOwnerNLSInfo.h
// Define the CATIOmbLifeCycleOwnerNLSInfo interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jan 2006  Creation: Code generated by the CAA wizard  fsd
//===================================================================
#ifndef CATIOmbLifeCycleOwnerNLSInfo_H
#define CATIOmbLifeCycleOwnerNLSInfo_H

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATOmbLifeCycleOwnerNLSAdapter
 */

#include "CATOmbLifeCycle.h"
#include "CATBaseUnknown.h"
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbLifeCycle IID IID_CATIOmbLifeCycleOwnerNLSInfo;
#else
extern "C" const IID IID_CATIOmbLifeCycleOwnerNLSInfo ;
#endif

//------------------------------------------------------------------

/**
* Interface representing a NLS helper to LifeCycle error messages.
* <p><b>BOA information</b>: this interface must be implemented
* using the BOA (Basic Object Adapter).
* To know more about the BOA, refer to the CAA Encyclopedia home page.
* Click Middleware at the bottom left, then click the Object Modeler tab page.
* Several articles deal with the BOA.</p>
*/
class ExportedByCATOmbLifeCycle CATIOmbLifeCycleOwnerNLSInfo: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Give a NLS name to the what forbids a Remove/Unload operation.
    * @param oName
	*        NLS name.
	* @return
	* <ul>
	*   <li><tt>S_OK</tt></li>
	* </ul>
	*/
	virtual HRESULT GetName( CATUnicodeString & oName ) = 0;
	/**
	* Explain how the forbidden lifecycle operation can become allowed.
	* @param oMethod
	*        NLS explanation.
	* @return
	* <ul>
	*   <li><tt>S_OK</tt></li>
	* </ul>
	*/
	virtual HRESULT GetClosureMethod( CATUnicodeString & oMethod ) = 0;

	// No constructors or destructors on this pure virtual base class
	// --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif