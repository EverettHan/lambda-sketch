#ifndef CATPLMDicCstDef_H
#define CATPLMDicCstDef_H

#include "CATPLMServicesItf.h"

//system
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATBoolean.h"

#include "CATPLMCoreType.h"
#include "CATPLMRepositoryName.h"

#include "CATOmxKeyString.h"
#include "CATOmxOSet.h"
#include "CATOmxOMap.h"

// BSFBuildtimeData
#include "CATIAV5Level.h"

class CATPLMType;

class ExportedByCATPLMServicesItf CATPLMDicCstDef
{
public:
  //s() like singleton...
  static const CATPLMDicCstDef& s();

  /*@deprecated R417*/
  static const CATPLMDicCstDef& cst();

  CATString ATTR_V_user;
  CATString ATTR_owner;
  CATString ATTR_V_organization;
  CATString ATTR_organization;
  CATString ATTR_V_project;
  CATString ATTR_project;
  CATString ATTR_C_created;
  CATString ATTR_originated;
  CATString ATTR_C_modified;
  CATString ATTR_modified;
  CATString ATTR_LOCKSTATUS;
  CATString ATTR_reserved;
  CATString ATTR_LOCKUSER;
  CATString ATTR_reservedby;
  CATString ATTR_CESTAMP;
  CATString ATTR_cestamp;
  CATString ATTR_PHYSICALID;
  CATString ATTR_physicalid;
  CATString ATTR_LOGICALID;
  CATString ATTR_logicalid;
  CATString ATTR_majorid;
  CATString ATTR_type;
  CATString ATTR_V_version;
  CATString ATTR_majorrevision;
  CATString ATTR_V_maturity;
  CATString ATTR_current;
  CATString ATTR_vault;
  CATString ATTR_updatestamp;
  CATString ATTR_V_isOnceInstantiable;
  CATString ATTR_minororder;
  CATString ATTR_PLM_ExternalID;
  CATString ATTR_versionid;
  CATString ATTR_V_VersionID; // V_VersionID only found on IRPC
  CATString ATTR_V_StreamDescriptors;
  CATString ATTR_V_PathRelations;
  CATString ATTR_V_SRs;
  CATString ATTR_interface;
  CATString ATTR_isbestsofar;
  CATString ATTR_islastversion;
  CATString ATTR_V_Name;
  CATString ATTR_V_description;
  //strong relationship are managed in CATPLMStrongRelationshipId.h
  //CATString V_Owner;
  //CATString V_InstanceOf;
  //CATString from;
  //CATString to;
  CATString CSplmid;

  CATOmxKeyString ksV_Name;
  CATOmxKeyString ksV_description;
  CATOmxKeyString ksreserved;
  CATOmxKeyString kscurrent;
  CATOmxKeyString ksreservedby;
  CATOmxKeyString ksproject;
  CATOmxKeyString ksorganization;
  CATOmxKeyString ksowner;
  CATOmxKeyString ksoriginated;
  CATOmxKeyString ksmodified;
  CATOmxKeyString kspolicy;
  CATString cspolicy;
  CATOmxKeyString ksname;
  CATOmxKeyString kslocked;
  CATOmxKeyString kslocker;
  CATOmxKeyString ksupdatestamp;
  CATOmxKeyString ksrevision;
  CATOmxKeyString ksdescription;
  CATOmxKeyString ksversionid;
  CATOmxKeyString ksV_VersionID;
  CATOmxKeyString ksrevindex;
  CATOmxKeyString ksminorrevision;
  CATOmxKeyString ksispublished;
  CATOmxKeyString ksmajororder;
  CATOmxKeyString ksminororder;
  CATOmxKeyString ksmajorrevision;
  CATOmxKeyString ksisbestsofar;
  CATOmxKeyString ksislastversion;
  CATOmxKeyString ksislastminorversion;
  CATOmxKeyString ksV_order;
  CATOmxKeyString ksvault;
  // plmid is not a real attribute declared in dictionary
  CATOmxKeyString ksplmid;
  // fake attributes used in PLMQL language only, there are not declared in metadata
  CATOmxKeyString ksV_StreamDescriptors;
  CATOmxKeyString ksV_SRs;
  CATOmxKeyString ksV_PathRelations;
  // ownership attributes for P&O access authorizations
  CATOmxKeyString kscurrentdotsignature;/*XMQL*/
  CATOmxKeyString ksownershipdotorganization;/*XMQL*/
  CATOmxKeyString ksownershipdotproject;/*XMQL*/
  CATOmxKeyString ksownershipdotcomment;/*XMQL*/
  CATOmxKeyString ksownershipdotaccess;/*XMQL*/
  CATUnicodeString dot;

