#ifndef UIPackage_h
#define UIPackage_h


#include "PLMDictionaryNavServices.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "UITypeHandler.h"
#include "CATListValUITypeHandler.h"

#include "UIDictionary.h"

class UIPackageLetter;
class CATListValCATIType_var;

//----------------------------------------------------------------------------------------------------------------------------------------
// This class is proposed for UI Components to navigate in PLM types (mainly for search and PLM new)
//----------------------------------------------------------------------------------------------------------------------------------------

class  ExportedByPLMDictionaryNavServices UIPackage
{

public :
  UIPackage (const UIPackage & iUIPackage );
  virtual ~UIPackage() ;
  boolean operator==(const UIPackage & iUIPackage ) const;
  boolean operator!=(const UIPackage & iUIPackage ) const;
  UIPackage &operator=(const UIPackage & iUIPackage );


  // returns the NLS name of the package
  CATUnicodeString Name() const;

  // returns the icon name to represent the package
  CATUnicodeString IconName() const;

  // Is the package available in PLM New
  CATBoolean AvailableInNew () const;

  // Is the package available in PLM Insert
  CATBoolean AvailableInInsert () const;

  // Is the package available in PLM Search
  CATBoolean AvailableInSearch () const;

  // Returns the list of types (not including the specializations done by customers)
  const CATListValUITypeHandler & GetDSTypes() const;

  // returns the Internal name of the package
  CATUnicodeString InternalName() const;

  //-- adds an existing  UITypeHandler in the current Package 
  void AddUITypeHandler ( const UITypeHandler & iUITypeHandler);

  //-- Gets a UITypeHandler from the current Package 
  UITypeHandler * GetUITypeHandler ( const CATUnicodeString & iName ) const;


  // returns the Usage of the Package
  UIDictionary::Usage Usage() const; 
  UIDictionary & GetUIDictionary() const;


private:

  friend class UIDictionary;
  friend class UIPackageLetter;

  /** 
  * Constructeur
  */
  UIPackage (const CATUnicodeString &iPackageName,const UIDictionary::Usage iUsage,CATListValCATIType_var *pliste=NULL);
  UIPackage (const UIPackageLetter *ipLetter);

  // Lettre
  UIPackageLetter * _pLetter;


}; 

#endif


