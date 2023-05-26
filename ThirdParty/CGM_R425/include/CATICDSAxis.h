#ifndef CATICDSAxis_H
#define CATICDSAxis_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a axis in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSAxis : public CATICDSGeometryLeaf
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
  virtual void GetOrigin(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Specify coordinates of the axis origin.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetOrigin(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the axis vectors.
   * @param oX1
   *   An abscissa of the first vector.
   * @param oY1
   *   An ordinate of the first vector.
   * @param oZ1
   *   An applicate of the first vector.
   * @param oX2
   *   An abscissa of the second vector.
   * @param oY2
   *   An ordinate of the second vector.
   * @param oZ2
   *   An applicate of the second vector.
   * @param oX3
   *   An abscissa of the third vector.
   * @param oY3
   *   An ordinate of the third vector.
   * @param oZ3
   *   An applicate of the third vector.
   *
   * @SKIP
   */
  virtual void GetVectors(double &oX1, double &oY1, double &oZ1,
                          double &oX2, double &oY2, double &oZ2,
                          double &oX3, double &oY3, double &oZ3) const = 0;
  
  /**
   * Specify coordinates of the axis vectors.
   * @param iX1
   *   An abscissa of the first vector.
   * @param iY1
   *   An ordinate of the first vector.
   * @param iZ1
   *   An applicate of the first vector.
   * @param iX2
   *   An abscissa of the second vector.
   * @param iY2
   *   An ordinate of the second vector.
   * @param iZ2
   *   An applicate of the second vector.
   * @param iX3
   *   An abscissa of the third vector.
   * @param iY3
   *   An ordinate of the third vector.
   * @param iZ3
   *   An applicate of the third vector.
   */
  virtual void SetVectors(double iX1, double iY1, double iZ1,
                          double iX2, double iY2, double iZ2,
                          double iX3, double iY3, double iZ3) = 0;
  
  /**
   * Creates an instance of the CATICDSAxis geometry.
   * @param ipFactory
   *   Axiser to the instance of CATICDSFactory to use.
   * @param iX
   *   X coordinate of the point.
   * @param iY
   *   Y coordinate of the point.
   * @param iZ
   *   Z coordinate of the point.
   * @param iX1
   *   An abscissa of the first vector.
   * @param iY1
   *   An ordinate of the first vector.
   * @param iZ1
   *   An applicate of the first vector.
   * @param iX2
   *   An abscissa of the second vector.
   * @param iY2
   *   An ordinate of the second vector.
   * @param iZ2
   *   An applicate of the second vector.
   * @param iX3
   *   An abscissa of the third vector.
   * @param iY3
   *   An ordinate of the third vector.
   * @param iZ3
   *   An applicate of the third vector.
   */
  static CATICDSAxis* Create(CATICDSFactory *ipFactory,
                             double iX , double iY , double iZ,
                             double iX1, double iY1, double iZ1,
                             double iX2, double iY2, double iZ2,
                             double iX3, double iY3, double iZ3);

  virtual ~CATICDSAxis() {}
};

#endif
