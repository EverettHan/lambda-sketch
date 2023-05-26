#ifndef CATPolyStdIteratorsUtilities2D_H
#define CATPolyStdIteratorsUtilities2D_H

#include "CATPolyFaceIter2D.h"
#include "CATPolyLoopIter2D.h"
#include "CATPolyBarIter2D.h"
#include "CATPolyVertexIter2D.h"
#include "CATPolyFaceLoopIter2D.h"
#include "CATPolyLoopVertexIter2D.h"
#include "CATPolyLoopBarIter2D.h"
#include "CATPolyVertexBarIter2D.h"
#include "CATPolyWireIter2D.h"
#include "CATPolyWireVertexIter2D.h"
#include "CATPolyWireBarIter2D.h"

#include <tuple>

class CATPolyPolygon2D;
class CATPolyFace2D;
class CATPolyLoop2D;
class CATPolyBar2D;
class CATPolyVertex2D;
class CATPolyWire2D;

/*
 * STL like iterator class encapsulating an PolyIter class 
 * Iterator template parameter can be CATPolyFaceIter2D, CATPolyLoopIter2D, ...
 */

template<class Iterator>
class CATPolyIterator
{
private:
  using Entity = decltype(static_cast<Iterator*>(nullptr)->Next());

public:
  template<class... Args>
  CATPolyIterator(Args&& ...iArgs)
    : _iterator(std::forward<Args>(iArgs)...)
    , _pEntity(_iterator.Next())
  {
  }

  CATPolyIterator& operator++()
  {
    _pEntity = _iterator.Next();
    return *this;
  }

  /*
   * Dereferences the iterator
   * @return a reference on the iter type : ie CATPolyFace2D & for CATPolyFaceIter2D
   */
  decltype(auto) operator*() const
  {
    return *_pEntity;
  }

  class EndIterator {};

  bool operator==(EndIterator const&) const
  {
    return !_pEntity;
  }

  bool operator!=(EndIterator const&) const
  {
    return _pEntity;
  }

private:
  Iterator _iterator;
  Entity _pEntity = nullptr;
};

/*
 * C++ range class implementing begin() and end() method
 * Template parameters :
 * Element : the element on which we iterate (CATPolyPolygon2D const &, CATPolyLoop2D const *, ...)
 * IteratorType : the type of the encapsulated iterator (CATPolyFaceIter2D, ...)
 * OptionalArguments : Types of optional arguments for constructing the iterator object (CATBoolean for iSkipHoleFaces argument of CATPolyFaceIter2D)
 */

template<class Element, class IteratorType, class... OptionalArguments>
class CATPolyRange : private std::tuple<OptionalArguments...>
{
public:
  CATPolyRange(Element iElement, OptionalArguments... iArguments)
    : std::tuple<OptionalArguments...>(iArguments...)
    , _element(iElement)
  {}

  class Iterator : private CATPolyIterator<IteratorType>
  {
  public:
    using CATPolyIterator<IteratorType>::CATPolyIterator;
    using CATPolyIterator<IteratorType>::operator++;
    using CATPolyIterator<IteratorType>::operator*;
    using CATPolyIterator<IteratorType>::operator==;
    using CATPolyIterator<IteratorType>::operator!=;
  };

  /*
   * Constructs an CATPolyIterator iterator encapsulating the IteratorType
   * @return a CATPolyIterator<IteratorType>
   */
  Iterator begin()
  {
    std::tuple<OptionalArguments...> &tuple = *this;
    return std::apply([&](auto const& ...iArguments)
      {
        return Iterator(_element, iArguments...);
      }, tuple);
  }

  /*
   * Constructs a sentinel iterator
   * @return a CATPolyIterator<IteratorType>::EndIterator
   */
  typename CATPolyIterator<IteratorType>::EndIterator end()
  {
    return typename CATPolyIterator<IteratorType>::EndIterator();
  }

protected:
  Element _element;
};

/*
 * Range class for iterating over polygon faces
 */

