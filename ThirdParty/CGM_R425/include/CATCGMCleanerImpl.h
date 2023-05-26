/* -*-c++-*- */
#ifndef CATCGMCleanerImpl_H_
#define CATCGMCleanerImpl_H_
//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//============================================================================
#include "ExportedByCATCGMCleaner.h"


#include "CATCGMCleanerActivation.h"
#include "CATCGMCleaner.h"
#include "CATCGMCleanerBridge.h"

#include "CATCGMCheckClean.h"

#include "CATGeoCln.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATCGMNewArray.h"
#include "CATListOfCATCGMRuleDef.h"
#include "CATListOfCATCGMCheckRule.h"
#include "CATCGMRuleDef.h"

class CATCGMObject;
class CATCheckReport;
class CATGeometricTypeEntry;
class CATHashTabCATGeometricTypeEntry;
class CATCX_CHECKUP;
class CATCGMCheckBehavior;
class CATCheckRule;
/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ofstream;
#endif
class CATCGMRuleDefHashTable;
class CATGeoClnCheckParameter;
class CATLISTP(CATGeoClnCheckParameter);
class CATLISTP(CATICGMObject);
class CATCGMCleanerCleaner;

class ExportedByCATCGMCleaner CATCGMCleanerImpl : protected CATCGMCleaner
{
 public:
  // basics
  CATDeclareKindOf;
 

  // Pour statistiques
  static CATULONG32 __NbDetectAllRulesCalls;

  static CATULONG32 __NbBRepLinkCalls;

  static CATULONG32 __NbSpecificCheckCalls;

  static CATULONG32 __NbBodyCompletedCalls;

  //---------------------------------------------------------------------------
  // Constructors/Destructor
  //---------------------------------------------------------------------------
  CATCGMCleanerImpl();
  CATCGMCleanerImpl(const CATCGMCleanerImpl& copy);

  ~CATCGMCleanerImpl();

  //---------------------------------------------------------------------------
  // = operator
  //---------------------------------------------------------------------------
  CATCGMCleanerImpl& operator= (const CATCGMCleanerImpl&);

  //---------------------------------------------------------------------------
  // For access to existing CGM Cleaner Rules defined in
  // CATCGMCleanerRulesDefinitions.h
  //---------------------------------------------------------------------------
  static void InitCGMRULEDEFS();

  static CATCGMRuleDef* _Get_ORIGINAL_CGM_RULE_DEF_FromNumInTab(const int iRuleNum);

  static CATCGMRuleDef* Get_ORIGINAL_CGM_RULE_DEF_FromRuleCode(const CATUnicodeString& iRuleCode);

  static CATCGMRuleDef* Get_ORIGINAL_CGM_RULE_DEF_FromRuleCode(const char* ipRuleCode);

  //---------------------------------------------------------------------------
  // Tools
  //---------------------------------------------------------------------------
  static void _DecodeCodeLevel(int iCodeLevel, char* ioBuffer);

  //---------------------------------------------------------------------------
  // Activation / Traces / Breakpoint
  //---------------------------------------------------------------------------
  static void _SetActive(CATBoolean iMode = TRUE);
  static CATBoolean _IsActive();

  static CATCGMCleanerImpl::FailureMode _GetEnvFailureMode();
  static                           void _SetFailureMode(CATCGMCleanerImpl::FailureMode iMode);
  static CATCGMCleanerImpl::FailureMode _GetFailureMode();

  static void _SetShowTraces(CATBoolean iMode = TRUE);
  // If severity included in CkeckParameter is 0, no traces are provided
  static CATBoolean DisabledMessage(CATCGMCheckRule* ipCGMCheckRule = NULL);
  static CATBoolean _IsShowTraces(CATCGMCheckRule* ipCGMCheckRule = NULL);

  static void SetTraceStream(ostream* ipTraceStream);
  static ostream* GetTraceStream();

  static void DumpRuleTraces(CATUnicodeString& iTraceMessage,
                             CATGeoCln::CATCGMCleanerAction iAction,
                             ostream* os = NULL);

  static void       _SetShowErrorDialogs(CATBoolean iMode = TRUE);
  static CATBoolean _IsShowErrorDialogs();

  static void       _SetBreakpoint(CATBoolean iMode);
  static CATBoolean _IsBreakpoint();

  static void        _SetBreakpointTag(CATULONG32  iTag = 0);
  static CATULONG32  _GetBreakpointTag();

  static void       _SetDumpCallStack(CATBoolean iMode = TRUE);
  static CATBoolean _IsDumpCallStack();

  static void DumpCallStack(CATGeoCln::CATCGMCleanerAction iAction, ostream* os = NULL);

