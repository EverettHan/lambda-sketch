// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarGraphManifolds.h
//
//===================================================================
// March 2012  Creation NDO
//===================================================================
#ifndef CATPolyBodyBarGraphManifolds_H
#define CATPolyBodyBarGraphManifolds_H

#include "CATPolyDecimateOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATListOfInt.h"

class CATPolyBodyBarGraph;
class CATPolyBarGraphNodeBarLoopIterator;

class CATPolyBitSet;
class CATSetOfInt;
class CATMapOfIntToInt;
class CATMapOfIntToPtr;
class CATStackOfInt;


/**
* Builds manifolds sets for a CATPolyBodyBarGraph.
*/
class ExportedByCATPolyDecimateOperators CATPolyBodyBarGraphManifolds
{

public:

  /**
  * Observer interface to the manifold operator.
  */
  class Observer
  {
  public:

    virtual void BeforeAddManifoldFace(const unsigned int f, const unsigned int manifold) = 0;
    virtual void AfterAddManifoldFace(const CATSetOfInt& nodes, const CATSetOfInt& bars) = 0;

    virtual void AfterAddTriangle(const unsigned int n[3]) = 0;

    virtual void BeforeAddManifoldEdge(const unsigned int e, const unsigned int manifold) = 0;

    // Case of a closed loop of nodes.
    virtual void AfterAddManifoldEdge(const CATListOfInt& nodes, const CATListOfInt& bars,
      const unsigned int fL, const unsigned int fR) = 0;

    // Case of an open sequence of nodes.
    virtual void AfterAddManifoldEdge(const CATListOfInt& nodes,
      const unsigned int bS, const unsigned int bE,
      const unsigned int fL, const unsigned int fR) = 0;

  };

public:

  /**
  * Constructs an operator to build all the manifold cells (edges and faces) in a body graph.
  * @param iDoMakeBoundaryEdges
  *   An option to turn on the construction of edges around all boundaries.
  *   By default, edges are not constructed for boundaries unless they are already defined as edges.
  * @param iObserver
  *   An observer notified when new manifold sets are created and populated.
  */
  CATPolyBodyBarGraphManifolds(const CATBoolean iDoTrimByInnerLoops, const CATBoolean iDoMakeBoundaryEdges /*= FALSE*/, Observer* iObserver = 0);

  ~CATPolyBodyBarGraphManifolds();

public:

  /**
  * Service to fetch an adjacent triangle.
  */
  static HRESULT FetchTriangle(const CATPolyBodyBarGraph& iBodyGraph,
    CATPolyBarGraphNodeBarLoopIterator& itL,
    CATStackOfInt& iStackNodes, CATStackOfInt& iStackBars,
    CATPolyBitSet& iBarFlags);

public:

  /**
  * Builds manifold cells (edges and faces) in the bar graph.
  * @param ioBodyGraph
  *   The input CATPolyBodyBarGraph.
  */
  HRESULT BuildManifoldCells(CATPolyBodyBarGraph& ioBodyGraph) const;

public:

  /**
  * Constructs manifolds set of triangles and updates the CATPolyBodyBarGraph.
  * @param ioBodyGraph
  *   The bar graph to update.
  * @return
  * <ul>
  *   <li> <code> S_OK </code> on successful construction of the manifold sets and update of the bar graph.
  *   <li> <code> E_FAIL </code> on failure.
  * </ul>
  */
  HRESULT GroupFacetsIntoFaceSets(CATPolyBodyBarGraph& ioBodyGraph) const;

  /**
  * Constructs manifolds set of bars and updates the CATPolyBodyBarGraph.
  * @param ioBodyGraph
  *   The bar graph to update.
  * @return
  * <ul>
  *   <li> <code> S_OK </code> on successful construction of the manifold sets and update of the bar graph.
  *   <li> <code> E_FAIL </code> on failure.
  * </ul>
  */
  HRESULT GroupBarsIntoEdgeSets(CATPolyBodyBarGraph& ioBodyGraph) const;

private:

  CATBoolean _DoTrimByInnerLoops;   // Flag to turn on or off the trimming of faces by inner loops of edges.
  CATBoolean _DoMakeBoundaryEdges;  // Flag to turn on or off the construction of boundary edges.
  CATBoolean _DoExerciseCautionForMarkedVertices;  // Flag to ensure no node marked as a vertex node occurs in the interior of an edge.
  Observer* _Observer;

private:

  HRESULT BuildManifoldFace(CATPolyBodyBarGraph& iBodyGraph,
    unsigned int n, unsigned int b,
    const unsigned int f,
    const unsigned int manifold,
    CATSetOfInt& nodes, CATSetOfInt& bars,
    CATPolyBitSet& barFlags) const;

  HRESULT GatherBars(const CATPolyBodyBarGraph& iBodyGraph,
    unsigned int n, unsigned int b,
    const unsigned int e,
    CATListOfInt& nodes, CATListOfInt& bars,
    CATPolyBitSet& barFlags) const;

  HRESULT IterateThroughFacetSets(CATPolyBodyBarGraph& ioBodyGraph,
    CATMapOfIntToInt& iMapManifoldToFace,
    CATPolyBitSet& iBarFlags) const;

  HRESULT IterateThroughBarSets(CATPolyBodyBarGraph& ioBodyGraph,
    CATMapOfIntToInt& iMapManifoldToEdge,
    CATPolyBitSet& iBarFlags) const;

  HRESULT CopySurfaceLayers(CATPolyBodyBarGraph& ioBodyGraph,
    const unsigned int f,
    const unsigned int manifold,
    const CATSetOfInt& nodes, const CATSetOfInt& bars) const;

};

#endif
