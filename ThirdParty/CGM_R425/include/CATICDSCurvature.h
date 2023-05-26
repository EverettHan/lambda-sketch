#ifndef CATICDSVertexCurvature_H
#define CATICDSVertexCurvature_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"
#include "CATIAV5Level.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying Curvature of a Geometry at a given parameter on the Geometry.
 */
class ExportedByCDSInterface CATICDSCurvature : public CATICDSGeomDimConstraint
{
public:

  /**
   * Set TRUE if you don't want to get a signed curvature (FALSE by default). Only relevant for 2D curve, 3D curvature are not signed.
   * @param iValue 
   *   TRUE if you want the absolute value of the curvature
   */
  virtual void SetUseAbsoluteValue(CATCDSBoolean iValue) = 0;

  /**
   * Return TRUE if the constraint uses the absolute value of the curvature (FALSE by default). Only relevant for 2D curve, 3D curvature are not signed.
   * @return 
   *   TRUE if using the absolute value of the curvature
   */
  virtual CATCDSBoolean GetUseAbsoluteValue() const = 0;

  /**
   * Creates an instance of the CATICDSCurvature Constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipGeometry
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on.
   * @param ipGeometry
   *   Pointer to the point where the curvature must be validated (for conics).
   */   
  static CATICDSCurvature* Create(CATICDSFactory *ipFactory, CATICDSGeometryLeaf* ipGeometry
#if defined(CATIAV5R27) || defined (CATIAR419) || defined(_EMSCRIPTEN_SOURCE)
  , CATICDSGeometryLeaf *ipPoint = 0);
#else
  );
#endif

  virtual ~CATICDSCurvature() {}
};

#endif
