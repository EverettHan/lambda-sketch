#ifndef __CATOmbListMembers_H
#define __CATOmbListMembers_H

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATOmxIter.h"

/**
 * not typed sub method, do not call
 */
ExportedByAC0XXLNK CATOmxBaseIter* CATOmbBaseListMembers(const CATBaseUnknown* iCont,const char* iItfID);

/**
 * wrapper on CATIContainer::ListMembersHere horrible method
 */
template<class T>
inline CATOmxIter<T> CATOmbListMembers(const CATBaseUnknown* iCont,const T* dummyArgument=NULL)
{
  return CATOmxIter<T>(CATOmbBaseListMembers(iCont,T::ClassName()));
}

#endif

