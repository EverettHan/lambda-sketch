// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
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
// Apr 2005 Creation: NDO
//===================================================================
#ifndef CATLISTV_CATPolyMPointTopo_h
#define CATLISTV_CATPolyMPointTopo_h

#include "CATIAV5Level.h"
#ifdef CATIAV5R15

/** 
 * @collection CATLISTV(CATPolyMeshPointTopo)
 * Collection class for mesh points topo.
 */

#include "CATPolyMCrv.h"

#include "CATLISTV_Clean.h"
#define	CATLISTV_InsertAt
#define	CATLISTV_RemovePosition
#define CATLISTV_AppendList
#include "CATLISTV_Declare.h"

#include "CATPolyMPointTopo.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATPolyMCrv

CATLISTV_DECLARE(CATPolyMPointTopo)


#endif
#endif

