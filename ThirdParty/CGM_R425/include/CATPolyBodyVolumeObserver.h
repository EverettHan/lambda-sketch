// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
// <date> Creation: <trigram>
//===================================================================
#ifndef CATPolyBodyVolumeObserver_H
#define CATPolyBodyVolumeObserver_H

#include "CATPolyBodyVolume.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
class CATTolerance;
class CATMath3x3Matrix;
class CATPolyBody;
class CATMathPoint;

/**
 * Observer class to CATPolyBodyVolume
 */
class ExportedByPolyBodyMeasures CATPolyBodyVolumeObserver
{

public:

  virtual ~CATPolyBodyVolumeObserver ();

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToComputeInertiaMatrix(CATBoolean iComputeInertiaMatrix) = 0;
  virtual void ReactToInputPolyBody(const CATPolyBody & iPolyBody) = 0;
  virtual void ReactToInputTolerance(const CATTolerance & iTol) = 0;
  virtual void ReactToPolyBodyVolume(double PolyBodyVolume) = 0;
  virtual void ReactToPolyBodyInertia(CATMathPoint & PolyBodyInertia) = 0;
  virtual void ReactToPolyBodyInertiaMatrix(CATMath3x3Matrix &Inertiamatrix) = 0;

public:
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
