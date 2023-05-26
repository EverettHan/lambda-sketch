// COPYRIGHT DASSAULT SYSTEMES  2003
//=============================================================================
//
// CATCkeLanguageServices.h:
//
//=============================================================================
// Usage Notes:
//
// See below
//
// 
//
//
//=============================================================================
// 15/12/98   Creation                                   T. Videcoq
//=============================================================================

/**
* This class contains services that corresponds to functions in EKL language that we want to make available for others.
*/

#ifndef CATCkeLanguageServices_H 
#define CATCkeLanguageServices_H 

#include "CATLifLibrary.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h" 
#include "CATListValCATIType.h"
#include "CATICkeObject.h"
#include "CATListValCATICkeParm.h"
#include "CATListValCATICkeObject.h"

class CATInstanciationContext;
class CATCkeEvalContext;
class CATICkeSolve_var;
class CATIInstanciation_var;
class CATIType_var;
class CATBRExtraParameters;

class ExportedByCATLifLibrary CATCkeLanguageServices 
{
public:
	
	/**
	* Equivalent of the Update method on an object in the language. <br>
	* works on rule base, optimizations, part (update), assembly (update), mechanical feature (update) <br>
	* The call to this method may raise evaluation error that need to be catched. <br>
	* Do not test if the object is NULL (means not solvable). It will raise an evaluation error.
	* @param iObjectToSolve
	* Object to solve, can be NULL_var if it is not solvable (will return E_INVALIDARG)
	* @param pIEvalcontext
	* Evaluation context. May be NULL
  	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the solve
	*    <li> E_INVALIDARG if the object in input is NULL (not solvable)
	*    <li> E_ACCESSDENIED if the solve has failed due to licensing considerations. 
	*    <li> S_OK if the solve is completed
	*  </ol>
	*/
	static HRESULT  Solve (const CATICkeSolve_var &iObjectToSolve,const CATCkeEvalContext *pIEvalcontext);

	/**
	* Equivalent of the new function in the language. <br>
	* Creates an object from its type, its name and its father <br>
	* @param NewOrUpdate
	* TRUE if we want to force the creation of the object
	* FALSE if we want either to create if it does not exist or to do nothing. The test to see if it already exist consists in finding a child with same type and same name.
	* @param NewOrAddExtension
	* TRUE if we are in a New context, FALSE if we are in an AddExtensionContext
	* @param iTypeToCreate
	* Type of the object to create
	* @param iName
	* Nale of the object may be ""
	* @param iFather
	* Father of the object may be NULL
	* @param NewObject
	* Object in output
	* @param iErrorMsg
	* Error message to raise if the new fails
	* @param pIEvalcontext
	* Evaluation context. May be NULL
	* @param pIInstanciationContext
	* Instanciation context. May be NULL
	* @param iPLMProxy
	* PLMProxy to use to valuate attribute. If you precise a PLM Proxy, pIInstanciationContext MUST BE NULL to be taken into account
  	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the new
	*    <li> E_INVALIDARG if type is empty or is not instanciable
	*    <li> E_ACCESSDENIED if the new has failed due to licensing or editability
	*    <li> S_OK if the new has succeded
	*  </ol>
	*/ 
	static HRESULT  New   ( CATBoolean NewOrUpdate,
							CATBoolean NewOrAddExtension,
							const CATUnicodeString &iTypeToCreate,
							const CATUnicodeString &iName,
							const CATBaseUnknown_var &iFather,
							CATICkeObject_var &NewObject, 
							const char *iErrorMsg,
							const CATCkeEvalContext *pIEvalcontext, 
							const CATInstanciationContext* pIInstanciationContext,
							const CATICkeObject_var &iPLMProxy = NULL_var);


	// A partir d'une chaine en entree, correspondant a un type, on retrouve 3 choses
	// - la fonction d'instanciation soit sous la forme d'un CATIInstanciation soit par un nom de classe sur laquelle on va appeler CATIDelegateInstanciation (les 2 s'excluent)
	// - le type Knowledge correspondant a ce qui est cree. Soit c'est le type donc le nom est la chaine en entree. Soit c'est le type de l'objet cree equivalent
	// On retourne une info dont on va se servir.
	// RC = 1 signifie qu'on n'a pas reconnu du tout le type
	// RC = 2 signifie qu'on a un type non instanciable

	// A noter que le type appelé concret rendu est le type INSTANCE
	static int FindInstanciatorOfType (const CATUnicodeString &typeS,CATIType_var &typeConcret,CATIInstanciation_var &InstanciationMethod,CATUnicodeString &InstanciationFonction);

	/**
	* This method lists all the sub types of a type, that can be created from the New.<br>
	* @param iTypeOrigin
	* Type from which we start to find the sub types
	* @param olListOfSubTypes
	* list of types filled by the method. It is emptied at the beginning of the method. Contains the sub types
  	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured 
	*    <li> E_INVALIDARG if type is empty 
	*    <li> S_OK if the service has succeeded
	*  </ol>
	*/
	static HRESULT ListNewableSubtypes (const CATIType_var &iTypeOrigin, CATListValCATIType_var& olListOfSubTypes) ;
	
