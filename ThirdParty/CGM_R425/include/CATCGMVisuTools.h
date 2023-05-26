// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyImportExport.h
// Header definition of CATPolyImportExport
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2006 Creation: chu/ndo
//===================================================================
#ifndef CATCGMVisuTools_H
#define CATCGMVisuTools_H

#include "PolyImportExport.h"

//Macro-modele
class CATPolyBody;

class CATSurfacicRep;
class CATMonoWireRep;
class CAT3DMarkerGP;
class CAT3DFaceGP;
class CAT3DEdgeGP;
class CAT3DLineGP;
class CATVizVertexBuffer;
class CAT3DBoundingSphere;
class CATGraphicAttributeSet;
class CATGraphicMaterial;

class CATMathBox;

template <class T> class CATVizPtrList;


class ExportedByPolyImportExport CATCGMVisuTools
{

public:

 static CAT3DBoundingSphere* CreateBoundingSphere (const CATMathBox& bbox);

 static CATMonoWireRep * CreateMonoWireRepFromLines(const CATVizPtrList<CAT3DLineGP> &iLines,
                                                    const CATVizPtrList<CATGraphicAttributeSet> &iLinesAttributes);


 static CATSurfacicRep* CreateSurfacicRepFromFacesAndEdges(CATVizPtrList<CAT3DEdgeGP> &iEdges, CATVizPtrList<CAT3DFaceGP> &iFaces,
                                                            CATVizVertexBuffer *& oVizVerxteBuffer);

 static CATSurfacicRep* CreateSurfacicRepFromFacesAndEdges(
                                                  const CATVizPtrList<CAT3DMarkerGP> &iPoints,
                                                  const CATVizPtrList<CAT3DLineGP> &iLines,
                                                  const CATVizPtrList<CAT3DEdgeGP> &iEdges, 
                                                  const CATVizPtrList<CAT3DEdgeGP> &iSharpEdges, 
                                                  const CATVizPtrList<CAT3DFaceGP> &iFaces,
                                                  const CATVizPtrList<CATGraphicAttributeSet> &iPointsAttributes,  
                                                  const CATVizPtrList<CATGraphicAttributeSet> &iLinesAttributes,  
                                                  const CATVizPtrList<CATGraphicAttributeSet> &iEdgesAttributes,
                                                  const CATVizPtrList<CATGraphicAttributeSet> &iSharpEdgesAttributes,
                                                  const CATVizPtrList<CATGraphicAttributeSet> &iFacesAttributes,
                                                  const CATVizPtrList<CATGraphicMaterial> &iFacesMaterials,
                                                  CATVizVertexBuffer* iVizVertexBuffer);

 static void SetDefaultGraphicAttributesForFaces (CATGraphicAttributeSet& graphicAttributes);
 
 static void SetDefaultGraphicAttributesForEdges (CATGraphicAttributeSet& graphicAttributes);
 static void SetDefaultGraphicAttributesForLines (CATGraphicAttributeSet& graphicAttributes);


};
#endif


