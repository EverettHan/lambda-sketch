#ifndef CATICDSPlane_H
#define CATICDSPlane_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a plane in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSPlane : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the plane origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetOrigin(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the plane origin.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetOrigin(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the plane normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the plane normal.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetNormal(double iX, double iY, double iZ) = 0;

  /**
   * Creates an instance of the CATICDSPlane geometry.
   * @param ipFactory
   *   Planeer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the plane origin.
   * @param iOriginY
   *   Y coordinate of the plane origin.
   * @param iOriginZ
   *   Z coordinate of the plane origin.
   * @param iNormalX
   *   X coordinate of the plane normal.
   * @param iNormalY
   *   Y coordinate of the plane normal.
   * @param iNormalZ
   *   Z coordinate of the plane normal.
   */
  static CATICDSPlane* Create(CATICDSFactory *ipFactory,
                              double iOriginX, double iOriginY, double iOriginZ,
                              double iNormalX, double iNormalY, double iNormalZ);

  virtual ~CATICDSPlane() {}
};

#endif
