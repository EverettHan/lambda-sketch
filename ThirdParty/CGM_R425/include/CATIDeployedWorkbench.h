// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIDeployedWorkbench.h
// Define the CATIDeployedWorkbench interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2005  Creation: Code generated by the CAA wizard  PHB
//===================================================================
#ifndef CATIDeployedWorkbench_H
#define CATIDeployedWorkbench_H

/**
* @level Protected
* @usage U3 
*/

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIDeployedWorkbench;
#else
extern "C" const IID IID_CATIDeployedWorkbench ;
#endif

class CATIUserCategory;

//------------------------------------------------------------------
/**
* Interface representing a deployed workbench.
* <br>
* @see CATIDeployedWorkbenchesManager
*/
class ExportedByCATAfrItf CATIDeployedWorkbench: public CATBaseUnknown
{
	CATDeclareInterface;

public:
	/**
	* Retrieves the workbench identifier.
	* @param oId
	*	The identifier of the workbench
	* @return
	*	<b>S_OK</b> in case of success
	*/
	virtual HRESULT GetId( CATString& oId ) = 0;

	/**
	* Retrieves the workbench title.
	* @param oTitle
	*	The title of the workbench
	* @return
	*	<b>S_OK</b> in case of success
	*/
	virtual HRESULT GetTitle( CATUnicodeString&  oTitle  ) = 0;

	/**
	* Retrieves the workbench factory interface.
	* @param oFactoryItf
	*	The name of the workbench factory interface
	* @return
	*	<b>S_OK</b> in case of success
	*/
	virtual HRESULT GetFactoryInterface( CATString& oFactoryItf ) = 0;

	/**
	* Set the workbench factory interface.
	* @param iFactoryItf
	*	The name of the workbench factory interface
	* @return
	*	<b>S_OK</b> in case of success
	*	<b>E_FAIL</b> in case of failure
	*/
	virtual HRESULT SetFactoryInterface (const CATString&  iFactoryItf  ) = 0;

	/**
	* Retrieves the father workshop the workbench belongs to.
	* @param oFatherWshop
	*	The name of the father workshop
	* @return
	*	<b>S_OK</b> in case of success
	*/
	virtual HRESULT GetFatherWorkshop( CATString& oFatherWshop ) = 0;

	/**
	* Set the father workshop the workbench belongs to.
	* @param iFatherWshop
	*	The name of the father workshop
	* @return
	*	<b>S_OK</b> in case of success
	*	<b>E_FAIL</b> in case of failure
	*/
	virtual HRESULT SetFatherWorkshop( const CATString& iFatherWshop ) = 0;

	/**
	* Retrieves the workbench additional infos.
	* @param oNames
	*	The list of additional informations' names (<b><i>name</i></b>[i]=value[i])
	* @param oValues
	*	The list of additional informations' values (name[i]=<b><i>value</i></b>[i])
	* @return
	*	<b>S_OK</b> in case of success
	*/
	virtual HRESULT GetAdditionalInfos( CATListOfCATUnicodeString& oNames, CATListOfCATUnicodeString& oValues ) = 0;

	/**
	* Set the workbench additional infos.
	* @param iNames
	*	The list of additional informations' names (<b><i>name</i></b>[i]=value[i])
	* @param iValues
	*	The list of additional informations' values (name[i]=<b><i>value</i></b>[i])
	* @return
	*	<b>S_OK</b> in case of success
	*	<b>E_FAIL</b> in case of failure
	*/
	virtual HRESULT SetAdditionalInfos( const CATListOfCATUnicodeString& iNames, const CATListOfCATUnicodeString& iValues ) = 0;

	/**
	* Retrieves the user category the workbench belongs to.
	* @param oUC
	*	The user category
	* @return
	*	<b>S_OK</b> in case of success
	*	<b>E_FAIL</b> in case of failure
	*/
	virtual HRESULT GetUserCategory( CATIUserCategory*& oUC ) = 0;

	// No constructors or destructors on this pure virtual base class
	// --------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler (CATIDeployedWorkbench, CATBaseUnknown);

#endif
