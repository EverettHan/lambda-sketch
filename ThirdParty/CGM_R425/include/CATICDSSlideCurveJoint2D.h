#ifndef CATICDSSlideCurveJoint2D_H
#define CATICDSSlideCurveJoint2D_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSCurve2D;
class CATICDSVariable;

/**
 * The joint make two curves tangent. Thus three degrees of freedom between
 * the curves are available. The tangency point is commanded by two length
 * variables which correspond to the parameters of curves.
 * @see #CATICDSCurve2D, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSSlideCurveJoint2D : public CATICDSJoint
{
public:
  /**
   * Creates an instance of the CATICDSSlideCurveJoint2D joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipCurve1
   *   The first curve.
   * @param ipCurve2
   *   The second curve.
   * @param ipLength1
   *   The variable corresponding to the first curve.
   * @param ipLength2
   *   The variable corresponding to the second curve.
   */
  static CATICDSSlideCurveJoint2D* Create(CATICDSFactory *ipFactory, CATICDSCurve2D *ipCurve1, CATICDSCurve2D *ipCurve2, CATICDSVariable *ipLength1, CATICDSVariable *ipLength2);

  virtual ~CATICDSSlideCurveJoint2D() {}
};

#endif
