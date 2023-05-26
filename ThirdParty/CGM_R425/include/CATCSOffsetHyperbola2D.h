// COPYRIGHT Dassault Systemes 2012
//===================================================================

// DEPRECATED CLASS - PLEASE USE CATCSOffsetCurve2D INSTEAD

//===================================================================

// Usage notes:

//===================================================================

//   Feb 2012  Creation              chu / bf8

//===================================================================
#ifndef CATCSOffsetHyperbola2D_H
#define CATCSOffsetHyperbola2D_H

#include "CATCDSVirtual.h"
#include "CATCSCurve2D.h" // derived
#include "CATCDSEnums.h"  // enumerator used

class CATCSVariable;
class CATCDSOffsetHyperbola2DImp;
class CATCSHyperbola2D;
class CATCSFunction;

//-----------------------------------------------------------------------

/**
 * DEPRECATED CLASS - PLEASE USE CATCSOffsetCurve2D INSTEAD

 * Constructed from an arbitrary CATCSHyperbola2D instance,
 * CATCSOffsetHyperbola2D represents its offset curve (which is not a hyperbola) with a given offset radius or function.
 * The offset may include cusps and local self-intersections if the offset is inward and larger than the curvature radius at the hyperbola's vertex,
 * or if the offset is a function that reaches larger values than the local curvature radius
 * The offset curve parametrization corresponds to the original hyperbola's parametrization, which is implicit.
 * It is defined from -Log(CATCDSDomainInfinity) to Log(CATCDSDomainInfinity), zero correponding to the vertex of the hyperbola
 * The original hyperbola is parametrized by x = a cosh t, y = b sinh t, a and b are henceforth called "major" and "minor" radius of the hyperbola
 * Hence a cartesian equation is x**2/a**2 - y**2/b**2 = 1, but the only branch that is currently parametrized is defined by x having same sign 
 * as "a" (major radius), which can be inferred from the parametrization since cosh t > 0
 * A positive offset is toward the concave half-space bounded by the hyperbola if major and minor radius have same sign, it is toward the convex half spave if a*b < 0
 * Hence, if both radii are positive (which is the default), a negative value is required to offset the hyperbola branch towards its convex side.
 * Like a Hyperbola, an offset Hyperbola does not qualify for any extrapolation (it is always complete, and only composite curves can trim it)
 */

class ExportedBySolverInterface CATCSOffsetHyperbola2D: public CATCSCurve2D
{
public:

  CATCSOffsetHyperbola2D(CATCSHyperbola2D& iBaseHyperbola, double iOffset);
  CATCSOffsetHyperbola2D(CATCSHyperbola2D& iBaseHyperbola, CATCSVariable& iOffsetVariable);
  CATCSOffsetHyperbola2D(CATCSHyperbola2D& iBaseHyperbola, CATCSFunction& iOffsetFunction);

  virtual ~CATCSOffsetHyperbola2D();

  virtual CATCSSketch* GetSketch() CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  CATCSHyperbola2D& GetBaseHyperbola();
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
  CATCDSOffsetHyperbola2DImp  * _pImp;

};

//-----------------------------------------------------------------------

#endif
