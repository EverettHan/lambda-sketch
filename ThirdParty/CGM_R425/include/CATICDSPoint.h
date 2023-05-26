#ifndef CATICDSPoint_H
#define CATICDSPoint_H

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
class ExportedByCDSInterface CATICDSPoint : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Retrieves coordinates of the point.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oz
   *   An applicate axis.
   */
  virtual void GetCoord(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Updates coordinates of the point
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iz
   *   An applicate axis.
   */
  virtual void SetCoord(double iX, double iY, double iZ) = 0;

  /**
   * Creates an instance of the CATICDSPoint geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iX
   *   X coordinate of the point.
   * @param iY
   *   Y coordinate of the point.
   * @param iZ
   *   Z coordinate of the point.
   */
  static CATICDSPoint* Create(CATICDSFactory *ipFactory,
                              double iX, double iY, double iZ);

  virtual ~CATICDSPoint() {}
};

#endif
