// COPYRIGHT Dassault Systemes 2007
// Author TVQ 

#ifndef CATKwePLMCustomizationServices_H
#define CATKwePLMCustomizationServices_H

#include "CATLISTV_CATBaseUnknown.h"
#include "CATLifBRules.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListValCATICkeParm.h"
#include "CATIType.h"
#include "CATBoolean.h"


class CATIPLMComponent_var;
class CATIInstance_var;
class CATICkeParm_var;
class CATBRuleImplementation;
class CATCkePLMNavServicesForCoexistence;

/** This class of services contains various methods to ease the use of customization rules in different contexts             
 *  It is more focused on customization rules that need to create an object, similar to a modeler object, but non persistant 
 *  (like it is requested in the PLM New, where we want to valuate attributes without having created the PLM object
 *  These services rely on an implementation of CATIInstance called VolatileInstance (for non persistant).
 *  Such a volatile instance can be created from a Knowledge type
 *    - In this context, we fill the attributes defined on this type and its ancestors, with a default value, considered as Unset
 *  Or it can be created from another instance (especially useful in duplication contexts)
 *    - In this case, we duplicate the attributes of the instance on the new volatile instance
 *  Finally, a VolatileInstance implements CATIDynamicAttributes, which means that dynamicallt, attributes can be added on it
 *  (for example, in the customization rules context by using the SetAttribute*** methods in the Enterprise Knowledge language.
 */

class ExportedByCATLifBRules CATKwePLMCustomizationServices
{
public:
	/**
	* This method creates a volatile object that implements CATIInstance from an existing instance. 
	* If iType is specified, it is used as the type for the new instance. Otherwise, the type is retrieved on provided instance (CATIInstance::Type)	
	* All attributes available on provided instance main type are available on created instance, with proper values and properties (read only state, manipulator)
	* Note that computed attributes are not copied.
	* If in new typing system, we also copy the deployment extension
	* If last argument is set to true, we are also copying all the extensions
	* The method fails (returns E_FAIL) if provided instance is NULL
	*/
	static HRESULT CreateVolatileInstanceFromInstance(const CATIInstance_var &iInstance, const CATIType_var &iType, CATIInstance_var &oInstance,CATBoolean iCopyAlsoExtensions=FALSE);

	/**
	* This method creates a volatile object that implements CATIInstance from a type definition. 
	* All attributes available on provided type are available on created instance, with proper properties (read only state)
	* The attributes are initially unset. Note that computed attributes are not copied.
	* The last argument contains a list of attributes values to initialise on the volatile object. It can contain values for read only attributes that 
	* cannot be modified afterwards. The values are volatile parameters which name is the attribute name.
	* This list can be built through a service like CATCkeObjectAttrWriteServices::CreateListOfValuesFromListOfStrings
	* By default, there is no defaut values. The content of the list will be copied. The pointer is not deallocated by the callee

	* The method fails (returns E_FAIL) if provided type is NULL
	*/
	static HRESULT CreateVolatileInstanceFromType(const CATIType_var &iType, CATIInstance_var &oInstance,CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL);

	/**
	* This method enable to test if a parameter supports a given type. 
	* Returns 1 if iParameter type is a kind of iType, 0 if not.
	* works on any parameter (value (persistent or volatile), object with multi typing, list, pointer)
	*/
	static int IsaKindOf(const CATICkeParm_var& iParameter, const CATIType_var& iType);


	/**
	 * Extends a proxy with a type and its associated values
	 * Is the equivalent of a CreateExtension on PC2 object. 
	 * Is not the equivalent of SetDiscipline: nothing is done regarding V_Discipline valuation. Use ExtendProxyWithDiscipline instead
	 * But if the extension has associated extensions they are added also (cascading)
	 * @param pListDefaultAttributeValues
	 * List of default values for the attributes (usually NULL)
	 * By default the attributes are filled with the default values coming from Metadata
	 * Do not pass V_discipline attribute !!!
	 * There is no check that the attributes are hold by the extension type
	 * Returns S_FALSE if type already supported
	 */
	static HRESULT ExtendProxyWithType (const CATIInstance_var &iProxy,const CATIType_var &iType,CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL);


