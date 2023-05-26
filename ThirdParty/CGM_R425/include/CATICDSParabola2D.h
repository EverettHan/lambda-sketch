#ifndef CATICDSParabola2D_H
#define CATICDSParabola2D_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric2D.h"

class CATICDSFactory;

/**
 * A geometry representing a parabola in two-dimensional space.
 */
class ExportedByCDSInterface CATICDSParabola2D : public CATICDSMonoParametric2D
{
public:

  /**
   * Retrieves coordinates of the parabola center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetCenter(double &oX, double &oY) const = 0;

  /**
   * Specify coordinates of the parabola center.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   */
  virtual void SetCenter(double iX, double iY) = 0;

  /**
   * Retrieves coordinates of the parabola major direction (perpendicular to the symmetry axis).
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetDirection(double &oX, double &oY) const = 0;

  /**
   * Specify coordinates of the parabola major direction (perpendicular to the symmetry axis).
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   */
  virtual void SetDirection(double iX, double iY) = 0;

  /**
   * Sets the vertex curvature of the parabola.
   * @param iCurvature
   *   A vertex curvature of the parabola.
   * @see #GetVertexCurvature
   */
  virtual void SetVertexCurvature(double iCurvature) = 0;

  /**
   * Retrieves the vertex curvature of the parabola.
   * @return
   *   A vertex curvature of the parabola.
   * @see #SetVertexCurvature
   */
  virtual double GetVertexCurvature() const = 0;

  /**
   * Creates an instance of the CATICDSParabola2D geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the parabola origin.
   * @param iOriginY
   *   Y coordinate of the parabola origin.
   * @param iDirectionX
   *   Input value that specifies the normalized X-direction of the major radius.
   * @param iDirectionY
   *   Input value that specifies the normalized Y-direction of the major radius.
   * @param iCurvature
   *   Input value that specifies the angle of curvature (radians) of the parabola.
   */
  static CATICDSParabola2D* Create(CATICDSFactory* ipFactory,
                                   double iOriginX, double iOriginY,
                                   double iDirectionX, double iDirectionY,
                                   double iCurvature);

  virtual ~CATICDSParabola2D() {}
};

#endif
