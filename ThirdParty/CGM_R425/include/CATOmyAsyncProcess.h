/**
* @level Protected
* @usage U1
*/

#ifndef CATOmyAsyncProcess_H
#define CATOmyAsyncProcess_H

#include "CATOMYCuteIO.h"
#include "CATVVSUrl.h"
#include "CATVVSTransaction.h"
#include "CATOmyVVSAsyncCallBackNotifier.h"
#include "CATOmyPLMQLAsyncCallBackNotifier.h"
#include "CATOmyAsyncProcessConstants.h"
#include "CATIOmyAsyncTaskCompletionCallBack.h"

// backbone
#include "CATIMessageReceiver.h"

#include "CATOmyAsyncProcessWatchCAT.h"

// system
#include "CATUnicodeString.h"
#include "CATOmxArray.h"        // For process arguments
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATBoolean.h"
#include "CATOmxSR.h"

class CATOmyPLMQLAsyncResult;
class CATOmyVVSAsyncResult;

// Backbone
class CATICommunicator;
class CATICommMsg;

// Generic
class CATIOmyPowerIOMPGenericTransactionMsg;

/** Class handling common process operation. It is meant to be redefined
* depending if it is implemented in CATIA or in the async process.
*/
class ExportedByCATOMYCuteIO CATOmyAsyncProcess : public CATBaseUnknown
{
public:

  /**
  * Constructor of the process
  * @param iTransactionId The id of the transaction between the process and
  * CATIA, used to know what the process is doing
  * @param iApplicationId The application identifier of the process, used to
  * communicate with the process via backbone/or in the case of the process to
  * declare itself to backbone
  */

  CATOmyAsyncProcess(int iTransactionId,CATUnicodeString iApplicationId);
  CATOmyAsyncProcess();          // default constructor not meant to be called
  virtual ~CATOmyAsyncProcess(); // default destructor

  // Generic
  CATOmxSR<CATIOmyPowerIOMPGenericTransactionMsg> _GenericMessage;

  //VVS Specific
  CATVVSTransaction* _transaction;
  CATBoolean _isOnlyCheckOut;

  //PLMQL Specific
  CATUnicodeString _XMLQuery;
  CATBoolean _isPushQuery;
  CATListOfCATUnicodeString _listParamName;
  CATListOfCATUnicodeString _listParamValue;

  /**
  * Get the application identifier of the process
  * @return The application identifier of the process
  */
  CATUnicodeString GetAppId()const { return _AppId; }

  /**
  * Set the application identifier of the process
  * @param iAppId The application identifier of the process
  */
  void SetAppId(CATUnicodeString iAppId);

  /**
  * Get the application type for this
  * @return The application type of the process
  */
  CATOmyAsyncProcessConstants::Appli GetCurrentAppli()const { return _CurrentAppli; }

  /**
  * Set the application type of type
  * @param iAppId The application type of the process
  */
  void SetCurrentAppli(CATOmyAsyncProcessConstants::Appli iCurrentAppli) { _CurrentAppli = iCurrentAppli ; }

  // ####################################################################################################
  //  Inter Process Communication (IPC) Control, aimed to communicate with the
  //  relatives (relative = CATIA if in process, process if in CATIA)
  //  ####################################################################################################
  // ******************************************************************************************
  // Waiting messages from the relative
  // ******************************************************************************************
  /**
  * Wait for a message coming from the relative.
  *
  * At the end of the function, the following condition is true
  * - a message has been received on the IPC bus
  * - OR iWaitingTime ms have been waited
  * - OR the IPC mecanism failed AND iWaitingTime ms have not been waited (this
  *   should practicaly never happen)
  *
  * @param iWaitingTime The time to wait, in ms
  * @return S_OK if the message have been caught, else E_*. If the IPC mecanism
  * is not working, return E_* also and do not wait for iWaitingTime ms
  */
  HRESULT IPCWait(unsigned int iWaitingTime)const;

  // ******************************************************************************************
  // Sending messages to the relative
  // ******************************************************************************************
  /**
  * Send a message to the relative process.
  *
  * It must not be redefined by children classes. It first updates the message
  * seen as a CATIOmyPowerIOMPTransactionMsg, that's to say it sets its
  * transactionID and its MessageCount. All other transactionID and
  * MessageCount settings before calling this method will be overriden. It then
  * calls the virtual method SendCustom and returns its result.
  *
  * @param ipiMsg The Message to send
  * @return @see CATICommunicator::SendRequest
  */
  HRESULT IPCSend(CATICommMsg *ipiMsg);

