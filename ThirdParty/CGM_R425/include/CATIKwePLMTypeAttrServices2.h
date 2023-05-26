// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIKwePLMTypeAttrServices.h
// Define the CATIKwePLMTypeAttrServices interface
//
//===================================================================
//
// Usage notes:
//   Do not use this interfaces. Private usage for CATCkePLMTypeAttrServices implementation
//
//===================================================================
//
//  Dec 2007  Creation: Code generated by the CAA wizard  PCC
//===================================================================
/**
* @level Private
* @usage U3
*/
#ifndef CATIKwePLMTypeAttrServices2_H
#define CATIKwePLMTypeAttrServices2_H

#include "CATLifSpecs.h"

#include "CATBaseUnknown.h"
#include "CATVariant.h"

#include "CATCkePLMTypeAttrServices.h"

#include "CATListOfCATUnicodeString.h" 
#include "CATLISTV_CATBaseUnknown.h"

#include "CATListValCATIType.h"
#include "CATBoolean.h"

#include <functional>

class CATICkeParm_var;
class CATIType_var;
class CATAttributeInfos;
class CATICkeObject_var;
class CATUnicodeString;
class CATIInstance_var;
class CATBRExtraParameters;
class CATIPathTypeDescriptor_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKwePLMTypeAttrServices2;
#else
extern "C" const IID IID_CATIKwePLMTypeAttrServices2;
#endif

#include "CATPathTypeDescriptorDictionary.h"

//------------------------------------------------------------------

/**
* Do not use the CATIPLMTypeServices interface.
**/
class ExportedByCATLifSpecs CATIKwePLMTypeAttrServices2 : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  //-----------------------------------------------------------------------------------
  // Calcul de la vue masqu�e
  //-----------------------------------------------------------------------------------
  virtual HRESULT ListFilteredAttributesFromMask(const CATIType_var& iKweType,
    const CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
    CATListValCATAttributeInfos &oListFilteredAttr) = 0;

  virtual HRESULT ListIdentifierAttributes(const CATIType_var& iKweType,
    CATListOfCATUnicodeString& oIdentifierAttrNames) = 0;


  //-----------------------------------------------------------------------------------
  // Chargement dico
  //-----------------------------------------------------------------------------------
  virtual HRESULT LoadCurrentEnvironment() = 0;

  //-- [chd:02.09.2018] Pour recharger un Kwe Dico qui s'est retrouv� vid� (sc�nario d�connexion/reconnexion ?) 
  virtual HRESULT ReloadKweDictionary() = 0;

  //-----------------------------------------------------------------------------------
  // Besoin de parcourir le dico pour trouver les extensions qui etendent un type
  // Est incompatible avec l'incremental
   // returns S_OK if yes S_FALSE if No
  //-----------------------------------------------------------------------------------
  virtual HRESULT CanBeExtendedBy(const CATICkeObject_var & iObject, const CATIType_var &iSecondaryType, CATUnicodeString *oMessage = NULL) = 0;

  //-----------------------------------------------------------------------------------
  // Besoin de prerequer le P&O pour recuperer les parametres de login
  //-----------------------------------------------------------------------------------
  virtual HRESULT GetParamNamingElements(const CATIType_var &iTypeName, CATUnicodeString &oPrefix, CATUnicodeString &iInterfix, CATUnicodeString &oSuffix, CATUnicodeString &oSeparator) = 0;


  //-----------------------------------------------------------------------------------
  // Nettoyage de fin de session
  //-----------------------------------------------------------------------------------
  virtual void FreeStatics() = 0;

  //-----------------------------------------------------------------------------------
  // Prereque PLMBusinessLogicAccess
  //-----------------------------------------------------------------------------------
  /**
  * This service is used to initialize a proxy with business logic.<br>
  * It is included in this interface as a bridge to be used in CATExpressionEngine.
  * @param oProxy
  * Type in input (only modeler types are supported)
  * @param oListSearchableSubTypes
  * The list is filled by the service
  * @return
  *  <ol>
  * 	 <li> E_INVALIDARG if the type is NULL
  * 	 <li> S_OK	if the list of types is retrieved and is not empty
  * 	 <li> S_FALSE if no type found
  *  </ol>
  */
  virtual HRESULT InitializeProxyWithBusinessLogic(const CATIInstance_var        &iProxy,
    const CATBRExtraParameters	*piExtraParameters) = 0;


  //-----------------------------------------------------------------------------------
  // Gestion des paths types: a besoin du dico PLM
  //-----------------------------------------------------------------------------------

  virtual HRESULT RetrievePathTypeDescriptor(const CATUnicodeString &iPathTypeName,
    const CATUnicodeString &iRoleName,
    const CATUnicodeString &iCategoryName,
    CATIPathTypeDescriptor_var &oPathtypeDescriptor) = 0;
  /*	virtual HRESULT ComputePathDisplayName (const CATUnicodeString &iPathTypeName,
                           const CATUnicodeString &iRoleName,
                           const CATUnicodeString &iCategoryName,
                           CATUnicodeString &oDisplayName)=0;

    */
  virtual CATIPathTypeDescriptor_var FindPathType(const CATUnicodeString &iPathTypeName) = 0;

  // Service to be used only by ODT
  virtual CATLISTV(CATBaseUnknown_var) *GetListOfGlobalPathDescriptor() = 0;

  //virtual CATOmxMapIter<CATUnicodeString, CATPathDescriptorH> RetrievePathDescriptors ()=0;



  // Methode pour migrer les paths
  virtual HRESULT MigratePathCharacteristics(const CATUnicodeString &iAggregatorTypeName,
    const CATUnicodeString &iRoleName,
    const CATUnicodeString &iCategoryName,
    CATUnicodeString &oPathTypeName,
    CATUnicodeString &oRoleName,
    CATUnicodeString &oCategoryName) = 0;

  // Service downward compatibility
  virtual HRESULT ProduceFormerPathModel(const CATIPathTypeDescriptor_var &iPathDesc, CATUnicodeString &oRole, CATUnicodeString &oCategory) = 0;

  //-----------------------------------------------------------------------------------
  // Dico incremental base sur l'indes
  //-----------------------------------------------------------------------------------
  // Va chercher un type PLM (et le charger): ne doit etre appel� qu'apres un echec du FindType en memoire
  virtual HRESULT CreatePLMPackages() = 0;
  virtual HRESULT LoadAndFindPLMType(const CATUnicodeString &iTypeName, CATIType_var &oType) = 0;
  virtual	HRESULT LoadPLMPackage(const CATUnicodeString &iPackageName) = 0;


  //-----------------------------------------------------------------------------------
  // Activation of path type project
  //-----------------------------------------------------------------------------------
  virtual CATBoolean PathTypeMappingSuppressed() = 0;
  virtual CATBoolean RoleAndCategoryReplaced() = 0;

  // recupere un type cache
  virtual CATIType_var FindHiddenType(const CATUnicodeString &iTypeName) = 0;

  virtual HRESULT GetTeamBehavior2() = 0;

  //-----------------------------------------------------------------------------------
  // Vue masquee: optimisation sur les attributs interessants uniquement (le filtre
  // doit rendre true pour ceux-la)
  //-----------------------------------------------------------------------------------
  virtual HRESULT ListFilteredAttributesFromMask(const CATIType_var& iKweType,
    const CATCkePLMTypeAttrServices::PLMMaskCriteria iPLMMaskCriteria,
	const std::function<bool (const CATAttributeInfos&)>& iAttributeInfosFilter,
    CATListValCATAttributeInfos &oListFilteredAttr) = 0;

};

//------------------------------------------------------------------

#endif
