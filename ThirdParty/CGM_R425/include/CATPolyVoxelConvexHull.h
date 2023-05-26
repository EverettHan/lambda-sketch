//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// CATPolyVoxelConvexHull
//
//=============================================================================
// 2006-07-10   ALA: New
//=============================================================================
#ifndef CATPolyVoxelConvexHull_H
#define CATPolyVoxelConvexHull_H

#include "CATPolyConvexHullExport.h"
#include "CATSoftwareConfiguration.h"
#include "CATBoolean.h"

class CATIPolyMesh;

class CATVCHOutputPolygon;
class CATVCHullSelector;
class CATPolyVoxelConvexHullObserver;
class CATMathTransformation;
class CATPolyBody;
class CATProgressCallback;

//
class ExportedByCATPolyConvexHull CATPolyVoxelConvexHull
{
public:
  //
  virtual ~CATPolyVoxelConvexHull();

public:
  //
  // usage :
  // must be called in following order:
  // 1) InitVoxelGrid(...)
  // 2) Repeat AddTriangle(...) as long as necessary
  // 3) Run(...)
  //
  virtual void InitVoxelGrid(double XMin, double XMax,double YMin, double YMax,double ZMin, double ZMax,
                             int iNVx = 64, int iNVy = 64, int iNVz = 64) = 0;
  //  triangle insertion (no limitation related to memory size , only disk size related limitation)
  // return 0 if the triangle does not fit in the bounding box
  // else return 1
  // X1,Y1,Z1,X2,Y2,Z2,X3,Y3,Z3
  //
  virtual int AddTriangle(float iTriangleVerticesCoordinates [9]) = 0;
  //
  virtual int AddPolygon(CATIPolyMesh &iMesh) = 0;
  //
  virtual int AddPolyBody(CATPolyBody* iPolyBody, CATMathTransformation& iTransfo) = 0;

  // Sets Computation Mode 
  // If Activated --> Operator returns all outerhulls in output mesh
  virtual void SetOuterHullsComputationMode(CATBoolean iActivate) = 0;
  //
  virtual CATBoolean GetOuterHullsComputationMode(void) = 0;

public:
  // run the algo...and ouput on oOuputPolygon...
  // return 0 if failed or empty
  // else return the number of connected components
  virtual int Run(CATVCHOutputPolygon *oOuputPolygon) = 0;
  //
  //
  // ioMesh is a pointer toward a valid instance of an empty CATCldPolygon
  virtual int Run(CATIPolyMesh &ioMesh) = 0;
  //
  // Return a Container containing all Mesh/HullEnvelopes
  virtual CATVCHullSelector* Run(void) = 0;

    /**
   *  @brief force the number of thread to use 
   *  if <=0 the number of thread will be selected from CATSettings
   *  @param iNb number of thread to use.
   * */
  virtual void SetNbThread(int iNb=-1) =0;

public:
  static CATPolyVoxelConvexHull *New(char * iTempFilesPrefix, CATSoftwareConfiguration * iConfig);
  // If iTempFilesPrefix = 0 => Run In-Memory mode else file-Based mode
  static CATPolyVoxelConvexHull *New(char * iTempFilesPrefix = 0);

  static CATVCHullSelector* NewHullSelector( CATPolyVoxelConvexHullObserver* ipObserver );

  // For internal use
public:
  inline void SetObserver (CATPolyVoxelConvexHullObserver* iObserver);
  inline CATPolyVoxelConvexHullObserver* GetObserver () const;

  void SetProgressCallback(CATProgressCallback * iProgress);

protected:
  CATPolyVoxelConvexHull();

protected:
  CATPolyVoxelConvexHullObserver* _Observer;
  CATProgressCallback * m_progress;
};

inline void CATPolyVoxelConvexHull::SetObserver (CATPolyVoxelConvexHullObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyVoxelConvexHullObserver* CATPolyVoxelConvexHull::GetObserver () const
{
  return _Observer;
}

#endif // !CATPolyVoxelConvexHull_H
