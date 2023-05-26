//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef VPMIDicMgr_h
#define VPMIDicMgr_h

#include "VPMIDicInterfaces.h"

#include "CATLib.h"
#include "CATCORBABoolean.h"
#include "CATBaseUnknown.h"
#include "CATLISTPIUnknown.h"

#include "VPMDicPRIMITIVEType.h"
#include "VPMDicPERSISTENT.h"
#include "VPMDicCONTENT.h"
#include "VPMDicTYPE.h"
#include "CATLISTV_VPMIDicPackage_var.h"
#include "CATLISTV_VPMIDicGenericClass_var.h"
#include "CATLISTV_VPMIDicClass_var.h"
#include "CATLISTV_VPMIDicExtension_var.h"
#include "CATLISTV_VPMIDicUniqueKey_var.h"
#include "CATLISTV_VPMIDicElement_var.h"

class CATISAXParser_var;
class CATISAXXMLReader_var;

class VPMIDicPackage;
class VPMIDicGenericClass;
class VPMIDicGenericClass_var;
class VPMIDicClass;
class VPMIDicClass_var;
class VPMIDicExtension;
class VPMIDicExtension_var;
class VPMIDicRelationClass;
class VPMIDicRelationClass_var;
class VPMIDicSimple_var;
class VPMIDicPrimitive;
class VPMIDicElementH;
class VPMIDicElement;
class VPMIDicOutputStream;
class CATDbBinary;

class VPMIDicEnvironment;
class VPMIDicModeler;
class VPMIDicProcedure;
class VPMIDicSemanticRelation;
class VPMIDicDiscipline;
class VPMIDicDiscipline_var;
class VPMIDicFunction;
class VPMIDicClassRule_var;
class VPMIDicSubRelationship;
class VPMIDicPathType_var;
class VPMIDicFunction_var;
class CATIType_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVPMIDicInterfaces const IID IID_VPMIDicMgr;
#else
extern "C" const IID IID_VPMIDicMgr;
#endif

