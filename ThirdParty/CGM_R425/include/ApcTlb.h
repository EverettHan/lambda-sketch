/* --------------------------------------------------------------------------
* ApcTlb.h
*
* Header file for the APC COM interfaces.
*
* This file is part of the Microsoft OneTool Wrapper (APC)
* Copyright (c) 1999, Microsoft Corporation. All Rights Reserved.
* Information Contained Herein Is Proprietary and Confidential.
* -------------------------------------------------------------------------- */


/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Apr 05 10:44:39 2017
 */
/* Compiler settings for .\vbahost.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __vbatlb_h__
#define __vbatlb_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IApcX_FWD_DEFINED__
#define __IApcX_FWD_DEFINED__
typedef interface IApcX IApcX;
#endif 	/* __IApcX_FWD_DEFINED__ */


#ifndef __IApcGlobal_FWD_DEFINED__
#define __IApcGlobal_FWD_DEFINED__
typedef interface IApcGlobal IApcGlobal;
#endif 	/* __IApcGlobal_FWD_DEFINED__ */


#ifndef __IApc_FWD_DEFINED__
#define __IApc_FWD_DEFINED__
typedef interface IApc IApc;
#endif 	/* __IApc_FWD_DEFINED__ */


#ifndef __IApcEvents_FWD_DEFINED__
#define __IApcEvents_FWD_DEFINED__
typedef interface IApcEvents IApcEvents;
#endif 	/* __IApcEvents_FWD_DEFINED__ */


#ifndef __IApcIde_FWD_DEFINED__
#define __IApcIde_FWD_DEFINED__
typedef interface IApcIde IApcIde;
#endif 	/* __IApcIde_FWD_DEFINED__ */


#ifndef __IApcIdeEvents_FWD_DEFINED__
#define __IApcIdeEvents_FWD_DEFINED__
typedef interface IApcIdeEvents IApcIdeEvents;
#endif 	/* __IApcIdeEvents_FWD_DEFINED__ */


#ifndef __IApcPropertiesWindow_FWD_DEFINED__
#define __IApcPropertiesWindow_FWD_DEFINED__
typedef interface IApcPropertiesWindow IApcPropertiesWindow;
#endif 	/* __IApcPropertiesWindow_FWD_DEFINED__ */


#ifndef __IApcProjects_FWD_DEFINED__
#define __IApcProjects_FWD_DEFINED__
typedef interface IApcProjects IApcProjects;
#endif 	/* __IApcProjects_FWD_DEFINED__ */


#ifndef __IApcProject_FWD_DEFINED__
#define __IApcProject_FWD_DEFINED__
typedef interface IApcProject IApcProject;
#endif 	/* __IApcProject_FWD_DEFINED__ */


#ifndef __IApcProjectEvents_FWD_DEFINED__
#define __IApcProjectEvents_FWD_DEFINED__
typedef interface IApcProjectEvents IApcProjectEvents;
#endif 	/* __IApcProjectEvents_FWD_DEFINED__ */


#ifndef __IApcProjectItems_FWD_DEFINED__
#define __IApcProjectItems_FWD_DEFINED__
typedef interface IApcProjectItems IApcProjectItems;
#endif 	/* __IApcProjectItems_FWD_DEFINED__ */


#ifndef __IApcProjectItem_FWD_DEFINED__
#define __IApcProjectItem_FWD_DEFINED__
typedef interface IApcProjectItem IApcProjectItem;
#endif 	/* __IApcProjectItem_FWD_DEFINED__ */


#ifndef __IApcProjectItemEvents_FWD_DEFINED__
#define __IApcProjectItemEvents_FWD_DEFINED__
typedef interface IApcProjectItemEvents IApcProjectItemEvents;
#endif 	/* __IApcProjectItemEvents_FWD_DEFINED__ */


#ifndef __IApcControls_FWD_DEFINED__
#define __IApcControls_FWD_DEFINED__
typedef interface IApcControls IApcControls;
#endif 	/* __IApcControls_FWD_DEFINED__ */


#ifndef __IApcControl_FWD_DEFINED__
#define __IApcControl_FWD_DEFINED__
typedef interface IApcControl IApcControl;
#endif 	/* __IApcControl_FWD_DEFINED__ */


#ifndef __IApcControlEvents_FWD_DEFINED__
#define __IApcControlEvents_FWD_DEFINED__
typedef interface IApcControlEvents IApcControlEvents;
#endif 	/* __IApcControlEvents_FWD_DEFINED__ */


#ifndef __IApcProcedures_FWD_DEFINED__
#define __IApcProcedures_FWD_DEFINED__
typedef interface IApcProcedures IApcProcedures;
#endif 	/* __IApcProcedures_FWD_DEFINED__ */


#ifndef __IApcProcedure_FWD_DEFINED__
#define __IApcProcedure_FWD_DEFINED__
typedef interface IApcProcedure IApcProcedure;
#endif 	/* __IApcProcedure_FWD_DEFINED__ */


#ifndef __IApcCategories_FWD_DEFINED__
#define __IApcCategories_FWD_DEFINED__
typedef interface IApcCategories IApcCategories;
#endif 	/* __IApcCategories_FWD_DEFINED__ */


#ifndef __IApcCategory_FWD_DEFINED__
#define __IApcCategory_FWD_DEFINED__
typedef interface IApcCategory IApcCategory;
#endif 	/* __IApcCategory_FWD_DEFINED__ */


#ifndef __IApcMiniBitmaps_FWD_DEFINED__
#define __IApcMiniBitmaps_FWD_DEFINED__
typedef interface IApcMiniBitmaps IApcMiniBitmaps;
#endif 	/* __IApcMiniBitmaps_FWD_DEFINED__ */


#ifndef __IApcMiniBitmap_FWD_DEFINED__
#define __IApcMiniBitmap_FWD_DEFINED__
typedef interface IApcMiniBitmap IApcMiniBitmap;
#endif 	/* __IApcMiniBitmap_FWD_DEFINED__ */


#ifndef __IApcRecorder_FWD_DEFINED__
#define __IApcRecorder_FWD_DEFINED__
typedef interface IApcRecorder IApcRecorder;
#endif 	/* __IApcRecorder_FWD_DEFINED__ */


#ifndef __IApcScopes_FWD_DEFINED__
#define __IApcScopes_FWD_DEFINED__
typedef interface IApcScopes IApcScopes;
#endif 	/* __IApcScopes_FWD_DEFINED__ */


#ifndef __IApcScope_FWD_DEFINED__
#define __IApcScope_FWD_DEFINED__
typedef interface IApcScope IApcScope;
#endif 	/* __IApcScope_FWD_DEFINED__ */


#ifndef __IApcMacrosDialog_FWD_DEFINED__
#define __IApcMacrosDialog_FWD_DEFINED__
typedef interface IApcMacrosDialog IApcMacrosDialog;
#endif 	/* __IApcMacrosDialog_FWD_DEFINED__ */


#ifndef __IApcStorage_FWD_DEFINED__
#define __IApcStorage_FWD_DEFINED__
typedef interface IApcStorage IApcStorage;
#endif 	/* __IApcStorage_FWD_DEFINED__ */


#ifndef __IApcStream_FWD_DEFINED__
#define __IApcStream_FWD_DEFINED__
typedef interface IApcStream IApcStream;
#endif 	/* __IApcStream_FWD_DEFINED__ */


#ifndef __IApcRequiredClasses_FWD_DEFINED__
#define __IApcRequiredClasses_FWD_DEFINED__
typedef interface IApcRequiredClasses IApcRequiredClasses;
#endif 	/* __IApcRequiredClasses_FWD_DEFINED__ */


#ifndef __IApcRequiredClass_FWD_DEFINED__
#define __IApcRequiredClass_FWD_DEFINED__
typedef interface IApcRequiredClass IApcRequiredClass;
#endif 	/* __IApcRequiredClass_FWD_DEFINED__ */


#ifndef __IApcExtender_FWD_DEFINED__
#define __IApcExtender_FWD_DEFINED__
typedef interface IApcExtender IApcExtender;
#endif 	/* __IApcExtender_FWD_DEFINED__ */


#ifndef __IApcSite_FWD_DEFINED__
#define __IApcSite_FWD_DEFINED__
typedef interface IApcSite IApcSite;
#endif 	/* __IApcSite_FWD_DEFINED__ */


#ifndef __IApcCompManager_FWD_DEFINED__
#define __IApcCompManager_FWD_DEFINED__
typedef interface IApcCompManager IApcCompManager;
#endif 	/* __IApcCompManager_FWD_DEFINED__ */


#ifndef __IApcInstances_FWD_DEFINED__
#define __IApcInstances_FWD_DEFINED__
typedef interface IApcInstances IApcInstances;
#endif 	/* __IApcInstances_FWD_DEFINED__ */


#ifndef __IApcHostAddIns_FWD_DEFINED__
#define __IApcHostAddIns_FWD_DEFINED__
typedef interface IApcHostAddIns IApcHostAddIns;
#endif 	/* __IApcHostAddIns_FWD_DEFINED__ */


#ifndef __IApcLegacyEvents_FWD_DEFINED__
#define __IApcLegacyEvents_FWD_DEFINED__
typedef interface IApcLegacyEvents IApcLegacyEvents;
#endif 	/* __IApcLegacyEvents_FWD_DEFINED__ */


#ifndef __ApcGlobal_FWD_DEFINED__
#define __ApcGlobal_FWD_DEFINED__

#ifdef __cplusplus
typedef class ApcGlobal ApcGlobal;
#else
typedef struct ApcGlobal ApcGlobal;
#endif /* __cplusplus */

#endif 	/* __ApcGlobal_FWD_DEFINED__ */


#ifndef __ApcEvents_FWD_DEFINED__
#define __ApcEvents_FWD_DEFINED__
typedef interface ApcEvents ApcEvents;
#endif 	/* __ApcEvents_FWD_DEFINED__ */


#ifndef __Apc_FWD_DEFINED__
#define __Apc_FWD_DEFINED__

#ifdef __cplusplus
typedef class Apc Apc;
#else
typedef struct Apc Apc;
#endif /* __cplusplus */

#endif 	/* __Apc_FWD_DEFINED__ */


#ifndef __ApcIdeEvents_FWD_DEFINED__
#define __ApcIdeEvents_FWD_DEFINED__
typedef interface ApcIdeEvents ApcIdeEvents;
#endif 	/* __ApcIdeEvents_FWD_DEFINED__ */


#ifndef __IDE_FWD_DEFINED__
#define __IDE_FWD_DEFINED__

#ifdef __cplusplus
typedef class IDE IDE;
#else
typedef struct IDE IDE;
#endif /* __cplusplus */

#endif 	/* __IDE_FWD_DEFINED__ */


#ifndef __PropertiesWindow_FWD_DEFINED__
#define __PropertiesWindow_FWD_DEFINED__

#ifdef __cplusplus
typedef class PropertiesWindow PropertiesWindow;
#else
typedef struct PropertiesWindow PropertiesWindow;
#endif /* __cplusplus */

#endif 	/* __PropertiesWindow_FWD_DEFINED__ */


#ifndef __Projects_FWD_DEFINED__
#define __Projects_FWD_DEFINED__

#ifdef __cplusplus
typedef class Projects Projects;
#else
typedef struct Projects Projects;
#endif /* __cplusplus */

#endif 	/* __Projects_FWD_DEFINED__ */


#ifndef __ApcProjectEvents_FWD_DEFINED__
#define __ApcProjectEvents_FWD_DEFINED__
typedef interface ApcProjectEvents ApcProjectEvents;
#endif 	/* __ApcProjectEvents_FWD_DEFINED__ */


#ifndef __Project_FWD_DEFINED__
#define __Project_FWD_DEFINED__

#ifdef __cplusplus
typedef class Project Project;
#else
typedef struct Project Project;
#endif /* __cplusplus */

#endif 	/* __Project_FWD_DEFINED__ */


#ifndef __ProjectItems_FWD_DEFINED__
#define __ProjectItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProjectItems ProjectItems;
#else
typedef struct ProjectItems ProjectItems;
#endif /* __cplusplus */

#endif 	/* __ProjectItems_FWD_DEFINED__ */


#ifndef __ApcProjectItemEvents_FWD_DEFINED__
#define __ApcProjectItemEvents_FWD_DEFINED__
typedef interface ApcProjectItemEvents ApcProjectItemEvents;
#endif 	/* __ApcProjectItemEvents_FWD_DEFINED__ */


#ifndef __ProjectItem_FWD_DEFINED__
#define __ProjectItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProjectItem ProjectItem;
#else
typedef struct ProjectItem ProjectItem;
#endif /* __cplusplus */

#endif 	/* __ProjectItem_FWD_DEFINED__ */


#ifndef __Controls_FWD_DEFINED__
#define __Controls_FWD_DEFINED__

#ifdef __cplusplus
typedef class Controls Controls;
#else
typedef struct Controls Controls;
#endif /* __cplusplus */

#endif 	/* __Controls_FWD_DEFINED__ */


#ifndef __ApcControlEvents_FWD_DEFINED__
#define __ApcControlEvents_FWD_DEFINED__
typedef interface ApcControlEvents ApcControlEvents;
#endif 	/* __ApcControlEvents_FWD_DEFINED__ */


#ifndef __Control_FWD_DEFINED__
#define __Control_FWD_DEFINED__

#ifdef __cplusplus
typedef class Control Control;
#else
typedef struct Control Control;
#endif /* __cplusplus */

#endif 	/* __Control_FWD_DEFINED__ */


#ifndef __Procedures_FWD_DEFINED__
#define __Procedures_FWD_DEFINED__

#ifdef __cplusplus
typedef class Procedures Procedures;
#else
typedef struct Procedures Procedures;
#endif /* __cplusplus */

#endif 	/* __Procedures_FWD_DEFINED__ */


#ifndef __Procedure_FWD_DEFINED__
#define __Procedure_FWD_DEFINED__

#ifdef __cplusplus
typedef class Procedure Procedure;
#else
typedef struct Procedure Procedure;
#endif /* __cplusplus */

#endif 	/* __Procedure_FWD_DEFINED__ */


#ifndef __Categories_FWD_DEFINED__
#define __Categories_FWD_DEFINED__

#ifdef __cplusplus
typedef class Categories Categories;
#else
typedef struct Categories Categories;
#endif /* __cplusplus */

#endif 	/* __Categories_FWD_DEFINED__ */


#ifndef __Category_FWD_DEFINED__
#define __Category_FWD_DEFINED__

#ifdef __cplusplus
typedef class Category Category;
#else
typedef struct Category Category;
#endif /* __cplusplus */

#endif 	/* __Category_FWD_DEFINED__ */


#ifndef __MiniBitmaps_FWD_DEFINED__
#define __MiniBitmaps_FWD_DEFINED__

#ifdef __cplusplus
typedef class MiniBitmaps MiniBitmaps;
#else
typedef struct MiniBitmaps MiniBitmaps;
#endif /* __cplusplus */

#endif 	/* __MiniBitmaps_FWD_DEFINED__ */


#ifndef __MiniBitmap_FWD_DEFINED__
#define __MiniBitmap_FWD_DEFINED__

#ifdef __cplusplus
typedef class MiniBitmap MiniBitmap;
#else
typedef struct MiniBitmap MiniBitmap;
#endif /* __cplusplus */

#endif 	/* __MiniBitmap_FWD_DEFINED__ */


#ifndef __Recorder_FWD_DEFINED__
#define __Recorder_FWD_DEFINED__

#ifdef __cplusplus
typedef class Recorder Recorder;
#else
typedef struct Recorder Recorder;
#endif /* __cplusplus */

#endif 	/* __Recorder_FWD_DEFINED__ */


#ifndef __Scopes_FWD_DEFINED__
#define __Scopes_FWD_DEFINED__

#ifdef __cplusplus
typedef class Scopes Scopes;
#else
typedef struct Scopes Scopes;
#endif /* __cplusplus */

#endif 	/* __Scopes_FWD_DEFINED__ */


#ifndef __Scope_FWD_DEFINED__
#define __Scope_FWD_DEFINED__

#ifdef __cplusplus
typedef class Scope Scope;
#else
typedef struct Scope Scope;
#endif /* __cplusplus */

#endif 	/* __Scope_FWD_DEFINED__ */


#ifndef __MacrosDialog_FWD_DEFINED__
#define __MacrosDialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class MacrosDialog MacrosDialog;
#else
typedef struct MacrosDialog MacrosDialog;
#endif /* __cplusplus */

#endif 	/* __MacrosDialog_FWD_DEFINED__ */


#ifndef __Storage_FWD_DEFINED__
#define __Storage_FWD_DEFINED__

#ifdef __cplusplus
typedef class Storage Storage;
#else
typedef struct Storage Storage;
#endif /* __cplusplus */

#endif 	/* __Storage_FWD_DEFINED__ */


#ifndef __Stream_FWD_DEFINED__
#define __Stream_FWD_DEFINED__

#ifdef __cplusplus
typedef class Stream Stream;
#else
typedef struct Stream Stream;
#endif /* __cplusplus */

#endif 	/* __Stream_FWD_DEFINED__ */


#ifndef __RequiredClasses_FWD_DEFINED__
#define __RequiredClasses_FWD_DEFINED__

#ifdef __cplusplus
typedef class RequiredClasses RequiredClasses;
#else
typedef struct RequiredClasses RequiredClasses;
#endif /* __cplusplus */

#endif 	/* __RequiredClasses_FWD_DEFINED__ */


#ifndef __RequiredClass_FWD_DEFINED__
#define __RequiredClass_FWD_DEFINED__

#ifdef __cplusplus
typedef class RequiredClass RequiredClass;
#else
typedef struct RequiredClass RequiredClass;
#endif /* __cplusplus */

#endif 	/* __RequiredClass_FWD_DEFINED__ */


#ifndef __ApcExtenderDisp_FWD_DEFINED__
#define __ApcExtenderDisp_FWD_DEFINED__
typedef interface ApcExtenderDisp ApcExtenderDisp;
#endif 	/* __ApcExtenderDisp_FWD_DEFINED__ */


#ifndef __ApcExtenderEvents_FWD_DEFINED__
#define __ApcExtenderEvents_FWD_DEFINED__
typedef interface ApcExtenderEvents ApcExtenderEvents;
#endif 	/* __ApcExtenderEvents_FWD_DEFINED__ */


#ifndef __ApcExtender_FWD_DEFINED__
#define __ApcExtender_FWD_DEFINED__

#ifdef __cplusplus
typedef class ApcExtender ApcExtender;
#else
typedef struct ApcExtender ApcExtender;
#endif /* __cplusplus */

#endif 	/* __ApcExtender_FWD_DEFINED__ */


#ifndef __IApcExtender64_FWD_DEFINED__
#define __IApcExtender64_FWD_DEFINED__
typedef interface IApcExtender64 IApcExtender64;
#endif 	/* __IApcExtender64_FWD_DEFINED__ */


#ifndef __ApcExtenderDisp64_FWD_DEFINED__
#define __ApcExtenderDisp64_FWD_DEFINED__
typedef interface ApcExtenderDisp64 ApcExtenderDisp64;
#endif 	/* __ApcExtenderDisp64_FWD_DEFINED__ */


#ifndef __ApcExtenderEvents64_FWD_DEFINED__
#define __ApcExtenderEvents64_FWD_DEFINED__
typedef interface ApcExtenderEvents64 ApcExtenderEvents64;
#endif 	/* __ApcExtenderEvents64_FWD_DEFINED__ */


#ifndef __ApcExtender64_FWD_DEFINED__
#define __ApcExtender64_FWD_DEFINED__

#ifdef __cplusplus
typedef class ApcExtender64 ApcExtender64;
#else
typedef struct ApcExtender64 ApcExtender64;
#endif /* __cplusplus */

#endif 	/* __ApcExtender64_FWD_DEFINED__ */


#ifndef __Instances_FWD_DEFINED__
#define __Instances_FWD_DEFINED__

#ifdef __cplusplus
typedef class Instances Instances;
#else
typedef struct Instances Instances;
#endif /* __cplusplus */

#endif 	/* __Instances_FWD_DEFINED__ */


#ifndef __HostAddIns_FWD_DEFINED__
#define __HostAddIns_FWD_DEFINED__

#ifdef __cplusplus
typedef class HostAddIns HostAddIns;
#else
typedef struct HostAddIns HostAddIns;
#endif /* __cplusplus */

#endif 	/* __HostAddIns_FWD_DEFINED__ */


#ifndef __IApcCollection_FWD_DEFINED__
#define __IApcCollection_FWD_DEFINED__
typedef interface IApcCollection IApcCollection;
#endif 	/* __IApcCollection_FWD_DEFINED__ */


#ifndef __Collection_FWD_DEFINED__
#define __Collection_FWD_DEFINED__

#ifdef __cplusplus
typedef class Collection Collection;
#else
typedef struct Collection Collection;
#endif /* __cplusplus */

#endif 	/* __Collection_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "servprov.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vbahost_0000_0000 */
/* [local] */ 

#pragma warning( disable : 4514 )		



extern RPC_IF_HANDLE __MIDL_itf_vbahost_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vbahost_0000_0000_v0_0_s_ifspec;


#ifndef __MSAPC_LIBRARY_DEFINED__
#define __MSAPC_LIBRARY_DEFINED__

/* library MSAPC */
/* [version][helpfile][helpstring][uuid] */ 

#define SID_SApc IID_IApcX
typedef /* [uuid] */  DECLSPEC_UUID("363B4047-DB07-4E41-9F3A-F0CA28A9A975") 
enum AxProjectProtection
    {	axProtectionNone	= 0,
	axProtectionUser	= 1,
	axProtectionHost	= 2,
	axProtectionVBA	= 4
    } 	AxProjectProtection;

typedef AxProjectProtection APCPROJECTPROTECTION;

typedef /* [uuid] */  DECLSPEC_UUID("F01225F7-93F9-4E5C-9F6C-FAF794B3DE2D") 
enum AxProjectFlag
    {	axProjectNormal	= 0,
	axProjectHidden	= 1,
	axProjectDisableMacros	= 2,
	axProjectDisableSave	= 4,
	axProjectThrowAwayCompiledState	= 8
    } 	AxProjectFlag;

typedef AxProjectFlag APCPROJECTFLAG;

typedef /* [uuid] */  DECLSPEC_UUID("FBBE7D52-B8BC-4F1D-BB38-10DD026DC455") 
enum AxProcedureScope
    {	axScopePublic	= 0,
	axScopePrivate	= 1
    } 	AxProcedureScope;

typedef enum AxProcedureScope APCPROCEDURESCOPE;

typedef /* [uuid] */  DECLSPEC_UUID("8CB6B79C-9818-491C-A2AB-A4CABFF4EB5A") 
enum AxProcedureType
    {	axProcTypePropertyLet	= 0,
	axProcTypePropertySet	= 1,
	axProcTypePropertyGet	= 2,
	axProcTypeFunction	= 3,
	axProcTypeSub	= 4,
	axProcTypeEventSub	= 5
    } 	AxProcedureType;

typedef enum AxProcedureType APCPROCEDURETYPE;

typedef /* [uuid] */  DECLSPEC_UUID("D2D63D9A-382E-4400-BBF8-F4CF9D8906B7") 
enum AxControlFlag
    {	axControlNormal	= 0,
	axControlNotInPropertiesWindow	= 1,
	axControlNoCodeBehind	= 2
    } 	AxControlFlag;

typedef enum AxControlFlag APCCONTROLFLAG;

typedef /* [uuid] */  DECLSPEC_UUID("E2301AB6-D42D-4A7E-B709-6B7FDABF0ECD") 
enum AxProjectItemType
    {	axTypeCodeModule	= 0,
	axTypeClassModule	= 1,
	axTypeDesigner	= 2,
	axTypeHostProjectItem	= 3,
	axTypeHostClass	= 4,
	axTypeOther	= 5
    } 	AxProjectItemType;

typedef enum AxProjectItemType APCPROJECTITEMTYPE;

typedef /* [uuid] */  DECLSPEC_UUID("74C9C77D-7493-4F8D-B70D-6745BE551E4B") 
enum AxProjectMode
    {	axModeDesign	= 0,
	axModeRun	= ( axModeDesign + 1 ) 
    } 	AxProjectMode;

typedef enum AxProjectMode APCPROJECTMODE;

typedef /* [uuid] */  DECLSPEC_UUID("44DFE146-4364-4860-B0E7-F685307ECA86") 
enum AxStepMode
    {	axStepNone	= 0,
	axStepInto	= 1,
	axStepOver	= 2
    } 	AxStepMode;

typedef enum AxStepMode APCSTEPMODE;

typedef /* [uuid] */  DECLSPEC_UUID("B4DE8C24-FCE9-48B8-96D9-848D049561C4") 
enum AxAccessMode
    {	axAccessTransacted	= 0x1L,
	axAccessRead	= 0x2L,
	axAccessWrite	= 0x4L,
	axAccessReadWrite	= 0x8L,
	axAccessShared	= 0x10L,
	axAccessLockRead	= 0x20L,
	axAccessLockWrite	= 0x40L,
	axAccessExclusive	= 0x80L,
	axAccessPreserveStorage	= 0x100L,
	axAccessPreserveFlags	= 0x10000000L
    } 	AxAccessMode;

typedef enum AxAccessMode APCACCESSMODE;

typedef /* [uuid] */  DECLSPEC_UUID("22ECF4D0-541C-4F3D-9D51-E5C7CD14ABE9") 
enum AxPropertyCategory
    {	axCategoryNil	= 0xffffffffL,
	axCategoryMisc	= 0xfffffffeL,
	axCategoryFont	= 0xfffffffdL,
	axCategoryPosition	= 0xfffffffcL,
	axCategoryAppearance	= 0xfffffffbL,
	axCategoryBehavior	= 0xfffffffaL,
	axCategoryData	= 0xfffffff9L,
	axCategoryList	= 0xfffffff8L,
	axCategoryText	= 0xfffffff7L,
	axCategoryScale	= 0xfffffff6L,
	axCategoryDDE	= 0xfffffff5L,
	axCategoryUserDefined	= 0L
    } 	AxPropertyCategory;

typedef enum AxPropertyCategory APCPROPERTYCATEGORY;

typedef /* [uuid] */  DECLSPEC_UUID("73C4AEFA-08A1-4074-9182-E60758C5DCC6") 
enum AxDialogStartUpPosition
    {	axPositionManual	= 0,
	axPositionCenterOwner	= 1,
	axPositionCenterScreen	= 2,
	axPositionWindowsDefault	= 3
    } 	AxDialogStartUpPosition;

typedef enum AxDialogStartUpPosition APCDIALOGSTARTUPPOSITION;

typedef /* [restricted][uuid] */  DECLSPEC_UUID("2C5514F9-66E9-475D-96BC-BDA7C62D11C8") 
enum AxMessageLoopReason
    {	axMsgLoopFocusWait	= 0,
	axMsgLoopDoEvents	= 1,
	axMsgLoopDebug	= 2,
	axMsgLoopModalUserForm	= 3
    } 	AxMessageLoopReason;

typedef enum AxMessageLoopReason APCLOOPREASON;

typedef /* [restricted][uuid] */  DECLSPEC_UUID("90E1CE71-2287-4B69-9BB0-2D4ECEB9B7E5") 
enum AxIdleFlag
    {	axIdlePeriodic	= 1,
	axIdleNonPeriodic	= 2,
	axIdlePriority	= 4
    } 	AxIdleFlag;

