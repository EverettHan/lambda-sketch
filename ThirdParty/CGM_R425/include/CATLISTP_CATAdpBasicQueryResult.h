#ifndef INCL_CATLISTPCATAdpBasicQueryResult_h
#define INCL_CATLISTPCATAdpBasicQueryResult_h
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**  
 *  @level  Protected  
 *  @usage  U1  
 */ 

/**
 * @collection CATLISTP(CATPLMBasicQueryResults)
 * Collection class for pointers to PLM  Basic Query result.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATPLMIntegrationAccess.h"

class CATAdpBasicQueryResult;

// Clean previous functions requests
#include "CATLISTP_Clean.h"
// Require needed functions
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
// Get macros
#include "CATLISTP_Declare.h"
// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationAccess

class CATAdpBasicQueryResult ;

CATLISTP_DECLARE( CATAdpBasicQueryResult)

#undef	CATCOLLEC_ExportedBy

#endif
