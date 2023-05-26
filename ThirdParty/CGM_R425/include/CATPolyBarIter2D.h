// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarIter2D.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// November 2006 Creation: ndo
//===================================================================
#ifndef CATPolyBarIter2D_H
#define CATPolyBarIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATBoolean.h"
#include "CATPolyPolygon2D.h"

class CATPolyPolygon2D;
class CATPolyBar2D;
class CATPolyBarBuckets2D;
class CATPolyArcBuckets2D;
template<class> class CATPolyBucket2D;

/**
Iterator.
Iterates through all the bars of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyBarIter2D
{

public :
  CATPolyBarIter2D(const CATPolyPolygon2D& iPolygon,
    bool iIncludeFullVertex = false,
    bool iIncludeSegments = true,
    bool iIncludeArcs = true);

  // Reset the iterator.
  HRESULT Reset ();

  // Cycle through the next valid bar of the CATPolyPolygon2D object.
  CATPolyBar2D* Next ();

private :
  // Keep static method for compiler optimizations (see Next implementation)
  static void Reset(bool iIncludeSegments, CATPolyBarBuckets2D const& iBars, CATPolyBucket2D<CATPolyBar2D>*& oBucket, unsigned char& oIndex);
  static void Reset(bool iIncludeArcs, CATPolyBarBuckets2D const& iBars, CATPolyBucket2D<CATPolyArc2D>*& oBucket, unsigned char& oIndex);
  static CATPolyBar2D& PrivateNext(CATPolyBucket2D<CATPolyBar2D>*& ioBucket, unsigned char& ioIndex);
  static CATPolyBar2D& PrivateNext(CATPolyBucket2D<CATPolyArc2D>*& ioBucket, unsigned char& ioIndex);
  static bool IsFullVertexBar(CATPolyBar2D const&);

  CATPolyBarBuckets2D* _Bars;
  union
  {
    CATPolyBucket2D<CATPolyBar2D>* _BarBucket;
    CATPolyBucket2D<CATPolyArc2D>* _ArcBucket;
  };
  unsigned char _Index;
  bool _IsArc;
  bool _IncludeFullVertex;
  bool _IncludeSegments;
  bool _IncludeArcs;
};

inline CATPolyBarIter2D::CATPolyBarIter2D(const CATPolyPolygon2D& iPolygon, 
  bool iIncludeFullVertex,
  bool iIncludeSegments,
  bool iIncludeArcs)
  : _Bars(iPolygon.GetBarBuckets())
  , _IncludeFullVertex(iIncludeFullVertex)
  , _IncludeSegments(iIncludeSegments)
  , _IncludeArcs(iIncludeArcs)
{
  Reset();
}

inline HRESULT CATPolyBarIter2D::Reset()
{
  Reset(_IncludeSegments , *_Bars, _BarBucket, _Index);
  if (_BarBucket)
  {
    _IsArc = false;
  }
  else
  {
    _IsArc = true;
    Reset(_IncludeArcs, *_Bars, _ArcBucket, _Index);
  }
  return S_OK;
}

inline CATPolyBar2D* CATPolyBarIter2D::Next()
{
  while (1)
  {
    // Use local stack int enables msvc optimization when _SkipHoleFaces is false
    // Compiler is able to remove useless test !_SkipHoleFaces || IsHoleFace
    if (!_IsArc)
    {
      CATPolyBucket2D<CATPolyBar2D>* BarBucket = _BarBucket;
      if (!BarBucket)
      {
        _IsArc = true;
        Reset(_IncludeArcs, *_Bars, _ArcBucket, _Index);
        return Next();
      }

      unsigned char index = _Index;
      CATPolyBar2D& res = PrivateNext(BarBucket, index);
      _BarBucket = BarBucket;
      _Index = index;
      if (_IncludeFullVertex || !IsFullVertexBar(res))
        return &res;
    }
    else
    {
      CATPolyBucket2D<CATPolyArc2D>* ArcBucket = _ArcBucket;
      if (!ArcBucket)
        return 0;

      unsigned char index = _Index;
      CATPolyBar2D& res = PrivateNext(ArcBucket, index);
      _ArcBucket = ArcBucket;
      _Index = index;
      return &res;
    }
  }
}

#endif