  // ******************************************************************************************
  // Interracting with the IPC mecanism
  // ******************************************************************************************
  /**
  * Setting up the IPC mecanism.
  *
  * WARNING : Do not call this method more than once before calling
  * IPCUnRegister. It has side effects that would cause the program to crash
  *
  * @return S_* if everything went ok (in case of backbone implementation,
  * S_FALSE if reusing generic backbone and multiple registration)
  */
  virtual HRESULT IPCRegister() = 0;

  /**
  * Tears down the IPC mecanism.
  *
  * In case of backbone implementation, removes the handlers associated with
  * the dedicated backbone and release the internal CATICommunicator object, so
  * that the process/CATIA is no more able to talk to CATIA/process.
  *
  * WARNING : Do not call this method before calling IPCRegister and more than
  * once after calling IPCRegister. Also, do not call it before
  * IPCRegister. Unfortunate side effects could be caused so.
  *
  * @return S_OK if everything was OK, (in backbone specific implementation, S_FALSE in the particular case of the
  * generic backbone and multiple unregistration.)
  */
  virtual HRESULT IPCUnRegister() = 0;

  // ******************************************************************************************
  // Backbone specific methods (even though the IPC claims to be as independent
  // as possible)
  // ******************************************************************************************
  /**
  * Gets or create the backbone bus.
  *
  * Though this BUS, the process/CATIA will communicate with CATIA/process
  *
  * @return S_OK
  */
  HRESULT IPCOpenBus();

  /**
  * Request an answer for a specific message.
  *
  * It only calls the GetRequestAnswer method from a CATICommunicator internal
  * object and return its result.
  *
  * @param ipiMsg @see CATICommunicator::GetRequestAnswer
  * @param ippiAnswer @see CATICommunicator::GetRequestAnswer
  * @param iTimeout @see CATICommunicator::GetRequestAnswer
  * @param iNoAnswerMeansNeverReceived indicates thats if the message is not
  * answered, it is considered as never received by other end. The only
  * difference is that the process will decrement a message counter (let's call
  * it MC) and next received message won't be expected to be MC+1 but MC.
  * @return @see CATICommunicator::GetRequestAnswer
  */
  HRESULT IPCGetRequestAnswer(CATICommMsg *ipiMsg, CATICommMsg **ippiAnswer, unsigned int iTimeout, CATBoolean iNoAnswerMeansNeverReceived = TRUE);

  //  ####################################################################################################
  // Process Finite State Machinery
  CATOmyAsyncProcessConstants::State GetOperationState()const{return _OperationState;}
  void SetOperationState(CATOmyAsyncProcessConstants::State iOperationState);

  /**
  * Getter for the current transaction id
  * @return The current transaction id
  */
  int GetCurrentTransactionId()const{return _CurrentTransactionId;}
  /**
  * Seter for the current transaction id
  * @param iTransactionId the current transaction id
  */
  void SetCurrentTransactionId(int iTransactionId);

  /**
  * Get the pid of the process
  * @return The pid of the process
  */
  int GetPID()const { return _PID; }

  /**
  * Set the pid of the process
  * @param iPid the pid of the process
  */
  void SetPID(int iPid) { _PID = iPid; }

  /** Sets the internal variable killFileName
  * Only meant to be used temporarily, waiting for a better architecture.
  */
  void _SetKillFileName();

  /** If the KillFileName used to communicate with the watchCAT exists, delete It */
  void _DeleteKillFileMayBe()const;

  /** Compute the cause of death filename path  */
  void SetCauseOfDeathFileName();

  /**
  * Testor of the message count received by any handler.
  *
  * @param iMessageCountReceived must be 1+ the current received message count. If so, the
  * process store the iMessageCountReceived as new received message count
  * @return S_OK if the received message count is 1+ the current received message count, else E_FAIL
  */
  HRESULT CheckMessageCount(unsigned int iMessageCountReceived);

  CATOmyAsyncProcessWatchCAT* const GetWatchCAT()const { _pWatchCAT->AddRef(); return _pWatchCAT; };

protected:
  /** Communicator element, used to communicate with the process and its own backBone */
  CATICommunicator *_piCommunicator;
  CATIMessageReceiver *_rcv;

