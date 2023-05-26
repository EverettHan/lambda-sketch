#ifndef CATCreateGeodesicLinePtPt_H 
#define CATCreateGeodesicLinePtPt_H 
//
//COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @required Protected
 * @usage U1
 */ 
#include "YJ000GSM.h"
//
class CATTopGeodesicPtPt;
class CATGeoFactory;
class CATTopData;
class CATBody;
//
/*
 * Constructs the CATTopGeodesicPtPt operator. 
 * The CATTopGeodesicPtPt operator
 * creates a geodesic line between two points.
 * @param iFacto
 * A pointer to the factory of the resulting body.
 * @param iData
 * A pointer to the topological data.
 * @param iPtOrig
 * A pointer to start point.
 * @param iPtFin
 * A pointer to end point. 
 * @param iShellSupport
 * A pointer to the support. 
 */
//
ExportedByYJ000GSM
CATTopGeodesicPtPt * CATCreateGeodesicLinePtPt (CATGeoFactory * iFacto, CATTopData * iData, CATBody * iPtOrig, CATBody * iPtFin, CATBody * iShellSupport);
    

//
#endif


