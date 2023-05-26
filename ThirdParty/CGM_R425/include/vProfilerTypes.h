#pragma once

#include "vHandleTypes.h"
#include "VisREKernel.h"

namespace VKL
{
  namespace Profiler
  {

    struct ProfilerName;

    using vProfilerName = handletd<ProfilerName>;

    using vFlowID = std::uint32_t;

    ExportedByVisREKernel vProfilerName RegisterName(const char* iName);
    ExportedByVisREKernel void          UnRegisterName(vProfilerName iName);
    ExportedByVisREKernel bool          IsProfilerEnabled();

    ExportedByVisREKernel vFlowID       GenerateNewFlowID();

  }

}

#ifndef V_DISABLE_PROFILING


#define V_PROFILE_CREATE_NAME(iName, oNameHandle) oNameHandle = VKL::Profiler::RegisterName(iName)
#define V_PROFILE_DELETE_NAME(iNameHandle)        VKL::Profiler::UnRegisterName(iNameHandle)

#else

#define V_PROFILE_CREATE_NAME(iName, oNameHandle)
#define V_PROFILE_DELETE_NAME(iName)

#endif

