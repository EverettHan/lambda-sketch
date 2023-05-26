#ifndef CATICDSLine_H
#define CATICDSLine_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSMonoParametric.h"

class CATICDSFactory;

/**
 * A geometry representing a line in three-dimensional space.
 */
class ExportedByCDSInterface CATICDSLine : public CATICDSMonoParametric
{
public:

  /**
   * Retrieves coordinates of the line origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetOrigin(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Updates coordinates of the line origin.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetOrigin(double iX, double iY, double iZ) = 0;

  /**
   * Retrieves coordinates of the line direction.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetDirection(double &oX, double &oY, double &oZ) const = 0;

  /**
   * Updates coordinates of the line direction.
   * @param iX
   *   An abscissa axis.
   * @param iY
   *   An ordinate axis.
   * @param iZ
   *   An applicate axis.
   */
  virtual void SetDirection(double iX, double iY, double iZ) = 0;

  /**
   * Creates an instance of the CATICDSLine geometry.
   * @param ipFactory.
   *   Pointer to the instance of CATICDSFactory to use
   * @param iOriginX
   *   X coordinate of the center of the line.
   * @param iOriginY
   *   Y coordinate of the center of the line.
   * @param iOriginZ
   *   Z coordinate of the center of the line.
   * @param iDirectionX
   *   Input value that specifies the normalized X-direction of the line.
   * @param iDirectionY
   *   Input value that specifies the normalized Y-direction of the line.
   * @param iDirectionZ
   *   Input value that specifies the normalized Z-direction of the line.
   */
  static CATICDSLine* Create(CATICDSFactory* ipFactory,
                             double iOriginX, double iOriginY, double iOriginZ,
                             double iDirectionX, double iDirectionY, double iDirectionZ);

  virtual ~CATICDSLine() {}
};

#endif
