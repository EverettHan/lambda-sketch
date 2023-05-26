/**
* @level Private
 * @usage U1
 */

#ifndef __CATOmxListPtrHelpers_H
#define __CATOmxListPtrHelpers_H

#include "CATOmxKernel.h"
#include "CATListPV.h"
#include "CATOmxVector.h"
#include "CATOmxStaticAssert.h"

/** Do not use directly, see CATOmxReleaseListPtr*/
ExportedByCATOmxKernel void _CATOmxReleaseListPtr(CATRawCollPV& iListPV);

/** Do not use directly, bypass private inheritance from CATRawCollPV*/
template<class CATListPtrXXX>
inline CATRawCollPV& _CATOmxAsRawCollPV(CATListPtrXXX& list)
{
  OMX_STATIC_ASSERT(std::is_base_of<CATRawCollPV, CATListPtrXXX>::value, "input list must inherit from CATRawCollPV");
  return *(CATRawCollPV*)(void*)&list;
}

/**
 * Clear a CATListPtrXXX (CATLISTP(XXX)) IUnknown derived object collection (Release elements, empty list)
 * Warning CATListPtrType MUST BE a System macro defined horrible CATLISTP
 * Notice that a better option consists in using CATOmxVector/CATOmxList instead
 * Usage:
 * CATListPtrXXX list;
 * list.Append(new XXX);
 * list.Append(new XXX);
 * CATOmxReleaseListPtr(list); //the two allocated items are released, list is emptied
 *
 * you can alternatively use CATListPtrAutoReleaser in some situations
 */
template<class CATListPtrType>
inline void CATOmxReleaseListPtr(CATListPtrType& iListPtr)
{
  if (0) { const IUnknown* item = iListPtr[0]; } //Force compilation error for non IUnkown derived objects
  _CATOmxReleaseListPtr(_CATOmxAsRawCollPV(iListPtr));
}

/** Do not use directly, see CATOmxListPtrToVector*/
ExportedByCATOmxKernel void _CATOmxListPtrToVector(const CATRawCollPV& iList, CATOmxBaseVector& oVect);

/**
 * Build a CATOmxVector from a CATListPtrXXX
 * Warning CATListPtrType MUST BE a System macro defined horrible CATLISTP
 * Notice that a better option consists in using CATOmxVector/CATOmxList instead
 * Usage:
 * CATListPtrXXX list;
 * list.Append(new XXX);
 * list.Append(new XXX);
 * CATOmxVector<XXX> vect;
 * CATOmxListPtrToVector(list,vect); //vect contains the 2 allocated elements (and AddRef's them)
 */
template<class CATListPtrType, class Type>
inline void CATOmxListPtrToVector(const CATListPtrType& iListPtr, CATOmxVector<Type>& oVect)
{
  if (0) { const Type* item = iListPtr[0]; } //Force compilation error if incoherent types
  _CATOmxListPtrToVector(_CATOmxAsRawCollPV(iListPtr), oVect);
}

/** Do not use directly, see CATOmxListPtrToVector*/
ExportedByCATOmxKernel CATOmxBaseIter* _CATOmxListPtrToIterator(const CATRawCollPV& iList);

/**
 * Build a CATOmxVector from a CATListPtrXXX
 * Warning CATListPtrType MUST BE a System macro defined horrible CATLISTP
 * Notice that a better option consists in using CATOmxVector/CATOmxList instead
 * Usage:
 * CATListPtrXXX list;
 * list.Append(new XXX);
 * list.Append(new XXX);
 * CATOmxIter<XXX> iter;
 * CATOmxListPtrToIterator(list,iter); //iter contains the 2 allocated elements (and AddRef's them)
 */
template<class CATListPtrType, class Type>
inline void CATOmxListPtrToIterator(const CATListPtrType& iListPtr, CATOmxIter<Type>& oIter)
{
  if (0) { const Type* item = iListPtr[0]; } //Force compilation error if incoherent types
  oIter = CATOmxIter<Type>(_CATOmxListPtrToIterator(_CATOmxAsRawCollPV(iListPtr)));
}

/** Do not use directly, see CATOmxToListPtr*/
ExportedByCATOmxKernel void _CATOmxToListPtr(CATOmxBaseIter* iIterator, CATRawCollPV& oListPtr);

/**
 * Fills oList with AddRef'ed pointers from iCollection
 * Usage:
 * CATOmxSet<XXX> set;
 * CATListPtrXXX list;
 * CATOmxToListPtr(set,list);
 * //you now have a list of AddRef'ed pointers (do not forget to release it with CATOmxReleaseListPtr)
 *
 * notice that output list is not flushed before being filled
 */
template<class Collection, class CATListPtrXXX>
inline void CATOmxToListPtr(const Collection& iCollection, CATListPtrXXX& oListPtr)
{
  if (0) { const IUnknown* item = oListPtr[0]; (void)item; } //Force compilation error for non IUnkown derived objects
  if (0) oListPtr.Append(iCollection.Iterator().Next()); //Force compilation error if incoherent types
  _CATOmxToListPtr(iCollection.Iterator().PrivateStrip(), _CATOmxAsRawCollPV(oListPtr));
}


#endif
