// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATIPLMIterationRecordWriteSet.h
// Define the CATIPLMNewVersionRecordWriteSet interface
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
#ifndef CATIPLMIterationRecordWriteSet_H
#define CATIPLMIterationRecordWriteSet_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMIterationRecordWriteSet;
#else
extern "C" const IID IID_CATIPLMIterationRecordWriteSet ;
#endif

class CATIPLMCompIterationRecordWrite;
class CATPLMID;

/**
 * CATIPLMRecordWriteSet  manages the list of record (the table of data).
 * The NewVersion message can be seen as a set of Record. <br>

 * The <code>Next(..)</code> method is used to move to the next record of the RecordSet, making the next record become the current record.
 * you will perform newVersion in the current record.
 * When you will be finished, you will Save()/Commit() on CATIPLMTransaction.
 */
class ExportedByCATPLMServicesItf CATIPLMIterationRecordWriteSet: public CATBaseUnknown
{
  CATDeclareInterface;

public:
 /**
  * Creates the next RecordWrite corresponding to the given CATPlmID, making this record become the current record.
  *	@param  iId
  *			The CATPlmID of the object to modify.
  * @param pWrite [out, CATBaseUnknown#Release]
  *         next record
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIImmErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Next (const CATPLMID & iId, CATIPLMCompIterationRecordWrite *&pWrite) = 0;

  virtual HRESULT SetWorkspace (const CATPLMID &  iId) = 0;

  virtual HRESULT SetActionID(const CATPLMID& iActionID) = 0;
};

#endif
