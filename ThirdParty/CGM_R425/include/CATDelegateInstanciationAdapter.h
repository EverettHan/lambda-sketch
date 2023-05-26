#ifndef CATDelegateInstanciationAdapter_H
#define CATDelegateInstanciationAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 2002

/** 
* @CAA2Level L1
* @CAA2Usage U2
*/


// Export Module 
#include "CATLifSpecs.h" 

// inherit from
#include "CATBaseUnknown.h"
#include "CATIForwardsDecl.h"
#include "CATUnicodeString.h"
#include "CATIDelegateInstanciation.h"
#include "CATKWEErrorSeverity.h"

class CATInstanciationContext;
class CATICkeObject_var;
class CATIType_var; 

/**   
 * CAA2 Adapter to CATIDelegateInstanciation Interface.
 * <b>Role</b>: This class must be derived to implement  extension to CATIDelegateInstanciation.<br>
 * CATIDelegateInstanciation is the interface used by Knowledgeware to instanciate objects.<br>
 * @see CATIDelegateInstanciation, CATIType, CATITypeDictionary, CATICkeObject, CATInstanciationContext
 */
class ExportedByCATLifSpecs CATDelegateInstanciationAdapter : public CATIDelegateInstanciation
{
public:

   /** 
    * Constructs the extension.
    */ 
    CATDelegateInstanciationAdapter();

   /** 
    * Deletes the extension.
    */ 
    virtual ~CATDelegateInstanciationAdapter();

	/**
	 * Creates an instance oInstanciated, of type typeName in owner iOwner and named iName.<br>
	 * Must be overriden by implementer.<br>
	 * @param iOwner The object that will aggregate the object to create
	 * @param iName The name of the object to create
	 * @param iTypeName Name of the type of the object to create
	 * @param oInstanciated object created in output
	 * @param iContext context of instantiation
   	 * @return
	 *  <ol>
 	 * 	 <li> E_INVALIDARG if the instantiation has failed (bad arguments, bad father).
	 * 	 <li> E_ACCESSDENIED if the creation is impossible because the context is read only.
	 * 	 <li> S_OK	if the object has been created successfully.
	 *  </ol>
	 */
	virtual HRESULT InstanciateObject( const CATICkeObject_var & iOwner, const CATUnicodeString& iName, const CATUnicodeString& iTypeName, CATICkeObject_var & oInstanciated,const CATInstanciationContext *iContext ) ;
 
 	/**
	*  Description: Raises an error. Use this method inside the InstanciateObject method.<br>
	*  when you want to bring to the user more explanation about why the new operation has failed.<br>
	*  Note that you don't need to raise message (& use this method) in the standard error cases (bad arguments, bad father, owner read only, ...
	*  Simply return the right HRESULT (E_INVALID_ARG, E_ACCESSDENIED) and a standard error message is raised (CreationInReadOnly, CreationFailed).<br>  
    *  @param iMessage: the NLS message that will be brought to the end-user.
    *  @param iSeverity: severity of the error.
	*  @return classic HRESULT
	*/
	HRESULT SendError  (const CATUnicodeString				&iMessage, 
						const CATKWEErrorSeverity::Severity	iSeverity	= CATKWEErrorSeverity::Error) const ;
      
	/**
     *   Validation of the object created after its modification in the PLM New.<br>
	 *   Default implementation returns OK.
     *   @param iObject
     *   Object to validate
     *   @param oErrorMessage
     *   Error message
     *   @return
     *  <ol>
     *    <li> E_INVALIDARG if iObject NULL or not recognized bu the factory.
     *    <li> S_OK if the validation of the object is OK
     *    <li> S_FALSE if the validation of the object is KO (an error message is filled)
     *  </ol>
     */
     virtual HRESULT ValidateModel( const CATICkeObject_var& iObject,CATUnicodeString &oErrorMessage) ;


	 /** 
	  * Retrieves the type to instanciate (by the name passed as third argument of instanciate Object
	  * @param typeName Name of the type of the object to create
	  * @param oType The type retrieved
   	  * @return
	  *  <ol>
 	  * 	 <li> S_FALSE if type not found
	  * 	 <li> S_OK	if the type has been found
	  *  </ol>
 	  */
	 HRESULT RetrieveTypeToInstanciate (const CATUnicodeString& typeName, CATIType_var &oType);

	 /**
     *   SuppressObject (remove an object or suppress an extension).<br>
	 *   Can be implemented or not.
     *   @param iObject
     *   Object to suppress or on which we want to suppress the extension.
     *   @param iType
     *   Type of the extension to suppress
	 *	 @param iContext the context of removal
	 *   @return
     *  <ol>
     *    <li> E_INVALIDARG if iObject NULL or not recognized bu the factory.
     *    <li> S_OK if the suppression of the object succeeded
     *    <li> E_ACCESSDENIED if iObject cannot be suppressed.
     *  </ol>
     */
     virtual HRESULT SuppressObject ( const CATICkeObject_var& iObject,const CATIType_var &iType,const CATCkeEvalContext *iContext) ;

	 /**
	 * Mode for creation (of PLM objects).
	 * In incremental mode:
	 * - the initialization of the object (thanks to BL) will be called by the incremental mode manager: don't call it
	 * - on extension type, "creation" means adding that extension on an already existing object: don't create a new reference object
	 * @param iTypeName
	 *   iTypeName queried on its support for incremental mode
	 * @return
	 *   S_OK incremental mode supported
	 *   S_FALSE incremental mode not supported
	 *   E_FAIL unable to decide ...
	 */
	 virtual HRESULT SupportIncrementalCreation(const CATUnicodeString& iTypeName);

	 /**
	 * Mode for creation (of PLM objects).
	 * In full mode:
	 * - the initialization of the object is to be called by the modeler: we won’t call it
	 * - on extension type, "creation" means adding that extension to a new object: you have to create a new reference object
	 * @param iTypeName
	 *   iTypeName queried on its support for incremental mode
	 * @return
	 *   S_OK full mode supported
	 *   S_FALSE full mode not supported
	 *   E_FAIL unable to decide ...
	 */
	 virtual HRESULT SupportFullCreation(const CATUnicodeString& iTypeName);
private:
 
  /**
   */
   CATDelegateInstanciationAdapter(const CATDelegateInstanciationAdapter&);
};


#endif
