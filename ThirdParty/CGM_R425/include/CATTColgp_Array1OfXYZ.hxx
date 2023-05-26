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

#ifndef _CATTColgp_Array1OfXYZ_HeaderFile
#define _CATTColgp_Array1OfXYZ_HeaderFile

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
class CATgp_XYZ;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

class CATTColgp_Array1OfXYZ  {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade  CATTColgp_Array1OfXYZ(const CATStandard_Integer Low,const CATStandard_Integer Up);
ExportedBySysCascade  CATTColgp_Array1OfXYZ(const CATgp_XYZ& Item,const CATStandard_Integer Low,const CATStandard_Integer Up);
ExportedBySysCascade    void Init(const CATgp_XYZ& V) ;
ExportedBySysCascade    void Destroy() ;
~CATTColgp_Array1OfXYZ()
{
  Destroy();
}

inline   CATStandard_Boolean IsAllocated() const;
ExportedBySysCascade   const CATTColgp_Array1OfXYZ& Assign(const CATTColgp_Array1OfXYZ& Other) ;
 const CATTColgp_Array1OfXYZ& operator =(const CATTColgp_Array1OfXYZ& Other) 
{
  return Assign(Other);
}

inline   CATStandard_Integer Length() const;
inline   CATStandard_Integer Lower() const;
inline   CATStandard_Integer Upper() const;
inline   void SetValue(const CATStandard_Integer Index,const CATgp_XYZ& Value) ;
inline  const CATgp_XYZ& Value(const CATStandard_Integer Index) const;
inline  const CATgp_XYZ& operator ()(const CATStandard_Integer Index) const
{
  return Value(Index);
}

inline   CATgp_XYZ& ChangeValue(const CATStandard_Integer Index) ;
inline   CATgp_XYZ& operator ()(const CATStandard_Integer Index) 
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
ExportedBySysCascade  CATTColgp_Array1OfXYZ(const CATTColgp_Array1OfXYZ& AnArray);


 // Fields PRIVATE
 //
CATStandard_Integer myLowerBound;
CATStandard_Integer myUpperBound;
CATStandard_Address myStart;
CATStandard_Boolean isAllocated;


};

#define Array1Item CATgp_XYZ
#define Array1Item_hxx <CATgp_XYZ.hxx>
#define CATTCollection_Array1 CATTColgp_Array1OfXYZ
#define CATTCollection_Array1_hxx <CATTColgp_Array1OfXYZ.hxx>

#include "CATTCollection_Array1.lxx"

#undef Array1Item
#undef Array1Item_hxx
#undef CATTCollection_Array1
#undef CATTCollection_Array1_hxx


// other inline functions and methods (like "C++: function call" methods)
//


#endif
