/**
@file

This file defines a basic management of the RTTI (Runtime Type Information).

There are 2 classes used for RTTI Support :
	- vkRTTI : the struct containing class info.
	- vkRTTIObject : the base class for all classes supporting RTTI.

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkRTTI_h)
#define __vkRTTI_h

#include "vkKernelLib.h"
#include "vkHeapObject.h"

#if !defined(__vkString_h)
#include "vkString.h"
#endif
#if !defined(__vkAutoPtr_h)
#include "vkAutoPtr.h"
#endif
#include "vkCtxObject.h"


namespace VKernel
{
	// Private
	class vkRTTI;
	extern vkRTTI* s_LocalRTTIList;
}

namespace VKernel
{
	class vkType;
	class vkTypeManager;
	class vkRTTIObject;

	/**
	Function Prototype to allocate a new element of a given type or RTTI.
	@param iHandle a handle of the current context
	@param iBuffer if not null, then a placement new must be done on the given address,
	else the callee must allocate memory
	@see vkClassType::SetNewFunction
	*/
	typedef void* (*vkNewFunctionPtr)(vkCtx iHandle, void* iBuffer);

	/**
	Default implementation of vkNewFunctionPtr for contexted objects.
	@param iHandle a handle of the current context
	@param iBuffer if not null, then a placement new must be done on the given address,
	else the callee must allocate memory
	@see vkClassType::SetNewFunction
	*/
	template <class T> void* vkStdCreateContextedInstance(vkCtx iHandle, void* iBuffer)
	{
		return (iBuffer != 0) ? new (iBuffer) T(iHandle) : new T(iHandle);
	}

	/**
	Default implementation of vkNewFunctionPtr for non contexted objects.
	@param iHandle a handle of the current context
	@param iBuffer if not null, then a placement new must be done on the given address,
	else the callee must allocate memory
	@see vkClassType::SetNewFunction
	*/
	template <class T> void* vkStdCreateInstance(vkCtx iHandle, void* iBuffer)
	{
		return (iBuffer != 0) ? new (iBuffer) T : new T;
	}

	/**
	Default implementation of vkDeleteFunction.
	@param iBuffer pointer to the object to delete
	@param iDeallocate if true then the memory is also deallocated
	*/
	template <class T> void vkStdDeleteInstance(void* iBuffer, bool iDeallocate = true)
	{
		T* instance = (T*) iBuffer;
		if (iDeallocate)
		{
			delete instance;
		}
		else
		{
			instance->~T();
		}
	}

	/**
	The RTTI Object embeds	all useful information to describe a class.

	A RTTI ((Run Time Test Information) object contains all data
	describing a class. This object is generally used as a static member of a class.
	From a vkRTTI Object, you can get :
		- the class name.
		- the inheritance hierarchy (linked list from class::kRTTI to superClass::kRTTI

	vkRTTI only supports encoding of simple inheritance.

	@see vkRTTIObject
	*/
	class VKKERNEL_API vkRTTI : public vkHeapObject
	{
	public :

		/**
		Constructor.
		
		RTTI objects created with this constructor should be declared static.

		@param iSuperClassRTTI the rtti of the super class
		@param iClassID the class ID (actually the plain class name as seen in C++)
		*/
		explicit vkRTTI(vkRTTI* iSuperClassRTTI, const vkString& iClassID, vkNewFunctionPtr iCreateFunction = 0, vkRTTI*& ioLocalRTTIList = s_LocalRTTIList);

		/**
		Destructor
		*/
		~vkRTTI();

		/**
		Gets the ID of this class.
		The ID of the class is generally the name of the class as typed in C++.
		@return the ID of the class
		*/
		const vkString&	GetClassID() const;

		/**
		Returns the depth of the class in the inheritance hierarchy

		0 = root class, ie vkRTTIObject

		@return the depth of the class.
		*/
		uint32			GetClassDepth() const;

		/**
		Returns whether the RTTI was correctly initialized..
		*/
		bool			IsValid() const;

		/**
		Tests if the class described by the rtti
		equals or is a subclass of the class described by iOtherRTTI
		@param iOtherRTTI the rtti object to compare with.
		@return true if class(this) derives from OR equals class(iOtherRTTI)
		*/
		bool			IsKindOf(const vkRTTI& iOtherRTTI) const;

		/**
		Returns the RTTI of the super class if it exists
		@return NULL if the class is root or a pointer to the parent RTTI otherwise
		*/
		const vkRTTI*	GetSuperClassRTTI() const;

		/**
		Tests if the class or one of its ancestors
		has a specific name.

		Use this if you want to sniff a object where its class is defined
		in a static lib, an then when the rtti is duplicated.

		@param iClassID the name of the class

		@return true if class(this) derives from OR equals class(iClassID)
		*/
		bool				IsKindOf(const vkString& iClassID) const;

		/**
		Equal operator
		@param iOther the rtti to compare with
		@return true if the 2 rttis are equal
		*/
		bool				operator==(const vkRTTI& iOther) const;

		/**
		Not Equal operator
		@param iOther the rtti to compare with
		@return false if the 2 rttis are equal
		*/
		bool				operator!=(const vkRTTI& iOther) const;

		/**
		Creates an instance of an RTTI object.
		@param iHandle the handle of the current context
		@param iBuffer an optional buffer where to perform placement new
		@return 0 if the class is abstract, a new instance otherwise
		@see GetRTTIByClassID
		*/
		vkRTTIObject*       CreateInstance(vkCtx iHandle, void* iBuffer = 0);

		/**
		Returns an RTTI given its class name.
		
		@param iClassID the ID of the RTTI.
		
		@return the RTTI found, 0 otherwise.

		@see CreateInstance
		*/
		static	vkRTTI*		GetRTTIByClassID(const vkString& iClassID);

		/**
		Base class to derive from to iterate all the rttis.
		@see Iterate
		*/
		class VKKERNEL_API Iterator
		{
		public:
			/**
			Destructor.
			*/
			virtual ~Iterator();

			/**
			Inspects the given rtti.
			@param iRTTI the rtti to inspect.
			@return true to stop iteration
			*/
			virtual bool Iterate(vkRTTI& iRTTI) = 0;

		protected:
			/**
			Default Constructor.
			*/
			Iterator();
		private:
			friend class vkRTTI;
			uint32 m_Index;
		};

		/**
		Iterates all the rttis.
		@param iIterator the iterator for inspecting the rttis one by one.
		@return true if the iterator stopped the iteration.
		*/
		static bool			Iterate(Iterator& iIterator);

	private:
		friend class vkModule;
		static vkRTTI** _InitRTTISystem(vkRTTI* iHead, uint32& oCacheSize, float& oEllapsedTime);

		void			_InitClassDepth();
		void			_Terminate();

	private :

		VK_NO_COPYING(vkRTTI);
		static void _RegisterRTTI(vkRTTI& ioRTTI);
		static void _UnregisterRTTI(vkRTTI& ioRTTI);

		// Chain of RTTIs in the current module to be able
		// to init them at module's initialization
		vkRTTI*				m_NextRTTIInModule;

		vkString             m_ClassID; // If m_ClassID.IsEmpty(), then it's a ref to another RTTI
		
		// IsKindOf System
		mutable int32		 m_ClassDepth; // 0 = vkRTTIObject::kRTTI, ie the root class
		vkRTTI*				 m_SuperRTTI;
		vkRTTI**			 m_Ancestors;

		vkNewFunctionPtr     m_CreateFunction;
	};

	class vkRTTIInstanceHash;

	/**
	vkRTTIObject is the root class for all the objects supporting RTTI.

	Use the macros VK_DECLARE_RTTI & VK_IMPLEMENT_RTTI in derived classes to
	automatically override the necessary methods for RTTI.

	Because vkRTTIObject uses virtual methods, all classes deriving from vkRTTIObject
	have a virtual table. Also, you don't need to redeclare a destructor to ensure proper deletion
	(base class declaring virtual destructor).
	 
	@code
	class Foo : public vkRTTIObject
	{
	public :
	VK_DECLARE_RTTI(Foo, vkRTTIObject);
	};

	class Foo1 : public Foo
	{
	public :
	VK_DECLARE_RTTI(Foo1, Foo);
	};

	class Foo2 : public Foo
	{
	public :
	VK_DECLARE_RTTI(Foo2, Foo);
	};

	vkRTTIObject* foo1 = new Foo1();
	vkRTTIObject* foo2 = new Foo2();

	// Testing kind of instances
	VKASSERT(foo1->IsKindOf(vkFoo::kRTTI)); // "foo1 should be kind of Foo"
	VKASSERT(foo1->IsKindOf(vkFoo1::kRTTI)); // "foo1 should be kind of Foo1"
	VKASSERT(!foo1->IsKindOf(vkFoo2::kRTTI)); // "foo1 should not be kind of Foo2"

	// Test class names
	VKASSERT(foo1->GetClassID().Equals("Foo1")); // "class ID of instance foo1 should ne Foo1"
	VKASSERT(foo2->GetClassID().Equals("Foo2")); // "class ID of instance foo2 should ne Foo2"
	@endcode

	@see vkRTTI, VK_DECLARE_RTTI, VK_IMPLEMENT_RTTI
	*/
	class VKKERNEL_API vkRTTIObject : public vkHeapObject
	{
	
	public:



		/**
		Destructor
		*/
		virtual						~vkRTTIObject();

		/**
		the static rtti object describing the vkRTTIObjectClass.
		
		At every levels of inheritance, all classes have a static kRTTI
		object. In one derivation graph, every kRTTI objects are linked together.
		*/
		typedef vkRTTI				RTTIClass;
		static RTTIClass			kRTTI;

		/**
		Returns the actual rtti object of the instance.
		To be automatically overriden in any derived class via the VK_DECLARE_RTTI macros.
		@return  the rtti object.
		*/
		virtual vkRTTI&		GetRTTI() const;

		virtual const vkCtxTypePtr& GetTypes() const;
		virtual const vkCtxTypePtr& GetTypesPtr() const;

		vkType* GetType(vkCtx iCtx) const;
		vkType* GetTypePtr(vkCtx iCtx) const;

		/**
		Defines this class.
		*/
		typedef vkRTTIObject ThisClass;

		/**
		Defines the super class.
		*/
		typedef vkHeapObject ParentClass;

		/**
		Defines the type describing vkRTTIObject.
		*/
		static vkCtxTypePtr s_Type;

		/**
		Defines the type describing a pointer to vkRTTIObject.
		*/
		static vkCtxTypePtr s_TypePtr;

		/**
		Registers the type vkRTTIObject.
		@param iTm the type manager
		*/
		static void RegisterType(vkTypeManager& iTm);

		/**
		Unregisters the type vkRTTIObject.
		@param iTm the type manager
		*/
		static void UnregisterType(vkTypeManager& iTm);


		/**
		Tests if the instance's class equals or derives from the class
		whose ID is iClassID
		@param iClassID the class ID of the class to compare with this instance
		@return true if class(instance) == OR derives from class(iClassID)
		*/
		bool						IsKindOfByClassID(const vkString& iClassID) const;

		/**
		Gets the class ID of this instance.
		@return the class ID.
		*/
		const vkString&				GetClassID() const;

		/**
		Tests if the instance's class equals or derives from the class
		described by iRTTI
		@param iRTTI the rtti object describing the class to compare with this instance
		@return true if class(instance) == OR derives from class(iRTTI)
		*/
		bool						IsKindOf(const vkRTTI& iRTTI) const;

		/**
		Prints instances information (instance count-peak / class).

		This routine exists in all configuration but actually only works
		in Debug Mode.

		@param iSkipClassesWithNoInstances if true, do not display info on class C if
		instance count(C) == 0
		*/
		static	void DumpInstanceCounts(bool iSkipClassesWithNoInstances = false);

#if !defined(VK_DOXYGEN)

	protected:
		/**
		A default implementation should mark the object as valid.

		This method is called by an object CreateInstance() member function and
		can be overridden to properly initialize an object. 

		@see _Destroy
		*/
		virtual error _Construct();

	private:
		static void _DeleteFct(void* iInstance, bool iDeallocate);
#endif // VK_DOXYGEN
	};

