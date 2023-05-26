// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSPointCurveJoint2D.h
// Header definition of CATCSPointCurveJoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSPointCurveJoint2D_H
#define CATCSPointCurveJoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint2D.h"

class CATCSPoint2D;
class CATCSCurve2D;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * The joint make a 2D point and a 2D curve coincident. Thus two degrees of freedom
 * between the objects are available. The point of coincidence is commanded by
 * a length variable which corresponds to the curve parameter.
 * @see #CATCSPoint2D, #CATCSCurve2D, #CATCSVariable
 */
class ExportedBySolverInterface CATCSPointCurveJoint2D : public CATCSSimpleJoint2D
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSPointCurveJoint2D(CATCSVariable *ipLength = 0);

  virtual ~CATCSPointCurveJoint2D();

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
  virtual void SetGeometries(CATCSPoint2D *ipPoint, CATCSCurve2D *ipCurve);

  /**
   * Retrieves the axes to be connected.
   * @param opAxis1
   *   The first axis.
   * @param opAxis2
   *   The second axis.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSPoint2D *&opPoint, CATCSCurve2D *&opCurve);

  /**
   * Retrieves the length variable.
   * @return
   *   The variable.
   */
  virtual CATCSVariable *GetLength();

  /**
   * Sets the length variable.
   * @param ipLength
   *   The length variable.
   */
  virtual void SetLength(CATCSVariable *ipLength);

private:
  CATCSVariable *_pLength;
};

//-----------------------------------------------------------------------

#endif
