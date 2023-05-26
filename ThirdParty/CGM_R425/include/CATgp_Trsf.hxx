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
/*
#ifndef _CATgp_Trsf_HeaderFile
#define _CATgp_Trsf_HeaderFile

#ifndef _CATStandard_Real_HeaderFile
#include "CATStandard_Real.hxx"
#endif
#ifndef _CATgp_TrsfForm_HeaderFile
#include "CATgp_TrsfForm.hxx"
#endif
#ifndef _CATgp_Mat_HeaderFile
#include "CATgp_Mat.hxx"
#endif
#ifndef _CATgp_XYZ_HeaderFile
#include "CATgp_XYZ.hxx"
#endif
#ifndef _CATStandard_Storable_HeaderFile
#include "CATStandard_Storable.hxx"
#endif
#ifndef _CATStandard_Boolean_HeaderFile
#include "CATStandard_Boolean.hxx"
#endif
#ifndef _CATStandard_Integer_HeaderFile
#include "CATStandard_Integer.hxx"
#endif
#ifndef _CATStandard_PrimitiveTypes_HeaderFile
#include "CATStandard_PrimitiveTypes.hxx"
#endif
class CATStandard_ConstructionError;
class CATStandard_OutOfRange;
class CATgp_GTrsf;
class CATgp_Trsf2d;
class CATgp_Pnt;
class CATgp_Ax1;
class CATgp_Ax2;
class CATgp_Ax3;
class CATgp_Vec;
class CATgp_XYZ;
class CATgp_Mat;


#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif

#include "SysCascade.h"

ExportedBySysCascade  Handle_CATStandard_Type& CATgp_Trsf_Type_();

class CATgp_Trsf  {

public:

 // Methods PUBLIC
 // 
ExportedBySysCascade inline CATgp_Trsf();
ExportedBySysCascade inline CATgp_Trsf(const CATgp_Trsf2d& T);
ExportedBySysCascade inline   void SetMirror(const CATgp_Pnt& P) ;
ExportedBySysCascade    void SetMirror(const CATgp_Ax1& A1) ;
ExportedBySysCascade    void SetMirror(const CATgp_Ax2& A2) ;
ExportedBySysCascade    void SetRotation(const CATgp_Ax1& A1,const CATStandard_Real Ang) ;
ExportedBySysCascade    void SetScale(const CATgp_Pnt& P,const CATStandard_Real S) ;
ExportedBySysCascade    void SetDisplacement(const CATgp_Ax3& FromSystem1,const CATgp_Ax3& ToSystem2) ;
ExportedBySysCascade    void SetTransformation(const CATgp_Ax3& FromSystem1,const CATgp_Ax3& ToSystem2) ;
ExportedBySysCascade    void SetTransformation(const CATgp_Ax3& ToSystem) ;
ExportedBySysCascade inline   void SetTranslation(const CATgp_Vec& V) ;
ExportedBySysCascade inline   void SetTranslation(const CATgp_Pnt& P1,const CATgp_Pnt& P2) ;
ExportedBySysCascade    void SetTranslationPart(const CATgp_Vec& V) ;
ExportedBySysCascade    void SetScaleFactor(const CATStandard_Real S) ;
ExportedBySysCascade    void SetValues(const CATStandard_Real a11,const CATStandard_Real a12,const CATStandard_Real a13,const CATStandard_Real a14,const CATStandard_Real a21,const CATStandard_Real a22,const CATStandard_Real a23,const CATStandard_Real a24,const CATStandard_Real a31,const CATStandard_Real a32,const CATStandard_Real a33,const CATStandard_Real a34,const CATStandard_Real Tolang,const CATStandard_Real TolDist) ;
ExportedBySysCascade inline   CATStandard_Boolean IsNegative() const;
ExportedBySysCascade inline   CATgp_TrsfForm Form() const;
ExportedBySysCascade inline   CATStandard_Real ScaleFactor() const;
ExportedBySysCascade inline  const CATgp_XYZ& TranslationPart() const;
ExportedBySysCascade    CATgp_Mat VectorialPart() const;
ExportedBySysCascade inline  const CATgp_Mat& HVectorialPart() const;
ExportedBySysCascade inline   CATStandard_Real Value(const CATStandard_Integer Row,const CATStandard_Integer Col) const;
ExportedBySysCascade    void Invert() ;
ExportedBySysCascade inline   CATgp_Trsf Inverted() const;
ExportedBySysCascade inline   CATgp_Trsf Multiplied(const CATgp_Trsf& T) const;
ExportedBySysCascade inline   CATgp_Trsf operator *(const CATgp_Trsf& T) const
{
  return Multiplied(T);
}

ExportedBySysCascade    void Multiply(const CATgp_Trsf& T) ;
  void operator *=(const CATgp_Trsf& T) 
{
  Multiply(T);
}

ExportedBySysCascade    void PreMultiply(const CATgp_Trsf& T) ;
ExportedBySysCascade    void Power(const CATStandard_Integer N) ;
ExportedBySysCascade inline   CATgp_Trsf Powered(const CATStandard_Integer N) ;
ExportedBySysCascade inline   void Transforms(CATStandard_Real& X,CATStandard_Real& Y,CATStandard_Real& Z) const;
ExportedBySysCascade inline   void Transforms(CATgp_XYZ& Coord) const;
    CATStandard_Real _CSFDB_GetCATgp_Trsfscale() const { return scale; }
    void _CSFDB_SetCATgp_Trsfscale(const CATStandard_Real p) { scale = p; }
    CATgp_TrsfForm _CSFDB_GetCATgp_Trsfshape() const { return shape; }
    void _CSFDB_SetCATgp_Trsfshape(const CATgp_TrsfForm p) { shape = p; }
    const CATgp_Mat& _CSFDB_GetCATgp_Trsfmatrix() const { return matrix; }
    const CATgp_XYZ& _CSFDB_GetCATgp_Trsfloc() const { return loc; }


friend class CATgp_GTrsf;


 // Type management
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATgp_Trsf_Type_();

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
CATStandard_Real scale;
CATgp_TrsfForm shape;
CATgp_Mat matrix;
CATgp_XYZ loc;


};


#include "CATgp_Trsf.lxx"



// other ExportedBySysCascade inline functions and methods (like "C++: function call" methods)
//


#endif
*/