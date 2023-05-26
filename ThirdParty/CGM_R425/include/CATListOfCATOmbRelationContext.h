#ifndef CATListOfCATOmbRelationContext_H
#define CATListOfCATOmbRelationContext_H


// COPYRIGHT DASSAULT SYSTEMES 2005


/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTP(CATOmbRelationContext)
 * Collection class for pointers to CATOmbRelationContext.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATOmbRelationContext;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_Locate
#include "CATLISTP_Declare.h"

#include "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATOmbRelationContext);
#endif
