/**
@file

This file defines all the vkType and related classes.

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkType_h)
#define __vkType_h

#if !defined(__vkKernelLib_h)
#include "vkKernelLib.h"
#endif
#if !defined(__vkRTTI_h)
#include "vkRTTI.h"
#endif
#if !defined(__vkString_h)
	#include "vkString.h"
#endif

#if !defined(__vkRefPtr_h)
#include "vkRefPtr.h"
#endif
#if !defined(__vkSmartPtr_h)
#include "vkSmartPtr.h"
#endif
#if !defined(__vkResource_h)
#include "vkResource.h"
#endif

namespace VKernel
{

class vkAsset;
typedef vkRefPtr<vkAsset> vkAssetPtr;

class vkContext;
class vkClassType;
class vkModifiableTypeData;
class vkRefPtrType;
class vkWeakPointerType;

class vkStringLoadArgs;
class vkStringSaveArgs;

class vkAssetSerializationContext;

class vkReferenceResolver;

class vkType;
typedef vkSmartPtr<vkType> vkTypePtr;


/**
Function Prototype to copy a buffer with a given type to another buffer.

Special copy functions can be defined to copy objects of a given to objects of another type

@see vkType::GetCopyCastFunction
*/
typedef void (*vkCopyFunction)(const vkType* iDstType, void* iDstBuffer, const vkType* iSrcType,const void* iSrcBuffer);

/**
Summary: Function Prototype to delete an object.

When declaring a new class, the system need to be aware if a specific function needs 
to be called to properly delete the object

@param iBuffer pointer on the object to delete
@param iDeallocate if true, then the buffer must be freed after having deleted the object

@see vkTypeManager::DeclareDeleteFunction
*/
typedef	void  (*vkDeleteFunctionPtr)(void* iBuffer, bool iDeallocate);

/**
Options when searching for a type.

This options can improve the performance of the GetType method by providing
some hints on the string being passed as argument for search

@see vkTypeManager::GetType
*/
enum EGetTypeOptions {
	fNoOptions						= 0,

	/** Hint : iName does not contain any Namespace:: in its string. */
	fHintNoNamespace				= 1<<0,

	/** Hint : iName does not contain any qualification (*,&,[],vkXXX<>) in its string. */
	fHintNoQualification			= 1<<1,

	/** Hint :  We only want to search in this namespace. */
	fDoNotSearchUsedNamespaces		= 1<<2,

	/** Hint :  We only want to search in this namespace exactly (dont take parents into accounts. */
	fDoNotSearchParentNamespaces	= 1<<3,

	/** don't create incomplete type to return a qualified type on a type not found*/
	fCreateIncompleteIfQualfied		= 1<<4,
};

/**
Base class for the reflection mechanism. 

This class is the base class for all types.
Types provide a reflection mechanism for any C++ type,a vkType gives the representation of a C++ type. 
This can be simple types (int , float , enum, etc..),  complex types (struct or class with methods),
qualified types (class* , const vkVec3&, vkArray<anotherType>) 

Declaring a new class or C++ type to the system is done through the binding process, see this 
<a href="studio-sdk\white-papers\understanding-binding-by-example.html">Understanding Binding by Example</a>

Once registered the vkType hold the information to perform the following operation
on a buffer containing an object the given type:
	- Call the appropriate constructor
	- Call the appropriate destructor
	- Copy an object
	- Cast an object from another type
	- Serialize to and from : a string , a binary buffer or an XML stream
	- Compare two objects 

Every C++ class or type can be represented as a vkType which then gives the opportunity
to have objects serialized easily or methods called form VSL for example.

The vkType is an empty class only containing the virtual functions that 
are called by the framework .
*/
class VKKERNEL_API vkType : public vkResource
{
	VK_DECLARE_RTTI_ABSTRACTTYPE(vkType, vkResource);
	friend class vkTypeManager;

public :

