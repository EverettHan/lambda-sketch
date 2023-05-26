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

#ifndef _CATTColgp_Array1OfVec_HeaderFile
#define _CATTColgp_Array1OfVec_HeaderFile

#ifndef _CATStandard_Integer_HeaderFile
#include "CATStandard_Integer.hxx"
#endif
#ifndef _CATStandard_Address_HeaderFile
#include "CATStandard_Address.hxx"
#endif
#ifndef _CATStandard_Boolean_HeaderFile
#include "CATStandard_Boolean.hxx"
#endif
class CATStandard_RangeError;
class CATStandard_DimensionMismatch;
class CATStandard_OutOfRange;
class CATStandard_OutOfMemory;
class CATgp_Vec;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

class CATTColgp_Array1OfVec  {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade  CATTColgp_Array1OfVec(const CATStandard_Integer Low,const CATStandard_Integer Up);
ExportedBySysCascade  CATTColgp_Array1OfVec(const CATgp_Vec& Item,const CATStandard_Integer Low,const CATStandard_Integer Up);
ExportedBySysCascade    void Init(const CATgp_Vec& V) ;
ExportedBySysCascade    void Destroy() ;
~CATTColgp_Array1OfVec()
{
  Destroy();
}

inline   CATStandard_Boolean IsAllocated() const;
ExportedBySysCascade   const CATTColgp_Array1OfVec& Assign(const CATTColgp_Array1OfVec& Other) ;
 const CATTColgp_Array1OfVec& operator =(const CATTColgp_Array1OfVec& Other) 
{
  return Assign(Other);
}

inline   CATStandard_Integer Length() const;
inline   CATStandard_Integer Lower() const;
inline   CATStandard_Integer Upper() const;
inline   void SetValue(const CATStandard_Integer Index,const CATgp_Vec& Value) ;
inline  const CATgp_Vec& Value(const CATStandard_Integer Index) const;
inline  const CATgp_Vec& operator ()(const CATStandard_Integer Index) const
{
  return Value(Index);
}

inline   CATgp_Vec& ChangeValue(const CATStandard_Integer Index) ;
inline   CATgp_Vec& operator ()(const CATStandard_Integer Index) 
{
  return ChangeValue(Index);
}






protected:

 // Methods PROTECTED
 // 


 // Fields PROTECTED
 //


private: 

 // Methods PRIVATE
 // 
ExportedBySysCascade  CATTColgp_Array1OfVec(const CATTColgp_Array1OfVec& AnArray);


 // Fields PRIVATE
 //
CATStandard_Integer myLowerBound;
CATStandard_Integer myUpperBound;
CATStandard_Address myStart;
CATStandard_Boolean isAllocated;


};

#define Array1Item CATgp_Vec
#define Array1Item_hxx <CATgp_Vec.hxx>
#define CATTCollection_Array1 CATTColgp_Array1OfVec
#define CATTCollection_Array1_hxx <CATTColgp_Array1OfVec.hxx>

#include "CATTCollection_Array1.lxx"

#undef Array1Item
#undef Array1Item_hxx
#undef CATTCollection_Array1
#undef CATTCollection_Array1_hxx


// other inline functions and methods (like "C++: function call" methods)
//


#endif
