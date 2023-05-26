#ifndef UpdateOnEdgeCurve_H
#define UpdateOnEdgeCurve_H


// COPYRIGHT DASSAULT SYSTEMES 2002

#include "UpdateOnEdgeCurve.h"

#include "Ribbon.h"

class CATGeoFactory;
class CATVertex;
class CATEdge;
class CATEdgeCurve;
class CATCrvParam;
class CATCurve;
class CATPointOnEdgeCurve;


//------------------------------------------------------------------------------
// Update a vertex with a given EdgeCurve and get/create the corresponding POEC
// (It's possible that the vertex already has a POEC on the EdgeCurve, in which
// nothing needs to be done)
// (If the vertex doesn't have a MacroPoint, then a new MacroPoint is created)
//------------------------------------------------------------------------------

ExportedByRibbon void UpdateVertexOnEdgeCurve(CATGeoFactory        *iGeoFactory,
                                              CATVertex            *iVertex,
                                              CATEdgeCurve         *iEdgeCurve,
                                              CATCrvParam          &iParamOnCurve,
                                              CATCurve             *iCurve,
                                              CATPointOnEdgeCurve *&oPOEC);

//------------------------------------------------------------------------------
// Changement de geometrie sous l'edge : on met iEdgeCurve comme nouvelle geometrie
//  NB : les vertices ont egalement une nouvelle geometrie en sortie
//------------------------------------------------------------------------------
ExportedByRibbon void UpdateEdgeOnEdgeCurve(CATGeoFactory        *iGeoFactory,
                                            CATEdge              *iEdge,
                                            CATEdgeCurve         *iNewEdgeCurve);
#endif
