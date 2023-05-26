// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSCircle.h
// Header definition of CATCSCircle
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2004  Creation:             Konstantin Kucheryavy
//===================================================================
#ifndef CATCSCircle_H
#define CATCSCircle_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSMonoParametric.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a circle in three-dimensional space.
 */
class ExportedBySolverInterface CATCSCircle : public CATCSMonoParametric
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSCircle();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define a center.
   *   The second three ones define a normal.
   * @param iRadius
   *   A radius of the circle.
   */
  CATCSCircle(const double iaCoord[6], double iRadius);

  virtual ~CATCSCircle();

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
   * Retrieves coordinates of the circle center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ);

  virtual void SetCenter(double iX, double iY, double iZ);

  /**
   * Retrieves coordinates of the circle normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ);

  virtual void SetNormal(double iX, double iY, double iZ);

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to six for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[6]) CATCDSOverride;

  /**
   * Sets radius of the circle.
   * @param iRadius
   *   A radius of the circle.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius);

  /**
   * Retrieves radius of the circle.
   * @return
   *   A radius of the circle.
   * @see #SetRadius
   */
  virtual double GetRadius();

  /**
  * Get a bounding box for the geometry (AABB type)
  * @param oBox
  *   the bounding box
  */
  virtual void GetBoundingBox(CATCDSBox *& oBox) CATCDSOverride;

  /**
   * Compute line length between two parameters
   * @param iStart
   *    Start parameter
   * @param iEnd
   *    End parameter
   * @param oLength
   *    Computed length
   * @return
   *    FALSE if computation failed
   */
  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride;


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
  double _aCoord[6];
  double _Radius;
};

//-----------------------------------------------------------------------

#endif
