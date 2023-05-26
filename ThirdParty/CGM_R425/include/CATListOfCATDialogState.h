#ifndef CATListOfCATDialogState_h
#define CATListOfCATDialogState_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATDialogState)
 * Collection class for pointers to <tt>CATDialogState</tt>.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>Locate</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATDialogState
 */

#include "CATLISTP_Clean.h"

#define	CATLISTP_Append
#define	CATLISTP_RemovePosition
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define	CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATDialogState;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATDialogEngine

CATLISTP_DECLARE(CATDialogState)

#define CATListOfCATDialogState CATLISTP(CATDialogState)

#endif
