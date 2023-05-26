// COPYRIGHT Dassault Systemes 2007


#ifndef CATBRUtilities_H
#define CATBRUtilities_H


#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATIBRExecutionServices.h"
class CATUnicodeString;
class CATIInstance_var;
#include "CATErrorDefs.h"
#include "CATInputError.h"


/** This class of services contains various methods to ease the use of customization rules in different contexts             
 */
 
class ExportedByCATLifSpecs CATBRUtilities
{
public:
	
	/**
	 * Interprets the HRESULT of CATIBRExecutionServices execution services (ExecuteComputationService, ExecuteRuleService, ExecuteValidationService)
	 * Those services returns S_OK when a business rule has been found and it was valid syntactically and it didn't raise evaluation error
	 * But they return E_FAIL in the 3 cases
	 * We must be able to consider that it is S_OK when no business rules where found. And if it fails, we may want to retrieve the error message
	 * @param
	 * ispExecutionServices execution manager
	 * @param 
	 * iHROrigin HRESULT returned by (ExecuteComputationService, ExecuteRuleService, ExecuteValidationService)
	 * @param
	 * iFailure returns FALSE if no issue (syntax/evaluation error) TRUE if an error occurred
	 * @return
	 * S_OK 
	 * E_FAIL if internal error
	 */ 
	static HRESULT InterpretError (const CATIBRExecutionServices_var &ispExecutionServices,
							HRESULT iHROrigin,
							CATBoolean &iFailure);


	
	/**
	 * Service to propagate the policy attribute available on an object into the Policy attribute of the BR Context
	 * This service must be called by software executing business rules, that want to articulate their business rule on the Policy axis
	 * @param
	 * iFact the object that contains the policy
	 * @param 
	 * iContext the BR context
	 * @return
	 * S_OK if the policy has been succesfuly been copied
	 * S_FALSE if the policy didn't need to be copied (for an instance type or relation type or if not in UnifiedExperience). Basically, if policy not found on the fact
	 * E_INVALIDARG if objects in input were missing
	 * E_FAIL if we didn't succeed
	 */
	static HRESULT PropagatePolicyFromFactToContext (const CATIInstance_var &iFact, const CATIInstance_var &iContext);
	
	//-------------------------------------------------------------------------------
	// Strings identifying Business logic ID and input/output parameters for infra business logic
	//-------------------------------------------------------------------------------

	// Input parameter for a lot of infrastructure BL, containing the security context information
	static const CATUnicodeString BRID_INFRABL_Role;                 // String corresponding to the rule of the user
	static const CATUnicodeString BRID_INFRABL_Organization;         // String corresponding to the organization of the user
	static const CATUnicodeString BRID_INFRABL_Project;              // String corresponding to the name of the project used by the user
	static const CATUnicodeString BRID_INFRABL_UserID;               // String corresponding to an ID of a user
	static const CATUnicodeString BRID_INFRABL_SecurityContext;      // String corresponding to the security context
	

	// Additional inputs
	static const CATUnicodeString BRID_INFRABL_FormerTyping;
	static const CATUnicodeString BRID_INFRABL_IsSessionOffline;

	// Input parameter for a lot of infrastructure BL, containing the policy of the fact that is duplicated on BR context to enable the choice of the BL to use 
	static const CATUnicodeString BRID_INFRABL_PolicyName_Input_Policy;

	// Output parameter for a lot of BR corresponding to a message to set in validation rules
	static const CATUnicodeString BRID_INFRABL_Message;
	static const CATUnicodeString BRID_INFRABL_NLSMessage; // Message on server side 
	// Method to retrieve message (one or the other)
	static HRESULT GetMessage (const CATIInstance_var &iBRContext,CATUnicodeString &oMessage);

	// Output parameter for a lot of BR corresponding to a severity to set in validation rules
	static const CATUnicodeString BRID_INFRABL_Severity;

