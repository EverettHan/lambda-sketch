// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATListOfCATOmbProposedRerouteTarget_H
#define CATListOfCATOmbProposedRerouteTarget_H

/**
 * @level Private
 * @usage U1
 */

/**
 * @collection CATLISTP(CATOmbProposedRerouteTarget)
 * Collection class for pointers to CATOmbProposedRerouteTarget.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATOmbProposedRerouteTarget;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#define CATLISTP_QuickSort
#include "CATLISTP_Declare.h"

#include  "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATOmbProposedRerouteTarget);
#endif
