// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonVertex2DPositionLayerImpl.h
// Header definition of CATPolyPolygonVertex2DPositionLayerImpl
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonVertex2DPositionLayerImpl_H
#define CATPolyPolygonVertex2DPositionLayerImpl_H

#include "PolygonalLayers.h"
#include "CATPolyPolygonVertex2DPositionLayer.h"
#include "CATErrorDef.h"

class CATPolyPolygon2D;
class CATPolyVertex2D;


class ExportedByPolygonalLayers CATPolyPolygonVertex2DPositionLayerImpl : 
  public CATPolyPolygonVertex2DPositionLayer
{

public :

  CATPolyPolygonVertex2DPositionLayerImpl (const CATPolyPolygon2D& polygon);
  ~CATPolyPolygonVertex2DPositionLayerImpl () {}

public:

  HRESULT Set (CATPolyVertex2D* vertex, const double x, const double y);
  HRESULT Get (const CATPolyVertex2D* vertex, double& x, double& y) const;

private:

  const CATPolyPolygon2D& _Polygon;

};

#endif