  // ####################################################################################################
  //  IPC control
  // ####################################################################################################
  // ******************************************************************************************
  // Send message to the relative
  // ******************************************************************************************
  /**
  * Send a message to the relative.
  *
  * It is meant to be called by Send and must be implemented by children
  * classes
  *
  * @param ipiMsg The message to send
  * @return S_OK if everything was ok, E_* if failed to send the message (IPC
  * mecanism bug for instance). In the specific case of backbone
  * implementation, returns the result of SendRequest @see CATICommunicator::SendRequest.
  */
  virtual HRESULT IPCSendCustom(CATICommMsg *ipiMsg) = 0;
  // ####################################################################################################

  /** WatchCAT associated with the process */
  CATOmyAsyncProcessWatchCAT * _pWatchCAT;

private:
  /** Counter of sent messages, used to check the order of messages transfered
  between CATIA and the asynchronous process */
  unsigned int _messagesCountSent;
  /** Counter of received messages */
  unsigned int _messagesCountReceived;

  /** PID of the process */
  int _PID;

  /** Id of the transaction the current process is on */
  int _CurrentTransactionId;

  /** Type of the process application */
  CATOmyAsyncProcessConstants::Appli _CurrentAppli;

  /** Name of the process, in order to communicate with it via backbone */
  CATUnicodeString _AppId;

  // ####################################################################################################
  // Process Finite State Machinery
  // ####################################################################################################
  CATOmyAsyncProcessConstants::State _OperationState;

  // ####################################################################################################
  // Error handling
  // ####################################################################################################
  CATOmyAsyncProcessConstants::Error _OperationError;
  CATUnicodeString _ErrorMessage;
};

/** Specific implementation of the process to fit catia needs */
class ExportedByCATOMYCuteIO CATOmyAsyncProcessImplCATIA: public CATOmyAsyncProcess
{
public:
  // ####################################################################################################
  // Constructors and destructors
  // ####################################################################################################
  CATOmyAsyncProcessImplCATIA(int iTransactionId,CATUnicodeString iIdentification);
  virtual ~CATOmyAsyncProcessImplCATIA();

  // ####################################################################################################
  // High level methods, mostly using Low Level ones (see below)
  // ####################################################################################################
  /**
  * It registers to the process's Backbone, spawns it and waits for it to send an
  * ack.
  * @param iaArguments The arguments to give to the process
  * @param iWaitForAck Wait for a reponse of the spawned process
  * @see CATOmyAsyncProcessImplCATIA::Spawn for more info on iaArguments
  * @return S_OK if all operations were well done, else E_FAIL. If one
  *        operation fails, it reverts the previous ones and goes no further
  */
  HRESULT Begin(CATOmxArray<CATUnicodeString> iaArguments, CATBoolean iWaitForAck = FALSE);

  /**
  * It kills the process, unregister it from its backbone and then
  * wait for it to be dead. At the end of this method, the caller is sure the
  * process is no more alive.
  *
  * In a particular case, one can call End after the process has been spawned
  * but no backbone wait has been done. In this case, the process is in
  * State_New and nothing will be done. Leading to the presence of a process in
  * memory not killed. Calling End after Begin should normally not cause this
  * problem because Begin does a wait on backbone.
  *
  * @return S_OK if all the operation worked, else E_FAIL. As soon as an
  * operation fails, it does not attempts to do the next ones and return E_FAIL
  */
  HRESULT End();

  // ******************************************************************************************
  // IPC control
  // ******************************************************************************************
  /**
  * Send the connection parameters to the process in order to have it
  * connected.
  *
  * SIDE EFFECT : It also sets the default connection information in the
  * MPConstant
  *
  * @param iBinConn the connection information (username, password)
  * @param iRepName the connection type : TST or M1
  * @param iTransactionType the type of transaction : PLMQL or VVS for the present
  * @param iPrefetchConnection boolean indicating if I want to pre fetch the
  * connection information of if I want to really connect.
  * @param oTransactionId the transaction id associated to this process
  * @return The result of IPCRequestConnect
  */
  HRESULT IPCSendConnectionParameter(CATOmyAsyncProcessConstants::Appli iTransactionType,CATBoolean iPrefetchConnection,int &oTransactionId);

