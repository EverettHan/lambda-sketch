#ifndef CATVertexRibbonOrder_h_
#define CATVertexRibbonOrder_h_

//-----------------------------------------------------------------------------
//
// CATVertexRibbonOrder
// ------------------
// Definition of class used for providing an edge order at a vertex
// 
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// January   2011 JQS: Creation
//-----------------------------------------------------------------------------


#include "Fillet.h"
#include "CATDynFilletVertexRibbonOrder.h"
#include "CATEdge.h"
#include "CATVertex.h"
#include "ListPOfCATFace.h"
#include "ListPOfListPOfCATEdge.h"

class CATCell;

class ExportedByFillet CATVertexRibbonOrder : public CATDynFilletVertexRibbonOrder
{

public:
  CATVertexRibbonOrder( CATVertex *iVertex, CATEdge *iLastEdge);
  CATVertexRibbonOrder( CATVertex *iVertex, const ListPOfListPOfCATEdge & ListsOfEdges );
  CATVertexRibbonOrder( CATEdge *iEdge, ListPOfCATFace *iFaceList);   
  virtual ~CATVertexRibbonOrder();

  CATVertexRibbonOrder* Clone();

  CATVertex *GetVertex();
  CATEdge   *GetLastEdge();
  ListPOfListPOfCATEdge *GetListsOfEdges();
  CATEdge   *GetEdgeForStopFaces();
  ListPOfCATFace *GetListOfStopFaces();

  void 		SetVertex( CATVertex *iVertex );
  void 		SetLastEdge( CATEdge *iLastEdge );
  void    SetListsOfEdges( const ListPOfListPOfCATEdge & ListsOfEdges );
  void    SetEdgeForStopFaces( CATEdge *iEdge );
  void    SetListOfStopFaces( ListPOfCATFace *iFaceList );

  void Dump(CATCGMOutput& os);

  void 		WriteInput( CATCGMStream &Str, CATGeoFactory *iFactory = NULL );
  static CATVertexRibbonOrder* CreateFromStream( CATCGMStream &Str, CATGeoFactory &iFactory );
  static int GetBSFStreamLevel();

  CATBoolean IsSharpCorner();
  CATBoolean ChangeOrderToFixDeadlock(  );
  
private:
  CATVertex *_VertexForOrder;
  CATEdge   *_LastEdgeForOrder;
  CATEdge   *_EdgeForStopFaces;
  ListPOfCATFace   _ListOfStopFaces;
  ListPOfListPOfCATEdge _ListsOfEdges;

};


#endif
