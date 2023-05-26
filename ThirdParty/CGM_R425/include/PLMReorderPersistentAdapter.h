#ifndef PLMReorderPersistentAdapter_H
#define PLMReorderPersistentAdapter_H

#include "CATPLMModelerBaseInterfaces.h"
#include "PLMIReorderPersistent.h"

class PLMReorderPersistentAdapter : public PLMIReorderPersistent
{
public:
  virtual HRESULT GetChildrenInPersistedOrder(PersistentReorderableType iReorderableType, CATListPtrCATIPLMComponent& oListOrderedChildren) { return E_NOTIMPL; }
  virtual HRESULT GetReorderableType(CATIPLMComponent* ipComponent, PersistentReorderableType& oReorderableType) { return E_NOTIMPL; }
};

#endif
