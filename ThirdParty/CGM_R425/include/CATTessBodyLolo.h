// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyLolo
//
//===================================================================
//
// Janvier 2011  Creation: LVL
//===================================================================
#ifndef CATTessBodyLolo_H
#define CATTessBodyLolo_H

#include "TessBodyAdapters.h"
/*#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATTessParam.h"*/
class CATIPolySurface;
class CATFace;
class CATIPolyCurve;
class CATEdge;
class CATBody;

// Phoenix.
class CATechExt; 

extern "C" ExportedByTessBodyAdapters CATIPolySurface*   ComputePolySurface(CATFace * iFace, CATBody * iBody, float iSag) ;
extern "C" ExportedByTessBodyAdapters CATIPolyCurve*   ComputePolyCurve(CATEdge * iEdge, CATBody * iBody, float iSag) ;

#endif
