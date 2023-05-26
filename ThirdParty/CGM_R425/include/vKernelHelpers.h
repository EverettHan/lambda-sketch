#include "VisREKernel.h"
#include <cstdint>

namespace VKL
{
  ExportedByVisREKernel void ParallelMemCpy(void* dest, const void* source, std::size_t size);
}
