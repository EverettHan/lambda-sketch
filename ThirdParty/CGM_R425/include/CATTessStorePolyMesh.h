//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// One-shot tessellation visitor dedicated to CATIPolyMesh filling
//
//=============================================================================
// 2008-10-24  RAQ : Déplacement en ProtectedInterfaces
// 2006-11-02  BPG: New.
//=============================================================================
#ifndef CATTessStorePolyMesh_H
#define CATTessStorePolyMesh_H

#include "TessPolygon.h"

#include "CATTessStore.h"
#include "CATTessDiagnostic.h"

//
class CATIPolyMesh;
class CATTessPolyMeshTriangleAttributeLayer;
class CATTessPolyMeshVertexAttributeLayer;

class CATSoftwareConfiguration;

//
class ExportedByTessPolygon CATTessStorePolyMesh:
  public CATTessStore
{
public:
  CATTessStorePolyMesh(CATLONG32 iVertexInfo,
                       
                       CATIPolyMesh &ioMesh,
                       CATTessPolyMeshTriangleAttributeLayer *oTriangleAttr,
                       CATTessPolyMeshVertexAttributeLayer *oVertexAttr);
  virtual ~CATTessStorePolyMesh();

public:
  void StorePoint(CATTessPointPolyIter *  iPointPolyIter,
		  CATLONG32             & oNuPoint);

  void StoreFace(CATFace*            iFace,
		 CATBoolean          iNew,
		 CATBoolean          iVolume,
		 CATSide             iSide,
		 CATBoolean          iPlane,
		 CATLONG32           iNbStrips,
		 CATTessStripeIter * iStrips,
		 CATLONG32           iNbFans,
		 CATTessFanIter    * iFans,
		 CATLONG32           iNbPolygons,
		 CATTessPolyIter   * iPolygons,
		 CATLONG32           iNbTriangles,
		 CATTessTrianIter  * iTriangles);

  void StoreEdge(CATEdge          * iEdge,
		 CATBoolean         iNew,
		 CATTessEdgeIter  * iEdgeIter);

  void StoreVertex(CATVertex* iVertex,
                   CATBoolean iNew,
                   CATTessVertexIter* iVertexIter);

  // Internal use only
  void SetCell(CATCell*);
#ifdef CATIAR420
  void WhichCellsDoYouNeed(ListPOfCATCell & oListOfCATCells);
#else
  virtual CATBoolean DoYouNeed(CATCell * iCell);
#endif

protected:
  const CATLONG32 _VertexInfo;

  CATCell* _Cell;

  CATIPolyMesh &_ioMesh;
  CATTessPolyMeshTriangleAttributeLayer *_oTriangleAttr;
  CATTessPolyMeshVertexAttributeLayer *_oVertexAttr;
};

#endif // !CATTessStorePolyMesh_H
