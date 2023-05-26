/**
@file

This file defines all the
classes related to the storage of a class (vkClassType):
- Members
- Member types
- Member functions 

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkClassType_h)
#define __vkClassType_h

#if !defined(__vkConcreteType_h)
#include "vkConcreteType.h"
#endif
#if !defined(__vkEnumType_h)
#include "vkEnumType.h"
#endif
#if !defined(__vkSignature_h)
#include "vkSignature.h"
#endif
#if !defined(__vkHash_h)
#include "vkHash.h"
#endif


namespace VKernel
{
	struct vkSignature;
	class vkClassType;
	struct vkMember;
	typedef vkSmartPtr<vkClassType> vkClassTypePtr;

	typedef uint32 (*vkMemberValidator)(const vkMember& iMember,const vkClassType* iType,const void* );

	/**
	Extended description of a class member
	A member can be a property : a value that is not stored in the class but rather get or set by methods of the class.
	A member can also be described through an additional string
	A member can have a special representation string that specifies the way it should be edited (an edit, a slider,etc..)
	*/
	struct VKKERNEL_API vkMemberEx : public vkHeapObject {
		
		vkMemberEx();

		vkString			description;
		vkString			category;
		
		void*		staticStorageRuntime;
		void*		staticStorageDefault;

		vkSignature*		getMethod;		// Method to get the value, if not present the property is write-only
		vkSignature*		setMethod;		// Method to set the value, if not present the property is read-only
		
		uint32 v8EditFlags;

		vkMemberValidator   validator;		// A function to call to validate the member flags
				
		// typedef void (vkMemberEx::*pCallGet)(void* iObjBuffer,void* iParamBuffer,const vkType* iType) const;
		// typedef void (vkMemberEx::*pCallSet)(void* iObjBuffer,void** iParamBuffer,const vkType* iType) const; 

		// pCallGet pOptCallGet;
		// pCallSet pOptCallSet;

		// void CallSet(void* iObjBuffer,void** iParamBuffer,const vkType* iType) const
		// {
			// (this->*(pOptCallSet))(iObjBuffer,iParamBuffer,iType);	
		// }

		// void CallGet(void* iObjBuffer,void* iParamBuffer,const vkType* iType) const
		// {
			// (this->*(pOptCallGet))(iObjBuffer,iParamBuffer,iType);	
		// }

    // // 1 is set, 0 is unset, -1 is undefined
		// template<int32 bComplexCall,int32 bReturnsObject,int32 isRef,int32 simpleReturnType> 
		// void OptCallSet(void* iObjBuffer,void** iParamBuffer,const vkType* iType) const;
		
		// // 1 is set, 0 is unset, -1 is undefined
		// template<int32 bReturnsRef,int32 bReturns1stParam,int32 bNoDefArgs,int32 simpleReturnType> 
		// void OptCallGet(void* iObjBuffer,void* iParamBuffer,const vkType* iType) const;
		
	};

	// Call Set


	

	/**
	Basic description of a class member 
	A member is defined by its type, its name and its starting offset.
	Additional information can be added to further describe a member using 
	the vkMemberEx structure in the exData member; 
	*/
	struct VKKERNEL_API vkMember : public vkHeapObject {
		enum FMemberFlags {
			fMemberNameModifiable		= 1<<0,	// If the class structure is modifiable then this member can be renamed
			fMemberTypeModifiable		= 1<<1,	// If the class structure is modifiable then this member can have its type changed
			fMemberDeletable			= 1<<2,	// If the class structure is modifiable then this member can be removed
			fMemberIsXMLAttribute		= 1<<3,	// When serializing this member in XML, write it using attributes
			fMemberIsProperty			= 1<<4,	// This member is a property (there is no real storage for this value, it directly calls functions to be read or written)
			fMemberIsTransient			= 1<<5, // This member must not be serialized
			fMemberIsStatic				= 1<<6, // This member is static ( global to all instance of this classType)
			fMemberStaticBufferAlloc	= 1<<7,	// A buffer has been allocated to store a static member value
			fMemberIsReadOnly			= 1<<8, // This member is read only (can not be set)
			fMemberIsWriteOnly			= 1<<9, // This member is write only (can not be read)
			fMemberDoNotDisplay			= 1<<10, // This member should not be displayed in authoring mode
			fMemberIsOptional			= 1<<11, // We should not raise an error if this member can not be read
			fMemberDoNotCopy			= 1<<12, // This member should not be copied			
			fMemberIsNotConfigured		= 1<<13, // This member should not be configured, and thus is not loaded if present into a configuration (vkNode2D::Parent for example)
			fMemberIsRedirection		= 1<<14, // This member has an alias, and should be redirected to it. The alias is not a simple name change in that case.
			fMemberDisplayInCompletion  = 1<<15, // Force this member to be displayed in completion, event if has flag not to be displayed
			fMemberIsUniquePointer		= 1<<16, // This member is a Ref Pointer that is not shared among different owners
			fMemberIsFixedVariant		= 1<<17, // When applied on Variant members, it specifies that the variant type cannot be edited by the user, and thus inform the controls that the variant's value can be displayed and edited directly
			fMemberIsExpendable			= 1<<18, // When this member is a pointer on a resource, the property view checks this flag to allow expending it
			fLastFlag					= 1<<19, 

			fMemberIsTransientDoNotCopy	= fMemberDoNotCopy|fMemberIsTransient, // This member should not be copied
			fMemberDoNotDisplayButCompletion = fMemberDoNotDisplay|fMemberDisplayInCompletion,	// This member is not displayed in UI, but still available in autocompletion
		};
		vkMember();
		vkMember(vkType* iType,uint8 iOffset);
		~vkMember();
		vkMember(const vkMember& iSrc);
		vkMemberEx* EnsureMemberEx() const;

		bool IsProperty() const;
		bool IsStatic() const;
		bool IsReadOnly() const;
		bool IsWriteOnly() const;
		bool IsTransient() const;
		uint32 GetMemberFlags(const vkClassType* iMyClass,const void* iInstance = 0) const;

		const vkString& GetDescription() const;
		const vkString& GetCategory() const;

		// Returns whether we can use the member offset to access a member data
		bool IsOffsetValid() const;

		uint32 GetAccessFlags() const;

		vkTypePtr		type;				// type of this member
		vkString		name;				// name of the member
		int32		offset;				// real offset of the member inside its structure or class	

		uint32					memberFlags;		// member flags
		mutable	vkMemberEx*		exData;		// Extended Data (store property info, description or representation if available)
	};


	typedef vkHash<vkString,vkTypePtr>		String2Type;
	typedef vkHash<vkString,vkSignaturePtr>	String2Function;

	typedef vkSmartPtr<vkEnumType> vkEnumTypePtr;

	/**
	Summary: vkClassType class. 
	Remarks: defines a compound of types, precisely vkMembers.
	This  is a base class for more complex class such as 
	one holding functions or coming from derivations
	See Also: vkType
	*/
	class VKKERNEL_API vkClassType : public vkConcreteType
	{
		VK_DECLARE_RTTI_EX(vkClassType, vkConcreteType, NOCREATE, TYPE, NOCOMP);

		friend class vkTypeManager;
		friend class vkType;
		friend class vkEnumType;
		friend class vkTypeType;
		friend struct vkSignature;
		friend class vkRefPtrType;
		friend void* ClassTypeNewFct(vkCtx iHandle);
	protected:

		//Special method to now type passing mode (in case of for copy parameter)
		enum FPassingMode
		{
			fParamCopyAsVal		= 1<<0,	  //The type as copy param should be passed by value
			fReturnCopyAsVal	= 1<<1	  //The type as return copy should be passed by value
		};

	public :
		//typedef VKernel::vkHash<vkString,vkMember>	MemberContainer;
		typedef VKernel::vkArray<vkMember>			MemberContainer;

		//Special method to now type passing mode (in case of for copy parameter)
		enum FSpecialMethodFlags
		{
			fHasConstructor		= 1<<0,	  //The type has a constructor
			fHasCopyConstructor = 1<<1,	  //The type has a copy constructor
			fHasDestructor		= 1<<2,	  //The type has a destructor
			fHasAssignOperator  = 1<<3,	  //The type overloads the assign operator
			fHasVirtual			= 1<<4,	  //The type has virtual functions
		};

		/**
		Summary: An iterator on members of a structure
		*/
		class VKKERNEL_API MemberIterator : public vkHeapObject{
			friend class vkClassType;
		public:
			MemberIterator();
			MemberIterator& operator++();
			operator bool() const;
			const vkType* GetType() const;
			uint32 GetSize() const;
			int32 GetOffset() const;
			const vkString& GetName() const;

			uint32  GetSelfIndex() const;
			uint32 GetIndex() const;

			const vkMember& operator*() const;

			// Documentation
			const vkString&	GetDescription() const;
			void			SetDescription(const vkString& iDescription);

			// v8 editFlags
			uint32	GetV8EditFlags() const ;
			void SetV8EditFlags(uint32 iFlags);


			// Description
			const vkString&	GetCategory() const;
			void			SetCategory(const vkString& iCategory);

			uint32		GetMemberFlags(const void* iInstance = 0) const;

			/**
			Summary: Returns the top type that in which this member is used
			Example:
			struct A {
			uint32 m1;
			uint32 m2;
			};
			struct B : public A {
			float m3;
			uint16 m4;
			}
			struct C : public B {
			uint32 m5;
			uint32 m6;
			}
			// let Atype,Btype,Ctype the vkTypes that have been registred for these structures
			vkClassType::Iterator it = Ctype->GetIterator(3); // returns an iterator on the 3rd member of structure (m3)
			it.GetRootType();	// returns C
			it.GetParentType(); // returns B
			it.GetType();		// returns the vkType class for a float
			*/
			const vkType* GetRootType() const;
			const vkType* GetParentType() const;


			bool operator==(const MemberIterator& iOp) const;
			bool operator!=(const MemberIterator& iOp) const;
		private:
			MemberIterator(const vkClassType* iStruct,const vkClassType* iStartStruct);
			MemberIterator(const vkClassType* iStruct,const MemberContainer::ConstIterator& iIterator);
			MemberIterator(const vkClassType* iStruct,const vkClassType* iTopClass,const MemberContainer::ConstIterator& iStartIterator);
			vkClassType* currentClass;
			vkClassType* topClass;
			MemberContainer::ConstIterator currentIt;
		};

		struct enumInfos
		{
			int32 value;			// The enum value;
			vkEnumTypePtr type;	// The enum type (wich is compatible with int32);
			enumInfos();
			enumInfos(const int32 iValue, vkEnumType* iType);
		};


		vkClassType(const vkClassType& iSrc);
		vkClassType(vkCtx iCtxHandle, const vkString& iName);
		virtual ~vkClassType();

		/**
		Summary: Reuse of parent's methods
		*/
		virtual void* New() const;
		virtual void* New(const void* iSrcBuffer, const vkType* iSrcType = 0) const;
		virtual void* NewUnresolved(const void* iSrcBuffer, const vkType* iSrcType = 0) const;
		virtual void Delete(void* iInstance) const;

		virtual void Construct(void* iParamBuffer) const;
		virtual void Destruct(void* iParamBuffer) const;
		virtual void CopyConstruct(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;
		virtual void CopyConstructUnresolved(void* iParamBuffer,const void* iSrcBuffer, const vkType* iSrcType = 0) const;
		virtual void Copy(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;
		virtual void CopyUnresolved(void* iParamBuffer, const void* iSrcBuffer, const vkType* iSrcType = 0) const;
		virtual bool Equals(const void* iOpBuffer1, const void* iOpBuffer2) const;
		virtual int32 Compare(const void* iOpBuffer1, const void* iOpBuffer2) const;

		static void ExtractElementFromString(vkString::ConstIterator& ioStringStart, vkString::ConstIterator& ioStringEnd, bool iInsideContainer);
		virtual error LoadFromString(vkStringLoadArgs& iArgs) const;
		virtual error SaveToString(const vkStringSaveArgs& iArgs) const;
		
		virtual void ComputeTypeDeclaration(vkString& oString) const;

		
		vkClassType* GetParentType() const;

		vkType*			GetInnerType(const vkString& iTypeName,uint32 iOptions = fNoOptions);
		vkSignature*	GetFunction(const vkString& iFctName,uint32 iOptions = fNoOptions);
		/**
		Returns a method description given its name , if it can be found in this 
		class or any parent class.
		*/
		vkSignature*	GetMethod(const vkString& iFunction, uint32 iOptions = fNoOptions);
		bool			GetEnumOrFlagsInfos(const vkString& iEnumValueName, enumInfos& oEnumInfos);

		uint32			GetTypeCount() const;
		vkType*			GetTypeByIndex(uint32 iIndex) const; 

		uint32			GetFunctionCount() const ;
		vkSignature*	GetFunctionByIndex(uint32 iIndex) const; 

		// Set a namespace as "using" so that type declared inside
		// can be retrieved by their name instead of namespace::name
		void	BeginUsingNamespace(vkClassType* iNamespace);
		void	EndUsingNamespace(vkClassType* iNamespace);
		void	SwapTypesDefinitions(vkClassType* iPreviousNamespace); 
		void	_AddTypeInNamespace(vkType* iType);
		void	_RemoveTypeFromNamespace(vkType* iType);

		// 
		vkClassType*	CloneOnlyMembers();

		// Passing mode for copy param (by value or by ref)
		void ComputePassingMode (uint32 iFlag = 0);
		bool CopyPassedByVal() const;
		bool CopyReturnedByVal() const;

		virtual bool  IsSameContent(const vkType* iType) const;

		/**
		Summary: Returns the number of members added by this type only
		Remarks: This methods counts all the members of this
		class without including its parent class members
		*/
		uint32 GetSelfMemberCount() const;
		uint32 GetSelfMemberStartIndex()  const;

		void DestructSelfMembers(void* iInstance) const;

		/**
		Summary: Returns the total number of member (including base classes)
		Remarks: This methods counts all the members of this
		class including its hierachy. 
		*/
		uint32 GetMemberCount()  const;

		/**
		Summary: Returns an iterator on the members of this structure 
		without 
		*/
		MemberIterator EndMembers()  const;

		/**
		Summary: Returns a member iterator using an index.
		Remarks:
		iIndex is a zero-based index of the member inside this class AND its base classes 
		(See also  GetMemberBySelfIndex)
		*/
		MemberIterator GetMemberIterator(uint32 iIndex = 0, const vkClassType* iTopParentType = NULL) const;
		MemberIterator GetMemberIterator(const vkString& iName, const vkClassType* iTopParentType = NULL) const;

		/**
		Summary:  Returns a member iterator using an index (only on this level members).
		Remarks:
		iIndex is a zero-based index of the member inside this class AND its base classes 
		(See GetMemberBySelfIndex)
		*/
		MemberIterator GetSelfMemberIterator(uint32 iIndex = 0) const;

		/**
		Summary: Returns whether this type is derived from another (directly or indirectly)
		*/
		bool IsDerivedFrom(const vkType* iType) const;
		using ParentClass::IsDerivedFrom;


		virtual uint32 GetInheritanceDepth() const;

		const vkClassType* GetCommonAncestor(const vkClassType* iType2) const;

		virtual uint32 GetAlignementSize() const;
		void SetAlignementSize(uint32 iSize);

		/**
		Summary: Retrieves the largest member inside a struct only considering fundamental types.
		(int , float ,int64 ,etc.)
		*/
		uint32 GetLargestMemberSize() const;

		/**
		*/
		vkNewFunctionPtr GetNewFunction() const;
		void SetNewFunction(vkNewFunctionPtr iNewFunctionPtr);
		/**
		*/
		void SetDeleteFunction(vkDeleteFunctionPtr iDeleteFunctionPtr);



		// Overrides...
		virtual const vkType* _Clone(bool iCopy) const;
		virtual void _PrepareDeletion_1_DeleteAllocatedBuffers();
		virtual void _PrepareDeletion_2_RemoveReferences();
		virtual void _UncompleteType();
		virtual vkType*			GetManagedPointerType(const vkString& iUsageName = VK_NS, const vkType* iOverridenBaseType = 0) const;
		friend void	_DeclareMember(vkClassType* iStruct, const vkMember& iMember, int32 iOffset, uint32 iFlags,const vkString& iCategory,vkMemberValidator iValidator,const vkString& iDescription);
		virtual uint32			GetMemoryOccupation(bool iSelfSize = true, bool iDependencies = false) const;

		const vkMember* GetFieldMember(uint32 iFieldIndex) const;
		virtual uint32 GetFieldCount(void* iParamBuffer = 0) const;
		virtual const vkType* GetFieldType(uint32 iFieldIndex,void* iParamBuffer = 0) const;
		virtual void GetFieldName(uint32 iFieldIndex,void* iParamBuffer,vkString& oName) const;
		virtual bool GetFieldDescription(uint32 iFieldIndex,void* iParamBuffer ,vkString& oDescription) const;
		
		virtual uint32 Hash(const void* iParamBuffer) const;


		virtual bool Op(EOperation iOperation, const void* iResultBuffer, const void* iParam1Buffer, const void* iParam2Buffer, float iAlpha = 0) const;

		// Some objects can be deleted at runtime, but it may exist
		// a pointed version that store permanently their value
		virtual void  EnsurePersistentInstance(void* iStorageBuffer) const;

		const vkClassType* GetMemberOwnerClass(uint32 iMemberIndex) const;

	protected:
		// Members...
		MemberContainer			m_Members;		// Members storage

		// should be uint16 (padding + PSP has its vfat at end of type)
		uint8					m_VirtualTableOffset;		// Potential offset due to a virtual table 
		uint8					m_MembersStartingIndex;		// Number of members in the parent Type

		// To now the passing mode of the type by copy
		uint8					m_CopyPassingMode;


		// Structure alignement size
		uint32					m_AlignementSize;

		vkClassTypePtr			m_ParentType;		// when using derivation : parent Type
		vkNewFunctionPtr		m_NewFunctionPtr;

		struct _CustomFunctionPtrs : public vkHeapObject {
			vkDeleteFunctionPtr				deletePtr;

			// Some types cannot be constructed directly from xml definition
			// They need to use a temporary struct, the parameters struct
			// which contains the plain data.
			// The proxy object is deleted just after loading.
			const vkType*					proxyType;
			_CustomFunctionPtrs();
		};

		_CustomFunctionPtrs*	m_CustomFunctions;



		// Store the sub types declared inside a namespace
		// some of these types can be new namespaces 
		struct NamespaceData : public vkHeapObject {
			String2Type									m_Types;
			vkHash<vkString, enumInfos>					m_EnumInfos;
			vkHash<vkClassType*,vkClassType*>			m_UsedNamespaces;
		};


		// hash for types that have been registred inside this namespace
		// some of these types can be sub-namespaces
		NamespaceData*	   m_NamespaceData;	
		// hash for functions that might have been registred 
		// this can be class methods, class static methods or global namespace functions
		String2Function*	m_Functions;


		virtual void		_Destroy();

		vkType::FQualifier	_ExtractQualification(const vkString& iTypeName,vkString& oSubTypeName,uint32& oStaticArrayDimension);						


		virtual void _Finalize(bool iClean = false,vkHash<vkClassType*,vkClassType*>* iModifs=0);
		virtual bool _CheckIfComplete();
		virtual bool _CompleteType();
		virtual void _TestIfPod();

		// type registration
		void _AddFunctionInNamespace(vkSignature* iSignature);
		void _RemoveFunctionFromNamespace(vkSignature* iSignature);

		// Enums values
		void _RegisterEnumInfos(const vkString& iEnumName, const enumInfos& iEnumInfos);
		void _UnregisterEnumInfos(const vkString& iValue);
		void _UnregisterEnumInfos(vkEnumType* iType);

		void _ComputeMemberFunctionsDeclaration(vkString& oString) const;
		void _ComputeInnerTypeDeclaration(vkString& oString) const;
		void _CheckFinalizedTypes(vkHash<vkType*,vkType*>&  iDoneTypes);


		void _ResetStaticValues();

		void	_ComputeMembersDeclaration(vkString& oString) const;

	};

	// Inlined implementations
	VK_INLINE bool
		vkMember::IsProperty() const
	{
		return (memberFlags & fMemberIsProperty) != 0;
	}

	VK_INLINE bool
		vkMember::IsStatic() const
	{
		return (memberFlags & fMemberIsStatic) != 0;
	}

	VK_INLINE bool
		vkMember::IsReadOnly() const
	{
		return (memberFlags & fMemberIsReadOnly) != 0;
	}

	VK_INLINE bool
		vkMember::IsWriteOnly() const
	{
		return (memberFlags & fMemberIsWriteOnly) != 0;
	}

	VK_INLINE bool
		vkMember::IsTransient() const
	{
		return (memberFlags & fMemberIsTransient) != 0;
	}
	

	VK_INLINE const vkString&
		vkMember::GetDescription() const
	{
		return exData ? exData->description : VK_NS;
	}

	VK_INLINE const vkString&
		vkMember::GetCategory() const
	{
		return exData ? exData->category : VK_NS;
	}

	VK_INLINE bool
		vkMember::IsOffsetValid() const 
	{
		return (memberFlags & (fMemberIsProperty|fMemberIsStatic)) == 0;
	}

	VK_INLINE
		vkClassType::MemberIterator::MemberIterator()
		:currentClass(0),topClass(0)
	{}

	VK_INLINE
		vkClassType::MemberIterator::operator bool() const
	{
		return (currentIt!=topClass->m_Members.End());
	}

	VK_INLINE const vkType*
		vkClassType::MemberIterator::GetType() const
	{
		return (*currentIt).type; 
	}

	VK_INLINE uint32
		vkClassType::MemberIterator::GetSize() const
	{
		return (*currentIt).type->GetSize();
	}

	VK_INLINE int32
		vkClassType::MemberIterator::GetOffset() const
	{
		return (*currentIt).offset;
	}

	VK_INLINE const vkString&
		vkClassType::MemberIterator::GetName() const
	{
		return (*currentIt).name; 
	}

	VK_INLINE uint32
		vkClassType::MemberIterator::GetSelfIndex() const
	{
		return (uint32) VK_POINTER_TO_PTRDIFF(currentIt - currentClass->m_Members.Begin());
	}

	VK_INLINE uint32
		vkClassType::MemberIterator::GetIndex() const
	{
		return GetSelfIndex() + currentClass->m_MembersStartingIndex;
	}

	VK_INLINE const vkMember&
		vkClassType::MemberIterator::operator*() const
	{
		return *currentIt;
	}

	VK_INLINE const vkType*
		vkClassType::MemberIterator::GetRootType() const 
	{
		return 	topClass;
	}

	VK_INLINE const vkType*
		vkClassType::MemberIterator::GetParentType() const 
	{
		return 	currentClass;
	}

	VK_INLINE bool
		vkClassType::MemberIterator::operator==(const MemberIterator& iOp) const
	{
		return (currentIt==iOp.currentIt);
	}

	VK_INLINE bool
		vkClassType::MemberIterator::operator!=(const MemberIterator& iOp) const
	{
		return (currentIt!=iOp.currentIt);
	}

	VK_INLINE vkClassType::enumInfos::enumInfos()
		: value(0), type(0)
	{}


	VK_INLINE vkClassType*
		vkClassType::GetParentType() const 
	{
		return 	m_ParentType;
	}

	VK_INLINE bool
		vkClassType::CopyPassedByVal() const
	{
		return (m_CopyPassingMode & fParamCopyAsVal) != 0;
	}

	VK_INLINE bool
		vkClassType::CopyReturnedByVal() const
	{
		return (m_CopyPassingMode & fReturnCopyAsVal) != 0;
	}

	VK_INLINE uint32
		vkClassType::GetSelfMemberCount() const
	{
		return m_Members.Size();
	}

	VK_INLINE uint32
		vkClassType::GetSelfMemberStartIndex()  const
	{
		return m_MembersStartingIndex;
	}



}; // Namespace VKernel 


#endif // __vkClassType_h


