/**
@file

This file defines the vkTypeManager class.

@COPYRIGHT

@autor: Aymeric Bard, Romain Sididris, Edwin Razafimahatratra
*/

#if !defined(__vkTypeManager_h)
#define __vkTypeManager_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkHash_h)
	#include "vkHash.h"
#endif
#if !defined(__vkType_h)
	#include "vkType.h"
#endif 
#if !defined(__vkEventsChannel_h)
#include "vkEventsChannel.h"
#endif
#if !defined(__vkFunctionPtr_h)
	#include "vkFunctionPtr.h"
#endif
#if !defined(__vkContext_h)
	#include "vkContext.h"
#endif
#if !defined(__vkClassType_h)
#include "vkClassType.h"
#endif 
#if !defined(__vkArray_h)
#include "vkArray.h"
#endif

namespace VKernel
{

// Forward Declarations
class vkParameter;
class vkRefParameter;
class vkFlagType;
class vkKernelModule;
class vkCallingConvention;
struct vkSignature;
class  vkClassType;
class  vkEnumType;
class vkEvent;

/**
Computes the offset of a member inside a given struct/class

@see vkTypeManager::DeclareMember
*/
#define VK_OFFSETOF(className, memberName) (int32)offsetof(className,memberName)

#define PREFIX_CONSTRUCTOR_FUNC								"__new"

#define GET_MEMBER_OFFSET(className, memberName) \
	(int32) offsetof(className,memberName) \

#if defined(VK_TARGET_WINDOWS)
	#define GET_MEMBER_OFFSET_FOR_REFERENCE(resultOffset,className,memberName)	\
	{	\
		typedef className classWithoutScope;	\
		__asm	\
		{	\
			__asm mov ecx,0	\
			__asm lea eax,[ecx]classWithoutScope.memberName	\
			__asm mov resultOffset,eax	\
		}	\
	}
#elif defined(VK_TARGET_MACOSX) || defined(VK_TARGET_ANDROID) || defined(VK_TARGET_IPHONE) || defined(VK_TARGET_LINUX) || defined(VK_TARGET_WINCE) 
	#define GET_MEMBER_OFFSET_FOR_REFERENCE(resultOffset,className,memberName)	\
		resultOffset = offsetof(className,memberName)
#else
	#error "This macro does not exist for this platform."			
#endif

// TODO : Change in VK_ something
#define DECLARE_MEMBER(member, memberType, memberCname)	iTm.DeclareMember(member, memberType, GET_MEMBER_OFFSET(ThisClass, memberCname))
#define DECLARE_MEMBER2(member, memberType)	iTm.DeclareMember(VK_AS(#member), memberType, GET_MEMBER_OFFSET(ThisClass, member))
#define DECLARE_MEMBER3(member, memberType,flags)	iTm.DeclareMember(VK_AS(#member), memberType, GET_MEMBER_OFFSET(ThisClass, member),flags)
#define DECLARE_MEMBER_CAT(member, memberType, memberCat)	iTm.DeclareMember(VK_AS(#member), memberType, GET_MEMBER_OFFSET(ThisClass, member),0,memberCat)
#define DECLARE_FLAG_VALUE(flagValue) iTm.DeclareFlagsValue(VK_AS(#flagValue), flagValue)
#define DECLARE_ENUM_VALUE(enumValue) iTm.DeclareEnumValue(VK_AS(#enumValue), enumValue)

/**
Type Manager.
*/

class VKKERNEL_API vkParseTypeHandler : public vkHeapObject
{
public:
	virtual ~vkParseTypeHandler();
	virtual error ParseType(const vkType* iType) = 0;
};

// structures to batch register
struct vkMemberDef
{
	const char8*	name;
	const char8*	type;
	int8	nameLength;
	int8	typeLength;
	uint16	offset;
};

struct vkEnumDef
{
	const char8*	name;
	int16	nameLength;
	int16	value;
};

struct vkCMethodDef
{
	const char8*	sign;
	int16	signLength;
	int16	type;
	uint32	acessFlags;
};

struct vkCMethodPtr
{
	vkFunctionPtr	ptr;
};

struct vkTypeExtraData 
{
	const char8*		name;
	int8		nameLength;
	const char8*		tags;
	int8		tagsLength;
	uint32		accessFlags;
};


class VKKERNEL_API vkTypeManager : public  vkHeapObject, public vkContextedObject
{
	friend class  vkType;
	friend class  vkEnumType;
	friend struct vkSignature;
	friend class  vkClassType;
	friend class  vkConcreteType;
	friend struct vkArgument;
	friend class  vkKernelModule;
	friend class  vkTypeType;

