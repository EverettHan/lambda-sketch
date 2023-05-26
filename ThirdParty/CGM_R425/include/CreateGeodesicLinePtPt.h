//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CreateGeodesicLinePtPt :
// Declaration of global functions used to create geodesic line
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//January 03   Creation                                  AOV
//=============================================================================
#ifndef CreateGeodesicLinePtPt_H 
#define CreateGeodesicLinePtPt_H 
//
#include "YJ000GSM.h"
//
class CATTopGeodesicPtPt;
class CATGeoFactory;
class CATTopData;
class CATBody;
//
// create the operator of geodesic line between two points
//
ExportedByYJ000GSM
CATTopGeodesicPtPt * CreateGeodesicLinePtPt (CATGeoFactory * iFacto, CATTopData * iData, CATBody * iPtOrig, CATBody * iPtFin, CATBody * iShellSupport);
    

//
#endif


