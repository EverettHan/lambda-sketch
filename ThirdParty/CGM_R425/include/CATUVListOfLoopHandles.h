// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATUVListOfLoopHandles.h
//
//===================================================================
//
// Sep 2012  Creation: NHD / MPX
//===================================================================

#ifndef CATUVListOfLoopHandles_H
#define CATUVListOfLoopHandles_H

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

CATRCOLL_DECLARE(CATUVLoopHandle)
typedef CATRCOLL(CATUVLoopHandle) CATUVListOfLoopHandles ;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy



#endif //CATUVListOfLoopHandles_H
