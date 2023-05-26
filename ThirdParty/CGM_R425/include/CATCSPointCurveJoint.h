// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSPointCurveJoint.h
// Header definition of CATCSPointCurveJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2005  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSPointCurveJoint_H
#define CATCSPointCurveJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSPoint;
class CATCSCurve;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * The joint make a point and a curve coincident. Thus four degrees of freedom
 * between the objects are available. The point of coincidence is commanded by
 * a length variable which corresponds to the curve parameter.
 * @see #CATCSPoint, #CATCSCurve, #CATCSVariable
 */
class ExportedBySolverInterface CATCSPointCurveJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSPointCurveJoint(CATCSVariable *ipLength = 0);

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSPointCurveJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, CATCSVariable *ipLength = 0);)

  virtual ~CATCSPointCurveJoint();

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
   * Sets the objects to be coincident.
   * @param ipPoint
   *   The point.
   * @param ipCurve
   *   The curve.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if it is successful,
   *     <li><tt>1</tt> - otherwise.
   *   </ul>
   * @see #GetGeometries
   */
  virtual int SetGeometries(CATCSPoint *ipPoint, CATCSCurve *ipCurve);

  /**
   * Retrieves the coincident objects.
   * @param opPoint
   *   The point.
   * @param opCurve
   *   The curve.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSPoint *&opPoint, CATCSCurve *&opCurve);

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
  void Init(CATCSVariable *ipLength);

  CATCSVariable *_pLength;
};

//-----------------------------------------------------------------------

#endif
