// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonBar3DBoundingGPLayer.h
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
class CAT3DBoundingGP;


/**
* Layer associating a CAT3DBoundingGP to bars of a CATPolyPolygon2D object.
*/
class CATPolyPolygonBar3DBoundingGPLayer : public CATPolyPolygonBarAttributeLayer
{

public :

  CATPolyPolygonBar3DBoundingGPLayer (const CATPolyPolygon2D& iPolygon) : CATPolyPolygonBarAttributeLayer (iPolygon) {}
  ~CATPolyPolygonBar3DBoundingGPLayer () {}

public:

  // Associate a CAT3DBoundingGP to a bar.
  HRESULT Set (const CATPolyBar2D* bar, CAT3DBoundingGP* attribute)
    {return CATPolyPolygonBarAttributeLayer::Set (bar, (CATPolyPolygonBarAttributeLayer::Attribute) attribute);}

  // Return the CAT3DBoundingGP associated to a bar.
  HRESULT Get (const CATPolyBar2D* bar, CAT3DBoundingGP*& attribute) const
    {return CATPolyPolygonBarAttributeLayer::Get (bar, (CATPolyPolygonBarAttributeLayer::Attribute&) attribute);}

};
