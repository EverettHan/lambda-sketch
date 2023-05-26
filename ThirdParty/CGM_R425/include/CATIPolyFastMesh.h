//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATIPolyFastMesh
//
//=============================================================================
// 2009-06-30   MPX: New
//=============================================================================
#ifndef CATIPolyFastMesh_H
#define CATIPolyFastMesh_H

#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATPolyListOfRayTriangleIntersections.h"
#include "CATPolyFastMeshExport.h"

class CATIPolyMesh;
class CATMathPoint;
class CATMathDirection;

/////////////////////////////////////////////////////////////////////////////////
// CATIPolyFastMesh: This class is a wrapper around CATIPolyMesh that uses
// a spatial partition data structure to speed up mesh operations.
// 
// Note: CATIPolyMesh should not be modified during the lifetime of an object of
//       CATIPolyFastMesh created from it.
//
///////////////////////////
// Sample Usage 1:
///////////////////////////
//
//     CATBoolean
//     DoesAnyOfGivenRaysIntersectGivenMesh(int iNbRays, CATMathPoint[] iRayOrigin, CATMathDirection[] iRayDir, CATIPolyMesh& iMesh)
//     {
//       CATBoolean FoundAtLeastOneIntersection = FALSE;
//
//       CATIPolyFastMesh* FastMesh = CATIPolyFastMesh::New(iMesh);
//       if (!FastMesh)
//         // DEAL WITH FAILURE
//       else
//       {
//         int i;
//         for (i = 0; i < iNbRays; ++i)
//         {
//           CATPolyListOfRayTriangleIntersections Intersections;
//           if (!SUCCEEDED(FastMesh->IntersectRay(iRayOrigin[i], iRayDir[i], Intersections)))
//             // DEAL WITH FAILURE
//           else
//           {
//             if (Intersections.Size() > 0)
//             {
//               FoundAtLeastOneIntersection = TRUE;
//               break;
//             }
//           }
//         }
//       }
// 
//       delete FastMesh; FastMesh = NULL;
// 
//       return FoundAtLeastOneIntersection;
//     }
//
///////////////////////////
// Sample Usage 2:
///////////////////////////
//
//     CATBoolean
//     FindPointsInsideMesh(CATIPolyMesh& iMesh, CATMathPoint iPoints[], int iNbPoints, CATBoolean IsPointInsideMesh[])
//     {
//       CATIPolyFastMesh* FastMesh = CATIPolyFastMesh::New(iMesh);
//       if (!FastMesh)
//         DEAL WITH FAILURE
//       else
//       {
//         int i;
//         for (i = 0; i < iNbPoints; ++i)
//         {
//           CATIPolyFastMesh::PointMeshContainment Result;
//           if (!SUCCEEDED(FastMesh->IsContainingPoint(iPoints[i], Result)))
//             DEAL WITH FAILURE
//           else
//             IsPointInsideMesh[i] = (CATIPolyFastMesh::PointInsideMesh == Result);
//         }
//       }
// 
//       delete FastMesh; FastMesh = NULL;
// 
//       return IsMesh1InsideMesh2;
//     }

///////////////////////////


//
class ExportedByCATPolyFastMesh CATIPolyFastMesh
{
public:
  enum SpaceAcceleratorMode
  {
    // USE_ACCELERATOR: CATIPolyFastMesh will take more memory and more creation time, 
    //                  but subsequent operations will be very fast. Use this mode if you 
    //                  need to several operations on CATIPolyFastMesh 
    //                  (like calling IntersectRay several times on the same mesh)

    USE_ACCELERATOR,  

    // NO_ACCELERATOR:  CATIPolyFastMesh will take less memory and less creation time, 
    //                  but subsequent operations will not be as fast. Use this mode if you 
    //                  need to only one or a very few operations on CATIPolyFastMesh 

    NO_ACCELERATOR
  };

public:

  static CATIPolyFastMesh* New(CATIPolyMesh& iPolyMesh, const SpaceAcceleratorMode iMode = USE_ACCELERATOR, double iLenTol = -1.);

  virtual ~CATIPolyFastMesh();

public:

  ////
  // Cast the given ray on the mesh and returns all the intersections. Note that
  // 1. The list of intersections returned is sorted in the increasing order of distance from ray origin
  // 2. If the ray hits a vertex/edge of mesh, then there will be a separate entry for each of the triangles around the vertex/edge
  virtual HRESULT IntersectRay(
                      CATMathPoint& iRayOrigin, 
                      CATMathDirection& iRayDir,
                      CATPolyListOfRayTriangleIntersections& oIntersections) = 0;
  ////


  ////
  enum PointMeshContainment
  {
    PointMeshCouldNotDetermine,

    PointInsideMesh,
    PointOnMesh,
    PointOutsideMesh,
  };

  ////
  // Finds if a given point is inside this mesh. But note that it assumes that the mesh is water-tight and encloses a volume
  virtual HRESULT IsContainingPoint(
                      CATMathPoint& iPoint, 
                      CATIPolyFastMesh::PointMeshContainment& oContainmentResult) = 0;
  ////

  ////
  // Finds if a given mesh is inside this mesh. But note that:
  // 1. it assumes that there is no intersection between meshes, although they are allowed to touch each other
  // 2. it assumes that both meshes are water-tight and enclose a volume
  // 3. it may additionally find that this mesh is inside the given mesh, in which case, 
  //    oFoundThisMeshIsInsideGivenMesh will be TRUE. But if oFoundThisMeshIsInsideGivenMesh is false, 
  //    it does not mean that this mesh is not inside the given mesh
  //    For more clarity, see the table below:
  //
  //    oGivenMeshIsInsideThisMesh oFoundThisMeshIsInsideGivenMesh Meaning
  //
  //           TRUE                    FALSE                       Given mesh is inside this mesh
  //
  //           FALSE                   TRUE                        This mesh is inside given mesh
  //
  //           FALSE                   FALSE                       Given mesh is not inside this mesh, 
  //                                                               so either this mesh is inside given mesh 
  //                                                               or both meshes are outside each other
  //
  //           TRUE                    TRUE                        Meshes are coicident
  //
  virtual HRESULT IsContainingMesh(
                      CATIPolyFastMesh& iGivenMesh, 
                      CATBoolean& oGivenMeshIsInsideThisMesh,
                      CATBoolean& oFoundThisMeshIsInsideGivenMesh) = 0;
  ////


  ////
  enum Mesh1Mesh2Containment
  {
    Mesh1Mesh2CouldNotDetermine,

    Mesh1InsideMesh2,
    Mesh2InsideMesh1,
    Mesh1Mesh2OutsideEachOther,
    Mesh1Mesh2Coincide,
  };

  static CATIPolyFastMesh::Mesh1Mesh2Containment FindContainment(CATIPolyFastMesh& iMesh1, CATIPolyFastMesh& iMesh2);
  ////

protected:
  CATIPolyFastMesh();
};



#endif // !CATIPolyFastMesh_H

