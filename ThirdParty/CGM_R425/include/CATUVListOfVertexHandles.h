// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATUVListOfVertexHandles.h
//
//===================================================================
//
// Sep 2012  Creation: NHD / MPX
//===================================================================

#ifndef CATUVListOfVertexHandles_H
#define CATUVListOfVertexHandles_H

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

CATRCOLL_DECLARE(CATUVVertexHandle)
typedef CATRCOLL(CATUVVertexHandle) CATUVListOfVertexHandles ;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy



#endif //CATUVListOfVertexHandles_H