typedef enum AxIdleFlag APCIDLEFLAG;


enum AxError
    {	APC_E_INVALIDINDEX	= 0x80040500L,
	APC_E_ZOMBIED	= 0x80040501L,
	APC_E_UNEXPECTED	= 0x80040502L,
	APC_E_OUTOFMEMORY	= 0x80040503L,
	APC_E_OPENFILEFAILED	= 0x80040504L,
	APC_E_ONLYDOCITEMS	= 0x80040505L,
	APC_E_VBA	= 0x80040506L,
	APC_E_OUTOFSYNC	= 0x80040507L,
	APC_E_INVALIDITEM	= 0x80040508L,
	APC_E_ONLYCODEMODULES	= 0x80040509L,
	APC_E_PROJECTLOCKED	= 0x8004050aL,
	APC_E_TYPELIBCHANGED	= 0x8004050bL,
	APC_E_CLASSNOTFOUND	= 0x8004050cL,
	APC_E_ONLYSUBROUTINES	= 0x8004050dL,
	APC_E_ALREADYRECORDING	= 0x8004050eL,
	APC_E_UNDOEMPTY	= 0x8004050fL,
	APC_E_NOTEVENT	= 0x80040510L,
	APC_E_TOOMANYCONTROLS	= 0x80040511L,
	APC_E_BADOBJ	= 0x80040512L,
	APC_E_SUBORFUNCEXPECTED	= 0x80040513L,
	APC_E_CANTCOPYTYPELIB	= 0x80040514L,
	APC_E_NOSCOPES	= 0x80040515L,
	APC_E_NOPERMISSION	= 0x80040516L,
	APC_E_TOOMANYOPENFILES	= 0x80040517L,
	APC_E_FILEALREADYEXISTS	= 0x80040518L,
	APC_E_OUTOFDISKSPACE	= 0x80040519L,
	APC_E_ONLYFORINMEMORY	= 0x8004051aL,
	APC_E_CANTACCESSARRAY	= 0x8004051bL,
	APC_E_NOREADORLOCKSTORAGE	= 0x8004051cL,
	APC_E_INVALIDFILENAME	= 0x8004051dL,
	APC_E_INVALIDINMEMORYSTG	= 0x8004051eL,
	APC_E_UNKNOWN	= 0x8004051fL,
	APC_E_INVALIDARG	= 0x80040520L,
	APC_E_INVALIDARG_SPECIFIC	= 0x80040521L,
	APC_E_BADPARMCOUNT	= 0x80040522L,
	APC_E_BADVARTYPE	= 0x80040523L,
	APC_E_OVERFLOW	= 0x80040524L,
	APC_E_TYPEMISMATCH	= 0x80040525L,
	APC_E_PARMNOTOPTIONAL	= 0x80040526L,
	APC_E_UNKNOWNLCID	= 0x80040527L,
	APC_E_CONNECTION_TERMINATED	= 0x80040528L,
	APC_E_CALL_REJECTED	= 0x80040529L,
	APC_E_BUSY	= 0x8004052aL,
	APC_E_CALLFAILED	= 0x8004052bL,
	APC_E_EXCEPTION	= 0x8004052cL,
	APC_E_NOCOLLECTION	= 0x8004052dL,
	APC_E_CANT_CREATE_PROJECTITEMS_COLLECTION	= 0x8004052eL,
	APC_E_CANT_CREATE_APC_DATA_STREAM	= 0x8004052fL,
	APC_E_CANT_CREATE_PROJITEM_DATA_STREAM	= 0x80040530L,
	APC_E_CANT_CREATE_VBA_STREAM	= 0x80040531L,
	APC_E_COULDNOTACCESSSTREAM	= 0x80040532L,
	APC_E_DISKERROR	= 0x80040533L,
	APC_E_INVALIDSEEKPOS	= 0x80040534L,
	APC_E_REVERTED	= 0x80040535L,
	APC_E_UNKNOWNPROPERTYNAME	= 0x80040536L,
	APC_E_HOSTCONTROLALREADYSET	= 0x80040537L,
	APC_E_EXTENDERALREADYSET	= 0x80040538L,
	APC_E_NOTATTACHED	= 0x80040539L,
	APC_E_INVALIDFILEFILTER	= 0x8004053aL,
	APC_E_SHAREVIOLATION	= 0x8004053bL,
	APC_E_NOTCURRENT	= 0x8004053cL,
	APC_E_UNDEFINEDPROC	= 0x8004053dL,
	APC_E_INVALIDPROCNAME	= 0x8004053eL,
	APC_E_CANTEXITDESIGNMODE	= 0x8004053fL,
	APC_E_HOSTPROJITEM_NOEVENT	= 0x80040540L,
	APC_E_CONTROL_NOEVENT	= 0x80040541L,
	APC_E_EXTENDER_NOEVENT	= 0x80040542L,
	APC_E_PROJ_STG_ALREADYINITIALIZED	= 0x80040543L,
	APC_E_MODNAMECONFLICT	= 0x80040544L,
	APC_E_INVALID_IDENT_STRING	= 0x80040545L,
	APC_E_HOSTCONTROLNOTSET	= 0x80040546L,
	APC_E_EXTENDERNOTSET	= 0x80040547L,
	APC_E_CANT_CREATE_TEMP_DIR	= 0x80040548L,
	APC_E_OBJECTNOTSET	= 0x80040549L,
	APC_E_CORRUPTSTORAGE	= 0x8004054aL,
	APC_E_COULD_NOT_REMOVE_OBJ	= 0x8004054bL,
	APC_E_COULD_NOT_ADD_OBJ	= 0x8004054cL,
	APC_E_COULD_NOT_CREATE_CODEMODULE	= 0x8004054dL,
	APC_E_COULD_NOT_CREATE_CLASSMODULE	= 0x8004054eL,
	APC_E_CANT_CREATE_PROJITEM	= 0x8004054fL,
	APC_E_CANT_ACCESS_TYPELIB	= 0x80040550L,
	APC_E_NO_VBA_PROJECT	= 0x80040551L,
	APC_E_COMPILEERROR	= 0x80040552L,
	APC_E_TOO_MANY_HOSTS	= 0x80040553L,
	APC_E_PROJECT_ITEM_COUNT_MISMATCH	= 0x80040554L,
	APC_E_PROJECT_ITEM_MISMATCH	= 0x80040555L,
	APC_E_INVALID_PROJECT_ITEM	= 0x80040556L,
	APC_E_CANT_READ_APC_DATA	= 0x80040557L,
	APC_E_INCORRECT_VERSION	= 0x80040558L,
	APC_E_INVALID_PICTURE	= 0x80040559L,
	APC_E_EXCEEDED_HOST_COUNT	= 0x8004055aL,
	APC_E_BAD_VBA_INSTALLATION	= 0x8004055bL,
	APC_E_EXPIRED	= 0x8004055cL,
	APC_E_INCORRECT_VBA_VERSION	= 0x8004055dL,
	APC_E_CLASS_NOT_FOUND	= 0x8004055eL,
	APC_E_CANT_FIRE_EVENT	= 0x8004055fL,
	APC_E_PROJECT_ALREADY_EXISTS	= 0x80040560L,
	APC_E_USER_INTERRUPT	= 0x80040561L,
	APC_E_INVALID_APP_OBJ	= 0x80040562L,
	APC_E_STORAGE_NOPERMISSION	= 0x80040563L,
	APC_E_MINIBITMAP_CANT_BE_CHANGED	= 0x80040564L,
	APC_E_CANTSAVE	= 0x80040565L,
	APC_E_APP_OBJECT_REQUIRED	= 0x80040566L,
	APC_E_NO_COMP_MANAGER	= 0x80040567L,
	APC_E_NOT_A_FORM	= 0x80040568L,
	APC_E_NO_UI	= 0x80040569L,
	APC_E_STILL_LOADING_CONTROLS	= 0x8004056aL,
	APC_E_MACRO_NAME_CONFLICT	= 0x8004056bL,
	APC_E_BROKEN_REFERENCE	= 0x8004056cL,
	APC_E_FILENOTFOUND	= 0x8004056dL,
	APC_E_NO_VBA_PROJECTITEM	= 0x8004056eL,
	APC_E_CONTROLNOTREGISTERED	= 0x8004056fL,
	APC_E_BADLICENSEDCONTROL	= 0x80040570L,
	APC_E_CANTREGISTERCONTROL	= 0x80040571L,
	APC_E_CANTREADREGISTRY	= 0x80040572L,
	APC_E_NOAGGREGATION	= 0x80040573L,
	APC_E_INVALIDCLASSID	= 0x80040574L,
	APC_E_EXTCLASSNOTREGISTERED	= 0x80040575L,
	APC_E_STREAM_OR_STORAGE_ALREADYEXISTS	= 0x80040576L,
	APC_E_NOTIMPLEMENTED	= 0x80040577L,
	APC_E_PROJECT_IS_PROTECTED	= 0x80040578L,
	APC_E_NOT_IN_DESIGN_MODE	= 0x80040579L,
	APC_E_MACROS_ARE_DISABLED	= 0x8004057aL,
	APC_E_NO_CONTROL_TYPELIBRARY_GUID	= 0x8004057bL,
	APC_E_USERFORM_NOT_SUPPORTED	= 0x8004057cL,
	APC_E_DUPLICATE_DOCUMENT_OBJECT_SPECIFIED	= 0x8004057dL,
	APC_E_INVALID_PROPERTY_TYPE	= 0x8004057eL,
	APC_E_INVALIDVARIANT_OR_INVALIDSEEKPOS	= 0x8004057fL,
	APC_E_HOSTOBJECT_REQUIRED	= 0x80040580L,
	APC_E_INVALID_HOSTOBJECT	= 0x80040581L,
	APC_E_HOST_ALREADYINITIALIZED	= 0x80040582L,
	APC_E_EVENTSINK_ALREADYINITIALIZED	= 0x80040583L,
	APC_E_EVENTSINK_INVALID	= 0x80040584L,
	APC_E_EVENTSINK_INVALIDCOOKIE	= 0x80040585L,
	APC_E_VBAMACROENABLE_DONTOPEN	= 0x80040586L,
	APC_E_CONTROL_LIBRARY_ALREADY_MADE	= 0x80040587L,
	APC_E_FAILED_VBASIGNPROJECT	= 0x80040588L,
	APC_E_INVALID_USERPASSWORD	= 0x80040589L,
	APC_E_ONLYDOCCLASSES	= 0x8004058aL,
	APC_E_HOSTADDINS_ALREADYINITIALIZED	= 0x8004058bL,
	APC_E_HOSTADDINSINIT_NOREGISTRYPATH	= 0x8004058cL,
	APC_E_HOSTADDINSINIT_NOLICENSEKEY	= 0x8004058dL,
	APC_E_HOSTADDINSINIT_NOHOSTOBJECT	= 0x8004058eL,
	APC_E_HOSTADDINSINIT_NOAPCOBJECT	= 0x8004058fL,
	APC_E_HOSTADDINSPUT_INVALID_REGISTRYPATH	= 0x80040590L,
	APC_E_BACKCOLOR_CANT_BE_CHANGED	= 0x80040591L,
	APC_E_CONTROL_MARKED_FOR_DELETE	= 0x80040592L,
	APC_E_HOSTADDINSINIT_FAILED	= 0x80040593L,
	APC_E_SHOWADDINSDIALOG_FAILED	= 0x80040594L,
	APC_E_NOTRECORDING	= 0x80040595L,
	APC_E_ROUNDTRIP_STREAM_NOT_FOUND	= 0x80040596L,
	APC_E_ROUNDTRIP_STORAGE_NOT_FOUND	= 0x80040597L,
	APC_E_ROUNDTRIP_STORAGE_NOT_INITIALIZED	= 0x80040598L,
	APC_E_INVALID_LICENSE_KEY	= 0x80040599L,
	APC_E_CANT_RUN_IN_BREAK_MODE	= 0x8004059aL,
	APC_E_DIGITAL_SIGNING_DISABLED	= 0x8004059bL,
	APC_E_ACTIONCANCELLED	= 0x8004059cL,
	APC_E_COLLECTION_ADD_DUPLICATEKEY	= 0x8004059dL,
	APC_E_COLLECTION_ITEMS_NOT_IDISPATCH	= 0x8004059eL,
	APC_S_SIGNFAILED	= 0x4004059fL,
	APC_E_LAST_ERROR	= 0x800405a0L
    } ;
typedef /* [uuid] */  DECLSPEC_UUID("E8E67C49-19C0-4E61-AD83-FD7AF9FA25D4") 
enum AxProcKind
    {	axProcKindProc	= 0,
	axProcKindLet	= 1,
	axProcKindSet	= 2,
	axProcKindGet	= 3
    } 	AxProcKind;

typedef enum AxProcKind APCPROCKIND;

typedef /* [uuid] */  DECLSPEC_UUID("588607BE-DB83-43E0-8839-AD55557A237D") 
enum AxSecurityLevel
    {	axSecurityNone	= 1,
	axSecurityMedium	= 2,
	axSecurityHigh	= 3,
	axSecurityVeryHigh	= 4
    } 	AxSecurityLevel;

typedef enum AxSecurityLevel APCSECURITYLEVEL;

typedef /* [uuid] */  DECLSPEC_UUID("0E7F6B1F-928A-44F1-8405-AA9334B0E790") 
enum AxHelpStyle
    {	axHelpHTML	= 0,
	axHelpWindows	= 1
    } 	AxHelpStyle;

typedef enum AxHelpStyle APCHELPSTYLE;





































EXTERN_C const IID LIBID_MSAPC;

#ifndef __IApcX_INTERFACE_DEFINED__
#define __IApcX_INTERFACE_DEFINED__

/* interface IApcX */
/* [local][restricted][uuid] */ 


