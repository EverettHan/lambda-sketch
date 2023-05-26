// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCellMerger.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2021  Creation: FFL3
//===================================================================

#ifndef CATPolyCellMerger_H
#define CATPolyCellMerger_H

#include "PolyBodyServices.h"
#include "CATErrorDef.h"  // Definition of HRESULT.
#include "CATCGMSharedPtr.h"

#include <vector>


class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATPolyVertex;
class CATIPolySurfaceVertexLine;

namespace Poly
{
  /**
   * Deletes a vertex by merging two adjacent edges.
   * The vertex must be adjacent to exactly two edges which must lie between two faces.
   * @param iPolyBody CATPolyBody to edit
   * @param iSplittingVertex CATPolyVertex between two edges
   * @return S_OK if the operation is done
   *         S_FALSE if the adjacency of the vertex is invalid
   *         E_FAIL if an error occured while editing the polybody
   */
  ExportedByPolyBodyServices HRESULT MergeEdges(CATPolyBody & iPolyBody, CATPolyVertex * iSplittingVertex);

  /**
   * Calls MergeFaces(CATPolyBody& iPolyBody, CATPolyFace* iDstFace, CATPolyFace* iSrcFace)
   * @param iPolyBody CATPolyBody to edit
   * @param iSplitingEdge CATPolyEdge between two faces
   * @return E_FAIL if iSplitingEdge is not adjacent to exactly two edges.
   *         Otherwise returns the result of the other method.
   */
  ExportedByPolyBodyServices HRESULT MergeFaces(CATPolyBody & iPolyBody, CATPolyEdge * iSplitingEdge);
  /**
   * Merges two faces and remove the edges wetween them.
   * Updates the topolgy and move data from iSrcFace to iDstFace
   * @param iPolyBody CATPolyBody to edit
   * @param iDstFace CATPolyFace to keep (must be attached to an editable CATIPolyMesh)
   * @param ipSrcFace CATPolyFace to delete (must be attached to a CATIPolyMesh). It will be set to NULL on success.
   * @return S_OK if the operation is done
   *         E_FAIL if surfaces are invalid or an error occured while editing the polybody
   */
  ExportedByPolyBodyServices HRESULT MergeFaces(CATPolyBody & iPolyBody, CATPolyFace & iDstFace, CATPolyFace *& ipSrcFace);


  struct ExportedByPolyBodyServices InterfaceEdge {
    InterfaceEdge(CATPolyEdge* iEdge=nullptr);
    InterfaceEdge(const InterfaceEdge &iOther, bool iSwapSides = false);
    void swapSides() {
      std::swap(face1, face2);
      std::swap(curve1, curve2);
    }
    CATPolyEdge* edge;
    CATPolyFace* face1;
    CATPolyFace* face2;
    CATIPolySurfaceVertexLine* curve1;
    CATIPolySurfaceVertexLine* curve2;
    bool valid;
  };

  /**
   * Gets the list of edges and data between two faces
   */
  ExportedByPolyBodyServices std::vector<InterfaceEdge> GetInterfaceEdges(CATPolyFace& iFace1, CATPolyFace& iFace2);
};

#endif
