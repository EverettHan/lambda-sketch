#ifndef CATOxRelationalDescriptorTransaction_H 
#define CATOxRelationalDescriptorTransaction_H
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
* @level Private
* @usage U1
*/
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATOmxSet.h"

class CATOxRelationalDescriptor;
class CATOxRelationalDescriptors;

/**
* A really fancy name for a dumb class that keeps AddRef'ed pointers...
*/
class CATOxRelationalDescriptorTransaction
{
public:
  inline void LockRelationalDescriptor(CATOxRelationalDescriptor * iDescriptor) {_LockedDescriptors.Insert(iDescriptor);}
private:
  CATOmxSet<CATOxRelationalDescriptor,com_manager> _LockedDescriptors;
};

#endif