	/** Type Qualifier.
	
	A type can be used in expressions such as functions or for members of a class or structure. 
	In these cases the type can be "qualified"
	*/
	enum FQualifier {
		fNone			= 0,				///< No Qualifier 
		fConst			= 1<<5,				///< Const qualifier (cumulable with other qualifiers)
		fStatic			= 1<<6,				///< Static qualifier (cumulable with other qualifiers) 
		fMoreParams		= 1<<7,				///< A single flag is not enough to describe the qualification entirely
		fOptionsMask	= ~(fConst|fStatic),///< Mask to remove the const and static qualifier
		fReference		= 1,				///< A reference (eg int&) 
		fPointer		= 2,				///< A pointer (eg int*) 
		fRefPtr			= 3,				///< vkRefPtr<>
		fAutoPtr		= 4,				///< vkAutoPtr<>
		fSmartPtr		= 5,				///< vkSmartPtr<> 
		fStaticArray	= 15|fMoreParams,	///< type[x]...[z]
		fvkArray		= 16|fMoreParams,	///< vkArray<>
		fvkHash			= 17|fMoreParams,	///< vkHash<> ; not used in memory, just used as a return value. because you can't have a "qualifier" for 2 types
		fvkHashEntry	= 18|fMoreParams,	///< vkHashEntry<> ; not used in memory, just used as a return value. because you can't have a "qualifier" for 2 types
	};

	
	/** Flags
	 
	Some of the following flags are used by the engine 
	during type registration (those marked as Internal) 
	*/
	enum FFlags {
		fUseXMLAttribute		= 1<<0,		///< When serializing to or from XML use an attribute mode instead of  hierarchical mode...
		fPlaindOldData			= 1<<1,		///< IsPod() Type is very simple one (int, float) without any specific constructor to be called.
		fToBeCompleted			= 1<<2,		///< (Internal) Type is to be completed by vkTypeManager::CompleteAllTypes
		fContainVirtuals		= 1<<3,		///< If this is a structure or class this indicates there is a VFat pointer in the object..
		fIsAbstract				= 1<<4,		///< The struct can only created/destructed via New/Delete and addressed through pointers
		fIsModifiable			= 1<<5,		///< A struct can be modified (members can be added/removed)
		fPropertyAdded			= 1<<6,		///< (Internal) A member property has been added to the type after it was finalized, internal data may need to be recomputed for other classes
		fComplete				= 1<<7,		///< (Internal) Type is completely defined and can be used
		fHasDefaultValueString	= 1<<8,		///< (Internal) When declaring a concrete type, a default value can be given as a (void*) buffer or a vkString
		fNeedDefaultValueBuffer	= 1<<9,		///< Type has a default value buffer
		fAtomicSerialization	= 1<<10,	///< This type must be saved in its entirety ( all members of a class must be saved for example ) 
		fNotReady				= 1<<11,	///< Type can't be used (from a semantically point of view)
		fSLType					= 1<<12,	///< Type has been registered by a script language (VSL, ...)
		fBeingReplaced			= 1<<13,	///< (Internal)
		fMergeableComponentType = 1<<14,    ///< This component type accepts to be merged several times in a component ring.
		fIsNamespace			= 1<<15,	///< (Internal)
		fIsInGlobalNamespace	= 1<<16,	///< to tell TypeManager::BeginCustomType & _RegisterCustom to use global namespace & not current namespace (mortal // now used only in Type::GetHashType to force hash to be global)
		fPreventGetHashLoop		= 1<<17,	///< to prevent vkType::GetHashType loop, inner use only, not for external user
		fPreventGetHashEntryLoop= 1<<18,	///< to prevent vkType::GetHashEntryType loop, inner use only, not for external user

		fMaxFlag				= 1<<18
	};

	/**
	Operation type for the Op() member function.

	the vkType::Op method can be used to perform different operations between buffers of a same type. This can be used for simple types (int, bool, float, String ,etc..)
	as well as complex types such as classes containing members ( the operation is then done member by member )
	*/
	enum EOperation {
		eAdd			= 0,	///< *iResultBuffer = *iParam1Buffer + *iParam2Buffer
		eSubtract		,		///< *iResultBuffer = *iParam1Buffer - *iParam2Buffer
		eMultiply		,		///< *iResultBuffer = *iParam1Buffer * *iParam2Buffer
		eDivide			,		///< *iResultBuffer = *iParam1Buffer / *iParam2Buffer	
		eAddSat			,		///< Only applicable to float values ( or class containing floats) *iResultBuffer = Clamp(*iParam1Buffer + *iParam2Buffer,0,1) 
		eSubSat			,		///< Only applicable to float values ( or class containing floats) *iResultBuffer = Clamp(*iParam1Buffer - *iParam2Buffer,0,1)

		eLerp			,		///< Linear Interpolation : *iResultBuffer = *iParam1Buffer + (*iParam2Buffer - *iParam1Buffer)* alpha	
		ePerSecond		,		///< *iResultBuffer = *iParam1Buffer * alpha

		eBinaryNot		,		///< *iResultBuffer = ~(*iParam1Buffer)
		eBinaryAnd		,		///< *iResultBuffer = *iParam1Buffer & *iParam2Buffer
		eBinaryOr		,		///< *iResultBuffer = *iParam1Buffer | *iParam2Buffer
		eBinaryXor		,		///< *iResultBuffer = *iParam1Buffer ^ *iParam2Buffer

		eMinus			,		///< *iResultBuffer = -*iParam1Buffer
		eInverse		,		///< *iResultBuffer = 1 / *iParam1Buffer

