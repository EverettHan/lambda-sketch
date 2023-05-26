// File generated by CPPExt (Transient)
//
//                     Copyright (C) 1991,1995 by
//  
//                      MATRA DATAVISION, FRANCE
//  
// This software is furnished in accordance with the terms and conditions
// of the contract and with the inclusion of the above copyright notice.
// This software or any other copy thereof may not be provided or otherwise
// be made available to any other person. No title to an ownership of the
// software is hereby transferred.
//  
// At the termination of the contract, the software and all copies of this
// software must be deleted.

#ifndef _Handle_CATTColgp_HArray2OfXYZ_HeaderFile
#define _Handle_CATTColgp_HArray2OfXYZ_HeaderFile

#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#ifndef _Handle_CATMMgt_TShared_HeaderFile
#include "Handle_CATMMgt_TShared.hxx"
#endif

class CATStandard_Transient;
class Handle_CATStandard_Type;
class Handle(CATMMgt_TShared);
class CATTColgp_HArray2OfXYZ;
#include "SysCascade.h"


ExportedBySysCascade  Handle_CATStandard_Type& STANDARD_TYPE(CATTColgp_HArray2OfXYZ);

class Handle(CATTColgp_HArray2OfXYZ) : public Handle(CATMMgt_TShared) {
  public:
    Handle(CATTColgp_HArray2OfXYZ)():Handle(CATMMgt_TShared)() {} 
    Handle(CATTColgp_HArray2OfXYZ)(const Handle(CATTColgp_HArray2OfXYZ)& aHandle) : Handle(CATMMgt_TShared)(aHandle) 
     {
     }

    Handle(CATTColgp_HArray2OfXYZ)(const CATTColgp_HArray2OfXYZ* anItem) : Handle(CATMMgt_TShared)((CATMMgt_TShared *)anItem) 
     {
     }

    Handle(CATTColgp_HArray2OfXYZ)& operator=(const Handle(CATTColgp_HArray2OfXYZ)& aHandle)
     {
      Assign(aHandle.Access());
      return *this;
     }

    Handle(CATTColgp_HArray2OfXYZ)& operator=(const CATTColgp_HArray2OfXYZ* anItem)
     {
      Assign((CATStandard_Transient *)anItem);
      return *this;
     }

    CATTColgp_HArray2OfXYZ* operator->() 
     {
      return (CATTColgp_HArray2OfXYZ *)ControlAccess();
     }

    CATTColgp_HArray2OfXYZ* operator->() const 
     {
      return (CATTColgp_HArray2OfXYZ *)ControlAccess();
     }

   ExportedBySysCascade  ~Handle(CATTColgp_HArray2OfXYZ)();
 
   ExportedBySysCascade  static const Handle(CATTColgp_HArray2OfXYZ) DownCast(const Handle(CATStandard_Transient)& AnObject);
};
#endif
