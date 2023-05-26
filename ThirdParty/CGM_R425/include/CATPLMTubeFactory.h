#ifndef CATPLMTubeFactory_h
#define CATPLMTubeFactory_h

#include "IUnknown.h" 
#include "CATPLMServicesItf.h"

class CATHashDico;
class CATIComSidlStreamTube;
class ExportedByCATPLMServicesItf CATPLMTubeFactory
{
public:
  static HRESULT CreateTube(CATHashDico *iConnectionParameters,CATIComSidlStreamTube**oTrs);
};
#endif
