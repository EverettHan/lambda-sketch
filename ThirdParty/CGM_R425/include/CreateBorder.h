#ifndef CreateBorder_H
#define CreateBorder_H


// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATBoolean.h"

#include "RibbonLight.h"


class CATSoftwareConfiguration;

class CATBody;
class CATCell;
class CATVertex;
class CATEdge;
class CATFace;
class CATPCurve;


//------------------------------------------------------------------------------
// Create default border cells (based on geometry) of a cell without
// any borders
// (no action is taken if the cell is not a face or an edge)
//
// ioMinUEdge, ioMaxUEdge, ioMinVEdge and ioMaxUEdge are optional
// input/output arguments that define (only if iCell is a face)
// the external loop (located at the surface's maximum limits)
// IF THEY ARE PROVIDED, they are defined as follows:
//
//  + ----------------------------------------------> u
//  |
//  |               ioMinVEdge
//  |             +------------->+
//  |             |              |
//  |             |              |
//  |  ioMinUEdge |              | ioMaxUEdge
//  |             |              |
//  |             V              V
//  |             +------------->+
//  |               ioMaxVEdge
//  |
//  V v
//
// The arrows on the above define the orientation of PCurves, SimCurves
// AND Edges!
//------------------------------------------------------------------------------
ExportedByRibbonLight
 void CreateBorder (CATBody                  *iBody,
                    CATSoftwareConfiguration *iConfig,
                    CATCell                  *iCell,
                    void                     *iStartParam  = NULL, // either CATSurParam or CATCrvParam
                    void                     *iEndParam    = NULL, // either CATSurParam or CATCrvParam
                    CATFace                  *iFace        = NULL,
                    CATVertex               **iStartVertex = NULL,
                    CATVertex               **iEndVertex   = NULL,
                    CATPCurve                *iRefPCurve   = NULL,
                    CATEdge                 **ioMinUEdge   = NULL,
                    CATEdge                 **ioMaxUEdge   = NULL,
                    CATEdge                 **ioMinVEdge   = NULL,
                    CATEdge                 **ioMaxVEdge   = NULL,
                    CATBoolean                iAddPCurveToProvidedMaxEdges = FALSE,
                    CATBoolean                iSupplFace = FALSE);
#endif
