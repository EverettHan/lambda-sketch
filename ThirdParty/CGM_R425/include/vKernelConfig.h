
#include "VisREKernel.h"
#include <string>

namespace VKL
{
  ExportedByVisREKernel bool IsCustomAllocatorDisabled();

  ExportedByVisREKernel bool IsDrawOrderActivated();

  ExportedByVisREKernel bool IsDrawOrderActivated(bool iIsExtendedObs);

  ExportedByVisREKernel bool IsDrawOrderDeactivated();
}
