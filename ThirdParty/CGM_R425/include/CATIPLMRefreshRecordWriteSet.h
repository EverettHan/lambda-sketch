#ifndef CATIPLMRefreshRecordWriteSet_H
#define CATIPLMRefreshRecordWriteSet_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#include "CATBaseUnknown.h"

#include "CATPLMServicesItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMRefreshRecordWriteSet;
#else
extern "C" const IID IID_CATIPLMRefreshRecordWriteSet ;
#endif

#include "CATIPLMCompTransactionService.h" // for enum

class CATIPLMCompRefreshRecordWrite;
class CATPLMID;

/**
 * CATIPLMRecordWriteSet  manages the list of record (the table of data).
 * The Clone message can be seen as a set of Record. <br>

 * The <code>Next(..)</code> method is used to move to the next record of the RecordSet, making the next record become the current record.
 * you will perform Clone in the current record.
 * When you will be finished, you will Save()/Commit() on CATIPLMTransaction.
 */
class ExportedByCATPLMServicesItf CATIPLMRefreshRecordWriteSet : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Creates the next CATIPLMCompRefreshRecordWrite corresponding to the given CATPlmID.
  * through the CATIPLMCompRefreshRecordWrite interface, you can synchronize or deliver an Object.
  *
  *	@param  oRecordWrite [out, CATBaseUnknown#Release]
  *			The new CATIPLMCompRefreshRecordWrite object.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompRefreshRecordWrite ** oRecordWrite) = 0;

};

#endif
