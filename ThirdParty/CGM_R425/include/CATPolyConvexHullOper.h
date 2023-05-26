//=============================================================================
// COPYRIGHT Dassault Systemes 2013
//=============================================================================
//
// CATPolyConvexHull
//
//=============================================================================
// 2013-10-18   MPX: New
//=============================================================================
#ifndef CATPolyConvexHull_H
#define CATPolyConvexHull_H

#include "CATBoolean.h"
#include "CATErrorDefs.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATPolyConvexHullExport.h"

#include "CATIAV5Level.h"

#ifdef CATIAR418
class CATPolyConvexHullOperObserver;
class CATechExt;
#endif //CATIAR418

class CATVCHConvexHull;
class CATMathPoint;

class ExportedByCATPolyConvexHull CATPolyConvexHullOper
{
public:
  static HRESULT Compute(
                     const CATLISTV(CATMathPoint)& iPoints,
                     CATLISTV(CATMathPoint)& ioPointsOnConvexHull,
                     double& oMaxError);

  static CATPolyConvexHullOperObserver* _Observer;
  static CATechExt* _PhoenixExtension;
};

#endif // !CATPolyConvexHull_H
