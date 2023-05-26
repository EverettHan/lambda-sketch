#ifndef ComputeLocationVsDirection_H
#define ComputeLocationVsDirection_H


// COPYRIGHT DASSAULT SYSTEMES 2002

// 28/06/19 PKC fix missing config in call to CATProjectionInDirectionPtSur

#include "CATMathDef.h"
#include "CATTopRibDef.h"
#include "ListPOfCATFace.h"

#include "Ribbon.h"

class CATGeoFactory;
class CATBody;
class CATVertex;
class CATEdge;
class CATFace;
class CATMathVector;
class CATMathDirection;
class CATSoftwareConfiguration;


//-----------------------------------------------------------------------------
// Commentaire a ecrire par GDR!!!!
//-----------------------------------------------------------------------------
ExportedByRibbon CATTopSign ComputeEdgeLocationVsFaceAndDirection
(CATSoftwareConfiguration *iSoftwareConfiguration,
 CATEdge                  *iEdge,
 CATFace                  *iFace, 
 CATMathDirection         &iVector);
ExportedByRibbon CATBoolean ComputeFaceLocationVsFacesAndDirection
(CATSoftwareConfiguration *iSoftwareConfiguration,   // 28/06/2019 PKC
 CATGeoFactory            *iFactory,
 CATFace                  *iFace,
 ListPOfCATFace           *iListOfFaces, 
 CATMathDirection         &iVector,
 CATTopSign               &oPosition);
//-----------------------------------------------------------------------------
// Find out if a given edge is located above or below another edge,
// with respect to a given direction
//
// Please note: 1) The possible results are
//                 PositiveSign - the edge is "above" the other edge
//                 NegativeSign - the edge is "below" the other edge
//                 UnknownSign  - the location cannot be determined
//              2) The edge MUST NOT intersect the other edge to begin with!
//                 The only accepted contact between the two is a vertex!
//              3) ioValue is an optional input/output, that is increased
//                 by the signed result
//-----------------------------------------------------------------------------
ExportedByRibbon CATTopSign ComputeEdgeLocationVsEdgeAndDirection
(CATSoftwareConfiguration *iSoftwareConfiguration,
 CATEdge          *iEdge,
 CATEdge          *iOtherEdge, 
 CATMathDirection &iVector,
 double           *ioValue = NULL);
#endif
