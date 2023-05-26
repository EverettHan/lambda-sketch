// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMCompIterationTransaction.h
// Define the CATIPLMCompIterationTransaction interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
// July 2012  Creation: EPB
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompIterationTransaction_H
#define CATIPLMCompIterationTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompIterationTransaction;
#else
extern "C" const IID IID_CATIPLMCompIterationTransaction ;
#endif

class CATIPLMCompIterationRecordWrite;
class CATPLMID;
class CATTime;
class CATUnicodeString;
class CATIPLMCompRecordReadSet;

/**
 * Interface belonging to the <b>Component services</b>.
 * Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
 *
 * CATIPLMCompIterationTransaction  manages the list of record (the table of data).
 * The NewVersion message can be seen as a set of Record and in a record through the CATIPLMCompRecordWrite interface,  you will perform new versionning of Object.
 */
class ExportedByCATPLMServicesItf CATIPLMCompIterationTransaction: public CATBaseUnknown
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
  * Creates the next CATIPLMCompNewVersionRecordWrite corresponding to the given CATPlmID.
  * through the CATIPLMCompNewVersionRecordWrite interface, you can perform new versionning of Object.
  *
  *	@param  iId
  *			The CATPlmID of the object to modify within the RecordWrite.
  *	@param  oRecordWrite [out, CATBaseUnknown#Release]
  *			The new CATIPLMCompNewVersionRecordWrite object.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompIterationRecordWrite *& oRecordWrite) = 0;

  /**
  * Save in the PDM all the NewVersion operations included in the transaction. 
  * 
  * Save method returns a CATIPLMCompRecordReadSet which allows accessing to the return message. 
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
  virtual HRESULT Execute(CATIPLMCompRecordReadSet ** oRecordReportSet) = 0;

  virtual HRESULT SetWorkspace(const CATPLMID &  iId) = 0;

  virtual HRESULT SetActionID(const CATPLMID &iActionID) = 0;
};


#endif
