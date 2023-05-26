/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATOmyAsyncMPConstants_H__
#define __CATOmyAsyncMPConstants_H__
#include "CATOmyAsyncSupport.h"
#include "CATOMYCuteIO.h"
#include "CATBinary.h"
#include "CATOmyAsyncProcess.h"

#include "CATOmxVector.h"
#include "CATOmxArray.h"        // for process arguments

class CATOmyAsyncMPManager;
class CATOmyPowerIOMPDeathMsgHandler;

class ExportedByCATOMYCuteIO CATOmyAsyncMPConstants
{
public:
  friend class CATOmyAsyncMPManager;
  friend class CATAsyncServicesClass;
  friend class CATPLMQLAsyncExpandResultHandler;
  friend class CATOmyPowerIOMPDeathMsgHandler;

  //Singleton
  static CATOmyAsyncMPConstants* GetAsyncMPConstants();
  static void DeleteAsyncMPConstants();
  static CATBoolean IsAsyncMaster();

  /**
   * Launch inbProcess with default arguments. @see LaunchProcess (other
   * definition)
   * @param inbProcess The number of arguments
   * @param iWaitForConnect if TRUE, wait that the remote processes connects to the provider
   * @return The result of LaunchProcess
   */
  HRESULT LaunchProcess(int inbProcess, CATBoolean iWaitForConnect=FALSE);

  /**
   * Launch a single process if the number of processes is not reached within the platform
   * anf if no process is initializing
   * Specific full async connection
   *
   * @return S_FALSE if no process has been launched
   *         else The result of LaunchProcess
   */
  HRESULT LaunchProcessIfNeeded();

  /**
   * Remove the process from the platform and launch a new one with the same
   * arguments.
   *
   * If there is no process associated with this transaction ID, calling this
   * method made no sense, then it asserts.
   *
   * @param iTransactionID the transaction id associated with the process
   * @param iKillIt If TRUE, attempt to kill the process in addition, else let
   * him be (it should be killed)
   * @param iWaitForConnect if TRUE, wait that the remote processes connects to the provider
   * @return The result of LaunchProcess on the new process
   */
  HRESULT RemoveProcessAndLaunchAgain(int iTransactionID,CATBoolean iKillIt=FALSE, CATBoolean iWaitForConnect=FALSE);

  /**
   * Launch a specified number of processes.
   *
   * It takes care of
   *       - creating processes, initializing them with transaction IDs
   *       - beginning them (@see CATOmyAsyncProcessImplCATIA::Begin)
   *       - request them to connect to the server
   *
   * It makes sure the process is dead in case it partially was launched and is
   * no usable
   *
   * @param inbProcess the number of processes to launch
   * @param iaArguments The arguments to give to the process (@see CATOmyAsyncProcessImplCATIA::Spawn)
   * @param iWaitForConnect if TRUE, wait that the remote processes connects to the provider
   * @return E_FAIL if cannot launch it, else S_OK
   */
  HRESULT LaunchProcess(int inbProcess, CATOmxArray<CATUnicodeString> iaArguments, CATBoolean iWaitForConnect=FALSE);

  /**
   * Generates a new transaction ID and return it. Every call to this method
   * will give a new and thus usable transaction ID
   * @return A new transaction ID
   */
  int GenerateNewTransactionID();

  /**
   * Creates a process object with the CATIA side implementation, with a default
   * transactionId and a default name.
   *
   * ATTENTION : This method must not be used in the asynchronous process body,
   * because it creates a CATIA Side implementation of it
   *
   * @param oTransactionID the newly created process transaction id, you can
   *                       then get the corresponding process via GetTask
   * @return S_OK
   */
  HRESULT CreateProcess(int &oTransactionID);

  /**
   * Add a process into the internal list of processes structure.
   * The process is given a new unique transaction ID.
   * @param ipProcess the input process, it will not be added in case another
   * process with the same transactionID already exists
   * @return S_OK if the process was correctly inserted. E_FAIL if another
   * process was already assigned to its transaction ID
   */
  HRESULT AddProcess(CATOmyAsyncProcessImplCATIA * ipProcess);

