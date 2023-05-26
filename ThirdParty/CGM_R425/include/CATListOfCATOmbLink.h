// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATListOfCATOmbLink_H
#define CATListOfCATOmbLink_H

/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTP(CATOmbLink)
 * Collection class for pointers to CATOmbLink.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATOmbLink;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"

#include "CATObjectModelerBase.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATObjectModelerBase
CATLISTP_DECLARE(CATOmbLink);
#endif