/**
* Interface to manage all dictionary data.
* <b>Role</b>: This interface is implemented on the dictionary manager that you
*  retrieve using the @href GetVPMIDicMgr global function.
*/
class ExportedByVPMIDicInterfaces VPMIDicMgr : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  //--------------------------------------------
  // Finding concepts by their name: will load the package containing the element if necessary
  //--------------------------------------------

  /**
  * Retrieves a Package by its Name. Will have the consequence to load the package in memory
  * @param iName : Package Name
  * @param oPackage : Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPackage(const CATUnicodeString& iName, VPMIDicPackage_var& oPackage) = 0;

  /**
  * Get a Class by its Name
  */
  virtual HRESULT GetClass(const CATUnicodeString& iName, VPMIDicClass_var& oClass, const boolean iLoadPackageIfNeeded = CATFalse) = 0;

  /**
  * Get a RelationClass by its Name
  */
  virtual HRESULT GetRelationClass(const CATUnicodeString & iName, VPMIDicRelationClass_var& oRelationClass, const boolean iLoadPackageIfNeeded = CATFalse) = 0;

  /**
  * Get an Extension by its Name
  */
  virtual HRESULT GetExtension(const CATUnicodeString& iName, VPMIDicExtension_var& oExtension, const boolean iLoadPackageIfNeeded = CATFalse) = 0;

  /**
  * Get an Extension or a class or a relation class by its Name
  */
  virtual HRESULT GetGenericClass(const CATUnicodeString& iName, VPMIDicGenericClass_var& oGenericClass, const boolean iLoadPackageIfNeeded = CATFalse) = 0;

  /**
  * Get a PathType by its Name
  */
  virtual HRESULT GetPathType(const CATUnicodeString & iName, VPMIDicPathType_var & oPathType, const boolean iLoadPackageIfNeeded = CATFalse) = 0;

  /**
  * To get the UniqueKeys defined on a given Class
  */
  virtual HRESULT GetUniqueKeys(const CATUnicodeString & iClassName, CATLISTV_VPMIDicUniqueKey_var & oUniqueKeys, const boolean iLocalOnly = CATFalse) = 0;

  /**
  * To get the UniqueKeys defined on a given Class and on a given Extension
  */
  virtual HRESULT GetUniqueKeys(const CATUnicodeString & iClassName, const CATUnicodeString & iExtensionName, CATLISTV_VPMIDicUniqueKey_var & oUniqueKeys, const boolean iLocalOnly = CATFalse) = 0;

  /**
  * Get a Function by its Name
  */
  virtual HRESULT GetFunction(const CATUnicodeString & iName, VPMIDicFunction_var & oFunction) = 0;

  /**
  * Return the procedure with the specified name
  * @param iProcedureName : the name of the Procedure
  * @param oppProcedure : the returned Procedure [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetProcedure(const CATString &iProcedureName, VPMIDicProcedure ** oppProcedure) = 0;

  /**
  * Get a global attribute by its name
  */
  virtual HRESULT GetGlobalSimple(const CATUnicodeString & iName, VPMIDicSimple_var & oSimple) = 0;

  /**
  * Retrieves the ClassRule according to its name.
  * NB: a ClassRule's name must be equal to the metadata name of the Class.
  * @param iName : the name of the ClassRule
  * @param oDicClassRule : the ClassRule
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetClassRule(const CATString & iName, VPMIDicClassRule_var & oDicClassRule) = 0;

  /**
  * Get an enum knowledge by its Name
  */
  virtual HRESULT GetEnumType(const CATUnicodeString& iName, CATIType_var & oEnumType) = 0;


  /**
  * To get the list of Elements (Class/RelationClass) which are involved by a given RelationClass and/or a given SubClause.
  * If the given RelationClass name is blank or set to "*", then all RelationClasses are taken into account
  * If the given SubClause name is blank or set to "*", then all SubClauses of the selected RelationClass(es) are taken into account
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded: at least one Element was found</li>
  *    <li>S_FALSE  Operation succeeded: however, no Element was found</li>
  *    <li>E_FAIL   Operation failed: an error has occured</li>
  *    </ul>
  */
  virtual HRESULT GetTargetListByRelationClassSubClause(const CATUnicodeString & iRelationClassName, const CATUnicodeString & iSubClauseName, CATLISTV_VPMIDicElement_var & oDicElementList, const VPMDicTYPE iFilter = (VPMDicTYPE)0) = 0;


  /**
  * Retrieves the Modeler interface according to its name.
  * @param iModelerName : Name of the Modeler
  * @param oDicModeler : the Modeler [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a Modeler was actually found.</li>
  *    <li>E_FAIL   Operation failed, no Modeler was found.</li>
  *    </ul>
  */
  virtual HRESULT GetModeler(const CATUnicodeString & iModelerName, VPMIDicModeler ** oDicModeler) const = 0;



  //--------------------------------------------
  // Introspecting dictionary relying on the index (without loading the packages)
  //--------------------------------------------

  /**
  * Index capability: get the names of all Packages listed in the Index
  */
  virtual HRESULT GetPackageNamesFromIndex(CATListOfCATUnicodeString & oPackageNames) = 0;

  /**
  * Index capability: get the names of Packages listed in the Index that contain at least one "newable" Type
  */
  virtual HRESULT GetNewablePackageNamesFromIndex(CATListOfCATUnicodeString & oPackageNames) = 0;

  /**
  * Index capability: get the name of the Package in which a given Type (i.e. Class/RelationClass/Extension) is defined
  */
  virtual HRESULT GetPackageNameFromIndex(const CATUnicodeString & iTypeName, CATUnicodeString & oPackageName) = 0;

  /**
  * Index capability: get the names of newable Types for a given Package
  */
  virtual HRESULT GetNewableTypeNamesFromIndex(const CATUnicodeString & iPackageName, CATListOfCATUnicodeString & oTypeNames, CATListOfCATUnicodeString & oNlsTypeNames, CATListOfCATUnicodeString & oIconNames) = 0;

  /**
  * Index capability: get the names of searchable Types for a given Package
  */
  virtual HRESULT GetSearchableTypeNamesFromIndex(const CATUnicodeString & iPackageName, CATListOfCATUnicodeString & oTypeNames, CATListOfCATUnicodeString & oNlsTypeNames, CATListOfCATUnicodeString & oIconNames) = 0;

  /**
  * Index capability: get the names of subTypes for a given Type
  */
  virtual HRESULT GetSubTypeNamesFromIndex(const CATUnicodeString & iTypeName, CATListOfCATUnicodeString & oTypeNames) = 0;

  /**
  * Index capability: get the names of 'specialization' Types for a given 'modeler' Type
  */
  virtual HRESULT GetSpecializationTypeNamesFromIndex(const CATUnicodeString & iTypeName, CATListOfCATUnicodeString & oTypeNames) = 0;  //--- TRANSITOIRE --- 
  virtual HRESULT GetSpecializationSubTypeNamesFromIndex(const CATUnicodeString & iTypeName, CATListOfCATUnicodeString & oTypeNames, CATListOfCATUnicodeString & oNlsTypeNames, CATListOfCATUnicodeString & oIconNames) = 0;

  /**
  * Index capability: for a given Type, get the names of Types that can be presented to the PLMInsert
  */
  virtual HRESULT GetInsertableSubTypeNamesFromIndex(const CATUnicodeString & iTypeName, CATListOfCATUnicodeString & oTypeNames, CATListOfCATUnicodeString & oNlsTypeNames, CATListOfCATUnicodeString & oIconNames) = 0;
  virtual HRESULT GetInsertableSubTypeNamesFromIndex(const CATUnicodeString & iTypeName, const CATUnicodeString & iFilterTypeName, CATListOfCATUnicodeString & oTypeNames, CATListOfCATUnicodeString & oNlsTypeNames, CATListOfCATUnicodeString & oIconNames) = 0;

  /**
  * Index capability: for a given Type, get the names of Types that can be presented to the PLMNew
  */
  virtual HRESULT GetNewableSubTypeNamesFromIndex(const CATUnicodeString & iTypeName, CATListOfCATUnicodeString & oTypeNames, CATListOfCATUnicodeString & oNlsTypeNames, CATListOfCATUnicodeString & oIconNames) = 0;


  /**
  * Index capability: get the kweAbstractStatus of a given Type
  */
  virtual HRESULT GetKweAbstractStatusFromIndex(const CATUnicodeString & iTypeName, boolean & oAbstract) = 0;

  /**
  * Index capability: get all the UI characteristics for a given Type from the Index
  */
  virtual HRESULT GetUIDataFromIndex(const CATUnicodeString & iTypeName
    , boolean & oIsAvailableNew
    , boolean & oIsAvailableInsert
    , boolean & oIsAvailableCAA
    , boolean & oIsAvailableOffLine
    , boolean & oIsSearchable
    , boolean & oIsKweAbstract
    //, kweNature ?
  ) = 0;



  /**
  * Retrieves the Modelers names list.
  * @param oModelerNameList : the Modelers names list
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the list contains at least one element.</li>
  *    <li>E_FAIL   Operation failed, the list is empty.</li>
  *    </ul>
  */
  virtual HRESULT GetModelerNames(CATListOfCATUnicodeString &oModelerNameList) const = 0;


  /**
  * Gets the list of Package names that the dictionary might be able to load.
  * @param iExtension
  *     The extension(s) to filter, where:
  *     <ul>
  *     <li>"" or "*" means "all known extensions"</li>
  *     <li>several extensions must be separated by a blank character</li>
  *     </ul>
  * @param oPackageNameList
  *     The list of Package names, including their extension
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetAvailablePackageNames(const CATUnicodeString & iExtension, CATListOfCATUnicodeString & oPackageNameList) = 0;

  /**
  * Retrieves the names of the Extensions that are usable on a given Type/Class.
  * @param iTypeName : Type/Class name
  * @param oUsableExtensionNameList : List of Extension names
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetUsableExtensionNamesForType(const CATUnicodeString & iTypeName, CATListOfCATUnicodeString &oUsableExtensionNameList) = 0;

  /**
  * Check whether the Dictionary is in NewTyping mode.
  */
  virtual boolean IsNewTypingActive() const = 0;

  /**
  * Retrieves the timestamp of the last modification that occured in the PLMDictionary.
  * @return unsigned int: the last modification timestamp
  */
  virtual unsigned int GetLastModTimestamp() const = 0;

  /**
  * Gets the "hierarchical" tree for a given element, either a Class or a RelationClass.
  * Watch out: never invoke this method on core types ! (it would load all the dictionary)
  * @param iDicType:     the Type of the element(VPMDicCLASS, VPMDicRELATIONCLASS, ...)
  * @param iElementName: the Name of the element, presumably the root element of the resulting tree
  * @param oLevelList:
  * @param oElementList:
  * @param iMaxDepth:
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded: </li>
  *    <li>S_FALSE  Operation succeeded: </li>
  *    <li>E_FAIL   Operation failed: an error has occured</li>
  *    </ul>
  */
  virtual HRESULT GetTree(const VPMDicTYPE iDicType, const CATUnicodeString & iElementName, CATListOfInt & oLevelList, CATLISTP(IUnknown) * oElementList, int MaxDepth = -1, const boolean iExtensionOnly = CATFalse) = 0;




  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // FIXME: Internal methods to be removed from the interface
  // ---------------------------------------------------------------------
  /**
  * Loads a given Admin file, and possibly loads the related Packages.
  * The Admin file will be searched in the directories listed in the CATDictionaryPath environment variable.
  * @param iAdminName : the Admin file name
  * @param iLoadPackages : load(or don't load) the related Packages(optional argument, default is CATTrue)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadAdmin(const CATString & iAdminName, boolean iLoadPackages = CATTrue, bool checkConstraints = false) = 0;


  /**
  * Loads a given Admin file from a given directory, and possibly loads the related Packages.
  * @param iAdminName : the Admin file name
  * @param iDirName : the directory into which the Admin file is to be searched
  * @param iLoadPackages : load(or don't load) the related Packages(optional argument, default is CATTrue)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadAdminFromDir(const CATString & iAdminName, const CATString & iDirName, boolean iLoadPackages = CATTrue, boolean iFailOnError = CATTrue) = 0;

  /**
  * Get the metadata file path for a given Package at a given code level.
  * @param iPackageName      : Package name
  * @param iExtension        : File extension; default is "metadata"
  * @param iCodeLevel        : Code Level; default is the code level used for Dictionary initialization(cf GetVPMIDicMgr)
  * @param oMetadataFilePath : Complete metadata file path where the requested Package is defined
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a file was found.</li>
  *    <li>E_FAIL   Operation failed, no file was found.</li>
  *    </ul>
  */
  virtual HRESULT GetMetadataFilePath(const CATUnicodeString & iPackageName, const CATUnicodeString & iExtension, const CATUnicodeString & iCodeLevel, CATUnicodeString & oMetadataFilePath) const = 0;

  /**
  * Get a handle on a Parser in order to load the metadata into the Dictionary from a stream.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed, error.</li>
  *    </ul>
  */
  virtual HRESULT GetStreamParser(CATISAXXMLReader_var & oStreamLoader) const = 0;

  /**
  * Retrieves the names of all loaded Packages.
  * @param oPackageNameList : Packages names list
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetLoadedPackageNames(CATListOfCATUnicodeString & oPackageNameList) = 0;
  /**
  * Saves the Admin data loaded in memory in a file according to an XML format.
  * @param iAdminFilePath : the full path name oof the Admin file to be written
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SaveAdminAsXMLFile(const CATUnicodeString & iAdminFilePath) const = 0;


  /**
  * Get a handle on a Parser in order to load the Admin into the Dictionary from a stream.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed, error.</li>
  *    </ul>
  */
  virtual HRESULT GetAdminStreamParser(CATISAXXMLReader_var & oStreamLoader) = 0;


  /**
  * Check whether Admin data is loaded into the Dictionary.
  * @return
  *    <ul>
  *    <li>CATTrue  Admin data is loaded into the Dictionary.</li>
  *    <li>CATFalse Admin data is not loaded into the Dictionary, error.</li>
  *    </ul>
  */
  virtual boolean IsAdminLoaded() const = 0;




  /**
  * Loads a given Admin file from a stream, and possibly loads the related Packages.
  * @param iAdminStream : the Admin stream
  * @param iLoadPackages : load(or don't load) the related Packages(optional argument, default is CATTrue)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadAdminFromStream(const CATUnicodeString &iAdminStream, boolean iLoadPackages = CATTrue) = 0;


  /**
  * Loads a package from a given directory.
  * @param iDirName     : Directory containing the package
  * @param iPackageName : Package name
  * @param iMode        : Persistency Mode(useless: should always be set to VPMDicFILE)
  * @param iWithComment : Set to 1 in order to let the Dictionary also process comment-like elements(Comment, CAAComment, Role, ShortRole)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadPackageFromDir(const CATString * iDirName, const CATString * iPackageName, const VPMDicPERSISTENT iMode = VPMDicFILE, int withComment = 0) = 0;


  /**
  * Loads a package from a given directory.
  * @param iDirName     : Directory containing the package
  * @param iPackageName : Package name
  * @param iMode        : Persistency Mode(useless: should always be set to VPMDicFILE)
  * @param iContent     : Package type of content(either VPMDicMETADATA, VPMDicTUNING,
  *                       VPMDicRBODEF, or VPMDicRBOMAP)
  * @param iWithComment : Set to 1 in order to let the Dictionary also process comment-like elements(Comment, CAAComment, Role, ShortRole)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadPackageFromDir(const CATString * iDirName, const CATString * iPackageName, const VPMDicPERSISTENT iMode, const VPMDicCONTENT iContent, int withComment = 0) = 0;



  /**
  * Loads a package.
  * @param iPackageName : Package name
  * @param iWithComment : Set to 1 in order to let the Dictionary also process comment-like elements(Comment, CAAComment, Role, ShortRole)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadPackage(const CATString * iPackageName, int withComment = 0) = 0;


  /**
  * Loads a package.
  * @param iPackageName : Package name
  * @param iMode        : Persistency Mode(useless: should always be set to VPMDicFILE)
  * @param iWithComment : Set to 1 in order to let the Dictionary also process comment-like elements(Comment, CAAComment, Role, ShortRole)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadPackage(const CATString * iPackageName, const VPMDicPERSISTENT iMode, int withComment = 0) = 0;


  /**
  * Loads a package.
  * @param iPackageName : Package name
  * @param iMode        : Persistency Mode(useless: should always be set to VPMDicFILE)
  * @param iContent     : Package type of content(either VPMDicMETADATA, VPMDicTUNING,
  *                       VPMDicRBODEF, or VPMDicRBOMAP)
  * @param iWithComment : Set to 1 in order to let the Dictionary also process comment-like elements(Comment, CAAComment, Role, ShortRole)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadPackage(const CATString * iPackageName, const VPMDicPERSISTENT iMode, const VPMDicCONTENT iContent, int withComment = 0) = 0;


  // ---------------------------------------------------------------------
  /**
  * Fills a XML file with the contents of a Package.
  * @param iPackageName   The package name
  * @param iDirectory     The directory where the XML file is to be created
  * @param oFileName      The create XML file name(full path)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT BuildXMLFile(const CATUnicodeString & iPackageName, const CATUnicodeString & iDirectory, CATUnicodeString & oFileName) = 0;


  /**
  * Loads the dictionary with packages contained in the stream.
  * @param iStream   The stream contents
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT LoadStream(const CATUnicodeString & iStream) = 0;



  /**
  * Initialize the PLM Dictionary with all the metadata contained in the metadata cache.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded</li>
  *    <li>E_FAIL   Operation failed</li>
  *    </ul>
  */
  virtual HRESULT LoadMetadataStreamFromCache(const CATUnicodeString & iCacheId) = 0;


  /**
  * Initialize the PLM Dictionary with all the environments contained in the admin cache.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded</li>
  *    <li>E_FAIL   Operation failed</li>
  *    </ul>
  */
  virtual HRESULT LoadAdminStreamFromCache(const CATUnicodeString & iCacheId) = 0;


  /**
    * Initialize the PLM Dictionary with the Server Id.
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded</li>
    *    <li>E_FAIL   Operation failed</li>
    *    </ul>
    */
  virtual HRESULT SetServerIdForCache(const CATUnicodeString & iServerId) = 0;


  virtual HRESULT GetModelerNamesFromIndex(CATListOfCATUnicodeString & oModelerNames) = 0;

  virtual HRESULT LoadPackageFromCache(const CATUnicodeString & iPackageName) = 0;
  virtual HRESULT LoadModelerFromCache(const CATUnicodeString & iModelerName) = 0;
  virtual HRESULT LoadPackageFromRunTimeView(const CATUnicodeString & iPackageName) = 0; //-- pour essayer de rendre obsolète le LoadPackage "tout court"
  virtual HRESULT LoadPackageFromDirectory(const CATUnicodeString & iPackageName, const CATUnicodeString & iDirectory) = 0; //-- pour essayer de rendre obsolète le LoadPackageFromDir "tout court"

  //-- [chd:30.01.2018] Pour recharger un Kwe Dico qui s'est retrouvé vidé (scénario déconnexion/reconnexion ?) 
  virtual HRESULT ReloadKweDictionary() = 0;

  /**
  * Saves the Package in a file, using an XML format.
  * @param iDirName  : Directory path
  * @param iPackName : Package Name
  * @param iMode     : Persistency Mode(useless: should always be set to VPMDicFILE)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SavePackageToDir(const CATString *iDirName, const CATString *iPackName, const VPMDicPERSISTENT iMode = VPMDicFILE) = 0;


  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  /**
  * Removes a Package from memory.
  * <b>Warning:</b> the Dictionary global consistency may become jeopardized,
  * because unresolved inter-package references may appear as the result of this operation.
  * @param iName : Package Name
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemovePackage(const CATString * iName) = 0;

  /**
  * Removes an Environment by its name.
  * @param iEnvironment : Name of the Environment
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the Environment has been removed.</li>
  *    <li>E_FAIL   Operation failed, the Environment was not found or could not be removed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveEnvironment(const CATUnicodeString & iEnvironmentName) = 0;

  /**
  * Creates a new Environment.
  * @param iEnvironment : Name of the Environment
  * @param oDicEnvironment : the Environement [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the Environment has been created.</li>
  *    <li>E_FAIL   Operation failed, the Environment already exists, or could not be created.</li>
  *    </ul>
  */
  virtual HRESULT CreateEnvironment(const CATUnicodeString & iEnvironmentName, VPMIDicEnvironment ** oDicEnvironment) = 0;

  /**
  * Retrieves a Primitive by its Type.
  * @param iPrimitiveType : Package Name
  * @param oPrimitive : Primitive [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPrimitive(const VPMDicPRIMITIVEType iPrimitiveType, VPMIDicPrimitive ** oPrimitive) = 0;



  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Obsolete methods corresponding to former typing: if you use them, you won't be Unified Typing compatible
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  /**
  * Retrieves the Class interface which derives from a given PLM CoreType either in a given Package, or for a given Modeler.
  * The Package given here is supposed to be a "Custo" Package, i.e. a Package defining Class(es) deriving from the six PLM CoreType(PLMConnection, PLMCoreInstance, PLMCoreRepInstance, PLMCoreReference, PLMCoreRepReference, PLMPort).
  * <br>Usage convention:
  * <ul>
  * <li> if the "Custo Package" name argument is given, then the Modeler name argument is ignored(could as well be set to ""!)
  * <li> if the "Custo Package" name argument is not given, i.e. set to "", then the Modeler name argument is taken into account to proceed to the search
  * </ul>
  * NB: this method prototype inherits from the previous service provided by the deprecated CATPLMAdmin component, basically for easier migration purpose. However, since the iModelerName and iPackageName arguments are exclusive one to each other, two different methods would have made the usage of this API much simpler !
  * @param iModelerName : Name of the Modeler Package in which the "Custo Class" of the "Modeler Class" is to be searched
  * @param iPackageName : Name of the Package in which the "Custo Class" of the PLM CoreType is to be searched
  * @param iPLMCoreTypeName : Name of the PLM CoreType
  * @param oDicClass : the Class [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a Class was actually found.</li>
  *    <li>E_FAIL   Operation failed, no Class was found.</li>
  *    </ul>
  */
  virtual HRESULT GetClassFromTypeId(const CATUnicodeString & iModelerName, const CATUnicodeString & iPackageName, const CATUnicodeString & iPLMCoreTypeName, VPMIDicClass ** oDicClass) = 0;

  /**
  * Retrieves the RelationClass interface which derives from a given PLM CoreType either in a given Package, or for a given Modeler.
  * The Package given here is supposed to be a "Custo" Package, i.e. a Package defining Class(es) deriving from the six PLM CoreType(PLMConnection, PLMCoreInstance, PLMCoreRepInstance, PLMCoreReference, PLMCoreRepReference, PLMPort).
  * <br>Usage convention:
  * <ul>
  * <li> if the "Custo Package" name argument is given, then the Modeler name argument is ignored(could as well be set to ""!)
  * <li> if the "Custo Package" name argument is not given, i.e. set to "", then the Modeler name argument is taken into account to proceed to the search
  * </ul>
  * NB: this method prototype inherits from the previous service provided by the deprecated CATPLMAdmin component, basically for easier migration purpose. However, since the iModelerName and iPackageName arguments are exclusive one to each other, two different methods would have made the usage of this API much simpler !
  * @param iModelerName : Name of the Modeler Package in which the "Custo Class" of the "Modeler Class" is to be searched
  * @param iPackageName : Name of the Package in which the "Custo Class" of the PLM CoreType is to be searched
  * @param iPLMCoreTypeName : Name of the PLM CoreType
  * @param oDicClass : the Class [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a Class was actually found.</li>
  *    <li>E_FAIL   Operation failed, no Class was found.</li>
  *    </ul>
  */
  virtual HRESULT GetRelationClassFromTypeId(const CATUnicodeString & iModelerName, const CATUnicodeString & iPackageName, const CATUnicodeString & iPLMCoreTypeName, VPMIDicRelationClass ** oDicRelationClass) = 0;

  /**
  * Retrieves the Extension interface which derives from a given PLM CoreType either in a given Package, or for a given Modeler.
  * The Package given here is supposed to be a "Custo" Package, i.e. a Package defining Class(es) deriving from the six PLM CoreType(PLMConnection, PLMCoreInstance, PLMCoreRepInstance, PLMCoreReference, PLMCoreRepReference, PLMPort).
  * <br>Usage convention:
  * <ul>
  * <li> if the "Custo Package" name argument is given, then the Modeler name argument is ignored(could as well be set to ""!)
  * <li> if the "Custo Package" name argument is not given, i.e. set to "", then the Modeler name argument is taken into account to proceed to the search
  * </ul>
  * NB: this method prototype inherits from the previous service provided by the deprecated CATPLMAdmin component, basically for easier migration purpose. However, since the iModelerName and iPackageName arguments are exclusive one to each other, two different methods would have made the usage of this API much simpler !
  * @param iModelerName : Name of the Modeler Package in which the "Custo Class" of the "Modeler Class" is to be searched
  * @param iPackageName : Name of the Package in which the "Custo Class" of the PLM CoreType is to be searched
  * @param iPLMCoreTypeName : Name of the PLM CoreType
  * @param oDicClass : the Class [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a Class was actually found.</li>
  *    <li>E_FAIL   Operation failed, no Class was found.</li>
  *    </ul>
  */
  virtual HRESULT GetExtensionFromTypeId(const CATUnicodeString & iModelerName, const CATUnicodeString & iPackageName, const CATUnicodeString & iPLMCoreTypeName, VPMIDicExtension ** oDicExtension) = 0;


  /**
  * Retrieves the Environments names list.
  * @param oEnvironmentNameList : the Environments names list
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the list contains at least one element.</li>
  *    <li>E_FAIL   Operation failed, the list is empty.</li>
  *    </ul>
  */
  virtual HRESULT GetEnvironmentNames(CATListOfCATUnicodeString &oEnvironmentNameList) const = 0;


  /**
  * Retrieves the Environment interface according to its name.
  * @param iEnvironment : Name of the Environment
  * @param oDicEnvironment : the Environment [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a Environment was actually found.</li>
  *    <li>E_FAIL   Operation failed, no Environment was found.</li>
  *    </ul>
  */
  virtual HRESULT GetEnvironment(const CATUnicodeString & iEnvironmentName, VPMIDicEnvironment ** oDicEnvironment) const = 0;
  /**
  * Gets the list of Classes/Extensions that hold the "DatabaseName" Property for a given name
  * @param iDatabaseName: the M1 database Name
  * @param oClassList:    the list of Classes/Extensions
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded: the list is not empty </li>
  *    <li>S_FALSE  Operation succeeded: this list is empty</li>
  *    <li>E_FAIL   Operation failed: an error has occured</li>
  *    </ul>
  */
  virtual HRESULT GetClassListByDatabaseName(const CATUnicodeString& iDatabaseName, CATLISTP(IUnknown)* oClassList) = 0;

  /**
  * Gets the list of RelationClasses that hold the "DatabaseName" Property for a given name
  * @param iDatabaseName: the M1 database Name
  * @param oClassList:    the list of RelationClasses
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded: the list is not empty </li>
  *    <li>S_FALSE  Operation succeeded: this list is empty</li>
  *    <li>E_FAIL   Operation failed: an error has occured</li>
  *    </ul>
  */
  virtual HRESULT GetRelationClassListByDatabaseName(const CATUnicodeString& iDatabaseName, CATLISTP(IUnknown)* oRelationClassList) = 0;

  /**
  * Remove all Mask-related objects from all Packages.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveMasks() = 0;


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetDiscipline is obsolete.")

#else
  /**
  * Retrieves the Discipline according to its name.
  * @param iDisciplineName : the name of the Discipline
  * @param oppDiscipline : the Discipline [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded and Discipline found</li>
  *    <li>S_FALSE  Operation succeeded but Discipline not found</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetDiscipline(const CATString& iDisciplineName, VPMIDicDiscipline** oppDiscipline) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetDiscipline is obsolete.")

#else
  /**
  * Retrieves the Discipline according to its name.
  * @param iName : the name of the Discipline
  * @param oDiscipline : the Discipline
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded and Discipline found</li>
  *    <li>S_FALSE  Operation succeeded but Discipline not found</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetDiscipline(const CATUnicodeString iName, VPMIDicDiscipline_var& oDiscipline) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::IsApplicationServiceAvailable is obsolete.")

#else
  /**
  * Specify if the Application Service with the name “iApplicationServiceName” has been declared in a Metadata file.
  * @param iApplicationServiceName : name of the application Service
  * @return
  *    <ul>
  *    <li>S_OK  when application service is available.</li>
  *    <li>S_FALSE  when application service is not available because it has not been declared in a metadata</li>
  *    <li>E_FAIL  when error occurred.</li>
  *    <li>E_NOTIMPL when application service is not available because it has been manually deactivated.</li>
  *    </ul>
  */
  virtual HRESULT IsApplicationServiceAvailable(const char* iApplicationServiceName) = 0;
