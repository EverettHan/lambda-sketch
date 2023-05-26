#ifndef CATBSDGapFillFunction_H
#define CATBSDGapFillFunction_H

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "Ribbon.h"
#include "CATDataType.h"
class CATBody;
class CATGeoFactory;
class CATFace;
class CATTopData;

typedef CATBody* 
    (*CATBSDGapFillFunction) 
        (CATGeoFactory* iFactory,
        CATTopData *  iTopData,
        CATBody*      iBody,
        CATBody*      iParting,
        CATFace*      iFace1,
        CATFace*      iFace2);    

//=================================================================================================
// To be used to dynamically load a GapFillFunction
//=================================================================================================
ExportedByRibbon CATBSDGapFillFunction CATGetBSDGapFillFunction();
//=================================================================================================
#endif
