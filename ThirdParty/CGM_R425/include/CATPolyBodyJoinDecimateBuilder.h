// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyJoinDecimateBuilder.h
//
//===================================================================
// August 2012  Creation: ZFI
//===================================================================
#ifndef CATPolyBodyJoinDecimateBuilder_H
#define CATPolyBodyJoinDecimateBuilder_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "PolyBodyDecimate.h"
#include "CATMapOfIntToInt.h"
#include "CATPolyMeshTypeVisitor.h"
#include "CATListOfDouble.h"
#include "CATMapOfPtrToInt.h"
#include "CATSetOfInt.h"
#include "CATListPV.h"
#include "CATMathConstant.h"
#include <vector>

class CATPolyBody;
class CATPolyCell;
class CATMathTransformation;
class CATPolyBodyJoinDecimateBuilderObserver;
class CATPolyBodyBarGraphTargetPercentageObserver;
class CATPolyBodyBarGraphDecimator;
class CATPolyBodyBarGraph;
class CATPolyBodyBarGraphBuilder;
class CATPolyBodyBarGraphEdgeQuery;
class CATPolyBodyBarGraphDebugObserver;
class CATMathBox;


/**
* Operator that heals and decimates one or several CATPolyBody.
* It generates a new decimated CATPolyBody.
*
* The input CATPolyBody and its optional layers do not need to be editable.
*
* @see CATPolyBodyDecimator
*/
class ExportedByPolyBodyDecimate CATPolyBodyJoinDecimateBuilder
{

public:

  CATPolyBodyJoinDecimateBuilder(CATPolyBodyJoinDecimateBuilderObserver* iObserver = 0);

  ~CATPolyBodyJoinDecimateBuilder();

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
  void SetChordalDeviation(const double iChordalDeviation, const double iChordalDeviationEdge = 0);

  /**
  * Sets a flag to prevent the collapse and change of any bar that is not adjacent to two triangles
  * (either on the same surface or across an edge.)
  * By default the boundary-bars are not frozen.
  * @param iDoFreeze
  *   The input flag.
  * @param iAngleTol
  *   If negative, all boundary bars are frozen
  *   else, all boundary points whose angle (from boundary bars) deviation from flat angle is higher than tolerance 
  *   are considered as vertices and therefore frozen during boundary decimation.
  */
  void DoFreezeBoundaryBars(CATBoolean iDoFreeze, double iAngleTol = -1.0);

  /**
  * Sets the flag to stitch the bars in a preprocessing step to decimation.
  * By default, this option is turned off.
  */
  void DoStitching(CATBoolean iDoStitching, double iStitchingTolerance);

  /**
  * Turns on an option for the construction of all boundary edges.
  * By default, this option is turned off.  Edges will be constructed along boundaries only if they
  * have been declared as such in the graph.
  */
  void DoCreateBoundaryEdges(CATBoolean iDoCreateBoundaryEdges);

  /**
   * Turns on an option for the construction of all edges in the result CATPolyBody
   * By default, this option is turned on. Edges will be constructed edge bars.
   * If turned off, the result CATPolyBody won't contain edges.
   */
  void DoCreateEdges(CATBoolean iDoCreateEdges);

  /**
  * Sets a flag to use and process the data in the texture layer.
  */
  void DoProcessTextureLayer(CATBoolean iUseTextureLayer);

  /**
  * Includes the 1D texture coordinate for the simplification of the bars and placement of the nodes.
  * @param iWeight
  *   The weight given to the texture coordinate.
  */
  void DoProcess1DTextureCoordinates(CATBoolean iFlag, const double iWeight = 1);

  /**
  * Includes the nD texture coordinates for the simplification of the bars and placement of the nodes.
  * @param iDim
  *   Number of constraints.
  * @param iWeight
  *   The weights given to the texture coordinates.
  */
  void DoProcessTextureCoordinatesConstraints(const int iDim, const double iWeight[]);

  /**
   * Sets a flag to use and process the data in the layer specified by its identifier.
   */
  void DoProcessDataLayer(const CATUnicodeString& iIdentifier);


