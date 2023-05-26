// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
// <date> Creation: <trigram>
//===================================================================
#ifndef CATPolyBodyAreaObserver_H
#define CATPolyBodyAreaObserver_H

#include "CATPolyBodyArea.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
class CATTolerance;
class CATMath3x3Matrix;
class CATPolyBody;
class CATMathPoint;

/**
 * Observer class to CATPolyBodyArea
 */
class ExportedByPolyBodyMeasures CATPolyBodyAreaObserver
{

public:

  virtual ~CATPolyBodyAreaObserver ();

public:

  ///////////////////////
  //ReactTo methods
  virtual void ReactToInputPolyBody(const CATPolyBody & iPolyBody) = 0;
  virtual void ReactToInputPolyMesh(const CATIPolyMesh & iPolyMesh) = 0;
  virtual void ReactToOutputs(HRESULT & hr, CATMathPoint & Gravity, double & Area) = 0;

public:
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
