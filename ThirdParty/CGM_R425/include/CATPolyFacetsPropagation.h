// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFacetsPropagation.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyFacetsPropagation_H
#define CATPolyFacetsPropagation_H

#include "CATPolyBuckets_T.h"
#include "CATPolyPartitionManager.h"
#include "CATPolySegmentOperators.h"
#include "CATMathLimits.h"

class CATPolyFacetsPatch;
class CATPolyIntegerSetPartition;
class CATPolyPriorityQueue;

class ExportedByCATPolySegmentOperators CATPolyFacetsPropagation
{
public:
  CATPolyFacetsPropagation(CATPolyIntegerSetPartition* iPartition = NULL);
  ~CATPolyFacetsPropagation();

public:
  enum FacetState
  {
	  Far,
	  Close,
	  Alive,
    Dead
  };

public:
  inline int GetNbPatchs();
  inline int GetFacetPatch(int iIdxFacet);
  
  HRESULT CreatePatch(int &oIdxPatch, 
                      CATPolyFacetsPatch*& oPatch);

  inline HRESULT GetPatch(int iIdxPatch, 
                          CATPolyFacetsPatch*& oPatch);
  
  inline CATBoolean IsFacetAvailable(int iIdxFacet);

  inline HRESULT AddFacetToPatch(int iIdxFacet, 
                                 int iIdxPatch);

  inline HRESULT RemoveFacetFromPatch(int iIdxFacet,
                                      int iIdxPatch);

  inline HRESULT EmptyPatch(int iIdxPatch);

  inline HRESULT EmptyFacetDatas();

  inline HRESULT SetFacetTempPatch(const int iIdxFacet, 
                                   const int iIdxPatch);

  inline int GetFacetTempPatch(const int iIdxFacet) const;


  inline HRESULT SetFacetCost(const int iIdxFacet, 
                              const double iCost);

  inline double GetFacetCost(const int iIdxFacet) const;

  inline HRESULT SetFacetState(const int iIdxFacet,
                               const int iState);

  inline int GetFacetState(const int iIdxFacet) const;


public:
  inline CATPolyIntegerSetPartition* Partition();
  inline CATPolyPriorityQueue* Queue();

private:
  class FacetData
  {
  public:
    FacetData() : _State(0), _Cost(CATMathInfinite), _TempPatch(0){};
  public:
    int _State;
    int _TempPatch;
    double _Cost;
  };
  class Specialize_CATPolyBuckets_T(FacetDataBuckets, FacetData*); 

private:
  inline FacetData* GetFacetData(const int iIdxFacet) const;  
  inline FacetData* GetFacetDataWithAlloc(const int iIdxFacet);

private:
  FacetDataBuckets _FacetDatas;
  CATPolyIntegerSetPartition* _Partition;
  CATPolyIntegerSetPartition* _NewPartition;

  CATPolyPartitionManager* _PartitionManager;

private:
  CATPolyPriorityQueue* _Queue; 
};

//INLINE

inline CATBoolean CATPolyFacetsPropagation::IsFacetAvailable(int iIdxFacet)
{
  if (_PartitionManager)
    return _PartitionManager->IsElementAvailable(iIdxFacet);
  return 0;
}

inline HRESULT CATPolyFacetsPropagation::GetPatch(int iIdxPatch, CATPolyFacetsPatch*& oPatch)
{
  if (_PartitionManager)
    return _PartitionManager->GetPatch(iIdxPatch,(CATPolyElementsPatch*&)oPatch);
  return E_FAIL;
}

inline int CATPolyFacetsPropagation::GetNbPatchs()
{
  if (_PartitionManager)
    return _PartitionManager->GetNbPatchs();
  return 0;
}

inline int CATPolyFacetsPropagation::GetFacetPatch(int iIdxFacet)
{
  HRESULT hr = E_FAIL;
  int oIdxPatch=0;

  if (_PartitionManager)
    _PartitionManager->GetElementPatch(iIdxFacet, oIdxPatch);

  return oIdxPatch;
}