  /**
  * Sets a flag to merge all faces into a unique face before running the operator.
  * Adjacent faces (joined by edges) will be merged into a contiguous face.
  * @param iAngleForSmoothEdges
  *   If set to a positive or null value, will be used as the minimum value (Radian) for the normals around an edge vertex to be considered sharp.
  *   Any smaller value and the edge vertex will be considered smooth, and the adjacent faces merged.
  *   The default value (-1.) ensure all faces are merged.
  *   If called with iFlag == FALSE, but iAngleForSmoothEdges set to a positive or null value, then edges will be created anywhere a bar is considered sharp.
  */
  void DoMergeFaces(CATBoolean iFlag, double iAngleForSmoothEdges = -1. /*CATPIBY4*/);

  /**
  * Enable target percentage of triangles as additional condition to stop decimation alongside deviation.
  * @param iFlag
  *   The input flag.
  * @param iTarget
  *   Percentage value (between 0 and 1).
  */
  void DoDecimateTargetPercentage(CATBoolean iFlag, double iTarget);

  /**
  * Enable target percentage of triangles per Polybody face groups as additional condition to stop decimation alongside deviation.
  * @param iFlag
  *   The input flag.
  * @param iTargetList
  *   Percentage value for each group (between 0 and 1).
  * @param iMapOfFaceToTarget
  *   Map of CATPolyFace * to their percentage index in iTargetList to describe face groups.
  */
  void DoDecimateTargetPercentage(CATBoolean iFlag, const CATListOfDouble &iTargetList, const CATMapOfPtrToInt &iMapOfFaceToTarget);

  /**
   * For NavReps, allow the merge of edge bars (default is off)
   */
  void DoMergeEdgeBars(CATBoolean iDoMergeEdgeBars);

  /**
   * For Navreps, we have to be strict on the percentage if we don't want a 0 triangle result (default is off).
   */
  void DoStrictPercentage(CATBoolean iDoStrictPercentage);
  
  /**
  *For Navreps, we have to ensure at least a 1 triangle result because decimation topology checks are not working anymore(default is off).
  */
  void DoEnsureOneTriangle(CATBoolean iDoEnsureOneTriangle);

  /*
   * Allow for (macro) vertex merge when it does not introduce any face collapse.
   * Note that this option will de-activate the texture restrictions (texture charts may be bigger and overlap)
   */
  void DoAllowVertexMerge(CATBoolean iAllow = TRUE);

  /**
   * When using angles for the merge of the faces and the post process of sharp edges,
   * do not create full edges. It creates less edges but should guarantee a valid output,
   * provided the input is valid.
   * Default is off (all edges are created.)
   **/
  void DoNotCreateFullEdges(CATBoolean iFlag);
  /** @} */

public:

  /** @name Observers
  @{ */

  /**
  * Input Cell Observer.
  * This observer associates the cells from the input CATPolyBody to unique identification tags.
  * @see OutputCellObserver
  */
  class InputCellObserver
  {
  public:

    virtual void AssociatePolyCellAndTag(CATPolyCell* iInputCell, const unsigned int iTag) = 0;

    virtual void ReactToAddPolyBody(const unsigned int iOutputPBIdx) {};

  };

  /**
  * Output Cell Observer.
  * This observer associates the identification tags to the cells from the output CATPolyBody.
  * @see InputCellObserver
  */
  class OutputCellObserver
  {
  public:

    virtual void AssociateTagAndPolyCell(const unsigned int iTag, CATPolyCell* iOutputCell) = 0;

    virtual void AssociateTagAndPolyBodyIndex(const unsigned int iTag, unsigned int &) {}

  };

public:

  /** @name Input Data
  @{ */

