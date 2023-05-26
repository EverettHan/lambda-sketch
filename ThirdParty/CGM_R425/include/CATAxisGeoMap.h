//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// Interface to define a diffeomophism 
//                                    3     3 
// ie a continous application  from IR to IR
//
// CATAxisGeoMap :
// Implementation du diffeomorphisme D 
//
//==========================================================================
// Usage Notes 
//==========================================================================
//
//========================================================================== 
#ifndef CATAxisGeoMap_H
#define CATAxisGeoMap_H

#include "FrFObjects.h"
#include "CATMapFunctionXYZ.h"
#include "CATSoftwareConfiguration.h"

class CATMathPoint;
class CATMathVector;
class CATMathPlane;
class CATSurParam;
class CATMathTransformation;
class CATGSDAxis;
class CATGSDBase;





class ExportedByFrFObjects CATAxisGeoMap : public CATMapFunctionXYZ
{
  public:
    //=============
    //Constructeur
    //=============
    CATAxisGeoMap(      CATGeoFactory            *iFactory ,
                  const CATMathAxis              *iStartAxis,
                  const CATMathAxis              *iTargetAxis,
                        CATSoftwareConfiguration *iSoftwareConfiguration =NULL);
     
    
    //===========
    //Information
    //===========
    // return true when ic is "CATAxisGeoMap"
    CATBoolean IsAKindOf(const char* ic) const;
    
    CATBoolean IsALinearMap() const;
    
    /*
    if it is a LinearMap this methode give the equivalent Transformation
    */
    CATLONG32 GetMathTransformation(CATMathTransformation & oTransformation) const;
    
    //===========
    //Evaluators
    //===========
    CATLONG32 Eval(const CATMathPoint& iPInitial, CATMathPoint & oPModified) const;

    //===========
    //Evaluation of the derivatives of the local canonical (cartesian) axis system
    //===========
    CATLONG32 EvalFirstDeriv(const CATMathPoint & iPInitial, 
                                   CATMathVector& oDx      ,
                                   CATMathVector& oDy      ,
                                   CATMathVector& oDz) const;
    
    CATLONG32 EvalSecondDeriv(const CATMathPoint& iPInitial, 
                                    CATMathVector& oD2x,
                                    CATMathVector& oD2y,
                                    CATMathVector& oD2z,
                                    CATMathVector& oDxy,
                                    CATMathVector& oDxz,
                                    CATMathVector& oDyz) const;
    void GetAnaSynth(CATGSDBase *&AnaObj,CATGSDBase *&SynthObj) const;

     virtual int   GetHasToBeChecked()   const;
 
     virtual void  SetHasToBeChecked(int &iCheckCode) const ; 

protected :
    
   virtual  ~CATAxisGeoMap();


  private :
    
   CATGSDAxis   * _Analysis;
   CATGSDBase  ** _Synthesis;
   

};
#endif
