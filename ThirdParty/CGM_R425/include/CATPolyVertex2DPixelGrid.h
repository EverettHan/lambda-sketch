// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertex2DPixelGrid.h
//
//===================================================================
// April 2019 Creation: ndo
//===================================================================
#ifndef CATPolyVertex2DPixelGrid_H
#define CATPolyVertex2DPixelGrid_H

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATArrayOfIntegerSets.h"
#include "CATPolySpatialPartition2D.h"
#include "CATPolyPolygon2D.h"

class CATPolyPolygon2D;
class CATPolyVertex2D;


/**
 * Array of pixels containing an arbitrary numbers of vertices from a CATPolyPolygon2D
 * for a spatial partition.
 */
class CATPolyVertex2DPixelGrid
{

public:

  inline CATPolyVertex2DPixelGrid (const CATPolyPolygon2D& polygon, const CATPolySpatialPartition2D& sp);

  ~CATPolyVertex2DPixelGrid () {}

public:

  /**
   * Adds a vertex to a pixel.
   */
  inline HRESULT AddVertex (unsigned int pixel, CATPolyVertex2D* V);

  /**
   * Removes a vertex from a pixel.
   */
  inline HRESULT RemoveVertex (unsigned int pixel, CATPolyVertex2D* V);

public:

  // Iterator cycling through all the CATPolyVertex2D in a given pixel.
  class Iterator
  {
  public:

    inline Iterator (const CATPolyVertex2DPixelGrid& iPixelGrid, unsigned int pixel);

    inline Iterator (const Iterator& iIterator);

  public:

    inline Iterator& Begin () {_It.Begin (); return *this;}
    inline bool End () const {return _It.End () ? true : false;}
    inline Iterator& operator++ () {++_It; return *this;}

    inline CATPolyVertex2D* operator * () const;

  private:

    const CATPolyPolygon2D& _Polygon;
    CATArrayOfIntegerSets::Iterator _It;

  };

private:

  const CATPolyPolygon2D& _Polygon;
  CATArrayOfIntegerSets _PixelGrid;
  friend class CATPolyOverlayPixelGrid2D;  // Reserved.
};

inline CATPolyVertex2DPixelGrid::CATPolyVertex2DPixelGrid (const CATPolyPolygon2D& polygon, const CATPolySpatialPartition2D& sp) :
  _Polygon (polygon),
  _PixelGrid (sp.GetNbPixels () ? sp.GetNbPixels () : 1)
{
}

inline HRESULT CATPolyVertex2DPixelGrid::AddVertex (unsigned int pixel, CATPolyVertex2D* V)
{
  _PixelGrid.AddElement (pixel, _Polygon.GetVertexIndex (V));
  return S_OK;
}

inline HRESULT CATPolyVertex2DPixelGrid::RemoveVertex (unsigned int pixel, CATPolyVertex2D* V)
{
  _PixelGrid.RemoveElement (pixel, _Polygon.GetVertexIndex (V));
  return S_OK;
}

inline CATPolyVertex2DPixelGrid::Iterator::Iterator (const CATPolyVertex2DPixelGrid& iPixelGrid, unsigned int pixel) :
  _Polygon (iPixelGrid._Polygon),
  _It (iPixelGrid._PixelGrid, pixel)
{
}

inline CATPolyVertex2DPixelGrid::Iterator::Iterator (const Iterator& iIterator) :
  _Polygon (iIterator._Polygon),
  _It (iIterator._It)
{
}

inline CATPolyVertex2D* CATPolyVertex2DPixelGrid::Iterator::operator * () const
{
  return _Polygon.GetVertex (*_It);
}

#endif