	friend class  vkTypeManagerTest;

	template <class T>
	friend const vkType* vkGetType(vkCtx iCtx);

	VK_DECLARE_CTXSINGLETONCONCRETE(vkTypeManager);
public:

	enum EGetRelationOptions
	{
		fRefAndPointerMeanSame	= 1 << 0,
		fDerefOnce				= 1 << 1,
		fDerefTwice				= 1 << 2,
		fDerefMoreThanTwice		= 1 << 3
	};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// TYPE REGISTRATION
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Prototypes for Type registration/unregistration
	typedef void (*TRegisterType)(vkTypeManager& iTm);
	typedef void (*TUnregisterType)(vkTypeManager& iTm);
	typedef vkHash<vkString,vkString>			String2String;

	//////////////////////////////////////////////////////////////////////////
	// Un-Registering a type 
	void MarkAsNotReady(vkType* iType);

	//////////////////////////////////////////////////////////////////////////
	// Un-Registering a type 
	void UncompleteType(const vkString& iName);
	void UncompleteType(vkType*  iType);


	void UnregisterType(const vkString& iName);
	void UnregisterType(vkType*  iType);

	void UnregisterModifiableTypes(vkArray<vkTypePtr>& iTypes);
	
	//////////////////////////////////////////////////////////////////////////
	// Re-Registering a type 
	bool CompleteType(vkType* iType);

	/**
	Tells the relations between two types.

	@return A vkType::FRelation combination
		- if both type are the sames
		- fInherited if iType1 is a class derived from iType2
		- fCast if none of the above are true but a value of type iType1
		can be casted to a value of type iType2
		- fUnrelated if values are unrelated
	*/
	uint32 GetRelation(const vkType* iType1,const vkType* iType2,vkCopyFunction* oCastFct =0, uint32 iRelationOptions = 0) const;
	const vkType* PhysicalDeref(const vkType* iType) const;

	/**
	Tells the type manager that multiple type registration will 
	be done, and that a critical section should be created for the 
	whole operation. 
	Note: This may freeze other thread that are also being registering types
	*/
	void BeginMultipleRegistrations();
	void EndMultipleRegistrations();

	////////////////////////////////////////////////////////////////////////////////
	// Asset (enclose the types registration into a registering asset)
	void BeginRegisteringAsset(vkAsset* iAsset);
	void EndRegisteringAsset();

	void BeginRegisteringTag(const vkString& iTag);
	void EndRegisteringTag();

	//////////////////////////////////////////////////////////////////////////
	// Namespace
	
	// Begin a new (or modify an existing) namespace)
	vkClassType* BeginNamespace(const vkString& iName);
	void BeginNamespace(const vkClassType* iNamespace);
	void EndNamespace();

	/**
	This adds a name a type can be retrieved from.

	- For example "vkString" (C++ class name) and "String" (VSL name) both refer to 
	the same underlying type so both can be used. AddNameAlias("vkString","String");
	- This also the choice for typedef definitions
	*/
	void AddNameAlias(const vkString& iName,const vkString& iExistingTypeName);
	void AddObsoleteType(const vkString& iObsoleteTypeName,const vkString& iNewTypeName);
	bool IsObsoleteType(const vkString& iName) const;



	//-------------------------------------------
	// Common to all BeginType / EndType
	// This can be called before or between
	void DeclareDefaultValue(const vkString& iStringValue, vkType* iOwnerType = 0);
	void DeclareDefaultValueBuffer(const void* iValueBuffer,vkType* iOwnerType = 0);
	void DeclareDefaultValueBuffer(bool iCreatebuffer,vkType* iOwnerType = 0);


	//////////////////////////////////////////////////////////////////////////
	// Structure/Class registration

	/**
	Specifies packing alignment for structure, union, and class members
	*/
	void SetStructMemberPacking(uint32 iPacking = 8);