	// Name of the business logic ID corresponding to policy choice depending on type
	static const CATUnicodeString BRID_INFRAAuthorizedPolicies;

		// Associated parameters
		static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Output_PolicyName; // Default policy name computed
		static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Output_OtherPolicies; // other policy names that can be chosen
  	static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Input_OperationId;  // Indicates in which context the BL is called
    		static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Input_OperationId_New; // Invoked in the New context
    		static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Input_OperationId_Import; // Invoked in Import context
    		static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Input_OperationId_Default; // Default value
  	static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Input_PolicyOfAggregatingReference;  // Policy of the aggregating reference if any
  	static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Input_IsAggregated;  // Indicates if the object is aggregated or not
  	static const CATUnicodeString BRID_INFRAAuthorizedPolicies_Input_AggregatingReference;  // Aggregating reference if any
    static CATErrorId GetPolicyComputationFailedID ();

 	// Name of the business logic ID corresponding to the choice of the vault
	static const CATUnicodeString BRID_INFRAVaultsSelection;

    // Associated parameters
		static const CATUnicodeString BRID_INFRAVaultsSelection_Output_DefaultVaultNameForCreation; // Default vault to use for creation
		static const CATUnicodeString BRID_INFRAVaultsSelection_Output_OtherVaultsForCreation; // other vault names that can be chosen for creation
  	static const CATUnicodeString BRID_INFRAVaultsSelection_Output_VaultsForSearch;  // Indicates in which vaults we are supposed to search
    static CATErrorId GetVaultComputationFailedID ();

    // Name of the business logic ID corresponding to deployment extension computation 
	static const CATUnicodeString BRID_INFRADeploymentExtensionComputation;
	
		// Associated parameters
		static const CATUnicodeString BRID_INFRADeploymentExtensionComputation_Output_DeploymentExtensionName; // Deployment extension name in output
		static const CATUnicodeString BRID_INFRADeploymentExtensionComputation_Output_CustomerExtensionsToAdd; // List of customer (or deployment by the way) extension names to be added on the object
	
	// Name of the business logic ID corresponding to computation of logical name attribute
	static const CATUnicodeString BRID_INFRALogicalNameAttribute;

		// Associated parameters
		static const CATUnicodeString BRID_INFRALogicalNameAttribute_Output_AttributeName; // attribute name in output
		static const CATUnicodeString BRID_INFRALogicalNameAttribute_Output_AdditionalAttributes; // attribute name in output

	// Name of the business logic ID corresponding to computed attributes
	static const CATUnicodeString BRID_INFRAComputedAttribute;
	static const CATUnicodeString BRID_INFRAComputedAttributeWrite;

		// Associated parameters
		static const CATUnicodeString BRID_INFRAComputedAttribute_Input_AttributeName; // attribute name in input
		static const CATUnicodeString BRID_INFRAComputedAttribute_Input_InputValue;    // attribute value in input
		static const CATUnicodeString BRID_INFRAComputedAttribute_Output_ComputedValue;    // attribute value in output
	
	// Name of the business logic ID corresponding to the selection of the instance type to use when instanciating a given reference
	static const CATUnicodeString BRID_INFRAInstanceTypeSelection;
	
		// Associated parameters: we can use the same parameters to define extension deployment or customer extensions to add
		//static const CATUnicodeString BRID_INFRADeploymentExtensionComputation_Output_DeploymentExtensionName; // Deployment extension name in output
		//static const CATUnicodeString BRID_INFRADeploymentExtensionComputation_Output_CustomerExtensionsToAdd; // List of customer (or deployment by the way) extension names to be added on the object
		static const CATUnicodeString BRID_INFRAInstanceTypeSelection_Input_AggregatingReference; // Aggregating reference
		static const CATUnicodeString BRID_INFRAInstanceTypeSelection_Output_InstanceTypeName; // Instance type name selected
		
