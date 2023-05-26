// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfBVHNodesToAttributes.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Mar 2009 Creation: JXO, derived from CATMapOfPtrToPtr
//===================================================================
#ifndef CATMapOfBVHNodesToAttributes_h
#define CATMapOfBVHNodesToAttributes_h

#include "PolyBVH.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfPtrToPtr.h"

class CATBVHNode;
class CATPolyBVHTreeNodePositionedBoxesAttribute;


class ExportedByPolyBVH CATMapOfBVHNodesToAttributes : public CATMapOfPtrToPtr
{

public:

  CATMapOfBVHNodesToAttributes () {}
  ~CATMapOfBVHNodesToAttributes () {}

public:

  inline HRESULT Insert (CATBVHNode * key, CATPolyBVHTreeNodePositionedBoxesAttribute * data);
  inline CATBoolean Locate (CATBVHNode * key, CATPolyBVHTreeNodePositionedBoxesAttribute *& data) const;
  inline HRESULT Remove (CATBVHNode * key);

  inline HRESULT Update (CATBVHNode * key, CATPolyBVHTreeNodePositionedBoxesAttribute * data);

};


inline HRESULT CATMapOfBVHNodesToAttributes::Insert (CATBVHNode * key, CATPolyBVHTreeNodePositionedBoxesAttribute * data)
{
  return CATMapOfPtrToPtr::Insert(key, (void*)data);
}

inline CATBoolean CATMapOfBVHNodesToAttributes::Locate (CATBVHNode * key, CATPolyBVHTreeNodePositionedBoxesAttribute *& value) const
{
  return CATMapOfPtrToPtr::Locate(key, (void*&)value);
}

inline HRESULT CATMapOfBVHNodesToAttributes::Remove (CATBVHNode * key)
{
  return CATMapOfPtrToPtr::Remove(key);
}

inline HRESULT CATMapOfBVHNodesToAttributes::Update (CATBVHNode * key, CATPolyBVHTreeNodePositionedBoxesAttribute * data)
{
  return CATMapOfPtrToPtr::Update(key, (void*)data);
}

#endif
