/**
 * @level Private
 * @usage U1
 */

#ifndef __CATUpdRestoreUpdateStatusForFBDI_H
#define __CATUpdRestoreUpdateStatusForFBDI_H

#include "CATUpd.h"
#include "CATIAV5Level.h"
#include "CATBaseUnknown.h"
class CATBaseUnknown_var;

#if !defined(_WINDOWS_SOURCE) || defined (__CATUpdEngine)  || defined(__TestUpdateEngine) || defined(__TstCATOsmNewUpdate) || ( defined(CATIAR207) && defined (__CATFbdModeler) )

/**
 * For FBDI only.
 * This method is meant to capture the list of dependencies of iRootObject.
 * iRootObject must be up to date or the capture will be empty and the return code S_FALSE.
 * The dependencies are stored in oCapture that must be passed to the following method.
 */
ExportedByCATUpd HRESULT CATUpdCaptureUpdateStatusForFBDI(CATBaseUnknown* iRootObject,CATBaseUnknown_var& oCapture);

/**
 * For FBDI only.
 * This method will restore up-to-date status of iRootObject and recursively to all its dependencies.
 * All the objects that where up to date during the capture step will not be built.
 * This supposes that the modifications performed after the capture step are only structural and do not
 * impact the underlying result of the build.
 */
ExportedByCATUpd HRESULT CATUpdRestoreUpdateStatusForFBDI(CATBaseUnknown* iRootObject,CATBaseUnknown* iCapture);

#endif

#endif

