// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMCompApplyEventTransaction.h
// Define the CATIPLMCompApplyEventTransaction interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Apr 2005  Creation: Code generated by the CAA wizard  mqv
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompApplyEventTransaction_H
#define CATIPLMCompApplyEventTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompApplyEventTransaction;
#else
extern "C" const IID IID_CATIPLMCompApplyEventTransaction ;
#endif

class CATIPLMCompMaturityRecordWrite;
class CATPLMID;
class CATUnicodeString;
class CATLISTV(CATPLMMaturityInfo);
class CATLISTP(CATPLMMaturityInfo);
class CATIPLMError;
class CATPLMClientTasks;
//------------------------------------------------------------------

/**
 * Interface belonging to the <b>Component services</b>.
 * Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
 *
 * CATIPLMCompApplyEventTransaction  manages the list of record (the table of data).
 * The LockUnlock message can be seen as a set of Record and in a record through the CATIPLMCompLockUnlockRecordWrite interface,  you will lock or unlock an Object.
 */
class ExportedByCATPLMServicesItf CATIPLMCompApplyEventTransaction: public CATBaseUnknown
{
  CATDeclareInterface;

public:

 /**
  * Returns the name of the transaction. This name can be used by error software to index the error stack (see CATIPLMErrorStack.h)
  * @param oName
  *   The name
  */
  virtual HRESULT GetName ( CATUnicodeString **oName) = 0;

 /**
  * Creates the next CATIPLMCompMaturityRecordWrite corresponding to the given CATPlmID.
  * through the CATIPLMCompMaturityRecordWrite interface, you can set the maturity event to launch on the Object.
  *
  * @param  iId
  *     The CATPlmID of the object to modify within the RecordWrite.
  * @param  oRecordWrite [out, CATBaseUnknown#Release]
  *     The new CATIPLMCompMaturityRecordWrite object.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompMaturityRecordWrite ** oRecordWrite) = 0;
  
 /**
  * Execute all the maturity events operations included in the transaction.
  * 
  * This method returns a list of MaturityInfo which allows access to the returned elements.
  *
  * @param oMaturityInfo [out]
  *   The list of returned maturity info.
  * @param oGlobalReport [out, CATBaseUnknown#Release]
  *   The global report of the operation.
  * @return
  *   Error code of function :
  *   <dl>
  *    <dt> <code>S_OK</code>     <dd> Success. No global report found.
  *    <dt> <code>S_FALSE</code>  <dd> Failure. A global report was found.
  *    <dt> <code>E_FAIL</code>   <dd> A problem occurs during the transcation.
  *   </dl>
  */
  virtual HRESULT ExecuteApplyEventRequest(CATLISTP(CATPLMMaturityInfo)& oMaturityInfoList, CATIPLMError*& oGlobalReport, CATPLMClientTasks& oCT) = 0;
  // @deprecated
  virtual HRESULT ExecuteApplyEventRequest(CATLISTP(CATPLMMaturityInfo) &oMaturityInfoList , CATIPLMError** oGlobalReport) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif