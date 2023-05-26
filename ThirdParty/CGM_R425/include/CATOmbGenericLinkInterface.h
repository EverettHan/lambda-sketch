#ifndef CATOmbGenericLinkInterface_h
#define CATOmbGenericLinkInterface_h

// COPYRIGHT DASSAULT SYSTEMES 2006

// SystemTS
#include "CATBoolean.h"
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxSR.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATUnicodeString;
class CATBaseUnknown;
class CATILinkableObject;
class CATComponentId;
class CATGenericLinkMemento;
class CATIBindParameters;


class ExportedByCATObjectModelerBase CATOmbGenericLinkInterface
{
public:
  // Synchro link state
  enum SynchroState { Synchronized, NotSynchronized, NotPertinent, NotInitialized };

  enum GenericLinkType { Single, Contextual };

  virtual GenericLinkType GetGenericLinkType() const = 0;

  virtual CATBoolean IsVisible() = 0;

  virtual HRESULT IsSynchronized(CATOmbGenericLinkInterface::SynchroState & oSyncroState) const = 0;

  virtual HRESULT Break() = 0;

  virtual HRESULT SynchronizeImport() = 0;

  virtual CATUnicodeString GetDisplayName() const = 0;

  virtual CATOmxSR<CATBaseUnknown> GetPointingObject() const = 0;

  virtual HRESULT LoadTarget() = 0;

  virtual HRESULT Bind(CATILinkableObject *& oObj, CATIBindParameters * B = NULL) = 0;

  // Rerouting methods

  enum GenericLinkStatus { GenericLinkValid, GenericLinkBroken, GenericLinkFatal, ContextualRulesViolation, GenericTypeViolation };

  virtual GenericLinkStatus SimulateSetTarget(CATComponentId & iNewComponent, CATGenericLinkMemento *& opState, CATBoolean unsetLinkIfBroken = FALSE) = 0;

  virtual GenericLinkStatus SimulateSetContextAndInput(CATComponentId & iNewContext, CATComponentId & iNewInput, CATGenericLinkMemento *& opState) = 0;

  virtual void SetNewState(const CATGenericLinkMemento * ipMemento) = 0;
};

#endif
