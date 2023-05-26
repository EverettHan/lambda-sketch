// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonVertex3DPositionLayerObserver.h
//
//===================================================================
// November 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonVertex3DPositionLayerObserver_H
#define CATPolyPolygonVertex3DPositionLayerObserver_H

#include "PolygonalLayers.h"
#include "CATPolyPolygonObserver2D.h"
#include "CATErrorDef.h"

class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyVertex2D;
class CATPolyBar2D;


class ExportedByPolygonalLayers CATPolyPolygonVertex3DPositionLayerObserver : public CATPolyPolygonObserver2D
{

public :

  CATPolyPolygonVertex3DPositionLayerObserver (CATPolyPolygonVertex3DPositionLayer& iPositionLayer,
                                               const CATPolyPolygon2D& polygon);

  ~CATPolyPolygonVertex3DPositionLayerObserver () {}

public:

  // Call made after a vertex is added.
  virtual HRESULT ReactToAddVertex (const CATPolyVertex2D* vertex);

  // Call made before a vertex is removed.
  virtual HRESULT PrepareToRemoveVertex (const CATPolyVertex2D* vertex);

  // Call made after an update to the position of a vertex.
  virtual HRESULT ReactToSetVertexPosition (const CATPolyVertex2D* vertex);

public:

  // Call made after a bar is split.
  virtual HRESULT ReactToSplitBar (const CATPolyBar2D* iSplitBar, const CATPolyVertex2D* iVertex, 
                                   const CATPolyBar2D* iNewBar); 

  // Call made before two vertices are merged.
  virtual HRESULT PrepareToMergeVertices (const CATPolyVertex2D* iMergeVertex, const CATPolyVertex2D* iDuplicateVertex);

private:

  CATPolyPolygonVertex3DPositionLayer& _PositionLayer;
  const CATPolyPolygon2D& _Polygon;

};

#endif
