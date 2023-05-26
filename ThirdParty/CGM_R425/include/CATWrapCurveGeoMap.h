//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// Interface to define a diffeomophism 
//                                    3     3 
// ie a continous application  from IR to IR
//
// CATWrapCurveGeoMap :
// Implementation du diffeomorphisme D 
//
//==========================================================================
// Usage Notes 
//==========================================================================
// 12/03/18 NLD Suppression ancien constructeur sans iDirKind
//========================================================================== 
#ifndef CATWrapCurveGeoMap_H
#define CATWrapCurveGeoMap_H

#include "FrFObjects.h"
#include "CATMapFunctionXYZ.h"
#include "CATSoftwareConfiguration.h"
class CATMathPoint;
class CATMathVector;
class CATMathPlane;
class CATSurParam;
class CATMathTransformation;
class CATGSDCrvWrap;
class CATGSDBase;
class CATGSDOnePoint;
class CATSoftwareConfiguration;




class ExportedByFrFObjects CATWrapCurveGeoMap : public CATMapFunctionXYZ
{
  public:
    //=============
    //Constructeur
    //=============
    /* NLD120318
    CATWrapCurveGeoMap(CATGeoFactory  *iFactory ,
                       CATSoftwareConfiguration *iSoftwareConfiguration,
                                       const CATNurbsCurve  *iRefSpine, 
                                       const CATNurbsCurve  *iRefDirCurve, 
                                       CATNurbsCurve **iRefCurves,
                                       const CATNurbsCurve  *iTargSpine, 
                                       const CATNurbsCurve  *iTargDirCurve, 
                                       CATNurbsCurve **iTargCurves,
                                       const CATLONG32            iNbCurves);
    */
    //=============
    //Constructeur
    //=============
     CATWrapCurveGeoMap(      CATGeoFactory            * iFactory ,
                              CATSoftwareConfiguration * iSoftwareConfiguration,
                        const CATNurbsCurve            * iRefSpine, 
                        const CATLONG32                  iDirKind,
                        const CATNurbsCurve            * iRefDirCurve, 
                              CATNurbsCurve           ** iRefCurves,
                        const CATNurbsCurve            * iTargSpine, 
                        const CATNurbsCurve            * iTargDirCurve, 
                              CATNurbsCurve           ** iTargCurves,
                        const CATLONG32                  iNbCurves);
     //=============                           
    
 
    //===========
    //Information
    //===========
    // return true when ic is "CATWrapCurveGeoMap"
    CATBoolean IsAKindOf(const char* ic) const;
    
    CATBoolean IsALinearMap() const;
    
    /*
    if it is a LinearMap this methode give the equivalent Transformation
    */
    CATLONG32 GetMathTransformation(CATMathTransformation & oTransformation) const;
    
    //===========
    //Evaluators
    //===========
    CATLONG32  Eval(const CATMathPoint& iPInitial, CATMathPoint & oPModified) const;

    //===========
    //Evaluation of the derivatives of the local canonical (cartesian) axis system
    //===========
    CATLONG32  EvalFirstDeriv(const CATMathPoint& iPInitial, 
                                    CATMathVector& oDx, CATMathVector& oDy,CATMathVector& oDz) const;
    
    CATLONG32  EvalSecondDeriv(const CATMathPoint& iPInitial, 
                                     CATMathVector& oD2x, CATMathVector& oD2y, CATMathVector& oD2z,
                                     CATMathVector& oDxy, CATMathVector& oDxz, CATMathVector& oDyz) const;
    void       GetAnaSynth(CATGSDBase *&AnaObj,CATGSDBase *&SynthObj) const;

    void       SetDeformationAlongNormal(int iOrientation);
    int        GetDeformationAlongNormal() const;
    CATBoolean IsModelDependant() const;

  protected :

  virtual  ~CATWrapCurveGeoMap();
    
    
  private :
    
   CATGSDCrvWrap  * _Analysis;
   CATGSDBase    ** _Synthesis;
   CATGSDOnePoint * _GSDOnePoint;
   int              _IsDeformationAlongNormal;
};
#endif
