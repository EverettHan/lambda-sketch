// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPartitionManager.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// June 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyPartitionManager_H
#define CATPolyPartitionManager_H

#include "CATErrorDef.h"

#include "CATPolyBuckets_T.h"

#include "CATListOfInt.h"
#include "CATBoolean.h"

#include "CATPolySegmentCommon.h"

class CATPolyGraph;
class CATPolyIntegerSetPartition;
class CATPolyElementsPatch;

class ExportedByCATPolySegmentCommon CATPolyPartitionManager
{
public:
  CATPolyPartitionManager(CATPolyIntegerSetPartition* ioPartition);
  virtual ~CATPolyPartitionManager();

public:
  HRESULT GetPatch(int iIdxPatch, CATPolyElementsPatch*& oPatch);
  
  int GetNbPatchs();
  HRESULT GetElementPatch(int iIdxElement, int& oIdxPatch);

  HRESULT RemovePatch(int iIdxPatch);

  CATBoolean IsElementAvailable(int iIdxElement);

  HRESULT GetPatchNeighbors(int iIdxPatch, CATListOfInt& oNeighbors);
  HRESULT ConnectPatchs(int iIdxPatch, int iIdxNeighbor);
  HRESULT DisConnectPatchs(int iIdxPatch, int iIdxNeighbor);
  CATBoolean PatchsConnected(int iIdxPatch1, int iIdxPatch2);

  HRESULT Initialize();

  HRESULT UnregisterPatch(int iIdxPatch);
  CATBoolean IsPatchRegistred(int iIdxPatch);

  HRESULT AddPatch(CATPolyElementsPatch* iPatch, int& oIdxPatch);

  inline CATPolyIntegerSetPartition* GetPartition();

  //FACETS MANAGEMENT
  HRESULT AddElementToPatch(int iIdxElement, int iIdxPatch);
  HRESULT RemoveElementFromPatch(int iIdxElement, int iIdxPatch);
  HRESULT EmptyPatch(int iIdxPatch);

private:
  HRESULT GetNewIdxForPatch(int& oIdxPatch);

public:
  CATPolyGraph* _PatchsGraph;
  CATPolyIntegerSetPartition* _Partition;

  class Specialize_CATPolyBuckets_T(PatchBuckets, CATPolyElementsPatch*);
  PatchBuckets _Patchs;

};

//inline
inline CATPolyIntegerSetPartition* CATPolyPartitionManager::GetPartition()
{
  return _Partition;
}

#endif //CATPolyPartitionManager_H