  /**
  * Send the connection parameter to the child process and request it to
  * connect to the sever.
  *
  * @param iPrefetchConnection @see IPCSendConnectionParameter
  * @param iWaitForConnect if the param is set to TRUE
  * the method returns when the main process receive
  * a confirmation of connection from the remode process
  *
  * @return S_OK if the connection successfuly was done,else E_FAIL
  */
  HRESULT IPCRequestConnect(CATBoolean iPrefetchConnection, CATBoolean iWaitForConnect);

  // ####################################################################################################
  // Low level method
  // ####################################################################################################
  // ******************************************************************************************
  // State relative
  // ******************************************************************************************
  /**
  * Update "this" to say the process is connected
  * @return S_OK
  */
  HRESULT MarkAsConnected();

  /**
  * Update "this" to say the process is disconnected
  * @return S_OK
  */
  HRESULT MarkAsDiconnected();

  /**
  * Checks if the process is well connected
  * @return True if the process is connected, else False
  */
  CATBoolean IsConnected() {return _isConnected;}

  // ******************************************************************************************
  // IPC Control
  // ******************************************************************************************
  /**
  * @see CATOmyAsyncProcess::IPCRegister
  */
  virtual HRESULT IPCRegister();

  /**
  * @see CATOmyAsyncProcess::IPCUnRegister
  */
  virtual HRESULT IPCUnRegister();

  /**
  * Wait for a ack from the process.
  *
  * At the end of the method, if the IPC mecanism is ok, the following
  * condition is respected :
  * - OR the CATIOmyPowerIOMPInstanciateAckMsg as been received from the
  * relative process
  * - OR 20 time quanta have been reached (@see CATOmyAsyncMPConstants::_TimeQuantum)
  *
  * FIXME : In current implementation, in case the IPC mecanism is ko, the 20*quanta
  * are waited.
  *
  * @return S_OK if the process correctly answered, else E_FAIL
  */
  HRESULT IPCWaitForAck();

  /**
  * Wait that a connection to the server is done.
  *
  * The only case when it makes sense calling this function is when
  * IPCRequestConnect has just been called.
  *
  * @return S_OK if the connection succeeded, else E_FAIL
  */
  HRESULT IPCWaitForConnection();

  /**
  * Wait for a message coming from backbone.
  *
  * ATTENTION : This method is deprecated and should not be sued anymore
  *
  * @param LongWait true for long wait, false for common wait (see description
  *          of CATOmyAsyncMPConstants for more info about what is long and
  *          common wait)
  * @return The exact result of the Wait method @see CATOmyAsyncProcess::IPCWait
  */
  HRESULT IPCWaitForMessage(CATBoolean iLongWait);

  /**
  * Wait for a death message from the process.
  *
  * It must be used when knowing that the process should die because it flushes
  * the messages coming from the process till its death. If not used, those
  * remaining messages could disturb the normal behavior of the IPC mecanism
  * platform. It CATAssert if the process is in new state because that reflect
  * a problem of conception.
  *
  * If this method is called, the process should have been killed OR the
  * watchCAT should be about to kill it.
  *
  * In the worst case scenario, after WatchCatWaitingTime (@see
  * CATOmyAsyncMPConstants::_WatchCatWaitingTime), the process should really be
  * dead and the message indicating it is dead should be sent.
  *
  * BIG ASSUMPTION : After some time, the communication between catia and its processes is
  * supposed to become IDLE.
  *
  * The method wait for messages coming from the process. It then returns in
  * following conditions :
  * - OR there is no more message to get AND there has been
  *   2*WatchCatWaitingTime (upper bound after what it is considered surely
  *   dead) spent waiting
  *
  * @return S_OK in the case the process got to State DeadAndWaited, else E_FAIL
  */
  HRESULT IPCFlushMessagesAndWaitForDeath();

  // ******************************************************************************************
  // Process control
  // ******************************************************************************************
  int GetProcessFlags()const { return _processFlags; }
  void SetProcessFlags (int iProcessflags) { _processFlags = iProcessflags; }

  /**
  * Spawn the asynchronous process.
  * It takes care of registering to backbone before doing so and internally set
  * the file name in the watchcat. It also delete such file if it already exist
  * to prevent the process to terminate as soon as it has been spawned.
  * @param iaArguments Arguments used to call the process, they must start with
  * the name of the executable. For instance, to call CATAsyncProcess with
  * arguments 3, 4 and 5, you must provide this method with
  * iaArguments = ["CATAsyncprocess","3","4","5"].
  * The arguments may refer to internal variable with pseudo bash syntax, see
  * documentation of CATOmyAsyncProcessImplCATIA::_ComputeArgument for more info
  * @return S_OK if the process was correctly spawned. Else E_FAIL causes of
  *  failure may be : could not aquire autorisation from
  *  DSYSysCPUResourceManager or CATStartProcessEx failed
  */
  HRESULT Spawn(CATOmxArray<CATUnicodeString> iaArguments);

