// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyDenoisingCloud.h
//
//===================================================================
//
// Usage notes:  
// Denoising cloud.
//
//===================================================================
// Sep   2019 : ANR      : Indus/Livraison
// Avril 2019 : CZI3/ANR : creation.
//===================================================================

#ifndef CATPolyDenoisingCloud_H
#define CATPolyDenoisingCloud_H

#ifndef _AIX_SOURCE

#include "CATPolyCanonicOperators.h"
 
#include "CATPolyDetectPrimitivesInCloud.h"
//#include "CATPolyNeighborsGraph.h"
#include "CATMapOfIntToInt.h"
#include "CATListOfInt.h"
#include "CATAssert.h"
#include "CATMathPoint.h"
//#include "CATPolyKDTree.h"
#include <vector>

//
typedef enum {
  D_WithModelBasedMethod,  // Model-based methods measure the distance from each point to a model
  D_WithStatisticalMethod,  // Compute the number of neighbors Using : GetNeighborhood(i)
  D_WithNeighSphereRadius   // Compute the number of neighbors Using: FindNeighborsInSphere
}CATDenoisingMethod;

class ExportedByCATPolyCanonicOperators CATPolyDenoisingCloud
{
public:

  CATPolyDenoisingCloud(CATSoftwareConfiguration* iConfig, CATTolerance* iTolerance, int iNbOfVertices, double* iVertices);

  ~CATPolyDenoisingCloud();

  //
  void SetCoeff(double icoeff);

  //
  HRESULT Run(CATDenoisingMethod iMethod = D_WithStatisticalMethod);

  //
  CATListOfInt& GetInliersPoints();

  //
  CATListOfInt& GetOutliersPoints();
   
   
private:

  CATPolyDenoisingCloud(const CATPolyDenoisingCloud&);
  CATPolyDenoisingCloud& operator=(const CATPolyDenoisingCloud&); 

  void DenoisingWithStatisticalMethods();
  void DenoisingPointCloudWithNeighSphere();
  int ComputeLocalAverage();
  int ComputeMaxDistance();
  void DenoisingWithModelBasedMethods();
   
  int _NbOfVertices;
  double* _Vertices;
  CATSoftwareConfiguration* _Config;
  CATTolerance* _Tolerance;

  CATPolyNeighborsGraph* _Graph;
  CATPolyKDTree* _Tree;

  CATListOfInt _InliersPoints, _OutliersPoints;
  std::vector<double> _Distances;
  std::vector<int> _NbrFixedNeigh;
  std::vector<int> _candidates;
  std::vector<double> _Average;
  std::vector<int> _NbrNeigh;
  double _Coeff;

}; 
#endif
#endif
