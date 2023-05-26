/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//===============================================================
//
// CATLifEvaluationError.h
//
//===============================================================
//
// Usage Notes:
//===============================================================
//
// version 0.1
// author FRH
// Date creation March. 1999
// 
//===============================================================
#ifndef CATLifEvaluationError_h
#define CATLifEvaluationError_h

#include "CATLifExpressions.h"

#include "CATUnicodeString.h"
#include "CATLifError.h"
#include "CATICkeNaming.h"
#include "CATKWEError.h"
#include "CATLifErrorManager.h"
#include "CATCkeEvalContext.h"
#include "CATUnicodeString.h"
#include "CATKWEErrorSeverity.h"
#include "CATKWEEvaluationErrors.h"
#include "CATCkeAttributeValuationFailing.h"
#include "CATListOfInt.h"

class CATString;


/** The CATLifEvaluationError class from the module CATLifLibrary.<br>
*
* Those errors are raised when an error happened in the evaluation of a relation
*	@see CATLifErrorManager
*/
class ExportedByCATLifExpressions CATLifEvaluationError : public CATLifError
{
public:
	
	// Some practical services to share code

	// Name of catalogs used in CATExpressionEngine framework
	static const CATString CATKweEvaluationErrors_CatalogName;
	static const CATString CATLifEvaluationErrors_CatalogName;
	// Name of catalogs used in KnowledgeModeler framework
	static const CATString CATLifEvaluationErrorsKnowledgeModeler_CatalogName;

	// Name of standard keyword for errors
	static const CATString KeyUnknownError;
	static const CATString KeyBadTypeError;

	
	// This method produces a string corresponding to a type of operator (to be used in error messages)
	// Kind
	// 1 comparateur
	// 2 operateur
	// 3 affectation
	// 4 method
	// 5 function
	// 6 mot clef for each
	static CATUnicodeString TypeSignature (const int kind) ;

	/** 
	 * Raises an evaluation error on the right eval context, precising the catalog msg name, the catalog key, the parameters.
	 * To be used to federate code regarding evaluation errors
	 */
	static void RaiseEvaluationError (const CATString	&iCatalogName,
									  const CATString   &iMessageKey,
									  CATUnicodeString iTabOfParameters[] = NULL,
									  const CATCkeEvalContext *pevalcontext = NULL,
									  const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error,
 								      const CATKWEEvaluationErrors::Code    iCode = CATKWEEvaluationErrors::Anonymous);

	/** 
	 * Raises an evaluation error on a method with an object that is NULL.
	 */
	static void RaiseMethodOnNullObject (CATUnicodeString	&NameOfMethod,
										 const CATICkeParm_var &Parameter,
									     const CATCkeEvalContext *pevalcontext = NULL);

	/** 
	 * Raises an evaluation error when an argument of a function/method should be set and is not
	 * Returns True is error has been raised. False instead
	 */
	static CATCke::Boolean TestAndRaiseArgumentUnsetError ( const int argNumber, // (1 to N)
															const int method,    // 0 if a function, 1 if a method
															CATCkeListOfParm l,  // List of arguments
															const CATUnicodeString	&NameOfMethod,	// Name of the method								
	     												    const CATCkeEvalContext *pevalcontext);
	/** 
	 * Raises an evaluation error when an argument of a function/method is set to an unauthorized value
	 */
	static void RaiseArgumentInvalidError ( const int argNumber, // (1 to N)
											const int method,    // 0 if a function, 1 if a method
											const CATICkeParm_var &parmvalue,  // Unauthorized value
											const CATUnicodeString	&NameOfMethod,	// Name of the method								
	     									const CATCkeEvalContext *pevalcontext);

	/** 
	 * Raises an evaluation error due to lack of license: You're not authorized to execute function <NameOfMethod> because you do not have the necessary license (<LicenseName>)
	 */
	static void RaiseNoLicenseToExecuteError (const int method,    // 0 if a function, 1 if a method
											  const CATUnicodeString	&NameOfMethod,	// Name of the method
											  const CATUnicodeString	&LicenseName,	// Name of the method
	     									  const CATCkeEvalContext *pevalcontext);


	/** 
	* Copy Constructor.
	*/	
	CATLifEvaluationError (const CATLifEvaluationError& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iMessage the message carried by the error.<br>
	* Eventually this message can end-up in a popup window.<br>
	* @param iSource the object that generated the error.<br>
	* @param iSeverity the severity of the error (This is an enum of the CATKWEError class).<br>
	* 	enum Severity { Message, Warning, Error };	
	* @see KnowledgeCommunication.CATKWEError
	*/	
	CATLifEvaluationError(const CATICkeNaming_var &iSource,
						  const CATUnicodeString    &message,
						  const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error,
						  const CATKWEEvaluationErrors::Code    iCode = CATKWEEvaluationErrors::Anonymous,
						  const int iLineNo = -1);
	
	
	CATLifEvaluationError(const CATCkeEvalContext* &iEvalCtx, const CATUnicodeString    &message,
						  const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error,
						  const CATKWEEvaluationErrors::Code    iCode = CATKWEEvaluationErrors::Anonymous,
						  const int iLineNo = -1);
	/** 
	* Destructor.
	*/	
	virtual ~CATLifEvaluationError();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	

	virtual CATICkeNaming_var GetRelation() const;

	HRESULT SetRelation(CATICkeNaming_var iRelationSource);

	CATKWEEvaluationErrors::Code ErrorCode () const;

	CATUnicodeString GetEmittingFunction() { return _emittingFunction;};
	int GetLineno() { return _lineno;};
	/** 
	 * Raises an evaluation error on the right eval context, precising the message.
	 * To be used to federate code regarding evaluation errors
	 */
	static void RaiseEvaluationErrorWithMessage (const CATUnicodeString &iMsg,
												 const CATCkeEvalContext *pevalcontext = NULL,
												 const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error,
 												 const CATKWEEvaluationErrors::Code    iCode = CATKWEEvaluationErrors::Anonymous);

protected :
	int _lineno;
	CATUnicodeString _emittingFunction;
  private :	

    CATUnicodeString errmsg (const CATICkeNaming_var &rel,const CATUnicodeString &u, CATListOfCATUnicodeString listOfNamesStack=NULL,
		CATListOfInt _listOfNosStack=NULL, const CATBoolean & disabledLines = FALSE, const CATBoolean & disableFunctionName = FALSE);

	CATICkeNaming_var _Rel;
	CATUnicodeString _originalMessage;
	CATKWEEvaluationErrors::Code _code;
	CATListOfCATUnicodeString _listOfNamesStack;
	CATListOfInt _listOfNosStack;

	CATDeclareClass;	
};


/** The CATLifEvalUpdateError class from the module CATLifLibrary.<br>
*
* Those errors are raised when an error happened in the evaluation of a relation due to 
* an error update in the computation of a feature (GSD corner for example)
*	@see CATLifErrorManager
*/
class ExportedByCATLifExpressions CATLifEvalUpdateError : public CATLifEvaluationError
{
public:


