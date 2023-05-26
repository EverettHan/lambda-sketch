#ifndef CATICDSCircle_H
#define CATICDSCircle_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric.h"

class CATICDSFactory;

/**
 * A geometry representing a Circle in two-dimensional space.
 */
class ExportedByCDSInterface CATICDSCircle : public CATICDSMonoParametric
{
public:

  /**
   * Retrieves coordinates of the circle center.
   * @param oX
   *   Returned value of the X coordinate
   * @param oY
   *   Returned value of the Y coordinate
   * @param oZ
   *   Returned value of the Z coordinate.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ) = 0;

  /**
   * Sets the coordinates of the circle center.
   * @parai oX
   *   Input value of the X coordinate
   * @param iY
   *   Input value of the Y coordinate
   * @param iZ
   *   Input value of the Zcoordinate
   */
  virtual void SetCenter(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the circle normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ) = 0;

  /**
   * Specify coordinates of the circle normal.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetNormal(double iX, double iY, double iZ) = 0;

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
  virtual double GetRadius() = 0;

  /**
   * Creates an instance of the CATICDSCircle geometry
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param iOriginX
   *   X coordinate of the center of the circle
   * @param iOriginY
   *   Y coordinate of the center of the circle
   * @param iOriginZ
   *   Z coordinate of the center of the circle
   * @param iNormalX
   *   Input value that specifies the normalized X-direction of the normal.
   * @param iNormalY
   *   Input value that specifies the normalized Y-direction of the normal.
   * @param iNormalZ
   *   Input value that specifies the normalized Z-direction of the normal.
   * @param iRadius
   *   Radius of the circle
   */
  static CATICDSCircle* Create(CATICDSFactory* ipFactory,
                               double iOriginX, double iOriginY, double iOriginZ,
                               double iNormalX, double iNormalY, double iNormalZ,
                               double iRadius);

  virtual ~CATICDSCircle() {}
};

#endif
