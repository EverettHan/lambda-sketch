#ifndef CATListPtrCATIPLMComponent_h
#define CATListPtrCATIPLMComponent_h
//===================================================================
// COPYRIGHT Dassault Systemes 2003
//===================================================================

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
* @CAA2Level L1 
* @CAA2Usage U1
*/

/**
 * @collection CATLISTP(CATIPLMComponent)
 * Collection class for pointers to <tt>CATIPLMComponent</tt>.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>InsertAt</tt></li>
 * <li><tt>ReSize</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMComponent
 */


// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Locate
#define CATLISTP_AppendList
#define CATLISTP_InsertAt
#define CATLISTP_ReSize

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATPLMIdentificationAccess.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMIdentificationAccess

// Declare the CATLISTP(CATPLMRelation) type.
#include "CATIPLMComponent.h"
CATLISTP_DECLARE( CATIPLMComponent )

#endif