EXTERN_C const IID IID_IApcX;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BFFC514-7FC3-4A88-99A7-E2D4E1DC7FF5")
    IApcX
    {
    public:
        BEGIN_INTERFACE
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct IApcXVtbl
    {
        BEGIN_INTERFACE
        
        END_INTERFACE
    } IApcXVtbl;

    interface IApcX
    {
        CONST_VTBL struct IApcXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcX_INTERFACE_DEFINED__ */


#ifndef __IApcGlobal_INTERFACE_DEFINED__
#define __IApcGlobal_INTERFACE_DEFINED__

/* interface IApcGlobal */
/* [object][dual][nonextensible][oleautomation][hidden][helpcontext][helpstring][uuid] */ 


EXTERN_C const IID IID_IApcGlobal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D826FE16-2A7C-4227-9BF6-4AD54A8C6C77")
    IApcGlobal : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CreateStorage( 
            /* [optional][in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE OpenStorage( 
            /* [in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [defaultvalue][in] */ VARIANT_BOOL inMemory,
            /* [retval][out] */ IApcStorage **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CreateStorageInMemory( 
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE OpenStorageInMemory( 
            /* [in] */ VARIANT byteArray,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppIApcStorage) = 0;
        
        virtual /* [helpcontext][helpstring][hidden] */ HRESULT STDMETHODCALLTYPE WrapStorage( 
            /* [in] */ IUnknown *pSource,
            /* [retval][out] */ IApcStorage **ppDest) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcGlobalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcGlobal * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcGlobal * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcGlobal * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcGlobal * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcGlobal * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcGlobal * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcGlobal * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateStorage )( 
            IApcGlobal * This,
            /* [optional][in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenStorage )( 
            IApcGlobal * This,
            /* [in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [defaultvalue][in] */ VARIANT_BOOL inMemory,
            /* [retval][out] */ IApcStorage **ppStorage);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateStorageInMemory )( 
            IApcGlobal * This,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenStorageInMemory )( 
            IApcGlobal * This,
            /* [in] */ VARIANT byteArray,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppIApcStorage);
        
        /* [helpcontext][helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *WrapStorage )( 
            IApcGlobal * This,
            /* [in] */ IUnknown *pSource,
            /* [retval][out] */ IApcStorage **ppDest);
        
        END_INTERFACE
    } IApcGlobalVtbl;

    interface IApcGlobal
    {
        CONST_VTBL struct IApcGlobalVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcGlobal_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcGlobal_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcGlobal_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcGlobal_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcGlobal_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcGlobal_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcGlobal_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcGlobal_CreateStorage(This,Name,AccessMode,ppStorage)	\
    ( (This)->lpVtbl -> CreateStorage(This,Name,AccessMode,ppStorage) ) 

#define IApcGlobal_OpenStorage(This,Name,AccessMode,inMemory,ppStorage)	\
    ( (This)->lpVtbl -> OpenStorage(This,Name,AccessMode,inMemory,ppStorage) ) 

#define IApcGlobal_CreateStorageInMemory(This,AccessMode,ppStorage)	\
    ( (This)->lpVtbl -> CreateStorageInMemory(This,AccessMode,ppStorage) ) 

#define IApcGlobal_OpenStorageInMemory(This,byteArray,AccessMode,ppIApcStorage)	\
    ( (This)->lpVtbl -> OpenStorageInMemory(This,byteArray,AccessMode,ppIApcStorage) ) 

#define IApcGlobal_WrapStorage(This,pSource,ppDest)	\
    ( (This)->lpVtbl -> WrapStorage(This,pSource,ppDest) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcGlobal_INTERFACE_DEFINED__ */


#ifndef __IApc_INTERFACE_DEFINED__
#define __IApc_INTERFACE_DEFINED__

/* interface IApc */
/* [object][dual][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F7268EE-64F4-4089-ADFA-232E3585094A")
    IApc : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Projects( 
            /* [retval][out] */ IApcProjects **ppProjects) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VBE( 
            /* [retval][out] */ /* external definition not present */ VBE **ppVBE) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PropertiesWindow( 
            /* [retval][out] */ IApcPropertiesWindow **ppPropertiesWindow) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Picture( 
            /* [in] */ /* external definition not present */ IPictureDisp *pPicture) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ /* external definition not present */ IPictureDisp **ppPicture) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MiniBitmaps( 
            /* [retval][out] */ IApcMiniBitmaps **ppMiniBitmaps) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_TypeLibraryGuid( 
            /* [retval][out] */ BSTR *pbstrTypeLibGuid) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_TypeLibraryChecksum( 
            /* [retval][out] */ long *pChecksum) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_TypeLibraryChecksum( 
            /* [in] */ long Checksum) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RunningInVB( 
            /* [retval][out] */ VARIANT_BOOL *pbRunningInVB) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Paused( 
            /* [retval][out] */ VARIANT_BOOL *pbPaused) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Running( 
            /* [retval][out] */ VARIANT_BOOL *pbRunning) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ExecutingProject( 
            /* [retval][out] */ IApcProject **ppProject) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_StepMode( 
            /* [in] */ APCSTEPMODE NewStepMode) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StepMode( 
            /* [retval][out] */ APCSTEPMODE *pStepMode) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_hWnd( 
            /* [in] */ long NewWindow) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hWnd( 
            /* [retval][out] */ long *phWnd) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_ControlLibraryGuid( 
            /* [in] */ BSTR Guid) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_ControlLibraryGuid( 
            /* [retval][out] */ BSTR *pbstrGuid) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LicenseKey( 
            /* [in] */ BSTR bstrKey) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LicenseKey( 
            /* [retval][out] */ BSTR *pbstrKey) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HostName( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostName( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_RegistryKey( 
            /* [in] */ BSTR bstrKey) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RegistryKey( 
            /* [retval][out] */ BSTR *pbstrKey) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_FileFilter( 
            /* [in] */ BSTR bstrFilter) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FileFilter( 
            /* [retval][out] */ BSTR *pbstrFilter) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Locale( 
            /* [in] */ long lcid) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Locale( 
            /* [retval][out] */ long *plcid) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pBackColor) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR BackColor) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ApplicationObject( 
            /* [retval][out] */ IDispatch **ppApplicationObject) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ApplicationObject( 
            /* [in] */ IDispatch *pApplicationObject) = 0;
        
        virtual /* [helpcontext][helpstring][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_MessageLoopSite( 
            /* [retval][out] */ IUnknown **ppSite) = 0;
        
        virtual /* [helpcontext][helpstring][restricted][propput] */ HRESULT STDMETHODCALLTYPE put_MessageLoopSite( 
            /* [in] */ IUnknown *pSite) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VBAVersion( 
            /* [retval][out] */ BSTR *pbstrVersion) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_APCVersion( 
            /* [retval][out] */ BSTR *pbstrVersion) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Debug( 
            /* [retval][out] */ VARIANT_BOOL *pbDebug) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Recorder( 
            /* [retval][out] */ IApcRecorder **ppRecorder) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Ide( 
            /* [retval][out] */ IApcIde **ppIde) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EnableDigitalSignatures( 
            /* [retval][out] */ VARIANT_BOOL *pbEnabled) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_EnableDigitalSignatures( 
            /* [in] */ VARIANT_BOOL Enable) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SecurityLevel( 
            /* [retval][out] */ APCSECURITYLEVEL *pSecurityLevel) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SecurityLevel( 
            /* [in] */ APCSECURITYLEVEL NewSecurityLevel) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SupportVbaDesigners( 
            /* [retval][out] */ VARIANT_BOOL *pbSupported) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SupportVbaDesigners( 
            /* [in] */ VARIANT_BOOL Supported) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ExecutingHostClassInstance( 
            /* [retval][out] */ IDispatch **ppInstance) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HelpStyle( 
            /* [retval][out] */ APCHELPSTYLE *pStyle) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HelpStyle( 
            /* [in] */ APCHELPSTYLE Style) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MoreInfoHelpFile( 
            /* [retval][out] */ BSTR *pbstrHelpFile) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MoreInfoHelpFile( 
            /* [in] */ BSTR bstrHelpFile) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MoreInfoContextID( 
            /* [retval][out] */ long *pContextID) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MoreInfoContextID( 
            /* [in] */ long ContextID) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Format( 
            /* [in] */ VARIANT Expression,
            /* [optional][in] */ BSTR Format,
            /* [defaultvalue][in] */ short firstdayofweek,
            /* [defaultvalue][in] */ short firstweekofyear,
            /* [retval][out] */ BSTR *pbstrFormattedText) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE BeginModalDialog( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE EndModalDialog( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Break( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE End( 
            /* [retval][out] */ VARIANT_BOOL *pbFinished) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE RegisterExtenderClass( 
            BSTR ClassName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ShowError( 
            /* [defaultvalue][in] */ long Error = 0) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CreateScopes( 
            /* [defaultvalue][in] */ VARIANT_BOOL AutoFill,
            /* [retval][out] */ IApcScopes **ppScopes) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AdviseApcEvents( 
            /* [in] */ IApcEvents *EventSink,
            /* [retval][out] */ long *pCookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE UnadviseApcEvents( 
            /* [in] */ long Cookie) = 0;
        
        virtual /* [helpcontext][helpstring][hidden] */ HRESULT STDMETHODCALLTYPE AdviseLegacyEvents( 
            /* [in] */ IApcLegacyEvents *LegacyEvents,
            /* [retval][out] */ long *pCookie) = 0;
        
        virtual /* [helpcontext][helpstring][hidden] */ HRESULT STDMETHODCALLTYPE UnadviseLegacyEvents( 
            /* [in] */ long Cookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ShowSecurityLevelDialog( 
            /* [retval][out] */ APCSECURITYLEVEL *SecurityLevel) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SupportDesigner( 
            /* [in] */ BSTR ClsidDesigner,
            /* [in] */ VARIANT_BOOL Supported) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CanTerminate( 
            /* [retval][out] */ VARIANT_BOOL *CanTerminate) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE PreTerminate( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AddMTProjectType( 
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RegistryPath,
            /* [in] */ BSTR HostObjectName,
            /* [in] */ BSTR HostApplicationName,
            /* [defaultvalue][in] */ long MajorVersion = 0,
            /* [defaultvalue][in] */ long MinorVersion = 0,
            /* [defaultvalue][in] */ VARIANT_BOOL AllowCommandLineExecution = 0) = 0;
        
        virtual /* [helpcontext][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_ApplicationObject( 
            /* [in] */ IDispatch *pApplicationObject) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ContinueOnError( 
            /* [retval][out] */ VARIANT_BOOL *pbContinue) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ContinueOnError( 
            /* [in] */ VARIANT_BOOL Continue) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ExtendedLibraryPath( 
            /* [retval][out] */ BSTR *pbstrPathName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ExtendedLibraryPath( 
            /* [in] */ BSTR PathName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HostUsingWideMessageLoops( 
            /* [in] */ BOOL bUsingWideMessageLoops) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApc * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Projects )( 
            IApc * This,
            /* [retval][out] */ IApcProjects **ppProjects);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VBE )( 
            IApc * This,
            /* [retval][out] */ /* external definition not present */ VBE **ppVBE);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropertiesWindow )( 
            IApc * This,
            /* [retval][out] */ IApcPropertiesWindow **ppPropertiesWindow);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Picture )( 
            IApc * This,
            /* [in] */ /* external definition not present */ IPictureDisp *pPicture);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Picture )( 
            IApc * This,
            /* [retval][out] */ /* external definition not present */ IPictureDisp **ppPicture);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MiniBitmaps )( 
            IApc * This,
            /* [retval][out] */ IApcMiniBitmaps **ppMiniBitmaps);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApc * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApc * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TypeLibraryGuid )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrTypeLibGuid);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TypeLibraryChecksum )( 
            IApc * This,
            /* [retval][out] */ long *pChecksum);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TypeLibraryChecksum )( 
            IApc * This,
            /* [in] */ long Checksum);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RunningInVB )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbRunningInVB);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Paused )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbPaused);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Running )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbRunning);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExecutingProject )( 
            IApc * This,
            /* [retval][out] */ IApcProject **ppProject);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StepMode )( 
            IApc * This,
            /* [in] */ APCSTEPMODE NewStepMode);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StepMode )( 
            IApc * This,
            /* [retval][out] */ APCSTEPMODE *pStepMode);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_hWnd )( 
            IApc * This,
            /* [in] */ long NewWindow);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_hWnd )( 
            IApc * This,
            /* [retval][out] */ long *phWnd);
        
        /* [helpcontext][helpstring][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ControlLibraryGuid )( 
            IApc * This,
            /* [in] */ BSTR Guid);
        
        /* [helpcontext][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlLibraryGuid )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrGuid);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LicenseKey )( 
            IApc * This,
            /* [in] */ BSTR bstrKey);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LicenseKey )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrKey);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostName )( 
            IApc * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostName )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegistryKey )( 
            IApc * This,
            /* [in] */ BSTR bstrKey);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegistryKey )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrKey);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileFilter )( 
            IApc * This,
            /* [in] */ BSTR bstrFilter);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileFilter )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrFilter);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Locale )( 
            IApc * This,
            /* [in] */ long lcid);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Locale )( 
            IApc * This,
            /* [retval][out] */ long *plcid);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IApc * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pBackColor);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IApc * This,
            /* [in] */ /* external definition not present */ OLE_COLOR BackColor);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ApplicationObject )( 
            IApc * This,
            /* [retval][out] */ IDispatch **ppApplicationObject);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ApplicationObject )( 
            IApc * This,
            /* [in] */ IDispatch *pApplicationObject);
        
        /* [helpcontext][helpstring][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MessageLoopSite )( 
            IApc * This,
            /* [retval][out] */ IUnknown **ppSite);
        
        /* [helpcontext][helpstring][restricted][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MessageLoopSite )( 
            IApc * This,
            /* [in] */ IUnknown *pSite);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VBAVersion )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrVersion);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_APCVersion )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrVersion);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Debug )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbDebug);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Recorder )( 
            IApc * This,
            /* [retval][out] */ IApcRecorder **ppRecorder);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Ide )( 
            IApc * This,
            /* [retval][out] */ IApcIde **ppIde);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableDigitalSignatures )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnabled);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableDigitalSignatures )( 
            IApc * This,
            /* [in] */ VARIANT_BOOL Enable);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SecurityLevel )( 
            IApc * This,
            /* [retval][out] */ APCSECURITYLEVEL *pSecurityLevel);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SecurityLevel )( 
            IApc * This,
            /* [in] */ APCSECURITYLEVEL NewSecurityLevel);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportVbaDesigners )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbSupported);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SupportVbaDesigners )( 
            IApc * This,
            /* [in] */ VARIANT_BOOL Supported);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExecutingHostClassInstance )( 
            IApc * This,
            /* [retval][out] */ IDispatch **ppInstance);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpStyle )( 
            IApc * This,
            /* [retval][out] */ APCHELPSTYLE *pStyle);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HelpStyle )( 
            IApc * This,
            /* [in] */ APCHELPSTYLE Style);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MoreInfoHelpFile )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrHelpFile);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MoreInfoHelpFile )( 
            IApc * This,
            /* [in] */ BSTR bstrHelpFile);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MoreInfoContextID )( 
            IApc * This,
            /* [retval][out] */ long *pContextID);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MoreInfoContextID )( 
            IApc * This,
            /* [in] */ long ContextID);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Format )( 
            IApc * This,
            /* [in] */ VARIANT Expression,
            /* [optional][in] */ BSTR Format,
            /* [defaultvalue][in] */ short firstdayofweek,
            /* [defaultvalue][in] */ short firstweekofyear,
            /* [retval][out] */ BSTR *pbstrFormattedText);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginModalDialog )( 
            IApc * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *EndModalDialog )( 
            IApc * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Break )( 
            IApc * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *End )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbFinished);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterExtenderClass )( 
            IApc * This,
            BSTR ClassName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ShowError )( 
            IApc * This,
            /* [defaultvalue][in] */ long Error);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateScopes )( 
            IApc * This,
            /* [defaultvalue][in] */ VARIANT_BOOL AutoFill,
            /* [retval][out] */ IApcScopes **ppScopes);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdviseApcEvents )( 
            IApc * This,
            /* [in] */ IApcEvents *EventSink,
            /* [retval][out] */ long *pCookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnadviseApcEvents )( 
            IApc * This,
            /* [in] */ long Cookie);
        
        /* [helpcontext][helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *AdviseLegacyEvents )( 
            IApc * This,
            /* [in] */ IApcLegacyEvents *LegacyEvents,
            /* [retval][out] */ long *pCookie);
        
        /* [helpcontext][helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *UnadviseLegacyEvents )( 
            IApc * This,
            /* [in] */ long Cookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ShowSecurityLevelDialog )( 
            IApc * This,
            /* [retval][out] */ APCSECURITYLEVEL *SecurityLevel);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SupportDesigner )( 
            IApc * This,
            /* [in] */ BSTR ClsidDesigner,
            /* [in] */ VARIANT_BOOL Supported);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CanTerminate )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *CanTerminate);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreTerminate )( 
            IApc * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddMTProjectType )( 
            IApc * This,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR RegistryPath,
            /* [in] */ BSTR HostObjectName,
            /* [in] */ BSTR HostApplicationName,
            /* [defaultvalue][in] */ long MajorVersion,
            /* [defaultvalue][in] */ long MinorVersion,
            /* [defaultvalue][in] */ VARIANT_BOOL AllowCommandLineExecution);
        
        /* [helpcontext][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_ApplicationObject )( 
            IApc * This,
            /* [in] */ IDispatch *pApplicationObject);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContinueOnError )( 
            IApc * This,
            /* [retval][out] */ VARIANT_BOOL *pbContinue);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ContinueOnError )( 
            IApc * This,
            /* [in] */ VARIANT_BOOL Continue);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExtendedLibraryPath )( 
            IApc * This,
            /* [retval][out] */ BSTR *pbstrPathName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExtendedLibraryPath )( 
            IApc * This,
            /* [in] */ BSTR PathName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostUsingWideMessageLoops )( 
            IApc * This,
            /* [in] */ BOOL bUsingWideMessageLoops);
        
        END_INTERFACE
    } IApcVtbl;

    interface IApc
    {
        CONST_VTBL struct IApcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApc_get_Projects(This,ppProjects)	\
    ( (This)->lpVtbl -> get_Projects(This,ppProjects) ) 

#define IApc_get_VBE(This,ppVBE)	\
    ( (This)->lpVtbl -> get_VBE(This,ppVBE) ) 

#define IApc_get_PropertiesWindow(This,ppPropertiesWindow)	\
    ( (This)->lpVtbl -> get_PropertiesWindow(This,ppPropertiesWindow) ) 

#define IApc_put_Picture(This,pPicture)	\
    ( (This)->lpVtbl -> put_Picture(This,pPicture) ) 

#define IApc_get_Picture(This,ppPicture)	\
    ( (This)->lpVtbl -> get_Picture(This,ppPicture) ) 

#define IApc_get_MiniBitmaps(This,ppMiniBitmaps)	\
    ( (This)->lpVtbl -> get_MiniBitmaps(This,ppMiniBitmaps) ) 

#define IApc_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApc_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApc_get_TypeLibraryGuid(This,pbstrTypeLibGuid)	\
    ( (This)->lpVtbl -> get_TypeLibraryGuid(This,pbstrTypeLibGuid) ) 

#define IApc_get_TypeLibraryChecksum(This,pChecksum)	\
    ( (This)->lpVtbl -> get_TypeLibraryChecksum(This,pChecksum) ) 

#define IApc_put_TypeLibraryChecksum(This,Checksum)	\
    ( (This)->lpVtbl -> put_TypeLibraryChecksum(This,Checksum) ) 

#define IApc_get_RunningInVB(This,pbRunningInVB)	\
    ( (This)->lpVtbl -> get_RunningInVB(This,pbRunningInVB) ) 

#define IApc_get_Paused(This,pbPaused)	\
    ( (This)->lpVtbl -> get_Paused(This,pbPaused) ) 

#define IApc_get_Running(This,pbRunning)	\
    ( (This)->lpVtbl -> get_Running(This,pbRunning) ) 

#define IApc_get_ExecutingProject(This,ppProject)	\
    ( (This)->lpVtbl -> get_ExecutingProject(This,ppProject) ) 

#define IApc_put_StepMode(This,NewStepMode)	\
    ( (This)->lpVtbl -> put_StepMode(This,NewStepMode) ) 

#define IApc_get_StepMode(This,pStepMode)	\
    ( (This)->lpVtbl -> get_StepMode(This,pStepMode) ) 

#define IApc_put_hWnd(This,NewWindow)	\
    ( (This)->lpVtbl -> put_hWnd(This,NewWindow) ) 

#define IApc_get_hWnd(This,phWnd)	\
    ( (This)->lpVtbl -> get_hWnd(This,phWnd) ) 

#define IApc_put_ControlLibraryGuid(This,Guid)	\
    ( (This)->lpVtbl -> put_ControlLibraryGuid(This,Guid) ) 

#define IApc_get_ControlLibraryGuid(This,pbstrGuid)	\
    ( (This)->lpVtbl -> get_ControlLibraryGuid(This,pbstrGuid) ) 

#define IApc_put_LicenseKey(This,bstrKey)	\
    ( (This)->lpVtbl -> put_LicenseKey(This,bstrKey) ) 

#define IApc_get_LicenseKey(This,pbstrKey)	\
    ( (This)->lpVtbl -> get_LicenseKey(This,pbstrKey) ) 

#define IApc_put_HostName(This,bstrName)	\
    ( (This)->lpVtbl -> put_HostName(This,bstrName) ) 

#define IApc_get_HostName(This,pbstrName)	\
    ( (This)->lpVtbl -> get_HostName(This,pbstrName) ) 

#define IApc_put_RegistryKey(This,bstrKey)	\
    ( (This)->lpVtbl -> put_RegistryKey(This,bstrKey) ) 

#define IApc_get_RegistryKey(This,pbstrKey)	\
    ( (This)->lpVtbl -> get_RegistryKey(This,pbstrKey) ) 

#define IApc_put_FileFilter(This,bstrFilter)	\
    ( (This)->lpVtbl -> put_FileFilter(This,bstrFilter) ) 

#define IApc_get_FileFilter(This,pbstrFilter)	\
    ( (This)->lpVtbl -> get_FileFilter(This,pbstrFilter) ) 

#define IApc_put_Locale(This,lcid)	\
    ( (This)->lpVtbl -> put_Locale(This,lcid) ) 

#define IApc_get_Locale(This,plcid)	\
    ( (This)->lpVtbl -> get_Locale(This,plcid) ) 

#define IApc_get_BackColor(This,pBackColor)	\
    ( (This)->lpVtbl -> get_BackColor(This,pBackColor) ) 

#define IApc_put_BackColor(This,BackColor)	\
    ( (This)->lpVtbl -> put_BackColor(This,BackColor) ) 

#define IApc_get_ApplicationObject(This,ppApplicationObject)	\
    ( (This)->lpVtbl -> get_ApplicationObject(This,ppApplicationObject) ) 

#define IApc_put_ApplicationObject(This,pApplicationObject)	\
    ( (This)->lpVtbl -> put_ApplicationObject(This,pApplicationObject) ) 

#define IApc_get_MessageLoopSite(This,ppSite)	\
    ( (This)->lpVtbl -> get_MessageLoopSite(This,ppSite) ) 

#define IApc_put_MessageLoopSite(This,pSite)	\
    ( (This)->lpVtbl -> put_MessageLoopSite(This,pSite) ) 

#define IApc_get_VBAVersion(This,pbstrVersion)	\
    ( (This)->lpVtbl -> get_VBAVersion(This,pbstrVersion) ) 

#define IApc_get_APCVersion(This,pbstrVersion)	\
    ( (This)->lpVtbl -> get_APCVersion(This,pbstrVersion) ) 

#define IApc_get_Debug(This,pbDebug)	\
    ( (This)->lpVtbl -> get_Debug(This,pbDebug) ) 

#define IApc_get_Recorder(This,ppRecorder)	\
    ( (This)->lpVtbl -> get_Recorder(This,ppRecorder) ) 

#define IApc_get_Ide(This,ppIde)	\
    ( (This)->lpVtbl -> get_Ide(This,ppIde) ) 

#define IApc_get_EnableDigitalSignatures(This,pbEnabled)	\
    ( (This)->lpVtbl -> get_EnableDigitalSignatures(This,pbEnabled) ) 

#define IApc_put_EnableDigitalSignatures(This,Enable)	\
    ( (This)->lpVtbl -> put_EnableDigitalSignatures(This,Enable) ) 

#define IApc_get_SecurityLevel(This,pSecurityLevel)	\
    ( (This)->lpVtbl -> get_SecurityLevel(This,pSecurityLevel) ) 

#define IApc_put_SecurityLevel(This,NewSecurityLevel)	\
    ( (This)->lpVtbl -> put_SecurityLevel(This,NewSecurityLevel) ) 

#define IApc_get_SupportVbaDesigners(This,pbSupported)	\
    ( (This)->lpVtbl -> get_SupportVbaDesigners(This,pbSupported) ) 

#define IApc_put_SupportVbaDesigners(This,Supported)	\
    ( (This)->lpVtbl -> put_SupportVbaDesigners(This,Supported) ) 

#define IApc_get_ExecutingHostClassInstance(This,ppInstance)	\
    ( (This)->lpVtbl -> get_ExecutingHostClassInstance(This,ppInstance) ) 

#define IApc_get_HelpStyle(This,pStyle)	\
    ( (This)->lpVtbl -> get_HelpStyle(This,pStyle) ) 

#define IApc_put_HelpStyle(This,Style)	\
    ( (This)->lpVtbl -> put_HelpStyle(This,Style) ) 

#define IApc_get_MoreInfoHelpFile(This,pbstrHelpFile)	\
    ( (This)->lpVtbl -> get_MoreInfoHelpFile(This,pbstrHelpFile) ) 

#define IApc_put_MoreInfoHelpFile(This,bstrHelpFile)	\
    ( (This)->lpVtbl -> put_MoreInfoHelpFile(This,bstrHelpFile) ) 

#define IApc_get_MoreInfoContextID(This,pContextID)	\
    ( (This)->lpVtbl -> get_MoreInfoContextID(This,pContextID) ) 

#define IApc_put_MoreInfoContextID(This,ContextID)	\
    ( (This)->lpVtbl -> put_MoreInfoContextID(This,ContextID) ) 

#define IApc_Format(This,Expression,Format,firstdayofweek,firstweekofyear,pbstrFormattedText)	\
    ( (This)->lpVtbl -> Format(This,Expression,Format,firstdayofweek,firstweekofyear,pbstrFormattedText) ) 

#define IApc_BeginModalDialog(This)	\
    ( (This)->lpVtbl -> BeginModalDialog(This) ) 

#define IApc_EndModalDialog(This)	\
    ( (This)->lpVtbl -> EndModalDialog(This) ) 

#define IApc_Break(This)	\
    ( (This)->lpVtbl -> Break(This) ) 

#define IApc_End(This,pbFinished)	\
    ( (This)->lpVtbl -> End(This,pbFinished) ) 

#define IApc_RegisterExtenderClass(This,ClassName)	\
    ( (This)->lpVtbl -> RegisterExtenderClass(This,ClassName) ) 

#define IApc_ShowError(This,Error)	\
    ( (This)->lpVtbl -> ShowError(This,Error) ) 

#define IApc_CreateScopes(This,AutoFill,ppScopes)	\
    ( (This)->lpVtbl -> CreateScopes(This,AutoFill,ppScopes) ) 

#define IApc_AdviseApcEvents(This,EventSink,pCookie)	\
    ( (This)->lpVtbl -> AdviseApcEvents(This,EventSink,pCookie) ) 

#define IApc_UnadviseApcEvents(This,Cookie)	\
    ( (This)->lpVtbl -> UnadviseApcEvents(This,Cookie) ) 

#define IApc_AdviseLegacyEvents(This,LegacyEvents,pCookie)	\
    ( (This)->lpVtbl -> AdviseLegacyEvents(This,LegacyEvents,pCookie) ) 

#define IApc_UnadviseLegacyEvents(This,Cookie)	\
    ( (This)->lpVtbl -> UnadviseLegacyEvents(This,Cookie) ) 

#define IApc_ShowSecurityLevelDialog(This,SecurityLevel)	\
    ( (This)->lpVtbl -> ShowSecurityLevelDialog(This,SecurityLevel) ) 

#define IApc_SupportDesigner(This,ClsidDesigner,Supported)	\
    ( (This)->lpVtbl -> SupportDesigner(This,ClsidDesigner,Supported) ) 

#define IApc_CanTerminate(This,CanTerminate)	\
    ( (This)->lpVtbl -> CanTerminate(This,CanTerminate) ) 

#define IApc_PreTerminate(This)	\
    ( (This)->lpVtbl -> PreTerminate(This) ) 

#define IApc_AddMTProjectType(This,Name,RegistryPath,HostObjectName,HostApplicationName,MajorVersion,MinorVersion,AllowCommandLineExecution)	\
    ( (This)->lpVtbl -> AddMTProjectType(This,Name,RegistryPath,HostObjectName,HostApplicationName,MajorVersion,MinorVersion,AllowCommandLineExecution) ) 

#define IApc_putref_ApplicationObject(This,pApplicationObject)	\
    ( (This)->lpVtbl -> putref_ApplicationObject(This,pApplicationObject) ) 

#define IApc_get_ContinueOnError(This,pbContinue)	\
    ( (This)->lpVtbl -> get_ContinueOnError(This,pbContinue) ) 

#define IApc_put_ContinueOnError(This,Continue)	\
    ( (This)->lpVtbl -> put_ContinueOnError(This,Continue) ) 

#define IApc_get_ExtendedLibraryPath(This,pbstrPathName)	\
    ( (This)->lpVtbl -> get_ExtendedLibraryPath(This,pbstrPathName) ) 

#define IApc_put_ExtendedLibraryPath(This,PathName)	\
    ( (This)->lpVtbl -> put_ExtendedLibraryPath(This,PathName) ) 

#define IApc_put_HostUsingWideMessageLoops(This,bUsingWideMessageLoops)	\
    ( (This)->lpVtbl -> put_HostUsingWideMessageLoops(This,bUsingWideMessageLoops) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApc_INTERFACE_DEFINED__ */


#ifndef __IApcEvents_INTERFACE_DEFINED__
#define __IApcEvents_INTERFACE_DEFINED__

/* interface IApcEvents */
/* [object][hidden][helpcontext][helpstring][uuid] */ 


EXTERN_C const IID IID_IApcEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CAFC21F2-6271-4ACF-AA67-F19B748E56DB")
    IApcEvents : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforeRun( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE AfterRun( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforePause( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE AfterPause( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforeModalDialog( 
            /* [in] */ IApcProject *Project) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE AfterModalDialog( 
            /* [in] */ IApcProject *Project) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( 
            /* [out][in] */ VARIANT_BOOL *Activate) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE NameChange( 
            /* [in] */ IApcProject *Project,
            /* [in] */ BSTR OldName) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenProject( 
            /* [in] */ BSTR ProjectFileName,
            IApcProject *ReferencingProject,
            /* [out][in] */ IApcProject **Project) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowHelp( 
            /* [in] */ BSTR HelpFileName,
            /* [in] */ long Command,
            /* [in] */ long CommandData,
            /* [in] */ VARIANT_BOOL IsWinHelp,
            /* [out][in] */ VARIANT_BOOL *pbShowHelp) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE FindFile( 
            /* [in] */ BSTR FileName,
            /* [out][in] */ BSTR *FullPath) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateMacro( 
            /* [in] */ BSTR ProcedureName,
            /* [in] */ IApcScope *CurrentScope,
            /* [in] */ BSTR Description,
            /* [out][in] */ VARIANT_BOOL *Created) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE HostCheckReference( 
            /* [in] */ VARIANT_BOOL Saving,
            /* [in] */ BSTR LibraryGuid,
            /* [out][in] */ long *MajorVersion,
            /* [out][in] */ long *MinorVersion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeforeRun )( 
            IApcEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AfterRun )( 
            IApcEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeforePause )( 
            IApcEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AfterPause )( 
            IApcEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeforeModalDialog )( 
            IApcEvents * This,
            /* [in] */ IApcProject *Project);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AfterModalDialog )( 
            IApcEvents * This,
            /* [in] */ IApcProject *Project);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IApcEvents * This,
            /* [out][in] */ VARIANT_BOOL *Activate);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NameChange )( 
            IApcEvents * This,
            /* [in] */ IApcProject *Project,
            /* [in] */ BSTR OldName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenProject )( 
            IApcEvents * This,
            /* [in] */ BSTR ProjectFileName,
            IApcProject *ReferencingProject,
            /* [out][in] */ IApcProject **Project);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowHelp )( 
            IApcEvents * This,
            /* [in] */ BSTR HelpFileName,
            /* [in] */ long Command,
            /* [in] */ long CommandData,
            /* [in] */ VARIANT_BOOL IsWinHelp,
            /* [out][in] */ VARIANT_BOOL *pbShowHelp);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindFile )( 
            IApcEvents * This,
            /* [in] */ BSTR FileName,
            /* [out][in] */ BSTR *FullPath);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateMacro )( 
            IApcEvents * This,
            /* [in] */ BSTR ProcedureName,
            /* [in] */ IApcScope *CurrentScope,
            /* [in] */ BSTR Description,
            /* [out][in] */ VARIANT_BOOL *Created);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HostCheckReference )( 
            IApcEvents * This,
            /* [in] */ VARIANT_BOOL Saving,
            /* [in] */ BSTR LibraryGuid,
            /* [out][in] */ long *MajorVersion,
            /* [out][in] */ long *MinorVersion);
        
        END_INTERFACE
    } IApcEventsVtbl;

    interface IApcEvents
    {
        CONST_VTBL struct IApcEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcEvents_BeforeRun(This)	\
    ( (This)->lpVtbl -> BeforeRun(This) ) 

#define IApcEvents_AfterRun(This)	\
    ( (This)->lpVtbl -> AfterRun(This) ) 

#define IApcEvents_BeforePause(This)	\
    ( (This)->lpVtbl -> BeforePause(This) ) 

#define IApcEvents_AfterPause(This)	\
    ( (This)->lpVtbl -> AfterPause(This) ) 

#define IApcEvents_BeforeModalDialog(This,Project)	\
    ( (This)->lpVtbl -> BeforeModalDialog(This,Project) ) 

#define IApcEvents_AfterModalDialog(This,Project)	\
    ( (This)->lpVtbl -> AfterModalDialog(This,Project) ) 

#define IApcEvents_Activate(This,Activate)	\
    ( (This)->lpVtbl -> Activate(This,Activate) ) 

#define IApcEvents_NameChange(This,Project,OldName)	\
    ( (This)->lpVtbl -> NameChange(This,Project,OldName) ) 

#define IApcEvents_OpenProject(This,ProjectFileName,ReferencingProject,Project)	\
    ( (This)->lpVtbl -> OpenProject(This,ProjectFileName,ReferencingProject,Project) ) 

#define IApcEvents_ShowHelp(This,HelpFileName,Command,CommandData,IsWinHelp,pbShowHelp)	\
    ( (This)->lpVtbl -> ShowHelp(This,HelpFileName,Command,CommandData,IsWinHelp,pbShowHelp) ) 

#define IApcEvents_FindFile(This,FileName,FullPath)	\
    ( (This)->lpVtbl -> FindFile(This,FileName,FullPath) ) 

#define IApcEvents_CreateMacro(This,ProcedureName,CurrentScope,Description,Created)	\
    ( (This)->lpVtbl -> CreateMacro(This,ProcedureName,CurrentScope,Description,Created) ) 

#define IApcEvents_HostCheckReference(This,Saving,LibraryGuid,MajorVersion,MinorVersion)	\
    ( (This)->lpVtbl -> HostCheckReference(This,Saving,LibraryGuid,MajorVersion,MinorVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcEvents_INTERFACE_DEFINED__ */


#ifndef __IApcIde_INTERFACE_DEFINED__
#define __IApcIde_INTERFACE_DEFINED__

/* interface IApcIde */
/* [object][hidden][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcIde;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("825DF6FB-D079-4F0F-A441-ECB9714951B1")
    IApcIde : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *pbVisible) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PreventShow( 
            /* [in] */ VARIANT_BOOL PreventShow) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PreventShow( 
            /* [retval][out] */ VARIANT_BOOL *pbPreventShow) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AdviseIdeEvents( 
            /* [in] */ IApcIdeEvents *EventSink,
            /* [retval][out] */ long *pCookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE UnadviseIdeEvents( 
            /* [in] */ long Cookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcIdeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcIde * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcIde * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcIde * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcIde * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcIde * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcIde * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcIde * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IApcIde * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IApcIde * This,
            /* [retval][out] */ VARIANT_BOOL *pbVisible);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PreventShow )( 
            IApcIde * This,
            /* [in] */ VARIANT_BOOL PreventShow);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreventShow )( 
            IApcIde * This,
            /* [retval][out] */ VARIANT_BOOL *pbPreventShow);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcIde * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcIde * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcIde * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcIde * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdviseIdeEvents )( 
            IApcIde * This,
            /* [in] */ IApcIdeEvents *EventSink,
            /* [retval][out] */ long *pCookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnadviseIdeEvents )( 
            IApcIde * This,
            /* [in] */ long Cookie);
        
        END_INTERFACE
    } IApcIdeVtbl;

    interface IApcIde
    {
        CONST_VTBL struct IApcIdeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcIde_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcIde_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcIde_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcIde_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcIde_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcIde_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcIde_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcIde_put_Visible(This,Visible)	\
    ( (This)->lpVtbl -> put_Visible(This,Visible) ) 

#define IApcIde_get_Visible(This,pbVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,pbVisible) ) 

#define IApcIde_put_PreventShow(This,PreventShow)	\
    ( (This)->lpVtbl -> put_PreventShow(This,PreventShow) ) 

#define IApcIde_get_PreventShow(This,pbPreventShow)	\
    ( (This)->lpVtbl -> get_PreventShow(This,pbPreventShow) ) 

#define IApcIde_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcIde_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcIde_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcIde_get_Parent(This,ppApc)	\
    ( (This)->lpVtbl -> get_Parent(This,ppApc) ) 

#define IApcIde_AdviseIdeEvents(This,EventSink,pCookie)	\
    ( (This)->lpVtbl -> AdviseIdeEvents(This,EventSink,pCookie) ) 

#define IApcIde_UnadviseIdeEvents(This,Cookie)	\
    ( (This)->lpVtbl -> UnadviseIdeEvents(This,Cookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcIde_INTERFACE_DEFINED__ */


#ifndef __IApcIdeEvents_INTERFACE_DEFINED__
#define __IApcIdeEvents_INTERFACE_DEFINED__

/* interface IApcIdeEvents */
/* [object][hidden][uuid] */ 


EXTERN_C const IID IID_IApcIdeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1B70B22-7E21-4849-A01B-3FE989BED4C6")
    IApcIdeEvents : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowHide( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ToolbarReset( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcIdeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcIdeEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcIdeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcIdeEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowHide )( 
            IApcIdeEvents * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ToolbarReset )( 
            IApcIdeEvents * This);
        
        END_INTERFACE
    } IApcIdeEventsVtbl;

    interface IApcIdeEvents
    {
        CONST_VTBL struct IApcIdeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcIdeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcIdeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcIdeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcIdeEvents_ShowHide(This,Visible)	\
    ( (This)->lpVtbl -> ShowHide(This,Visible) ) 

#define IApcIdeEvents_ToolbarReset(This)	\
    ( (This)->lpVtbl -> ToolbarReset(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcIdeEvents_INTERFACE_DEFINED__ */


#ifndef __IApcPropertiesWindow_INTERFACE_DEFINED__
#define __IApcPropertiesWindow_INTERFACE_DEFINED__

/* interface IApcPropertiesWindow */
/* [object][hidden][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcPropertiesWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D474E71B-FD49-436D-8C02-8B8654FD75C4")
    IApcPropertiesWindow : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *pbVisible) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcPropertiesWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcPropertiesWindow * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcPropertiesWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcPropertiesWindow * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcPropertiesWindow * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcPropertiesWindow * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcPropertiesWindow * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcPropertiesWindow * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IApcPropertiesWindow * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IApcPropertiesWindow * This,
            /* [retval][out] */ VARIANT_BOOL *pbVisible);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcPropertiesWindow * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcPropertiesWindow * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcPropertiesWindow * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcPropertiesWindow * This,
            /* [retval][out] */ IApc **ppApc);
        
        END_INTERFACE
    } IApcPropertiesWindowVtbl;

    interface IApcPropertiesWindow
    {
        CONST_VTBL struct IApcPropertiesWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcPropertiesWindow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcPropertiesWindow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcPropertiesWindow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcPropertiesWindow_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcPropertiesWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcPropertiesWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcPropertiesWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcPropertiesWindow_put_Visible(This,Visible)	\
    ( (This)->lpVtbl -> put_Visible(This,Visible) ) 

#define IApcPropertiesWindow_get_Visible(This,pbVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,pbVisible) ) 

#define IApcPropertiesWindow_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcPropertiesWindow_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcPropertiesWindow_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcPropertiesWindow_get_Parent(This,ppApc)	\
    ( (This)->lpVtbl -> get_Parent(This,ppApc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcPropertiesWindow_INTERFACE_DEFINED__ */


#ifndef __IApcProjects_INTERFACE_DEFINED__
#define __IApcProjects_INTERFACE_DEFINED__

/* interface IApcProjects */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcProjects;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("076294A3-1ED5-4CCD-A382-C834911303A8")
    IApcProjects : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcProject **ppProject) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VBProjects( 
            /* [retval][out] */ /* external definition not present */ _VBProjects **ppVBProjects) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ APCPROJECTFLAG ProjectFlags,
            /* [optional][in] */ BSTR ProjectName,
            /* [retval][out] */ IApcProject **ppProject) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ APCPROJECTFLAG Flags,
            /* [defaultvalue][in] */ IApcStorage *Storage,
            /* [defaultvalue][in] */ IDispatch *ProjectItemCollection,
            /* [retval][out] */ IApcProject **ppProject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProjectsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProjects * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProjects * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProjects * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcProjects * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcProjects * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcProjects * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcProjects * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcProjects * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcProjects * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcProjects * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcProjects * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcProjects * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcProjects * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcProject **ppProject);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcProjects * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VBProjects )( 
            IApcProjects * This,
            /* [retval][out] */ /* external definition not present */ _VBProjects **ppVBProjects);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcProjects * This,
            /* [in] */ APCPROJECTFLAG ProjectFlags,
            /* [optional][in] */ BSTR ProjectName,
            /* [retval][out] */ IApcProject **ppProject);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IApcProjects * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IApcProjects * This,
            /* [in] */ APCPROJECTFLAG Flags,
            /* [defaultvalue][in] */ IApcStorage *Storage,
            /* [defaultvalue][in] */ IDispatch *ProjectItemCollection,
            /* [retval][out] */ IApcProject **ppProject);
        
        END_INTERFACE
    } IApcProjectsVtbl;

    interface IApcProjects
    {
        CONST_VTBL struct IApcProjectsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProjects_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProjects_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProjects_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProjects_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcProjects_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcProjects_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcProjects_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcProjects_get_Parent(This,ppApc)	\
    ( (This)->lpVtbl -> get_Parent(This,ppApc) ) 

#define IApcProjects_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcProjects_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcProjects_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcProjects_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcProjects_get_Item(This,Index,ppProject)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppProject) ) 

#define IApcProjects_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcProjects_get_VBProjects(This,ppVBProjects)	\
    ( (This)->lpVtbl -> get_VBProjects(This,ppVBProjects) ) 

#define IApcProjects_Add(This,ProjectFlags,ProjectName,ppProject)	\
    ( (This)->lpVtbl -> Add(This,ProjectFlags,ProjectName,ppProject) ) 

#define IApcProjects_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IApcProjects_Open(This,Flags,Storage,ProjectItemCollection,ppProject)	\
    ( (This)->lpVtbl -> Open(This,Flags,Storage,ProjectItemCollection,ppProject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProjects_INTERFACE_DEFINED__ */


#ifndef __IApcProject_INTERFACE_DEFINED__
#define __IApcProject_INTERFACE_DEFINED__

/* interface IApcProject */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcProject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10E018B3-6FD7-486A-8F05-0DDF4B821EA1")
    IApcProject : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayName( 
            /* [retval][out] */ BSTR *pbstrDisplayName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayName( 
            /* [in] */ BSTR NewDisplayName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ReferenceName( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ReferenceName( 
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Mode( 
            /* [retval][out] */ APCPROJECTMODE *pMode) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Mode( 
            /* [in] */ APCPROJECTMODE NewMode) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Dirty( 
            /* [out][retval] */ VARIANT_BOOL *pbIsDirty) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Dirty( 
            /* [in] */ VARIANT_BOOL IsDirty) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProjects **ppProjects) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HostProtection( 
            /* [in] */ VARIANT_BOOL Protected) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HostProtection( 
            /* [retval][out] */ VARIANT_BOOL *pbProtected) = 0;
        
        virtual /* [helpcontext][helpstring][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_ProtectionState( 
            /* [retval][out] */ APCPROJECTPROTECTION *pState) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UserProtection( 
            /* [retval][out] */ VARIANT_BOOL *pbProtected) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SystemProtection( 
            /* [retval][out] */ VARIANT_BOOL *pbProtected) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DelayProtection( 
            /* [out][retval] */ VARIANT_BOOL *pbDelayedProtection) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DelayProtection( 
            /* [in] */ VARIANT_BOOL DelayedProtection) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectItems( 
            /* [out][retval] */ IApcProjectItems **ppProjectItems) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Locked( 
            /* [out][retval] */ VARIANT_BOOL *pbLocked) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VBProject( 
            /* [out][retval] */ /* external definition not present */ VBProject **ppVBProject) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [out][retval] */ APCPROJECTFLAG *pFlags) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Storage( 
            /* [retval][out] */ IApcStorage **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_IStorage( 
            /* [retval][out] */ IUnknown **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EventsFrozen( 
            /* [retval][out] */ VARIANT_BOOL *pbEventsFrozen) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ParseLineError( 
            /* [retval][out] */ BSTR *pbstrError) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Compiled( 
            /* [retval][out] */ VARIANT_BOOL *pbCompiled) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HasDigitalSignature( 
            /* [retval][out] */ VARIANT_BOOL *pbHasSignature) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [defaultvalue][in] */ VARIANT_BOOL ForceSave = FALSE) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ IApcStorage *Storage) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SaveCopyAs( 
            /* [in] */ IApcStorage *Storage) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SaveCompleted( 
            /* [defaultvalue][in] */ VARIANT_BOOL SaveSucceeded = TRUE) = 0;
        
        virtual /* [vararg][helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ BSTR ModuleName,
            /* [in] */ BSTR Name,
            /* [in] */ SAFEARRAY * *Arguments,
            /* [retval][out] */ VARIANT *pReturnValue) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Compile( 
            /* [retval][out] */ VARIANT_BOOL *pbCompiled) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ExecuteLine( 
            /* [in] */ BSTR ExecuteText) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ParseLine( 
            /* [in] */ BSTR ParseText,
            /* [retval][out] */ VARIANT_BOOL *pbSuccess) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [defaultvalue][in] */ VARIANT_BOOL SaveChanges = FALSE) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AdviseProjectEvents( 
            /* [in] */ IApcProjectEvents *EventSink,
            /* [retval][out] */ long *pCookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE UnadviseProjectEvents( 
            /* [in] */ long Cookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CreateScopes( 
            /* [defaultvalue][in] */ VARIANT_BOOL AutoFill,
            /* [retval][out] */ IApcScopes **ppScopes) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ChangeUserProtection( 
            /* [in] */ VARIANT_BOOL Protected,
            /* [in] */ BSTR Password) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_FormsSFILevel( 
            /* [retval][out] */ DWORD *pdwLevel) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_FormsSFILevel( 
            /* [in] */ DWORD dwLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcProject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcProject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcProject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcProject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcProject * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IApcProject * This,
            /* [in] */ BSTR NewName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            IApcProject * This,
            /* [retval][out] */ BSTR *pbstrDisplayName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayName )( 
            IApcProject * This,
            /* [in] */ BSTR NewDisplayName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferenceName )( 
            IApcProject * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ReferenceName )( 
            IApcProject * This,
            /* [in] */ BSTR NewName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mode )( 
            IApcProject * This,
            /* [retval][out] */ APCPROJECTMODE *pMode);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Mode )( 
            IApcProject * This,
            /* [in] */ APCPROJECTMODE NewMode);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dirty )( 
            IApcProject * This,
            /* [out][retval] */ VARIANT_BOOL *pbIsDirty);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dirty )( 
            IApcProject * This,
            /* [in] */ VARIANT_BOOL IsDirty);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcProject * This,
            /* [retval][out] */ IApcProjects **ppProjects);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostProtection )( 
            IApcProject * This,
            /* [in] */ VARIANT_BOOL Protected);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostProtection )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT_BOOL *pbProtected);
        
        /* [helpcontext][helpstring][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProtectionState )( 
            IApcProject * This,
            /* [retval][out] */ APCPROJECTPROTECTION *pState);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserProtection )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT_BOOL *pbProtected);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SystemProtection )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT_BOOL *pbProtected);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DelayProtection )( 
            IApcProject * This,
            /* [out][retval] */ VARIANT_BOOL *pbDelayedProtection);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DelayProtection )( 
            IApcProject * This,
            /* [in] */ VARIANT_BOOL DelayedProtection);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectItems )( 
            IApcProject * This,
            /* [out][retval] */ IApcProjectItems **ppProjectItems);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Locked )( 
            IApcProject * This,
            /* [out][retval] */ VARIANT_BOOL *pbLocked);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VBProject )( 
            IApcProject * This,
            /* [out][retval] */ /* external definition not present */ VBProject **ppVBProject);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            IApcProject * This,
            /* [out][retval] */ APCPROJECTFLAG *pFlags);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcProject * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcProject * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storage )( 
            IApcProject * This,
            /* [retval][out] */ IApcStorage **ppStorage);
        
        /* [helpcontext][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IStorage )( 
            IApcProject * This,
            /* [retval][out] */ IUnknown **ppStorage);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventsFrozen )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT_BOOL *pbEventsFrozen);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParseLineError )( 
            IApcProject * This,
            /* [retval][out] */ BSTR *pbstrError);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Compiled )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT_BOOL *pbCompiled);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasDigitalSignature )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT_BOOL *pbHasSignature);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IApcProject * This,
            /* [defaultvalue][in] */ VARIANT_BOOL ForceSave);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IApcProject * This,
            /* [in] */ IApcStorage *Storage);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveCopyAs )( 
            IApcProject * This,
            /* [in] */ IApcStorage *Storage);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SaveCompleted )( 
            IApcProject * This,
            /* [defaultvalue][in] */ VARIANT_BOOL SaveSucceeded);
        
        /* [vararg][helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IApcProject * This,
            /* [in] */ BSTR ModuleName,
            /* [in] */ BSTR Name,
            /* [in] */ SAFEARRAY * *Arguments,
            /* [retval][out] */ VARIANT *pReturnValue);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Compile )( 
            IApcProject * This,
            /* [retval][out] */ VARIANT_BOOL *pbCompiled);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ExecuteLine )( 
            IApcProject * This,
            /* [in] */ BSTR ExecuteText);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ParseLine )( 
            IApcProject * This,
            /* [in] */ BSTR ParseText,
            /* [retval][out] */ VARIANT_BOOL *pbSuccess);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IApcProject * This,
            /* [defaultvalue][in] */ VARIANT_BOOL SaveChanges);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdviseProjectEvents )( 
            IApcProject * This,
            /* [in] */ IApcProjectEvents *EventSink,
            /* [retval][out] */ long *pCookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnadviseProjectEvents )( 
            IApcProject * This,
            /* [in] */ long Cookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateScopes )( 
            IApcProject * This,
            /* [defaultvalue][in] */ VARIANT_BOOL AutoFill,
            /* [retval][out] */ IApcScopes **ppScopes);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ChangeUserProtection )( 
            IApcProject * This,
            /* [in] */ VARIANT_BOOL Protected,
            /* [in] */ BSTR Password);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FormsSFILevel )( 
            IApcProject * This,
            /* [retval][out] */ DWORD *pdwLevel);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FormsSFILevel )( 
            IApcProject * This,
            /* [in] */ DWORD dwLevel);
        
        END_INTERFACE
    } IApcProjectVtbl;

    interface IApcProject
    {
        CONST_VTBL struct IApcProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcProject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcProject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcProject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcProject_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcProject_put_Name(This,NewName)	\
    ( (This)->lpVtbl -> put_Name(This,NewName) ) 

#define IApcProject_get_DisplayName(This,pbstrDisplayName)	\
    ( (This)->lpVtbl -> get_DisplayName(This,pbstrDisplayName) ) 

#define IApcProject_put_DisplayName(This,NewDisplayName)	\
    ( (This)->lpVtbl -> put_DisplayName(This,NewDisplayName) ) 

#define IApcProject_get_ReferenceName(This,pbstrName)	\
    ( (This)->lpVtbl -> get_ReferenceName(This,pbstrName) ) 

#define IApcProject_put_ReferenceName(This,NewName)	\
    ( (This)->lpVtbl -> put_ReferenceName(This,NewName) ) 

#define IApcProject_get_Mode(This,pMode)	\
    ( (This)->lpVtbl -> get_Mode(This,pMode) ) 

#define IApcProject_put_Mode(This,NewMode)	\
    ( (This)->lpVtbl -> put_Mode(This,NewMode) ) 

#define IApcProject_get_Dirty(This,pbIsDirty)	\
    ( (This)->lpVtbl -> get_Dirty(This,pbIsDirty) ) 

#define IApcProject_put_Dirty(This,IsDirty)	\
    ( (This)->lpVtbl -> put_Dirty(This,IsDirty) ) 

#define IApcProject_get_Parent(This,ppProjects)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProjects) ) 

#define IApcProject_put_HostProtection(This,Protected)	\
    ( (This)->lpVtbl -> put_HostProtection(This,Protected) ) 

#define IApcProject_get_HostProtection(This,pbProtected)	\
    ( (This)->lpVtbl -> get_HostProtection(This,pbProtected) ) 

#define IApcProject_get_ProtectionState(This,pState)	\
    ( (This)->lpVtbl -> get_ProtectionState(This,pState) ) 

#define IApcProject_get_UserProtection(This,pbProtected)	\
    ( (This)->lpVtbl -> get_UserProtection(This,pbProtected) ) 

#define IApcProject_get_SystemProtection(This,pbProtected)	\
    ( (This)->lpVtbl -> get_SystemProtection(This,pbProtected) ) 

#define IApcProject_get_DelayProtection(This,pbDelayedProtection)	\
    ( (This)->lpVtbl -> get_DelayProtection(This,pbDelayedProtection) ) 

#define IApcProject_put_DelayProtection(This,DelayedProtection)	\
    ( (This)->lpVtbl -> put_DelayProtection(This,DelayedProtection) ) 

#define IApcProject_get_ProjectItems(This,ppProjectItems)	\
    ( (This)->lpVtbl -> get_ProjectItems(This,ppProjectItems) ) 

#define IApcProject_get_Locked(This,pbLocked)	\
    ( (This)->lpVtbl -> get_Locked(This,pbLocked) ) 

#define IApcProject_get_VBProject(This,ppVBProject)	\
    ( (This)->lpVtbl -> get_VBProject(This,ppVBProject) ) 

#define IApcProject_get_Flags(This,pFlags)	\
    ( (This)->lpVtbl -> get_Flags(This,pFlags) ) 

#define IApcProject_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcProject_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcProject_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcProject_get_Storage(This,ppStorage)	\
    ( (This)->lpVtbl -> get_Storage(This,ppStorage) ) 

#define IApcProject_get_IStorage(This,ppStorage)	\
    ( (This)->lpVtbl -> get_IStorage(This,ppStorage) ) 

#define IApcProject_get_EventsFrozen(This,pbEventsFrozen)	\
    ( (This)->lpVtbl -> get_EventsFrozen(This,pbEventsFrozen) ) 

#define IApcProject_get_ParseLineError(This,pbstrError)	\
    ( (This)->lpVtbl -> get_ParseLineError(This,pbstrError) ) 

#define IApcProject_get_Compiled(This,pbCompiled)	\
    ( (This)->lpVtbl -> get_Compiled(This,pbCompiled) ) 

#define IApcProject_get_HasDigitalSignature(This,pbHasSignature)	\
    ( (This)->lpVtbl -> get_HasDigitalSignature(This,pbHasSignature) ) 

#define IApcProject_Save(This,ForceSave)	\
    ( (This)->lpVtbl -> Save(This,ForceSave) ) 

#define IApcProject_SaveAs(This,Storage)	\
    ( (This)->lpVtbl -> SaveAs(This,Storage) ) 

#define IApcProject_SaveCopyAs(This,Storage)	\
    ( (This)->lpVtbl -> SaveCopyAs(This,Storage) ) 

#define IApcProject_SaveCompleted(This,SaveSucceeded)	\
    ( (This)->lpVtbl -> SaveCompleted(This,SaveSucceeded) ) 

#define IApcProject_Run(This,ModuleName,Name,Arguments,pReturnValue)	\
    ( (This)->lpVtbl -> Run(This,ModuleName,Name,Arguments,pReturnValue) ) 

#define IApcProject_Compile(This,pbCompiled)	\
    ( (This)->lpVtbl -> Compile(This,pbCompiled) ) 

#define IApcProject_ExecuteLine(This,ExecuteText)	\
    ( (This)->lpVtbl -> ExecuteLine(This,ExecuteText) ) 

#define IApcProject_ParseLine(This,ParseText,pbSuccess)	\
    ( (This)->lpVtbl -> ParseLine(This,ParseText,pbSuccess) ) 

#define IApcProject_Close(This,SaveChanges)	\
    ( (This)->lpVtbl -> Close(This,SaveChanges) ) 

#define IApcProject_AdviseProjectEvents(This,EventSink,pCookie)	\
    ( (This)->lpVtbl -> AdviseProjectEvents(This,EventSink,pCookie) ) 

#define IApcProject_UnadviseProjectEvents(This,Cookie)	\
    ( (This)->lpVtbl -> UnadviseProjectEvents(This,Cookie) ) 

#define IApcProject_CreateScopes(This,AutoFill,ppScopes)	\
    ( (This)->lpVtbl -> CreateScopes(This,AutoFill,ppScopes) ) 

#define IApcProject_ChangeUserProtection(This,Protected,Password)	\
    ( (This)->lpVtbl -> ChangeUserProtection(This,Protected,Password) ) 

#define IApcProject_get_FormsSFILevel(This,pdwLevel)	\
    ( (This)->lpVtbl -> get_FormsSFILevel(This,pdwLevel) ) 

#define IApcProject_put_FormsSFILevel(This,dwLevel)	\
    ( (This)->lpVtbl -> put_FormsSFILevel(This,dwLevel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProject_INTERFACE_DEFINED__ */


#ifndef __IApcProjectEvents_INTERFACE_DEFINED__
#define __IApcProjectEvents_INTERFACE_DEFINED__

/* interface IApcProjectEvents */
/* [object][hidden][uuid] */ 


EXTERN_C const IID IID_IApcProjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87AA3B8B-B188-45B4-9ECA-4DB2E90F1335")
    IApcProjectEvents : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ProjectItemCreated( 
            /* [in] */ IApcProjectItem *ProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ProjectItemDelete( 
            /* [in] */ IApcProjectItem *ProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ModeChange( 
            /* [in] */ APCPROJECTMODE NewMode) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE NameChange( 
            /* [in] */ IApcProjectItem *ProjectItem,
            /* [in] */ BSTR OldName) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcedureAdd( 
            /* [in] */ IApcProcedure *Procedure) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcedureDelete( 
            /* [in] */ IApcProjectItem *ProjectItem,
            /* [in] */ BSTR ProcedureName,
            /* [in] */ APCPROCEDURETYPE ProcedureType) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ModuleChange( 
            /* [in] */ IApcProjectItem *ProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenProjectItem( 
            /* [in] */ BSTR Name,
            /* [in] */ long ID,
            /* [out][in] */ IDispatch **HostProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ModuleDirtyChange( 
            /* [in] */ IApcProjectItem *ProjectItem,
            VARIANT_BOOL Dirty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProjectEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProjectEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProjectEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IApcProjectEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IApcProjectEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProjectItemCreated )( 
            IApcProjectEvents * This,
            /* [in] */ IApcProjectItem *ProjectItem);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProjectItemDelete )( 
            IApcProjectEvents * This,
            /* [in] */ IApcProjectItem *ProjectItem);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ModeChange )( 
            IApcProjectEvents * This,
            /* [in] */ APCPROJECTMODE NewMode);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NameChange )( 
            IApcProjectEvents * This,
            /* [in] */ IApcProjectItem *ProjectItem,
            /* [in] */ BSTR OldName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcedureAdd )( 
            IApcProjectEvents * This,
            /* [in] */ IApcProcedure *Procedure);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcedureDelete )( 
            IApcProjectEvents * This,
            /* [in] */ IApcProjectItem *ProjectItem,
            /* [in] */ BSTR ProcedureName,
            /* [in] */ APCPROCEDURETYPE ProcedureType);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ModuleChange )( 
            IApcProjectEvents * This,
            /* [in] */ IApcProjectItem *ProjectItem);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenProjectItem )( 
            IApcProjectEvents * This,
            /* [in] */ BSTR Name,
            /* [in] */ long ID,
            /* [out][in] */ IDispatch **HostProjectItem);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ModuleDirtyChange )( 
            IApcProjectEvents * This,
            /* [in] */ IApcProjectItem *ProjectItem,
            VARIANT_BOOL Dirty);
        
        END_INTERFACE
    } IApcProjectEventsVtbl;

    interface IApcProjectEvents
    {
        CONST_VTBL struct IApcProjectEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProjectEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProjectEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProjectEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProjectEvents_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IApcProjectEvents_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IApcProjectEvents_ProjectItemCreated(This,ProjectItem)	\
    ( (This)->lpVtbl -> ProjectItemCreated(This,ProjectItem) ) 

#define IApcProjectEvents_ProjectItemDelete(This,ProjectItem)	\
    ( (This)->lpVtbl -> ProjectItemDelete(This,ProjectItem) ) 

#define IApcProjectEvents_ModeChange(This,NewMode)	\
    ( (This)->lpVtbl -> ModeChange(This,NewMode) ) 

#define IApcProjectEvents_NameChange(This,ProjectItem,OldName)	\
    ( (This)->lpVtbl -> NameChange(This,ProjectItem,OldName) ) 

#define IApcProjectEvents_ProcedureAdd(This,Procedure)	\
    ( (This)->lpVtbl -> ProcedureAdd(This,Procedure) ) 

#define IApcProjectEvents_ProcedureDelete(This,ProjectItem,ProcedureName,ProcedureType)	\
    ( (This)->lpVtbl -> ProcedureDelete(This,ProjectItem,ProcedureName,ProcedureType) ) 

#define IApcProjectEvents_ModuleChange(This,ProjectItem)	\
    ( (This)->lpVtbl -> ModuleChange(This,ProjectItem) ) 

#define IApcProjectEvents_OpenProjectItem(This,Name,ID,HostProjectItem)	\
    ( (This)->lpVtbl -> OpenProjectItem(This,Name,ID,HostProjectItem) ) 

#define IApcProjectEvents_ModuleDirtyChange(This,ProjectItem,Dirty)	\
    ( (This)->lpVtbl -> ModuleDirtyChange(This,ProjectItem,Dirty) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProjectEvents_INTERFACE_DEFINED__ */


#ifndef __IApcProjectItems_INTERFACE_DEFINED__
#define __IApcProjectItems_INTERFACE_DEFINED__

/* interface IApcProjectItems */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcProjectItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("435D295E-6855-4988-9747-082EA809987A")
    IApcProjectItems : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProject **ppProject) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByID( 
            /* [in] */ long ID,
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VBComponents( 
            /* [retval][out] */ /* external definition not present */ _VBComponents **ppVBComponents) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AddCodeModule( 
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AddClassModule( 
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AddHostProjectItem( 
            /* [in] */ VARIANT *HostObject,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AddDesignerProjectItem( 
            /* [in] */ BSTR Designer,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AddHostClass( 
            /* [in] */ VARIANT *HostObject,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ IApcProjectItem *ProjectItem,
            /* [optional][in] */ BSTR NewName,
            /* [defaultvalue][in] */ IDispatch *HostObject,
            /* [retval][out] */ IApcProjectItem **ppNewProjItem) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ValidName( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT_BOOL *pbValid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProjectItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProjectItems * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProjectItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProjectItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcProjectItems * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcProjectItems * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcProjectItems * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcProjectItems * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcProjectItems * This,
            /* [retval][out] */ IApcProject **ppProject);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcProjectItems * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcProjectItems * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcProjectItems * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcProjectItems * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcProjectItems * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByID )( 
            IApcProjectItems * This,
            /* [in] */ long ID,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VBComponents )( 
            IApcProjectItems * This,
            /* [retval][out] */ /* external definition not present */ _VBComponents **ppVBComponents);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddCodeModule )( 
            IApcProjectItems * This,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddClassModule )( 
            IApcProjectItems * This,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddHostProjectItem )( 
            IApcProjectItems * This,
            /* [in] */ VARIANT *HostObject,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddDesignerProjectItem )( 
            IApcProjectItems * This,
            /* [in] */ BSTR Designer,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddHostClass )( 
            IApcProjectItems * This,
            /* [in] */ VARIANT *HostObject,
            /* [optional][in] */ BSTR Name,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcProjectItems * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IApcProjectItems * This,
            /* [in] */ IApcProjectItem *ProjectItem,
            /* [optional][in] */ BSTR NewName,
            /* [defaultvalue][in] */ IDispatch *HostObject,
            /* [retval][out] */ IApcProjectItem **ppNewProjItem);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ValidName )( 
            IApcProjectItems * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT_BOOL *pbValid);
        
        END_INTERFACE
    } IApcProjectItemsVtbl;

    interface IApcProjectItems
    {
        CONST_VTBL struct IApcProjectItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProjectItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProjectItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProjectItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProjectItems_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcProjectItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcProjectItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcProjectItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcProjectItems_get_Parent(This,ppProject)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProject) ) 

#define IApcProjectItems_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcProjectItems_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcProjectItems_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcProjectItems_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcProjectItems_get_Item(This,Index,ppProjectItem)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppProjectItem) ) 

#define IApcProjectItems_get_ItemByID(This,ID,ppProjectItem)	\
    ( (This)->lpVtbl -> get_ItemByID(This,ID,ppProjectItem) ) 

#define IApcProjectItems_get_VBComponents(This,ppVBComponents)	\
    ( (This)->lpVtbl -> get_VBComponents(This,ppVBComponents) ) 

#define IApcProjectItems_AddCodeModule(This,Name,ppProjectItem)	\
    ( (This)->lpVtbl -> AddCodeModule(This,Name,ppProjectItem) ) 

#define IApcProjectItems_AddClassModule(This,Name,ppProjectItem)	\
    ( (This)->lpVtbl -> AddClassModule(This,Name,ppProjectItem) ) 

#define IApcProjectItems_AddHostProjectItem(This,HostObject,Name,ppProjectItem)	\
    ( (This)->lpVtbl -> AddHostProjectItem(This,HostObject,Name,ppProjectItem) ) 

#define IApcProjectItems_AddDesignerProjectItem(This,Designer,Name,ppProjectItem)	\
    ( (This)->lpVtbl -> AddDesignerProjectItem(This,Designer,Name,ppProjectItem) ) 

#define IApcProjectItems_AddHostClass(This,HostObject,Name,ppProjectItem)	\
    ( (This)->lpVtbl -> AddHostClass(This,HostObject,Name,ppProjectItem) ) 

#define IApcProjectItems_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcProjectItems_Copy(This,ProjectItem,NewName,HostObject,ppNewProjItem)	\
    ( (This)->lpVtbl -> Copy(This,ProjectItem,NewName,HostObject,ppNewProjItem) ) 

#define IApcProjectItems_ValidName(This,Name,pbValid)	\
    ( (This)->lpVtbl -> ValidName(This,Name,pbValid) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProjectItems_INTERFACE_DEFINED__ */


#ifndef __IApcProjectItem_INTERFACE_DEFINED__
#define __IApcProjectItem_INTERFACE_DEFINED__

/* interface IApcProjectItem */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcProjectItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ACA4A939-23B2-4931-BF9D-883BE81A52C4")
    IApcProjectItem : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProjectItems **ppProjectItems) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ APCPROJECTITEMTYPE *pType) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CompositeObject( 
            /* [retval][out] */ IDispatch **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pID) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Procedures( 
            /* [retval][out] */ IApcProcedures **ppProceduress) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DisplayName( 
            /* [retval][out] */ BSTR *pbstrDisplayName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DisplayName( 
            /* [in] */ BSTR NewDisplayName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Controls( 
            /* [retval][out] */ IApcControls **ppControls) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Categories( 
            /* [retval][out] */ IApcCategories **ppIApcCategorizedProperties) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VBComponent( 
            /* [out][retval] */ /* external definition not present */ _VBComponent **ppVBComponent) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HostObject( 
            /* [out][retval] */ IDispatch **ppHostObject) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AllowViewObject( 
            /* [out][retval] */ VARIANT_BOOL *pbAllowViewObject) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AllowViewObject( 
            /* [in] */ VARIANT_BOOL AllowViewObject) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Picture( 
            /* [in] */ /* external definition not present */ IPictureDisp *pPicture) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ /* external definition not present */ IPictureDisp **ppPicture) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pBackColor) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR BackColor) = 0;
        
        virtual /* [helpcontext][helpstring][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_RequiredClasses( 
            /* [out][retval] */ IApcRequiredClasses **ppRequiredClasses) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Instances( 
            /* [out][retval] */ IApcInstances **ppInstances) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AppendTextFromFile( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ViewEventHandler( 
            /* [optional][in] */ BSTR EventName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ViewCode( 
            /* [optional][in] */ BSTR ProcedureName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
        virtual /* [vararg][helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ BSTR Name,
            /* [in] */ SAFEARRAY * *Arguments,
            /* [retval][out] */ VARIANT *pReturnValue) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AdviseProjectItemEvents( 
            /* [in] */ IApcProjectItemEvents *EventSink,
            /* [retval][out] */ long *pCookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE UnadviseProjectItemEvents( 
            /* [in] */ long Cookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Compile( 
            /* [retval][out] */ VARIANT_BOOL *pbCompiled) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SetHostClassBase( 
            /* [in] */ IDispatch *HostClassBase) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProjectItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProjectItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProjectItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProjectItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcProjectItem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcProjectItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcProjectItem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcProjectItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcProjectItem * This,
            /* [retval][out] */ IApcProjectItems **ppProjectItems);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IApcProjectItem * This,
            /* [retval][out] */ APCPROJECTITEMTYPE *pType);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositeObject )( 
            IApcProjectItem * This,
            /* [retval][out] */ IDispatch **ppProjectItem);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcProjectItem * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IApcProjectItem * This,
            /* [in] */ BSTR NewName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IApcProjectItem * This,
            /* [retval][out] */ long *pID);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Procedures )( 
            IApcProjectItem * This,
            /* [retval][out] */ IApcProcedures **ppProceduress);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            IApcProjectItem * This,
            /* [retval][out] */ BSTR *pbstrDisplayName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayName )( 
            IApcProjectItem * This,
            /* [in] */ BSTR NewDisplayName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Controls )( 
            IApcProjectItem * This,
            /* [retval][out] */ IApcControls **ppControls);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcProjectItem * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Categories )( 
            IApcProjectItem * This,
            /* [retval][out] */ IApcCategories **ppIApcCategorizedProperties);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcProjectItem * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcProjectItem * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VBComponent )( 
            IApcProjectItem * This,
            /* [out][retval] */ /* external definition not present */ _VBComponent **ppVBComponent);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostObject )( 
            IApcProjectItem * This,
            /* [out][retval] */ IDispatch **ppHostObject);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowViewObject )( 
            IApcProjectItem * This,
            /* [out][retval] */ VARIANT_BOOL *pbAllowViewObject);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowViewObject )( 
            IApcProjectItem * This,
            /* [in] */ VARIANT_BOOL AllowViewObject);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Picture )( 
            IApcProjectItem * This,
            /* [in] */ /* external definition not present */ IPictureDisp *pPicture);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Picture )( 
            IApcProjectItem * This,
            /* [retval][out] */ /* external definition not present */ IPictureDisp **ppPicture);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IApcProjectItem * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pBackColor);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IApcProjectItem * This,
            /* [in] */ /* external definition not present */ OLE_COLOR BackColor);
        
        /* [helpcontext][helpstring][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequiredClasses )( 
            IApcProjectItem * This,
            /* [out][retval] */ IApcRequiredClasses **ppRequiredClasses);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Instances )( 
            IApcProjectItem * This,
            /* [out][retval] */ IApcInstances **ppInstances);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AppendTextFromFile )( 
            IApcProjectItem * This,
            /* [in] */ BSTR FileName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ViewEventHandler )( 
            IApcProjectItem * This,
            /* [optional][in] */ BSTR EventName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ViewCode )( 
            IApcProjectItem * This,
            /* [optional][in] */ BSTR ProcedureName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IApcProjectItem * This);
        
        /* [vararg][helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IApcProjectItem * This,
            /* [in] */ BSTR Name,
            /* [in] */ SAFEARRAY * *Arguments,
            /* [retval][out] */ VARIANT *pReturnValue);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcProjectItem * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdviseProjectItemEvents )( 
            IApcProjectItem * This,
            /* [in] */ IApcProjectItemEvents *EventSink,
            /* [retval][out] */ long *pCookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnadviseProjectItemEvents )( 
            IApcProjectItem * This,
            /* [in] */ long Cookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Compile )( 
            IApcProjectItem * This,
            /* [retval][out] */ VARIANT_BOOL *pbCompiled);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetHostClassBase )( 
            IApcProjectItem * This,
            /* [in] */ IDispatch *HostClassBase);
        
        END_INTERFACE
    } IApcProjectItemVtbl;

    interface IApcProjectItem
    {
        CONST_VTBL struct IApcProjectItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProjectItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProjectItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProjectItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProjectItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcProjectItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcProjectItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcProjectItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcProjectItem_get_Parent(This,ppProjectItems)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProjectItems) ) 

