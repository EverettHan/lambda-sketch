#ifndef CATLMStructs_h
#define CATLMStructs_h
#include "CATSysLMdefine.h"

typedef enum {
  startupCNext = 0,
  startupServer,
  startupTools,
  startupDirect,
  startupEnovia,
  startupCAA,
  startupCAANext,
  startupBatch,
  startupRepresentation,
  startupConnectedApp,
#ifdef UKU_PHASE_2
  startupPLMCoreServer,
  startupLegacyProvider,
  startupEV6Provider,
  startupDummy,
  startupSession
#endif
} StartupMode;

typedef enum {
  ChassisUndefined = PKGEnum::ChassisUndefined,
  ChassisP = PKGEnum::ChassisP,
  ChassisP2 = PKGEnum::ChassisP2,
  ChassisP3 = PKGEnum::ChassisP3
} ChassisLevel;

typedef enum { Authorized = 0, NotAuthorized, Unknown } AuthorizationStatus;

typedef enum { NamedUser = 0, Std } UserMode;

typedef enum { DSLS, UndefinedMode } LMMode;

typedef enum {
  LicAuthorizationOK = 1,
  LicAuthorizationKO = 2,
  LicAlreadyAuthorized = 4 | LicAuthorizationOK,
  LicGranted = 8 | LicAuthorizationOK,
  LicAuthorized = 16 | LicAuthorizationOK,
  LicGrantedWithIDS = 32 | LicAuthorizationOK,
  LicNotFound = 64 | LicAuthorizationKO,
  LicNotAuthorized = 128 | LicAuthorizationKO,
  LicReleased = 256 | LicAuthorizationKO,
  LicToRequest = 512
} LicAuthorization;

typedef enum {
  undefined = -1,
  success = 0,
  noSettings,
  noProduct,
  noLicense
} LicenseStatus;

typedef enum {  // keep in sync with defs in LUM.h
  ImportSuccess = 0,
  ImportError,
  IOError,
  certificateOpenError,
  tempOpenError,
  nodelockOpenError,
  LUMError,
  invalidVendorId,
  invalidLicense,      // Certificate OK but LUM says no
  invalidCertificate,  // Missing keywords or bad dates
  invalidLicenseType,
  invalidTargetId,
  invalidTargetType,
  licenseNotYetAvailable,
  licenseHasExpired,
  certificateNotFound,  // [LicenseCertificate] not found
  invalidSerialNumber,
  invalidUpdateLicense,
  noInitialLicense,
  duplicateInitialLicense,
  duplicateLicense,
  extractSuccess,  // Extraction / Restitution
  restituteSuccess,
  alreadyOffline,
  badReservePeriod,
  driverNotRunning,
  missingOfflineLicense,
  invalidTimestamp,
  invalidOfflineLicense,
  licenseNotFound,
  licenserFatalError,
  duplicateProduct,
  duplicateOfflineLicense,
  nodPermDeny,
  notAuthorizedUser,
  clearSuccess
} ImportStatus;

typedef enum {
  standAlone = PKGEnum::standAlone,
  configuration = PKGEnum::configuration,
  customConfig = PKGEnum::customConfig,
  customConfigAlias = PKGEnum::customConfigAlias,
  userExperience = PKGEnum::userExperience,
  app = PKGEnum::app,
  technicalProduct = PKGEnum::technicalProduct,
  commercialProduct = PKGEnum::commercialProduct,
  richClientPart = PKGEnum::richClientPart,
  allProductTypes = PKGEnum::allProductTypes,

  // flags for external use
  licensedFlag = PKGEnum::licensedFlag,
  shareableFlag = PKGEnum::shareableFlag,
  addonFlag = PKGEnum::addonFlag,

  // flags for internal use only
  anyProductAttr = PKGEnum::anyProductAttr,
  allProductAttrs = PKGEnum::allProductAttrs,
  visible = PKGEnum::visible,
  licensed = PKGEnum::licensed,
  addon = PKGEnum::addon,
  shareable = PKGEnum::shareable,
  representation = PKGEnum::representation,
  delegation = PKGEnum::delegation,
  token = PKGEnum::token,
  credit = PKGEnum::credit,
  namedUser = PKGEnum::namedUser
} ProductType;

