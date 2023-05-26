/**
 * @level Private
 * @usage U1
 */
#ifndef __CATUpdEngine_H
#define __CATUpdEngine_H

#include "CATUpd.h"
#include "CATOmxPortability.h"

class CATBaseUnknown;
class CATError;

/**
 * Front end for update algorithms.
 * see CATUpdHRESULT.h for HRESULT values.
 */
class ExportedByCATUpd CATUpdEngine
{
public:
  /**
   * Compute Update status of input object iObj.
   * iObj is up-to-date if its internal status is up-to-date and if all
   * of its dependencies are up-to-date.
   */
  static HRESULT ComputeUpdateStatus(CATBaseUnknown* iObj,CATBoolean& oUpToDate);

  /**
   * Launch update of input object and of all of its dependencies.
   */
  static HRESULT LaunchUpdate(CATBaseUnknown* iObj,CATError** oError=NULL);

  /**
   * Mark input object iObj as out-of-date.
   * All its impacts (objects that depend on it) will also be
   * marked as out of date.
   */
  static HRESULT SetOutOfDate(CATBaseUnknown* iObj);
};

#endif

