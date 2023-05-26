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

#ifndef _Handle_CATMMgt_TShared_HeaderFile
#define _Handle_CATMMgt_TShared_HeaderFile

#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#ifndef _Handle_CATStandard_Transient_HeaderFile
#include "Handle_CATStandard_Transient.hxx"
#endif

class CATStandard_Transient;
class Handle_CATStandard_Type;
class Handle(CATStandard_Transient);
class CATMMgt_TShared;

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& STANDARD_TYPE(CATMMgt_TShared);

class Handle(CATMMgt_TShared) : public Handle(CATStandard_Transient) {
  public:
    Handle(CATMMgt_TShared)():Handle(CATStandard_Transient)() {} 
    Handle(CATMMgt_TShared)(const Handle(CATMMgt_TShared)& aHandle) : Handle(CATStandard_Transient)(aHandle) 
     {
     }

    Handle(CATMMgt_TShared)(const CATMMgt_TShared* anItem) : Handle(CATStandard_Transient)((CATStandard_Transient *)anItem) 
     {
     }

    Handle(CATMMgt_TShared)& operator=(const Handle(CATMMgt_TShared)& aHandle)
     {
      Assign(aHandle.Access());
      return *this;
     }

    Handle(CATMMgt_TShared)& operator=(const CATMMgt_TShared* anItem)
     {
      Assign((CATStandard_Transient *)anItem);
      return *this;
     }

    CATMMgt_TShared* operator->() 
     {
      return (CATMMgt_TShared *)ControlAccess();
     }

    CATMMgt_TShared* operator->() const 
     {
      return (CATMMgt_TShared *)ControlAccess();
     }

   ExportedBySysCascade  ~Handle(CATMMgt_TShared)();
 
   ExportedBySysCascade  static const Handle(CATMMgt_TShared) DownCast(const Handle(CATStandard_Transient)& AnObject);
};
#endif