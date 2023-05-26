#ifndef CATICDSSphere_H
#define CATICDSSphere_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a sphere in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSSphere : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the sphere center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the sphere center.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetCenter(double iX, double iY, double iZ) = 0;

  /**
   * Sets radius of the sphere.
   * @param iRadius
   *   A radius of the sphere.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius) = 0;

  /**
   * Retrieves radius of the sphere.
   * @return
   *   A radius of the sphere.
   * @see #SetRadius
   */
  virtual double GetRadius() const = 0;

  /**
   * Creates an instance of the CATICDSSphere geometry.
   * @param ipFactory
   *   Sphereer to the instance of CATICDSFactory to use.
   * @param iX
   *   X coordinate of the sphere center.
   * @param iY
   *   Y coordinate of the sphere center.
   * @param iZ
   *   Z coordinate of the sphere center.
   * @param iRadius
   *   Radius of the sphere.
   */
  static CATICDSSphere* Create(CATICDSFactory *ipFactory,
                               double iX, double iY, double iZ,
                               double iRadius);

  virtual ~CATICDSSphere() {}
};

#endif
