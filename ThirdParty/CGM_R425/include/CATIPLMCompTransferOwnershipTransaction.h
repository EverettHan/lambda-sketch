// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMCompTransferOwnershipTransaction.h
// Define the CATIPLMCompTransferOwnershipTransaction interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2011  Creation: FBN
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompTransferOwnershipTransaction_H
#define CATIPLMCompTransferOwnershipTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompTransferOwnershipTransaction;
#else
extern "C" const IID IID_CATIPLMCompTransferOwnershipTransaction ;
#endif

class CATIPLMCompAddOwnershipRecordWrite;
class CATIPLMCompRemoveOwnershipRecordWrite;
class CATIPLMCompTransferOwnershipRecordWrite;
class CATPLMID;
class CATUnicodeString;
class CATIPLMCompRecordReadSet;
//------------------------------------------------------------------

/**
 * Interface belonging to the <b>Component services</b>.
 * Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
 *
 * CATIPLMCompTransferOwnershipTransaction  manages the list of record (the table of data).
 * The Transfer Ownership message can be seen as a set of Record and in a record through the CATIPLMCompTransferOwnershipRecordWrite interface.
 */
class ExportedByCATPLMServicesItf CATIPLMCompTransferOwnershipTransaction: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	 * Returns the name of the transaction. This name can be used by error software to index the error stack (see CATIPLMErrorStack.h)
	 * @param oName
	 *   The name
	 */
	virtual HRESULT GetName(CATUnicodeString &oName) = 0;

	/**
	 * Creates the next CATIPLMCompAddOwnershipRecordWrite corresponding to the given CATPlmID.
	 * through the CATIPLMCompAddOwnershipRecordWrite interface, you can add multi ownership to an Object.
	 *
	 *	@param  iId
	 *			The CATPlmID of the object to modify within the RecordWrite.
	 *	@param  oRecordWrite [out, CATBaseUnknown#Release]
	 *			The new CATIPLMCompAddOwnershipRecordWrite object.
	 * @return
	 *   Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>successfully</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	 *   </dl>
	 */
	virtual HRESULT Next(const CATPLMID &iId, CATIPLMCompAddOwnershipRecordWrite *&oRecordWrite) = 0;

	/**
	 * Creates the next CATIPLMCompRemoveOwnershipRecordWrite corresponding to the given CATPlmID.
	 * through the CATIPLMCompRemoveOwnershipRecordWrite interface, you can remove multi ownership from an Object.
	 *
	 *	@param  iId
	 *			The CATPlmID of the object to modify within the RecordWrite.
	 *	@param  oRecordWrite [out, CATBaseUnknown#Release]
	 *			The new CATIPLMCompRemoveOwnershipRecordWrite object.
	 * @return
	 *   Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>successfully</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	 *   </dl>
	 */
	virtual HRESULT Next(const CATPLMID &iId, CATIPLMCompRemoveOwnershipRecordWrite *&oRecordWrite) = 0;

	/**
	 * Creates the next CATIPLMCompTransferOwnershipRecordWrite corresponding to the given CATPlmID.
	 * through the CATIPLMCompTransferOwnershipRecordWrite interface, you can transfert ownership of an Object.
	 *
	 *	@param  iId
	 *			The CATPlmID of the object to modify within the RecordWrite.
	 *	@param  oRecordWrite [out, CATBaseUnknown#Release]
	 *			The new CATIPLMCompTransferOwnershipRecordWrite object.
	 * @return
	 *   Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>successfully</dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	 *   </dl>
	 */
	virtual HRESULT Next(const CATPLMID &iId, CATIPLMCompTransferOwnershipRecordWrite *&oRecordWrite) = 0;

	/**
	 * Execute all the lock or unlock operations included in the transaction. 
	 * 
	 * This method returns a CATIPLMCompRecordReadSet which allows accessing to the return message. 
	 * By calling Next method, analyse the report on each Operation (record) done.
	 *
	 *	@param  oRecordReportSet [out, CATBaseUnknown#Release]
	 *			Provides access to the list of record.(The message)
	 * @return
	 *   Error code of function :
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>Save is successfully.</dd>
	 *     <dt>S_FALSE</dt>
	 *     <dd>Save entirely or partially failed. A report is available.
	 *     Get further information by using CATIPLMCompRecordReadSet returned
	 *     </dd>
	 *     <dt>E_FAIL </dt>
	 *     <dd>A fatal communication problem occurs during the operation.
	 *     Get further information by using CATIPLMErrorStack</dd>
	 *   </dl>
	 */
	virtual HRESULT ExecuteTransferOwnershipRequest(CATIPLMCompRecordReadSet *&oRecordReportSet) = 0;

  /**
  * Sets the Workspace associated to the transaction.
  * Should be done before any ::Next statement to make sure that streaming can be acheived.
  *	@param  iId
  *			The CATPlmID of the workspace.
  */
  virtual HRESULT SetWorkspace(const CATPLMID & iWorkspace) = 0;
};
//------------------------------------------------------------------
#endif