	/**
	* This method creates a volatile object that implements CATIInstance from a type definition. It adds automatically an extension, if declared.
	* All attributes available on provided type are available on created instance, with proper properties (read only state)
	* The attributes are initially unset. Note that computed attributes are not copied.
	* The last argument contains a list of attributes values to initialise on the volatile object. It can contain values for read only attributes that 
	* cannot be modified afterwards. The values are volatile parameters which name is the attribute name.
	* This list can be built through a service like CATCkeObjectAttrWriteServices::CreateListOfValuesFromListOfStrings
	* By default, there is no defaut values. The content of the list will be copied. The pointer is not deallocated by the callee

	* The method fails (returns E_FAIL) if provided type is NULL
	*/
	static HRESULT CreateExtendedVolatileInstanceFromType(const CATIType_var &iType, CATIInstance_var &oInstance,CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues = NULL,const CATIType_var & typeDiscipline = NULL_var,
															CATBoolean iAuthorizeModificationOfReadOnlyAttributes = FALSE);

	/**
	* This method creates a volatile object that is a PLMEntity (no particular type precised. So Feature is used by default).<br>
	* It is used to model fake contextual objects to pass to business rules as parameters.
	* Instance created in output.
	*/
	static HRESULT CreateVolatilePLMEntity (CATIInstance_var &oInstance);

	/** 
	 * Propagates some information from the fact to the BR context
	 * @param
	 * iThisObject the fact
	 * @param
	 * iBRContext the business rule context
	 * @param
	 * iCustoType TRUE to propagate the custo type
	 * @param
	 * iDiscipline TRUE to propagate the discipline value
	 * @param
	 * iPolicy TRUE to propagate the policy value
	 * @result
	 * E_INVALIDARG if bad input, E_FAIL if fail, S_OK if OK
	 */
	static HRESULT PropagateFactAttributeToBRContext (const CATIInstance_var &iThisObject,const CATIInstance_var &iBRContext,CATBoolean iCustoType,CATBoolean iDiscipline,CATBoolean iPolicy=FALSE);

	/**
	 * Extends a proxy with a type and its associated values. Valuates V_Discipline
	 * Is the equivalent of a SetDiscipline on PC2 object. 
	 * if the extension has associated extensions they are added also (cascading)
	 * Returns S_FALSE if type already supported
	 * Returns E_INVALIDARG, if type is not a discipline or not a a posteriori discipline
	 */
	static HRESULT ExtendProxyWithDiscipline (const CATIInstance_var &iProxy,const CATIType_var &iType);

	
	/**
	* This method creates a volatile object that is a VolatileInstance.<br>
	* It is used to model fake contextual objects to pass to business rules as parameters.
	* Where business rules will be able to add any kind of extensions on it
	* Instance created in output.
	*/
	static HRESULT CreateUnconstrainedVolatileInstance (CATIInstance_var &oInstance);

protected:
	static HRESULT _CreateVolatileInstanceFromTypeInternal (const CATIType_var &iType, CATIInstance_var &oInstance,CATLISTV(CATICkeParm_var) *pListInitialAttributeValues = NULL,CATBoolean iAuthorizeModificationOfReadOnlyAttributes = FALSE);

	friend class CATBRuleImplementation;
	friend class CATCkePLMNavServicesForCoexistence;
	friend class CATCkePLMNavServices;

private:
	static HRESULT CreateAttributesParms(const CATBoolean isPLM,const CATIInstance_var &iComponent, const CATIType_var &iType, CATLISTV(CATBaseUnknown_var) &attrs,
															  CATListOfCATUnicodeString *lName=NULL,CATBoolean acceptPointers = FALSE);
	static HRESULT FillDefaultValues (CATLISTV(CATBaseUnknown_var) &attrs,
									  CATListOfCATUnicodeString *lName,
									 CATLISTV(CATICkeParm_var) *pListDefaultAttributeValues) ;

	CATKwePLMCustomizationServices();	
	CATKwePLMCustomizationServices(const CATKwePLMCustomizationServices &);	
	CATKwePLMCustomizationServices & operator=(const CATKwePLMCustomizationServices &);
	~CATKwePLMCustomizationServices();	


};

//-------------------------------------------------------------------------

#endif
