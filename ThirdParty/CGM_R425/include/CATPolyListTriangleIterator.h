// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyListTriangleIterator.h
//
//===================================================================
// December 2007 Creation: ndo
//===================================================================
#ifndef CATPolyListTriangleIterator_H
#define CATPolyListTriangleIterator_H

#include "CATPolyMiscellaneous.h"
#include "CATIPolyMeshTriangleIterator.h"
#include "CATListOfInt.h"


/**
 * Iterator through the triangles contained in a list.
 */
class ExportedByCATPolyMiscellaneous CATPolyListTriangleIterator : public CATIPolyMeshTriangleIterator
{

public:

  inline CATPolyListTriangleIterator ();
  inline CATPolyListTriangleIterator (const CATListOfInt& iList);
  inline ~CATPolyListTriangleIterator ();

public:

  CATIPolySurfaceFacetIterator* Clone () const;

public:

  CATIPolySurfaceFacetIterator& Begin (const CATListOfInt& iList);
  CATIPolySurfaceFacetIterator& Begin ();
  CATBoolean End () const;

public:

  inline CATIPolySurfaceFacetIterator& operator++ ();

public:

  inline int Get () const;
  inline int operator* ();
  inline int operator-> ();

private:

  const CATListOfInt* _List;
  int _Index;

};

inline CATPolyListTriangleIterator::CATPolyListTriangleIterator () :
  _List (0),
  _Index (1)
{
}

inline CATPolyListTriangleIterator::CATPolyListTriangleIterator (const CATListOfInt& iList) :
  _List (&iList),
  _Index (1)
{
}

inline CATIPolySurfaceFacetIterator* CATPolyListTriangleIterator::Clone () const
{
  return new CATPolyListTriangleIterator(*this);
}

inline CATPolyListTriangleIterator::~CATPolyListTriangleIterator ()
{
  _List = 0;
}

inline CATIPolySurfaceFacetIterator& CATPolyListTriangleIterator::Begin (const CATListOfInt& iList)
{
  _List = &iList;
  _Index = 1;
  return *this;
}

inline CATIPolySurfaceFacetIterator& CATPolyListTriangleIterator::Begin ()
{
  _Index = 1;
  return *this;
}

inline CATBoolean CATPolyListTriangleIterator::End () const
{
  return _List && _Index <= _List->Size () ? FALSE : TRUE;
}

inline CATIPolySurfaceFacetIterator& CATPolyListTriangleIterator::operator++ ()
{
  ++_Index;
  return *this;
}

inline int CATPolyListTriangleIterator::Get () const
{
  return _List ? (*_List)[_Index] : 0;
}

inline int CATPolyListTriangleIterator::operator* ()
{
  return _List ? (*_List)[_Index] : 0;
}

inline int CATPolyListTriangleIterator::operator-> ()
{
  return _List ? (*_List)[_Index] : 0;
}

#endif // !CATPolyListTriangleIterator_H
