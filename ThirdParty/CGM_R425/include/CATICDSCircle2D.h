#ifndef CATICDSCircle2D_H
#define CATICDSCircle2D_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric2D.h"

class CATICDSFactory;

/**
 * A geometry representing a Circle in two-dimensional space.
 */
class ExportedByCDSInterface CATICDSCircle2D : public CATICDSMonoParametric2D
{
public:

  /**
   * Retrieves coordinates of the circle center.
   * @param oX
   *   Returned value of the X coordinate
   * @param oY
   *   Returned value of the Y coordinate
   * @see SetCenter2D
   */
  virtual void GetCenter(double &oX, double &oY) const = 0;

  /**
   * Sets the coordinates of the circle center.
   * @param oX
   *   Input value of the X coordinate
   * @param oY
   *   Input value of the Y coordinate
   * @see GetCenter2D
   */
  virtual void SetCenter(double iX, double iY) = 0;

  /**
   * Sets radius of the circle.
   * @param iRadius
   *   Input value of the radius of the circle.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius) = 0;

  /**
   * Retrieves radius of the circle.
   * @return
   *   Returned value of the radius of the circle.
   * @see #SetRadius
   */
  virtual double GetRadius() const = 0;

  /**
   * Creates an instance of the CATICDSCircle2D geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the center of the circle.
   * @param iOriginY
   *   Y coordinate of the center of the circle.
   * @param iRadius
   *   Radius of the circle.
   */
  static CATICDSCircle2D* Create(CATICDSFactory* ipFactory,
                                 double iOriginX, double iOriginY,
                                 double iRadius);

  virtual ~CATICDSCircle2D() {}
};

#endif
