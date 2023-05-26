/**
@file

This file defines the vkKernelModule class.

@COPYRIGHT

@author Nicolas Hognon
*/

#if !defined(__vkKernelInit_h)
#define __vkKernelInit_h

#if !defined(__vkKernelLib_h)
#include "vkKernelLib.h"
#endif
#if !defined(__vkModule_h)
#include "vkModule.h"
#endif

namespace VKernel
{
	class vkAssetSerializationContext;

}

#if defined (VK_STATIC)
extern void vkCreateKernelStaticModules(VKernel::vkAssetSerializationContext* iContext);
#endif

/**
Namespace containing all types from the vkKernel library.

The VKernel namespace is the main name of @SDK_NAME. It contains
all bases types (classes, functions, enumerations, ...).
*/
namespace VKernel
{
class vkMainParameters;

/**
This is the class used to initialize the vkKernel module.

This is the module asset for the vkKernel library (see vkModule).
So this class is used to initialize the vkKernel library. But it also contains methods
to control the allocations and the assertion.

The vkKernel module asset must be initialized before all other module asset (and
uninitialized after all other module asset). If you create your executable
linking with the vkStandAlone static library and implementing a #vkMain function
the vkKernel module asset is automatically initialized (uninitiliazed). But as the initialization
is refcounted (to prevent you of any modification in our implementation), it is recommanded
to initialize the vkKernel module asset if you do not depend of another module asset.

To initialize/uninitialize the vkKernel module asset use Init()/Uninit() static method
(as defined by the macro VK_DECLARE_MODULE).

@see vkModule, VK_DECLARE_MODULE, VK_IMPLEMENT_MODULE
*/
class VKKERNEL_API vkKernelModule : public vkModuleBaseClass
{
public:
#if !defined(VK_DOXYGEN)
	VK_DECLARE_MODULE(vkKernelModule, vkModuleBaseClass);
#endif

	/**
	Control the assert behavior.

	This flags are used to control the behavior of the assert macros (VKASSERT and VKCALLASSERT).
	To modify this behavior you have to modify the value on the vkSystem::s_AssertBehavior static variable.
	It is recommended to do this in the vkStartup() function.

	@see s_AssertBehavior, VKASSERT, VKCALLASSERT, vkStartup
	*/
	enum FAssertBehavior
	{
		/** Display a message box if it is possible on the platform and log an error, else simply log an error without breaking on a breakpoint.*/
		fNormal				= 0x00000000,

		/** Simply log an error. Breaking on a breakpoint depend on the flag fBreakWhenNoDialog. */
		fNoDialog			= 0x00000001,

		/**
		The assert does not generate log.
		
		@see vkLog
		*/
		fNoLog				= 0x00000002,

		/**
		Does assert should break in the debugger in fNoDialog ?
		
		If fNoDialog is set or if the system cannot display message box, should we break or not ?
		If fBreakWhenNoDialog is set VK_BREAKPOINT is used else nothing is done.

		@see VK_BREAKPOINT
		*/
		fBreakWhenNoDialog	= 0x00000004,

		/**
		Does assert should add the call stack in the log output?

		Not yet implemented.

		@todo Implement it.
		*/
		fLogCallStack		= 0x00000008,

		fCustomDlg			= 0x00000010
	};

	/**
	Control the assert behavior.

	This static variable is used to control the assert macros behavior. For more information
	see the #FAssertBehavior enum documentation.

	@see FAssertBehavior, VKASSERT, VKCALLASSERT, vkStartup
	*/
	static uint32                         s_AssertBehavior;

	/**
	Sets the allocator functions to overload default heap manager
	behavior.
	
	- this function is to be called before vkKernel module asset is initialized (see #vkStartup)
	- To set the default allocation behavior of the system, call
	with SetAllocatorFunctions(malloc, free, _msize); 

	On systems where _msize is not available, do not specify any TellSize
	function, but do not rely on the vkTellSize function in your program,
	since it will not work.

	@param iAFct the allocation function to use.
	@param iDFct the deallocation function to use.
	@param iTFct the tell size function to use.
	*/
	static void                           SetAllocatorFunctions(vkAllocateFct iAFct, vkDeallocateFct iDFct, vkTellSizeFct iTFct = 0);

	/**
	Sets the size beneath which the object will be allocated in 
	small blocks allocator.
	
	The small blocks are allocated with no overhead by 
	allocation, whereas large blocks have an overhead of 2 or 3 dwords.
	The downside of the small block is that they are allocated by pages
	of vkHeapManager::kSmallPageSize, for each size multiple of 4 bytes. If you have only 
	one object of a given size (say 56 bytes), a whole pool will be allocated 
	for it, loosing (vkHeapManager::kSmallPagePoolSize - 56) bytes in unused space (8ko by default).
	Hence you must carefully set the small block limit to avoid many objects 
	alone in their pool.

	- the limit itself is good to go for a small block.
	- You cannot set a limit higher than vkHeapManager::kSmallPageBlockLimit
	
	@param iSmallBockLimit the small block limit, in bytes.
	*/
	static void                           SetSmallBlockLimit(uint32 iSmallBloclLimit);

	virtual bool                          IsImplicit() {return true;}

	/**
	Tells whether the vkGUI module has been initialized.

	This function is useful for engine modules that need
	to load some GUI data in an authoring context, but 
	do not do that operation at runtime.

	@return TRUE if vkGUI module has been initialized
	*/
	bool                                  IsGUIInitialized() const;

	/**
	Sets the initialization status of vkGUI module.

	Note: this function is for intern use only, and should
	be called only by vkGUI module initialization.

	@param iInitialized true if the vkGUI module is initialized, false else
	*/
	void                                  SetGUIInitialized(bool iInitialized);

#if !defined(VK_DOXYGEN)
	static vkAllocateFct                  s_AllocateFct;
	static vkDeallocateFct                s_DeallocateFct;
	static vkTellSizeFct                  s_TellSizeFct;
	static uint32                         s_SmallBlockLimit;
		
#if defined(VK_TARGET_MACOSX)
	static void*                          s_AutoreleasePool;
#endif
#endif // VK_DOXYGEN


#if defined(VK_MULTIPLE_CONTEXTS)
	static vkCtxObjectBase**              GetCtxObjectsList();
#endif

private:

	// Overriden from vkObject
	virtual void                          _Destroy();

	// Override from vkAsset
	virtual error                         _Load(vkAssetSerializationContext& iContext);

	// Override from vkModule
#if defined(VK_MULTIPLE_CONTEXTS)
	virtual error                         _CreateCtxObjects();
	virtual error                         _DestroyCtxObjects();
#endif

	virtual error                         _CreateContextedSingletons();
	virtual error                         _DestroyContextedSingletons();

	virtual error                         _RegisterAssetFactories();
	virtual error                         _UnregisterAssetFactories();

	// Cannot rely on vkModule::_CreateSingletons and vkModule::_DestroySingletons
	// because vkKernelModule
	static error                          _PreCreateSingletons();
	static error                          _PostDestroySingletons();

	virtual error                         _CreateSingletons();
	virtual error                         _DestroySingletons();


	// new functions
	static void                           _ProcessParameters1(const vkMainParameters& iParams); // called before singleton creation
	
#if defined(VK_TARGET_MACOSX)
	static void _InitCocoaObjects();
	static void                           _DestroyCocoaObjects();
#endif

private:
	bool                                  m_GUIInitialized;

};

} // VKernel

#endif // __vkKernelInit_h


