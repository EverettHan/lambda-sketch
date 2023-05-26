// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyToBRep.h
//
//===================================================================
// April 2015  Creation: NG4
//===================================================================
#ifndef CATPolyBodyToBRep_H
#define CATPolyBodyToBRep_H

#include "PolyBodyBuilders.h" // ExportedByPolyBodyBuilders

#include "CATCGMScaleCategoryDef.h"
#include "CATMathTransformation.h"

#include "CATListPV.h"
#include "CATMapOfPtrToPtr.h"
#include "CATLISTV_CATMathTransformation.h"
#include "CATListOfInt.h"

class CATMathTransformation;
class CATIPolyCurve;
class CATIPolySurface;
class CATPolyVertex;
class CATPolyFace;
class CATUnicodeString;
class CATIPolyMesh;
class CATPolyBody;

/**
This is an extension to the CATPolyBodyRepAdapter.
The generated PolyBody should match the BRep paradigm requirements, meaning, for example, there should not be faces without edges, non watertight edges, non manifold support meshes...
For instance, the generated PolyBody should be imported by the CATGMPolyBodyImporter with no errors.
*/
class ExportedByPolyBodyBuilders CATPolyBodyToBRep
{

public:

  /**
   * Default constructor.
   */
  CATPolyBodyToBRep();

  ~CATPolyBodyToBRep ();

  /**
   * Constructs a CATPolyBody from a supported CATRep.
   * The supported CATRep are : the ones supported by the CATPolyBodyRepAdapter (see header), and BagReps
   * If the input is a BagRep, the CATRep will be parsed, and the supported LeafReps will be processed
   * Usually, we construct one PolyBody for each terminal Rep. In some cases, under certain options, we may break this rule (sometimes, several terminal Reps will be merged in a unique PolyBody)
   * @param iPolyBodies
   *   The input CATPolyBodies.
   * @param oPolyBodies
   *   The output CATPolyBodies. The pointers contained in this list must be released by the caller.
   * @param iTryToConvertWiresIntoEdges
   *   When activated, this will enable the analyze of the wires contained in the terminal reps nested in iRep, and determine if it matches any face border in any terminal rep.
   *   If there is a match and no edge on the matching border, an edge will be created
   * @param iDeleteMergedWires
   *   This parameter has no effect if iTryToConvertWiresIntoEdges is disabled.
   *   It determines, when a wire has been assimilated to an edge, if we have to delete the wire after creating the edge or not.
   * @param iRemoveAutoIntersections
   *   When activated, the internal intersections in each PolyBody will be removed.
   *   FOR NOW : we will prevent the triangles that go through vertices that define, or partially define a cell (PolyEdge or PolyVertex) from being removed. Thus, some AutoIntersections may remain.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CATListPV &iPolyBodies,
               CATLISTV(CATMathTransformation) &iTransfos,
               CATListPV &oPolyBodies,
               CATListOfInt &iScaleCats,
               CATListOfFloat &iSags,
               CATBoolean iTryToConvertWiresIntoEdges = TRUE,
               CATBoolean iDeleteMergedWires = TRUE,
               CATBoolean iRemoveAutoIntersections = TRUE);

private:

  // The cardinality of the two input lists can change as we may merge several PolyBodies (eg : one with the faces, one with the edges) into one
  HRESULT RunWireConversionIntoEdges(CATListPV &ioPolyBodies, CATLISTV(CATMathTransformation) &ioTransfos, CATListOfDouble &ioSags, CATBoolean iDeleteMergedWires = TRUE);
  // The above methods are called by RunWireConversionIntoEdges
  CATBoolean SameTransfos(const CATMathTransformation &iTransfo1, const CATMathTransformation &iTransfo2) const;
  CATBoolean IsCurveABorderOfSurface(const CATIPolyCurve &iCurve, const CATIPolySurface &iSurface, CATListOfInt &oVerticesIndexes);
  CATBoolean IsOneBarPartOfAnEdge(CATPolyFace &iFace, const CATListOfInt &iVerticesIndexes) const;

  // Removes the null area triangles from the PolyBody and updates the geometries and topology if necessary
  // In some configurations, this operation is impossible because it leads to a non manifold situation
  HRESULT RemoveDegenerateTrianglesFromPolyBody(CATPolyBody &ioPolyBody) const;

  // Removes duplicated triangles (lying on the same triplet of vertices), considering the following rules :
  // 1- If we find N duplicated triangles with the same orientation, we only keep one of these N
  // 2- If we find N duplicated triangles, with P triangles having +1 orientation, and Q triangles having -1 orientation (P+Q==N), we check the orientation of the neighbourhood
  //    a- If an orientation (+1 or -1) is consistent with ALL the neighbour triangles, we keep one triangle with this orientation
  //    b- If there is no consistent orientation available, we keep one triangle with the orientation that satisfies a maximum of neighbour triangles
  HRESULT RemoveDuplicatedTrianglesFromPolyBody(CATPolyBody &ioPolyBody) const;

  // In each PolyMesh associated to each PolyFace of the PolyBody, it merges the vertices located at the exact same place into a single one
  // The micro topology will be updated
  // FOR NOW : there will be no merge if one of the two MicroVertices supports a macro topology cell as a MacroVertex or a MacroEdge
  HRESULT MergeSuperimposedMicroVerticesFromPolyBody(CATPolyBody &ioPolyBody) const;

  // Returns -1.0 if a problem occured
  double GetMinLengthBarInBody(const CATPolyBody &iPolyBody);

  // Returns -1.0 if a problem occured
  double GetMinTriangleHeightInBody(const CATPolyBody &iPolyBody);

  // Streams the vicinity of a triangle, with the desired depth, as a PolyBody (for debug)
  // (iDepth == 0) -> the triangle iTriangle will be streamed alone
  void StreamTriangleVicinity(const CATUnicodeString &iPath, CATIPolyMesh &iMesh, const int &iTriangle, const int &iDepth = 0) const;

  // Checks if several PolyVertices are coincident in the PolyBody
  CATBoolean AreSeveralVerticesCoincident(const CATPolyBody &iPolyBody);

  // Checks if several PolyVertices are coincident in the PolyBody
  CATBoolean MergeCoincidentVertices(const CATPolyBody &iPolyBody, CATPolyBody * &oNewPolyBody);

  // Since the MergeVertices method on the PolyBody class is not available, this method recreates a PolyBody from scratch, similar to iPolyBody, merging vertices organized in equivalence classes
  void ClonePolyBodyAndMergeVertices(const CATPolyBody &iPolyBody, const CATListPV &iEquivalenceClasses, CATPolyBody * &oPolyBody);

  void SplitEdgesOnInternalPolyVertices(CATPolyBody &iPolyBody);

private:

  CATMapOfPtrToPtr _MeshesToMapsOf3Doubles;
};

#endif // !CATPolyBodyToBRep_H
