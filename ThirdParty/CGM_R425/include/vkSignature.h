/**
@file

@COPYRIGHT

Description: 

@author Aymeric Bard
Creation date: 14/2/2005
*/

#if !defined(__vkSignature_h)
#define __vkSignature_h

#if !defined(__vkType_h)
	#include "vkType.h"
#endif

#if !defined(__vkFunctionPtr_h)
	#include "vkFunctionPtr.h"
#endif

#if !defined(__vkArray_h)
	#include "vkArray.h"
#endif

#if !defined(__vkArgument_h)
	#include "vkArgument.h"
#endif

namespace VKernel
{
// forward decl
struct vkSignature;
class vkClassType;

struct vkSignature;
typedef vkSmartPtr<vkSignature> vkSignaturePtr;

class vkMultipleBreakpointR;
typedef vkRefPtr<vkMultipleBreakpointR> vkMultipleBreakpointRPtr;

/**
Summary: vkSignature class. 
Remarks: Defines the argument signature of a function
(that is arguments and return value)

See Also: vkFunctionPtr,vkArgument
*/
struct VKKERNEL_API vkSignature : public vkResource
{
	VK_DECLARE_RTTI_OBJECT(vkSignature, vkResource);

	friend class vkTypeManager;
	enum FQualifier {
		fConst		= 1 << 0,	// Method is const (does not modify object members )
		fMethod		= 1 << 1,	// Function is a method
		fVirtual	= 1 << 2,	// Method is virtual	
		fStatic		= 1 << 3,	// Function is static 
		fReturnObj	= 1 << 4,	// Function returns an is static 
		fQualificationMask = fConst|fMethod|fVirtual|fStatic|fReturnObj,
		fReady		= 1 << 5,	// Function is ready to be called
		fComplete	= 1 << 6,	// 
		fInline		= 1 << 7,
		fEmulated	= 1 << 8,
		fThrow		= 1 << 9,
		fCatThrow	= 1 << 10
	};

	enum EMatch {
		eOk,					// A signature exists with all the correct parameters
		eOkWithSomeProcess,		// A signature exists  but some parameters must be processed (cast, ref, deref)		
		eInvalidType,			// One or more arguments are invalid...
		eNotEnoughParameters,	// Not enough parameters were given...
		eTooMuchParameters,		// Too much parameters were given...
		eAmbigousSyntax,		// It exists two or more options for a signature
		eMethodIsNotConst		// Method should have to be const
	};

	enum FCustomMatch {
		fNoCast			= 1 << 1,	// Cast produce error matching
		fNoInheritage	= 1 << 2,	// Heritage produce error matching
		fNoRef			= 1 << 3,	// Referencing produce error matching
		fNoDeRef		= 1 << 4,	// Dereferencing produce error matching
		fNoDeConst		= 1 << 5	// Can't ignore constanteness
	};

	enum EConstStatus {
		eConstIsNotManaged,			// We does not manage the constantness of "THIS" (GetCorrectSignature could return eAmbigousSyntax...)
		eThisIsNotConst,		// "THIS" is not const
		eThisIsConst			// "THIS" is const
	};
	
	enum ECallCategory { // used to determine which glue-code to use to call the method
		fIsVirtual			= 1 << 0, // virtual function/method
		fIsMethod			= 1 << 1, // class-method
		fReturnsInRegister	= 1 << 2, // returns value directly (but could be converted for MP, if needed)
		fReturns8Bit		= 1 << 3, // returns an 8-bit value in register
		fReturns16Bit		= 1 << 4, // returns a 16-bit value in register
		fReturns32Bit		= 1 << 5, // returns a 32-bit value in register
		fReturns64Bit		= 1 << 6, // returns a 64-bit value in register
		fReturnsFloat		= 1 << 7, // returns a float
		fReturnsStruct		= 1 << 8, // returns a struct (can be used with a size flag)
		fCanMoveToParam		= 1 << 9, // associated glue code can move returned register to first parameter
		
		// special flags for set/get methods
		fIsMemberRef		= 1 << 10, // the member is passed/returned as a reference
		fMemberIsReturned	= 1 << 11, // the member is returned in the get method
		fReturnsDouble		= 1 << 12, // where were the doubles !?
		fReturnsNonVoid		= fReturnsFloat|fReturns8Bit|fReturns16Bit|fReturns32Bit|fReturns64Bit|fReturnsStruct|fReturnsDouble, // returns something, but that can be returned as param

	};

	enum EditFlags {
		fV8None       = 0,
		fV8ReadOnly   = 1 << 0,
		fV8DontEnum   = 1 << 1,
		fV8DontDelete = 1 << 2,
		fV8PropagateFlags= 1 << 3 , 
		fV8DefaultEditFlag = 1 << 4
	};

	vkSignature(vkCtx iCtxHandle);
	vkSignature(const vkSignature& iSrc);
	~vkSignature();

	////////////////////////////////////////////////////////////////////////////////
	// Overrides from vkResource
	virtual error					_SetResourceID(const vkString& iID);
	virtual error					_SetAsset(vkAsset* iAsset);
	virtual uint32					GetMemoryOccupation(bool iSelfSize = true, bool iDependencies = false) const;

	static void					AppendTypeValue(vkString& ioString, const vkType* iType, void* iBuffer);

