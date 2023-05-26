

#if !defined(__vkMutex_hpp)
#define __vkMutex_hpp

namespace VKernel
{

VK_INLINE vkMutex::Lock::Lock(vkMutex& iMutex)
: m_Mutex(iMutex)
{
	m_Mutex.Acquire();
}

VK_INLINE vkMutex::Lock::~Lock()
{
	m_Mutex.Release();
}

template <typename T>
vkLockPtr<T>::vkLockPtr(volatile T& iObj,volatile vkMutex& iMutex)
: m_Obj(const_cast<T&>(iObj)),m_Mutex(const_cast<vkMutex&>(iMutex))
{
	m_Mutex.Acquire();
}

template <typename T>
vkLockPtr<T>::~vkLockPtr()
{
	m_Mutex.Release();
}

template <typename T>
T&
vkLockPtr<T>::operator*()
{
	return m_Obj;
}

template <typename T>
T*
vkLockPtr<T>::operator->()
{
	return &m_Obj;
}

template <typename T>
vkConstLockPtr<T>::vkConstLockPtr(volatile const T& iObj,volatile const vkMutex& iMutex)
: m_Obj(const_cast<T&>(iObj)),m_Mutex(const_cast<vkMutex&>(iMutex))
{
	m_Mutex.Acquire();
}

template <typename T>
vkConstLockPtr<T>::~vkConstLockPtr()
{
	m_Mutex.Release();
}

template <typename T>
const T&
vkConstLockPtr<T>::operator*()
{
	return m_Obj;
}

template <typename T>
const T*
vkConstLockPtr<T>::operator->()
{
	return &m_Obj;
}

}

#endif // __vkMutex_hpp



