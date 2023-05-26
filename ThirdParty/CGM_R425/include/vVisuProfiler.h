
#ifndef VISUPROFILER_H_
#define VISUPROFILER_H_

#include "VisREKernel.h"
#include <string>
#include "CATUnicodeString.h"

class ExportedByVisREKernel vVisuProfiler
{
private:
  vVisuProfiler() {};

public:  
  ~vVisuProfiler();
  
  /** 
  * Enable/Disable the Present profiling. It doesn't the full profiler. Just the Present Timing.
  * It can be retrived through the GetPresentTime() function
  */
  void EnablePresentProfiling() const;
  void DisablePresentProfiling() const;
  
  /** 
  * return the time in ms between to vRenderRenderRequest submission.
  * this is usually the FPS. But when several requests are submitted, though offline rendering for example, you won't get the FPS.
  */
  [[nodiscard]] float GetPresentTime() const;
  
  /** 
  * Enable/Disable the Query of GPU Information. Those informations will be added to the profiling report.
  * The function is not supported on all GPU (yet ? Only Nvidia)
  * It doesn't turn the profiling on or off.
  */
  void EnableGPUMemoryAndLoadProfiling() const;
  void DisableGPUMemoryAndLoadProfiling() const;


  /*
  * Specify the path where to dump the traces
  */
  void SetTracePath(const char * iPath);

  /*
  * Get the path where to dump the traces
  */
  const std::string& GetTracePath() const;

  /** 
    * Specify if the file is overriden if exits
  */
  void SetOverrideFile(bool isOverriden);

  /** 
  * Will the file been overriden if exists?
  */
  const bool IsOverrideFile() const;

  /** Enable the timer profiling. */
  void EnableProfiling();
  
  /** Disable the timer profiling. */
  void DisableProfiling();

  static vVisuProfiler&  GetVisuProfiler() 
  {
      static vVisuProfiler s;
      return s;
  }
  /*
  vVisuProfiler(vVisuProfiler const&) = delete;             // copy constructor is deleted
  vVisuProfiler& operator=(vVisuProfiler const&) = delete;  // assignment operator is deleted
  */
};
#endif

