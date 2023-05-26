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

#ifndef _Handle_CATTColStd_HArray2OfReal_HeaderFile
#define _Handle_CATTColStd_HArray2OfReal_HeaderFile

#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#ifndef _Handle_CATMMgt_TShared_HeaderFile
#include "Handle_CATMMgt_TShared.hxx"
#endif

class CATStandard_Transient;
class Handle_CATStandard_Type;
class Handle(CATMMgt_TShared);
class CATTColStd_HArray2OfReal;
#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& STANDARD_TYPE(CATTColStd_HArray2OfReal);

class Handle(CATTColStd_HArray2OfReal) : public Handle(CATMMgt_TShared) {
  public:
    Handle(CATTColStd_HArray2OfReal)():Handle(CATMMgt_TShared)() {} 
    Handle(CATTColStd_HArray2OfReal)(const Handle(CATTColStd_HArray2OfReal)& aHandle) : Handle(CATMMgt_TShared)(aHandle) 
     {
     }

    Handle(CATTColStd_HArray2OfReal)(const CATTColStd_HArray2OfReal* anItem) : Handle(CATMMgt_TShared)((CATMMgt_TShared *)anItem) 
     {
     }

    Handle(CATTColStd_HArray2OfReal)& operator=(const Handle(CATTColStd_HArray2OfReal)& aHandle)
     {
      Assign(aHandle.Access());
      return *this;
     }

    Handle(CATTColStd_HArray2OfReal)& operator=(const CATTColStd_HArray2OfReal* anItem)
     {
      Assign((CATStandard_Transient *)anItem);
      return *this;
     }

    CATTColStd_HArray2OfReal* operator->() 
     {
      return (CATTColStd_HArray2OfReal *)ControlAccess();
     }

    CATTColStd_HArray2OfReal* operator->() const 
     {
      return (CATTColStd_HArray2OfReal *)ControlAccess();
     }

   ExportedBySysCascade  ~Handle(CATTColStd_HArray2OfReal)();
 
   ExportedBySysCascade  static const Handle(CATTColStd_HArray2OfReal) DownCast(const Handle(CATStandard_Transient)& AnObject);
};
#endif
