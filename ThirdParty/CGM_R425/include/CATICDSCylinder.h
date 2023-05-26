#ifndef CATICDSCylinder_H
#define CATICDSCylinder_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a point in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSCylinder : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the axis origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetAxisOrigin(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the axis origin.
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
   * Sets radius of the cylinder.
   * @param iRadius
   *   A radius of the cylinder.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius) = 0;

  /**
   * Retrieves radius of the cylinder.
   * @return
   *   A radius of the cylinder.
   * @see #SetRadius
   */
  virtual double GetRadius() const = 0;

  /**
   * Creates an instance of the CATICDSCylinder geometry.
   * @param ipFactory
   *   Coneer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the cylinder apex.
   * @param iOriginY
   *   Y coordinate of the cylinder apex.
   * @param iOriginZ
   *   Z coordinate of the cylinder apex.
   * @param iDirectionX
   *   X coordinate of the cylinder axis direction.
   * @param iDirectionY
   *   Y coordinate of the cylinder axis direction.
   * @param iDirectionZ
   *   Z coordinate of the cylinder axis direction.
   * @param iRadius
   *   Radius of the cylinder.
   */
  static CATICDSCylinder* Create(CATICDSFactory *ipFactory,
                                 double iOriginX, double iOriginY, double iOriginZ,
                                 double iDirectionX, double iDirectionY, double iDirectionZ,
                                 double iRadius);

  virtual ~CATICDSCylinder() {}
};

#endif
