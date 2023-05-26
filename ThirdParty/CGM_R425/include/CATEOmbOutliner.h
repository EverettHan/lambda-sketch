#ifndef CATEOmbOutliner_H
#define CATEOmbOutliner_H

#include "CATIOmbOutliner.h"
#include "IUnknown.h"
#include "CATBaseUnknown.h"
#include "CATOmxKeyValueBlock.h"
#include "CATSysErrorDef.h"

class CATEOmbOutliner : public CATIOmbOutliner
{
public:
  HRESULT GetOutlinedData(CATBaseUnknown const * iComponent, CATOmxKeyValueBlock& oBlock){return E_NOTIMPL;}
};

#endif
