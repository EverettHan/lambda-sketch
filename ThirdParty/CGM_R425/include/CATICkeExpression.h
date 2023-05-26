// Copyright Dassault Systemes 2002
#ifndef CATICkeExpression_H
#define CATICkeExpression_H


// module definition
#include "CATLifSpecs.h"

// inheriting from
#include "CATICkeNaming.h"

#include "CATLISTV_CATBaseUnknown.h"

// forwards definition
class CATICkeExpression_var;
class CATICkeTerm_var;
class CATIKweFunctionsProvider_var;

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeExpression;
#else
extern "C" const IID IID_CATICkeExpression;
#endif

/** 
 * Some option to parse expressions
 */ 
typedef unsigned long CATCkeParseOption;

// by default, attributes are defined using internal names
// with CATCkeParseOptionAttributesNLS option, we will use NLS names
extern ExportedByCATLifSpecs const CATCkeParseOption  CATCkeParseOptionAttributesNLS;   

//-----------------------------------------------------------------------------
/**   
 * Interface dedicated to Knowledge expressions management.
 * 
 * A Knowledge expression is an object that describes a function to be evaluated on a set of identified objects.
 * <p>
 * It is composed of a signature and a body.
 * <p>
 * The signature details the list of objects on which it is supposed to work on.
 * example : "(x: #In Integer, y: #Out Real) : #Void " means that the expression works on 2 abstract
 * objects x which is an Integer and will be used as an input; and y which is a Real and that will be
 * used as output.
 * <p>
 * The body expresses the function: example : " y=3.2*x "
 * <p>
 * A Knowledge expression is created from 2 strings (signature and body). It is able to tell if they are
 * syntaxically correct.
 * <p>
 * Knowledge Expressions also implement CATICkeFunction that is in charge of evaluation on specific objects.
 * <p>
 * This interface is multi implemented. Both by persistent and C++ expressions. See CATICkeRelationFactory for creation.
 * @see CATICkeRelationFactory
 * @see CATICkeFunction
 * @see CATICkeSignature
 * @see CATICkeArg
 * @see CATICkeType
 */
//-----------------------------------------------------------------------------
class ExportedByCATLifSpecs CATICkeExpression : public CATICkeNaming
{
  CATDeclareInterface;

public:

   /**
    * Returns the signature of this Knowledge expression.
    * This will provoke a partial "parse" of the Knowledge expression if not done already
    * @return  CATICkeSignature_var : signature of the Knowledge expression
    */
   virtual CATICkeSignature_var Signature () const = 0;

   /**
    * Returns the signature string of this Knowledge expression.
    * @return  CATUnicodeString : signature string of the Knowledge expression
    */
   virtual CATUnicodeString SignatureAsString() const = 0;

   /**
    * Returns the body of this Knowledge expression.
	* It Shouldn't be used to produce a view of the body, it returns only the body stored in the attribute.
    * @return : body in a text format
    */
   virtual CATUnicodeString Body () const = 0;
 
   /**
    * Replaces the Knowledge expression content (parse of the Knowledge expression is done).
    * This method may raise syntax error (CATCkeParseException). No ability to catch them in CAA.<br>
    * @param iSignature : signature in a text format
    * @param iBody : body in a text format
    */
   virtual HRESULT SetBody (const CATUnicodeString &iSignature,const CATUnicodeString &iBody) = 0;

   /**
    * Produces a view of the body of the Knowledge expression with a change in the variable names.
    * @param iListNames : list of the names to be used
    * @return : body view
    */
   virtual CATUnicodeString ViewBody (const CATListOfCATUnicodeString &iListNames) const = 0;

   /**
    * Copy the Knowledge expression.
    * @return : copied expression 
    */
   virtual CATICkeExpression_var Copy () const = 0;

   /**
    * Replaces a Knowledge expression by another.
    * @param iExpression : expression that replaces
    */
   virtual HRESULT Replace (const CATICkeExpression_var &iExpression) = 0;

