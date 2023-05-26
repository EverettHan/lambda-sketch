#pragma once

#include "VisREKernel.h"
#include "vProfilerTypes.h"

#include <memory>

#ifndef V_DISABLE_PROFILING

#define V_PROFILE_APPLI_CPU(iName)                static VKL::Profiler::vProfilerName __sentinelName = VKL::Profiler::RegisterName(iName); VKL::vProfilerAppli __profileSentinel(__sentinelName)
#define V_PROFILE_APPLI_CPU_DYNAMIC(iNameHandle) VKL::vProfilerAppli __profileSentinel(iNameHandle)


///@deprecated do not use it
#define V_PROFILE_APPLI_CPU_COPY(iName)    V_PROFILE_APPLI_CPU(iName)

#else //Profiling is disabled

#define V_PROFILE_APPLI_CPU(iName)
#define V_PROFILE_APPLI_CPU_COPY(iName)
#define V_PROFILE_APPLI_CPU_DYNAMIC(iNameHandle)

#endif //V_DISABLE_PROFILING



namespace VKL
{

  namespace Profiler
  {
    class vProfiler2;
  }

  class ExportedByVisREKernel vProfilerAppli
  {
    
  public :
    vProfilerAppli(const char * iName, bool iCopyName);
    vProfilerAppli(Profiler::vProfilerName iName);
    ~vProfilerAppli();

  private :

    std::unique_ptr<Profiler::vProfiler2> m_impl;
    static Profiler::vProfilerName s_categoryName;
    const bool m_enabled;
  };



}

#ifndef V_DISABLE_PROFILING

inline std::unique_ptr<VKL::vProfilerAppli> V_PROFILE_APPLI_PUSH_MARKER(VKL::Profiler::vProfilerName iName)
{ 
  return std::unique_ptr<VKL::vProfilerAppli>(new VKL::vProfilerAppli(iName));
}

inline void V_PROFILE_APPLI_POP_MARKER(std::unique_ptr<VKL::vProfilerAppli> && iProfiler)
{ 
  iProfiler.reset(); 
}
#else

inline std::unique_ptr<VKL::vProfilerAppli> V_PROFILE_APPLI_PUSH_MARKER(VKL::Profiler::vProfilerName iName)
{ }

inline void V_PROFILE_APPLI_POP_MARKER(std::unique_ptr<VKL::vProfilerAppli> && iProfiler)
{ }

#endif


