#ifndef CATPolyMeshCurvatureComputer_H
#define CATPolyMeshCurvatureComputer_H

//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshCurvatureComputer.h
// Header definition of CATPolyMeshCurvatureComputer
//
//===================================================================
//
// Usage notes: Computes the 2 principal vectorial curvatures at a given vertex of a mesh
//
// Provides also the gaussian curvature, as product of the 2 principal curvatures
//
// All the returned curvatures are signed according to the mesh orientation:
// By default : positive for convex shapes, negative for concave shapes.
// The caller has the possibility to change this convention, piloting the sign of the curvature:
// setting the convex normal direction as reference for negative curvature values.
// The gaussian curvature, product of the 2 principal curvatures, is not impacted by this option.
//
//===================================================================
//
// 2021-09-21   DPS : Creation
//===================================================================

// Math
#include "CATSysErrorDef.h"

// export
#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATIPolyMesh;
class CATPolyMeshPointDef;
class CATTolerance;
class CATMathVector;
class CATSoftwareConfiguration;

#ifndef NULL
#define NULL 0
#endif


class ExportedByCATPolyMiscellaneous CATPolyMeshCurvatureComputer
{
public:

  // ------------------- Creation of the operator --------------------
  // May return NULL if at least one mandatory layer is missing
  //
  static CATPolyMeshCurvatureComputer * New(const CATIPolyMesh & iMesh, const CATTolerance & iTol, CATSoftwareConfiguration * iConfig=NULL);

  // virtual destructor
  virtual ~CATPolyMeshCurvatureComputer();


  // --------- Settings ---------

  // The default convention for curvatures sign consists in considering convex curvatures as positive, concave curvatures as negative
  // This option allows the caller to change / pilot its own convention
  // To keep the original default convention, iConvexIsNegative has to be set to FALSE.
  // If the caller wants to retrieve the vector from the input vertex to the center of the local circle,
  // simply dividing the normal vector by the computed signed curvature, iConvexIsNegative has to be set to TRUE
  // Note that the computed gaussian curvature is not impacted by this option.
  virtual void SetConvexCurvatureSignAsNegative(CATBoolean iConvexIsNegative) = 0;


  // --------- Computation of the operator at a given mesh vertex/point ----------
  //
  virtual HRESULT Run(int iMeshVertexIndex) = 0;

  virtual HRESULT Run(const CATPolyMeshPointDef & iMeshPointDef) = 0;



  // --------- Get the different computed curvatures ---------
  //
  // All the returned curvatures are signed according to the mesh orientation:
  // positive for convex shapes, negative for concave shapes.
  //

  // Returns the 2 principal signed curvatures (min and max)
  // The optional vectors are the directions which are tangent to the local circular arcs
  // These 2 vectors are othorgonal to the local normal, but not necessarily orthogonal to each other
  virtual HRESULT GetPrincipalCurvatures(double & oMinCurvature, double & oMaxCurvature, CATMathVector * ioMinTangentVector=NULL, CATMathVector * ioMaxTangentVector=NULL) = 0;

  // Returns the principal signed curvature (min or max) with the highest absolute value
  // The optional vector is the direction tangent to the local circular arc, othorgonal to the local normal
  virtual HRESULT GetHighCurvature(double & oHighCurvature, CATMathVector * ioHighTangentVector=NULL) = 0;

  // Returns the principal signed curvature (min or max) with the lowest absolute value
  // The optional vector is the direction tangent to the local circular arc, othorgonal to the local normal
  virtual HRESULT GetLowCurvature(double & oLowCurvature, CATMathVector * ioLowTangentVector=NULL) = 0;

  // Returns the signed mean curvature
  virtual HRESULT GetMeanCurvature(double & oMeanCurvature) = 0;

  // Returns the signed product of the 2 principal curvatures
  // This product is called "Gaussian curvature"
  virtual HRESULT GetGaussianCurvature(double & oGaussianCurvature) = 0;

  // Returns the signed curvature observed locally in a specific direction.
  // This direction will be projected in the tangent plane around the current mesh vertex/point
  // Returns S_OK if a local curvature can be computed from a projected solution of the input direction on the mesh
  // Returns S_FALSE if the projection has no solution, and if the returned curvature is the closest one
  // Returns E_FAIL if no local curvature can be computed (failure of global computation, iSpecDirVector degenerated or colinear with the local normal ...)
  virtual HRESULT GetDirectionalCurvature(const CATMathVector & iSpecDirVector, double & oLocalCurvature, CATMathVector * ioLocalTangentVector=NULL) = 0;

};

#endif // CATPolyMeshCurvatureComputer_H
