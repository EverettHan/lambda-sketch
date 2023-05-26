// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATListOfCATOmbElementaryRerouteTransaction_H
#define CATListOfCATOmbElementaryRerouteTransaction_H

/**
 * @level Private
 * @usage U1
 */

/**
 * @collection CATLISTP(CATOmbElementaryRerouteTransaction)
 * Collection class for pointers to CATOmbElementaryRerouteTransaction.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATOmbElementaryRerouteTransaction;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#define CATLISTP_InsertAt
#include "CATLISTP_Declare.h"

#include  "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATOmbElementaryRerouteTransaction);
#endif
