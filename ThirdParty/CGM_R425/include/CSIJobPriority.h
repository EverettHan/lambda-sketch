#ifndef CSIJobPriority_H
#define CSIJobPriority_H

#include "CSICommandBinderModule.h"

#include <stdint.h>

namespace CSI
{
/**
* Possible values for a job priority
*/
// While it does not make a lot of sense to export an inline enum class,
// this is mandatory with Clang if we want template instantiation using this type to be exported
enum class ExportedByCSIBinderModule JobPriority
{
  high = 0,
  aboveNormal = 1,
  normal = 2,
  belowNormal = 3,
  low = 4,
};
}

#endif /*CSIJobPriority_H*/
