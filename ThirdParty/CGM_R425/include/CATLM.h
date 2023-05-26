#ifndef CATLM_INCLUDE
#define CATLM_INCLUDE

// COPYRIGHT DASSAULT SYSTEMES 1998
//-----------------------------------------------------------------------------
// Abstract:    CATLM CATIA License Manager
//-----------------------------------------------------------------------------

#include "JS0CATLM.h"
#include "JS0ERROR.h"
#include "CATSysCAALM.h"
#include "CATConstantsForThreads.h"
#include "CATSysLMdefine.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>



#ifdef _WINDOWS_SOURCE
#include <windows.h>
#include <winnt.h>
#define CHECKANDGO(a,b) \
    {\
      PIMAGE_DOS_HEADER dH = (PIMAGE_DOS_HEADER) ::GetModuleHandleA(a);\
      if (dH && dH->e_oemid == 0 && dH->e_oeminfo == 0) {\
        PIMAGE_NT_HEADERS ntH = (PIMAGE_NT_HEADERS) ((LPBYTE)dH + dH->e_lfanew);\
        PIMAGE_DATA_DIRECTORY d = &ntH->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];\
        if (d->VirtualAddress != 0 && d->Size >= 0x1000) b;\
      }\
    }
#else
#include <unistd.h>
#   define CHECKANDGO(a,b) b;
#endif

#define CATLM_FWK_OFFSET_01 0x0a /*27*/
#define CATLM_FWK_OFFSET_02 0xe2 /*44*/
#define CATLM_PRD_OFFSET_01 0x44 /*78*/
#define CATLM_PRD_OFFSET_02 0xf5 /*169*/
#define CATLM_PRD_OFFSET_03 0xaa /*184*/

class CATUnicodeString;
class DSYTrace;
class BasicLicenser;
class CATLMPrivate;
class Prod;

class CATLM {

   friend void DllMainBody (int reason);
   friend class CATError;
   friend class XtOrbix;           // pour JPL
   friend class InternalDSProd;
   friend class CATSysCAALM;
   // ODT stuff
   friend class LMTest;
   friend class CATLicenseMgtWindow;
   friend int ODTEntryPoint (int argc, char *argv[]);
   friend int OnInitialize(const char*, int);
   friend void OnFinalize();

   public:

#include "CATLMStructs.h"

   private:
   ExportedByJS0CATLM static CATLMServices& GetCATLM();
   ExportedByJS0CATLM static void GetCATLM(int version, CATLMServices*& services);

   static void crashIfCracked(int pcv) {
#ifdef _WINDOWS_SOURCE
       static int piracyCheckValue = ::GetCurrentProcessId();
#else
       int piracyCheckValue = getpid();
#endif
       if (pcv != piracyCheckValue) {
           void (*f)() = NULL;
           f();
       }
   }
   

   static CATLMServices& GetCATLMServices() {
       static CATLM::CATLMServices* services = NULL;
       if (!services) {
           CHECKANDGO("JS0GROUP", GetCATLM(CATLMStructsVersion, services))
               }
       return *services;
   }

