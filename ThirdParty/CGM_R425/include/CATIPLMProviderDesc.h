// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATIPLMProviderDesc.h
// Define the CATIPLMProviderDesc interface
//
//===================================================================
//
// Usage notes:
//   Define the CATIPLMProviderDesc interface
//
//===================================================================
//
//  May 2003  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMProviderDesc_H
#define CATIPLMProviderDesc_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMProviderDesc;
#else
extern "C" const IID IID_CATIPLMProviderDesc ;
#endif


class CATUnicodeString;
class CATPLMRepositoryName;
//------------------------------------------------------------------

/**
* Descriptors of the provider. Allows to use provider without instanciating the whole provider object.
*/
class ExportedByCATPLMServicesItf CATIPLMProviderDesc: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	
	/**
	*   Returns the provider type. 
  *   This type is the Plm Repository Name. Its format is on 4 characters. @see CATPLMRepositoryName
	*   @param  oType 
	*			provider type.
	*	@return
  *			Error code of function.
	*/    
	virtual HRESULT GetType( CATPLMRepositoryName * oType ) =0;
	
	/**
	*   Returns the provider display name.
	*   @param  oDisplayName
	*			provider display name.
	*	@return
    *			Error code of function.
	*/    
	virtual HRESULT DisplayName( CATUnicodeString **oDisplayName ) =0;
	
	/**
	*   Returns the provider logical instance id. May be null if multi site connection is not implemented.
  *   The Logical Instance Id is the Plm Repository location. @see CATPLMID_RepositoryLocation
	*   @param oLogicalInstanceId
	*			provider logical instance id.
	*	@return
    *			Error code of function.
	*/
	virtual HRESULT InstanceId(CATUnicodeString **oLogicalInstanceId) =0;

  /**
	*   Set the provider logical instance id.
  *   The Logical Instance Id is the Plm Repository location. @see CATPLMID_RepositoryLocation
	*   @param oLogicalInstanceId
	*			provider logical instance id.
	*	@return
    *			Error code of function.
	*/
	virtual HRESULT SetInstanceId(CATUnicodeString *iLogicalInstanceId) =0;
};

//------------------------------------------------------------------

#endif
