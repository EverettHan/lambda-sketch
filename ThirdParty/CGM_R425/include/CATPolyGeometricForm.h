// COPYRIGHT DASSAULT SYSTEMES 2008-2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyGeometricForm.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
// Mai 2019                  : ANR : Correction de CD chez Reverse
// AVril 2019  : ANR : Ajout de SetTorus(coude)
// June  2008  Creation: ZFI
//===================================================================

#ifndef CATPolyGeometricForm_H
#define CATPolyGeometricForm_H

#include "CATPolySegmentCommon.h"

#include "CATErrorDef.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATListOfDouble.h"
#include "CATMathAxis.h"

class ExportedByCATPolySegmentCommon CATPolyGeometricForm
{
public:
  CATPolyGeometricForm();
  virtual ~CATPolyGeometricForm();

public:
  enum  FormTypeIds
  {
    NoForm,
    Line,
    Plane,
    Circle,
    Cylinder,
    Cone, 
    Sphere,
    Torus,
    Fillet,
    FreeSurf,
    Band,
    CurvedPlane
  };
  typedef int FormType;

public:
  //TYPE
  int GetType() const;
  CATBoolean IsLine() const;
  CATBoolean IsPlane() const;
  CATBoolean IsCircle() const;
  CATBoolean IsCylinder() const;
  CATBoolean IsCone() const;
  CATBoolean IsSphere() const;  
  CATBoolean IsTorus() const;  
  CATBoolean IsFillet() const;
  CATBoolean IsFreeSurf() const;
  CATBoolean IsBand() const;
  CATBoolean IsCurvedPlane() const;

  //GET PARAMETERS
  HRESULT GetPlaneParameters(CATMathPoint& oCenter, CATMathVector& oAxis) const ;
  HRESULT GetLineParameters(CATMathPoint& oBegin, CATMathPoint& oEnd) const ;
  HRESULT GetCylinderParameters(CATMathPoint& oCenter, CATMathVector& oAxis, double& oRad)const;
  HRESULT GetCircleParameters(CATMathPoint& oCenter, CATMathVector& oAxis, double& oRad)const;
  HRESULT GetConeParameters(CATMathPoint& oCenter1, CATMathPoint& oCenter2, CATMathVector& oAxis, double& oRad1, double& oRad2)const;
  HRESULT GetSphereParameters(CATMathPoint& oCenter, double& oRad)const;
  HRESULT GetTorusParameters(CATMathPoint& oCenter, CATMathVector& oAxis , double& oSmallRad , double& oBigRad)const;
  //Creates a piece of a geometric self - intersecting torus.
  HRESULT GetTorusParameters(CATMathAxis& oMathAxis, double& oSmallRadius, double& oBigRadius, CATAngle& oMajorStartAngle, CATAngle& oMajorEndAngle)const;
  HRESULT GetFilletParameters(double& oRad)const;
  HRESULT GetFilletSpineParameters(CATListOfDouble &oCenterList, CATListOfDouble &oAxisList, CATBoolean &oIsProfiledSurf)const;
  HRESULT GetBandParameters(CATMathPoint& oCenter1, CATMathPoint& oCenter2,  CATMathVector& oAxis1, CATMathVector&oAxis2, double& oRad1, double& oRad2) const ;
  HRESULT GetSeed(int& oSeed)const;
  HRESULT GetCurvedPlaneParameters(CATMathVector& oAxis, double& oMaxDeviation)const;
  

  //SET PARAMETERS
  HRESULT SetPlane(const CATMathPoint& iCenter,const CATMathVector& iAxis) ;
  HRESULT SetLine(const CATMathPoint& iBegin,const CATMathPoint& iEnd) ;
  HRESULT SetCylinder(const CATMathPoint& iCenter,const  CATMathVector& iAxis, double iRad);
  HRESULT SetCircle(const CATMathPoint& iCenter,const  CATMathVector& iAxis, double iRad);
  HRESULT SetCone(const CATMathPoint& iCenter1, const CATMathPoint& iCenter2,
                  const CATMathVector& iAxis, double iRad1, double iRad2);
  HRESULT SetSphere(const CATMathPoint& iCenter, const double iRad);
  HRESULT SetTorus(const CATMathPoint& iCenter, const CATMathVector& iAxis, const double iSmallRad, const double iBigRad);
  //Creates a piece of a geometric self - intersecting torus.
  HRESULT SetTorus(CATMathAxis &iMathAxis, double iSmallRadius, double iBigRadius, CATAngle iMajorStartAngle, CATAngle iMajorEndAngle);
  HRESULT SetFillet(const double iRad);
  HRESULT SetFilletSpine(CATListOfDouble &iCenterList, CATListOfDouble &iAxisList, CATBoolean IsProfiledSurf = FALSE);
  HRESULT SetFreeSurf();
  HRESULT SetBand(const CATMathPoint& iCenter1, const CATMathPoint& iCenter2, 
                  const CATMathVector& iAxis1, const CATMathVector& iAxis2,
                  const double iRad1, const double iRad2);

  HRESULT SetSeed(int iSeed);
  HRESULT SetCurvedPlane(const CATMathVector& iVector, const double iMaxDeviation);

  //METHODS
  //double Distance(const CATMathPoint& iP)const;

public:
  //Assignement Operator=
  CATPolyGeometricForm& operator=(const CATPolyGeometricForm &iPC);

private:
  CATMathVector _Axis1, _Axis2;
  CATMathPoint _Center1, _Center2;
  double _Rad1, _Rad2;
  int _Type;
  int _Seed;

  // ANR :
  CATListOfDouble _CenterList ;
  CATListOfDouble _AxisList ;
  CATBoolean      _ProfiledSurf ;

  CATMathAxis _MathAxis;
  CATAngle _MajorStartAngle;
  CATAngle _MajorEndAngle;
};

#endif
