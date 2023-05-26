/**
@file

This files defines the vkModule class.

@COPYRIGHT

@author Gérald Guyomard
*/

#if !defined(__vkModule_h)
#define __vkModule_h

#if !defined(__vkKernelLib_h)
#include "vkKernelLib.h"
#endif
#if !defined(__vkAsset_h)
#include "vkAsset.h"
#endif



	#if defined(VK_MULTIPLE_CONTEXTS)
		#define VK_DECLARE_GETCTXOBJECTSLIST_METHOD \
			virtual vkCtxObjectBase** _GetCtxObjectsList();

		#define VK_IMPLEMENT_GETCTXOBJECTSLIST_METHOD(NameSpace, ClassName) \
			VKernel::vkCtxObjectBase** NameSpace::ClassName::_GetCtxObjectsList() { return &VKernel::s_LocalCtxObjectList; }

	#else
		#define VK_DECLARE_GETCTXOBJECTSLIST_METHOD
		#define VK_IMPLEMENT_GETCTXOBJECTSLIST_METHOD(NameSpace, ClassName)
	#endif

	#define VK_DECLARE_MODULE(ClassName, SuperClassName) \
	protected:\
		virtual StaticData& _GetStaticData() const; \
		VK_DECLARE_GETCTXOBJECTSLIST_METHOD \
	public:\
		VK_DECLARE_RTTI(ClassName, SuperClassName); \
		static void CreateInstance(vkCtx iCtxHandle, vkModulePtr& oModule, vkAssetSerializationContext* iCtx); \
		static StaticData s_Data; \
		static error Init(vkCtx iContext, vkAsset* iUser = 0);\
		static error Uninit(vkCtx iContext, vkAsset* iUser = 0);\
		static ClassName* InstancePtr(vkCtx iContext);\
		static ClassName& Instance(vkCtx iContext); \
		ClassName(vkCtx iContext); \


#define VK_IMPLEMENT_MODULE_CREATEINSTANCE(NameSpace, ClassName) \
void NameSpace::ClassName::CreateInstance(VKernel::vkCtx iCtxHandle, VKernel::vkModulePtr& oModule, VKernel::vkAssetSerializationContext* iCtx) { \
	oModule = ClassName::s_Data.m_Instances.IsInitialized() ? ClassName::s_Data.m_Instances[iCtxHandle] : 0; \
	if (oModule == 0) { \
		oModule = new ClassName(iCtxHandle); \
		((ClassName*) oModule.Ptr())->_CreateFromStaticLinkage(iCtx); \
	} \
} \

#if defined(VK_STATIC)
// Static EntryPoint


#define VK_IMPLEMENT_MODULE_ENTRYPOINT(NameSpace, ClassName) \
VK_IMPLEMENT_MODULE_CREATEINSTANCE(NameSpace, ClassName) \
	void vkCreateModule_##NameSpace##_##ClassName(VKernel::vkCtx iCtx, VKernel::vkAssetSerializationContext* iContext, VKernel::vkModulePtr& oModule) { \
	NameSpace::ClassName::CreateInstance(iCtx, oModule, iContext); \
} \


#define VK_CREATE_STATIC_MODULE(NameSpace, ClassName, ctxHandle, serializationContext, oModule) \
	extern void vkCreateModule_##NameSpace##_##ClassName(VKernel::vkCtx iCtx, VKernel::vkAssetSerializationContext* iContext, VKernel::vkModulePtr& oModule); \
	vkCreateModule_##NameSpace##_##ClassName(ctxHandle, serializationContext, oModule);

#else

// Dynamic Entry Point
#define VK_IMPLEMENT_MODULE_ENTRYPOINT(NameSpace, ClassName) \
	namespace VKernel { vkCtxObjectBase* s_LocalCtxObjectList = 0; vkRTTI* s_LocalRTTIList = 0; }\
VK_IMPLEMENT_MODULE_CREATEINSTANCE(NameSpace, ClassName) \
VK_PLUGIN_EXPORT void vkCreateModule(VKernel::vkCtx iCtx, VKernel::vkDynamicModulePtr& oModule) { \
	oModule = NameSpace::ClassName::s_Data.m_Instances.IsInitialized() ? VKernel::vkDynamicModule::StaticCast(NameSpace::ClassName::s_Data.m_Instances[iCtx]) : 0; \
	if (oModule == 0) {\
		oModule = new NameSpace::ClassName(iCtx);\
	} \
}\

