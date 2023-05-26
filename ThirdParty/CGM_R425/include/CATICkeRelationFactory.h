// Copyright Dassault Systemes 2000
#ifndef CATICkeRelationFactory_H
#define CATICkeRelationFactory_H



/** 
* @CAA2Level L1
* @CAA2Usage U3 
*/ 

/*  CAA2Reviewed by FRH */

// include root of extension CKE
#include "CATBaseUnknown.h"

//LiteralFeatures
#include "KnowledgeItf.h"
#include "CATICkeRelationForwards.h"
#include "CATICkeSignature.h"
#include "CATICkeParameterSet.h"
#include "CATIParmPublisher.h"
#include "CATICkeFunction.h"

class CATIList_var;
class CATIPsiRepresentationReference_var;


// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeRelationFactory;
#else
extern "C" const IID IID_CATICkeRelationFactory;
#endif

/**   
* Interface dedicated to Knowledge relations creation.
* <b>Role</b>: manages the creation of Knowledge relations.
* This interface is implemented on feature container.<br>
* Note that the behavior of a Knowledge relation is that it does not need to be evaluated "by hand".<br>
* By default, the creation methods are creating an active relationship, that is evaluated within the method.<br>
* @see CATIParmPublisher, CATIParmManipulator
*/
class ExportedByKnowledgeItf CATICkeRelationFactory : public CATBaseUnknown
{
    
public:
    
      
        /**
        * @nodoc to be suppressed
        * Creating a relation from something else.
		* SPECIAL CASE FOR FORMULAS : the ouput parameter is at the end of the list.
    */
    virtual CATICkeRelationExp_var CreateRelation  (CATUnicodeString n,
        CATUnicodeString c,
        CATUnicodeString p,
        CATCkeListOfParm lstparam,
        const CATICkeType_var &t,
        const CATICkeExpression_var &e,
        CATCke::Boolean synchrone,
        CATCke::Boolean shared = 0) =0;
    
    
        /**
        * @nodoc to be suppressed
        * Create a parameter.
    */
    virtual CATICkeParm_var CreateParameter (CATUnicodeString ident,
        const CATICkeInst_var &val,
        CATCke::Boolean constval) =0;
    
    
        /**
        * Creates a relation set.
        * @param name
        * name of the relation set. 
        * @return the newly created relation set viewed a a parameter publisher.
		* <br>
		* only works on persistent factory. This object must be aggregated.
		*/
		virtual CATIParmPublisher_var CreateRelationSet (const CATUnicodeString name) =0;
    
    /**
    * Creates a parameter set.
    * @param name
    * name of the parameter set. 
    * @return the newly created relation set viewed a a parameter publisher.
	* <br>
	* only works on persistent factory. This object must be aggregated.
	*/
    virtual CATIParmPublisher_var CreateParameterSet (const CATUnicodeString name) =0;
    
    
    
    /**
    * Creates an optimization set.
    * @param name
    * name of the optimization set. 
    * @return the newly created optimization set viewed a a parameter publisher.
	* <br>
	* only works on persistent factory. This object must be aggregated.
    */
    virtual CATIParmPublisher_var CreateOptimizationSet() = 0;
    
    
    /**
    * Create a formula between parameters (example : y=3*x).<br>
    * if a syntax error occurs, NULL_var is returned and a CATCkeParseException exception is raised<br>
    * @param iRelationName formula's name
    * @param iComment no more used for formula !!
    * @param iFamily not used !!
    * @param iOutputParameter valuated parameter (y in our example)
    * @param iListOfParameters  (pointer on list of CATBaseUnknown_var) contains literal used in inputs (x in our example)  
    * @param iBody contains the string describing the formula ("3*x" in our example)
    * @param iRoot (CATIParmPublisher) used to name parameters with RelativeName (root) method<br> 
    * and so to be able to recognize parameters by their name <br>
    * Not used in realnames = false mode<br>
    * @param iRealnames  = 2 possibilities to name a parameter in the body.<br> 
    * <tt>CATCke::True</tt>  names used are the one returned by RelativeName (root) and we try to recognize names used in the body with parameters of iListParameters..
    * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
    *                        a1 meaning the first parameter of iListParameters, a2, the second one, etc....<br>
    * We advise you strongly to use this second method in your application to avoid NLS problems .  <br>
    * <br>
    * @return Formula created or NULL_var if syntax error<br>
	* <br>
	* only works on persistent factory. This object must be aggregated.
	* The parameters passed as arguments must be in the same container as the relation. This will be enforced in the future release
	* to allow only supported model.
    */
    virtual CATICkeRelation_var CreateFormula ( const CATUnicodeString    &iRelationName,
												const CATUnicodeString    &iComment,
												const CATUnicodeString    &iFamily,
												const CATICkeParm_var     &iOutputParameter,
												const CATCkeListOfParm     iListOfParameters,
												const CATUnicodeString    &iBody,
												const CATIParmPublisher_var &iRoot = NULL_var,
												const CATCke::Boolean     &iRealnames = 1) = 0;
    
