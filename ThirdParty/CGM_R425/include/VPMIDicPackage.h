//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef VPMIDicPackage_h
#define VPMIDicPackage_h

#include "CATBaseUnknown.h"
#include "CATIAV5Level.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATLISTPIUnknown.h"

#include "VPMIDicInterfaces.h"
#include "VPMDicTYPE.h"
#include "VPMDicCUSTOMEREXPOSITION.h"
#include "VPMDicARCHITECTURE.h"
#include "VPMDicCUSTOMEREXPOSITIONPURPOSE.h"
#include "CATListValCATAttributeInfos.h"

#include "CATLISTV_VPMIDicClass_var.h"
#include "CATLISTV_VPMIDicExtension_var.h"
#include "CATLISTV_VPMIDicGenericClass_var.h"
#include "CATLISTV_VPMIDicRelationClass_var.h"
#include "CATLISTV_VPMIDicPathType_var.h"
#include "CATLISTV_VPMIDicSimple_var.h"

class CATDbBinary;
class VPMIDicApplicationService;
class VPMIDicClass;
class VPMIDicExtension;
class VPMIDicElement;
class VPMIDicEnum;
class VPMIDicDiscipline;
class VPMIDicPrimitive;
class VPMIDicInterface;
class VPMIDicAttributeBlock;
class VPMIDicAttributeMask;
class VPMIDicMask;
class VPMIDicComment;
class VPMIDicCAAComment;
class VPMIDicSemanticRelation;
class VPMIDicClassRule_var;
class VPMIDicFunction;
class VPMIDicUniqueKey_var;
class VPMIDicSubRelationship;
class VPMIDicFunction_var; 
class VPMIDicRelationClass_var;

class CATIType_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicPackage;
#else
extern "C" const IID IID_VPMIDicPackage;
#endif

