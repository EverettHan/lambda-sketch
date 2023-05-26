#ifndef CATLISTPCATPLMREDataImportResultRecord_h
#define CATLISTPCATPLMREDataImportResultRecord_h
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* Project 2008 : Replication - Operation Manager
*/

/**  
 *  @level  Protected  
 *  @usage  U1  
 */ 

/**
 * @collection CATLISTP(CATPLMREDataImportResultRecord)
 * Collection class for pointers of import results records.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>QuickSort</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */


// Exported by module
#include "CATPLMIntegrationInterfaces.h"

#include "CATPLMREDataImportResultRecord.h"

// Clean previous functions requests
#include "CATLISTP_Clean.h"

// Require needed functions
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#define CATLISTP_QuickSort

// Get macros
#include "CATLISTP_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationInterfaces

CATLISTP_DECLARE( CATPLMREDataImportResultRecord )
typedef CATLISTP( CATPLMREDataImportResultRecord ) CATListPtrCATPLMREDataImportResultRecord;

#undef	CATCOLLEC_ExportedBy

#endif
