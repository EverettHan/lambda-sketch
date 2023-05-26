// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATListOfCATPolyMPoints.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// sep 2003 Creation: dhp
//===================================================================
#ifndef CATLISTV_CATPolyMPoint_h
#define CATLISTV_CATPolyMPoint_h

#include "CATIAV5Level.h"
#ifdef CATIAV5R15

/** 
 * @collection CATLISTV(CATPolyMeshPoints)
 * Collection class for mesh points.
 */

#include "CATPolyMCrv.h"

#include "CATLISTV_Clean.h"
#define	CATLISTV_InsertAt
#define	CATLISTV_RemovePosition
#define CATLISTV_AppendList
#include "CATLISTV_Declare.h"

#include "CATPolyMPoint.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyMCrv

CATLISTV_DECLARE(CATPolyMPoint)


#endif
#endif