/**
* VPMIDicPackage describes a Package
* a DicPackage contains a set of object description
*<p>
* Element name must be unique in the package
* <br>
*/
class ExportedByVPMIDicInterfaces VPMIDicPackage : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  //----------------------------------------------------------------------------------------------
  // characteristics of the package itself
  //----------------------------------------------------------------------------------------------
  /**
  * Get the Type of the Package.
  * NB: it should always be "VPMDicPACKAGE"
  * @return the Type of the Package
  */
  virtual VPMDicTYPE Type() = 0;

  /**
  * Get the Name of the Package.
  * @param oName the Name of the Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetName             ( CATString * oName ) = 0;

  /**
  * Retrieve the element's NLSValue.
  * @param oNLSValue : NLSValue
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetNLSValue ( CATUnicodeString & oNLSValue) = 0;

    /**
  * Get the element's NLSTag.
  * @param oNLSTag : NLSTag
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetNLSTag ( CATUnicodeString & oNLSTag) const = 0;


  /* Returns in which architecture of the package it is used
  */
  virtual VPMDicARCHITECTURE GetTargetArchitecture() const = 0;
  


  /**
  * Get the code level (or Version and Release level) of the Package.
  * @param oVRLevel the code level of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetVersionReleaseLevel ( CATUnicodeString * oVRLevel ) = 0;

  /**
  * Get the modeler type defined in the current Package
  * @param oModelerType the modeler type (either Core, Abstract, Top ,Resources or Custo)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetModelerType( CATUnicodeString& oModelerType ) = 0;

  /**
  * Get the value of the ModelerName tag modeler Name defined in the current Package
  * @param oModelerName the modeler name
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetModelerName ( CATUnicodeString& oModelerName ) = 0;

  /**
  * Get the value of the BelongsToModeler tag defined for the current Package
  * @return
  *    <ul>
  *    <li>the value of the BelongsToModeler tag.</li>
  *    </ul>
  */
  virtual CATUnicodeString GetBelongsToModeler ( ) const = 0;
  
  /**
  * FIXME: explain
  */
  virtual HRESULT IsExposedForPurpose ( const VPMDicCUSTOMEREXPOSITIONPURPOSE iPurpose, boolean & oIsExposed  ) const = 0;


  //----------------------------------------------------------------------------------------------
  // package properties
  //----------------------------------------------------------------------------------------------
  /**
  * Retrieves the property value with the given Name
  * @param iPropertyName : the name of the Property
  * @param oPropertyValue : the corresponding value of the Property
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL  The property with the given name could not be found.</li>
  *    </ul>
  */
  virtual HRESULT getPropertyValue ( const CATUnicodeString &iPropertyName, CATUnicodeString & oPropertyValue ) const = 0;


  /**
  * Retrieves the names and the values of all properties assigned to the current Package.
  * @param oNames : the list of Property names
  * @param oValues : the list of corresponding Property values
  * @return
  *    <ul>
  *    <li>S_OK    Operation succeeded.</li>
  *    <li>E_FAIL  No Property could be found.</li>
  *    </ul>
  */
  virtual HRESULT getPropertyNamesAndValues ( CATListOfCATUnicodeString & oNames, CATListOfCATUnicodeString & oValues ) const = 0;


  /**
  * Creates a Property element in the current Package.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT addProperty(const CATUnicodeString & iName, const CATUnicodeString & iValue) = 0;


  /**
  * Get the list of all XML attributes names and values describing the current Package.
  * @param oNameList Package's attributes names list
  * @param oValueList Package's attributes values list
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetAllAttributes ( CATListOfCATUnicodeString & oNameList, CATListOfCATUnicodeString & oValueList ) const = 0;


  //----------------------------------------------------------------------------------------------
  // package prerequisites
  //----------------------------------------------------------------------------------------------

  /**
  * Get the list of Packages used (pre-requested) by the current Package.
  * A Package refers to another Package using the UseNames XML attribute when inheritance between Classes are to be solved.
  * @param oUsedPackageList the list of Packages referred by the UseNames XML attribute of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetUsedPackages     ( CATLISTP(IUnknown) * oUsedPackageList ) = 0;

  /**
  * Get the list of Names of the pre-requested Packages of the current Package.
  * Both list defined by the UseNames and ScopeNames attributes are scanned to build this list
  * @param oPackageNameList Pre-requested Package name list of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPrereqPackageNames ( CATListOfCATUnicodeString & oPackageNameList ) = 0;

  //----------------------------------------------------------------------------------------------
  // accessing elements of the package
  //----------------------------------------------------------------------------------------------

  /**
  * Get a UniqueKey by its Name
  */
  virtual HRESULT GetUniqueKey ( const CATUnicodeString & iName, VPMIDicUniqueKey_var & oUniqueKey ) = 0;

  /**
  * Get a Function by its Name
  */
  virtual HRESULT GetFunction ( const CATUnicodeString & iName, VPMIDicFunction_var & oFunction ) = 0;

  /**
  * Retrieves all the Classes  of the Package.
  * @param oClasses : Classes List
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetClasses ( CATLISTV_VPMIDicClass_var & oClasses ) = 0;
  /**
  * Retrieves all the Extensions of the Package.
  * @param oExtensions : Extensions List
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetExtensions ( CATLISTV_VPMIDicExtension_var & oExtensions ) = 0;

  /**
  * Retrieves all the RelationClasses of the Package.
  * @param oRelationClasses : RelationClasses List
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetRelationClasses ( CATLISTV_VPMIDicRelationClass_var & oRelationClasses ) = 0;

  /**
  * Retrieves all the Generic Classes (Class, RelationClass, Extension) of the Package.
  * @param oGenericClasses : oGenericClasses List
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetGenericClasses ( CATLISTV_VPMIDicGenericClass_var & oGenericClasses ) = 0;

  /**
  * Retrieves all the Path types of the Package.
  * @param oGenericClasses : oPathTypes List
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPathTypes ( CATLISTV_VPMIDicPathType_var & oPathTypes ) = 0;
  
  /**
  * Get the list of Global attributes defined in trhis package.
  * @param oSimples        List of Simple elements of the package (lobal attributes)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetGlobalSimples ( CATLISTV_VPMIDicSimple_var & oSimples ) = 0;

  /**
  * Retrieve the ClassRule element declared in the current Packaging according to its Name.
  * Note that the VPMIDicMgr::SearchByName((const VPMDicTYPE) VPMDicCLASSRULE, .../... ) method can also be used in case the containing Package is not known.
  * @param oDicClassRule : the ClassRule element [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     The element was found.</li>
  *    <li>S_FALSE  No element was found.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetClassRule ( const CATString & iName, VPMIDicClassRule_var & oDicClassRule ) = 0;


  /**
  * Return the Functions of this Package
  * FIXME: explain how it is supposed to be used
  * @param oListOfFunctions List of VPMIDicFunction
  */
  virtual HRESULT getFunctions(CATLISTP(IUnknown) & oListOfFunctions ) = 0;








  //----------------------------------------------------------------------------------------------
  // Masks
  //----------------------------------------------------------------------------------------------

  /**
  * @nodoc: FIXME: explain
  */
  virtual HRESULT GetLoadMaskCompleted ( int * oLoadMaskConpleted ) = 0;


  /**
  * @nodoc: FIXME explain
  */
  virtual HRESULT SetLoadMaskCompleted ( const int * iLoadMaskConpleted ) = 0;


  
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  /**
  * Introduces a new public extension in dictionary cache only (not searchable): service that only catalog application will used 
  * @param iExtensionName
  * name of the extension to add
  * @param iFatherExtensionName
  * extension name from which the extension will inherit: cannot be blank. Must correspond to an extension
  * @param iListFilteredAtt
  * list of public attributes to be added on the extension 
  * @param iCreatedExtensionType
  * Extension type created
  * @return
  *  <ol>
  * 	<li> E_INVALIDARG if the extension name is blank or if the extension father is not defined 
  * 	<li> S_OK	if the creation has succeeded
  *  <li> E_FAIL if one of the attribute already exist or if the extension already exist,
  *  </ol>
  */
  virtual HRESULT CreateCatalogExtension ( const CATUnicodeString &iExtensionName,
                                           const CATUnicodeString &iFatherExtensionName,
                                           const CATListValCATAttributeInfos &iListFilteredAtt,
                                           CATIType_var &iCreatedExtensionType) =0;


  /**
  * Set the Name of the Package.
  * @param iName the Name of the Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetName             ( const CATString *iName ) = 0;
  /**
  * @deprecated
  */
  virtual HRESULT SetModelerName   ( const CATUnicodeString * iModelerName ) = 0;
  /**
  * @nodoc
  */
  virtual HRESULT SetCustomerExposition ( const VPMDicCUSTOMEREXPOSITION iCustomerExposition ) = 0;

    /**
  * @deprecated
  */
  virtual HRESULT SetModelerType   ( const CATUnicodeString * iModelerType ) = 0;


  /**
  * Set the code level (or Version and Release level) of the Package.
  * @param iVRLevel the code level of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetVersionReleaseLevel ( const CATUnicodeString * iVRlevel ) = 0;

  /**
  * Add a Package in the list of Packages used (pre-requested) by the current Package.
  * A Package refers to another Package using the UseNames XML attribute when inheritance between Classes are to be solved.
  * @param iUsedPackage the Package used by the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT AddUsedPackage      ( const VPMIDicPackage * iUsedPackage ) = 0;


  /**
  * @nodoc
  * @param oDicClass [out, CATBaseUnknown#Release]
  * @return S_OK, E_FAIL
  */
  virtual HRESULT CreateClass       ( const CATString * iName, VPMIDicClass ** oDicClass ) = 0;

  /**
  * Create a Class element in the current Package.
  * @param iName Name ot the Class
  * @param iUuid Uuid of the Class
  * @param oDicClass the created Class [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateClass       ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicClass ** oDicClass ) = 0;

  /**
  * @nodoc
  * @param oDicClass [out, CATBaseUnknown#Release]
  * @return S_OK, E_FAIL
  */
  virtual HRESULT CreatePathType       ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicSubRelationship ** oDicPathType ) = 0;

  /**
  * @nodoc
  * @param oDicRelationClass 
  * @return S_OK, E_FAIL
  */
  virtual HRESULT CreateRelationClass       ( const CATString * iName,const CATDbBinary * iUuid, VPMIDicRelationClass_var &oDicRelationClass ) = 0;

  
  /**
  * Create an Application Service element in the current Package.
  * @param iName Name ot the Application Service
  * @param iUuid Uuid of the Application Service
  * @param oDicApplicationService the created Application Service [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateApplicationService(const CATString * iName,const CATDbBinary * iUuid,VPMIDicApplicationService ** oDicApplicationService) = 0;
  
  /**
  * Create an Extension element in the current Package.
  * @param iName Name ot the Extension
  * @param iUuid Uuid of the Extension
  * @param oDicExtension the created Extension [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateExtension   ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicExtension ** oDicExtension ) = 0;


  /**
  * Create an Interface element in the current Package.
  * @param iName Name ot the Interface
  * @param iUuid Uuid of the Interface
  * @param oDicInterface the created Interface [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateInterface   ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicInterface ** oDicInterface ) = 0;


  /**
  * Create a Mask element in the current Package.
  * @param oMask the created Mask [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateMask          ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicMask ** oMask ) = 0;

   /**
  * Remove an element from the current Package according to its Name.
  * @param iName Name of the element to search
  * @param oDicElement Found element, if any [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveElement (const CATString * iName ) = 0;

  /**
  * @deprecated
  */
  virtual HRESULT AddScopePackage ( const VPMIDicPackage * iScopePackage ) = 0;

  /**
  * Create aa AttributeMask element in the current Package.
  * @param iName Name ot the AttributeMask
  * @param iUuid Uuid of the AttributeMask
  * @param oAttrMask the created AttributeMask [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateAttributeMask ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicAttributeMask ** oAttrMask ) = 0;


  /**
  * Remove all Mask-related objects from the current Package.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveMasks () = 0;

  //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " VPMIDicPackage::GetAlias is obsolete. Please remove usage.")

#else

    /**
  * @deprecated
  */
  virtual HRESULT GetAlias            ( CATUnicodeString * oAlias ) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " VPMIDicPackage::SetAlias is obsolete. Please remove usage.")

