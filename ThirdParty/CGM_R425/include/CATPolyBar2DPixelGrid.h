// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBar2DPixelGrid.h
//
//===================================================================
// April 2019 Creation: ndo
//===================================================================
#ifndef CATPolyBar2DPixelGrid_H
#define CATPolyBar2DPixelGrid_H

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATArrayOfIntegerSets.h"
#include "CATPolySpatialPartition2D.h"
#include "CATPolyPolygon2D.h"

class CATPolyPolygon2D;
class CATPolyBar2D;


/**
 * Array of pixels containing an arbitrary numbers of bars from a CATPolyPolygon2D
 * for a spatial partition.
 */
class CATPolyBar2DPixelGrid
{

public:

  inline CATPolyBar2DPixelGrid (const CATPolyPolygon2D& polygon, const CATPolySpatialPartition2D& sp);

  ~CATPolyBar2DPixelGrid () {}

public:

  /**
   * Adds a bar to a pixel.
   */
  inline HRESULT AddBar (unsigned int pixel, CATPolyBar2D* B);

  /**
   * Removes a bar from a pixel.
   */
  inline HRESULT RemoveBar (unsigned int pixel, CATPolyBar2D* B);

public:

  // Iterator cycling through all the CATPolyBar2D in a given pixel.
  class Iterator
  {
  public:

    inline Iterator (const CATPolyBar2DPixelGrid& iPixelGrid, unsigned int pixel);

    inline Iterator (const Iterator& iIterator);

  public:

    inline Iterator& Begin () {_It.Begin (); return *this;}
    inline bool End () const {return _It.End () ? true : false;}
    inline Iterator& operator++ () {++_It; return *this;}

    inline CATPolyBar2D* operator * () const;

  private:

    const CATPolyPolygon2D& _Polygon;
    CATArrayOfIntegerSets::Iterator _It;

  };

private:

  const CATPolyPolygon2D& _Polygon;
  CATArrayOfIntegerSets _PixelGrid;

  friend class CATPolyOverlayPixelGrid2D;  // Reserved.

};

inline CATPolyBar2DPixelGrid::CATPolyBar2DPixelGrid (const CATPolyPolygon2D& polygon, const CATPolySpatialPartition2D& sp) :
  _Polygon (polygon),
  _PixelGrid (sp.GetNbPixels () ? sp.GetNbPixels () : 1)
{
}

inline HRESULT CATPolyBar2DPixelGrid::AddBar (unsigned int pixel, CATPolyBar2D* B)
{
  _PixelGrid.AddElement (pixel, _Polygon.GetBarIndex (B));
  return S_OK;
}

inline HRESULT CATPolyBar2DPixelGrid::RemoveBar (unsigned int pixel, CATPolyBar2D* B)
{
  _PixelGrid.RemoveElement (pixel, _Polygon.GetBarIndex (B));
  return S_OK;
}

inline CATPolyBar2DPixelGrid::Iterator::Iterator (const CATPolyBar2DPixelGrid& iPixelGrid, unsigned int pixel) :
  _Polygon (iPixelGrid._Polygon),
  _It (iPixelGrid._PixelGrid, pixel)
{
}

inline CATPolyBar2DPixelGrid::Iterator::Iterator (const Iterator& iIterator) :
  _Polygon (iIterator._Polygon),
  _It (iIterator._It)
{
}

inline CATPolyBar2D* CATPolyBar2DPixelGrid::Iterator::operator * () const
{
  return _Polygon.GetBar (*_It);
}

#endif