#define IApcProjectItem_get_Type(This,pType)	\
    ( (This)->lpVtbl -> get_Type(This,pType) ) 

#define IApcProjectItem_get_CompositeObject(This,ppProjectItem)	\
    ( (This)->lpVtbl -> get_CompositeObject(This,ppProjectItem) ) 

#define IApcProjectItem_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcProjectItem_put_Name(This,NewName)	\
    ( (This)->lpVtbl -> put_Name(This,NewName) ) 

#define IApcProjectItem_get_ID(This,pID)	\
    ( (This)->lpVtbl -> get_ID(This,pID) ) 

#define IApcProjectItem_get_Procedures(This,ppProceduress)	\
    ( (This)->lpVtbl -> get_Procedures(This,ppProceduress) ) 

#define IApcProjectItem_get_DisplayName(This,pbstrDisplayName)	\
    ( (This)->lpVtbl -> get_DisplayName(This,pbstrDisplayName) ) 

#define IApcProjectItem_put_DisplayName(This,NewDisplayName)	\
    ( (This)->lpVtbl -> put_DisplayName(This,NewDisplayName) ) 

#define IApcProjectItem_get_Controls(This,ppControls)	\
    ( (This)->lpVtbl -> get_Controls(This,ppControls) ) 

#define IApcProjectItem_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcProjectItem_get_Categories(This,ppIApcCategorizedProperties)	\
    ( (This)->lpVtbl -> get_Categories(This,ppIApcCategorizedProperties) ) 

