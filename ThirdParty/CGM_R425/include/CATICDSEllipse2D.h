#ifndef CATICDSEllipse2D_H
#define CATICDSEllipse2D_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric2D.h"

class CATICDSFactory;

/**
 * A geometry representing an Ellipse in two-dimensional space.
 */
class ExportedByCDSInterface CATICDSEllipse2D : public CATICDSMonoParametric2D
{
public:
  
  /**
   * Retrieves coordinates of the ellipse center.
   * @param oX
   *   Returned value of the X coordinate
   * @param oY
   *   Returned value of the Y coordinate
   */
  virtual void GetCenter(double &oX, double &oY) const = 0;

  /**
   * Sets coordinates of the ellipse center.
   * @param oX
   *   Input value of the X coordinate
   * @param oY
   *   Input value of the Y coordinate
   */
  virtual void SetCenter(double iX, double iY) = 0;

  /**
   * Retrieves coordinates of the ellipse major axis direction.
   * @param oX
   *   Returned value of the direction's X component
   * @param oY
   *   Returned value of the direction's Y component
   */
  virtual void GetDirection(double &oX, double &oY) const = 0;

  /**
   * Sets coordinates of the ellipse major axis direction.
   * @param oX
   *   Input value of the direction's X component
   * @param oY
   *   Input value of the direction's Y component
   */
  virtual void SetDirection(double iX, double iY) = 0;

  /**
   * Sets major radius of the ellipse.
   * @param iRadius
   *   A major radius of the ellipse.
   */
  virtual void SetMajorRadius(double iRadius) = 0;

  /**
   * Sets minor radius of the ellipse.
   * @param iRadius
   *   A minor radius of the ellipse.
   */
  virtual void SetMinorRadius(double iRadius) = 0;

  /**
   * Retrieves major radius of the ellipse.
   * @return
   *   The major radius of the ellipse.
   */
  virtual double GetMajorRadius() const = 0;

  /**
   * Retrieves minor radius of the ellipse.
   * @return
   *   The minor radius of the ellipse.
   */
  virtual double GetMinorRadius() const = 0;

  /**
   * Creates an instance of the CATICDSEllipse2D geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param iOriginX
   *   X coordinate of the center of the ellipse
   * @param iOriginY
   *   Y coordinate of the center of the ellipse
   * @param iDirectionX
   *   X component of the direction of the major axis
   * @param iDirectionY
   *   Y component of the direction of the major axis
   * @param iMajorRadius
   *   Major radius of the ellipse
   * @param iMinorRadius
   *   Minor radius of the ellipse
   */
  static CATICDSEllipse2D* Create(CATICDSFactory* ipFactory,
                                  double iOriginX, double iOriginY,
                                  double iDirectionX, double iDirectionY,
                                  double iMajorRadius, double iMinorRadius);

  virtual ~CATICDSEllipse2D() {}
};

#endif
