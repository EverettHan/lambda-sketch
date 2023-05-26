// COPYRIGHT DASSAULT SYSTEMES  1999

#ifndef CATCkeParser_H
#define CATCkeParser_H

#include "CATLifParser.h"

#include "CATCkeContext.h"
#include "CATICkeRelationForwards.h"
#include "CATICkeType.h"
#include "CATIParmPublisher.h"
#include "CATICkeExpressionRestriction.h"


/**   
 * Class used by our basic editor to build a relation, an expression or to check syntax.
 * <b>Role</b>: we provide a ready to use editor that allow a user to create or modify a 
 * formula, a rule or a check.<br>
 * This editor provides selection in the V5 model, a wizard and checks the syntax of objects created.<br>
 * This class is an abstraction of what is manipulated through this editor.<br>
 * It can be a relation (formula, rule or check).<br>
 * It can be an expression (same kind of objects working on abstractions).<br>
 * The editor can be used only as a tester and produce a text=>this is the last use case.<br>
 * 
 */
class ExportedByCATLifParser CATCkeParser 
{
  public :

    /**
    * Creates a Parser on an expression.
    * The expression must have been created previously: it can be invalid at the beginning.
    * @param  iExpression: expression
    * @param  iRest: indicates if we want to impose a restriction to what is parsed
    * The parser object returned must be deallocated.
    */
   static CATCkeParser *Create (const CATICkeExpression_var &iExpression,const CATICkeExpressionRestriction_var &iRest = NULL_var);
   
 
   /**
    * Returns the current body entered by end-user (or starting body).
	* This is the body to be shown in the editor.
	* It contains the last body "entered" through the editor even if it is invalid.
	* (entered mean Validate with the Validate method)
    */
   CATUnicodeString Body () const ;

   /**
    * Indicates if the current body is valid. It may be invalid since the beginning.
	* Validation of this body through the editor (OK) should be forbidden.
    */
   CATCke::Boolean  IsValid  () const ;

   /**
    * Validates a new body (catch the error or warning (checkmagnitude) in output if any).
    * This method may raise syntax error (CATCkeParseException)
    * @param iBody: new body to validate => becomes the current one even if validation fails
	* @param iListOfParm: list of parameters that can be used in the definition of this object
	* @return : return True is valid. False instead
    */
   virtual CATCke::Boolean Validate (const CATUnicodeString &iBody,const CATCkeListOfParm iListOfParm) =0;
 
   /**
    * Get the list of parameters already used by this object. 
	* List is not allocated-> Do not delete it. Can Be NULL
	*/
   virtual CATCkeListOfParm  BeginningList () const =0;

   virtual ~CATCkeParser ();

   void SetAggregationContext(const CATIParmPublisher_var publisher);

   // Returns the applicative restriction to the parser
   CATICkeExpressionRestriction_var GetRestriction()const;
   void SetRestriction(const CATICkeExpressionRestriction_var &iRest) { _Restriction = iRest;};

   // Allows to plug the parser on another expression (used when browsing from expression to expression through the interactive combo in reusable functions)
   static void Update (CATCkeParser * iParser, const CATICkeExpression_var &iExpression,const CATICkeExpressionRestriction_var &iRest);
  protected:

 
   //-------------------------------
   // Construction Methods
   //-------------------------------
   CATCkeParser (const CATICkeExpressionRestriction_var &iRest = NULL_var);
   CATCkeParser (const CATCkeParser&);

   CATIParmPublisher_var root_;
   CATUnicodeString body_;
   CATCke::Boolean  isvalid_;

   CATIParmPublisher_var _AggregationContext;
   CATICkeExpressionRestriction_var _Restriction;
} ;




#endif


