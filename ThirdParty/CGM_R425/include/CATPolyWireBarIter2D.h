// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyWireBarIter2D.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2009 Creation: ndo
//===================================================================
#ifndef CATPolyWireBarIter2D_H
#define CATPolyWireBarIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyWire2D;
class CATPolyCoBar2D;
class CATPolyVertex2D;
class CATPolyBar2D;


/**
Iterator.
Iterates through all the vertices of a wire of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyWireBarIter2D
{

public :

  CATPolyWireBarIter2D(const CATPolyWire2D& iWire);
  CATPolyWireBarIter2D (const CATPolyWire2D* iWire);

  // Reset the iterator to iterate through all the vertices of a wire of the CATPolyPolygon2D object.
  HRESULT Reset (const CATPolyWire2D* iWire);

  // Cycle through the next bar of the wire.
  CATPolyBar2D* Next ();

  // Cycle through the next pair (vertex, bar) of the wire.  Both bar and vertex are outputs.
  // The vertex is the start vertex of the bar in the direction of the wire.
  CATPolyBar2D* Next (CATPolyVertex2D*& vertex);

private :

  const CATPolyWire2D* _Wire;
  CATPolyCoBar2D* _CoBar;

};


#endif
