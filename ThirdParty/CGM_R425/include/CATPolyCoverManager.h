// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCoverManager.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// June 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyCoverManager_H
#define CATPolyCoverManager_H

#include "CATErrorDef.h"

#include "CATPolyBuckets_T.h"

#include "CATListOfInt.h"
#include "CATBoolean.h"

#include "CATPolySegmentCommon.h"

class CATPolyIntegerSetCover;
class CATPolyElementsPatch;

class ExportedByCATPolySegmentCommon CATPolyCoverManager
{
public:
  CATPolyCoverManager(CATPolyIntegerSetCover* iCover);
  virtual ~CATPolyCoverManager();

public:
  HRESULT Initialize();

  //PATCHS MANAGEMENT
  HRESULT AddPatch(CATPolyElementsPatch* iPatch, int& oIdxPatch);
  HRESULT GetPatch(int iIdxPatch, CATPolyElementsPatch*& oPatch);
  int GetNbPatchs();

  CATBoolean IsElementAvailable(int iIdxFacet);
  HRESULT GetElementPatchs(int iIdxElem, CATListOfInt& oPatchs);
  
  HRESULT RemovePatch(int iIdxPatch);

  //PATCHS VERTICES MANAGEMENT
  HRESULT AddElementToPatch(int iIdxElement, int iIdxPatch);
  HRESULT RemoveElementFromPatch(int iIdxElement, int iIdxPatch);
  CATBoolean IsElementInPatch(int iIdxElement, int iIdxPatch);

  inline CATPolyIntegerSetCover* GetCover();

private:
  HRESULT GetNewIdxForPatch(int& oIdxPatch);

public:
  CATPolyIntegerSetCover* _Cover;

  class Specialize_CATPolyBuckets_T(PatchBuckets, CATPolyElementsPatch*);
  PatchBuckets _Patchs;
};

//inline
inline CATPolyIntegerSetCover* CATPolyCoverManager::GetCover()
{
  return _Cover;
}

#endif //CATPolyCoverManager_H