		eLogicalExpMask = 0x100,///< Logical operation mask , Result buffer must be a bool
		eLower			,		///< *iResultBuffer = *iParam1Buffer <  *iParam2Buffer ( Destination buffer must be a bool )
		eLowerEqual		,		///< *iResultBuffer = *iParam1Buffer <= *iParam2Buffer ( Destination buffer must be a bool )
		eEqual			,		///< *iResultBuffer = *iParam1Buffer == *iParam2Buffer ( Destination buffer must be a bool )
		eLogicalAnd		,		///< *iResultBuffer = *iParam1Buffer && *iParam2Buffer ( Destination buffer must be a bool )
		eLogicalOr		,		///< *iResultBuffer = *iParam1Buffer || *iParam2Buffer ( Destination buffer must be a bool )
		eLogicalNot		,		///< *iResultBuffer = !(*iParam1Buffer) ( Destination buffer must be a bool )
		eApproxEqual			///< *iResultBuffer = *iParam1Buffer ~= *iParam2Buffer ( difference is lower than vkConstants::kEpsilon )

	};


	/**
	Templated Types enum

	Some built-in template classes also benefit from the reflexion mecanism. the vkType::GetTemplateKind returns whether the
	type is describing a template
	*/
	enum ETemplateKind {
		eNotATemplate	= 0,	///< This is not a template
		eArray			,		///< vkArray
		eList			,		///< vkList
		eHash			,		///< vkHash
		eTree					///< vkTree
	};

	/** Compatibility between types
	This value is returned by the vkTypeManager::GetRelation(const vkType* iType1,const vkType* iType2,...) method
	to check how two types are related one to the other
	*/
	enum FRelation {
		fSame			= 1<<0,	///< Exact same underlying type , valid for Aliases too : ie a enum is considered as the same than an integer )
		fInherited		= 1<<1,	///< iType1 is a class derived from iType2
		fCast			= 1<<2,	///< A value of type iType1 can be casted to a value of iType2
		fRef			= 1<<3,	///< A value of type iType1 is a pointer/reference to a value of type iType2
		fDeRef			= 1<<4,	///< A value of type iType2 is a pointer/reference to a value of type iType1
		fMultiRef		= 1<<5,	///< A value of type iType1 is a pointer on pointer/reference to a value of type iType2
		fMultiDeRef		= 1<<6,	///< A value of type iType2 is a pointer on pointer/reference to a value of type iType1
		fConstant		= 1<<7,	///< iType1 is a const relationship order (this is cumulable with the Ref/DeRef flags)
		fUnrelated		= 1<<8	///< iType1 and iType2 are completely unrelated...
	};

	/// @cond
	/** 
	Control Flags when generating the CRC of a type
	*/
	enum FCRCFlags {
		fIgnoreName			= 1<<0,	  ///< If present, the name of the type is not taken into account	in the CRC
		fIgnoreMembersNames	= 1<<1,	  ///< If present, the names of members of a struct are not taken into account	in the CRC 	
		fIgnoreEnumNames	= 1<<2,	  ///< If present, the names of member of an enum definition are not taken into account in the CRC
		fIgnoreCopyOptions	= 1<<3,	  ///< If present, the copy options are ignored when computing the CRC
		fUseDefaultValue	= 1<<4,   ///< If present, the type default value taken into account in the CRC
		fIgnoreRefTypes		= 1<<5,   ///< If present, only deref type's CRC is computed in members
		fIgnoreConcreteTypeSize= 1<<6,	  ///< If present, don't count concreteType's size  in CRC
	};
	/// @endcond

	/**
	Availability of a type or method on a given platform or application
	*/
	enum FAccessFlags 
	{	
		// Platforms
		fPC					= 0x00000001,	///< type or function is available on PC (32 & 64 bits)
		FMac				= 0x00000002,	///< type or function is available on Mac (32 & 64 bits)	
		fX360				= 0x00000004,	///< type or function is available on Xbox360
		fPS3				= 0x00000008,	///< type or function is available on PS3
		fWii				= 0x00000010,	///< type or function is available on WII
		fiPhone				= 0x00000020,	///< type or function is available on IPhone
		fWinCE				= 0x00000040,	///< type or function is available on WinCE

		fAllPlatforms		= 0x0000FFFF, ///< 16 bits reserved for platforms

		// Runtimes
		fWeb				= 0x00010000, ///< This type or method is available in the web player 
		fOffline			= 0x00020000, ///< This type or method is available in any other application 
		fAuthoring			= 0x00040000, ///< This type or method is available in the Studio Authoring tool ( used by build system (processors) or ui scripts )

		fAllRuntimes		= 0x00FF0000, ///< 8 bits reserved for runtime
		fNotWeb				= 0x00FE0000, ///< This type or method can not be used in the web player 	

		// Expertise		
		fIntermediate		= 0x01000000, ///< This type or function requires some level of knowledge to be used
		fExpert				= 0x03000000, ///< This type or function is rarely used, should only be used by expert users	
		

		// Restrictions
		fDeprecated			= 0x08000000, ///< symbol is deprecated, and should not be used anymore in future experience
		fNotSchematic		= 0x10000000, ///< symbol is not available in schematic

