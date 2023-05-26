#ifndef CATOmySessionRecordManager_h
#define CATOmySessionRecordManager_h

/**
 * @level Protected
 * @usage U4
 */
#include "CATBoolean.h"
#include "CATOMYBaseSession.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATIPLMMaintenanceTubeErrorReporter.h"
#include "CATOmxPair.h"

class CATOmyStorageHandler;
class CATOmyStreamHandler;
class CATHashDico;
class CATIComSidlStreamTube;
class CATIOmyRecordAuthorizationErrorReporter;
class CATListValCATUnicodeString;
class CATIOmySessionRecordManager_var;
class CATOmySessionImageDescriptor;

#undef CATPLMTubeFactoryErrorSimulatorServices

/**
* Session data recording is handled through a singleton initialized through InitSessionRecordManager
* and released via UnsetSessionRecordManager. Those services expose all the necessary services for
* session recoding.
*/
enum RecordMode { undefined, norecord, record, replay, messages, online, offline, offlineauto };



class ExportedByCATOMYBaseSession CATOmySessionRecordServices
{
public:
  enum QueueForceRecordType { noforcerecord, collab };
  /**
  * Indicate is a recording manager is active.
  *
  * @return
  *   TRUE if a recording manager is active, FALSE if no active manager is running or if it is a replaying one.
  *
  */
  static CATBoolean IsRecording();

  /**
  * Indicate is a replaying manager is active.
  *
  * @return
  *   TRUE if a replaying manager is active, FALSE if no active manager is running or if it is a recording one.
  *
  */
  static CATBoolean IsReplaying();

  /**
  * Indicate catia has been launched in offline mode.
  *
  * @return
  *   TRUE if catia has been launched in offline mode, FALSE if normal connected mode or PLMMaintenance mode.
  *
  */
  static CATBoolean IsOffline();
  static CATBoolean IsOnline();
  static CATBoolean IsOfflineAuto();

  /**
  * Check the validity of the current mode. To be called after connection !
  */
  static HRESULT CheckModeAuthorization();

  /**
  * Specify the reporter to be used when an authorization error is found
  */
  static HRESULT SetAuthorizationErrorReporter(CATIOmyRecordAuthorizationErrorReporter *);

  /**
  * Initialize the session record manager. Should only be called once by session.
  *
  * @param iPathToRecordData [in]
  *   Path to the file where to find the record data (if iMode==replay) or path to the directory
  *   where the record data will be created (if iMode==record). In this second case the generated
  *   file will follow pattern YYYY-MM-DD-HH-mm-ss.CATMaintenance).
  * @param iMode [in]
  *   Specifies the replay/record status for the current session. If this mode is set to norecord
  *   and the path isn't null, the node will be computed with the following behavior:
  *     - If the path points to a read/write accessible file, the replay mode is triggered
  *     - If the path points to a wirte accessible directory, the record mode is triggered
  *
  * @return
  *   E_FAIL if a record manager has already been initialized, S_FALSE, if default has been initialized,
  *   S_OK if a manager has been initilaized
  */
  static HRESULT InitSessionRecordManager(const char * iPathToRecordData = NULL, RecordMode iMode = undefined);

  /**
  * Initialize the record data from the image directory. Only effective for online or offline mode as we
  * wouldn't know otherwise where to collect the logon data before the image selection.
  */
  static HRESULT InitRecordDataFromImage(CATOmySessionImageDescriptor * iSID);
  

  /**
  * Unsets the session recorder. Should be called only once at the end of the session.
  */
  static void UnsetSessionRecordManager();

  static HRESULT GetPathToCache(CATUnicodeString & oPathToCache);

  
  /*
  * There may be some data not initialized because we want to get path to record data before initialized it
  * This should be simplified, initialization should be done at the correct time.
  */
  static HRESULT InitializeFromCurrentLocalSaveImage();

  static CATUnicodeString GetPathToRecordData();