        /**
        * Create a rule between parameters (example : if (x> 3) y=3*x else y = 2).<br>
		* Watch out: to use this service, you need to have the Knowledge Advisor license at runtime.<br> 
        * if a syntax error occurs, NULL_var is returned and a CATCkeParseException exception is raised<br>
        * @param iRelationName  program's name
        * @param iComment comment  !!
        * @param iFamily not used !!
        * @param iListOfParameters (pointer on list of CATBaseUnknown_var) contains literal used in inputs or outputs (x and y  in our example)  
        * @param iBody contains the string describing the program ("if (x> 3) y=3*x else y = 2" in our example)
        * @param iRoot (CATIParmPublisher) used to name parameters with RelativeName (root) method <br>
        * and so to be able to recognize parameters by their name<br>
        * Not used in realnames = false mode<br>
        * @param iRealnames  = 2 possibilities to name a parameter in the body.<br> 
        * <tt>CATCke::True</tt>  names used are the one returned by RelativeName (root) and we try to recognize names used in the body with parameters of iListParameters..
        * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
        *                        a1 meaning the first parameter of iListParameters, a2, the second one, etc....<br>
        * We advise you strongly to use this second method in your application to avoid NLS problems .  
        * <br> 
        * @return Rule created or NULL_var if syntax error
		* <br>
		* only works on persistent factory. This object must be aggregated.
		* The parameters passed as arguments must be in the same container as the relation. This will be enforced in the future release
		* to allow only supported model.	
	    */
		virtual CATICkeRelation_var CreateProgram (	const CATUnicodeString    &iRelationName,
													const CATUnicodeString    &iComment,
													const CATUnicodeString    &iFamily,
													const CATCkeListOfParm     iListOfParameters,
													const CATUnicodeString    &iBody,
													const CATIParmPublisher_var &iRoot = NULL_var,
													const CATCke::Boolean     &iRealnames = 1) = 0;
    
        /**
        * Create a check between parameters (example : x > 3).<br>
		* Watch out: to use this service, you need to have the Knowledge Advisor license at runtime.<br> 
        * if a syntax error occurs, NULL_var is returned and a CATCkeParseException exception is raised<br>
        * @param iRelationName program's name
        * @param iComment comment
        * @param iFamily not used !!
        * @param iListOfParameters (pointer on list of CATBaseUnknown_var) contains literal used in inputs (x and y  in our example)  
        * @param iBody contains the string describing the check ("x> 3" in our example)
        * @param iRoot (CATIParmPublisher) used to name parameters with RelativeName (root) method<br> 
        * and so to be able to recognize parameters by their name<br>
        * Not used in realnames = false mode<br>
        * @param iRealnames  = 2 possibilities to name a parameter in the body. <br>
        * <tt>CATCke::True</tt>  names used are the one returned by RelativeName (root) and we try to recognize names used in the body with parameters of iListParameters..
        * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
        *                        a1 meaning the first parameter of iListParameters, a2, the second one, etc....<br>
        * We advise you strongly to use this second method in your application to avoid NLS problems .  
        * <br>
        * @return check created or NULL_var if syntax error
		* <br>
		* only works on persistent factory. This object must be aggregated.
		* The parameters passed as arguments must be in the same container as the relation. This will be enforced in the future release
		* to allow only supported model.
		*/
	    virtual CATICkeRelation_var CreateCheck   (	const CATUnicodeString     &iRelationName,
													const CATUnicodeString     &iComment,
													const CATUnicodeString     &iFamily,
													const CATCkeListOfParm    iListOfParameters,
													const CATUnicodeString     &iBody,
													const CATIParmPublisher_var &iRoot = NULL_var,
													const CATCke::Boolean    &iRealnames = 1) = 0;
	
