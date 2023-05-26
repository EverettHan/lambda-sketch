#ifndef CATInstanciationContext_h
#define CATInstanciationContext_h


// COPYRIGHT DASSAULT SYSTEMES 2002
/** 
* @CAA2Level L1
* @CAA2Usage U1
*/


#include "CATLifSpecs.h"
 

#include "CATICkeParmFactory.h"
#include "CATICkeRelationForwards.h"
#include "CATICkeObject.h"
#include "CATListValCATICkeObject.h"
#include "CATSysBoolean.h"
class CATUnicodeString;
class CATIValue_var;

/**   
 * Class dedicated to instanciation management.
 * <b>Role</b>: When instanciating an object through CATIDelegateInstanciation, this class is used to pass some arguments.<br>
 * @see CATIDelegateInstanciation, CATICkeObject, CATICkeParmFactory
 */
class ExportedByCATLifSpecs CATInstanciationContext
{

public:

	/**
     * Constructor.
	 * @param plist list of parameters (potentially passed by the new function in EKL.
  	 * @param ipAdditionalProxies list of additional proxies passed by the PLM New. 
	 * Usually NULL. Additional proxies...
	 */
	CATInstanciationContext (const CATCkeListOfParm plist = NULL,
							 const CATICkeObject_var &iProxy = NULL_var,
							 const CATBoolean iLongTransaction = TRUE,
							 const CATLISTV(CATICkeObject_var) *ipAdditionalProxies = NULL);
	CATInstanciationContext(const CATCkeListOfParm plist,
		const CATICkeObject_var &iProxy,
		const CATBoolean iLongTransaction,
		const CATLISTV(CATICkeObject_var) *ipAdditionalProxies,
		const CATBoolean iFullCreationMode);

	/**
     * Destructor.
	 */
	virtual ~CATInstanciationContext ();

	/**
	 * Useless in CAA.<br>
     * Returns a string information.
	 * @return parameters converted as a string
	 */
	virtual CATUnicodeString StringInfo () const;

	/**
	 * Useless in CAA.<br>
     * Positions the container where the object is created.
	 * @param iCont becomes the current container
	 */
	void SetContainer (const CATICkeParmFactory_var &iCont);

	/**
     * Retrieves the container where the object has been created.
	 * @return current container retrieved
	 */
	CATICkeParmFactory_var RetrieveContainer () const;

	/** 
	 * Retrieves the list of parameters passed as argument of the new.
	 * Note that for performance purpose, the arguments starts at rank 4 if any
	 * @return liste of arguments
	 */
	CATCkeListOfParm  RetrieveArguments () const;

	/**
	 * Retrieves the proxy that must be used to copy attributes. 
	 * Can be NULL when called from the Knowledge language.
	 * Is not NULL when called from the PLM New UI. In this case, it contains a proxy.
	 * @return proxy
	 */
	CATICkeObject_var RetrieveProxy() const;

	/**
	 * Indicates if we require a short/long transaction creation for PLM objects. 
	 * @return TRUE if long transaction
	 */
	virtual CATBoolean LongTransaction () const;

	
	/**
	 * Retrieves the reference (or representation) to instanciate if any. 
	 * Can be NULL
	 * @return proxy
	 */
	CATICkeObject_var RetrieveReferenceToInsert() const;

	
	/**
	 * Retrieves the additional arguments to be passed to the implementation.<br>
	 * Must pass a rank (1 to N) AND a Name (in any case).<br>
	 * When called from the Knowledge language, the rank correspond to the additional arguments (in reality from 4 to N)
	 * When called from the PLM New UI, the name is used and it correspond to the name of the parameter added to the proxy.
	 * @param iRank
	 * Rank of the argument in the Knowledge language function
	 * @param iName
	 * Name of the parameter on the proxy
	 * @param oValue
	 * Value found
	 * @return
	 *  <ol>
	 * 	 <li> E_INVALIDARG if called without rank in Knowledge language context, or without name in PLM New context.
	 * 	 <li> S_FALSE	if the argument has not been found
	 * 	 <li> S_OK      if the argument has been found
	 *  </ol>
	 */
	HRESULT RetrieveArgument(const int iRank,const CATUnicodeString &iName,CATIValue_var &oValue) const;


	/**
	 * Returns a prefix used to add parameter on a proxy in order to avoid conflicts 
	 */
	static const char *PrefixToUseForParametersAddedOnProxy ();

	/**
	 * Retrieving additional proxies if any.
	 * @param iListToBeFilled
	 * List to be filled with proxies
	 */
	HRESULT RetrieveAdditionalProxies (CATLISTV(CATICkeObject_var) &iListToBeFilled) const;

	/**
	* Mode for creation.
	* In incremental mode:
	* - the initialization of the object (thanks to BL) will be called by the incremental mode manager: don't call it
	* - on extension type, "creation" means adding that extension on an already existing object: don't create a new reference object
	*
	* In full mode:
	* - the initialization of the object is to be called by the modeler: we won’t call it
	* - on extension type, "creation" means adding that extension to a new object: you have to create a new reference object
	*
	* @return
	*   S_OK incremental mode
	*   S_FALSE full mode
	*   E_FAIL unable to decide ...
	*/
	HRESULT IsIncrementalCreationMode() const;

private: 
	/**
     * Copy constructor.
	 * @param iCopy vontext copied
	 */
    CATInstanciationContext (const CATInstanciationContext &iCopy);

	CATICkeParmFactory_var _container;
	CATCkeListOfParm _plist; 
	CATICkeObject_var _proxy;
	CATBoolean _longTransaction;
	CATLISTV(CATICkeObject_var) *_piAdditionalProxies;
	CATBoolean _isFullCreationMode;
};

#endif
