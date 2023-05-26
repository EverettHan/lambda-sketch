#ifndef CATICkeSignature_h
#define CATICkeSignature_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// export module
#include "CATLifSpecs.h"

// inherited from
#include "CATBaseUnknown.h"

// forward
#include "CATICkeRelationForwards.h"
class CATICkeTerm_var; // Do not use
class CATCkeStream;    // Do not use 

// used interface  
#include "CATICkeArg.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeSignature;
#else
extern "C" const IID IID_CATICkeSignature;
#endif

/**
* Defines which are used in SetEditionContext and GetEditionContext.
* They allow callers to specify in which context a signature of a method can be used. It is intended for people creating functions.
* It has no value for the other users.
* This is a way to express accurately where a specific function can be used in term of editors.
* Is it used in Law editor, or Rule editor, or both ?
* It is important to understand that this information is used by the Knowledge editor, not by the expression model.
* <br>
* The first defines allow to explicitely declare what are the editors where the function will be visible.
*/

/** Available in the formula editor. 
*/
#define CATCkeEditionCxtFormula 1

/** Available in the rule editor of Knowledge Advisor. 
*/
#define CATCkeEditionCxtRule 2

/**
* Available in the check editor of Knowledge Advisor.
*/
#define CATCkeEditionCxtCheck 4

/**
* Available in the law editor.
*/
#define CATCkeEditionCxtLaw 8

/**
* Available in the action editor of Knowledge Advisor.
*/
#define CATCkeEditionCxtActions 16

/**
* Available in the set of equation editor of Knowledge Advisor.
*/
#define CATCkeEditionCxtSetOfEq 32

/**
* Available in the expert check editor of Knowledge Expert.
*/
#define CATCkeEditionCxtExpertCheck 64

/**
* Available in the expert rule editor of Knowledge Expert.
*/
#define CATCkeEditionCxtExpertRule 128


/**
* Available in all Knowledge Advisor editors except set of equations.
*/
#define CATCkeEditionCxtKWA 31

/**
* Available in all Knowledge Expert editors.
*/
#define CATCkeEditionCxtKWE 192

/**
* Available in all Knowledge editors.
*/
#define CATCkeEditionCxtAll 255





/**
* A different way to express this is to use the CATCkeFunctionQuality which details what can support a function. 
* Is it an inversible function ? Does it update correctly ?
* Based on this information, we will deduce ourself in which editor it will be available.
* It is intended for people creating functions.
* It has no value for the other users.
*/
/**
* Indicates that we know how to invert this function (in an equation). This makes sense in Knowledge Advisor set of equations.
*/
#define CATCkeFunctionQualityInversible 1

/**
* Indicates that this function creates objects (and thus those objects must be managed). This is not authorized today in Knowledge Expert.  
*/
#define CATCkeFunctionQualityCreateObject 2

/**
* Indicates that this function operates a treatment (and thus cannot be called twice. It is not a pure computation). This is not authorized in rule editor.
*/
#define CATCkeFunctionQualityOperate 4

/**
* Indicates that some of the inputs of the functions are not update compliant (they don't know when they have been modified). Can not be used in Knowledge Advisor rules.
*/
#define CATCkeFunctionQualityNotUpdateCompliant 8






/** 
 * @nodoc
 * Do not use.
 * External functions to show an expression. Internal use only.<br>
 * when creating a signature, you can define a function to show it in a particular manner.
 * This view is used for debug purposes.
 * By default functions are shown like a functional expression: (example: sin (x) will be shown like this sin (Sub expression 1))
 * @param sig Signature of the function
 * @param term term to show
 * @param stream stream to use
 * @return the stream
 */
typedef   CATCkeStream& (*CATCkeShowExpression) (const CATICkeSignature_var &sig,const CATICkeTerm_var &term,CATCkeStream &stream);


/**
 * Possible values for defining signature information. 
 * <br><b>Legal values</b>:
 * <tt>CATCkeSigInfoInternal</tt> never use.<br>
 * <tt>CATCkeSigInfoExternal</tt> default value. Indicates that this function is not managed by Knowledge core.<br>
 * <tt>CATCkeSigInfoInvalid</tt> do not use.<br>
 * <tt>CATCkeSigInfoConsuming</tt> use it to indicate that this function is really high CPU consuming.<br>
 * <tt>CATCkeSigInfoSubExpr</tt> do not use. It explains that this function calls a sub expression.<br>
 */
typedef unsigned long CATCkeSignatureInfo;

/**
 * Indicates that the signature is external (out of Knowledge framework) or internal this is used to know if a relation potentially includes functions that couldn't be retrieved at runtime.
 * we call external those relations.<br>
 * You can also specify that evaluation of this signature is really high consuming. It is used, not to evaluate this function
 * the first time it is created.<br>
 * Please use only CATCkeSigInfoExternal or CATCkeSigInfoConsuming values.
 */
