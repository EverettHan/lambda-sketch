#ifndef INCL_CATLISTPIConnectionPoint_h
#define INCL_CATLISTPIConnectionPoint_h


// COPYRIGHT DASSAULT SYSTEMES 2000

// Clean previous functions requests
#include  <CATLISTP_Clean.h>

// Specify the function to take into account.
#include <CATLISTP_AllFunct.h>

// Get macros
#include  <CATLISTP_Declare.h>

// Define the NT DLL export macro
#include "ConnectionPts.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByConnectionPts

// Declare the CATLISTP(IConnectionPoint) type.
#include "IConnectionPoint.h"
CATLISTP_DECLARE( IConnectionPoint )

#endif
