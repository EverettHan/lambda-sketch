// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSComparator:
//
//=============================================================================
//  Feb 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSComparator_h
#define CATCDSComparator_h

#include "CATCDSAssert.h"

template<class T>
class CATCDSComparator
{
public:
  CATCDSComparator() : _count(0) {}
  virtual ~CATCDSComparator() {}

  virtual bool Compare(T const &iT1, T const &iT2) = 0;

  // Reference counter for the less operator
  int _count;
};

template<class T>
class CATCDSLess
{
public:
  // The less object takes ownership of ipComparator
  CATCDSLess(CATCDSComparator<T> *ipComparator) :
    _pComparator(ipComparator)
  {
    CATCDSAssert(ipComparator->_count == 0);
    ipComparator->_count = 1;
  }

  CATCDSLess(CATCDSLess const &iLess) : _pComparator(iLess._pComparator)
  {
    ++_pComparator->_count;
  }

  CATCDSLess& operator=(CATCDSLess const &iLess)
  {
    if(this != &iLess) {
      if(--_pComparator->_count == 0)
        delete _pComparator;
      _pComparator = iLess._pComparator;
      ++_pComparator->_count;
    }
    return *this;
  }

  ~CATCDSLess()
  {
    if(--_pComparator->_count == 0)
      delete _pComparator;    
  }

  bool operator()(T const &iT1, T const &iT2) const
  {
    return _pComparator->Compare(iT1, iT2);
  }

private:
  CATCDSComparator<T> *_pComparator;
};

template<class T>
class CATCDSMore
{
public:
  // The more object takes ownership of ipComparator
  CATCDSMore(CATCDSComparator<T> *ipComparator) :
    _pComparator(ipComparator)
  {
    CATCDSAssert(ipComparator->_count == 0);
    ipComparator->_count = 1;
  }

  CATCDSMore(CATCDSMore const &iMore) : _pComparator(iMore._pComparator)
  {
    ++_pComparator->_count;
  }

  CATCDSMore& operator=(CATCDSMore const &iMore)
  {
    if(this != &iMore) {
      if(--_pComparator->_count == 0)
        delete _pComparator;
      _pComparator = iMore._pComparator;
      ++_pComparator->_count;
    }
    return *this;
  }

  ~CATCDSMore()
  {
    if(--_pComparator->_count == 0)
      delete _pComparator;    
  }

  bool operator()(T const &iT1, T const &iT2) const
  {
    return _pComparator->Compare(iT2, iT1);
  }

private:
  CATCDSComparator<T> *_pComparator;
};

#endif
