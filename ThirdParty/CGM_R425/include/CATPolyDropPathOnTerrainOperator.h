#ifndef CATPolyDropPathOnTerrainOperator_h__
#define CATPolyDropPathOnTerrainOperator_h__
//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolyDropPathOnTerrainOperator.h
// Header definition of class CATPolyDropPathOnTerrainOperator
//===================================================================
//
// Usage notes: Compute the water flow from a given starting point
//
//===================================================================
// HISTORIQUE :
// 09/06/2017 : NUA : Add callback
// 30/03/2017 : NUA : Creation
//===================================================================


// export + error
#include "ExportedByCATPolyWatershedOperators.h"
#include "CATErrorDef.h"

// STL
#include <vector>
#include <memory>
#include <array>
#include <limits>
#include <functional>

#undef max
#undef min

// CGM / Math
#include "CATMathPoint.h"
#include "CATTolerance.h"

class CATIPolyMesh;

// ope
class CATPolySteepestSlopeOperator;
class CATPolyCriticalMorseIndexOperator;
class CATPolyRidgeValleyOperator;

struct CATPolyWatershedSegmentationData_t;

struct CATPolyWatershedCallback;

// Compute the water flow from a given starting point
// 1 - Call the Init method
// 2 - Iterative call to Run method
class ExportedByCATPolyWatershedOperators CATPolyDropPathOnTerrainOperator
{
public:

  // position of a vertex on the terrain mesh
  enum KindOfPosition
  {
    K_OnTriangleInterior,
    K_OnEdgeInterior,
    K_OnVertex,
    K_Other
  };

  // The path consists in segments, which may be lying
  // - on an edge ( this segment follows an edge : K_FollowEdge)
  // - on a triangle ( this segments crosses a triangle : K_CrossTriangle)
  enum KindOfPath
  {
    K_FollowEdge,
    K_CrossTriangle,
    K_UndefPath
  };

  // The computed trajectory can be descending (Each drop goes down the slope), or ascending (Each drop goes up the slope)
  enum KindOfFlow
  {
    K_Ascending,
    K_Descending
  };

  struct PointPos_t { PointPos_t(KindOfPosition K) : m_KindOfPos(K) {} KindOfPosition m_KindOfPos; };
  struct PointPosInTriangle_t : public PointPos_t { PointPosInTriangle_t() : PointPos_t(K_OnTriangleInterior) {} int m_TriangleIdx; };
  struct PointPosInEdge_t : public PointPos_t
  {
    int m_TriangleIdx; std::array<int, 2> m_VertexIdxs; std::array<int, 2> m_GlobalVertexIndex; double m_Lambda;
    
    PointPosInEdge_t() : PointPos_t(K_OnEdgeInterior) , m_TriangleIdx(-1), m_Lambda(-1.) 
    {
      m_VertexIdxs[0] = m_VertexIdxs[1] = -1;
      m_GlobalVertexIndex[0] = m_GlobalVertexIndex[1] = -1;
    }
    
    PointPosInEdge_t(const PointPosInEdge_t & iOther) : PointPos_t(iOther.m_KindOfPos)
    {
      this->m_Lambda = iOther.m_Lambda;
      this->m_TriangleIdx = iOther.m_TriangleIdx;
      this->m_VertexIdxs = iOther.m_VertexIdxs;
      this->m_GlobalVertexIndex = iOther.m_GlobalVertexIndex;
    }
    PointPosInEdge_t & operator = (const PointPosInEdge_t & iOther)
    {
      this->m_Lambda = iOther.m_Lambda;
      this->m_TriangleIdx = iOther.m_TriangleIdx;
      this->m_VertexIdxs = iOther.m_VertexIdxs;
      this->m_GlobalVertexIndex = iOther.m_GlobalVertexIndex;

      return *this;
    }

