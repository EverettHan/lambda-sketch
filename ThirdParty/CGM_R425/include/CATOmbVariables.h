// COPYRIGHT DASSAULT SYSTEMES 2000
//===================================================================
//
// CATOmbVariables.h
//
//===================================================================
//
// Usage notes: Development environment variables.
//
//===================================================================
//
// CATOmbVariables
//===================================================================
#ifndef CATOmbVariables_H
#define CATOmbVariables_H

/**
* @level Private
* @usage U1
*/

// ObjectModelerBase
#include "AD0XXBAS.h"
// ObjectModelerSystem
#include "CATPLMSDProperties.h"
// SystemTS
#include "CATBoolean.h"

//-----------------------------------------------------------------------
#define OMB_UNDO_LA_DEV 1

class ExportedByAD0XXBAS CATOmbVariables
{
public:
  /**
  * For RepRef in TOS development.
  */
  static CATBoolean PLMMultiRep();

  /**
  * For SelectiveLoading in development.
  */
  static CATBoolean PLMSelectiveLoading();

  /**
  * For Composite File and PX1CAA / PUI Demo Toolbars
  */
  static CATBoolean PLMCompositeFile();

  /**
  * Authoring_Mode and PartEdit_Mode are replaces by FullEdit_Mode.
  * Laoding a container in PartBrep_Mode will force the switch to FullEdit_Mode
  */
  static CATBoolean ForceFullEditModeForCAA() { return TRUE; }

  /**
  * Loading a RepRef in AuthoringVisu_Mode or AuthoringVisu2_Mode will the UV document
  */
  static CATBoolean ForceVisuInUV();

  /**
  * Loading a RepRef in AuthoringVisu2_Mode will the UV document. (In AuthoringVisu_Mode, the cgr document will be loaded)
  */
  static CATBoolean AllowVisuInUV();

  /**
  * Allow creation of Ports On Representation References
  */
  static CATBoolean EnablePortsOnRep();

  /**
  * Disable New R211 (R2012) sub-CATNonCATIADocument late typing for non CATIA documents
  * (instead of previous generic extension late typing)
  */
  static CATBoolean DisableNonCATIALateTyping();

  /**
  * LA dev on R212rel to keep undo/redo log after open
  */
  static CATBoolean KeepUndoAfterOpen_LA();

  /**
  * Activates the coherency check on user file name extension proposed for Non CATIA doc projection
  */
  static CATBoolean CheckProjectionExtension();

  /**
  * set OMB_STREAMS_ON_ENTITIES=1
  * not activated before R418
  * => Allow streams (Archive role) on entities
  */
  static CATBoolean StreamsOnEntities() { return CATPLMSDProperties::IsStreamsOnEntityActivated(); }

  /**
  * set OMB_V5INV6FullAccess=1 + Internal DS
  * not activated
  * => Allow unrestricted loading of CATIAV5INV6 streams
  */
  static CATBoolean V5INV6FullAccess();

  /**
  * set OMB_COLLABORATIVE_ACCESS=1 + Internal DS
  * not activated
  * => Allow Collaborative Access streams
  */
  static CATBoolean CollaborativeAccess();

  /**
  * set OMB_FORCE_LOAD_WITH_NATIVE_ACCESS=1 + Internal DS
  * not activated
  * => Force Rep Ref to be loaded always in NativeAccess
  */
  static CATBoolean ForceLoadWithNativeAccess();

  /**
  * set OMB_COLLABORATIVE_UVR_VISU=1 + Internal DS
  * not activated
  * => Allow Collaborative Access streams
  */
  static CATBoolean CollaborativeUVRVisu();

  /**
  * set PCACHE_EXTENSIONNAME=myExtensionName (PLMOsmTstConnectionAuxiliary4 for test in CATPLMSpecsModeler.tst for example)
  * not activated
  * => define the name of the extension to be used for pCache management
  */
  static const char* pCacheExtensionName();

  /**
  * set OMB_NO_FAILURE_ON_CONTAINER_LOAD=1
  * not activated
  * => ignore failure on applicative containers loading
  */
  static CATBoolean NoFailureOnContainerLoad();

  /**
  * set OMB_OLD_V5INV6_LOAD_SEQUENCE=1
  * not activated
  * => ignore last improvements about V5INV6 global CATPartloading sequence
  */
  static CATBoolean NoFailureOnV5InV6LoadSequence();

  /**
  * set OMB_V5INV6ReadOnly=1
  * not activated
  * => Activate read-only checks on CATIAV5INV6 streams
  */
  static CATBoolean V5INV6ReadOnly();

  /**
  * set OMB_NO_REVERT_ON_ABORTED_SWITCH=1
  * not activated
  * => ignore reverting aborted switches to their initial load mode
  */
  static CATBoolean NoRevertOnAbortedSwitch();

  /**
  * set OMB_NO_EXPORTER_DECLARATION_CATCHUP=1
  * not activated
  * => ignore exporter declaration catchup when new param Role is missing in .xdefinition/.capa declarative file
  */
  static CATBoolean NoExporterDeclarationCatchUp();

  /**
  * set V5INV6ModificationError=1
  * activated
  * => Activate modification error when attempting to modify V5INV6 data
  */
  static CATBoolean V5INV6ModificationError();