#endif

  //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------
#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetPackage is to be replaced by equivalent method that is not obsolete.")

#else
/**
  * Retrieves a Package by its Name.
  * @param iName : Package Name
  * @param oPackage : Package [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPackage(const CATUnicodeString& iName, VPMIDicPackage*& oPackage) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetPackage is to be replaced by equivalent method that is not obsolete.")

#else
  /**
  * Retrieves a Package by its Name.
  * @param iName : Package Name
  * @param oPackage : Package [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPackage(const CATString * iName, VPMIDicPackage ** oPackage) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetPackage is to be replaced by equivalent method that is not obsolete.")

#else

  /**
  * Creates a Package, giving Name, Uuid and Domain.
  * @param iName : Package Name
  * @param iUuid : Package Uuid
  * @param iDomain : Package Domain(either ENOVIA or CATIA)
  * @param oPackage : Package [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreatePackage(const CATString * iName, const CATDbBinary * iUuid, const CATString * iDomain, VPMIDicPackage ** oPackage) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetClass is to be replaced by equivalent method that is not obsolete.")

#else
  /**
  * Get a Class by its Name
  */
  virtual HRESULT GetClass(const CATUnicodeString& iName, VPMIDicClass ** oClass) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetRelationClass is to be replaced by equivalent method that is not obsolete.")

