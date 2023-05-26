#ifndef CATOmyTubeFactoryAdapter_h
#define CATOmyTubeFactoryAdapter_h

#include "CATIOmyTubeFactory.h"
#include "CATOMYCommunication.h"
#include "CATOmyAuditLogMgt.h"
#include "CATOmxPair.h"
class CATUnicodeString ;

class ExportedByCATOMYCommunication CATOmyTubeFactoryAdapter : public CATIOmyTubeFactory
{
public:
  HRESULT CreateTube(CATHashDico *iConnectionParameters,CATIComSidlStreamTube ** oTrs);
  void AddLogInfos(const CATUnicodeString& iThem, const CATUnicodeString& iOperation,const CATListValCATUnicodeString & iInfos);
  HRESULT SetErrorReporter(CATIPLMMaintenanceTubeErrorReporter * iReporter);
  HRESULT StartForceRecording(const CATUnicodeString & iMessagesId);
  HRESULT StopForceRecording();
  HRESULT StartQueueForceRecording(const CATOmySessionRecordServices::QueueForceRecordType &iRecordType);
  HRESULT StopQueueForceRecording();
  HRESULT GetReplayCount(const CATOmySessionRecordServices::QueueForceRecordType &iType, unsigned int &oCount);

  CATBoolean IsForceRecordingInProgress();
  CATOmxPair<unsigned int, CATUnicodeString> GetForceRecorderDataForxMQL();
  void IncrementCountForxMQL() {}
  CATBoolean IsQueueForceRecordingInProgress();
  CATOmxPair<unsigned int, CATUnicodeString> GetQueueForceRecorderDataForxMQL();
  void IncrementQueueCountForxMQL() {}
  HRESULT ResetIDs();
  HRESULT ResetQueueId(const CATOmySessionRecordServices::QueueForceRecordType &iType);
protected:
  virtual HRESULT CreateRealTube(CATHashDico *iConnectionParameters,CATIComSidlStreamTube ** oTrs)=0;
  CATOmyAuditLogMgt _log;
};
#endif
