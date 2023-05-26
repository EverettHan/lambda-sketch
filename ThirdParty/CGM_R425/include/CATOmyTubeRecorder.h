#ifndef CATOmyTubeRecorder_h
#define CATOmyTubeRecorder_h

#include "CATIComSidlStreamTube.h"
#include "CATUnicodeString.h"
#include "CATIOmySessionRecordManager.h"
#include "CATIComSidlOutputStream.h"
#include "CATIComSidlInputStream.h"
#include "CATOMYCommunication.h"

class CATHashDico;
class CATOmyStreamHandler;

class ExportedByCATOMYCommunication CATOmyTubeRecorder : public CATIComSidlStreamTube
{
public:
  CATDeclareClass;

  CATOmyTubeRecorder(CATIComSidlStreamTube * iTubeToRecord, CATHashDico *iParameters,
    CATOmyStreamHandler * iInputStream, CATOmyStreamHandler * iOutputStream, CATBoolean iWithCrunch = FALSE);
  ~CATOmyTubeRecorder();

  HRESULT SetConnectionParameters( CATHashDico *iParameters );
  HRESULT GetQueryStream (CATIComSidlOutputStream**oQuery);
  HRESULT GetAnswerStream (CATIComSidlInputStream**oAnswer);

private:
  CATOmyStreamHandler * _InputStream;
  CATOmyStreamHandler * _OutputStream;

  CATIComSidlStreamTube_var _RecordedTube;
  CATUnicodeString _SidlProcessorClass;

  CATIComSidlOutputStream_var _CreateRecordOutputStreamForQuery();
  CATIComSidlOutputStream_var _CreateRecordOutputStreamForAnswer();

  CATBoolean _WithCrunch;
};

#endif 
