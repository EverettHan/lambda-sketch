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
#ifndef _CATgp_Vec2d_HeaderFile
#define _CATgp_Vec2d_HeaderFile

#ifndef _CATgp_XY_HeaderFile
#include "CATgp_XY.hxx"
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
class CATStandard_OutOfRange;
class CATgp_VectorWithNullMagnitude;
class CATgp_Dir2d;
class CATgp_XY;
class CATgp_Pnt2d;
class CATgp_Ax2d;
class CATgp_Trsf2d;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATgp_Vec2d_Type_();

class CATgp_Vec2d  {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade inline CATgp_Vec2d();
ExportedBySysCascade inline CATgp_Vec2d(const CATgp_Pnt2d& P1,const CATgp_Pnt2d& P2);
ExportedBySysCascade inline   void Coord(CATStandard_Real& Xv,CATStandard_Real& Yv) const;

/*ExportedBySysCascade inline CATgp_Vec2d(const CATgp_Dir2d& V);
ExportedBySysCascade inline CATgp_Vec2d(const CATgp_XY& Coord);
ExportedBySysCascade inline CATgp_Vec2d(const CATStandard_Real Xv,const CATStandard_Real Yv);
ExportedBySysCascade inline   void SetCoord(const CATStandard_Integer Index,const CATStandard_Real Xi) ;*/
ExportedBySysCascade inline   void SetCoord(const CATStandard_Real Xv,const CATStandard_Real Yv) ;
/*ExportedBySysCascade inline   void SetX(const CATStandard_Real X) ;
ExportedBySysCascade inline   void SetY(const CATStandard_Real Y) ;
ExportedBySysCascade inline   void SetXY(const CATgp_XY& Coord) ;
ExportedBySysCascade inline   CATStandard_Real Coord(const CATStandard_Integer Index) const;
*/
ExportedBySysCascade inline   CATStandard_Real X() const;
ExportedBySysCascade inline   CATStandard_Real Y() const;
/*ExportedBySysCascade inline  const CATgp_XY& XY() const;
ExportedBySysCascade    CATStandard_Boolean IsEqual(const CATgp_Vec2d& Other,const CATStandard_Real LinearTolerance,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsNormal(const CATgp_Vec2d& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsOpposite(const CATgp_Vec2d& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsParallel(const CATgp_Vec2d& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade    CATStandard_Real Angle(const CATgp_Vec2d& Other) const;
ExportedBySysCascade inline   CATStandard_Real Magnitude() const;
ExportedBySysCascade inline   CATStandard_Real SquareMagnitude() const;
ExportedBySysCascade inline   void Add(const CATgp_Vec2d& Other) ;
ExportedBySysCascade inline   void operator +=(const CATgp_Vec2d& Other) 
{
  Add(Other);
}

ExportedBySysCascade inline   CATgp_Vec2d Added(const CATgp_Vec2d& Other) const;
ExportedBySysCascade inline   CATgp_Vec2d operator +(const CATgp_Vec2d& Other) const
{
  return Added(Other);
}

ExportedBySysCascade inline   CATStandard_Real Crossed(const CATgp_Vec2d& Right) const;
ExportedBySysCascade inline   CATStandard_Real operator ^(const CATgp_Vec2d& Right) const
{
  return Crossed(Right);
}

ExportedBySysCascade inline   CATStandard_Real CrossMagnitude(const CATgp_Vec2d& Right) const;
ExportedBySysCascade inline   CATStandard_Real CrossSquareMagnitude(const CATgp_Vec2d& Right) const;
ExportedBySysCascade inline   void Divide(const CATStandard_Real Scalar) ;
ExportedBySysCascade inline   void operator /=(const CATStandard_Real Scalar) 
{
  Divide(Scalar);
}

ExportedBySysCascade inline   CATgp_Vec2d Divided(const CATStandard_Real Scalar) const;
ExportedBySysCascade inline   CATgp_Vec2d operator /(const CATStandard_Real Scalar) const
{
  return Divided(Scalar);
}

ExportedBySysCascade inline   CATStandard_Real Dot(const CATgp_Vec2d& Other) const;
ExportedBySysCascade inline   CATStandard_Real operator *(const CATgp_Vec2d& Other) const
{
  return Dot(Other);
}
*/
ExportedBySysCascade inline   void Multiply(const CATStandard_Real Scalar) ;
ExportedBySysCascade inline   void operator *=(const CATStandard_Real Scalar) 
{
  Multiply(Scalar);
}
/*
ExportedBySysCascade inline   CATgp_Vec2d Multiplied(const CATStandard_Real Scalar) const;
ExportedBySysCascade inline   CATgp_Vec2d operator *(const CATStandard_Real Scalar) const
{
  return Multiplied(Scalar);
}

ExportedBySysCascade inline   void Normalize() ;
ExportedBySysCascade inline   CATgp_Vec2d Normalized() const;
ExportedBySysCascade inline   void Reverse() ;
ExportedBySysCascade inline   CATgp_Vec2d Reversed() const;
ExportedBySysCascade inline   CATgp_Vec2d operator -() const
{
  return Reversed();
}

ExportedBySysCascade inline   void Subtract(const CATgp_Vec2d& Right) ;
ExportedBySysCascade inline   void operator -=(const CATgp_Vec2d& Right) 
{
  Subtract(Right);
}

ExportedBySysCascade inline   CATgp_Vec2d Subtracted(const CATgp_Vec2d& Right) const;
ExportedBySysCascade inline   CATgp_Vec2d operator -(const CATgp_Vec2d& Right) const
{
  return Subtracted(Right);
}

ExportedBySysCascade inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec2d& V1,const CATStandard_Real A2,const CATgp_Vec2d& V2,const CATgp_Vec2d& V3) ;
ExportedBySysCascade inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec2d& V1,const CATStandard_Real A2,const CATgp_Vec2d& V2) ;
ExportedBySysCascade inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_Vec2d& V1,const CATgp_Vec2d& V2) ;
ExportedBySysCascade inline   void SetLinearForm(const CATgp_Vec2d& Left,const CATgp_Vec2d& Right) ;
ExportedBySysCascade    void Mirror(const CATgp_Vec2d& V) ;
ExportedBySysCascade    CATgp_Vec2d Mirrored(const CATgp_Vec2d& V) const;
ExportedBySysCascade    void Mirror(const CATgp_Ax2d& A1) ;
ExportedBySysCascade    CATgp_Vec2d Mirrored(const CATgp_Ax2d& A1) const;
ExportedBySysCascade inline   void Rotate(const CATStandard_Real Ang) ;
ExportedBySysCascade inline   CATgp_Vec2d Rotated(const CATStandard_Real Ang) const;
ExportedBySysCascade inline   void Scale(const CATStandard_Real S) ;
ExportedBySysCascade inline   CATgp_Vec2d Scaled(const CATStandard_Real S) const;
ExportedBySysCascade    void Transform(const CATgp_Trsf2d& T) ;
ExportedBySysCascade inline   CATgp_Vec2d Transformed(const CATgp_Trsf2d& T) const;
    const CATgp_XY& _CSFDB_GetCATgp_Vec2dcoord() const { return coord; }

*/


 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATgp_Vec2d_Type_();

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
CATgp_XY coord;


};


#include "CATgp_Vec2d.lxx"



// other ExportedBySysCascade inline functions and methods (like "C++: function call" methods)
//


#endif
