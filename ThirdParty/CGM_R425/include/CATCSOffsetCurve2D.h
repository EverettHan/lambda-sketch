// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATCSOffsetCurve2D.h
// Header definition of CATCSOffsetCurve2D

//===================================================================

//  November 2012  Creation:                chu / bf8

//===================================================================

#ifndef CATCSOffsetCurve2D_H
#define CATCSOffsetCurve2D_H

#include "CATCDSVirtual.h"
#include "CATCSCurve2D.h" // derived
#include "CATCDSEnums.h"  // enumerator used

class CATCSVariable;
class CATCSSketch;
class CATCSNOffsetCurve2D;

//-----------------------------------------------------------------------

/**
 * Constructed from an arbitrary CATCSCurve2D instance,
 * CATCSOffsetCurve2D represents its offset curve with a given offset radius.
 * The offset may include cusps and local self-intersections
 * that appear around the input curve discontinuities and
 * intervals where curvature radius is less than offset radius.
 * The offset curve parametrization is induced by the input curve,
 * its limits are identical to those of the input curve if the offset is not extrapolated.
 * Extrapolation options are given by SetExtrapolationMode(): none, linear, or C2 extrapolations
 * are provided in option. The default is a linear extrapolation
 */
class ExportedBySolverInterface CATCSOffsetCurve2D: public CATCSCurve2D
{
public:

  CATCSOffsetCurve2D(CATCSMonoParametric* iBaseCurve, double iOffset);
  CATCSOffsetCurve2D(CATCSMonoParametric* iBaseCurve, CATCSVariable* iOffsetVariable);

  virtual ~CATCSOffsetCurve2D();

  void SetGeometry(
    CATCSMonoParametric* iBaseCurve, 
    double iOffset, 
    CATCSVariable* iOffsetVariable);

  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  CATCSMonoParametric* GetBaseCurve();
  double GetOffset() const;
  CATCSVariable* GetOffsetVariable();

  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;
  virtual void ApplyTransformation2D(double iMatrix[3][3]) CATCDSOverride;
  virtual CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

  // Extend the parametric domain from [Low, Up] to [iNewLow, iNewUp], assuming iNewLow<Low and iNewUp>Up
  // Returns FALSE if extrapolation is not allowed for the given curve and/or for the given extrapolation mode
  virtual CATCDSBoolean Extrapolate(double iNewLow, double iNewUp, CATCSExtrapolMode iMode) CATCDSOverride;
  virtual CATCDSBoolean ExtrapolateOneSide(double iNewLimit, CATCSExtrapolMode iMode, CATCDSBoolean iUp);

  virtual CATCSExtrapolMode GetExtrapolationModeUp() const;
  virtual CATCSExtrapolMode GetExtrapolationModeLow() const;

  // The default implementation is:
  // find the first planar sketch, then call Evaluate2D and
  // transform the obtained coordinates into 3D ones.
  // An application may re-define this method
  virtual void Evaluate(double iT,
                        double* oaPoint,
                        double* oaFirstDeriv,
                        double* oaSecondDeriv,
                        double* oaThirdDeriv) CATCDSOverride;

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
  virtual void SetDirection2D(double oX, double oY) CATCDSOverride;
  virtual void GetDirection2D(double &oX, double &oY) CATCDSOverride;
  virtual void GetDirection(double &oX, double &oY, double &oZ) CATCDSOverride;

  virtual CATCSNOffsetCurve2D* GetOffsetNode();

  //Return the parameters of a NURBS approximation of this offset
  virtual CATCDSBoolean GetNURBSApprox(double& iLinearTolerance, int& oNbOfControlPoints, int& oDegree, double*& oControlPoints, double*& oKnots, double*& oWeights);

  virtual CATCSType GetType() const CATCDSOverride;

  CATCSOffsetCurve2D();
protected :

  // Get the initial limits, not taking into account a possible extrapolation
  // This method must be redefined in all classes that implement Extrapolate() method
  virtual CATParamType GetInitialLimits(double &oInitialLow, double &oInitialUp) CATCDSOverride;

private:

  CATCSMonoParametric* _pBase;

  // Only one of the following three data should be not null
  double _offset;
  CATCSVariable* _pVar;

  CATCDSBoolean _periodic;
  CATCSExtrapolMode _ExtrapModeLow, _ExtrapModeUp;
  double _ExtrapLow, _ExtrapUp; // meaningless (=0.) if _ExtrapMode==exNONE
};

//-----------------------------------------------------------------------

#endif
