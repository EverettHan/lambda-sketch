// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyStitcher.h
//
//===================================================================
// June 2016  Creation: JXO, from CATPolyBodyJoinDecimateBuilder
//===================================================================
#ifndef CATPolyBodyStitcher_H
#define CATPolyBodyStitcher_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "PolyBodyDecimate.h"

class CATPolyBody;
class CATPolyCell;
class CATMathTransformation;
class CATPolyBodyStitcherObserver;
class CATPolyBodyBarGraphDecimator;
class CATPolyBodyBarGraph;
class CATPolyBodyBarGraphBuilder;
class CATPolyBodyBarGraphDebugObserver;
class CATMathBox;
class CATPolyBodyBarGraphHoleIterator;
class CATPolyBodyBarGraphHoleBarIterator;


/**
 * Operator that stitches one or several CATPolyBody.
 * It generates a new CATPolyBody.
 *
 * The input CATPolyBody and its optional layers do not need to be editable.
 */
class ExportedByPolyBodyDecimate CATPolyBodyStitcher
{

public:

  CATPolyBodyStitcher (CATPolyBodyStitcherObserver* iObserver = 0);

  ~CATPolyBodyStitcher ();

public:

/** @name Settings
    @{ */

  /**
   * Sets the stitch tolerance.
   */
  void SetStitchingTolerance (double iStitchingTolerance);

  /**
   * Turns on an option for the construction of all boundary edges.
   * By default, this option is turned off.  Edges will be constructed along boundaries only if they
   * have been declared as such in the graph.
   */
  void DoCreateBoundaryEdges (CATBoolean iDoCreateBoundaryEdges);

  /**
   * Sets a flag to use and process the data in the texture layer.
   * Default is FALSE.
   */
  void DoProcessTextureLayer (CATBoolean iUseTextureLayer);

  /**
   * Includes the nD texture coordinates for the simplification of the bars and placement of the nodes.
   * Default iDim is 0.
   * @param iDim
   *   Number of constraints.
   * @param iWeight
   *   The weight given to the texture coordinate.
   */
  void DoProcessTextureCoordinatesConstraints(const unsigned int iDim, const double iWeight[]);
  void DoProcess1DTextureCoordinates (CATBoolean iFlag, const double iWeight = 1)
  {
    if(iFlag)
    {
      double Weight[1] = {iWeight};
      DoProcessTextureCoordinatesConstraints(1, Weight);
    }
  }

  /**
   * Sets a flag to merge all faces into a unique face before running the operator.
   * Adjacent faces (joined by edges) will be merged into a contiguous face.
   * Default is FALSE.
   */
  void DoMergeFaces (CATBoolean iFlag);

  /**
   * Sets the flag to flip the triangles of badly oriented faces. Badly oriented faces
   * are detected through a construction of a graph of faces, and orientation propagation.
   * Note that the whole result may not be orientable.
   * By default, this option is turned on, because in some cases stitching would not be possible without.
   */
  void DoFlipBadlyOrientedFaces (CATBoolean iDoFlip);

  /**
   * If set to a positive value, will be used as the minimum value (Radian) for the normals around an edge vertex to be considered sharp.
   * Any smaller value and the edge vertex will be considered smooth, and the adjacent faces merged.
   * The default value (-1.) ensure all faces are merged.
   */
  void SetAngleForSmoothEdges(double iAngleForSmoothEdges = -1. /*CATPIBY4*/);

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
    /**
     * Associates a tag to an input poly cell.
     * First all the CATPolyVertex will be added, then all the CATPolyEdge's, then all the CATPolyFace's.
     * @param iInputCell
     *        Cell from the input CATPolyBody
     * @param iTag
     *        Associated tag inside bar-graph
     */
    virtual void AssociatePolyCellAndTag (CATPolyCell* iInputCell, const unsigned int iTag) = 0;
    /**
     * Associates a node id to an input micro vertex.
     * First all the CATPolyVertex will be added, then all the vertices of the CATIPolyCurve's, then all the vertices of the CATIPolySurface's.
     * @param iInputMicroVertex
     *        Micro vertex index inside input cell. It can be the index of vertex inside a CATIPolySurface, or inside a CATIPolyCurve, and 0 for a CATIPolyPoint.
     * @param iCellTag
     *        Bar-graph tag associated to the cell (see AssociatePolyCellAndTag)
     * @param iNode
     *        Bar-graph node associated to the micro vertex.
     */
    virtual void AssociatePolyVertexAndTag (const int iInputMicroVertex, const unsigned int iNode, const unsigned int iCellTag) = 0;
  };

  /**
   * Output Cell Observer.
   * This observer associates the identification tags to the cells from the output CATPolyBody.
   * @see InputCellObserver
   */
  class OutputCellObserver
  {
  public:

    virtual void AssociateTagAndPolyCell (const unsigned int iTag, CATPolyCell* iOutputCell) = 0;

  };

