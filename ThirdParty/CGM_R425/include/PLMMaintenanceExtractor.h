#ifndef PLMMaintenanceExtractor_h
#define PLMMaintenanceExtractor_h

#include "CATOMYSessionReplay.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class ExportedByCATOMYSessionReplay PLMMaintenanceExtractor
{
public:
  /** 
  * Extract the messages traces found in the given PLMMaintenanceFile
  *
  * @param iPathToPLMMaintenanceFile [in]
  *   The PLMMaintenance file path
  * @param iDirPathWhereToPutTheTraces [in]
  *   The path to the directory where to put the trace. This directory must exist before calling this method.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *
  */
  static HRESULT ExtractPLMMaintenanceMessages(const CATUnicodeString & iPathToPLMMaintenanceFile,
    const CATUnicodeString & iDirPathWhereToPutTheTraces);
};
#endif
