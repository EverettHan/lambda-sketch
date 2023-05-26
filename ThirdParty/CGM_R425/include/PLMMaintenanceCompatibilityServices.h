#ifndef PLMMaintenanceCompatibilityServices_h
#define PLMMaintenanceCompatibilityServices_h

#include "CATOMYCommunication.h"
#include "IUnknown.h"
class CATIComSidlOutputStream;
class CATIComSidlOutputStream_var;
class CATIComSidlInputStream;
class CATOmyStreamHandler;
class CATIComSidlStreamTube_var;
class CATUnicodeString;
class PLMMaintenanceMessageStorage;
class PLMMaintenanceMessageStreamId;
class ExportedByCATOMYCommunication PLMMaintenanceCompatibilityServices
{
public:
  static CATIComSidlOutputStream_var CreateUnscrambledOutput(const CATIComSidlOutputStream_var & iScrambledStream);
  static HRESULT CreateUnscrambledInput(CATIComSidlInputStream ** oUnscrambledInput,
    CATOmyStreamHandler * iScrambledOutputStreamData, CATOmyStreamHandler * iScrambledInputStreamData);

  // Pour la denomination des tube scrambling et unscrambling, on se base sur l'action a appliquer a
  // l'output - car c'est elle qui contient les infos de scrambling.
  static CATIComSidlStreamTube_var CreateScramblingTube(const CATIComSidlStreamTube_var & iTubeToScramble);
  static CATIComSidlStreamTube_var CreateUnscramblingTube(const CATIComSidlStreamTube_var & iTubeToUnscramble);

  static HRESULT ExtractUnscrambledPLMMaintenanceStream(CATIComSidlOutputStream* oWhereToExtract,
    PLMMaintenanceMessageStorage & iMessageStorage, const PLMMaintenanceMessageStreamId & iStreamId);

private:
  static CATIComSidlStreamTube_var CreateWrappedTube(const CATIComSidlStreamTube_var & iTubeToUnscramble,
    const CATUnicodeString & iWrappingTubeLateType);
};
#endif
