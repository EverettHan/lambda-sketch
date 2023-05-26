// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATListOfCATOmbLinkProperties_H
#define CATListOfCATOmbLinkProperties_H

/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTP(CATOmbLinkProperties)
 * Collection class for pointers to CATOmbLinkProperties.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATOmbLinkProperties;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_RemovePosition
#include "CATLISTP_Declare.h"

#include  "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATOmbLinkProperties);
#endif
