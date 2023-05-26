// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSCurve2D.h
// Header definition of CATCSCurve2D
//
//===================================================================
//
// Usage notes: pure virtual class
// A CATCSCurve2D is initially defined with a given parametric domain, which can be explicitly extended by Extrapolate() method
// Note that GetLimits() is a method of the base class CATCSCurve
//
//===================================================================
//
//  May 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSCurve2D_H
#define CATCSCurve2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSCurve.h"

class CATCSSketch;
class CATCDSBox2D;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSCurve2D: public CATCSCurve
{
public:
  CATCSCurve2D();
  virtual ~CATCSCurve2D();

  // Get the type of the curve
  // An application should never re-define this method.
  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
  * Check if the curve is planar, if yes compute the support plane 
  * @param oPlaneCoords
  *    Coordinates of the support plane (origin, normal) if the curve is planar
  * @param iLinearTolerance
  *    Linear tolerance (a positive real value)
  * @return
  *    TRUE if the curve is planar, FALSE otherwise
  */
  virtual CATCDSBoolean IsPlanar(double oPlaneCoords[6], double iLinearTolerance = CATCDSDefaultLinearTolerance) CATCDSOverride;

  // This method must be re-defined.
  virtual void ApplyTransformation2D(double iMatrix[3][3]) = 0;

  // The default implementation is:
  // for each sketch: project the 3D transformation onto it,
  // then call ApplyTransformation2D.
  // An application may re-define this method.
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  // Evaluate the curve point or/and derivative at given parameter's value
  // This method must be re-defined.
  virtual void Evaluate2D(double iT,
                          double* oaPoint,
                          double* oaFirstDeriv,
                          double* oaSecondDeriv,
                          double* oaThirdDeriv = 0) = 0;

  // The default implementation is:
  // find the first planar sketch, then call Evaluate2D and
  // transform the obtained coordinates into 3D ones.
  // An application may re-define this method
  virtual void Evaluate(double iT,
                        double* oaPoint,
                        double* oaFirstDeriv,
                        double* oaSecondDeriv,
                        double* oaThirdDeriv = 0) CATCDSOverride;

  // Get the number of parametric discontinuities
  //virtual int GetNbOfDiscontinuities() = 0;

  // Fill the array of parameter values where there are discontinuities
  // (array allocated by caller)
  //virtual void GetDiscontinuitiesParams(double *oaValues) = 0;

  // For a given discontinuity index (1-based), side and parameter,
  // return point, first and second derivatives
  // (arrays allocated by caller)
  // This method must be re-defined.
  virtual void EvaluateAtDiscontinuity2D(int iIdx,
                                         CATDiscontinuitySide iSide,
                                         double iT,
                                         double* oaPoint,
                                         double* oaFirstDeriv,
                                         double* oaSecondDeriv,
                                         double* oaThirdDeriv = 0) = 0;

  // The default implementation is:
  // find the first planar sketch, then call EvaluateAtDiscontinuity2D and
  // transform the obtained coordinates into 3D ones.
  // An application may re-define this method
  virtual void EvaluateAtDiscontinuity(int iIdx,
                                       CATDiscontinuitySide iSide,
                                       double iT,
                                       double* oaPoint,
                                       double* oaFirstDeriv,
                                       double* oaSecondDeriv,
                                       double* oaThirdDeriv = 0) CATCDSOverride;

  virtual void GetDirection(double &oX, double &oY, double &oZ);

  // This method must be re-defined.
  virtual void GetDirection2D(double &oX, double &oY) = 0;

  // This method must be re-defined.
  virtual void SetDirection2D(double iX, double iY);


  virtual void GetBoundingBox(CATCDSBox *& oBox) CATCDSOverride;

  // Get the 2D box corresponding to a sub-interval of the parametric domain, oBox = null if not implemented
  virtual void Get2DBoundingBoxForSubDomain(double iWMin, double iWMax, CATCDSBox2D *& oBox) CATCDSOverride;

};

//-----------------------------------------------------------------------

#endif