#endif

	#define VK_IMPLEMENT_MODULE_ACCESSORS(NameSpace, ClassName) \
		VKernel::vkModule::StaticData NameSpace::ClassName::s_Data; \
		VKernel::vkModule::StaticData& NameSpace::ClassName::_GetStaticData() const { return ClassName::s_Data; } \
		VK_IMPLEMENT_GETCTXOBJECTSLIST_METHOD(NameSpace, ClassName) \
		NameSpace::ClassName::ClassName(VKernel::vkCtx iCtx, VKernel::vkManifest* iManifest) : ParentClass(iCtx, iManifest) {} \
		VKernel::error NameSpace::ClassName::Init(VKernel::vkCtx iContext, VKernel::vkAsset* iUser) {\
			ClassName* instance = ClassName::s_Data.m_Instances.IsInitialized() ? (ClassName*) ClassName::s_Data.m_Instances[iContext] : 0; \
			if (instance == 0) {\
				instance = new ClassName(iContext);\
				instance->_AddUse(iUser); \
				return instance->_LoadModule(VK_AS(QUOTE(ClassName)));\
			} else {\
				instance->_AddUse(iUser); \
				return instance->_GetLastError();\
			} \
		}\
		VKernel::error NameSpace::ClassName::Uninit(VKernel::vkCtx iContext, VKernel::vkAsset* iUser) {\
			ClassName* module = (ClassName*) ClassName::s_Data.m_Instances[iContext]; \
			if (module != 0) { \
				module->_ReleaseUse(iUser); \
			} \
			return errOk; \
		}\
		NameSpace::ClassName* NameSpace::ClassName::InstancePtr(VKernel::vkCtx iContext)\
		{\
		return s_Data.m_Instances.IsInitialized() ? ((ClassName*) s_Data.m_Instances[iContext]) : 0;\
		}\
		NameSpace::ClassName& NameSpace::ClassName::Instance(VKernel::vkCtx iContext)\
		{\
			return (ClassName&) (*s_Data.m_Instances[iContext]);\
		}

	#define VK_IMPLEMENT_MODULE(NameSpace, ClassName) \
		VK_IMPLEMENT_RTTI(NameSpace::ClassName) \
		VK_IMPLEMENT_MODULE_ENTRYPOINT(NameSpace, ClassName) \
		VK_IMPLEMENT_MODULE_ACCESSORS(NameSpace, ClassName)


namespace VKernel
{
	// private
	class vkCtxObjectBase;
	extern vkCtxObjectBase* s_LocalCtxObjectList;


	class vkModule;
	typedef vkRefPtr<vkModule> vkModulePtr;

#define VK_MODULE_EXTENSION "vkModule"
#define VK_MODULE_EXTENSION_FILTER "*." VK_MODULE_EXTENSION

