// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCoBarIter2D.h
// Header definition of CATPolyCoBarIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2006 Creation: ndo
//===================================================================
#ifndef CATPolyCoBarIter2D_H
#define CATPolyCoBarIter2D_H

#include "PolygonalModel.h"
#include "CATPolyBarIter2D.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATBoolean.h"

class CATPolyPolygon2D;
class CATPolyBar2D;
class CATPolyCoBar2D;


/**
Iterator.
Iterates through all the cobars of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyCoBarIter2D
{

public :

  CATPolyCoBarIter2D (const CATPolyPolygon2D& iPolygon);

  // Reset the iterator.
  // If the argument is set to TRUE, the iterator will skip the twin of the cobars.
  // By default, all cobars are returned.
  HRESULT Reset (const CATBoolean iSkipTwins = FALSE);

  // Cycle through the next valid cobar of the CATPolyPolygon2D object.
  CATPolyCoBar2D* Next ();

private :

  CATBoolean _SkipTwins;
  CATPolyBar2D* _Bar;

  CATPolyBarIter2D _BarIter;
};


inline HRESULT CATPolyCoBarIter2D::Reset (const CATBoolean iSkipTwins)
{
  _SkipTwins = iSkipTwins;
  _Bar = 0;
  return _BarIter.Reset ();
}

#endif
