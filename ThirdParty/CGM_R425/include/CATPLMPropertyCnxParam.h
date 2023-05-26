// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMPropertyCnxParam.h
// Header definition of CATPLMPropertyCnxParam
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2009  Creation: Code generated by the CAA wizard  xjt
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMPropertyCnxParam_H
#define CATPLMPropertyCnxParam_H

#include "CATPLMServicesItf.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------

/**
* String associated to PROP_DefaultCaseSensitivityForQuery.
* Used by default implementation of CATPLMProviderCapabilityAdapter::GetProperty
*/
extern ExportedByCATPLMServicesItf const CATUnicodeString PCP_DEFAULTCASESENSITIVITY; 

/**
* String associated to PROP_FullTextSearchAvailable.
* Used by default implementation of CATPLMProviderCapabilityAdapter::GetProperty
*/
extern ExportedByCATPLMServicesItf const CATUnicodeString PCP_ADVANCEDSEARCHACTIVATED; 

/**
* String associated to PROP_AcceptIrrelevantSearches .
* Used by default implementation of CATPLMProviderCapabilityAdapter::GetProperty
*/
extern ExportedByCATPLMServicesItf const CATUnicodeString PCP_ACCEPTIRRELEVANTSEARCHES; 

/**
* String associated to PROP_NameMapping.
* Used by default implementation of CATPLMProviderCapabilityAdapter::GetProperty
*/
extern ExportedByCATPLMServicesItf const CATUnicodeString PCP_NAMEMAPPING; 

#endif