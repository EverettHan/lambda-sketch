//COPYRIGHT   : DASSAULT SYSTEMES 2005

#ifndef CATCreateTopSmartProjectSimplif_H
#define CATCreateTopSmartProjectSimplif_H


// COPYRIGHT DASSAULT SYSTEMES  2005

#include "FrFTopologicalOpe.h"
#include "CATHybDef.h"

class CATTopSmartProject;

/** @nodoc */

ExportedByFrFTopologicalOpe
CATTopSmartProject *CATCreateTopSmartProjectSimplif(CATGeoFactory*           iFactory,
                                                    CATTopData*              iData,
                                                    CATBody*                 iBodyToProject,
                                                    CATBody*                 iBodySupport,
                                                    CATMathDirection*        iDirection = (CATMathDirection *) 0);
    
#endif




