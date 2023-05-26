
/**
 * @level Private
 * @usage U1
 */
 // COPYRIGHT DASSAULT SYSTEMES  1996
 //=============================================================================
 //
 // CATCkeDictionary: Internal dictionary. Applications are invited to use CATParmDictionary
 //
 // Dictionnary used by CKE : Note that there is a current Dictionnary 
 // that you can find in CATCkeEquationContext: Define CATCKEDictionary
 //
 // Types :
 // -----
 //    - access CKE types of objects (CATUnicodeString, Integer, Real, ...)
 //    - add User types 
 //   
 // Scan : 
 // ----
 //    - capability to scan types  
 //    - direct access to some types 
 //
 // Retrieving types by "name"
 // --------------------------------------
 //    - capability to find a type by its name
 //    Those capabilities are linked to parsing expressions they must be as
 //    quick as possible 
 //
 //=============================================================================
 // Usage Notes:
 //
 //=============================================================================
 //
 // May. 96   Creation                                   F.Riche
 //=============================================================================

#ifndef CATCkeDictionary_H
#define CATCkeDictionary_H   

// BSFBuildtimeData
#include "CATIAV5Level.h"
// KnowledgeInterfaces
#include "CATICkeConstraintForwards.h"
#include "CATICkeForwards.h"
#include "CATICkeMagnitude.h"
#include "CATICkeSignature.h"
#include "CATICkeType.h"
#include "CATITypeDictionary.h"
#include "CATITypeDictionaryListener.h"
// System
#include "CATHashDico.h"
#include "CATListOfCATString.h"
#include "CATLISTV_CATBaseUnknown.h"
// ObjectModelerBase
#include "CATIContainer.h"
// LiteralFeatures
#include "CATCkeContext.h"
#include "CATCkeObjectOrInstance.h"
#include "CATLifDictionary.h"
#include "CATLifDictionaryForwards.h"
#include "CATLISTV_CATICkeType.h"

class CATIDelegateInstanciation_var;

class CATDelayedMsgCmd;

//-----------------------------------------------------------------------------
class ExportedByCATLifDictionary CATCkeDictionary : public CATCkeContext
{
public:

  static CATCkeDictionary & GetDictionary();
  static void Delete();

  //-------------------------------
  // Construction 
  //-------------------------------
  CATCkeDictionary();
  virtual ~CATCkeDictionary();

  static CATBoolean UnitsInitialized();

  // Add a type and add a method
  void AddType(const CATICkeType_var &);

  //-------------------------------
  // Managing fake types and methods
  //-------------------------------

// tracing 
  CATUnicodeString Trace() const;

  CATListValCATBaseUnknown_var * Types() const;
  CATListValCATBaseUnknown_var * Magnitudes() const;
  // liste des types de litteraux
  const CATLISTV(CATICkeType_var) * GetLiteralTypes(int withFeature = 0);

  //Deprecated : use  GetLiteralTypes (int withFeature = 0)    
  CATCkeListOfType                  LiteralTypes(int withFeature = 0);
  //------------------------------------------
  // Retrieving types or shapes by "name"
  //------------------------------------------
  // for search : find type from its name 
  CATICkeType_var   FindType(const CATUnicodeString & iTypeName, const char * iContext = "", int tryLoadingLibs = 1) const;

  // find a magnitude/unit from its symbol
  CATICkeMagnitude_var   FindUnit(const CATUnicodeString &, CATICkeUnit_var &)  const;

  // Initialise le container et le recupere
  virtual void Init(const CATIContainer_var &);
  virtual CATIContainer_var  Container() const;

  // Ask for a specific library load NULL if we want to load all librairies
  //  (true is succeeded)
  CATCke::Boolean LoadLibraryWhithoutInitMethods(const char * libraryName = NULL);
  CATCke::Boolean LoadLibrary(const char * libraryName = NULL);

  // use with care
  void RemoveType(const CATICkeType_var &);

  // evenements liés au dictionnaire
  HRESULT AddDictionaryListener(const CATITypeDictionaryListener_var & iListener);
  HRESULT RemoveDictionaryListener(const CATITypeDictionaryListener_var & iListener);

  HRESULT AdviseInstanciated(const CATIType_var & iType, const CATCkeObjectOrInstance_var & iInstance);
  HRESULT AdviseTypeAdded(const CATIType_var & iType);
  HRESULT AdviseTypeRemoved(const CATIType_var & iType);
  HRESULT AdviseTypeUpdated(const CATIType_var & iType);
  HRESULT AdviseMethodAdded(const CATBaseUnknown_var & iMethod);
  HRESULT AdviseMethodRemoved(const CATBaseUnknown_var & iMethod);

#if !defined(CATIAR201)
  HRESULT GenerateTypesFromDirectory();
#endif

  HRESULT Synchronize();

  //gestion du flag d'initialisation des methodes, pour ne pas le faire 
  //10000 fois.
  int GetInitMethods();
  void SetInitMethods(int val);

  int GetLoadTypesDirectory();
  void SetLoadTypesDirectory(int val);

  void Clear();

  HRESULT FindNLSTypes(const CATUnicodeString & iType, CATListValCATIType_var & oTypes, CATBoolean only_one);

  //--------------------------------------------------
  // Ajout FRH_SPLIT 
  // find a magnitude/unit from its symbol
  CATICkeUnit_var   FindUnit(const CATUnicodeString &)  const;

  // NewInit
  void   InitStaticForLanguage();        // Cette methode initialise les statiques utiles a CATExpressionEngine

  static int GetDynamicLibrairies();
  static void SetDynamicLibrairies(const int dynamicLibrary);

  static CATUnicodeString GetLoadLibrary();
  static void SetLoadLibrary(const CATUnicodeString loadLibrary);

  static CATUnicodeString GetLoadTypesDirectoryPath();
  static void SetLoadTypesDirectoryPath(const CATUnicodeString loadTypesDirectory);

  static CATCke::Boolean GetLoadLibraryTraces();
  static void SetLoadLibraryTraces(const CATCke::Boolean loadLibraryTraces);

  static int GetNbLoadedLibrairies();
  static void AddLoadedLibrary();

  static void CreateConstantFromEnum(const CATICkeType_var &);
  // End Ajout FRH_SPLIT 
  //--------------------------------------------------
  static CATDelayedMsgCmd * GetDelayedMsgCmd();

private:

  //-------------------------------
  // Acces aux types particuliers
  //-------------------------------
  CATCke::Boolean InternalLoadLibrary(const char * libraryName);

  CATCkeDictionary(const CATCkeDictionary &);

  // initialise les statiques 
  void InitStatic();
  void InitStaticForMagnitudes();
  // ajoute un type volatile
  CATICkeType_var AddVolatileType(const CATUnicodeString & name, const CATICkeType_var & type = NULL_var, const CATUnicodeString & username = "");

  // Internal adding type
  HRESULT InternalAddType(const CATICkeType_var &);

  void RemoveAll();

  CATIContainer_var container_;

  CATLISTV(CATBaseUnknown_var)   m_litTypeLst;
  CATLISTV(CATBaseUnknown_var)   m_litTypeWithFeatLst;
  CATLISTV(CATBaseUnknown_var)   m_listeners;

};

#endif
