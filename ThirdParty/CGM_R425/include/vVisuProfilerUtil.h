#ifndef VISUPROFILERUTIL_H_
#define VISUPROFILERUTIL_H_

/*
  Encryption utility developed for profiling are in Private interfaces. 
  Workaround to access it without giving private access in identityCard.
*/
#include "VisREKernel.h"
#include <cstdint>
#include <cstddef>

namespace vVisuProfilerUtil
{
  void ExportedByVisREKernel Encrypt(char* iData, std::size_t iSize);
}


#endif

