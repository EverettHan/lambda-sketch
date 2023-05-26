#ifndef CATCreateDynAdvancedFilletFunction_H
#define CATCreateDynAdvancedFilletFunction_H

// COPYRIGHT DASSAULT SYSTEMES 2004
//=================================================================================================
//
// Function definition for generating advanced fillet operators
//
//=================================================================================================

#include "Ribbon.h"
#include "CATDataType.h"
class CATBody;
class CATGeoFactory;
class CATShell;
class CATEdge;
class CATFace;
class CATTopData;
class CATDynFillet;

typedef CATDynFillet*
    (*CATCreateDynAdvancedFilletFunction) 
        (
         CATGeoFactory* iContainer,
         CATTopData*    iData,
         CATBody*       iPart,
         CATBoolean     iMultiRibbSafeMode
        )  ;    
#endif
