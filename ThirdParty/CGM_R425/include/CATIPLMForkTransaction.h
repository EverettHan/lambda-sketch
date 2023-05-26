/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMForkTransaction_H
#define CATIPLMForkTransaction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

extern ExportedByCATPLMServicesItf IID IID_CATIPLMForkTransaction;

class CATIPLMRecordReadSet;
class CATPLMCompForkInputs;

class ExportedByCATPLMServicesItf CATIPLMForkTransaction: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual HRESULT ExecuteForkRequest(const CATPLMCompForkInputs& iInputs,CATIPLMRecordReadSet*& oRecords) = 0;
};

//------------------------------------------------------------------

#endif
