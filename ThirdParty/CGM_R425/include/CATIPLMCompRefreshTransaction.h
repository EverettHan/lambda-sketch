// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCompRefreshTransaction.h
// Define the CATIPLMCompRefreshTransaction interface
//
//===================================================================
//
// Usage notes:
//   New interface:
//    During a PLMCOPY, instances and references are explicitely given
//    Completion is called on the server side to get port and connection
//    For each object given (instance or reference), we specify options:
//    KeepOwnership,KeepLock,KeepMaturity,KeepVersioning.
//
//    During a PLMCLONE, completion is called on the server side to retrive
//    all objects.
//===================================================================
//
// June 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMCompRefreshTransaction_H
#define CATIPLMCompRefreshTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompRefreshTransaction;
#else
extern "C" const IID IID_CATIPLMCompRefreshTransaction ;
#endif

class CATIPLMCompRefreshRecordWrite;
class CATPLMID;
// class CATTime;
class CATUnicodeString;
class CATIPLMCompRecordReadSet;
class CATIPLMCompRefreshRecordWrite;

/**
 * Interface belonging to the <b>Component services</b>.
 * Using this level of abstraction you manipulate only Component Id without knowing the PDM it belongs to.<br>
 *
 * CATIPLMCompRefreshTransaction  manages the list of record (the table of data).
 * The copy message can be seen as a set of Record.
*/
class ExportedByCATPLMServicesItf CATIPLMCompRefreshTransaction: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
  * Returns the name of the transaction. This name can be used by error software to index the error stack (see CATIPLMErrorStack.h)
  * @param oName
  *   The name
  */
  virtual HRESULT GetName ( CATUnicodeString & oName) = 0;


  /**
  * Accepts that the target object is not part of the family of the BasId.
  * By default, the logicalId of the target and the Base must be equal.
  *  virtual HRESULT DontCheckFamily ( ) = 0;
  */

  /**
  * Sets the Applicability Date associated to the transaction.
  * @param  iValue
  *     The CATTime corresponding to Applicabilitydate.
  *     The provided date must be between 1970 and 2038.
  */
  // virtual HRESULT SetApplicabilityDate(const CATTime & iValue) = 0;

  /**
  * Sets the Action associated to the transaction.
  * Should be done before any ::Next statement to make sure that streaming can be acheived.
  * @param  iId
  *     The CATPlmID of the action.
  */
  // virtual HRESULT SetAction(const CATPLMID & iId) = 0;

  /**
  * Creates the next CATIPLMCompRefreshRecordWrite.
  *
  * @param  iTargetId
  *     The CATPlmID of the object to modify.
  * @param oRecordWrite
  *     The new CATIPLMCompCopyRecordWrite object.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt><dd>successfully</dd>
  *     <dt>E_FAIL</dt><dd>A problem occurs during the operation.</dd>
  *     <dt>E_UNEXPECTED </dt><dd>Integrity test: we only support PLMCoreInstance,PLMCoreRepInstance,PLMCoreReference,PLMCoreRepReference during a PLMCopy transaction, if you pass the iId of a connection or a port, E_UNEXPECTED</dd>
  *     <dt>E_FAIL</dt><dd>oRecordWrite==NULL<dd>
  *   </dl>
  */
  virtual HRESULT Next ( CATPLMID &iTargetId, CATIPLMCompRefreshRecordWrite* & oRecordWrite) = 0;

  /**
  * Execute all the operations included in the transaction. 
  * 
  * This method returns a CATIPLMCompRecordReadSet which allows accessing to the return message. 
  * By calling Next method, analyse the report on each Operation (record) done.
  *
  * @param  oRecordReportSet [out, CATBaseUnknown#Release]
  *     Provides access to the list of record.(The message)
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
  virtual HRESULT ExecuteRefreshRequest(CATIPLMCompRecordReadSet* & oRecordReportSet) = 0;

};

#endif
