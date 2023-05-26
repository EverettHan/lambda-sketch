#ifndef CATPolyMeshBilateralFiltering_h__
#define CATPolyMeshBilateralFiltering_h__
//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshBilateralFiltering.h : Apply a smoothing filter on the input and try to preserve the sharp edges 
//
//===================================================================
// December 2019  Creation NUA
//===================================================================

// export
#include "ExportedByCATPolyFeatureLineOperator.h"

// Math
#include "CATMathVector.h"

#include "CATSysErrorDef.h"

// STL
#include <map>

class CATIPolyMesh;
class CATTolerance;
class CATPolyVertexNormalAttributeOpe;
class CATIPolySurfaceVertexFacetNeighborhood;
class CATIPolySurfaceVertexIterator;
class CATPolyMeshKRingOpe;

// Bilateral Mesh Denoising

class ExportedByCATPolyFeatureLineOperator CATPolyMeshBilateralFiltering
{
public:

  CATPolyMeshBilateralFiltering(CATIPolyMesh & iMesh, const CATTolerance & iTol, double iSigma_s, double iSigma_c);

  ~CATPolyMeshBilateralFiltering();

  HRESULT Run(int NbIterations);

  // K_FittingPlane par defaut
  enum VecPolicy
  {
    K_UnitaryNormal,
    K_FittingPlane
  };

  // 1 par defaut
  void SetRingSize(int iSize)
  {
    m_RingSize = iSize;
  }

  void SetVecPolicy(VecPolicy iPolicy)
  {
    m_VecPolicy = iPolicy;
  }

private:

  HRESULT PlaneFromPoint(int NumV, const CATPolyVertexNormalAttributeOpe & iNormalOpe, CATMathVector & N) const;

  CATIPolyMesh & m_Mesh;
  const CATTolerance & m_Tol;

  CATIPolySurfaceVertexIterator * m_VIter;
  CATIPolySurfaceVertexFacetNeighborhood * m_VoisinOpe;

  double m_Sigma_s;
  double m_Sigma_c;

  std::map<int, CATMathVector> m_VecByVertices;

  int m_RingSize;
  VecPolicy m_VecPolicy;

  CATPolyMeshKRingOpe * m_KRingOpe;
};
#endif // CATPolyMeshBilateralFiltering_h__
