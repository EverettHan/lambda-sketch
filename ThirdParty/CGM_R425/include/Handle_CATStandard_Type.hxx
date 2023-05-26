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

#ifndef _Handle_CATStandard_Type_HeaderFile
#define _Handle_CATStandard_Type_HeaderFile

#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#ifndef _Handle_CATStandard_Transient_HeaderFile
#include "Handle_CATStandard_Transient.hxx"
#endif

class CATStandard_Transient;
class Handle_CATStandard_Type;
class Handle(CATStandard_Transient);
class CATStandard_Type;
#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& STANDARD_TYPE(CATStandard_Type);

class Handle(CATStandard_Type) : public Handle(CATStandard_Transient) {
  public:
    Handle(CATStandard_Type)():Handle(CATStandard_Transient)() {} 
    Handle(CATStandard_Type)(const Handle(CATStandard_Type)& aHandle) : Handle(CATStandard_Transient)(aHandle) 
     {
     }

    Handle(CATStandard_Type)(const CATStandard_Type* anItem) : Handle(CATStandard_Transient)((CATStandard_Transient *)anItem) 
     {
     }

    Handle(CATStandard_Type)& operator=(const Handle(CATStandard_Type)& aHandle)
     {
      Assign(aHandle.Access());
      return *this;
     }

    Handle(CATStandard_Type)& operator=(const CATStandard_Type* anItem)
     {
      Assign((CATStandard_Transient *)anItem);
      return *this;
     }

    CATStandard_Type* operator->() 
     {
      return (CATStandard_Type *)ControlAccess();
     }

    CATStandard_Type* operator->() const 
     {
      return (CATStandard_Type *)ControlAccess();
     }

   ExportedBySysCascade  ~Handle(CATStandard_Type)();
 
   ExportedBySysCascade  static const Handle(CATStandard_Type) DownCast(const Handle(CATStandard_Transient)& AnObject);
};
#endif
