// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVoxelConvexHullObserver.h
//
//===================================================================
// Nov 2014  Creation: E3H
//===================================================================
#ifndef CATPolyVoxelConvexHullObserver_H
#define CATPolyVoxelConvexHullObserver_H

#include "CATPolyVoxelConvexHull.h"
#include "CATIPolyMesh.h"
#include "CATErrorDef.h"
#include "CATVCHullIterator.h"

/**
 * Observer class to CATPolyVoxelConvexHullOper.
 */
class ExportedByCATPolyConvexHull CATPolyVoxelConvexHullObserver
{

public:

  virtual ~CATPolyVoxelConvexHullObserver ();

public:

  virtual void ReactToInitVoxelGrid (double XMin, double XMax, double YMin, double YMax, double ZMin, double ZMax, int NVx, int NVy, int NVz) = 0;
  virtual void ReactToAddTriangle (float iTriangleVerticesCoordinates[9]) = 0;   
  virtual void ReactToHullOuterComputationMode (CATBoolean iOuterHullComputationMode) = 0;
  virtual void ReactToInternalOption (CATBoolean iInternalOption) = 0;  
  virtual void ReactToConfig (CATSoftwareConfiguration * ipSoftConfig) = 0; 
  virtual void ReactToOutputMesh (CATIPolyMesh &oMesh) = 0;
  virtual void ReactToOperResult (HRESULT iOperResult) = 0;
  virtual void ReactToFeedPoints (const CATMathPoint& iPoint) = 0;
  virtual void ReactToOutputHulls (CATVCHullIterator * &pIt) = 0;  
  virtual void ReactToHullSelector () = 0;

public:
  virtual void AfterConstructor () = 0;
  virtual void BeforeRun () = 0;
  virtual void AfterRun () = 0;
  virtual void BeforeDestructor () = 0;
  
};

#endif
