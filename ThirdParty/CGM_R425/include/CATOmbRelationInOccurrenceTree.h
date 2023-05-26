#ifndef CATOmbRelationsInOccurrenceTree_H
#define CATOmbRelationsInOccurrenceTree_H

#include "CATObjectModelerBase.h"
#include "CATOmxSR.h"
#include "CATOmbRelationInformation.h"
#include "CATOmbLinkStatusServices.h"
#include "CATOMBLinkResolutionError.h"

class CATIPLMNavOccurrence;
class CATOmbOutputRelation;
class CATOmbRelationSnapshot;
class PLMLinkFacade;
class PLMIOmbVirtualObjectDescriptor;
class CATOmbRelationContext;
class CATOmbRelationContextSnapshot;

constexpr HRESULT OMB_E_NOTLOADED = PrivateLinkError(21); //HR_LINKSOLVE_ComponentNotOpened
constexpr HRESULT OMB_E_OUTOFCONTEXT = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xd48c + 1);
constexpr HRESULT OMB_E_BADCONTEXT = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xd48c + 2);
constexpr HRESULT OMB_E_INVALIDPATH = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xd48c + 3);
constexpr HRESULT OMB_E_NOOCCURRENCE = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xd48c + 4);
constexpr HRESULT OMB_E_BROKENSESSION = PrivateLinkError(20); //HR_LINKSOLVE_ComponentWaitingToBeDeleted
constexpr HRESULT OMB_E_BROKENREMOTE = PrivateLinkError(16);  //HR_LINKSOLVE_RelationBroken

/**
 * Allows to project semantic relations in occurrence tree
 */
class ExportedByCATObjectModelerBase CATOmbRelationInOccurrenceTree
{
  const CATBaseUnknown& m_originOccurrence;
  enum class ContentType { OutputRelation, RelationSnapshot, LinkFacade, VOD };
  const ContentType m_contentType;
  union
  {
    const CATOmbOutputRelation* m_outputRelation;
    const CATOmbRelationSnapshot* m_relationSnapshot;
    const PLMLinkFacade* m_linkFacade;
    const PLMIOmbVirtualObjectDescriptor* m_VOD;
  };
  template<class Functor>
  HRESULT Visit(Functor&);
public:
  /**
   * constructor
   * @param iOriginOccurrence
   *   an occurrence (CATIPLMNavOccurrence) or a rep occurrence (CATIPLMNavRepOccurrence) which is at the origin of the relation
   * @param iRelation
   *   the relation to consider
   */
  CATOmbRelationInOccurrenceTree(const CATBaseUnknown& iOriginOccurrence, const CATOmbOutputRelation& iRelation);
  CATOmbRelationInOccurrenceTree(const CATBaseUnknown& iOriginOccurrence, const CATOmbRelationSnapshot& iRelation);
  CATOmbRelationInOccurrenceTree(const CATBaseUnknown& iOriginOccurrence, const PLMLinkFacade& iRelation);
  CATOmbRelationInOccurrenceTree(const CATBaseUnknown& iOriginOccurrence, const PLMIOmbVirtualObjectDescriptor& iRelation);

  /**
   * result of CATOmbRelationInOccurrenceTree::Solve
   */
  struct Target
  {
    /**
     * target occurrence (implements CATIPLMNavOccurrence)
     * it is set if the target path contains an instance
     * if the target path contains a rep instance, this member contains the father occurrence of the rep occurrence
     */
    CATOmxSR<CATBaseUnknown> Occurrence;
    /**
     * target rep occurrence (implements CATIPLMNavRepOccurrence)
     * it is set if the target path contains a rep instance which implements rep occurrence
     */
    CATOmxSR<CATBaseUnknown> RepOccurrence;
    /**
     * target rep instance (implements CATIPLMNavRepInstance & CATIPLMComponent)
     * it is set if the target path contains a rep instance
     */
    CATOmxSR<CATBaseUnknown> RepInstance;
    /**
     * trailing target component (implements CATIPLMComponent)
     * it is set if target path ends with an object which is not an instance/rep instance
     */
    CATOmxSR<CATBaseUnknown> TrailingComponent;
  };

