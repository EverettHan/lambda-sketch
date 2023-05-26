/**
* @level Protected
* @usage U1
*/
#ifndef INCL_CATListPtrCATIPLMRecordRead_h
#define INCL_CATListPtrCATIPLMRecordRead_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @collection CATLISTP(CATIPLMRecordRead)
 * Collection class for pointers to <tt>CATIPLMRecordRead</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMRecordRead
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Locate
#define CATLISTP_InsertAt
#define CATLISTP_AppendList
// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(CATIPLMRecordRead) type.
#include "CATIPLMRecordRead.h"
CATLISTP_DECLARE( CATIPLMRecordRead )

#endif