  static ofstream* Open_ofstream(const char* ipFileInnerSuffix);
  static ofstream* Open_BodyCompleted_ofstream();
  static ofstream* Open_Features_ofstream();
  static ofstream* Open_ODT_DOC_CHECK_ofstream();

  static void Close_ofstreams();

  static CATULONG32 _DumpCGMRuleStats(ostream* ipOutput);
  static CATULONG32 ResetCGMRuleStats();

  //---------------------------------------------------------------------------
  // For access to existing CGM Cleaner Rules defined in
  // CATCGMCleanerRulesDefinitions.h
  //---------------------------------------------------------------------------
  static CATCGMRuleDefHashTable* _CreateStaticTabOfAllCGMRuleDefs(CATBoolean iOnCompletedRules);

  static void _DeleteStaticCGMRuleDefsAndCGMRules();

  // Inactivation is prioritary against activation
  // The service certifies that all elements are unic in the output list
  static void ActivateRulesInStaticTabOfAllCGMRuleDefs(const CATListOfInt * iListOfRulesToActivate,
                                                       const CATListOfInt * iListOfRulesToInactivate,
                                                       CATLISTP(CATCGMRuleDef)*& iopListOfModifiedRuleDefs,
                                                       CATBoolean iForceActivate = FALSE);

  //---------------------------------------------------------------------------
  // For debug purposes
  //---------------------------------------------------------------------------
  static void _ForceActivateAllCGMRules(CATBoolean iForce = TRUE);

  static void _ActivateApplyCreatedCGMRulesTraces(CATBoolean iForce = TRUE);

  //---------------------------------------------------------------------------
  // CATGemEvtGenericNamed event management
  //---------------------------------------------------------------------------
  static void _ActivateCATGemEvtGenericNamedRules();

  //---------------------------------------------------------------------------
  // Cleaner session management
  //---------------------------------------------------------------------------
  static CATBoolean IsCleanerSessionStarted();

  //---------------------------------------------------------------------------
  // Gestion des regles declarees par variable d'environnement ou dans un contexte ODT
  //---------------------------------------------------------------------------
  static void GetListOfRuleCodesFromEnv(const char* ipEnvString,
                                        CATListOfCATUnicodeString& iListOfRuleCodes);

  static void _GetEnvRules(CATListOfCATUnicodeString* iopListEnvRules = NULL, CATListOfCATUnicodeString* iopListEnvOFFRules = NULL,
                          CATListOfCATUnicodeString* iopListODTRules = NULL);

  static void GetListOfRuleCodesFromODT(CATListOfCATUnicodeString& iListOfRuleCodes);

  //---------------------------------------------------------------------------
  // Forcage des regles au moment du completed des bodies
  //---------------------------------------------------------------------------
  static void GetEnvOnCompletedRules();

  //---------------------------------------------------------------------------
  // Gestion des breakpoints CATCheckCleanFollowTag
  //---------------------------------------------------------------------------
  static void InitCATCheckCleanFollowTag();

  //---------------------------------------------------------------------------
  // Acces aux ExtendedErrorMsg specifiques aux CATCGMCheckRule/CATGeoCln
  //---------------------------------------------------------------------------
  static void _FillExtendedCheckErrorMsg(CATCheckRule* ipCheckRule, CATListValCATUnicodeString* iopListExtendedErrorMsg);
  static void _FillExtendedCleanErrorMsg(CATCheckRule* ipCheckRule, CATListValCATUnicodeString* iopListExtendedErrorMsg);

  //---------------------------------------------------------------------------
  // Acces aux CleanMessages
  //---------------------------------------------------------------------------
  static void _GetCleanMessages(CATCheckRule* ipCheckRule, CATUnicodeString& ioMessage, CATUnicodeString& ioShortMessage);

  //---------------------------------------------------------------------------
  // Mise a jour des CATCGMRuleDef::_pStaticTableChkCGMEntsKO
  //          et des CATCGMRuleDef::_pStaticTableChkCGMEntsKOWitns
  //---------------------------------------------------------------------------
  static void _DeleteStaticTablesOfChkCGMEnts(CATGeoFactory* ipGeoFactory = NULL);

  //---------------------------------------------------------------------------
  // Internals
  //---------------------------------------------------------------------------
  static int _DetectUserActivatedRulesForPerfo(CATCGMCleanerImpl*               ipThisCleaner,
                                              CATSoftwareConfiguration*    ipSoftConf,
                                              CATICGMUnknown*              ipSpecificToCheck,
                                              CATListOfInt*                ipSpecificRuleIDs,
                                              CATCX_CHECKUP*               iopCATCX_Report,
                                              CATCGMCheckBehavior*         ipCheckBehavior,
                                              CATCGMCheckClean::CallMethod iCallMethod,
                                              CATLISTP(CATICGMObject)*     ipPreCalculatedAllLinks);