  /**
  * Gets the arguments used in the process. This may be useful when wanting to
  * spawn a similar process.
  * @return The arguments array, as required by Spawn
  */
  CATOmxArray<CATUnicodeString> GetArguments()const{return _aArguments;}

  /**
  * Tests if the process is alive
  * @param oIsAlive TRUE if the process is alive, else FALSE
  * @return S_OK
  */
  HRESULT IsAlive(CATBoolean &oIsAlive)const;
  
  /**
  * @return TRUE if the process death message has been receive
  */
  CATBoolean IsMarkAsDead(){ return _isDead; }
  
  /**
  * Marks the process as dead meaning the process death message has been receive
  */
  void MarkAsDead(){_isDead = TRUE;}

  /**
  * Check if the process does an asynchronous connection to the provider
  * @return TRUE if the connection is asynchrous, FALSE otherwise
  */
  CATBoolean IsAsyncConnection() const { return _asyncConnection; }

  /**
  * Attempt to kill the process, using as last resort the watchCat to do so
  * @return S_OK if everything works fine, S_FALSE if call to the watchcat was
  * needed (be warned that in this case the process may be killed with a little
  * delay around the value of OMY_ASYNC_WATCHCAT_WAITING_TIME), E_FAIL if
  * something went wrong (unable to release DSYCPUResources may return E_FAIL)
  */
  HRESULT Kill();

  /** Ask the process to suicid */
  void AskToSuicid()const;

  /**
  * Wait for the process to really end its work and save its returnCode.  It is
  * equivalent to the meaning of what POSIX wait would mean.
  *
  * At the end of this method, the caller is sure the process is no more alive
  *
  * ATTENTION : This must be called instead of doing a loop waiting for the
  * State_Kill state because it update CATOmyAsyncProcess class static
  * information about the number of processes alive so far
  * @return S_OK if the process finished, else E_FAIL
  */
  HRESULT Wait();

  /**
  * Check if the process is initializing ie is in state <code>State_New</code>,
  * <code>State_WaitForAck</code> or <code>State_WaitForConnect</code>
  *
  * @return TRUE if the process is initializing, FALSE otherwise
  */
  CATBoolean IsInitializing() const;

  // ####################################################################################################
  // Transaction control
  // ####################################################################################################
  /**
  * Get a new transaction ID for current process.
  * POSTCOND : The transaction id of this is unique and may be used to identify
  * the process
  * @return the new transaction ID of the process
  */
  int AssignNewTransactionID();

  // ####################################################################################################
  // Other stuff
  // ####################################################################################################

  // VVS Specific
  CATOmyVVSAsyncCallBackNotifier* _VVSCallbackNotifier;
  CATOmyVVSAsyncResult * _VVSResult;
  CATBoolean _isOnlyCheckOut;

  // PLMQL Specific
  CATOmyPLMQLAsyncCallBackNotifier* _PLMQLCallBackNotifier;
  CATOmyPLMQLAsyncResult * _PLMQLResult;


protected:
  // ####################################################################################################
  // Backbone control
  // ####################################################################################################
  /**
  * Implementation of IPCSendCustom of CATOmyAsyncProcess
  */
  virtual HRESULT IPCSendCustom(CATICommMsg *ipiMsg);

private:

  /** Internal counter used to know how many times a process has been
  *  registered to backbone. It is used only in GENERIC backbone to handle
  *  Registering and UnRegistering. Indeed, I have to Register only once to
  *  backbone and to UnRegister only once also in this case */
  static int _numberOfRegisterBackboneTimes;

  /**
  * Computes the argument used to spawn a process, it is useful to call the
  * process from outside of CATOmyAsyncProcess with a single argument value
  * that will change with the process. For instance, if I want several
  * processes to be spawned with "PROCESS_NAME PROCESS_TRANSACTION" as an
  * argument, I don't want them to be recomputed for each call to Spawn, I
  * prefer using "$NAME $TRANSACTION_ID" and let _ComputeArgument return the
  * correct value for NAME and the correct value for TRANSACTION_ID. For the
  * present, only NAME and TRANSACTION_ID are understood that way :
  * - $NAME : use the name of the process (the app ID)
  * - $TRANSACTION_ID : use the transaction id of the process
  * @param iArgument The input argument
  * @return The value after substitution
  */
  CATUnicodeString _ComputeArgument(CATUnicodeString iArgument) const;

