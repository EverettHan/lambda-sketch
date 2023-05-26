#ifndef CATOmxExpectErrorInODT_H
#define CATOmxExpectErrorInODT_H

#include "CATOmxKernel.h"
#include "CATOmxSR.h"
#include "IUnknown.h"

/**
 * CATOmxExpectErrorInODT
 * @href http://osmwebdsy/wiki/index.php/CATOmxLogError#CATOmxExpectErrorInODT
 *
 * It is strictly forbidden to use this macro outside ODT code
 *
 * Do not use this macro to "hide" errors generated by some other team without their acknowledgement
 */
#define CATOmxExpectErrorInODT(errorId) CATOmxExpectErrorInODTIf(errorId,true)

 /**
  * CATOmxExpectErrorInODTIf
  *
  * Same as CATOmxExpectErrorInODT but does nothing if the condition passed as second argument is false
  */
#define CATOmxExpectErrorInODTIf(errorId,condition) CATOmxSR<IUnknown> expect##errorId((condition) ? CATOmx::ExpectErrorInODT(__FILE__,__LINE__,#errorId) : NULL,Steal)

namespace CATOmx
{
  /** internal implementation function for CATOmxExpectErrorInODT, do not call directly. */
  ExportedByCATOmxKernel IUnknown* ExpectErrorInODT(const char* source, int line, const char* errorId);
}

#endif