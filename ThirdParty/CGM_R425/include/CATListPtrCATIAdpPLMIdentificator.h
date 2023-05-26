#ifndef CATListPtrCATIAdpPLMIdentificator_h
#define CATListPtrCATIAdpPLMIdentificator_h
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @collection CATLISTP(CATIAdpPLMIdentificator)
 * Collection class for pointers to PLM Identificator.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */
#include "CATPLMIdentificationAccess.h"

class CATIAdpPLMIdentificator;

// Clean previous functions requests
#include "CATLISTP_Clean.h"

// Require needed functions
#define CATLISTP_Append
#define CATLISTP_RemoveAll

// Get macros
#include "CATLISTP_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIdentificationAccess

// Declare the collection class
CATLISTP_DECLARE(CATIAdpPLMIdentificator)

// Define an handy name
typedef CATLISTP(CATIAdpPLMIdentificator) CATListPtrCATIAdpPLMIdentificator;

#undef	CATCOLLEC_ExportedBy

#endif
