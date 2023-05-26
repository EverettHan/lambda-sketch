#ifndef CATListOfCATDiaAction_h
#define CATListOfCATDiaAction_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999



/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATDiaAction)
 * Collection class for pointers to <tt>CATDiaAction</tt>.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>Locate</tt></li>
 * </ul>
 *
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATDiaAction
 */

#include "CATLISTP_Clean.h"

#define	CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define	CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATDiaAction;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATDialogEngine

CATLISTP_DECLARE(CATDiaAction)

#define CATListOfCATDiaAction CATLISTP(CATDiaAction)

#endif
