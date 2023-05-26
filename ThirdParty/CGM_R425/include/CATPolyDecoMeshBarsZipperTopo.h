//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshBarsZipperTopo.h
//
//=============================================================================
// June 2009 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshBarsZipperTopo_H
#define CATPolyDecoMeshBarsZipperTopo_H

#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 
#include "CATListPV.h"
#include "CATMapOfIntToInt.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATPolyDecoMeshBars;

class ExportedByPolyBodyBuilders CATPolyDecoMeshBarsZipperTopo
{
public:
	CATPolyDecoMeshBarsZipperTopo (CATPolyDecoMeshBars* iDecoMesh) ;
	virtual ~CATPolyDecoMeshBarsZipperTopo () ;

//vertex nodes management
public:
  HRESULT GetVertexNode(const int iIdxVertex, int& oIdxVertexNode)const ;
  HRESULT CreateVertexNode(int& oIdxVertexNode);
  HRESULT AddVertexToNode(const int iIdxVertex, const int iIdxVertexNode );
  HRESULT GetNodeVertices(const int iIdxVertexNode, CATListOfInt& oVertexNode);
  HRESULT GetNodeLinks(const int iIdxVertexNode, CATListOfInt& oVertexNode);
  HRESULT EmptyVertexNode(const int iIdxVertexNode);
  HRESULT ClearVertexNodes();
  HRESULT AddNodeToLink(const int iIdxVertexNode, const int iIdxLink);

  //bar links management
public:
  HRESULT GetBarLink(const int iIdxBar, int& oIdxBarLink)const ;
  HRESULT RemoveBarLink(const int iIdxBar);
  HRESULT GetVertexLink(const int iIdxBar, int& oIdxLink)const ;
  HRESULT CreateBarLink(int& oIdxBarLink);
  HRESULT SetBarLink(const int iIdxBar, const int iIdxLink);
  HRESULT ClearBarLinks();
  
  HRESULT GetLinkNodes(const int iIdxLink, int& oVertexNode1, int& iVertexNode2);
  HRESULT SetLinkNodes(const int iIdxLink, const int iIdxNode1, const int iIdxNode2);

  HRESULT GetLinkStartEndVertex(const int iIdxLink, int& oStartVertex, int& oEndVertex);
  HRESULT SetLinkStartEndVertex(const int iIdxLink, const int iStartVertex, const int iEndVertex);
  
  HRESULT SetLinkBars(const int iIdxLink, const CATListOfInt& iBars);
  HRESULT GetLinkBars(const int iIdxLink, CATListOfInt& iBars);
  HRESULT GetLinkVertices(const int iIdxLink, CATListOfInt& oVertices);

  HRESULT GetSecondLinkNode(const int idxLink, const int iIdxNode1, int& oIdxNode2);
  HRESULT SetLinkTwin(const int iIdxLink, const int iIdxTwin);
  HRESULT GetLinkTwin(const int iIdxLink, int& oIdxTwin);


public:
  class ExportedByPolyBodyBuilders VertexNode
  {
  public:
    CATListOfInt _Vertices;
    CATListOfInt _Links;
  };

  class ExportedByPolyBodyBuilders BarLink
  {
  public:
    BarLink(){_Node1=0;_Node2=0;_Twin=0;_StartVertex=0;_EndVertex=0;}
  public:
    CATListOfInt _Bars;
    int _Node1;
    int _Node2;
    int _StartVertex;
    int _EndVertex;
    int _Twin;

  };
  
  int GetNbNodes(){return _VertexNodes.Size();}
  int GetNbLinks(){return _BarLinks.Size();}

  CATListPV& GetVertexNodes(){return _VertexNodes;}
  CATListPV& GetBarLinks(){return _BarLinks;}

private:
  CATPolyDecoMeshBars* _DecoMesh;  
  
  CATListPV _VertexNodes;
  CATListPV _BarLinks;

  CATMapOfIntToInt _VertexToVertexNode;
  CATMapOfIntToInt _BarToBarLink;

};

#endif 
