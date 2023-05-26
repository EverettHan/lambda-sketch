// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSPrismaticJoint2D.h
// Header definition of CATCSPrismaticJoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSPrismaticJoint2D_H
#define CATCSPrismaticJoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint2D.h"

class CATCSAxis2D;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * 2D Prismatic joint is a type of joint which connects two 2D axes thus only one
 * degree of freedom between them is available. The degree is a shift along the first
 * axis of the sketch wich is commanded by a length variable. No relative rotations are
 * available.
 * @see #CATCSAxis2D, #CATCSVariable
 */
class ExportedBySolverInterface CATCSPrismaticJoint2D : public CATCSSimpleJoint2D
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSPrismaticJoint2D(CATCSVariable *ipLength = 0);

  virtual ~CATCSPrismaticJoint2D();

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
  virtual void SetGeometries(CATCSAxis2D *ipAxis1, CATCSAxis2D *ipAxis2);

  /**
   * Retrieves the axes to be connected.
   * @param opAxis1
   *   The first axis.
   * @param opAxis2
   *   The second axis.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSAxis2D *&opAxis1, CATCSAxis2D *&opAxis2);

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
