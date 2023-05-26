#ifndef CATICDSCylicone_H
#define CATICDSCylicone_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a cylicone in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSCylicone : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the cylicone apex.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetAxisOrigin(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the cylicone apex.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetAxisOrigin(double iX, double iY, double iZ) = 0;
  
  /**
   * Retrieves coordinates of the axis direction.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetAxisDirection(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the axis direction.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetAxisDirection(double iX, double iY, double iZ) = 0;
  
  /**
   * Sets radius of the cylicone.
   * @param iRadius
   *   An radius of the cylicone.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius) = 0;

  /**
   * Retrieves radius of the cylicone.
   * @return
   *   An radius of the cylicone.
   * @see #SetRadius
   */
  virtual double GetRadius() const = 0;

  /**
   * Sets angle of the cylicone.
   * @param iAngle
   *   An angle of the cylicone.
   * @see #GetAngle
   */
  virtual void SetAngle(double iAngle) = 0;

  /**
   * Retrieves angle of the cylicone.
   * @return
   *   An angle of the cylicone.
   * @see #SetAngle
   */
  virtual double GetAngle() const = 0;

  /**
   * Creates an instance of the CATICDSCylicone geometry.
   * @param ipFactory
   *   Cyliconeer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the cylicone apex.
   * @param iOriginY
   *   Y coordinate of the cylicone apex.
   * @param iOriginZ
   *   Z coordinate of the cylicone apex.
   * @param iDirectionX
   *   X coordinate of the cylicone axis direction.
   * @param iDirectionY
   *   Y coordinate of the cylicone axis direction.
   * @param iDirectionZ
   *   Z coordinate of the cylicone axis direction.
   * @param iAngle
   *   Angle of the cylicone.
   * @param iRadius
   *   Radius of the cylicone.
   */
  static CATICDSCylicone* Create(CATICDSFactory *ipFactory,
                             double iOriginX, double iOriginY, double iOriginZ,
                             double iDirectionX, double iDirectionY, double iDirectionZ,
                             double iRadius, double iAngle);

  virtual ~CATICDSCylicone() {}
};

#endif
