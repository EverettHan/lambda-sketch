/* -*-c++-*- */

#ifndef CATDynCNEXTLight_H
#define CATDynCNEXTLight_H

#include "AnalysisToolsLight.h"
#include "CATDynMassProperties1DOnEdge.h"

extern "C"
{

ExportedByAnalysisToolsLight CATDynMassProperties1DOnEdge* CreateMassProperties1DOnEdgeCNEXT(const CATEdge*);
ExportedByAnalysisToolsLight CATDynMassProperties1DOnEdge* CreateMassProperties1DOnEdge(CATTopData * iTopData, const CATEdge*);

};


#endif
