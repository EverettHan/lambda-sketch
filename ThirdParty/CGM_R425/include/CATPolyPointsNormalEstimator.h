// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPointsNormalEstimator.h
//
//===================================================================
//
// Usage notes:  
// Compute normals in a point cloud.
//
//===================================================================
//
// Juin 2013 : ANR : Creation.
// Feb  2017 : VMC1 : implementation of new methods.
//===================================================================

#ifndef CATPolyPointsNormalEstimator_H
#define CATPolyPointsNormalEstimator_H

#ifndef _AIX_SOURCE
 
#include "CATPolyCanonicOperators.h"
#include "CATBoolean.h"  
#include "CATListOfInt.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "CATErrorDef.h"
#include <vector>

class CATPolyNeighborsGraph;
class CATPolyPointsOctreeOper;

class ExportedByCATPolyCanonicOperators CATPolyPointsNormalEstimator  {

public:

  enum NormalEstimationMethod {
    ESTIMATION_PCA=0,
    ESTIMATION_RANSAC=1
  };

  enum NormalReorientationMethod {
    REORIENTATION_NONE=0,
    REORIENTATION_MINIMUM_SPANNING_TREE=1,
    REORIENTATION_BREADTH_FIRST_SEARCH=2
  };

	CATPolyPointsNormalEstimator(
    int iNumberOfPoints,
    double *iPoints); 

	~CATPolyPointsNormalEstimator();

  void SetSizeOfNeighborhood(int iVal); // Need to compute kd-tree/Graph

  // Proceed with the computation of the normals.
  // iNEM is the way to estimate the normals.
  // iNOM is the way to reorient the normals consistently.
  HRESULT Run(NormalEstimationMethod iNEM, NormalReorientationMethod iNOM);

  // Return true is the normal was successfully computed and false otherwise.
  bool NormalIsComputed(int iNum) {
    return _NormalIsComputed[iNum];
  }

  // Return true is the normal was successfully computed and false otherwise.
  // False otherwise.
  // 0 <= iNum < NumberOfPoints
  bool GetNormal(int iNum, double& oX, double& oY, double &oZ) {
    oX = _Normals[3*iNum+0];
    oY = _Normals[3*iNum+1];
    oZ = _Normals[3*iNum+2];
    return _NormalIsComputed[iNum];
  }

  // Return the array containing the normals.
  double* GetNormals() {
    return &_Normals[0];
  }

protected:

  class UnionFind;

  struct Edge {
    int vertex_a;
    int vertex_b;
    double weight;
  };

  struct WeightedPoint {

    int index;
    double weight;
    bool toggle;
  };

  void ComputeNormalsWithRANSAC();

	void ComputeNormalsWithPCA(CATPolyNeighborsGraph& iGraph);

	void ReorientNormalsConsistentlyWithMST(CATPolyNeighborsGraph& iGraph);
  
  void ReorientNormalsConsistentlyWithBFS(CATPolyNeighborsGraph& iGraph);

  void BuildNeighborhoods(int iSizeOfNeighborhood, CATPolyNeighborsGraph*& oGraph);

  int PropagateNormalsOrientations(CATPolyNeighborsGraph& forest);

  void BuildOctree(CATPolyPointsOctreeOper*& oOctree);

	int UpdatePlanarPatch(CATListOfInt &iListVertices, CATMathPoint &oAjustCenter, CATMathVector &oAjustNormal);

	void RANSACPlaneDetection(
		CATListOfInt &iListOfVertices,
		CATListOfInt &oPlanarList,
		CATMathPoint &oCenter,
		CATMathVector &oAxis,
		CATBoolean iComputeBary,
		int &oNearPtIndex);

	int _NumberOfPoints;
	double* _Vertices;
	std::vector<double> _Normals;
	std::vector<bool> _NormalIsComputed;

  int _ParamSizeOfNeighborhood;
};

#endif
#endif