#else
  /**
  * @deprecated
  */
  virtual HRESULT SetAlias            ( const CATUnicodeString * iAlias ) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetFileExtension should be replaced by call of same name with different arguments")

#else
/**
  * @deprecated
  */
  virtual HRESULT GetFileExtension    ( CATUnicodeString * oFileExtension ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::SetFileExtension should be replaced by call of same name with different arguments")

#else
  /**
  * @deprecated
  */
  virtual HRESULT SetFileExtension    ( const CATUnicodeString * iFileExtension ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetClasses should be replaced by call of same name with different arguments")

#else
  /**
  * Get all the Class (and therefore also Extension) elements defined at the level of the current Package.
  * @param oDicClassList the list of Class and Extension elements defined at the level of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetClasses ( CATLISTP(IUnknown) * oDicClassList ) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetScopePackages is obsolete. Stop using it")
#else
  /**
  * @deprecated
  */
  virtual HRESULT GetScopePackages ( CATLISTP(IUnknown) * ioUsePackage ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetModelerType should be replaced by call of same name with different arguments")

#else
  /**
  * @deprecated
  */
  virtual HRESULT GetModelerType   ( CATUnicodeString * oModelerType ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetModelerName should be replaced by call of same name with different arguments")

#else
  /**
  * @deprecated
  */
  virtual HRESULT GetModelerName   ( CATUnicodeString * oModelerName ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetSemanticRelationList is obsolete. Stop using it")

#else

  /**
  * Retrieve the list of SemanticRelation elements declared in the current Package.
  * @param ioSemanticRelationList : list of SemanticRelation elements
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the list is not empty.</li>
  *    <li>S_FALSE  Operation succeeded, but the list is empty.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSemanticRelationList ( CATLISTP(IUnknown) * ioSemanticRelationList ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetSemanticRelation is obsolete. Stop using it")

#else
  /**
  * Retrieve the SemanticRelation element declared in the current Packaging according to its Name.
  * Note that the VPMIDicMgr::SearchByName((const VPMDicTYPE) VPMDicSEMANTICRELATION, .../... ) method can also be used in case the containing Package is not known.
  * @param oDicSemanticRelation : the SemanticRelation element [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     The element was found.</li>
  *    <li>S_FALSE  No element was found.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSemanticRelation ( const CATString & iName, VPMIDicSemanticRelation ** oDicSemanticRelation ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetInterfaces is obsolete. Stop using it")

#else
  /**
  * Get all the Interface elements defined at the level of the current Package.
  * @param oDicInterfaceList the list of Interface elements defined at the level of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetInterfaces ( CATLISTP(IUnknown) * oDicInterfaceList ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::CreateEnum is obsolete")

#else
  /**
  * Create an Enum element in the current Package.
  * @param iName Name ot the Enum
  * @param iUuid Uuid of the Enum
  * @param oDicEnum the created Enum [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateEnum        ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicEnum ** oDicEnum ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::getFunction should be replaced by equivalent with VPMIDicFunction_var")

#else
  /**
  * @deprecated: preferred method with VPMIDicFunction_var argument  
  * FIXME: where is it ?
  * Return the function with the specified name
  * @param oFunction
  */
  virtual HRESULT getFunction(CATString Name,VPMIDicFunction ** oFunction ) = 0;
#endif
  
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetCommentis useless")

#else
  /**
  * Get the Comment element of the current Package.
  * @param oDicComment [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetComment        ( VPMIDicComment ** oDicComment ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetElementR is not allowed because the method is purely internal")

#else
    /**
  * Get an element from the current Package according to its Name, and recursively in used Packages if necessary.
  * @param iName Name of the element to search
  * @param oDicElement Found element, if any [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetElementR (const CATString * iName, VPMIDicElement ** oDicElement ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetElements should be replaced by precised methods (returning a particular kind of sub element)")

#else

  /**
  * Get all the elements defined at the level of the current Package.
  * These elements can be for instance Class, Extension, Enum, Interface, Mask, AttributeMask...
  * @param oDicElements the list of elements defined at the level of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetElements ( CATLISTP(IUnknown) * oDicElements ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetElements should be replaced by precised methods (returning a particular kind of sub element)")

#else
  /**
  * Get all the elements defined at the level of the current Package and its used (pre-requested) Packages.
  * These elements can be for instance Class, Extension, Enum, Interface, Mask, AttributeMask...
  * FIXME: document how it shall be used
  * @param oDicElements the list of elements defined at the level of the current Package its used (pre-requested) Packages.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetAllElements ( CATLISTP(IUnknown) * oDicClasses ) = 0;
#endif
  

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetElement should be replaced by precised methods (returning a particular kind of sub element)")

#else
    /**
  * Get an element from the current Package according to its Name.
  * @param iName Name of the element to search
  * @param oDicElement Found element, if any [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetElement (const CATString * iName, VPMIDicElement ** oDicElement ) = 0;
#endif
  
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetElements should be replaced by precised methods (returning a particular kind of sub element)")

#else
  /**
  * Get all the elements of a given @href VPMDicTYPE defined at the level of the current Package.
  * FIXME: document how it shall be used
  * @param oDicElements the list of elements of the given VPMDicTYPE defined at the level of the current Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetElements ( const VPMDicTYPE iDicType, CATLISTP(IUnknown) * oDicElements ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetUuid should not be used)")

#else
    /**
  * Get the Uuid of the Package.
  * @param oUuid the Uuid of the Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetUuid             ( CATDbBinary * oUuid ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::GetCAAComment should not be used anymore)")

#else
  /**
  * Get the CAAComment element of the current Package.
  * @param oDicCAAComment [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetCAAComment     ( VPMIDicCAAComment ** oDicCAAComment ) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::CreateCAAComment should not be used anymore)")

#else
  /**
  * Create a CAAComment element in the current Package.
  * @param oDicCAAComment [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateCAAComment  ( VPMIDicCAAComment ** oDicCAAComment ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicPackage::CreateComment should not be used anymore)")

#else
  /**
  * Create a Comment element in the current Package.
  * @param oDicComment [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateComment     ( VPMIDicComment ** oDicComment ) = 0;
#endif

};

CATDeclareHandler( VPMIDicPackage, CATBaseUnknown );

#endif /*VPMIDicPackage_h*/
