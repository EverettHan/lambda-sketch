// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATListOfCATIOmbTechnologicalSet_H
#define CATListOfCATIOmbTechnologicalSet_H

/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTP(CATIOmbTechnologicalSet)
 * Collection class for pointers to CATIOmbTechnologicalSet.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATIOmbTechnologicalSet;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#include "CATLISTP_Declare.h"

#include  "CATOmbTechnologicalRep.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATOmbTechnologicalRep
CATLISTP_DECLARE(CATIOmbTechnologicalSet);
#endif