	// Name of the business logic ID corresponding to frozen state computation
	static const CATUnicodeString BRID_INFRAMaturityStateInformation;

		// Associated parameters: we can use the same parameters to define extension deployment or customer extensions to add
		static const CATUnicodeString BRID_INFRAMaturityStateInformation_Input_State; // State in input of the BL
		static const CATUnicodeString BRID_INFRAMaturityStateInformation_Output_IsFrozen; // IsFrozen information in output of the BL
		static const CATUnicodeString BRID_INFRAMaturityStateInformation_Output_MetaStateName; // MetaStateNameinformation in output of the BL

	// Name of the business logic ID corresponding to attribute initialization
	static const CATUnicodeString BRID_PLMIdentificationInitialization;
	
	// Name of the business logic ID corresponding to finalization
	static const CATUnicodeString BRID_PLMFinalizationForOffline;
	
	// Name of the business logic ID corresponding to integrity check
	static const CATUnicodeString BRID_PLMObjectIntegrityCheck;
		
	// Name of the business logic ID corresponding to new typing upgrade of filters & PVS
	static const CATUnicodeString BRID_INFRA_UnifiedTypingMigration;
	static const CATUnicodeString BRID_INFRA_UnifiedTypingMigration_Input_DefaultTargetTypeName; // Type to query by default 
	static const CATUnicodeString BRID_INFRA_UnifiedTypingMigration_Input_PreviousAttributes; // List of attributes names used in previous query
	static const CATUnicodeString BRID_INFRA_UnifiedTypingMigration_Output_ComputedTargetTypeName; // Type name in output
	static const CATUnicodeString BRID_INFRA_UnifiedTypingMigration_Output_MappedAttributes; // List of attributes names in output
	static const CATUnicodeString BRID_INFRA_UnifiedTypingMigration_Output_MappedExtensions; // List of attributes names in output

  // Service for invoking business rule either on a type or on an object. Shouldn't be invoked with the two arguments not null
  // operationID must be one of the authorized strings
  static HRESULT ComputePolicies  ( const CATIType_var &iType,const CATIInstance_var &iObject,const CATUnicodeString &OperationId,
                                    CATUnicodeString &oPolicyName,
                                    CATListOfCATUnicodeString &AdditionalPolicies,
                                    CATInputError **pOutputError,
                                    const CATIInstance_var &iAggregator = NULL_var,
                                    CATBoolean isAggregated=FALSE);
  
   static HRESULT InstanceTypeSelectionComputation (	const CATIInstance_var &iReferenceToInstantiate,
											const CATIInstance_var &iReferenceWhereAggregated,
											CATIType_var &oInstantiationTypeChosenByBL,
											CATIType_var &oDeploymentExtensionTypeChosenByBL,
											CATListValCATIType_var &oCustomerExtensionsToAddChosenByBL);
   
  // Service for invoking business rule either on a type
  static HRESULT ComputeVaults  ( const CATIType_var &iType,
                                  CATUnicodeString &oDefaultVaultNameForCreation,
                                  CATListOfCATUnicodeString &oVaultsForSearch,
                                  CATListOfCATUnicodeString &oOtherVaultsForCreation,
                                  CATInputError **pOutputError);

private:
	
	CATBRUtilities();	
	CATBRUtilities(const CATBRUtilities &);	
	CATBRUtilities & operator=(const CATBRUtilities &);
	~CATBRUtilities();	

	static int _sComputeVaults_isComputing;

public:

  // pour eviter un decalage de lib
  static HRESULT ComputePolicies(const CATIType_var &iType, const CATIInstance_var &iObject, const CATUnicodeString &OperationId,
    CATUnicodeString &oPolicyName,
    CATListOfCATUnicodeString &AdditionalPolicies,
    CATInputError **pOutputError,
    const CATIInstance_var &iAggregator,
    CATBoolean isAggregated,
    CATBoolean * pImportContext);

};

//-------------------------------------------------------------------------

#endif
