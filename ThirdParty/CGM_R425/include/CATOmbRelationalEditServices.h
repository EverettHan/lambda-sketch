// COPYRIGHT Dassault Systemes 2009

#ifndef CATOmbRelationalEditServices_H
#define CATOmbRelationalEditServices_H

/**
* @level Protected
* @usage U1
*/

#ifndef NULL
#define NULL 0
#endif

// List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
  // Fatal error on solaris
@error
#endif


// List of authorized modules 

#define AuthorizedModule                              999
#define CATOmbLinkApplicativeAccess                   AuthorizedModule    
#define CATOmbTst_RelationalEditServices              AuthorizedModule
#define OmbTST_RerouteUseCasesFactory                 AuthorizedModule
#define CATOmbTst_RerouteUseCases_FullAuto_Special    AuthorizedModule
#define ElecHarnessIntegration                        AuthorizedModule
#define CATEnsSymmetryIntegration                     AuthorizedModule
#define CATComponentsFamily                           AuthorizedModule
#define CATPLMTemplates                               AuthorizedModule
#define PLMPointingVarsMgmtImpl                       AuthorizedModule   // Config & Relational 
#define CATOxiReroute_Find_Other_Occurrences          AuthorizedModule  
#define CATOxiInstanceWithSRs                         AuthorizedModule 
#define CATOxiRerouteUFO                              AuthorizedModule
#define CATOxiNewRerouteAPI                           AuthorizedModule
#define CATOxTestLib                                  AuthorizedModule
#define CATOmbLinkAccessTestLib                       AuthorizedModule
#define PLMModelerContextualLink                      AuthorizedModule
#define CATDftGenModel                                AuthorizedModule
#define CATPLMLinksUI                                 AuthorizedModule
#define CATOxiRerouteBundleMultiAlternative			      AuthorizedModule	
#define CATOxiRerouteBundleDrafting			              AuthorizedModule
#define CATFmtToolsServices                           AuthorizedModule
#define CATAsmAdvanceDuplicateModel                   AuthorizedModule
#define CATPLMClientCoreModel                         AuthorizedModule
#define OmbTST_PLMShared                              AuthorizedModule
#define CATEnsFluServices                             AuthorizedModule
#define CATTPSMCXFeature                              AuthorizedModule
#define CATPLMSynchronization                         AuthorizedModule
#define TestPLMModelerCtxLink                         AuthorizedModule
#define CATEnsPLMServices                             AuthorizedModule

// Config & Relational
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATOmbRelationalEditServices
  // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule
#undef CATOmbLinkApplicativeAccess
#undef CATOmbTst_RelationalEditServices
#undef OmbTST_RerouteUseCasesFactory
#undef CATOmbTst_RerouteUseCases_FullAuto_Special
#undef ElecHarnessIntegration
#undef CATEnsSymmetryIntegration
#undef CATComponentsFamily
#undef CATPLMTemplates
#undef PLMPointingVarsMgmtImpl      
#undef CATOxiReroute_Find_Other_Occurrences     
#undef CATOxiInstanceWithSRs 
#undef CATOxiRerouteUFO
#undef PLMModelerContextualLink
#undef CATDftGenModel
#undef CATOxiNewRerouteAPI
#undef CATOxTestLib  
#undef CATPLMLinksUI
#undef CATOmbLinkAccessTestLib
#undef CATPLMClientCoreModel
#undef CATOxiRerouteBundleMultiAlternative			     
#undef CATOxiRerouteBundleDrafting			             
#undef CATFmtToolsServices                           
#undef CATAsmAdvanceDuplicateModel
#undef OmbTST_PLMShared
#undef CATEnsFluServices
#undef CATTPSMCXFeature 
#undef CATPLMSynchronization
#undef TestPLMModelerCtxLink
#undef CATEnsPLMServices

#include "CATObjectModelerBase.h"
#include "IUnknown.h"
#include "CATSysBoolean.h"
#include "CATIAV5Level.h"
#include "CATOmxOHMap.h"
#include "CATComponentId.h"

#include "PLMIOmbVirtualObjectDescriptor.h"
#include "PLMI3DPositionServices.h"

  class CATOmbRelationSnapshotSpecificationIterator;
class CATOmbRelationSnapshotIterator;
class CATOmbRelationContextSnapshot;
class CATOmbRelationInterface;
class CATListPtrCATOmbOutputRelation;
class PLMIContextualLinksManager_var;

/**
* Static class providing services to edit the relational model.
* @see CATOmbRelationSnapshotIterator
*/
class ExportedByCATObjectModelerBase CATOmbRelationalEditServices
{
public:
  /**
   * Automatic reroute on a given relations set.
   * @param iterator [in]
   *   A iterator on relation snapshots.
   * @return
   *   <code>S_OK</code> if everything ran ok..
   *   <code>S_FALSE</code> Nothing to do (relations are OK).
   *   <code>E_UNEXPECTED</code> Unexpected error (could be related to an expired input snapshot view).
   *   Otherwise, associated failure code.
   */
  static HRESULT Reroute(CATOmbRelationSnapshotIterator & iterator);

