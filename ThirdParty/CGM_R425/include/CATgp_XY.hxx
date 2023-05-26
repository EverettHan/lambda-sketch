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
#ifndef _CATgp_XY_HeaderFile
#define _CATgp_XY_HeaderFile

#ifndef _CATStandard_Real_HeaderFile
#include "CATStandard_Real.hxx"
#endif
#ifndef _CATStandard_Storable_HeaderFile
#include "CATStandard_Storable.hxx"
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
//class CATgp_Mat2d;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATgp_XY_Type_();

class CATgp_XY  {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade inline CATgp_XY();
ExportedBySysCascade inline CATgp_XY(const CATStandard_Real X,const CATStandard_Real Y);
ExportedBySysCascade inline   void SetCoord(const CATStandard_Integer Index,const CATStandard_Real Xi) ;
ExportedBySysCascade inline   void SetCoord(const CATStandard_Real X,const CATStandard_Real Y) ;
ExportedBySysCascade inline   void SetX(const CATStandard_Real X) ;
ExportedBySysCascade inline   void SetY(const CATStandard_Real Y) ;
ExportedBySysCascade inline   CATStandard_Real Coord(const CATStandard_Integer Index) const;
ExportedBySysCascade inline   void Coord(CATStandard_Real& X,CATStandard_Real& Y) const;
ExportedBySysCascade inline   CATStandard_Real X() const;
ExportedBySysCascade inline   CATStandard_Real Y() const;
ExportedBySysCascade inline   CATStandard_Real Modulus() const;
ExportedBySysCascade inline   CATStandard_Real SquareModulus() const;
ExportedBySysCascade    CATStandard_Boolean IsEqual(const CATgp_XY& Other,const CATStandard_Real Tolerance) const;
ExportedBySysCascade inline   void Add(const CATgp_XY& Other) ;
ExportedBySysCascade inline   void operator +=(const CATgp_XY& Other) 
{
  Add(Other);
}

ExportedBySysCascade inline   CATgp_XY Added(const CATgp_XY& Other) const;
ExportedBySysCascade inline   CATgp_XY operator +(const CATgp_XY& Other) const
{
  return Added(Other);
}

ExportedBySysCascade inline   CATStandard_Real Crossed(const CATgp_XY& Right) const;
ExportedBySysCascade inline   CATStandard_Real operator ^(const CATgp_XY& Right) const
{
  return Crossed(Right);
}

ExportedBySysCascade inline   CATStandard_Real CrossMagnitude(const CATgp_XY& Right) const;
ExportedBySysCascade inline   CATStandard_Real CrossSquareMagnitude(const CATgp_XY& Right) const;
ExportedBySysCascade inline   void Divide(const CATStandard_Real Scalar) ;
ExportedBySysCascade inline   void operator /=(const CATStandard_Real Scalar) 
{
  Divide(Scalar);
}

ExportedBySysCascade inline   CATgp_XY Divided(const CATStandard_Real Scalar) const;
ExportedBySysCascade inline   CATgp_XY operator /(const CATStandard_Real Scalar) const
{
  return Divided(Scalar);
}

ExportedBySysCascade inline   CATStandard_Real Dot(const CATgp_XY& Other) const;
ExportedBySysCascade inline   CATStandard_Real operator *(const CATgp_XY& Other) const
{
  return Dot(Other);
}

ExportedBySysCascade inline   void Multiply(const CATStandard_Real Scalar) ;
ExportedBySysCascade inline   void operator *=(const CATStandard_Real Scalar) 
{
  Multiply(Scalar);
}

ExportedBySysCascade inline   void Multiply(const CATgp_XY& Other) ;
ExportedBySysCascade inline   void operator *=(const CATgp_XY& Other) 
{
  Multiply(Other);
}

/*ExportedBySysCascade inline   void Multiply(const CATgp_Mat2d& Matrix) ;
ExportedBySysCascade inline   void operator *=(const CATgp_Mat2d& Matrix) 
{
  Multiply(Matrix);
}*/

ExportedBySysCascade inline   CATgp_XY Multiplied(const CATStandard_Real Scalar) const;
ExportedBySysCascade inline   CATgp_XY operator *(const CATStandard_Real Scalar) const
{
  return Multiplied(Scalar);
}

ExportedBySysCascade inline   CATgp_XY Multiplied(const CATgp_XY& Other) const;
/*ExportedBySysCascade inline   CATgp_XY Multiplied(const CATgp_Mat2d& Matrix) const;
ExportedBySysCascade inline   CATgp_XY operator *(const CATgp_Mat2d& Matrix) const
{
  return Multiplied(Matrix);
}*/

ExportedBySysCascade inline   void Normalize() ;
ExportedBySysCascade inline   CATgp_XY Normalized() const;
ExportedBySysCascade inline   void Reverse() ;
ExportedBySysCascade inline   CATgp_XY Reversed() const;
ExportedBySysCascade inline   CATgp_XY operator -() const
{
  return Reversed();
}

ExportedBySysCascade inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_XY& XY1,const CATStandard_Real A2,const CATgp_XY& XY2) ;
ExportedBySysCascade inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_XY& XY1,const CATStandard_Real A2,const CATgp_XY& XY2,const CATgp_XY& XY3) ;
ExportedBySysCascade inline   void SetLinearForm(const CATStandard_Real A1,const CATgp_XY& XY1,const CATgp_XY& XY2) ;
ExportedBySysCascade inline   void SetLinearForm(const CATgp_XY& XY1,const CATgp_XY& XY2) ;
ExportedBySysCascade inline   void Subtract(const CATgp_XY& Right) ;
ExportedBySysCascade inline   void operator -=(const CATgp_XY& Right) 
{
  Subtract(Right);
}

ExportedBySysCascade inline   CATgp_XY Subtracted(const CATgp_XY& Right) const;
ExportedBySysCascade inline   CATgp_XY operator -(const CATgp_XY& Right) const
{
  return Subtracted(Right);
}

    CATStandard_Real _CSFDB_GetCATgp_XYx() const { return x; }
    void _CSFDB_SetCATgp_XYx(const CATStandard_Real p) { x = p; }
    CATStandard_Real _CSFDB_GetCATgp_XYy() const { return y; }
    void _CSFDB_SetCATgp_XYy(const CATStandard_Real p) { y = p; }




 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATgp_XY_Type_();

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
CATStandard_Real x;
CATStandard_Real y;


};


#include "CATgp_XY.lxx"



// other ExportedBySysCascade inline functions and methods (like "C++: function call" methods)
//


#endif
