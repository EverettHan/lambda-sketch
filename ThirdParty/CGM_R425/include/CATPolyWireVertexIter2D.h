// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyWireVertexIter2D.h
// Header definition of CATPolyWireVertexIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// November 2006 Creation: ndo
//===================================================================
#ifndef CATPolyWireVertexIter2D_H
#define CATPolyWireVertexIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyWire2D;
class CATPolyCoBar2D;
class CATPolyVertex2D;


/**
Iterator.
Iterates through all the vertices of a wire of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyWireVertexIter2D
{

public :
  CATPolyWireVertexIter2D(const CATPolyWire2D& iWire);
  CATPolyWireVertexIter2D (const CATPolyWire2D* iWire);

  // Reset the iterator to iterate through all the vertices of a wire of the CATPolyPolygon2D object.
  HRESULT Reset (const CATPolyWire2D* iWire);

  // Cycle through the next vertex of the wire.
  CATPolyVertex2D* Next ();

private :

  const CATPolyWire2D* _Wire;
  CATPolyCoBar2D* _CoBar;
  int _Index;

};


#endif
