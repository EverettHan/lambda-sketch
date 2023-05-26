#ifndef CATICDSPoint2D_H
#define CATICDSPoint2D_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A geometry representing a point in two-dimensional space.
 */
class ExportedByCDSInterface CATICDSPoint2D : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the point.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetCoord(double &oX, double &oY) const = 0;

  /**
   * Updates coordinates of the point
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   */
  virtual void SetCoord(double iX, double iY) = 0;

  /**
   * Creates an instance of the CATICDSPoint2D geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iX
   *   X coordinate of the point.
   * @param iY
   *   Y coordinate of the point.
   */
  static CATICDSPoint2D* Create(CATICDSFactory *ipFactory,
                                double iX, double iY);

  /** @DEPRECATED */
  virtual void GetCoord2D(double &oX, double &oY) const = 0;
  
  virtual ~CATICDSPoint2D() {}
};

#endif
