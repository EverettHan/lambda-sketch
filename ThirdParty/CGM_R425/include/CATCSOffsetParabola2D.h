// COPYRIGHT Dassault Systemes 2012
//===================================================================

// DEPRECATED CLASS - PLEASE USE CATCSOffsetCurve2D INSTEAD 

//===================================================================

// Usage notes:

//===================================================================

//   Feb 2012  Creation              chu / bf8

//===================================================================
#ifndef CATCSOffsetParabola2D_H
#define CATCSOffsetParabola2D_H

#include "CATCDSVirtual.h"
#include "CATCSCurve2D.h" // derived
#include "CATCDSEnums.h"  // enumerator used

class CATCSVariable;
class CATCDSOffsetParabola2DImp;
class CATCSParabola2D;
class CATCSFunction;

//-----------------------------------------------------------------------

/**
 * DEPRECATED CLASS - PLEASE USE CATCSOffsetCurve2D INSTEAD
 * Constructed from an arbitrary CATCSParabola2D instance,
 * CATCSOffsetParabola2D represents its offset curve (which is not a parabola) with a given offset radius or function.
 * The offset may include cusps and local self-intersections if the offset is inward and larger than the curvature radius at the parabola's vertex,
 * or if the offset is a function that reaches larger values than the local curvature radius
 * The offset curve parametrization is implicit, it is defined from -CATCDSDomainInfinity to CATCDSDomainInfinity, zero correponding to the vertex,
 * and the parameter on the offset parabola is equal to the corresponding parameter on the parabola
 * The original parabola is parametrized by its x coordinate, using x**2 = 2*p*y, with p = parabola's parameter, equal to the curvature radius at the vertex
 * x is the "major direction of the parabola" as stated at construction, y being the axis of symmetry.
 * Since y runs toward the convexity of the parabola, positive offset values are toward the convex halfspace, and negative values are outward
 * Like a parabola, an offset parabola does not qualify for any extrapolation (it is always complete, and only composite curves can trim it)
 */

class ExportedBySolverInterface CATCSOffsetParabola2D: public CATCSCurve2D
{
public:

  CATCSOffsetParabola2D(CATCSParabola2D& iBaseParabola, double iOffset);
  CATCSOffsetParabola2D(CATCSParabola2D& iBaseParabola, CATCSVariable& iOffsetVariable);
  CATCSOffsetParabola2D(CATCSParabola2D& iBaseParabola, CATCSFunction& iOffsetFunction);

  virtual ~CATCSOffsetParabola2D();

  virtual CATCSSketch* GetSketch() CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  CATCSParabola2D& GetBaseParabola();
  double GetOffset();
  CATCSVariable* GetOffsetVariable();
  CATCSFunction* GetOffsetFunction();

  virtual void ApplyTransformation2D(double iMatrix[3][3]) CATCDSOverride;
  virtual CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;
  virtual void Evaluate2D(double iT,
                          double* oaPoint,
                          double* oaFirstDeriv,
                          double* oaSecondDeriv,
                          double* oaThirdDeriv = 0) CATCDSOverride;
  virtual CATCDSBoolean Regenerate() CATCDSOverride;
  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;

  virtual int GetNbOfDiscontinuities() CATCDSOverride;
  virtual void GetDiscontinuitiesParams(double *oaValues) CATCDSOverride;
  virtual void EvaluateAtDiscontinuity2D(int iIdx,
                                         CATDiscontinuitySide iSide,
                                         double iT,
                                         double* oaPoint,
                                         double* oaFirstDeriv,
                                         double* oaSecondDeriv,
                                         double* oaThirdDeriv = 0) CATCDSOverride;
  virtual void GetDirection2D(double &oX, double &oY) CATCDSOverride;

  // Internal Use Only :
  virtual int IsAnExactOffset();                                          // returns 1

private:
  CATCDSOffsetParabola2DImp  * _pImp;

};

//-----------------------------------------------------------------------

#endif
