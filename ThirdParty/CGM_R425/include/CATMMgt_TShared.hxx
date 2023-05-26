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
//
#ifndef _CATMMgt_TShared_HeaderFile
#define _CATMMgt_TShared_HeaderFile

#ifndef _Handle_CATMMgt_TShared_HeaderFile
#include "Handle_CATMMgt_TShared.hxx"
#endif

#ifndef _CATStandard_Transient_HeaderFile
#include "CATStandard_Transient.hxx"
#endif
#ifndef _CATStandard_Address_HeaderFile
#include "CATStandard_Address.hxx"
#endif
#ifndef _CATStandard_Integer_HeaderFile
#include "CATStandard_Integer.hxx"
#endif
class CATStandard_OutOfMemory;


#include "SysCascade.h"

class ExportedBySysCascade CATMMgt_TShared : public CATStandard_Transient {

public:

 // Methods PUBLIC
 // 
/*ExportedBySysCascade  static  CATStandard_Address New(const CATStandard_Integer aSize) ;
ExportedBySysCascade  void* operator new (size_t);
ExportedBySysCascade  static  void Destroy(CATStandard_Address& aInstance,const CATStandard_Integer aSize) ;
ExportedBySysCascade  void operator delete (void*, size_t);
*/
virtual  void Delete() const;
~CATMMgt_TShared();




 // Type management
 //
 friend ExportedBySysCascade Handle_CATStandard_Type& CATMMgt_TShared_Type_();
 const Handle(CATStandard_Type)& DynamicType() const;
 CATStandard_Boolean	       IsKind(const Handle(CATStandard_Type)&) const;

protected:

 // Methods PROTECTED
 // 


 // Fields PROTECTED
 //


private: 

 // Methods PRIVATE
 // 


 // Fields PRIVATE
 //


};





// other inline functions and methods (like "C++: function call" methods)
//


#endif