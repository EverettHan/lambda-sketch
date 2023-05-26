#ifndef CATICDSParabola_H
#define CATICDSParabola_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric.h"

class CATICDSFactory;

/**
 * A geometry representing a parabola in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSParabola : public CATICDSMonoParametric
{
public:

  /**
   * Retrieves coordinates of the parabola center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the parabola center.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetCenter(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the parabola major direction (perpendicular to the symmetry axis).
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetDirection(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the parabola major direction (perpendicular to the symmetry axis).
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetDirection(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the parabola normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the parabola normal.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetNormal(double iX, double iY, double iZ) = 0;
  
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
   * Creates an instance of the CATICDSParabola geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the parabola origin.
   * @param iOriginY
   *   Y coordinate of the parabola origin.
   * @param oZ
   *   Z coordinate of the parabola origin.
   * @param iDirectionX
   *   Input value that specifies the normalized X-direction of the major radius.
   * @param iDirectionY
   *   Input value that specifies the normalized Y-direction of the major radius.
   * @param iDirectionZ
   *   Input value that specifies the normalized Z-direction of the major radius.
   * @param iNormalX
   *   Input value that specifies the normalized X-direction of the normal.
   * @param iNormalY
   *   Input value that specifies the normalized Y-direction of the normal.
   * @param iNormalZ
   *   Input value that specifies the normalized Z-direction of the normal.
   * @param iCurvature
   *   Input value that specifies the angle of curvature (radians) of the parabola.
   */
  static CATICDSParabola* Create(CATICDSFactory* ipFactory, 
                                 double iOriginX, double iOriginY, double iOriginZ,
                                 double iDirectionX, double iDirectionY, double iDirectionZ,
                                 double iNormalX, double iNormalY, double iNormalZ,
                                 double iCurvature);

  virtual ~CATICDSParabola() {}
};

#endif
