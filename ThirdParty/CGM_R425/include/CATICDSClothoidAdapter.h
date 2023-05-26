#ifndef CATICDSClothoidAdapter_H
#define CATICDSClothoidAdapter_H

// COPYRIGHT DASSAULT SYSTEMES  2016
#include "CATCDS.h"
#include "CATICDSBBoxCurve2DAdapter.h"

class CATICDSFactory;
class CATICDSPoint2D;
class CATICDSLine2D;
class CATICDSCircle2D;
class CATPlane;
class CATCurve;
class CATTolerance;
class CATGeoFactory;
class CATCSTransitionCurve2D;


/**
 * A clothoid.
 */
class ExportedByCDSInterface CATICDSClothoidAdapter : public CATICDSBBoxCurve2DAdapter
{
public:

  /**
   * Returns the initial point defining the clothoïd
   * @return Initial point
   */
  virtual CATICDSPoint2D* GetInitialPoint() const = 0;

  /**
   * Returns the initial line defining the clothoïd
   * @return Initial tangent line
   */
  virtual CATICDSLine2D* GetInitialLine() const = 0;

  /**
   * Returns the initial circle defining the clothoïd
   * @return Initial tangent circle
   */
  virtual CATICDSCircle2D* GetInitialCircle() const = 0;

  /**
   * Returns initial line tangent side with respect to line direction
   * @return Tangent side
   */
  virtual int GetInitialOrient() const = 0;


  /**
   * Returns the final point defining the clothoïd
   * @return Final point
   */
  virtual CATICDSPoint2D* GetFinalPoint() const = 0;

  /**
   * Returns the final line defining the clothoïd
   * @return Final tangent line
   */
  virtual CATICDSLine2D* GetFinalLine() const = 0;

  /**
   * Returns final line tangent side with respect to line direction
   * @return Tangent side
   */
  virtual int GetFinalOrient() const = 0;

  /**
   * Returns the circle defining the clothoïd
   * @return Final tangent circle
   */
  virtual CATICDSCircle2D* GetFinalCircle() const = 0;

  /**
   * Returns the side defining the clothoïd
   * @return Side
   */
  virtual int GetSide() const = 0;


  /**
  * Specify the scale of the clothoid
  *
  */
  virtual void SetScale(CATCDSScale iScale) = 0;

 /**
 * Set the initial point.
 * @param iInitialPoint
 *   Initial point
 */
  virtual void SetInitialPoint(CATICDSPoint2D* iInitialPoint) = 0;

  /**
   * Set the initial tangent line with orientation.
   * @param ipInitialLine
   *   Initial tangent line
   * @param iInitialOrient
   *   Initial tangent orientation (to reverse line direction if necessary)
   */
  virtual void SetInitialLine(CATICDSLine2D* iInitialLine, int iInitialOrient) = 0;

  /**
   * Set the initial tangent circle with orientation.
   * @param iInitialCircle
   *   Initial tangent circle
   * @param iInitialOrient
   *   Initial tangent orientation (clockwise or anticlockwise)
   */  
  virtual void SetInitialCircle(CATICDSCircle2D* iInitialCircle, int iInitialOrient) = 0;

  /**
 * Set the final point.
 * @param iFinalPoint
 *   Final point
 */
  virtual void SetFinalPoint(CATICDSPoint2D* iFinalPoint) = 0;

  /**
   * Set the final tangent line with orientation.
   * @param ipFinalLine
   *   Final tangent line
   * @param iFinalOrient
   *   Final tangent orientation (to reverse line direction if necessary)
   */
  virtual void SetFinalLine(CATICDSLine2D* iFinalLine, int iFinalOrientat) = 0;

  /**
   * Set the final tangent circle. Orientation is computed from initial object.
   * @param ipFinalCircle
   *   Final tangent circle
   */
  virtual void SetFinalCircle(CATICDSCircle2D* iFinalCircle) = 0;

  /**
  * Set the Initial orthogonal vector side of the clothoid.
  *@param iSide
  *   Initial orthogonal vector side
  */
  virtual void SetSide(int const& iSide) = 0;

  /**
 * Set definition parameters of the clothoids
 * @params ipA2     Clothoïd parameter if defined, null pointer otherwise
 * @params ipLength Clothoïd length if defined, null pointer otherwise
 * @params ipRadius Clothoïd final curvature radius if defined, null pointer otherwise
 * @params ipAngle  Clothoïd angle between initial and final tangent if defined, null pointer otherwise
 * @params ipShift  Clothoïd shift between initial tangent and final pseudo circle if defined, null pointer otherwise
 */
  virtual void SetInitialParameters(double const *ipA2, double const *ipLength, double const *ipRadius, double const *ipAngle, double const *ipShift) = 0;

  /**
   * Create a curve approximating the clothoïd curve
   * Caller is responsible for curve deletion
   * @param iPlane      The plane which will contain the curve
   * @param opClothoid  The clothoid approximation if run succeeded and clothoid isn't reduced to a point
   * @param oaPoint     A point if clothoid is reduced to a point
   * @return            TRUE if clothoid approximation succeeded
   */
  virtual CATCDSBoolean CreateCurve(CATPlane &iPlane, CATCurve *&opClothoid, double oaPoint[2]) const = 0;

  /**
   * Retrieves definition parameters of the clothoids
   * @params opA2     Clothoïd parameter if defined, null pointer otherwise
   * @params opLength Clothoïd length if defined, null pointer otherwise
   * @params opRadius Clothoïd final curvature radius if defined, null pointer otherwise
   * @params opAngle  Clothoïd angle between initial and final tangent if defined, null pointer otherwise
   * @params opShift  Clothoïd shift between initial tangent and final pseudo circle if defined, null pointer otherwise
   */
  virtual void GetInitialParameters(double const *&opA2, double const *&opLength, double const *&opRadius, double const *&opAngle, double const *&opShift) = 0;

  /**
 * Set the GeoFactory which is used in the evaluator
 * @params ipGeoFactory     Factory to set
 */
  virtual void SetGeoFactory(CATGeoFactory* ipGeoFactory) = 0;

  /**
 * Retrieves GeoFactory which is used in the evaluator
 * @return            pointer on the GeoFactory
 */
  virtual CATGeoFactory* GetGeoFactory() const = 0;

  /**
  Internal method. Do not use
  */
  virtual CATCSTransitionCurve2D* GetClothoid() const = 0;
};

#endif