#else
  /**
  * Get a RelationClass by its Name
  */
  virtual HRESULT GetRelationClass(const CATUnicodeString & iName, VPMIDicRelationClass ** oClass) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::SearchByName is to be replaced by equivalent methods Get*** that is not obsolete.")

#else
  /**
  * @deprecated
  * Search an element by its Name(obsolete: please use the other form of SearchByName).
  * @param iName          : Name to search
  * @param ioElements  : List of elements carrying that Name(each of these elements must be released)
  * @return
  *    <ul>
  *    <li>S_OK     At least an element was found.</li>
  *    <li>E_FAIL   No element was found.</li>
  *    </ul>
  */
  virtual HRESULT SearchByName(const CATString *iName, CATLISTP(IUnknown) * ioElements) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::Search is to be replaced by equivalent methods Get*** that is not obsolete.")

#else
  /**
  * Search an element by its Uuid.
  * Attention: you get a VPMIDicElementH as a result, not a VPMIDicElement.
  * @param iUuid
  * @param oEltH    [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     One element was found.</li>
  *    <li>E_FAIL   No element was found.</li>
  *    </ul>
  */
  virtual HRESULT Search(const CATDbBinary *iUuid, VPMIDicElementH **oEltH) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::SearchByName is to be replaced by equivalent methods Get*** that is not obsolete.")

