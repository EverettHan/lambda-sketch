// File generated by CPPExt (Storable)
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
#ifndef _CATgp_Vec_HeaderFile
#define _CATgp_Vec_HeaderFile

#ifndef _CATgp_XYZ_HeaderFile
#include "CATgp_XYZ.hxx"
#endif
#ifndef _CATStandard_Storable_HeaderFile
#include "CATStandard_Storable.hxx"
#endif
#ifndef _CATStandard_Real_HeaderFile
#include "CATStandard_Real.hxx"
#endif
#ifndef _CATStandard_Integer_HeaderFile
#include "CATStandard_Integer.hxx"
#endif
#ifndef _CATStandard_Boolean_HeaderFile
#include "CATStandard_Boolean.hxx"
#endif
#ifndef _CATStandard_PrimitiveTypes_HeaderFile
#include "CATStandard_PrimitiveTypes.hxx"
#endif
class CATStandard_ConstructionError;
class CATStandard_DomainError;
class CATStandard_OutOfRange;
class CATgp_VectorWithNullMagnitude;
class CATgp_Dir;
class CATgp_XYZ;
class CATgp_Pnt;
class CATgp_Ax1;
class CATgp_Ax2;
class CATgp_Trsf;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATgp_Vec_Type_();

class CATgp_Vec  {

public:

