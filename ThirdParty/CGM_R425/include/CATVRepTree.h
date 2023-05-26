//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//==============================================================================================================

// CATVRepTree : Octree associated with client data on corners, describing at least the distance
//               between each corner and a reference object, and optionally additional information
//               such as "gradient" vectors on each corner

//==============================================================================================================
// Creation : CHU/DPS , march / 2006 
//==============================================================================================================

#ifndef CATVRepTree_H
#define CATVRepTree_H

#include "CATErrorDef.h"          // HRESULT definition
#include "CATPolyDumpable.h"      // derived
#include "CATVRepType.h"          // agregated
#include "VRepGen.h"              // ExportedBy

class CATPolyVtxOctree;
class CATPolyDistanceField;
class CATPolyGradientField;
class CATPolyVoxelClient;
class CATPolyBasicOctree;
class CATPolyCompleteVoxelPath;
class CATMathBox;
class CATPolyError;
class CATCGMOutput;

class ExportedByVRepGen CATVRepTree : public CATPolyDumpable
{

public :

  // Life cycle
  CATVRepTree(CATPolyVtxOctree * iOctree, CATVRepType & iType);
  virtual ~CATVRepTree();

  // Construction from a sub-voxel of current (master) vrep, sharing all data under this sub-voxel with the master vrep:
  // FocusDuplicateVRep creates a root equivalent to the master's root, therefore has unshared octocubes
  // down to the given voxel depth, and shares all data from this depth downward, but its IJK match those of
  // the master, and the atomic voxel size is identical.
  // Divisions that would touch the unshared octocubes (including the root) may be locked by specifying iLockDivisionsOutsideRefVoxel=1 in input.
  // No specific voxel-clients-cleaner is attached to the underlying octree (if required, it has to be done after invoking this method)
  CATVRepTree * FocusDuplicateVRep(const CATPolyCompleteVoxelPath &iMasterPath, int iLockDivisionsOutsideRefVoxel = 0) const;

  // Cast to CATPolyDistanceField is safe if invoked on a corner beared by member _Tree
  CATPolyDistanceField * SafeCastToDistanceField(CATPolyVoxelClient * iCornerClient);

  // Cast to CATPolyGradientField is safe if invoked on a corner beared by member _Tree
  CATPolyGradientField * SafeCastToGradientField(CATPolyVoxelClient * iCornerClient);

  // Data access
  inline CATPolyVtxOctree * GetTree() const;
  inline CATVRepType GetVRepType() const;
  void SetVRepType(CATVRepType & iType);
  void SetTree(CATPolyVtxOctree * iTree);
  inline double GetGlobalOffset() const;
  inline void SetGlobalOffset(double iGlobalOffset);

  /*
  // Read/Write the memory manager that handles all distance and gradient fields
  void SetVCMemoryManager(CATPolyMemoryManager * iManager);
  inline CATPolyMemoryManager * GetVCMemoryManager() const;
  */

  // Eliminate all voxels divisions outside a given box
  // The reference box is not changed, but the VRep has less voxels (this method calls RemoveOctoCube())
  // It is assumed that iBox is contained in the current box.
  // Orphan corner clients (not bounding any voxel) are deleted
  HRESULT FocusVRepOnBox(CATMathBox & iBox);
  HRESULT FocusVRepOnBox(unsigned int iIJKBox[6]);

  // Eliminate all voxels divisions outside areas where CornerClients are attached to Voxel corners
  // The reference box is not changed, but the VRep has less voxels (this method calls RemoveOctoCube())
  // Orphan corner clients (not bounding any voxel) are deleted
  HRESULT SimplifyTreeOutOfVRepData();

  // Stream as text file (requires CATDevelopmentStage=TRUE)
  HRESULT WriteToFile(char * iFilePathName, int iVerbose=0);

  // Dump (the octree is dumped with its corner clients)
  static char _Name[10];
  virtual char * GetShortName() const;

  HRESULT Dump( CATCGMOutput & s) const; // inherited from CATPolyDumpable
  HRESULT Dump( CATCGMOutput & s, int iVerbose) const;

private:

  /*
  // Call back passed to the octree in order to flush all voxel clients
  static HRESULT FlushVoxelClients(const CATPolyBasicOctree * iOctree, void * iPolyVRepObject);
  */

  // Data

  static unsigned int  _LastCreatedVRepNumber;

  CATPolyVtxOctree * _Tree; // owned
  CATVRepType        _VRepType; 

  // Value to be subtracted to all distance fields
  double             _GlobalOffset;
};

// inline methods
inline CATPolyVtxOctree * CATVRepTree::GetTree() const {
  return _Tree; }

inline CATVRepType CATVRepTree::GetVRepType() const {
  return _VRepType; }

/*
inline CATPolyMemoryManager * CATVRepTree::GetVCMemoryManager() const {
  return _VoxelClientsMemoryManager; }
*/

inline double CATVRepTree::GetGlobalOffset() const {
  return _GlobalOffset; }

inline void CATVRepTree::SetGlobalOffset(double iGlobalOffset) {
  _GlobalOffset = iGlobalOffset; }

#endif
