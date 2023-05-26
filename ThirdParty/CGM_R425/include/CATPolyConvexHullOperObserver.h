// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyConvexHullOperObserver.h
//
//===================================================================
// 
//===================================================================
#ifndef CATPolyConvexHullOperObserver_H
#define CATPolyConvexHullOperObserver_H

#include "CATPolyConvexHullExport.h"
#include "CATPolyConvexHullOper.h"
#include "CATIPolyMesh.h"
#include "CATErrorDef.h"


/**
 * Observer class to CATPolyConvexHullOperOper.
 */
class ExportedByCATPolyConvexHull CATPolyConvexHullOperObserver
{

public:

  virtual ~CATPolyConvexHullOperObserver ();

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToInputPoints (const CATLISTV(CATMathPoint)& iPoints) = 0;
  virtual void ReactToOutputs (HRESULT & hr, CATLISTV(CATMathPoint)& iPointsOnConvexHull, double& iMaxError) = 0;

public:
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  
};

#endif
