//===================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//===================================================================================
//
// CATLISTP_CATPolyMCurveNetworkIntersectionPoint.h
//
//===================================================================================
//
// Usage notes: Collection of CATPolyMCurveNetworkIntersectionPoint objects.
//
//===================================================================================
// July,   2009 : RAQ : Création
//===================================================================================
#ifndef CATLISTP_CATPolyMCurveNetworkIntersectionPoint_H
#define CATLISTP_CATPolyMCurveNetworkIntersectionPoint_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Déclaration des listes
#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

class CATPolyMCurveNetworkIntersectionPoint;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyTrimOperators

CATLISTPP_DECLARE_TS(CATPolyMCurveNetworkIntersectionPoint, 10)

typedef CATListPtrCATPolyMCurveNetworkIntersectionPoint CATListPtrNetworkIntersectionPoint;

#endif

