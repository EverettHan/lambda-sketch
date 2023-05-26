#ifndef UITypeHandler_h
#define UITypeHandler_h


#include "PLMDictionaryNavServices.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

class CATIType_var;
class CATICkeObject_var;

class UIPackage;
class CATListValUITypeHandler;
class UITypeHandlerLetter;

//----------------------------------------------------------------------------------------------------------------------------------------
// This class is proposed for UI Components to navigate in PLM types (mainly for search and PLM new)
//----------------------------------------------------------------------------------------------------------------------------------------
 
class  ExportedByPLMDictionaryNavServices UITypeHandler
{
	
public :

  // returns the NLS name of the type
	CATUnicodeString Name () const;

  // returns the 'internal name' of the type
	CATUnicodeString InternalName () const;

  // returns the icon name used to represent the type
  CATUnicodeString IconName ()const;

	CATBoolean AvailableInNew ()const;
	CATBoolean AvailableInInsert () const;
	CATBoolean AvailableInSearch () const;
	CATBoolean AvailableInCAA () const;

  // returns the package of the type
  const UIPackage &GetPackage() const;

  // Indicates if the type is abstract or not
	CATBoolean IsAbstract() const;

  // returns the real type underneath (loads it !)
	CATIType_var AccessType() const;

  // returns the specializations of the current type
	const CATListValUITypeHandler & GetSpecializations () const;

  // returns the types that can be inserted under the current type
	const CATListValUITypeHandler & GetInsertables ();
	const CATListValUITypeHandler & GetInsertables ( const CATUnicodeString &iFilterTypeName );
	//const CATListValUITypeHandler & GetInsertables ( const CATICkeObject_var &iAggregator );
  
  // returns the types that can be inserted(?) under the current type
	const CATListValUITypeHandler & GetNewables ();
	//const CATListValUITypeHandler & GetNewables ( const CATICkeObject_var &iAggregator );

  

  /**
	 * Copy constructor 
	 */
	UITypeHandler (const UITypeHandler&);
  /*
	 * Destructor
	 */
	virtual ~UITypeHandler() ;

  	/**
	 * Operator to compare equality.
	 * @param iInfos Attribute to be compared with.
	 * @return Result of the comparison.
	 */
	boolean           operator==(const UITypeHandler& iInfos ) const;

	/**
	 * Operator to compare difference.
	 * @param iInfos Attribute to be compared with.
	 * @return Result of the comparison.
	 */
	boolean           operator!=(const UITypeHandler& iInfos ) const;

	/**
	 * Operator to affect a value.
	 * @param iInfos Value to valuate with.
	 * @return Handler on the attribute itself
	 */
	UITypeHandler &operator=(const UITypeHandler& iInfos ) ;



private:

  friend class UIDictionary;
  friend class UIPackage;
  friend class UIPackageLetter;
  friend class UITypeHandlerLetter;
  friend class UITypeHandlerLetter_Real;
  friend class UITypeHandlerLetter_Fake;
  
  UITypeHandler ( const UIPackage &iPackage, const CATIType_var &iType );

 	UITypeHandler ( const UIPackage &iPackage, const CATUnicodeString &iTypeName, const CATUnicodeString &iUserName, const CATUnicodeString &iIconName, boolean isFake = CATFalse );

  // Lettre
	UITypeHandlerLetter *_pLetter;

  /** 
   * Constructeur
   */
 	UITypeHandler (UITypeHandlerLetter *ipLetter);
  

}; 

#endif


