#ifndef CATICDSHyperbola_H
#define CATICDSHyperbola_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric.h"

class CATICDSFactory;

/**
 * A geometry representing a hyperbola in two-dimensional space.
 */
class ExportedByCDSInterface CATICDSHyperbola : public CATICDSMonoParametric
{
public:

  /**
   * Retrieves coordinates of the hyperbola center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the hyperbola center.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetCenter(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the hyperbola major direction.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetDirection(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the hyperbola major direction.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetDirection(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the hyperbola normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the hyperbola normal.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetNormal(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves major radius of the hyperbola.
   * @return
   *   A major radius of the hyperbola.
   * @see #SetMajorRadius
   */
  virtual double GetMajorRadius() const = 0;

  /**
   * Sets the major radius of the hyperbola.
   * @param iRadius
   *   A major radius of the hyperbola.
   * @see #GetMajorRadius
   */
  virtual void SetMajorRadius(double iRadius) = 0;

  /**
   * Retrieves the minor radius of the hyperbola.
   * @return
   *   A minor radius of the hyperbola.
   * @see #SetMinorRadius
   */
  virtual double GetMinorRadius() const = 0;

  /**
   * Sets the minor radius of the hyperbola.
   * @param iRadius
   *   A minor radius of the hyperbola.
   * @see #GetMinorRadius
   */
  virtual void SetMinorRadius(double iRadius) = 0;

  /**
   * Creates an instance of the CATICDSHyperbola geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iOriginX
   *   X coordinate of the center of the hyperbola.
   * @param iOriginY
   *   Y coordinate of the center of the hyperbola.
   * @param iOriginZ
   *   Z coordinate of the center of the hyperbola.
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
   * @param iMajorRadius
   *   Input value that specifies the major radius of the hyperbola.
   * @param iMinorRadius
   *   Input value that specifies the minor radius of the hyperbola.
   */
  static CATICDSHyperbola* Create(CATICDSFactory* ipFactory,
                                  double iOriginX, double iOriginY, double iOriginZ,
                                  double iDirectionX, double iDirectionY, double iDirectionZ,
                                  double iNormalX, double iNormalY, double iNormalZ,
                                  double iMajorRadius, double iMinorRadius);

  virtual ~CATICDSHyperbola() {}
};

#endif