	/**
	The module asset is a special kind of asset representing a module
	on disk (ex : vkKernel, vkMath) which is used to initialize a library.

	For any non-module shared modules (i.e. plugin), derive from this class to properly handle
	intialization, creation and destruction of data and resources owned by modules.

	To intialize/unitialize a module asset simply call MyModuleInit::Init() and MyModuleInit::Uninit() (do not
	forget to use #VK_DECLARE_MODULE and #VK_IMPLEMENT_MODULE).

	<b>The initialization process</b>: The asset is initialized (vkAsset::Initialize). During
	the initialization, _Construct() is called. The default implementation of _Create() calls:
		- _CreateContextedSingletons()
		- _RegisterResourceCategories()
		- _RegisterTypes()
		- _RegisterAssetFactories()

	<b>The uninitialization process</b>: The asset is destroyed (vkRefPtrObject::Destroy). During
	the destruction, _Destroy() is called. The default implementation of _Destroy() calls:
		- _UnregisterAssetFactories()
		- _UnregisterResourceCategories()
		- _DestroyContextedSingletons()

	During its initialization (uninitialization), the module should initialize (uninitialize) other module
	assert it depends on.

	Here is sample of a simple implementation of a module asset:

	@code
	////////////////////////////////////////
	// in MyModule.h

	class MyModule : public vkModuleBaseClass
	{
	public:
		VK_DECLARE_MODULE(MyModuleInit, vkModuleBaseClass);
	
		// Override from vkModule
		virtual error _CreateContextedSingletons();
		virtual error _DestroyContextedSingletons();
		virtual error _RegisterTypes(vkTypeManager& iTm);

	};

	////////////////////////////////////////
	// in MyModule.cpp

	VK_IMPLEMENT_MODULE(MyModuleInit)

	error MyModuleInit::_CreateContextedSingletons()
	{
		// initialize the vkKernel module asset
		VK_RETURN_IF_FAILED(vkKernelModule::Init());

		// initialize module singleton
		VK_RETURN_IF_FAILED(MySingleton::_Initialize());

		// initialize static data
		MyClass::EnableFunctionality(true);

		return errOk;
	}

	error MyModuleInit::_DestroyContextedSingletons()
	{
		ReleaseStaticData();

		// uninitialize the vkKernel module asset
		return vkKernelModule::Uninit();
	}

	error MyModuleInit::_RegisterTypes(vkTypeManager& iTm)
	{
		iTm.BeginClass("MyType",VK_NS,sizeof(MyType));
		iTm.DeclareMember(VK_AS("x"), vkFloat::s_Type);
		iTm.DeclareMember(VK_AS("y"), vkFloat::s_Type);
		iTm.DeclareMember(VK_AS("z"), vkFloat::s_Type);
		MyType::s_Type = iTm.EndClass();

		return errOk;
	}
	@endcode

	@ingroup grp_resource
	*/
	class VKKERNEL_API vkModule : public vkAsset
	{
	public:
#if !defined(VK_DOXYGEN)
		VK_DECLARE_RTTI(vkModule, vkAsset);
#endif
		/** Default constructor.\ Internal data are initiliazed. */
		vkModule(vkCtx iCtx);

		// Overridden from vkObject
		virtual void                      Destroy();

		/**
		Gets the name of this module.
		Name is simply the filename of the file storing this module.
		@return the name
		*/
		vkString                          GetName() const;

		/**
		Gets the number of times static init where called.
		Automatically implemented by VK_DECLARE_MODULE
		*/
		int32&                            GetStaticInitCount() const;

		/**
		Tells that we are currently for the first time
		in static inits.
		@return if static inits are done for the first time
		*/
		bool                              IsFirstStaticInit() const;

		/**
		Destroys all the modules listed in the specified array.
		After call, the array is empty.
		@param ioModules the list of modules to destroy and clean
		@return error code
		*/
		static error                      DestroyModules(vkArray<vkModulePtr>& ioModules);

		/**
		Gets the buffer size allocated to cache RTTI ancestors for any RTTI
		of the current process. This method is for performance tuning only.
		@return the buffer size
		*/
		static uint32                     GetRTTIAncestorsCacheSize();

		/**
		Defines the extension on disk of the modules.
		This is highly dependent to the platform (dll on windows, framework on mac...)
		*/
		static const vkString             kExtension;

		/**
		Defines the variable of the environment manager
		that stores the directory where modules are located by default.
		Value is "ModulesURI".
		*/
		static const vkString             kDirectoryURIVariableName;

		/**
		Defines the variable of the environment manager
		that stores the file extension of a module.
		Value is "ModulesExt".
		*/
		static const vkString             kExtensionVariableName;

		/**
		Defines the static data.
		*/
		struct VKKERNEL_API StaticData
		{
#if defined(VK_MULTIPLE_CONTEXTS)
			StaticData(vkCtxObjectBase*& ioCtxObjectList = s_LocalCtxObjectList, vkRTTI*& ioRTTIList = s_LocalRTTIList);
#else
			StaticData(vkRTTI*& ioRTTIList = s_LocalRTTIList);
#endif

			int32                         m_StaticInitCount;
			vkCtxObject<vkModule*>        m_Instances;
			vkRTTI*&                      m_RTTIList;
		};

