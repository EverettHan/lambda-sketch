// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyKDTree.h
//
//===================================================================
//
// Usage notes:  
// A kd-tree for fast neighbors search.
//
//===================================================================
//
// Feb  2017 : VMC1 : creation
//===================================================================

#ifndef CATPolyKDTree_H
#define CATPolyKDTree_H

#ifndef _AIX_SOURCE

#include "CATPolyCanonicOperators.h"

#include "CATAssert.h"
#include "CATMathPoint.h"
#include <vector>

class ExportedByCATPolyCanonicOperators CATPolyKDTree
{
public:

  // Build the kd-tree.
  // iNumPoints => the number of points.
  // iPoints => an array of size (3*iNumPoints) containing the points coordinates.
  // iMaxPointsPerLeaf => no leaf will contain more than iMaxPointsPerLeaf points
  // (unless some point is duplicated more than iMaxPointsPerLeaf times).
  void Build(int iNumPoints, const double* iPoints, int iMaxPointsPerLeaf=60);

  // Clear the kd-tree.
  void Release();

  /*
  We have implemented the following neighbors searches :
  - Find the nearest neighbor of a point (nn search).
  - Find the k nearest neighbors of a point (knn search).
  - Find the points lying inside a given sphere (radius search).
  - Among the points lying inside a given sphere, find the k closest to the center of that sphere (intersection of radius search and knn search).

  A point can be a neighbor of itself, except for nearest neighbor search !
  For instance :
  - The k-nearest-neighbors of A with k=1 will be {A}.
  - The nearest-neighbor of A will be other than {A}.
  */

  // Find the the nearest neighbor of a given point
  // with guarantee that iPoint != oNeighbor.
  // oNeighbor is set to -1 if (there was only one point in the cloud).
  void FindNearestNeighbor(int iPoint, int& oNeighbor);

  // iPoint : an array of size three containing (x, y, z) coordinates of the points whose neighborhood we are interested in.
  // iK : the maximum number of neighbors to 
  // oNeighbors : the indices of the points in the neighborhood if iPoint.
  // The size of oNeighbors may be less than iK if the cloud contains less than iK points.
  void FindKNearestNeighbors(const double* iPoint, int iK, std::vector<int>& oNeighbors);

  // iPoint will be listed in oNeighbors.
  // 0 <= iPoint < NumberOfPoints.
  // iPoint is the index of the point whose neighborhood we are interested in.
  // iK is the number of points of the neighborhood.
  // The size of oNeighbors may be less than iK if the cloud contains less than iK points.
  void FindKNearestNeighbors(int iPoint, int iK, std::vector<int>& oNeighbors)
  {
    FindKNearestNeighbors(&_Points[3*iPoint], iK, oNeighbors);
  }

  void FindKNearestNeighbors(const CATMathPoint& iPoint, int iK, std::vector<int>& oNeighbors)
  {
    double coords[3] = { iPoint.GetX(), iPoint.GetY(), iPoint.GetZ() };
    FindKNearestNeighbors(coords, iK, oNeighbors);
  }

  // Find all the points (oNeighbors) which lie inside a sphere of center (iPoint) and radius (iRadius).
  // iPoint is an array of three double, the x,y,z coordinates of the center of the sphere.
  void FindNeighborsInSphere(const double* iPoint, double iRadius, std::vector<int>& oNeighbors);

  // Find all the points (oNeighbors) which lie inside a sphere of center (iPoint) and radius (iRadius).
  // 0 <= iPoint < NumberOfPoints
  // iPoint is the index of the center of the sphere.
  // iPoint will be listed in oNeighors.
  void FindNeighborsInSphere(int iPoint, double iRadius, std::vector<int>& oNeighbors)
  {
    FindNeighborsInSphere(&_Points[3*iPoint], iRadius, oNeighbors);
  }

  void FindNeighborsInSphere(const CATMathPoint& iPoint, double iRadius, std::vector<int>& oNeighbors)
  {
    double coords[3] = { iPoint.GetX(), iPoint.GetY(), iPoint.GetZ() };
    FindNeighborsInSphere(coords, iRadius, oNeighbors);
  }

  /*
  FindKNearestNeighborsInSphere functions have not been tested yet so they are commented out.

  // Find the intersection of a radius search and a knn search.
  // 0 <= iPoint < NumberOfPoints
  // iPoint is the index of the point which is the center of the clipping sphere and whose neighbors we are looking for.
  // iRadius is the radius of the sphere.
  // iK is the number of nearest neighbors.
  // oNeighbors contains the indices of the neighbors.
  // If iRadius > 0 then iPoint will be listed in oNeighors.
  void FindKNearestNeighborsInSphere(int iPoint, double iRadius, int iK, std::vector<int>& oNeighbors)
  {
    FindKNearestNeighborsInSphere(&_Points[3*iPoint], iRadius, iK, oNeighbors);
  }

  // Find the intersection of a radius search and a knn search.
  // 0 <= iPoint < NumberOfPoints
  // iPoint is an array of three double, the x,y,z coordinates of the clipping center of the sphere and whose neighbors we are looking for.
  // iRadius is the radius of the sphere.
  // iK is the number of nearest neighbors.
  // oNeighbors contains the indices of the neighbors.
  // If iRadius > 0 then iPoint will be listed in oNeighors.
  void FindKNearestNeighborsInSphere(double* iPoint, double iRadius, int iK, std::vector<int>& oNeighbors);
  */

  CATPolyKDTree();

  ~CATPolyKDTree();

protected:

  class PriorityQueue;
  //class PriorityQueueWithHeap;

  class AABB;

  class Node
  {
  public:
    virtual ~Node();
    virtual bool IsLeaf() = 0;
  };

  class Leaf : public Node
  {
  public:
    virtual ~Leaf();
    virtual bool IsLeaf();
    int first;
    int count;
  };

  class Box : public Node
  {
  public:
    virtual ~Box();
    virtual bool IsLeaf();
    int splitting_dimension;
    double splitting_value;
    Node* children[2];
  };

  struct QueryNode
  {
    Node* node;
    double distance;
  };

  struct Pool
  {
    Box* father;
    int depth;
    int first;
    int count;
  };

  int Classify(double val, double treshold)
  {
    if(val < treshold)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  int _NumPoints;
  const double* _Points;
  std::vector<int> _Indices;
  Node* _Root;
};

#endif //_AIX_SOURCE

#endif
