/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATLISTP_CATAdpQueryResult_h
#define CATLISTP_CATAdpQueryResult_h

/**
 * @CAA2Level L1 
 * @CAA2Usage U1 
 */

/**
 * @collection CATLISTP(CATAdpQueryResult)
 * Collection class for @href CATAdpQueryResult .
 * Only the following methods of are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

// Clean previous functions requests
#include  "CATLISTP_Clean.h"

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveAll

// Get macros
#include  "CATLISTP_Declare.h"

// Define the NT DLL export macro
#include "CATPLMIntegrationAccess.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIntegrationAccess

// Declare the CATLISTP(XXX) type.
#include "CATAdpQueryResult.h"
CATLISTP_DECLARE(CATAdpQueryResult)

#endif
