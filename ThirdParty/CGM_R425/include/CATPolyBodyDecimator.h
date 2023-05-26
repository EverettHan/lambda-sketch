// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyDecimator.h
//
//===================================================================
// August 2011 Creation: NDO
// May    2018 Modification JXO: DoCheckForSelfIntersections
//===================================================================
#ifndef CATPolyBodyDecimator_H
#define CATPolyBodyDecimator_H

#include "PolyBodyDecimate.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATPolyDeprecated.h"
#include "CATPolyMeshTypeVisitor.h"

class CATPolyBody;
class CATIPolyBodyFrameLayers;
class CATPolyBodyBarGraph;

class CATPolyBodyDecimatorObserver;
class CATPolyBodyDecimatorEdgeQuery;
class CATPolyBodyDecimatorCaptureObserver;
class CATPolyBodyUnaryObserver;
class CATMathTransformation;
class CATPolyBodyDecimatorImpl;
class CATMapOfPtrToPtr;
class CATTolerance;

/**
 * Operator that decimates a CATPolyBody.
 * It decimates the discrete geometry (CATIPolySurface and CATIPolyCurve) until a target deviation
 * parameter between the input CATPolyBody and decimated CATPolyBody is reached.
 *
 * This operator does not simplify the topology of the CATPolyBody.  
 *
 * The operator can process models with several layers of vertex positions, normals and textures
 * such as in an animated sequence.
 *
 * The input CATPolyBody and its optional layers do not need to be editable.
 *
 * @see CATPolyBodyJoinDecimateBuilder
 */
class ExportedByPolyBodyDecimate CATPolyBodyDecimator
{

public:

  CATPolyBodyDecimator (CATPolyBodyDecimatorObserver* iObserver = 0);

  ~CATPolyBodyDecimator ();

public:

/** @name Settings
    @{ */

  /**
   * Sets the chordal deviation that is not to be exceeded between the input and decimated CATPolyBody instances.
   * Decimation stops when further processing would exceed this chordal deviation. 
   * @param iChordalDeviation
   *   The input chordal deviation.
   * @param iChordalDeviationEdge
   *   An optional chordal deviation which can be tighter for the edges.
   *   (For instance to prevent, shrinking of the mesh or excessive displacement of the edges across the surface.)
   */
  void SetChordalDeviation (const double iChordalDeviation, const double iChordalDeviationEdge = 0);

  /**
   * Sets a flag to prevent the collapse and change of any bar that is not adjacent to two triangles
   * (either on the same surface or across an edge.)
   * By default the boundary-bars are not frozen.
   * @param iDoFreeze
   *   The input flag.
   */
  void DoFreezeBoundaryBars (CATBoolean iDoFreeze);

  /**
   * Sets a flag to use and process the data in the normal layer.
   */
  void DoProcessNormalLayer (CATBoolean iUseNormalLayer);

  /**
   * Sets a flag to use and process the data in the texture layer.
   */
  void DoProcessTextureLayer (CATBoolean iUseTextureLayer);

  /**
   * Includes the nD texture coordinates for the simplification of the bars and placement of the nodes.
   * @param iDim
   *   Number of constraints.  
   * @param iWeight
   *   The weight given to the texture coordinate.
   */
  void DoProcessTextureCoordinatesConstraints (const unsigned int iDim, const double iWeight[]);
  void DoProcess1DTextureCoordinates (CATBoolean iFlag, const double iWeight = 1)
  {
    if(iFlag)
    {
      double Weight[1] = {iWeight};
      DoProcessTextureCoordinatesConstraints(1, Weight);
    }
  }

  /**
   * Sets the flag to stitch the bars in a preprocessing step to decimation.
   * By default, this option is turned off.
   */
  void DoStitching (CATBoolean iDoStitching);

  /**
   * Turns on an option for the construction of all boundary edges.
   * By default, this option is turned off.  Edges will be constructed along boundaries only if they
   * have been declared as such in the graph.
   */
  void DoCreateBoundaryEdges (CATBoolean iDoCreateBoundaryEdges);

  /**
  * Sets the flag to add an additional restriction to conserve texture coordinates inside original charts.
  * By default, this option is turned off.
  * @param iTextureCoordinatesInsideCharts
  *        If set to TRUE, activates this restriction.
  */
  void DoKeepTextureCoordinatesInsideCharts(CATBoolean iDoKeepTextureCoordinatesInsideCharts);

/** @} */

public:

/** @name Temporary settings for use until the new decimation becomes official
    @{ */