  /**
  * Adds a CATPolyBody to the operator for healing and decimation.
  * Several CATPolyBody can be added in this manner for concatenation to the operator.
  * @param iPolyBody
  *   The input CATPolyBody.
  * @param iPositionMatrix
  *   The position of the input CATPolyBody.
  * @param iCellObserver
  *   An observer to associate the cells of the input CATPolyBody to unique identification tags.
  * @param iRequestNewOutputPolyBody
  *   If true, iPolyBody and every subsequently added polybody with iRequestNewOutputPolyBody == false will be grouped into the same output polybody
  *   To have one output polybody per input polybody, call AddPolyBody with iRequestNewOutputPolyBody == true each single time
  *   Due to the way decimation works, there are a couple of limitations with this option:
  *     - DoCreateBoundaryEdges and DoCreateEdges will be ignored
  *     - DoMergeFaces will be ignored as well
  *     - Output bodies' domain dimensions won't be set
  *   Call the multi-polybody variants of Run/BuildBolyBody/etc methods after setting this option to true
  */
  HRESULT AddPolyBody(const CATPolyBody& iPolyBody, const CATMathTransformation* iPositionMatrix = 0, InputCellObserver* iCellObserver = 0, bool iRequestNewOutputPolyBody = false);

  /** @} */

public:

  /** @name Automatic Mode
  @{ */

  /**
  * Runs the operator.
  * @param oPolyBody
  *   The output CATPolyBody.
  * @param iCellObserver
  *   An observer to associate the identification tags to the cells from the output CATPolyBody.
  */
  HRESULT Run(CATPolyBody*& oPolyBody, OutputCellObserver* iCellObserver = 0, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);

  /**
  * Runs the operator.
  * @param oPolyBody
  *   The output CATPolyBody.
  * @param iQuery
  *   An optional parameter used to query the edge-bars in the graph.
  *   If the query replies <tt>TRUE</tt> then the faces adjacent to the edge are merged.
  *   If set to null, then no edge is removed.
  * @param iCellObserver
  *   An observer to associate the identification tags to the cells from the output CATPolyBody.
  */
  HRESULT Run(CATPolyBody*& oPolyBody, CATPolyBodyBarGraphEdgeQuery* iQuery, OutputCellObserver* iCellObserver = 0, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);

  /**
  * Runs the operator in multi-polybodies mode. See AddPolyBody for further information.
  * @param oPolyBodies
  *   The output CATPolyBody objects.
  * @param iQuery
  *   An optional parameter used to query the edge-bars in the graph.
  *   If the query replies <tt>TRUE</tt> then the faces adjacent to the edge are merged.
  *   If set to null, then no edge is removed.
  * @param iCellObserver
  *   A list of CATPolyBodyJoinDecimateBuilder::OutputCellObserver (one per PolyBody) to associate the identification tags to the cells from the output CATPolyBody.
  */
  HRESULT Run(CATListPV& oPolyBodies, CATPolyBodyBarGraphEdgeQuery* iQuery = 0, CATListPV* iCellObservers = 0, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);

  /** @} */

public:

  /** @name Manual Mode
  @{ */

  /**
  * Initializes the operator after addition of the input CATPolyBody.
  * @param iQuery
  *   An optional parameter used to query the edge-bars in the graph.
  *   If the query replies <tt>TRUE</tt> then the faces adjacent to the edge are merged.
  */
  HRESULT Initialize(CATPolyBodyBarGraphEdgeQuery* iQuery = 0);

  /**
  * Performs a decimation step.
  * <ul>
  *   <li> <tt>S_OK</tt> if a decimation step is performed successfully.
  *   <li> <tt>S_FALSE</tt> if the end has been reached without further decimation of the model.
  *   <li> <tt>E_FAIL</tt> if an error occured.
  * </ul>
  */
  HRESULT Step();

  /**
  * Builds a CATPolyBody from the current state of the decimation data.
  * This method can be called several times to get intermediate decimation results.
  * It should be called before the call to Finalize.
  * @param oPolyBody
  *   The output CATPolyBody.
  * @param iCellObserver
  *   An observer to associate the identification tags to the cells from the output CATPolyBody.
  * @param oMeshType
  *   You may choose type between ePolyMeshImpl (fully editable), ePolyCompactMesh (compact) and ePolyCompactMeshConst (compact and const)
  */
  HRESULT BuildPolyBody(CATPolyBody*& oPolyBody, OutputCellObserver* iCellObserver = 0, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);

