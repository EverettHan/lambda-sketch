// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySubMeshInclusionTree.h
// Header definition of CATPolySubMeshInclusionTree
//
// Utility class : submeshes generation, inclusionTree, Volume of CATIPolymesh...
// Take a main CATIPolyMesh as input. Then, the caller can :
//    Generate submeshes
//    Construct an inclusion tree of those meshes
//    Add optionally other meshes to the tree (BEFORE ITS CREATION)
//    Get the volume of a submesh or of an additional mesh
//
//===================================================================
//
// August 2016  Creation:                                                               h7w
// April  2019  Modification: it is now an abstract class.                              RBU3 
// April  2019  Renamed : CATPolyMeshEnvelopeUtil.h -> CATPolySubMeshInclusionTree.h    RBU3
//===================================================================

#ifndef CATPolySubMeshInclusionTree_H
#define CATPolySubMeshInclusionTree_H

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATTolerance.h"     // CATTolerance
#include "CATBoolean.h"       // TRUE / FALSE
#include <list> // std::list
#include <vector> // std::vector
#include <utility> //std::pair

#include "CATIPolyMesh.h"
#include "CATMathBox.h"
#include "CATListOfInt.h"


class CATPolySubMesh;
class CATMathPoint;


// Utility class to generate an inclusion tree of the submeshes of a CATIPolyMesh
class ExportedByCATFuzzyPolyOper CATPolySubMeshInclusionTree {
public :
  virtual ~CATPolySubMeshInclusionTree() {};

  virtual CATBoolean AreSubmeshesGenerated() const = 0;
  virtual CATBoolean IsInclusionTreeGenerated() const = 0;

  // Add a mesh in addition of the submeshes of the initial mesh.
  // All the additional meshes will be placed at the end of the intern list of the inclusionList
  // meaning that their IDs will be from nbSubmeshes to the end.
  // CAUTION : they will not be returned by the method that contain Submesh/submeshes in their name.
  //    For example, GetHighLevelSubMeshes() return only submeshes.
  // @param iPolyMesh : pointer to the polyMesh to add.
  virtual HRESULT AddAnotherMeshBeforeRun(CATIPolyMesh* iPolyMesh) = 0;

  // Replace a mesh by the new polyMesh in input.
  // CAUTION : only works before the generation of the inclusionTree.
  // Return E_FAIL if there are no mesh with this ID.
  // ID are :
  //    For a submesh, its ID is its place in the vector of SubMeshes (only before the inclusionTree generation)
  //    For an additional mesh, it is _NbSubMeshes + its place in the vector of Additional Meshes (only before the inclusionTree generation)
  virtual HRESULT ModifyAMeshBeforeRun(int idItem, CATIPolyMesh* iNewPolyMesh) = 0;

  // From an ID, remove a submesh or an additional mesh from its vector and
  //  from the inclusionTree if it was generated.
  // Does not remove the meshes included in it.
  //  Modify the tree if it is generated. Modify the ID of the other meshes.
  virtual HRESULT RemoveMesh(int iIdMesh) = 0;

  // Compute the submeshes of the main CATIPolyMesh
  // Doesn't generate an inclusion tree
  // Doesn't compute any volume for the submeshes
  virtual HRESULT GenerateSubmeshes() = 0;

  // Build the inclusion tree of all the meshes.
  //   Compute the submeshes of the main polyMesh if needed
  //   Also take count of the additional meshes added by the user
  //   Compute a volume for each mesh added to the tree.
  virtual HRESULT GenerateInclusionTree() = 0;

  // Compute the volume of the input polymesh
  virtual double ComputeMeshVolume(CATIPolyMesh *iPolyMesh) = 0 ;

  // The inclusionTree must have been generated before a call to this function
  // Return a vector of all the subMeshes of level 0 in the inclusionTree (top level)
  //    A subMesh is 0 when it is not included in any other submesh
  //      and its volume is positive.
  //
  // DOES NOT RETURN THE ADDITIONAL MESHES added by the caller.
  //   Use GetAdditionalMeshHighLevel() to get them
  virtual std::vector<int> GetHighLevelSubMeshes() const = 0;

  // The inclusionTree must have been generated before a call to this function
  // Return a vector of all the subMeshes of level 1 in the inclusionTree
  //    A subMesh is level 1 when it is included in a submesh of level 0
  //    and its volume is negative.
  //
  // DOES NOT RETURN THE ADDITIONAL MESHES added by the caller.
  virtual std::vector<int> GetLevel1SubMeshes() const = 0;

  // The inclusionTree must have been generated before a call to this function
  // iVolume define the type of subMesh it return.
  //    1 : subMesh with positive volume
  //    -1 : submesh with negative volume
  //
  // DOES NOT RETURN THE ADDITIONAL MESHES added by the caller.
  virtual std::vector<int> GetSubMeshesWithSignVolume(short iVolumeSign) const = 0;

