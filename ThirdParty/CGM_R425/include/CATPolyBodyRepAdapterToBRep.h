// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRepAdapterToBRep.h
//
//===================================================================
// April 2015  Creation: NG4
//===================================================================
#ifndef CATPolyBodyRepAdapterToBRep_H
#define CATPolyBodyRepAdapterToBRep_H

#include "CATPolyVisuBuildOper.h" // ExportedByPolyVisuBuildOper
#include "CATPolyBodyRepAdapter.h"

#include "CATListPV.h"
#include "CATMapOfPtrToPtr.h"

#include "CATPolyBodyToBRep.h"

class CATMathTransformation;
class CATIPolyCurve;
class CATIPolySurface;
class CATPolyVertex;
class CATPolyFace;
class CATUnicodeString;
class CATIPolyMesh;

/**
This is an extension to the CATPolyBodyRepAdapter.
The generated PolyBody should match the BRep paradigm requirements, meaning, for example, there should not be faces without edges, non watertight edges, non manifold support meshes...
For instance, the generated PolyBody should be imported by the CATGMPolyBodyImporter with no errors.
*/
class ExportedByPolyVisuBuildOper CATPolyBodyRepAdapterToBRep
{

public:

  /**
   * Default constructor.
   */
  CATPolyBodyRepAdapterToBRep();

  ~CATPolyBodyRepAdapterToBRep ();

  /**
   * Constructs a CATPolyBody from a supported CATRep.
   * The supported CATRep are : the ones supported by the CATPolyBodyRepAdapter (see header), and BagReps
   * If the input is a BagRep, the CATRep will be parsed, and the supported LeafReps will be processed
   * Usually, we construct one PolyBody for each terminal Rep. In some cases, under certain options, we may break this rule (sometimes, several terminal Reps will be merged in a unique PolyBody)
   * @param iRep
   *   The input CATRep.
   * @param oPolyBodies
   *   The output CATPolyBodies. The pointers contained in this list must be released by the caller.
   * @param oTransfos
   *   The matrix transformations associated to each outputted PolyBody. #(oPolyBodies) == #(oTransfos).
   *   The pointers in this list must be destroyed by the caller.
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
  HRESULT Run (CATRep& iRep, 
               CATListPV &oPolyBodies, CATListPV& oTransfos,
               CATBoolean iTryToConvertWiresIntoEdges = TRUE,
               CATBoolean iDeleteMergedWires = TRUE,
               CATBoolean iRemoveAutoIntersections = TRUE);

private:

  CATPolyBodyRepAdapter _RepAdapter;
  CATPolyBodyToBRep _PBodyToBRep;
};

#endif // !CATPolyBodyRepAdapterToBRep_H
