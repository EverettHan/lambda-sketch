//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Pool of CATMathPoint
//
//=============================================================================
//  2009-06-23  JXO: New.
//  2015-04-23  JXO: Warning correction
//=============================================================================
#ifndef CATPolyPoolOfPoints_H
#define CATPolyPoolOfPoints_H

#include "string.h"
// Math
#include "CATMathPoint.h"


#include "PolyBodyBVHOperators.h"

/**
 * Pool of Points
 */
class ExportedByPolyBodyBVHOperators CATPolyPoolOfPoints
{
public:
  inline CATPolyPoolOfPoints(const CATPolyPoolOfPoints & iCopy);
  inline CATPolyPoolOfPoints();
  inline ~CATPolyPoolOfPoints();

  /**
   * Put a new Point, returns the index
   */
  inline int Add(const CATMathPoint & Point);
  /**
   * index from 0 to < size
   */
  inline const CATMathPoint & Get(int index);
  /**
   * Returns size of pool.
   */
  inline int Size();

  /**
   * <b>Role</b>: Overwrites the content of the stack with this new stack.
   */
  inline CATPolyPoolOfPoints & operator = (const CATPolyPoolOfPoints & iCopy)
  {
    return Copy(iCopy);
  }

protected:
  /**
   * Copy operator. 
   */
  inline CATPolyPoolOfPoints & Copy(const CATPolyPoolOfPoints & iCopy);


private:
  inline void DestroyPools();
private:
  int _PoolSize;
  int _InitialNbOfPools;

  CATMathPoint ** _Pool;
  int _NbPools;
  int _NbPoints;

  // Just in case:
  CATMathPoint _EmptyPoint;

};






inline CATPolyPoolOfPoints::CATPolyPoolOfPoints()
{
  _PoolSize = 1000;
  _InitialNbOfPools = 1000;

  _Pool = NULL;
  _NbPools = 0;
  _NbPoints = 0;

  // I allocated a first pool in constructor: for
  // multi threading, it could be better to allocate outside thread management
  // _Pool = new CATMathPoint * [_InitialNbOfPools];
  // _Pool[_NbPools] = new CATMathPoint[_PoolSize];
  
  // _NbPools++;
}

CATPolyPoolOfPoints::CATPolyPoolOfPoints(const CATPolyPoolOfPoints & iCopy)
{
  _PoolSize = 1000;
  _InitialNbOfPools = 1000;

  _Pool = NULL;
  _NbPools = 0;
  _NbPoints = 0;

  Copy(iCopy);
}

CATPolyPoolOfPoints::~CATPolyPoolOfPoints()
{
  DestroyPools();
  _Pool = NULL;
  _NbPools = 0;
  _NbPoints = 0;
}

int CATPolyPoolOfPoints::Add(const CATMathPoint & Point)
{
  int newnbcouples = _NbPoints + 1;
  if(_PoolSize * _NbPools < newnbcouples)
  {
    if(NULL == _Pool)
    {
      _Pool = new CATMathPoint * [_InitialNbOfPools];
    }
    _Pool[_NbPools] = new CATMathPoint[_PoolSize];

    /**
     * Reallocation in case...
     */
    _NbPools++;
    if(_NbPools >= _InitialNbOfPools)
    {
      int newnbofpools = _InitialNbOfPools * 2;
      CATMathPoint ** tmppool = new CATMathPoint * [newnbofpools];
      memset(tmppool+_InitialNbOfPools, 0, _InitialNbOfPools * sizeof(CATMathPoint *));
      memcpy(tmppool, _Pool, _InitialNbOfPools * sizeof(CATMathPoint *));

      delete [] _Pool;
      _Pool = tmppool;
      tmppool = NULL;
      _InitialNbOfPools = newnbofpools;
    }
  }

  // Perfect
  if(NULL != _Pool)
  {
    int currentpoolnb = (newnbcouples-1)/_PoolSize;
    int indexincurrentpool = newnbcouples - 1 - currentpoolnb * _PoolSize;
    if(NULL != _Pool[currentpoolnb])
    {
      _NbPoints = newnbcouples;
      _Pool[currentpoolnb][indexincurrentpool] = Point;
      return currentpoolnb * _PoolSize + indexincurrentpool;
    }
  }
  _Pool = NULL;
  _NbPools = 0;
  _NbPoints = 0;
  return -1;
}

const CATMathPoint & CATPolyPoolOfPoints::Get(int index)
{
  if(NULL != _Pool)
  {
    if(index < _NbPoints)
    {
      int currentpoolindex = index/_PoolSize;

      // We can't release memory because somebody may still be pointing some previously popped point...

      int indexincurrentpool = index - currentpoolindex * _PoolSize;
      if(NULL != _Pool[currentpoolindex])
      {
        return _Pool[currentpoolindex][indexincurrentpool];
      }
    }
  }
  return _EmptyPoint;
}

int CATPolyPoolOfPoints::Size()
{
  return _NbPoints;
}


CATPolyPoolOfPoints & CATPolyPoolOfPoints::Copy(const CATPolyPoolOfPoints & iCopy)
{
  DestroyPools();
  _PoolSize = iCopy._PoolSize;
  _InitialNbOfPools = iCopy._InitialNbOfPools;
  _NbPools = iCopy._NbPools;
  _NbPoints = iCopy._NbPoints;

  /**
   * Optimization in case we copy a very small stack
   * (Note that in this case the Push method could suffer some performances pbs if
   * Size becomes very large.)
   */
  if(1 <= _NbPoints && _NbPoints < _PoolSize && 1 == _NbPools)
  {
    _PoolSize = _NbPoints;
  }

  /**
   * Pool copy...
   */
  _Pool = NULL;
  if(NULL != iCopy._Pool)
  {
    _Pool = new CATMathPoint * [_InitialNbOfPools];
    memset(_Pool, 0, _InitialNbOfPools * sizeof(CATMathPoint *));
    int i = 0;
    for(i = 0; i < _NbPools; i++)
    {
      if(NULL != iCopy._Pool[i])
      {
        _Pool[i] = new CATMathPoint[_PoolSize];
        memcpy(_Pool[i], iCopy._Pool[i], _PoolSize * sizeof(CATMathPoint));
      }
    }
  }
  return (*this);
}

void CATPolyPoolOfPoints::DestroyPools()
{
  if(NULL != _Pool)
  {
    int i = 0;
    for(i = 0; i < _NbPools; i++)
    {
      CATMathPoint * couples = _Pool[i];
      if(NULL != couples)
      {
        delete [] couples;
      }
      couples = NULL;
    }
    delete [] _Pool;
  }
  _Pool = NULL;
  _NbPools = 0;
  _NbPoints = 0;
}



#endif // !CATPolyPoolOfPoints_H
