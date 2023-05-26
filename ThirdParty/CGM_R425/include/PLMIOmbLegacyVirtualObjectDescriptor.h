#ifndef PLMIOmbVirtualObjectDescriptor_DEPRECATED_H
#define PLMIOmbVirtualObjectDescriptor_DEPRECATED_H

// System
#include "CATBaseUnknown.h"
// CATPLMIdentificationAccess
#include "CATListPtrCATIPLMComponent.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATOmbObjectInContext;
class CATIPLMComponent;
class PLMIOmbVirtualObjectDescriptor_var;

extern ExportedByCATObjectModelerBase IID IID_PLMIOmbLegacyVirtualObjectDescriptor;

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------     DIRECT USE OF THIS CLASS IS FORBIDDEN, USE PLMIOmbVirtualObjectDescriptor    ----------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class ExportedByCATObjectModelerBase  PLMIOmbLegacyVirtualObjectDescriptor : public CATBaseUnknown
{
public:
  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use MakeEmptyDescriptor") */ static PLMIOmbVirtualObjectDescriptor_var CreateEmptyDescriptor();

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use MakeDescriptorFromConcreteOrVirtualObject") */ static PLMIOmbVirtualObjectDescriptor_var CreateDescriptorFromConcreteOrVirtualObject(CATBaseUnknown const * iDoNotUse);

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use GetPathOfInstances with CATOmxList") */ virtual HRESULT GetPathOfInstances(CATLISTP(CATIPLMComponent) & doNotUse) const = 0; /* DO NOT USE */

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use SetPathOfInstances with CATOmxList") */ virtual HRESULT SetPathOfInstances(CATLISTP(CATIPLMComponent) & doNotUse) = 0; /* DO NOT USE */

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use GetInstanceOfRepresentation with CATOmxSR") */ virtual HRESULT GetInstanceOfRepresentation(CATIPLMComponent *& doNotUse) const = 0; /* DO NOT USE */

  virtual HRESULT SetInstanceOfRepresentation(CATIPLMComponent * iRepresentationInstance) = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use GetTarget with CATOmxSR") */ virtual HRESULT GetTarget(CATBaseUnknown *& doNotUse1, const IID & doNotUse2 = IID_CATBaseUnknown) const = 0; /* DO NOT USE */

  virtual HRESULT SetTarget(CATBaseUnknown * iTarget) = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use GetRootReference with CATOmxSR") */ virtual HRESULT GetRootReference(CATIPLMComponent *& doNotUse) const = 0; /* DO NOT USE */

  virtual void GetKind(CATBoolean & oPathOfInstances, CATBoolean & oInstanceOfRepresentation, CATBoolean & oTarget, const IID & iTargetIID = IID_CATBaseUnknown) const = 0;

  virtual HRESULT CheckValidity() const = 0;

  virtual HRESULT Reset() = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use IsIdenticalTo") */ virtual HRESULT Compare(PLMIOmbVirtualObjectDescriptor_var & doNotUse) const = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use ArePathsOfInstancesIdentical with const &") */ virtual CATBoolean ArePathsOfInstancesIdentical(PLMIOmbVirtualObjectDescriptor_var & doNotUse) const = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use AreInstancesOfRepresentationIdentical with const &") */ virtual CATBoolean AreInstancesOfRepresentationIdentical(PLMIOmbVirtualObjectDescriptor_var & doNotUse) const = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use AreTargetsIdentical with const &") */ virtual CATBoolean AreTargetsIdentical(PLMIOmbVirtualObjectDescriptor_var & doNotUse) const = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use GetObjectInContext with CATOmxSR") */ virtual HRESULT GetObjectInContext(CATOmbObjectInContext *& doNotUse) = 0; /* DO NOT USE */

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use GetPathOfContextInstances with CATOmxList") */ virtual HRESULT GetPathOfContextInstances(CATLISTP(CATIPLMComponent) & doNotUse) const = 0; /* DO NOT USE */

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use SetPathOfContextInstances with CATOmxList") */ virtual HRESULT SetPathOfContextInstances(CATLISTP(CATIPLMComponent) & doNotUse) = 0; /* DO NOT USE */

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use GetContextInstanceOfRepresentation with CATOmxSR") */ virtual HRESULT GetContextInstanceOfRepresentation(CATIPLMComponent *& doNotUse) const = 0; /* DO NOT USE */

  virtual HRESULT SetContextInstanceOfRepresentation(CATIPLMComponent * iContextRepresentationInstance) = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use ArePathsOfContextInstancesIdentical with const &") */ virtual CATBoolean ArePathsOfContextInstancesIdentical(PLMIOmbVirtualObjectDescriptor_var & iVOD) const = 0;

  /* DO NOT USE */ /* OMX_DEPRECATED("[DEPRECATED METHOD] Use AreContextInstancesOfRepresentationIdentical with const &") */ virtual CATBoolean AreContextInstancesOfRepresentationIdentical(PLMIOmbVirtualObjectDescriptor_var & iVOD) const = 0;

  virtual void GetKind(CATBoolean & oPathOfInstances, CATBoolean & oInstanceOfRepresentation, CATBoolean & oTarget, CATBoolean & oPathOfContextInstances, CATBoolean & oContextInstanceOfRepresentation, const IID & iTargetIID = IID_CATBaseUnknown) const = 0;
};

#define USINGPLMIOMBLEGACYVIRTUALOBJECTDESCRIPTORMETHODS \
using PLMIOmbLegacyVirtualObjectDescriptor::GetPathOfInstances; \
using PLMIOmbLegacyVirtualObjectDescriptor::SetPathOfInstances; \
using PLMIOmbLegacyVirtualObjectDescriptor::GetInstanceOfRepresentation; \
using PLMIOmbLegacyVirtualObjectDescriptor::GetTarget; \
using PLMIOmbLegacyVirtualObjectDescriptor::GetRootReference; \
using PLMIOmbLegacyVirtualObjectDescriptor::Compare; \
using PLMIOmbLegacyVirtualObjectDescriptor::ArePathsOfInstancesIdentical; \
using PLMIOmbLegacyVirtualObjectDescriptor::AreInstancesOfRepresentationIdentical; \
using PLMIOmbLegacyVirtualObjectDescriptor::AreTargetsIdentical; \
using PLMIOmbLegacyVirtualObjectDescriptor::GetObjectInContext; \
using PLMIOmbLegacyVirtualObjectDescriptor::GetPathOfContextInstances; \
using PLMIOmbLegacyVirtualObjectDescriptor::SetPathOfContextInstances; \
using PLMIOmbLegacyVirtualObjectDescriptor::GetContextInstanceOfRepresentation; \
using PLMIOmbLegacyVirtualObjectDescriptor::ArePathsOfContextInstancesIdentical; \
using PLMIOmbLegacyVirtualObjectDescriptor::AreContextInstancesOfRepresentationIdentical

#endif

