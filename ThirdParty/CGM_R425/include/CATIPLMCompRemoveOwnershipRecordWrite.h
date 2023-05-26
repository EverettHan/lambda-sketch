// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMCompRemoveOwnershipRecordWrite.h
// Define the CATIPLMCompRemoveOwnershipRecordWrite interface
//
//===================================================================
//
// Usage notes:
// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMCompRemoveOwnershipTransaction.h
//
//===================================================================
//
// Usage notes:
//
//  June 2012  Creation: LFE
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompRemoveOwnershipRecordWrite_H
#define CATIPLMCompRemoveOwnershipRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompRemoveOwnershipRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompRemoveOwnershipRecordWrite ;
#endif
//------------------------------------------------------------------

class CATPLMID;
class CATUnicodeString;

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to change ownership of an object.
* This operation can be done under the control of a transaction of the PDM(s). 
*/
class ExportedByCATPLMServicesItf CATIPLMCompRemoveOwnershipRecordWrite: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	 * Returns the CATPlmId of this Record (of the current object). 
	 * @param  oId
	 *    The PLMId of the object to modify
	 * @return
	 *    Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>successfully.</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	 *   </dl>
	 */ 
	virtual HRESULT GetPLMId(CATPLMID &oId) = 0;

	/**
	 * Remove a defined access ownership from the object already identified.
	 * @param  iOrgName
	 *    Name of the Organization removed from the multi ownership vector.
	 *    The reserved string "-" means any Organization.
	 * @param  iProjectName
	 *    Name of the Project removed from the multi ownership vector.
	 *    The reserved string "-" means any Project.
	 *    For workspace membership this project is the project of the user's Grant security context.
	 * @param  iComment
	 *    The same free string that identified this ownership item when it was first added.
	 * @return
	 *    Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dt>S_FALSE</dt>
	 *     <dd>The input Identifier does not represent an object belonging to the PDM associated to the transaction.</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	 *   </dl>
	 */ 
	virtual HRESULT RemoveOwnership(const CATUnicodeString &iOrgName, const CATUnicodeString &iProjectName, const CATUnicodeString &iComment) = 0;

	/**
	 * Remove an inherited ownership from the object already identified.
	 * @param  iId
	 *    Identifier of the object removed from the multi ownership vector and from which the ownership was inherited.
	 * @param  iComment
	 *    The same free string that identified this ownership item when it was first added.
	 * @return
	 *    Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dt>S_FALSE</dt>
	 *     <dd>The input Identifier does not represent an object belonging to the PDM associated to the transaction.</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	 *   </dl>
	 */ 
	virtual HRESULT RemoveOwnership(const CATPLMID &iId, const CATUnicodeString &iComment) = 0;
};
//------------------------------------------------------------------
#endif
