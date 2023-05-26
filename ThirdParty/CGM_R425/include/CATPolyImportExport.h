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
#ifndef CATPolyImportExport_H
#define CATPolyImportExport_H

#include "PolyImportExport.h"
#include "CATErrorDef.h"  // Definition of HRESULT
#include "CATListPV.h"

#include "CATPolyCurveList.h"
#include "CATPolyMeshVertexLineList.h"

class CATIPolyMesh;
class CATPolyMeshVertexNNormalsLayer;
class CATPolyMeshTriangleVizLayer;
class CATIPolyMeshTriangleIterator;

class CATPolyBars;
class CATPolyBarsBarVizLayer;

class CATPolyVizContainer;
class CATMapOfPtrToInt;

class CAT3DRep;
class CAT3DBagRep;
class CATSurfacicRep;
class CAT3DLineGP;
class CAT3DEdgeGP;
class CAT3DFaceGP;
class CAT3DBoundingGP;
class CAT4x4Matrix;
class CATGraphicAttributeSet;
class VisPrimitiveGroupRep;

template <class T> class CATVizPtrList;


class ExportedByPolyImportExport CATPolyImportExport
{

public:

  /*
   * *** IMPORT WITH HEALING *** 
   * Import a list of Edge GPs and Face GPs into a CATPolyMesh with layers.
   * Optional layers of Viz IDs can be filled.  The Viz IDs are found from the Viz Container.
   * (The GPs should also be in the Viz Container prior to the call.)
   *
   * In this import:
   *   All vertices from the faces, edges and lines having identical coordinates are merged.
   */
  static HRESULT ImportWithHealing (const CATVizPtrList<CAT3DLineGP>& iLines,
                                    const CATVizPtrList<CAT3DEdgeGP>& iEdges,
                                    const CATVizPtrList<CAT3DFaceGP>& iFaces,
                                    CATIPolyMesh& ioPolyMesh,
                                    CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                                    CATPolyMeshTriangleVizLayer* ioTriangleVizLayer,
                                    CATPolyBars* ioPolyBars,
                                    CATPolyBarsBarVizLayer* ioBarVizLayer,
                                    CATPolyVizContainer* ioVizContainer,
                                    const CAT4x4Matrix* iPosition = 0);

  /*
   * *** IMPORT WITH STITCHING (stitch faces along edges) ***
   * Import a list of Edge GPs and Face GPs into a CATPolyMesh with layers.
   * Optional layers of Viz IDs can be filled.  The Viz IDs are found from the Viz Container.
   * (The GPs should also be in the Viz Container prior to the call.)
   *
   * In this import:
   *   The face data are stitched along the edges.  If there are no edges, no stitching occur.
   */
/*
  static HRESULT Import (const CATVizPtrList<CAT3DLineGP>& iLines,
                         const CATVizPtrList<CAT3DEdgeGP>& iEdges,
                         const CATVizPtrList<CAT3DFaceGP>& iFaces,
                         CATIPolyMesh& ioPolyMesh,
                         CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                         CATPolyMeshTriangleVizLayer* ioTriangleVizLayer,
                         CATPolyCurveList* ioCurveList,
                         CATPolyVizContainer* ioVizContainer,
                         CATMapOfPtrToInt* ioMapFromPolyCurveToVizKey,
                         const CAT4x4Matrix* iPosition = 0);
*/

public:

  //
  // Import of a CAT3DRep into a CATIPolyMesh + Layers.
  // Raw importer of the CAT3DRep data into CATIPolyMesh + Layers with stitching of the seams between 
  // faces according to the edge data.  (It includes supports of edge and line GPs.)
  // 