  static HRESULT Clean(CATCGMCleanerImpl*               ipThisCleaner,
                       CATCheckReport*              iopCheckReport,
                       CATCX_CHECKUP*               iopCATCX_Report,
                       CATCGMCheckClean::CallMethod iCallMethod);

  //---------------------------------------------------------------------------
  // Pour diminuer le cout perfo du check CGM a base de regles de cleaner
  //---------------------------------------------------------------------------
  static void UserActivatedRuleBegin(CATGeoClnIDs::RuleID ipSpecificRuleID, CATGeoClnCheckParameter* ipRuleCheckParameter);
  static void UserActivatedRuleAdd(CATGeoClnIDs::RuleID ipSpecificRuleID, CATGeoClnCheckParameter* ipRuleCheckParameter);
  static void UserActivatedRuleReset();
  static CATListOfInt* UserActivatedRuleGetList();
  static CATBoolean IsUserRuleAllowedForCheck(CATGeoClnIDs::RuleID ipSpecificRuleID);

  static CATULONG32 GetNB_AtCompletedAndActive_Rules();
  static CATULONG32 _Inc_NB_AtCompletedAndActive_Rules();
  static CATULONG32 _Dec_NB_AtCompletedAndActive_Rules();

  //---------------------------------------------------------------------------
  // CATCGMCheckClean
  //---------------------------------------------------------------------------
  HRESULT GetCheckRules(CATListOfCATUnicodeString & ioRuleCodeList);
  HRESULT DetectAllRules(CATCheckReport* CheckReport);
  HRESULT DetectSpecificRules(CATListOfCATUnicodeString & RuleCodeList, CATCheckReport* CheckReport);
  HRESULT GetCleanRules(CATListOfCATUnicodeString & ioRuleCodeList);
  HRESULT Clean(CATCheckReport* CheckReport);
  void* GetCGMCleaner();
  void SetFeatureName(CATUnicodeString& iFeatureName);
  int DetectUserActivatedRules(CATSoftwareConfiguration*    ipSoftConf,
                               CATICGMUnknown*              ipSpecificToCheck,
                               CATListOfInt*                ipSpecificRuleIDs,
                               CATCX_CHECKUP*               iopCATCX_Report,
                               CATCGMCheckBehavior*         ipCheckBehavior,
                               CATUnicodeString*            ipFeatureName,
                               CATCGMCheckClean::CallMethod iCallMethod,
                               CATUnicodeString*            ipErrorDialogMsg);
  //---------------------------------------------------------------------------
  // For interactive use
  //---------------------------------------------------------------------------
  void SetpErrorDialogMsg(CATUnicodeString* ipErrorDialogMsg);

  //---------------------------------------------------------------------------
  // Internals
  //---------------------------------------------------------------------------
  int GetNbCheckedCGMEntitiesKO();

  static void _SetVerbose(CATBoolean iVerbose);

  //---------------------------------------------------------------------------
  // CATCGMObject access
  //---------------------------------------------------------------------------
  CATCGMObject* GetCGMObject();

  //---------------------------------------------------------------------------
  // Access a l'object qui implemente CATICheckObject et CATICleanObject
  //---------------------------------------------------------------------------
  CATBaseUnknown* GetPartCleanerObject();

  // Restore the rules that were temporary modified in a transaction, and delete their list
  static void RestoreModifiedCleanerRules(CATLISTP(CATCGMRuleDef)*& iopListOfModifiedRuleDefs);

 private :

  static CATULONG32                   __IdMax;

  static CATULONG32                   __NbPerformedChecks;

  static CATULONG32                   __NbPerformedCleans;

  static CATBoolean                   __DumpStats;

  static CATBoolean                   __Active;

  static CATCGMCleanerImpl::FailureMode   __FailureMode;


  static CATCGMRuleDefHashTable*      __pStaticTabOfCGMRuleDefs;

  static int                          __NB_AtCompletedAndActive_Rules;

  static CATLISTP(CATCGMCheckRule)    __ListOfCGMRules;

  static CATBoolean                   __ForceVerbose;

  static ostream*                     __pTraceStream;

  static ofstream*                    __pFeatures_ofstream;

  static ofstream*                    __pBodyCompleted_ofstream;

  static ofstream*                    __pODT_DOC_CHECK_ofstream;

  static CATBoolean                   __ShowTraces;

  static CATBoolean                   __ShowErrorDialogs;

  static CATBoolean                   __Breakpoint;

  static CATULONG32                   __BreakpointTag;

  static CATBoolean                   __DumpCallStack;

  static CATBoolean                   __CleanerSessionStarted;

  static CATBoolean                   __ForceActivateAllCGMRules;

