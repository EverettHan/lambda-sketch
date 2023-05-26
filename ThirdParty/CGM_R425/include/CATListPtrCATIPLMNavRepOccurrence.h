// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
//  Dec 2005  Creation: LJE
//
//===================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */
#ifndef CATListPtrCATIPLMNavRepOccurrence_H
#define CATListPtrCATIPLMNavRepOccurrence_H

#include "CATPLMComponentInterfaces.h"

#include "CATLISTP_Declare.h"

/**
 * @collection CATListPtrCATIPLMNavRepOccurrence
 * Collection class for pointers to @href CATIPLMNavRepOccurrence.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>RemoveAll</tt</li>
 * <li><tt>RemoveValue</tt</li>
 * <li><tt>RemovePosition</tt</li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATLISTP_Clean.h"
#define CATLISTP_Append
#define CATLISTP_Locate
#define CATLISTP_RemoveAll
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#include "CATLISTP_Declare.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPLMComponentInterfaces

class CATIPLMNavRepOccurrence;
CATLISTP_DECLARE(CATIPLMNavRepOccurrence)

#endif
