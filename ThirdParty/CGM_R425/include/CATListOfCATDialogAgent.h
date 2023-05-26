#ifndef	CATListOfCATDialogAgent_h
#define	CATListOfCATDialogAgent_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATDialogAgent)
 * Collection class for pointers to <tt>CATDialogAgent</tt>.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>Locate</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATDialogAgent
 */

#include "CATLISTP_Clean.h"

#define	CATLISTP_Append
#define	CATLISTP_RemovePosition
#define CATLISTP_RemoveValue
#define	CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATDialogAgent;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATDialogEngine

CATLISTP_DECLARE(CATDialogAgent)

#define CATListOfCATDialogAgent CATLISTP(CATDialogAgent)

#endif