  // ####################################################################################################
  // CPU resources acquirement
  // ####################################################################################################
  /**
  * Acquire the DSYCPUResources and does nothing if not necessary
  * @return S_OK if correctly acquired, S_FALSE if already acquired
  * it, E_FAIL if failed to acquire it
  */
  HRESULT _AcquireDSYCPUResourcesMayBe();

  /** The number of resources acquired. It is updated by _AcquireDSYCPUResourcesMayBe */
  static unsigned int _DSYCPUResourcesAcquired;

  /** The maximum of async processes that have been running at the same time since
  the beginning of CATIA. It is incremented by Spawn because when it knows the process
  has been spawned and decremented by Join since it knows the process has
  died */
  static unsigned int _DSYCPUResourcesTotalNumberOfProcesses;

  // ####################################################################################################
  // Process lifecycle
  // ####################################################################################################
  /** Flags used with CATStartProcessEx when spawning the process */
  int _processFlags;
  /** Arguments given to the process by the spawn method. They are stored to
  allow respawn of the process or outside access */
  CATOmxArray<CATUnicodeString> _aArguments;

  /** The return code of the process. It is set when doing Join */
  int _returnCode;

  // ####################################################################################################
  // Backbone
  // ####################################################################################################
  CATIMessageReceiver *_piListUrlsAckMsgReceiver;
  CATIMessageReceiver *_piErrorMsgReceiver;

  CATBoolean _isConnected;

  CATBoolean _isDead;

  CATBoolean _asyncConnection;

  CATOmyAsyncProcessImplCATIA& operator = ( const CATOmyAsyncProcessImplCATIA&) = delete;
  CATOmyAsyncProcessImplCATIA(const CATOmyAsyncProcessImplCATIA&) = delete;
};

/** Specific implementation of the process to fit the asynchronous process
needs. It is also a SINGLETON, thus forcing the process to use only one
instance of process. */
class ExportedByCATOMYCuteIO CATOmyAsyncProcessImplAsync: public CATOmyAsyncProcess
{
public:
  // ####################################################################################################
  // LifeCycle handling
  // ####################################################################################################
  static CATOmyAsyncProcessImplAsync *GetInstance();
  static void DeleteInstance();

  virtual ~CATOmyAsyncProcessImplAsync();

  // ####################################################################################################
  // IPC Control
  // ####################################################################################################
  virtual HRESULT IPCRegister();
  virtual HRESULT IPCUnRegister();

  // ####################################################################################################
  // WatchCat control
  // ####################################################################################################
  /**
  * Checks if the process has been asked to be killed (used by the WhatchCat)
  * @return True if the process has been asked to suicid by catia, else false
  */
  CATBoolean AskedToSuicid()const;

  /**
  * Sets the remaining time before the WatchCAT kills the process
  * @param iRemainingTime The time before the WatchCAT kills the process (in ms)
  * @return S_OK
  */
  HRESULT SetRemainingTime(CATLONG64 iRemainingTime);

  // ####################################################################################################

  //VVS Specific
  CATOmxArray<CATVVSUrl> _srcUrlList;
  CATOmxArray<CATVVSUrl> _destUrlList;
  CATUnicodeString       _CachePath;

protected:
  // ####################################################################################################
  // IPC control
  // ####################################################################################################
  /**
  * Implementation of IPCSendCustom of CATOmyAsyncProcess
  */
  virtual HRESULT IPCSendCustom(CATICommMsg *ipiMsg);

private:

  // ####################################################################################################
  // Singleton handling
  // ####################################################################################################
  static CATOmyAsyncProcessImplAsync *_pInstance;

  // For the copy methods not to be automatically constructed
  CATOmyAsyncProcessImplAsync& operator = ( const CATOmyAsyncProcessImplAsync&) = delete;
  CATOmyAsyncProcessImplAsync(const CATOmyAsyncProcessImplAsync&) = delete;
  CATOmyAsyncProcessImplAsync(); // Private CTOR for Singleton

  // ####################################################################################################
  // Backbone
  // ####################################################################################################
  CATIMessageReceiver *_piListConnectMsgReceiver;
};


#endif