   /**
    * @nodoc to be suppressed as soon as possible
    * Replaces an expression by another.
    * @param iExpression : expression that replaces
    */
   virtual HRESULT Replace (const CATICkeTerm_var &iExpression) = 0;


   /**
    * Indicates if a Knowledge expression can be edited (Is it syntaxically correct).
    * @return CATCke::Boolean : True if can be edited
    */
   virtual CATCke::Boolean CanBeEdited () const = 0;


   /**
    * Indicates if a Knowledge expression can be evaluated (syntaxically correct & operators available at runtime).
     * This method may raise syntax error (CATCkeParseException). No ability to catch them in CAA.<br>
    * @return CATCke::Boolean : True if can be evaluated
    */
   virtual CATCke::Boolean CanBeEvaluated () const= 0;

   
   /**
    * Indicates if a Knowledge expression contains external functions.
    * @return CATCke::Boolean : True if contains external functions
    */
   virtual CATCke::Boolean UsesExternalFunctions () const= 0;
   
   /**
    * Indicates if the Knowledge expression is broken (syntaxically incorrect or broken).
    * @return CATCke::Boolean : True if contains external functions
    */
   virtual CATCke::Boolean IsBroken () const= 0;
     
   /**
    * Indicates if a Knowledge expression contains external functions that are time consuming.
    * @return CATCke::Boolean : True if update must be postponed
    */
   virtual CATCke::Boolean IsTimeConsuming () const= 0;

   /**
    * Defines some options. On persistent expression, it is not supported yet. It will return NO_IMPL.
    * @param iOption : option to specify
    */
   virtual HRESULT	SpecifyOptions (const CATCkeParseOption iOption) = 0;

   /**
    * Retrieve some options. On persistent expression, it is not supported yet. It will return NO_IMPL.
    * @return iOption : option to specify
    */
   virtual HRESULT  RetrieveOptions (CATCkeParseOption &oOption) const = 0;
 
   
   /**
    * Tests the parse of sub expressions used in this expression (like one used in Filter, Query, Compute, Extract methods).
	* This method can be used only if the expression can be evaluated
	* Returns CATCke::Tue when the sub expressions are OK. CATCke::False instead.
	* HRESULT = E_FAIL if the expression itself is not parsable
    */
   virtual HRESULT ParseSubExpression (CATCke::Boolean &oBool) const= 0;

   /**
   * Creates a file from this expression.
   * @param iFilePath file path including the name of the file with its extension.
   * @param oProgram to generate. 
   */
   virtual HRESULT    CreateFileFromProgram    (const CATUnicodeString &iFilePathname) =0;

   /**
    * Sets for this expression a list of Libraries to automatically Include.
	* This is used in a PLM Library Function to make sure that
	* the other functions from this Library are available AND on subexpressions (query/find/... functions)
	* to inherit from the libraries of the current expression.
	* @param iNames the names under which the libraries were included
	* @param iLibToInclude a Library to be included always in the context of the current expression
	*/
   virtual void SetAutoIncludes(const CATListOfCATUnicodeString &iNames, const CATLISTV(CATBaseUnknown_var) &iLibsToInclude) = 0;

   /**
   * Returns the automatically included Library for this expression (if any)
   */
   virtual void GetAutoIncludes(CATListOfCATUnicodeString &oNames, CATLISTV(CATBaseUnknown_var) &oLibsToInclude) = 0;

   /**
    * Returns the list of included libraries for this expression 
	* after parse.
	* @return a list containing CATIKweFunctionProvider objects
	*/
   virtual void GetIncludedLibs(CATListOfCATUnicodeString &oNames, CATLISTV(CATBaseUnknown_var) &oLibs) const = 0;

};

// declaration of Handler
CATDeclareHandler(CATICkeExpression,CATICkeNaming);


#endif

