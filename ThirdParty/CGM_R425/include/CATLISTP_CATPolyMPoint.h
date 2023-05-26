//===================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//===================================================================
//
// CATLISTP_CATPolyMPoint.h
//
//===================================================================
//
// Usage notes: List of CATPolyMPoint pointers.
//
//===================================================================
// March,     2012 : RAQ : Creation
//===================================================================
#ifndef CATLISTP_CATPolyMPoint_H
#define CATLISTP_CATPolyMPoint_H

#include "CATPolyMCrv.h"

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

class CATPolyMPoint;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyMCrv

CATLISTPP_DECLARE_TS(CATPolyMPoint, 10)

typedef CATListPtrCATPolyMPoint CATListPOfPolyMPoint;

#endif