  static CATBoolean                   __ApplyCreatedCGMRulesTraces;

  static CATListOfCATUnicodeString    __ListEnvRules;

  static CATListOfCATUnicodeString    __ListODTRules;

  static CATListOfCATUnicodeString    __ListEnvOFFRules;

  static CATListOfCATUnicodeString    __ListEnvOnCompletedRules;

  static CATListOfInt*                __pList_CHECKUP_Rules;

  CATULONG32                          _Id;

  CATCGMObject*                       _pThisCGMObject;

  int                                 _NbCheckedCGMEntitiesKO;

  static CATBoolean                   _Verbose;

  CATUnicodeString*                   _pErrorDialogMsg;

  CATUnicodeString                    _FeatureName;

  //---------------------------------------------------------------------------
  // Cleaner session management
  //---------------------------------------------------------------------------
  static CATBoolean StartCleanerSession();
  static void EndCleanerSession(CATBoolean iOldCleanerSessionStatus = FALSE);

  //---------------------------------------------------------------------------
  // Internals
  //---------------------------------------------------------------------------

  static CATHashTabCATGeometricTypeEntry* CreateHashTableCATGeometricTypeEntry(CATICGMUnknown*          ipCGMUnknown,
                                                                               CATLISTP(CATICGMObject)* ipPreCalculatedAllLinks);

  static void DeleteHashTableCATGeometricTypeEntry(CATHashTabCATGeometricTypeEntry* ipTable);

  static CATULONG32 GetNbObjectsToProcess(CATHashTabCATGeometricTypeEntry* ipTable);

  static void UpdateStaticTabOfCGMRuleDefs(CATSoftwareConfiguration*    ipSoftConf,
                                           CATICGMUnknown*              ipICGMEntity,
                                           CATListOfInt*                ipSpecificRuleIDs,
                                           CATCGMCheckBehavior*         ipCheckBehavior,
                                           CATCGMCheckClean::CallMethod iCallMethod,
                                           CATBoolean                   iVerbose,
                                           CATBoolean                   iFilterRule);

  static void CreateCGMRuleIfNecessary(CATSoftwareConfiguration*    ipSoftConf,
                                       CATCGMRuleDef*               ipCGMRuleDef,
                                       CATICGMUnknown*              ipICGMEntity,
                                       CATCGMCheckBehavior*         ipCheckBehavior,
                                       CATCGMCheckClean::CallMethod iCallMethod,
                                       CATBoolean                   iVerbose,
                                       CATBoolean                   iFilterRule);

  static HRESULT ApplyCreatedCGMRules(CATCGMCleanerImpl*               ipThisCleaner,
                                      CATICGMUnknown*              ipICGMEntity,
                                      CATListOfInt*                ipSpecificRuleIDs,
                                      CATCheckReport*              iopCheckReport,
                                      CATCX_CHECKUP*               iopCATCX_Report,
                                      CATCGMCheckBehavior*         ipCheckBehavior,
                                      CATCGMCheckClean::CallMethod iCallMethod,
                                      CATUnicodeString*            ipErrorDialogMsg,
                                      int*                         iopNbCheckedCGMEntitiesKO,
                                      CATLISTP(CATICGMObject)*     ipPreCalculatedAllLinks);

  static HRESULT ApplyOneCGMRule(CATCGMCleanerImpl*                   ipThisCleaner,
                                 CATICGMUnknown*                  ipICGMEntity,
                                 CATHashTabCATGeometricTypeEntry* ipTableOfTypeEntries,
                                 CATCGMCheckRule*                 ipCGMCheckRule,
                                 CATCheckReport*                  iopCheckReport,
                                 CATCX_CHECKUP*                   iopCATCX_Report,
                                 CATCGMCheckBehavior*             ipCheckBehavior,
                                 CATCGMCheckClean::CallMethod     iCallMethod,
                                 CATUnicodeString*                ipErrorDialogMsg,
                                 int*                             iopNbCheckedCGMEntitiesKO);

  static HRESULT ApplyRuleToOneCATGeometricTypeEntry(CATCGMCheckRule*       ipRuleToApply,
                                                     CATGeometricTypeEntry* ipEntry,
                                                     CATUnicodeString*      ipErrorDialogMsg);

  static HRESULT ApplyRuleToOneEntity(CATCGMCheckRule*         ipRuleToApply,
                                      CATICGMUnknown*          ipICGMEntity,
                                      CATUnicodeString*        ipErrorDialogMsg);

  //---------------------------------------------------------------------------
  // Surcharge new/delete ...
  //---------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;

  //---------------------------------------------------------------------------
  // Classes amies
  //---------------------------------------------------------------------------
  friend class CATCGMCheckRule;
	friend class CATCGMCleanerCleaner;
};

#endif