#define IApcProjectItem_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcProjectItem_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcProjectItem_get_VBComponent(This,ppVBComponent)	\
    ( (This)->lpVtbl -> get_VBComponent(This,ppVBComponent) ) 

#define IApcProjectItem_get_HostObject(This,ppHostObject)	\
    ( (This)->lpVtbl -> get_HostObject(This,ppHostObject) ) 

#define IApcProjectItem_get_AllowViewObject(This,pbAllowViewObject)	\
    ( (This)->lpVtbl -> get_AllowViewObject(This,pbAllowViewObject) ) 

#define IApcProjectItem_put_AllowViewObject(This,AllowViewObject)	\
    ( (This)->lpVtbl -> put_AllowViewObject(This,AllowViewObject) ) 

#define IApcProjectItem_put_Picture(This,pPicture)	\
    ( (This)->lpVtbl -> put_Picture(This,pPicture) ) 

#define IApcProjectItem_get_Picture(This,ppPicture)	\
    ( (This)->lpVtbl -> get_Picture(This,ppPicture) ) 

#define IApcProjectItem_get_BackColor(This,pBackColor)	\
    ( (This)->lpVtbl -> get_BackColor(This,pBackColor) ) 

#define IApcProjectItem_put_BackColor(This,BackColor)	\
    ( (This)->lpVtbl -> put_BackColor(This,BackColor) ) 

#define IApcProjectItem_get_RequiredClasses(This,ppRequiredClasses)	\
    ( (This)->lpVtbl -> get_RequiredClasses(This,ppRequiredClasses) ) 

#define IApcProjectItem_get_Instances(This,ppInstances)	\
    ( (This)->lpVtbl -> get_Instances(This,ppInstances) ) 

#define IApcProjectItem_AppendTextFromFile(This,FileName)	\
    ( (This)->lpVtbl -> AppendTextFromFile(This,FileName) ) 

#define IApcProjectItem_ViewEventHandler(This,EventName)	\
    ( (This)->lpVtbl -> ViewEventHandler(This,EventName) ) 

#define IApcProjectItem_ViewCode(This,ProcedureName)	\
    ( (This)->lpVtbl -> ViewCode(This,ProcedureName) ) 

#define IApcProjectItem_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#define IApcProjectItem_Run(This,Name,Arguments,pReturnValue)	\
    ( (This)->lpVtbl -> Run(This,Name,Arguments,pReturnValue) ) 

#define IApcProjectItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IApcProjectItem_AdviseProjectItemEvents(This,EventSink,pCookie)	\
    ( (This)->lpVtbl -> AdviseProjectItemEvents(This,EventSink,pCookie) ) 

#define IApcProjectItem_UnadviseProjectItemEvents(This,Cookie)	\
    ( (This)->lpVtbl -> UnadviseProjectItemEvents(This,Cookie) ) 

#define IApcProjectItem_Compile(This,pbCompiled)	\
    ( (This)->lpVtbl -> Compile(This,pbCompiled) ) 

#define IApcProjectItem_SetHostClassBase(This,HostClassBase)	\
    ( (This)->lpVtbl -> SetHostClassBase(This,HostClassBase) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProjectItem_INTERFACE_DEFINED__ */


#ifndef __IApcProjectItemEvents_INTERFACE_DEFINED__
#define __IApcProjectItemEvents_INTERFACE_DEFINED__

/* interface IApcProjectItemEvents */
/* [object][hidden][uuid] */ 


EXTERN_C const IID IID_IApcProjectItemEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91CBB031-1003-4E9D-A27F-979224C88BCB")
    IApcProjectItemEvents : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE View( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateInstance( 
            /* [out][in] */ IDispatch **Instance) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ReleaseInstances( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE InstanceCreated( 
            /* [in] */ IDispatch *Instance) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProjectItemEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProjectItemEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProjectItemEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProjectItemEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IApcProjectItemEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IApcProjectItemEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            IApcProjectItemEvents * This,
            /* [out][in] */ IDispatch **Instance);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseInstances )( 
            IApcProjectItemEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InstanceCreated )( 
            IApcProjectItemEvents * This,
            /* [in] */ IDispatch *Instance);
        
        END_INTERFACE
    } IApcProjectItemEventsVtbl;

    interface IApcProjectItemEvents
    {
        CONST_VTBL struct IApcProjectItemEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProjectItemEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProjectItemEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProjectItemEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProjectItemEvents_View(This)	\
    ( (This)->lpVtbl -> View(This) ) 

#define IApcProjectItemEvents_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#define IApcProjectItemEvents_CreateInstance(This,Instance)	\
    ( (This)->lpVtbl -> CreateInstance(This,Instance) ) 

#define IApcProjectItemEvents_ReleaseInstances(This)	\
    ( (This)->lpVtbl -> ReleaseInstances(This) ) 

#define IApcProjectItemEvents_InstanceCreated(This,Instance)	\
    ( (This)->lpVtbl -> InstanceCreated(This,Instance) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProjectItemEvents_INTERFACE_DEFINED__ */


#ifndef __IApcControls_INTERFACE_DEFINED__
#define __IApcControls_INTERFACE_DEFINED__

/* interface IApcControls */
/* [object][hidden][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcControls;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E449291-C5F0-43F1-BF4A-DA6B9973B8D4")
    IApcControls : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcControl **ppControl) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByID( 
            /* [in] */ long ID,
            /* [retval][out] */ IApcControl **ppControl) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IDispatch *HostControl,
            /* [defaultvalue][in] */ IDispatch *Extender,
            /* [defaultvalue][in] */ APCCONTROLFLAG Flags,
            /* [retval][out] */ IApcControl **ppControl) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE AddByGuid( 
            /* [in] */ GUID guid,
            /* [defaultvalue][in] */ IDispatch *Extender,
            /* [defaultvalue][in] */ APCCONTROLFLAG Flags,
            /* [retval][out] */ IApcControl **ppControl) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE AddByProgID( 
            /* [in] */ BSTR ProgID,
            /* [defaultvalue][in] */ IDispatch *Extender,
            /* [defaultvalue][in] */ APCCONTROLFLAG Flags,
            /* [retval][out] */ IApcControl **ppControl) = 0;
        
        virtual /* [helpcontext][helpstring][hidden] */ HRESULT STDMETHODCALLTYPE LoadControl( 
            /* [in] */ long ID) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE FinishedLoadingControls( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcControlsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcControls * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcControls * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcControls * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcControls * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcControls * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcControls * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcControls * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcControls * This,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcControls * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcControls * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcControls * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcControls * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcControls * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcControl **ppControl);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByID )( 
            IApcControls * This,
            /* [in] */ long ID,
            /* [retval][out] */ IApcControl **ppControl);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcControls * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcControls * This,
            /* [in] */ IDispatch *HostControl,
            /* [defaultvalue][in] */ IDispatch *Extender,
            /* [defaultvalue][in] */ APCCONTROLFLAG Flags,
            /* [retval][out] */ IApcControl **ppControl);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *AddByGuid )( 
            IApcControls * This,
            /* [in] */ GUID guid,
            /* [defaultvalue][in] */ IDispatch *Extender,
            /* [defaultvalue][in] */ APCCONTROLFLAG Flags,
            /* [retval][out] */ IApcControl **ppControl);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *AddByProgID )( 
            IApcControls * This,
            /* [in] */ BSTR ProgID,
            /* [defaultvalue][in] */ IDispatch *Extender,
            /* [defaultvalue][in] */ APCCONTROLFLAG Flags,
            /* [retval][out] */ IApcControl **ppControl);
        
        /* [helpcontext][helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *LoadControl )( 
            IApcControls * This,
            /* [in] */ long ID);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *FinishedLoadingControls )( 
            IApcControls * This);
        
        END_INTERFACE
    } IApcControlsVtbl;

    interface IApcControls
    {
        CONST_VTBL struct IApcControlsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcControls_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcControls_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcControls_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcControls_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcControls_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcControls_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcControls_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcControls_get_Parent(This,ppProjectItem)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProjectItem) ) 

#define IApcControls_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcControls_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcControls_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcControls_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcControls_get_Item(This,Index,ppControl)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppControl) ) 

#define IApcControls_get_ItemByID(This,ID,ppControl)	\
    ( (This)->lpVtbl -> get_ItemByID(This,ID,ppControl) ) 

#define IApcControls_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcControls_Add(This,HostControl,Extender,Flags,ppControl)	\
    ( (This)->lpVtbl -> Add(This,HostControl,Extender,Flags,ppControl) ) 

#define IApcControls_AddByGuid(This,guid,Extender,Flags,ppControl)	\
    ( (This)->lpVtbl -> AddByGuid(This,guid,Extender,Flags,ppControl) ) 

#define IApcControls_AddByProgID(This,ProgID,Extender,Flags,ppControl)	\
    ( (This)->lpVtbl -> AddByProgID(This,ProgID,Extender,Flags,ppControl) ) 

#define IApcControls_LoadControl(This,ID)	\
    ( (This)->lpVtbl -> LoadControl(This,ID) ) 

#define IApcControls_FinishedLoadingControls(This)	\
    ( (This)->lpVtbl -> FinishedLoadingControls(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcControls_INTERFACE_DEFINED__ */


#ifndef __IApcControl_INTERFACE_DEFINED__
#define __IApcControl_INTERFACE_DEFINED__

/* interface IApcControl */
/* [object][hidden][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E88006EA-83BF-4A97-9926-AFD64CCC0E93")
    IApcControl : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pID) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PersistTag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PersistTag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HostControl( 
            /* [retval][out] */ IDispatch **ppHostControl) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HostControl( 
            /* [in] */ IDispatch *HostControl) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Extender( 
            /* [retval][out] */ IDispatch **ppExtender) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Extender( 
            /* [in] */ IDispatch *NewExtender) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CompositeControl( 
            /* [retval][out] */ IDispatch **ppCompositeControl) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Categories( 
            /* [retval][out] */ IApcCategories **ppIApcCategorizedProperties) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcControls **ppControls) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ APCCONTROLFLAG *pFlags) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ViewEventHandler( 
            /* [optional][in] */ BSTR EventName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE AdviseControlEvents( 
            /* [in] */ IApcControlEvents *EventSink,
            /* [retval][out] */ long *pCookie) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE UnadviseControlEvents( 
            /* [in] */ long Cookie) = 0;
        
        virtual /* [helpcontext][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_HostControl( 
            /* [in] */ IDispatch *HostControl) = 0;
        
        virtual /* [helpcontext][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_Extender( 
            /* [in] */ IDispatch *NewExtender) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Disable( void) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [out][retval] */ VARIANT_BOOL *pbAllowViewObject) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL AllowViewObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcControl * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IApcControl * This,
            /* [in] */ BSTR NewName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IApcControl * This,
            /* [retval][out] */ long *pID);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcControl * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcControl * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PersistTag )( 
            IApcControl * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PersistTag )( 
            IApcControl * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcControl * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostControl )( 
            IApcControl * This,
            /* [retval][out] */ IDispatch **ppHostControl);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostControl )( 
            IApcControl * This,
            /* [in] */ IDispatch *HostControl);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            IApcControl * This,
            /* [retval][out] */ IDispatch **ppExtender);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Extender )( 
            IApcControl * This,
            /* [in] */ IDispatch *NewExtender);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompositeControl )( 
            IApcControl * This,
            /* [retval][out] */ IDispatch **ppCompositeControl);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Categories )( 
            IApcControl * This,
            /* [retval][out] */ IApcCategories **ppIApcCategorizedProperties);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcControl * This,
            /* [retval][out] */ IApcControls **ppControls);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            IApcControl * This,
            /* [retval][out] */ APCCONTROLFLAG *pFlags);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IApcControl * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ViewEventHandler )( 
            IApcControl * This,
            /* [optional][in] */ BSTR EventName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcControl * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdviseControlEvents )( 
            IApcControl * This,
            /* [in] */ IApcControlEvents *EventSink,
            /* [retval][out] */ long *pCookie);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnadviseControlEvents )( 
            IApcControl * This,
            /* [in] */ long Cookie);
        
        /* [helpcontext][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_HostControl )( 
            IApcControl * This,
            /* [in] */ IDispatch *HostControl);
        
        /* [helpcontext][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Extender )( 
            IApcControl * This,
            /* [in] */ IDispatch *NewExtender);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Disable )( 
            IApcControl * This);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IApcControl * This,
            /* [out][retval] */ VARIANT_BOOL *pbAllowViewObject);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IApcControl * This,
            /* [in] */ VARIANT_BOOL AllowViewObject);
        
        END_INTERFACE
    } IApcControlVtbl;

    interface IApcControl
    {
        CONST_VTBL struct IApcControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcControl_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcControl_put_Name(This,NewName)	\
    ( (This)->lpVtbl -> put_Name(This,NewName) ) 

#define IApcControl_get_ID(This,pID)	\
    ( (This)->lpVtbl -> get_ID(This,pID) ) 

#define IApcControl_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcControl_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcControl_put_PersistTag(This,UserTag)	\
    ( (This)->lpVtbl -> put_PersistTag(This,UserTag) ) 

#define IApcControl_get_PersistTag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_PersistTag(This,pUserTag) ) 

#define IApcControl_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcControl_get_HostControl(This,ppHostControl)	\
    ( (This)->lpVtbl -> get_HostControl(This,ppHostControl) ) 

#define IApcControl_put_HostControl(This,HostControl)	\
    ( (This)->lpVtbl -> put_HostControl(This,HostControl) ) 

#define IApcControl_get_Extender(This,ppExtender)	\
    ( (This)->lpVtbl -> get_Extender(This,ppExtender) ) 

#define IApcControl_put_Extender(This,NewExtender)	\
    ( (This)->lpVtbl -> put_Extender(This,NewExtender) ) 

#define IApcControl_get_CompositeControl(This,ppCompositeControl)	\
    ( (This)->lpVtbl -> get_CompositeControl(This,ppCompositeControl) ) 

#define IApcControl_get_Categories(This,ppIApcCategorizedProperties)	\
    ( (This)->lpVtbl -> get_Categories(This,ppIApcCategorizedProperties) ) 

#define IApcControl_get_Parent(This,ppControls)	\
    ( (This)->lpVtbl -> get_Parent(This,ppControls) ) 

#define IApcControl_get_Flags(This,pFlags)	\
    ( (This)->lpVtbl -> get_Flags(This,pFlags) ) 

#define IApcControl_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#define IApcControl_ViewEventHandler(This,EventName)	\
    ( (This)->lpVtbl -> ViewEventHandler(This,EventName) ) 

#define IApcControl_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IApcControl_AdviseControlEvents(This,EventSink,pCookie)	\
    ( (This)->lpVtbl -> AdviseControlEvents(This,EventSink,pCookie) ) 

#define IApcControl_UnadviseControlEvents(This,Cookie)	\
    ( (This)->lpVtbl -> UnadviseControlEvents(This,Cookie) ) 

#define IApcControl_putref_HostControl(This,HostControl)	\
    ( (This)->lpVtbl -> putref_HostControl(This,HostControl) ) 

#define IApcControl_putref_Extender(This,NewExtender)	\
    ( (This)->lpVtbl -> putref_Extender(This,NewExtender) ) 

#define IApcControl_Disable(This)	\
    ( (This)->lpVtbl -> Disable(This) ) 

#define IApcControl_get_Visible(This,pbAllowViewObject)	\
    ( (This)->lpVtbl -> get_Visible(This,pbAllowViewObject) ) 

#define IApcControl_put_Visible(This,AllowViewObject)	\
    ( (This)->lpVtbl -> put_Visible(This,AllowViewObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcControl_INTERFACE_DEFINED__ */


#ifndef __IApcControlEvents_INTERFACE_DEFINED__
#define __IApcControlEvents_INTERFACE_DEFINED__

/* interface IApcControlEvents */
/* [object][hidden][uuid] */ 


EXTERN_C const IID IID_IApcControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("363316D1-A224-4BDC-A757-15924938A11D")
    IApcControlEvents : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcControlEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcControlEvents * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IApcControlEvents * This);
        
        END_INTERFACE
    } IApcControlEventsVtbl;

    interface IApcControlEvents
    {
        CONST_VTBL struct IApcControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcControlEvents_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcControlEvents_INTERFACE_DEFINED__ */


#ifndef __IApcProcedures_INTERFACE_DEFINED__
#define __IApcProcedures_INTERFACE_DEFINED__

/* interface IApcProcedures */
/* [object][hidden][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcProcedures;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BCB891AE-B732-4D87-94B3-A6E314D9DC0E")
    IApcProcedures : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcProcedure **ppProcedure) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProceduresVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProcedures * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProcedures * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProcedures * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcProcedures * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcProcedures * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcProcedures * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcProcedures * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcProcedures * This,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcProcedures * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcProcedures * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcProcedure **ppProcedure);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcProcedures * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcProcedures * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcProcedures * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcProcedures * This,
            /* [retval][out] */ IApc **ppApc);
        
        END_INTERFACE
    } IApcProceduresVtbl;

    interface IApcProcedures
    {
        CONST_VTBL struct IApcProceduresVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProcedures_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProcedures_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProcedures_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProcedures_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcProcedures_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcProcedures_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcProcedures_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcProcedures_get_Parent(This,ppProjectItem)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProjectItem) ) 

#define IApcProcedures_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcProcedures_get_Item(This,Index,ppProcedure)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppProcedure) ) 

#define IApcProcedures_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcProcedures_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcProcedures_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcProcedures_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProcedures_INTERFACE_DEFINED__ */


#ifndef __IApcProcedure_INTERFACE_DEFINED__
#define __IApcProcedure_INTERFACE_DEFINED__

/* interface IApcProcedure */
/* [object][hidden][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcProcedure;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A29E6ABE-B2C7-4FDA-987C-48629E63D383")
    IApcProcedure : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProcedures **ppProcedures) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR NewDescription) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pbstrDescription) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HostString( 
            /* [in] */ BSTR NewHostString) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HostString( 
            /* [retval][out] */ BSTR *pbstrHostString) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProcedureScope( 
            /* [out][retval] */ APCPROCEDURESCOPE *pScope) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HasParameters( 
            /* [out][retval] */ VARIANT_BOOL *pbHasParameters) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Empty( 
            /* [out][retval] */ VARIANT_BOOL *pbEmpty) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [out][retval] */ APCPROCEDURETYPE *pType) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProcKind( 
            /* [out][retval] */ APCPROCKIND *pProcKind) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StartLine( 
            /* [retval][out] */ long *pStartLine) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_EndLine( 
            /* [retval][out] */ long *pEndLine) = 0;
        
        virtual /* [vararg][helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ SAFEARRAY * *Arguments,
            /* [retval][out] */ VARIANT *pReturnValue) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ViewCode( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcProcedureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcProcedure * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcProcedure * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcProcedure * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcProcedure * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcProcedure * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcProcedure * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcProcedure * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcProcedure * This,
            /* [retval][out] */ IApcProcedures **ppProcedures);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcProcedure * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IApcProcedure * This,
            /* [in] */ BSTR NewDescription);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IApcProcedure * This,
            /* [retval][out] */ BSTR *pbstrDescription);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostString )( 
            IApcProcedure * This,
            /* [in] */ BSTR NewHostString);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostString )( 
            IApcProcedure * This,
            /* [retval][out] */ BSTR *pbstrHostString);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProcedureScope )( 
            IApcProcedure * This,
            /* [out][retval] */ APCPROCEDURESCOPE *pScope);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HasParameters )( 
            IApcProcedure * This,
            /* [out][retval] */ VARIANT_BOOL *pbHasParameters);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Empty )( 
            IApcProcedure * This,
            /* [out][retval] */ VARIANT_BOOL *pbEmpty);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IApcProcedure * This,
            /* [out][retval] */ APCPROCEDURETYPE *pType);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProcKind )( 
            IApcProcedure * This,
            /* [out][retval] */ APCPROCKIND *pProcKind);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcProcedure * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcProcedure * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcProcedure * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartLine )( 
            IApcProcedure * This,
            /* [retval][out] */ long *pStartLine);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EndLine )( 
            IApcProcedure * This,
            /* [retval][out] */ long *pEndLine);
        
        /* [vararg][helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IApcProcedure * This,
            /* [in] */ SAFEARRAY * *Arguments,
            /* [retval][out] */ VARIANT *pReturnValue);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ViewCode )( 
            IApcProcedure * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcProcedure * This);
        
        END_INTERFACE
    } IApcProcedureVtbl;

    interface IApcProcedure
    {
        CONST_VTBL struct IApcProcedureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcProcedure_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcProcedure_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcProcedure_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcProcedure_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcProcedure_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcProcedure_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcProcedure_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcProcedure_get_Parent(This,ppProcedures)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProcedures) ) 

