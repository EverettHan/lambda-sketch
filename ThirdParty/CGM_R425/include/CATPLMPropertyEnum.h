// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMPropertyEnum.h
// Define the enums used in CATIPLMCompProviderFeatureService
//
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMPropertyEnum_H
#define CATPLMPropertyEnum_H

#include "CATPLMServicesItf.h"

/**
 * List of possible properties to ask to providers.
 * The CATOmxAny returned can be of various type. @see CATOmxAny 
 */
enum ExportedByCATPLMServicesItf CATPLMPropertyEnum
{
/**
 * Returns the default case sensitivity.
 * Possible values of oValue are :
 *    omx_identifier : "CaseSensitive" (default)
 *    omx_identifier : "CaseInsensitive"
 */
  PROP_DefaultCaseSensitivityForQuery       = 0
/**
 * Returns the default Full Text Search Avalaibility.
 * Possible values of oValue are :
 *    omx_identifier : "No" (default)
 *    omx_identifier : "Yes"
 */
 ,PROP_FullTextSearchAvailable              = 1
/**
 * Returns if the server accepts irrelevant search or not.
 * query 'always true' : WHERE T0.PLMExternal_Id LIKE '*' or without WHERE clause
 * Possible values of oValue are :
 *    omx_identifier : "Yes" (default)
 *    omx_identifier : "No"
 */
 ,PROP_AcceptIrrelevantSearches             = 2
/**
 * Returns if the server use a mapping to implement the dictionary.
 * Possible values of oValue are :
 *    omx_identifier : "Yes" (default)
 *    omx_identifier : "No"
 */
 ,PROP_NameMapping                          = 3};

#endif
