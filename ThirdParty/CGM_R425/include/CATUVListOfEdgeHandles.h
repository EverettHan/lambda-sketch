// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVAbstractTopo.h
//
//===================================================================
//
// Sep 2012  Creation: NHD / MPX
//===================================================================

#ifndef CATUVListOfEdgeHandles_H
#define CATUVListOfEdgeHandles_H

#include "ExportedByTessellateCommon.h"
#include "CATUVAbstractTopoHandles.h"

#include  <CATCollec.h>
#include  <CATRCOLL_Clean.h>

#define CATRCOLL_Append ;
#define CATRCOLL_RemoveAll ;
#define CATRCOLL_ReSize ;

#undef  CATCOLLEC_ExportedBy
#define  CATCOLLEC_ExportedBy ExportedByTessellateCommon
#include  <CATRCOLL_Declare.h>

CATRCOLL_DECLARE(CATUVEdgeHandle)
typedef CATRCOLL(CATUVEdgeHandle) CATUVListOfEdgeHandles ;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy



#endif //CATUVListOfEdgeHandles_H