  /**
   * Get the process dealing with a task id
   * @param iTransactionId Id of the task the process is assigned to
   * @return an AddRefed process, NULL if nothing has been found for this task
   */
  CATOmyAsyncProcessImplCATIA* GetTask(int iTransactionId);
  /**
   * Gets the task associated with aa pid instead of a transaction id
   * @param iPid the pid of the process
   * @return The corresponding process
   */
  CATOmyAsyncProcessImplCATIA* GetTaskByPID(int iPid);
  /**
  * Remove a task associated with a specific transaction ID.
  *
  * Be careful when using this method, as it could delete the CATIA
  * representation of a process in memory and thus loose control of its life
  * cycle
  *
  * @param iTransactionID the transaction id of the process to remove
  * @return S_OK if the task was found and removed, else E_FAIL.
  */
  HRESULT RemoveTask(int iTransactionID);
  /**
  * Remove all tasks running
  *
  * Be careful when using this method, as it could delete the CATIA
  * representation of a process in memory and thus loose control of its life
  * cycle
  *
  * @return S_OK if all the tasks were removed, else E_FAIL.
  */
  HRESULT RemoveAllTasks();

  CATOmyAsyncProcessConstants::Appli GetCurrentAppli();
  HRESULT SetCurrentAppli(CATOmyAsyncProcessConstants::Appli iAppliType);

  /**
   * Find a process ready to serve and return it.
   * The process is given a unique transaction ID.
   * @return The new process. NULL if no process is available
   */
  CATOmyAsyncProcessImplCATIA* ReserveProcess();

  inline unsigned int GetWaitingTime() {return _TimeQuantum;};
  inline unsigned int GetLongWaitingTime() {return 10*_TimeQuantum;};
  inline unsigned int GetTimeOutTime() {return _TimeOutTime;};
  inline void IncreaseTimeOut()
  {
    if(_TimeOutTime<(30*_TimeQuantum))
      _TimeOutTime+=_TimeQuantum;
    return;
  };

  /**
   * Get the list of all processes currently in execution
   * @param oListOfProcess Le list of processes
   * @return S_OK (because everything will work fine !!)
   */
  HRESULT RetrieveAllProcess(CATOmxVector<CATOmyAsyncProcessImplCATIA>& oListOfProcess);
  int GetNumberOfProcesses()const;

  /** Not sure what it really means. It seems to be the max of the current
      transaction numbers */
  int _TransactionId;
  int _CATIAProcessPID;
  int _ClientDetected;


  //prevent handler declenching an asynchronous transaction
  CATBoolean _isDuringHandler;

  // Watchcat info
  CATULONG32 GetWatchCatWaitingTime() const {return _WatchCatWaitingTime; }
  CATUnicodeString GetWatchCatLogFileName() const {return _WatchCatLogFileName; }
  CATBoolean GetWatchCatVerbose() const {return _WatchCatVerbose; }
  CATBoolean GetWatchCatTimerDeactivated() const {return _WatchCatTimerDeactivated; }
  CATBoolean GetWatchCatKillingDeactivated() const {return _WatchCatKillingDeactivated; }
  CATUINT32 GetProcessMaxTimeSpentInIdleState() const { return _processMaxTimeSpentInIdleState; }

  CATUnicodeString GetMPConstantUuid()const{return _Uuid;}
  /**
   * Get the CATIA application Id.
   * It must be called to get the name of CATIA in order to communicate with it
   * via backbone.
   * @return The application ID
   */
  CATUnicodeString GetCATIAAppId()const{return _CATIAAppsId;}
  /**
   * Set the CATIA application Id.
   * With it, backbone communication will be done. It must contain less than 32
   * character, because backbone will not look after the 32th char.
   * @param iAppsId The application ID given to CATIA
   */
  void SetCATIAAppId(CATUnicodeString iAppsId);
  CATOmyAsyncProcessConstants::Appli GetCurrentAppli()const{return _CurrentAppli;}
  /**
   * Test if the private backbone feature is enabled
   * @return TRUE if private backbone in enabled, else FALSE
   */
  CATBoolean PrivateBackbone()const{return _privateBackbone;}
  /**
   * Sets the private backbone feature
   * @param iPrivateBackbone TRUE means enabling the feature, false means
   * disable it
   */
  void SetPrivateBackbone(CATBoolean iPrivateBackbone){_privateBackbone = iPrivateBackbone;}

  /**
   * Set the generic backbone handlers, used internally for compatibility
   * between multi backbone and generic one
   */
  void _SetGenericBackBoneHandlers(CATIMessageReceiver * ipiListUrlsAckMsgReceiver,
                                   CATIMessageReceiver * ipiErrorMsgReceiver,
                                   CATIMessageReceiver * ipiRcv);

