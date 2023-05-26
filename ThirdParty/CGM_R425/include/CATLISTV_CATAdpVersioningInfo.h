#ifndef INCL_CATLISTVCATAdpVersioningInfo_h
#define INCL_CATLISTVCATAdpVersioningInfo_h
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**  
 *  @level  Protected  
 *  @usage  U1  
 */ 

/**
 * @collection CATLISTV(CATAdpVersioningInfo)
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATPLMIntegrationAccess.h"

#include "CATAdpVersioningInfo.h"

// Clean previous functions requests
#include "CATLISTV_Clean.h"
// Require needed functions
#define CATLISTV_Append
#define	CATLISTV_AppendList
#define	CATLISTV_InsertAt
#define	CATLISTV_neOP
// Get macros
#include "CATLISTV_Declare.h"
// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationAccess

CATLISTV_DECLARE( CATAdpVersioningInfo)

#undef	CATCOLLEC_ExportedBy

#endif