inline HRESULT CATPolyFacetsPropagation::AddFacetToPatch(int iIdxFacet, int iIdxPatch)
{
  if (_PartitionManager)
    return _PartitionManager->AddElementToPatch(iIdxFacet, iIdxPatch);
  return E_FAIL;
}

inline HRESULT CATPolyFacetsPropagation::RemoveFacetFromPatch(int iIdxFacet, int iIdxPatch)
{
  if (_PartitionManager)
    return _PartitionManager->RemoveElementFromPatch(iIdxFacet, iIdxPatch);
  return E_FAIL;
}

inline HRESULT CATPolyFacetsPropagation::EmptyPatch( int iIdxPatch)
{
  if (_PartitionManager)
    return _PartitionManager->EmptyPatch(iIdxPatch);
  return E_FAIL;
}

inline CATPolyIntegerSetPartition* CATPolyFacetsPropagation::Partition()
{
  return _Partition;
}
inline CATPolyPriorityQueue* CATPolyFacetsPropagation::Queue()
{
  return _Queue;
}

inline HRESULT CATPolyFacetsPropagation::EmptyFacetDatas()
{
  int numFacet=0;
  for (numFacet=1; numFacet<=(int)_FacetDatas.Size();++numFacet)
  {
    FacetData* facetData = _FacetDatas[numFacet];
    if (facetData)
      delete facetData;
  }
  _FacetDatas.Clear();
  return S_OK;
}
 
inline CATPolyFacetsPropagation::FacetData* CATPolyFacetsPropagation::GetFacetData(const int iIdxFacet) const
{
  if (iIdxFacet>=1 && iIdxFacet<=(int)_FacetDatas.Size())
    return _FacetDatas[iIdxFacet];
  
  return NULL;
}
 
inline CATPolyFacetsPropagation::FacetData* CATPolyFacetsPropagation::GetFacetDataWithAlloc(const int iIdxFacet)
{
  int maxSize = _FacetDatas.Size ();
  
  while (maxSize < iIdxFacet)
    maxSize = _FacetDatas.PushBack (0);

  FacetData* facetData = _FacetDatas[iIdxFacet];
  if (!facetData)
  {
    facetData = new FacetData();
    _FacetDatas[iIdxFacet] = facetData;
  }
  return facetData;
}

inline HRESULT CATPolyFacetsPropagation::SetFacetCost(const int iIdxFacet,
                                                      const double iCost)
{
  HRESULT hr = E_FAIL;

  FacetData* facetData = GetFacetDataWithAlloc(iIdxFacet);
  if (facetData)
  {
    facetData->_Cost = iCost;
    hr = S_OK;
  }
  
  return hr;
}
inline double CATPolyFacetsPropagation::GetFacetCost(const int iIdxFacet)const
{
  double cost = CATMathInfinite;

  FacetData* facetData = GetFacetData(iIdxFacet);
  if (facetData)
    cost = facetData->_Cost;

  return cost;
}

inline HRESULT CATPolyFacetsPropagation::SetFacetState(const int iIdxFacet, 
                                                       const int iState)
{
  HRESULT hr = E_FAIL;

  FacetData* facetData = GetFacetDataWithAlloc(iIdxFacet);
  if (facetData)
  {
    facetData->_State = iState;
    hr = S_OK;
  }
  
  return hr;

}

inline int CATPolyFacetsPropagation::GetFacetState(const int iIdxFacet)const 
{
  int state = 0;

  FacetData* facetData = GetFacetData(iIdxFacet);
  if (facetData)
    state = facetData->_State;

  return state;
}

inline HRESULT CATPolyFacetsPropagation::SetFacetTempPatch(const int iIdxFacet, 
                                                           const int iTempPatch)
{
  HRESULT hr = E_FAIL;

  FacetData* facetData = GetFacetDataWithAlloc(iIdxFacet);
  if (facetData)
  {
    facetData->_TempPatch = iTempPatch;
    hr = S_OK;
  }
  
  return hr;

}

inline int CATPolyFacetsPropagation::GetFacetTempPatch(const int iIdxFacet)const 
{
  int tempPatch = 0;

  FacetData* facetData = GetFacetData(iIdxFacet);
  if (facetData)
    tempPatch = facetData->_TempPatch;

  return tempPatch;
}


#endif