#else
  /**
  * Search an element by its Name, possibly filtering by a given @href VPMDicTYPE.
  * @param iDicType    : Type to filter candidate elements
  * @param iName       : Name to search
  * @param ioElements  : List of elements carrying that Name(each of these elements must be released)
  * @return
  *    <ul>
  *    <li>S_OK     At least an element was found.</li>
  *    <li>E_FAIL   No element was found.</li>
  *    </ul>
  * Remarks:
  * <ul>
  * <li>The list of possible values for iDicType is: VPMDicCLASS, VPMDicEXTENSION, VPMIDicINTERFACE, VPMDicENUM, VPMDicRBOCLASS , VPMDicRBOMAPPING, VPMDicMASK and VPMDicATTRIBUTEMASK.</li>
  * <li>Whenever iDicType is set to(VPMDicTYPE)0, then candidate elements are not filtered.</li>
  * </ul>
  */
  virtual HRESULT SearchByName(const VPMDicTYPE iDicType, const CATString *iName, CATLISTP(IUnknown) * ioElements) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::SearchByName is to be replaced by equivalent methods Get*** that is not obsolete.")

#else
  /**
  * Get a Class by its name.
  *(Obsolete, same as GetClass).
  */
  virtual HRESULT SearchClassByName(const CATUnicodeString & iName, VPMIDicClass ** oClass) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetPathType is to be replaced by equivalent method  that is not obsolete.")

