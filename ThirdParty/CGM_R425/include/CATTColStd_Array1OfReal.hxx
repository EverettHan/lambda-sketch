// File generated by CPPExt (Value)
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

#ifndef _CATTColStd_Array1OfReal_HeaderFile
#define _CATTColStd_Array1OfReal_HeaderFile

#ifndef _CATStandard_Integer_HeaderFile
#include "CATStandard_Integer.hxx"
#endif
#ifndef _CATStandard_Address_HeaderFile
#include "CATStandard_Address.hxx"
#endif
#ifndef _CATStandard_Boolean_HeaderFile
#include "CATStandard_Boolean.hxx"
#endif
#ifndef _CATStandard_Real_HeaderFile
#include "CATStandard_Real.hxx"
#endif
class CATStandard_RangeError;
class CATStandard_DimensionMismatch;
class CATStandard_OutOfRange;
class CATStandard_OutOfMemory;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

class CATTColStd_Array1OfReal  {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade  CATTColStd_Array1OfReal(const CATStandard_Integer Low,const CATStandard_Integer Up);
ExportedBySysCascade  CATTColStd_Array1OfReal(const CATStandard_Real& Item,const CATStandard_Integer Low,const CATStandard_Integer Up);
ExportedBySysCascade    void Init(const CATStandard_Real& V) ;
ExportedBySysCascade    void Destroy() ;
~CATTColStd_Array1OfReal()
{
  Destroy();
}

inline   CATStandard_Boolean IsAllocated() const;
ExportedBySysCascade   const CATTColStd_Array1OfReal& Assign(const CATTColStd_Array1OfReal& Other) ;
 const CATTColStd_Array1OfReal& operator =(const CATTColStd_Array1OfReal& Other) 
{
  return Assign(Other);
}

inline   CATStandard_Integer Length() const;
inline   CATStandard_Integer Lower() const;
inline   CATStandard_Integer Upper() const;
inline   void SetValue(const CATStandard_Integer Index,const CATStandard_Real& Value) ;
inline  const CATStandard_Real& Value(const CATStandard_Integer Index) const;
inline  const CATStandard_Real& operator ()(const CATStandard_Integer Index) const
{
  return Value(Index);
}

inline   CATStandard_Real& ChangeValue(const CATStandard_Integer Index) ;
inline   CATStandard_Real& operator ()(const CATStandard_Integer Index) 
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
ExportedBySysCascade  CATTColStd_Array1OfReal(const CATTColStd_Array1OfReal& AnArray);


 // Fields PRIVATE
 //
CATStandard_Integer myLowerBound;
CATStandard_Integer myUpperBound;
CATStandard_Address myStart;
CATStandard_Boolean isAllocated;


};

#define Array1Item CATStandard_Real
#define Array1Item_hxx <CATStandard_Real.hxx>
#define CATTCollection_Array1 CATTColStd_Array1OfReal
#define CATTCollection_Array1_hxx <CATTColStd_Array1OfReal.hxx>

#include "CATTCollection_Array1.lxx"

#undef Array1Item
#undef Array1Item_hxx
#undef CATTCollection_Array1
#undef CATTCollection_Array1_hxx


// other inline functions and methods (like "C++: function call" methods)
//


#endif
