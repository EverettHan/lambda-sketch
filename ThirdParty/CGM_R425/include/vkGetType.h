/**
@file

Template class to get predefined types 
in a easier way (vkGetType<uint8>() return the appropriate vkType

@COPYRIGHT

@author Romain Sididris
*/
#if !defined(__vkGetType_h)
#define __vkGetType_h

#if !defined(__vkKernelLib_h)
#include "vkKernelLib.h"
#endif

#if !defined(__vkType_h)
#include "vkType.h"
#endif

namespace VKernel
{

template <class T>
VK_INLINE const vkType* vkGetType(vkCtx iCtx)
{
	return T::s_Type[iCtx];
}


template <class T>
VK_INLINE const vkType* vkGetWeakPointerType(vkCtx iCtx)
{
	return T::s_Type[iCtx]->GetQualifiedType(vkType::fPointer);
}

template <class T>
VK_INLINE const vkType* vkGetPtrType(vkCtx iCtx)
{
	return T::s_TypePtr[iCtx];
}

template <>
VK_INLINE const vkType* vkGetType<uint8>(vkCtx iCtx) {	return vkUint8::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<int8>(vkCtx iCtx) {	return vkInt8::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<uint16>(vkCtx iCtx) {	return vkUint16::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<int16>(vkCtx iCtx) {	return vkInt16::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<uint32>(vkCtx iCtx) {	return vkUint32::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<int32>(vkCtx iCtx) {	return vkInt32::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<uint64>(vkCtx iCtx) {	return vkUint64::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<int64>(vkCtx iCtx) {	return vkInt64::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<bool>(vkCtx iCtx) {	return vkBool::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<float>(vkCtx iCtx) {	return vkFloat::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<double>(vkCtx iCtx) {	return vkDouble::s_Type[iCtx]; };
template <>
VK_INLINE const vkType* vkGetType<void>(vkCtx iCtx) {	return vkVoid::s_Type[iCtx]; };



template <class T>
class vkGetTypeClass
{
public:
	static const vkType* GetType(vkCtx iCtx)
	{
		return vkGetType<T>(iCtx);
	}
};

// Please ask tristan if this don't compile on exotic compilers ;-)
template <class T>
class vkGetTypeClass<const T*>
{
public:
	static const vkType* GetType(vkCtx iCtx)
	{
		return vkGetType<T>(iCtx)->GetWeakPointerType();
	}
};
template <class T>
class vkGetTypeClass<T*>
{
public:
	static const vkType* GetType(vkCtx iCtx)
	{
		return vkGetType<T>(iCtx)->GetWeakPointerType();
	}
};

template <class T>
class vkGetTypeClass<vkRefPtr<T> >
{
public:
	static const vkType* GetType(vkCtx iCtx)
	{
		return vkGetPtrType<T>(iCtx);
	}
};

template <class T>
class vkGetTypeClass<vkSmartPtr<T> >
{
public:
	static const vkType* GetType(vkCtx iCtx)
	{
		return vkGetPtrType<T>(iCtx);
	}
};

template <class T>
class vkGetTypeClass<vkArray<T> >
{
public:
	static const vkType* GetType(vkCtx iCtx)
	{
		return vkGetTypeClass<T>::GetType(iCtx)->GetDynArrayType();
	}
};

template <>
class vkGetTypeClass<int32>
{
public:
	static const vkType* GetType(vkCtx iCtx)
	{
		return vkGetType<int32>(iCtx);
	}
};
/*
static void Test()
{
	vkGetTypeClass<vkRefPtrObjectPtr >::GetType(0);
	vkGetTypeClass<vkResourcePtr >::GetType(0);
	vkGetTypeClass<vkResource>::GetType(0);
	vkGetTypeClass<vkArray<uint32> >::GetType(0);
	vkGetTypeClass<vkArray<vkResourcePtr> >::GetType(0);
}*/

} // Namespace VKernel

#endif // __vkGetType_h


