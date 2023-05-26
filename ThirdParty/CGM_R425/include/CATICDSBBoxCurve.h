#ifndef CATICDSBBoxCurve_H
#define CATICDSBBoxCurve_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"
#include "CATICDSCurve.h"

class CATICDSFactory;
class CATICDSBBoxCurveAdapter;

/*#include "CATICDSGeomConstraint.h"
class CATICDSDependence : public CATICDSGeomConstraint
{
};*/

/**
 * @SKIP
 *
 * Black-box 3D dependent curve. It uses an input adapter object 
 * to make the binding with application implemented methods.
 */
class ExportedBySolverInterface CATICDSBBoxCurve : public CATICDSCurve
{
public:
 
  /**
   * Retreive pointer to adapter object.
   */
  virtual CATICDSBBoxCurveAdapter* GetAdapter() const = 0;

  /**
   * Creates an instance of the CATICDSBBoxCurve geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAdapter
   *   Pointer to the adapter to use.
   */
  static CATICDSBBoxCurve* Create(CATICDSFactory *ipFactory,
                                  CATICDSBBoxCurveAdapter* ipAdapter);

  virtual ~CATICDSBBoxCurve() {}
};

#endif
