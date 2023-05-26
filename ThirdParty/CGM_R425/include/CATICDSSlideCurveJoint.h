#ifndef CATICDSSlideCurveJoint_H
#define CATICDSSlideCurveJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSCurve;
class CATICDSVariable;

/**
 * The joint make two curves tangent. Thus three degrees of freedom between
 * the curves are available. The tangency point is commanded by two length
 * variables which correspond to the parameters of curves.
 * @see #CATICDSCurve, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSSlideCurveJoint : public CATICDSJoint
{
public:
  /**
   * Retrieves the tangent curves.
   * @param opCurve1
   *   The first curve.
   * @param opCurve2
   *   The second curve.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATICDSCurve *&opCurve1, CATICDSCurve *&opCurve2) const = 0;

  /**
   * Retrieves the length variables.
   * @param opLength1
   *   The variable corresponding to the first curve.
   * @param opLength2
   *   The variable corresponding to the second curve.
   */
  virtual void GetLengths(CATICDSVariable *&opLength1, CATICDSVariable *&opLength2) const = 0;

  /**
   * Creates an instance of the CATICDSSlideCurveJoint joint.
   * Joint create two length variables at creation and manage their life cycle.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipCurve1
   *   The first curve.
   * @param ipCurve2
   *   The second curve.
   *
   * @SKIP
   */
  static CATICDSSlideCurveJoint* Create(CATICDSFactory *ipFactory, CATICDSCurve *ipCurve1, CATICDSCurve *ipCurve2);

  /**
   * Creates an instance of the CATICDSSlideCurveJoint joint.
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
  static CATICDSSlideCurveJoint* Create(CATICDSFactory *ipFactory, CATICDSCurve *ipCurve1, CATICDSCurve *ipCurve2, CATICDSVariable *ipLength1, CATICDSVariable *ipLength2);

  virtual ~CATICDSSlideCurveJoint() {}
};

#endif
