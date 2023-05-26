// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonCompactVertexIndexMapper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// September 2008 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonCompactVertexIndexMapper_H
#define CATPolyPolygonCompactVertexIndexMapper_H

#include "PolygonalSerializers.h"
#include "CATErrorDef.h"
#include "CATBucketsOfInt.h"

class CATPolyPolygon2D;


/*
Maps the indices of the vertices of a CATPolyPolygon2D object to an index in a compact (serialized) 
array of vertices.  Compact indices start at 0 and end at the number of vertices minus 1. 
*/
class ExportedByPolygonalSerializers CATPolyPolygonCompactVertexIndexMapper
{

public :

  CATPolyPolygonCompactVertexIndexMapper (const CATPolyPolygon2D& iPolygon);
  ~CATPolyPolygonCompactVertexIndexMapper () {}

  // Return a map of the vertex indices to indices in a compact array starting at 0.
  inline const CATBucketsOfInt& GetMap () const;

private:

  CATBucketsOfInt _Map;

};

inline const CATBucketsOfInt& CATPolyPolygonCompactVertexIndexMapper::GetMap () const
{
  return _Map;
}

#endif
