#ifndef CATOmbVOServices_H
#define CATOmbVOServices_H

/**
 * @level Protected
 * @usage U1
 */

 // System
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"
// SystemTS
#include "CATBoolean.h"
// ObjectModelerCollection
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATIPLMComponent.h"
#include "CATListPtrCATIPLMComponent.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class PLMIOmbVirtualObjectDescriptor;
class PLMIOmbVirtualObjectDescriptor_var;
class CATILinkableObject;
class CATIOmbUniversalLink;

/**
 * Static services class providing services dedicated to VO & VODescriptor.
 * Restricted access.
 */
class ExportedByCATObjectModelerBase CATOmbVOServices
{
public:
  /**
   * Splits a list corresponding to an object in context into 3 elements:
   *  - a Path of Instances.
   *  - an Instance of Representation.
   *  - A Target.
   *
   *  @param  iLObjects
   *      A list of objects representing an object in context.
   *  @param  oLPathOfInstances
   *      A list made of PLM instances
   *  @param  opRepInstance
   *      An instance of representation
   *  @param  opTarget
   *      A Target
   *  @return
   *      <code>S_OK</code> if the methods succeeds. <br>
   *      <code>E_INVALIDARG</code> if provided arguments are unexpected. <br>
   *      <code>E_FAIL</code> otherwise. <br>
   */
  static HRESULT SplitListForVODescOrVO(CATLISTP(CATBaseUnknown) & iObjects, CATLISTP(CATIPLMComponent) & oPathOfInstances, CATIPLMComponent *& oRepInstance, CATBaseUnknown *& oTarget);

  // obsolete, only used by CATPLOInfo::GetPLO
  enum ValidityProcessKind { VO };
  static HRESULT CheckValidity(const CATLISTP(CATIPLMComponent) & iPathOfInstances, CATIPLMComponent * iRepInstance, CATBaseUnknown * iTarget, ValidityProcessKind);

  static CATOmxSR<CATILinkableObject> GetLinkableFromVOD(PLMIOmbVirtualObjectDescriptor const & iVOD, bool iVOInterface);
  static HRESULT GetVOSnapshotFromVODesc(PLMIOmbVirtualObjectDescriptor_var iVOD, CATILinkableObject *& oLinkable);

  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> GetVODescriptor(CATBaseUnknown const & iCBU);
  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> GetVODescriptor_FullIfActivated(CATBaseUnknown const & iCBU);
  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> GetVODescriptor_OnVOAndCtxLinkIfSnapshotActivated(CATBaseUnknown const & iCBU);

private:
  static CATOmxSR<PLMIOmbVirtualObjectDescriptor> GetVODescriptor(CATBaseUnknown const & iCBU, bool iFailOnModelerVO, bool iFailOnModelerCtxLink, bool iFailOnSingle);
};

//-----------------------------------------------------------------------

#endif
