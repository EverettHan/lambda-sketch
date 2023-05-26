//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/11
//===================================================================

#ifndef CSIJobStatus_H
#define CSIJobStatus_H

#include "CSICommandBinderModule.h"

#include <stdint.h>

namespace CSI
{
/**
* Possible values for a job status
*/
// While it does not make a lot of sense to export an inline enum class,
// this is mandatory with Clang if we want template instantiation using this type to be exported
enum class ExportedByCSIBinderModule JobStatus
{
  created,
  pending,
  running,
  cancel_pending,
  succeeded,
  failed,
  canceled,
  removed
};
}

#endif /*CSIJobStatus_H*/