	protected :

		/**
		Create the module asset.

		This function is called during the initialization of the module asset (see
		vkModule for an explaination).
		
		The default implementation of this function should be enough, but if you really
		need to do something else do not forget to call ParentClass::_Create() at the beginning
		of your implementation.

		@code
		error MyModuleInit::_Construct()
		{
			VK_RETURN_IF_FAILED(ParentClass::_Create(iCtxHandle));

			WhatIWantToDo();

			return errOk;
		}
		@endcode

		@see _Destroy, _CreateContextedSingletons, _RegisterResourceCategories, _RegisterTypes, _RegisterAssetFactories
		*/
		virtual error                     _Construct();

		/**
		Adds or releases a use of this module by a user
		If iUser is not null then this module is stored as a
		dependency of iUser, otherwise a simple AddRef/Release is done.
		@param iUser
		*/
		//@{
		void                              _AddUse(vkAsset* iUser);
		void                              _ReleaseUse(vkAsset* iUser);
		//@}

		/**
		Loads this module.
		This method must be only called by <Module>::Init().
		It reconstructs a complete URI from iModuleName and the Exe path.
		@param iModuleName the name of this module
		*/
		error                             _LoadModule(const vkString& iModuleName);


		/**
		Destroy the module asset.

		This function is called during the uninitialization of the module asset (see
		vkModule for an explaination).
		
		The default implementation of this function should be enough, but if you really
		need to do something else do not forget to call ParentClass::_Destroy() at the end
		of your implementation.

		@code
		void  MyModuleInit::_Destroy()
		{
			WhatIWantToDo();

			ParentClass::_Destroy();
		}
		@endcode

		@see _Destroy, _DestroyContextedSingletons, _UnregisterResourceCategories, _UnregisterAssetFactories
		*/
		virtual void                      _Destroy();

		/**
		Returns the last error return by _LoadModule() in <Module>::Init()
		@return the error code
		*/
		error                             _GetLastError();

		/**
		Returns all the static data defined for this module.
		@return the static data
		*/
		virtual StaticData&               _GetStaticData() const = 0;

#if defined(VK_MULTIPLE_CONTEXTS)
		/**
		Returns the list of ctx objects
		@return the list
		*/
		virtual vkCtxObjectBase**         _GetCtxObjectsList() = 0;

		/**
		Create the ctx objects
		@return error code
		*/
		virtual error                     _CreateCtxObjects();

		/**
		Destroy the ctx objects
		@return error code
		*/
		virtual error                     _DestroyCtxObjects();
#endif // VK_MULTIPLE_CONTEXTS

		/**
		Initializes all the objects that are cross-context.
		@return error code.
		*/
		virtual error                     _CreateSingletons();

		/**
		Uninitializes all the objects that are cross-context.
		@return error code.
		*/
		virtual error                     _DestroySingletons();

		/**
		Initializes all the modules that are used by this module
		@return error code.
		*/
		virtual error                     _InitUsedModules();

		/**
		Uninitializes all the modules that were used by this module
		@return error code.
		*/
		virtual error                     _UninitUsedModules();

		// New functions to override
		/**
		Override this function to initiliaze any data (singleton, static, global)  relative to the module
		in its context.

		This is the first function called during the module asset initialization (with
		the default implementation of _Create()).

		As this function is the first one called during the initialization of the module, it is also
		used to intialize other module your modules depends from.

		@code
		error MyModule::_CreateContextedSingletons()
		{
			vkCtx ctx = GetCtx();
			// initialize the vkKernel module asset
			VK_RETURN_IF_FAILED(vkKernelModule::Init(ctx));

			// initialize module singleton
			VK_RETURN_IF_FAILED(MySingleton::_Initialize(ctx));

			return errOk;
		}
		@endcode

		@see _DestroyContextedSingletons, _Create
		*/
		virtual error                     _CreateContextedSingletons();