  // Moved in CATPLMiPMLDefGrammar
  //CATOmxKeyString kscurrentcolonsignature;/*IPML*/
  //CATOmxKeyString ksownershipcolonorganization;/*IPML*/
  //CATOmxKeyString ksownershipcolonproject;/*IPML*/
  //CATOmxKeyString ksownershipcoloncomment;/*IPML*/
  //CATOmxKeyString ksownershipcolonaccess;/*IPML*/

  CATOmxKeyString ksLOCKSTATUS;
  CATOmxKeyString ksV_maturity;
  CATOmxKeyString ksLOCKUSER;
  CATOmxKeyString ksV_organization;
  CATOmxKeyString ksV_project;
  CATOmxKeyString ksV_user;
  CATOmxKeyString ksC_created;
  CATOmxKeyString ksC_modified;

  CATOmxKeyString ksphysicalid;
  CATOmxKeyString kslogicalid;
  CATOmxKeyString ksmajorid;
  CATOmxKeyString kstype;
  CATOmxKeyString ksinterface;
  CATOmxKeyString ksV_isOnceInstantiable;
  //strong relationship are managed in CATPLMStrongRelationshipId.h
  //CATOmxKeyString ksfrom;
  //CATOmxKeyString ksfromrel;
  //CATOmxKeyString ksto;
  //CATOmxKeyString kstorel;
  //CATOmxKeyString ksV_InstanceOf;
  //CATOmxKeyString ksV_Owner;
  CATOmxKeyString kscestamp;
  CATOmxKeyString ksCESTAMP;

  CATOmxKeyString ksrowuuid;
  CATOmxKeyString ksmrowuuid;
  CATOmxKeyString ksmasterrowuuid;

  CATUnicodeString BusinessType;
  CATOmxKeyString ksBusinessType;
  CATUnicodeString RelationType;
  CATOmxKeyString ksRelationType;
  CATUnicodeString PLMReference;
  CATOmxKeyString ksPLMReference;
  CATUnicodeString PLMInstance;
  CATOmxKeyString ksPLMInstance;
  CATUnicodeString PLMPort;
  CATOmxKeyString ksPLMPort;
  CATUnicodeString PLMConnection;
  CATOmxKeyString ksPLMConnection;
  CATUnicodeString PLMEntity;
  CATOmxKeyString ksPLMEntity;
  CATUnicodeString PLMCoreReference;
  CATOmxKeyString ksPLMCoreReference;
  CATUnicodeString PLMCoreRepReference;
  CATOmxKeyString ksPLMCoreRepReference;
  CATUnicodeString PLMCoreInstance;
  CATOmxKeyString ksPLMCoreInstance;
  CATUnicodeString PLMCoreRepInstance;
  CATOmxKeyString ksPLMCoreRepInstance;
  CATUnicodeString CacheInstance;
  CATString csCacheInstance;
  CATOmxKeyString ksCacheInstance;
  CATUnicodeString CacheInstanceModeler;
  CATUnicodeString VPMReference;
  CATOmxKeyString ksVPMReference;
  CATUnicodeString VPMRepReference;
  CATUnicodeString VPMInstance;
  CATOmxKeyString ksVPMInstance;
  CATUnicodeString DELFmiFunctionReference;
  CATOmxKeyString ksVPMCfgEffectivity;
  CATOmxKeyString ksPLMPosDeliverableCnx;
  CATOmxKeyString ksPLMSample2LightConnection;
  CATOmxKeyString ksPLMSample3InstAWithSR;
  CATOmxKeyString ksPLMSample2Connection;
  CATString csPLMEntity;
  CATString csPLMReference;
  CATString csPLMInstance;
  CATUnicodeString VPLMrelSlashPLMConnectionSlashV_Owner;
  CATOmxKeyString ksVPLMrelSlashPLMConnectionSlashV_Owner;
  CATUnicodeString VPLMrelSlashPLMPortSlashV_Owner;
  CATOmxKeyString ksVPLMrelSlashPLMPortSlashV_Owner;
  CATUnicodeString PLMConnectionSlashV_Owner;
  CATOmxKeyString ksPLMConnectionSlashV_Owner;
  CATUnicodeString PLMPortSlashV_Owner;
  CATOmxKeyString ksPLMPortSlashV_Owner;
  CATUnicodeString ThreeDShape;
  CATOmxKeyString ksThreeDShape;

