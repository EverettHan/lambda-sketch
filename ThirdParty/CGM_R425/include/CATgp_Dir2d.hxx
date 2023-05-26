
#ifndef _CATgp_Dir2d_HeaderFile
#define _CATgp_Dir2d_HeaderFile

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
class CATStandard_DomainError;
class CATStandard_OutOfRange;
class CATgp_Vec2d;
class CATgp_XY;
class CATgp_Ax2d;
class CATgp_Trsf2d;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif



 Handle_CATStandard_Type& CATgp_Dir2d_Type_();

class CATgp_Dir2d  {

public:

 // Methods PUBLIC
 // 
//ExportedBySysCascade inline CATgp_Dir2d();
//ExportedBySysCascade inline CATgp_Dir2d(const CATgp_Vec2d& V);
//ExportedBySysCascade inline CATgp_Dir2d(const CATgp_XY& Coord);
ExportedBySysCascade inline CATgp_Dir2d(const CATStandard_Real Xv,const CATStandard_Real Yv);
/*ExportedBySysCascade inline   void SetCoord(const CATStandard_Integer Index,const CATStandard_Real Xi) ;
ExportedBySysCascade inline   void SetCoord(const CATStandard_Real Xv,const CATStandard_Real Yv) ;
ExportedBySysCascade inline   void SetX(const CATStandard_Real X) ;
ExportedBySysCascade inline   void SetY(const CATStandard_Real Y) ;
ExportedBySysCascade inline   void SetXY(const CATgp_XY& Coord) ;
ExportedBySysCascade inline   CATStandard_Real Coord(const CATStandard_Integer Index) const;
ExportedBySysCascade inline   void Coord(CATStandard_Real& Xv,CATStandard_Real& Yv) const;
ExportedBySysCascade inline   CATStandard_Real X() const;
ExportedBySysCascade inline   CATStandard_Real Y() const;
ExportedBySysCascade inline  const CATgp_XY& XY() const;
ExportedBySysCascade inline   CATStandard_Boolean IsEqual(const CATgp_Dir2d& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsNormal(const CATgp_Dir2d& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsOpposite(const CATgp_Dir2d& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade inline   CATStandard_Boolean IsParallel(const CATgp_Dir2d& Other,const CATStandard_Real AngularTolerance) const;
ExportedBySysCascade    CATStandard_Real Angle(const CATgp_Dir2d& Other) const;
ExportedBySysCascade inline   CATStandard_Real Crossed(const CATgp_Dir2d& Right) const;
ExportedBySysCascade inline   CATStandard_Real operator ^(const CATgp_Dir2d& Right) const
{
  return Crossed(Right);
}

ExportedBySysCascade inline   CATStandard_Real Dot(const CATgp_Dir2d& Other) const;
ExportedBySysCascade inline   CATStandard_Real operator *(const CATgp_Dir2d& Other) const
{
  return Dot(Other);
}

ExportedBySysCascade inline   void Reverse() ;
ExportedBySysCascade inline   CATgp_Dir2d Reversed() const;
ExportedBySysCascade inline   CATgp_Dir2d operator -() const
{
  return Reversed();
}

ExportedBySysCascade    void Mirror(const CATgp_Dir2d& V) ;
ExportedBySysCascade    CATgp_Dir2d Mirrored(const CATgp_Dir2d& V) const;
ExportedBySysCascade    void Mirror(const CATgp_Ax2d& A) ;
ExportedBySysCascade    CATgp_Dir2d Mirrored(const CATgp_Ax2d& A) const;
ExportedBySysCascade inline   void Rotate(const CATStandard_Real Ang) ;
ExportedBySysCascade inline   CATgp_Dir2d Rotated(const CATStandard_Real Ang) const;
ExportedBySysCascade    void Transform(const CATgp_Trsf2d& T) ;
ExportedBySysCascade inline   CATgp_Dir2d Transformed(const CATgp_Trsf2d& T) const;
    const CATgp_XY& _CSFDB_GetCATgp_Dir2dcoord() const { return coord; }
*/



 // Type management
 //
   friend Handle_CATStandard_Type& CATgp_Dir2d_Type_();

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


#include "CATgp_Dir2d.lxx"



// other ExportedBySysCascade inline functions and methods (like "C++: function call" methods)
//


#endif
