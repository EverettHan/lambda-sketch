// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonVertex3DPositionLayer.h
// Header definition of CATPolyPolygonVertex3DPositionLayer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonVertex3DPositionLayer_H
#define CATPolyPolygonVertex3DPositionLayer_H

#include "PolygonalLayers.h"
#include "CATErrorDef.h"

class CATPolyVertex2D;


class ExportedByPolygonalLayers CATPolyPolygonVertex3DPositionLayer
{

public :

  virtual ~CATPolyPolygonVertex3DPositionLayer () {}

public:

  virtual HRESULT Set (const CATPolyVertex2D* vertex, const double x, const double y, const double z) = 0;
  virtual HRESULT Get (const CATPolyVertex2D* vertex, double& x, double& y, double& z) const = 0;

};

#endif
