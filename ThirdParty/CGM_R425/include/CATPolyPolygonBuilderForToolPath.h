// COPYRIGHT Dassault Systemes 2007, all rights reserved
//===================================================================
//
// CATPolyPolygonBuilderForToolPath
// 2021-09-14 : VKH1 : Creation
//  
//===================================================================

#ifndef CATPolyPolygonBuilderForToolPath_H
#define CATPolyPolygonBuilderForToolPath_H

#include <map>
#include "ExportedByCATPolyToolPathOper.h"
#include "CATLib.h"

class CATPolyPolygonWNBuilder2D;
#include "CATPolyParallelPlanesMeshIntersector.h" // class CATPolyParallelPlanesMeshIntersector;
class CATPolyBar2D;
class CATPolyVertex2D;

class CATPolyPolygonBuilderForToolPath : public CATPolyParallelPlanesMeshIntersector::PolygonBuilder
{
public:
  CATPolyPolygonBuilderForToolPath(CATPolyPolygonWNBuilder2D& iWNBuilder2D, 
    std::multimap<const CATPolyBar2D*, int>& iMap_Bar_IdxTris,
    std::map<const CATPolyVertex2D*, std::pair<int, int>> &ioMap_Vertex_IdxVertices)
    : _WNBuilder(iWNBuilder2D), _map_Bar_IdxTris(iMap_Bar_IdxTris), _map_Vertex_IdxVertices(ioMap_Vertex_IdxVertices)
  {
  }

  HRESULT AddVertex(const CATMathPoint& iPoint, int iVertex1, int iVertex2, CATPolyVertex2D*& oVertex);
  HRESULT AddBar(CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, int iTriangle, int iMultiplicity, CATPolyBar2D*& oBar);
  void ActivateDebugTraces();

  CATPolyPolygonWNBuilder2D GetWNBuilder();

private:
  CATPolyPolygonWNBuilder2D& _WNBuilder;
  std::multimap<const CATPolyBar2D*, int>& _map_Bar_IdxTris;
  std::map<const CATPolyVertex2D*, std::pair<int, int>>& _map_Vertex_IdxVertices;
  bool _b_DebugTraces = false;
};

#endif