		/**
        * Create an Equivalent Dimension.<br>
        * if a syntax error occurs, NULL_var is returned<br>
        * @param name program's name
        * @param comment comment
        * @param family not used !!
        * @return EquivalentDimension created or NULL_var if no EquivalentDimension has been created
		* <br>
		* only works on persistent factory. This object must be aggregated.
	    */
	virtual CATICkeRelation_var CreateEquivalentDimensions(
		const CATUnicodeString	&name,
		const CATUnicodeString	&comment,
		const CATUnicodeString	&family) = 0;
    
        /**
        * @nodoc to be suppressed
        * Create a simple relation between 2 parameters 'y = ax+b'.
        * with x is first parameter, y is second one. This relation is synchronous <br>
        * 
        * @param iRelationName  relations name
        * @param iComment comment
        * @param iFamily not used !!
        * @param iX input literal
        * @param iY output literal
        * @param iA a
        * @param iB b
        * @return relation created
	   */
    virtual CATICkeRelation_var CreateSymetricalRelation (const CATUnicodeString &iRelationName,
        const CATUnicodeString &iComment,
        const CATUnicodeString &iFamily,
        const CATICkeParm_var &iX,
        const CATICkeParm_var &iY,
        const double iA,
        const double iB) = 0;
    
        /**
        * Creates a fully functional design table (with its embedded sheet) from a file (excel or text file).<br>
        * @Returns an handler on the new design table. if a problem occurs while creating it (bad file format), returns NULL_var 
        * @param iRelationName The name of the design table
        * @param iComment The comment associated to the design table
        * @param iFilePath
        *	The path of the sheet file.
        *	- If param sheetWithoutFile = 0 :
        *			if this path contains ".xls", the Excel format is assumed, else the tabulated text format is used.
        *			If this path is empty, no sheet is aggregated to the design table, and the user has to create a sheet 
        *			(method CreateSheet) and associate it to an excel or text file)
        *	- If param sheetWithoutFile = 1 :
        *			no matter with the content of this path
        * @param orientation
        *	1 if vertical, 0 else (used only if path != "" and sheetWithoutFile = 0)
        * @param sheetWithoutFile
        *	If sheetWithoutFile = 1, a model sheet is created (sheet with persitent memory storage, but no file)
        *	and it won't be possible to associate a file to this sheet.
		* <br>
		* only works on persistent factory. This object must be aggregated.
		* @return the created design table
		*/
		virtual CATIDesignTable_var CreateDesignTable(	const CATUnicodeString     &iRelationName,
														const CATUnicodeString &iComment,
														const CATUnicodeString &iFilePath,
														int orientation = 1,
														int sheetWithoutFile = 0) = 0;
    

    /**
    * Creates a fully functional design table (with its embedded sheet) from the file name (excel or text file).<br>
	*
	* @param oDesignTable the new design table. 
	* @param iRelationName The name of the design table
    * @param iComment The comment associated to the design table
    * @param iFilePath
    *	The path of the sheet file.
    *	- If param sheetWithoutFile = 0 :
    *			if this path contains ".xls", the Excel format is assumed, else the tabulated text format is used.
    *			If this path is empty, no sheet is aggregated to the design table, and the user has to create a sheet 
    *			(method CreateSheet) and associate it to an excel or text file)
    *	- If param sheetWithoutFile = 1 :
    *			no matter with the content of this path
    * @param iOrientation
    *	1 if vertical, 0 else (used only if path != "" and sheetWithoutFile = 0)
    * @param iSheetWithoutFile
    *	If sheetWithoutFile = 1, a model sheet is created (sheet with persitent memory storage, but no file)
    *	and it won't be possible to associate a file to this sheet.
	* @return E_FAIL if the method fails 
	*		  S_OK if the method succeeds
	* <br>
	* only works on persistent factory. This object must be aggregated.
	*/

