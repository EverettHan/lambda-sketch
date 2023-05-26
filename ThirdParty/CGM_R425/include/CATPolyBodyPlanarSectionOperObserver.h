// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
// Dec 2014 Creation: mpx
//===================================================================
#ifndef CATPolyBodyPlanarSectionOperObserver_H
#define CATPolyBodyPlanarSectionOperObserver_H

#include "PolyBodyBVHOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATPolyExactArithmetic.h"

class CATPolyBody;
class CATMathTransformation;
class CATMathPlane;
class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyPolygonBarSurfaceLayer;

/**
 * Observer class to CATPolyBodyPlanarSectionOper
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyPlanarSectionOperObserver 
{

public:

  virtual ~CATPolyBodyPlanarSectionOperObserver ();

public:

  ///////////////////////
  // ReactTo methods

  virtual void ReactTo_AllInputs(
                    CATPolyExactArithmetic::Mode iMode,
                    const CATPolyBody& iPolyBody,
                    const CATMathTransformation* iBodyPosition,
                    const CATBoolean iBodyIsVolume,
                    const double iHalfThickness,
                    const CATMathPlane& iPlane) = 0;

  // 
  virtual void ReactTo_Result(
                    HRESULT iRunStatus,
                    CATPolyPolygon2D* iPolygon,
                    CATPolyPolygonVertex3DPositionLayer* iPolygonVertexPositionLayer,
                    CATPolyPolygonBarSurfaceLayer* iPolygonBarSurfaceLayer) = 0;

public:

  virtual void AfterConstructor () = 0;
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
};

#endif
