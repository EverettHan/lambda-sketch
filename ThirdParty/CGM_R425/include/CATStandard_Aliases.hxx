//============================================================================
//===== Titre: CATStandard_Aliases
//=====           
//===== Role:  this header file can be used by the "C++" programs, which used
//=====        the types and the classes defined in the package "CATStandard", 
//=====        without the suffix "CATStandard".
//=====           
//===== Remarque: A conflict may appear, if a type with the same name is 
//=====           defined in another package than "CATStandard".
//=====           
//============================================================================ 

#ifndef _CATStandard_Aliases_HeaderFile
#define _CATStandard_Aliases_HeaderFile

//==== CATStandard Classes ======================================================
#define Persistent        CATStandard_Persistent
#define PersistentType    CATStandard_ PersistentType
#define Handle_Persistent Handle_CATStandard_Persistent


#define Storable       CATStandard_Storable
#define IStream        CATStandard_IStream
#define OStream        CATStandard_OStream
#define SStream        CATStandard_SStream

//==== CATStandard Primitives ===================================================
#define Integer     CATStandard_Integer
#define Real        CATStandard_Real
#define Boolean     CATStandard_Boolean
#define Character   CATStandard_Character
#define CString     CATStandard_CString

//==== CATStandard Exceptions ===================================================
#define AbortiveTransaction	    CATStandard_AbortiveTransaction
#define AbortiveTransactionType	    CATStandard_AbortiveTransactionType
#define Handle_AbortiveTransaction  Handle_CATStandard_AbortiveTransaction
#define DomainError		    CATStandard_DomainError
#define DomainErrorType		    CATStandard_DomainErrorType
#define Handle_DomainError          Handle_CATStandard_DomainError
#define ConstructionError	    CATStandard_ConstructionError
#define ConstructionErrorType	    CATStandard_ConstructionErrorType
#define Handle_ConstructionError    Handle_CATStandard_ConstructionError
#define NullObject		    CATStandard_NullObject
#define NullObjectType		    CATStandard_NullObjectType
#define Handle_NullObject           Handle_CATStandard_NullObject
#define NoSuchObject		    CATStandard_NoSuchObject
#define NoSuchObjectType	    CATStandard_NoSuchObjectType
#define Handle_NoSuchObject         Handle_CATStandard_NoSuchObject
#define NoMoreObject		    CATStandard_NoMoreObject
#define NoMoreObjectType	    CATStandard_NoMoreObjectType
#define Handle_NoMoreObject         Handle_CATStandard_NoMoreObject
#define ImmutableObject		    CATStandard_ImmutableObject
#define ImmutableObjectType	    CATStandard_ImmutableObjectType
#define Handle_ImmutableObject      Handle_CATStandard_ImmutableObject
#define TypeMismatch		    CATStandard_TypeMismatch
#define TypeMismatchType	    CATStandard_TypeMismatchType
#define Handle_TypeMismatch         Handle_CATStandard_TypeMismatch
#define MultiplyDefined		    CATStandard_MultiplyDefined
#define MultiplyDefinedType	    CATStandard_MultiplyDefinedType
#define Handle_MultiplyDefined      Handle_CATStandard_MultiplyDefined
#define DimensionError		    CATStandard_DimensionError
#define DimensionErrorType	    CATStandard_DimensionErrorType
#define Handle_DimensionError       Handle_CATStandard_DimensionError
#define DimensionMismatch	    CATStandard_DimensionMismatch
#define DimensionMismatchType	    CATStandard_DimensionMismatchType
#define Handle_DimensionMismatch    Handle_CATStandard_DimensionMismatch
#define RangeError		    CATStandard_RangeError
#define RangeErrorType		    CATStandard_RangeErrorType
#define Handle_RangeError           Handle_CATStandard_RangeError
#define OutOfRange		    CATStandard_OutOfRange
#define OutOfRangeType		    CATStandard_OutOfRangeType
#define Handle_OutOfRange           Handle_CATStandard_OutOfRange
#define NullValue		    CATStandard_NullValue
#define NullValueType		    CATStandard_NullValueType
#define Handle_NullValue            Handle_CATStandard_NullValue
#define NegativeValue		    CATStandard_NegativeValue
#define NegativeValueType	    CATStandard_NegativeValueType
#define Handle_NegativeValue        Handle_CATStandard_NegativeValue
#define NumericError		    CATStandard_NumericError
#define NumericErrorType	    CATStandard_NumericErrorType
#define Handle_NumericError         Handle_CATStandard_NumericError
#define Underflow		    CATStandard_Underflow
#define UnderflowType		    CATStandard_UnderflowType
#define Handle_Underflow            Handle_CATStandard_Underflow
#define Overflow		    CATStandard_Overflow
#define OverflowType		    CATStandard_OverflowType
#define Handle_Overflow             Handle_CATStandard_Overflow
#define DivideByZero		    CATStandard_DivideByZero
#define DivideByZeroType	    CATStandard_DivideByZeroType
#define Handle_DivideByZero         Handle_CATStandard_DivideByZero
#define ProgramError		    CATStandard_ProgramError
#define ProgramErrorType	    CATStandard_ProgramErrorType
#define Handle_ProgramError         Handle_CATStandard_ProgramError
#define NotImplemented		    CATStandard_NotImplemented
#define NotImplementedType	    CATStandard_NotImplementedType
#define Handle_NotImplemented       Handle_CATStandard_NotImplemented
#define OutOfMemory		    CATStandard_OutOfMemory
#define OutOfMemoryType		    CATStandard_OutOfMemoryType
#define Handle_OutOfMemory          Handle_CATStandard_OutOfMemory

//==== CATStandard False, True ===================================================
#define False       0
#define True        1


#endif 
