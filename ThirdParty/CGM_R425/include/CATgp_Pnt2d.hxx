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
#ifndef _CATgp_Pnt2d_HeaderFile
#define _CATgp_Pnt2d_HeaderFile

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
class CATStandard_OutOfRange;
class CATgp_XY;
class CATgp_Ax2d;
class CATgp_Trsf2d;
class CATgp_Vec2d;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATgp_Pnt2d_Type_();

class CATgp_Pnt2d  {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade inline CATgp_Pnt2d();
//ExportedBySysCascade inline CATgp_Pnt2d(const CATgp_XY& Coord);
ExportedBySysCascade inline CATgp_Pnt2d(const CATStandard_Real Xp,const CATStandard_Real Yp);
ExportedBySysCascade inline   void SetCoord(const CATStandard_Integer Index,const CATStandard_Real Xi) ;
ExportedBySysCascade inline   void SetCoord(const CATStandard_Real Xp,const CATStandard_Real Yp) ;
//ExportedBySysCascade inline   void SetX(const CATStandard_Real X) ;
//ExportedBySysCascade inline   void SetY(const CATStandard_Real Y) ;
//ExportedBySysCascade inline   void SetXY(const CATgp_XY& Coord) ;
ExportedBySysCascade inline   CATStandard_Real Coord(const CATStandard_Integer Index) const;
ExportedBySysCascade inline   void Coord(CATStandard_Real& Xp,CATStandard_Real& Yp) const;
ExportedBySysCascade inline   CATStandard_Real X() const;
ExportedBySysCascade inline   CATStandard_Real Y() const;
ExportedBySysCascade inline  const CATgp_XY& XY() const;
//ExportedBySysCascade inline  const CATgp_XY& Coord() const;
//ExportedBySysCascade inline   CATgp_XY& ChangeCoord() ;
//ExportedBySysCascade inline   CATStandard_Boolean IsEqual(const CATgp_Pnt2d& Other,const CATStandard_Real LinearTolerance) const;
//ExportedBySysCascade inline   CATStandard_Real Distance(const CATgp_Pnt2d& Other) const;
//ExportedBySysCascade inline   CATStandard_Real SquareDistance(const CATgp_Pnt2d& Other) const;
//ExportedBySysCascade    void Mirror(const CATgp_Pnt2d& P) ;
//ExportedBySysCascade    CATgp_Pnt2d Mirrored(const CATgp_Pnt2d& P) const;
//ExportedBySysCascade    void Mirror(const CATgp_Ax2d& A) ;
//ExportedBySysCascade    CATgp_Pnt2d Mirrored(const CATgp_Ax2d& A) const;
//ExportedBySysCascade inline   void Rotate(const CATgp_Pnt2d& P,const CATStandard_Real Ang) ;
//ExportedBySysCascade inline   CATgp_Pnt2d Rotated(const CATgp_Pnt2d& P,const CATStandard_Real Ang) const;
//ExportedBySysCascade inline   void Scale(const CATgp_Pnt2d& P,const CATStandard_Real S) ;
//ExportedBySysCascade inline   CATgp_Pnt2d Scaled(const CATgp_Pnt2d& P,const CATStandard_Real S) const;
//ExportedBySysCascade    void Transform(const CATgp_Trsf2d& T) ;
//ExportedBySysCascade inline   CATgp_Pnt2d Transformed(const CATgp_Trsf2d& T) const;
//ExportedBySysCascade inline   void Translate(const CATgp_Vec2d& V) ;
//ExportedBySysCascade inline   CATgp_Pnt2d Translated(const CATgp_Vec2d& V) const;
//ExportedBySysCascade inline   void Translate(const CATgp_Pnt2d& P1,const CATgp_Pnt2d& P2) ;
//ExportedBySysCascade inline   CATgp_Pnt2d Translated(const CATgp_Pnt2d& P1,const CATgp_Pnt2d& P2) const;
//    const CATgp_XY& _CSFDB_GetCATgp_Pnt2dcoord() const { return coord; }




 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATgp_Pnt2d_Type_();

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


#include "CATgp_Pnt2d.lxx"



// other ExportedBySysCascade inline functions and methods (like "C++: function call" methods)
//


#endif
