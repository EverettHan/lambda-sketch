#ifndef CATListOfCATISelectionSetElement_var_h
#define CATListOfCATISelectionSetElement_var_h

// COPYRIGHT DASSAULT SYSTEMES 2001
/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATISelectionSetElement_var)
 * Collection class for <tt>CATISelectionSetElement_var</tt>.
 * Only the following methods of collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * <li><tt>RemoveDuplicatesCount</tt></li>
 * <li><tt>RemoveList</tt></li>
 * <li><tt>Size</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATISelectionSetElement
 */
#include "CATISelectionSetElement.h"

#include "CATLISTV_Clean.h"

#define CATLISTV_Append
#define CATLISTV_Locate
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_RemoveDuplicatesCount
#define CATLISTV_RemoveList
#define CATLISTV_Size

#include "CATLISTV_Declare.h"

// exporting module
#include "UIModelInterfaces.h"
#undef  CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByUIModelInterfaces

CATLISTV_DECLARE(CATISelectionSetElement_var)

typedef CATLISTV(CATISelectionSetElement_var) CATListOfCATISelectionSetElement_var;

#endif

