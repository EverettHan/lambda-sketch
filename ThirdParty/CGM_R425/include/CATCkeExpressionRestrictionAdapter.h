#ifndef CATCkeExpressionRestrictionAdapter_H
#define CATCkeExpressionRestrictionAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 2002


// Export Module 
#include "CATLifSpecs.h"

// inherit from
#include "CATBaseUnknown.h"
#include "CATICkeExpressionRestriction.h"


/**   
 * Adapter to CATICkeExpressionRestriction Interface.
 * <b>Role</b>: This class must be derived to implement CATICkeExpressionRestriction.<br>
 * CATICkeExpressionRestriction is the interface used by Knowledgeware to take into account restrictions on keywords/types/methods for an expression	.<br>
 * @see CATICkeExpressionRestriction
 */
class ExportedByCATLifSpecs CATCkeExpressionRestrictionAdapter : public CATICkeExpressionRestriction
{
public:

   /** 
    * Constructs the object.
    */ 
    CATCkeExpressionRestrictionAdapter();

   /** 
    * Deletes the object.
    */ 
    virtual ~CATCkeExpressionRestrictionAdapter();

 	/** 
	 * This method MUST BE overriden.<br>
	 * This method retrieves the NLS name of the kind of expression (reason why there is a restriction).<br>
	 * This name is used to build parse errors saying something like this "the keyword else can not be used in a ** "
	 * ** is replaced by the name returned by NameOfExpressionKind.<br>
	 */
   virtual CATUnicodeString NameOfExpressionKind () const = 0;


	  /** 
       * This method MUST BE overriden.<br>
       * Declares interest of the restriction. Do we want to be called.<br>
	   * Very important method for performance
	   * @param iInterestedInTypes I want to be called on ValidateType
	   * @param iInterestedInTypesOfValues I want to be called on ValidateType on types of values
	   * @param iInterestedInKeyword I want to be called on ValidateKeyword
	   * @param iInterestedInSignature I want to be called on ValidateSignature
	   * @param iInterestedInAttributes I want to be called on ValidateAttribute
	   * @return the answer from the application
       */
	  virtual void DeclareInterest (  CATBoolean &iInterestedInTypes,	
									  CATBoolean &iInterestedInTypesOfValues,
									  CATBoolean &iInterestedInKeyword,
									  CATBoolean &iInterestedInSignature,
									  CATBoolean &iInterestedInAttributes) const = 0; 

	  /**
       * This method CAN BE overriden.<br>
       * Asks for the validation of a keyword (let for while).<br>
	   * @param iKeyword the keyword
	   * @return the answer from the application
	   * Default implementation returns that all keywords are OK.
       */
	  virtual CATICkeExpressionRestriction::RestrictionStatus ValidateKeyword (const CATUnicodeString &iKeyword) const ; 

	  /**
       * This method CAN BE overriden.<br>
       * Asks for the validation of a signature. Use CATICkeSignature::Notation if you're interested by some cases.<br>
	   * @param iSignature the function
	   * @return the answer from the application
	   * Default implementation calls the other ValidateSignature with the name in argument.
       */
	  virtual CATICkeExpressionRestriction::RestrictionStatus ValidateSignature (const CATICkeSignature_var &iSignature) const; 

	  /**
       * This method CAN BE overriden.<br>
       * Asks for the validation of a signature.<br>
	   * At this stage we have only the name and the notation which could be sufficient. 
	   * @param iSignatureName the name of the type.
	   * @param iSignatureNotation the name of the type.
	   * @return the answer from the application
	   * Default implementation returns that all signatures are OK.
       */
	  virtual CATICkeExpressionRestriction::RestrictionStatus ValidateSignature (const CATUnicodeString &iSignatureName, const CATICkeSignature::Mode iNotation	) const ; 

	  /**
       * This method CAN BE overriden.<br>
       * Asks for the validation of a type.<br>
	   * @param iType the type
	   * @return the answer from the application
	   * Default implementation calls the other ValidateType with the name in argument.
       */
	  virtual CATICkeExpressionRestriction::RestrictionStatus ValidateType (const CATICkeType_var &iType,const CATBoolean iIsAValue=FALSE) const ; 

	  /**
       * This method CAN BE overriden.<br>
       * Asks for the validation of a type.<br>
	   * At this stage we have only the name which could be sufficient. 
	   * @param iTypeName the name of the type.
	   * @return the answer from the application
	   * Default implementation returns that all types are OK.
       */
	  virtual CATICkeExpressionRestriction::RestrictionStatus ValidateType (const CATUnicodeString &iTypeName,const CATBoolean iIsAValue=FALSE) const ; 


private:
 

  /**
   */
   CATCkeExpressionRestrictionAdapter(const CATCkeExpressionRestrictionAdapter&);
};


#endif
