#ifndef CATVVSEnv_H
#define CATVVSEnv_H

// SystemTS
#include "CATSysTSUnicodeString.h"
// CATVirtualVaultSystem
#include "VVSUtils.h"

#define OMY_CHATTINESS_CORELATIONID_ACTIVATION
#define OMY_WAIT_FILE_ACTIVATION
#define OMY_DUMP_STREAMS_ACTIVATION

class ExportedByVVSUtils CATVVSEnv
{
private:
  CATVVSEnv();
public:
  CATBoolean _ForceFailureOfMassiveCopy;
  CATSysTSUnicodeString _ForceFailureOfMassiveCopyWhenThisFileExist;
  CATBoolean _CheckMassiveCopyResult;
  CATBoolean _AuthorizeInvalidCall;
  CATBoolean _ComputeCorelationIdAsStreamId;
  CATSysTSUnicodeString _WaitInAsyncFCS;
  CATBoolean _SimulateFailureMTDownload;
  CATBoolean _SimulateFailureZipMTDownload;
  CATBoolean _SimulateFailureGetTicketMTDownload;
  CATBoolean _ForceLongPathPattern;
  CATBoolean _DumpHumanReadable;
  CATBoolean _DumpCacheTrace;
  CATBoolean _DumpQueryFilter;
  CATBoolean _DeleteManagedFile;
  CATBoolean _CopyPLMDictionaryDir;
  CATBoolean _ForceFlush;
  CATBoolean _ForceMD5ComputationOnAW;
  CATBoolean _ManageLocalStorageLock;
  CATBoolean _ReadLocalStorageOwner;
  CATBoolean _ManageLocalStorageOwner;
  CATBoolean _ViscaVaultActivated;
  CATBoolean _ViscaAsyncVaultActivated;
  CATBoolean _ViscaFallbackActivated;
  CATBoolean _ViscaEmptyFallbackActivated;
  CATBoolean _DumpLocalStorageLocks;

  CATBoolean CheckIfMassiveCopyMustFail() const;
  static const CATVVSEnv& env();
};

#endif