/**
Use this macro in declaration of classes whose root class
is vkRTTIObject.

Every VK_DECLARE_RTTI must match a VK_IMPLEMENT_RTTI(used in a .cpp).
All classes including VK_DECLARE_RTTI provide 2 static methods:
	- Class* Class::StaticCast(const vkRTTIObject* iObj) : downcast obj in Class. It makes a type check
	only in Debug (It only causes an Assert).
	- Class* Class::DynamicCast(const vkRTTIObject* iObj) : downcast obj in Class. It makes a full type check
	in all configuration. If iObj is not kind of Class, then a null pointer is returned.

@param theClass the class to declare rtti
@param superClass the super class of the current class


@code

	// In .h
	namespace MyNamespace
	{
		class Foo : public Bar
		{
		public:
			VK_DECLARE_RTTI(Foo, Bar);
		};
	}

	// In .cpp
	namespace MyNameSpace
	{
		VK_IMPLEMENT_RTTI(Foo);
	}
@endcode

@see VK_IMPLEMENT_RTTI, vkRTTIObject
*/

#if !defined(VK_DOXYGEN)

#ifndef VK_GCC_XML 

#define VK_DECLARE_INSTANCE_RTTI(theClass) \
	public : \
	void* operator new(size_t iSize); \
	void  operator delete(void* iP, size_t iSize);\
	void* operator new(size_t iSize, void* p); \
	void  operator delete(void*, void*);
	/* placement new : does not work (operator delete is not called by dtor
	*/
