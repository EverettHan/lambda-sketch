// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSParabola.h
// Header definition of CATCSParabola
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Dec 2010  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSParabola_H
#define CATCSParabola_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSMonoParametric.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a parabola in three-dimensional space.
 */
class ExportedBySolverInterface CATCSParabola : public CATCSMonoParametric
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSParabola();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define a center.
   *   The second three ones define a direction of major axis. The third three
   *   ones define a normal.
   * @param iCurvature
   *   A curvature at the parabola vertex.
   */
  CATCSParabola(const double iaCoord[9], double iCurvature);

  virtual ~CATCSParabola();

  /**
   * Retrieves type of the geometry.
   * @return
   *   Type of the geometry.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the geometry is matched to a specific type. The geometry
   * can be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
   * Get the parameter limits of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if curve is periodic or bounded
   */
  virtual CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

  /**
   * Applies an affine transformation to the geometry.
   * @param iMatrix
   *   A matrix representing a rotation in three-dimensional space.
   * @param iTranslation
   *   A vector representing a translation in three-dimensional space.
   */
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  /**
   * Retrieves coordinates of the parabola center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ);

  virtual void SetCenter(double iX, double iY, double iZ);
  virtual void SetNormal(double iX, double iY, double iZ);
  virtual void GetNormal(double &oX, double &oY, double &oZ);
  virtual void GetDirection(double &oX, double &oY, double &oZ);
  virtual void SetDirection(double iX, double iY, double iZ);

  /**
   * Retrieves coordinates of the parabola major direction and the parabola
   * normal.
   * @param oX1
   *   An abscissa axis of major direction.
   * @param oY1
   *   An ordinate axis of major direction.
   * @param oZ1
   *   An applicate axis of major direction.
   * @param oX2
   *   An abscissa axis of normal.
   * @param oY2
   *   An ordinate axis of normal.
   * @param oZ2
   *   An applicate axis of normal.
   */
  virtual void GetDirections(double &oX1, double &oY1, double &oZ1, double &oX2, double &oY2, double &oZ2);

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to nine for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[9]) CATCDSOverride;

  /**
   * Sets vertex curvature of the parabola.
   * @param iCurvature
   *   A vertex curvature of the parabola.
   * @see #GetVertexCurvature
   */
  virtual void SetVertexCurvature(double iCurvature);

  /**
   * Retrieves vertex curvature of the parabola.
   * @return
   *   A vertex curvature of the parabola.
   * @see #SetVertexCurvature
   */
  virtual double GetVertexCurvature();
  
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

private:
  double _aCoord[9];
  double _Curvature;
};

//-----------------------------------------------------------------------

#endif