  /*
     Import a CAT3DRep into a CATIPolyMesh with optional layers for:
       o Vertex normals (arbitrary number of normals for each vertex.)
       o Surface support associated to each triangle.
       o List of CATIPolyCurve's associated to the edges and lines of the CAT3DRep.
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
        A mesh to be filled in with the data.
     @param ioNormalLayer
        A layer to be filled in with the vertex normals.  
        Set it to 0 to ignore the normals.
     @param ioTriangleVizLayer
        A layer to be filled in with the surface support for each triangle.  
        Set it to 0 to ignore the surface support.
     @param ioCurves
        A list of CATIPolyCurve's.
        Set it to 0 to ignore edge and line GP's.
     @param ioVizContainer
        The container of GPs that are imported.
        Any imported GP that is not in the container will be added to it.
     @param oMapFromPolyCurveToVizKey
        A mapping from a CATIPolyCurve to the key of the GP in the CATPolyVizContainer.
     @param iIgnoreCustomReps
        A flag set to 1 to ignore the custom reps.
     @param iPosition
        A positioning matrix.  By default, the positioning matrix is the identity.
     @return
        S_OK upon successful completion and E_FAIL otherwise.
  */
  static HRESULT BuildPolyMeshFromRep (CAT3DRep* const iRep,
                                       CATIPolyMesh& ioPolyMesh,
                                       CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                                       CATPolyMeshTriangleVizLayer* ioTriangleVizLayer,
                                       CATPolyCurveList* ioCurveList,
                                       CATPolyVizContainer* ioVizContainer,
                                       CATMapOfPtrToInt* ioMapFromPolyCurveToVizKey,
                                       const int iIgnoreCustomReps = 0,
                                       const CAT4x4Matrix* iPosition = 0);

public:

  //
  // Import of a CAT3DRep into a CATIPolyMesh + Layers.
  // Import that includes "healing" through the use of a hash table for the points.
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
     @param iIgnoreCustomReps
        A flag set to 1 to ignore the custom reps.
     @param iPosition
        A positioning matrix.  By default, the positioning matrix is the identity.
     @param iOnlyGP
        Option to import a specific Face GP.  By default all GPs are imported.
     @return
        S_OK upon successful completion and E_FAIL otherwise.
  */
  static HRESULT BuildPolyMeshFromRep (CAT3DRep* const iRep,
                                       CATIPolyMesh* ioPolyMesh,
                                       CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                                       CATPolyMeshTriangleVizLayer* ioTriangleVizLayer,
                                       const int iIgnoreCustomReps = 0,
                                       const CAT4x4Matrix* iPosition = 0,
                                       CAT3DBoundingGP* iOnlyGP = 0);

  static HRESULT BuildPolyMeshFromRep (CAT3DRep* const iRep,
                                       CATIPolyMesh* ioPolyMesh,
                                       CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                                       CATPolyMeshTriangleVizLayer* ioTriangleVizLayer,
                                       CATPolyBars* ioPolyBars,
                                       CATPolyBarsBarVizLayer* ioBarVizLayer,
                                       const int iIgnoreCustomReps = 0,
                                       const CAT4x4Matrix* iPosition = 0,
                                       CAT3DBoundingGP* iOnlyGP = 0);

public:

  //
  // Export of a CATIPolyMesh with Layers into a CATSurfacicRep.
  //

  /*
     Build a surfacic reps from a CATIPolyMesh.
     Optional arguments are normal and surface support layers and a triangle iterator.
     @param iTriangleIter
       An iterator going through the triangle of the mesh that are to be exported into the surfacic rep.
     @param iMesh
       The input mesh.
     @param iNormalLayer
       An optional layer with the vertex normals.
     @param iTriangleVizLayer
       An optional layer with the surface supports for the triangles of the mesh.
       Graphic attributes are copied from this layer.
     @param iBars
       An optional argument with the bars composing the edges to be exported.
     @param iBarVizLayer
       An optional layer with the curve supports for the bars on which edges lie.
       Graphic attributes are copied from this layer.
     @param oSurfacicRep
       The surfacic rep that is constructed.
     @param iType
       The type of the surfacic rep to be constructed.  By default, it will adopt the type of the input rep obtained from the layers.
  */
  static HRESULT BuildSurfacicRepFromPolyMesh (CATIPolyMeshTriangleIterator& iTriangleIter,
                                               const CATIPolyMesh& iMesh,
                                               const CATPolyMeshVertexNNormalsLayer* iVertexNormalLayer,
                                               const CATPolyMeshTriangleVizLayer* iTriangleVizLayer, 
                                               const CATPolyBars* iBars,
                                               const CATPolyBarsBarVizLayer* iBarVizLayer,
                                               CATSurfacicRep*& oSurfacicRep,
                                               const int iType = -1 /* Adopt type from input rep (layers). */,
                                               CATListPV * oMapsFaceVertexToMeshVertex = 0 );

