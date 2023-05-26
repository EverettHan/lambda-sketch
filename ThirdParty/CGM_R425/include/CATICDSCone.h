#ifndef CATICDSCone_H
#define CATICDSCone_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a cone in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSCone : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the cone apex.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetAxisOrigin(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the cone apex.
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
   * Sets angle of the cone.
   * @param iAngle
   *   An angle of the cone.
   * @see #GetAngle
   */
  virtual void SetAngle(double iAngle) = 0;

  /**
   * Retrieves angle of the cone.
   * @return
   *   An angle of the cone.
   * @see #SetAngle
   */
  virtual double GetAngle() const = 0;

  /**
   * Creates an instance of the CATICDSCone geometry.
   * @param ipFactory
   *   Coneer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the cone apex.
   * @param iOriginY
   *   Y coordinate of the cone apex.
   * @param iOriginZ
   *   Z coordinate of the cone apex.
   * @param iDirectionX
   *   X coordinate of the cone axis direction.
   * @param iDirectionY
   *   Y coordinate of the cone axis direction.
   * @param iDirectionZ
   *   Z coordinate of the cone axis direction.
   * @param iAngle
   *   Angle of the cone.
   */
  static CATICDSCone* Create(CATICDSFactory *ipFactory,
                             double iOriginX, double iOriginY, double iOriginZ,
                             double iDirectionX, double iDirectionY, double iDirectionZ,
                             double iAngle);

  virtual ~CATICDSCone() {}
};

#endif
