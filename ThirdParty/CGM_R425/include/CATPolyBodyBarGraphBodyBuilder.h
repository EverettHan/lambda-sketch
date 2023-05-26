// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBarGraphBodyBuilder.h
//
//===================================================================
// September 2011  Creation NDO
//===================================================================
#ifndef CATPolyBodyBarGraphBodyBuilder_H
#define CATPolyBodyBarGraphBodyBuilder_H

#include "CATPolyDecimateOperators.h"
#include "CATCollec.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATListPV.h"

#include <unordered_set>

class CATPolyBodyBarGraph;
class CATPolyBody;
class CATPolyCell;
class CATIPolyBodyFrameLayers;
class CATMapOfPtrToInt;
class CATMapOfIntToInt;


/**
 * Builds an editable CATPolyBody from a body bar-graph.
 */
class ExportedByCATPolyDecimateOperators CATPolyBodyBarGraphBodyBuilder
{

public:

  /**
   * Constructs a builder of CATPolyBody from a CATPolyBodyBarGraph.
   * @iDoMakeBoundaryEdges
  *                       turns on or off the construction of boundary edges for all boundary bars.
   * @iDoMakeEdgesAtAll
  *                       turns on or off the construction of edges for all edges.
   */
  CATPolyBodyBarGraphBodyBuilder(const CATBoolean iDoMakeBoundaryEdges, CATBoolean iDoMakeEdgesAtAll = TRUE, CATBoolean iDoCreateOneOutputFacePerInputFace = FALSE);

  ~CATPolyBodyBarGraphBodyBuilder();

public:

  /**
   * Observer interface for builder.
  * It can be used to construct mappings from the tags (cell IDs) to the output CATPolyCell (or its opposite.)
   */
  class Observer
  {
  public:
    virtual void AssociateTagAndPolyCell(const unsigned int iTag, CATPolyCell* iOutputCell) = 0;

    virtual void ReactToFailedEdgeCreation(const unsigned int iTag,
                                           CATListOfInt const &nodes) {}

    virtual void ReactToFailedVertexCreation(const unsigned int iNode) {}
  };

public:
  /**
   * Constructs a CATPolyBody from a CATPolyBodyBarGraph.
   * @param iBodyGraph
   *   The input bar graph.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param iObserver
  *   An optional observer for mapping of the manifold index of the cell to the new CATPolyCell from the CATPolyBody.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on successful construction of a CATPolyBody.
   *   <li> <code> E_FAIL </code> on failure.
   * </ul>
   */
  HRESULT Run(CATPolyBodyBarGraph& iBodyGraph, CATPolyBody*& oPolyBody,
              Observer *iObserver = 0);

  /**
   * Constructs multiple CATPolyBody objects from a CATPolyBodyBarGraph.
   * @param iBodyGraph
   *   The input bar graph.
   * @param oPolyBodies
   *   The output CATPolyBody objects.  These objects must be released by the caller.
   * @param iNbOfPolyBodies
   *   The number of output polybodies to create
   * @param iMapOfFaceTagsToPolyBodies
   *   Map that matches decimation cell tags to a unique output polybody. Polybody indices start at 1. If one
   *   of the polybodies never appears in the map, it will be empty.
   * @param iObserver
   *   An optional observer for mapping of the manifold index of the cell to the new CATPolyCell from the CATPolyBody.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on successful construction of a CATPolyBody.
   *   <li> <code> E_FAIL </code> on failure.
   * </ul>
   */
  HRESULT Run(CATPolyBodyBarGraph& iBodyGraph, CATListPV &oPolyBodies,
    unsigned int iNbOfPolyBodies, CATMapOfIntToInt &iMapOfFaceTagsToPolyBodies, Observer *iObserver = 0);

  /**
   * Constructs a CATPolyBody with its frame layers from a CATPolyBodyBarGraph.
   * @param iBodyGraph
   *   The input bar graph.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oFrameLayers
   *   The output frame layers.  This object must be released by the caller.
   * @param iObserver
  *   An optional observer for mapping of the manifold index of the cell to the new CATPolyCell from the CATPolyBody.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on successful construction of a CATPolyBody.
   *   <li> <code> E_FAIL </code> on failure.
   * </ul>
   */
  HRESULT Run(CATPolyBodyBarGraph& iBodyGraph, CATPolyBody*& oPolyBody, CATIPolyBodyFrameLayers*& oFrameLayers,
              Observer *iObserver = 0);

  void SetMapOfManifoldCellTagsToParentCellTags(CATMapOfIntToInt* ipMap);

  void SetSharpEdges(const std::unordered_set<unsigned int> *ipSharpEdges);

  void DoMergeFacesSeparatedBySmoothEdges(CATBoolean iDoMerge = TRUE) { _DoMergeFacesSeparatedBySmoothEdges = iDoMerge; }

private:

  CATBoolean _DoMakeBoundaryEdges;
  // Default is TRUE
  CATBoolean _DoMakeEdges;
  // Default is FALSE
  CATBoolean _DoCreateOneOutputFacePerInputFace;
  // Default is FALSE
  CATBoolean _DoMergeFacesSeparatedBySmoothEdges;

  CATMapOfIntToInt* m_pMapOfManifoldCellTagsToParentCellTags;

  // Default is nullptr
  // If the option allowing to detect smooth edges and recompute normals around them is enabled,
  // this set holds the list of edges that are considered sharp
  const std::unordered_set<unsigned int> *m_pSharpEdges;
};

#endif
