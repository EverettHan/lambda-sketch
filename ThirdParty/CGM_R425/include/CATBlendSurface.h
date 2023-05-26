// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATBlendSurface:
// Interface class of the Blend Surface Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Blend or derived
// in order to implement specific algorithm or capabilities.
//
//========================================================================== 
// May 97     Creation                       Tuan Phung (tpg)
// Mar 02     Ajout SetSoftwareConfiguration Jean Saloux(jsx)
// 24/12/04 NLD Ajout SetFrFTopologyCallBacks()
// 28/05/08 JSX Migration sur CATFrFObject
//========================================================================== 

#ifndef CATBlendSurface_H
#define CATBlendSurface_H

#include "FrFOpeSur.h"
#include "CATMathDef.h"
#include "CATCGMVirtual.h"

#include "CreateBlendSurface.h"
#include "CATMathVector.h"

#include "CATFrFObject.h"

class CATSurface;
class CATSoftwareConfiguration;
class CATGeometry ;
class CATFrFTopologyCallBacks ;
//-----------------------------------------------------------------------------
class ExportedByFrFOpeSur CATBlendSurface : public CATFrFObject//CATCGMVirtual //JSX270508
  {
  public :
    
    virtual ~CATBlendSurface();
    virtual void Run()=0;
    //
    // Default is 0; LastLevel = -1;
    virtual void SetBlendSurfaceLevel(CATLONG32 iLevel) = 0;
    //
    //  Setting the blend configuration 
    //
    virtual void SetDefaultConfiguration(CATLONG32 &oCurveOrientationSide1,
                                         CATLONG32 &oCurveOrientationSide2,
                                         CATLONG32 &oTransitionOrientationSide1,
                                         CATLONG32 &oTransitionOrientationSide2)=0;

    virtual void SetDefaultConfigurationWithRefDir(CATLONG32 &oCurveOrientationSide1,
                                         CATLONG32 &oCurveOrientationSide2,
                                         CATLONG32 &oTransitionOrientationSide1,
                                         CATLONG32 &NotPrecise,
                                         CATLONG32 &oTransitionOrientationSide2,CATMathVector &Dir1,CATMathVector &Dir2)=0;
    
    virtual void ReverseCurveOrientation(const CATLONG32 iSide)=0;
    
    virtual void SetCurveOrientation(const CATLONG32 iSide, const CATLONG32 iCurveOrientation)=0;
    
    virtual void SetTransitionContinuity(const CATLONG32 iSide, const CATLONG32 iTransitionContinuity)=0;

    virtual void SetTransitionOrientation(const CATLONG32 iSide, const CATLONG32 iTransitionOrientation)=0;
    //
    //  Setting the blend parameters 
    //
    virtual void SetTangencyParameter(const CATLONG32 iSide, const double TangencyParameter)=0;

    virtual void SetCurvatureParameter(const CATLONG32 iSide, const double CurvatureParameter)=0;
    //
    //  Getting the blend result 
    // 
    virtual CATLONG32 GetNumberOfBlends() const=0;
    virtual void BeginningBlend()=0;
    virtual CATBoolean NextBlend()=0;
    virtual CATSurface *GetSurface() const=0;
    virtual void SurfacesAreDeleted()=0;
    
    //
    //  Validation
    //
    virtual void SetTwistTreatment(CATLONG32 iLevel)=0;
    virtual CATLONG32 GetTwistTreatment() const=0;
    virtual CATLONG32 GetValidity() =0;
    // Topological callbacks
    virtual void SetFrFTopologyCallBacks(CATFrFTopologyCallBacks* iFrFTopologyCallBacks) = 0 ;

  };

#endif
