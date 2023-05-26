// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPriorityQueue2.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Aug 2007  Creation: ZFI
//===================================================================

#ifndef CATPolyPriorityQueue2_H
#define CATPolyPriorityQueue2_H

#include "CATPolySegmentOperators.h"
#include "CATPolyBuckets_T.h"
#include "CATErrorDef.h"
#include "CATBucketsOfInt.h"
#include "CATMathLimits.h"
#include "CATMapOfIntToInt.h"

class ExportedByCATPolySegmentOperators CATPolyPriorityQueue2 
{
public:
  //consttrcutor and destrcutor
  CATPolyPriorityQueue2();
  virtual ~CATPolyPriorityQueue2();

public:
  HRESULT Add(const int iIndex, const int iIdxSubset, const double iCost);
  HRESULT Remove(const int iIndex, const int iIdxSubset);
  HRESULT GetMin(int& oIndex ,int& oIdxSubset, double & oCost)const;
  HRESULT Update(const int iIndex,const int iIdxSubset, const double iCost);
  HRESULT RemoveAll();

  HRESULT GetItemIndices(int iIdxItem, int& oIndex, int& oIdxSubset); //replace by iterator
  int Size();

private:
  HRESULT SwapItems(const int iIdxItem1, const int iIdxItem2);
  HRESULT AddItem(int& oIdxItem);
  HRESULT UpdateItem(const int iIdxItem,const int iIndex,const int iIdxSubset, const double iCost);
  HRESULT RemoveItem(const int iIdxItem);
  HRESULT UpdateItemParent(const int iIdxItem);
  HRESULT UpdateItemChildren(const int iIdxItem);
  int CompareItems (const int iIdxItem1, const int iIdxItem2) const;

private:
  inline int GetItemIndex(const int iIndex, const int iIdxSubet) const;
  inline HRESULT SetItemIndex(const int iIndex, const int iIdxSubet, const int iIdxItem);

private:
  class Item
  {  
  public:
    Item() : _Index(0),_Subset(0),_Cost(CATMathInfinite) {}

  public:
    int _Index;
    int _Subset;
    double _Cost;
  };

  class Specialize_CATPolyBuckets_T(ItemsBuckets, Item); 
  class Specialize_CATPolyBuckets_T(IndicesBuckets, CATMapOfIntToInt*); 

private:
  ItemsBuckets _Items;
  IndicesBuckets _Indices;
  int _LastIdxItem;
};

//inline
inline int CATPolyPriorityQueue2::GetItemIndex(const int iIndex, const int iIdxSubet) const
{
  int result=0;
  if (iIndex>=1 && iIndex <= (int)_Indices.Size())
  {
    CATMapOfIntToInt* mapToIdxItem = (CATMapOfIntToInt*)_Indices[iIndex];
    if (mapToIdxItem)
      mapToIdxItem->Locate(iIdxSubet, result);
  }
  return result;

}

inline HRESULT CATPolyPriorityQueue2::SetItemIndex(const int iIndex, const int iIdxSubet, const int iIdxItem)
{
  if (iIndex<1)
    return E_FAIL;

  int maxSize = _Indices.Size ();
  while (maxSize < iIndex)
    maxSize = _Indices.PushBack (0);

  if (iIndex>=1 && iIndex <= maxSize)
  {
    CATMapOfIntToInt* mapToIdxItem = (CATMapOfIntToInt*)_Indices[iIndex];
    if (!mapToIdxItem)
    {
      mapToIdxItem = new CATMapOfIntToInt();
      _Indices[iIndex] = mapToIdxItem;
    }
    if (mapToIdxItem)
    {
      int idxItem=0;
      if (mapToIdxItem->Update(iIdxSubet, iIdxItem)!=S_OK)
        mapToIdxItem->Insert(iIdxSubet,iIdxItem);
    }
  }
  return S_OK;
}

#endif
