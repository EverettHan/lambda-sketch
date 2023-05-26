#ifndef CATDynMassProperties1DOnEdge_H
#define CATDynMassProperties1DOnEdge_H
//=============================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 1997
//
// DESCRIPTION : CATDynMassProperties1DOnEdge  class declaration
//
//=============================================================================
//#include "BODYNOPE.h"
#include "BODYNOPELight.h"

#include "CATDynMassProperties1DOnEdge.h"

ExportedByBODYNOPELight CATDynMassProperties1DOnEdge *CATInternalDynCreateMassProperties1DOnEdge (const CATEdge*);  

ExportedByBODYNOPELight CATDynMassProperties1DOnEdge *CATInternalDynCreateMassProperties1DOnEdge (CATTopData * iTopData, const CATEdge*);  

#endif
