#ifndef CATICDSPointCurveJoint2D_H
#define CATICDSPointCurveJoint2D_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSPoint2D;
class CATICDSCurve2D;
class CATICDSVariable;

/**
 * The joint make a point and a curve coincident. Thus four degrees of freedom
 * between the objects are available. The point of coincidence is commanded by
 * a length variable which corresponds to the curve parameter.
 * @see #CATICDSPoint2D, #CATICDSCurve2D, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSPointCurveJoint2D : public CATICDSJoint
{
public:
  /**
   * Creates an instance of the CATICDSPointCurveJoint2D joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipPoint
   *   The point.
   * @param ipCurve
   *   The curve.
   * @param ipLength
   *   The variable.
   */
  static CATICDSPointCurveJoint2D* Create(CATICDSFactory *ipFactory, CATICDSPoint2D *ipPoint, CATICDSCurve2D *ipCurve, CATICDSVariable *ipLength);

  virtual ~CATICDSPointCurveJoint2D() {}
};

#endif
