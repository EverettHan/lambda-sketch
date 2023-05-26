// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATCSCurve.h
// Header definition of CATCSCurve
//
//===================================================================
//
// Usage notes:
//   This class is to derived in the application to represent
//   a callback information about a parametric curve.
//   A curve is supposed to have G1 continuity.
//
//===================================================================
//
//  Jan 2003  Creation:                   Dmitry USHAKOV
//===================================================================
#ifndef CATCSCurve_H
#define CATCSCurve_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCDSBoolean.h"
#include "CATCSMonoParametric.h"
#include "CATCDSEnums.h"
#include "CATCDSConstants.h"

//-----------------------------------------------------------------------

/**
 * A callback for parametric curve.
 * Provides an information about parameter limits, and evaluators
 * for curves and its derivative.
 */
class ExportedBySolverInterface CATCSCurve: public CATCSMonoParametric
{
public:
  CATCSCurve();
  virtual ~CATCSCurve();

  virtual CATCSCurve* Clone() const;


  /**
  * Get the type of the curve
  * An application should never re-define these methods.
  */
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
  virtual CATCDSBoolean IsPlanar(double oPlaneCoords[6], double iLinearTolerance = CATCDSDefaultLinearTolerance);

  /**
  * Compute the closest point on the curve to a 3D point 
  * @param iPointCoords
  *    Coordinates of the 3d point
  * @param oParameter
  *    Parameter on the curve corresponding to the minimal distance
  * @return
  *    TRUE if the closest point has been computed, FALSE otherwise
  */
  virtual CATCDSBoolean ComputeDistanceMinParameter(double iPointCoords[3], double & oParameter);

  /**
  * Extend the parametric domain from [Low, Up] to [iNewLow, iNewUp], assuming iNewLow<Low and iNewUp>Up
  * Returns FALSE if extrapolation is not allowed for the given curve and/or for the given extrapolation mode (for instance, circles cannot be extrapolated)
  * @param iNewLow
  *     New Lower bound of parametrization interval, must be inferior or equal to the old lower bound
  * @param iNewUp
  *     New Upper bound of parametrization interval, must be superior or equal to the old upper bound
  * @param iMode
  *     Extrapolation mode, linear by default : In a linear extrapolation, the value of the 1st derivative at the old bound prevails throughout the extrapolated part of the parameter range.
  *     So the 1st derivative remains constant and equal to its value at the old bound, and the 2nd derivative is null between the old and the bew bounds.
  */
  virtual CATCDSBoolean Extrapolate(double iNewLow, double iNewUp, CATCSExtrapolMode iMode = exLINEAR);

  virtual CATCSExtrapolMode GetExtrapolationMode() const;

  /**
  * Compute curve curvature at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvature
  *    Computed curvature
  * @return
  *    FALSE if computation failed
  */
  virtual CATCDSBoolean EvaluateCurvature(double iT, double &oCurvature) CATCDSOverride;

  /**
  * Compute curve curvature derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvatureDeriv
  *    Computed curvature deriv
  * @return
  *    FALSE if computation failed
  */
  virtual CATCDSBoolean EvaluateCurvatureDeriv(double iT, double &oCurvatureDeriv) CATCDSOverride;

  /* for internal use */
  virtual void Stream(char *& oStreamData, size_t & oLength);

  /**
   * DO NOT USE
   * TEST ONLY
   */
  virtual void Scale(double iFactor);

protected :
  // Get the initial limits, not taking into account a possible extrapolation
  // This method must be redefined in all classes that implement Extrapolate() method
  virtual CATParamType GetInitialLimits(double &oInitialLow, double &oInitialUp) CATCDSOverride;

};

//-----------------------------------------------------------------------

#endif
