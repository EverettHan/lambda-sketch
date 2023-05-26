
/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 2002
 
 DESCRIPTION : LayDown For Parallal method
               LayDown a wire for parallel and give an error if not nay down and build a journal
               without laydown on shell

=============================================================================
*/
#ifndef LayDownForParallel_H
#define LayDownForParallel_H

#include "CATDataType.h"
#include "ExportedByPARLight.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATDistanceTool;
class CATLaw;
class CATWireTopOp;
class CATParallelInitBase;
class CATTopOperator;

// S9L : IR-509840, IR-515225, IR-518261 : Start
// Check if the entire shell is contained in a single plane
CATBoolean CheckForPlanarSupport(CATBody * ipSupport);
// Check if the support shell contains fat edges
CATBoolean CheckForFatEdgesOnSupport(CATBody * ipSupport);
// S9L : IR-509840, IR-515225, IR-518261 : End

void HealWires(CATGeoFactory * iFacto, CATTopData * iNewData,CATBody * iOrigWire,
               CATBody *& ioParallelBody,CATLONG32 *& ioDescDebWires,CATLONG32 *& ioDescFinWires);

void ExportedByPARLight ExecuteParallel(CATGeoFactory * iFacto, CATTopData * iData, CATBody * iCurve,CATBody * iSupport,
                     CATLONG32 ichkcurvature,CATLONG32 iRunOpt,CATDistanceTool * iDistTool,CATLaw ** MapLaws,
                     CATWireTopOp *& oOperator,CATParallelInitBase *& oWireInit, CATBody*& oParallBody) ;
#endif


