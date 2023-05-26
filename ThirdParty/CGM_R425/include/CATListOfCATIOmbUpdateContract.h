// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATListOfCATIOmbUpdateContract_H
#define CATListOfCATIOmbUpdateContract_H

/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTP(CATIOmbUpdateContract)
 * Collection class for pointers to CATIOmbUpdateContract.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATIOmbUpdateContract;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"

#include "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATIOmbUpdateContract);
#endif