  /**
   * retrieve relation target in a given occurrence tree
   * @param iContextOccurrence
   *   the occurrence starting from which the relation must be solved
   *    can be an occurrence (CATIPLMNavOccurrence) or a rep occurrence (CATIPLMNavRepOccurrence)
   * @param iRelation
   *   the relation to solve
   *   notice that for PLMLinkFacade/PLMIOmbVirtualObjectDescriptor only relational part is used (intra-stream part is not considered)
   * @param oTargetOccurrence
   *  target occurrence (or nullptr)
   *  notice that target occurrence can be either an occurrence (CATIPLMNavOccurrence) or a rep occurrence (CATIPLMNavRepOccurrence)
   * @return
   *  S_OK
   *    the target occurrence was retrieved successfuly
   *  S_FALSE
   *    target occurrence is input occurrence
   *  E_INVALIDARG
   *    origin occurrence or provided relation are invalid/deleted
   *  OMB_E_OUTOFCONTEXT
   *    the relation is contextual and the context occurrence tree is not deep enough
   *  OMB_E_BADCONTEXT
   *    the relation cannot be solved starting from given origin occurrence
   *  OMB_E_INVALIDPATH
   *    path is invalid
   *  OMB_E_NOOCCURRENCE
   *    the corresponding occurrence was not found.
   *    this can occur because the occurrence was filtered from the occurrence tree
   *    but also because the occurrence tree was not synchronized (@href CATRootOccurrenceMgr::SynchronizeOccurrenceTree)
   *    notice that this return code has priority over HR_LINKSOLVE_*
   *  HR_LINKSOLVE_*
   *    the relation is broken or its target is not loaded
   *    more details can be retrieved using CATOmbLinkStatusServices::GetLinkStatusFromRc/CATOmbLinkStatusServices2::GetLinkStatusFromRc
   */
  HRESULT Solve(Target& oTarget);

  /**
   * Same as Solve but if the target path ends with a PLMPort then the result contains the (relational) target of the port
   */
  HRESULT SolveAndTraversePorts(Target& oTarget);

  CATOmbRelationInOccurrenceTree(const CATOmbRelationInOccurrenceTree&) = delete;
  CATOmbRelationInOccurrenceTree& operator=(const CATOmbRelationInOccurrenceTree&) = delete;
};

enum class CATOmbRelationStatusInOccurrenceTree
{
  Solved = CatOmbRelationStatus_Solved,
  BrokenSession = CatOmbRelationStatus_Broken_Session,
  BrokenRemote = CatOmbRelationStatus_Broken_Remote,
  NotOpened = CatOmbRelationStatus_NotOpened,
  OutOfContext,
  NoOccurrence
};

ExportedByCATObjectModelerBase HRESULT CATOmbGetRelationStatusInOccurrenceTree(const CATBaseUnknown& iContextOccurrence, const CATOmbOutputRelation& iRelation, bool iMergeWithContextStatus, CATOmbRelationStatusInOccurrenceTree & oStatus, CATOmbAdditionalRelationStatus * oAdditionalRelationStatus = nullptr);
ExportedByCATObjectModelerBase HRESULT CATOmbGetRelationStatusInOccurrenceTree(const CATBaseUnknown& iContextOccurrence, const CATOmbRelationSnapshot& iRelation, bool iMergeWithContextStatus, CATOmbRelationStatusInOccurrenceTree & oStatus, CATOmbAdditionalRelationStatus * oAdditionalRelationStatus = nullptr);
ExportedByCATObjectModelerBase HRESULT CATOmbGetContextRelationStatusInOccurrenceTree(const CATBaseUnknown& iContextOccurrence, const CATOmbRelationContext& iContextRelation, CATOmbRelationStatusInOccurrenceTree & oStatus);
ExportedByCATObjectModelerBase HRESULT CATOmbGetContextRelationStatusInOccurrenceTree(const CATBaseUnknown& iContextOccurrence, const CATOmbRelationContextSnapshot& iContextRelation, CATOmbRelationStatusInOccurrenceTree & oStatus);



namespace CATOmbLinkStatusServices2
{
  enum LinkResolutionStatus2
  {
    Target_Found = CATOmbLinkStatusServices::Target_Found,
    Component_NotInSession = CATOmbLinkStatusServices::Component_NotInSession,
    Relation_Broken = CATOmbLinkStatusServices::Relation_Broken,
    Link_Broken = CATOmbLinkStatusServices::Link_Broken,
    Target_NotInSession = CATOmbLinkStatusServices::Target_NotInSession,
    InvalidLink = CATOmbLinkStatusServices::InvalidLink,
    OutOfContext,
    NoOccurrence
  };

  ExportedByCATObjectModelerBase HRESULT GetLinkStatusFromRc(HRESULT irc, LinkResolutionStatus2& oStatus);
}

#endif
