
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATRoundUtilites :
// method used for round extrapolation treatment in parallel
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// August 03  Creation                          AOV
//=============================================================================
#ifndef CATRoundUtilities_H
#define CATRoundUtilities_H

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByPARLight.h"

class CATWire;
class CATPointOnEdgeCurve;
class CATMathVector;
class CATTopData;
class CATBody;

ExportedByPARLight void ComputePoecAndTangent(CATWire* iWire, int numvertex/*position dans le wire numerote de 0 a nbedges*/, 
                           int numext /* 0 edge precedente 1 edge suivante */,
                           CATPointOnEdgeCurve *& ioPoec,CATMathVector & ioTangent);

ExportedByPARLight void ReportBouchageCornerExtrap(CATTopData * iData, CATBody * iExtrapolation,CATBody **  iInitial);

#endif


