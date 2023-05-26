// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
// <date> Creation: <trigram>
//===================================================================
#ifndef CATPolyBVHMinimalDistanceObserver_H
#define CATPolyBVHMinimalDistanceObserver_H

#include "PolyBodyMeasureBetween.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATPolyBVHMeasureBetween.h"

/**
 * Observer class to CATPolyBVHMinimalDistance
 */
class ExportedByPolyBodyMeasureBetween CATPolyBVHMinimalDistanceObserver 
{

public:

  virtual ~CATPolyBVHMinimalDistanceObserver ();

public:

  ///////////////////////
  //ReactTo methods

  virtual void ReactTo_AllInputs(
                    const CATTolerance & iTol,
                    CATBoolean iInfiniteGeometry1,
                    CATBoolean iInfiniteGeometry2,
                    CATBVHTree * iTree1,
                    CATBVHTree * iTree2,
                    const CATMathTransformation * iPosition1,
                    const CATMathTransformation * iPosition2) = 0;

  virtual void ReactTo_Result(
                    CATBoolean iRunSucceeded, 
                    double iMinimalDistance, 
                    const CATMathPoint& iP1, 
                    CATMathPoint& iP2, 
                    CATPolyBVHMeasureBetween::DistanceType iType) = 0;

public:

  virtual void AfterConstructor () = 0;
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
};

#endif
