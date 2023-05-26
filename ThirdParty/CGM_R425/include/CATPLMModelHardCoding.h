/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATPLMModelHardCoding_H
#define CATPLMModelHardCoding_H

#include "CATOmxKeyString.h"

// HACK OpenEngineMediator.
#define g_VPMTechPackExtension "VPMTechPackExtension"

// HARD CODAGE DU PLMCORE

#define g_PLMCoreModeler "PLMCORE"
#define g_PLMCoreReference "PLMCoreReference"
#define g_PLMCoreInstance "PLMCoreInstance"
#define g_PLMCoreRepReference "PLMCoreRepReference"
#define g_PLMCoreRepInstance "PLMCoreRepInstance"
#define g_PLMCorePort "PLMPort"
#define g_PLMCoreConnection "PLMConnection"
#define g_PLMCoreEntity "BusinessType"
#define g_PLMCoreRelation "RelationType"
#define g_PLMExternalId "PLM_ExternalID"
#define g_name "name"
#define g_PLMIsOwnedBy "V_Owner"
#define g_PLMIsInstanceOf "V_InstanceOf"
#define g_PLMPreferredRepInstance "V_PreferredRepInstance"
#define g_PLMIsOnceInstantiable "V_isOnceInstantiable"
#define g_PLMIsLastVersion "V_isLastVersion"

// Private reps modeler
#define g_LPPRIVATEREPModeler  "LPPRIVATEREP"

// Composition
#define g_iscomposee "iscomposee"
#define g_compositional "type:compositional"

// Config modelers.
#define g_PLMBRIDGE_CfgContext_Modeler "VPMCfgContext"
#define g_PLMBRIDGE_CfgStaticMapping_Modeler "VPMCfgInstanceConfiguration"
#define g_PLMConfigEffectivity_Modeler "VPMCfgEffectivity"
#define g_PLMConfigApplicability_Modeler "VPMCfgApplicability"
#define g_PLMConfiguration_Modeler "VPMCfgConfiguration"

// Dataspace.
#define g_CATIA3D_Dataspace "CATIA3D"
#define g_3DLiveTOS_Dataspace "3DLiveTOS"
#define g_Completion_Dataspace "CompletionSpace"

// Catalog modelers.
#define g_Catalog_Livrary_Modeler "ENOCLG_LIBRARY"
#define g_Catalog_Class_Modeler "ENOCLG_CLASS"
#define g_Catalog_Keyword_Modeler "ENOCLG_KEYWORD"
#define g_Catalog_Modeler "ENOCLG_CATALOG" // Old modeler
#define g_Catalog_Chapter_Modeler "ENOCLG_CHAPTER" // Old modeler

// Folder Modeler
#define g_Folder_Root_Modeler "ENOFLD_FOLDER_ROOT"
#define g_Folder_Ref_Modeler "ENOFLD_FOLDER_REF"

// DWS Modeler
#define g_Workspace_Root_Modeler "ENOWSP_WORKSPACE_ROOT"
#define g_Workspace_Ref_Modeler "ENOWSP_WORKSPACE"

// Test Modeler
#define g_PLMSAMPLE2_Modeler "PLMSAMPLE2"
#define g_PLMSAMPLE2Light_Modeler "PLMSAMPLE2Light"
#define g_PLMSAMPLE2Custo1_Package "PLMSAMPLE2Custo1"
#define g_PLMSAMPLE2_Package "PLMSAMPLE2"

#endif
