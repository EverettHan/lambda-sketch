#ifndef UIDictionary_h
#define UIDictionary_h


#include "PLMDictionaryNavServices.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
#include "CATLib.h"

class CATListValUIPackage;
class UIPackage;
class UITypeHandler;


#define my_cerr cerr<<__FUNCTION__<<" ["<<__LINE__<<"] - "

//--------------------------------------------------------------------------------------------------
// This class is proposed for UI Components to navigate in PLM types (mainly for search and PLM new)
//--------------------------------------------------------------------------------------------------

class  ExportedByPLMDictionaryNavServices UIDictionary
{

public :


  // returns a singleton for a given usage (PLM New)
  static const UIDictionary & GetDictionaryForNew ();	

  // returns a singleton for a given usage (Search)
  static const UIDictionary & GetDictionaryForSearch ();	

  // Lists the available packages of the dictionary: presents only the packages containing objects that can be created with the current licenses
  const CATListValUIPackage & Packages() const;

  // Retrieves a Type handler from its name
  // returns NULL if not found
  // Return pointer must be deallocated (deleted)
  UITypeHandler * RetrieveFromInternalName ( const CATUnicodeString &iName ) const; //-- = GetUITypeHandler , ce serait plus clair !... et en plus elle est pas vraiment "const", cette méthode
  UITypeHandler * GetUITypeHandler ( const CATUnicodeString &iName ) const; //-- pour remplacer RetrieveFromInternalName
  
  UIPackage * GetUIPackage ( const CATUnicodeString & iName );

  void Refresh () const; //-- devrait disparaitre au profit de Flush
  void Flush   () const;

  CATUnicodeString getUsage () const { return (_usage==ForNew)?"ForNew":"ForSearch"; } //-- pour debug 

private:

  friend class UIPackage;
  friend class UIPackageLetter;

  enum Usage { ForNew, ForSearch };
  /** 
  * Constructeur
  */
  UIDictionary (const Usage iUsage);

  /**
  * Copy constructor 
  */
  UIDictionary (const UIDictionary&);
  /*
  * Destructor
  */
  virtual ~UIDictionary() ;

  Usage _usage;
  CATListValUIPackage *_plistPackage;

  //void CreateFakePackageAndTypes ( const CATUnicodeString & iPackageName, const CATListOfCATUnicodeString & iTypeNames, const CATListOfCATUnicodeString & iIconNames );
  void CreateFakePackagesAndTypes ();
  void ComputePackages ();
  

  static const UIDictionary _dictionaryForSearch;
  static const UIDictionary _dictionaryForNew;
}; 

#endif


