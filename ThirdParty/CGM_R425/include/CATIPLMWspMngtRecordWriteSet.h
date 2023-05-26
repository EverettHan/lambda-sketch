#ifndef CATIPLMWspMngtRecordWriteSet_H
#define CATIPLMWspMngtRecordWriteSet_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#include "CATBaseUnknown.h"

#include "CATPLMServicesItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMWspMngtRecordWriteSet;
#else
extern "C" const IID IID_CATIPLMWspMngtRecordWriteSet ;
#endif

#include "CATIPLMCompTransactionService.h" // for enum

#include  "CATListOfCATUnicodeString.h"
class CATIPLMCompWspMngtRecordWrite;
class CATPLMID;

/**
 * CATIPLMRecordWriteSet  manages the list of record (the table of data).
 * The Clone message can be seen as a set of Record. <br>

 * The <code>Next(..)</code> method is used to move to the next record of the RecordSet, making the next record become the current record.
 * you will perform Clone in the current record.
 * When you will be finished, you will Save()/Commit() on CATIPLMTransaction.
 */
class ExportedByCATPLMServicesItf CATIPLMWspMngtRecordWriteSet : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Creates the next CATIPLMCompWspMngtRecordWrite corresponding to the given CATPlmID.
  * through the CATIPLMCompWspMngtRecordWrite interface, you can synchronize or deliver an Object.
  *
  *	@param  iId
  *			The CATPlmID of the object to modify within the RecordWrite.
  *     Mainly the workspace PLMID, but can be the reference PLMID for synchronize_Attach.
  *	@param  oRecordWrite [out, CATBaseUnknown#Release]
  *			The new CATIPLMCompWspMngtRecordWrite object.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompWspMngtRecordWrite ** oRecordWrite) = 0;

  virtual HRESULT InitWspMngtTrs (CATIPLMCompTransactionService::PLMWspMngtTrnsType iTransType,CATListOfCATUnicodeString& iHeaderParams) = 0;
};

#endif
