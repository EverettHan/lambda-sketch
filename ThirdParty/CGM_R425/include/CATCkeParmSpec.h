/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

// COPYRIGHT DASSAULT SYSTEMES 1999
#ifndef CATCkeParmSpec_h
#define CATCkeParmSpec_h

// module
#include "CATLifDictionary.h"

// inherited from
#include "CATCkeParm.h"
#include "CATICkeExpressionForwards.h"

// Modif frh 29 sept 2006: implementation of CATIParmVariable
#include "CATIParmVariable.h"

#define DATUMPOINTERTYPEDEFINED 1
#define NEWKWENAMING 1 // pour activer le dev sur le nouveau nommage dans KnowledgeModeler

class CATTime;

// Used to create references on features
class  ExportedByCATLifDictionary CATCkeParmSpec: public CATCkeParm
{
	CATCkeParmSpec (const CATCkeParmSpec&);
public :

  CATCkeParmSpec (const CATICkeType_var&, CATUnicodeString = "", const CATCke::Boolean outside = CATCke::True,const CATCke::Boolean constant=CATCke::False);
  CATCkeParmSpec (const CATICkeInst_var&, CATUnicodeString = "", const CATCke::Boolean outside = CATCke::True); // from instance. const
	virtual ~CATCkeParmSpec() ;

	// rename 
	virtual void           Rename       (const CATUnicodeString &s) ;
	virtual CATCke::Boolean        IsNamed      () const;
	virtual CATUnicodeString         Pathname     (const CATIParmPublisher_var &context = NULL_var,CATUnicodeString *p=NULL) const ;
	virtual CATUnicodeString         RelativeName (const CATIParmPublisher_var &context = NULL_var) const ;
	virtual CATUnicodeString Role         (const CATIParmPublisher_var &des = NULL_var) const;

	// valuate
	virtual void     Valuate  (const CATICkeInst_var&);	// raises ConstObject, InvalidType
	virtual void     ValuateObject  (const CATBaseUnknown_var &v) ;   // raises InvalidType, ConstObject 

	virtual void     Valuate  (const double v) ;      // raises InvalidType, ConstObject 
	virtual void     Valuate  (const int v) ;      // raises InvalidType, ConstObject 
	virtual void     Valuate  (const CATUnicodeString v) ;    // raises InvalidType, ConstObject 
	virtual void     Valuate  (const CATCke::Boolean v) ;   // raises InvalidType, ConstObject 
	virtual void     Valuate  (const CATTime& ) ;   // raises InvalidType, ConstObject 

	virtual  CATICkeParm::UserAccessMode UserAccess () const ;
	virtual void           SetUserAccess (CATICkeParm::UserAccessMode m) ; 

	virtual CATUnicodeString   Family() const;
	virtual CATICkeType_var Type() const ; 
	virtual CATCke::Boolean  IsSet() const ; 
	virtual CATICkeInst_var Value() const;	// raises UnsetParameter

	/**
	* Returns the type of the variable (opposed to the type of the value, which is the same in most cases but not all.
	*/
	virtual CATICkeType_var VariableType () const;

	int IsPointerOnDatum(){return _DatumPointerType;};
	int IsPropagatingPointerOnDatum(){return _PropagateDatumPointerType;};
	void SetIsPointerOnDatum(int value) {_DatumPointerType = value;};
	void SetIsPropagatingPointerOnDatum(int value) {_PropagateDatumPointerType = value;};
	
#ifdef CATIAR203
  // Modif frh 29 sept 2006: implementation of CATIParmVariable
  // This service returns the identification of a parameter 
	virtual HRESULT IdentifyParameter (CATIParmVariable::ParameterIdentification &oIdentification) const;

    /*
	 * A CATICkeParm is a variable in any case (meaning that it can be manipulated as a variable in the Knowledge Language
	 * But some are just variables (volatile value, volatile list, volatile pointer, volatile valuePointer) and some are objects 
	 * that can be referenced by a relation (literal, new literal, list, pointer, value pointer, and object reference)
	 * this method indicates that the parameter is a pure volatile variable (watch out, answers false for an object reference)
	 */
	virtual CATCke::Boolean IsVolatile () const;

#endif 
private:

	CATBaseUnknown_var GetObject() const;
	CATICkeFeature_var GetFeature() const;

  unsigned int _PropagateDatumPointerType:1;
  unsigned int _DatumPointerType:1;
  unsigned int _renamed:1;

	CATDeclareClass;
}; 

#endif


