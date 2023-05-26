#ifndef CATICDSTorus_H
#define CATICDSTorus_H

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
class ExportedByCDSInterface CATICDSTorus : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the torus center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the torus center.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetCenter(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the torus normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the torus normal.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetNormal(double iX, double iY, double iZ) = 0;

  /**
   * Sets major radius of the torus.
   * @param iRadius
   *   A major radius of the torus.
   * @see #GetMajorRadius
   */
  virtual void SetMajorRadius(double iRadius) = 0;

  /**
   * Sets minor radius of the torus.
   * @param iRadius
   *   A minor radius of the torus.
   * @see #GetMinorRadius
   */
  virtual void SetMinorRadius(double iRadius) = 0;

  /**
   * Retrieves major radius of the torus.
   * @return
   *   A major radius of the torus.
   * @see #SetMajorRadius
   */
  virtual double GetMajorRadius() const = 0;

  /**
   * Retrieves minor radius of the torus.
   * @return
   *   A minor radius of the torus.
   * @see #SetMinorRadius
   */
  virtual double GetMinorRadius() const = 0;

  /**
   * Creates an instance of the CATICDSTorus geometry.
   * @param ipFactory
   *   Coneer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the torus center.
   * @param iOriginY
   *   Y coordinate of the torus center.
   * @param iOriginZ
   *   Z coordinate of the torus center.
   * @param iNormalX
   *   X coordinate of the torus normal.
   * @param iNormalY
   *   Y coordinate of the torus normal.
   * @param iNormalZ
   *   Z coordinate of the torus normal.
   * @param iMajorRadius
   *   Major radius of the torus.
   * @param iMinorRadius
   *   Minor radius of the torus.
   */
  static CATICDSTorus* Create(CATICDSFactory *ipFactory,
                              double iOriginX, double iOriginY, double iOriginZ,
                              double iNormalX, double iNormalY, double iNormalZ,
                              double iMajorRadius, double iMinorRadius);

  virtual ~CATICDSTorus() {}
};

#endif