		// default values
		fInfraOnly				= fAllPlatforms,	///< Type or method can not be used in an experience
		fFullAccess				= fAllPlatforms | fAllRuntimes,	///< Type or method is always available
		
		// Shortcuts used by Binder Generator
		fFullAccessDeprecated	= fFullAccess | fDeprecated,	
		fFullAccessExpert		= fFullAccess | fExpert,
		fFullAccessNotSchematic	= fFullAccess | fNotSchematic,

		fDefaultType			= fFullAccess,
		fDefaultSignature		= 0xF7FFFFFF,
	};

	/// @cond
	/**
	Ctor
	*/
	vkType(vkCtx iCtxHandle);
	/**
	Copy Ctor
	*/
	vkType(const vkType& iSrc);
	/**
	Ctor with params
	*/
	vkType(vkCtx iCtxHandle, const vkString& iName, FQualifier iQualifier);

	/**
	Dtor
	*/
	virtual ~vkType();
	/// @endcond


	/**
	Returns type flags.

	Flags give additional information about the type specificities 

	@see FFlags
	*/
	uint32	GetFlags() const;
	
	/**
	Adds one or several flags to the type.

	@see FFlags
	*/
	void		AddFlags(uint32 iFlags);

	/**
	Removes one or several flags from the type.

	@see FFlags
	*/
	void		RemoveFlags(uint32 iFlags);

	/**
	Returns the name of this type without any namespace information.

	Example: vkStringType::GetName() returns "vkString";
	*/
	const vkString&	GetName() const;


	virtual uint32			GetMemoryOccupation(bool iSelfSize = true, bool iDependencies = false) const;

	/**
	Returns the name of this type with all its parent namespace information.

	Example: vkStringType::GetName() returns "VKernel::vkString";
	*/
	virtual vkString  GetCompleteName() const;


	/**
	Returns the complete name without the namespace.	

	Example: 
		- GetName() on vkToto::SubClass returns "SubClass"
		- GetCompleteName() on vkToto::SubClass returns "Namespace::vkToto::SubClass"
		- GetUnnamespacedName() on vkToto::SubClass returns "vkToto::SubClass"
	*/
	vkString GetUnnamespacedName() const;

	/**
	Tells if this type is plain old data.
	
	True when a type does not have any constructor and can be copied with a simple memcpy().
	*/
	bool	IsPod() const;

	/**
	Tells is this type is completely valid.

	When declaring a type to the type manager, so information maybe missing ( member types not yet known for example).
	In this case the type is marked as "incomplete". Once the member types are also declared , the type declaration can be finalized 
	by calling vkTypeManager::CompleteAllTypes
	*/
	bool	IsComplete() const;

	/**
	If this type is a class or structure this method returns whether it contains virtual methods
	*/
	bool ContainVirtuals() const;

	/**
	Tells is this type is constant.
	*/
	bool IsConst() const;

	/**
	Tells is this type is a pointer,reference or RefPtr to another.
	*/
	bool	IsRef() const;

	/**
	Tells is this type is a pointer.
	*/
	bool	IsPointerOnly() const;

	/**
	Tells is this type is a pointer.
	*/
	bool	IsReferenceOnly() const;

	/**
	Tells is this type is a vkRefPtr to another.
	*/
	bool	IsRefPtrOnly() const;

	/**
	Tells is this type is a vkSmartPtr to another.
	*/
	bool	IsSmartPtrOnly() const;

	/**
	Tells if qualifier exists on this type.
	*/
	FQualifier	GetQualifier() const;

	/**
	Tells if objects of this type can not be instantiated
	*/
	bool IsAbstract() const;

	/**
	Tells if this type can be modified (members added,removed,renamed)

	Typically types declared inside the authoring tool such as behavior or new classes are modifiables.
	*/
	bool  IsModifiable() const;

	/// @cond
	/**
	Tells the system whether every buffers of this type must be registred in order to be tracked.
	*/
	virtual bool MustRegisterBuffer() const;
	/// @endcond

	/**
	Tells if a type is a vkArray template .
	*/
	bool  IsArrayTemplate() const;

	/**
	Tells if a type is a vkHash template .
	*/
	bool  IsHashTemplate() const;

	/**
	Returns whether this type must be saved in its entirety ( all members of a class must be saved for example ).
	*/
	bool IsAtomicSerialization() const;

	/**
	Tells if values from two different type can be copied without any cast operation.

	This functions returns true for two identical types, or for classes which are 
	derived one from another.

	@See Copy,Cast,GetCopyFunction
	*/
	bool  IsSame(const vkType* iType) const;


	/**
	Tells if this type can not be used (from a semantically point of view)
	*/
	virtual bool IsNotReady() const {
		return false;
	}