typedef enum {
  /* following types are defined in DSLicensing.h and must be synchronized */
  none = 0,
  simple_nodelocked = 1 << 0,
  simple_concurrent = 1 << 1,
  retention_concurrent = 1 << 2,
  simple_token = 1 << 3,
  offline_concurrent = 1 << 4,
  offline_named_user = 1 << 5,
  /* following types are NOT defined in DSLicensing.h*/
  included = 1 << 10,
  tools = 1 << 11,
  all_offline = offline_concurrent | offline_named_user,
  all_nodelocked = simple_nodelocked | all_offline,
  all_concurrent = simple_concurrent | retention_concurrent,
  all_type = all_nodelocked | all_concurrent | included | tools
} LicenseSource;

typedef struct {
  lm_base base;
  lm_addons addons;
  lm_version version;
  int licId;
  int amount;
  int inUse;
  time_t startDate;
  time_t endDate;
  lm_timestamp timestamp;
  LicenseSource sourceType;
  char serverId[CATLM_COMPUTER_ID_MAX_LEN];
  char serverVersion[16]; /* ex: 6.210.0 */
  unsigned char reservePeriod;
  unsigned char admReservePeriod;
  time_t
      offlineMasterStartDate;  /* offline only: start date of the corresponding
                                  concurrent license on the license server*/
  time_t offlineMasterEndDate; /* offline only: end date of the corresponding
                                  concurrent license on the license server*/
  lm_addons user;
} LicenseInfo;

typedef struct {
  AuthorizationStatus authStat;
  LicenseSource licSource;
  LicenseSource availableLicSources;
  int inclByProdCount;
  int reqByProdCount;
  int productId;
  lm_prd_name name;
  lm_prd_desc description;
  lm_prd_alias alias;
  lm_server licServer;
  lm_prd_name_tab inclByProdTab;
  lm_prd_name_tab reqByProdTab;
} ProductInfo;

typedef struct {
  int remoteDisplayFlag;
  int productCount;
  int frameworkCount;
  int authProductCount;
  int serverCount;
  StartupMode mode;
  lm_licenser_name name;
  lm_licenser_id id;
  lm_server_tab serverTab;
} SystemInfo;

typedef PKGEnum::FrameworkInfo FrameworkInfo;

typedef struct {
  char* logon;
  /* rich client licenses data */
  char** richClientAssignedLic;
  char** richClientAssignedLicCustomerIds;
  int* richClientAssignedLicCasualUsageValue;
  int nbRichClientAssignedLic;
  char** richClientLicServers;
  int nbRichClientLicServers;
  char** notGrantedRichClientLic;
  int nbNotGrantedRichClientLic;
  int nbAlreadyInUseClientLics;
  char** uselessRichClientLic;
  int nbUselessRichClientLic;
  char** richClientLicAuthByServer;
  int nbRichClientLicAuthByServer;
  int nbInvalidManagedServers;

  /* MCS licenses data */
  char** MCSAssignedLic;
  int* MCSAssignedLicCasualUsageValue;
  int nbMCSAssignedLic;
  char** MCSAuthorizedPrd;
  int nbMCSAuthorizedPrd;

} PLM1Info;

#ifdef _WINDOWS_SOURCE
typedef __int64    dsl_time64_t;  /* seconds since UNIX Epoch */
#else
typedef long long  dsl_time64_t;
#endif

typedef struct dsl_available_offline_licenses
{
    char*                           offlineLicenseName; /* List name of offline licenses */
    dsl_time64_t                    exp_date;           /* Expiration date */
    dsl_available_offline_licenses* next;               /* Pointer to next element */
}dsl_available_offline_licenses, *pdsl_available_offline_licenses;

typedef enum {
  infoType,
  warningType,
  errorType,
  stackType,
  isxaType,
  noPrefix
} TraceType;

