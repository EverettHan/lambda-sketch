//===================================================================
// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATCDSVarSweepFuncEvaluator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 5.10.2006  Creation                                          FCX
//===================================================================

#ifndef CATCDSVarSweepFuncEvaluator_H
#define CATCDSVarSweepFuncEvaluator_H

#include "VarSweepDriver.h"

//-----------------------------------------------------------------------

class ExportedByVarSweepDriver CATCDSVarSweepFuncEvaluator {
public:
  CATCDSVarSweepFuncEvaluator(int iNbVariables);
  virtual ~CATCDSVarSweepFuncEvaluator();

  // iaX contains the values of the variables V0...Vn-1
  // returns f(V0,...,Vn-1)
  virtual double Eval(double * iaX) = 0;

  // iaX contains the values of the variables V0...Vn-1
  // computes in oaDX the n partial derivatives df/dV0,...,df/dVn-1 at (V0,...,Vn-1)
  virtual void EvalGradient(double * iaX, double *oaDX);

protected:
  int _nVariables;
};

//-----------------------------------------------------------------------

#endif
