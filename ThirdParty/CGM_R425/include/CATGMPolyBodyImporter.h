/* -*-C++-*-*/
#ifndef CATGMPolyBodyImporter_H
#define CATGMPolyBodyImporter_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2014
//
// CATGMPolyBodyImporter 
//
// DESCRIPTION :
// Import a PolyBody into a CATGMPolyBody as a polyhedral CATBody in the ContainerCGM
// with the full BRep description
//
//
// History
//
// Nov. 2014 DPS Creation
// Oct.  2016 DPS This class becomes virtual, derived into CATGMPolyBodyPrivateImporter, for a private use of SmartBehavior
//
//=============================================================================

// For Windows NT export
#include "CATPGMPolyBodyImporter.h" // derivation
#include "GMPolyImportExport.h"    // ExportedBy

#include "CATErrorDef.h"           // HRESULT
#include "CATSysDataType.h"        // NULL
#include "CATTopDefine.h"          // CATOrientation

#include "CATBoolean.h" 
#include "CATSysBoolean.h" 

#include "CATCollec.h"
#include "CATListPV.h"
#include "CATListOfInt.h"
#include "ListPOfCATCell.h"
#include "CATListOfCATCells.h"
#include "CATIACGMLevel.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATMathTransformation;
class CATMapOfIntToInt;

class CATPolyBody;
class CATPolyVertex;
class CATPolyFace;
class CATPolyEdge;
class CATPolyCell;
class CATIPolyMesh;

class CATBody;
class CATFace;
class CATVertex;
class CATEdge;
class CATCell;


/**
* Please, note that the convention of matter side for a CATShell bounding a CATVolume is INWARD,
* opposite to the PolyBody convention  which is always OUTWARD.
* So, importing a volumic set of PolyFaces obviously leads to reverse the global side of the imported CATDomain.
* The default behavior in case of surfacic set of faces consists in reversing the original sides as if the domain was volumic.
*/

class ExportedByGMPolyImportExport CATGMPolyBodyImporter : public CATPGMPolyBodyImporter
{
protected:

  /**
  * Protected constructor for derivation (private use only)
  * Please use CATCreateGMPolyBodyImporter
  */
  CATGMPolyBodyImporter();

public:

  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyImporter();


  //=============================================================================
  // Settings
  //=============================================================================

  virtual void SetMatrixPosition(CATMathTransformation * iMatrix) = 0;

  /*
  * The following option allows the caller to specify the global orientation of 2D-bodies, keeping or reversing the original mesh orientation
  * @param iOriShellVsMesh
  * The relative orientation of the imported 2D-Body, versus the original mesh orientation
  * Only 2 values are accepted : CATOrientationPositive or CATOrientationNegative
  * The current Default behavior is CATOrientationNegative if the option is not called
  */
  virtual void SetSurfacicBodyOrientationVsMesh(const CATOrientation iOriShellVsMesh) = 0;

  /*
  * Option enabling to store the mapping of MeshVertices and MeshTriangles after duplication/transformation
  * in order to retrieve them after Run, thanks to the GetImage() API
  * @param iEnableMeshVerticesMapping
  * Pilots the storage of Mesh Vertices mapping
  * @param iEnableMeshTrianglesMapping
  * Pilots the storage of Mesh Vertices mapping
  */
  virtual void SetMeshMappingKnowledge(CATBoolean iEnableMeshVerticesMapping=TRUE, CATBoolean iEnableMeshTrianglesMapping=FALSE) = 0;

  
#ifdef CATIAR425
  /*
  * Option piloting the segmentation of a single mesh bigger than 1% of the model size
  * > 100 mm in Small Range, > 10 m in Normal Range, > 1 km in Large Range, > 100 km in Extreme Large Range
  * If it's authorized, a segmentation grid is applied on the single mesh in order to split it into several smaller faces.
  * This segmentation leads to have better performances (CPU and memory) in case of next boolean operations.
  * @param iAuthorize
  * enables(TRUE)/disables(FALSE) the segmentation grid in case of big single mesh
  * The segmentation is authorized by default
  */
  virtual void AuthorizeSegmentationGrid(CATBoolean iAuthorize) = 0;
#endif


