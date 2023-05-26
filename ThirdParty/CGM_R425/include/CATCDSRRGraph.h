// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCDSRRGraph.h
// Header definition of CATCDSRRGraph
//
//===================================================================
//
// Usage notes:
//   This class is used inside RelativeRepresentation to represent
// a weigthed (labeled) graph and to code the Kruskal's algorithm
// to find its minimum spanning tree.
//   The graph can be disconnected, so its spanning tree can be
// a forest. Each tree in this forest is rooted by its central
// node to minimize its depth.
//
//===================================================================
//
//  Jan 2005  Creation:                   Dmitry USHAKOV
//===================================================================
#ifndef CATCDSRRGraph_H
#define CATCDSRRGraph_H

#include "CATCDSBoolArray.h"
#include "CATCDSIntArray.h"
#include "SolverUtilities.h"

class ExportedBySolverUtilities CATCDSRRGraph
{
public:
  CATCDSRRGraph(int iNbNodes, int * ipForest);
  virtual ~CATCDSRRGraph();

  struct Node {
    int _idx, _parent, _depth, _forest, _ref;
  };

  struct Edge {
    int _from, _to, _weight;
  };

  void AddEdge(int iFrom, int iTo, int iWeight);

  void FindMinimumSpanningTree();
  void FindMinimumSpanningTreeOnOneForest(); // old code, kept for perfos

 /**
  * Return nodes one by one sorted according to their appearance in a tree,
  * i.e. it guranteed that parent nodes are returned before child nodes.
  * @param iIdx an index of node (from 0 to number of nodes minus 1)
  * @param oParent parent node
  * @return the node at index iIdx
  */
  int GetNode(int iIdx, int &oParent) const;

  void SetFixedIdx(int iIdx);
  void SetRootIdx(int iIdx);
  void SetForestRoot(CATCDSIntArray& aForestIdx);

  void Dijkstra(int , int*, int, int* ,int);


private:
  CATCDSRRGraph(const CATCDSRRGraph&);
  void operator=(const CATCDSRRGraph&);

  int _nbNodes, _nbEdges, _fixedIdx;
  Node *_aNodes;
  Edge *_aEdges;
  CATCDSIntArray _aQueue, _aAdjacency, _aRootForest;
  CATCDSBoolArray _rootNodes;
  
  CATCDSInline CATCDSBoolean IsRootNode(int i) const
    {return i < _rootNodes.Size() && _rootNodes.IsSet(i);}
  
  int RootTree(int iRoot, CATCDSBoolean* oHasFixed = 0, int *oFixedNode = 0);
  void UnrootAllTrees();
  void UnrootAllTrees(int inNode, int* iTabNodes);
};

//-----------------------------------------------------------------------

#endif