#define IApcProcedure_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcProcedure_put_Description(This,NewDescription)	\
    ( (This)->lpVtbl -> put_Description(This,NewDescription) ) 

#define IApcProcedure_get_Description(This,pbstrDescription)	\
    ( (This)->lpVtbl -> get_Description(This,pbstrDescription) ) 

#define IApcProcedure_put_HostString(This,NewHostString)	\
    ( (This)->lpVtbl -> put_HostString(This,NewHostString) ) 

#define IApcProcedure_get_HostString(This,pbstrHostString)	\
    ( (This)->lpVtbl -> get_HostString(This,pbstrHostString) ) 

#define IApcProcedure_get_ProcedureScope(This,pScope)	\
    ( (This)->lpVtbl -> get_ProcedureScope(This,pScope) ) 

#define IApcProcedure_get_HasParameters(This,pbHasParameters)	\
    ( (This)->lpVtbl -> get_HasParameters(This,pbHasParameters) ) 

#define IApcProcedure_get_Empty(This,pbEmpty)	\
    ( (This)->lpVtbl -> get_Empty(This,pbEmpty) ) 

#define IApcProcedure_get_Type(This,pType)	\
    ( (This)->lpVtbl -> get_Type(This,pType) ) 

#define IApcProcedure_get_ProcKind(This,pProcKind)	\
    ( (This)->lpVtbl -> get_ProcKind(This,pProcKind) ) 

#define IApcProcedure_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcProcedure_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcProcedure_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcProcedure_get_StartLine(This,pStartLine)	\
    ( (This)->lpVtbl -> get_StartLine(This,pStartLine) ) 

#define IApcProcedure_get_EndLine(This,pEndLine)	\
    ( (This)->lpVtbl -> get_EndLine(This,pEndLine) ) 

#define IApcProcedure_Run(This,Arguments,pReturnValue)	\
    ( (This)->lpVtbl -> Run(This,Arguments,pReturnValue) ) 

#define IApcProcedure_ViewCode(This)	\
    ( (This)->lpVtbl -> ViewCode(This) ) 

#define IApcProcedure_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcProcedure_INTERFACE_DEFINED__ */


#ifndef __IApcCategories_INTERFACE_DEFINED__
#define __IApcCategories_INTERFACE_DEFINED__

/* interface IApcCategories */
/* [object][dual][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApcCategories;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C503BBE4-93A5-4A82-9D20-89C4B7EEC1D3")
    IApcCategories : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IDispatch **ppParent) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ short *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcCategory **ppCategory) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR PropertyName,
            /* [in] */ APCPROPERTYCATEGORY Category,
            /* [optional][in] */ BSTR CategoryName,
            /* [retval][out] */ IApcCategory **ppCategory) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcCategoriesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcCategories * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcCategories * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcCategories * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcCategories * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcCategories * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcCategories * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcCategories * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcCategories * This,
            /* [retval][out] */ IDispatch **ppParent);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcCategories * This,
            /* [retval][out] */ short *pCount);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcCategories * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcCategory **ppCategory);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcCategories * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcCategories * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcCategories * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcCategories * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcCategories * This,
            /* [in] */ BSTR PropertyName,
            /* [in] */ APCPROPERTYCATEGORY Category,
            /* [optional][in] */ BSTR CategoryName,
            /* [retval][out] */ IApcCategory **ppCategory);
        
        END_INTERFACE
    } IApcCategoriesVtbl;

    interface IApcCategories
    {
        CONST_VTBL struct IApcCategoriesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcCategories_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcCategories_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcCategories_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcCategories_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcCategories_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcCategories_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcCategories_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcCategories_get_Parent(This,ppParent)	\
    ( (This)->lpVtbl -> get_Parent(This,ppParent) ) 

#define IApcCategories_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcCategories_get_Item(This,Index,ppCategory)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppCategory) ) 

#define IApcCategories_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcCategories_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcCategories_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcCategories_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcCategories_Add(This,PropertyName,Category,CategoryName,ppCategory)	\
    ( (This)->lpVtbl -> Add(This,PropertyName,Category,CategoryName,ppCategory) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcCategories_INTERFACE_DEFINED__ */


#ifndef __IApcCategory_INTERFACE_DEFINED__
#define __IApcCategory_INTERFACE_DEFINED__

/* interface IApcCategory */
/* [object][dual][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApcCategory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76206E2A-1A11-4670-A329-E32992E31CFB")
    IApcCategory : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Category( 
            /* [retval][out] */ APCPROPERTYCATEGORY *pCategory) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CategoryName( 
            /* [retval][out] */ BSTR *pbstrCategoryName) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_DispatchID( 
            /* [retval][out] */ DISPID *pDispatchID) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcCategories **ppCategories) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcCategoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcCategory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcCategory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcCategory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcCategory * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcCategory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcCategory * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcCategory * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcCategory * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IApcCategory * This,
            /* [retval][out] */ APCPROPERTYCATEGORY *pCategory);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CategoryName )( 
            IApcCategory * This,
            /* [retval][out] */ BSTR *pbstrCategoryName);
        
        /* [helpcontext][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DispatchID )( 
            IApcCategory * This,
            /* [retval][out] */ DISPID *pDispatchID);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcCategory * This,
            /* [retval][out] */ IApcCategories **ppCategories);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcCategory * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcCategory * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcCategory * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcCategory * This);
        
        END_INTERFACE
    } IApcCategoryVtbl;

    interface IApcCategory
    {
        CONST_VTBL struct IApcCategoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcCategory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcCategory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcCategory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcCategory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcCategory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcCategory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcCategory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcCategory_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcCategory_get_Category(This,pCategory)	\
    ( (This)->lpVtbl -> get_Category(This,pCategory) ) 

#define IApcCategory_get_CategoryName(This,pbstrCategoryName)	\
    ( (This)->lpVtbl -> get_CategoryName(This,pbstrCategoryName) ) 

#define IApcCategory_get_DispatchID(This,pDispatchID)	\
    ( (This)->lpVtbl -> get_DispatchID(This,pDispatchID) ) 

#define IApcCategory_get_Parent(This,ppCategories)	\
    ( (This)->lpVtbl -> get_Parent(This,ppCategories) ) 

#define IApcCategory_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcCategory_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcCategory_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcCategory_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcCategory_INTERFACE_DEFINED__ */


#ifndef __IApcMiniBitmaps_INTERFACE_DEFINED__
#define __IApcMiniBitmaps_INTERFACE_DEFINED__

/* interface IApcMiniBitmaps */
/* [object][dual][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApcMiniBitmaps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("07AD49B3-AAEC-4101-B869-4D98C0C8EC94")
    IApcMiniBitmaps : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ short *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcMiniBitmap **ppMiniBitmap) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR ClassName,
            /* [in] */ /* external definition not present */ IPictureDisp *MiniBitmap,
            /* [defaultvalue][in] */ /* external definition not present */ OLE_COLOR BackColor,
            /* [retval][out] */ IApcMiniBitmap **ppMiniBitmap) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcMiniBitmapsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcMiniBitmaps * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcMiniBitmaps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcMiniBitmaps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcMiniBitmaps * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcMiniBitmaps * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcMiniBitmaps * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcMiniBitmaps * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcMiniBitmaps * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcMiniBitmaps * This,
            /* [retval][out] */ short *pCount);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcMiniBitmaps * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcMiniBitmap **ppMiniBitmap);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcMiniBitmaps * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcMiniBitmaps * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcMiniBitmaps * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcMiniBitmaps * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcMiniBitmaps * This,
            /* [in] */ BSTR ClassName,
            /* [in] */ /* external definition not present */ IPictureDisp *MiniBitmap,
            /* [defaultvalue][in] */ /* external definition not present */ OLE_COLOR BackColor,
            /* [retval][out] */ IApcMiniBitmap **ppMiniBitmap);
        
        END_INTERFACE
    } IApcMiniBitmapsVtbl;

    interface IApcMiniBitmaps
    {
        CONST_VTBL struct IApcMiniBitmapsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcMiniBitmaps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcMiniBitmaps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcMiniBitmaps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcMiniBitmaps_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcMiniBitmaps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcMiniBitmaps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcMiniBitmaps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcMiniBitmaps_get_Parent(This,ppApc)	\
    ( (This)->lpVtbl -> get_Parent(This,ppApc) ) 

#define IApcMiniBitmaps_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcMiniBitmaps_get_Item(This,Index,ppMiniBitmap)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppMiniBitmap) ) 

#define IApcMiniBitmaps_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcMiniBitmaps_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcMiniBitmaps_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcMiniBitmaps_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcMiniBitmaps_Add(This,ClassName,MiniBitmap,BackColor,ppMiniBitmap)	\
    ( (This)->lpVtbl -> Add(This,ClassName,MiniBitmap,BackColor,ppMiniBitmap) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcMiniBitmaps_INTERFACE_DEFINED__ */


#ifndef __IApcMiniBitmap_INTERFACE_DEFINED__
#define __IApcMiniBitmap_INTERFACE_DEFINED__

/* interface IApcMiniBitmap */
/* [object][dual][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApcMiniBitmap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19FDB89F-0DFD-49AA-B219-CEA6C48A887C")
    IApcMiniBitmap : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ /* external definition not present */ IPictureDisp **ppMiniBitMap) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcMiniBitmaps **ppMiniBitmaps) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClassName( 
            /* [retval][out] */ BSTR *pbstrClassName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pBackColor) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ /* external definition not present */ OLE_COLOR BackColor) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcMiniBitmapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcMiniBitmap * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcMiniBitmap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcMiniBitmap * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcMiniBitmap * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcMiniBitmap * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcMiniBitmap * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcMiniBitmap * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Picture )( 
            IApcMiniBitmap * This,
            /* [retval][out] */ /* external definition not present */ IPictureDisp **ppMiniBitMap);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcMiniBitmap * This,
            /* [retval][out] */ IApcMiniBitmaps **ppMiniBitmaps);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassName )( 
            IApcMiniBitmap * This,
            /* [retval][out] */ BSTR *pbstrClassName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcMiniBitmap * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcMiniBitmap * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcMiniBitmap * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IApcMiniBitmap * This,
            /* [retval][out] */ /* external definition not present */ OLE_COLOR *pBackColor);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IApcMiniBitmap * This,
            /* [in] */ /* external definition not present */ OLE_COLOR BackColor);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcMiniBitmap * This);
        
        END_INTERFACE
    } IApcMiniBitmapVtbl;

    interface IApcMiniBitmap
    {
        CONST_VTBL struct IApcMiniBitmapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcMiniBitmap_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcMiniBitmap_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcMiniBitmap_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcMiniBitmap_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcMiniBitmap_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcMiniBitmap_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcMiniBitmap_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcMiniBitmap_get_Picture(This,ppMiniBitMap)	\
    ( (This)->lpVtbl -> get_Picture(This,ppMiniBitMap) ) 

#define IApcMiniBitmap_get_Parent(This,ppMiniBitmaps)	\
    ( (This)->lpVtbl -> get_Parent(This,ppMiniBitmaps) ) 

#define IApcMiniBitmap_get_ClassName(This,pbstrClassName)	\
    ( (This)->lpVtbl -> get_ClassName(This,pbstrClassName) ) 

#define IApcMiniBitmap_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcMiniBitmap_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcMiniBitmap_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcMiniBitmap_get_BackColor(This,pBackColor)	\
    ( (This)->lpVtbl -> get_BackColor(This,pBackColor) ) 

#define IApcMiniBitmap_put_BackColor(This,BackColor)	\
    ( (This)->lpVtbl -> put_BackColor(This,BackColor) ) 

#define IApcMiniBitmap_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcMiniBitmap_INTERFACE_DEFINED__ */


#ifndef __IApcRecorder_INTERFACE_DEFINED__
#define __IApcRecorder_INTERFACE_DEFINED__

/* interface IApcRecorder */
/* [object][hidden][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcRecorder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EFE443A3-22F1-4436-AA57-1DD347AE7FE8")
    IApcRecorder : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [out][retval] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MacroName( 
            /* [out][retval] */ BSTR *pbstrMacroName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectItem( 
            /* [out][retval] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Recording( 
            /* [out][retval] */ VARIANT_BOOL *pbRecording) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Record( 
            /* [in] */ BSTR Text) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE RecordLine( 
            /* [optional][in] */ BSTR Text) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Start( 
            /* [defaultvalue][in] */ IDispatch *Destination,
            /* [optional][in] */ BSTR Name) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SetUndoMarking( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Undo( 
            /* [defaultvalue][in] */ long NumberOfLevels = 1) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_UndoCount( 
            /* [retval][out] */ long *pUndoCount) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Paused( 
            /* [out][retval] */ VARIANT_BOOL *pbPaused) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcRecorderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcRecorder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcRecorder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcRecorder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcRecorder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcRecorder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcRecorder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcRecorder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcRecorder * This,
            /* [out][retval] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MacroName )( 
            IApcRecorder * This,
            /* [out][retval] */ BSTR *pbstrMacroName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectItem )( 
            IApcRecorder * This,
            /* [out][retval] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Recording )( 
            IApcRecorder * This,
            /* [out][retval] */ VARIANT_BOOL *pbRecording);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcRecorder * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcRecorder * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcRecorder * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Record )( 
            IApcRecorder * This,
            /* [in] */ BSTR Text);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RecordLine )( 
            IApcRecorder * This,
            /* [optional][in] */ BSTR Text);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IApcRecorder * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IApcRecorder * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IApcRecorder * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IApcRecorder * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IApcRecorder * This,
            /* [defaultvalue][in] */ IDispatch *Destination,
            /* [optional][in] */ BSTR Name);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetUndoMarking )( 
            IApcRecorder * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Undo )( 
            IApcRecorder * This,
            /* [defaultvalue][in] */ long NumberOfLevels);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UndoCount )( 
            IApcRecorder * This,
            /* [retval][out] */ long *pUndoCount);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Paused )( 
            IApcRecorder * This,
            /* [out][retval] */ VARIANT_BOOL *pbPaused);
        
        END_INTERFACE
    } IApcRecorderVtbl;

    interface IApcRecorder
    {
        CONST_VTBL struct IApcRecorderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcRecorder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcRecorder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcRecorder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcRecorder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcRecorder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcRecorder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcRecorder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcRecorder_get_Parent(This,ppApc)	\
    ( (This)->lpVtbl -> get_Parent(This,ppApc) ) 

#define IApcRecorder_get_MacroName(This,pbstrMacroName)	\
    ( (This)->lpVtbl -> get_MacroName(This,pbstrMacroName) ) 

#define IApcRecorder_get_ProjectItem(This,ppProjectItem)	\
    ( (This)->lpVtbl -> get_ProjectItem(This,ppProjectItem) ) 

#define IApcRecorder_get_Recording(This,pbRecording)	\
    ( (This)->lpVtbl -> get_Recording(This,pbRecording) ) 

#define IApcRecorder_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcRecorder_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcRecorder_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcRecorder_Record(This,Text)	\
    ( (This)->lpVtbl -> Record(This,Text) ) 

#define IApcRecorder_RecordLine(This,Text)	\
    ( (This)->lpVtbl -> RecordLine(This,Text) ) 

#define IApcRecorder_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IApcRecorder_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IApcRecorder_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IApcRecorder_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define IApcRecorder_Start(This,Destination,Name)	\
    ( (This)->lpVtbl -> Start(This,Destination,Name) ) 

#define IApcRecorder_SetUndoMarking(This)	\
    ( (This)->lpVtbl -> SetUndoMarking(This) ) 

#define IApcRecorder_Undo(This,NumberOfLevels)	\
    ( (This)->lpVtbl -> Undo(This,NumberOfLevels) ) 

#define IApcRecorder_get_UndoCount(This,pUndoCount)	\
    ( (This)->lpVtbl -> get_UndoCount(This,pUndoCount) ) 

#define IApcRecorder_get_Paused(This,pbPaused)	\
    ( (This)->lpVtbl -> get_Paused(This,pbPaused) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcRecorder_INTERFACE_DEFINED__ */


#ifndef __IApcScopes_INTERFACE_DEFINED__
#define __IApcScopes_INTERFACE_DEFINED__

/* interface IApcScopes */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcScopes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2AF449CD-B830-4840-940B-C2EBEFA34761")
    IApcScopes : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcScope **ppScope) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MacrosDialog( 
            /* [retval][out] */ IApcMacrosDialog **ppMacrosDialog) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IDispatch **ppParent) = 0;
        
        virtual /* [vararg][helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR ScopeName,
            /* [in] */ SAFEARRAY * *ProjectItems,
            /* [retval][out] */ IApcScope **ppScope) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CallMacro( 
            /* [in] */ BSTR MacroName) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcScopesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcScopes * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcScopes * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcScopes * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcScopes * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcScopes * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcScopes * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcScopes * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcScopes * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcScopes * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcScopes * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcScopes * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcScope **ppScope);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MacrosDialog )( 
            IApcScopes * This,
            /* [retval][out] */ IApcMacrosDialog **ppMacrosDialog);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcScopes * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcScopes * This,
            /* [retval][out] */ IDispatch **ppParent);
        
        /* [vararg][helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcScopes * This,
            /* [in] */ BSTR ScopeName,
            /* [in] */ SAFEARRAY * *ProjectItems,
            /* [retval][out] */ IApcScope **ppScope);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CallMacro )( 
            IApcScopes * This,
            /* [in] */ BSTR MacroName);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcScopes * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        END_INTERFACE
    } IApcScopesVtbl;

    interface IApcScopes
    {
        CONST_VTBL struct IApcScopesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcScopes_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcScopes_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcScopes_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcScopes_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcScopes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcScopes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcScopes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcScopes_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcScopes_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcScopes_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcScopes_get_Item(This,Index,ppScope)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppScope) ) 

#define IApcScopes_get_MacrosDialog(This,ppMacrosDialog)	\
    ( (This)->lpVtbl -> get_MacrosDialog(This,ppMacrosDialog) ) 

#define IApcScopes_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcScopes_get_Parent(This,ppParent)	\
    ( (This)->lpVtbl -> get_Parent(This,ppParent) ) 

#define IApcScopes_Add(This,ScopeName,ProjectItems,ppScope)	\
    ( (This)->lpVtbl -> Add(This,ScopeName,ProjectItems,ppScope) ) 

#define IApcScopes_CallMacro(This,MacroName)	\
    ( (This)->lpVtbl -> CallMacro(This,MacroName) ) 

#define IApcScopes_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcScopes_INTERFACE_DEFINED__ */


#ifndef __IApcScope_INTERFACE_DEFINED__
#define __IApcScope_INTERFACE_DEFINED__

