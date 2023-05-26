// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFaceIntLayer2D.h
// Header definition of CATPolyFaceIntLayer2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2007 Creation: ndo
//===================================================================
#ifndef CATPolyFaceIntLayer2D_H
#define CATPolyFaceIntLayer2D_H

#include "PolygonalLayers.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATPolyBuckets_T.h"

class CATPolyPolygon2D;
class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyFace2D;


/**
* Layer of integers for faces of a CATPolyPolygon2D object.
*/
class ExportedByPolygonalLayers CATPolyFaceIntLayer2D
{

public :

  CATPolyFaceIntLayer2D (const CATPolyPolygon2D& iPolygon, const int iDefault = 0);
  ~CATPolyFaceIntLayer2D () {}

public:

  // Return the integer attribute associated to the face.
  int operator [] (const CATPolyFace2D* face) const;

  // Return a reference to the integer attribute associated to the face.
  int& operator [] (const CATPolyFace2D* face);

public:

  inline unsigned int Size () const;
  inline unsigned int PushBack ();   // Add a slot for a face.

private:

  // Buckets of integers.
  class Specialize_CATPolyBuckets_T (IntBuckets, int);

private:

  IntBuckets _Data;
  int _Default;

private:

  // Forbidden.
  CATPolyFaceIntLayer2D (const CATPolyFaceIntLayer2D& iOther) ;
  CATPolyFaceIntLayer2D& operator= (const CATPolyFaceIntLayer2D& iOther) ;

};


inline unsigned int CATPolyFaceIntLayer2D::Size () const
{
  return _Data.Size ();
}

inline unsigned int CATPolyFaceIntLayer2D::PushBack ()
{
  return _Data.PushBack (_Default);
}

#endif
