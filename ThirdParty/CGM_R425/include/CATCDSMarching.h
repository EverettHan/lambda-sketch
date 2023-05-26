#ifndef CATCDSMarching_H
#define CATCDSMarching_H

#include "Marching.h"
#include "CATBoolean.h"
#include "CATListOfDouble.h"
class CATConstraintSolver;
class CATCSVariable;
class CATCSGeomConstraint;
class CATCSGeometryLeaf;
class CATCSState;
class CATCDSMarchingImp;

#ifdef FCX_MARCHING

//-----------------------------------------------------------------------------

class ExportedByMarching CATCDSMarching
{
public:
  /**
   *  Default constructor.
   */
  CATCDSMarching(CATConstraintSolver * ipConstraintSolver);

  /**
   *  Destructor.
   */
  virtual ~CATCDSMarching();

  /**
   *  Get the constraint solver.
   *  @return pointer on a CATConstraintSolver
   */
  CATConstraintSolver* GetConstraintSolver();

  /**
   *  Set the marching parameter.
   *  @param IVariable
   */
  void SetMarchingParameter(CATCSVariable* iVariable);

  /**
   *  Set interval for the marching parameter.
   *  @param iLow
   *  @param iHigh
   */
  void SetMarchingInterval(double iLow, double iHigh);

  /**
   *  Perform the marching algorithm.
   *  @return error code
   */
  int Run();

  /**
   *  Get the marching result interval.
   *  To be performed after Run().
   *  @param oLow
   *  @param oHigh
   */
  void GetResultInterval(double & oLow, double & oHigh);

  /**
   *  Apply tranformations at the parameter iT.
   *  To be performed after Run() in marching mode.
   *  @param iT input param in the interval defined by SetMarchingInterval
   *  @return error code
   */
  int ComputeState(double iT);

  // La vie en rose !
  void GetPrecomputedParams(CATListOfDouble &L);

private:
  CATCDSMarchingImp * _Imp;
};

//-----------------------------------------------------------------------------

#endif
#endif
