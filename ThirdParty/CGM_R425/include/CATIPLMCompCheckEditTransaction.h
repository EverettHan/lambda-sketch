// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCompCheckEditTransaction.h
// Define the CCATIPLMCompCheckEditTransaction interface
//
//  Oct 2006  Creation:  BHG
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMCompCheckEditTransaction_H
#define CATIPLMCompCheckEditTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompCheckEditTransaction;
#else
extern "C" const IID IID_CATIPLMCompCheckEditTransaction ;
#endif

//------------------------------------------------------------------
class CATIPLMCompCheckEditRecordWrite;
class CATUnicodeString;
class CATIPLMCompRecordReadSet;
class CATPLMID;


/**
 * Lock mode of the CheckEditRules Transaction.
 */
typedef enum EditabilityLockMode
{
  /** PLMCHKEDIT_ONLY_EDITABLE: All editable objects of this transaction are locked . */
  PLMCHKEDIT_ONLY_EDITABLE = 1,
  /** PLMCHKEDIT_ALL_OR_NOTHING: Try to lock all editable objects of this transaction. If one of them is not editable, no object is locked*/
  PLMCHKEDIT_ALL_OR_NOTHING = 2,
  /** PLMCHKEDIT_NONE: No lock operation is performed on objects. */
  PLMCHKEDIT_NONE = 3
} CATPLMEditabilityLockMode;


/**
 * Interface belonging to the <b>Component services</b>.
 * Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
 *
 * CATIPLMCompCheckEditTransaction  manages the list of record (the table of data).
 * The CheckEdit message can be seen as a set of Record and in a record through the CATIPLMCompCheckEditRecordWrite interface,  you will check Edit rules of the Object.
*/
class ExportedByCATPLMServicesItf CATIPLMCompCheckEditTransaction: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	*	Returns the name of the transaction. This name can be used by error software to index the error stack (see CATIPLMErrorStack.h)
	* @param oName
	*   The name
	*/
	virtual HRESULT GetName ( CATUnicodeString **oName) = 0;

	/**
	* Creates the next CATIPLMCompDeleteRefRecordWrite corresponding to the given CATPlmID.
	* through the CATIPLMCompDeleteRefRecordWrite interface, you can lock or unlock an Object.
	*
	*	@param  iId
	*			The CATPlmID of the object to modify within the RecordWrite.
	*	@param  oRecordWrite [out, CATBaseUnknown#Release]
	*			The new CATIPLMCompDeleteRefRecordWrite object.
	* @return
	*   Error code of function :
	*   <dl>
	*     <dt>S_OK</dt>
	*     <dd>successfully</dd>
	*     <dt>E_FAIL </dt>
	*     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	*   </dl>
	*/
	virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompCheckEditRecordWrite ** oRecordWrite) = 0;

	/**
	* Execute all the DeleteRef operations included in the transaction. 
	* 
	* This method returns a CATIPLMCompRecordReadSet which allows accessing to the return message. 
	* By calling Next method, analyse the report on each Operation (record) done.
	*
	*	@param  oRecordReadtSet [out, CATBaseUnknown#Release]
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
	virtual HRESULT ExecuteCheckEditabilityRequest(CATIPLMCompRecordReadSet** oRecordReportSet) = 0;
};

//------------------------------------------------------------------

#endif
