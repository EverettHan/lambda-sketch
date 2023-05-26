// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSPointSurfaceJoint.h
// Header definition of CATCSPointSurfaceJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2005  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSPointSurfaceJoint_H
#define CATCSPointSurfaceJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"

class CATCSPoint;
class CATCSSkin;
class CATCSSkinParam;

//-----------------------------------------------------------------------

/**
 * The joint make a point and a surface coincident. Thus five degrees of
 * freedom between the objects are available. The point of coincidence is
 * provided by a help parameter.
 * @see #CATCSPoint, #CATCSSkin, #CATCSSkinParam
 */
class ExportedBySolverInterface CATCSPointSurfaceJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSPointSurfaceJoint();

  virtual ~CATCSPointSurfaceJoint();

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
   * @param ipSkin
   *   The surface.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if it is successful,
   *     <li><tt>1</tt> - otherwise.
   *   </ul>
   * @see #GetGeometries
   */
  virtual int SetGeometries(CATCSPoint *ipPoint, CATCSSkin *ipSkin);

  /**
   * Retrieves the coincident objects.
   * @param opPoint
   *   The point.
   * @param opSkin
   *   The surface.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSPoint *&opPoint, CATCSSkin *&opSkin);

  /**
   * Sets the help parameter.
   * @param ipPointOnSkin
   *   The parameter.
   * @see #GetHelpParameter
   */
  virtual void SetHelpParameter(CATCSSkinParam *ipPointOnSkin);

  /**
   * Retrieves the help parameter.
   * @param opPointOnSkin
   *   The parameter.
   * @see #SetHelpParameter
   */
  virtual void GetHelpParameter(CATCSSkinParam *opPointOnSkin);
private:
  CATCSSkinParam *_pPointOnSkin;
};

//-----------------------------------------------------------------------

#endif
