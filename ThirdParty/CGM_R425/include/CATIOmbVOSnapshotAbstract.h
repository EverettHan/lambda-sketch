#ifndef CATIOmbVOSnapshotAbstract_H
#define CATIOmbVOSnapshotAbstract_H

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATIOmbVOSnapshotAbstract;
#else
extern "C" const IID IID_CATIOmbVOSnapshotAbstract;
#endif

class CATILinkableObject;
class CATIOmbVOSnapshotAbstract;

class ExportedByCATPLMTos CATIOmbVOSnapshotAbstract : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual int IsEqual(const CATBaseUnknown* iLinkable) const = 0;
  virtual unsigned int GetHashKey() = 0;
};

//required by CATPrdLinkableObjectMediatorOnPLOSnapshot.cpp
#include "CATAssert.h"

#endif
