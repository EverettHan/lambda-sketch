// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyContour.h (CATPolyContour, + winding numbers)
//
//===================================================================
//
// Usage notes: Create a contour from a set of polygons (defined by
// a set of oriented bars), with known neighbors.
//
//===================================================================
//
// May 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyContour_H
#define CATPolyContour_H

#include "CATPolySegmentCommon.h"
#include "CATPolyBuckets_T.h"
#include "CATListOfInt.h"

class ExportedByCATPolySegmentCommon CATPolyContour
{
public:
  /** 
  *  Constrcutor and Destructor
  */
  CATPolyContour();
  virtual ~CATPolyContour();

public:
  /**
  *  Main methods to create the contour
  */

  /**
  *  Add an oriented  bar, defined by iIdxPolyV1 (index of V1 in the mesh), 
  *  and iIdxPolyV2 (index of V2 in the mesh). Give the neighbor facet of the added
  *  oriented bar.
  *  Example : If you want to add a triangle with its three neighbors, you 
  *  should add the three bars, and the three neighbor facets. Each bar with its 
  *  neighbor facet
  */
  HRESULT AddBar(int iIdxPolyV1, int iIdxPolyV2, int iIdxPolyNeighbor);
  
  
  
  /**
  *  Find loops, in the set of already added bars
  */
  HRESULT UpdateLoops();

  /**
  *  Get resulting Loops
  *  Get each loop vertices
  *  Get each loop neighbors
  *  LoopVertices = V1 V2 V3 ... Vp
  *  LoopNeighbors = N1 N2 N3 ... Np
  *  N1 is the neighbor facet of the bar V1V2, N2 is neighbor facet of the bar V2V3, ...
  */
  HRESULT GetLoops(CATListOfInt& oLoops);
  HRESULT GetLoopVertices(int iIdxLoop, CATListOfInt& oContourVertices);
  HRESULT GetLoopNeighbors(int iIdxLoop, CATListOfInt& oContourNeighbors);  


  /**
  *  Get the neighbor V2 of a Vertex V1: the next vertex in the loop
  *  Get the neighbor facet of the bar V1V2
  */
  HRESULT GetNextNeighbors(int iIdxPolyV, int& oNextPolyV, int& oPolyNeighbor);
  
  
  /**
  *  Get All contour vertices
  *  Get All contour neighbors 
  */
  HRESULT GetAllContourVertices(CATListOfInt& oContourVertices);
  HRESULT GetAllContourNeighbors(CATListOfInt& oContourNeighbors);  


  /**
  /*   Clear, Initialize
  */
  HRESULT Clear();

  
private:
  HRESULT GetVertex(int iIdxPolyV, int& oIdxVertex);
  HRESULT GetBar(int iIdxV1, int iIdxV2, int& oIdxBar);
  HRESULT GetNextBar(int iIdxBar, int& oIdxNextBar);
  
  HRESULT InsertVertex(int& oIdxVertex);
  HRESULT InsertBar(int& oIdxBar);
  HRESULT InsertLoop(int& oIdxLoop);


  //GEOMETRY
  //VERTEX
private:
  class Vertex
  {
  public:
    Vertex();

  public:
    int _PolyIndex;
    CATListOfInt _Bars;
    
  };
  class Specialize_CATPolyBuckets_T(VertexBuckets, Vertex);

  //BAR
private:
  class Bar
  {
  public:
    Bar();

  public:
    int _V1, _V2;
    int _PolyNeighbor;
    int _WindingNumber;
    int _Loop;
  };
  class Specialize_CATPolyBuckets_T(BarBuckets, Bar);

  //LOOP
private:
  class Loop
  {
  public:
    Loop();
  public:
    CATListOfInt _Vertices;
    CATListOfInt _Bars;
    CATListOfInt _PolyVertices;
    CATListOfInt _PolyNeighbors;
    int _Valid;
    };
  class Specialize_CATPolyBuckets_T(LoopBuckets, Loop);

private:
  VertexBuckets _Vertices;
  int _NbVertices;

private:
  BarBuckets _Bars;
  int _NbBars;

private:
  LoopBuckets _Loops;
  int _NbLoops;
};


//inline implementation

#endif