class CATPolyPolygonFaceRange2D : private CATPolyRange<CATPolyPolygon2D const&, CATPolyFaceIter2D, CATBoolean>
{
private:
  using Base = CATPolyRange<CATPolyPolygon2D const&, CATPolyFaceIter2D, CATBoolean>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over polygon loops
 */

class CATPolyPolygonLoopRange2D : private CATPolyRange<CATPolyPolygon2D const&, CATPolyLoopIter2D>
{
private:
  using Base = CATPolyRange<CATPolyPolygon2D const&, CATPolyLoopIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over polygon bars
 */

class CATPolyPolygonBarRange2D : private CATPolyRange<CATPolyPolygon2D const&, CATPolyBarIter2D, bool, bool, bool>
{
private:
  using Base = CATPolyRange<CATPolyPolygon2D const&, CATPolyBarIter2D, bool, bool, bool>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over polygon vertices
 */

class CATPolyPolygonVertexRange2D : private CATPolyRange<CATPolyPolygon2D const&, CATPolyVertexIter2D>
{
private:
  using Base = CATPolyRange<CATPolyPolygon2D const&, CATPolyVertexIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};


/*
 * Range class for iterating over polygon wires
 */

class CATPolyPolygonWireRange2D : private CATPolyRange<CATPolyPolygon2D const&, CATPolyWireIter2D>
{
private:
  using Base = CATPolyRange<CATPolyPolygon2D const&, CATPolyWireIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over face loops
 */

class CATPolyFaceLoopRange2D : private CATPolyRange<CATPolyFace2D const&, CATPolyFaceLoopIter2D>
{
private:
  using Base = CATPolyRange<CATPolyFace2D const&, CATPolyFaceLoopIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over loop vertices
 */

class CATPolyLoopVertexRange2D : private CATPolyRange<CATPolyLoop2D const&, CATPolyLoopVertexIter2D>
{
private:
  using Base = CATPolyRange<CATPolyLoop2D const&, CATPolyLoopVertexIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over loop bars
 */

class CATPolyLoopBarRange2D : private CATPolyRange<CATPolyLoop2D const&, CATPolyLoopBarIter2D>
{
private:
  using Base = CATPolyRange<CATPolyLoop2D const&, CATPolyLoopBarIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Iterator class wrapper of CATPolyLoopBarIter2D/CATPolyWireBarIter2D compatible with CATPolyIterator
 * which return a pair of vertex and bar
 */
template<class Base>
class CATPolyLoopWireVertexBarIter2D : private Base
{
public:
  using Base::Base;
  using Base::Reset;

  class VertexBar
  {
  public:
    operator bool() const
    {
      return _pBar;
    }

    std::pair<CATPolyVertex2D&, CATPolyBar2D&> operator*() const
    {
      return { *_pVertex , *_pBar };
    }

    CATPolyVertex2D *_pVertex;
    CATPolyBar2D *_pBar;
  };

  VertexBar Next()
  {
    VertexBar res;
    res._pBar = Base::Next(res._pVertex);
    return res;
  }
};

/*
 * Range class for iterating over loop vertices and bars
 */

class CATPolyLoopVertexBarRange2D : private CATPolyRange<CATPolyLoop2D const&, CATPolyLoopWireVertexBarIter2D<CATPolyLoopBarIter2D>>
{
private:
  using Base = CATPolyRange<CATPolyLoop2D const&, CATPolyLoopWireVertexBarIter2D<CATPolyLoopBarIter2D>>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over wire vertices
 */

class CATPolyWireVertexRange2D : private CATPolyRange<CATPolyWire2D const&, CATPolyWireVertexIter2D>
{
private:
  using Base = CATPolyRange<CATPolyWire2D const&, CATPolyWireVertexIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over wire bars
 */

class CATPolyWireBarRange2D : private CATPolyRange<CATPolyWire2D const&, CATPolyWireBarIter2D>
{
private:
  using Base = CATPolyRange<CATPolyWire2D const&, CATPolyWireBarIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over wire vertices and bars
 */

class CATPolyWireVertexBarRange2D : private CATPolyRange<CATPolyWire2D const&, CATPolyLoopWireVertexBarIter2D<CATPolyWireBarIter2D>>
{
private:
  using Base = CATPolyRange<CATPolyWire2D const&, CATPolyLoopWireVertexBarIter2D<CATPolyWireBarIter2D>>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

/*
 * Range class for iterating over vertex bars
 */

class CATPolyVertexBarRange2D : private CATPolyRange<CATPolyVertex2D const&, CATPolyVertexBarIter2D>
{
private:
  using Base = CATPolyRange<CATPolyVertex2D const&, CATPolyVertexBarIter2D>;

public:
  using Base::CATPolyRange;
  using Base::Iterator;
  using Base::begin;
  using Base::end;
};

#endif
