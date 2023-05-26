//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyConvexHullObserver.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2014-11-14   E3H: New
//===================================================================
#ifndef CATPolyConvexHullObserver_H
#define CATPolyConvexHullObserver_H

#include "CATPolyConvexHull.h"
#include "CATErrorDef.h"


/**
 * Observer class to CATPolyConvexHullOper.
 */
class ExportedByCATPolyConvexHull CATPolyConvexHullObserver
{

public:

  virtual ~CATPolyConvexHullObserver ();

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToInputBody (CATPolyBody& iPolyBody, const CATMathTransformation*& iTransfo) = 0;
  virtual void ReactToOutputMesh (CATIPolyMesh &oMesh) = 0;

public:
  virtual void AfterConstructor () = 0;
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
