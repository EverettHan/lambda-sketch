// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIPLMCompImportTransaction.h
// Define the CATIPLMCompImportTransaction interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  Mai 2007  Creation: tbf
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompImportTransaction_H
#define CATIPLMCompImportTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATListPtrCATPLMStreamDescriptor.h"
#include "CATVVSUrl.h"
#include "CATListValCATPLMSDId.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompImportTransaction;
#else
extern "C" const IID IID_CATIPLMCompImportTransaction ;
#endif

//------------------------------------------------------------------

class CATIPLMCompImportRecordWrite;
class CATIPLMCompRecordReadSet;
class CATPLMID;
class CATUnicodeString;
class CATPLMCEStamp;
class CATVVSTransaction;
class CATListValCATPLMID;
class CATVVSUrl;
class CATLISTV;
class CATPLMTLogEntry;
class CATPLMTEvent;
class CATPLMFlatTableRowToWrite;
class CATOmxKeyString;
class CATOmxAny;

/**
 * Interface belonging to the <b>Component services</b>.
 * Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
 *
 * CATIPLMCompImportTransaction  manages the list of record (the table of data).
 * The Import message can be seen as a set of Record and in a record through the CATIPLMCompRecordWrite interface,  you will perform new versionning of Object.
 */
class ExportedByCATPLMServicesItf CATIPLMCompImportTransaction: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
   /**
  * Returns the URls of the transaction. This name can be used by error software to index the error stack (see CATIPLMErrorStack.h)
  *
  * @param ioSDIdList
  *
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT GetURLs ( CATLISTV(CATPLMSDId) &ioSDIdList) = 0;

  /**
  * Creates the next CATIPLMCompImportRecordWrite corresponding to the given CATPlmID.
  * through the CATIPLMCompImportRecordWrite interface, you can perform all your Updates/Creations/Deletions of Object.
  *
  * @param  iId
  *     The CATPlmID of the object to modify within the RecordWrite.
  * @param  oRecordWrite [out, CATBaseUnknown#Release]
  *     The new CATIPLMCompImportRecordWrite object.
  * @param  iOnEvent
  *     Event associated (if any) to the RecordWrite.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompImportRecordWrite ** oRecordWrite) = 0;
  
  /**
  * Creates a new section that can be seen as a whole of RecordWrite,
  * ie Insert a delimiter characters into the import message to separate whole of Records.
  * 
  * @param  iPLMIdList [in, CATLISTV(CATPLMID)]
  *
  * @param  oStamp  [out, CATPLMCEStamp]
  *
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT GetCEStamp (const CATLISTV(CATPLMID)& iPLMIdList, CATPLMCEStamp& oStamp) = 0;

  /**
  *
  *	@param  oCATVVSTsansaction [out, CATBaseUnknown#Release]
  *			Provides access to the list of Transaction
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
  virtual HRESULT GetVVSTransaction(CATVVSTransaction *& oCATVVSTsansaction) = 0;

  /**
  * As soon as the commit step has failed, you can rollback the PDM using this service..
  * @param  iImportHandler
  *
  * @param  oRecordReportSet [out, CATBaseUnknown]
  *  (*oRecordReportSet)->Release()
  *
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>rollback is successfully.</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>nothing to rollback.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Import(CATIPLMCompRecordReadSet ** oRecordReportSet) = 0;

  /**
  * Add a log entry to be saved within the transaction.
  * WARNING: All events must be logged before the first call to Next method...
  * @return
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Log entry added successfully.</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>Log entry not added.</dd>
  *   </dl>
  */
  virtual HRESULT AddLogEntry(CATPLMTLogEntry *iLogEntry) = 0;

  /*
  * Ability given to add a row of flattable in a save transaction
  */
  virtual HRESULT AddFlatTableRow(const CATPLMFlatTableRowToWrite& iFTR) = 0;

  /*
  * Add in body of request BEFORE SET CONTEXT (...) some specific parameters.
  * Those specific parameters activate or not some triggers server side.
  *
  * BE CAREFUL (Import transaction):
  * Those specific parameters appears when Import transaction is sent to server (eg: On M1, 00XY+1_ImportProcessor.vplmsession is filled with parameters).
  *
  * BE CAREFUL:
  * SetCustomizedParameters must be called before first call to AddFlatTableRow and/or Next
  *
  *
  * @param iName
  *  iName can be "customdata" or "customlisteners" or customtransactionparameters
  * @param iKey
     (key_1, value_1),..., (key_N, value_N)
     iKey is used for key_1,...,key_N
  * @param iValue
     (key_1, value_1),..., (key_N, value_N)
     iValue is used for value_1,...,value_N
  */
  virtual HRESULT SetCustomizedParameters(const CATUnicodeString& iName, const CATOmxKeyString& iKey, const CATOmxAny& iValue) = 0;
};

//------------------------------------------------------------------

#endif
