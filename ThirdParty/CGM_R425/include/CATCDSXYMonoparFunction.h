// COPYRIGHT Dassault Systemes 2013
//===================================================================

// CATCDSXYMonoparFunction.h

//===================================================================

// Usage notes: Math function associated with the X or Y coordinate of a 2D monoparametric

//===================================================================

//  Oct 2012  Creation:             BF8 CHU
//===================================================================
#ifndef CATCDSXYMonoparFunction_H
#define CATCDSXYMonoparFunction_H

#include "CDSProfile.h"
#include "CATMathFunctionX.h" // derived

class CATCSMonoParametric;
class CATMathInterval;

//-----------------------------------------------------------------------

class CATCDSXYMonoparFunction : public CATMathFunctionX
{
public:

  // Life cycle
  CATCDSXYMonoparFunction(CATCSMonoParametric & iMonop, int iCoord, double iStartDomain, double iEndDomain);
  virtual ~CATCDSXYMonoparFunction();

  // Virtual methods that need to be implemented
  CATMathClassId IsA() const;
  virtual CATMathFunctionX * Duplicate() const;

  // Evaluators
  virtual double Eval(const double & iT) const;
  virtual double EvalFirstDeriv(const double & iT) const;
  virtual double EvalSecondDeriv(const double & iT) const;

  virtual CATMathInterval EvalFirstDeriv(const CATMathInterval & iInterval) const;

  // Monotone function check
  virtual int IsMonotoneInInterval(const CATMathInterval & iInterval) const; // returns 1 if monotone, 0 otherwise

  CATBoolean IsOption(const CATMathOption iOption) const;

private:

  CATCSMonoParametric      & _Monop;
  int                        _Coord; // 0=X, 1=Y
  double                     _StartDomain, _EndDomain;
};

//-----------------------------------------------------------------------

#endif
