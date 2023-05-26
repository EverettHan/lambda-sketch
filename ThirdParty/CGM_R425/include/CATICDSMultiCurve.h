#ifndef CATICDSMultiCurve_H
#define CATICDSMultiCurve_H

// COPYRIGHT DASSAULT SYSTEMES  2021

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSCurve.h"

class CATICDSFactory;

/**
 * A 3D MultiCurve.
 */
class ExportedByCDSInterface CATICDSMultiCurve : public CATICDSCurve
{
public:
  /**
   * Add a line to the multicurve.
   * @param iOriginX.
   *   X coordinate of first extrimity of the line
   * @param iOriginY.
   *   Y coordinate of first extrimity of the line
   * @param iOriginZ.
   *   Z coordinate of first extrimity of the line
   * @param iDestinX.
   *   X coordinate of second extrimity of the line
   * @param iDestinY.
   *   Y coordinate of second extrimity of the line
   * @param iDestinZ.
   *   Z coordinate of second extrimity of the line
   *
   */
  virtual void AddLine(double iOriginX, double iOriginY, double iOriginZ,
                       double iDestinX, double iDestinY, double iDestinZ) = 0;

  /**
   * Add a circle to the multicurve
   * @param iOriginX
   *   X coordinate of the center of the circle
   * @param iOriginY
   *   Y coordinate of the center of the circle
   * @param iOriginZ
   *   Z coordinate of the center of the circle
   * @param iAbsciX
   *   Input value that specifies the normalized X-direction of the abscissa
   * @param iAbsciY
   *   Input value that specifies the normalized Y-direction of the abscissa
   * @param iAbsciZ
   *   Input value that specifies the normalized Z-direction of the abscissa
   * @param iOrdX
   *   Input value that specifies the normalized X-direction of the ordinate
   * @param iOrdY
   *   Input value that specifies the normalized Y-direction of the ordinate
   * @param iOrdZ
   *   Input value that specifies the normalized Z-direction of the ordinate
   * @param iRadius
   *   Radius of the circle
   * @param iParam
   *   Parameter
   */
  virtual void AddCircle(double iOriginX, double iOriginY, double iOriginZ,
                         double iAbsciX, double iAbsciY, double iAbsciZ,
                         double iOrdX, double iOrdY, double iOrdZ,
                         double iRadius, double iParamBegin, double iParamEnd) = 0;
  
  /**
   * Constructs an instance of 3D MultiCurve.
   * @param ipFactory.
   *   Pointer to the instance of CATICDSFactory to use
   *
   */
  static CATICDSMultiCurve* Create(CATICDSFactory *ipFactory, double iOriginX, double iOriginY, double iOriginZ,
                                                              double iDestinX, double iDestinY, double iDestinZ);

  static CATICDSMultiCurve* Create(CATICDSFactory* ipFactory, double iOriginX, double iOriginY, double iOriginZ,
                                                              double iAbsciX, double iAbsciY, double iAbsciZ,
                                                              double iOrdX, double iOrdY, double iOrdZ,
                                                              double iRadius, double iParamBegin, double iParamEnd);

  virtual ~CATICDSMultiCurve() {}
};

#endif