/** @} */

public:

/** @name Input Data
    @{ */

  /**
   * Adds a CATPolyBody to the operator for stitching.
   * Several CATPolyBody can be added in this manner for concatenation to the operator.
   * @param iPolyBody
   *   The input CATPolyBody.
   * @param iPositionMatrix
   *   The position of the input CATPolyBody.
   * @param iCellObserver
   *   An observer to associate the cells of the input CATPolyBody to unique identification tags.
   */
  HRESULT AddPolyBody (const CATPolyBody& iPolyBody,  const CATMathTransformation* iPositionMatrix = 0, InputCellObserver* iCellObserver = 0);

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
  HRESULT Run (CATPolyBody*& oPolyBody, OutputCellObserver* iCellObserver = 0);

/** @} */

public:

/** @name Manual Mode
    @{ */

  /**
   * Initializes the operator after addition of the input CATPolyBody.
   * @param oHoleIterator
   *        To be deleted by caller.
   */
  HRESULT Initialize (CATPolyBodyBarGraphHoleIterator * & oHoleIterator);

  /** 
   * Stich one particular hole.
   * Can be called for the holes from CATPolyBodyBarGraphHoleIterator.
   * At each step an intermediate CATPolyBody may be constructed through BuildPolyBody.
   * @param ipHole
   *        Hole to be stichted, given the tolerance iTol.
   */
  HRESULT StitchHole(CATPolyBodyBarGraphHoleBarIterator * ipHole, double iTol);

  /**
   * Builds an intermediate CATPolyBody from the current state of the stitcher data.
   * This method can be called several times to get intermediate stitch results.
   * It should be called before the call to Finalize.
   * @param oPolyBody
   *   The output CATPolyBody.
   * @param iCellObserver
   *   An observer to associate the identification tags to the cells from the output CATPolyBody.
   */
  HRESULT BuildPolyBody (CATPolyBody*& oPolyBody, OutputCellObserver* iCellObserver = 0);

  /**
   * Creates the final edges and constructs the final output CATPolyBody.
   * Finalizes the operator after construction of the output CATPolyBody.
   */
  HRESULT Finalize (CATPolyBody*& oPolyBody, CATPolyBodyStitcher::OutputCellObserver* iCellObserver = 0);


  HRESULT GetBoundingBox (CATMathBox& oBoundingBox);

/** @} */

private:

  CATBoolean _WithTextures, _WithNormals, _DoCreateBoundaryEdges;
  CATBoolean _DoMergeFaces;
  unsigned int _NbConstraints;

  double _StitchingTolerance;
  CATPolyBodyBarGraphBuilder* _BarGraphBuilder;
  CATPolyBodyBarGraph* _BodyGraph;

  CATPolyBodyStitcherObserver* _Observer;
  CATPolyBodyBarGraphDebugObserver* _DebugObserver;

  CATBoolean m_FlipBadlyOrientedFaces;

  CATBoolean m_DoJournaling; // Playback

  double _AngleForSmoothEdges;

public:

  //friend class CATPolyBodyStitcherCaptureObserver;  // Reserved for Phoenix capture.

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetObserver (CATPolyBodyStitcherObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyBodyStitcherObserver* GetObserver () const;

  inline CATBoolean DoJournaling(){return m_DoJournaling;}
  inline void SetDoJournaling(CATBoolean iDoJournaling){m_DoJournaling = iDoJournaling;}

};

inline void CATPolyBodyStitcher::SetObserver (CATPolyBodyStitcherObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyBodyStitcherObserver* CATPolyBodyStitcher::GetObserver () const
{
  return _Observer;
}

#endif
