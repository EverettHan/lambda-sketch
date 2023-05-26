// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATListOfCATOmbRelationRerouteTransaction_H
#define CATListOfCATOmbRelationRerouteTransaction_H

/**
 * @level Private
 * @usage U1
 */

/**
 * @collection CATLISTP(CATOmbRelationRerouteTransaction)
 * Collection class for pointers to CATOmbRelationRerouteTransaction.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATOmbRelationRerouteTransaction;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#include "CATLISTP_Declare.h"

#include  "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATOmbRelationRerouteTransaction);
#endif
