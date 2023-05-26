// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFixSmallAngleTrianglesOperObserver.h
//
//===================================================================
// Nov 2014  Creation: D1A
//===================================================================
#ifndef CATPolyFixSmallAngleTrianglesOperObserver_H
#define CATPolyFixSmallAngleTrianglesOperObserver_H

#include "CATPolyFixSmallAngleTrianglesOper.h"
#include "CATErrorDef.h"
#include "CATIPolyMesh.h"
#include "CATTolerance.h"
#include "CATListOfInt.h"
#include "CATCGMModif.h"
#include "CATIPolyFactory.h"

#include "CATListPV.h"
#include "CATLib.h"
#include "CATString.h"
#include "CATIPolyMesh.h"
#include "CATErrorDef.h"


/**
 * Observer class to CATPolyFixSmallAngleTrianglesOper.
 */
class ExportedByCATPolyRegularizeOperators CATPolyFixSmallAngleTrianglesOperObserver
{

public:
  
  virtual ~CATPolyFixSmallAngleTrianglesOperObserver ();

public:
   
  //At 4 check points:
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void AfterConstructor(double angTol) = 0;
  virtual void BeforeDestructor() = 0;

  //For input parameters of CATPolyFixSmallAngleTrianglesOper
  virtual void ReactToAngleTolerance(double iAngleTol) = 0;
  virtual void ReactToPolyMesh (CATIPolyMesh &iMesh) = 0;

  //For public APIs of CATPolyFixSmallAngleTrianglesOper
  virtual void ReactToRun() = 0;
  virtual void ReactToRunOnSelectedTriangles1(const CATListOfInt & triangles) = 0;
  virtual void ReactToRunOnSelectedTriangles2(const CATListOfInt & triangles, CATListOfInt & decimatedTriangles) = 0;
  virtual void ReactToGetSmallAngleTriangles(CATListOfInt & triangles) = 0;
  
};

#endif
