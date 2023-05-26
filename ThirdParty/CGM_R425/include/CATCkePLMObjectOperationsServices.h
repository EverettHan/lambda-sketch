// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCkePLMObjectOperationsServices.h
// Header definition of CATCkePLMObjectOperationsServices
//
//===================================================================
//
// Usage notes:
// Provides services to Life cycle commands UI and PLM New UI
//
//===================================================================

 

#ifndef CATCkePLMObjectOperationsServices_H
#define CATCkePLMObjectOperationsServices_H

// Module export
#include "PLMDictionaryNavServices.h" 
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATListValCATICkeObject.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATICkeObject_var;
class CATUnicodeString;
class CATIType_var;
class CATIDelegateInstanciation_var;


/**
 * Services to know which operations are available on an object.<br>
 * Works on PLM components implementing Knowledge view.<br>
 * @see CATIValue
 * @see CATIInstance
 * @see CATIType
 */
class ExportedByPLMDictionaryNavServices CATCkePLMObjectOperationsServices
{

  public:

    /**
	 * Enumerated value that defines the list of operations that are enabled or not on a PLM object.<br>
	 * @param NewVersion
 	 * Versioning operation. Major version.
	 * @param ChangeMaturity
	 * Changing maturity of an object.
	 * @param Delete
	 * Deleting an object.
 	 * @param LockUnlock
	 * Locking or unlocking an object.
 	 * @param TransferOwnership
	 * Transfering ownership of an object.
 	 * @param Duplicate
	 * Duplicating an object.
 	 * @param EditProperties
	 * Editing properties of an object.
 	 * @param SaveAsNew
	 * Saving an object as new.
	 * @param NewMinorRevision
 	 * Revision operation. Minor revision.
	 * @param Evolution
 	 * Evolution operation
 	 * @param ManageAccess
 	 * Manage access operation: a design workspace enables to define particular access rights to the data it contains
	 * @param ProjectApplicability
 	 * For data that can be shared between projects
	 */
	  enum PLMOperation { NewVersion=1,
						  ChangeMaturity=2,
						  Delete=3,
						  LockUnlock=4,
						  TransferOwnership=5,
						  Duplicate=6,
						  EditProperties=7,
						  SaveAsNew=8,
						  NewMinorRevision=9,
						  Evolution =10,
						  Iteration =11,
						  ManageAccess =12,
						  ShareBetweenProjects =13,
						  ChangeCollaborativeSpace =14};
	
	  /**
	 * Tests if a given operation is available on an object.<br>
	 * Tests both what is declared in the PLM Dictionary and what comes from security/grants.<br>
	 * @param iObject
 	 * Knowledge object we want to interrogate.
	 * @param iOperationToTest
	 * Operation we want to test
	 * @param oAvailable
	 * Indicates if the operation is available
	 *  <ol>
	 * 	 <li> TRUE if the operation is available
	 * 	 <li> FALSE instead
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object was NULL
	 * 	 <li> S_OK	if the service has answered the question.
	 *  </ol> 
     */
	static HRESULT SupportsOperation (const CATICkeObject_var &iObject,
										 const PLMOperation iOperationToTest,
										 CATBoolean     &oAvailable) ;