  // The inclusionTree must have been generated before a call to this function
  // Return a vector of id of the additional meshes with level 0.
  // Those meshes are not included in any other mesh/submesh
  virtual std::vector<int> GetHighLevelAdditionalMeshes() const = 0;

  // The inclusionTree must have been generated before a call to this function
  // Return a vector of id of the additional meshes with level 1.
  // Those meshes are included in an other mesh/submesh, but not in more than one.
  virtual std::vector<int> GetLevel1AdditionalMesh() const = 0;

  // The inclusionTree must have been generated before a call to this function
  // Return a vector of id of the additional meshes with a volume of the sign in parameter (positive or negative).
  // Those meshes are not included in any other mesh/submesh
  virtual std::vector<int> GetAdditionalMeshWithSignVolume(short iVolumeSign) const = 0;

  // Return the number of submeshes of the main CATIPolyMesh.
  // Does not count the additional meshes added by the caller
  virtual int GetNbSubMeshes() const = 0;

  // The submeshes must have been generated with GenerateSubmeshes before a call to this function
  // Return the list of submeshes extracted from the input PolyMesh
  // CAUTION : if the InclusionTree has been generated, return an empty vector.
  //              Use GetAllInclusionTreeItems() instead.
  virtual std::vector<CATIPolyMesh*> GetSubMeshesBeforeInclusionTree() const = 0;

  // Return the list of the IDs of the subMeshes into the InclusionTree.
  // Use the Get (GetSubMesh, GetBox, GetVolume...) with this ID to get information about the subMesh
  // CAUTION : the InclusionTree MUST have been generated
  virtual std::vector<int> GetSubMeshesIdInTree() const = 0;

  // Return the list of the IDs of the additional meshes into the InclusionTree.
  // Use the Get (GetSubMesh, GetBox, GetVolume...) with this ID to get information about the mesh
  // CAUTION : the InclusionTree MUST have been generated
  virtual std::vector<int> GetAdditionalMeshesIdInTree() const = 0;

  // Return the list of pointer to the InclusionTreeItems.
  // They store all the informations about an item : ID, mesh, Volume, Box...
  // CAUTION : the InclusionTree MUST have been generated
  virtual std::vector<int> GetAllMeshesIdInTree() const = 0;

  // From the ID of an inclusionTreeItem return its mesh
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetSubMesh(int idItem, CATIPolyMesh(*&oMesh)) const = 0;

  // From its ID, return the volume of a mesh (submesh or additional mesh)
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetVolume(int idItem, double &oVolume) const = 0;

  // From its ID, return the level of a mesh in the inclusionTree (submesh or additional mesh)
  //   Level 0 is the top of the tree, level 1 are the meshes included into a level 0 mesh, ect...
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetLevel(int idItem, int &oLevel) const = 0;

  // From its ID, return the box of a mesh (submesh or additional mesh)
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetBox(int idItem, CATMathBox &o3DBox) const = 0;

  // Return the list of all meshes included into another one.
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetListOfInclusion(int idItem, CATListOfInt(*&oListInclusionID)) const = 0;

  // Return the list of all meshes that include the input mesh.
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetListOfContainer(int idItem, CATListOfInt(*&oListContainersID)) const = 0;

  // Return the mesh that include directly the input mesh.
  // Return -1 if the mesh is on the top of the tree.
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetFatherInTree(int idItem, int &oFather) const = 0;

  // Return the list of the top of the meshes included into another one.
  //   aka the meshes directly included into it
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT GetListOfHighLevelInclusion(int idItem, CATListOfInt &oListInclusionID) const = 0;

  // Return TRUE if the mesh of this item was added by the caller.
  //        FALSE if it is a submesh of the main CATIPolyMesh
  // CAUTION : the InclusionTree MUST have been generated
  virtual HRESULT IsAdditionalMesh(int idItem, CATBoolean &oIsAdditionalMesh) const = 0;
};


// =============================================================================
// Creates an instance of CATPolySubMeshInclusionTree
// This is the constructor of the CATPolySubMeshInclusionTree that should be used.
//  @param iPolyMesh
//    The input polyhedral mesh from which the sub-meshes are generated
//  @param iClientTol
//    The Tolerance is required to be consistent with the other operators
//  @param iOnlyComputeVolume
//    If TRUE, the volumes are computed for each sub-meshes but the inclusion-tree isn't generated. FALSE by default. 
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolySubMeshInclusionTree* CATCreatePolySubMeshInclusionTree(CATIPolyMesh &iPolyMesh, 
  const CATTolerance &iClientTol, CATBoolean iOnlyComputeVolume = FALSE);



#endif
