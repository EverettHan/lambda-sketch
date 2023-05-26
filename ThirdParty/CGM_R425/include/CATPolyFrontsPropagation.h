// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFrontsPropagation.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyFrontsPropagation_H
#define CATPolyFrontsPropagation_H

#include "CATErrorDef.h"
#include "CATDataType.h"

#include "CATPolySegmentOperators.h"
#include "CATPolyBuckets_T.h"
#include "CATMathLimits.h"
#include "CATListOfInt.h"


class CATPolyIntegerSetCover;
class CATPolyCoverManager;

class CATPolyPriorityQueue2;

class CATPolyVerticesFront;
class CATIPolyIntIterator;

class CATMapOfIntToPtr;


class ExportedByCATPolySegmentOperators CATPolyFrontsPropagation
{
public:
  CATPolyFrontsPropagation(int iMaxVertexIndex, CATPolyIntegerSetCover* iCover=NULL);
  ~CATPolyFrontsPropagation();

public:
  enum VertexState
  {
	  Far,
	  Close,
	  Alive,
    Dead
  };

public:
  HRESULT GetVertexFronts(const int iIdxVertex, CATListOfInt& oVertexFronts) const;
  CATBoolean IsVertexInFront(const int iIdxVertex, const int iIdxFront);
  double VertexDistance(const int iIdxVertex, const int iIdxFront) const;
  int VertexState(const int iIdxVertex, const int iIdxFront) const;

  HRESULT SetVertexFront(const int iIdxVertex, const int iIdxFront);
  HRESULT SetVertexState(const int iIdxVertex, const int iIdxFront, const int iState);
  HRESULT SetVertexDistance(const int iIdxVertex,const int iIdxFront, const double iDistance);

public:
  HRESULT AddFront(int& oIdxFront);
  HRESULT RemoveFront(int iIdxFront);
  
  HRESULT GetFront(int iIdxFront, CATPolyVerticesFront*& oFront);
  HRESULT GetFrontVertices(int iIdxFront, CATIPolyIntIterator*& oFrontVerticesIter);

  int GetNbFronts();
  HRESULT Initialize();

public:
  inline CATPolyIntegerSetCover* Cover();
  inline CATPolyPriorityQueue2* Queue();
  inline HRESULT SetLastAttributed(const int iIdxV);
  inline HRESULT SetMaxDistance(const double iDistance);
  


private:
  class VertexData
  {
  public:
    VertexData() : _State(0), _Distance(CATMathInfinite){};
  public:
    int _State;
    double _Distance;
  };
  class Specialize_CATPolyBuckets_T(VertexDataBuckets, CATMapOfIntToPtr*); 


private:
  HRESULT EmptyVertexDatas();
  VertexData* GetVertexData(const int iIdxVertex, 
                            const int iIdxFront) const;
  
  VertexData* GetVertexDataWithAlloc(const int iIdxVertex, 
                                     const int iIdxFront);

private:
  CATPolyIntegerSetCover* _Cover;
  CATPolyIntegerSetCover* _NewCover;
  CATPolyCoverManager* _CoverManager;

private:
  int _MaxVertexIndex;

private:
  VertexDataBuckets _VertexDatas;
  CATPolyPriorityQueue2* _Queue; 
  double _MaxDistance;
  int _LastAttributed;
};


//INLINE

inline CATPolyIntegerSetCover* CATPolyFrontsPropagation::Cover() 
{
  return _Cover;
}

inline CATPolyPriorityQueue2* CATPolyFrontsPropagation::Queue()
{
  return _Queue;
}

inline HRESULT CATPolyFrontsPropagation::SetLastAttributed(const int iIdxV)
{
  _LastAttributed = iIdxV; 
  return S_OK;
}

inline HRESULT CATPolyFrontsPropagation::SetMaxDistance(const double iDistance)
{
  _MaxDistance = iDistance;
  return S_OK;
}

#endif