  /**
  * set DerivedFromCollaborativeModificationError=1
  * activated
  * => Activate modification error when attempting to modify DerivedFromCollaborative data
  */
  static CATBoolean DerivedFromCollaborativeModificationError();

  /**
  * set OMB_DOWNLOAD_LARGEFILE_IF_LOCALSAVE=1
  * not activated
  * => continues downloading large file streams at open if LocalSave active
  */
  static CATBoolean DownloadLargeFileIfLocalSave();

  /**
  * set OMB_RULES_CATSHAPE=1
  * not activated
  * new rules for CATShape
  */
  static CATBoolean NewRulesForCATShape();

  /**
  * set OMB_OUTLINER=1
  * activated since R419
  * Unset it with NO_OMB_OUTLINER=1
  * activation for outliners
  */
  static CATBoolean OutlinersActivated();

  /**
  * set OMB_DownwardCompatibility=1
  * activate downwardCompatibility and possibility to create a repRef with a lower soft level stream
  * for instance create a repRef that will be streamed in 13x format on a R419 CNEXT
  */
  static CATBoolean DownwardCompatibilityActivated();

  /**
  * set OMB_V5INV6AttributeSave=1
  * not activated
  * => Allow session modification(s) of PLM attributes belonging to CATIAV5INV6 (V5Native) RepRef to be saved
  */
  static CATBoolean V5INV6AttributeSave();

  /**
  * set OMB_NoCGRContLoad=1
  * not activated, not activable before R420
  * => do not load CGRCont during globalLoad
  */
  static CATBoolean NoCGRContLoad();

  /**
  * set OMB_NO_CLONING_OF_CLONE_FIXING=1
  * not activated
  * => ignore fix IR-553760 about Saving clone of cloned StreamDescriptor in Session
  */
  static CATBoolean NoCloningOfCloneFixing();

  /**
  * set OMB_NO_CheckFileNameAtAddSD=1 to disable check file name when adding SD (adding an sd with special characters in persistency name will fail)
  */
  static CATBoolean CheckFileNameAtAddSD();

  /**
  * set OMB_FORGET_SYNCHRO_LOCAL_SAVE=1 or > 1
  * not activated
  * if set, ignore fix for IR-564382 : global SynchroStamp persistency problem in PXn is not corrected
  */
  static int ForgetSynchroLocalSave();

  /**
  * set OMB_FULL_DYNAMIC_PERSIST_TYPING=1
  * not activated
  * if set, when using AddExtendedSDToRepRefForSimulia/AddDynamicExtendedSD with a Persistency type not yet declared in
  * static PersistencyType>Latetype hierarchy table, this PT is not added to this static table
  */
  static int FullDynamicPersistTyping();
  /**
  * common to OMB/VVS/OMY
  * set OMY_MANAGE_LOCAL_STORAGE_LOCK=0 to disable LocalStorage lock/remove management, from R420 on
  */
  static CATBoolean ManageLocalStorageLock();

  /**
  * set OMB_UDL_R2019x=1 to enable UDL secondary format management in V6R2019x
  * set OMB_UDL_R2020x=0 to disable UDL secondary format management in V6R2020x
  * (always TRUE for V6R2020x and >  | always FALSE before V6R2019x)
  */
  static CATBoolean ManageUDLFormat();

  /**
  * set OMB_SET_LOCAL_STORAGE_OWNER=1 to enable storing LocalStorage FileDescription V2 = LocalfilePath(V1) + PhysicalId of component set by user to LocalStorage
  * (always TRUE for V6R2020x and >  | always FALSE before V6R2019x)
  */
  static CATBoolean SetLocalStorageOwner();

  /**
  * set OMB_MANAGE_COMP_CHECK_ON_STREAMS=0 to enable back secondary streams generation requests at ComponentCheck time. 
  *  generation request is disabled by specification during ComponentChecker action. 
  *  this variable should only be deactivated on purpose for debug/convergence.
  */
  static CATBoolean ManageComponentCheckerOnStreams();

  /**
  * set OMB_LOG_MIGRATION_PCS=1 to enable PCS logging of migration operation (MigrateFromPart/Drawing/Product) logging and CATDocumentServices::Open
  * this can be used with MipMip variables to generate MipMip for these operations
  */
  static bool IsLoggingMigrationPCS();

  /**
  * set OMB_MD5_GEN_FOR_SAVE_OPEN=1 to enable MD5 generation before Save (switch all stamps with MD5)
  */
  static CATBoolean MD5GenerationForSaveOpenTransaction();
  /**
    * set OMB_NO_ALTER_FORMAT_OVERTYPE=1 to disable Alternative format management
  */
  static CATBoolean ManageAlternativeFormatOvertype();

  /**
  * Disabled for now. set OMB_AUTHORIZE_CONTAINER_OVER2GB=1
  */
  static bool AreOver2GbContainersAuthorized();

  /**
  * set OMB_CATISTREAM2=1 before R426
  * to deactivate : set OMB_NO_CATISTREAM2 from R426 included
  */
  static bool IsCATIStream2Activated();
  /**
  * TEMP STUFF FOR PASCAL PETIN
  */
  static CATBoolean IsNewNativeToXCADFormatActivated();
  /**
  * YET MORE TEMP STUFF FOR PASCAL PETIN   :)
  */
  static CATBoolean IsRuntimeUpdaterActivated();
};
//-----------------------------------------------------------------------
#endif
