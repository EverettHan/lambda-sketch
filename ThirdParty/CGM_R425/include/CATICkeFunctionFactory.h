#ifndef CATICkeFunctionFactory_h
#define CATICkeFunctionFactory_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */




#include "CATBaseUnknown.h"
#include "CATCkeScale.h"
#include "CATLifSpecs.h"
#include "CATICkeType.h"
#include "CATICkeArg.h"
#include "CATICkeMagnitude.h"
#include "CATIParmPublisher.h"

#include "CATICkeSignature.h"
#include "CATCkeEvalContext.h"
#include "CATKWEErrorSeverity.h"
#include "CATKWEEvaluationErrors.h"

class CATIEnumere_var;
class CATICkeObject_var;


class CATCkeEvalContext;

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeFunctionFactory;
#else
extern "C" const IID IID_CATICkeFunctionFactory;
#endif


// Knowledge functions evaluator : this is this kind of functions that you must implement to code your
// own functions behaviour : In input, there-s a list of parameters that are the function arguments
// in output, you must create a C++ instance 
// the list musnt be deallocated

// WATCH OUT : pevalcontext can be NULL

/**
* Pointer on function that performs the evaluation.
* @param plist list of parameters in argument
* @param oResult parameter returned by the function
* @param pevalcontext context of evaluation 
*/
typedef void             (*CATCkeFunctionEvaluator) (CATCkeListOfParm plist,const CATICkeParm_var &oResult,const CATCkeEvalContext *pevalcontext);

/**
* Pointer on function that performs the check of the magnitude.
* @param plist list of parameters in argument
* @param oResult parameter returned by the function
* @param pevalcontext context of evaluation 
* @return indicates if the check of magnitude succeeded or not
*/
typedef CATCke::Boolean  (*CATCkeCheckMagnitude)    (CATCkeListOfParm plist,const CATICkeParm_var &oResult,const CATCkeEvalContext *pevalcontext);


//-------------------------------------------------------------------
/**   
 * Interface to create Knowledge functions.
 * Gathers also some basic services about literals and relations.
 * <p>
 * <b>Role</b>: This class provides a way to create your own Knowledge functions that can later be used in Knowledge expressions or Knowledge relations, and add them 
 * to the dictionary.<br>
 * This interface is mono implemented.
 * @see CATITypeDictionary
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATICkeFunctionFactory : public CATBaseUnknown
{
	CATDeclareInterface;

public:


/**
 * Creates a Knowledge function and adds it to the dictionary.
 * @param iFunctionName function name (example : "sin") It is the name
 * that will be used in formulas
 * @param iReturnedType returned type of the function (example : CATParmDictionary::RealType in our sinus example) 
 * @param iEvalFuncPtr function evaluator 
 * @param iCheckMagnitudeFuncPtr magnitude evaluator
 * @param iNotation notation
 * @return Function created
 * Use @href CATITypeDictionary#AddMethodForPackage to register this function in a given package.
 */
virtual CATICkeSignature_var CreateFunction (const CATUnicodeString &iFunctionName,
					                        const CATICkeType_var  &iReturnedType,
							                CATCkeFunctionEvaluator iEvalFuncPtr = NULL,
											CATCkeCheckMagnitude iCheckMagnitudeFuncPtr = NULL,
											const CATICkeSignature::Mode iNotation = CATICkeSignature::Function)=0;
									
					      
/**
 * Creates an argument that will be added later to a signature.
 * @param iArgName argument name (example : "x") 
 * @param iArgType argument type (example : CATParmDictionary::RealType in our example)
 * @param iMode indicates if the argument is In, Out or InOut
 * @return Argument created
 * @see CATICkeSignature#AddArgument
 */
virtual CATICkeArg_var       CreateArg (const CATUnicodeString &iArgName,
                                       const CATICkeType_var  &iArgType,
				                       const CATICkeArg::Mode iMode = CATICkeArg::In)=0;
					      


					      
/**
 * Creates an argument that will be added later to a signature.
 * @param iArgName argument name (example : "x") 
 * @param iArgType argument type (example : "Real" in our example)
 * @param iArgMode: indicates if the argument is In, Out or InOut
 * @return Argument created
 * @see CATICkeSignature#AddArgument
 */
virtual CATICkeArg_var       CreateArg (const CATUnicodeString &iArgName,
                                        const CATUnicodeString &iArgType,
								        const CATICkeArg::Mode iArgMode = CATICkeArg::In)=0;

virtual CATICkeArg_var       CreateArgWithInfo (const CATUnicodeString &iArgName,
                                       const CATICkeType_var  &iArgType,
									   const CATUnicodeString& tai,
				                       const CATICkeArg::Mode iMode = CATICkeArg::In)=0;
virtual CATICkeArg_var       CreateArgWithInfo (const CATUnicodeString &iArgName,
                                       const CATICkeType_var  &iArgType,
									   const CATUnicodeString& tai,
									   const CATUnicodeString& intellisenseArgs,
				                       const CATICkeArg::Mode iMode = CATICkeArg::In)=0;
