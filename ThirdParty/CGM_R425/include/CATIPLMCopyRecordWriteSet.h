// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCopyRecordWriteSet.h
// Define the CATIPLMCopyRecordWriteSet interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2006  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCopyRecordWriteSet_H
#define CATIPLMCopyRecordWriteSet_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#include "CATBoolean.h"
#include "CATPLMQLCommand.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCopyRecordWriteSet;
#else
extern "C" const IID IID_CATIPLMCopyRecordWriteSet;
#endif

class CATIPLMCompCopyRecordWrite;
class CATPLMID;

/**
 * CATIPLMRecordWriteSet  manages the list of record (the table of data).
 * The Clone message can be seen as a set of Record. <br>

 * The <code>Next(..)</code> method is used to move to the next record of the RecordSet, making the next record become the current record.
 * you will perform Clone in the current record.
 * When you will be finished, you will Save()/Commit() on CATIPLMTransaction.
 */
class ExportedByCATPLMServicesItf CATIPLMCopyRecordWriteSet : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT Init(CATPLMQLCommand iCommand) = 0;

  virtual HRESULT KeepFamily() = 0;

  /**
  * Creates the next CATIPLMCompCopyRecordWrite corresponding to the given CATPlmID.
  * through the CATIPLMCompCopyRecordWrite interface, you can lock or unlock an Object.
  *
  *	@param  iId
  *			The CATPlmID of the object to modify within the RecordWrite.
  *	@param  oRecordWrite [out, CATBaseUnknown#Release]
  *			The new CATIPLMCompCopyRecordWrite object.
  * @return
  *   Error code of function :
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>successfully</dd>
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
  *   </dl>
  */
  virtual HRESULT Next(const CATPLMID & iId,
    CATIPLMCompCopyRecordWrite* & oRecordWrite) = 0;

};

#endif