extern ExportedByCATLifSpecs const CATCkeSignatureInfo  CATCkeSigInfoInternal;
extern ExportedByCATLifSpecs const CATCkeSignatureInfo  CATCkeSigInfoExternal;
extern ExportedByCATLifSpecs const CATCkeSignatureInfo  CATCkeSigInfoInvalid; 
extern ExportedByCATLifSpecs const CATCkeSignatureInfo  CATCkeSigInfoConsuming;
extern ExportedByCATLifSpecs const CATCkeSignatureInfo  CATCkeSigInfoSubExpr;

/**   
 * Interface dedicated to signature management.
 * <b>Role</b>: A signature is a definition of the arguments of a Knowledge function or Knowledge expression.<br>
 * for example : "name [arg: mode Type] : mode Type"  ie: "Real sin (x: in int): out Real".<br>
 * Such a signature is used to check the types compatibility when writing a relation<br>
 * Example : cos(sin(tan(c)*2))<br>
 * If you want to create a new Knowledge function usable in formulas/checks/programs, you'll have<br>
 * to define a signature and an evaluator<br>
 * This interface is mono implemented.
 * @see CATICkeArg, CATICkeFunction, CATICkeFunctionFactory
 */
class ExportedByCATLifSpecs CATICkeSignature: public CATBaseUnknown
{

public :

/**
 * Signature mode: indicates how this function will be written in Knowledgeware language.
 * <br><b>Legal values</b>: the notation can be
 * <tt>Function</tt> to be seen as a function : f(x,y), or
 * <tt>Method</tt> to be seen as a method : x,f(y), or
 * <tt>Operator</tt> do not use, or
 * <tt>Special</tt> do not use, or
 * <tt>Attribut</tt> to be seen as an attribute : x.f.
 */
enum Mode
{
  Function	= 1, 
  Method	= 2, 
  Operator	= 3, 
  Special	= 4, 
  Attribute	= 5,
  Event     = 6
};  
  

//--------------------------------------
// Nommage
//--------------------------------------
/**
 * Returns the name of the signature.<br>
 * (example : "sin")
 */
virtual CATUnicodeString  Name    () const =0;
  
/**
 * Renames the signature.<br>
 * @param  iNewName New name 
 * Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void            Rename    (const CATUnicodeString &iNewName) =0;

/**
 * Shows the signature to the user.<br>
 * Example: "sin(Real) : Real" 
 * This method is the one used in Knowledge wizard.
 * @return string used to show the signature to the user
 */
virtual CATUnicodeString  Show    () const =0; 



/**
 * Returns signatures notation.<br>
 * Indicates if it is an operator, a function, a method or something else<br>
 * @return <br><b>Legal values</b>: the notation can be
 * <tt>Function</tt> to be seen as a function : f(x,y), or
 * <tt>Method</tt> to be seen as a method : x,f(y), or
 * <tt>Operator</tt> do not use, or
 * <tt>Special</tt> do not use, or
 * <tt>Attribut</tt> to be seen as an attribute : x.f.
 */
virtual CATICkeSignature::Mode    Notation      () const = 0;

/**
 * Sets notation of the signature.
 * Function is default value.
 * @param iNotation notation to be set.
 * <br><b>Legal values</b>: the notation can be
 * <tt>Function</tt> to be seen as a function : f(x,y), or
 * <tt>Method</tt> to be seen as a method : x,f(y), or
 * <tt>Operator</tt> do not use, or
 * <tt>Special</tt> do not use, or
 * <tt>Attribut</tt> to be seen as an attribute : x.f.
 * Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void		   SetNotation (CATICkeSignature::Mode iNotation) = 0;


/**
 * @nodoc. Use previous method instead.
 * Sets notation of the signature.
 * Function is default value.
 * @param iNotation notation to be set.
 * <br><b>Legal values</b>: the notation can be
 * <tt>Function</tt> to be seen as a function : f(x,y), or
 * <tt>Method</tt> to be seen as a method : x,f(y), or
 * <tt>Operator</tt> do not use, or
 * <tt>Special</tt> do not use, or
 * <tt>Attribut</tt> to be seen as an attribute : x.f.
 * @param iHowToShow function pointer to specify how to show such a signature in special cases.
 * Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void		   SetNotation (CATICkeSignature::Mode iNotation,CATCkeShowExpression iHowToShow) = 0;




//--------------------------------------
// prototype
//--------------------------------------

/**
 * Returns the number of arguments of this signature.<br>
 * (Can be 0).
 * @return the number of  arguments.
 */
virtual int          PrototypeSize () const = 0;

/**
 * Returns the list of arguments of this signature.<br>
 * @return list of arguments (not to be deallocated)
 */
virtual CATCkeListOfArg  Prototype     () const = 0;

/**
 * Returns the returned argument of the signature.
 */
virtual CATICkeArg_var   ReturnedArg   () const = 0;

/**
 * Add an argument to the list.
 * @param iArgToAdd argument to be added
 */
virtual void   AddArgument   (const CATICkeArg_var iArgToAdd)  = 0;

/**
 * Modifies the whole list of arguments.
 * @param iListOfArguments list of arguments to replace
 * Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void		   SetPrototype  (const CATCkeListOfArg iListOfArguments) = 0;

/**
 * Sets the returned argument.
 * @param iReturnedArg returned arg
 * Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void		   SetReturnedArg(const CATICkeArg_var &iReturnedArg)  = 0;




/**
 * Indicates if the number of argument is variable.<br>
 * those signature must have at least one argument that defines the type of variable arguments.<br>   
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it has a variable number of arguments.
 * <tt>CATCke::False</tt> if it has a constant number of arguments (default value).
 */
virtual CATCke::Boolean  HasVariableArgNb () const  = 0;

/**
 * Modifies the variable number of arguments property.<br>
 * @param iVariable <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it has a variable number of arguments.
 * <tt>CATCke::False</tt> if it has a constant number of arguments (default value).
 * Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void SetVariableArgNb (const CATCke::Boolean &iVariable)  = 0;

/**
 * Modifies the visibility of the function.<br>
 * A function is by default visible.<br>
 * If it is invisible, it is never shown in the V5 editors.<br>
 * @param iVariable <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it should be visible.
 * <tt>CATCke::False</tt> if not.
 */
virtual void SetUserVisibility (const CATCke::Boolean &iVariable)  = 0;

/**
 * Indicates if the function is visible.<br>
 * A function is by default visible.<br>
 * If it is invisible, it is never shown in the V5 editors.<br>
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it is visible.
 * <tt>CATCke::False</tt> if not.
 */
virtual CATCke::Boolean IsUserVisible ()  = 0;

/**
 * Modifies the information that explains if a function is time consuming.<br>
 * @param info information 
 * Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
 * on existing signatures.
 */
virtual void SetInformation (const CATCkeSignatureInfo info) =0;

/**
 * Returns the information of a signature. Not supposed to be used by anybody else than the Knowledge editors.
 * @return the information.<br>
 */
virtual CATCkeSignatureInfo GetInformation () const =0;

/**
* indicates if this signature is to be seen in different editors. 
* By default, a function can be seen in any editor of Knowledge Advisor and Knowledge Expert, except set of equations.
* @param context context of edition
* (formula = 1, rule = 2, check = 4, set of equations = 8, 
* law = 16, actions = 32, expert check = 64, expert rule = 128)
* Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
* on existing signatures.
*/
virtual void SetAllowedEditionContext(short context) = 0;

/**
* indicates if this signature is to be seen in different editors.
* @return the context of edition
* (formula = 1, rule = 2, check = 4, set of equations = 8, 
* law = 16, actions = 32, expert check = 64, expert rule = 128)
*/
virtual short GetAllowedEditionContext() = 0;


/**
* another way to define where this function is accessible, is to describe what it can and cannot support.
* @param Quality the quality of the function
* By default, a function can be seen in any editor of Knowledge Advisor and Knowledge Expert, except set of equations. 
* (inversible = 1, create object = 2, operate treatment = 4, is not update compliant = 8)
* Note that this method is supposed to be used only at the definition stage of a signature. It is not supposed to be modified afterwards
* on existing signatures.
*/
virtual void SetFunctionQuality(short Quality) = 0;

/**
* Defines if the signature has optional arguments and starting from which argument (rank 1 to N).
* @param iRankForOptionalArguments 0 to declare that there is no optional argument (by default). 1 to N .
*/
virtual void SetRankOfOptionalArguments (const int iRankForOptionalArguments)  = 0;

/**
* Indicates if the signature has optional arguments and starting from which argument (rank 1 to N).
* @return 0 to declare that there is no optional argument (by default). 1 to N .
*/

virtual int  RankOfOptionalArguments () const  = 0;

/**
 * For a reusable function, this method returns the library name
 * as used in the include statement 
 * @returns A string contaning the included library name
 */
virtual CATUnicodeString GetLibraryIfReusable() const = 0;
/**
 * Sets the Library name from which the function comes (only for 
 * reusable functions in edition context of a rule)
 * @param iLibName The library name as used in the Include statement
 */
virtual void SetLibraryForReusable(const CATUnicodeString &iLibName) = 0;

/**
* Returns the function long HTML description given by either
* @return a HTML description for the function
*/
virtual CATUnicodeString GetHTMLDescription() = 0;

/**
* Returns the function plain text description
* @return a plain text description for the function
*/
virtual CATUnicodeString GetPlainDescription() = 0;

private :
     
  // 2 define ClassName
  CATDeclareInterface;

}; 

CATDeclareHandler(CATICkeSignature,CATBaseUnknown);

#endif