  /**
   * Explicit reroute according to a given component specified relational model.
   * @param iterator [in]
   *   A iterator on specifiable relation snapshots.
   * @return
   *   <code>S_OK</code> if everything ran ok..
   *   <code>S_FALSE</code> Nothing to do (no specification or relations already pointing specified components).
   *   <code>E_FAIL</code> Incomplete specification or not ready for commit.
   *   <code>E_UNEXPECTED</code> Unexpected error (could be related to an expired input snapshot view).
   *   Otherwise, associated failure code.
   */
  static HRESULT Reroute(CATOmbRelationSnapshotSpecificationIterator & iterator);

  /**
 * Explicit reroute according to a given component specified relational model, specially made for Drafting
 * since they need bypass manual bundle reroute interdiction.
 * @param iterator [in]
 *   A iterator on specifiable relation snapshots.
 * @return
 *   <code>S_OK</code> if everything ran ok..
 *   <code>S_FALSE</code> Nothing to do (no specification or relations already pointing specified components).
 *   <code>E_FAIL</code> Incomplete specification or not ready for commit.
 *   <code>E_UNEXPECTED</code> Unexpected error (could be related to an expired input snapshot view).
 *   Otherwise, associated failure code.
 */
  static HRESULT RerouteForDrafting(CATOmbRelationSnapshotSpecificationIterator & iterator);

  /**
  *	PrepareForReroute
  * <br><b>Role</b>: Analyze the relations for which  reroute strategies have been set, check if they belong to an integrity group
  *  like bundle or contextuel relations, and in that case, apply a reroute strategy if needed to preserve integrity.
  * @param iterator [in]
  *   A iterator on specifiable relation snapshots where strategies were set.
  * @param oPropagationNeeded
  *   A boolean to signal if others relations have been specified a reroute strategy in order to satisfy
  *   relationnal integrity in case of bundle or contextual relations
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_FAIL</code> Incoherent strategies between relations.
  *   <code>E_INVALIDARG </code> arguments of manual reroute of contextual relation are not compliants with contextual relation rules.
  *   <code>E_UNEXPECTED</code> Unexpected error (could be related to an expired input snapshot view).
  *   Otherwise, associated failure code.
  */
  static HRESULT PrepareForReroute(CATOmbRelationSnapshotSpecificationIterator & iterator, CATBoolean & oPropagationNeeded);

  /**
  * Reroute provided relations to minor in session. These relations should have either a MISNIP or NOAMIS status (see CATOmbAdditionalRelationStatus).
  * If a contextual relation is provided, then the context relation will be rerouted if necessary.
  * MISNIP or NOAMIS relations impacted by links bundle will also be rerouted.
  * @param iRelations [in]
  *   A list of relations to reroute.
  * @return
  *   <code>S_OK</code> Reroute successful.
  *   <code>S_FALSE</code> Nothing done.
  *   <code>E_INVALIDARG</code> Invalid argument. May be due to an invalid output relation or the relation not being NOAMIS or MISNIP.
  *   <code>E_FAIL</code> Reroute failure.
  */
  static HRESULT RerouteToMinorInSession(CATListPtrCATOmbOutputRelation const & iRelations);

  static HRESULT RerouteForDuplicateSession(const CATOmxOHMap<CATComponentId, CATComponentId> &iMapComponentID);

  static HRESULT ComputeMinimumContext(PLMIContextualLinksManager_var & iCtxLinkManager, PLMIOmbVirtualObjectDescriptor_var & iLinkTarget, PLMIOmbVirtualObjectDescriptor_var & iLinkSource, PLMIOmbVirtualObjectDescriptor_var & oComputedContext, PLMIOmbVirtualObjectDescriptor_var & oComputedInput, CATBoolean & oChangeContextIsRequired, CATBoolean iManageFlexibility);

  static HRESULT GetLongestCommonPathWithFlexibility(CATOmxArray<CATComponentId> & iListPaths, CATComponentId& oCommonPath, CATBoolean& oIsRigidMinimum);
private:
  static HRESULT CommonElementAndFlexibility(CATOmxArray<CATComponentId> & iInputPath, CATOmxArray<CATComponentId> & iContextPath, PLMI3DPositionServices *pPLM3DPositionServices, const int& iIndexCommonRoot, bool& oCanBeRepositioned);
  static HRESULT GetCommonRoot(const CATOmxArray<CATComponentId> & iInputPath, const CATOmxArray<CATComponentId> & iContextPath, int & oIndexCommonRoot);

  static HRESULT InternalGetLongestCommonPathWithFlexibility(const CATComponentId& iFirstCID, const CATComponentId& iSecondCID, CATComponentId& oCommonPath, CATBoolean& oIsRigidMinimum);
};

#endif