	/** 
	* Copy Constructor.
	*/	
	CATLifEvalUpdateError (const CATLifEvalUpdateError& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iSource the relation in which the evaluation error has occured.<br>
    * @param iFunctionName name of the function where unset has been used
    */	
	CATLifEvalUpdateError(const  CATICkeNaming_var &iSource, CATUnicodeString &updateError = CATLifEvalUpdateError::_Empty);
	
	
	CATLifEvalUpdateError(const CATCkeEvalContext* &iEvalCtx,CATUnicodeString    &updateError = CATLifEvalUpdateError::_Empty);

	/** 
	* Destructor.
	*/	
	virtual ~CATLifEvalUpdateError();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	

   private:

    CATUnicodeString errmsg2 (CATUnicodeString &msg);
	CATDeclareClass;	

	static CATUnicodeString _Empty;
};

/** The CATLifEvalUnsetError class from the module CATLifLibrary.<br>
*
* Those errors are raised when an error happened in the evaluation of a relation due to 
* the use of an Unset value in a function
*	@see CATLifErrorManager
*/
class ExportedByCATLifExpressions CATLifEvalUnsetError : public CATLifEvaluationError
{
public:

	/** 
	 * Generates an Unset error if one of the parameters in input is unset.
	 * You can call this method before evaluating your function to raise an error
	 * if one of the inputs is unset
	 * returns true if one parameter was unset
	 */
	static CATCke::Boolean Generate(const CATCkeListOfParm iList,
                                    const CATCkeEvalContext *, 
									const CATUnicodeString & iOperationWithUnset = "");

	/** 
	* Copy Constructor.
	*/	
	CATLifEvalUnsetError (const CATLifEvalUnsetError& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iSource the relation in which the evaluation error has occured.<br>
    * @param iFunctionName name of the function where unset has been used
    */	
	CATLifEvalUnsetError(const  CATICkeNaming_var &iSource);
	
	CATLifEvalUnsetError(const CATCkeEvalContext* &iEvalCtx);
	
	/** 
	* Destructor.
	*/	
	virtual ~CATLifEvalUnsetError();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	

   private:

    CATUnicodeString errmsg2 ();
	CATDeclareClass;	
};

/** The CATLifSLCreationError class from the module CATLifLibrary.<br>
*
* Those errors are raised when an error happened in the creation of a relation due to 
* the use of a unresolved SemanticLink creation
*	@see CATLifErrorManager
*/
class ExportedByCATLifExpressions CATLifSLCreationError : public CATLifEvaluationError
{
public:

	/** 
	* Copy Constructor.
	*/	
	CATLifSLCreationError (const CATLifSLCreationError& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iSource the relation in which the evaluation error has occured.<br>
    * @param iFunctionName name of the function where unset has been used
    */	
	CATLifSLCreationError(const  CATICkeNaming_var &iSource,
						  const CATUnicodeString    &message);
	
	
	CATLifSLCreationError(const CATCkeEvalContext* &iEvalCtx,const CATUnicodeString    &message);

	/** 
	* Destructor.
	*/	
	virtual ~CATLifSLCreationError();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	

   private:

	   CATDeclareClass;	
};


class ExportedByCATLifExpressions CATLifEvalMaxSizeAttributeError : public CATLifEvaluationError
{
public:

	/** 
	* Copy Constructor.
	*/	
	CATLifEvalMaxSizeAttributeError (const CATLifEvalMaxSizeAttributeError& h);
	
	/** 
	* Constructor with parameters and without parameters.
	* @param iSource the relation in which the evaluation error has occured.<br>
    * @param iFunctionName name of the function where unset has been used
    */	
	CATLifEvalMaxSizeAttributeError(const  CATICkeNaming_var &iSource,const CATCkeAttributeValuationFailing &,const CATKWEErrorSeverity::Severity sever);
	
	/** 
	* Destructor.
	*/	
	virtual ~CATLifEvalMaxSizeAttributeError();
	
	/**
	* Returns a copy of this obejct that must be deleted BY THE USER.
	* @return a copy of this object that must be deleted BY THE USER.
	*/
	virtual CATKWEError* Clone() const;	

	CATCkeAttributeValuationFailing GetValuationFailingInformation () const;

   private:

	CATCkeAttributeValuationFailing _valfailing;
	CATDeclareClass;	
};
#endif



