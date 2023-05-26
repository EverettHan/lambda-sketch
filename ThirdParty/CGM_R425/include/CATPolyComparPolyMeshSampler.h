#ifndef CATPolyComparPolyMeshSampler_h_
#define CATPolyComparPolyMeshSampler_h_

//=======================================================================
// Copyright Dassault Systemes Provence 2016, All Rights Reserved 
//=======================================================================
//
// CATPolyComparPolyMeshSampler.h
//
//=======================================================================
//
// Usage notes: Sampling a mesh according to a given tolerance
//
//=======================================================================
// 21.03.2016 : NUA : Creation
//=======================================================================

#include "CATPolyComparAbstractMesherPriv.h"

#include <set>


class CATPolyComparPolyMeshSampler : public CATPolyComparAbstractMesherPriv
{
public:
  
  //virtual ~CATPolyComparPolyMeshSampler() {}
  //
  CATPolyComparPolyMeshSampler(double iTol, CATIPolyMesh * iMesh, const std::vector<int> & iTriangleIndices, const std::pair<double,double> & iSamplingZone);
  CATPolyComparPolyMeshSampler(double iTol, CATIPolyMesh * iMesh, const std::pair<double,double> & iSamplingZone);

  // parameters

  virtual std::vector<CATMathPoint> Sample() const;

  virtual CATPolyComparDistanceMapPoints<double> * SampleForDistanceMapDouble() const;
  virtual CATPolyComparDistanceMapPoints<float> * SampleForDistanceMapFloat() const;

protected:

  template<typename T>
  void SampleForDistanceMap(CATPolyComparDistanceMapPoints<T> * oResult) const;

  void Init();
  
  // methods
  void SampleAllVertices(std::vector<CATMathPoint> & ioRes) const;
  void SampleAllEdges(std::vector<CATMathPoint> & ioRes) const;
  void SampleAllTriangles(std::vector<CATMathPoint> & ioRes) const;
  
  void SampleTriangleInterior(std::vector<CATMathPoint> & ioRes, const int IndT) const;
  void SampleEdgeInterior(std::vector<CATMathPoint> & ioRes, int IndV1, int IndV2) const;


  const CATIPolyMesh * m_Mesh;
  std::vector<int> m_TriangleIndices;
  //
  std::set<int> m_VerticesToBeSampled;
  typedef int VertexInd;
  std::set<std::pair<VertexInd,VertexInd> > m_EdgesToBeSampled;
};

#endif // CATPolyComparPolyMeshSampler_h_
