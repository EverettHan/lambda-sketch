#ifndef CATICDSEllipse_H
#define CATICDSEllipse_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric.h"

class CATICDSFactory;

/**
 * A geometry representing an Ellipse in two-dimensional space.
 */
class ExportedByCDSInterface CATICDSEllipse : public CATICDSMonoParametric
{
public:
  
  /**
   * Retrieves coordinates of the ellipse center.
   * @param oX
   *   Returned value of the X coordinate
   * @param oY
   *   Returned value of the Y coordinate
   * @param oZ
   *   An applicate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Sets coordinates of the ellipse center.
   * @param oX
   *   Input value of the X coordinate
   * @param oY
   *   Input value of the Y coordinate
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetCenter(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the ellipse major axis direction.
   * @param oX
   *   Returned value of the direction's X component
   * @param oY
   *   Returned value of the direction's Y component
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetDirection(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Sets coordinates of the ellipse major axis direction.
   * @param oX
   *   Input value of the direction's X component
   * @param oY
   *   Input value of the direction's Y component
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetDirection(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the ellipse normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the ellipse normal.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetNormal(double iX, double iY, double iZ) = 0;
  
  /**
   * Sets major radius of the ellipse.
   * @param iRadius
   *   A major radius of the ellipse.
   */
  virtual void SetMajorRadius(double iRadius) = 0;

  /**
   * Retrieves major radius of the ellipse.
   * @return
   *   The major radius of the ellipse.
   */
  virtual double GetMajorRadius() const = 0;

  /**
   * Sets minor radius of the ellipse.
   * @param iRadius
   *   A minor radius of the ellipse.
   */
  virtual void SetMinorRadius(double iRadius) = 0;

  /**
   * Retrieves minor radius of the ellipse.
   * @return
   *   The minor radius of the ellipse.
   */
  virtual double GetMinorRadius() const = 0;

  /**
   * Creates an instance of the CATICDSEllipse geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param iOriginX
   *   X coordinate of the center of the ellipse
   * @param iOriginY
   *   Y coordinate of the center of the ellipse
   * @param iOriginZ
   *   Z coordinate of the center of the ellipse
   * @param iDirectionX
   *   X component of the direction of the major axis
   * @param iDirectionY
   *   Y component of the direction of the major axis
   * @param iDirectionZ
   *   Z component of the direction of the major axis
   * @param iNormalX
   *   Input value that specifies the normalized X-direction of the normal.
   * @param iNormalY
   *   Input value that specifies the normalized Y-direction of the normal.
   * @param iNormalZ
   *   Input value that specifies the normalized Z-direction of the normal.
   * @param iMajorRadius
   *   Major radius of the ellipse
   * @param iMinorRadius
   *   Minor radius of the ellipse
   */
  static CATICDSEllipse* Create(CATICDSFactory* ipFactory,
                                double iOriginX, double iOriginY, double iOriginZ,
                                double iDirectionX, double iDirectionY, double iDirectionZ,
                                double iNormalX, double iNormalY, double iNormalZ,
                                double iMajorRadius, double iMinorRadius);

  virtual ~CATICDSEllipse() {}
};

#endif