	/**
	Starts registering a structure or a class.

	If no size is given it will be computed according to the information
	given about members and base class.

	If a structure is not completely described by its members, that is for example that a member 
	is not declared because it should not be exposed you must provide the size for the complete structure.
	The size must take base classes into account.

	Once all the members are declared the end of the structure registration occurs on EndClass.
	The main difference between class and structure in the vkTypeManager is that class are allowed to declare 
	methods and sub-types.
	*/
	vkType* BeginClass(const vkString& iName, const vkType* iBaseClass = 0,int32 iSize = 0, vkType* iOwnerNamespace = 0 , vkNewFunctionPtr newFunction = 0, uint32 iSpecialMethods = 0);
	vkType* BeginClass(const vkString& iName, const vkCtxTypePtr& iBaseClass,int32 iSize = 0, vkType* iOwnerNamespace = 0 , vkNewFunctionPtr newFunction = 0, uint32 iSpecialMethods = 0);
	vkType* BeginClass(const vkString& iName, const vkString& iBaseClassName,int32 iSize = 0, vkType* iOwnerNamespace = 0 , vkNewFunctionPtr newFunction = 0, uint32 iSpecialMethods = 0);
//	vkType* BeginComponent(vkString iName, vkComponentType* iType, const vkType* iParentType = 0);

	vkType* BeginCustomType(vkType* iTypeToRegister, vkType* iOwnerNamespace = 0);
	vkType* BeginCustomType(vkClassType* iTypeToRegister, vkType* iOwnerNamespace, uint32 iSpecialMethods);
	void EndCustomType(vkType* iTypeToRegister);
	
	vkType* RegisterCustomType(vkType* iTypeToRegister, vkType* iOwnerNamespace = 0);

	// Optional : constructor and copy operators
	void DeclareParent(const vkString& iParentName);
	// If no method is declared but the class is using virtual methods
	// they should be given in order the member offset to be computed 
	void DeclareVirtualMethods();
	void DeclareAsModifiable();

	/**
	Declares a class or structure member.

	The members must be declared in the order they appear in the structure.
	If iOffset is not given, Parent and virtual methods must be declared BEFORE any member is declared 
	for offset information to be correctly computed.
	Furthermore if iOffset is given, it must be taking into account the parent class and/or virtual method :

	For example
	@code
		class A {
			int m_a;
		};

		class B : public A {
			int m_b;
		}
		class C : public A {
			virtual anymethod();
			virtual anymethod2();
			int m_b;
		}
	@endcode

	The offset of m_b in class B is 4 (sizeof(m_a));
	The offset of m_b in class C is 8 (sizeof(m_a) + virtual table pointer (4) );
	*/
	void DeclareMember(const vkString& iName, const vkString& iType, int32 iOffset = -1, uint32 iFlags = 0, const vkString& iCategory = VK_NS, vkMemberValidator iValidator = 0, const vkString& iDescription = VK_NS);
	void DeclareMember(const vkString& iName, const vkType* iType, int32 iOffset = -1, uint32 iFlags = 0, const vkString& iCategory = VK_NS, vkMemberValidator iValidator = 0, const vkString& iDescription = VK_NS);
	void DeclareMember(const vkString& iName, const vkCtxTypePtr& iTyper, int32 iOffset = -1, uint32 iFlags = 0, const vkString& iCategory = VK_NS, vkMemberValidator iValidator = 0, const vkString& iDescription = VK_NS);

	void DeclareStaticMember(const vkString& iName, const vkString& iType, void* iStaticVarAddress = 0, vkType* iHolderType = 0, uint32 iFlags = vkMember::fMemberDoNotDisplay|vkMember::fMemberIsReadOnly|vkMember::fMemberDisplayInCompletion, const vkString& iCategory = VK_NS, vkMemberValidator iValidator = 0, const vkString& iDescription = VK_NS);
	void DeclareStaticMember(const vkString& iName, const vkType* iType, void* iStaticVarAddress = 0, vkType* iHolderType = 0, uint32 iFlags = vkMember::fMemberDoNotDisplay|vkMember::fMemberIsReadOnly|vkMember::fMemberDisplayInCompletion, const vkString& iCategory = VK_NS, vkMemberValidator iValidator = 0, const vkString& iDescription = VK_NS);

