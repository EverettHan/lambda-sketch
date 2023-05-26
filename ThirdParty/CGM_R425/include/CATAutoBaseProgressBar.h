#ifndef CATAutoBaseProgressBar_H
#define CATAutoBaseProgressBar_H
//===================================================================
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATAutoBaseProgressBar.h
// 		
//===================================================================
//  Feb 2004  Creation: JHG
//===================================================================

#include "CATOracleObject.h"
#include "CATBoolean.h"
#include "CATCGMNewArray.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CFSEngine.h"

#define AUTOOPSTEP_WorkBodyCreation -1
#define AUTOOPSTEP_FrontiersExtraction -2
#define AUTOOPSTEP_Coupling -3
#define AUTOOPSTEP_SurfaceCreation -4
#define AUTOOPSTEP_Sewing -5
#define AUTOOPSTEP_ResultBodyPostTreatment -6

#define AUTOOPSTEP_CouplingFillet -31
#define AUTOOPSTEP_CouplingStep -32
#define AUTOOPSTEP_CouplingWall -33
#define AUTOOPSTEP_CouplingParallel -34
#define AUTOOPSTEP_CouplingConeRule -35
#define AUTOOPSTEP_CouplingConeTangent -36

#define AUTOOPSTEP_PostTreatment_CloseVolume -61
#define AUTOOPSTEP_PostTreatment_Simplify -62
#define AUTOOPSTEP_PostTreatment_RemoveConicalFace -63

class ExportedByCFSEngine CATAutoBaseProgressBar : public CATOracleObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATAutoBaseProgressBar(CATTopOracle &iOracle, int iTotalStep, CATAutoBaseProgressBar *iMotherBar = NULL);
  virtual ~CATAutoBaseProgressBar();

  void AddStep(int iStepId, double iStepWeight);

  void StartStep(int iStepId, int iNumberOfSubsteps);
  void StartStepWithChildBar(int iStepId, CATAutoBaseProgressBar *iChildBar);

  void SetSubstep(int iSubstep);

  int GetGlobalStep();
  int GetGlobalMaxStep();

  CATBoolean SomethingHasChangedSinceLastGetGlobalStep();

  void ForceComplete();

private:

  void SetInvalid();
  CATBoolean IsInvalid();

  int _NumberOfSteps;
  double _TotalWeight;
  CATListOfInt _Ids;
  CATListOfDouble _StepsWeights;
  int _CurrentStepNumberOfTotalSubsteps;
  int _CurrentSubstepOfCurrentStep;

  int _CurrentStep;

  CATBoolean _IsUpToDate;

  void ComputeGlobalStep(); 

  CATBoolean _ForceComplete;
  int _GlobalStep;
  int _GlobalMaxStep;

  int _LastGlobalStep;

#if 0
  CATTimer _Timer;
  double _LastTime;
#endif

  CATAutoBaseProgressBar *_MotherBar;
};

#endif