	virtual HRESULT CreateDesignTable(CATIDesignTable_var& oDesignTable,
		                      const CATUnicodeString     &iRelationName,
							  const CATUnicodeString &iComment,
							  const CATUnicodeString &iFilePath,
		                      int iOrientation,
							  int iSheetWithoutFile = 0) = 0;


    /**
    * Creates a fully functional design table (with its embedded sheet) from a Representation Reference.<br>
	* Returns an handler on the new design table.
	*
	* @param oDesignTable the new design table. 
	* @param iRelationName The name of the design table
    * @param iComment The comment associated to the design table
    * @param iRepresentation The representation reference.	
    * @param iOrientation
    *	1 if vertical, 0 else (used only if path != "" and sheetWithoutFile = 0)
    * @param iSheetWithoutFile
    *	If sheetWithoutFile = 1, a model sheet is created (sheet with persitent memory storage, but no file)
    *	and it won't be possible to associate a file to this sheet.
	* @return E_FAIL if the method fails 
	*		  S_OK if the method succeeds
	* <br>
	* only works on persistent factory. This object must be aggregated.
	*/
	virtual HRESULT CreateDesignTable(CATIDesignTable_var& oDesignTable,
									  const CATUnicodeString     &iRelationName,
									  const CATUnicodeString &iComment,
									  const CATIPsiRepresentationReference_var& iRepresentation,
		                              int iOrientation, 
									  int iSheetWithoutFile = 0) = 0;

    
    /**
	* Creates a sheet feature.
        * @param iFilePath The path of the source file. It can be an Excel or a Lotus sheet
        * or a tabulated text file, or an empty path (if iType != 4, you'll have to call 
        * CreateSourceFile on CATICkeSheet interface).
        * If the path isn't empty and the file doesn't exist, the file is created.
        * @param iType
        * - if iType = 4, whatever the content of the path, a model sheet 
        *   is created (sheet with persitent memory storage, but no file) 
        * - if path is empty, uses the type to know what kind of sheet has to be created
        *   <br><b>Legal values</b>: the test can be either
        *   <tt>1</tt> Excel one.
        *   <tt>2</tt> Text one
        *   <tt>3</tt> Lotus one
        *   <tt>4</tt> Model one
        * @return
        * the created sheet. It returns NULL_var if the file creation failed (in the case where the file has to be created) or if Excel or Lotus is asked on UNIX
		* <br>
		* only works on persistent factory. This object must be aggregated.
	    */
    virtual CATICkeSheet_var CreateSheet(const CATUnicodeString &iFilePath,int iType = 0) = 0;
    
  
	/**
	* Creates a sheet feature. 
	* @param oSheet The sheet feature
	* @param iRepresentation The representation reference.	
    * @param iSheetWithoutFile
    *	If sheetWithoutFile = 1, a model sheet is created (sheet with persitent memory storage, but no file)
    *	and it won't be possible to associate a file to this sheet.
	* @return E_FAIL if the method fails for example if Excel or Lotus is asked on UNIX
	*		  S_OK if the method succeeds
    */
	virtual HRESULT CreateSheet(CATICkeSheet_var& oSheet,const CATIPsiRepresentationReference_var& iRepresentation,int iSheetWithoutFile = 0) = 0;
	
