// Copyright Dassault Systemes 2005
#ifndef CATICkeExpressionFactory_H
#define CATICkeExpressionFactory_H


// Base interface
#include "CATBaseUnknown.h"

// module
#include "CATLifSpecs.h" 
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATICkeForwards.h"
#include "CATIType.h"
class CATICkeExpression_var;
class CATIInstance_var;
class CATIList_var;

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeExpressionFactory;
#else
extern "C" const IID IID_CATICkeExpressionFactory;
#endif

/**   
* Interface dedicated to Knowledge expressions creation.
* <b>Role</b>: manages the creation of Knowledge expressions.
* This interface is implemented on feature container and volatile factory (CATCkeGlobalFunctions::GetVolatileFactory())
* @see CATICkeExpression
*/
class ExportedByCATLifSpecs CATICkeExpressionFactory : public CATBaseUnknown
{
    
public:
    
    
/**
* Creates an optimization constraint expression.
* @param name
* name of the expression 
* @param comment
* comment of the expression
* @param formalSignature
* This string describes the type of used parameters and the returned type of the expression. <br>
* For an optimization constraint, no value is returned<br>
* @param body
* the body of the expression
* This method requires the PEO license (Product Engineering Optimizer product.
* <br>
* in the case of a feature, this object must be aggregated.
*/
    virtual CATICkeExpression_var CreateOptConstraint (CATUnicodeString name,
        CATUnicodeString comment,
        CATUnicodeString formalSignature,
        CATUnicodeString body) =0;
    
    
		/**
        * Creates a check expression.
        * @param name
        * name of the expression 
        * @param comment
        * comment of the expression
        * @param formalSignature
        * This string describes the type of used parameters and the returned type of the expression. <br>
        * For a check, no value is returned<br>
        * @param body
        * the body of the check expression		
		* <br>
		* in the case of a feature, this object must be aggregated.
		*/
    virtual CATICkeExpression_var CreateConstraint (CATUnicodeString name,
        CATUnicodeString comment,
        CATUnicodeString formalSignature,
        CATUnicodeString body) =0;
    
    
        /**
        * Creates a rule expression.
        * @param name
        * name of the expression 
        * @param comment
        * comment of the expression
        * @param formalSignature
        * This string describes the type of used parameters and the returned type of the expression. <br>
        * For a rule, no value is returned<br>
        * @param body
        * the body of the rule expression
		* <br>
		* in the case of a feature, this object must be aggregated.
	    */
    virtual CATICkeExpression_var    CreateProgram    (CATUnicodeString name,
        CATUnicodeString comment,
        CATUnicodeString formalSignature,
        CATUnicodeString body) = 0;
    
        /**
        * Creates a functional expression (to be used in a knowledgeware formula).
        * @param name
        * name of the expression 
        * @param comment
        * comment of the expression
        * @param formalSignature
        * This string describes the type of used parameters and the returned type of the expression. <br>
        * For a formula, the returned value is the type of the output parameter of the formula<br>
        * @param body
        * the body of the functional expression
		* <br>
		* in the case of a feature, this object must be aggregated.
		*/
    virtual CATICkeExpression_var CreateFunctionalExpression (CATUnicodeString name,
        CATUnicodeString comment,
        CATUnicodeString formalSignature,
        CATUnicodeString body) = 0;
    
    
    /**
    * Copy an expression .<br>
	* The object must be aggregated.
    */
    virtual CATICkeExpression_var CopyExpression (const CATICkeExpression_var &iExpToCopy) = 0;

    /**
	* Creates a volatile instance (an object that implements CATIInstance. Has a name. Is of a given type. And has a list of attributes.
	* WATCH OUT: List of attribute in in input are allocated by the caller and lifecycle managed by the instance. So do not delete them in your code.
	* WATCH OUT: Do not use pListChildrens. It is not supported
	* WATCH OUT: Keep last argument as it is.
    */
	
   virtual CATIInstance_var CreateVolatileInstance ( const CATUnicodeString &iName,
													 const CATIType_var &iType, // This type is the main type of the object (returned by CATIInstance::Type
													 CATLISTV(CATBaseUnknown_var) *pListAttributes = NULL,
													 CATLISTV(CATBaseUnknown_var) *pListChildrens = NULL,
													 CATBoolean iComputeModifiedAttributes = TRUE,
													 const CATIType_var &iCustoType = NULL_var) =0;   // This type is a secondary one

 

   /** @nodoc temporary solution */
   virtual void Init () = 0;

   /**
    * Creates a List object.<br>
    * @param iName name of the list.
    * The object must be aggregated.
    */
   virtual CATIList_var   CreateList (const CATUnicodeString &iName) = 0;
     
  /**
   * Creates a program from file.
   * @param iFilePath file path including the name of the file with its extension.
   * @param oProgram program generated. May be NULL if file not found or syntax incorrect.
   */
   virtual HRESULT    CreateProgramFromFile    (const CATUnicodeString &iFilePathname,CATICkeExpression_var &oProgram) =0;

   /**
	* Creates a volatile instance (an object that implements CATIInstance. Has a name. Is of a given type. And has a list of attributes. Internal use for Knowledge only
    */
   virtual CATIInstance_var CreateInternalVolatileInstance ( const CATUnicodeString &iName,
															 const CATIType_var &iType,
															 CATBoolean iComputeModifiedAttributes = FALSE) =0;	


   /** creates a volatile instance that delegates to another one 
   	 * 	 <li> E_FAIL	if we didn't find the factory that computes attribute
	 * 	 <li> S_FALSE	if the implementation of the computed attribute cannot work on this object

   */
   virtual HRESULT CreateInstanceFederation (const CATIInstance_var &iObjectToDelegateTo,const CATIType_var &iType,CATIInstance_var &oOutput) =0;

private :  
    
    // 2 define ClassName
    CATDeclareInterface; 
    
};


CATDeclareHandler(CATICkeExpressionFactory,CATBaseUnknown);


#endif