  //=============================================================================
  // Computation
  //=============================================================================
  /**
  * Compute the polyhedral CATBody from the input CATPolyBody 
  * Returns S_OK if the Body is created without any pathology, else E_FAIL
  */
  virtual HRESULT Run(CATBody * &oResultBody) = 0;



  //=============================================================================
  // Information and Diagnosis
  //=============================================================================

  // Information about the highest domains directly owned by the imported CATBody
  // In each service (one for each dimension), the optional boolean argument allows the caller 
  // to know if the input PolyBody declared containing this dimension.
  // Returns -1 if the query doesn't make sense
  // ----------------------------------------------------------------------------
  virtual int GetNbImportedHighLevelDomains(int iExpectedDimension012or3, CATBoolean * oInLineWithExpectation=NULL) = 0;

  virtual int GetNbImportedVerticesInSpace(CATBoolean * oInLineWithExpectation=NULL) = 0; // idem GetNbDomains(0,...)
  virtual int GetNbImportedWires(CATBoolean * oInLineWithExpectation=NULL) = 0;           // idem GetNbDomains(1,...)
  virtual int GetNbImportedSurfaces(CATBoolean * oInLineWithExpectation=NULL) = 0;        // idem GetNbDomains(2,...)
  virtual int GetNbImportedVolumes(CATBoolean * oInLineWithExpectation=NULL) = 0;         // idem GetNbDomains(3,...)


  // "Non watertight edges" diagnosis
  // The list oImportedEdges is filled only if "Mode Without Failure" has been enabled
  // and its size might be greater than oPolyEdges.Size() in case of duplication
  // Returns TRUE if this diagnosis happens at least once, else returns FALSE
  // ---------------------------------------------------------------------------
  virtual CATBoolean GetNonWatertightPolyEdges(CATListPV &oPolyEdges, CATLISTP(CATCell) * oImportedEdges=NULL) = 0;


  // "Non manifold meshes" diagnosis
  // Returns TRUE if this diagnosis happens at least once, else returns FALSE
  // ---------------------------------------------------------------------------
  virtual CATBoolean GetPolyFacesWithNonManifoldMesh(CATListPV & oPolyFaces) = 0;


  // "Disconnected faces" diagnosis
  // The 2 lists oDisconnectedPolyFaces & oNbPartsByPolyFaces (if required) have the same size
  // The list oImportedFaces is filled only if "Mode Without Failure" has been enabled
  // and then might contain invalid imported faces.
  // Returns TRUE if this diagnosis happens at least once, else returns FALSE
  // ---------------------------------------------------------------------------
  virtual CATBoolean GetDisconnectedPolyFaces(CATListPV & oDisconnectedPolyFaces, CATListOfInt * oNbPartsByPolyFace=NULL, CATLISTP(CATCell) * oImportedFaces=NULL) = 0;


  // Faces with missing edges on their boundaries
  // The list oImportedFaces is filled only if "Mode Without Failure" has been enabled
  // The list oImportedMissingEdges is filled only if "Mode Without Failure" has been enabled
  // Returns TRUE if this diagnosis happens at least once, else returns FALSE
  // ----------------------------------------------------------------------------
  virtual CATBoolean GetPolyFacesWithMissingEdges(CATListPV & oPolyFaces, CATLISTP(CATCell) * oImportedFaces=NULL, CATLISTP(CATCell) * oImportedMissingEdges=NULL) = 0;

    
  // Faces with at least one NonManifold vertex on mesh which doesn't reference any PolyVertex (Mandatory)
  // Returns TRUE if this diagnosis happens at least once, else returns FALSE
  // ----------------------------------------------------------------------------
  virtual CATBoolean GetPolyFacesWithMissingNonManifoldVertices(CATListPV & oPolyFaces, CATListOfInt & oNonManifoldVtxIndexes) = 0;



