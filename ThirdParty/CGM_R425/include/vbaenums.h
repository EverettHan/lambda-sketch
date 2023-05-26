//---------------------------------------------------------------------------
// Copyright (C) 1995-1998, Microsoft Corporation
//                 All Rights Reserved
// Information Contained Herein Is Proprietary and Confidential.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// VBAenums.h
//---------------------------------------------------------------------------
//
//
//
// *** CAUTION ***
//
// Types defined in this file are not owned by Office, and changing them
// will break VBA.  Interface changes must be made in sync with DevDiv, and
// must be kept in sync with vbaenums.h and vba.h in otools\inc\vba.
//
// *** CAUTION ***
//
// Contents:
// - VBA API-Related Enums
//
//---------------------------------------------------------------------------


#ifndef _VBAENUMS_H
#define _VBAENUMS_H



// Stand-Alone Project information
typedef enum { 
  VBASAPT_NONE= 1, 
  VBASAPT_MT
}VBASAPROJTYPE;


typedef enum {
	VBASTEPMODE_None,
	VBASTEPMODE_Into,
	VBASTEPMODE_Over,
} VBASTEPMODE;


// for IVBASite::Notify
typedef enum {
	VBAHN_ExecuteCodeBegin,
	VBAHN_ExecuteCodeEnd,
        VBAHN_Activate,
        VBAHN_Reset,
        VBAHN_ModalDlgBegin,
        VBAHN_ModalDlgEnd,
	VBAHN_ResetToolbar,
} VBASITENOTIFY;


// for IVBASite::CanEnterBreakMode
typedef enum {
  VBA_BRKREASON_Error,
  VBA_BRKREASON_UserInterrupt,
  VBA_BRKREASON_Breakpoint,
  VBA_BRKREASON_WatchBreak,
  VBA_BRKREASON_HostBreak,
  VBA_BRKREASON_CompileError,
  VBA_BRKREASON_Assert
} VBA_BRKREASON;


// for IVBASite::CanEnterBreakMode
typedef enum VBA_BRKOPT {
  VBA_BRKOPT_Continue,
  VBA_BRKOPT_Debug,
  VBA_BRKOPT_End,
  VBA_BRKOPT_InterruptError,
  VBA_BRKOPT_ContinueNoReset
} VBA_BRKOPT;


// for IVBAProjectSite::Notify
typedef enum {
	VBAPSN_AfterProjectReset,
        VBAPSN_Activate,
        VBAPSN_ModalDlgBegin,
        VBAPSN_ModalDlgEnd,
        VBAPSN_SearchReplaceBegin,
        VBAPSN_SearchReplaceEnd,
} VBAPROJSITENOTIFY;


// for IVBAProjItem::GetItemType
typedef enum {
	VBAPIT_StdModule,
	VBAPIT_ClassModule,
	VBAPIT_Designer,
	VBAPIT_DocumentObject,
	VBAPIT_DocumentClass,
	VBAPIT_Other
} VBAPROJITEMTYPE;


typedef enum {
	VBA_PROJ_MODE_Design,
	VBA_PROJ_MODE_Use,
} VBA_PROJECT_MODE;


typedef enum {
	VBA_PROC_MODE_Wait,
	VBA_PROC_MODE_Run,
	VBA_PROC_MODE_Break
} VBA_PROCESS_MODE;


typedef enum {
	Protection_None = 0,
	Protection_User = 1,
	Protection_Host = 2,
	Protection_VBA  = 4   // the VBA referred to by the world at large...
	// Note: next one's are 8, 16, 32, etc...
} PROTECTIONSTATE, * LPPROTECTIONSTATE;


typedef enum {
        VBACMSN_LostActivation    = 1,
        VBACMSN_HideBorderTools   = 2,
        VBACMSN_TrackingBegins    = 3,
        VBACMSN_TrackingEnds      = 4
} VBACMSITENOTIFY;

typedef enum {
        VBACOMPSTATE_Modal        = 1,
	// RedrawOff/WarningsOff/Recording are not used in the current version
        VBACOMPSTATE_RedrawOff    = 2,
        VBACOMPSTATE_WarningsOff  = 3,
        VBACOMPSTATE_Recording    = 4
} VBACOMPSTATE;