	/**
	A property is a special kind of member.

	There is no physical storage for a property but its value can read or written
	using class specific methods.

	To declare a property in class declaration you should first declare one or two method
	respectively named GetXXX and SetXXX where XXX is the name of the property that will 
	be bound.
	*/
	void	DeclareProperty(const vkString& iName, uint32 iFlags = 0, vkType* iHolderType = 0 , const vkString& iCategory = VK_NS, vkMemberValidator iValidator = 0, const vkString& iDescription = VK_NS);
	void	DeclareProperty(const vkString& iName, const vkString& iGetFunctionName, const vkString& iSetFunctionName, uint32 iFlags = 0, vkType* iHolderType = 0, const vkString& iCategory = VK_NS, vkMemberValidator iValidator = 0, const vkString& iDescription = VK_NS, bool iEmulatedGetter=false, bool iEmulatedSetter=false);

	/*
		@param iSignature : In some cases (VSL) we should be able to give a created signature to the method declaring function
	*/
	const vkSignature*	DeclareCMethod(const vkString& iMethodDescription, const vkFunctionPtr& iPointer,vkFunctionPtr::ECallType = vkFunctionPtr::eSTD, vkType* iOwnerNamespace = 0, vkSignature* iSignature = 0, vkType::FAccessFlags iAccessFlags = vkType::fFullAccess);
	const vkSignature*	DeclareCFunction(const vkString& iFunctionDescription, const vkFunctionPtr& iPointer,vkFunctionPtr::ECallType = vkFunctionPtr::eCDECL, vkType* iOwnerNamespace = 0, vkType::FAccessFlags iAccessFlags = vkType::fFullAccess);
	const vkSignature*  DeclareCFunction(vkSignature* iSignature, const vkString& iFunctionDescription, const vkFunctionPtr& iPointer,vkFunctionPtr::ECallType iCallType = vkFunctionPtr::eCDECL, vkType* iOwnerNamespace = 0, vkType::FAccessFlags iAccessFlags = vkType::fFullAccess);
	
	// Batch declaration (for binder generators)
	void DeclareTypesExtraData(vkTypeExtraData* iTypesData, uint32 iDataCount);
	void DeclareMemberBatch(vkMemberDef* iDef, uint32 iDefCount);
	void DeclareCMethodBatch(vkType* iOwnerType, const vkCMethodDef* iDef, const vkCMethodPtr* iPtr, uint32 iDefCount);
	vkType* DeclareEnumBatch(const vkString& iName, const vkEnumDef* iDef, uint32 iDefCount);

	void ModifyTypeFlags(uint32 iFlagsToSet, uint32 iFlagsToRemove);

	void DeclareInstanceResourceCategory(vkResourceCategory iResourceCategory);
	void DeclareInstanceResourceCategory(const vkCtxObject<vkResourceCategory>& iResourceCategory);

	void DeclareNewFunction(vkNewFunctionPtr iNewFunctionPtr);
	void DeclareDeleteFunction(vkDeleteFunctionPtr iDeleteFunctionPtr);

	void			EndClass();

	bool			RemoveFunction(const vkString& iFunctionDescription,vkClassType* iOwnerNamespace = 0);
	bool			RemoveFunction(const vkSignature& iSignature,vkClassType* iOwnerNamespace = 0);
	vkSignature*	GetExistingSignature(const vkString& iFunctionDescription,vkClassType* iOwnerNamespace = 0);
	vkSignature*	GetExistingSignature(const vkSignature& iSignature,vkClassType* iOwnerNamespace = 0);

	//////////////////////////////////////////////////////////////////////////
	//Enum registration
	vkType*	BeginEnum(const vkString& iName, vkType* iOwnerNamespace = 0);
	void		DeclareEnumValue(const vkString& iName,int32 iVal,vkEnumType* iEnum = NULL);
	void		EndEnum();

	//////////////////////////////////////////////////////////////////////////
	//Flags registration
	vkType*	BeginFlags(const vkString& iName, vkType* iOwnerNamespace = 0);
	void		DeclareFlagsValue(const vkString& iName,int32 iVal,vkFlagType* iFlag = NULL);
	void		EndFlags();

	//////////////////////////////////////////////////////////////////////////
	// Description methods
	//////////////////////////////////////////////////////////////////////////
	vkType*	GetType(const vkString& iName,uint32 iOptions = fNoOptions);
	
	// This do not clear the given array before filling it
	uint32		GetDerivedTypes(const vkType* iBaseType, vkArray<vkTypePtr>& oTypes, bool iDiscardAbstractTypes = false);


