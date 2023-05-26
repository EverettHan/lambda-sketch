//===================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//===================================================================
//
// CATLISTP_CATPolyMCNOPoint.h
//
//===================================================================
//
// Usage notes: List of CATPolyMCNOPoint pointers.
//
//===================================================================
// March,     2012 : RAQ : Creation
//===================================================================
#ifndef CATLISTP_CATPolyMCNOPoint_H
#define CATLISTP_CATPolyMCNOPoint_H

//Pour l'export
#include "CATPolyTrimOperators.h"

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

class CATPolyMCNOPoint;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyTrimOperators

CATLISTPP_DECLARE_TS(CATPolyMCNOPoint, 10)

typedef CATListPtrCATPolyMCNOPoint CATListPOfPolyMCNOPoint;

#endif

