// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATListOfCATPLMEditabilityError_H
#define CATListOfCATPLMEditabilityError_H

/**
 * @level Protected
 * @usage U1
 */

/**
 * @collection CATLISTP(CATPLMEditabilityError)
 * Collection class for pointers to CATPLMEditabilityError.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATPLMEditabilityError;

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"

#include "CATPLMComponentInterfaces.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATPLMComponentInterfaces
CATLISTP_DECLARE(CATPLMEditabilityError);
#endif