// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBarVizPrimitiveLayer.h
//
//===================================================================
// July 2009 Creation: ndo
//===================================================================
#pragma once

#include "CATPolyPolygonBarAttributeLayer.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyPolygon2D;
class CATPolyBar2D;
class CATVizPrimitive;


/**
* Layer associating a CATVizPrimitive to bars of a CATPolyPolygon2D object.
*/
class CATPolyPolygonBarVizPrimitiveLayer : public CATPolyPolygonBarAttributeLayer
{

public :

  CATPolyPolygonBarVizPrimitiveLayer (const CATPolyPolygon2D& iPolygon) : CATPolyPolygonBarAttributeLayer (iPolygon) {}
  ~CATPolyPolygonBarVizPrimitiveLayer () {}

public:

  // Associate a CATVizPrimitive to a bar.
  HRESULT Set (const CATPolyBar2D* bar, const CATVizPrimitive* attribute)
    {return CATPolyPolygonBarAttributeLayer::Set (bar, (CATPolyPolygonBarAttributeLayer::Attribute) attribute);}

  // Return the CATVizPrimitive associated to a bar.
  HRESULT Get (const CATPolyBar2D* bar, const CATVizPrimitive*& attribute) const
    {return CATPolyPolygonBarAttributeLayer::Get (bar, (CATPolyPolygonBarAttributeLayer::Attribute&) attribute);}

};