	/**
	* Equivalent of the new function in the language. <br>
	* Creates an object from its type, its name and its father <br>
	* @param NewOrAddExtension
	* TRUE if we are in a New context, FALSE if we are in an AddExtensionContext
	* @param iTypeToCreate
	* Type of the object to create
	* @param iName
	* Nale of the object may be ""
	* @param iFather
	* Father of the object may be NULL
	* @param NewObject
	* Object in output
	* @param iErrorMsg
	* Error message to raise if the new fails
	* @param pAdditionalParameters
	* Additional parameters to be passed (corresponding to arguments 4 to N of the new in the language)
  	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the new
	*    <li> E_INVALIDARG if type is empty or is not instanciable
	*    <li> E_ACCESSDENIED if the new has failed due to licensing or editability
	*    <li> S_OK if the new has succeded
	*  </ol>
	*/ 
	static HRESULT  NewForModelers   ( CATBoolean NewOrAddExtension,
							const CATUnicodeString &iTypeToCreate,
							const CATUnicodeString &iName,
							const CATBaseUnknown_var &iFather,
							CATICkeObject_var &NewObject, 
							const char *iErrorMsg,
							const CATLISTV(CATICkeParm_var) *pAdditionalParameters = NULL);

	/**
	* Equivalent of the RemoveExtension or Delete function in the language. <br>
	* Suppresses an object or remove an extension of a given type on an objectr <br>
	* @param DeleteOrRemoveExtension
	* TRUE if we are in a Delete context, FALSE if we are in an DeleteExtensionContext
	* @param iObject
	* Object to delete, or object where we want to remove an extension
	* @param iTypeOfExtension
	* Type of the extension 
	* @param iErrorMsg
	* Error message to raise if the delete or remove extension fails
  	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the delete or remove extension
	*    <li> E_INVALIDARG if object is empty 
	*    <li> E_ACCESSDENIED if the Delete or the removeExtension has failed due to licensing or editability
	*    <li> S_OK if the Delete or RemoveExtension has succeded
	*  </ol>
	*/ 
	static HRESULT  DeleteForModelers   ( CATBoolean DeleteOrRemoveExtension,
							const CATICkeObject_var &iObject,
							const CATIType_var &iTypeOfExtension,
							const char *iErrorMsg);
 
	/**
	* Equivalent of the Delete or RemoveExtension function in the language. <br>
	* Deletes an object pr Remove an extension on an object.<br>
	* @param DeleteOrRemoveExtension
	* TRUE if we want to delete the objet, FALSE if we want to remove an extension.
	* @param iErrorMsg
	* Error message to raise if the delete or add extension fails fails
	* @param iObject
	* Object to delete, or object where we want to remove an extension
	* @param iTypeOfExtension
	* Type of the extension 
	* @param pIEvalcontext
	* Evaluation context. May be NULL
	* @param pIInstanciationContext
	* Instanciation context. May be NULL
	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the delete or remove extension
	*    <li> E_INVALIDARG if object is empty 
	*    <li> E_ACCESSDENIED if the Delete or the removeExtension has failed due to licensing or editability
	*    <li> S_OK if the Delete or RemoveExtension has succeded
	*  </ol>
	*/ 
	static HRESULT  Delete   (  CATBoolean DeleteOrRemoveExtension,
							const CATICkeObject_var &iObject,
							const CATIType_var &iTypeOfExtension,
							const char *iErrorMsg,
							const CATCkeEvalContext *pIEvalcontext);

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
	* Calls the Knowledge protocol to create a PLM object and initializes it with attributes initialization business logics<br>
	* Creates an object from its main type or secondary type<br>
	* @param iPrimaryType
	* Typename of the primary type of the object to create
	* @param iSecondaryType
	* Typename of the secondary type of the object to create
	* @param ilExtensionTypes
	* List of typenames of extensions to add to the object to create
	* @param iFather
	* Aggregator of the object to create (may be NULL)
	* @param oNewObject
	* Object in output. When creating a reference or a representation under an aggregating reference, the instance is returned
	* @param pAdditionalParameters
	* Extra parameters as received from the "new" EKL function so NOT the first 3 parameters (may be NULL)
	* @param piExtraParameters
	* Parameters to be used in attributes initialization business logics (may be NULL)
	* @return
	*  <ol>
	*    <li> E_FAIL if an error occured during the new
	*    <li> S_OK if the new has succeded
	*  </ol>
	*/ 
	static HRESULT  NewPLMObjectWithInitialization ( const CATUnicodeString &iPrimaryType,
		const CATUnicodeString &iSecondaryType,
		const CATListOfCATUnicodeString& ilExtensionTypes,
		const CATBaseUnknown_var& iFather,
		CATICkeObject_var& oNewObject,	
		const CATLISTV(CATICkeParm_var) *pAdditionalParameters = NULL,
		const CATBRExtraParameters * piExtraParameters = NULL);

};

#endif
