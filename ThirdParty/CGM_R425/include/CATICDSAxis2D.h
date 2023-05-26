#ifndef CATICDSAxis2D_H
#define CATICDSAxis2D_H

// COPYRIGHT DASSAULT SYSTEMES  2015

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
class ExportedByCDSInterface CATICDSAxis2D : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the axis origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetOrigin(double &oX, double &oY) const = 0;

  /**
   * Specify coordinates of the axis origin.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   */
  virtual void SetOrigin(double iX, double iY) = 0;

  /**
   * Retrieves coordinates of the axis vectors.
   * @param oX1
   *   An abscissa of the first vector.
   * @param oY1
   *   An ordinate of the first vector.
   * @param oX2
   *   An abscissa of the second vector.
   * @param oY2
   *   An ordinate of the second vector.
   *
   * @SKIP
   */
  virtual void GetVectors(double &oX1, double &oY1,
                          double &oX2, double &oY2) const = 0;
  
  /**
   * Specify coordinates of the axis vectors.
   * @param iX1
   *   An abscissa of the first vector.
   * @param iY1
   *   An ordinate of the first vector.
   * @param iX2
   *   An abscissa of the second vector.
   * @param iY2
   *   An ordinate of the second vector.
   */
  virtual void SetVectors(double iX1, double iY1,
                          double iX2, double iY2) = 0;
  
  /**
   * Creates an instance of the CATICDSAxis2D geometry.
   * @param ipFactory
   *   Axiser to the instance of CATICDSFactory to use.
   * @param iX
   *   X coordinate of the point.
   * @param iY
   *   Y coordinate of the point.
   * @param iX1
   *   An abscissa of the first vector.
   * @param iY1
   *   An ordinate of the first vector.
   * @param iX2
   *   An abscissa of the second vector.
   * @param iY2
   *   An ordinate of the second vector.
   */
  static CATICDSAxis2D* Create(CATICDSFactory *ipFactory,
                             double iX , double iY,
                             double iX1, double iY1,
                             double iX2, double iY2);

  virtual ~CATICDSAxis2D() {}
};

#endif