   public:	
   static const SystemInfo *GetInfo(int localOnlyFlag = 0) {
      int pcv = 0; const SystemInfo* result = GetCATLMServices().GetInfo(localOnlyFlag, pcv); crashIfCracked(pcv); return result;
   }
   static int GetRequestedProducts(const char ***tab) {
      int pcv = 0; int result = GetCATLMServices().GetRequestedProducts(tab, pcv); crashIfCracked(pcv); return result;
   }
   static unsigned int GetProductCount (ProductType what = allProductTypes) {
      int pcv = 0; int result = GetCATLMServices().GetProductCount(what, pcv); crashIfCracked(pcv); return result;
   }
   static int ProductEnum (char *oname, unsigned int onamesize, void **iocontext, ProductType what = allProductTypes) {
      int pcv = 0; int result = GetCATLMServices().ProductEnum(oname, onamesize, iocontext, what, pcv); crashIfCracked(pcv); return result;
   }
   static int ProductEnum (CATUnicodeString *tab, unsigned int itabsize, void **iocontext, ProductType what = allProductTypes) {
      int pcv = 0; int result = GetCATLMServices().ProductEnum1(tab, itabsize, iocontext, what, pcv); crashIfCracked(pcv); return result;
   }
   static int ProductEnum (CATUnicodeString *tab, CATUnicodeString *desc, unsigned int itabsize, void **iocontext, ProductType what = allProductTypes) {
      int pcv = 0; int result = GetCATLMServices().ProductEnum2(tab, desc, itabsize, iocontext, what, pcv); crashIfCracked(pcv); return result;
   }
   static unsigned int GetAllProductCount() {
      int pcv = 0; int result = GetCATLMServices().GetAllProductCount(pcv); crashIfCracked(pcv); return result;
   }
   static int AllProductEnum(char *oname, unsigned int onamesize, void **iocontext) {
      int pcv = 0; int result = GetCATLMServices().AllProductEnum(oname, onamesize, iocontext, pcv); crashIfCracked(pcv); return result;
   }
   static unsigned int GetDefaultProductCount (ProductType what = allProductTypes) {
      int pcv = 0; unsigned int result = GetCATLMServices().GetDefaultProductCount (what, pcv); crashIfCracked(pcv); return result;
   }
   static int DefaultProductEnum (CATUnicodeString *tab, unsigned int itabsize, void **iocontext, ProductType what = allProductTypes) {
      int pcv = 0; int result = GetCATLMServices().DefaultProductEnum(tab, itabsize, iocontext, what, pcv); crashIfCracked(pcv); return result;
   }
   static int GetFrameworkLevels(FrameworkInfo *&tab, unsigned int& fwcount) {
      int pcv = 0; int result = GetCATLMServices().GetFrameworkLevels(tab, fwcount, pcv); crashIfCracked(pcv); return result;
   }
   static unsigned int GetFrameworkCount() {
      int pcv = 0; unsigned int result = GetCATLMServices().GetFrameworkCount(pcv); crashIfCracked(pcv); return result;
   }
   static int FrameworkEnum(char *oname, unsigned int onamesize, void **context) {
      int pcv = 0; int result = GetCATLMServices().FrameworkEnum(oname, onamesize, context, pcv); crashIfCracked(pcv); return result;
   }
   static int GetWorkbenchStates(FrameworkInfo *&tab, unsigned int& wbcount) {
      int pcv = 0; int result = GetCATLMServices().GetWorkbenchStates(tab, wbcount, pcv); crashIfCracked(pcv); return result;
   }
   static unsigned int GetWorkbenchCount() {
      int pcv = 0; unsigned int result = GetCATLMServices().GetWorkbenchCount(pcv); crashIfCracked(pcv); return result;
   }
   static int WorkbenchEnum(char *oname, unsigned int onamesize, void **context) {
      int pcv = 0; int result = GetCATLMServices().WorkbenchEnum(oname, onamesize, context, pcv); crashIfCracked(pcv); return result;
   }
   static unsigned int GetWorkbenchLicenseCount(const char *iwbname) {
      int pcv = 0; unsigned int result = GetCATLMServices().GetWorkbenchLicenseCount(iwbname, pcv); crashIfCracked(pcv); return result;
   }
   static int WorkbenchLicenseEnum(const char *iwbname, char *oname, unsigned int onamesize, void **context) {
      int pcv = 0; int result = GetCATLMServices().WorkbenchLicenseEnum(iwbname, oname, onamesize, context, pcv); crashIfCracked(pcv); return result;
   }
   static int PreqProductCount(const char *iname) {
      int pcv = 0; int result = GetCATLMServices().PreqProductCount(iname, pcv); crashIfCracked(pcv); return result;
   }
   static int PreqProductEnum(const char *iname, char *oname, unsigned int onamesize, void **context) {
      int pcv = 0; int result = GetCATLMServices().PreqProductEnum(iname, oname, onamesize, context, pcv); crashIfCracked(pcv); return result;
   }
   static int AuthProductCount(const char *iname) {
      int pcv = 0; int result = GetCATLMServices().AuthProductCount(iname, pcv); crashIfCracked(pcv); return result;
   }
   static int AuthProductEnum(const char *iname, char *oname, unsigned int onamesize, void **context) {
      int pcv = 0; int result = GetCATLMServices().AuthProductEnum(iname, oname, onamesize, context, pcv); crashIfCracked(pcv); return result;
   }
   static int AuthFrameworkCount(const char *iname) {
      int pcv = 0; int result = GetCATLMServices().AuthFrameworkCount(iname, pcv); crashIfCracked(pcv); return result;
   }
   static int AuthFrameworkEnum(const char *iname, char *oname, unsigned int onamesize, void **context) {
      int pcv = 0; int result = GetCATLMServices().AuthFrameworkEnum(iname, oname, onamesize, context, pcv); crashIfCracked(pcv); return result;
   }
   static int AllowedWorkbenchCount(const char *iname) {
      int pcv = 0; int result = GetCATLMServices().AllowedWorkbenchCount(iname, pcv); crashIfCracked(pcv); return result;
   }
   static int AllowedWorkbenchEnum(const char *iname, char *oname, unsigned int onamesize, void **context) {
      int pcv = 0; int result = GetCATLMServices().AllowedWorkbenchEnum(iname, oname, onamesize, context, pcv); crashIfCracked(pcv); return result;
   }
   static int ProductExists(const char *iname) {
      int pcv = 0; int result = GetCATLMServices().ProductExists(iname, pcv); crashIfCracked(pcv); return result;
   }
   static int FrameworkExists(const char *iname) {
      int pcv = 0; int result = GetCATLMServices().FrameworkExists(iname, pcv); crashIfCracked(pcv); return result;
   }
   static void DumpRequested(FILE *out, int level = 0) {
      int pcv = 0; GetCATLMServices().DumpRequested (out, level, pcv); crashIfCracked(pcv);
   }
   static void DumpProducts(FILE *out, int level = 0) {
      int pcv = 0; GetCATLMServices().DumpProducts(out, level, pcv); crashIfCracked(pcv);
   }
   static void DumpFrameworks(FILE *out, int level = 0) {
      int pcv = 0; GetCATLMServices().DumpFrameworks(out, level, pcv); crashIfCracked(pcv);
   }
   static void DumpWorkbenches(FILE *out, int level = 0) {
      int pcv = 0; GetCATLMServices().DumpWorkbenches(out, level, pcv); crashIfCracked(pcv);
   }
   static int RequestProduct(const CATUnicodeString& iname, int ireqConcLicFlag = 0) {
      int pcv = 0; int result = GetCATLMServices().RequestProduct(iname, ireqConcLicFlag, pcv); crashIfCracked(pcv); return result;
   }
   static int RequestProduct(const char *iname, int ireqConcLicFlag = 0) {
      int pcv = 0; int result = GetCATLMServices().RequestProduct1(iname, ireqConcLicFlag, pcv); crashIfCracked(pcv); return result;
   }
   static int RequestDirectProducts(const char **iName, int iNbLic, char iTryIDS = 1, char iReadSettings = 0, char iAllowNodelock = 1, char iDisplayMsg = 1, char iConfigNeeded = 1, char iAllLicNeeded = 0, char iReleaseIfKO = 0, char *oIDSCheckedOut = NULL, LicAuthorization **ioRes = NULL) {
      int pcv = 0; int result = GetCATLMServices().RequestDirectProducts(iName, iNbLic, iTryIDS, iReadSettings, iAllowNodelock, iDisplayMsg, iConfigNeeded, iAllLicNeeded, iReleaseIfKO, oIDSCheckedOut, ioRes, pcv); crashIfCracked(pcv); return result;
   }
   static int ReleaseProduct(const CATUnicodeString& iname) {
      int pcv = 0; int result = GetCATLMServices().ReleaseProduct(iname, pcv); crashIfCracked(pcv); return result;
   }
   static int ReleaseProduct(const char *iname) {
      int pcv = 0; int result = GetCATLMServices().ReleaseProduct1(iname, pcv); crashIfCracked(pcv); return result;
   }
   static const ProductInfo *GetProductInfo(const char *iname) {
      int pcv = 0; const ProductInfo* result = GetCATLMServices().GetProductInfo(iname, pcv); crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsProductAuthorized(const CATUnicodeString& iname, unsigned int *oid = NULL) {
      int pcv = 1; AuthorizationStatus result = GetCATLMServices().IsProductAuthorized(iname, oid, pcv); pcv^=CATLM_PRD_OFFSET_01; crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsProductAuthorized(const char *iname, unsigned int *oid = NULL) {
      int pcv = 1; AuthorizationStatus result = GetCATLMServices().IsProductAuthorized1(iname, oid, pcv); pcv^=CATLM_PRD_OFFSET_02; crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsProductAuthorized(unsigned int id) {
      int pcv = 1; AuthorizationStatus result = GetCATLMServices().IsProductAuthorized2(id, pcv); pcv^=CATLM_PRD_OFFSET_03; crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsFrameworkAuthorized(const char *iname, int level = 0, unsigned int *oid = NULL) {
      int pcv = 1; AuthorizationStatus result = GetCATLMServices().IsFrameworkAuthorized(iname, level, oid, pcv); pcv^=CATLM_FWK_OFFSET_01;  crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsFrameworkAuthorized(unsigned int id, int level = 0) {
      int pcv = 1; AuthorizationStatus result = GetCATLMServices().IsFrameworkAuthorized1(id, level, pcv); pcv^=CATLM_FWK_OFFSET_02;  crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsOptionAuthorized(const char *iname) {
      int pcv = 1; AuthorizationStatus result = GetCATLMServices().IsOptionAuthorized(iname, pcv); pcv^=CATLM_FWK_OFFSET_01; crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsWorkbenchAllowed(const char *iname) {
      int pcv = 0; AuthorizationStatus result = GetCATLMServices().IsWorkbenchAllowed(iname, pcv); crashIfCracked(pcv); return result;
   }
   static AuthorizationStatus IsFrameworkIncluded(const char *iname) {
      int pcv = 0; AuthorizationStatus result = GetCATLMServices().IsFrameworkIncluded(iname, pcv); crashIfCracked(pcv); return result;
   }
   static int GetUsageCount(const char *iname, const char *iuid, const char *igid, const char *idisplay, const char *ihost) {
      int pcv = 0; int result = GetCATLMServices().GetUsageCount(iname, iuid, igid, idisplay, ihost, pcv); crashIfCracked(pcv); return result;
   }
   static const char *GetProductName(unsigned int id) {
      int pcv = 0; const char* result = GetCATLMServices().GetProductName(id, pcv); crashIfCracked(pcv); return result;
   }
   static const char *GetFrameworkName(unsigned int id) {
      int pcv = 0; const char* result = GetCATLMServices().GetFrameworkName(id, pcv); crashIfCracked(pcv); return result;
   }
   static int GetNodelockAlertMsg(int iNbDays, CATUnicodeString &oMsg) {
      int pcv = 0; int result = GetCATLMServices().GetNodelockAlertMsg(iNbDays, oMsg, pcv); crashIfCracked(pcv); return result;
   }
   static BasicLicenser *GetLicenser() {
      int pcv = 0; BasicLicenser* result = GetCATLMServices().GetLicenser(pcv); crashIfCracked(pcv); return result;
   }
   static int RequestLicense(int prodId) {
      int pcv = 0; int result = GetCATLMServices().RequestLicense(prodId, pcv); crashIfCracked(pcv); return result;
   }
   static const char *GetIDS() {
      int pcv = 0; const char* result = GetCATLMServices().GetIDS(pcv); crashIfCracked(pcv); return result;
   }
   static int IsConfigFrozen() {
      int pcv = 0; int result = GetCATLMServices().IsConfigFrozen(pcv); crashIfCracked(pcv); return result;
   }
   static int RequestHobbled(unsigned int productCount, const CATUnicodeString *productTable) {
      int pcv = 0; int result = GetCATLMServices().RequestHobbled(productCount, productTable, pcv); crashIfCracked(pcv); return result;
   }
   static int RequestHobbled(unsigned int productCount, const char **productTable) {
      int pcv = 0; int result = GetCATLMServices().RequestHobbled1(productCount, productTable, pcv); crashIfCracked(pcv); return result;
   }
   static int ReleaseHobbled() {
      int pcv = 0; int result = GetCATLMServices().ReleaseHobbled(pcv); crashIfCracked(pcv); return result;
   }
   static int IsHobbled(ChassisLevel *chassis = NULL) {
      int pcv = 0; int result = GetCATLMServices().IsHobbled(chassis, pcv); crashIfCracked(pcv); return result;
   }
   static ImportStatus AddNodelockLicense(const char *iCertificatePath) {
      int pcv = 0; ImportStatus result = GetCATLMServices().AddNodelockLicense(iCertificatePath, pcv); crashIfCracked(pcv); return result;
   }
   static const char* GetComputerID() {
      int pcv = 0; const char* result = GetCATLMServices().GetComputerID(pcv); crashIfCracked(pcv); return result;
   }
   static int SetPLM1Info(const char*  iUserLogon, const char* iCustomerId,
                          const char** iRichClientAssignedLic, int iNbRichClientAssignedLic, const int* iRichClientAssignedLicCasualUsageValue, 
                          const char** iMCSAssignedLic,        int iNbMCSAssignedLic,        const int* iMCSAssignedLicCasualUsageValue, 
                          const char** iMCSAuthorizedPrd,      int iNbMCSAuthorizedPrd, 
                          const char** iLicServer, int iNbServers)  {
       int pcv = 0; int result = GetCATLMServices().SetPLM1Info(iUserLogon, &iCustomerId, 1,
                                                                iRichClientAssignedLic,  iNbRichClientAssignedLic, iRichClientAssignedLicCasualUsageValue,
                                                                iMCSAssignedLic,iNbMCSAssignedLic,iMCSAssignedLicCasualUsageValue,
                                                                iMCSAuthorizedPrd, iNbMCSAuthorizedPrd, 
                                                                iLicServer, iNbServers, pcv);
       crashIfCracked(pcv); return result;
   }
   static int SetPLM1Info(const char* iUserLogon, 
                          const char** iCustomerIds,           int iNbCustomerIds,
                          const char** iRichClientAssignedLic, int iNbRichClientAssignedLic, const int* iRichClientAssignedLicCasualUsageValue, 
                          const char** iMCSAssignedLic,        int iNbMCSAssignedLic,        const int* iMCSAssignedLicCasualUsageValue, 
                          const char** iMCSAuthorizedPrd,      int iNbMCSAuthorizedPrd, 
                          const char** iLicServer, int iNbServers)  {
       int pcv = 0; 
       int result = GetCATLMServices().SetPLM1Info(iUserLogon,
                                                   iCustomerIds, iNbCustomerIds,
                                                   iRichClientAssignedLic,  iNbRichClientAssignedLic, iRichClientAssignedLicCasualUsageValue,
                                                   iMCSAssignedLic,iNbMCSAssignedLic,iMCSAssignedLicCasualUsageValue,
                                                   iMCSAuthorizedPrd, iNbMCSAuthorizedPrd, 
                                                   iLicServer, iNbServers, pcv);
       crashIfCracked(pcv); return result;
   }


   static int BallsTheJobUp(const char* iProviderName) {
      int pcv = 0; int result = GetCATLMServices().BallsTheJobUp(iProviderName, pcv); crashIfCracked(pcv); return result;
   }
   static int SetBatchMode(int iBatchType, const char** iComputerId=NULL ) {
      int pcv = 0; int result = GetCATLMServices().SetBatchMode(iBatchType, iComputerId, pcv); crashIfCracked(pcv); return result;
   }
   static void PrintDbg(CATLM::TraceType iType,const char* fmt,...) {
      va_list args;
      va_start(args, fmt);
      int pcv = 0; GetCATLMServices().PrintDbgV(iType, fmt, args, pcv); crashIfCracked(pcv);
      va_end(args);
   }

   static int isValidComp(const char* iCompName, const char* iCompExt) {
      int pcv = 0; int result = GetCATLMServices().isValidComp(iCompName, iCompExt, pcv); crashIfCracked(pcv); return result;
   }
   static StartupMode GetStartupMode() {
      int pcv = 0; StartupMode result = GetCATLMServices().GetStartupMode(pcv); crashIfCracked(pcv); return result;
   }
   static CATLM::UserMode GetUserMode() {
      int pcv = 0; CATLM::UserMode result = GetCATLMServices().GetUserMode(pcv); crashIfCracked(pcv); return result;
   }
   static lm_target_id GetTargetId() {
      int pcv = 0; lm_target_id result = GetCATLMServices().GetTargetId(pcv); crashIfCracked(pcv); return result;
   }
   static const char *GetNodelockPath(int *ioIsWritable = NULL) {
      int pcv = 0; const char* result = GetCATLMServices().GetNodelockPath(ioIsWritable, pcv); crashIfCracked(pcv); return result;
   }
   static int GetLicenseCount(LicenseSource iLicenseType, time_t it = CATLM_CURRENT_TIME_FILTER, const char *inodelockPath = NULL) {
      int pcv = 0; int result = GetCATLMServices().GetLicenseCount(iLicenseType, it, inodelockPath, pcv); crashIfCracked(pcv); return result;
   }
   static int LicenseEnum(LicenseInfo itab[], int itabSize, void **iocontext) {
      int pcv = 0; int result = GetCATLMServices().LicenseEnum(itab, itabSize, iocontext, pcv); crashIfCracked(pcv); return result;
   }

   static int CheckSignature(const char *iText, unsigned int iTextLength, const char *iSig, unsigned int iSigLength, int *status = NULL) {
      int pcv = 0; int result = GetCATLMServices().CheckSignature(iText, iTextLength, iSig, iSigLength, status, pcv); crashIfCracked(pcv); return result;
   }
   static int Process(const char *iText, unsigned int iTextLength, char **oText, unsigned int *oTextLength) {
      int pcv = 0; int result = GetCATLMServices().Process(iText, iTextLength, oText, oTextLength, pcv); crashIfCracked(pcv); return result;
   }
   static int GetDecodeLicense(const char *encodingKey) {
      int pcv = 0; int result = GetCATLMServices().GetDecodeLicense(encodingKey, pcv); crashIfCracked(pcv); return result;
   }
   static int DecodeBuffer(const char *encodingKey,char *buffer, unsigned int &length) {
      int pcv = 0; int result = GetCATLMServices().DecodeBuffer(encodingKey, buffer, length, pcv); crashIfCracked(pcv); return result;
   }
   static ChassisLevel IntegerToChassis(int i) {
      int pcv = 0; ChassisLevel result = GetCATLMServices().IntegerToChassis(i, pcv); crashIfCracked(pcv); return result;
   }
   static const char *ChassisToString(ChassisLevel chassis) {
      int pcv = 0; const char* result = GetCATLMServices().ChassisToString(chassis, pcv); crashIfCracked(pcv); return result;
   }
   static void SetErrorNotify(ErrorNotifyMethod hardfun) {
      int pcv = 0; GetCATLMServices().SetErrorNotify(hardfun, pcv); crashIfCracked(pcv);
   }
   static void SetDisplayMsg(DisplayMsgMethod m) {
      int pcv = 0; GetCATLMServices().SetDisplayMsg(m, pcv); crashIfCracked(pcv);
   }
   static void SetExtFunct(int (*f)(char **)) {
      int pcv = 0; GetCATLMServices().SetExtFunct(f, pcv); crashIfCracked(pcv);
   }
   static void SetWbUpdateFunct(WbUpdateMethod m) {
      int pcv = 0; GetCATLMServices().SetWbUpdateFunct(m, pcv); crashIfCracked(pcv);
   }
   static void DisplayMsg(const char *msgkey, const char *args, ...) {
      va_list args1;
      va_start(args1, args);
      int pcv = 0; GetCATLMServices().DisplayMsgV(msgkey, args, args1, pcv); crashIfCracked(pcv);
      va_end(args1);
   }
   static void CleanupDynLicPersistency() {
      int pcv = 0; GetCATLMServices().CleanupDynLicPersistency(pcv); crashIfCracked(pcv);
   }
   static void ActivateDynLicPersistency(CATUnicodeString &iWarmStartStoragePath) {
      int pcv = 0; GetCATLMServices().ActivateDynLicPersistency(iWarmStartStoragePath, pcv); crashIfCracked(pcv);
   }
   static int RequestDynLicForWarmStart(CATUnicodeString &iWarmStartStoragePath) {
      int pcv = 0; int result = GetCATLMServices().RequestDynLicForWarmStart(iWarmStartStoragePath, pcv); crashIfCracked(pcv); return result;
   }
   static int IsRequestedByWarmStart(CATUnicodeString &iLicenseName) {
      int pcv = 0; int result = GetCATLMServices().IsRequestedByWarmStart(iLicenseName, pcv); crashIfCracked(pcv); return result;
   }
   static void AddDynLicInPersistencyFile(CATUnicodeString &iLicenseName) {
      int pcv = 0; GetCATLMServices().AddDynLicInPersistencyFile(iLicenseName, pcv); crashIfCracked(pcv);
   }
   static const char **GetMinFrameworks() {
      int pcv = 0; const char** result = GetCATLMServices().GetMinFrameworks(pcv); crashIfCracked(pcv); return result;
   }
   static int GetTheBallRolling(int imode = startupCNext, const char *iClientId = NULL) {
      int pcv = 0; int result = GetCATLMServices().GetTheBallRolling(imode, iClientId, pcv); crashIfCracked(pcv); return result;
   }
   static void TheBallHasRolled() {
      int pcv = 0; GetCATLMServices().TheBallHasRolled(pcv); crashIfCracked(pcv);
   }
   static LicenseStatus GetLicenseStatus() {
      int pcv = 0; LicenseStatus result = GetCATLMServices().GetLicenseStatus(pcv); crashIfCracked(pcv); return result;
   }
   static void KickTheBall() {
      int pcv = 0; GetCATLMServices().KickTheBall(pcv); crashIfCracked(pcv);
   }

   protected:	
   static CATLMPrivate *Make(DSYTrace *tracer = NULL, BasicLicenser *lsr = NULL, const char *rtvpath = NULL, int checkPeriod = 0, int failedCheckPeriod = 0, StartupMode imode = startupCNext, const char *iClientId = NULL) {
      int pcv = 0; CATLMPrivate* result = GetCATLMServices().Make(tracer, lsr, rtvpath, checkPeriod, failedCheckPeriod, imode, iClientId, pcv); crashIfCracked(pcv); return result;
   }
   static void SendAPM(unsigned long iMsg) {
     int pcv = 0;
     GetCATLMServices().SendAPM(iMsg, pcv);
     crashIfCracked(pcv);     
   }

   public:
   static void Unmake() {
      int pcv = 0; GetCATLMServices().Unmake(pcv); crashIfCracked(pcv);
   }
   static int CAAInitialize(const char *ipartnerName, unsigned int ipartnerKey, const char *iICPath, CATSysCAALM::RequestCallback ircb, CATSysCAALM::Handle *h) {
      int pcv = 0; int result = GetCATLMServices().CAAInitialize(ipartnerName, ipartnerKey, iICPath, ircb, h, pcv); crashIfCracked(pcv); return result;
   }
   static int RequestCAAProduct(CATSysCAALM::Handle h, const char *iproductName) {
      int pcv = 0; int result = GetCATLMServices().RequestCAAProduct(h, iproductName, pcv); crashIfCracked(pcv); return result;
   }
   static int ReleaseCAAProduct(CATSysCAALM::Handle h, const char *iproductName) {
      int pcv = 0; int result = GetCATLMServices().ReleaseCAAProduct(h, iproductName, pcv); crashIfCracked(pcv); return result;
   }
   static int CAAStop(CATSysCAALM::Handle h) {
      int pcv = 0; int result = GetCATLMServices().CAAStop(h, pcv); crashIfCracked(pcv); return result;
   }
   static WbUpdateMethod GetWbUpdateMethod() {
      int pcv = 0; WbUpdateMethod result = GetCATLMServices().GetWbUpdateMethod(pcv); crashIfCracked(pcv); return result;
   }
   static CheckFunction GetCheckFunction() {
      int pcv = 0; CheckFunction result = GetCATLMServices().GetCheckFunction(pcv); crashIfCracked(pcv); return result;
   }
   static void SetExitFunction(ExitFunction fct) {
      int pcv = 0; GetCATLMServices().SetExitFunction(fct, pcv); crashIfCracked(pcv);
   }
   static int GetServersQueriedFlag() {
      int pcv = 0; int result = GetCATLMServices().GetServersQueriedFlag(pcv); crashIfCracked(pcv); return result;
   }
   static unsigned int GetProductCount (int what) {
      return GetProductCount ((ProductType)what);
   }
   static int ProductEnum (char *oname, unsigned int onamesize, void **iocontext, int what) {
       return ProductEnum (oname, onamesize, iocontext, (ProductType) what);
   }
   static int GetLicenseCount(int iLicenseType, time_t it = CATLM_CURRENT_TIME_FILTER, const char *inodelockPath = NULL) {
      int pcv = 0; int result = GetCATLMServices().GetLicenseCount((LicenseSource)iLicenseType, it, inodelockPath, pcv); crashIfCracked(pcv); return result;
   }

   static const char* StatusToMessage(unsigned int sts, const char *prefix, int iDumpServersConfig) {
      int pcv = 0; const char* result = GetCATLMServices().StatusToMessage(sts, prefix, iDumpServersConfig, pcv); crashIfCracked(pcv); return result;
   }

   static int RequestProductInContext(const char* context, const char* product) {
      int pcv = 0; int result = GetCATLMServices().RequestProductInContext(context, product, pcv); crashIfCracked(pcv); return result;
   }

   static int ReleaseProductInContext(const char* context, const char* product) {
      int pcv = 0; int result = GetCATLMServices().ReleaseProductInContext(context, product, pcv); crashIfCracked(pcv); return result;
   }

   static AuthorizationStatus IsProductAuthorizedInContext(const char* context, const char* product) {
      int pcv = 0; AuthorizationStatus result = GetCATLMServices().IsProductAuthorizedInContext(context, product, pcv); crashIfCracked(pcv); return result;
   }

   static AuthorizationStatus IsFrameworkAuthorizedInContext(const char* context, const char *iname, int level) {
      int pcv = 0; AuthorizationStatus result = GetCATLMServices().IsFrameworkAuthorizedInContext(context, iname, level, pcv); crashIfCracked(pcv); return result;
   }

   static void SetCheckFailedListener(void (*CheckFailed)(const char* context, const char* product)) {
      int pcv = 0; GetCATLMServices().SetCheckFailedListener(CheckFailed, pcv); crashIfCracked(pcv);
   }

   static void OpenContext(const char* context) {
      int pcv = 0; GetCATLMServices().OpenContext(context, pcv); crashIfCracked(pcv);
   }

   static void CloseContext(const char* context) {
      int pcv = 0; GetCATLMServices().CloseContext(context, pcv); crashIfCracked(pcv);
   }
   static int GetFailedCheckCount() {
      int pcv = 0; int result = GetCATLMServices().GetFailedCheckCount(pcv); crashIfCracked(pcv); return result;
   }
   static const char* GetConsolidation() {
      int pcv = 0; const char* result = GetCATLMServices().GetConsolidation(pcv); crashIfCracked(pcv); return result;
   }
   static const char* GetCustomerId() {
      int pcv = 0; const char* result = GetCATLMServices().GetCustomerId(pcv); crashIfCracked(pcv); return result;
   }
   static int RetrieveLicenses () {
      /*DEPRECATED: TO BE REMOVED*/
      return -1;
   }
   static AuthorizationStatus IsMCSProductAuthorized (const char* product) {
      int pcv = 0; AuthorizationStatus result = GetCATLMServices().IsMCSProductAuthorized(product, pcv); crashIfCracked(pcv); return result;
   }
   static int GetGrantedLicenses(const char*** oLicTab) {
        int pcv = 0; int result = GetCATLMServices().GetGrantedLicenses(oLicTab, pcv); crashIfCracked(pcv); return result;
    }
    static int SetWorkOfflineLicenses(const char** oLicTab, int iLicTabSize) {
        int pcv = 0; int result = GetCATLMServices().SetWorkOfflineLicenses(oLicTab, iLicTabSize, pcv); crashIfCracked(pcv); return result;
    }
  static int ExtractOfflineAllGranted(unsigned short iDuration) {
        int pcv = 0; int result = GetCATLMServices().ExtractOfflineAllGranted(iDuration, pcv); crashIfCracked(pcv); return result;
    }
  static int GetMaxOfflineDurationDays() {
      int pcv = 0; int result = GetCATLMServices().GetMaxOfflineDurationDays(pcv); crashIfCracked(pcv); return result;
  }
  static int ListAvailableOfflineLicenses(CATLM::dsl_available_offline_licenses& oAvailableOfflineLicensesStructure) {
      int pcv = 0; int result = GetCATLMServices().ListAvailableOfflineLicenses(oAvailableOfflineLicensesStructure, pcv); crashIfCracked(pcv); return result;
  }
  static int RestituteAllOffline() {
        int pcv = 0; int result = GetCATLMServices().RestituteAllOffline(pcv); crashIfCracked(pcv); return result;
    }
  static const PLM1Info* GetPLM1Info() {
        int pcv = 0; const PLM1Info* result = GetCATLMServices().GetPLM1Info(pcv); crashIfCracked(pcv); return result;
    }
  static int  RequestToken (CATUnicodeString &iProductName, int iNbTokensToRequest) {
        int pcv = 0; int result = GetCATLMServices().RequestToken(iProductName, iNbTokensToRequest, pcv); crashIfCracked(pcv); return result;
  }
  static int  RequestWAToken(CATUnicodeString& iProductName, int iNbTokensToRequest) {
      int pcv = 0; int result = GetCATLMServices().RequestWAToken(iProductName, iNbTokensToRequest, pcv); crashIfCracked(pcv); return result;
  }
  static int  ReleaseToken (CATUnicodeString &iProductName, int iNbTokensToRelease) {
        int pcv = 0; int result = GetCATLMServices().ReleaseToken(iProductName, iNbTokensToRelease, pcv); crashIfCracked(pcv); return result;
  }
  static int  ReleaseWAToken(CATUnicodeString& iProductName, int iNbTokensToRelease) {
      int pcv = 0; int result = GetCATLMServices().ReleaseWAToken(iProductName, iNbTokensToRelease, pcv); crashIfCracked(pcv); return result;
  }
  static int  GetTokenNumber (CATUnicodeString &iProductName, int &oNbGrantedTokens) {
        int pcv = 0; int result = GetCATLMServices().GetTokenNumber(iProductName, oNbGrantedTokens, pcv); crashIfCracked(pcv); return result;
  }
  static int ListAvailableTokens(CATUnicodeString& iProductName) {
        int pcv = 0; int result = GetCATLMServices().ListAvailableTokens(iProductName, pcv); crashIfCracked(pcv); return result;
  }
  static int  RequestCredit(CATUnicodeString &iProductName, int iNbCreditsToRequest) {
      int pcv = 0; int result = GetCATLMServices().RequestCredit(iProductName, iNbCreditsToRequest, pcv); crashIfCracked(pcv); return result;
  }
  static int  RequestWACredit(CATUnicodeString& iProductName, int iNbCreditsToRequest) {
      int pcv = 0; int result = GetCATLMServices().RequestWACredit(iProductName, iNbCreditsToRequest, pcv); crashIfCracked(pcv); return result;
  }
  static int  ReleaseCredit(CATUnicodeString &iProductName, int iNbCreditsToRelease, bool iDontCommitCredit) {
      int pcv = 0; int result = GetCATLMServices().ReleaseCredit(iProductName, iNbCreditsToRelease, iDontCommitCredit,  pcv); crashIfCracked(pcv); return result;
  }
  static int  ReleaseWACredit(CATUnicodeString& iProductName, int iNbCreditsToRelease, bool iDontCommitCredit) {
      int pcv = 0; int result = GetCATLMServices().ReleaseWACredit(iProductName, iNbCreditsToRelease, iDontCommitCredit, pcv); crashIfCracked(pcv); return result;
  }
  static int  GetCreditNumber(CATUnicodeString &iProductName, int &oNbGrantedCredits) {
      int pcv = 0; int result = GetCATLMServices().GetCreditNumber(iProductName, oNbGrantedCredits, pcv); crashIfCracked(pcv); return result;
  }
  static int ListAvailableCredits(CATUnicodeString &iProductName) {
    int pcv = 0;
    int result = GetCATLMServices().ListAvailableCredits(iProductName, pcv);
    crashIfCracked(pcv);
    return result;
  }
  static CATLM::LMMode GetMode() {
    int pcv = 0;
    CATLM::LMMode result = GetCATLMServices().GetMode(pcv);
    crashIfCracked(pcv);
    return result;
  }
  static int IsProductInstalled(const char* iname) {
    int pcv = 0;
    int result = GetCATLMServices().IsProductInstalled(iname, pcv);
    crashIfCracked(pcv);
    return result;
  }
  static AuthorizationStatus IsOptionAuthorizedEvenIfNotInstalled(
      const CATUnicodeString &iOptionName) {
    int pcv = 0;
    AuthorizationStatus result = GetCATLMServices().IsOptionAuthorizedEvenIfNotInstalled(iOptionName, pcv);
    crashIfCracked(pcv);
    return result;
  };
  static int SynchroDSLContext(void* iContext) {
	  int pcv = 0;
	  int result = GetCATLMServices().SynchroDSLContext(iContext, pcv);
	  crashIfCracked(pcv);
	  return result;
  };
  static int SetDraftsightCloudInfo(
      const CATUnicodeString& iUserName,
      const CATUnicodeString& iWhereUsedTenantName,
      const CATUnicodeString& iWhereAccessedTenant,
      const CATUnicodeString& iDSLSServerName) {
    int pcv = 0;
    int result = GetCATLMServices().SetDraftsightCloudInfo(
        iUserName, iWhereUsedTenantName, iWhereAccessedTenant, iDSLSServerName,
        pcv);
    crashIfCracked(pcv);
    return result;
  };
 protected:
   static void SetErrorListener(ErrorListener listener) {
      int pcv = 0; GetCATLMServices().SetErrorListener(listener, pcv); crashIfCracked(pcv);
   }
};
#endif
