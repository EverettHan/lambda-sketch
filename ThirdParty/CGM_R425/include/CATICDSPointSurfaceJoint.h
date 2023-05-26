#ifndef CATICDSPointSurfaceJoint_H
#define CATICDSPointSurfaceJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSPoint;
class CATICDSSkin;
class CATICDSVariable;

/**
 * The joint make a point and a surface coincident. Thus five degrees of
 * freedom between the objects are available. The point of coincidence is
 * provided by a help parameter.
 * @see #CATICDSPoint, #CATICDSSkin, #CATICDSSkinParam
 */
class ExportedByCDSInterface CATICDSPointSurfaceJoint : public CATICDSJoint
{
public:
  /**
   * Creates an instance of the CATICDSPointSurfaceJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipPoint
   *   The point.
   * @param ipSkin
   *   The Skin.
   */
  static CATICDSPointSurfaceJoint* Create(CATICDSFactory *ipFactory, CATICDSPoint *ipPoint, CATICDSSkin *ipSkin);

  virtual ~CATICDSPointSurfaceJoint() {}
};

#endif