#else

#define VK_DECLARE_INSTANCE_RTTI(theClass) \
	public : 

#endif



#define VK_IMPLEMENT_INSTANCE_RTTI(theClass)\
	void* theClass::operator new(size_t iSize) {\
	void* p = VKernel::vkHeapObject::operator new(iSize);\
	return p; \
	} \
	void theClass::operator delete(void* iP, size_t iSize) { \
	VKernel::vkHeapObject::operator delete(iP, iSize);\
	}\
	void* theClass::operator new(size_t, void* iP) { \
	return iP; \
	} \
	void theClass::operator delete(void*, void*) { \
	}

#define VK_IMPLEMENT_INSTANCE_RTTI_ALIGNED(theClass)\
	void* theClass::operator new(size_t iSize) {\
	void* p = VKernel::vkAlignedHeapObject<VKALIGNOF(theClass)>::operator new(iSize);\
	return p;\
	}\
	void theClass::operator delete(void* iP, size_t iSize) { \
	VKernel::vkAlignedHeapObject<VKALIGNOF(theClass)>::operator delete(iP,iSize);\
	}\
	void* theClass::operator new(size_t, void* iP) { \
	return iP; \
	} \
	void theClass::operator delete(void*, void*) { \
	}

#endif // VK_DOXYGEN

