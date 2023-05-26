// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATCkePLMNavBusinessLogic.h
// Header definition of CATCkePLMNavBusinessLogic
//
//===================================================================
//
// Usage notes:
// Provides services for accessing attributes on an object
//
//===================================================================



#ifndef CATCkePLMNavBusinessLogic_H 
#define CATCkePLMNavBusinessLogic_H 

// Module export
#include "CATLifSpecs.h"
#include "CATBoolean.h"
#include "CATCkePLMTypeAttrServices.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATIType.h"
#include "CATIInstance.h"
#include "CATErrorDefs.h"
class CATIType_var;

/**
* Services used by navigation UI to access critical BLs.<br>
*/
class ExportedByCATLifSpecs CATCkePLMNavBusinessLogic
{

public:

  //---------------------------------------------------------------------------------------------------------------------------
  // The deployment business logics are invoked on a type and never on an object
  // The policy computation is invoked only in UnifiedTyping mode and in UnifiedExperience context
  // The deployment extension computation is invoked only in UnifiedTyping mode 
  // The vault choice business logic is invoked in all mode (UnifiedTyping & FormerTyping)
  //---------------------------------------------------------------------------------------------------------------------------

  // In input we give the public type 
  // We can precise that we want to compute additional policies that can be selected in PLM New context for example
  CATCkePLMNavBusinessLogic(const CATIType_var iTypeInput,
    CATBoolean iAdditionalPoliciesNeeded = FALSE);

  // The deployment business logic can also be invoked starting from a proxy. However, the type is deduced from the proxy (we take the primary type)
  // In some case, we invoke the policy computation on a proxy (that has been built for coexistence purpose)
  CATCkePLMNavBusinessLogic(const CATIInstance_var &iProxy,
    CATBoolean iAdditionalPoliciesNeeded = FALSE,
    CATBoolean iPolicyComputationNeeded = TRUE,
    CATBoolean iIsAggregated = FALSE);

  // In the case when an object is to be created aggregated under another one, we provide in input the aggregator
  // The fact that the object will be aggregated may lead to the choice of a different business rule
  CATCkePLMNavBusinessLogic(const CATIType_var iTypeInput,
    const CATIInstance_var &iAggregator,
    CATBoolean iAdditionalPoliciesNeeded = FALSE);

  // Constructor for private type. A private type has no CATIType available. Nevertheless, it is possible to invoke a business rule
  // for policy choice or for vault choice. 
  // We pass the type name
  CATCkePLMNavBusinessLogic(const CATUnicodeString &iTypeNameInput);

  ~CATCkePLMNavBusinessLogic();

  // Note that there are 2 BL that are fired
  // - the first one computes the policy name by default to use, and a list of additional policies
  // - the second one (starting from a policy name) will compute the deployment extension and a list of customer extensions

  // Returns the deployment extension type after computation
  // Note that we retrieve the pointer on the lists to av
  // returns a HR=GetPolicyComputationFailedID if the BL for computing policies failed
  HRESULT RetrievePolicies(CATUnicodeString &oPolicyName, CATListOfCATUnicodeString &AdditionalPolicies);

  // When the policies have been retrieved, the user can select one of it
  // returns E_FAIL if the policy chosen is not part of the authorized policies
  // returns a HR=GetPolicyComputationFailedID if the BL for computing policies failed
  HRESULT SelectPolicy(const CATUnicodeString &oPolicyName);

  // Returns the deployment extension type and the list of customer extensions
  // returns a HR=GetPolicyComputationFailedID if the BL for computing policies failed
  HRESULT RetrieveExtensions(CATIType_var &oDeploymentExtension, CATListValCATIType_var &CustomerExtensionsToAdd);

  // Returns the vaults to use for search
  // returns a HR=GetVaultComputationFailedID if the BL for computing policies failed
  HRESULT RetrieveVaultsForSearch(CATListOfCATUnicodeString &oVaultToUseForSearch);

  // Returns the the vaults to use for creation. 
  // Note that we retrieve the pointer on the lists to av
  // returns a HR=GetVaultComputationFailedID if the BL for computing policies failed
  HRESULT RetrieveVaultsForCreation(CATUnicodeString &VaultName, CATListOfCATUnicodeString &AdditionalVaults);

  // Returns the 

  /**
  * Indicates if we're managing choice between deployment extensions
  * @return
  *  <ol>
  * 	 <li> TRUE if there is a possible choice
  * 	 <li> FALSE	instead
  *  </ol>
  */
  static CATBoolean ChoiceBetweenPolicies();

  /**
  * Indicates if Race is available with new typing
  * @return
  *  <ol>
  * 	 <li> TRUE
  * 	 <li> FALSE
  *  </ol>
  */
  static CATBoolean RaceAvailableWithNewTyping();

  /*
  * Returns the CATErrorID raised when the BL for assigning policy failed
  */
  static CATErrorId GetPolicyComputationFailedID();

  /*
  * Returns the CATErrorID raised when the BL for computing vaults failed
  */
  static CATErrorId GetVaultComputationFailedID();

private:

  // Computes deployment business logic
  //HRESULT ComputePolicy();
  //HRESULT ComputeExtension();

  void DecodeType(const CATIType_var &iTypeInput);

  CATIInstance_var      _iProxy; // contient le proxy quand on l'a
  CATIType_var			    _TypePrimary;  // Contient le type primaire
  CATIType_var			    _FirstPublicTypePrimary;  // Contient le premier type primaire public
  CATIType_var			    _TypeExtension;  // Contient le type secondaire 
  CATIType_var			    _TypePolicy;  // Contient le type sur lequel on va calculer la policy 

  CATUnicodeString		  _PolicyNameInOutput;              // policy name in output, soit le defaut calcule par la policy, soit celle qu'on a selectionne
  CATBoolean            _PolicyBusinessLogicIsComputed;   // On se souvient si on l'a calculée

  CATIInstance_var      _iAggregatingReference; // Reference aggregeante
  CATBoolean            _isAggregated;          // est-on aggrege
  CATBoolean*           _pIsMajorMinorAtImport;  // non NULL, en import avec/sans major/minor

  // not implemented
  CATCkePLMNavBusinessLogic(const CATCkePLMNavBusinessLogic&);

public:
  // .. in the context of an import ONLY, major/minor mode has an impact
  CATCkePLMNavBusinessLogic(const CATIInstance_var &iProxy,
    CATBoolean iAdditionalPoliciesNeeded,
    CATBoolean iPolicyComputationNeeded,
    CATBoolean iIsAggregated,
    CATBoolean iIsMajorMinorAtImport);

};


#endif
