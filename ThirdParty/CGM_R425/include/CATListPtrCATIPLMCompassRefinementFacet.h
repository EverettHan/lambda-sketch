#ifndef INCL_CATListPtrCATIPLMCompassRefinementFacet_h
#define INCL_CATListPtrCATIPLMCompassRefinementFacet_h

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
 * @collection CATLISTP(CATIPLMCompassRefinementFacet)
 * Collection class for pointers to <tt>CATIPLMCompassRefinementFacet</tt>.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATIPLMCompassRefinementFacet
 */

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveValue
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Locate
#define CATLISTP_QuickSort

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "CATAfrItf.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByCATAfrItf

// Declare the CATLISTP(CATIPLMCompassRefinementFacet) type.
class CATIPLMCompassRefinementFacet;
CATLISTP_DECLARE( CATIPLMCompassRefinementFacet )

#endif