  /**
   * The new decimation is activated by default (Option set to <tt>TRUE</tt>).
   * To use a previous version of the operation (called custom decimation)
   * set this option to <tt>FALSE</tt>.
   * There is no need to call this option to use the new decimation.
   */
  void DoUseNewDecimation (CATBoolean iUseNewDecimation);

  /**
   * For custom decimation only, selects the frame to decimate.
   * All other frames will be identical after decimation.
   * This does not apply to the new decimation which can process all the frames.
   */
  void SelectFrame (const unsigned int iFrame);

  /**
   * If set to TRUE, then an extra step is used at the end to check for self intersections and to tries to repair them, if any.
   * Note that it may take a long time (usually the same amount of time as the decimation itself.)
   * Default is FALSE.
   * @param iTol
   *        Must be set to a non null value for the setting to work. This CATTolerance object must live at least as long as the operator.
   */
  void DoCheckForSelfIntersections(CATBoolean iDoCheckForSelfIntersections = FALSE, const CATTolerance * iTol = 0);
  /**
   * Sets a flag to avoid producing duplicate triangles (i.e., multiple
   * triangles with the same vertices).  Decimation only rarely produces this
   * sort of problem and the check has a slight performance cost, so by default,
   * the check is not done.
   */
  void DoAvoidDuplicateTriangles(CATBoolean iAvoidDuplicateTriangles);
  /** @} */

public:

/** @name Automatic Mode
    @{ */

  /**
   * Runs the operator.
   * @param iPolyBody
   *   The input CATPolyBody to decimate.  This instance is not modified.
   * @param iMatrix
   *   An optional input CATMathTransformation applied to the CATPolyBody data.
   *   This input parameter can be null.
   * @param iQuery
   *   An optional parameter used to query the edges from the CATPolyBody.  
   *   If the query replies <tt>TRUE</tt> for an edge then the faces adjacent to the edge are merged.
   *   If set to null, then no edge is removed.
   * @param oPolyBody
   *   The decimated CATPolyBody created by this operator.  This instance must be released.
   * @param iObserver
   *   An observer to obtain the mappings of the resulting cells to the input operand cells.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the CATPolyBody is successfully decimated to the target sag.
   *   <li> <tt>E_FAIL</tt> if an error occurs.
   * </ul>
   */
  HRESULT Run (const CATPolyBody& iPolyBody, const CATMathTransformation* iMatrix, 
               CATPolyBodyDecimatorEdgeQuery* iQuery,
               CATPolyBody*& oPolyBody, CATPolyBodyUnaryObserver* iObserver, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);

  // Do not use.
  HRESULT Run (const CATPolyBody& iPolyBody, const CATMathTransformation* iMatrix, 
               CATPolyBody*& oPolyBody, CATPolyBodyUnaryObserver* iObserver, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);


  /**
   * Runs the operator.
   * @param iPolyBody
   *   The input CATPolyBody to decimate.  This instance is not modified.
   * @param iMatrix
   *   An optional input CATMathTransformation applied to the CATPolyBody data.
   *   This input parameter can be null.
   * @param oPolyBody
   *   The decimated CATPolyBody created by this operator.  This instance must be released.
   * @param ioMapOutputToInputPolyCells
   *   An optional map from the output CATPolyCell to the input CATPolyCell.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the CATPolyBody is successfully decimated to the target sag.
   *   <li> <tt>E_FAIL</tt> if an error occurs.
   * </ul>
   */
  HRESULT Run (const CATPolyBody& iPolyBody, const CATMathTransformation* iMatrix, 
               CATPolyBody*& oPolyBody, CATMapOfPtrToPtr* ioMapOutputToInputPolyCells = 0);

