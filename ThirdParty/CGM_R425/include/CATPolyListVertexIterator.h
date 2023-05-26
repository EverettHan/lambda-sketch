// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyListVertexIterator.h
//
//===================================================================
// July 2018 Creation: tct5
//===================================================================

#ifndef CATPolyListVertexIterator_h
#define CATPolyListVertexIterator_h

#include "CATPolyMiscellaneous.h"
#include "CATIPolySurfaceVertexIterator.h"
#include "CATListOfInt.h"

// Iterator through the vertices contained in a list.
class ExportedByCATPolyMiscellaneous CATPolyListVertexIterator : public CATIPolySurfaceVertexIterator
{
public:
  inline CATPolyListVertexIterator();
  inline CATPolyListVertexIterator(const CATListOfInt& iList);
  inline ~CATPolyListVertexIterator();

public:
  inline CATPolyListVertexIterator& Begin();
  inline CATPolyListVertexIterator& Begin(const CATListOfInt& iList);
  inline CATBoolean End() const;

public:
  inline int Get() const;
  inline int operator*();
  inline int operator-> ();

public:
  CATPolyListVertexIterator& operator++();

private:
  const CATListOfInt* _List;
  int _Index;
};

inline CATPolyListVertexIterator::CATPolyListVertexIterator() :
  _List(0),
  _Index(1)
{
}

inline CATPolyListVertexIterator::CATPolyListVertexIterator(const CATListOfInt& iList) :
  _List(&iList),
  _Index(1)
{
}

inline CATPolyListVertexIterator::~CATPolyListVertexIterator()
{
  _List = 0;
}

inline CATPolyListVertexIterator& CATPolyListVertexIterator::Begin()
{
  _Index = 1;
  return *this;
}

inline CATPolyListVertexIterator& CATPolyListVertexIterator::Begin(const CATListOfInt& iList)
{
  _List = &iList;
  _Index = 1;
  return *this;
}

inline CATBoolean CATPolyListVertexIterator::End() const
{
  return _List && _Index <= _List->Size() ? FALSE : TRUE;
}

inline CATPolyListVertexIterator& CATPolyListVertexIterator::operator++ ()
{
  ++_Index;
  return *this;
}

inline int CATPolyListVertexIterator::Get() const
{
  return _List ? (*_List)[_Index] : 0;
}

inline int CATPolyListVertexIterator::operator* ()
{
  return _List ? (*_List)[_Index] : 0;
}

inline int CATPolyListVertexIterator::operator-> ()
{
  return _List ? (*_List)[_Index] : 0;
}

#endif // !CATPolyListVertexIterator_h
