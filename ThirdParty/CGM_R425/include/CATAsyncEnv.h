#ifndef CATAsyncEnv_H
#define CATAsyncEnv_H

// SystemTS
#include "CATUnicodeString.h"
// CATPLMCommunication
#include "CATAsyncTasksPlatform_NG.h"

class ExportedByCATAsyncTasksPlatform CATAsyncEnv
{
private:
  CATAsyncEnv();
public:
  CATBoolean _FullAsyncODT;
  CATBoolean _AsyncSync;
  CATBoolean _ForceAsyncSyncForODT; // For KOALA ODT purpose, do not remove !
  static const CATAsyncEnv &env();
};

#endif