	inline const vkString& GetName() const {
		return m_ResourceID;
	}
	vkString GetCompleteName(bool iFullyDecorated,bool iWithDefaultValues = false,bool iWithCtxParams=true) const;
	
	bool operator == (const vkSignature& iSign) const;
	vkString			functionDescription;	// Complete string description of the signature
	vkClassType*		ownerNamespace;			// Namespace in which the signature was declared
	ArgumentsArray		arguments;				// List of arguments
	vkTypePtr			returnType;				// type of the return value
	uint8				callingConvention;		// calling convention (vkSignature::ECallType)
	uint16				fctQualifier;			// function qualifier itself (vkSignature::FQualifier)
	uint8				totalArgumentsSize;		// size taken by all arguments on stack...
	uint8				defaultArgumentsCount;	// Number of input arguments with a default value...
	mutable vkFunctionPtr	fctPointer;				// Function pointer to execute code
	vkSignature*		nextOverloadedSignature; 	// overloaded functions by default it points to itself
	uint32				accessFlags;
	uint32				fctCallFlags;
	uint32				v8EditFlags;

#if defined(EXPERIENCEKERNEL)
	//NLS
private :
	vkString			m_NLSKey;				//Key used to retrieve the appropriate localized function description in an associated CATMsgCatalog

public :
	VK_INLINE void SetNLSKey(const char* iKey){ 
		m_NLSKey = vkString(iKey); 
	}
	
	VK_INLINE const vkString& GetNLSKey(){
		return m_NLSKey;
	} 
#endif
	
	inline bool IsMethod() const {
		return (fctQualifier & fMethod) != 0;
	}
	inline bool IsVirtual() const {
		return (fctQualifier & fVirtual) != 0;
	}
	inline bool IsStatic() const {
		return (fctQualifier & fStatic) != 0;
	}
	inline bool IsConst() const {
		return (fctQualifier & fConst) != 0;
	}
	inline bool ReturnObject() const {
		return (fctQualifier & fReturnObj) != 0;
	}
	inline bool IsReady() const {
		return (fctQualifier & fReady) != 0;
	}
	inline bool IsEmulated() const {
		return (fctQualifier & fEmulated) != 0;
	}
	inline bool IsThrowable() const {
		return (fctQualifier & fThrow) != 0;
	}
	inline bool IsCatThrowable() const {
		return (fctQualifier & fCatThrow) != 0;
	}
	inline void MarkAsReady(bool iReady) {
		if (iReady) {
			fctQualifier |= fReady;
		} else {
			fctQualifier &= ~fReady;
		}
	}
	virtual bool IsFromScriptLanguage() const
	{
		return false;
	}

	/**
	Given a list of argument (qualified types), try to find the best 
	matching signature if it exists.
	Sets the oMatchingType enum according to the results
	If some arguments need to be processed before calling the function
	the oToCastArguments contains their indices.
	iCustomMatching can custom the matching requirement.
	*/
	const vkSignature* GetCorrectSignature(const EConstStatus iConstStatus, const vkArray<const vkType*>& iArguments, vkArray<uint32>& oToProcessArguments, EMatch& oMatchingType, const uint32 iCustomMatching = fNoRef | fNoDeRef | fNoDeConst, const uint32 iObjectQualifier = 0, const uint32 iRelationOptions = 0) const;
	
	/**
	Summary: Returns the number of overloaded signature (same name with different arguments)
	*/
	uint32 GetOverloadedCount() const;

	/**
	Summary: Returns the next overloaded method
	*/
	vkSignature* GetNextOverloadedSignature() const {
		return nextOverloadedSignature;
	}
	/**
	Summary: Returns the next overloaded method
	*/
	void AddOverloadedSignature(vkSignature* iSignature);

	void DeleteAllOverloadedSignatures();
	void RemoveOverloadedSignature(vkSignature* iSignature);

	/**
	Summary: Returns the next overloaded method
	*/
	vkSignature* FindExistingSignature(const vkSignature& iSign) const;

	/**
	Summary: Check that the signature is valid
	*/
	virtual bool IsValid() const;

	/**
	Summary: Change owner of the function
	*/
	void ChangeOwnerNamespace(vkClassType* iOwnerNamespace);

	/**
	Pre computes the size that arguments will take on stack
	*/
	void _ComputeArgumentsSize();
	/**
	Pre computes the size that arguments will take on stack
	*/
	void _ReplaceTemplateType(const vkType* iTType,const vkType* iArgumentType);
// Computes fctQualifier and totalArgumentsSize according to the arguments and return type
	void _Finalize();
	void _ComputeArgDefaultValueString(const vkType* iType,const void* iBuffer,vkString& oString) const;

	// Debugger
	bool CanAddBreakpointAtFunctionStart() const;
	error AddBreakpointAtFunctionStart(vkMultipleBreakpointRPtr& oMultipleBreakpoint) const;

	uint32	GetAccessFlags() const;
	void	SetAccessFlags(uint32 iAccessFlags);
	
	uint32	GetFunctionCallFlags() const;
	void	SetFunctionCallFlags(uint32 iFctCallFlags);

	uint32 GetV8EditFlags() const;
	void SetV8EditFlags(uint32 iEditFlags);

};
	
}; // VKernel

#endif // __vkSignature_h