  /*
     Build a surfacic rep with line GPs from CATPolyBars.
     An optional argument is a curve support layer.
     @param iMesh
       The mesh with the coordinates of the points.
     @param iBars
       The bars composing the wires to be exported.
     @param iBarVizLayer
       An optional layer with the curve supports for the bars defining the wires.
       Graphic attributes are copied from this layer.
     @param oSurfacicRep
       The surfacic rep that is constructed.
  */
  static HRESULT BuildSurfacicRepFromPolyBars (const CATIPolyMesh& iMesh,
                                               const CATPolyBars& iBars,
                                               const CATPolyBarsBarVizLayer* iBarVizLayer,                                                           
                                               CATSurfacicRep*& oSurfacicRep);

public:

  //
  // Converter of a list of CATIPolyCurve's into a CATPolyBars object.
  //

  /*
     Build PolyBars from a list of CATPolyCurve's.
     @param iCurveList
       The list of CATPolyCurve's.
     @param iVizContainer
       The container of GP's.
     @param iMapFromPolyCurveToVizKey
       The mapping of a CATIPolyCurve to its key of its GP support in the viz container.
     @param ioPolyBars
       The CATPolyBars object that is filled in with the curve data.
     @param ioBarsVizLayer
       An optional layer for the keys of the viz support.
   */
  static HRESULT BuildPolyBarsFromPolyCurves (const CATPolyCurveList& iCurveList,
                                              const CATPolyVizContainer& iVizContainer,
                                              const CATMapOfPtrToInt& iMapFromPolyCurveToVizKey,
                                              CATIPolyMesh& ioMesh,
                                              CATPolyBars& ioPolyBars, 
                                              CATPolyBarsBarVizLayer* ioBarsVizLayer);

  //static HRESULT CATPolyImportExport::BuildRepFromTerrainMesh (const CATIPolyMesh& iMesh,
  //                                                             CAT3DRep*& oRep);

public:

  //
  // METHODS TO BE REMOVED.
  //

  // GET RID OF ME! I should be part of the main import method!
  static HRESULT ImportWires (CAT3DRep& iRep,
                              CATIPolyMesh& ioMesh, CATPolyBars& ioBars, CATPolyBarsBarVizLayer& ioBarVizLayer);

  // OBSOLETE.
  static CATSurfacicRep * GetSurfacicRepFromPolyMesh (CATIPolyMesh * pNewMesh, CATGraphicAttributeSet * att = 0);

  // DO NOT USE.
  static HRESULT BuildPolyMeshFromRep (CAT3DRep* const iRep,
                                       CATIPolyMesh& ioPolyMesh,
                                       CATPolyMeshVertexNNormalsLayer* ioVertexNormalLayer,
                                       CATPolyMeshTriangleVizLayer* ioTriangleVizLayer,
                                       CATPolyMeshVertexLineList* ioMeshCurves,
                                       const int iIgnoreCustomReps = 0,
                                       const CAT4x4Matrix* iPosition = 0,
                                       CAT3DBoundingGP* iOnlyGP = 0)
  {
    return E_FAIL;
  }

};

#endif
