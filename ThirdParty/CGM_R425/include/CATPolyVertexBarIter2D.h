// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexBarIter2D.h
// Header definition of CATPolyVertexBarIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2007 Creation: ndo
//===================================================================
#ifndef CATPolyVertexBarIter2D_H
#define CATPolyVertexBarIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyCoBar2D;

/**
Iterator.
Iterates through all the bars around a vertex.
*/
class ExportedByPolygonalModel CATPolyVertexBarIter2D
{

public :

  CATPolyVertexBarIter2D(const CATPolyVertex2D &iVertex);
  CATPolyVertexBarIter2D (const CATPolyVertex2D* iVertex);

  // Reset the iterator to iterate through all the bars around a vertex.
  HRESULT Reset (const CATPolyVertex2D* iVertex);

  // Cycle through the next bar around the vertex.
  CATPolyBar2D* Next ();

private :
  CATPolyCoBar2D* _StartCoBar;
  CATPolyCoBar2D* _CoBar;

};


#endif
