//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// Interface to define a diffeomophism 
//                                    3     3 
// ie a continous application  from IR to IR
//
// CATWrapSurfaceGeoMap :
// Implementation du diffeomorphisme D 
//
//==========================================================================
// Usage Notes 
//==========================================================================
//
//========================================================================== 
#ifndef CATWrapSurfaceGeoMap_H
#define CATWrapSurfaceGeoMap_H

#include "FrFObjects.h"
#include "CATMapFunctionXYZ.h"

class CATMathPoint;
class CATMathVector;
class CATMathPlane;
class CATSurParam;
class CATMathTransformation;
class CATGSDPatch;
class CATGSDBase;
class CATGSDOnePoint;
class CATGlobdefCommand;
class CATSurLimits;
class CATSoftwareConfiguration;



class ExportedByFrFObjects CATWrapSurfaceGeoMap : public CATMapFunctionXYZ
{
  public:
    //=============
    //Constructeur
    //=============
    CATWrapSurfaceGeoMap(      CATGeoFactory            *  iFactory  ,
                               CATSoftwareConfiguration *  iSoftwareConfiguration,
                         const CATSurface               *  iRefSur   ,
                               CATSurLimits             *& iRefSurLim,
                         const CATSurface               *  iTargSur  ,
                               CATSurLimits             *& iTargSurLim); 
    //=============
    //Constructeur
    //=============
    CATWrapSurfaceGeoMap(      CATGeoFactory            *  iFactory              ,
                               CATSoftwareConfiguration *  iSoftwareConfiguration,
                         const CATSurface               *  iRefSur               ,
                               CATSurLimits             *& iRefSurLim            ,
                         const CATSurface               *  iTargSur              ,
                               CATSurLimits             *& iTargSurLim           ,
                               CATGlobdefCommand        &  iGlobdefCommand       );
     //=============                           
    
    

    
    //===========
    //Information
    //===========
    // return true when ic is "CATWrapSurfaceGeoMap"
    CATBoolean IsAKindOf(const char* ic) const;
    
    CATBoolean IsALinearMap() const;
    
    /*
    if it is a LinearMap this methode give the equivalent Transformation
    */
    CATLONG32 GetMathTransformation(CATMathTransformation & oTransformation) const;
    
    //===========
    //Evaluators
    //===========
    CATLONG32 Eval           (const CATMathPoint & iPInitial,
                                    CATMathPoint & oPModified) const;

    //===========
    //Evaluation of the derivatives of the local canonical (cartesian) axis system
    //===========
    CATLONG32 EvalFirstDeriv (const CATMathPoint & iPInitial, 
                                    CATMathVector& oDx, CATMathVector& oDy,CATMathVector& oDz) const;
    
    CATLONG32 EvalSecondDeriv(const CATMathPoint & iPInitial, 
                                    CATMathVector& oD2x, CATMathVector& oD2y, CATMathVector& oD2z,
                                    CATMathVector& oDxy, CATMathVector& oDxz, CATMathVector& oDyz) const;

    void GetAnaSynth(CATGSDBase *&AnaObj,CATGSDBase *&SynthObj) const;

  protected :
    virtual  ~CATWrapSurfaceGeoMap();
    

    
    
  private :
    
   CATGSDPatch    * _Analysis;
   CATGSDBase    ** _Synthesis;
   CATGSDOnePoint * _GSDOnePoint;
};
#endif
