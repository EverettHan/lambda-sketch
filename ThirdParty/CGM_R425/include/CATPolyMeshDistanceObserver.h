// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
// <date> Creation: <trigram>
//===================================================================
#ifndef CATPolyMeshDistanceObserver_H
#define CATPolyMeshDistanceObserver_H

#include "CATPolyMeshDistance.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
class CATTolerance;
class CATPolyMeshDistanceLayer;
class CATIPolyMesh;

/**
 * Observer class to CATPolyMeshDistance
 */
class ExportedByPolyhedralDistanceOperators CATPolyMeshDistanceObserver
{

public:

  virtual ~CATPolyMeshDistanceObserver ();

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToTolerance(const CATTolerance & iTol) = 0;
  virtual void ReactToRefineLimit(double & _RefineLimit)= 0;
  virtual void ReactToInitialize(CATIPolyMesh & mesh1, CATIPolyMesh & mesh2 )= 0;
  virtual void ReactToGetResult(CATPolyMeshDistanceLayer & distanceLayer)= 0;

public:
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
