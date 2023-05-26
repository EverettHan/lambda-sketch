#ifndef CATPolyRidgeValleyGraph_h__
#define CATPolyRidgeValleyGraph_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRidgeValleyGraph.h
//
//===================================================================
//
// Usage notes: a graph formed by ridges and valleys polylines. Produced by CATPolyRidgeValleyGraphOperator
//
//===================================================================
// 22/05/2017 : NUA : add r/v extension
// 15/05/2017 : NUA : Creation
//===================================================================


// watershed ope
#include "ExportedByCATPolyWatershedOperators.h"

// export + error
#include "CATErrorDef.h"

// STL
#include <array>
#include <list>
#include <map>
#include <vector>
#include <memory>
#include <array>

#include "CATPolyDropPathOnTerrainOperator.h"
#include "CATMathPoint.h"

// represent the graph composed by ridge and valleys, potentially with additionnal elements produced by extending "basic" ridges and valleys
// the graph is given by the mesh vertices on the ridge and valley, and also the points on the extensions. All these points are stored in the CATPolyRVVertex_t structure
// This latter structure stored the incidence relation into a vector of adjacent elem arc (CATPolyRVArcElem_t). This latter structure consists mainly in a pair of vertices
// and represent a segment along a valley, a ridge or an extension, an a tag to indicating whether the corresponding segment is on a ridge or a valley
// a vertex that is shared by 1 or more than 2 arc is a node of the graph (CATPolyRVNode_t)
// a node stored a list of CATPolyRVArc_t's and CATPolyRVExtendedArc_t's allowing to distinguish arcs that lie on the mesh edges, an arc produced ny extension
// a CATPolyRVArc_t structure represent a sequence of adjacent CATPolyRVArcElem_t's from a string node to an ending node.
// a CATPolyRVExtendedArc_t also indicates if the extension has be produced to a downward or upward flow.
// 

struct ExportedByCATPolyWatershedOperators CATPolyRidgeValleyGraph
{
public:

  struct CATPolyRVNode_t;
  typedef std::shared_ptr<CATPolyRVNode_t> CATPolyRVNodePtr_t;

  struct CATPolyRVArcElem_t;
  typedef std::shared_ptr<CATPolyRVArcElem_t> CATPolyRVArcElemPtr_t;
  typedef std::weak_ptr<CATPolyRVArcElem_t> CATPolyRVArcElemWeakPtr_t;

  // a CATPolyRVVertex_t is a mesh vertex or a point produced by extending the original ridge and valley polylines
  struct CATPolyRVVertex_t
  {
    enum KindOfVertex_t
    {
      K_OriginalVertex,
      K_ExtendedVertex
    };

    // integer representing the mesh vertex index. Only meaningfull if m_Kind = K_OriginalVertex
    int m_MeshIndex;

    // 3d position of the vertex. Always valid, regardless the value of m_MeshIndex
    CATMathPoint m_Pos;

    // is the vertex come from mesh vertex or has it been built by extension (in the latter case, it may correspond to a vertex of the original mesh)
    KindOfVertex_t m_Kind;

    // internal use. only valid if the current vertex is a node (but every node is also a vertex)
    CATPolyRVNode_t * m_ParentNode;

    CATPolyRVVertex_t(KindOfVertex_t K, const CATMathPoint & iPos) : m_Kind(K), m_Pos(iPos), m_MeshIndex(-1) {}
    CATPolyRVVertex_t(KindOfVertex_t K, int iNum) : m_Kind(K), m_MeshIndex(iNum) {}

    // vector of incident elem arcs
    std::vector<CATPolyRVArcElemWeakPtr_t> m_ElemArcs;
  };
  typedef std::shared_ptr<CATPolyRVVertex_t> CATPolyRVVertexPtr_t;
  typedef std::weak_ptr<CATPolyRVVertex_t> CATPolyRVVertexWeakPtr_t;

  enum KindOfArcElem_t
  {
    K_RidgeElem,
    K_ValleyElem,
    K_ExtendedValleyUpward,
    K_ExtendedValleyDownward,
    K_ExtendedRidgeUpward,
    K_ExtendedRidgeDownward,
    K_Unknown
  };

  struct CATPolyRVArc_t;
  typedef std::shared_ptr<CATPolyRVArc_t> CATPolyRVArcPtr_t;
  typedef std::weak_ptr<CATPolyRVArc_t> CATPolyRVArcWeakPtr_t;

  // an elem arc is a pair of vertices that represents a ridge or a valley segment
  struct CATPolyRVArcElem_t
  {
    // arc extremities
    std::array<CATPolyRVVertexWeakPtr_t, 2> m_VertexExtremities;