	/**
	Tells if this type has been defined by a script language (VSL)
	*/
	bool IsFromScriptLanguage() const;

	/**
	Tells if this type is a namespace
	*/
	bool IsNamespace() const;

	/**
	Returns the namespace in which this type was declared
	*/
	virtual vkClassType*  GetOwnerNamespace() const  = 0;

	/// @cond
	/**
	Set the namespace to which this type should belong
	*/
	virtual void SetOwnerNamespace(vkClassType* iOwnerNamespace);
	/// @endcond
	
	/** 
	Overridden to display the parent namespace if it is a class
	*/
	virtual vkString GetObjectDisplayName() const;

	/**
	Gets a short version of the type's name intended for display only.
	Default implementation simply returns GetName().
	Derived implementations may override this to change the displayed name
	when inspected by a property view.
	*/
	virtual vkString GetShortDisplayName() const;

	/**
	Tells if values from two different type can be copied without any cast operation.
	
	This methods compares two structure and returns true is they 
	have the same memory storage. 

	For example the two following structure are considered equivalent 
	@code
	Struct aStruct {
	int32 b;
	float c;
	}
	and 
	Struct bStruct {
	int32 val;
	float s;
	}
	@endcode
	*/
	virtual bool  IsSameContent(const vkType* iType) const;

	/**
	Returns whether this type is derived from another (directly or indirectly)
	*/
	virtual bool IsDerivedFrom(const vkType* iType) const;

	bool IsInstanceKindOf(const vkType* iType) const
	{
		return ((iType == this) || IsDerivedFrom(iType));
	}

	/**
	Returns true if the resource adapter owns the created object, false otherwise.

	@param iObject Pointer to the created object.

	@return True if the resource adapter owns the created object, false otherwise.
	*/
	virtual bool IsResourceAdapterOwningObject(const void* /*iObject*/) const
	{
		return true;
	}

	/**
	Returns an unqualified Type
	
	If this type if a qualified type this method returns the type without the qualifier
	otherwise it returns itself.
	*/
	virtual vkType* GetUnQualifiedType() const;

	/**
	Returns a qualified Type
	
	@code
	//stringType->GetQualifiedType(fRefPtr);


	@endcode

	If this type if a qualified type this method returns the type without the qualifier
	otherwise it returns itself.
	*/
	virtual vkType* GetQualifiedType(FQualifier iQualifier,const vkString& iUsageName = VK_NS,uint32 iDimension = 0, const vkType* iOverridenBaseType = 0) const;

	/**
	For template class (vkArray,vkHash,etc..), returns the type of template class this is
	*/
	virtual ETemplateKind GetTemplateKind() const;


	/**
	Returns true if this is kind of the other type.
	*/
	bool IsDerivedFrom(const vkCtxTypePtr& iOtherType) const;

	/**
	Computes a string representation of the type declaration in 
	pseudo C code.
	*/
	virtual void ComputeTypeDeclaration(vkString& oString) const;

	/**
	Returns the actual sub type to be instantiated.

	This is used when saving an abstract struct vktype
	*/
	virtual const vkType*	GetInstanceType(const void* iInstance) const;

	/**
	Returns the resource type.

	@see vkResourceManager::EResourceType
	*/
	virtual vkResourceCategory GetInstanceResourceCategory(const void* iInstance) const;

	/**
	Returns the type that represents a weak pointer to a value this type.
	*/
	vkType* GetWeakPointerType(const vkString& iUsageName =VK_NS) const;

	/**
	Returns the type that represents a reference to a value this type.
	*/
	vkType* GetReferenceType(const vkString& iUsageName =VK_NS) const;

	/**
	Returns the type that represents a vkRefPtr of a a value of this type.
	*/
	vkType* GetRefPtrType(const vkString& iUsageName = VK_NS) const;

	/**
	Returns the type that represents a managed pointer to this type.
	Depending on the type, it may be AutoPtr, RefPtr, SmartPtr or even a new
	kind of managed pointer defined by 3rd parties.
	*/
	virtual vkType* GetManagedPointerType(const vkString& iUsageName = VK_NS, const vkType* iOverridenBaseType = 0) const;

	/**
	Returns the unqualified instance specified by iInstance.
	Default implementation simply returns iInstance.
	Pointer types return the object being pointed.
	@param iInstance the qualified instance
	@return the unqualified instance
	*/
	virtual void* GetUnqualifiedInstance(const void* iInstance) const;

	/**
	Returns the type that represents a const pointer to a value of this type.
	*/
	vkType* GetConstRefType(const vkString& iUsageName =VK_NS) const;
	vkType* GetDynArrayType(const vkString& iUsageName =VK_NS) const;	
	vkType* GetStaticArrayType(const uint32 iDimension,const vkString& iUsageName =VK_NS) const;
	vkType* GetAutoPtrType(const vkString& iUsageName =VK_NS) const;
	vkType* GetConstType(const vkString& iUsageName =VK_NS) const;