  CATOmxKeyString ksWspTableEntry;
  CATOmxKeyString ksHistoryEntry;
  CATOmxKeyString DWS_physicalIdWS;
  CATOmxKeyString DWS_logicalIdWS;
  CATOmxKeyString DWS_majorIdWS;
  CATOmxKeyString DWS_physicalIdParentWS;
  CATOmxKeyString DWS_logicalIdParentWS;
  CATOmxKeyString DWS_majorIdParentWS;
  CATOmxKeyString DWS_physicalIdObject;
  CATOmxKeyString DWS_logicalIdObject;
  CATOmxKeyString DWS_majorIdObject;
  CATOmxKeyString DWS_physicalIdObjectInParentWS;
  CATOmxKeyString DWS_logicalIdObjectInParentWS;
  CATOmxKeyString DWS_majorIdObjectInParentWS;
  CATOmxKeyString DWS_status;
  CATOmxKeyString DWS_localReserve;
  CATOmxKeyString DWS_parentReserve;

  CATOmxKeyString ksUndefinedType;

  // Expand
  CATOmxKeyString ksLevel; // a.k.a depth
  CATOmxKeyString ksRelationship;
  CATOmxKeyString ksDirection;

  CATUnicodeString PLMABSTRACT;
  CATUnicodeString ERCoreModeler;

  CATUnicodeString Core;
  CATUnicodeString Specialization;
  CATUnicodeString Custo;

  CATUnicodeString ObjectNature;
  CATUnicodeString RelationNature;

  // -------------------------------
  // composition
  // -------------------------------
  // bo
  CATUnicodeString Aggregated;
  CATUnicodeString MayBeAggregated;//ptet ben que c'est aggrégé...
  CATUnicodeString Independent;
#ifdef CATIAR424
  CATOmxKeyString ksiscomposee;
  CATString ATTR_iscomposee;

  CATOmxKeyString kstypedotcompositional;/*XMQL*/
  CATString ATTR_typedotcompositional;
  // Moved in CATPLMiPMLDefGrammar
  //CATOmxKeyString kstypecoloncompositional;/*IPML not supported*/
#endif
  // rel
  CATUnicodeString Aggregation;
  // -------------------------------

  // RepoPrivilege is found for IRPC on PLMEntity, it is a global attribute...
  // RepoPrivilege is found on historical ER on interface  repoprivilegeitf...
  const CATOmxKeyString ksRepoPrivilege;//XMQL real attribute defined by M1 kernel + PLMQL read
  const CATString ATTR_RepoPrivilege;//XMQL real attribute defined by M1 kernel + PLMQL read
  const CATOmxKeyString ksrepoprivilege;//PLMQL write only...

  //CATOmxKeyString ksSemanticRelation;// transferred in CATPLMDicPathTypeCstDef
  //CATUnicodeString SemanticRelation;// transferred in CATPLMDicPathTypeCstDef

  CATPLMRepositoryName PLM1;
  CATPLMRepositoryName PLMxT;
  CATPLMRepositoryName TST;
  CATPLMRepositoryName TSTV5;

  ~CATPLMDicCstDef();

private:
  CATPLMDicCstDef();

  CATPLMDicCstDef(const CATPLMDicCstDef &);
  CATPLMDicCstDef& operator=(const CATPLMDicCstDef&);

};

#endif
