#ifndef __CATOmbStreamDescriptorQualifiers_H
#define __CATOmbStreamDescriptorQualifiers_H

#include "CATOmbStreamDescriptorDefinitionQualifiers.h"
#include "CATOmbStreamDescriptorObjectQualifiers.h"

#include "CATVVSEnv.h"
#include "CATVVSFileDescriptionServices.h"

struct ExportedByCATOmbSelectiveLoading  CATOmbStreamDescriptorQualifiers: public CATOmbStreamDescriptorDefinitionQualifiers,public CATOmbStreamDescriptorObjectQualifiers
{
  CATOmbStreamDescriptorQualifiers(const CATOmbStreamDescriptorDefinitionQualifiers& iDef,const CATOmbStreamDescriptorObjectQualifiers& iObj):
    CATOmbStreamDescriptorDefinitionQualifiers(iDef),
    CATOmbStreamDescriptorObjectQualifiers(iObj),
    _LocalStorageBehavior(FD::Managed),
    _LocalStorage(FALSE)
  {}

  CATOmbStreamDescriptorQualifiers(const CATOmbLoadableDataUniqueKey& iKey,
    const CATUnicodeString& iLateType,
    const CATVVSUrl& iUrl,                                   
    int iWatermarkStamp,
    int iSynchroStamp,
    const CATUnicodeString& iPersistencyType):
  CATOmbStreamDescriptorDefinitionQualifiers(iKey,iLateType),
    CATOmbStreamDescriptorObjectQualifiers(iUrl,iWatermarkStamp,iSynchroStamp,iPersistencyType,iKey.GetPersistencyName()),
    _LocalStorageBehavior(FD::Managed),
    _LocalStorage(FALSE)
  {}

  void UseAsLocalStorage(FD::FileDescriptionBehavior iLRMode) {_LocalStorage=TRUE;_LocalStorageBehavior=iLRMode;};
  CATBoolean UsedAsLocalStorage(FD::FileDescriptionBehavior& oLRMode) {oLRMode=_LocalStorageBehavior; return _LocalStorage;};

private:
  CATBoolean _LocalStorage;
  FD::FileDescriptionBehavior _LocalStorageBehavior;
};

#endif