/* interface IApcScope */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcScope;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4E8F8FD8-C956-4243-8570-4EE040B4A683")
    IApcScope : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR NewName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectItems( 
            /* [retval][out] */ IDispatch **ppProjectItems) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ProjectItems( 
            /* [in] */ IDispatch *pProjectItems) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcScopes **ppScopes) = 0;
        
        virtual /* [helpcontext][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_ProjectItems( 
            /* [in] */ IDispatch *pProjectItems) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcScopeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcScope * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcScope * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcScope * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcScope * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcScope * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcScope * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcScope * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcScope * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IApcScope * This,
            /* [in] */ BSTR NewName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectItems )( 
            IApcScope * This,
            /* [retval][out] */ IDispatch **ppProjectItems);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProjectItems )( 
            IApcScope * This,
            /* [in] */ IDispatch *pProjectItems);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcScope * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcScope * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcScope * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcScope * This,
            /* [retval][out] */ IApcScopes **ppScopes);
        
        /* [helpcontext][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_ProjectItems )( 
            IApcScope * This,
            /* [in] */ IDispatch *pProjectItems);
        
        END_INTERFACE
    } IApcScopeVtbl;

    interface IApcScope
    {
        CONST_VTBL struct IApcScopeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcScope_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcScope_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcScope_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcScope_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcScope_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcScope_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcScope_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcScope_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcScope_put_Name(This,NewName)	\
    ( (This)->lpVtbl -> put_Name(This,NewName) ) 

#define IApcScope_get_ProjectItems(This,ppProjectItems)	\
    ( (This)->lpVtbl -> get_ProjectItems(This,ppProjectItems) ) 

#define IApcScope_put_ProjectItems(This,pProjectItems)	\
    ( (This)->lpVtbl -> put_ProjectItems(This,pProjectItems) ) 

#define IApcScope_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcScope_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcScope_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcScope_get_Parent(This,ppScopes)	\
    ( (This)->lpVtbl -> get_Parent(This,ppScopes) ) 

#define IApcScope_putref_ProjectItems(This,pProjectItems)	\
    ( (This)->lpVtbl -> putref_ProjectItems(This,pProjectItems) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcScope_INTERFACE_DEFINED__ */


#ifndef __IApcMacrosDialog_INTERFACE_DEFINED__
#define __IApcMacrosDialog_INTERFACE_DEFINED__

/* interface IApcMacrosDialog */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcMacrosDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B588B4E-2880-4F10-ACB2-6C98FED07DC9")
    IApcMacrosDialog : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DialogTitle( 
            /* [retval][out] */ BSTR *pbstrTitle) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DialogTitle( 
            /* [in] */ BSTR NewDialogTitle) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HelpFile( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HelpFile( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HelpContextID( 
            /* [retval][out] */ long *pContextID) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HelpContextID( 
            /* [in] */ long ContextID) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcScopes **ppParent) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ long Left) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ long *pLeft) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ long Top) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ long *pTop) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_StartUpPosition( 
            /* [in] */ APCDIALOGSTARTUPPOSITION Position) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_StartUpPosition( 
            /* [retval][out] */ APCDIALOGSTARTUPPOSITION *pPosition) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ParentWindow( 
            /* [retval][out] */ long *phWnd) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ParentWindow( 
            /* [in] */ long hWnd) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcMacrosDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcMacrosDialog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcMacrosDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcMacrosDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcMacrosDialog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcMacrosDialog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcMacrosDialog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcMacrosDialog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DialogTitle )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ BSTR *pbstrTitle);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DialogTitle )( 
            IApcMacrosDialog * This,
            /* [in] */ BSTR NewDialogTitle);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpFile )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HelpFile )( 
            IApcMacrosDialog * This,
            /* [in] */ BSTR FileName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpContextID )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ long *pContextID);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HelpContextID )( 
            IApcMacrosDialog * This,
            /* [in] */ long ContextID);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcMacrosDialog * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ IApcScopes **ppParent);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IApcMacrosDialog * This,
            /* [in] */ long Left);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ long *pLeft);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IApcMacrosDialog * This,
            /* [in] */ long Top);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ long *pTop);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartUpPosition )( 
            IApcMacrosDialog * This,
            /* [in] */ APCDIALOGSTARTUPPOSITION Position);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartUpPosition )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ APCDIALOGSTARTUPPOSITION *pPosition);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentWindow )( 
            IApcMacrosDialog * This,
            /* [retval][out] */ long *phWnd);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ParentWindow )( 
            IApcMacrosDialog * This,
            /* [in] */ long hWnd);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IApcMacrosDialog * This);
        
        END_INTERFACE
    } IApcMacrosDialogVtbl;

    interface IApcMacrosDialog
    {
        CONST_VTBL struct IApcMacrosDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcMacrosDialog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcMacrosDialog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcMacrosDialog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcMacrosDialog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcMacrosDialog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcMacrosDialog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcMacrosDialog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcMacrosDialog_get_DialogTitle(This,pbstrTitle)	\
    ( (This)->lpVtbl -> get_DialogTitle(This,pbstrTitle) ) 

#define IApcMacrosDialog_put_DialogTitle(This,NewDialogTitle)	\
    ( (This)->lpVtbl -> put_DialogTitle(This,NewDialogTitle) ) 

#define IApcMacrosDialog_get_HelpFile(This,pbstrName)	\
    ( (This)->lpVtbl -> get_HelpFile(This,pbstrName) ) 

#define IApcMacrosDialog_put_HelpFile(This,FileName)	\
    ( (This)->lpVtbl -> put_HelpFile(This,FileName) ) 

#define IApcMacrosDialog_get_HelpContextID(This,pContextID)	\
    ( (This)->lpVtbl -> get_HelpContextID(This,pContextID) ) 

#define IApcMacrosDialog_put_HelpContextID(This,ContextID)	\
    ( (This)->lpVtbl -> put_HelpContextID(This,ContextID) ) 

#define IApcMacrosDialog_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcMacrosDialog_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcMacrosDialog_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcMacrosDialog_get_Parent(This,ppParent)	\
    ( (This)->lpVtbl -> get_Parent(This,ppParent) ) 

#define IApcMacrosDialog_put_Left(This,Left)	\
    ( (This)->lpVtbl -> put_Left(This,Left) ) 

#define IApcMacrosDialog_get_Left(This,pLeft)	\
    ( (This)->lpVtbl -> get_Left(This,pLeft) ) 

#define IApcMacrosDialog_put_Top(This,Top)	\
    ( (This)->lpVtbl -> put_Top(This,Top) ) 

#define IApcMacrosDialog_get_Top(This,pTop)	\
    ( (This)->lpVtbl -> get_Top(This,pTop) ) 

#define IApcMacrosDialog_put_StartUpPosition(This,Position)	\
    ( (This)->lpVtbl -> put_StartUpPosition(This,Position) ) 

#define IApcMacrosDialog_get_StartUpPosition(This,pPosition)	\
    ( (This)->lpVtbl -> get_StartUpPosition(This,pPosition) ) 

#define IApcMacrosDialog_get_ParentWindow(This,phWnd)	\
    ( (This)->lpVtbl -> get_ParentWindow(This,phWnd) ) 

#define IApcMacrosDialog_put_ParentWindow(This,hWnd)	\
    ( (This)->lpVtbl -> put_ParentWindow(This,hWnd) ) 

#define IApcMacrosDialog_Show(This)	\
    ( (This)->lpVtbl -> Show(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcMacrosDialog_INTERFACE_DEFINED__ */


#ifndef __IApcStorage_INTERFACE_DEFINED__
#define __IApcStorage_INTERFACE_DEFINED__

/* interface IApcStorage */
/* [object][dual][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApcStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EFC1E36E-2C0D-4B4F-BDD3-20B049267D7C")
    IApcStorage : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_CreationDate( 
            /* [retval][out] */ DATE *pDate) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LastModifiedDate( 
            /* [retval][out] */ DATE *pDate) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IDispatch **ppParent) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_IStorage( 
            /* [retval][out] */ IUnknown **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Storages( 
            /* [retval][out] */ VARIANT *pStorages) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Streams( 
            /* [retval][out] */ VARIANT *pStreams) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_InMemoryStorageBytes( 
            /* [retval][out] */ VARIANT *pBytes) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SetCreationDate( 
            /* [in] */ BSTR Name,
            /* [in] */ DATE Date) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE SetLastModifiedDate( 
            /* [in] */ BSTR Name,
            /* [in] */ DATE Date) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CreateStream( 
            /* [in] */ BSTR StreamName,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStream **ppStream) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE OpenStream( 
            /* [in] */ BSTR StreamName,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStream **ppStream) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CreateStorage( 
            /* [in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE OpenStorage( 
            /* [in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ BSTR Name,
            /* [in] */ IApcStorage *DestinationStorage,
            /* [optional][in] */ BSTR NewStorageName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [optional][in] */ BSTR Name) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ BSTR Name,
            /* [in] */ IApcStorage *DestinationStorage,
            /* [optional][in] */ BSTR NewName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Commit( 
            /* [defaultvalue][in] */ VARIANT_BOOL ForceCommit = FALSE) = 0;
        
        virtual /* [helpcontext][helpstring][hidden] */ HRESULT STDMETHODCALLTYPE Rollback( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ BSTR OldName,
            /* [in] */ BSTR NewName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcStorage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcStorage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcStorage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcStorage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcStorage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcStorage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcStorage * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationDate )( 
            IApcStorage * This,
            /* [retval][out] */ DATE *pDate);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModifiedDate )( 
            IApcStorage * This,
            /* [retval][out] */ DATE *pDate);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcStorage * This,
            /* [retval][out] */ IDispatch **ppParent);
        
        /* [helpcontext][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IStorage )( 
            IApcStorage * This,
            /* [retval][out] */ IUnknown **ppStorage);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Storages )( 
            IApcStorage * This,
            /* [retval][out] */ VARIANT *pStorages);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Streams )( 
            IApcStorage * This,
            /* [retval][out] */ VARIANT *pStreams);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InMemoryStorageBytes )( 
            IApcStorage * This,
            /* [retval][out] */ VARIANT *pBytes);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcStorage * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcStorage * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCreationDate )( 
            IApcStorage * This,
            /* [in] */ BSTR Name,
            /* [in] */ DATE Date);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLastModifiedDate )( 
            IApcStorage * This,
            /* [in] */ BSTR Name,
            /* [in] */ DATE Date);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateStream )( 
            IApcStorage * This,
            /* [in] */ BSTR StreamName,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStream **ppStream);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenStream )( 
            IApcStorage * This,
            /* [in] */ BSTR StreamName,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStream **ppStream);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateStorage )( 
            IApcStorage * This,
            /* [in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenStorage )( 
            IApcStorage * This,
            /* [in] */ BSTR Name,
            /* [defaultvalue][in] */ APCACCESSMODE AccessMode,
            /* [retval][out] */ IApcStorage **ppStorage);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IApcStorage * This,
            /* [in] */ BSTR Name,
            /* [in] */ IApcStorage *DestinationStorage,
            /* [optional][in] */ BSTR NewStorageName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcStorage * This,
            /* [optional][in] */ BSTR Name);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IApcStorage * This,
            /* [in] */ BSTR Name,
            /* [in] */ IApcStorage *DestinationStorage,
            /* [optional][in] */ BSTR NewName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IApcStorage * This,
            /* [defaultvalue][in] */ VARIANT_BOOL ForceCommit);
        
        /* [helpcontext][helpstring][hidden] */ HRESULT ( STDMETHODCALLTYPE *Rollback )( 
            IApcStorage * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IApcStorage * This,
            /* [in] */ BSTR OldName,
            /* [in] */ BSTR NewName);
        
        END_INTERFACE
    } IApcStorageVtbl;

    interface IApcStorage
    {
        CONST_VTBL struct IApcStorageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcStorage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcStorage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcStorage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcStorage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcStorage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcStorage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcStorage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcStorage_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcStorage_get_CreationDate(This,pDate)	\
    ( (This)->lpVtbl -> get_CreationDate(This,pDate) ) 

#define IApcStorage_get_LastModifiedDate(This,pDate)	\
    ( (This)->lpVtbl -> get_LastModifiedDate(This,pDate) ) 

#define IApcStorage_get_Parent(This,ppParent)	\
    ( (This)->lpVtbl -> get_Parent(This,ppParent) ) 

#define IApcStorage_get_IStorage(This,ppStorage)	\
    ( (This)->lpVtbl -> get_IStorage(This,ppStorage) ) 

#define IApcStorage_get_Storages(This,pStorages)	\
    ( (This)->lpVtbl -> get_Storages(This,pStorages) ) 

#define IApcStorage_get_Streams(This,pStreams)	\
    ( (This)->lpVtbl -> get_Streams(This,pStreams) ) 

#define IApcStorage_get_InMemoryStorageBytes(This,pBytes)	\
    ( (This)->lpVtbl -> get_InMemoryStorageBytes(This,pBytes) ) 

#define IApcStorage_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcStorage_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcStorage_SetCreationDate(This,Name,Date)	\
    ( (This)->lpVtbl -> SetCreationDate(This,Name,Date) ) 

#define IApcStorage_SetLastModifiedDate(This,Name,Date)	\
    ( (This)->lpVtbl -> SetLastModifiedDate(This,Name,Date) ) 

#define IApcStorage_CreateStream(This,StreamName,AccessMode,ppStream)	\
    ( (This)->lpVtbl -> CreateStream(This,StreamName,AccessMode,ppStream) ) 

#define IApcStorage_OpenStream(This,StreamName,AccessMode,ppStream)	\
    ( (This)->lpVtbl -> OpenStream(This,StreamName,AccessMode,ppStream) ) 

#define IApcStorage_CreateStorage(This,Name,AccessMode,ppStorage)	\
    ( (This)->lpVtbl -> CreateStorage(This,Name,AccessMode,ppStorage) ) 

#define IApcStorage_OpenStorage(This,Name,AccessMode,ppStorage)	\
    ( (This)->lpVtbl -> OpenStorage(This,Name,AccessMode,ppStorage) ) 

#define IApcStorage_Copy(This,Name,DestinationStorage,NewStorageName)	\
    ( (This)->lpVtbl -> Copy(This,Name,DestinationStorage,NewStorageName) ) 

#define IApcStorage_Delete(This,Name)	\
    ( (This)->lpVtbl -> Delete(This,Name) ) 

#define IApcStorage_Move(This,Name,DestinationStorage,NewName)	\
    ( (This)->lpVtbl -> Move(This,Name,DestinationStorage,NewName) ) 

#define IApcStorage_Commit(This,ForceCommit)	\
    ( (This)->lpVtbl -> Commit(This,ForceCommit) ) 

#define IApcStorage_Rollback(This)	\
    ( (This)->lpVtbl -> Rollback(This) ) 

#define IApcStorage_Rename(This,OldName,NewName)	\
    ( (This)->lpVtbl -> Rename(This,OldName,NewName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcStorage_INTERFACE_DEFINED__ */


#ifndef __IApcStream_INTERFACE_DEFINED__
#define __IApcStream_INTERFACE_DEFINED__

/* interface IApcStream */
/* [object][dual][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApcStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71AC2124-550D-4B5A-8DD6-D6DDB57680D9")
    IApcStream : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ long *pSize) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcStorage **ppStorage) = 0;
        
        virtual /* [helpcontext][helpstring][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_IStream( 
            /* [retval][out] */ IUnknown **ppStream) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Position( 
            /* [in] */ long SeekPosition) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Position( 
            /* [retval][out] */ long *pSeekPosition) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Get( 
            /* [retval][out] */ VARIANT *pData) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Put( 
            /* [in] */ VARIANT *Value) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ IApcStream *DestinationStream) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ IApcStream **ppClonedStream) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcStream * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcStream * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcStream * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IApcStream * This,
            /* [retval][out] */ long *pSize);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcStream * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcStream * This,
            /* [retval][out] */ IApcStorage **ppStorage);
        
        /* [helpcontext][helpstring][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IStream )( 
            IApcStream * This,
            /* [retval][out] */ IUnknown **ppStream);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Position )( 
            IApcStream * This,
            /* [in] */ long SeekPosition);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Position )( 
            IApcStream * This,
            /* [retval][out] */ long *pSeekPosition);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcStream * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcStream * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Get )( 
            IApcStream * This,
            /* [retval][out] */ VARIANT *pData);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Put )( 
            IApcStream * This,
            /* [in] */ VARIANT *Value);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IApcStream * This,
            /* [in] */ IApcStream *DestinationStream);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IApcStream * This,
            /* [retval][out] */ IApcStream **ppClonedStream);
        
        END_INTERFACE
    } IApcStreamVtbl;

    interface IApcStream
    {
        CONST_VTBL struct IApcStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcStream_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcStream_get_Size(This,pSize)	\
    ( (This)->lpVtbl -> get_Size(This,pSize) ) 

#define IApcStream_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IApcStream_get_Parent(This,ppStorage)	\
    ( (This)->lpVtbl -> get_Parent(This,ppStorage) ) 

#define IApcStream_get_IStream(This,ppStream)	\
    ( (This)->lpVtbl -> get_IStream(This,ppStream) ) 

#define IApcStream_put_Position(This,SeekPosition)	\
    ( (This)->lpVtbl -> put_Position(This,SeekPosition) ) 

#define IApcStream_get_Position(This,pSeekPosition)	\
    ( (This)->lpVtbl -> get_Position(This,pSeekPosition) ) 

#define IApcStream_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcStream_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcStream_Get(This,pData)	\
    ( (This)->lpVtbl -> Get(This,pData) ) 

#define IApcStream_Put(This,Value)	\
    ( (This)->lpVtbl -> Put(This,Value) ) 

#define IApcStream_Copy(This,DestinationStream)	\
    ( (This)->lpVtbl -> Copy(This,DestinationStream) ) 

#define IApcStream_Clone(This,ppClonedStream)	\
    ( (This)->lpVtbl -> Clone(This,ppClonedStream) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcStream_INTERFACE_DEFINED__ */


#ifndef __IApcRequiredClasses_INTERFACE_DEFINED__
#define __IApcRequiredClasses_INTERFACE_DEFINED__

/* interface IApcRequiredClasses */
/* [object][dual][nonextensible][oleautomation][restricted][uuid] */ 


EXTERN_C const IID IID_IApcRequiredClasses;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("095CE45C-DFD0-450F-A373-4EB42BFD5B33")
    IApcRequiredClasses : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByClsid( 
            /* [in] */ REFCLSID clsid,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR Clsid,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE _Add( 
            /* [in] */ REFCLSID Clsid,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcRequiredClassesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcRequiredClasses * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcRequiredClasses * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcRequiredClasses * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcRequiredClasses * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcRequiredClasses * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcRequiredClasses * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcRequiredClasses * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcRequiredClasses * This,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcRequiredClasses * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcRequiredClasses * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcRequiredClasses * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcRequiredClasses * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByClsid )( 
            IApcRequiredClasses * This,
            /* [in] */ REFCLSID clsid,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcRequiredClasses * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcRequiredClasses * This,
            /* [in] */ BSTR Clsid,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *_Add )( 
            IApcRequiredClasses * This,
            /* [in] */ REFCLSID Clsid,
            /* [retval][out] */ IApcRequiredClass **ppRequiredClass);
        
        END_INTERFACE
    } IApcRequiredClassesVtbl;

    interface IApcRequiredClasses
    {
        CONST_VTBL struct IApcRequiredClassesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcRequiredClasses_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcRequiredClasses_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcRequiredClasses_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcRequiredClasses_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcRequiredClasses_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcRequiredClasses_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcRequiredClasses_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcRequiredClasses_get_Parent(This,ppProjectItem)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProjectItem) ) 

#define IApcRequiredClasses_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcRequiredClasses_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcRequiredClasses_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcRequiredClasses_get_Item(This,Index,ppRequiredClass)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppRequiredClass) ) 

#define IApcRequiredClasses_get_ItemByClsid(This,clsid,ppRequiredClass)	\
    ( (This)->lpVtbl -> get_ItemByClsid(This,clsid,ppRequiredClass) ) 

#define IApcRequiredClasses_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcRequiredClasses_Add(This,Clsid,ppRequiredClass)	\
    ( (This)->lpVtbl -> Add(This,Clsid,ppRequiredClass) ) 

#define IApcRequiredClasses__Add(This,Clsid,ppRequiredClass)	\
    ( (This)->lpVtbl -> _Add(This,Clsid,ppRequiredClass) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcRequiredClasses_INTERFACE_DEFINED__ */


#ifndef __IApcRequiredClass_INTERFACE_DEFINED__
#define __IApcRequiredClass_INTERFACE_DEFINED__

/* interface IApcRequiredClass */
/* [object][dual][nonextensible][oleautomation][restricted][uuid] */ 


EXTERN_C const IID IID_IApcRequiredClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1F05FD72-DEE1-4D32-A8B1-ED2D1EE454A6")
    IApcRequiredClass : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcRequiredClasses **ppRequiredClasses) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ClassObject( 
            /* [retval][out] */ IUnknown **ppClassFactory) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_TypeLibrary( 
            /* [retval][out] */ IUnknown **ppTypeLibrary) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ REFIID riid,
            /* [defaultvalue][in] */ IUnknown *pOuter,
            /* [retval][out] */ void **ppObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcRequiredClassVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcRequiredClass * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcRequiredClass * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcRequiredClass * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcRequiredClass * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcRequiredClass * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcRequiredClass * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcRequiredClass * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcRequiredClass * This,
            /* [retval][out] */ IApcRequiredClasses **ppRequiredClasses);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassObject )( 
            IApcRequiredClass * This,
            /* [retval][out] */ IUnknown **ppClassFactory);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TypeLibrary )( 
            IApcRequiredClass * This,
            /* [retval][out] */ IUnknown **ppTypeLibrary);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcRequiredClass * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcRequiredClass * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcRequiredClass * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IApcRequiredClass * This,
            /* [in] */ REFIID riid,
            /* [defaultvalue][in] */ IUnknown *pOuter,
            /* [retval][out] */ void **ppObject);
        
        END_INTERFACE
    } IApcRequiredClassVtbl;

    interface IApcRequiredClass
    {
        CONST_VTBL struct IApcRequiredClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcRequiredClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcRequiredClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcRequiredClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcRequiredClass_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcRequiredClass_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcRequiredClass_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcRequiredClass_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcRequiredClass_get_Parent(This,ppRequiredClasses)	\
    ( (This)->lpVtbl -> get_Parent(This,ppRequiredClasses) ) 

#define IApcRequiredClass_get_ClassObject(This,ppClassFactory)	\
    ( (This)->lpVtbl -> get_ClassObject(This,ppClassFactory) ) 

#define IApcRequiredClass_get_TypeLibrary(This,ppTypeLibrary)	\
    ( (This)->lpVtbl -> get_TypeLibrary(This,ppTypeLibrary) ) 

#define IApcRequiredClass_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcRequiredClass_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcRequiredClass_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IApcRequiredClass_Create(This,riid,pOuter,ppObject)	\
    ( (This)->lpVtbl -> Create(This,riid,pOuter,ppObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcRequiredClass_INTERFACE_DEFINED__ */


#ifndef __IApcExtender_INTERFACE_DEFINED__
#define __IApcExtender_INTERFACE_DEFINED__

/* interface IApcExtender */
/* [object][hidden][uuid] */ 


EXTERN_C const IID IID_IApcExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EAB38D5B-26DC-11D2-98C0-00104B24170B")
    IApcExtender : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out][retval] */ BSTR *pbstr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [out][retval] */ IUnknown **ppunk) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [out][retval] */ IUnknown **ppunk) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE Index( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcExtender * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcExtender * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcExtender * This,
            /* [out][retval] */ BSTR *pbstr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IApcExtender * This,
            /* [in] */ BSTR bstrName);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IApcExtender * This,
            /* [out][retval] */ IUnknown **ppunk);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcExtender * This,
            /* [out][retval] */ IUnknown **ppunk);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcExtender * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Index )( 
            IApcExtender * This);
        
        END_INTERFACE
    } IApcExtenderVtbl;

    interface IApcExtender
    {
        CONST_VTBL struct IApcExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcExtender_get_Name(This,pbstr)	\
    ( (This)->lpVtbl -> get_Name(This,pbstr) ) 

#define IApcExtender_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IApcExtender_get_Object(This,ppunk)	\
    ( (This)->lpVtbl -> get_Object(This,ppunk) ) 

#define IApcExtender_get_Parent(This,ppunk)	\
    ( (This)->lpVtbl -> get_Parent(This,ppunk) ) 

#define IApcExtender_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IApcExtender_Index(This)	\
    ( (This)->lpVtbl -> Index(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcExtender_INTERFACE_DEFINED__ */


#ifndef __IApcSite_INTERFACE_DEFINED__
#define __IApcSite_INTERFACE_DEFINED__

/* interface IApcSite */
/* [object][local][restricted][uuid] */ 


EXTERN_C const IID IID_IApcSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("034770A9-662A-4F77-9EA6-36E1D83002AA")
    IApcSite : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE ContinueIdle( 
            BOOL *pbContinue) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE DoIdle( void) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE EnterModalState( void) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE LeaveModalState( void) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE LostActivation( void) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE PushMessageLoop( 
            APCLOOPREASON LoopReason,
            BOOL *pbAborted) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE ShutDown( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcSite * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcSite * This);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *ContinueIdle )( 
            IApcSite * This,
            BOOL *pbContinue);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *DoIdle )( 
            IApcSite * This);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *EnterModalState )( 
            IApcSite * This);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *LeaveModalState )( 
            IApcSite * This);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *LostActivation )( 
            IApcSite * This);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *PushMessageLoop )( 
            IApcSite * This,
            APCLOOPREASON LoopReason,
            BOOL *pbAborted);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *ShutDown )( 
            IApcSite * This);
        
        END_INTERFACE
    } IApcSiteVtbl;

    interface IApcSite
    {
        CONST_VTBL struct IApcSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcSite_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcSite_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcSite_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcSite_ContinueIdle(This,pbContinue)	\
    ( (This)->lpVtbl -> ContinueIdle(This,pbContinue) ) 

#define IApcSite_DoIdle(This)	\
    ( (This)->lpVtbl -> DoIdle(This) ) 

#define IApcSite_EnterModalState(This)	\
    ( (This)->lpVtbl -> EnterModalState(This) ) 

#define IApcSite_LeaveModalState(This)	\
    ( (This)->lpVtbl -> LeaveModalState(This) ) 

#define IApcSite_LostActivation(This)	\
    ( (This)->lpVtbl -> LostActivation(This) ) 

#define IApcSite_PushMessageLoop(This,LoopReason,pbAborted)	\
    ( (This)->lpVtbl -> PushMessageLoop(This,LoopReason,pbAborted) ) 

#define IApcSite_ShutDown(This)	\
    ( (This)->lpVtbl -> ShutDown(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcSite_INTERFACE_DEFINED__ */


#ifndef __IApcCompManager_INTERFACE_DEFINED__
#define __IApcCompManager_INTERFACE_DEFINED__

/* interface IApcCompManager */
/* [object][dual][local][nonextensible][oleautomation][restricted][uuid] */ 


EXTERN_C const IID IID_IApcCompManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("16FEF95A-31F8-4C5B-85E7-349F2F354689")
    IApcCompManager : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_ModalState( 
            /* [retval][out] */ BOOL *pbModalState) = 0;
        
        virtual /* [helpcontext][helpstring][restricted][propput] */ HRESULT STDMETHODCALLTYPE put_ModalState( 
            /* [in] */ BOOL bModalState) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE DoIdle( 
            /* [in] */ APCIDLEFLAG IdleFlag,
            /* [retval][out] */ BOOL *pbContinue) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE ContinueMessageLoop( 
            /* [in] */ BOOL bPushedByHost,
            /* [retval][out] */ BOOL *pbContinue) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE HostActivate( void) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE WaitForMessage( void) = 0;
        
        virtual /* [helpcontext][helpstring][restricted] */ HRESULT STDMETHODCALLTYPE PreTranslateMessage( 
            /* [in] */ void *pMsg,
            /* [retval][out] */ BOOL *pbConsumed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcCompManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcCompManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcCompManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcCompManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcCompManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcCompManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcCompManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcCompManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ModalState )( 
            IApcCompManager * This,
            /* [retval][out] */ BOOL *pbModalState);
        
        /* [helpcontext][helpstring][restricted][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ModalState )( 
            IApcCompManager * This,
            /* [in] */ BOOL bModalState);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *DoIdle )( 
            IApcCompManager * This,
            /* [in] */ APCIDLEFLAG IdleFlag,
            /* [retval][out] */ BOOL *pbContinue);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *ContinueMessageLoop )( 
            IApcCompManager * This,
            /* [in] */ BOOL bPushedByHost,
            /* [retval][out] */ BOOL *pbContinue);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *HostActivate )( 
            IApcCompManager * This);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *WaitForMessage )( 
            IApcCompManager * This);
        
        /* [helpcontext][helpstring][restricted] */ HRESULT ( STDMETHODCALLTYPE *PreTranslateMessage )( 
            IApcCompManager * This,
            /* [in] */ void *pMsg,
            /* [retval][out] */ BOOL *pbConsumed);
        
        END_INTERFACE
    } IApcCompManagerVtbl;

    interface IApcCompManager
    {
        CONST_VTBL struct IApcCompManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcCompManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcCompManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcCompManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcCompManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcCompManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcCompManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcCompManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcCompManager_get_ModalState(This,pbModalState)	\
    ( (This)->lpVtbl -> get_ModalState(This,pbModalState) ) 

#define IApcCompManager_put_ModalState(This,bModalState)	\
    ( (This)->lpVtbl -> put_ModalState(This,bModalState) ) 

#define IApcCompManager_DoIdle(This,IdleFlag,pbContinue)	\
    ( (This)->lpVtbl -> DoIdle(This,IdleFlag,pbContinue) ) 

#define IApcCompManager_ContinueMessageLoop(This,bPushedByHost,pbContinue)	\
    ( (This)->lpVtbl -> ContinueMessageLoop(This,bPushedByHost,pbContinue) ) 

#define IApcCompManager_HostActivate(This)	\
    ( (This)->lpVtbl -> HostActivate(This) ) 

#define IApcCompManager_WaitForMessage(This)	\
    ( (This)->lpVtbl -> WaitForMessage(This) ) 

#define IApcCompManager_PreTranslateMessage(This,pMsg,pbConsumed)	\
    ( (This)->lpVtbl -> PreTranslateMessage(This,pMsg,pbConsumed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcCompManager_INTERFACE_DEFINED__ */


#ifndef __IApcInstances_INTERFACE_DEFINED__
#define __IApcInstances_INTERFACE_DEFINED__

/* interface IApcInstances */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcInstances;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("89EB6752-D31A-4C33-B3E8-3871C3364145")
    IApcInstances : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IApcProjectItem **ppProjectItem) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch **ppInstance) = 0;
        
        virtual /* [id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultInstance( 
            /* [retval][out] */ IDispatch **ppInstance) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT UserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pUserTag) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Apc( 
            /* [retval][out] */ IApc **ppApc) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ResetDefaultInstance( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [defaultvalue][in] */ VARIANT_BOOL DefaultInstance,
            /* [defaultvalue][in] */ IDispatch *Reserved,
            /* [retval][out] */ IDispatch **ppInstance) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcInstancesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcInstances * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcInstances * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcInstances * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcInstances * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcInstances * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcInstances * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcInstances * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcInstances * This,
            /* [retval][out] */ IApcProjectItem **ppProjectItem);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IApcInstances * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IApcInstances * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IDispatch **ppInstance);
        
        /* [id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewEnum )( 
            IApcInstances * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultInstance )( 
            IApcInstances * This,
            /* [retval][out] */ IDispatch **ppInstance);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IApcInstances * This,
            /* [in] */ VARIANT UserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IApcInstances * This,
            /* [retval][out] */ VARIANT *pUserTag);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Apc )( 
            IApcInstances * This,
            /* [retval][out] */ IApc **ppApc);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResetDefaultInstance )( 
            IApcInstances * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcInstances * This,
            /* [defaultvalue][in] */ VARIANT_BOOL DefaultInstance,
            /* [defaultvalue][in] */ IDispatch *Reserved,
            /* [retval][out] */ IDispatch **ppInstance);
        
        END_INTERFACE
    } IApcInstancesVtbl;

    interface IApcInstances
    {
        CONST_VTBL struct IApcInstancesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcInstances_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcInstances_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcInstances_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcInstances_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcInstances_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcInstances_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcInstances_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcInstances_get_Parent(This,ppProjectItem)	\
    ( (This)->lpVtbl -> get_Parent(This,ppProjectItem) ) 

#define IApcInstances_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IApcInstances_get_Item(This,Index,ppInstance)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppInstance) ) 

#define IApcInstances_get_NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get_NewEnum(This,ppUnk) ) 

#define IApcInstances_get_DefaultInstance(This,ppInstance)	\
    ( (This)->lpVtbl -> get_DefaultInstance(This,ppInstance) ) 

#define IApcInstances_put_Tag(This,UserTag)	\
    ( (This)->lpVtbl -> put_Tag(This,UserTag) ) 

#define IApcInstances_get_Tag(This,pUserTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pUserTag) ) 

#define IApcInstances_get_Apc(This,ppApc)	\
    ( (This)->lpVtbl -> get_Apc(This,ppApc) ) 

#define IApcInstances_ResetDefaultInstance(This)	\
    ( (This)->lpVtbl -> ResetDefaultInstance(This) ) 

#define IApcInstances_Add(This,DefaultInstance,Reserved,ppInstance)	\
    ( (This)->lpVtbl -> Add(This,DefaultInstance,Reserved,ppInstance) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcInstances_INTERFACE_DEFINED__ */


#ifndef __IApcHostAddIns_INTERFACE_DEFINED__
#define __IApcHostAddIns_INTERFACE_DEFINED__

/* interface IApcHostAddIns */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcHostAddIns;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1ACC518-41B3-4201-A15D-C5C05089FB7D")
    IApcHostAddIns : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AddIns( 
            /* [retval][out] */ IDispatch **ppAddIns) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_LicenseKey( 
            /* [in] */ BSTR Key) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_LicenseKey( 
            /* [retval][out] */ BSTR *pbstrKey) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_RegistryPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RegistryPath( 
            /* [retval][out] */ BSTR *pbstrPath) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_RemoveOnFailure( 
            /* [in] */ VARIANT_BOOL Remove) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_RemoveOnFailure( 
            /* [retval][out] */ VARIANT_BOOL *pbRemove) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HostObject( 
            /* [in] */ IDispatch *pHostObject) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HostObject( 
            /* [retval][out] */ IDispatch **ppHostObject) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DisableOnStartup( 
            /* [in] */ VARIANT_BOOL Disabled) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DisableOnStartup( 
            /* [retval][out] */ VARIANT_BOOL *pbDisabled) = 0;
        
        virtual /* [helpcontext][helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Locale( 
            /* [in] */ long lcidHost) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Locale( 
            /* [retval][out] */ long *plcidHost) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE LoadHostAddIns( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE NotifyBeginShutdown( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE NotifyStartupComplete( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ShowAddInsDialog( void) = 0;
        
        virtual /* [helpcontext][helpstring][propputref] */ HRESULT STDMETHODCALLTYPE putref_HostObject( 
            /* [in] */ IDispatch *pHostObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcHostAddInsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcHostAddIns * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcHostAddIns * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcHostAddIns * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcHostAddIns * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcHostAddIns * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcHostAddIns * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcHostAddIns * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddIns )( 
            IApcHostAddIns * This,
            /* [retval][out] */ IDispatch **ppAddIns);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LicenseKey )( 
            IApcHostAddIns * This,
            /* [in] */ BSTR Key);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LicenseKey )( 
            IApcHostAddIns * This,
            /* [retval][out] */ BSTR *pbstrKey);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RegistryPath )( 
            IApcHostAddIns * This,
            /* [in] */ BSTR Path);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RegistryPath )( 
            IApcHostAddIns * This,
            /* [retval][out] */ BSTR *pbstrPath);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveOnFailure )( 
            IApcHostAddIns * This,
            /* [in] */ VARIANT_BOOL Remove);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveOnFailure )( 
            IApcHostAddIns * This,
            /* [retval][out] */ VARIANT_BOOL *pbRemove);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostObject )( 
            IApcHostAddIns * This,
            /* [in] */ IDispatch *pHostObject);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostObject )( 
            IApcHostAddIns * This,
            /* [retval][out] */ IDispatch **ppHostObject);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisableOnStartup )( 
            IApcHostAddIns * This,
            /* [in] */ VARIANT_BOOL Disabled);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisableOnStartup )( 
            IApcHostAddIns * This,
            /* [retval][out] */ VARIANT_BOOL *pbDisabled);
        
        /* [helpcontext][helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Locale )( 
            IApcHostAddIns * This,
            /* [in] */ long lcidHost);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Locale )( 
            IApcHostAddIns * This,
            /* [retval][out] */ long *plcidHost);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *LoadHostAddIns )( 
            IApcHostAddIns * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *NotifyBeginShutdown )( 
            IApcHostAddIns * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *NotifyStartupComplete )( 
            IApcHostAddIns * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ShowAddInsDialog )( 
            IApcHostAddIns * This);
        
        /* [helpcontext][helpstring][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_HostObject )( 
            IApcHostAddIns * This,
            /* [in] */ IDispatch *pHostObject);
        
        END_INTERFACE
    } IApcHostAddInsVtbl;

    interface IApcHostAddIns
    {
        CONST_VTBL struct IApcHostAddInsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcHostAddIns_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcHostAddIns_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcHostAddIns_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcHostAddIns_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcHostAddIns_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcHostAddIns_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcHostAddIns_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcHostAddIns_get_AddIns(This,ppAddIns)	\
    ( (This)->lpVtbl -> get_AddIns(This,ppAddIns) ) 

#define IApcHostAddIns_put_LicenseKey(This,Key)	\
    ( (This)->lpVtbl -> put_LicenseKey(This,Key) ) 

#define IApcHostAddIns_get_LicenseKey(This,pbstrKey)	\
    ( (This)->lpVtbl -> get_LicenseKey(This,pbstrKey) ) 

#define IApcHostAddIns_put_RegistryPath(This,Path)	\
    ( (This)->lpVtbl -> put_RegistryPath(This,Path) ) 

#define IApcHostAddIns_get_RegistryPath(This,pbstrPath)	\
    ( (This)->lpVtbl -> get_RegistryPath(This,pbstrPath) ) 

#define IApcHostAddIns_put_RemoveOnFailure(This,Remove)	\
    ( (This)->lpVtbl -> put_RemoveOnFailure(This,Remove) ) 

#define IApcHostAddIns_get_RemoveOnFailure(This,pbRemove)	\
    ( (This)->lpVtbl -> get_RemoveOnFailure(This,pbRemove) ) 

#define IApcHostAddIns_put_HostObject(This,pHostObject)	\
    ( (This)->lpVtbl -> put_HostObject(This,pHostObject) ) 

#define IApcHostAddIns_get_HostObject(This,ppHostObject)	\
    ( (This)->lpVtbl -> get_HostObject(This,ppHostObject) ) 

#define IApcHostAddIns_put_DisableOnStartup(This,Disabled)	\
    ( (This)->lpVtbl -> put_DisableOnStartup(This,Disabled) ) 

#define IApcHostAddIns_get_DisableOnStartup(This,pbDisabled)	\
    ( (This)->lpVtbl -> get_DisableOnStartup(This,pbDisabled) ) 

#define IApcHostAddIns_put_Locale(This,lcidHost)	\
    ( (This)->lpVtbl -> put_Locale(This,lcidHost) ) 

#define IApcHostAddIns_get_Locale(This,plcidHost)	\
    ( (This)->lpVtbl -> get_Locale(This,plcidHost) ) 

#define IApcHostAddIns_LoadHostAddIns(This)	\
    ( (This)->lpVtbl -> LoadHostAddIns(This) ) 

#define IApcHostAddIns_NotifyBeginShutdown(This)	\
    ( (This)->lpVtbl -> NotifyBeginShutdown(This) ) 

#define IApcHostAddIns_NotifyStartupComplete(This)	\
    ( (This)->lpVtbl -> NotifyStartupComplete(This) ) 

#define IApcHostAddIns_ShowAddInsDialog(This)	\
    ( (This)->lpVtbl -> ShowAddInsDialog(This) ) 

#define IApcHostAddIns_putref_HostObject(This,pHostObject)	\
    ( (This)->lpVtbl -> putref_HostObject(This,pHostObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcHostAddIns_INTERFACE_DEFINED__ */


#ifndef __IApcLegacyEvents_INTERFACE_DEFINED__
#define __IApcLegacyEvents_INTERFACE_DEFINED__

/* interface IApcLegacyEvents */
/* [object][dual][local][nonextensible][oleautomation][hidden][uuid] */ 


EXTERN_C const IID IID_IApcLegacyEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("623EF25C-C853-4832-A268-5646E84CA622")
    IApcLegacyEvents : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectItemCount( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SaveAsLegacy( 
            /* [retval][out] */ VARIANT_BOOL *SaveLegacy) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ProjectItemName( 
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ BSTR *pbstrProjectItemName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ControlCount( 
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE LicensedControlCount( 
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ControlName( 
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ BSTR *pbstrControlName) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ClassID( 
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ BSTR *bstrClassID) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE TypeLibraryInfo( 
            /* [in] */ long ProjectItemIndex,
            /* [out][in] */ BSTR *bstrTypeLibraryGuid,
            /* [out][in] */ unsigned short *MajorVersion,
            /* [out][in] */ unsigned short *MinorVersion,
            /* [out][in] */ long *Lcid) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE UseDefaultExtender( 
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ VARIANT_BOOL *UseExtender) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ControlCoClassGuid( 
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ BSTR *bstrControlCoClassGuid) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE LicensedControlCoClassGuid( 
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ BSTR *bstrLicControlCoClassGuid) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE ControlID( 
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ long *pControlID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcLegacyEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcLegacyEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcLegacyEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcLegacyEvents * This);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectItemCount )( 
            IApcLegacyEvents * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SaveAsLegacy )( 
            IApcLegacyEvents * This,
            /* [retval][out] */ VARIANT_BOOL *SaveLegacy);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ProjectItemName )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ BSTR *pbstrProjectItemName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ControlCount )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *LicensedControlCount )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ long *pCount);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ControlName )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ BSTR *pbstrControlName);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ClassID )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [retval][out] */ BSTR *bstrClassID);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *TypeLibraryInfo )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [out][in] */ BSTR *bstrTypeLibraryGuid,
            /* [out][in] */ unsigned short *MajorVersion,
            /* [out][in] */ unsigned short *MinorVersion,
            /* [out][in] */ long *Lcid);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *UseDefaultExtender )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ VARIANT_BOOL *UseExtender);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ControlCoClassGuid )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ BSTR *bstrControlCoClassGuid);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *LicensedControlCoClassGuid )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ BSTR *bstrLicControlCoClassGuid);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ControlID )( 
            IApcLegacyEvents * This,
            /* [in] */ long ProjectItemIndex,
            /* [in] */ long ControlIndex,
            /* [retval][out] */ long *pControlID);
        
        END_INTERFACE
    } IApcLegacyEventsVtbl;

    interface IApcLegacyEvents
    {
        CONST_VTBL struct IApcLegacyEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcLegacyEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcLegacyEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcLegacyEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcLegacyEvents_get_ProjectItemCount(This,pCount)	\
    ( (This)->lpVtbl -> get_ProjectItemCount(This,pCount) ) 

#define IApcLegacyEvents_get_SaveAsLegacy(This,SaveLegacy)	\
    ( (This)->lpVtbl -> get_SaveAsLegacy(This,SaveLegacy) ) 

#define IApcLegacyEvents_ProjectItemName(This,ProjectItemIndex,pbstrProjectItemName)	\
    ( (This)->lpVtbl -> ProjectItemName(This,ProjectItemIndex,pbstrProjectItemName) ) 

#define IApcLegacyEvents_ControlCount(This,ProjectItemIndex,pCount)	\
    ( (This)->lpVtbl -> ControlCount(This,ProjectItemIndex,pCount) ) 

#define IApcLegacyEvents_LicensedControlCount(This,ProjectItemIndex,pCount)	\
    ( (This)->lpVtbl -> LicensedControlCount(This,ProjectItemIndex,pCount) ) 

#define IApcLegacyEvents_ControlName(This,ProjectItemIndex,ControlIndex,pbstrControlName)	\
    ( (This)->lpVtbl -> ControlName(This,ProjectItemIndex,ControlIndex,pbstrControlName) ) 

#define IApcLegacyEvents_ClassID(This,ProjectItemIndex,bstrClassID)	\
    ( (This)->lpVtbl -> ClassID(This,ProjectItemIndex,bstrClassID) ) 

#define IApcLegacyEvents_TypeLibraryInfo(This,ProjectItemIndex,bstrTypeLibraryGuid,MajorVersion,MinorVersion,Lcid)	\
    ( (This)->lpVtbl -> TypeLibraryInfo(This,ProjectItemIndex,bstrTypeLibraryGuid,MajorVersion,MinorVersion,Lcid) ) 

#define IApcLegacyEvents_UseDefaultExtender(This,ProjectItemIndex,ControlIndex,UseExtender)	\
    ( (This)->lpVtbl -> UseDefaultExtender(This,ProjectItemIndex,ControlIndex,UseExtender) ) 

#define IApcLegacyEvents_ControlCoClassGuid(This,ProjectItemIndex,ControlIndex,bstrControlCoClassGuid)	\
    ( (This)->lpVtbl -> ControlCoClassGuid(This,ProjectItemIndex,ControlIndex,bstrControlCoClassGuid) ) 

#define IApcLegacyEvents_LicensedControlCoClassGuid(This,ProjectItemIndex,ControlIndex,bstrLicControlCoClassGuid)	\
    ( (This)->lpVtbl -> LicensedControlCoClassGuid(This,ProjectItemIndex,ControlIndex,bstrLicControlCoClassGuid) ) 

#define IApcLegacyEvents_ControlID(This,ProjectItemIndex,ControlIndex,pControlID)	\
    ( (This)->lpVtbl -> ControlID(This,ProjectItemIndex,ControlIndex,pControlID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcLegacyEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ApcGlobal;

#ifdef __cplusplus

class DECLSPEC_UUID("2F967C44-B1F0-485E-957C-97538BCAD2DE")
ApcGlobal;
#endif

#ifndef __ApcEvents_DISPINTERFACE_DEFINED__
#define __ApcEvents_DISPINTERFACE_DEFINED__

/* dispinterface ApcEvents */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E5BBE1B9-2AC3-42B4-9D7B-080629237408")
    ApcEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcEventsVtbl;

    interface ApcEvents
    {
        CONST_VTBL struct ApcEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Apc;

#ifdef __cplusplus

class DECLSPEC_UUID("CFE9F29B-E1B6-4240-AED7-360846769314")
Apc;
#endif

#ifndef __ApcIdeEvents_DISPINTERFACE_DEFINED__
#define __ApcIdeEvents_DISPINTERFACE_DEFINED__

/* dispinterface ApcIdeEvents */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcIdeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AB6EBCA7-6F83-4A56-936E-01A12E8CB707")
    ApcIdeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcIdeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcIdeEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcIdeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcIdeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcIdeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcIdeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcIdeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcIdeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcIdeEventsVtbl;

    interface ApcIdeEvents
    {
        CONST_VTBL struct ApcIdeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcIdeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcIdeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcIdeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcIdeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcIdeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcIdeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcIdeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcIdeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_IDE;

#ifdef __cplusplus

class DECLSPEC_UUID("58ABE70F-0FBA-4AE1-9F97-D582EA2647C2")
IDE;
#endif

EXTERN_C const CLSID CLSID_PropertiesWindow;

#ifdef __cplusplus

class DECLSPEC_UUID("C6086EFA-2CB1-4341-B4EA-52292F24EBAB")
PropertiesWindow;
#endif

EXTERN_C const CLSID CLSID_Projects;

#ifdef __cplusplus

class DECLSPEC_UUID("5F988A5F-B5FC-46D1-8FC8-64A7B92D6164")
Projects;
#endif

#ifndef __ApcProjectEvents_DISPINTERFACE_DEFINED__
#define __ApcProjectEvents_DISPINTERFACE_DEFINED__

/* dispinterface ApcProjectEvents */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcProjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4C0B5416-4E47-4C99-AD8B-8C55963047A7")
    ApcProjectEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcProjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcProjectEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcProjectEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcProjectEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcProjectEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcProjectEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcProjectEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcProjectEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcProjectEventsVtbl;

    interface ApcProjectEvents
    {
        CONST_VTBL struct ApcProjectEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcProjectEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcProjectEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcProjectEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcProjectEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcProjectEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcProjectEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcProjectEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcProjectEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Project;

#ifdef __cplusplus

class DECLSPEC_UUID("21E45CB2-9DD0-430C-B45D-8E2C92EFDDC6")
Project;
#endif

EXTERN_C const CLSID CLSID_ProjectItems;

#ifdef __cplusplus

class DECLSPEC_UUID("6637D4A3-8113-4BEE-94C9-3E30E4479047")
ProjectItems;
#endif

#ifndef __ApcProjectItemEvents_DISPINTERFACE_DEFINED__
#define __ApcProjectItemEvents_DISPINTERFACE_DEFINED__

/* dispinterface ApcProjectItemEvents */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcProjectItemEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6C7B9A5E-9315-41DE-BCD2-43A35203168A")
    ApcProjectItemEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcProjectItemEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcProjectItemEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcProjectItemEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcProjectItemEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcProjectItemEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcProjectItemEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcProjectItemEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcProjectItemEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcProjectItemEventsVtbl;

    interface ApcProjectItemEvents
    {
        CONST_VTBL struct ApcProjectItemEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcProjectItemEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcProjectItemEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcProjectItemEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcProjectItemEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcProjectItemEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcProjectItemEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcProjectItemEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcProjectItemEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ProjectItem;

#ifdef __cplusplus

class DECLSPEC_UUID("ACBF3ED4-7030-4D1F-9AF9-650C9BD012D8")
ProjectItem;
#endif

EXTERN_C const CLSID CLSID_Controls;

#ifdef __cplusplus

class DECLSPEC_UUID("DCB5B55E-878C-4323-A2CD-3582363E9853")
Controls;
#endif

#ifndef __ApcControlEvents_DISPINTERFACE_DEFINED__
#define __ApcControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface ApcControlEvents */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B14EBB17-6790-4A06-B9FC-8D893967D76C")
    ApcControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcControlEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcControlEventsVtbl;

    interface ApcControlEvents
    {
        CONST_VTBL struct ApcControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Control;

#ifdef __cplusplus

class DECLSPEC_UUID("B70A4899-1D5D-4B34-8DB0-466A7AFD3CB0")
Control;
#endif

EXTERN_C const CLSID CLSID_Procedures;

#ifdef __cplusplus

class DECLSPEC_UUID("35AD7D45-772C-456F-87B6-84C4DEBA7458")
Procedures;
#endif

EXTERN_C const CLSID CLSID_Procedure;

#ifdef __cplusplus

class DECLSPEC_UUID("C3015E74-17AD-4868-8FE6-E4894AE83992")
Procedure;
#endif

EXTERN_C const CLSID CLSID_Categories;

#ifdef __cplusplus

class DECLSPEC_UUID("78394D3B-9F90-46DA-BA04-1C1D5D19697C")
Categories;
#endif

EXTERN_C const CLSID CLSID_Category;

#ifdef __cplusplus

class DECLSPEC_UUID("C0759571-C165-4D61-AF17-B615E88DD6A3")
Category;
#endif

EXTERN_C const CLSID CLSID_MiniBitmaps;

#ifdef __cplusplus

class DECLSPEC_UUID("9136B1D8-B042-4342-A889-72B208F52D87")
MiniBitmaps;
#endif

EXTERN_C const CLSID CLSID_MiniBitmap;

#ifdef __cplusplus

class DECLSPEC_UUID("17401A70-E557-48DB-A653-B3862A39DE4A")
MiniBitmap;
#endif

EXTERN_C const CLSID CLSID_Recorder;

#ifdef __cplusplus

class DECLSPEC_UUID("3EC956A9-6E6B-4366-8DCB-5BBF88758411")
Recorder;
#endif

EXTERN_C const CLSID CLSID_Scopes;

#ifdef __cplusplus

class DECLSPEC_UUID("466C4F7F-C1AB-4D48-8E64-EDA7506FBB8B")
Scopes;
#endif

EXTERN_C const CLSID CLSID_Scope;

#ifdef __cplusplus

class DECLSPEC_UUID("0020C54C-EC81-4236-9079-3AC9DE2FFCA9")
Scope;
#endif

EXTERN_C const CLSID CLSID_MacrosDialog;

#ifdef __cplusplus

class DECLSPEC_UUID("BD176440-F4D7-4D40-BD61-FD8E7C08BDDD")
MacrosDialog;
#endif

EXTERN_C const CLSID CLSID_Storage;

#ifdef __cplusplus

class DECLSPEC_UUID("EF072E9F-A2F0-4BCA-86AF-C33DEDFBD55E")
Storage;
#endif

EXTERN_C const CLSID CLSID_Stream;

#ifdef __cplusplus

class DECLSPEC_UUID("998F7461-B8B7-46ED-8BFD-4CA32DBE93C5")
Stream;
#endif

EXTERN_C const CLSID CLSID_RequiredClasses;

#ifdef __cplusplus

class DECLSPEC_UUID("432C4A73-AA29-4905-BA96-A04639F3D7AC")
RequiredClasses;
#endif

EXTERN_C const CLSID CLSID_RequiredClass;

#ifdef __cplusplus

class DECLSPEC_UUID("D149A120-A07F-4471-A593-AC7BA8E57E6E")
RequiredClass;
#endif

#ifndef __ApcExtenderDisp_DISPINTERFACE_DEFINED__
#define __ApcExtenderDisp_DISPINTERFACE_DEFINED__

/* dispinterface ApcExtenderDisp */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcExtenderDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EAB38D5C-26DC-11D2-98C0-00104B24170B")
    ApcExtenderDisp : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcExtenderDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcExtenderDisp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcExtenderDisp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcExtenderDisp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcExtenderDisp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcExtenderDisp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcExtenderDisp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcExtenderDisp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcExtenderDispVtbl;

    interface ApcExtenderDisp
    {
        CONST_VTBL struct ApcExtenderDispVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcExtenderDisp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcExtenderDisp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcExtenderDisp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcExtenderDisp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcExtenderDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcExtenderDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcExtenderDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcExtenderDisp_DISPINTERFACE_DEFINED__ */


#ifndef __ApcExtenderEvents_DISPINTERFACE_DEFINED__
#define __ApcExtenderEvents_DISPINTERFACE_DEFINED__

/* dispinterface ApcExtenderEvents */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcExtenderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EAB38D5D-26DC-11D2-98C0-00104B24170B")
    ApcExtenderEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcExtenderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcExtenderEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcExtenderEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcExtenderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcExtenderEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcExtenderEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcExtenderEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcExtenderEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcExtenderEventsVtbl;

    interface ApcExtenderEvents
    {
        CONST_VTBL struct ApcExtenderEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcExtenderEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcExtenderEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcExtenderEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcExtenderEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcExtenderEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcExtenderEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcExtenderEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcExtenderEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ApcExtender;

#ifdef __cplusplus

class DECLSPEC_UUID("EAB38D5E-26DC-11D2-98C0-00104B24170B")
ApcExtender;
#endif

#ifndef __IApcExtender64_INTERFACE_DEFINED__
#define __IApcExtender64_INTERFACE_DEFINED__

/* interface IApcExtender64 */
/* [object][hidden][uuid] */ 


EXTERN_C const IID IID_IApcExtender64;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A3727A72-D741-4187-8E91-4C13765E3138")
    IApcExtender64 : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out][retval] */ BSTR *pbstr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [out][retval] */ IUnknown **ppunk) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [out][retval] */ IUnknown **ppunk) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE Index( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcExtender64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcExtender64 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcExtender64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcExtender64 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcExtender64 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcExtender64 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcExtender64 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcExtender64 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IApcExtender64 * This,
            /* [out][retval] */ BSTR *pbstr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IApcExtender64 * This,
            /* [in] */ BSTR bstrName);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IApcExtender64 * This,
            /* [out][retval] */ IUnknown **ppunk);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IApcExtender64 * This,
            /* [out][retval] */ IUnknown **ppunk);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IApcExtender64 * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Index )( 
            IApcExtender64 * This);
        
        END_INTERFACE
    } IApcExtender64Vtbl;

    interface IApcExtender64
    {
        CONST_VTBL struct IApcExtender64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcExtender64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcExtender64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcExtender64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcExtender64_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcExtender64_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcExtender64_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcExtender64_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcExtender64_get_Name(This,pbstr)	\
    ( (This)->lpVtbl -> get_Name(This,pbstr) ) 

#define IApcExtender64_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IApcExtender64_get_Object(This,ppunk)	\
    ( (This)->lpVtbl -> get_Object(This,ppunk) ) 

#define IApcExtender64_get_Parent(This,ppunk)	\
    ( (This)->lpVtbl -> get_Parent(This,ppunk) ) 

#define IApcExtender64_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IApcExtender64_Index(This)	\
    ( (This)->lpVtbl -> Index(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcExtender64_INTERFACE_DEFINED__ */


#ifndef __ApcExtenderDisp64_DISPINTERFACE_DEFINED__
#define __ApcExtenderDisp64_DISPINTERFACE_DEFINED__

/* dispinterface ApcExtenderDisp64 */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcExtenderDisp64;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("16E1F945-3B74-4D61-B181-A7DCDC969F22")
    ApcExtenderDisp64 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcExtenderDisp64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcExtenderDisp64 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcExtenderDisp64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcExtenderDisp64 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcExtenderDisp64 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcExtenderDisp64 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcExtenderDisp64 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcExtenderDisp64 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcExtenderDisp64Vtbl;

    interface ApcExtenderDisp64
    {
        CONST_VTBL struct ApcExtenderDisp64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcExtenderDisp64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcExtenderDisp64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcExtenderDisp64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcExtenderDisp64_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcExtenderDisp64_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcExtenderDisp64_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcExtenderDisp64_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcExtenderDisp64_DISPINTERFACE_DEFINED__ */


#ifndef __ApcExtenderEvents64_DISPINTERFACE_DEFINED__
#define __ApcExtenderEvents64_DISPINTERFACE_DEFINED__

/* dispinterface ApcExtenderEvents64 */
/* [hidden][uuid] */ 


EXTERN_C const IID DIID_ApcExtenderEvents64;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("21BC5D29-0798-46F4-BBF5-70EDD1569CE5")
    ApcExtenderEvents64 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ApcExtenderEvents64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ApcExtenderEvents64 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ApcExtenderEvents64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ApcExtenderEvents64 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ApcExtenderEvents64 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ApcExtenderEvents64 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ApcExtenderEvents64 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ApcExtenderEvents64 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ApcExtenderEvents64Vtbl;

    interface ApcExtenderEvents64
    {
        CONST_VTBL struct ApcExtenderEvents64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ApcExtenderEvents64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ApcExtenderEvents64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ApcExtenderEvents64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ApcExtenderEvents64_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ApcExtenderEvents64_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ApcExtenderEvents64_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ApcExtenderEvents64_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ApcExtenderEvents64_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ApcExtender64;

#ifdef __cplusplus

class DECLSPEC_UUID("805A6343-18B0-430C-B2C7-97F08C2F43EC")
ApcExtender64;
#endif

EXTERN_C const CLSID CLSID_Instances;

#ifdef __cplusplus

class DECLSPEC_UUID("ED314606-5463-4D3E-A6C7-4F7FA398D840")
Instances;
#endif

EXTERN_C const CLSID CLSID_HostAddIns;

#ifdef __cplusplus

class DECLSPEC_UUID("943FA227-E90C-47DA-987B-C4DD13E48CB4")
HostAddIns;
#endif

#ifndef __IApcCollection_INTERFACE_DEFINED__
#define __IApcCollection_INTERFACE_DEFINED__

/* interface IApcCollection */
/* [object][dual][nonextensible][oleautomation][uuid] */ 


EXTERN_C const IID IID_IApcCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("677ADEBA-0AF6-40CC-B582-439FBE4099B0")
    IApcCollection : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT *Index,
            /* [retval][out] */ VARIANT *pvarRet) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT *Item,
            /* [optional][in] */ VARIANT *Key) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Count( 
            /* [retval][out] */ long *pi4) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT *Index) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IApcCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApcCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApcCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApcCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApcCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApcCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApcCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApcCollection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IApcCollection * This,
            /* [in] */ VARIANT *Index,
            /* [retval][out] */ VARIANT *pvarRet);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IApcCollection * This,
            /* [in] */ VARIANT *Item,
            /* [optional][in] */ VARIANT *Key);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Count )( 
            IApcCollection * This,
            /* [retval][out] */ long *pi4);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IApcCollection * This,
            /* [in] */ VARIANT *Index);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            IApcCollection * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        END_INTERFACE
    } IApcCollectionVtbl;

    interface IApcCollection
    {
        CONST_VTBL struct IApcCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApcCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApcCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApcCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApcCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApcCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApcCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApcCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApcCollection_Item(This,Index,pvarRet)	\
    ( (This)->lpVtbl -> Item(This,Index,pvarRet) ) 

#define IApcCollection_Add(This,Item,Key)	\
    ( (This)->lpVtbl -> Add(This,Item,Key) ) 

#define IApcCollection_Count(This,pi4)	\
    ( (This)->lpVtbl -> Count(This,pi4) ) 

#define IApcCollection_Remove(This,Index)	\
    ( (This)->lpVtbl -> Remove(This,Index) ) 

#define IApcCollection__NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> _NewEnum(This,ppUnk) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApcCollection_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Collection;

#ifdef __cplusplus

class DECLSPEC_UUID("95C9DCCD-A44A-4034-84BB-D7912DF5711F")
Collection;
#endif
#endif /* __MSAPC_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


