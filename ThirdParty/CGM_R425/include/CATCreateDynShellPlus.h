#ifndef CATCreateDynShellPlus_H
#define CATCreateDynShellPlus_H

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "CATCleverOffset.h"
#include "CATShellOperatorPlus.h"
#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATBody.h"


/**
 * Class defining the topological operator that offsets a body.
 * We are able to Regularize faces that are un-offsetable geometrically.
 */  
ExportedByCATCleverOffset CATShellOperatorPlus * CATCreateDynShellPlus( 
				      CATTopData    * iTopData,
				      CATBody       * iPart,
				      CATLength       iInternal,
				      CATLength       iExternal);

#endif