    /**
	 * In a transition phase, some types of objects have declared the supported operations in the PLM Dictionary <br>
	 * And some are still based on declarative files.<br>
	 * This method enables to differentiate when we must useSupportsOperation method and when we shall rely on declarative files <br>
	 * @param iObject
 	 * Knowledge object we want to interrogate.
	 * @param oAvailable
	 * Indicates if the availability is declared in the PLM Dictionary
	 *  <ol>
	 * 	 <li> TRUE if the support of operation is declared in PLM Dictionary
	 * 	 <li> FALSE instead
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object was NULL
	 * 	 <li> S_OK	if the service has answered the question.
	 *  </ol> 
     */
	static HRESULT IsOperationSupportDeclaredInPLMDictionary (const CATICkeObject_var &iObject,
														      CATBoolean     &oIsDeclared) ;
	/**
	* Calls the Knowledge protocol to create a PLM object from the PLM New command<br>
	* Creates an object from its type, its name and its father <br>
	* @param iTypeToCreate
	* Type of the object to create
	* @param iAggregator
	* Aggregator of the object may be NULL
	* @param iPLMProxy
	* PLMProxy to use to valuate attribute. Can be NULL.
	* @param oNewObject
	* Object in output. When creating a reference or a representation under an aggregating reference, the instance is returned
	* @param oErrorMessage
	* Message in case of error
	* @param iLongTransactionMode
	* TRUE if long transaction, FALSE instead
	* @param ipAdditionalProxies
	* Usually NULL. Additional proxies...
	* @param iInputsValues
	* Usually NULL. Inputs values for literal attributes of KML Concepts called through PLM New
	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the new
	*    <li> E_INVALIDARG if type is empty or is not instanciable
	*    <li> E_ACCESSDENIED if the new has failed due to licensing or editability
	*    <li> S_OK if the new has succeded
	*  </ol>
	*/ 
	static HRESULT  NewPLMObject   (const CATIType_var		 &iTypeToCreate,
									const CATICkeObject_var  &iAggregator,
									const CATICkeObject_var  &iPLMProxy,
									CATICkeObject_var		 &oNewObject, 
									CATUnicodeString         &oErrorMessage,
									CATBoolean				  iLongTransactionMode = TRUE,
									const CATLISTV(CATICkeObject_var) *ipAdditionalProxies = NULL,
									const CATLISTV(CATBaseUnknown_var) * iInputsValues = NULL);
	/**
	* Calls the Knowledge protocol to insert a PLM object under another one from the PLM New command<br>
	* Creates the instance from its type, its name and its father <br>
	* @param iTypeToCreate
	* Type of the object to create
  * If the type is not precised, it will be deduced from dictionary declarations or from business logic
	* @param iAggregator
	* Aggregator of the object. Cannot be NULL
	* @param iObjectToInsert
	* Object to insert (a ref or rep)
	* @param iPLMProxy
	* PLMProxy of the instance to use to valuate attribute. Can be NULL. Must be NULL if you wish to deduce the type of instance
	* @param NewObject
	* Object in output. When creating a reference or a representation under an aggregating reference, the instance is returned
	* @param oErrorMessage
	* Message in case of error
	* @param iLongTransactionMode
	* TRUE if long transaction, FALSE instead
	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the new
	*    <li> E_INVALIDARG if type is empty or is not instanciable
	*    <li> E_ACCESSDENIED if the new has failed due to licensing or editability
	*    <li> S_OK if the new has succeded
	*  </ol>
	*/ 
	static HRESULT  InsertExistingPLMObject   ( const CATIType_var		 &iTypeToCreate,
											    const CATICkeObject_var  &iAggregator,
											    const CATICkeObject_var  &iObjectToInsert,
												const CATICkeObject_var  &iPLMProxy,
												CATICkeObject_var		 &oNewObject,
												CATUnicodeString         &oErrorMessage,
												CATBoolean				  iLongTransactionMode = TRUE);

	// Internal: Do not use
	static CATListOfCATUnicodeString PLMOperationAsStrings ();
	static CATUnicodeString PLMOperationAsString (const PLMOperation iOperationToTest);
	static HRESULT PLMOperationFromString (const CATUnicodeString &s, PLMOperation &oOperation);

	/**
	* Retrieve the applicative class used to instanciate the Object.<br>
	* Do not use. Strictly restricted to PLM New UI.<br>
	* @param iType
	* Type that we want to create
	* @param oApplicativeFactory
	* Factory (can be NULL)
	* @return
	*  <ol>
	*    <li> E_INVALIDARG if type is empty or if the type has no associated factory mechanism
	*    <li> S_OK if the factory has been retrieved.
	*    <li> S_FALSE if the factory has not been retrieved because it didn't exist on this type.
	*  </ol>
	*/ 
	static HRESULT  RetrieveApplicativeFactory ( const CATIType_var		 &iType,
											     CATIDelegateInstanciation_var  &oApplicativeFactory);


