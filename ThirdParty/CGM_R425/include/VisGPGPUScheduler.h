#ifndef VISGPGPUSCHEDULER_H_
#define VISGPGPUSCHEDULER_H_

#include "CATVisFoundation.h"
#include "VisGPGPUProgram.h"

#ifdef throw
#undef throw
#define RESTORE_THROW
#endif /* throw */          

#pragma warning( disable : 4530 )

#include <queue>
#include <vector>

#ifdef RESTORE_THROW
#undef RESTORE_THROW
#define throw ERROR
#endif /* RESTORE_THROW */


class VisGPGPUPrimitive;
class VisComputeProgram;
class CATSupport;

class ExportedByCATVisFoundation VisGPGPUScheduler
{
  friend class CATPassGPGPU;
  friend class VisGPGPUSchedulerTstClass;
  friend class VisCUDASchedulerTstClass;
  friend class vREViewpoint;

protected :

  struct Program
  {
    VisGPGPUProgram * _prog;
    void *            _arg;
  };

  struct ComputeProgram
  {
    VisComputeProgram * _prog;
    void *              _arg;
  };


public :

  static VisGPGPUScheduler * GetInstance();
  
  HRESULT SubmitJob(VisGPGPUProgram * iJobGeneric, void * iProgramArgument);

  HRESULT SubmitJob(VisGPGPUProgram * iJobOpenCL, void * iProgramArgumentOpenCL,
                    VisGPGPUProgram * iJobCuda, void * iProgramArgumentCuda);

  HRESULT SubmitJob(VisGPGPUPrimitive * iPrimitive);

  HRESULT SubmitComputeJob(VisComputeProgram * iComputeProgram, void * iProgramArgument);

  void LaunchJobComputePur();
  
  void LaunchJobCompute(CATSupport & iSupport);
  
protected :

  HRESULT _SubmitJob(VisGPGPUProgram * iJob, void * iProgramArgument);

  std::queue<VisGPGPUPrimitive *> & GetListInterop();
  std::vector<ComputeProgram>   & GetListCompute();

protected :
  
  std::queue<VisGPGPUPrimitive *> _listProgramInterop;
  std::queue<Program>             _listProgramPurCompute;
  std::vector<ComputeProgram>     _listProgramCompute;
};



#endif /* VISGPGPUSCHEDULER_H_ */