#else
  /**
* @deprecated
*/
  virtual HRESULT GetPathType(const CATUnicodeString& iName, VPMIDicSubRelationship ** oPathType) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetFunction is to be replaced by equivalent method  that is not obsolete.")

#else
  /**
  * Return the function with the specified name
  * @param oFunction
  */
  virtual HRESULT GetFunction(const CATUnicodeString& iName, VPMIDicFunction*& oFunction) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetSemanticRelation is to be replaced by VPMIDicPackage::GetPathType.")

#else
  /**
* Retrieves the SemanticRelation according to its name.
* NB: a SemanticRelation's name must be equal to one of the PLMRole role.
* @param iName : the name of the SemanticRelation
* @param oDicSemanticRelation : the SemanticRelation [out, CATBaseUnknown#Release]
* @return
*    <ul>
*    <li>S_OK     Operation succeeded.</li>
*    <li>E_FAIL   Operation failed.</li>
*    </ul>
*/
  virtual HRESULT GetSemanticRelation(const CATString & iName, VPMIDicSemanticRelation ** oDicSemanticRelation) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetPackages is to be replaced by the equivalent method that is not obsolete.")

#else
  /**
  * Retrieves all the loaded Packages.
  * @param ioPackages : Package List
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPackages(CATLISTP(IUnknown) * ioPackages, boolean iNoResources = CATFalse) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  //#pragma message ("WARNING "  " VPMIDicPackage::GetPackages is to be replaced by VPMIDicPackage::GetPackageNamesFromIndex")

#else
  /**
  * Retrieves all the loaded Packages.
  * @param oPackages : Package List
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPackages(CATLISTV_VPMIDicPackage_var& oPackages) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  //#pragma message ("WARNING "  " VPMIDicPackage::GetPackages is to be replaced by VPMIDicPackage::GetPackageNamesFromIndex")

#else
  /**
* @deprecated
* Consider using LoadPackageFromRunTimeView method if your intent is to load a Package from a metadata file available in one of the RunTimeView directories.
*/
  virtual HRESULT LoadPackage(const CATUnicodeString& iName) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  //#pragma message ("WARNING "  " VPMIDicPackage::GetPackages is to be replaced by VPMIDicPackage::GetPackageNamesFromIndex")

