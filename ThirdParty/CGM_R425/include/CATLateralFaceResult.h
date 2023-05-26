#ifndef CATLateralFaceResult_H
#define CATLateralFaceResult_H

#include "CATCGMNewArray.h"

#include "AdvTrimOpe.h"
#include "ListPOfCATEdge.h"
#include "CATEdge.h"
#include "CATlsoError.h"
#include "ListPOfCATLateralFaceResult.h"

class CATGlobalThicknessContext;

#define LateralFaceType           CATLateralFaceResult::LateralFace_type

class ExportedByAdvTrimOpe CATLateralFaceResult //PPU7: Faire deriver du bon objet
{

public:

  enum LateralFace_type {
    LATERALFACE_UNKNOWN = 0,
    LATERALFACE_CANDIDATE = 1,
    LATERALFACE_ADMITTED = 2,
    LATERALFACE_REFUSED = 3
  };

  //Constructor
  CATLateralFaceResult (CATFace * ipLateralFace, LateralFaceType iTrustLevel, ListPOfCATEdge iEdge1List, ListPOfCATEdge iEdge2List);
  CATLateralFaceResult (CATLateralFaceResult & iLateralFaceResult); // Constructeur par copie
  // surcharge de new
  CATCGMNewClassArrayDeclare;

  //Destructor
  ~CATLateralFaceResult ();

  //Methods
  //Get Methods
  INLINE CATFace * GetLateralFace () const;
  INLINE LateralFace_type GetTrustLevel () const;
  INLINE const ListPOfCATEdge & GetEdge1List () const;
  INLINE const ListPOfCATEdge & GetEdge2List () const;
  int  GetNbEdgeCouple () const;
  void GetEdgeCoupleNumber (const int iNum, CATEdge *& opEdge1, CATEdge *& opEdge2) const;

  //SetMethods
  INLINE void SetTrustLevel (const LateralFace_type iTrustLevel);
  void AppendCouple (CATEdge * ipEdge1, CATEdge * ipEdge2);

  void PutColorForDebug (CATGlobalThicknessContext & iContext) const;

  // Dump
  void Dump (CATCGMOutput& os) const;
  static void DumpList (CATCGMOutput& os, ListPOfCATLateraFaceResult & iLateralFaceResultList);

private:

  //Members
  CATFace *        _pLateralFace;
  LateralFace_type _TrustLevel;
  ListPOfCATEdge   _Edge1List;
  ListPOfCATEdge   _Edge2List;
};

INLINE CATFace * CATLateralFaceResult::GetLateralFace () const {
  return _pLateralFace;
}

INLINE LateralFaceType CATLateralFaceResult::GetTrustLevel () const {
  return _TrustLevel;
}

INLINE const ListPOfCATEdge & CATLateralFaceResult::GetEdge1List () const {
  return _Edge1List;
}

INLINE const ListPOfCATEdge & CATLateralFaceResult::GetEdge2List () const {
  return _Edge2List;
}

INLINE void CATLateralFaceResult::SetTrustLevel (const LateralFaceType iTrustLevel) {
  _TrustLevel = iTrustLevel;
}

#endif


