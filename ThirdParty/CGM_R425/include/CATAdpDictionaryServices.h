// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATAdpDictionaryServices.h
// Header definition of CATAdpDictionaryServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2005  Creation: Code generated by the CAA wizard  PMM
//===================================================================
/**
* @CAA2Level L1
* @CAA2Usage U1  
*/
#ifndef CATAdpDictionaryServices_H
#define CATAdpDictionaryServices_H

#include "CATPLMIntegrationAccess.h"

#include "CATBoolean.h"
#include "IUnknown.h"

class CATUnicodeString ;
class CATListValCATUnicodeString;
class CATListValCATString;
class CATString;
class CATIAdpEnvironment;
class CATListPtrCATBaseUnknown ;


//-----------------------------------------------------------------------

/**
* Class to manage PLM dictionary.
*
* <br><b>Role</b>: This class provides all basic functions to browse and navigate on PLM dictionaries
* A repository contains many environments.
* In a repository, can be declared differents modelers.
* The types of differents modelers are describe in metadata files. 
*/
class ExportedByCATPLMIntegrationAccess CATAdpDictionaryServices
{
public:
   
  /**
  * Gets the available environments.
  *
  * <br><b>Role</b>: This method provides the different available environments.
  *
  * @param  iRepository 
	*			The repository name.
  * @param oEnvId [out]
  *   The environment name list. When calling method, this list should be empty.
  * @param oEnvAlias [out]
  *   The environment display name list.When calling method, this list should be empty.
  *
  * @return
  * <dt> <code>S_OK</code>     <dd> At least one environment is available.
  * <dt> <code>S_FALSE</code>  <dd> No environment available.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  *
  */
  static HRESULT ListEnvironments( const char * iRepository,
                                   CATListValCATString & oEnvId, 
                                   CATListValCATUnicodeString & oEnvAlias);
  
  /**
  * Retrieves an environment by its name. 
  *
  * <br><b>Role</b>: This will result in the loading of the corresponding modelers describe in the metadata file.
  *
  * @param  iRepository 
	*			The repository name.
  * @param iEnvId [in]
  *   The environment name.
  * @param oEnvironment [out, CATBaseUnknown#Release]
  *   The loaded environment. Release the pointer when useless.
  *
  * @return
  *     <dt><code>S_OK</code></dt>
  *      <dd> The provided environment was successfully loaded.</dd>
  *     <dt><code>E_FAIL</code> </dt>
	*     <dd>A problem occurs during the operation. 
  *
  */
  static HRESULT GetEnvironment( const char * iRepository,
                                 const CATString & iEnvId, 
                                 CATIAdpEnvironment ** oEnvironment );


/**
  * @deprecated R213 Use CATITypeDictionary#ListTypesForPackage instead  <br>
  * Gets the available modelers.
  *
  * <br><b>Role</b>: this method provides the different available modelers.
  *
  * @param  iRepository 
	*			The repository which load the modeler from.
  * @param oModId [out]
  *   The modeler name list. When calling method, this list should be empty.
  * @param oModAlias [out]
  *   The modeler display name list.When calling method, this list should be empty.
  *
  * @return
  * <dt> <code>S_OK</code>     <dd> At least one modeler is available.
  * <dt> <code>S_FALSE</code>  <dd> No modeler available.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  *
  */
  static HRESULT ListModelers( const char * iRepository,
                               CATListValCATString & oModId, 
                               CATListValCATUnicodeString & oModAlias);
  

  /**
  * @deprecated R213 Use CATITypeDictionary#ListTypesForPackage instead  <br>
  * Retrieves the modeler identified through the provided identifier. 
  * <br><b>Role</b>: This will result in the loading of the corresponding modeler.
  *
  * @param  iRepository 
	*			The repository which load the Modeler from.
  * @param iModId [in]
  *   The modeler name.
  * @param oTypes [out]
  *   The types of components that can be examined in this modeler. Release the returned objects when useless.
  *
  * @return
  *     <dt><code>S_OK</code></dt>
  *     <dd> The provided modeler was successfully loaded.</dd>
  *     <dt><code>E_FAIL</code> </dt>
	*     <dd>Failure. A problem occurs during the operation.</dd>
  *
  */
	static HRESULT GetModeler(const char * iRepository,
                            const CATString & iModId, 
                            CATListPtrCATBaseUnknown & oTypes);

};

//-----------------------------------------------------------------------

#endif