#else

  /**
  * @deprecated
  */
  virtual HRESULT LoadPackage(const CATUnicodeString& iName, VPMIDicPackage*& oPackage) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " VPMIDicPackage::GetOrphanExtensions is is obsolete (not compatible with incremental loading)")

#else
  /**
   * @deprecated
   * (use the other form of GetOrphanExtensions, with CATLISTV_VPMIDicExtension_var argument)
   * Get all the Extensions which extend nothing explicitely
   * nb: yep, I know, I could have introduced CATLISTV_VPMIDicExtension_var as output argument...
   */
  virtual HRESULT GetOrphanExtensions(CATLISTP(IUnknown)* oDicExtensionList) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  //#pragma message ("WARNING "  " VPMIDicPackage::GetOrphanExtensions is obsolete (not compatible with incremental loading)")

#else

  /**
  * Get the list of Extensions which extend nothing explicitely.
  * @param oExtensions
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetOrphanExtensions(CATLISTV_VPMIDicExtension_var & oExtensions) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  //  #pragma message ("WARNING "  " VPMIDicPackage::GetClassListByRelationClassSubClause must be replaced by equivalent non obsolete method")

#else
  /**
  * @deprecated
  * (use the other form of GetClassListByRelationClassSubClause, with CATLISTV_VPMIDicClass_var argument)
  */
  virtual HRESULT GetClassListByRelationClassSubClause(const CATUnicodeString & iRelationClassName, const CATUnicodeString & iSubClauseName, CATLISTP(IUnknown) * oDicClassList) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  //  #pragma message ("WARNING "  " VPMIDicPackage::GetClassListByRelationClassSubClause must be replaced by equivalent non obsolete method")

#else
  /**
  * @deprecated
  * (use GetTargetListByRelationClassSubClause, with CATLISTV_VPMIDicElement_var argument)
  */
  virtual HRESULT GetClassListByRelationClassSubClause(const CATUnicodeString & iRelationClassName, const CATUnicodeString & iSubClauseName, CATLISTV_VPMIDicClass_var & oDicClassList) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  //  #pragma message ("WARNING "  " VPMIDicPackage::GetGlobalFunctions is not compatible with incremental loading")

#else
  /**
  * Get the list of all global Functions.
  * Reminder: as of January'06, a global Function is actually any Service of any Interface declared in the GlobalFunctions.metadata file
  * @param oFunctions  : List of all global Functions
  * @return
  *    <ul>
T  *    <li>S_OK     Operation succeeded, global Functions were found.</li>
  *    <li>S_FALSE  Operation succeeded, but no global Function was found.</li>
  *    <li>E_FAIL   Operation failed, error.</li>
  *    </ul>
  */
  virtual HRESULT GetGlobalFunctions(CATLISTP(IUnknown) * oFunctions) = 0;
#endif




#if defined(REMOVE_USELESS_CALLS)

  // #pragma message ("WARNING "  " VPMIDicPackage::GetElementByURL is obsolete. Use Get** methods instead")

#else

  /**
  * Get an element by its URL.
  * If needed, the appropriate Package is loaded in memory.
  * @param iURL
  * @param oElement    [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     The element was found.</li>
  *    <li>E_FAIL   No element was found.</li>
  *    </ul>
  */
  virtual HRESULT GetElementByURL(const CATDbBinary& iURL, VPMIDicElement** oElement) = 0;