#define VK_SET_TYPE(Type, ctxHandle) s_Type[ctxHandle] = Type; /*kRTTI.types[ctxHandle] = Type*/

////////////////////////////////////////////////////////////////////////////////
// Declare
////////////////////////////////////////////////////////////////////////////////

#define VK_DECLARE_NOCREATE(Class)
#define VK_DECLARE_NOTYPE(Class)
#define VK_DECLARE_NOCOMP(Class)

#define VK_DECLARE_CREATE(Class)\
	static Class* CreateInstance(vkCtx iHandle, void* iBuffer = 0);

#define VK_DECLARE_CREATEABSTRACT(Class)\
	static Class* CreateInstance(vkCtx iHandle, void* iBuffer = 0);

#define VK_DECLARE_CREATEPIMPL(Class)\
	VK_NO_COPYING(Class);public:										\
	Class##Impl* Impl() {return (Class##Impl*)m_Implementation;}	\
	const Class##Impl* Impl() const {return (const Class##Impl*)m_Implementation;}	\
	virtual void DeleteImplementation();\
	static Class* CreateInstance(vkCtx iCtx, void* iBuffer = 0);\
	static Class##Impl* CreateImplementation(vkCtx iCtx);\
	
#define VK_DECLARE_TYPERTTIOBJECT(Class)\
private: \
	static void RegisterMembers(vkTypeManager& iTm);\
public:\
	static vkCtxTypePtr s_Type;\
	static vkCtxTypePtr s_TypePtr;\
	static void RegisterType(vkTypeManager& iTm);\
	static void UnregisterType(vkTypeManager& iTm);\
	virtual const vkCtxTypePtr& GetTypes() const;\
	virtual const vkCtxTypePtr& GetTypesPtr() const;\
	
#define VK_DECLARE_TYPE(Class)\
	VK_DECLARE_TYPERTTIOBJECT(Class)\
	virtual vkType* GetType() const;\
	virtual vkType* GetTypePtr() const;



