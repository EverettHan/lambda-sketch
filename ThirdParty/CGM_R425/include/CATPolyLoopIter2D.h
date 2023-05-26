// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyLoopIter2D.h
// Header definition of CATPolyLoopIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2006 Creation: ndo
//===================================================================
#ifndef CATPolyLoopIter2D_H
#define CATPolyLoopIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyPolygon2D;
class CATPolyLoop2D;
class CATPolyLoopBuckets2D;
template<class> class CATPolyBucket2D;
/**
Iterator.
Iterates through all the loops of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyLoopIter2D
{
public :
  CATPolyLoopIter2D (const CATPolyPolygon2D& iPolygon);

  // Reset the iterator.
  HRESULT Reset ();

  // Cycle through the next valid loop of the CATPolyPolygon2D object.
  CATPolyLoop2D* Next ();

private :
  CATPolyLoop2D& PrivateNext();

  CATPolyLoopBuckets2D* _Loops;
  CATPolyBucket2D<CATPolyLoop2D>* _LoopBucket;
  unsigned char _Index;
};

inline CATPolyLoop2D* CATPolyLoopIter2D::Next()
{
  if (!_LoopBucket)
    return 0;
  CATPolyLoop2D& loop = PrivateNext();
  return &loop;
}

#endif
