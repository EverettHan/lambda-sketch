// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBarSurfaceLayer.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2009 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonBarSurfaceLayer_H
#define CATPolyPolygonBarSurfaceLayer_H

#include "PolygonalLayers.h"
#include "CATPolyPolygonBarAttributeLayer.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyPolygon2D;
class CATPolyBar2D;
class CATIPolySurface;


/**
* Layer associating a CATIPolySurface to bars of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalLayers CATPolyPolygonBarSurfaceLayer : public CATPolyPolygonBarAttributeLayer
{

public :

  CATPolyPolygonBarSurfaceLayer (const CATPolyPolygon2D& iPolygon) : CATPolyPolygonBarAttributeLayer (iPolygon) {}
  ~CATPolyPolygonBarSurfaceLayer () {}

public:

  // Associate a CATIPolySurface to a bar.
  HRESULT Set (const CATPolyBar2D* bar, const CATIPolySurface* attribute)
    {return CATPolyPolygonBarAttributeLayer::Set (bar, (CATPolyPolygonBarAttributeLayer::Attribute) attribute);}

  // Return the CATIPolySurface associated to a bar.
  HRESULT Get (const CATPolyBar2D* bar, const CATIPolySurface*& attribute) const
    {return CATPolyPolygonBarAttributeLayer::Get (bar, (CATPolyPolygonBarAttributeLayer::Attribute&) attribute);}

};

#endif