  // Edges which don't match with the boundaries of their adjacent faces
  // The list oImportedNonMatchingEdges is filled only if "Mode Without Failure" has been enabled
  // Returns TRUE if this diagnosis happens at least once, else returns FALSE
  // ----------------------------------------------------------------------------
  virtual CATBoolean GetPolyEdgesNonLyingOnMeshBoundaries(CATListPV &oPolyEdges, CATLISTP(CATCell) * oImportedNonMatchingEdges=NULL) = 0;


  //=============================================================================
  // Journaling
  //=============================================================================

  virtual CATVertex * GetImage(CATPolyVertex & iPolyVtx) = 0;
  virtual CATEdge   * GetImage(CATPolyEdge   & iPolyEdge, CATOrientation * oRelativeOrientation=NULL) = 0;
  virtual CATFace   * GetImage(CATPolyFace   & iPolyFace, CATOrientation * oRelativeOrientation=NULL) = 0;
  virtual CATCell   * GetImage(CATPolyCell * iPolyCell, CATOrientation * oRelativeOrientation=NULL) = 0;

  // Retrieve image CATFace with Mesh Mapping information driven before Run by SetMeshMappingKnowledge() API
  // Each optional mapping object will be filled only if it has been explicitely requested by iEnableMeshVerticesMapping / iEnableMeshTianglesMapping
  // and only if at least one ID has changed 
  // -> An iso-mapping will be returned as empty with Size() == 0
  virtual CATFace   * GetImage(CATPolyFace   & iPolyFace, const CATIPolyMesh * & oImageMesh, CATMapOfIntToInt * oSourceVtxToImageVtx = NULL,  CATMapOfIntToInt * oSourceTriToImageTri = NULL) = 0;



public:

  /**
  * Iterator to cycle through all the cells of the current domain
  */
  /*
  class Iterator
  {
  public:

    Iterator(const CATGMPolyBodyImporter & iBodyImporter, int iDim=-1); // -1 for all cells, 0 for vertices, 1 for edges, 2 for faces
    ~Iterator();

    // no implementation
    Iterator();
    Iterator(const Iterator& iIterToCopy); 
    Iterator& operator =(const Iterator& iOneOf);


    void Begin ();
    CATBoolean End();
    void operator++ ();

    CATPolyCell   * GetSource();
    CATPolyVertex * GetVertexSource();
    CATPolyEdge   * GetEdgeSource();
    CATPolyFace   * GetFaceSource();

    CATCell       * GetImage();
    CATVertex     * GetVertexImage();
    CATEdge       * GetEdgeImage();
    CATFace       * GetFaceImage();


  private:

    void Restart();

    CATMapOfPtrToPtr::Iterator     _VtxMapIter;
    CATMapOfPtrToPtr::Iterator     _EdgMapIter;
    CATMapOfPtrToPtr::Iterator     _FacMapIter;

    int                            _MinDim;
    int                            _MaxDim;

    int                            _curDim;
    CATCell                      * _curCell;
    CATPolyCell                  * _curPolyCell;
    CATMapOfPtrToPtr::Iterator   * _curMapIterator; 
  };
  */

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyImporter(const CATGMPolyBodyImporter & iOneOf); 
  CATGMPolyBodyImporter & operator =(const CATGMPolyBodyImporter & iOneOf);

};

/**
 * Creates a CATGMPolyBodyImporter.
 * @param iTargetFactory
 * The factory in which the input data will be imported and contained. (MANDATORY)
 * @param iSoftwareConfig
 * The pointer to the SoftwareConfiguration in order to drive the versionning of future modifications
 * Default (9019) closed config with the versioning value of V5R31 SP1 / V6R423 FD01 releases will be considered if iSoftwareConfig is set to null
 * @param iPolyBodyToImport
 * The input PolyBody to import into a CATBody
 * @return [out]
 * The pointer to the created operator. To be deleted after use.
 */
ExportedByGMPolyImportExport CATGMPolyBodyImporter * CATCreateGMPolyBodyImporter(CATGeoFactory * iTargetFactory, CATSoftwareConfiguration * iSoftwareConfig, CATPolyBody * iPolyBodyToImport); 

#endif