	// Shortcuts for access to frequently used type...
	// They can be accessed with template using vkGetType
	const vkType* GetNullType() const;
	const vkType* GetErrorType() const;
	const vkType* GetCtxType() const;

	const vkType* GetAttributeType() const;
	const vkType* GetAttributesSetType() const;
	const vkType* GetUnknownType();

	vkClassType* GetGlobalNamespace();
	vkClassType* GetCurrentNamespace();
	vkType* GetTypeBeingRegistered();
	const String2String& GetAliases();

	//////////////////////////////////////////////////////////////////////////
	// Cast operators 
	//////////////////////////////////////////////////////////////////////////
	
	void DeclareCastFunction(const vkType* iSrcType,const vkType* iDstType,vkCopyFunction iCastFct);
	void DeclareCastFunction(const vkString& iSrcTypeName,const vkString& iDstTypeName,vkCopyFunction iCastFct);


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// BINDING
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// retrieving a function given its name...
	vkSignature* GetFunction(const vkString& iFunction,uint32 iOptions = fNoOptions);

	/**
	Fills a function signature structure given its description string.

	A function declaration is supposed to meet the C/C++ function declaration requirements :

	<pre>
	[Static][virtual](returnValue) FunctionName(argumentDesc,argumentDesc,...) [Const qualifier]
	returnValue = [const]type[*][&]
	argumentDesc = [const]type[*][&] [variableName [= value]]
	</pre>

	From a simple as: void SetScale(float iScale);
	to more complex things like: virtual float vkMyClass::ComputeAddition(float iA,const vkVec3& iB) const;

	@param iFunctionDescription Complete function declaration string.
	@param oSignature A vkSignature to be filled with the function signature.
	@param oFunctionName The function name extracted from the above description.
	*/
	bool	CreateSignatureFromString(const vkString& iFunctionDescription,vkSignature& oSignature, vkClassType* iOwnerNamespace,vkFunctionPtr::ECallType iCallType);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// PARAMETERS CREATION
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
	
	/**
	Parameter creation method.

	If you specify iLink = true, cast the resulting parameter into a 
	vkParameterLinked to use its specific methods related to links.

	@param iName name of the type of the parameter to create.
	@param iType type of the parameter to create.

	@return A pointer on the parameter created, 0 if the type was invalid or not registered.

	@see DestroyParameter
	*/
	vkParameter*	CreateParameter(const vkString& iName);
	vkParameter*	CreateParameter(const vkType* iType);

	/**
	Register the address of a buffer that was created 
	with a type so that it can be automatically reallocated and destroyed, 
	when the type is changed or destroyed.
	*/
	void RegisterBuffer(const vkType* iType, void** iBufferAddress);
	void UnregisterBuffer(const vkType* iType, void** iBufferAddress, bool iRelease);

	/**
	Register the address of a buffer that was created 
	with a modifiable type so that it can be automatically reallocated.
	*/
	void RegisterModifiableBuffer(vkType* iType, void** iBufferAddress);
	void UnregisterModifiableBuffer(vkType* iType, void** iBufferAddress, bool iLast = false);

	/**
	Creates a struct type from a struct type plus a new member.
	*/
	void AddMember(vkClassType* iType, const vkString& iMemberName, const vkType* iMemberType, int32 iMemberIndex, uint32 iFlags = 0);

	/**
	Creates a struct type from a struct type minus one of its members.
	*/
	void RemoveMember(vkClassType* iType, uint32 iMemberIndex);

	bool SetMemberName(vkClassType* iType, uint32 iMemberIndex, const vkString& iNewName);

	void SetMemberType(vkClassType* iType, uint32 iMemberIndex, const vkType* iNewType);

	void SetMemberDefaultValue(vkClassType* iType, uint32 iMemberIndex, const vkString& iNewValue);
	void SetMemberDefaultValue(vkClassType* iType, uint32 iMemberIndex,const void* iData,const vkType* iDataType = 0);

	uint32	GetTimeStamp();
	
	void RegisterCallingConvention(vkCallingConvention* iCallingConvention, vkFunctionPtr::ECallType iCallType);
	uint8 GetCallingConventionIdentifier(const vkString& iConventionName);
	vkString GetCallingConventionName(uint8 iConvention);
	vkCallingConvention* UnregisterCallingConvention(const vkString& iConventionName);


	 void PropagateNotReadyOnParents();

	 void ResetStaticValues();

