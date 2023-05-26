// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyElementsPatch.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// June 2008  Creation: ZFI
//===================================================================


#ifndef CATPolyElementsPatch_H
#define CATPolyElementsPatch_H

#include "CATPolySegmentCommon.h"

#include "CATErrorDef.h"

#include "CATListOfInt.h"
#include "CATIPolyIntIterator.h"
#include "CATPolyDoublyLinkedList_T.h"


class ExportedByCATPolySegmentCommon CATPolyElementsPatch
{
public:
  //constrcutor destructor
  CATPolyElementsPatch();
  virtual ~CATPolyElementsPatch();

  HRESULT GetElementsIterator(CATIPolyIntIterator*& oIter) const;
  int GetNbElements()const;

  //facets management
  virtual HRESULT AddElement(int iIdxVertex);
  virtual HRESULT RemoveElement(int iIdxVertex);
  virtual HRESULT RemoveAllElements();

private:
  friend class CATPolyPartitionManager;
  friend class CATPolyCoverManager;

  //index
  HRESULT SetIndex(const int iIndex);
  int GetIndex() const;

protected:
  int _Index;

protected:
  class Specialize_CATPolyDoublyLinkedList_T(IntDoublyLinkedList, int);
  IntDoublyLinkedList _Elements;

private:
  // ELEMENTS ITERATOR
  class PatchElementsIterator : public CATIPolyIntIterator
  {
  public:
    PatchElementsIterator(const IntDoublyLinkedList& iElements);

  public:
    CATIPolyIntIterator& Begin ();
    CATBoolean End () const;
    int Get () const;

  private:
    void Initialize ();

  public:
    int operator* ();
    CATIPolyIntIterator& operator++ ();
  
  private:
    int _NumElement;
    const IntDoublyLinkedList& _Elements;
  };
};

#endif