    /**
    * Creates an optimization constraint (example : x > 3).
    * 
    * if a syntax error occurs, NULL_var is returned and a CATCkeParseException exception is raised<br>
    * 
    * @param iRelationName optimization constraint's name
    * @param iComment comment
    * @param iPrecision precision attached to the comparison
    * @param iPriority priority of the optimization constraint in the context of a multiple constrained optimization
    * @param iListOfParameters (pointer on list of CATBaseUnknown_var) contains literal used in inputs (x and y  in our example)  
    * @param iBody contains the string describing the check ("x> 3" in our example)
    * @param iRoot (CATIParmPublisher) used to name parameters with RelativeName (root) method 
    * and so to be able to recognize parameters by their name <br>
    * Not used in realnames = false mode
    * @param iRealnames 2 possibilities to name a parameter in the body. <br>
    * <tt>CATCke::True</tt>  names used are the one returned by RelativeName (root) and we try to recognize names used in the body with parameters of iListParameters..
    * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
    *                        a1 meaning the first parameter of iListParameters, a2, the second one, etc....<br>
    * We advise you strongly to use this second method in your application to avoid NLS problems .  
    * 
    * @return = optimization constraint created or NULL_var if syntax error
	* <br>
	* only works on persistent factory. This object must be aggregated.
	* The parameters passed as arguments must be in the same container as the relation. This will be enforced in the future release
	* to allow only supported model.
	* This method reuires the PEO license (Product Engineering Optimizer).
    */
    virtual CATICkeRelation_var CreateOptimizationConstraint   (const CATUnicodeString     &iRelationName,
        const CATUnicodeString     &iComment,
        double iPrecision,
        int iPriority,
        const CATCkeListOfParm    iListOfParameters,
        const CATUnicodeString     &iBody,
        const CATIParmPublisher_var &iRoot = NULL_var,
        const CATCke::Boolean    &iRealnames = 1) = 0;
    
        /**
        * Creates a law between parameters and formal parameters (example : y = sin(x) + Real.1).<br>
        * if a syntax error occurs, NULL_var is returned and a CATCkeParseException exception is raised<br>
        * @param iRelationName  program's name
        * @param iComment comment  !!
        * @param iFamily not used !!
        * @param iListOfParameters (pointer on list of CATBaseUnknown_var) contains literal used in inputs or outputs (Real.1 in our example)  
        * @param iListOfFormalParameters (pointer on list of CATBaseUnknown_var) contains formal literal used in inputs or outputs (x and y  in our example)  
        * @param iBody contains the string describing the program ("y = sin(x) + Real.1" in our example)
        * @param iRoot (CATIParmPublisher) used to name parameters with RelativeName (root) method <br>
        * and so to be able to recognize parameters by their name<br>
        * Not used in realnames = false mode<br>
        * @param iRealnames  = 2 possibilities to name a parameter in the body.<br> 
        * <tt>CATCke::True</tt>  names used are the one returned by RelativeName (root) and we try to recognize names used in the body with parameters of iListParameters..
        * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
        *                        a1 meaning the first parameter of iListParameters, a2, the second one, etc....<br>
        * We advise you strongly to use this second method in your application to avoid NLS problems .  
        * <br> 
        * @return Rule created or NULL_var if syntax error
		* only works on persistent factory. This object must be aggregated.
		* The parameters passed as arguments must be in the same container as the relation. This will be enforced in the future release
		* to allow only supported model.
	    */
		virtual CATICkeRelation_var CreateLaw (	const CATUnicodeString    &iRelationName,
												const CATUnicodeString    &iComment,
												const CATUnicodeString    &iFamily,
												const CATCkeListOfParm     iListOfParameters,
												const CATCkeListOfParm     iListOfFormalParameters,
												const CATUnicodeString    &iBody,
												const CATIParmPublisher_var &iRoot = NULL_var,
												const CATCke::Boolean     &iRealnames = 1) = 0;
    
        /**
        * Creates a relation from another by copying it.
        * Works only on formulas, not on rules or checks.
		* Works only on the same container.
		* The copied relation must be aggregated.
        * Note that second relation will reference the same parameters, il will be deactivated
        * @param iRelationToCopy parameter to copy
        * @return CATICkeRelation_var relation copied
		*/
		virtual CATICkeRelation_var Copy (const CATICkeRelation_var     &iRelationToCopy) = 0 ;
    
    
    
    /**
    * @nodoc to be suppressed
    * Initialise LiteralFeatures environnement.<br>
    * It finds all startups needed in this container.<br>
    */
    virtual void Init () = 0;
    
    /**
    * @nodoc to be suppressed
    */
    virtual void End () = 0;
    
    /**
    * Creates a feature macro with arguments.<br>
	* Watch out: to use this service, you need to have the Knowledge Advisor license at runtime.<br> 
    * It is initialized like the following : <br>
    * no argument<br>
    * the entry point is called <it>main</it><br>
    * the body is empty
	* This method requires the KWA license (Knowledge Advisor).
	* The object must be aggregated.
	* @return the macro created
    */
    virtual CATBaseUnknown_var CreateKweMacro() = 0;
    