  /**
  * Builds multiple CATPolyBody objects from the current state of the decimation data.
  * This method can be called several times to get intermediate decimation results.
  * It should be called before the call to Finalize.
  * See AddPolyBody for further information.
  * @param oPolyBodies
  *   The output CATPolyBody objects.
  * @param iCellObservers
  *   A list of CATPolyBodyJoinDecimateBuilder::OutputCellObserver (one per PolyBody) to associate the identification tags to the cells from the output CATPolyBody.
  * @param oMeshType
  *   You may choose type between ePolyMeshImpl (fully editable), ePolyCompactMesh (compact) and ePolyCompactMeshConst (compact and const)
  */
  HRESULT BuildPolyBodies(CATListPV& oPolyBodies, CATListPV *iCellObservers = 0, CATPolyMeshTypeVisitor::MeshType oMeshType = CATPolyMeshTypeVisitor::ePolyCompactMesh);

  /**
  * Finalizes the operator after construction of the output CATPolyBody.
  */
  HRESULT Finalize();

  int GetNbBars();
  HRESULT GetBoundingBox(CATMathBox& oBoundingBox) const;

  /**
  * Sets the flag to stitch the gaps inside faces.
  * By default, this option is turned off.
  * Note that this can't be activated if stitching is not activated
  */
  void DoStitchingInsideFaces(CATBoolean iDoStitching, double iStitchingToleranceInsideFace);

  /**
  * Sets the flag to flip the triangles of badly oriented faces. Badly oriented faces
  * are detected through a construction of a graph of faces, and orientation propagation.
  * Note that this can't be activated if stitching is not activated.
  * Note that the whold result may not be orientable.
  * By default, this option is turned off.
  */
  void DoFlipBadlyOrientedFaces(CATBoolean iDoFlip);

  /**
  * Sets the flag to compute new edges as a post process. Works well for a massive decimation with the option to merge all the faces.
  * By default, this option is turned off.
  * @param iDoPostProcessSharpEdges
  *        If set to TRUE, activates this post process
  * @param iAngleForSharpEdges
  *   Will be used as the minimum value (Radian) for the normals around a bar to be considered sharp.
  *   Any smaller value and the bar will be considered smooth.
  *   Edges will be created along sharp bars, and normals computed again for a better shading.
  */
  void DoPostProcessSharpEdges(CATBoolean iDoPostProcessSharpEdges, double iAngleForSharpEdges = CATPIBY4);

  /**
  * Sets the flag to add an additional restriction to conserve texture coordinates inside original charts.
  * By default, this option is turned off.
  * @param iTextureCoordinatesInsideCharts
  *        If set to TRUE, activates this restriction.
  */
  void DoKeepTextureCoordinatesInsideCharts(CATBoolean iTextureCoordinatesInsideCharts);

  /**
   * Sets the flag to interpolate the normal when collapsing a bar
   * By default, this option is turned on.
   * It may lead to shading problems when heavily decimating areas where normals vary a lot.
   * In this case, you may want to set it to off.
   * If turned off, then normals are fully computed again at the end of decimation.
   * On is good for CAD models where edges between faces are kept.
   * Off is good for impostors.
   */
  void DoInterpolateNormals(CATBoolean iDoInterpolateNormals);

  /** @} */

  void DoStitchDifferentNormals(CATBoolean iDoStitchDifferentNormals);

  void DoUseNormalConstraints(CATBoolean iDoUseNormalsConstraints, double iDeviation = 0.);

  /**
  * This option is disabled by default.
  * By default, the decimation operator creates one output face for each manifold surfacic patch in the input polybody.
  * Therefore, if the polybody contains faces whose meshes are made up of multiple manifold patches, the output polybody will feature many more faces than the input one.
  * If enabled, this option allows for the creation of exactly one output polybody face per input polybody face.
  */
  void DoCreateOneOutputFacePerInputFace(CATBoolean iDoCreateOneOutputFacePerInputFace);

  /**
  * This option is disabled by default.
  * If enabled, the decimation operator will attempt to detect smooth edges in the decimated bar graph by finding edges that have moved too far away from their initial location.
  * When a smooth edge is detected, normals around this edge are recomputed in the output polybody.
  * Only available in multi-polybodies mode at the moment.
  */
  void DoDetectOutputSmoothEdgesAndRecomputeNormals(CATBoolean iDoDetectOutputSmoothEdgesAndRecomputeNormals);

