// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCkePLMNavCustoAccessServices.h
// Header definition of CATCkePLMNavServices
//
//===================================================================
//
// Usage notes:
// Provides services for accessing custo types specific information
//
// NOBODY should use those services except AdvancedSearch
// NOBODY should use those services except AdvancedSearch
// NOBODY should use those services except AdvancedSearch
// NOBODY should use those services except AdvancedSearch
// NOBODY should use those services except AdvancedSearch
// NOBODY should use those services except AdvancedSearch
//
//===================================================================


/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#ifndef CATCkePLMNavCustoAccessServices_H 
#define CATCkePLMNavCustoAccessServices_H

// Module export
#include "CATCkePLMNavCustoAccessPublicServices.h"
#include "CATCkePLMTypeAttrServices.h"
#include "CATListValCATIType.h"

class CATIType_var;
class CATIAdpType;
class CATIAdpEnvironment;
 



/**
 * Services enabling the access to custo types in particular (in addition with other types).<br> 
 * Those services are made available to Advanced Search because they want to introspect types whatever their nature (V1, V2)
 * NOBODY should use it except advanced search
 * NOBODY should use it except advanced search
 * NOBODY should use it except advanced search
 * NOBODY should use it except advanced search
 * NOBODY should use it except advanced search
 *
 * @see CATCkePLMNavCustoAccessPublicServices, CATIType, CATAttributeInfos, CATCkePLMNavCustoAccessPublicServices, CATCkePLMNavPublicServices.
 */
class ExportedByPLMDictionaryNavServices CATCkePLMNavCustoAccessServices : public CATCkePLMNavCustoAccessPublicServices
{

  public: 

	  
	   
   	  /**
	  * This service is used to retrieve from a custo type, the type that must be used to call query services (like CATAdpQueryServices). It works in V1 and in V2.<br>
	  * In V1 it will access the custo type and retrieve it. In V2, it will return the same type.<br>
	  * @param iType
      * CustoTypeInInput
	  * @param oTypeForQuery
	  * The type that must be used to give to query services. An AddRef is done
	  * @return
	  *  <ol>
	  * 	 <li> E_INVALIDARG if the type is NULL
	  * 	 <li> S_OK	if the type has been found
	  * 	 <li> E_FAIL if no queryable type found
	  *  </ol>
	  */
  	   static HRESULT RetrieveCustoTypeForQuery  (const CATIType_var &iType,CATIAdpType *&oTypeForQuery);
  
	   /**
	  * This service is used to retrieve the custo types can be created) types in a given package. It works in V1 and in V2.<br>
	  * @param iType
      * Type in input
	  * @param oListSearchableSubTypes
	  * The list is filled by the service
	  * @return
	  *  <ol>
	  * 	 <li> E_INVALIDARG if the package is not found
	  * 	 <li> S_OK	if the list of types is retrieved and is not empty
	  * 	 <li> S_FALSE if no type found 
	  *  </ol>
	  */
	   static HRESULT ListCustoSubTypes	( const CATIType_var & iPrimaryType,
										  CATListValCATIType_var & oListSearchableSubTypes);

	 
	   /** 
	  * This service is used to retrieve the list of possible secondary searchable types (extensions) that can exist on an object of a given type. It works in V1 and in V2.<br>
	  * Advanced Search functionality will use this service to propose an advanced search on extensions.<br>
	  * The type in input can be a custo type, a functional specialization or a modeler type. It cannot be an extension
	  * @param ipiEnv	
	  * The environment. Usually null(interpreted as “current environment”)
	  * @param iPrimaryType
      * primary type
	  * @param oListSecondaryTypes
	  * The list is filled by the service
	  * @return
	  *  <ol>
	  * 	 <li> E_INVALIDARG if the type is NULL
	  * 	 <li> S_OK	if the list of types is retrieved and is not empty
	  * 	 <li> S_FALSE if no secondary type found 
	  *  </ol>
	  */
	   static HRESULT ListPossibleSecondaryTypesForAnyType(  const CATIAdpEnvironment * ipiEnv,
														     const CATIType_var & iPrimaryType,
														     CATListValCATIType_var & oListSecondaryTypes);
};



//-----------------------------------------------------------------------

#endif