typedef enum { legacyMode = 3, warmStartMode = 4 } RequestOption;

typedef void (*DisplayMsgMethod)(const CATUnicodeString& title,
                                 const CATUnicodeString& message);
typedef void (*WbUpdateMethod)();
typedef void (*ErrorNotifyMethod)(int errorCount, int numTrialLeft);
typedef int (*CheckFunction)();
typedef void (*ExitFunction)(DSYTrace* tracer);
typedef void (*ErrorListener)(const char* component, int errorCode, ...);

#define CATLMStructsVersion 17
typedef struct {  
  const SystemInfo* (*GetInfo)(int localOnlyFlag, int& pid);
  int (*GetRequestedProducts)(const char*** tab, int& pid);
  unsigned int (*GetProductCount)(int what, int& pid);
  int (*ProductEnum)(char* oname,
                     unsigned int onamesize,
                     void** iocontext,
                     int what,
                     int& pid);
  int (*ProductEnum1)(CATUnicodeString* tab,
                      unsigned int itabsize,
                      void** iocontext,
                      int what,
                      int& pid);
  int (*ProductEnum2)(CATUnicodeString* tab,
                      CATUnicodeString* desc,
                      unsigned int itabsize,
                      void** iocontext,
                      int what,
                      int& pid);
  unsigned int (*GetAllProductCount)(int& pid);
  int (*AllProductEnum)(char* oname,
                        unsigned int onamesize,
                        void** iocontext,
                        int& pid);
  unsigned int (*GetDefaultProductCount)(int w, int& pid);
  int (*DefaultProductEnum)(CATUnicodeString* tab,
                            unsigned int itabsize,
                            void** iocontext,
                            int what,
                            int& pid);
  int (*GetFrameworkLevels)(FrameworkInfo*& tab,
                            unsigned int& fwcount,
                            int& pid);
  unsigned int (*GetFrameworkCount)(int& pid);
  int (*FrameworkEnum)(char* oname,
                       unsigned int onamesize,
                       void** context,
                       int& pid);
  int (*GetWorkbenchStates)(FrameworkInfo*& tab,
                            unsigned int& wbcount,
                            int& pid);
  unsigned int (*GetWorkbenchCount)(int& pid);
  int (*WorkbenchEnum)(char* oname,
                       unsigned int onamesize,
                       void** context,
                       int& pid);
  unsigned int (*GetWorkbenchLicenseCount)(const char* iwbname, int& pid);
  int (*WorkbenchLicenseEnum)(const char* iwbname,
                              char* oname,
                              unsigned int onamesize,
                              void** context,
                              int& pid);
  int (*PreqProductCount)(const char* iname, int& pid);
  int (*PreqProductEnum)(const char* iname,
                         char* oname,
                         unsigned int onamesize,
                         void** context,
                         int& pid);
  int (*AuthProductCount)(const char* iname, int& pid);
  int (*AuthProductEnum)(const char* iname,
                         char* oname,
                         unsigned int onamesize,
                         void** context,
                         int& pid);
  int (*AuthFrameworkCount)(const char* iname, int& pid);
  int (*AuthFrameworkEnum)(const char* iname,
                           char* oname,
                           unsigned int onamesize,
                           void** context,
                           int& pid);
  int (*AllowedWorkbenchCount)(const char* iname, int& pid);
  int (*AllowedWorkbenchEnum)(const char* iname,
                              char* oname,
                              unsigned int onamesize,
                              void** context,
                              int& pid);
  int (*ProductExists)(const char* iname, int& pid);
  int (*FrameworkExists)(const char* iname, int& pid);
  void (*DumpRequested)(FILE* out, int level, int& pid);
  void (*DumpProducts)(FILE* out, int level, int& pid);
  void (*DumpFrameworks)(FILE* out, int level, int& pid);
  void (*DumpWorkbenches)(FILE* out, int level, int& pid);
  int (*RequestProduct)(const CATUnicodeString& iname,
                        int ireqConcLicFlag,
                        int& pid);
  int (*RequestProduct1)(const char* iname, int ireqConcLicFlag, int& pid);
  int (*RequestDirectProducts)(const char** iName,
                               int iNbLic,
                               char iTryIDS,
                               char iReadSettings,
                               char iAllowNodelock,
                               char iDisplayMsg,
                               char iConfigNeeded,
                               char iAllLicNeeded,
                               char iReleaseIfKO,
                               char* oIDSCheckedOut,
                               LicAuthorization** ioRes,
                               int& pid);
  int (*ReleaseProduct)(const CATUnicodeString& iname, int& pid);
  int (*ReleaseProduct1)(const char* iname, int& pid);
  const ProductInfo* (*GetProductInfo)(const char* iname, int& pid);
  AuthorizationStatus (*IsProductAuthorized)(const CATUnicodeString& iname,
                                             unsigned int* oid,
                                             int& pid);
  AuthorizationStatus (*IsProductAuthorized1)(const char* iname,
                                              unsigned int* oid,
                                              int& pid);
  AuthorizationStatus (*IsProductAuthorized2)(unsigned int id, int& pid);
  AuthorizationStatus (*IsFrameworkAuthorized)(const char* iname,
                                               int level,
                                               unsigned int* oid,
                                               int& pid);
  AuthorizationStatus (*IsFrameworkAuthorized1)(unsigned int id,
                                                int level,
                                                int& pid);
  AuthorizationStatus (*IsOptionAuthorized)(const char* iname, int& pid);
  AuthorizationStatus (*IsWorkbenchAllowed)(const char* iname, int& pid);
  AuthorizationStatus (*IsFrameworkIncluded)(const char* iname, int& pid);
  int (*GetUsageCount)(const char* iname,
                       const char* iuid,
                       const char* igid,
                       const char* idisplay,
                       const char* ihost,
                       int& pid);
  const char* (*GetProductName)(unsigned int id, int& pid);
  const char* (*GetFrameworkName)(unsigned int id, int& pid);
  int (*GetNodelockAlertMsg)(int iNbDays, CATUnicodeString& oMsg, int& pid);
  BasicLicenser* (*GetLicenser)(int& pid);
  int (*RequestLicense)(int prodId, int& pid);
  const char* (*GetIDS)(int& pid);
  int (*IsConfigFrozen)(int& pid);  // Don't bring up licensing dialog
  int (*RequestHobbled)(unsigned int productCount,
                        const CATUnicodeString* productTable,
                        int& pid);
  int (*RequestHobbled1)(unsigned int productCount,
                         const char** productTable,
                         int& pid);
  int (*ReleaseHobbled)(int& pid);
  int (*IsHobbled)(ChassisLevel* chassis, int& pid);
  ImportStatus (*AddNodelockLicense)(const char* iCertificatePath, int& pid);
  const char* (*GetNodelockPath)(int* ioIsWritable, int& pid);
  int (*GetLicenseCount)(int iLicenseType,
                         time_t it,
                         const char* inodelockPath,
                         int& pid);
  int (*LicenseEnum)(LicenseInfo itab[],
                     int itabSize,
                     void** iocontext,
                     int& pid);
  int (*isValidComp)(const char* iCompName, const char* iCompExt, int& pid);
  lm_target_id (*GetTargetId)(int& pid);
  StartupMode (*GetStartupMode)(int& pid);
  int (*CheckSignature)(const char* iText,
                        unsigned int iTextLength,
                        const char* iSig,
                        unsigned int iSigLength,
                        int* status,
                        int& pid);
  int (*Process)(const char* iText,
                 unsigned int iTextLength,
                 char** oText,
                 unsigned int* oTextLength,
                 int& pid);
  int (*GetDecodeLicense)(const char* encodingKey, int& pid);
  int (*DecodeBuffer)(const char* encodingKey,
                      char* buffer,
                      unsigned int& length,
                      int& pid);
  ChassisLevel (*IntegerToChassis)(int, int& pid);
  const char* (*ChassisToString)(ChassisLevel, int& pid);
  void (*SetErrorNotify)(ErrorNotifyMethod hardfun, int& pid);
  void (*SetDisplayMsg)(DisplayMsgMethod, int& pid);
  void (*SetExtFunct)(int (*)(char**), int& pid);
  void (*SetWbUpdateFunct)(WbUpdateMethod, int& pid);
  void (*DisplayMsgV)(const char* msgkey,
                      const char* args,
                      va_list args1,
                      int& pid);
  const char* (*GetComputerID)(int& pid);
  int (*BallsTheJobUp)(const char* iProviderName, int& pid);
  int (*SetBatchMode)(int iBatchType, const char** iComputerId, int& pid);
  void (*PrintDbgV)(CATLM::TraceType iType,
                    const char* fmt,
                    va_list args,
                    int& pid);
  CATLM::UserMode (*GetUserMode)(int& pid);
  void (*CleanupDynLicPersistency)(int& pid);
  void (*ActivateDynLicPersistency)(CATUnicodeString& iWarmStartStoragePath,
                                    int& pid);
  int (*RequestDynLicForWarmStart)(CATUnicodeString& iWarmStartStoragePath,
                                   int& pid);
  int (*IsRequestedByWarmStart)(CATUnicodeString& iLicenseName, int& pid);
  void (*AddDynLicInPersistencyFile)(CATUnicodeString& iLicenseName, int& pid);
  const char** (*GetMinFrameworks)(int& pid);
  int (*GetTheBallRolling)(int imode, const char* iClientId, int& pid);
  void (*TheBallHasRolled)(int& pid);
  LicenseStatus (*GetLicenseStatus)(int& pid);
  void (*KickTheBall)(int& pid);
  CATLMPrivate* (*Make)(DSYTrace* tracer,
                        BasicLicenser* lsr,
                        const char* rtvpath,
                        int checkPeriod,
                        int failedCheckPeriod,
                        StartupMode imode,
                        const char* iClientId,
                        int& pid);
  void (*Unmake)(int& pid);
  int (*CAAInitialize)(const char* ipartnerName,
                       unsigned int ipartnerKey,
                       const char* iICPath,
                       CATSysCAALM::RequestCallback ircb,
                       CATSysCAALM::Handle* h,
                       int& pid);
  int (*RequestCAAProduct)(CATSysCAALM::Handle h,
                           const char* iproductName,
                           int& pid);
  int (*ReleaseCAAProduct)(CATSysCAALM::Handle h,
                           const char* iproductName,
                           int& pid);
  int (*CAAStop)(CATSysCAALM::Handle h, int& pid);
  WbUpdateMethod (*GetWbUpdateMethod)(int& pid);
  CheckFunction (*GetCheckFunction)(int& pid);
  void (*SetExitFunction)(ExitFunction fct, int& pid);
  int (*GetServersQueriedFlag)(int& pid);
  const char* (*StatusToMessage)(unsigned int sts,
                                 const char* prefix,
                                 int iDumpServersConfig,
                                 int& pid);
  int (*RequestProductInContext)(const char* context,
                                 const char* product,
                                 int& pid);
  int (*ReleaseProductInContext)(const char* context,
                                 const char* product,
                                 int& pid);
  AuthorizationStatus (*IsProductAuthorizedInContext)(const char* context,
                                                      const char* product,
                                                      int& pid);
  AuthorizationStatus (*IsFrameworkAuthorizedInContext)(const char* context,
                                                        const char* iname,
                                                        int level,
                                                        int& pid);
  void (*SetCheckFailedListener)(void (*CheckFailed)(const char* context,
                                                     const char* product),
                                 int& pid);
  void (*OpenContext)(const char* context, int& pid);
  void (*CloseContext)(const char* context, int& pid);
  int (*GetFailedCheckCount)(int& pid);
  const char* (*GetConsolidation)(int& pid);
  const char* (*GetCustomerId)(int& pid);
  void (*SetErrorListener)(ErrorListener fct, int& pid);
  int (*SetPLM1InfoLegacy)(const char* iUserLogon,
                           const char* iCustomerId,
                           const char** iRichClientAssignedLic,
                           int iNbRichClientAssignedLic,
                           const int* iRichClientAssignedLicCasualUsageValue,
                           const char** iMCSAssignedLic,
                           int iNbMCSAssignedLic,
                           const int* iMCSAssignedLicCasualUsageValue,
                           const char** iMCSAuthorizedPrd,
                           int iNbMCSAuthorizedPrd,
                           const char** iLicServer,
                           int iNbServers,
                           int& pid);

  int (*SetPLM1Info)(const char* iUserLogon,
                     const char** iCustomerIds,
                     int iNbCustomerIds,
                     const char** iRichClientAssignedLic,
                     int iNbRichClientAssignedLic,
                     const int* iRichClientAssignedLicCasualUsageValue,
                     const char** iMCSAssignedLic,
                     int iNbMCSAssignedLic,
                     const int* iMCSAssignedLicCasualUsageValue,
                     const char** iMCSAuthorizedPrd,
                     int iNbMCSAuthorizedPrd,
                     const char** iLicServer,
                     int iNbServers,
                     int& pid);
  AuthorizationStatus (*IsMCSProductAuthorized)(const char* product, int& pid);
  int (*GetGrantedLicenses)(const char*** oLicTab, int& pid);
  int (*SetWorkOfflineLicenses)(const char** oLicTab,
                                int iLicTabSize,
                                int& pid);
  int (*ExtractOfflineAllGranted)(unsigned short iDuration, int& pid);
  int (*RestituteAllOffline)(int& pid);
  const PLM1Info* (*GetPLM1Info)(int& pid);
  int (*RequestToken)(CATUnicodeString& iProductName,
                      int nbTokensToRequest,
                      int& pid);
  int (*GetTokenNumber)(CATUnicodeString& iProductName,
                        int& oNbGrantedTokens,
                        int& pid);
  int (*ReleaseToken)(CATUnicodeString& iProductName,
                      int nbTokensToRelease,
                      int& pid);
  int (*RequestCredit)(CATUnicodeString& iProductName,
                       int nbCreditsToRequest,
                       int& pid);
  int (*GetCreditNumber)(CATUnicodeString& iProductName,
                         int& oNbGrantedCredits,
                         int& pid);
  int (*ReleaseCredit)(CATUnicodeString& iProductName,
                       int nbCreditsToRelease,
                       bool iCommit,
                       int& pid);
  LMMode (*GetMode)(int& pid);
  int (*IsProductInstalled)(const char* iname, int& pid);
  int (*ListAvailableCredits)(CATUnicodeString& iProductName, int& pid);
  void (*SendAPM)(unsigned long iMsg, int& pid);
  AuthorizationStatus (*IsOptionAuthorizedEvenIfNotInstalled)(
      const CATUnicodeString& iOptionName,
      int& pid);
  int (*SynchroDSLContext)(void* iCtx, int& pid);
  int (*SetDraftsightCloudInfo)(const CATUnicodeString &iUserName,
                                const CATUnicodeString &iWhereUsedTenantName,
                                const CATUnicodeString &iWhereAccessedTenant,
                                const CATUnicodeString &iDSLSServerName,
                                int& pid);
  int (*GetMaxOfflineDurationDays)(int& pid);
  int (*RequestWAToken)(CATUnicodeString&   iProductName,
                        int                 nbTokensToRequest,
                        int&                pid);
  int (*ReleaseWAToken)(  CATUnicodeString&     iProductName, 
                          int                   iNbTokenToRelease,
                          int&                  pid);
  int (*RequestWACredit)(CATUnicodeString& iProductName,
                         int               iNbCreditToRequest,
                         int&              pid);
  int (*ReleaseWACredit)(CATUnicodeString&  iProductName,
                         int                nbCreditsToRelease,
                         bool               iCommit,
                         int&               pid);
  int (*ListAvailableTokens)(CATUnicodeString& iProductName, int& pid);
  int (*ListAvailableOfflineLicenses)(CATLM::dsl_available_offline_licenses& oAvailableOfflineLicensesStructure, int& pid);
} CATLMServices;
#endif