    /**
    * Creates a feature macro with arguments.<br>
	* Watch out: to use this service, you need to have the Knowledge Advisor license at runtime.<br> 
    * It is initialized with the given arguments
	* @param iArgumentString the argument string
	* @param iScriptText the script text
	* @return The feature macro
	* @example
	*	CATICkeFunction_var MyFunc = MyFact->CreateKweMacro("MyArg","MyArg.Value = 10.0\nEnd Sub");
    */
    virtual CATICkeFunction_var CreateKweMacro(const CATUnicodeString& iArgumentString, const CATUnicodeString& iScriptText) = 0;


    /**
    * @nodoc to be suppressed
    * Creates an equality link between two parameters. <br>
    * The output parameter will always be equal to the input parameter. <br>
    * The equlity mechanism is integrated to update.
    * @param iOutputParameter : The valuated parameter
    * @param iInputParameter : The valuating parameter
    */
    virtual void CreateEquality(const CATICkeParm_var& iOutputParameter, const CATICkeParm_var& iInputParameter) = 0;
    
    /**
	* @nodoc Use CATICkeParmFactory::CreateList
    * Creates a List object.<br>
    * @param iName name of the list.
	* The object must be aggregated
    */
    virtual CATIList_var   CreateList (const CATUnicodeString &iName) = 0;
    
    /**
	 * Creates an action.
	* Watch out: to use this service, you need to have the Knowledge Advisor license at runtime.<br> 
	 * <br>
     * If a syntax error occurs, NULL_var is returned and a CATCkeParseException exception is raised<br>
        * @param iRelationName  program's name
        * @param iComment comment  !!
        * @param iFamily not used !!
        * @param iSignature external signature of the action
        * @param iListOfParameters (pointer on list of CATBaseUnknown_var) contains literal used in inputs or outputs (Real.1 in our example)  
        * @param iBody contains the string describing the program ("y = sin(x) + Real.1" in our example)
        * @param iRoot (CATIParmPublisher) used to name parameters with RelativeName (root) method <br>
        * and so to be able to recognize parameters by their name<br>
        * Not used in realnames = false mode<br>
        * @param iRealnames  = 2 possibilities to name a parameter in the body.<br> 
        * <tt>CATCke::True</tt>  names used are the one returned by RelativeName (root) and we try to recognize names used in the body with parameters of iListParameters..
        * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
        *                        a1 meaning the first parameter of iListParameters, a2, the second one, etc....<br>
        * We advise you strongly to use this second method in your application to avoid NLS problems .  
        * <br> 
        * @return Action created or NULL_var if syntax error
		* only works on persistent factory. This object must be aggregated.
		* The parameters passed as arguments must be in the same container as the relation. This will be enforced in the future release
		* to allow only supported model.
		* This method requires the Knowledge Advisor license (KWA)
		*/
    virtual CATICkeRelation_var CreateAction (	const CATUnicodeString    &iRelationName,
												const CATUnicodeString    &iComment,
												const CATUnicodeString    &iFamily,
												const CATICkeSignature_var    &iSignature,
												const CATCkeListOfParm     iListOfParameters,
												const CATUnicodeString    &iBody,
												const CATIParmPublisher_var &iRoot = NULL_var,
												const CATCke::Boolean     &iRealnames = 1) = 0;
    
    /**
    * Creates a feature reaction.
	* Watch out: to use this service, you need to have the Knowledge Advisor license at runtime.<br> 
	* This object must be aggregated.
	* This method requires the Knowledge Advisor license (KWA).
	* @return the reaction feature
    */
    virtual CATBaseUnknown_var CreateReaction() = 0;
    
    /**
    * @nodoc to be suppressed
    * Copy an expression .<br>
	* The object must be aggregated.
	* @return the expression copied
    */
    virtual CATICkeExpression_var CopyExpression (const CATICkeExpression_var &iExpToCopy) = 0;
	
private :  
    
    // 2 define ClassName
    CATDeclareInterface;
    
};


CATDeclareHandler(CATICkeRelationFactory,CATBaseUnknown);


#endif




