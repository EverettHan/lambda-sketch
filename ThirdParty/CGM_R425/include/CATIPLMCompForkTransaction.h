/**
* @level Protected
* @usage U3
*/

#ifndef CATIPLMCompForkTransaction_H
#define CATIPLMCompForkTransaction_H

// System
#include "CATBaseUnknown.h"
// CATPLMServices
#include "CATPLMServicesItf.h"

extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompForkTransaction;

class CATIPLMCompRecordReadSet;
class CATPLMCompForkInputs;

/**
 * PLMQL Fork operation
 */
class ExportedByCATPLMServicesItf CATIPLMCompForkTransaction: public CATBaseUnknown
{
	CATDeclareInterface;
public:
  virtual HRESULT SetForkInputs(const CATPLMCompForkInputs& ) = 0;

	/**
   * Execute PLMQL Fork operation on server
   */
	virtual HRESULT ExecuteForkRequest(CATIPLMCompRecordReadSet*& oRecords) = 0;
};

//------------------------------------------------------------------

#endif