  /**
   * Runs the operator.
   * @param iPolyBody
   *   The input CATPolyBody defining the cell and mesh topology of the model to decimate.
   * @param iFrameLayers
   *   The layers associated to the cells of the CATPolyBody for the various frames.
   * @param iMatrix
   *   An optional input CATMathTransformation applied to the CATPolyBody data.
   *   This input parameter can be null.
   * @param oPolyBody
   *   A new CATPolyBody representing the decimated model.
   * @param oFrameLayers
   *   The layers associated to the cells of the decimated CATPolyBody.
   * @param ioMapOutputToInputPolyCells
   *   An optional map from the output CATPolyCell to the input CATPolyCell.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the CATPolyBody and its frames were successfully decimated to the target sag.
   *   <li> <tt>E_FAIL</tt> if an error occurs.
   * </ul>
   */
  HRESULT Run (const CATPolyBody& iPolyBody, const CATIPolyBodyFrameLayers& iFrameLayers, 
               const CATMathTransformation* iMatrix,
               CATPolyBody*& oPolyBody, CATIPolyBodyFrameLayers*& oFrameLayers, 
               CATMapOfPtrToPtr* ioMapOutputToInputPolyCells = 0);

/** @} */

public:

/** @name Manual Mode
    @{ */

  /**
   * Initializes the operator for decimation of a CATPolyBody.
   * @param iPolyBody
   *   The input CATPolyBody to decimate.  This instance is not modified.
   * @param iFrameLayers
   *   In option, the layers associated to the cells of the CATPolyBody.
   * @param iMatrix
   *   An optional input CATMathTransformation applied to the CATPolyBody data.
   *   This input parameter can be null.
   * @param iQuery
   *   An optional parameter used to query the edges from the CATPolyBody.  
   *   If the query replies <tt>TRUE</tt> for an edge then the faces adjacent to the edge are merged.
   *   If set to null, then no edge is removed.
   */
  HRESULT Initialize (const CATPolyBody& iPolyBody, const CATIPolyBodyFrameLayers* iFrameLayers = 0, const CATMathTransformation* iMatrix = 0,
                      CATPolyBodyDecimatorEdgeQuery* iQuery = 0);


  /**
   * Performs a decimation step.
   * @param oBarGraph
   *   An optional argument for acces to the bar graph after a decimation step.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if a decimation step is performed successfully.
   *   <li> <tt>S_FALSE</tt> if the end has been reached without further decimation of the model.
   *   <li> <tt>E_FAIL</tt> if an error occured.
   * </ul>
   */
  HRESULT Step ();

  /**
   * Finalizes the decimation and constructs the resulting CATPolyBody.
   * @param oPolyBody
   *   The decimated CATPolyBody created by this operator.  This instance must be released.
   * @param oFrameLayers
   *   The layers associated to the cells of the output CATPolyBody.
   *   This instance may be null if there were no input frames.
   * @param iObserver
   *   An observer to obtain the mappings of the resulting cells to the input operand cells.
   * @param oMeshType
   *   You may choose type between ePolyMeshImpl (fully editable), ePolyCompactMesh (compact) and ePolyCompactMeshConst (compact and const)
   */
  HRESULT Finalize (CATPolyBody*& oPolyBody, CATIPolyBodyFrameLayers*& oFrameLayers,
                    CATPolyBodyUnaryObserver* iObserver, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);

  /**
   * Finalizes the decimation and constructs the resulting CATPolyBody.
   * @param oPolyBody
   *   The decimated CATPolyBody created by this operator.  This instance must be released.
   * @param oFrameLayers
   *   The layers associated to the cells of the output CATPolyBody.
   *   This instance may be null if there were no input frames.
   * @param ioMapOutputToInputPolyCells
   *   An optional map from the output CATPolyCell to the input CATPolyCell.
   */
  POLY_DEPRECATED ("Do not use Finalize with CATMapOfPtrToPtr.  Use instead CATPolyBodyUnaryObserver.", 
    HRESULT Finalize (CATPolyBody*& oPolyBody, CATIPolyBodyFrameLayers*& oFrameLayers,
                      CATMapOfPtrToPtr* ioMapOutputToInputPolyCells = 0));

/** @} */

public: 
//private:

  /**
   * Constructs a new bar graph for a CATPolyBody with copy of various editable data layers 
   * (positions, normals, texture coordinates).
   */
  static CATPolyBodyBarGraph* NewBarGraph (const CATPolyBody& iPolyBody, const CATIPolyBodyFrameLayers* iFrameLayers = 0,
                                           const CATMathTransformation* iPositionMatrix = 0,
                                           CATBoolean iWithNormals = FALSE, unsigned int iTextureDimension = 0, 
                                           CATBoolean iDoProcess1DTextureCoordinates = FALSE,
                                           CATBoolean iDoKeepTextureCoordinatesInsideCharts = FALSE);

private:

  CATPolyBodyDecimatorCaptureObserver* _Observer;

  CATPolyBodyDecimatorImpl* _Decimator;

};

#endif
