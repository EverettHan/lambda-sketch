/**
@file

Base class for all contexts.

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkContext_h)
#define __vkContext_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkKernelTypes_h)
	#include "vkKernelTypes.h"
#endif


#if !defined(__vkError_h)
	#include "vkError.h"
#endif
#if !defined(__vkCtxObject_h)
	#include "vkCtxObject.h"
#endif
#if !defined(__vkString_h)
	#include "vkString.h"
#endif
#if !defined(__vkEventsChannel_h)
	#include "vkEventsChannel.h"
#endif

#include <mutex>

namespace VKernel
{
	class vkContext;
}

#define VK_DECLARE_CTXSINGLETON(TCtxSingleton)		\
	public:\
	static TCtxSingleton&	Instance(vkCtx iCtxHandle) \
{VKASSERT(iCtxHandle >= 0); return *s_Singleton[iCtxHandle];} \
	static TCtxSingleton*	InstancePtr(vkCtx iCtxHandle) \
{VKASSERT(iCtxHandle >= 0); return s_Singleton[iCtxHandle];} \
	static TCtxSingleton*	InstancePtr(vkContext* iContext) \
{return (iContext != 0) ? s_Singleton[iContext->GetCtx()] : 0;}\
	static bool				IsValid(vkCtx iCtxHandle) \
{return (s_Singleton[iCtxHandle] != 0);} \
	static error			RegisterSingleton(vkCtx iCtxHandle, TCtxSingleton* iInstance)\
{VKASSERT((s_Singleton[iCtxHandle] == 0) && (iInstance != 0)); s_Singleton[iCtxHandle] = iInstance;\
	return (s_Singleton[iCtxHandle] != 0) ? errOk : errOutOfMemory;}\
	static error			UnregisterSingleton(vkCtx iCtxHandle)\
{VKASSERT(s_Singleton[iCtxHandle] != 0); s_Singleton[iCtxHandle] = 0; return errOk;}\
	protected:	static vkCtxObject<TCtxSingleton*> s_Singleton;\
	public:\
	
#define VK_IMPLEMENT_CTXSINGLETON(TCtxSingleton)	vkCtxObject<TCtxSingleton*> TCtxSingleton::s_Singleton;

#define VK_DECLARE_CTXSINGLETONCONCRETE(TCtxSingleton) \
	VK_DECLARE_CTXSINGLETON(TCtxSingleton); \
	public:\
	static error		CreateSingleton(vkCtx iCtxHandle)\
	{TCtxSingleton* s =  new TCtxSingleton(iCtxHandle); if (s == 0) return errOutOfMemory;\
		return RegisterSingleton(iCtxHandle, s);}\
	static error		DeleteSingleton(vkCtx iCtxHandle){\
		TCtxSingleton* s = InstancePtr(iCtxHandle); \
		if (s != 0) { \
			VKASSERT(s->GetCtx() == iCtxHandle); \
			delete s; return UnregisterSingleton(iCtxHandle); \
		} \
		return errOk; } 
	
#define VK_IMPLEMENT_CTXSINGLETONCONCRETE(TCtxSingleton)	vkCtxObject<TCtxSingleton*> TCtxSingleton::s_Singleton;

#define VK_DECLARE_CTXCONSTRUCTOR(Class) \
	Class(vkCtx iCtx) : ParentClass(iCtx) {} \


namespace VKernel
{
	class VKKERNEL_API vkContextedObject
	{
	public:
		vkContextedObject(vkCtx iCtx);

		vkCtx		GetCtx() const;
		vkContext*	GetContext() const;

	private:
#if defined(VK_MULTIPLE_CONTEXTS)
		vkCtxVariable m_Ctx;
#endif
	};

	class vkEventsListener;

	/**
	Base class for all contexts. A context is an object giving access
	to singleton objects. It's also considered as a singleton of itself !
	*/
	class VKKERNEL_API vkContext : public vkStdHeapObject, public vkContextedObject
	{
		VK_DECLARE_CTXSINGLETON(vkContext);
	public:
		/**
		Constructor.
		*/
		vkContext(vkCtx iCtx, const vkString& iID = VK_NS);
		~vkContext();

		static uint32		GetContextCount();
		static vkCtx		CreateContext(const vkString& iID = VK_NS, bool iCopyMainParametersFromMainCtx = true);
		static void			DeleteContext(vkCtx iCtx);
		
		static void			RegisterContextListener(vkEventsListener* iListener);
		static void			UnregisterContextListener(vkEventsListener* iListener);

	private :
		friend class vkCtxObjectBase;

		static vkEventsChannel m_ContextEventsChannel;
		vkString	m_ID;	
	};

	////////////////////////////////////////////////////////////////////////////////
#if !defined(VK_MULTIPLE_CONTEXTS)
	VK_INLINE uint32	
	vkContext::GetContextCount()
	{
		return 1;
	}
#endif

	VK_INLINE vkContextedObject::vkContextedObject(vkCtx iCtx)
	{
#if defined(VK_MULTIPLE_CONTEXTS)
		m_Ctx = iCtx;
#else
		VKASSERT(iCtx == kMainCtx);
#endif
	}

	VK_INLINE vkCtx
	vkContextedObject::GetCtx() const
	{
#if defined(VK_MULTIPLE_CONTEXTS)
		return m_Ctx;
#else
		return kMainCtx;
#endif
	}


} // namespace VKernel

#endif // __vkContext_h