		/**
		Override this function to release any data (singleton, static, global)  relative to the module
		in its context.

		This is the last function called during the module asset uninitialization (with
		the default implementation of _Destroy()).

		As this function is the last one called during the uninitialization of the module, it is also
		used to unintialize other modules your module depends from.

		@code
		error MyModule::_CreateContextedSingletons(vkCtx iCtx)
		{
			VK_RETURN_IF_FAILED(MySingleton::_Uninitialize(iCtx));

			return vkKernelModule::Uninit(ctx);
		}
		@endcode

		@see _CreateContextedSingletons, _Destroy
		*/
		virtual error                     _DestroyContextedSingletons();

		/**
		Override this function to register any type (#VKernel::vkType) relative to the module.

		This function is called during the module asset initialization (with
		the default implementation of _Create()).

		Types are automatically unregistered when the module asset is unloaded (destroyed).

		@code
		error MyModuleInit::_RegisterTypes(vkTypeManager& iTm)
		{
			iTm.BeginClass("MyType",VK_NS,sizeof(MyType));
			iTm.DeclareMember(VK_AS("x"), vkFloat::s_Type);
			iTm.DeclareMember(VK_AS("y"), vkFloat::s_Type);
			iTm.DeclareMember(VK_AS("z"), vkFloat::s_Type);
			MyType::s_Type = iTm.EndClass();

			return errOk;
		}
		@endcode

		@see _Create
		*/
		virtual error                     _RegisterTypes(vkTypeManager& iTm);

		
		virtual error                     _RegisterAssetFactories();

		/**
		Override this function to unregister any resource categories (vkAssetFactory::UnregisterFactory()) relative to the module.
		
		This function is called during the module asset uninitialization (with
		the default implementation of _Destroy()).

		@code
		error MyModuleInit::_UnregisterAssetFactories()
		{
			vkAssetFactory::UnregisterFactory(MyAsset::Factory::kRTTI);
			return errOk;
		}
		@endcode

		@see _RegisterAssetFactories, _Destroy
		*/
		virtual error                     _UnregisterAssetFactories();

#if !defined(VK_DOXYGEN)
		// Overridden from vkAsset
		virtual error                     _Load(vkAssetSerializationContext& iContext);
#endif

	private:
		vkArray<vkAssetPtr>               m_Assets;
		void                              _LoadStatic(vkAssetSerializationContext* iContext);

		static uint32                     s_RTTIAncestorsCacheSize;
		static uint32                     s_RTTIAncestorsCacheCount;
		static float                      s_RTTIInitDuration;

		vkRTTI**                          m_RTTIAncestorsCache;
		error                             m_InitError;

	protected:
		error                             _InitRTTISystem();
		void                              _TerminateRTTISystem();

		void                              _CreateFromStaticLinkage(vkAssetSerializationContext* iContext);
	};

	class vkDynamicModule;
	typedef vkRefPtr<vkDynamicModule> vkDynamicModulePtr;

	class VKKERNEL_API vkDynamicModule : public vkModule
	{
	public:
		VK_DECLARE_RTTI(vkDynamicModule, vkModule);


		/**
		Constructor.
		@param iCtx the context in which this module will live
		@param iManifest an optional manifest
		*/
		vkDynamicModule(vkCtx iCtx);

		/**
		Gets all the supported module extensions.
		module extensions are used to identify module files
		when parsing directories.
		@param iCtx the context
		@return the array of supported module extensions.
		*/
		static const vkArray<vkString>&   GetModuleExtensions(vkCtx iCtx);

	protected:
		virtual ~vkDynamicModule();

	private:
		friend class vkKernelModule;
		static error                      _InitializeDynamicModules(vkCtx iCtx);
		static error                      _TerminateDynamicModules(vkCtx iCtx);

		static vkCtxObject<vkArray<vkString>*> s_Extensions;

	};

	/**
	Unique Entry Point exported by the dynamic modules (stored in a shared library)
	*/
	typedef void(*TCreateModule)(vkCtx iCtx, vkDynamicModulePtr& oModulePtr);


#if defined(VK_STATIC)
	typedef vkModule vkModuleBaseClass;
#else
	typedef vkDynamicModule vkModuleBaseClass;
#endif

	/**
	Inline implementations.
	*/
	VK_INLINE uint32
	vkModule::GetRTTIAncestorsCacheSize()
	{
		return s_RTTIAncestorsCacheSize;
	}
}

#endif // __vkModule_h



