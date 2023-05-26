#ifndef CATListOfCATOmbOutputRelation_H
#define CATListOfCATOmbOutputRelation_H


// COPYRIGHT DASSAULT SYSTEMES 2005


/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTP(CATOmbOutputRelation)
 * Collection class for pointers to CATOmbOutputRelation.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATOmbOutputRelation;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_Locate
#include "CATLISTP_Declare.h"

#include "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATOmbOutputRelation);
#endif
