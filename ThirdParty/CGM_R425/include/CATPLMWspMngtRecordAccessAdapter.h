#ifndef CATPLMWspMngtRecordAccessAdapter_H
#define CATPLMWspMngtRecordAccessAdapter_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Protected
* @usage U3
*/

#include "CATIPLMWspMngtRecordAccess.h"

#include "CATPLMImplAdapterClass.h"

class ExportedByCATPLMImplAdapterClass CATPLMWspMngtRecordAccessAdapter : public CATIPLMWspMngtRecordAccess
{
public:

  CATPLMWspMngtRecordAccessAdapter ();
  virtual ~CATPLMWspMngtRecordAccessAdapter ();

  virtual HRESULT GetWspOperation (CATIPLMWspMngtRecordAccess::WspOperation &oOperation);
  virtual HRESULT GetWspPLMId (CATPLMID &oWspPLMID, CATBoolean &oIsImpactedByOperation);
  virtual HRESULT GetRefPLMId (CATPLMID &oRefPLMID, CATBoolean &oIsImpactedByOperation);

private:
  CATPLMWspMngtRecordAccessAdapter (CATPLMWspMngtRecordAccessAdapter &);
  CATPLMWspMngtRecordAccessAdapter& operator=(CATPLMWspMngtRecordAccessAdapter&);
};

#endif