    bool operator == (const PointPosInEdge_t & iOther) const
    {
      if (m_Lambda != iOther.m_Lambda) return false;
      if (m_TriangleIdx != iOther.m_TriangleIdx) return false;
      if (m_VertexIdxs != iOther.m_VertexIdxs) return false;
      return true;
    }
  };
  struct PointPosInVertex_t : public PointPos_t { PointPosInVertex_t() : PointPos_t(K_OnVertex), m_VertexIdx(0) {} PointPosInVertex_t(int V) : PointPos_t(K_OnVertex), m_VertexIdx(V) {} int m_VertexIdx; };
  typedef std::shared_ptr<PointPos_t> PointPosPtr_t;

  // Struct containing a point of the path (which is a polyline)
  // - 1 CATMathPoint reached along the path
  // - 1 location info specifying on which entity this point lies
  typedef std::pair<CATMathPoint, PointPosPtr_t> PointOnPath_t;

  // Struct containing a single path info
  // - The two extremities given by PointOnPath_t
  // - the kind of entity on which this segment lies
  struct EdgeOnPath_t
  {
    EdgeOnPath_t() 
    {
      m_Start.second = m_End.second = nullptr; m_CrossedTriangle = std::numeric_limits<int>::max();
    }
    EdgeOnPath_t(const PointOnPath_t & iS, const PointOnPath_t & iE) : m_Start(iS), m_End(iE) {}
    PointOnPath_t m_Start, m_End;
    KindOfPath m_PathKind;

    // valide uniquement si m_PathKind = CrossTriangle
    int m_CrossedTriangle ;
  };

  virtual ~CATPolyDropPathOnTerrainOperator() {}

  // - if P is on a vertex return {-1, NumV}
  // - if P lies on an edge [V1, V2], return {V1, V2}
  virtual std::array<int, 2> GetVertexIndices(const PointOnPath_t & P) const = 0;

  //// for reusing existing operators
  // reuse slope ope
  virtual void SetSteepestSlopeOperator(CATPolySteepestSlopeOperator * iOpe) = 0;
  // reuse index ope
  virtual void SetCriticalMorseIndexOperator(CATPolyCriticalMorseIndexOperator * iOpe) = 0;
  // reuse ridge valley ope
  virtual void SetRidgeValleyOperator(CATPolyRidgeValleyOperator * iOpe) = 0;

  virtual void SetProgressCallback(CATPolyWatershedCallback * iCallback) = 0;

  virtual HRESULT Init() = 0;

  
  // a computed path is a sequence EdgeOnPath_t stored in a vector
  typedef std::vector<EdgeOnPath_t> WaterFlow_t;

  // Input
  // - iStartPoint : a starting point lying on the mesh
  // - iStartTriangle : the index of the triangle containing the starting point
  // - iTrajType : The kind of trajectory (ascending or descending) 
  // Output
  // - oOutputPath : the computed path
  // Return S_OK if no error
  virtual HRESULT Run(const CATMathPoint & iStartPoint, int iStartTriangle, KindOfFlow iTrajType, WaterFlow_t & oOutputPath) const = 0;

  // Input
  // - iStartVertex : index of the starting vertex
  // - iTrajType : The kind of trajectory (ascending or descending) 
  // Output
  // - oOutputPath : the computed path
  // Return S_OK if no error
  virtual HRESULT Run(int iStartVertex, KindOfFlow iTrajType, WaterFlow_t & oOutputPath) const = 0;

  static CATPolyDropPathOnTerrainOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolObject);

  // use this method when watershed basins have already been computed
  // - iMesh must be the terrain refined by the segmentation operator (->GetRefined)
  // - iTol must be tuned according to the scale
  // - iBasins must be the segmentation produced by the segmentation ope
  // - oInternalMesh is the mesh that must be used to identify any triangle on the terrain
  static CATPolyDropPathOnTerrainOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolObject, const CATPolyWatershedSegmentationData_t & iBasins, CATIPolyMesh *& oInternalMesh);

  ////////////// DEBUG
  virtual void ChangeSlopeTestStatus(bool ) {}
};

#endif // CATPolyDropPathOnTerrainOperator_h__
