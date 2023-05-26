// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMCompAddOwnershipRecordWrite.h
// Define the CATIPLMCompAddOwnershipRecordWrite interface
//
//===================================================================
//
// Usage notes:
// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMCompAddOwnershipTransaction.h
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
#ifndef CATIPLMCompAddOwnershipRecordWrite_H
#define CATIPLMCompAddOwnershipRecordWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompAddOwnershipRecordWrite;
#else
extern "C" const IID IID_CATIPLMCompAddOwnershipRecordWrite ;
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
class ExportedByCATPLMServicesItf CATIPLMCompAddOwnershipRecordWrite: public CATBaseUnknown
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
	 * Add a new access ownership to the object already identified.
	 * @param  iOrgName
	 *    Name of the Organization added to the multi ownership vector.
	 *    The reserved string "-" means any Organization.
	 * @param  iProjectName
	 *    Name of the Project added to the multi ownership vector.
	 *    The reserved string "-" means any Project.
	 *    For workspace membership this project is the project of the user's Grant security context.
	 * @param  iComment
	 *    A free string describing the purpose of this new ownership item and allowing to identify it.
	 * @param  iAccesses
	 *    A comma separated list of security accesses defining the allowed rights for this new ownership.
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
	virtual HRESULT AddOwnership(const CATUnicodeString &iOrgName, const CATUnicodeString &iProjectName, const CATUnicodeString &iComment, const CATUnicodeString &iAccesses) = 0;

	/**
	 * Add an inherited ownership to the object already identified.
	 * @param  iId
	 *    Identifier of the object added to the multi ownership vector and from which the ownership is inherited.
	 * @param  iComment
	 *    A free string describing the purpose of this new ownership item and allowing to identify it.
	 * @param  iAccesses
	 *    A comma separated list of security accesses defining the allowed rights for this new ownership.
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
	virtual HRESULT AddOwnership(const CATPLMID &iId, const CATUnicodeString &iComment, const CATUnicodeString &iAccesses) = 0;
};
//------------------------------------------------------------------
#endif
