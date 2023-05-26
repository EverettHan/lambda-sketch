// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPriorityQueue.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Aug 2007  Creation: ZFI
//===================================================================

#ifndef CATPolyPriorityQueue_H
#define CATPolyPriorityQueue_H

#include "CATPolySegmentOperators.h"
#include "CATPolyBuckets_T.h"
#include "CATErrorDef.h"
#include "CATBucketsOfInt.h"
#include "CATMathLimits.h"

class ExportedByCATPolySegmentOperators CATPolyPriorityQueue 
{
public:
  //consttrcutor and destrcutor
  CATPolyPriorityQueue();
  virtual ~CATPolyPriorityQueue();

public:
  HRESULT Add(const int iIndex, const double iCost);
  HRESULT Remove(const int iIndex);
  HRESULT GetMin(int& oIndex ,double & oCost)const;
  HRESULT Update(const int iIndex,const double iCost);
  HRESULT RemoveAll();

  int GetItemIndex(const int iIdxItem); //replace by iterator
  int Size();

private:
  HRESULT SwapItems(const int iIdxItem1, const int iIdxItem2);
  HRESULT AddItem(int& oIdxItem);
  HRESULT UpdateItem(const int iIdxItem,const int iIndex,const double iCost);
  HRESULT RemoveItem(const int iIdxItem);
  HRESULT UpdateItemParent(const int iIdxItem);
  HRESULT UpdateItemChildren(const int iIdxItem);
  int CompareItems (const int iIdxItem1, const int iIdxItem2) const;

private:
  class Item
  {  
  public:
    Item() : _Index(0),_Cost(CATMathInfinite) {}

  public:
    int _Index;
    double _Cost;
  };

  class Specialize_CATPolyBuckets_T(ItemsBuckets, Item); 

private:
  ItemsBuckets _Items;
  CATBucketsOfInt _Indices;
  int _LastIdxItem;
};

#endif
