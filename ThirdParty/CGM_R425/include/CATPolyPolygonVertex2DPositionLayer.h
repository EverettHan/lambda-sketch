// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonVertex2DPositionLayer.h
// Header definition of CATPolyPolygonVertex2DPositionLayer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonVertex2DPositionLayer_H
#define CATPolyPolygonVertex2DPositionLayer_H

#include "PolygonalLayers.h"
#include "CATErrorDef.h"

class CATPolyVertex2D;


class ExportedByPolygonalLayers CATPolyPolygonVertex2DPositionLayer
{

public :

  virtual ~CATPolyPolygonVertex2DPositionLayer () {}

public:

  virtual HRESULT Set (CATPolyVertex2D* vertex, const double x, const double y) = 0;
  virtual HRESULT Get (const CATPolyVertex2D* vertex, double& x, double& y) const = 0;

};

#endif
