// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonCompactArcIndexMapper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2022 Creation: te9
//===================================================================
#ifndef CATPolyPolygonCompactArcIndexMapper_H
#define CATPolyPolygonCompactArcIndexMapper_H

#include "CATErrorDef.h"
#include "CATBucketsOfInt.h"

class CATPolyPolygon2D;


/*
Maps the indices of the vertices of a CATPolyPolygon2D object to an index in a compact (serialized) 
array of vertices.  Compact indices start at 0 and end at the number of vertices minus 1. 
*/
class CATPolyPolygonCompactArcIndexMapper
{

public :

  CATPolyPolygonCompactArcIndexMapper (const CATPolyPolygon2D& iPolygon);

  // Return a map of the vertex indices to indices in a compact array starting at 0.
  const CATBucketsOfInt& GetMap () const;

private:

  CATBucketsOfInt _Map;

};

inline const CATBucketsOfInt& CATPolyPolygonCompactArcIndexMapper::GetMap () const
{
  return _Map;
}

#endif