	/**
	If this type if a const this method returns it the type no const. 
	*/
	virtual const vkType* GetDeConstType() const;

	/**
	If this type if a pointer (or reference) to another type 
	this method returns it. 
	*/
	virtual const vkType* GetDeRefType() const;

	/**
	Returns the type that is used to store the data. Most of the time
	this function returns this at the exception of enum and flag which are considered to
	be stored as a uint32 type
	*/
	virtual const vkType* GetStorageType() const;

	/**
	Returns the size taken in memory by a object of this type .
	*/
	virtual int32 GetSize() const  = 0;

	/**
	Gets the depth of inheritance of the class described by this type.
	0 means the class is root.
	@return the inheritance's depth
	*/
	virtual uint32 GetInheritanceDepth() const;
	
	/**
	Helper static method to generate a default ID.

	The ID is made of a random number and the current physical address in hexa.
	*/
	static vkString GenerateDefaultID(const void* iInstance);

	/**
	Gets the id of the instance.

	Default implementation uses vkType::GenerateDefaultID.
	*/
	//GetInstanceResourceID
	virtual vkString GetInstanceID(const void* iInstance) const;

	/**
	Gives all information to retrieve the resource in an asset.

	Default implementation uses vkType::GenerateDefaultID.
	*/
	virtual bool GetResourceLocation(const void* iInstance, vkAssetPtr& oResourceAsset, vkString& oResourceID) const;

	/**
	Allocate some space to store an instance of this vkType.

	Default implementation : use the default memory allocator.
	Must call Construct on the buffer to initialize the object
	*/
	virtual void* Allocate() const;

	/**
	Deallocate the space taken by the instance that was allocated previously with Allocate
	*/
	virtual void Deallocate(void* iInstance) const;

	/**
	Given a parameter buffer , this method calls the appropriate constructor for this type.
	*/
	virtual void Construct(void* iParamBuffer) const = 0;

	/**
	Given a parameter buffer , this method calls the appropriate destructor for this type.
	*/
	virtual void Destruct(void* iParamBuffer) const = 0;

