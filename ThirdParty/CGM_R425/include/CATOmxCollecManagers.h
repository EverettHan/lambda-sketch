#ifndef CATOmxManagers_H
#define CATOmxManagers_H

#include "CATOmxKernel.h" 
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxStaticAssert.h"
#include "CATOmxPortability.h"

/**
 * A manager that is really COM compliant
 * The difference with com_manager is that Hash & Compare use "implementation" pointer (the object returned by QueryInterface(IID_IUnknown))
 */
extern ExportedByCATOmxKernel CATOmxCollecManager& genuine_com_manager();

/**
 * A manager compliant with CATBaseUnknown comparison protocol.
 * The difference with com_manager is that Hash & Compare use "implementation" pointer (the object returned by GetImpl())
 * Use only on CATBaseUnknown derived classes
 */
extern ExportedByCATOmxKernel CATOmxCollecManager& cbu_manager();

/** internals */
template<size_t sizeOf> CATOmxCollecManager& _enum_manager();
template<> inline CATOmxCollecManager& _enum_manager<sizeof(char)>() { return CATOmxDefaultCollecManager<char>::manager(); }
template<> inline CATOmxCollecManager& _enum_manager<sizeof(short)>() { return CATOmxDefaultCollecManager<short>::manager(); }
template<> inline CATOmxCollecManager& _enum_manager<sizeof(int)>() { return CATOmxDefaultCollecManager<int>::manager(); }
template<> inline CATOmxCollecManager& _enum_manager<sizeof(CATLONG64)>() { return CATOmxDefaultCollecManager<CATLONG64>::manager(); }

/**
 * A generic manager for enum types
 * Warning: do not use directly as a collection manager (eg: CATOmxArray<XXX,enum_manager<XXX> >)
 * because it might cause compilation "non-type template argument refers to function 'enum_manager<XXX>' that does not have linkage" with clang
 */
template<typename EnumType>
inline CATOmxCollecManager& enum_manager()
{
  OMX_STATIC_ASSERT(std::is_enum<EnumType>::value, "illegal usage");
  return _enum_manager<sizeof(EnumType)>();
}


template<class T> class CATOmxSR;

//specialization of CATOmxDefaultCollecManager for CATOmxSR
template<class T>
struct CATOmxDefaultCollecManager<CATOmxSR<T> >
{
  static CATOmxCollecManager& manager() { return CATOmxDefaultCollecManager<T*>::manager(); }
};

template<class T> class CATOmxQIPtr;

//specialization of CATOmxDefaultCollecManager for CATOmxQIPtr
template<class T>
struct CATOmxDefaultCollecManager<CATOmxQIPtr<T> >
{
  static CATOmxCollecManager& manager() { return CATOmxDefaultCollecManager<T*>::manager(); }
};

extern ExportedByCATOmxKernel CATOmxCollecManager& vector_manager();
template<class T> class CATOmxVector;

//specialization of CATOmxDefaultCollecManager for CATOmxVector
template<class T>
struct CATOmxDefaultCollecManager<CATOmxVector<T> >
{
  static CATOmxCollecManager& manager() { return vector_manager(); }
};

template<class T> class CATOmxList;

//specialization of CATOmxDefaultCollecManager for CATOmxList
template<class T>
struct CATOmxDefaultCollecManager<CATOmxList<T> >
{
  static CATOmxCollecManager& manager() { return vector_manager(); }
};

template<class T, CATOmxCollecManagerLocator TMgr> class CATOmxSet;
ExportedByCATOmxKernel CATOmxCollecManager& com_set_manager();
ExportedByCATOmxKernel CATOmxCollecManager& naive_set_manager();
ExportedByCATOmxKernel CATOmxCollecManager& sharable_set_manager();
ExportedByCATOmxKernel CATOmxCollecManager& com_ordered_set_manager();
ExportedByCATOmxKernel CATOmxCollecManager& naive_ordered_set_manager();
ExportedByCATOmxKernel CATOmxCollecManager& sharable_ordered_set_manager();

//specialization of CATOmxDefaultCollecManager for CATOmxSet<T, naive_manager>
template<class T>
struct CATOmxDefaultCollecManager<CATOmxSet<T, naive_manager> >
{
  static CATOmxCollecManager& manager() { return naive_set_manager(); }
};

//specialization of CATOmxDefaultCollecManager for CATOmxSet<T, com_manager>
template<class T>
struct CATOmxDefaultCollecManager<CATOmxSet<T, com_manager> >
{
  static CATOmxCollecManager& manager() { return com_set_manager(); }
};

//specialization of CATOmxDefaultCollecManager for CATOmxSet<T, sharable_manager>
template<class T>
struct CATOmxDefaultCollecManager<CATOmxSet<T, sharable_manager> >
{
  static CATOmxCollecManager& manager() { return sharable_set_manager(); }
};

template<class T, CATOmxCollecManagerLocator TMgr> class CATOmxOrderedSet;

//specialization of CATOmxDefaultCollecManager for CATOmxOrderedSet<T, naive_manager>
template<class T>
struct CATOmxDefaultCollecManager<CATOmxOrderedSet<T, naive_manager> >
{
  static CATOmxCollecManager& manager() { return naive_ordered_set_manager(); }
};

//specialization of CATOmxDefaultCollecManager for CATOmxOrderedSet<T, com_manager>
template<class T>
struct CATOmxDefaultCollecManager<CATOmxOrderedSet<T, com_manager> >
{
  static CATOmxCollecManager& manager() { return com_ordered_set_manager(); }
};

//specialization of CATOmxDefaultCollecManager for CATOmxOrderedSet<T, sharable_manager>
template<class T>
struct CATOmxDefaultCollecManager<CATOmxOrderedSet<T, sharable_manager> >
{
  static CATOmxCollecManager& manager() { return sharable_ordered_set_manager(); }
};

#endif
