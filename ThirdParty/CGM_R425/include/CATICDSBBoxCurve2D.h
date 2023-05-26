#ifndef CATICDSBBoxCurve2D_H
#define CATICDSBBoxCurve2D_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"
#include "CATICDSCurve2D.h"

class CATICDSFactory;
class CATICDSBBoxCurve2DAdapter;

#include "CATICDSGeomConstraint.h"
/**
 * @SKIP
 *
 */
class CATICDSDependence : public CATICDSGeomConstraint
{
};

/**
 * @SKIP
 *
 * Black-box 2D dependent curve. It uses an input adapter object 
 * to make the binding with application implemented methods.
 */
class ExportedBySolverInterface CATICDSBBoxCurve2D : public CATICDSCurve2D
{
public:
 
  /**
   * Retreive pointer to adapter object.
   */
  virtual CATICDSBBoxCurve2DAdapter* GetAdapter() const = 0;

  /**
   * Declare a new dependency relation.
   * @param ipGeometry
   *     Geometry on which the curve will depend.
   */
  virtual CATICDSDependence* AddDependence(CATICDSGeometryLeaf* ipGeometry) = 0;

  /**
   * Creates an instance of the CATICDSBBoxCurve2D geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAdapter
   *   Pointer to the adapter to use.
   */
  static CATICDSBBoxCurve2D* Create(CATICDSFactory *ipFactory,
                                    CATICDSBBoxCurve2DAdapter* ipAdapter);

  virtual ~CATICDSBBoxCurve2D() {}
};

#endif
