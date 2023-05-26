// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyWireIter2D.h
// Header definition of CATPolyWireIter2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// November 2006 Creation: ndo
//===================================================================
#ifndef CATPolyWireIter2D_H
#define CATPolyWireIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATBoolean.h"
#include "CATListPV.h"

class CATPolyPolygon2D;
class CATPolyCoBar2D;
class CATPolyWire2D;


/**
Iterator.
Iterates through all the wires of a CATPolyPolygon2D object.
A wire is a list of linked cobars that delimit only hole faces.  
A wire can be a loop or a subset of a loop.
*/
class ExportedByPolygonalModel CATPolyWireIter2D
{

public :

  // Construction of an iterator to go through the wires of a CATPolyPolygon2D object. 
  CATPolyWireIter2D (const CATPolyPolygon2D& iPolygon);

  ~CATPolyWireIter2D ();

  inline HRESULT Reset ();

  // Cycle through the next valid wire of the CATPolyPolygon2D object.
  CATPolyWire2D* Next ();

  inline int GetNbWires () const;

public:

  // Deprecated. ** DO NOT USE **
  CATPolyWireIter2D (CATPolyPolygon2D* iPolygon);

private :

  const CATPolyPolygon2D* _Polygon;
  CATListPV _Wires;

  int _Index;

  void FindWires ();
  void DeleteWires ();
  void ConstructNewWire (CATPolyCoBar2D* cobar0, int* barVisited);

public:

  // Temporary static method to activate stable iteration mode.  (For ODTs).
  static void SetStableMode (const int iStableMode);

};


inline HRESULT CATPolyWireIter2D::Reset ()
{
  _Index = 0;
  return _Polygon ? S_OK : E_FAIL;
}


inline int CATPolyWireIter2D::GetNbWires () const
{
  return _Wires.Size ();
}

#endif
