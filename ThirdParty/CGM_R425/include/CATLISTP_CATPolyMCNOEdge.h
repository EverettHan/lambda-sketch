//===================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//===================================================================
//
// CATLISTP_CATPolyMCNOEdge.h
//
//===================================================================
//
// Usage notes: List of CATPolyMCNOEdge pointers.
//
//===================================================================
// March,     2012 : RAQ : Creation
//===================================================================
#ifndef CATLISTP_CATPolyMCNOEdge_H
#define CATLISTP_CATPolyMCNOEdge_H

//Pour l'export
#include "CATPolyTrimOperators.h"

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

class CATPolyMCNOEdge;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyTrimOperators

CATLISTPP_DECLARE_TS(CATPolyMCNOEdge, 10)

typedef CATListPtrCATPolyMCNOEdge CATListPOfPolyMCNOEdge;

#endif

