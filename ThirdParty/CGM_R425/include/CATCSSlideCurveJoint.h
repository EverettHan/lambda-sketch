// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSlideCurve.h
// Header definition of CATCSSlideCurve
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2005  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSSlideCurveJoint_H
#define CATCSSlideCurveJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSCurve;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * The joint make two curves tangent. Thus three degrees of freedom between
 * the curves are available. The tangency point is commanded by two length
 * variables which correspond to the parameters of curves.
 * @see #CATCSCurve, #CATCSVariable
 */
class ExportedBySolverInterface CATCSSlideCurveJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSSlideCurveJoint(CATCSVariable *ipLength1 = 0, CATCSVariable *ipLength2 = 0);

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSSlideCurveJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, CATCSVariable *ipLength1 = 0, CATCSVariable *ipLength2 = 0);)

  virtual ~CATCSSlideCurveJoint();

  /**
   * Retrieves type of the joint.
   * @return
   *   Type of the joint.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the joint is matched to a specific type. The joint can be
   * casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
   * Sets the curves to be tangent.
   * @param ipCurve1
   *   The first curve.
   * @param ipCurve2
   *   The second curve.
   * @see #GetGeometries
   */
  virtual int SetGeometries(CATCSCurve *ipCurve1, CATCSCurve *ipCurve2);

  /**
   * Retrieves the tangent curves.
   * @param opCurve1
   *   The first curve.
   * @param opCurve2
   *   The second curve.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSCurve *&opCurve1, CATCSCurve *&opCurve2) const;

  /**
   * Retrieves the length variables.
   * @param opLength1
   *   The variable corresponding to the first curve.
   * @param opLength2
   *   The variable corresponding to the second curve.
   */
  virtual void GetLengths(CATCSVariable *&opLength1, CATCSVariable *&opLength2) const;

  /**
   * Sets the length variables.
   * @param ipLength1
   *   The variable corresponding to the first curve.
   * @param ipLength2
   *   The variable corresponding to the second curve.
   */
  virtual void SetLengths(CATCSVariable *ipLength1, CATCSVariable *ipLength2);

private:
  void Init(CATCSVariable *ipLength1, CATCSVariable *ipLength2);

  CATCSVariable *_pLength1, *_pLength2;
};

//-----------------------------------------------------------------------

#endif