  /**
   * Get the generic backbone handlers, used internally for compatibility
   * between multi backbone and generic one
   */
  void _GetGenericBackBoneHandlers(CATIMessageReceiver *& opiListUrlsAckMsgReceiver,
                                   CATIMessageReceiver *& opiErrorMsgReceiver,
                                   CATIMessageReceiver *& opiRcv);

  HRESULT SetConnectionParameters(const CATBinary& iBufConn, const char* iRepositoryName, const char* iCookieUrl, const char* iCookieContent);
  CATBinary* GetConnectionBinary() {return _bufConn;}
  const char* GetRepositoryName() {return _RepName.ConvertToChar();}
  const CATUnicodeString GetRepositoryNameStr() { return _RepName; }
  HRESULT GetCookieInfo(CATUnicodeString& oCookieUrl, CATUnicodeString& oCookieContent) {oCookieContent=_CookieContent; oCookieUrl = _CookieUrl;return S_OK;}
  HRESULT SetCookieInfo(CATUnicodeString& iCookieUrl, CATUnicodeString& iCookieContent) {_CookieContent = iCookieContent; _CookieUrl = iCookieUrl;return S_OK;}

  /**
   * Gets the default arguments that could be given to process when launching it
   * with LaunchProcess
   * @return The default arguments
   */
  CATOmxArray<CATUnicodeString> GetProcessDefaultArguments()const{return _processDefaultArguments;}
  /**
   * Sets the default arguments that could be given to process when launching it
   * with LaunchProcess
   * @param iProcessDefaultArguments The default arguments
   */
  void SetProcessDefaultArguments(CATOmxArray<CATUnicodeString> iProcessDefaultArguments){_processDefaultArguments = iProcessDefaultArguments;}

  void SetMasterConnectionStatus(CATBoolean iConnected) {_MasterIsConnected = iConnected;}
  CATBoolean IsMasterConnected() {return _MasterIsConnected;}


private:

  HRESULT InitEnvVariable();
  CATOmyAsyncMPConstants();
  ~CATOmyAsyncMPConstants();

  static CATOmyAsyncMPConstants* _instance;

  CATOmxVector<CATOmyAsyncProcessImplCATIA> _ListProcess;
  /** Default arguments to give to process */
  CATOmxArray<CATUnicodeString> _processDefaultArguments;

  // ####################################################################################################
  // Backbone (used only in case of no private backbone)
  // ####################################################################################################
  CATIMessageReceiver *_piListUrlsAckMsgReceiver;
  CATIMessageReceiver *_piErrorMsgReceiver;
  CATIMessageReceiver *_rcv;

  //Connection params
  CATBinary* _bufConn;


  /** in ms */
  CATUINT32 _TimeQuantum;
  CATUINT32 _TimeOutTime;
  CATUINT32 _asyncProcessNbMilliSecondsBeforeSendingRecordExpand;

  CATUINT32 _NbProcessToStart;
  CATUINT32 _nbLaunchedProcess;
  /** variable used to check the process does not spend too much time in idle
      state (in s) */
  CATUINT32 _processMaxTimeSpentInIdleState;

  CATUINT32 _currentProcessIteration;
  /** Used to mute the process when spawing it (for the client not to see its output) */
  CATUINT32 _processFlags;

  CATUnicodeString _WaitForFile;
  CATUnicodeString _asyncProcessMessageDumpFile;
  CATUnicodeString _Uuid;
  CATUnicodeString _RepName;

  // Watchcat info
  CATULONG32 _WatchCatWaitingTime;
  CATUnicodeString _WatchCatLogFileName;
  CATBoolean _WatchCatVerbose;
  CATBoolean _WatchCatKillingDeactivated;
  CATBoolean _WatchCatTimerDeactivated;
  CATBoolean _IsDebugMode;
  CATBoolean _IsMonitored;
  /** Boolean describing if private backbone is enabled */
  CATBoolean _privateBackbone;
  // Application info
  CATUnicodeString _CATIAAppsId;
  CATOmyAsyncProcessConstants::Appli _CurrentAppli;
  // Gestion du Cookie
  CATUnicodeString _CookieUrl;
  CATUnicodeString _CookieContent;
  CATBoolean _MasterIsConnected;
};

// MACRO that defines a FOR LOOP with a stop condition
#define WHILE_WITH_MAX_TRY(IT,MAX,COND) for(IT=0;IT<MAX&&COND;IT++)

#endif
