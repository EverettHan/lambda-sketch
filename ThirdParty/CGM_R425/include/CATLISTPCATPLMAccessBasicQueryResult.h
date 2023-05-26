#ifndef INCL_CATLISTPCATPLMAccessBasicQueryResult_h
#define INCL_CATLISTPCATPLMAccessBasicQueryResult_h
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004

/**  
 *  @level  Protected  
 *  @usage  U1  
 */ 

/**
 * @collection CATLISTP(CATPLMAccessBasicQueryResult)
 * Collection class for pointers to PLM  Basic Query result.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATPLMIntegrationAccess.h"

class CATPLMAccessBasicQueryResult;

// Clean previous functions requests
#include "CATLISTP_Clean.h"
// Require needed functions
#define CATLISTP_Append
#define CATLISTP_RemoveAll
// Get macros
#include "CATLISTP_Declare.h"
// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationAccess

class CATPLMAccessBasicQueryResult ;

CATLISTP_DECLARE( CATPLMAccessBasicQueryResult)

#undef	CATCOLLEC_ExportedBy

#endif
