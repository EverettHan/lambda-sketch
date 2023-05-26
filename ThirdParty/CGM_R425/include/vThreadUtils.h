#pragma once

#include "VisREKernel.h"
#include "vHandleTypes.h"

namespace vThreadUtils
{

  void ExportedByVisREKernel SetThreadName(const char * iName);

  /** 
   * The thread ID is the value that will be shifted for the mask : 1 << iThreadID
   * Must be < 64 on windows
   */
  void ExportedByVisREKernel SetThreadAffinity(std::uint32_t iNUMAGroup, std::uint32_t iThreadID);
}

