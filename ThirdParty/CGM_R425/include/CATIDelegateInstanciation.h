#ifndef CATIDelegateInstanciation_h
#define CATIDelegateInstanciation_h

// COPYRIGHT DASSAULT SYSTEMES 2001

/** 
* @CAA2Level L1
* @CAA2Usage U4 CATDelegateInstanciationAdapter
*/


// inherited class 
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h" 

// load module
#include "CATLifSpecs.h"
#include "CATIForwardsDecl.h"

#include "CATICkeObject.h"
class CATInstanciationContext;
class CATICkeObject_var;
class CATCkeEvalContext;


// OLE IID
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIDelegateInstanciation;
#else
extern "C" const IID IID_CATIDelegateInstanciation;
#endif

/**
 * CATIDelegateInstanciation allows several types to use the same instanciation function.<br>
 * The CATIType created by CATITypeDictionary can specify the name of a class which implements CATIDelegateInstanciation.<br>
 * The purpose of the implementation is to create objects from their type. The implementation must also implement CATICreateInstance.<br>
 * This instantiation method will be called from the Knowledge language with the function "new"
 * or from the PLM New panel (the instanciation context will then carry a proxy). <br>
 * <p><b>BOA information</b>: this interface CAN be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 *
 * @see CATIType, CATITypeDictionary, CATICkeObject, CATInstanciationContext
 */
class ExportedByCATLifSpecs CATIDelegateInstanciation : public CATBaseUnknown
{
public :

	/**
	 * Creates an instance oInstanciated, of type iTypeName, in owner iOwner, and named iName.<br>
	 * This method must be implemented by the application.
	 * @param iOwner the object that will aggregate the object to create
	 * @param iName the name of the object to create
	 * @param iTypeName the name of the type of the object to create
	 * @param oInstanciated the object created
	 * @param iContext the context of instanciation
	 * @return classic HRESULT
	 */
	virtual HRESULT InstanciateObject ( const CATICkeObject_var & iOwner, const CATUnicodeString& iName, const CATUnicodeString& iTypeName, CATICkeObject_var & oInstanciated,const CATInstanciationContext *iContext ) = 0;

	/**
     *   Validation of the object created after its modification in the PLM New.<br>
	 *   It is not mandatory to implement this method.<br>
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
     virtual HRESULT ValidateModel( const CATICkeObject_var& iObject,CATUnicodeString &oErrorMessage) =0;

	 /**
     *   SuppressObject (removes an object or suppresses an extension).<br>
	 *   It is not mandatory to implement this method.<br>
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
     virtual HRESULT SuppressObject ( const CATICkeObject_var& iObject,const CATIType_var &iType,const CATCkeEvalContext *iContext) =0;

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
	 virtual HRESULT SupportIncrementalCreation(const CATUnicodeString& iTypeName) = 0;

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
	 virtual HRESULT SupportFullCreation(const CATUnicodeString& iTypeName) = 0;

private:
  CATDeclareInterface;
}; 

CATDeclareHandler(CATIDelegateInstanciation, CATBaseUnknown);

#endif
