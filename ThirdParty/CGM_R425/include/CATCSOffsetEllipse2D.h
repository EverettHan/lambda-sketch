// COPYRIGHT Dassault Systemes 2010
//===================================================================

// DEPRECATED CLASS - PLEASE USE CATCSOffsetCurve2D INSTEAD 

//===================================================================

// Usage notes:

//===================================================================

//   Jan 2012  Creation              chu / bf8

//===================================================================
#ifndef CATCSOffsetEllipse2D_H
#define CATCSOffsetEllipse2D_H

#include "CATCDSVirtual.h"
#include "CATCSCurve2D.h" // derived
#include "CATCDSEnums.h"  // enumerator used

class CATCSVariable;
class CATCDSOffsetEllipse2DImp;
class CATCSEllipse2D;
class CATCSFunction;

//-----------------------------------------------------------------------

/**
 * DEPRECATED CLASS - PLEASE USE CATCSOffsetCurve2D INSTEAD

 * Constructed from an arbitrary CATCSEllipse2D instance,
 * CATCSOffsetEllipse2D represents its offset curve (which is not an ellipse) with a given offset radius or function.
 * The offset may include cusps and local self-intersections if the offset is inward and larger than the smallest radius,
 * or if the offset is a function that reaches larger values than the local curvature radius
 * The offset curve parametrization is implicit, it is defined from 0 to 2*pi, starting from the positive end of the major axis and
 * going countrclockwise on the reference sketch plane. Note that the major axis is defined at the construction of the reference ellipse,
 * and may not always correspond to the larger radius (as both radii and / or axes may vary when contraints are applied)
 * Since the parameter runs counterclockwise, positive offset values are inward, and negative values are outward
 * Like an ellipse, an offset ellipse does not qualify for any extrapolation (it is always complete, and only
 * composite curves can trim it)
 */
class ExportedBySolverInterface CATCSOffsetEllipse2D: public CATCSCurve2D
{
public:

  CATCSOffsetEllipse2D(CATCSEllipse2D& iBaseEllipse, double iOffset);
  CATCSOffsetEllipse2D(CATCSEllipse2D& iBaseEllipse, CATCSVariable& iOffsetVariable);
  CATCSOffsetEllipse2D(CATCSEllipse2D& iBaseEllipse, CATCSFunction& iOffsetFunction);

  virtual ~CATCSOffsetEllipse2D();

  virtual CATCSSketch* GetSketch() CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  CATCSEllipse2D& GetBaseEllipse();
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
  CATCDSOffsetEllipse2DImp  * _pImp;

};

//-----------------------------------------------------------------------

#endif
