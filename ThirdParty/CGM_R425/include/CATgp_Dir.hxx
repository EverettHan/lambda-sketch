
#ifndef _CATgp_Dir_HeaderFile
#define _CATgp_Dir_HeaderFile

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
class CATgp_Vec;
class CATgp_XYZ;
class CATgp_Ax1;
class CATgp_Ax2;
class CATgp_Trsf;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATgp_Dir_Type_();

class CATgp_Dir  {

public:

 // Methods PUBLIC
 // 
//ExportedBySysCascade inline CATgp_Dir();
//ExportedBySysCascade inline CATgp_Dir(const CATgp_Vec& V);
ExportedBySysCascade inline CATgp_Dir(const CATgp_XYZ& Coord);
ExportedBySysCascade inline CATgp_Dir(const CATStandard_Real Xv,const CATStandard_Real Yv,const CATStandard_Real Zv);
/*ExportedBySysCascade inline   void SetCoord(const CATStandard_Integer Index,const CATStandard_Real Xi) ;
ExportedBySysCascade inline   void SetCoord(const CATStandard_Real Xv,const CATStandard_Real Yv,const CATStandard_Real Zv) ;
ExportedBySysCascade inline   void SetX(const CATStandard_Real X) ;
ExportedBySysCascade inline   void SetY(const CATStandard_Real Y) ;
ExportedBySysCascade inline   void SetZ(const CATStandard_Real Z) ;
ExportedBySysCascade inline   void SetXYZ(const CATgp_XYZ& Coord) ;
ExportedBySysCascade inline   CATStandard_Real Coord(const CATStandard_Integer Index) const;
ExportedBySysCascade inline   void Coord(CATStandard_Real& Xv,CATStandard_Real& Yv,CATStandard_Real& Zv) const;
ExportedBySysCascade inline   CATStandard_Real X() const;
ExportedBySysCascade inline   CATStandard_Real Y() const;
ExportedBySysCascade inline   CATStandard_Real Z() const;
ExportedBySysCascade inline  const CATgp_XYZ& XYZ() const;
ExportedBySysCascade inline   CATStandard_Boolean IsEqual(const CATgp_Dir& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsNormal(const CATgp_Dir& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsOpposite(const CATgp_Dir& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsParallel(const CATgp_Dir& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade    CATStandard_Real Angle(const CATgp_Dir& Other) const;
ExportedBySysCascade    CATStandard_Real AngleWithRef(const CATgp_Dir& Other,const CATgp_Dir& VRef) const;*/
ExportedBySysCascade inline   void Cross(const CATgp_Dir& Right) ;
ExportedBySysCascade inline   void operator ^=(const CATgp_Dir& Right) 
{
  Cross(Right);
}

/*ExportedBySysCascade inline   CATgp_Dir Crossed(const CATgp_Dir& Right) const;
ExportedBySysCascade inline   CATgp_Dir operator ^(const CATgp_Dir& Right) const
{
  return Crossed(Right);
}*/

ExportedBySysCascade inline   void CrossCross(const CATgp_Dir& V1,const CATgp_Dir& V2) ;
//ExportedBySysCascade inline   CATgp_Dir CrossCrossed(const CATgp_Dir& V1,const CATgp_Dir& V2) const;
//ExportedBySysCascade inline   CATStandard_Real Dot(const CATgp_Dir& Other) const;
//ExportedBySysCascade inline   CATStandard_Real operator *(const CATgp_Dir& Other) const
//{
//  return Dot(Other);
//}

/*ExportedBySysCascade inline   CATStandard_Real DotCross(const CATgp_Dir& V1,const CATgp_Dir& V2) const;
ExportedBySysCascade inline   void Reverse() ;
ExportedBySysCascade inline   CATgp_Dir Reversed() const;
ExportedBySysCascade inline   CATgp_Dir operator -() const
{
  return Reversed();
}

ExportedBySysCascade    void Mirror(const CATgp_Dir& V) ;
ExportedBySysCascade    CATgp_Dir Mirrored(const CATgp_Dir& V) const;
ExportedBySysCascade    void Mirror(const CATgp_Ax1& A1) ;
ExportedBySysCascade    CATgp_Dir Mirrored(const CATgp_Ax1& A1) const;
ExportedBySysCascade    void Mirror(const CATgp_Ax2& A2) ;
ExportedBySysCascade    CATgp_Dir Mirrored(const CATgp_Ax2& A2) const;
ExportedBySysCascade inline   void Rotate(const CATgp_Ax1& A1,const CATStandard_Real Ang) ;
ExportedBySysCascade inline   CATgp_Dir Rotated(const CATgp_Ax1& A1,const CATStandard_Real Ang) const;
ExportedBySysCascade    void Transform(const CATgp_Trsf& T) ;
ExportedBySysCascade inline   CATgp_Dir Transformed(const CATgp_Trsf& T) const;
    const CATgp_XYZ& _CSFDB_GetCATgp_Dircoord() const { return coord; }


*/

 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATgp_Dir_Type_();

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


#include "CATgp_Dir.lxx"



// other ExportedBySysCascade inline functions and methods (like "C++: function call" methods)
//


#endif
