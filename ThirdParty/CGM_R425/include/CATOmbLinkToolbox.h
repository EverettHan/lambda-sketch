// COPYRIGHT DASSAULT SYSTEMES 2008

#ifndef CATOmbLinkToolbox_H
#define CATOmbLinkToolbox_H

/**
* @level Private
* @usage U3
*/

#include "CATObjectModelerBase.h"
#include "CATOmxArray.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATBaseUnknown.h"
#include "CATSysMacros.h"
#include "CATAssert.h"
#include "CATComponentId.h"
#include "CATPLMTypeToolsDefinitions.h"

class CATOmbDescriptorAdaptorImpl;
class CATUnicodeString;
class CATOmxAny;
class CATComponentId;


class ExportedByCATObjectModelerBase CATOmbLinkToolbox
{
public:

  enum CATListLifeCycle { AddRef, Release };

  // Prefix : OMBLink_...
  // Antivar : NO_...
  enum ActivationVariable
  {
    VOID_ON = 0,
    VOID_OFF,
    OLE_InsertionOnUIActiveObject,
    LinkDoctor_ReportTicketError,
    LinkDoctor_ReportSymbolError,
    LinkBind_ReturnCorrectOnBrokenTarget,
    LinkBind_ReturnCorrectOnBrokenContainer,
    NewCtxLinkUndoRedo,
    PostFilteringOnRerouteFailure,
    DuplicateUnstream_IntraComponentLink_Fix,
    PLMIntegrity_IntegrityUnit_CompliantReroute,
    CorrectLevelSensitivitySupport,
    OBSOLETE_PCS_SynchroAtCreate,
    Proxy_Pub_Activated,
    RelationSynchroOnMasterStamp,
    InternalSeekDocumentOptim,
    Reorder_SetNewTarget,
    PLMCoreUseAttrBlockForLinks, // WARNING : NO PREFIX
    OBSOLETE_Relation_FalseImpactsHandlingAtLinkDeletion,
    ContextualLinkMustBeSolvedAfterReroute,
    CATOmVOUnload_WithoutLCTransaction,
    Ticket_UndoRedoDirty,
    NeutralizeLinkDoctorReporting,
    DynamicBinding,
    VODesc_GetRRef_Fix,
    OBSOLETE_CATOmbRelationSTSSynchroMememto,
    PLO_Absorption_CtxLink,
    NewDirty,
    NewRetrieveAll3,
    DisableCatalogBindAnywhere,
    ForceUnsynchroAfterReroute,
    NewRetrieveAll4,
    OBSOLETE_PointingOnThis,
    TreatCompleteNameCorruptionWithDOC5,
    OBSOLETE_MigrationOnPathType,
    OBSOLETE_MigrationOnPathType_InflexibleCheck,
    Fix_PDM_Offer_Initial_Status,
    Drw_Reroute_Links_ToRef,
    PLMCoreOOD_InTOS,
    PLMCoreOOD_InTOS2,
    OBSOLETE_BLOBBEDCTX_SaveIntegrity,
    NewContextFlexibilityComputation,
    OldRerouteImpactingModification,
    // Add a new variable here ...
    END_MARK // MUST BE AT END !
  };

  static CATBoolean IsActivated(ActivationVariable);

  /** allow compiler/linker to remove links dead code... */
  enum DefinitivelyActivatedVariable { Proxy_Creation_Activated, PLO_Absorption };
  static inline CATBoolean IsActivated(DefinitivelyActivatedVariable) { return TRUE; }

  enum IncidentType { Missing_Catalog_Incident };

  static void ReportIncident(IncidentType iType, CATBaseUnknown * ipRelatedObject, const CATUnicodeString & iSecondRelatedObjectInfo);

  static void GetUnsynchronizedSynchroStamp(CATOmxAny & iSynchroStampVersion, CATOmxAny & iSynchroStamp, const CATOmxAny & iOldSeed);

private:

  // Friendness access restriction : do not re-expose CATPLMTypeProtectedDescriptor
  // Maybe to move to ObjectModelerBase/PrivateInterfaces ?
  friend class CATOmbVO;
  friend class CATOmbContextRerouteAssistant;
  friend class CATOmbContextualInputBuilder;
  friend class CATOmbEquivalentFactory;
  friend class CATOmbRelationSnapshotImpl;
  friend class CATOmbComponentLinkTable;
  friend class CATOmbComponentTablesMediator;
  friend class CATOmbRelationImpl;
  friend class CATOmbRestrictedServicesForPLMCore2;
  friend class CData_ComplexName;
  friend class CATLinkBinder;
  friend class CATLinkPrivateServices;
  friend class CATOmbLink;
  friend class CATOmbLinkProtectedServices;
  friend class CATOmbRepRefScopeBaseEntityAdapter;
  friend class CATOmbVOServices;
  friend class PLMOmbVirtualObjectDescriptorFactory;
  friend class PLMOmbVirtualObjectDescriptorImpl;
  friend class CATOmbComponentRelationTable;
  friend class GetVODescriptor_TestMatrix;
  friend class GetVODescriptor_Test;
  friend class GetVODescriptor_Test_Unit;
  friend class CATOmbTst_GetVODescriptor_UseCases;
  friend class CATOmbUniversalLinkPLMV2;
  friend class CATOmbRelationProperties;
  friend class CATOmbRelationalEditServices;
  friend class PLMContextualLinkServices;

  enum ObjectType { Entity, Relation, Port, Connection, Entity_RepReference, Relation_RepInstance, Other };
  /* Return :
   *   S_OK : it is a component.
   *   S_FALSE : it is not a component.
   *   Otherwise, associated error code.
   */
  static ObjectType GetObjectType(const CATComponentId &);
  static ObjectType GetObjectType(const CATBaseUnknown &);
  static CATBoolean IsEntityType(const ObjectType &);
  static CATBoolean IsRelationType(const ObjectType &);

  static const  int m_RelationType = (TYPTRP_Instance | TYPTRP_RepInstance | TYPTRP_Relation);

  static inline CATBoolean IsRelationType(const CATComponentId & iCID)
  {
    return S_OK == iCID.IsMatchingCoreBehavior(m_RelationType);
  };
  static inline CATBoolean IsPortType(const CATComponentId & iCID)
  {
    return(S_OK == iCID.IsMatchingCoreBehavior(TYPTRP_Port));
  };
  static inline CATBoolean IsRepInstType(const CATComponentId & iCID)
  {
    return(S_OK == iCID.IsMatchingCoreBehavior(TYPTRP_RepInstance));
  };
};

/*
  Depreciated for iLifeCycle == CATOmbLinkToolbox::Release
  use CATOmxReleaseListPtr instead
*/
template <typename List> void CATOmbLinkToolbox_ManageListLifeCycle(List & iList, CATOmbLinkToolbox::CATListLifeCycle iLifeCycle)
{
  IUnknown * pI = NULL;
  for (int i = 1; i <= iList.Size(); i++)
  {
    pI = iList[i];
    switch (iLifeCycle)
    {
      case CATOmbLinkToolbox::AddRef:
        if (pI)
          pI->AddRef();
        break;
      case CATOmbLinkToolbox::Release:
        CATSysReleasePtr(pI);
        break;
    }
  }
  if (iLifeCycle == CATOmbLinkToolbox::Release)
    iList.RemoveAll();
};

#endif

