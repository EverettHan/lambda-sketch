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

#ifndef _CATTColgp_HArray1OfVec_HeaderFile
#define _CATTColgp_HArray1OfVec_HeaderFile

#ifndef _Handle_CATTColgp_HArray1OfVec_HeaderFile
#include "Handle_CATTColgp_HArray1OfVec.hxx"
#endif

#ifndef _CATTColgp_Array1OfVec_HeaderFile
#include "CATTColgp_Array1OfVec.hxx"
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
class CATgp_Vec;
class CATTColgp_Array1OfVec;


#include "SysCascade.h"

class CATTColgp_HArray1OfVec : public CATMMgt_TShared {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade  CATTColgp_HArray1OfVec(const CATStandard_Integer R1,const CATStandard_Integer R2);
ExportedBySysCascade  CATTColgp_HArray1OfVec(const CATStandard_Integer R1,const CATStandard_Integer R2,const CATgp_Vec& V);
ExportedBySysCascade    void Init(const CATgp_Vec& V) ;
inline   CATStandard_Integer Length() const;
inline   CATStandard_Integer Lower() const;
inline   CATStandard_Integer Upper() const;
inline   void SetValue(const CATStandard_Integer Row,const CATgp_Vec& Value) ;
ExportedBySysCascade   const CATgp_Vec& Value(const CATStandard_Integer Row) const;
ExportedBySysCascade    CATgp_Vec& ChangeValue(const CATStandard_Integer Row) ;
inline  const CATTColgp_Array1OfVec& Array1() const;
inline   CATTColgp_Array1OfVec& ChangeArray1() ;
ExportedBySysCascade  ~CATTColgp_HArray1OfVec();




 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATTColgp_HArray1OfVec_Type_();
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
CATTColgp_Array1OfVec myArray;


};

#define ItemHArray1 CATgp_Vec
#define ItemHArray1_hxx <CATgp_Vec.hxx>
#define TheArray1 CATTColgp_Array1OfVec
#define TheArray1_hxx <CATTColgp_Array1OfVec.hxx>
#define CATTCollection_HArray1 CATTColgp_HArray1OfVec
#define CATTCollection_HArray1_hxx <CATTColgp_HArray1OfVec.hxx>
#define Handle_CATTCollection_HArray1 Handle_CATTColgp_HArray1OfVec
#define CATTCollection_HArray1_Type_() CATTColgp_HArray1OfVec_Type_()

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
