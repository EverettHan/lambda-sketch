// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyToCATBodyChecker
//
//===================================================================
//
// June 2017  Creation: JXO
// Nov  2018  JXO: You can now pass a CATSoftwareConfiguration
//===================================================================
#ifndef CATPolyBodyToCATBodyChecker_H
#define CATPolyBodyToCATBodyChecker_H

#include "PolyBodyServices.h"

class CATPolyBody;

// Math
#include "CATTolerance.h"
class CATSoftwareConfiguration;
class CATProgressCallback;

/**
 * Chains all the needed checks to be sure a CATPolyBody can be imported into a CATBody.
 * Updates the CATPolyBodyDiagnosis and CATPolyBodyGeoDiagnosis if needed.
 */
class ExportedByPolyBodyServices CATPolyBodyToCATBodyChecker
{
public:
/**
 * Chains all the needed checks to be sure a CATPolyBody can be imported into a CATBody.
 * Updates the CATPolyBodyDiagnosis and CATPolyBodyGeoDiagnosis if needed.
 * @param iBody
 *   Input CATPolyBody to check. If the diagnosis already have the check return codes, then the check is not launched (lazy.)
 * @param iTol
 *   Should be the tolerance of the factory where the CATBody will be instanciated
 * @param iConfig
 *   Software configuration to be used in the checker. If null (default), then last version is used.
 * @return
 *   S_OK        iBody is valid for import.
 *   S_FALSE     iBody is not valid for import.
 *   Error code: The check itself failed. iBody may be unusable.
 */
static HRESULT Check(CATPolyBody & iBody, const CATTolerance & iTol, CATBoolean iForceCheck = FALSE, CATSoftwareConfiguration * iConfig = 0, CATProgressCallback * ioProgress = 0);

protected:
  CATPolyBodyToCATBodyChecker(){};
  ~CATPolyBodyToCATBodyChecker(){};
};


#endif // !CATPolyBodyGeoDiagnosis_H
