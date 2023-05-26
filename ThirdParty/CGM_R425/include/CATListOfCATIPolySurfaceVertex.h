// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATListOfCATIPolySurfaceVertex
//
//===================================================================
//
// April 2012  ZFI
//===================================================================

#ifndef CATListOfCATIPolySurfaceVertex_H
#define CATListOfCATIPolySurfaceVertex_H

#include "ExportedByTessellateCommon.h"

class CATIPolySurfaceVertex;

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

#include "CATGMModelInterfaces.h"
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByTessellateCommon
/** @nodoc */
CATLISTPP_DECLARE_TS(CATIPolySurfaceVertex, 10)
/** @nodoc */
typedef CATLISTP(CATIPolySurfaceVertex) CATListOfCATIPolySurfaceVertex;

#endif /* CATListOfCATIPolySurfaceVertex_H */
