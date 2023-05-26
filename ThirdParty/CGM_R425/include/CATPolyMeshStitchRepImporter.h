// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshStitchRepImporter.h
// Header definition of CATPolyMeshStitchRepImporter
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2008 Creation: ndo
//===================================================================
#ifndef CATPolyMeshStitchRepImporter_H
#define CATPolyMeshStitchRepImporter_H

#include "PolyImportExport.h"
#include "CATErrorDef.h" // Definition of HRESULT.

class CATIPolyMesh;
class CATPolyMeshVertexNNormalsLayer;
class CATPolySurfaceFacetSupportLayer;

class CATPolyBars;
class CATPolyBarsBarSupportLayer;

class CATPolyVizContainer;

class CAT3DLineGP;
class CAT3DEdgeGP;
class CAT3DFaceGP;
class CAT3DBoundingGP;
class CAT3DRep;
class CAT4x4Matrix;

template <class T> class CATVizPtrList;


class ExportedByPolyImportExport CATPolyMeshStitchRepImporter
{

public:

  //
  // Import of a CAT3DRep into a CATIPolyMesh + Layers.
  // In this import, all vertices with bitwise identical coordinates are merged.  
  // Matching boundaries are stitched together.
  // 

  /*
     Import of a CAT3DRep into a polymesh with optional layers for:
       o Vertex normals (arbitrary number of normals for each vertex.)
       o Surface support associated to each triangle.
       o List of mesh vertex lines for each edge of the CAT3DRep.
     A polymesh has to be created before the call (thus enabling all implementations of CATIPolyMesh.)
     The reps supported are:
       o CAT3DBagRep
       o CATSurfacicRep
       o CAT3DCylinderRep
       o CAT3DCurvedPipeRep
       o CAT3DCustomRep
       o CAT3DCanonicalRep
     @param iRep
        The input 3D Rep.
     @param ioPolyMesh
        The mesh to be filled in with the data.
     @param ioNormalLayer
        A layer to be filled in with the vertex normals.  
        Set it to 0 to ignore the normal.
     @param ioTriangleVizLayer
        A layer to be filled in with the surface support for each triangle.  
        Set it to 0 to ignore the surface support.
     @param ioPolyBars
     @param ioBarVizLayer
     @param iIgnoreCustomReps
        A flag set to 1 to ignore the custom reps.
     @param iPosition
        A positioning matrix.  By default, the positioning matrix is the identity.
     @param iOnlyGP
        Option to import a specific Face GP.  By default all GPs are imported.
     @return
        S_OK upon successful completion and E_FAIL otherwise.
  */
  static HRESULT Import (CAT3DRep* const iRep,
                         const CATPolyVizContainer* iVizContainer,  // If layers, required container of viz GP's.
                         CATIPolyMesh* ioPolyMesh,
                         CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                         CATPolySurfaceFacetSupportLayer* ioTriangleVizLayer,
                         CATPolyBars* ioPolyBars,
                         CATPolyBarsBarSupportLayer* ioBarVizLayer,
                         const int iIgnoreCustomReps = 0,
                         const CAT4x4Matrix* iPosition = 0,
                         CAT3DBoundingGP* iOnlyGP = 0);

  static HRESULT Import (const CATVizPtrList<CAT3DLineGP>& iLines,
                         const CATVizPtrList<CAT3DEdgeGP>& iEdges,
                         const CATVizPtrList<CAT3DFaceGP>& iFaces,
                         const CATPolyVizContainer* iVizContainer,  // If layers, required container of viz GP's.
                         CATIPolyMesh& ioPolyMesh,
                         CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                         CATPolySurfaceFacetSupportLayer* ioTriangleVizLayer,
                         CATPolyBars* ioPolyBars,
                         CATPolyBarsBarSupportLayer* ioBarVizLayer,
                         const CAT4x4Matrix* iPosition = 0);

public:

  // DO NOT USE!
  static HRESULT ImportWires (CAT3DRep& iRep,
                              const CATPolyVizContainer* iVizContainer,  // Optional container of viz GP.
                              CATIPolyMesh& ioMesh, CATPolyBars& ioBars, CATPolyBarsBarSupportLayer& ioBarsVizLayer);

};

#endif
