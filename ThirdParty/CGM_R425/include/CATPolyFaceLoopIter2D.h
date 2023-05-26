// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFaceLoopIter2D.h
// Header definition of CATPolyFaceLoopIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2006 Creation: ndo
//===================================================================
#ifndef CATPolyFaceLoopIter2D_H
#define CATPolyFaceLoopIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyFace2D;
class CATPolyLoop2D;


/**
Iterator.
Iterates through the loops of a face of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalModel CATPolyFaceLoopIter2D
{

public :

  CATPolyFaceLoopIter2D(const CATPolyFace2D &iFace);
  CATPolyFaceLoopIter2D (const CATPolyFace2D* iFace);

  // Reset the operator to iterate through the loop of a specific face.
   HRESULT Reset (const CATPolyFace2D* iFace);

  // Cycle through the next valid loop of a face.
  // The first loop returned is the outer loop of the face.
  CATPolyLoop2D* Next ();

private :

  CATPolyLoop2D* _Loop;

};

#endif