 // Methods PUBLIC
 // 
inline CATgp_Vec();
//inline CATgp_Vec(const CATgp_Dir& V);
//inline CATgp_Vec(const CATgp_XYZ& Coord);
inline CATgp_Vec(const CATStandard_Real Xv,const CATStandard_Real Yv,const CATStandard_Real Zv);
inline CATgp_Vec(const CATgp_Pnt& P1,const CATgp_Pnt& P2);
inline   void SetCoord(const CATStandard_Integer Index,const CATStandard_Real Xi) ;
inline   void SetCoord(const CATStandard_Real Xv,const CATStandard_Real Yv,const CATStandard_Real Zv) ;
inline   void SetX(const CATStandard_Real X) ;
inline   void SetY(const CATStandard_Real Y) ;
inline   void SetZ(const CATStandard_Real Z) ;
//inline   void SetXYZ(const CATgp_XYZ& Coord) ;
inline   CATStandard_Real Coord(const CATStandard_Integer Index) const;
inline   void Coord(CATStandard_Real& Xv,CATStandard_Real& Yv,CATStandard_Real& Zv) const;
inline   CATStandard_Real X() const;
inline   CATStandard_Real Y() const;
inline   CATStandard_Real Z() const;
//inline  const CATgp_XYZ& XYZ() const;
/*ExportedBySysCascade    CATStandard_Boolean IsEqual(const CATgp_Vec& Other,const CATStandard_Real LinearTolerance,const CATStandard_Real AngularTolerance) const;
inline   CATStandard_Boolean IsNormal(const CATgp_Vec& Other,const CATStandard_Real AngularTolerance) const;
inline   CATStandard_Boolean IsOpposite(const CATgp_Vec& Other,const CATStandard_Real AngularTolerance) const;
inline   CATStandard_Boolean IsParallel(const CATgp_Vec& Other,const CATStandard_Real AngularTolerance) const;
inline   CATStandard_Real Angle(const CATgp_Vec& Other) const;
inline   CATStandard_Real AngleWithRef(const CATgp_Vec& Other,const CATgp_Vec& VRef) const;
inline   CATStandard_Real Magnitude() const;
inline   CATStandard_Real SquareMagnitude() const;
inline   void Add(const CATgp_Vec& Other) ;
inline   void operator +=(const CATgp_Vec& Other) 
{
  Add(Other);
}

inline   CATgp_Vec Added(const CATgp_Vec& Other) const;
inline   CATgp_Vec operator +(const CATgp_Vec& Other) const
{
  return Added(Other);
}

inline   void Subtract(const CATgp_Vec& Right) ;
inline   void operator -=(const CATgp_Vec& Right) 
{
  Subtract(Right);
}

inline   CATgp_Vec Subtracted(const CATgp_Vec& Right) const;
inline   CATgp_Vec operator -(const CATgp_Vec& Right) const
{
  return Subtracted(Right);
}
*/
inline   void Multiply(const CATStandard_Real Scalar) ;
inline   void operator *=(const CATStandard_Real Scalar) 
{
  Multiply(Scalar);
}
/*
inline   CATgp_Vec Multiplied(const CATStandard_Real Scalar) const;
inline   CATgp_Vec operator *(const CATStandard_Real Scalar) const
{
  return Multiplied(Scalar);
}

inline   void Divide(const CATStandard_Real Scalar) ;
inline   void operator /=(const CATStandard_Real Scalar) 
{
  Divide(Scalar);
}

inline   CATgp_Vec Divided(const CATStandard_Real Scalar) const;
inline   CATgp_Vec operator /(const CATStandard_Real Scalar) const
{
  return Divided(Scalar);
}

inline   void Cross(const CATgp_Vec& Right) ;
inline   void operator ^=(const CATgp_Vec& Right) 
{
  Cross(Right);
}

inline   CATgp_Vec Crossed(const CATgp_Vec& Right) const;
inline   CATgp_Vec operator ^(const CATgp_Vec& Right) const
{
  return Crossed(Right);
}

inline   CATStandard_Real CrossMagnitude(const CATgp_Vec& Right) const;
inline   CATStandard_Real CrossSquareMagnitude(const CATgp_Vec& Right) const;
inline   void CrossCross(const CATgp_Vec& V1,const CATgp_Vec& V2) ;
inline   CATgp_Vec CrossCrossed(const CATgp_Vec& V1,const CATgp_Vec& V2) const;
inline   CATStandard_Real Dot(const CATgp_Vec& Other) const;
inline   CATStandard_Real operator *(const CATgp_Vec& Other) const
{
  return Dot(Other);
}

inline   CATStandard_Real DotCross(const CATgp_Vec& V1,const CATgp_Vec& V2) const;
inline   void Normalize() ;
inline   CATgp_Vec Normalized() const;
inline   void Reverse() ;
inline   CATgp_Vec Reversed() const;
inline   CATgp_Vec operator -() const
{
  return Reversed();
}

inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec& V1,const CATStandard_Real A2,const CATgp_Vec& V2,const CATStandard_Real A3,const CATgp_Vec& V3,const CATgp_Vec& V4) ;
inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec& V1,const CATStandard_Real A2,const CATgp_Vec& V2,const CATStandard_Real A3,const CATgp_Vec& V3) ;
inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec& V1,const CATStandard_Real A2,const CATgp_Vec& V2,const CATgp_Vec& V3) ;
inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec& V1,const CATStandard_Real A2,const CATgp_Vec& V2) ;
inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec& V1,const CATgp_Vec& V2) ;
inline   void SetLinearForm(const CATgp_Vec& V1,const CATgp_Vec& V2) ;
ExportedBySysCascade    void Mirror(const CATgp_Vec& V) ;
ExportedBySysCascade    CATgp_Vec Mirrored(const CATgp_Vec& V) const;
ExportedBySysCascade    void Mirror(const CATgp_Ax1& A1) ;
ExportedBySysCascade    CATgp_Vec Mirrored(const CATgp_Ax1& A1) const;
ExportedBySysCascade    void Mirror(const CATgp_Ax2& A2) ;
ExportedBySysCascade    CATgp_Vec Mirrored(const CATgp_Ax2& A2) const;
inline   void Rotate(const CATgp_Ax1& A1,const CATStandard_Real Ang) ;
inline   CATgp_Vec Rotated(const CATgp_Ax1& A1,const CATStandard_Real Ang) const;
inline   void Scale(const CATStandard_Real S) ;
inline   CATgp_Vec Scaled(const CATStandard_Real S) const;
*/
//ExportedBySysCascade    void Transform(const CATgp_Trsf& T) ;
//inline   CATgp_Vec Transformed(const CATgp_Trsf& T) const;
//    const CATgp_XYZ& _CSFDB_GetCATgp_Veccoord() const { return coord; }




 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATgp_Vec_Type_();

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
CATgp_XYZ coord;


};


#include "CATgp_Vec.lxx"



// other inline functions and methods (like "C++: function call" methods)
//


#endif
