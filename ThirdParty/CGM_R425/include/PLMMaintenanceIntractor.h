#ifndef PLMMaintenanceIntractor_h
#define PLMMaintenanceIntractor_h

#include "CATOMYSessionReplay.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class ExportedByCATOMYSessionReplay PLMMaintenanceIntractor
{
public:
  /** 
  * Import the messages traces found in a directory to the given PLMMaintenanceFile
  *
  * @param iPathToTraceFile [in]
  *   The path where are the files from. This directory must exist before calling this method.
  * @param iMaintenanceFileDirPath [in]
  *   The path + filename to the directory where the PLMMaintenance file is. This directory must exist before calling this method.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *
  */
  static HRESULT IntractPLMMaintenanceMessages(const CATUnicodeString & iPathToTraceFile,
                                               const CATUnicodeString & iMaintenanceFileDirPath);
};
#endif
