#ifndef CATICDSPointCurveJoint_H
#define CATICDSPointCurveJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSPoint;
class CATICDSCurve;
class CATICDSVariable;

/**
 * The joint make a point and a curve coincident. Thus four degrees of freedom
 * between the objects are available. The point of coincidence is commanded by
 * a length variable which corresponds to the curve parameter.
 * @see #CATICDSPoint, #CATICDSCurve, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSPointCurveJoint : public CATICDSJoint
{
public:
  /**
   * Creates an instance of the CATICDSPointCurveJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipPoint
   *   The point.
   * @param ipCurve
   *   The curve.
   * @param ipLength
   *   The variable.
   */
  static CATICDSPointCurveJoint* Create(CATICDSFactory *ipFactory, CATICDSPoint *ipPoint, CATICDSCurve *ipCurve, CATICDSVariable *ipLength);

  virtual ~CATICDSPointCurveJoint() {}
};

#endif
