// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATListOfCATIPolyCurveVertex
//
//===================================================================
//
// April 2012  ZFI
//===================================================================

#ifndef CATListOfCATIPolyCurveVertex_H
#define CATListOfCATIPolyCurveVertex_H

#include "ExportedByTessellateCommon.h"

class CATIPolyCurveVertex;

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

#include "CATGMModelInterfaces.h"
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByTessellateCommon
/** @nodoc */
CATLISTPP_DECLARE_TS(CATIPolyCurveVertex, 10)
/** @nodoc */
typedef CATLISTP(CATIPolyCurveVertex) CATListOfCATIPolyCurveVertex;

#endif /* CATListOfCATIPolyCurveVertex_H */
