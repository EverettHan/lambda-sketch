//COPYRIGHT   : DASSAULT SYSTEMES 2005

#ifndef CATCreateTopProjectSimplif_H
#define CATCreateTopProjectSimplif_H


// COPYRIGHT DASSAULT SYSTEMES  2005

#include "FrFTopologicalOpe.h"
#include "CATHybDef.h"


/** @nodoc */

ExportedByFrFTopologicalOpe    CATHybProject *CATCreateTopProjectSimplif(CATGeoFactory*           iFactory,
                                                                         CATTopData*              iData,
                                                                         CATBody*                 iBodyToProject,
                                                                         CATBody*                 iBodySupport,
                                                                         CATMathDirection*        iDirection = (CATMathDirection *) 0);
    
#endif