virtual CATICkeArg_var       CreateArgWithInfo (const CATUnicodeString &iArgName,
                                       const CATICkeType_var  &iArgType,
									   const CATUnicodeString& tai,
									   const CATListOfCATUnicodeString& intellisenseArgs,
				                       const CATICkeArg::Mode iMode = CATICkeArg::In)=0;
					      

/**
 * Creates a Knowledge function and add it to the dictionary.
 * @param iFunctionName  function name (example : "sin") It is the name
 * that will be used in formulas
 * @param iReturnedType returned type of the function (example : CATParmDictionary::RealType in our sinus example) 
 * @param iEvalFuncPtr function evaluator 
 * @param iCheckMagnitudePtr check magnitude evaluator
 * @param iNotation notation
 * @return Function created
 */
virtual CATICkeSignature_var CreateFunction (const CATUnicodeString      &iFunctionName,
											const CATUnicodeString      &iReturnedType,
											CATCkeFunctionEvaluator      iEvalFuncPtr = NULL,
											CATCkeCheckMagnitude         iCheckMagnitudePtr = NULL,
											const CATICkeSignature::Mode iNotation = CATICkeSignature::Function)=0;

	/** 
	* Initializes the list of Knowledge functions and sort it.<br>
	* Load all libraries if necessary
	*/
	virtual void Methods() = 0;

	/** 
	* Adds a constant (true, false).
    * @param iParameter parameter to add to list of Constant. 
	*/
	virtual void AddConstant (const CATICkeParm_var &iParameter) = 0;


    /** 
	* Evaluates a formula whithout parameters.
	* Ex : 3*10+sin(80) ou "Hello"+" World".<br>
	* @param itexte is the texte of the formula. 
	* @param imag precises the magnitude in output
	* @return the return value is in MKS unit
    */
    virtual CATICkeInst_var  ParseAndEval (const CATUnicodeString &itexte,const CATICkeMagnitude_var &imag = NULL_var, CATCkeScale iScale = CATNormalScale) =0;

	/**
	* Returns the standard magnitude checker.
	* @return the standard magnitude checker.
	*/
	virtual CATCkeCheckMagnitude GetStandardMagnitudeChecker() =0;

	/**
	* Creates an event signature and add it to the dictionary.
	* @param iFunctionName :  function name (example : "Instanciation")
    * @return Event created
	*/
	virtual CATICkeSignature_var CreateEvent (const CATUnicodeString &iFunctionName) = 0;

	
	/**
	* Creates an evaluator context that can be given to the Knowledge function as input.
	* @param iObject relation that controls the evaluation.
	* @param iAdditionalConstraints always keep default value.
	* @param iBRContext always keep default value.
	* @param iSourceKind indicates what is the source of the evaluation context. From which object it is triggered.
	* @return the evaluation context created (it must be deallocated).
	*/
	virtual CATCkeEvalContext *CreateEvaluationContext (const CATBaseUnknown_var &iObject,
														const int iAdditionalConstraints =0,
														const int iBRContext = 0,
												   	    const CATCkeEvalContext::SourceKind iSourceKind = CATCkeEvalContext::Undefined) =0;


	
	/** 
	* Creates constant relative to an Enumere type.
    * @param iEnumere type of the enumere 
	* @return
	*  <ol>
	* 	 <li> E_INVALIDARG if the input is NULL.
	* 	 <li> E_FAIL if the creation failed (most of the case because there already exist a constant with the same name.
	* 	 <li> S_OK	if the constants have been created successfully.
	*  </ol>
	*/
	virtual HRESULT CreateConstantFromEnumeratedType (const CATIEnumere_var &iEnumere) = 0;

	/**
	* Send Error. To be used in the definition of user functions.
	*
	* @param iMessage Message. Must be NLS.
	* @param iSeverity Severity.
	* @param iSource Source
	* @param iCode Code of the error
	* @return classic HRESULT
	*/
	virtual HRESULT SendError (const CATUnicodeString&			iMessage, 
		const CATKWEErrorSeverity::Severity					iSeverity	= CATKWEErrorSeverity::Information,
        const CATBaseUnknown_var&		iSource		= NULL_var,
		const CATKWEEvaluationErrors::Code    iCode = CATKWEEvaluationErrors::Anonymous) const =0;

	/**
	* Send attribute truncation error. Do not use, it is meaningless.
	*
	* @param iSeverity Severity.
	* @param iObject object that we attempt to valuate
	* @param iAttributeName name of the attribute that we try to valuate
	* @param iAttributeValue value that we tried to give to the attribute
	* @param iMaxSizeViolated Max size that was authorized and that has been violated
	* @return classic HRESULT
	*/
	virtual HRESULT SendAttributeValuationError (const CATKWEErrorSeverity::Severity					iSeverity,
							   const CATICkeObject_var &		iObject,
							   const CATUnicodeString &		iAttributeName,
							   const CATUnicodeString &		iAttributeValue,
							   int   iMaxSizeViolated) const = 0;

};
CATDeclareHandler(CATICkeFunctionFactory,CATBaseUnknown);

#endif
