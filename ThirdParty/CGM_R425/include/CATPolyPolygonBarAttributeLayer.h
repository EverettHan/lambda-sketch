// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBarAttributeLayer.h
//
//===================================================================
// July 2009 Creation: ndo
//===================================================================
#pragma once

#include "PolygonalLayers.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATMapOfPtrToPtr.h"

class CATPolyPolygon2D;
class CATPolyBar2D;


/**
* Layer associating an attribute to bars of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalLayers CATPolyPolygonBarAttributeLayer
{

public:

  // Generic type of an attribute is a void*.  It's up to the user to cast it to the correct type!
  typedef void* Attribute;

public :

  CATPolyPolygonBarAttributeLayer (const CATPolyPolygon2D& iPolygon);
  virtual ~CATPolyPolygonBarAttributeLayer () {}

public:

  // Associate a CATIPolySurface to a bar.
  inline HRESULT Set (const CATPolyBar2D* bar, Attribute iAttribute);

  // Return the CATIPolySurface associated to a bar.
  inline HRESULT Get (const CATPolyBar2D* bar, Attribute& oAttribute) const;

private:

  CATMapOfPtrToPtr _MapBarToAttribute;

private:

  // Forbidden.
  CATPolyPolygonBarAttributeLayer (const CATPolyPolygonBarAttributeLayer& iOther) ;
  CATPolyPolygonBarAttributeLayer& operator= (const CATPolyPolygonBarAttributeLayer& iOther) ;

};


inline HRESULT CATPolyPolygonBarAttributeLayer::Set (const CATPolyBar2D* bar, Attribute iAttribute)
{
  HRESULT hr = _MapBarToAttribute.Insert ((void*) bar, iAttribute);
  return FAILED (hr) ? _MapBarToAttribute.Update ((void*) bar, iAttribute) : hr;
}


inline HRESULT CATPolyPolygonBarAttributeLayer::Get (const CATPolyBar2D* bar, Attribute& oAttribute) const
{
  return _MapBarToAttribute.Locate ((void*) bar, oAttribute) ? S_OK : E_FAIL;
}