	/**
	 * Indicates if it is possible for a CAA customer to integrate the command operating the PLM New of an object of a given type
	 * 	
	 * @param iType
	 * Type that we want to create
 	 * @param oNewable
	 * Can be used in PLM New
 	 * @param oInsertable
	 * Can be used to insert New object
 	 * @param oCAA
	 * Possible or not in CAA
 	 * @param poOffline
	 * Possible or not in offline. If pointer is null, information is not set (due to upward compatibility of the API)
	 * @return
 	 *  <ol>
	 *    <li> E_INVALIDARG if type is empty 
	 *    <li> S_OK if ok
	 *  </ol>
	 */
	 static HRESULT  CanBeCreatedByPLMNew ( const CATIType_var		 &iType,
											CATBoolean               &oNewable,
											CATBoolean               &oInsertable,
											CATBoolean               &oCAA,
											CATBoolean				 *poOffline=NULL
											);


	/**
	* Retrieve the additional contributors participating to the UI for creating an object.<br>
	* Do not use. Strictly restricted to PLM New UI.<br>
	* @param iType
	* Type that we want to create
	* @param oTransversalContributors
	* Late types (like configuration) that are transversal
	* @return
	*  <ol>
	*    <li> E_INVALIDARG if type is empty or if the type has no associated factory mechanism
	*    <li> S_OK if the factory has been retrieved.
	*    <li> S_FALSE if the factory has not been retrieved because it didn't exist on this type.
	*  </ol>
	*/ 
	static HRESULT  RetrieveTransversalContributors	( const CATIType_var		 &iType,
											          CATListOfCATUnicodeString  &oTransversalContributors);

    /**
	 * Tests if a given operation is available on a type.<br>
	 * Tests what is declared in PLM Dictionary.<br>
	 * @param iType
 	 * Type
	 * @param iOperationToTest
	 * Operation we want to test
	 * @param oAvailable
	 * Indicates if the operation is available
	 *  <ol>
	 * 	 <li> TRUE if the operation is available
	 * 	 <li> FALSE instead
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL
	 * 	 <li> S_OK	if the service has answered the question.
	 *  </ol> 
     */
	static HRESULT SupportsOperationFromType (	const CATIType_var &iType,
												const PLMOperation iOperationToTest,
												CATBoolean     &oAvailable) ;

	/** 
	 * Depending on the level of packaging (sharing or innovation), we may have access to life cycle operations (revision, maturity) or not on a type.
	 * @param iType
 	 * Type
	 * @param oAvailable
	 * Indicates if the operation is available
	 *  <ol>
	 * 	 <li> TRUE if the operation is available
	 * 	 <li> FALSE instead
	 *  </ol>
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the type is NULL
	 * 	 <li> S_OK	if the service has answered the question.
	 *  </ol> 
	 */
//	static HRESULT LifeCycleOperationsAvailable (const CATIType_var &iType,CATBoolean     &oAvailable);


	/**
	 * Returns the list of operations that are supported by the object and that supports publish/subscribe
	 * @param iObject
 	 * Knowledge object we want to interrogate.
	 * @param oListOperationID
	 * list of names of operations (id that will be passed to server)
	 * @param oListOperationNamesTranslated
	 * list of names of operations, translated to be shown in UI
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object was NULL
	 * 	 <li> S_OK	if the service has answered the question. List can be empty
	 *  </ol> 
	 */
	static HRESULT ListPublishedOperationsSupportedByObject (const CATICkeObject_var    &iObject,
															 CATListOfCATUnicodeString  &oListOperationID,	
															 CATListOfCATUnicodeString  &oListOperationNamesTranslated);	
										
   
	/**
	 * Returns the list of operations that are supported by a type and that supports publish/subscribe
	 * @param iType
 	 * Type we want to interrogate.
	 * @param oListOperationID
	 * list of names of operations (id that will be passed to server)
	 * @param oListOperationNamesTranslated
	 * list of names of operations, translated to be shown in UI
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if the object was NULL
	 * 	 <li> S_OK	if the service has answered the question. List can be empty
	 *  </ol> 
	 */
	static HRESULT ListPublishedOperationsSupportedByType   (const CATIType_var      &iType,
															 CATListOfCATUnicodeString  &oListOperationID,	
															 CATListOfCATUnicodeString  &oListOperationNamesTranslated);	
										
   


};

//-----------------------------------------------------------------------

#endif