	/**
	Allocates and construct a new instance.

	Default implementation : Call Allocate, then Construct.

	@param iSrcBuffer optional buffer containing value to recopy
	*/
	virtual void* New(const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual void* NewUnresolved(const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual void* New() const;

	/**
	Destruct and deallocate the instance.

	Default implementation : Call Destruct, then Deallocate.
	*/
	virtual void Delete(void* iInstance) const;

	/**
	Given a parameter buffer, a source buffer and a source type, this method calls the appropriate copy constructor for this type.

	If the source type is not given, the function assumes it is from the same type as the destination.
	*/
	virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;
	virtual void CopyConstructUnresolved(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;

	/**
	Copy a buffer to another which are of compatible types

	Given a parameter buffer and a source buffer , this method copy the content of iSrcBuffer inside iParamBuffer.
	Both buffers must be using the same type (or derived one)
	*/
	virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;

	/**
	Copy a buffer to another which are of compatible types

	This method differs from the copy method for pointed types such as components
	which may become invalid (vkUnresolvedComponent), the copy method try to resolve
	an unresolved component to a valid one, if it fails it copy a null pointer.
	This method do not try to resolve the component

	*/
	virtual void CopyUnresolved(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;

	/**
	Given a parameter buffer and a source buffer , this method tests if the content of iOpBuffer1 equals iOpBuffer2's one.
	Default implementation reroutes to Compare.
	@return true if the 2 values are considered as the same
	*/
	virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const;
	/**
	Given a parameter buffer and a source buffer , this method tests if the content of iOpBuffer1 equals iOpBuffer2's one.
	This is specific to test values in the context of configurations (typically compares UCIs instead of pointer to objects for example)
	Default implementation reroutes to Equals.

	@param iContext the object to which the configuration is applied (used when comparing component-type member values)
	@return true if the 2 values are considered as the same
	*/
	virtual bool EqualsForConfiguration(const void* iOpBuffer1, const void* iOpBuffer2, const vkObject* iContext=NULL) const;
	

	/**
	Given a parameter buffer and a source buffer , this method compare the content of iSrcBuffer inside iParamBuffer
	using the appropriate function.

	The function returns 0 if the two value are equal , a positive value if value1 is greater than value 2 , a negative value otherwise
	*/
	virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const;

	/**
	Given a parameter buffer, this method generates a hash value, usable for example to create
	hash tables.
	*/
	virtual uint32 Hash(const void* iParamBuffer) const;

	/**
	Copy from a buffer to another checking for any cast.

	Given a parameter buffer and a source buffer , this method copy the content of iSrcBuffer inside iDstBuffer
	using the appropriate casting or copying function to convert from iSrcType to this type.
	
	This function calls GetCopyFunction to find the appropriate method and then call CallCopyCast
	@See Copy,Cast,GetCopyFunction
	*/
	bool	Cast(void* iDstBuffer,const vkType* iSrcType,const void* iSrcBuffer) const;

	/**
	Tells if we can replace a instance registered in the resource manager  by a new one.
	This method when attempting to add an object to the resource manager whose name and category
	clash with an existing one. If this method returns true the old instance is replaced by the one.
	Otherwise an error is raised.
	Default implementation returns true.
	@return true if replacement is authorized.
	*/
	virtual bool IsReplacementAuthorizedInResourceManager() const;

	/**
	Given a parameter buffer and a string, this method reads the string to fill the oBuffer.

	@param iInternal must be true when the type is loaded as a part of a whole. Therefore
	it should look for markers ("" for vkString, {} for structs, etc.)
	*/
	virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
	/**
	Given a parameter buffer and a string, this method creates
	the string from the content of iBuffer.

	@param iInternal must be true when the type is loaded as a part of a whole. Therefore
	it should look for markers ("" for vkString, {} for structs, etc.)
	*/
	virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
	virtual error SavePointedObjectToString(const vkStringSaveArgs& iArgs) const;


	/**
	Reads the content of an XML file being read into the oBuffer.

	iArgs.buffer can be :
		- If (New() previously returned the object) => void* = TObject*
		- If (New() previously returned 0) => void* = TObject**

	@return Error code.
	*/

	
	/**
	Returns a function to copy or cast a parameter from iSrcType to this Type.

	This function returns NULL if iSrcType can not be cast or copied to this
	type, otherwise it returns a function that can be used to copy a value
	using CopyFunction(type, oDstBuffer, iSrcType, iSrcBuffer);
	This method is useful if you would like to store the function pointer
	to copy a value frequently without finding the appropriate cast function
	each time.
	@See Cast,Copy
	*/
	vkCopyFunction GetCopyFunction(const vkType* iSrcType) const;

	/**
	Reset a buffer to its default value, if any.
	*/
	virtual void ResetToDefault(void* iParamBuffer) const;

	/**
	Returns the alignement rules for this type.
	*/
	virtual uint32 GetAlignementSize() const;

	/**
	Returns a new type that is the exact copy of this type.

	Modifiable types MUST implement this method to support the addition/removal of data.
	*/
	const vkType* Clone() const;
	virtual vkModifiableTypeData* GetModifiableData() const;

	virtual void _PrepareDeletion_1_DeleteAllocatedBuffers();
	virtual void _PrepareDeletion_2_RemoveReferences();
	virtual void _UncompleteType();

	virtual vkCopyFunction _GetCastFromFunction(const vkType* iDstType) const;
	virtual vkCopyFunction _GetCastToFunction(const vkType* iSrcType) const;

	// Some objects can be deleted at runtime, but it may exist
	// a pointed version that store permanently their value
	virtual void  EnsurePersistentInstance(void* iStorageBuffer) const;
	virtual bool  IsInstancePersistent(void* iStorageBuffer) const;

	// Try to complete a type 
	// If the type definition is complete it may rely on other types and so ensure
	// they are all complete
	// A type that has become uncomplete must register itself 
	virtual bool _CheckIfComplete() = 0;
	virtual bool _CompleteType() = 0;
	// Returns true if the type was not yet flagged as ToBeCompleted
	bool _BecomesIncomplete();

	// Ensure that this type is modifiable
	// otherwise change its type to become modifiable
	virtual void SwitchToModifiableType();

	void SetIsRegister(bool iRegister);
	/**
	Number of sub-field.
	
	- for a struct returns the number of members
	- for a static or dynamic array returns the number of elements
	*/
	virtual uint32 GetFieldCount(void* iParamBuffer = 0) const;

	virtual const vkType* GetFieldType(uint32 iFieldIndex, void* iParamBuffer = 0) const;
	virtual void GetFieldName(uint32 iFieldIndex, void* iParamBuffer, vkString& oName) const;
	virtual bool GetFieldDescription(uint32 iFieldIndex, void* iParamBuffer, vkString& oDescription) const;
	// -1 when none found
	virtual int32 GetFieldByName(const vkString& iName, void* iParamBuffer = 0) const;
	
	virtual bool Op(EOperation iOperation,const void* iResultBuffer,const void* iParam1Buffer, const void* iParam2Buffer, float iAlpha = 0) const;

	// Checks that an instance of this type is still valid
	// if not try to return a valid pointer 
	virtual void* CheckInstanceValidity(void* iInstanceBuffer) const;

	virtual error		SetResourceID(const vkString& iID);

	uint32	GetAccessFlags() const;
	void	SetAccessFlags(uint32 iFlags);

	uint32	v8EditFlags;

	VK_INLINE void SetV8EditFlags(uint32 iEditFlags){v8EditFlags = iEditFlags;}
	VK_INLINE uint32 GetV8EditFlags() const{return v8EditFlags;}

#if defined(EXPERIENCEKERNEL)
	//NLS
private :
	vkString	m_NLSKey;				//Key used to retrieve the appropriate localized function description in an associated CATMsgCatalog

public :
	VK_INLINE void SetNLSKey(const char* iKey){ 
		m_NLSKey = vkString(iKey); 
	}

	VK_INLINE const vkString& GetNLSKey(){
		return m_NLSKey;
	} 

	 


#endif


	/**
	Some constants used in XML Serialization.
	*/
	static const vkString	kIDAttributeName;			///< "id"
	static const vkString	kScopeAttributeName;		///< "scope"
	static const vkString	kGlobalValue;				///< "global"
	static const vkString	kAssetValue;				///< "asset"
	static const vkString	kVolatileValue;				///< "volatile"
	static const vkString	kRefAttributeName;			///< "ref"
	static const vkString	kCopyAttributeName;			///< "copy"
	static const vkString	kTypeAttributeName;			///< "type"
	static const vkString	kCreateAttributeName;		///< "create"
	static const vkString	kOptionalAttributeName;		///< "optional"
	static const vkString	kOverrideAttributeName; 	///< "override"
	static const vkString	kReplaceAttributeName;  	///< "replace"
	static const vkString	kLoadPolicyAttributeName;	///< "loadPolicy"
	static const vkString	kLoadPolicyOffline;			///< "offline"
	static const vkString	kLoadPolicyStream;			///< "stream"
	
/// @cond
	static vkCtxTypePtr  s_OperationType;	
//----------------  Members ----------------------------------
protected :
		friend class vkKernelModule;
mutable uint32					flags;						/// misc flags
		uint8					qualifier;					/// qualifier if relevant (qualified type)
		vkResourceCategory		instanceResourceCategory; 	/// resource category of instances using this type
mutable vkTypePtr				nextQualifiedType;			/// list of qualified types using this type..
															/// These types are only registered on this type
															/// and not to the global type manager

		uint32					accessFlags;				/// access flags
													

//----------------  protected methods  ----------------------------------
protected:

	virtual void			_Destroy();
	virtual error			_SetAsset(vkAsset* iAsset);
	virtual const vkType*	_Clone(bool iCopy = true) const;
	static bool		_GetExternalResourceLocation(const void* iObject, const vkType* iObjectType, vkAsset* iCurrentAsset, vkAssetPtr& oResourceAsset, vkResourceCategory& oCategory, vkString& oResourceID);
		error			_CopyResource(void* oDstBuffer, const vkType* iDstType, vkResource* iResource) const;
	static vkResource*		_RegisterResource(void* iInstance, const vkType* iType, vkAsset* iAsset, EResourceScope iScope, const vkString& iID, vkResourceCategory iCategory);
	void _AddQualifiedType(vkType* iQualifType) const;
	vkType* _CreateQualifiedType(FQualifier iQualifier,uint32 iDimension, const vkType* iOverridenBaseType = 0,bool iAdd = true) const;
	virtual vkRefPtrType* _CreateRefPtrType(const vkString& iName) const;
	virtual vkWeakPointerType* _CreateWeakPtrType(const vkString& iName) const;
	vkType* _FindQualifiedType(FQualifier iQualifier,uint32 iDimension) const;
	void _MarkTypeAsIncomplete(vkType* iQualifType) const;
	 
	static vkString		s_Tabs; 
	static void			_IncTab();
	static void			_DecTab();

	/// @endcond

};

#include "vkType.hpp"

}  // NameSpace VKernel

namespace VKernel
{


/**
@internal
standard implementation of functions.
*/
template <class T>
class vkStdTypeFunctions
{
public :

	static inline void* New()
	{
		return new T;
	}

	static inline void Delete(void* iBuffer)
	{
		delete (T*) iBuffer;
	}

	static inline void Construct(void* iBuffer)
	{
		::new (iBuffer) T;
	}

	static inline void Destruct(void* iBuffer)
	{
		((T*) iBuffer)->~T();
	}

	static inline void CopyConstruct(void* iDstBuffer, const void* iSrcBuffer)
	{
		::new (iDstBuffer)T((const T&)*((T*)iSrcBuffer));
	}

	static inline void Copy(void* iDstBuffer,const void* iSrcBuffer)
	{
		*((T*) iDstBuffer) = *((const T*) iSrcBuffer);
	}

	static inline int32 Compare(const void* iDstBuffer, const void* iSrcBuffer)
	{
		return (*((const T*) iDstBuffer) == *((const T*) iSrcBuffer)) ? 0 : -1;
	}

protected :
	vkStdTypeFunctions() {}
};

#if defined(_MSC_VER)
#pragma warning(default:4355) // this used in base member initializer list
#endif

} // NameSpace VKernel

#endif // __vkType_h