#define VK_DECLARE_COMP(Class)\
	static Class* ComponentCast(const vkComponent* iComp) {\
	if (iComp == 0) return 0; \
	vkCtx ctx = iComp->GetCtx(); \
	return Class::DynamicCast(iComp->QueryComponent(Class::s_Type[ctx]));\
	}

#define VK_DECLARE_RTTI_EX(Class, SuperClass, CreateInst, TypeMacro, ComponentMacro)\
	VK_DECLARE_INSTANCE_RTTI(Class);\
	public :\
	static RTTIClass kRTTI;\
	typedef Class ThisClass;\
	typedef SuperClass ParentClass;\
	virtual VKernel::vkRTTI& GetRTTI() const { return kRTTI; } \
	static Class* DynamicCast(const VKernel::vkRTTIObject* iPtr); \
	VK_INLINE static Class* StaticCast(const VKernel::vkRTTIObject* iPtr) { \
	VKASSERT((iPtr == 0) || iPtr->IsKindOf(Class::kRTTI)); \
	return (Class*) iPtr; \
	} \
	VK_INLINE static Class* WeakDynamicCast(const VKernel::vkRTTIObject* iPtr){\
	return (iPtr && iPtr->IsKindOfByClassID(VK_AS(#Class))) ? (Class*)iPtr:0;\
	} \
	VK_INLINE static Class* WeakStaticCast(const VKernel::vkRTTIObject* iPtr){\
	if (iPtr != 0) { \
	VKASSERT(iPtr->IsKindOfByClassID(VK_AS(#Class)));\
	return (Class*)iPtr; \
	} else return 0; \
	}\
	VK_DECLARE_##CreateInst(Class)\
	VK_DECLARE_##TypeMacro(Class)\
	VK_DECLARE_##ComponentMacro(Class)


////////////////////////////////////////////////////////////////////////////////
// Implement
////////////////////////////////////////////////////////////////////////////////

// only calls the ctor of the RTTI
#define VK_IMPLEMENT_NOCREATE(Class)\
	Class::RTTIClass Class::kRTTI(&(Class::ParentClass::kRTTI), VK_AS(#Class));

#define VK_IMPLEMENT_NOTYPE(Class)
#define VK_IMPLEMENT_NOCOMP(Class)

#define VK_IMPLEMENT_DEFAULT_UNREGISTER_TYPE(Class) \
void Class::UnregisterType(vkTypeManager& iTm) {\
iTm.UnregisterType(Class::s_Type[iTm.GetCtx()]);\
Class::s_Type[iTm.GetCtx()] = 0;\
} \

#define VK_IMPLEMENT_RTTI_CTOR_CREATE(Class)\
	Class::RTTIClass Class::kRTTI(&(Class::ParentClass::kRTTI), VK_AS(#Class), (vkNewFunctionPtr)(Class*(*)(vkCtx, void*))Class::CreateInstance);\

#define VK_IMPLEMENT_CREATE(Class)\
	VK_IMPLEMENT_RTTI_CTOR_CREATE(Class)\
	Class* Class::CreateInstance(vkCtx iHandle, void* iBuffer) {\
		Class* c = (iBuffer == 0) ? new Class : new (iBuffer) Class;\
		c->_Construct();\
		return c;\
	}

#define VK_IMPLEMENT_CREATEABSTRACT(Class)\
	VK_IMPLEMENT_RTTI_CTOR_CREATE(Class)\
	Class* Class::CreateInstance(vkCtx iHandle, void* iBuffer) {return 0;}

#define VK_IMPLEMENT_CREATECONTEXTOBJECT(Class)\
	VK_IMPLEMENT_RTTI_CTOR_CREATE(Class)\
	Class* Class::CreateInstance(vkCtx iHandle, void* iBuffer) {\
		Class* c = (iBuffer == 0) ? new Class(iHandle) : new (iBuffer) Class(iHandle);\
		c->_Construct();\
		return c;\
	}

#define VK_IMPLEMENT_CREATEPIMPL_NODEL(Class)\
	VK_IMPLEMENT_RTTI_CTOR_CREATE(Class)\
	Class##Impl* Class::CreateImplementation(vkCtx iHandle) {\
		return new Class##Impl(iHandle);\
	}\
	Class* Class::CreateInstance(vkCtx iHandle, void* iBuffer) {\
		Class* c = (iBuffer == 0) ? new Class(iHandle) : new (iBuffer) Class(iHandle);\
		c->m_Implementation = CreateImplementation(iHandle);\
		c->_Construct();\
		return c;\
	}

#define VK_IMPLEMENT_CREATEPIMPL(Class)\
	VK_IMPLEMENT_CREATEPIMPL_NODEL(Class)\
	void Class::DeleteImplementation() {\
		delete (Class##Impl*)m_Implementation;\
		m_Implementation = 0;\
	}

	#define _IncrementInstanceCount(a)


#define VK_IMPLEMENT_INSTANCE_ALIGNED_PIMPL_LOCAL(theClass)\
	void* theClass::operator new(size_t iSize) {\
	const uint32 offset = vkAlign(sizeof(theClass),VKALIGNOF(theClass##Impl));\
	const uint32 maxAlign = VKALIGNOF(theClass##Impl);\
	const uint32 sz  = offset + sizeof(theClass##Impl);\
	void* p = vkAllocateAligned(sz,maxAlign);\
	return p; \
} \
	void theClass::operator delete(void* iP, size_t iSize) { \
	vkDeallocateAligned(iP);\
}\
	void* theClass::operator new(size_t, void* iP) { \
	return iP; \
} \
	void theClass::operator delete(void*, void*) { \
}

#define VK_IMPLEMENT_CREATEPIMPL_LOCAL(Class)\
	VK_IMPLEMENT_RTTI_CTOR_CREATE(Class)\
	VK_IMPLEMENT_INSTANCE_ALIGNED_PIMPL_LOCAL(Class)\
	Class##Impl* Class::CreateImplementation(vkCtx iHandle) {\
	VKASSERT(0);\
	return 0;\
	}\
	Class* Class::CreateInstance(vkCtx iHandle, void* iBuffer) {\
		VKASSERT(iBuffer==0);\
		const uint32 offset = vkAlign(sizeof(Class),VKALIGNOF(Class##Impl));\
		const uint32 maxAlign = VKALIGNOF(Class##Impl);\
		const uint32 sz  = offset + sizeof(Class##Impl);\
		uint8* buffer = vkAllocateAligned(sz,maxAlign);\
		Class* c = new (buffer) Class(iHandle);\
		c->m_Implementation = new ((void*)(buffer+offset)) Class##Impl(iHandle);\
		c->_Construct();\
		_IncrementInstanceCount(Class::kRTTI);\
		return c;\
	}\
	void Class::DeleteImplementation() {\
	((Class##Impl*)m_Implementation)->~Class##Impl();\
	m_Implementation = 0;\
	}


#define VK_IMPLEMENT_TYPERTTIOBJECT(Class)\
	const vkCtxTypePtr& Class::GetTypes() const {return s_Type;}\
	const vkCtxTypePtr& Class::GetTypesPtr() const {return s_TypePtr;}\
	vkCtxTypePtr Class::s_Type;\
	vkCtxTypePtr Class::s_TypePtr;

// For classes that are derived from vkObject ( contexted classes)
#define VK_IMPLEMENT_TYPE(Class)\
	VK_IMPLEMENT_TYPERTTIOBJECT(Class);\
	vkType* Class::GetType() const {return s_Type[GetCtx()];}\
	vkType* Class::GetTypePtr() const {return s_TypePtr[GetCtx()];}\

#define VK_IMPLEMENT_TYPECLASS(Class)\
	VK_IMPLEMENT_TYPE(Class);\
	void Class::RegisterType(vkTypeManager& iTm) {\
		vkCtx ch = iTm.GetCtx();\
		vkType* createdType = iTm.BeginClass(Class::kRTTI.GetClassID(),ParentClass::s_Type, sizeof(Class), 0, (vkNewFunctionPtr)(Class*(*)(vkCtx, void*))Class::CreateInstance );\
		VK_SET_TYPE(createdType, ch);\
		s_TypePtr[ch]	= createdType->GetManagedPointerType(QUOTE(Class##Ptr)); \
		RegisterMembers(iTm); \
		iTm.EndClass(); \
	}\
	VK_IMPLEMENT_DEFAULT_UNREGISTER_TYPE(Class)

#define VK_IMPLEMENT_TYPERTTIOBJECTCLASS(Class)\
	VK_IMPLEMENT_TYPERTTIOBJECT(Class);\
	void Class::RegisterType(vkTypeManager& iTm) {\
		vkCtx ch = iTm.GetCtx();\
		vkType* createdType = iTm.BeginClass(Class::kRTTI.GetClassID(),ParentClass::s_Type, sizeof(Class) , 0, (vkNewFunctionPtr)(Class*(*)(vkCtx, void*))Class::CreateInstance );\
		VK_SET_TYPE(createdType, ch);\
		s_TypePtr[ch]	= createdType->GetManagedPointerType(QUOTE(Class##Ptr)); \
		RegisterMembers(iTm); \
		iTm.EndClass(); \
	}\
	VK_IMPLEMENT_DEFAULT_UNREGISTER_TYPE(Class)


#define VK_IMPLEMENT_COMP(Class)

/**
Use this macro in implementation of classes whose root class
is vkRTTIObject.

Use only this macro in .cpp and not in .h to avoid multiple link definition.

@param classID the class to implement rtti

@see VK_DECLARE_RTTI, vkRTTIObject
*/
#define VK_IMPLEMENT_RTTI_EX(Class, CreateInst, TypeMacro, ComponentMacro)\
	VK_IMPLEMENT_INSTANCE_RTTI(Class);\
	Class* Class::DynamicCast(const VKernel::vkRTTIObject* iPtr) { return (iPtr && iPtr->IsKindOf(Class::kRTTI))?(Class*)iPtr:0;}\
	VK_IMPLEMENT_##CreateInst(Class)\
	VK_IMPLEMENT_##TypeMacro(Class)\
	VK_IMPLEMENT_##ComponentMacro(Class)

#define VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CreateInst, TypeMacro, ComponentMacro)\
	VK_IMPLEMENT_INSTANCE_RTTI_ALIGNED(Class);\
	Class* Class::DynamicCast(const VKernel::vkRTTIObject* iPtr) { return (iPtr && iPtr->IsKindOf(Class::kRTTI))?(Class*)iPtr:0;}\
	VK_IMPLEMENT_##CreateInst(Class)\
	VK_IMPLEMENT_##TypeMacro(Class)\
	VK_IMPLEMENT_##ComponentMacro(Class)


	#define USE_LOCAL_PIMPL 0


#if USE_LOCAL_PIMPL
	#define VK_IMPLEMENT_RTTI_EX_ALIGNED_PIMPL_LOCAL(Class, CreateInst, TypeMacro, ComponentMacro)\
		Class* Class::DynamicCast(const VKernel::vkRTTIObject* iPtr) { return (iPtr && iPtr->IsKindOf(Class::kRTTI))?(Class*)iPtr:0;}\
		VK_IMPLEMENT_##CreateInst(Class)\
		VK_IMPLEMENT_##TypeMacro(Class)\
		VK_IMPLEMENT_##ComponentMacro(Class)
#else
	#define VK_IMPLEMENT_RTTI_EX_ALIGNED_PIMPL_LOCAL(Class, CreateInst, TypeMacro, ComponentMacro)\
		VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CreateInst, TypeMacro, ComponentMacro)
#endif


////////////////////////////////////////////////////////////////////////////////
// Helpers
////////////////////////////////////////////////////////////////////////////////

#define VK_DECLARE_RTTI(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, NOCREATE, NOTYPE, NOCOMP)

#define VK_DECLARE_RTTI_CREATE(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATE, NOTYPE, NOCOMP)

#define VK_DECLARE_RTTI_ABSTRACTTYPE(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATEABSTRACT, TYPE, NOCOMP)

#define VK_DECLARE_RTTI_ABSTRACTRTTIOBJECT(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATEABSTRACT, TYPERTTIOBJECT, NOCOMP)

#define VK_DECLARE_RTTI_RTTIOBJECT(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATE, TYPERTTIOBJECT, NOCOMP)

#define VK_DECLARE_RTTI_OBJECT(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATE, TYPE, NOCOMP)

#define VK_DECLARE_RTTI_OBJECT_PIMPL(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATEPIMPL, TYPE, NOCOMP)

#define VK_DECLARE_RTTI_COMPONENT(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATE, TYPE, COMP)

#define VK_DECLARE_RTTI_COMPONENT_PIMPL(Class, SuperClass)\
	VK_DECLARE_RTTI_EX(Class, SuperClass, CREATEPIMPL, TYPE, COMP)


////////////////////////////////////////////////////////////////////////////////

#define VK_IMPLEMENT_RTTI(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, NOCREATE, NOTYPE, NOCOMP)

#define VK_IMPLEMENT_RTTI_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, NOCREATE, NOTYPE, NOCOMP)

#define VK_IMPLEMENT_RTTI_TYPED(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, NOCREATE, TYPE, NOCOMP)

#define VK_IMPLEMENT_RTTI_TYPED_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, NOCREATE, TYPE, NOCOMP)


#define VK_IMPLEMENT_RTTI_REGTYPE(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, NOCREATE, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_REGTYPE_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, NOCREATE, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_CREATE(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, CREATECONTEXTOBJECT, NOTYPE, NOCOMP)

#define VK_IMPLEMENT_RTTI_CREATE_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CREATECONTEXTOBJECT, NOTYPE, NOCOMP)

#define VK_IMPLEMENT_RTTI_ABSTRACTTYPE(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, CREATEABSTRACT, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_ABSTRACTTYPE_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CREATEABSTRACT, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_CONTEXTOBJECT(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, CREATECONTEXTOBJECT, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_CONTEXTOBJECT_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CREATECONTEXTOBJECT, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_OBJECT_PIMPL(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, CREATEPIMPL, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_OBJECT_PIMPL_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CREATEPIMPL, TYPECLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_RTTIOBJECT(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, CREATE, TYPERTTIOBJECTCLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_RTTIOBJECT_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CREATE, TYPERTTIOBJECTCLASS, NOCOMP)

#define VK_IMPLEMENT_RTTI_COMPONENT(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, CREATECONTEXTOBJECT, TYPECLASS, COMP)

#define VK_IMPLEMENT_RTTI_COMPONENT_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CREATECONTEXTOBJECT, TYPECLASS, COMP)

#define VK_IMPLEMENT_RTTI_COMPONENT_PIMPL(Class)\
	VK_IMPLEMENT_RTTI_EX(Class, CREATEPIMPL, TYPECLASS, COMP)

#define VK_IMPLEMENT_RTTI_COMPONENT_PIMPL_ALIGNED(Class)\
	VK_IMPLEMENT_RTTI_EX_ALIGNED(Class, CREATEPIMPL, TYPECLASS, COMP)

#if USE_LOCAL_PIMPL
	#define VK_IMPLEMENT_RTTI_COMPONENT_PIMPL_LOCAL(Class)\
		VK_IMPLEMENT_RTTI_EX_ALIGNED_PIMPL_LOCAL(Class, CREATEPIMPL_LOCAL, TYPECLASS, COMP)
#else
	#define VK_IMPLEMENT_RTTI_COMPONENT_PIMPL_LOCAL(Class)\
		VK_IMPLEMENT_RTTI_COMPONENT_PIMPL_ALIGNED(Class)
#endif


	#define VK_DECLARE_RTTI_DEBUG(theClass, superClass)



	#define VK_IMPLEMENT_RTTI_DEBUG(classID)



// Inlined Implementations

VK_INLINE const vkString&
vkRTTI::GetClassID() const
{ 
	return m_ClassID;
}

VK_INLINE uint32
vkRTTI::GetClassDepth() const
{
	VKASSERT(m_ClassDepth >= 0);
	return (uint32) m_ClassDepth;
}

VK_INLINE bool
vkRTTI::IsValid() const
{
	return (m_ClassDepth >= 0);
}

VK_INLINE bool
vkRTTI::operator==(const vkRTTI& iOther) const
{
	return this == &iOther;
}

VK_INLINE bool
vkRTTI::operator!=(const vkRTTI& iOther) const
{
	return this != &iOther;
}

VK_INLINE bool
vkRTTIObject::IsKindOf(const vkRTTI& iRTTI) const
{
	return GetRTTI().IsKindOf(iRTTI);
}

VK_INLINE bool
vkRTTIObject::IsKindOfByClassID(const vkString& iClassID) const
{
	return GetRTTI().IsKindOf(iClassID);
}

VK_INLINE const vkString&
vkRTTIObject::GetClassID() const
{
	return GetRTTI().GetClassID();
}

VK_INLINE const vkRTTI*
vkRTTI::GetSuperClassRTTI() const
{
	return m_SuperRTTI;
}

} // namespace VKernel

#endif // __vkRTTI_h



