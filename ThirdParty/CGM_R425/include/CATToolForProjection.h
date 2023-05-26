#ifndef CATToolForProjection_H 
#define CATToolForProjection_H 

// COPYRIGHT DASSAULT SYSTEMES  2005

#include "BOHYBOPELight.h"
#include "CATHybDef.h"
#include "CATDataType.h"

class CATSimplifyParallelTool;
class CATICGMHybProject;

ExportedByBOHYBOPELight void SetSimplifyTool(CATHybProject * iProjection, CATSimplifyParallelTool * iCurSimplif);
ExportedByBOHYBOPELight void SetSimplifyTool(CATICGMHybProject * iProjection, CATSimplifyParallelTool * iCurSimplif);
ExportedByBOHYBOPELight void SetSimplifyToolParameters(CATHybProject * iProjection, double iTolerance, 
												  CATLONG32 iNewSmoothing, CATLONG32 iOutputWire3DCleaning);
ExportedByBOHYBOPELight void SetSimplifyToolParameters(CATICGMHybProject * iProjection, double iTolerance, 
												  CATLONG32 iNewSmoothing, CATLONG32 iOutputWire3DCleaning);

#endif
