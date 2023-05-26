// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSSlideCurveJoint2D.h
// Header definition of CATCSSlideCurveJoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSSlideCurveJoint2D_H
#define CATCSSlideCurveJoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint2D.h"

class CATCSCurve2D;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * The joint make two 2D curves tangent. Thus 2 degrees of freedom between
 * the curves are available. The tangency point is commanded by two length
 * variables which correspond to the parameters of curves.
 * @see #CATCSCurve2D, #CATCSVariable
 */
class ExportedBySolverInterface CATCSSlideCurveJoint2D : public CATCSSimpleJoint2D
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSSlideCurveJoint2D(CATCSVariable *ipLength1 = 0, CATCSVariable *ipLength2 = 0);

  virtual ~CATCSSlideCurveJoint2D();

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
   * Sets the axes to be connected.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @see #GetGeometries
   */
  virtual void SetGeometries(CATCSCurve2D *ipCurve1, CATCSCurve2D *ipCurve2);

  /**
   * Retrieves the axes to be connected.
   * @param opAxis1
   *   The first axis.
   * @param opAxis2
   *   The second axis.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSCurve2D *&opCurve1, CATCSCurve2D *&opCurve2);

  /**
   * Retrieves the length variables.
   * @param opLength1
   *   The variable corresponding to the first curve.
   * @param opLength2
   *   The variable corresponding to the second curve.
   */
  virtual void GetLengths(CATCSVariable *&opLength1, CATCSVariable *&opLength2);

  /**
   * Sets the length variables.
   * @param ipLength1
   *   The variable corresponding to the first curve.
   * @param ipLength2
   *   The variable corresponding to the second curve.
   */
  virtual void SetLengths(CATCSVariable *ipLength1, CATCSVariable *ipLength2);

private:
  CATCSVariable *_pLength1, *_pLength2;
};

//-----------------------------------------------------------------------

#endif