	 void CompleteAllTypes();
	 uint32 GetIncompleteTypesCount();
	 vkType* GetIncompleteType(uint32 iIndex);

	 void CompleteAllSignatures();
	 uint32 GetIncompleteSignatureCount();
	 vkSignature* GetIncompleteSignature(uint32 iIndex);

	const vkString&			ResolveAliases(const vkString& iName);
	// Remove any [namespace::] from ioTypeName and returned the according 
	// namespace if found.
	// ioTypeName is modified to only contain the undecorated symbol 
	 static vkClassType* ResolveSymbolNamespace(vkString& ioSymbol, vkClassType* iOwnerNamespace);

	 bool FindCastFunctionTypes(vkCopyFunction iCast, const vkType*& oSrcType, const vkType*& oDstType);


	void _AddModifiableType(const vkType* iType);
	void _RemoveModifiableType(vkType* iType);

	//////////////////////////////////////////////////////////////////////////

	void	AddReservedWord(const vkString& iWord);
	bool	IsWordReserved(const vkString& iWord) const;
	bool	ValidateWord(const vkString& iWord) const;
	bool	ValidateWordAndPropose(vkString& iWord) const;

	////////////////////////////////////////////////////////////////////////////////

	/*
	void	RegisterListener(vkEventsListener* iListener, const int32 iPriority = 0);
	bool	UnregisterListener(vkEventsListener* iListener);
	void	SendEvent(vkEvent& ioEvent);
	*/

	 void  CheckForAddedProperties();
	 

	 error ParseTypes(vkParseTypeHandler& iHandler,vkClassType* iStartNamespace = 0);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// TOOLS
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
	bool IsTypeReturnedByCopyInRegisters(const vkType* iType);

	error Create();
	vkType* CreateNewIncompleteType(const vkString& iName,vkClassType* iOwnerNamespace = NULL);

	// Ctor
	vkTypeManager(vkCtx iCtxHandle);
	// Dtor
	~vkTypeManager();

private:
	VK_NO_COPYING(vkTypeManager);
	const vkType*	_RedeclareType(vkType* iType);

	static vkSignature* _GetFirstReadySignature(vkSignature* iSignature);

	vkCopyFunction	_GetCastFunction(const vkType* iFrom, const vkType* iTo) const;
	void			_ComputeStructRemappingTable(const vkClassType* iOldType, const vkClassType* iNewType, vkArray<int32>& oTable);
	void			_ComputeEnumRemappingTable(const vkEnumType* iOldType, const vkEnumType* iNewType, vkArray<int32>& oTable);

	//////////////////////////////////////////////////////////////////////////
	// Base Types (int ,float,etc...)
	void	EndType();
	vkType*	_RegisterType(const vkType* iType, vkClassType* iOwnerNamespace = 0);
	void	_CreateQualifiedTypes(vkType* iIncompleteType, vkType* iNewType,vkClassType* iOwnerNamespace);

	//////////////////////////////////////////////////////////////////////////
	// Typedefs

	
	// Small struct to store type pairs for conversion function retrieval
	struct TypePair
	{

		TypePair(const vkType* iFirst = 0, const vkType* iSecond = 0);

		// Comparison operator
		bool operator == (const TypePair& iOp) const;

		// Hashing function
		operator uint32() const;

		const vkType* first;
		const vkType* second;
	};


	//---------------------------------------------------------------
	// Functions arguments default value are stored in hash table 
	// given a type and a string
	// Small struct to store a type and a string conversion function retrieval
	struct TypeAndString 
	{
		TypeAndString(vkType* iFirst = 0,const vkString& iSecond = VK_NS);
		TypeAndString(const TypeAndString& iSrc);
		TypeAndString& operator = (const TypeAndString& iSrc);

		// Comparison operator
		bool operator==(const TypeAndString& iOp) const;

		// Hashing function
		operator uint32() const;

		vkType*			first;
		vkString	   second;
	};


	typedef vkHash<TypePair, vkCopyFunction>	Types2Cast;
	typedef vkHash<TypeAndString, int32>		Types2Int;

// when functions are registred , they call this method to obtain a index 
// where their default value parameters will be stored...

	vkCallingConvention* _GetCallingConvention(uint8 iIndex);

