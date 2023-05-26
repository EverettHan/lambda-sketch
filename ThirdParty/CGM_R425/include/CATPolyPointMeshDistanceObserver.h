// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
// <date> Creation: <trigram>
//===================================================================
#ifndef CATPolyPointMeshDistanceObserver_H
#define CATPolyPointMeshDistanceObserver_H

#include "CATPolyPointMeshDistance.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATIPolyMesh;
class CATMathPoint;

/**
 * Observer class to CATPolyPointMeshDistance
 */
class ExportedByCATPolyMeshIntersectors CATPolyPointMeshDistanceObserver
{

public:

  virtual ~CATPolyPointMeshDistanceObserver ();

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToResolutionForLengthTest(const double iResForLengthTest) = 0;
  virtual void ReactToEpsilonForLengthTest(const double iEpsForLengthTest) = 0;
  virtual void ReactToInputPoint(const CATMathPoint & iPoint) = 0;
  virtual void ReactToInputMesh(const CATIPolyMesh & iMesh) = 0;
  virtual void ReactToResult(CATPolyPointMeshDistance::Result & result) = 0;

public:
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