  /**
  * This option is disabled by default.
  * Warning: DoDetectOutputSmoothEdgesAndRecomputeNormals must be enabled. Otherwise, turning on this option won't do anything.
  * If enabled, the decimation operator will attempt to merge faces that are separated by a smooth edges. Smooth and hard edges have been computed by 
  * DoDetectOutputSmoothEdgesAndRecomputeNormals(), which is why this option must be turned on.
  * Only available in multi-polybodies mode at the moment.
  */
  void DoMergeFacesAroundSmoothEdges(CATBoolean iDoMergeFacesAroundSmoothEdges);

  /**
  * If DoMergeFacesAroundSmoothEdges is enabled, this method allows to set faces that cannot be merged to any other face under any circumstance.
  * @param iUnmergeableFaces The tags of the face that should not be merged.
  */
  void SetUnmergeableFaces(const CATSetOfInt &iUnmergeableFaces);

private:

  CATBoolean _WithTextures, _WithNormals, _DoDecimation, _DoStitching, _DoCreateBoundaryEdges;
  CATBoolean _DoKeepTextureCoordinatesInsideCharts;
  CATBoolean _DoMergeFaces;
  CATBoolean _AllowMergeFaces;
  CATBoolean _DoStitchingInsideFaces;
  CATBoolean m_FlipBadlyOrientedFaces;
  CATBoolean m_DoPostProcessSharpEdges;
  CATBoolean m_DoJournaling; // Playback
  CATBoolean m_DoStitchDifferentNormals;
  CATBoolean _DoCreateOneOutputFacePerInputFace;
  CATBoolean _DoDetectOutputSmoothEdgesAndRecomputeNormals;
  CATBoolean _DoMergeFacesAroundSmoothEdges;

  std::vector<CATUnicodeString> _WithFilter;
  unsigned int _NbConstraints;

  double _StitchingTolerance;
  double _StichToleranceInsideFaces;
  double _AngleForSmoothEdges;
  double m_AngleForSharpEdges;

  CATPolyBodyBarGraphBuilder* _BarGraphBuilder;
  CATPolyBodyBarGraphDecimator* _BarDecimator;
  CATPolyBodyBarGraph* _BodyGraph;

  CATPolyBodyJoinDecimateBuilderObserver* _Observer;
  CATPolyBodyBarGraphDebugObserver* _DebugObserver;
  CATPolyBodyBarGraphTargetPercentageObserver* _TargetPercentageObserver;

  CATMapOfIntToInt _MapOfCellIDToParentID; // Associated a cell ID (an integer) to a parent cell ID.
  CATMapOfIntToInt _MapOfCellIDToCGMId; // Associated a cell ID (an integer) to a parent cgm ID.
  CATMapOfIntToInt _MapOfTagToPolyBody;

  CATSetOfInt _UnmergeableFaces;

  unsigned int m_NumberOfPolybodiesToBuild;

  CATBoolean _DoCreateEdges;
  CATBoolean m_DoNotCreateFullEdges;
public:
  //private:

  //friend class CATPolyBodyJoinDecimateBuilderCaptureObserver;  // Reserved for Phoenix capture.

  /**
  * Reserved for Phoenix capture.
  * Sets an observer with the operator.
  */
  inline void SetObserver(CATPolyBodyJoinDecimateBuilderObserver* iObserver);

  /**
  * Reserved for Phoenix capture.
  * Returns the observer of the operator.
  */
  inline CATPolyBodyJoinDecimateBuilderObserver* GetObserver() const;

  inline CATBoolean DoJournaling() { return m_DoJournaling; }
  inline void SetDoJournaling(CATBoolean iDoJournaling) { m_DoJournaling = iDoJournaling; }

  HRESULT ProcessSharpEdges();

};

inline void CATPolyBodyJoinDecimateBuilder::SetObserver(CATPolyBodyJoinDecimateBuilderObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyBodyJoinDecimateBuilderObserver* CATPolyBodyJoinDecimateBuilder::GetObserver() const
{
  return _Observer;
}

#endif