	// <<
public: // Should not be needed
	int16		_GetDefaultValueIndex(const vkType* itype,const vkString& iDefaultValueString,vkClassType* iOwnernamespace);		
	// >>

private:
	const vkSignature*	_GetFunctionSignature(const vkSignature* iFunction,const vkArray<vkParameter*>& iParameters,void* iBuffer);
	vkType::FQualifier	_ExtractQualification(const vkString& iTypeName,vkString& oSubTypeName,vkString& oQualificationInfo);

	//  if iArgumentType is vkVec3 =>  iType = T* return vkVec3* , iType = const T& will return const vkVec3&
	//  if iType does not contain T this method returns iType
	const vkType* _GetSpecializedType(const vkType* iSrcType,const vkType* iTType, const vkType* iArgumentType);

	//Returns the buffer allocated to store the default value of an argument inside a signature
	void* _GetArgumentDefaultValueBuffer(int16 iIndex);

	void _TypeBecomesIncomplete(vkType* iType);

	void _RemoveIncompleteType(vkType* iType);
	void _DestroyRegisteredBuffers(vkType* iType);

	error _ParseTypeRecurse(vkType* iStartNamespace,vkParseTypeHandler& iHandler);
	error _ParseNamespaceRecurse(vkClassType* iStartNamespace,vkParseTypeHandler& iHandler);

	vkType* _RegisterBaseTypes(vkClassType* iNamespace, vkType* iType);
	vkClassType* _RegisterBaseTypes(vkClassType* iNamespace, vkClassType* iType, uint32 iSpecialFlags /*vkClassType::FSpecialMethodFlags*/);
	vkType*	_RegisterTemplatedParameterTypes(vkClassType* iNamespace, vkType* iType);

	void _ResolveTypeDefaultValueString(vkConcreteType* iType);


	void _FillESBufferWithParams(const vkSignature* iSigna,const vkArray<vkParameter*>& iParameters,void* iBuffer);

	vkSmartPtrManager	m_SmartPtrManager;

	// the hash table to store the casts
	Types2Cast			m_CastFunctions;
	String2String		m_Aliases;

	Types2Int			m_Types2DefaultValues;
	vkArray<void*>		m_ArgumentDefaultValues;		
	
	vkArray<vkTypePtr>		m_NotReadyTypes;
	vkArray<vkTypePtr>		m_ToFinalizeTypes;	// Non Modifiable Types which have been added a property after finalization
	vkArray<vkTypePtr>		m_IncompleteTypes;	// Types that has become uncomplete		
	vkArray<vkSignature*>	m_IncompleteSignatures;	// Types that has become uncomplete		
	
//--Temporary variables only used during type registration 
	vkArray<vkTypePtr>	m_TypesBeingRegistred;


	////////////////////////////////////////////////////////////////////////////////
	// Type Modification related
	vkHash<vkTypePtr,vkTypePtr>				m_ModifiableTypes;

	// Registered buffers
	vkHash<const vkType*, vkArray<void**> >	m_RegisteredBuffers;

	uint32									m_TimeStamp;
	// Type Modification related
	////////////////////////////////////////////////////////////////////////////////

	// Main namespace
	vkTypePtr			m_GlobalNamespace;
	// current namespace index
	vkTypePtr			m_CurrentNamespace;
	
	vkEventsChannel		m_EventsChannel;

	// 
	uint32				m_StructMemberPacking;

	// All predefined types...
	vkTypePtr			m_ErrorType;
	vkTypePtr			m_UnknownType;
	vkTypePtr			m_CtxType;

	const vkType*		m_NullType;
	const vkType*		m_AttributeType;
	const vkType*		m_AttributesSetType;
	
	// template argument void type 
	const vkType*		m_TType;
	const vkType*		m_UType;
	const vkType*		m_VType;


	vkHash<uint8, vkCallingConvention*> m_CallingConventions;

	vkMutex				m_RegistrationMutex;
	vkMutex				m_ModifiableTypesMutex;
	vkArray<vkAsset*>	m_RegistrationAsset;
	vkArray<vkString>	m_RegistrationTags;

	String2String		m_ReservedWords;
	String2String		m_ObsoleteTypes;




}; // class vkTypeManager 

inline void SkipBlanks(vkString::ConstIterator& s) 
{
	while ((*s).IsSeparator()) ++s;
}

} // namespace VKernel

#include "vkTypeManager.hpp"
#include "vkGetType.h"

#endif // __vkTypeManager_h



