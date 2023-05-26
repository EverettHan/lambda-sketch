#ifndef CATCDSGraphSolver_H
#define CATCDSGraphSolver_H

// COPYRIGHT DASSAULT SYSTEMES  2016

#include "CATCDSVirtual.h"
#include "CATCDSGraph.h"
#include "CATCDSOperator.h"
#include "CATCDSBoolean.h"
#include "CATCDSArray.h"
#include <algorithm>
#include "CATCDSGraphClasses.h"
#include "CATCDSStack.h"
#include "CATCDSGraphVertex.h"
class CATCDSGraphEdge;
//class CATCDSGraphVertex;

static const char * chGraphOptionsHeader = "#!OPTIONS";
static const char * chChordlessCyclesHeader = "#!CHORDLESS";
static const char * chStronglyConnectedComponentsHeader = "#!STRONGLYCONNECTEDCOMPONENTS";
static const char * chConnectedComponentsHeader = "#!CONNECTEDCOMPONENTS";
static const char * chSpanningTreeHeader = "#!SPANNINGTREE";
static const char * chThreeVerticesCyclesHeader = "#!THREEVERTICESCYCLES";

class ExportedByGraph CATCDSGraphSolver : public CATCDSOperator
{
public:
  enum Method
  {
    NotDefined,
    Chordless,
    ChordlessSelection,
    StronglyConnectedComponents,
    SpanningTree,
    ConnectedComponents,
  };

  enum Display
  {
    None,
    ThreeVerticesCycles,
  };

  CATCDSGraphSolver(CATCDSBoolean iOrientedGraph=FALSE);

  int RunOperator() CATCDSOverride;

  #ifdef CDS_DEBUG
    void WriteInput(CATCDSStream & ioStream) const CATCDSOverride;
    template<typename Type> void WriteListOfLists(CATCDSStream & ioStream, Type iListOfLists) const;
    void WriteOutput(CATCDSStream & ioStream) const CATCDSOverride;
  #endif

  void SetMethod(Method iMethod);
  Method GetMethod() const;
  void AddVertex(CATCDSGraphVertex* ipVertex);
  void AddEdge(CATCDSGraphEdge* ipEdge);

  void SetDisplay(Display iDisplay); // utile seulement pr les cdsreplays

  CATCDSArray<CATCDSGraphVertex*> GetVertices();
  CATCDSArray<CATCDSGraphEdge*> GetEdges();

  /***
  * @return _feasibleTriplets
  *
  */
  CATCDSArray<CATCDSTriplet>& GetFeasibleTriplets();

  /***
  * @return _notFeasibleTriplets
  *
  */
  CATCDSArray<CATCDSTriplet>& GetNotFeasibleTriplets();

  /***
* @return cycles of 3 vertices (can be used only if method "chordless cycles" has been used. not available for directed graph) 
*
*/
 CATCDSArray<CATCDSTriplet>const& GetCyclesOfThreeVertices() const;

  /***
  * @return _chordlessCycles (found solution)
  *
  */
  CATCDSArray<CATCDSPath> const& GetChordlessCycles() const;

  /***
  * @return _stronglyConnectedComponents (found solution)
  *
  */
  CATCDSArray<CATCDSArray<CATCDSGraphVertex*> > const& GetStronglyConnectedComponents() const;

  CATCDSArray<CATCDSArray<CATCDSGraphVertex*> > const& GetConnectedComponents() const;
  CATCDSArray<CATCDSGraphEdge*>  const& GetSpanningTree() const;
  /**
  * @param ipV1 the extremity of the (in)existant edge  
  * @param ipV2 the other extremity of the (in)existant edge 
  * @return 0 if the edge ipV1--ipV2 (or ipV1->ipV2 for directed graph) does not exist. Otherwise, return the pointer to the edge
  */
  CATCDSGraphEdge* EdgeExists(CATCDSGraphVertex const* ipV1, CATCDSGraphVertex const* ipV2);

  /**
  * Deletes some chordless cycles of _chordlessCycles. 
  * Amongst chordless cycles, eliminate those that have all their vertices yet involved in other chordless cycles.
  */
  void SelectChordlessCycles();
  
private:
  CATCDSBoolean _orientedGraph;
  Method _method;
  Display _display;
  CATCDSArray<CATCDSGraphVertex*> _vertices;
  CATCDSArray<CATCDSGraphEdge*> _edges;
  CATCDSArray<CATCDSTriplet> _feasibleTriplets;
  CATCDSArray<CATCDSTriplet> _notFeasibleTriplets; //utile lorsque le developpeur a besoin de recuperer les cycles a 3
  CATCDSArray<CATCDSPath> _chordlessCycles;
  CATCDSArray<CATCDSArray<CATCDSGraphVertex*> > _stronglyConnectedComponents;
  CATCDSArray<CATCDSArray<CATCDSGraphVertex*> > _connectedComponents;
  CATCDSArray<CATCDSGraphEdge*> _spanningTree;
  
    /**
  * find chordless cycles such that 
  * 1) they contain iPath (of lenghts>=3)
  * 2) all the vertices (except iPath[1]) in the cycle have their _index > iKey
  * @param : iPath must be chordless path.
  * @param : iKey, every vertex in the cycle must have its _index> iKey, except one vertex : in fact, iKey = iPath[1].
  */
  int FindChordlessCyclesWithMyPath(CATCDSPath& iPath, int iKey);

    /*
  * find chordless cycles that contain at least 4 vertices. Each cycle is found only once thanks to the criteria :
  * 1) cycle[1]._index (not cycle[0]._index!!) is the lower _index ;
  * 3) the last element of cycle is adjacent to cycle[0]
  * 4) the path (cycle[0], cyle[1], ...cycle[k]) is a chordless path for all k<cycle.size()
  * @param iSelection  : if true, some chordless cycles are deleted from the solution
  * @return CATCDSRunFailed if problem occured
  */
  int FindChordlessCycles(CATCDSBoolean iSelection=FALSE);

  /*
  * Find strongly connected component that contains the vertex iVertex. 
  */
  int TarjanAlgorithm(CATCDSGraphVertex* iVertex, CATCDSStack<CATCDSGraphVertex*>& ioVerticesStack, int ioDate);

  /* 
  * Find all the vertices that are in the same component than ipVertex. 
  * More precisely, put ipVertex in the component and then put its neighbor in the same component (recursively).
  * @param ipVertex : vertex to put in the component
  * @param iComponentName : name of the component 
  */
  int ExtendConnectedComponent(CATCDSGraphVertex* ipVertex, int iComponentName);

  int RunChordless(CATCDSBoolean iSelection=FALSE);
  int RunStronglyConnectedComponents();
  int RunConnectedComponents();
  int RunSpanningTree();

protected:

  CATCDSDeclareOperator;

  friend void CATCDSGraphVertex::FindTriplets(CATCDSGraphSolver* ipSolver);
};

ExportedByGraph CATCDSGraphSolver* CATCreateGraphSolver(); //necessaire pr CATCDSOperator
ExportedByGraph void CATRemove(CATCDSGraphSolver *ipSolver); //necessaire CATCDSOperator

#endif
