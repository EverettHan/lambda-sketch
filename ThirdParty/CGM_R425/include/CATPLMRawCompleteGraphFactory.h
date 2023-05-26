#ifndef CATPLMRawCompleteGraphFactory_h
#define CATPLMRawCompleteGraphFactory_h

#include "CATPLMIntegrationInterfaces.h"

class ExportedByCATPLMIntegrationInterfaces CATPLMRawCompleteGraphFactory
{
private:
  friend class CATPLMSessionImageManagerImpl;
  friend class PLMPosUtil;
  static HRESULT GetRawCompleteGraph(CATIPLMCompleteGraph *& oCGraph);
};
#endif

