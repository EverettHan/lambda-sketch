// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexIter2D.h
// Header definition of CATPolyVertexIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2006 Creation: ndo
//===================================================================
#ifndef CATPolyVertexIter2D_H
#define CATPolyVertexIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATPolyPolygon2D.h"     // HRESULT definition (for compil under UNIX)

class CATPolyPolygon2D;
class CATPolyVertex2D;
class CATPolyVertexBuckets2D;
template<class> class CATPolyBucket2D;

/**
Iterator.
Iterates through all the vertices of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyVertexIter2D
{

public :

  CATPolyVertexIter2D (const CATPolyPolygon2D& iPolygon);

  // Reset the iterator to iterate through all the vertices of the CATPolyPolygon2D object.
  HRESULT Reset ();

  // Cycle through the next valid vertex of the CATPolyPolygon2D object.
  CATPolyVertex2D* Next ();

public :

  // Deprecated. ** DO NOT USE **
  CATPolyVertexIter2D (CATPolyPolygon2D* iPolygon);

private:
  CATPolyVertex2D& PrivateNext();

  CATPolyVertexBuckets2D* _Vertices;
  CATPolyBucket2D<CATPolyVertex2D>* _VertexBucket;
  unsigned char _Index;

};

inline CATPolyVertexIter2D::CATPolyVertexIter2D(const CATPolyPolygon2D& iPolygon)
  : _Vertices(iPolygon.GetVertexBuckets())
{
  Reset();
}

inline CATPolyVertexIter2D::CATPolyVertexIter2D(CATPolyPolygon2D *iPolygon)
  : _Vertices(iPolygon ? iPolygon->GetVertexBuckets() : 0)
{
  Reset();
}

inline CATPolyVertex2D* CATPolyVertexIter2D::Next()
{
  if (!_VertexBucket)
    return 0;
  CATPolyVertex2D& res = PrivateNext();
  return &res;
}

#endif
