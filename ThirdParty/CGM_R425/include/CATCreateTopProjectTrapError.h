#ifndef CATCreateTopProjectTrapError_H 
#define CATCreateTopProjectTrapError_H 

#include "BOHYBOPELight.h"
#include "CATHybDef.h"

/**
* no doc DAIMLER Chrysler issue Only
*/

ExportedByBOHYBOPELight CATHybProject * CATCreateTopProjectTrapError(CATGeoFactory*           iFactory,
                                                       CATTopData*              iData,
                                                       CATBody*                 iBodyToProject,
                                                       CATBody*                 iBodySupport,
                                                       CATMathDirection*        iDirection = (CATMathDirection *) 0);
#endif
