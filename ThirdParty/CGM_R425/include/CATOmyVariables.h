// COPYRIGHT DASSAULT SYSTEMES 2011
//===================================================================
//
// CATOmyVariables.h
// Header definition for CATOmyVariables
//
//===================================================================
//
// Usage notes: Development environment variables.
//
//===================================================================
#ifndef CATOmyVariables_H
#define CATOmyVariables_H

/**
 * @level Private
 * @usage U1
 */
#include "CATOMY.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATIAV5Level.h"

#ifndef CATIAR420
#include "CATIOmyAsyncSettingAtt.h"
#endif
class CATUnicodeString;
//-----------------------------------------------------------------------
//rjs braindead
#define RJSBRAINDEAD //pour compatibilité de build

class ExportedByCATOMY CATOmyVariables
{
public:

  /**
   * Checks if the repos name is not supported by the asyncronism platform
   * Supends asynchronism if not
   * @param iRepoName the name of the repository. If NULL, it is considered unsupported
   * @return S_OK if repository is supported, S_FALSE if it is disabled, and in
   * case of problem, E_FAIL. ATTENTION, returning S_OK does not mean the async
   * tasks are enabled.
   * To check if asynchronism if enabled, use
   * CheckAsyncTasksAreAuthorized.
   */
  static HRESULT CheckProviderSupportedForMP(const char * iRepoName, CATBoolean ibAsyncActivation = TRUE);

  /**
  * Determine whether one can performe Async VVS or Async PLMQL
  * @param ibForInit: if TRUE, async is iniatializing, no async call is performed by caller
  *                   some tests are skipped
  */
  static CATBoolean CheckAsyncTasksAreAuthorizedForMP(CATBoolean ibForInit = FALSE);
  static CATBoolean CheckAsyncTasksAreAuthorizedForXMQL(CATBoolean ibForInit = FALSE);

  /**
  * The process have to be launched on the main appli start up if the user's setting option is set
  */
  static CATBoolean LaunchRemoteProcessesOnStartUp();

  /**
  * For UI appplications (CATIA; Delmia...), the asynchronous platform is launched at the same time
  * For Batch, one can activate this behavior with a variable
  * Otherwise, it will be launched at the first asynchronous request
  */
  static CATBoolean CheckCATIAExe();

  /**
  * Async Refresh is authorized only in CATIA exe and if Asynchronous variable is set
  */
  static CATBoolean CheckAsyncRefreshIsAuthorized();

  /**
  * Async Refresh is authorized only in CATIA exe and if Asynchronous variable is set
  */
  static CATBoolean CheckAsyncExpandIsAuthorized();

  /**
  * Async Transitional open is authorized only in SolidWorks exe and if Asynchronous variable is set
  */
  static CATBoolean CheckAsyncTransitionalOpenIsAuthorized();

  /**
  * Async Session Duplicate is authorized only in CATIA exe and if Asynchronous variable is set
  */
  static CATBoolean CheckAsyncSessionDuplicateIsAuthorized();

  /**
  * Set the async platform status
  */
#ifndef CATIAR420
  static void SetAsyncPlatformStatus(AsyncPlatformStatus iAsyncPlatformStatus);
#endif

  /**
  * check whether code is ran in ODT
  */
  static CATBoolean isODTReplay();

  /**
  * Ability to start the platform early in ODT
  */
  static CATBoolean ForceAsyncPlatformStart();

  /** Disables the async tasks */
  static void DisableAsyncTasks();

  /** Suspends the async tasks */
  static void SuspendAsyncTasks();

  /**
  * Check if the remote processes connection is asynchron 
  */
  static CATBoolean IsFullAsyncConnection();

  /**
  * Check if the notifiers of the async platform are on idle
  */
  static CATBoolean IsAsyncPlatformNotifiersOnIdle();
  static CATBoolean IsExternalAuthentificationActivated();

  /**
  * Check if "small files" are buffered in memory
  */
  static CATBoolean IsMemoryBufferActivated();

  /**
  *
  */
  static CATBoolean CheckAsyncVVSIsAuthorizedForMP();

  /**
  *
  */
  static CATBoolean CheckAsyncPLMQLIsAuthorizedForMP();

  /**
  *
  */
  static CATBoolean CheckAsyncGenericIsAuthorizedForMP();

  static CATBoolean DisconnectAsyncProcessWhenMasterDisconnects();

  // Service will return true if string "itg" or "omb" is found in CATGraphicPath
  // In TEST_INDUS_PERFO, it will return FALSE
  static CATBoolean ReplayWithDepartmentConfiguration();

  // Just a repository to store from running code the reason that may fail an UTS
  // and to be able to report it in the final report
  static void SetUTComment(const char * UTComment);
  static void ResetUTComment();
  static const CATUnicodeString& GetUTComment();
  static bool CancelOnStartReentranceAndWait();
  static bool LaunchProcessAtConnect();
  static bool ReplaceMpWithMt();
  static bool SharedFileInCache();
  static bool SharedFilePacketCutter();

  static CATBoolean ActivatePerfoTrace();

private :
  
  /** TRUE if Async tasks have been disabled */
  static CATBoolean _asyncTasksDisabled;

  /** TRUE if Async tasks support the current provider */
  static CATBoolean _providerSupportedForAsync;
};
//-----------------------------------------------------------------------

#endif
