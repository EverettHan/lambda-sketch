//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
//  Avril 2003 : jcv/anr : Creation (Cascade)
//====================================================================

#ifndef _Handle_CATTColgp_HArray1OfVec2d_HeaderFile
#define _Handle_CATTColgp_HArray1OfVec2d_HeaderFile

#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#ifndef _Handle_CATMMgt_TShared_HeaderFile
#include "Handle_CATMMgt_TShared.hxx"
#endif

class CATStandard_Transient;
class Handle_CATStandard_Type;
class Handle(CATMMgt_TShared);
class CATTColgp_HArray1OfVec2d;
#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& STANDARD_TYPE(CATTColgp_HArray1OfVec2d);

class Handle(CATTColgp_HArray1OfVec2d) : public Handle(CATMMgt_TShared) {
  public:
    Handle(CATTColgp_HArray1OfVec2d)():Handle(CATMMgt_TShared)() {} 
    Handle(CATTColgp_HArray1OfVec2d)(const Handle(CATTColgp_HArray1OfVec2d)& aHandle) : Handle(CATMMgt_TShared)(aHandle) 
     {
     }

    Handle(CATTColgp_HArray1OfVec2d)(const CATTColgp_HArray1OfVec2d* anItem) : Handle(CATMMgt_TShared)((CATMMgt_TShared *)anItem) 
     {
     }

    Handle(CATTColgp_HArray1OfVec2d)& operator=(const Handle(CATTColgp_HArray1OfVec2d)& aHandle)
     {
      Assign(aHandle.Access());
      return *this;
     }

    Handle(CATTColgp_HArray1OfVec2d)& operator=(const CATTColgp_HArray1OfVec2d* anItem)
     {
      Assign((CATStandard_Transient *)anItem);
      return *this;
     }

    CATTColgp_HArray1OfVec2d* operator->() 
     {
      return (CATTColgp_HArray1OfVec2d *)ControlAccess();
     }

    CATTColgp_HArray1OfVec2d* operator->() const 
     {
      return (CATTColgp_HArray1OfVec2d *)ControlAccess();
     }

   ExportedBySysCascade  ~Handle(CATTColgp_HArray1OfVec2d)();
 
   ExportedBySysCascade  static const Handle(CATTColgp_HArray1OfVec2d) DownCast(const Handle(CATStandard_Transient)& AnObject);
};
#endif
