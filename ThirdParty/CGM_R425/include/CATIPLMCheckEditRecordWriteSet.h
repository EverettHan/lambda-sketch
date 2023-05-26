// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMCheckEditRecordWriteSet.h
// Define the CATIPLMCheckEditRecordWriteSet interface
//
//  Oct 2006  Creation:  BHG
//===================================================================

#ifndef CATIPLMCheckEditRecordWriteSet_H
#define CATIPLMCheckEditRecordWriteSet_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATIPLMCompCheckEditTransaction.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCheckEditRecordWriteSet;
#else
extern "C" const IID IID_CATIPLMCheckEditRecordWriteSet ;
#endif

//------------------------------------------------------------------
/**
* @level Protected
* @usage U3
*/
class CATIPLMCompCheckEditRecordWrite;
class CATPLMID;

/**
 * CATIPLMRecordWriteSet  manages the list of record (the table of data).
 * The Check Editability message can be seen as a set of Record. <br>

 * The <code>Next(..)</code> method is used to move to the next record of the RecordSet, making the next record become the current record.
 * you will perform Check Editability in the current record.
 * When you will be finished, you will Save()/Commit() on CATIPLMTransaction.
 */
class ExportedByCATPLMServicesItf CATIPLMCheckEditRecordWriteSet: public CATBaseUnknown
{
	CATDeclareInterface;

public:
  /** 
  * Sets the lock attribute for all record write of this set.
  * @param iLockMode [in]
  *   The lock mode of the transaction.
  *
  * @return
	*   Error code of function :
	*   <dl>
	*     <dt>S_OK</dt>
	*     <dd>successfully</dd>
	*     <dt>E_FAIL </dt>
	*     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	*   </dl>
  */
  virtual HRESULT SetLockMode(CATPLMEditabilityLockMode iLockMode) =0;

	/**
	* Creates the next CATIPLMCompCheckEditRecordWrite corresponding to the given CATPlmID.
	* through the CATIPLMCompCheckEditRecordWrite interface, you can check the editabiliy of an Object.
	*
	*	@param  iId
	*			The CATPlmID of the object to check  within the RecordWrite.
	*	@param  oRecordWrite [out, CATBaseUnknown#Release]
	*			The new CATIPLMCompCheckEditRecordWrite object.
	* @return
	*   Error code of function :
	*   <dl>
	*     <dt>S_OK</dt>
	*     <dd>successfully</dd>
	*     <dt>E_FAIL </dt>
	*     <dd>A problem occurs during the operation. get further information by using CATIPLMErrorStack</dd>
	*   </dl>
	*/
	virtual HRESULT Next(const CATPLMID & iId, CATIPLMCompCheckEditRecordWrite** oRecordWrite) = 0;

};

//------------------------------------------------------------------

#endif
