#ifndef CATAdpExtensionsAdaptor_H
#define CATAdpExtensionsAdaptor_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATIAdpExtensions.h"
#include "CATListOfCATString.h"
class CATPLMTypeHArray;

class OMX_DEPRECATED("obsolete internal protocol") CATAdpExtensionsAdaptor : public CATIAdpExtensions
{
public:
  HRESULT GetPLMExtensionTypes(CATPLMTypeHArray & oPLMExtensions) { return S_OK; }
};

//-----------------------------------------------------------------------

#endif
