/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATLISTP_CATIPLMCompResultVersion_h
#define CATLISTP_CATIPLMCompResultVersion_h

/**
* @level Protected
* @usage U1
 */

/**
 * @collection CATLISTP(CATIPLMCompResultVersion)
 * Collection class for @href CATIPLMCompResultVersion .
 * Only the following methods of are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

// Clean previous functions requests
#include  "CATLISTP_Clean.h"

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_RemoveAll

// Get macros
#include  "CATLISTP_Declare.h"

// Define the NT DLL export macro
#include "CATPLMServicesItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATPLMServicesItf

// Declare the CATLISTP(XXX) type.
#include "CATIPLMCompResultVersion.h"
CATLISTP_DECLARE(CATIPLMCompResultVersion)

#endif