typedef enum {
        VBALOOPREASON_FocusWait   = 1,
        VBALOOPREASON_DoEvents    = 2,
        VBALOOPREASON_Debug       = 3,
        VBALOOPREASON_ModalForm   = 4
} VBALOOPREASON;


typedef enum {
    VBASecurityLevel_Undefined      = 0,
    VBASecurityLevel_None           = 1,
    VBASecurityLevel_Medium         = 2,
    VBASecurityLevel_High           = 3,
    VBASecurityLevel_VeryHigh       = 4,
}  VBADIGSIGSECURITYLEVEL;



#ifndef _HOSTREQUEST_
#define	_HOSTREQUEST_
typedef enum {
  HOSTREQUEST_NONE = 0x00000000,
  HOSTREQUEST_DONTREGISTER = 0x00000001,
  HOSTREQUEST_SKIPVERCHECK = 0x00000002
} HOSTREQUEST, *PHOSTREQUEST;
#endif	//_HOSTREQUEST_


typedef enum
{
	resultError = 0xFFFFFFFF,
	resultOk = 1,
	resultCancel = 2,
} SignDlgResult;


typedef enum
{
	actionEnable = 1,
	actionDisable = 2,
	actionDontOpen = 3,
} MacroLoadAction;


// Output of the digital signature verification (dsv)
typedef enum
{
	// No project was found
	dsvNoMacros = 0,

	// No signature was provided
	dsvUnsigned = 1,

	// signature was verified, but certificate could not be verified
	dsvPassedUntrustedCert = 2,

	// signature could not be verified
	dsvFailed = 3,

	// signature verification was skipped because the security level of the application is set to low
	dsvLowSecurityLevel = 4,

	// signature was verified and certificate was verified and trusted
	dsvPassedTrustedCert = 5,

	// signature was verified only for the canonical portion of the project
	dsvLoadFromText = 6,

	// the project should be blocked from opening for other reasons not indicated by one of the other values
	dsvBlocked = 7
} DigSigVerifyResult;


typedef enum VBADIGSIGTYPE {
	VBASIG_UNKNOWN = 0,
	VBASIG_V1 = 2, // old project sig
	VBASIG_V2 = 3 // crypto agile sig
} VBADIGSIGTYPE;

// For IVBASite5::IsCapabilityAvailable. Each capability is a bit flag
// Values should be 0x01, 0x02, 0x04, etc
typedef enum VBACAPABILITYTYPE {
    VBACapability_UIAProxies = 0x01,
    VBACapability_Telemetry = 0x02,
    VBACapability_NotifyBreak = 0x04
} VBACAPABILITYTYPE;

// For IVbaProjectSite2
// HostNotifyTelemetry(VBATELEMETRYDATAPOINT dp, VARIANT* pArgumentsArray) with optional arguments in SAFEARRAY or NULL
typedef enum VBATELEMETRYDATAPOINT {
    VBATelemetry_Declare = 0, // Arguments: Lib Name, Entry point name, fPtrSafe
    VBATelemetry_ReferencedLibrary = 1, // Argument: Lib GUID
    VBATelemetry_ComObjectInstantiated = 2, // Argument: Object CLSID
    VBATelemetry_Compile = 3,
    VBATelemetry_ShowIDE = 4,
    VBATelemetry_MacroRecord = 5,
    VBATelemetry_IdeMacroStart = 6,
    VBATelemetry_IdeMacroEnd = 7,
    VBATelemetry_HostMacroStart = 8,
    VBATelemetry_HostMacroEnd = 9,
    VBATelemetry_AmsiScan = 10,
    VBATelemetry_Break = 11 // Arguments: [VBABREAKREASON], Internal Error Code, Error Description
} VBATELEMETRYDATAPOINT;

// For IVbaProjectSite2.HostNotifyMalwareFound()
// VBA action after malware found
typedef enum VBAACTIONONMALWARE {
    VBAActionOnMalware_TermProcess = 0, // VBA to terminate process
} VBAACTIONONMALWARE;

// For HostNotifyTelemetry [VBATelemetry_Break] - reason for break
typedef enum VBABREAKREASON {
    VBABreakReason_Other = 0,
    VBABreakReason_RuntimeError = 1,
    VBABreakReason_CompileError = 2
} VBABREAKREASON;

#endif // ndef _VBAENUMS_H
