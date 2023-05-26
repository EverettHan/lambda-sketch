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

#ifndef _CATTColgp_HArray1OfPnt_HeaderFile
#define _CATTColgp_HArray1OfPnt_HeaderFile

#ifndef _Handle_CATTColgp_HArray1OfPnt_HeaderFile
#include "Handle_CATTColgp_HArray1OfPnt.hxx"
#endif

#ifndef _CATTColgp_Array1OfPnt_HeaderFile
#include "CATTColgp_Array1OfPnt.hxx"
#endif
#ifndef _CATMMgt_TShared_HeaderFile
#include "CATMMgt_TShared.hxx"
#endif
#ifndef _CATStandard_Integer_HeaderFile
#include "CATStandard_Integer.hxx"
#endif
class CATStandard_RangeError;
class CATStandard_OutOfRange;
class CATStandard_OutOfMemory;
class CATStandard_DimensionMismatch;
class CATgp_Pnt;
class CATTColgp_Array1OfPnt;


#include "SysCascade.h"

class CATTColgp_HArray1OfPnt : public CATMMgt_TShared {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade  CATTColgp_HArray1OfPnt(const CATStandard_Integer R1,const CATStandard_Integer R2);
ExportedBySysCascade  CATTColgp_HArray1OfPnt(const CATStandard_Integer R1,const CATStandard_Integer R2,const CATgp_Pnt& V);
ExportedBySysCascade    void Init(const CATgp_Pnt& V) ;
inline   CATStandard_Integer Length() const;
inline   CATStandard_Integer Lower() const;
inline   CATStandard_Integer Upper() const;
inline   void SetValue(const CATStandard_Integer Row,const CATgp_Pnt& Value) ;
ExportedBySysCascade   const CATgp_Pnt& Value(const CATStandard_Integer Row) const;
ExportedBySysCascade    CATgp_Pnt& ChangeValue(const CATStandard_Integer Row) ;
inline  const CATTColgp_Array1OfPnt& Array1() const;
inline   CATTColgp_Array1OfPnt& ChangeArray1() ;
ExportedBySysCascade  ~CATTColgp_HArray1OfPnt();




 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATTColgp_HArray1OfPnt_Type_();
 ExportedBySysCascade  const Handle(CATStandard_Type)& DynamicType() const;
 ExportedBySysCascade  CATStandard_Boolean	       IsKind(const Handle(CATStandard_Type)&) const;

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
CATTColgp_Array1OfPnt myArray;


};

#define ItemHArray1 CATgp_Pnt
#define ItemHArray1_hxx <CATgp_Pnt.hxx>
#define TheArray1 CATTColgp_Array1OfPnt
#define TheArray1_hxx <CATTColgp_Array1OfPnt.hxx>
#define CATTCollection_HArray1 CATTColgp_HArray1OfPnt
#define CATTCollection_HArray1_hxx <CATTColgp_HArray1OfPnt.hxx>
#define Handle_CATTCollection_HArray1 Handle_CATTColgp_HArray1OfPnt
#define CATTCollection_HArray1_Type_() CATTColgp_HArray1OfPnt_Type_()

#include "CATTCollection_HArray1.lxx"

#undef ItemHArray1
#undef ItemHArray1_hxx
#undef TheArray1
#undef TheArray1_hxx
#undef CATTCollection_HArray1
#undef CATTCollection_HArray1_hxx
#undef Handle_CATTCollection_HArray1
#undef CATTCollection_HArray1_Type_


// other inline functions and methods (like "C++: function call" methods)
//


#endif
