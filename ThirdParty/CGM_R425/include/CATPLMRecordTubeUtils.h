#ifndef CATPLMRecordTubeUtils_h
#define CATPLMRecordTubeUtils_h

#include "CATOmyTubeFactoryAdapter.h"
#include "PLMMaintenanceMessageStorage.h"
#include "CATUnicodeString.h"
#include "CATHashDico.h"
#include "CATOMYCommunication.h"

class ExportedByCATOMYCommunication CATPLMRecordTubeUtils : public CATOmyTubeFactoryAdapter
{
public:
  static CATUnicodeString ExtractProcessorClass(CATHashDico * iConnectionParameters);
  
  static CATIComSidlStreamTube * CreateRecordedTube(PLMMaintenanceMessageStorage & iMessageStorage,
    CATHashDico * iConnectionParameters, const CATUnicodeString & iProcessorClass, int iIndex, CATBoolean iWithCrunch = FALSE);
  };
#endif