#endif


  /**
  * Get the ModelerName for a given PackageName
  * If the metadata Index is available, the request is performed on the metadata Index.
  * If the metadata Index is not available, the request is forwarded to the Package if it is loaded.
  * @param iPackageName
  * @param oModelerName
    * @return
  *    <ul>
  *    <li>S_OK     PackageName is valid, and a ModelerName was found.</li>
  *    <li>S_FALSE  PackageName is valid, but no ModelerName was found.</li>
  *    <li>E_FAIL   PackageName is NOT valid.</li>
  *    </ul>
  */
  virtual HRESULT GetModelerName(const CATUnicodeString & iPackageName, CATUnicodeString & oModelerName) = 0;


  /**
  * Retrieves the GenericClass interface which derives from a given PLM CoreType either in a given Package, or for a given Modeler.
  * The Package given here is supposed to be a "Custo" Package, i.e. a Package defining Class(es) deriving from the six PLM CoreType(PLMConnection, PLMCoreInstance, PLMCoreRepInstance, PLMCoreReference, PLMCoreRepReference, PLMPort).
  * <br>Usage convention:
  * <ul>
  * <li> if the "Custo Package" name argument is given, then the Modeler name argument is ignored(could as well be set to ""!)
  * <li> if the "Custo Package" name argument is not given, i.e. set to "", then the Modeler name argument is taken into account to proceed to the search
  * </ul>
  * NB: this method prototype inherits from the previous service provided by the deprecated CATPLMAdmin component, basically for easier migration purpose. However, since the iModelerName and iPackageName arguments are exclusive one to each other, two different methods would have made the usage of this API much simpler !
  * @param iModelerName : Name of the Modeler Package in which the "Custo Class" of the "Modeler Class" is to be searched
  * @param iPackageName : Name of the Package in which the "Custo Class" of the PLM CoreType is to be searched
  * @param iPLMCoreTypeName : Name of the PLM CoreType
  * @param oDicClass : the Class [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a Class was actually found.</li>
  *    <li>E_FAIL   Operation failed, no Class was found.</li>
  *    </ul>
  */
  virtual HRESULT GetGenericClassFromTypeId(const CATUnicodeString & iModelerName, const CATUnicodeString & iPackageName, const CATUnicodeString & iPLMCoreTypeName, VPMIDicGenericClass ** oDicGenericClass) = 0;
  virtual HRESULT GetGenericClassFromTypeId(const CATUnicodeString & iModelerName, const CATUnicodeString & iPackageName, const CATUnicodeString & iPLMCoreTypeName, VPMIDicGenericClass_var & oDicGenericClass) = 0;
  /* @nodoc */
  virtual HRESULT GetListOfGenericClassFromTypeId(const CATUnicodeString & iModelerName, const CATUnicodeString & iPackageName, const CATUnicodeString & iPLMCoreTypeName, CATLISTV_VPMIDicGenericClass_var & oListOfDicGenericClass) = 0;
};

CATDeclareHandler( VPMIDicMgr, CATBaseUnknown );

/**
* Retrieves an interface to the Dictionary Manager.
* If it is the first call to this method, no implicit Package besides the Dictionary resource Packages is loaded;
* then to complete the Dictionary loading, the LoadPackage need to be called.
* @param oDicMgr : Dictionary manager [out, CATBaseUnknown#Release]
* @return S_OK, E_FAIL
*/
#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "  " GetVPMIDicMgr(VPMIDicMgr**) method is obsolete; preferred method would be GetVPMIDicMgr(VPMIDicMgr_var&)")

#else
ExportedByVPMIDicInterfaces HRESULT GetVPMIDicMgr( VPMIDicMgr** oDicMgr );
#endif 

/**
* Retrieves an interface to the Dictionary Manager.
* If it is the first call to this method, no implicit Package besides the Dictionary resource Packages is loaded;
* then to complete the Dictionary loading, the LoadPackage need to be called.
* @param oDicMgr : Dictionary manager
* @return S_OK, E_FAIL
*/
ExportedByVPMIDicInterfaces HRESULT GetVPMIDicMgr( VPMIDicMgr_var& oDicMgr );

/**
* Retrieves an interface to the Dictionary, loading the Admin data from the provided Admin file, and loading all referred Packages in this given Admin file.
* When providing an Admin file name, this method not only loads the admin data such as Environments, Modelers, and list of Packages involved, but also loads all the necessary Packages.
* Therefore the VPMIDicMgr interface returned by this method is ready to use, i.e. no LoadPackage call should be needed.
* NB : the Admin file will be searched in the directories listed by the CATDictionaryPath environment variable.
* @param iAdminFileName : name of the Admin file to use to initialize the Dictionary Packages loading
* @param oDicMgr : Dictionary manager [out, CATBaseUnknown#Release]
* @return S_OK, E_FAIL
*/
ExportedByVPMIDicInterfaces HRESULT GetVPMIDicMgr( const CATString& iAdminFileName, VPMIDicMgr** oDicMgr );

ExportedByVPMIDicInterfaces HRESULT GetVPMIDicMgr( const CATString& iAdminFileName, VPMIDicMgr** oDicMgr, bool checkConstraints );

/**
* Retrieves an interface to the Dictionary, loading the Admin data from the provided Admin file, and loading all referred Packages in this given Admin file.
* When providing an Admin file name, this method not only loads the admin data such as Environments, Modelers, and list of Packages involved, but also loads all the necessary Packages. The Admin file will be searched in the given directory(or directories).
* Therefore the VPMIDicMgr interface returned by this method is ready to use, i.e. no LoadPackage call should be needed.
* @param iAdminFileName : name of the Admin file to use to initialize the Dictionary Packages loading
* @param iDirectory : the directory(or directories) where the Admin file is to be searched
* @param oDicMgr : Dictionary manager [out, CATBaseUnknown#Release]
* @return S_OK, E_FAIL
*/
ExportedByVPMIDicInterfaces HRESULT GetVPMIDicMgr( const CATString& iAdminFileName, const CATString& iDirectory, VPMIDicMgr** oDicMgr );

/**
* Retrieves an interface to the Dictionary, loading the Admin data from the provided Admin stream, and loading all referred Packages in this given Admin stream.
* When providing an Admin stream, this method not only loads the admin data such as Environments, Modelers, and list of Packages involved, but also loads all the necessary Packages.
* Therefore the VPMIDicMgr interface returned by this method is ready to use, i.e. no LoadPackage call should be needed.
* @param iAdminStream : the Admin stream to initialize the Dictionary Packages loading
* @param oDicMgr : Dictionary manager [out, CATBaseUnknown#Release]
* @return S_OK, E_FAIL
*/
ExportedByVPMIDicInterfaces HRESULT GetVPMIDicMgr( const CATUnicodeString& iAdminStream, VPMIDicMgr** oDicMgr );

/**
* Check whether the Dictionary is in IncrementalLoading mode.
*/
//--  /!\ --  Ne pas enlever le extern "C" car appel par CATGetEntryPoint -- /!\ --
extern "C" ExportedByVPMIDicInterfaces int IsIncrementalLoadingActive();

#endif /*VPMIDicMgr_h*/
