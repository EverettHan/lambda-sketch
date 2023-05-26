#ifndef CATAutoBaseRemoveFace_H
#define CATAutoBaseRemoveFace_H
//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATAutoBaseRemoveFace.h
// 		
//===================================================================
//  Jan 2005  Creation: PFV
//===================================================================

#include "CATOracleObject.h"
#include "CATCGMNewArray.h"
#include "CATMathInline.h"


class CATPersistentBody;
#include "ListPOfCATPersistentFaces.h"

#include "CFSEngine.h"

class ExportedByCFSEngine CATAutoBaseRemoveFace
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation
  DEFINE_ADVOP_CLASS_NAME("CATAutoBaseRemoveFace")

  CATAutoBaseRemoveFace(const CATAutoBaseThreadContext &iThreadContext,
  CATSoftwareConfiguration *iConfig, CATPersistentBody *iPersistentBody, 
    ListPOfCATPersistentFaces &iPersistentFacesToRemove);
  virtual ~CATAutoBaseRemoveFace();

  INLINE void SetMatterDirection(short iMatterDirection);
  INLINE void AllowPartialRemoveFace();
  HRESULT Run();
  INLINE CATPersistentBody * GetResult();
  INLINE void GetTrickyPersistentFaces(ListPOfCATPersistentFaces &ioTrickyPersistentFaces);

  void SetCollapseFamilyFaces(ListPOfCATPersistentFaces &iCollapseFamilyFaces);

  void SetAllowedPersistentFacesToRemove(ListPOfCATPersistentFaces &iAllowedPersistentFacesToRemove);

  CATBoolean CheckThatCollapsedFacesAreInTheSameFamily(CATCGMJournalList *iJournal);

  int GetCellFamily(CATCell *iCell);

private:
  CATPersistentBody * _PersistentBody;
  CATPersistentBody * _ResultPersistentBody;
  ListPOfCATPersistentFaces _PersistentFacesToRemove, _TrickyPersistentFaces,_AllowedPersistentFacesToRemove;
  ListPOfCATPersistentFaces _CollapsableFamily;
  short _MatterDirection;
  CATBoolean _PartialRemoveFaceAllowed;

  CATSoftwareConfiguration *_Config;
  const CATAutoBaseThreadContext &_ThreadContext;
};

INLINE void CATAutoBaseRemoveFace::SetMatterDirection(short iMatterDirection)
{
  _MatterDirection = iMatterDirection;
}
INLINE void CATAutoBaseRemoveFace::AllowPartialRemoveFace()
{
  _PartialRemoveFaceAllowed = TRUE;
}
INLINE CATPersistentBody * CATAutoBaseRemoveFace::GetResult()
{
  return _ResultPersistentBody;
}
INLINE void CATAutoBaseRemoveFace::GetTrickyPersistentFaces(ListPOfCATPersistentFaces &ioTrickyPersistentFaces)
{
  ioTrickyPersistentFaces = _TrickyPersistentFaces;
}
#endif