  /**
  * Open the current local save storage.
  *
  * @param iOpenMode [in]
  *   Open for the storage. Depends on what you want make of it. Expected values are STGM_READ,
  *   STGM_WRITE and STGM_READWRITE.
  * @return
  *   If the current session manager handles the local save data, retrieve the associated storage,
  *   else return NULL.
  */
  static CATOmyStorageHandler * OpenLocalSaveStorage(DWORD iOpenMode);


  /**
  * Open the current local save storage.
  *
  * @param iOpenMode [in]
  *   Open for the storage. Depends on what you want make of it. Expected values are STGM_READ,
  *   STGM_WRITE and STGM_READWRITE.
  * @return
  *   If the current session manager handles the local save data, retrieve the associated storage,
  *   else return NULL.
  */
  static CATOmyStorageHandler * OpenLocalVaultStorage(DWORD iOpenMode);

  /**
  * Instanciate an sidl tube from the given connection parameters. This tube will be wrapped to
  * authorize recording (record mode) or even faking the real communication tube (replay mode).
  *
  * @param iConnectionParameters [in]
  *   The connection parameters as defined in CATComSidlCreateStreamTube
  * @param oTrs [out]
  *   The resulting tube. May be null if the current session doesn't have any record manager.
  * @return
  *   S_OK if everything is ok, else E0_*
  */
  static HRESULT CreateTube(CATHashDico *iConnectionParameters, CATIComSidlStreamTube**oTrs);

  /**
  * Add the given log info to the current log.
  *
  * @param iThem [in]
  *   A distinctive name for your information. May be used to extract only relevant type of informations
  * @param iOperation [in]
  *   The name of the operation. May be used to extract only relevant type of informations
  * @param iInfos [in]
  *   The various informations are expected as a key, followed by a value, that will be displayed as key=value;
  */
  static void AddLogInfos(const CATUnicodeString& iThem, const CATUnicodeString& iOperation, const CATListValCATUnicodeString& iInfos);

  static HRESULT SetTubeErrorReporter(CATIPLMMaintenanceTubeErrorReporter * iReporter);
  static void ReportTubeError(const PLMMaintenanceTubeTubeErrorType iErrorType,
    const CATUnicodeString & iProcessor = "", const CATUnicodeString &  iPLMQL = "");

  static HRESULT StartForceRecording(const CATUnicodeString & iMessagesId);
  static HRESULT StopForceRecording();
  static CATBoolean IsForceRecordingInProgress();
  static CATOmxPair<unsigned int, CATUnicodeString> GetForceRecorderDataForxMQL();
  static void IncrementCountForxMQL();
  static CATBoolean IsQueueForceRecordingInProgress();
  static CATOmxPair<unsigned int, CATUnicodeString> GetQueueForceRecorderDataForxMQL();
  static void IncrementQueueCountForxMQL();
  /*
  * Queue messages to replay at demand later.
  */
  static HRESULT StartQueueForceRecording(const CATOmySessionRecordServices::QueueForceRecordType &iType);
  static HRESULT StopQueueForceRecording();
  //How many queued recordings for a QueryForceRecordType
  //Returns S_FALSE and oCount of 0 if nothing to replay
  static HRESULT GetReplayCount(const CATOmySessionRecordServices::QueueForceRecordType &iType, unsigned int &oCount);
  static HRESULT ResetQueueId(const CATOmySessionRecordServices::QueueForceRecordType &iType);
  /***/
  static HRESULT ResetTubeIDs();

  //raii
  struct QueueForceRecording
  {
    QueueForceRecording(const CATOmySessionRecordServices::QueueForceRecordType &iType)
    {
      StartQueueForceRecording(iType);
    }
    ~QueueForceRecording()
    {
      StopQueueForceRecording();
    }
  };

  class ExportedByCATOMYBaseSession SecurityContext
  {
    static bool replaying;
  public:
    static const bool& Replaying() { return replaying; }
    SecurityContext()
    {
      replaying = true;
    }
    ~SecurityContext()
    {
      replaying = false;
    }

  };

private:
  static HRESULT SetRecordManager(CATIOmySessionRecordManager_var iManager);
  static CATIOmySessionRecordManager_var GetRecordManager();
  friend class CATPLMTubeFactoryErrorSimulatorServices;

};
#endif