    // indicates if the arc lie on a ridge or a valley
    std::map<KindOfArcElem_t, size_t> m_KindCounter;

    // to be removed soon!
    CATPolyRidgeValleyGraph::KindOfArcElem_t m_Kind;

    // every elem arc belongs to a unique arc joining 2 graph nodes
    // m_ParentArc allows to retrieve this arc
    std::weak_ptr<CATPolyRVArc_t> m_ParentArc;

    CATPolyRVArcElem_t() {}
    CATPolyRVArcElem_t(const std::array<CATPolyRVVertexWeakPtr_t, 2> & iA, KindOfArcElem_t K) : m_VertexExtremities(iA)
    {
      m_KindCounter.insert(std::make_pair(K, 1));
	  m_Kind = K;
    }
    CATPolyRVArcElem_t(std::array<CATPolyRVVertexWeakPtr_t, 2> && iA, KindOfArcElem_t K) : m_VertexExtremities(std::move(iA))
    {
      m_KindCounter.insert(std::make_pair(K, 1));
	  m_Kind = K;
    }
    bool operator == (const CATPolyRVArcElem_t & iOther) const
    {
      const std::array<CATPolyRVVertexPtr_t, 2> T1 = { m_VertexExtremities[0].lock(), m_VertexExtremities[1].lock() }, T2 = { iOther.m_VertexExtremities[0].lock(), iOther.m_VertexExtremities[1].lock() };
      return T1 == T2;
    }
    bool operator != (const CATPolyRVArcElem_t & iOther) const { return *this != iOther; }
    bool operator < (const CATPolyRVArcElem_t & iOther) const
    {
      const std::array<CATPolyRVVertexPtr_t, 2> T1 = { m_VertexExtremities[0].lock(), m_VertexExtremities[1].lock() }, T2 = { iOther.m_VertexExtremities[0].lock(), iOther.m_VertexExtremities[1].lock() };
      return T1 < T2;
    }
  };


  // an arc is a sequence of elem arc, and joins a starting node to an ending node
  struct CATPolyRVArc_t
  {
    std::list<CATPolyRVArcElemPtr_t > m_Elems;
    CATPolyRVNodePtr_t m_Start, m_End;
    CATPolyRVArc_t() : m_Start(nullptr), m_End(nullptr) {}

    std::map<KindOfArcElem_t, size_t> m_KindCounter;
  };

  // extension arc
  // same as CATPolyRVArc_t, but also indicates if the extension has been produced by creating a path upward or downward from a node 
  struct CATPolyRVExtendedArc_t
  {
    CATPolyDropPathOnTerrainOperator::KindOfFlow m_KindOfFlow;
    KindOfArcElem_t m_KindOfExtendedArc;
    std::list<CATPolyRVArcElemPtr_t> m_Arcs;
  };
  typedef std::shared_ptr<CATPolyRVExtendedArc_t> CATPolyRVExtendedArcPtr_t;
  typedef std::weak_ptr<CATPolyRVExtendedArc_t> CATPolyRVExtendedArcWeakPtr_t;

  // CATPolyRVNode_t represents a node of the graph
  // a node is vertex whose valence is not equal to 2
  // a node store a list of adjacent arcs, and adjacent extended arcs
  // finally a node include a pointer to the corresponding vertex
  struct CATPolyRVNode_t : public std::enable_shared_from_this<CATPolyRVNode_t>
  {
    CATPolyRVNode_t(CATPolyRVVertexPtr_t iV) { m_Vertex = iV; m_Vertex->m_ParentNode = this; }

    std::vector<CATPolyRVArcWeakPtr_t> m_Arcs;
    std::vector<CATPolyRVExtendedArcWeakPtr_t> m_ExtendedArcs;

    CATPolyRVVertexPtr_t m_Vertex;

  private:
    CATPolyRVNode_t();
  };


  // a graph is collection of nodes, arcs and extended arcs
  std::vector<CATPolyRVNodePtr_t> m_AllNodes;
  std::vector<CATPolyRVArcPtr_t> m_AllArcs;
  std::vector<CATPolyRVExtendedArcPtr_t> m_AllExtendedArcs;

  // because of rounding error in slope/ridge/valley computation, some arcs may result in closed loop (store in a special container to avoid future issues ...)
  std::vector<CATPolyRVArcPtr_t> m_AllLoops;

  // pour conserver tous les vertices sans risque d'ils ne soient tues
  std::vector<CATPolyRVVertexPtr_t> m_AllVertices;

};


#endif // CATPolyRidgeValleyGraph_h__
