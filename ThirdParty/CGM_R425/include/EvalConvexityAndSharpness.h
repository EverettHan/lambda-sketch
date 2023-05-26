#ifndef EvalConvexityAndSharpness_H
#define EvalConvexityAndSharpness_H


// COPYRIGHT DASSAULT SYSTEMES 1999


#include "EvalConvexityAndSharpnessLight.h"

#include "CATTopDef.h"

#include "RibbonLight.h"

#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"

class CATBody;
class CATShell;
class CATVertex;
class CATEdge;
class CATLoop;
class CATFace;
class CATCrvParam;
class CATSoftwareConfiguration;


//------------------------------------------------------------------------------
// Compute the convexity of a border vertex on a given face and linking two
// given border edges in given loop
//
// Please note: iprevEdge and iNextEdge are two edges linked by iVertex
//              on the border of iFace, and define a direction on the
//              boundary which is as follows:
//              if the edges are on an outer loop of the face, and
//              if the vertex is the end vertex of the previous edge
//              and the start vertex of the next edge, then the face
//              must be to the left of both edges.
//------------------------------------------------------------------------------

ExportedByRibbonLight CATTopConvexity ComputeVertexConvexityInFace(CATSoftwareConfiguration *iConfig,
                                                              CATVertex  *iVertex,
							                                                CATEdge    *iPrevEdge,
							                                                CATEdge    *iNextEdge,
							                                                CATLoop    *iLoop,
							                                                CATFace    *iFace,
							                                                CATBoolean &oSingular,
                                                              CATBoolean  iNonOrderedEdges = FALSE);

//------------------------------------------------------------------------------
// Compute the convexity of a border vertex on a given face
//------------------------------------------------------------------------------

ExportedByRibbonLight CATTopConvexity ComputeVertexConvexityInFaceHigh(CATSoftwareConfiguration *iConfig, 
                                                                  CATBody *iBody, CATVertex *iVertex, CATFace *iFace, CATBoolean &oSingular);

//------------------------------------------------------------------------------
// Evaluate in a given point the convexity of an Edge with respect to a face
// (i.e. the face's transversal curvature at a given point along the edge)
//------------------------------------------------------------------------------
ExportedByRibbonLight void EvalConvexityOnFace(CATSoftwareConfiguration *iConfig,
                                          const CATCrvParam &iParamOnEdgeCurve,         
                                          CATEdge           *iEdge,
                                          CATFace           *iFace,
                                          CATTopConvexity   &oConvexity,
                                          CATShell          *iShellOwningTheFace=NULL);

//------------------------------------------------------------------------------
// Evaluate the global convexity of an Edge with respect to a face
// (i.e. the face's transversal curvature along the edge)
//------------------------------------------------------------------------------
ExportedByRibbonLight void EvalGlobalConvexityOnFace(CATSoftwareConfiguration *iConfig,
                                                CATEdge         *iEdge,
                                                CATFace         *iFace,
                                                CATTopConvexity &oConvexity,
                                                CATShell        *iShellOwningTheFace=NULL);

//------------------------------------------------------------------------------
// Find the common border edges between two lists of faces and evaluate their
// sharpness values
//------------------------------------------------------------------------------
ExportedByRibbonLight CATTopSharpness GetCommonEdgesAndSharpnesses (CATSoftwareConfiguration *iConfig,
                                                               CATBody                  *iBody,
                                                               CATShell                 *iShell,
                                                               CATLISTP(CATFace)        &iFaces1,
                                                               CATLISTP(CATFace)        &iFaces2,
                                                               CATLISTP(CATEdge)        *oEdges       = NULL,
                                                               CATListPV                *oSharpnesses = NULL);


#endif
