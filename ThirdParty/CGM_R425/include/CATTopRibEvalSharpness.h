/* -*-C++-*- */
#ifndef CATTopRibEvalSharpness_H
#define CATTopRibEvalSharpness_H
// COPYRIGHT DASSAULT SYSTEMES 2002

//===================================================================
//
// Utilitaire de CATTopRib 
//
//===================================================================

//===================================================================
// Usage notes:
// - Vérifie que la vivicité en traversant un Vertex et en roulant sur 2 edges
//
//===================================================================

//===================================================================
// Feb. 02    Creation                         R. Rorato
//===================================================================

#include "CATTopRibDef.h"
#include "ExportedByRIBLight.h"

class CATEdge;
class CATVertex;
class CATBody;
class CATSoftwareConfiguration;

ExportedByRIBLight CATTopGeoContinuity CATTopRibEvalSharpness(CATSoftwareConfiguration* iConfig,
                                                         CATEdge*                  iEdge1, 
                                                         CATVertex*                iCommonVertex,
                                                         CATEdge*                  iEdge2,
                                                         CATBody*                  iBody, 
                                                         CATTopRibSign           & oOrientation );

#endif
