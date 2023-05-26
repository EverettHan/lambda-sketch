// COPYRIGHT Dassault Systemes 2003, all rights reserved.
//===================================================================
//
// CATLISTP_CATPolyMCurve.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  sep 2003 Creation: dhp
//===================================================================
#ifndef CATLISTP_CATPolyMCurve_h
#define CATLISTP_CATPolyMCurve_h

#include "CATIAV5Level.h"
#ifdef CATIAV5R15

/** 
 * @collection CATLISTP(CATPolyMeshCurves)
 * Collection class for pointers to polymesh curves.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia. 
 */
#include "CATPolyMCrv.h"

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"


class CATPolyMCurve;


#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyMCrv

CATLISTPP_DECLARE_TS( CATPolyMCurve , 10 )

#endif
#endif


