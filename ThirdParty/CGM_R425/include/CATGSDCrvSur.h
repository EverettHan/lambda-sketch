/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=====================================================================
//
// GlobDef object using a spine curve and a surface :
//
//=====================================================================
// Usage notes:
//
//=====================================================================
// June 98   Creation                         D. Johansson
//=====================================================================

#ifndef CATGSDCrvSur_H  
#define CATGSDCrvSur_H 


#include <stdlib.h>
#include "CATCrvParam.h"
#include "CATGSDModParam.h"
#include "CATNurbsCurve.h"
#include "CATNurbsSurface.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "CATMathSetOfPoints.h"
#include "CATMathSetOfVectors.h"
#include "FrFOpeSur.h"
#include "CATGSDBase.h"
#include "CATGeoFactory.h"
class CATSoftwareConfiguration;


class  ExportedByFrFOpeSur CATGSDCrvSur : public CATGSDBase 

{  
public: 
    
  //===================================================================
  // Constructor:
  //===================================================================
  
  CATGSDCrvSur (      CATGeoFactory             *ifactory,
                      CATSoftwareConfiguration  *iSoftwareConfiguration,
                const CATNurbsCurve             *iSpine,
                const CATNurbsSurface           *iRefSurf,
                const CATLONG32                  NrOfNod   = 1000 , 
                const double                     offset  = 0.0 ) ;

  //===================================================================
  // Destructor:
  //===================================================================
  
  virtual ~CATGSDCrvSur () ; 

  //===================================================================
  // Change the curve:
  //===================================================================

  void SetOtherCurve  ( const CATNurbsCurve *iSpine ) ;

  //===================================================================
  // Change the surface:
  //===================================================================

  void SetOtherSurface  ( const CATNurbsSurface *iRefSurf,
                          const double           offset = 0 ) ;

  //===================================================================
  // Change the offset: ( empty arg. resets to zero )
  //===================================================================

  void SetOtherOffset  ( const double offset = 0.0 ) ;

  // +++++ Methods to modify U(-niform) parameter along the curve ++++++  

  //===================================================================
  // To extract the curve length. 
  //===================================================================
  
  double CurveLength ( ) ;
  
  //===================================================================
  // Sets a "U-modification". Use at synthesis only! 
  // 0 = magnI = magnII ==> no U modification.
  // scaleI and scaleII sets the scaling at the ends.
  // Empty argument resets to no U-modification.     
  //===================================================================

  void SetModU (const double      lengthCRVA = 0.0 ,
                const CATLONG32   magnI      = 0   , 
                const CATLONG32   magnII     = 0   ,
                const double      scaleI     = 1.0 ,  
                const double      scaleII    = 1.0 ) ; 

  //===================================================================
  // Set or reset scales.  
  //===================================================================

  void SetScales (const double scaleI  = 1.0 , 
                  const double scaleII = 1.0 ) ; 
  
  //==== All following ModU-methods are intended for manual work ======

  //===================================================================
  // Set parameter segment on CRVA corresponding to [Par1, Par4] on
  // the sunthesis curve.
  //===================================================================

  void SetCRVASegment (const double iPar1A  , 
                       const double iPar4A ) ; 

  //===================================================================
  // Move along CRVS. Normal use: 
  // Before this methods is used we define start segments by
  // "SetCRVASegment(Par1, Par4r1)" and "SetSegment(Par1, Par4)".
  //===================================================================

  void MoveSegment (const double iParFrom , 
                    const double iParTo   ) ;

  //===================================================================
  // The first signature is used if we do not want to change scalings
  //  or if both magnitudes are zero.

  // The second signature is used if we want to manipulate scalings by
  // simulated control points but ONLY IF ONE magnitude IS ZERO and
  // THE OTHER IS NOT. The three points will, in a particular way, 
  // change the  scalings, scaleI or scaleII respectively. 

  // The third signature is used like the second but ONLY IF NO 
  // magnitude IS ZERO. 
  // OneScaleIsConst = 0: Both scaleI and scaleII will be changed.  
  // OneScaleIsConst = 1: scaleI  is constant and iPar2 is ignored. 
  // OneScaleIsConst = 2: scaleII is constant and iPar3 is ignored.   
  //===================================================================

  void SetSegment (const double iPar1 ,  
                   const double iPar4 ) ; 

  void SetSegment (const double    iPar1    ,  
                   const double    iPar2or3 ,  
                   const double    iPar4    ) ; 

  void SetSegment (const double    iPar1 ,  
                   const double    iPar2 ,  
                   const double    iPar3 ,  
                   const double    iPar4 ,
                   const CATLONG32 OneScaleIsConst = 0 ) ;
  
  //===================================================================
  // Read the simulated control points. To be used after "MoveSegment",
  // after direct setting of scaling or after "SetSetment". 
  // Observe: In the last case, Par2 and Par3 may be changed since they
  // has become "illegal". The restriction of use of signatures is as 
  // for "SetSegment" 
  //===================================================================

  void GetSegment (double &oPar1 ,
                   double &oPar4 ) ;

  void GetSegment (double &oPar1    ,
                   double &oPar2or3 , 
                   double &oPar4    ) ;

  void GetSegment (double &oPar1 ,
                   double &oPar2 , 
                   double &oPar3 , 
                   double &oPar4 ) ;

  //==================================================================
  // Read  scales. Used if "SetSetment" has changed the scales.
  //==================================================================

  void GetScales (double  &ScaleI  , 
                  double  &ScaleII ) ;  

  // Private section. Only related to ModU:
private:

  CATGSDModParam _ModUParam       ;
  double _Length, _LengthCRVA     ;
  double _UIA, _LUA, _UIS, _LUS   ;

  //===================================================================
  // Set modification polynomials   
  //===================================================================

  void SetModUPolynomials() ; 
  
  //===================================================================
  // Evaluate the parameter modification  
  //===================================================================

  void evalModUParam(const double  iu ,
                     double       &ou , 
                     double       &du  ) ; 

public:

  //+++++++++++++++++++++ to evaluate the "K- function" +++++++++++++++

  //===================================================================
  // Used for differentiation by finite differences :
  //===================================================================

  void VeryCloseAtK ( CATLONG32 yes ) {} ; // to be implemented.

  //===================================================================
  // 
  //===================================================================

  void InitializeK () {} ; // to be implemented.

  //===================================================================
  // Evaluation of K(u, v, w) :
  //===================================================================

  CATLONG32 EvaluateKuvw() ;
  
  //===================================================================
  // Projection onto K(u, v, 0) . 
  //===================================================================

  CATLONG32 ProjOnKuv0() ; 

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
  // PRIVATE PROPERTY  
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
  
private:
  
  CATLONG32               _NrOfNod                   ;
  double                * _LInNod,
                        * _dLInNod      ;
  CATMathSetOfVectors     _ZInNod,
                          _dZInNod  ;
  const CATNurbsCurve   * _Spine     ;
  CATCrvParam             _CrvParam           ;
  const CATNurbsSurface * _RefSurf ;
  double                  _Offset                  ;  
  double                  _RStart,
                          _REnd,
                          _RLength,
                          _RScale  ;
  CATLONG32               _IsPeriodic                ;
  CATLONG32              _ProjOnCrSurInitialized   ;
  double                 _RGrid[11]               ; 
  CATMathSetOfPoints     _CGrid       ;      
  CATMathVector          _TgStart,
                         _TgEnd  ; 
  CATMathSetOfVectors    _CrGrid,
                         _CrrGrid,
                         _VGrid,
                         _VrGrid ;
  double               * _SqLGrid                ;

  //===================================================================
  // Initialize Curve data 
  //===================================================================

  void InitializeCurveData () ;
  
  //===================================================================
  // Set interpolation data _LInNodes and _dLInNodes from
  // lengths of derivatives and length of param interval
  //===================================================================

  void SetLInNoddLInNod () ; 
  
  //===================================================================
  // Evaluation in segment [0, 1] R --> L (The length L 
  // normalized by L/_Length is used as U parameter. Se next.) 
  //===================================================================

  void R_to_L ( const double r,  const double *cL, 
               const double *dcL,     double &outL ) ; 

  //===================================================================
  // Return U parameter from the curves original param r_r. 
  //===================================================================

  double Get_UFrom_R ( const double r_r ) ;
  
  //===================================================================
  // Iverse evaluation in segment [0, 1] R --> L,
  //===================================================================

  void L_to_R ( const double L,   const double *cL, 
               const double *dcL,      double &r ) ; 

  //===================================================================
  // Return  curve param R from length param. 
  //===================================================================

  double Get_RFrom_U ( const double u_u ) ;

  //===================================================================
  // Vector evaluation in segment [0, 1] R --> Z (Z is in R3)
  //===================================================================

  void R_to_Z ( const double         r,
                const double         sc, 
                const CATLONG32      i,     
                      CATMathVector *outZ, 
                      CATMathVector *outdZ, 
                      CATMathVector *outddZ = NULL ) ;
  
  //===================================================================
  // In my thesis, page 66, the direction v and its derivative are
  // calculated (and also the direction, w). This routine does this
  // using the curves own parameter "r". It is to be changed to "u" by  
  // the use of the chain rule.
  // n  and nu  are given    as ioV and ioVr.
  // cu and cuu are given    as iCr and iCrr.
  // v  and vu  are returned in ioV and ioVr.   
  // By option, the second derivative of v can be calculated, as given by
  // obvious notation. 
  //===================================================================

  void V_Vectors ( const CATMathVector *iCr,
                         CATMathVector *ioV,
                   const CATMathVector *iCrr,
                         CATMathVector *ioVr,
                   const CATMathVector *iCrrr = NULL,  
                         CATMathVector *ioVrr = NULL ) ; 

  //===================================================================
  // Evaluates _CRV and V-vectors in r_r. 
  //===================================================================

  void EvaluateCRVandV ( const double r_r, 
                               CATMathPoint  *Cp,  
                               CATMathVector *V,  
                               CATMathVector *Cr,  
                               CATMathVector *Vr, 
                               CATMathVector *Crr = NULL, 
                               CATMathVector *Vrr = NULL ) ;

  //===================================================================
  // Calculate CRVsurface point and normal and their derivatives.
  //===================================================================

  void EvaluateCRVSurAndNormal ( const double r_r,  
                                 const double v_v, 
                                       CATMathPoint *Kp,
                                       CATMathVector *Kr,
                                       CATMathVector *Kv,
                                       CATMathVector *No,
                                       CATMathVector *Nr,
                                       CATMathVector *Nv,
                                       CATMathVector *Cr ) ;

  //===================================================================
  // Changes derivatives of the curve (C) and of vectors (V1 - V2) from
  // variables of r to the variable u.
  //===================================================================

  void ChangeToUDerivatives ( const double          Bu,
                              const CATMathVector * Cr,
                                    CATMathVector * V1r, 
                                    CATMathVector * V2r = NULL ) ;

  //===================================================================
  // Subroutine for next prog 
  //===================================================================

  CATLONG32 FindTraceByProject (const CATLONG32   index,
                                const double i_u,
                                      double &io_s,
                                      double &io_t,
                                      double &o_su,
                                      double &o_tu, 
                                const double sMin,
                                const double tMin,
                                const double sMax,
                                const double tMax,
                                const double sDiff,
                                const double tDiff ) ;
  
  //===================================================================
  // See my thesis, bottom of page 63 to top of page 66.
  //
  // First, this routine tries to find a good "st" point.
  // Then it calculate and return the normal n and its u-
  // derivative. Further, su and tu, where su and tu are 
  // the u-derivative of "smallFi" at the bottom of page 65.
  // 
  // The method may stop and an error messge be delivered 
  // this EITHER means that the given start point "st" is 
  // too far from a correct solution OR that one of the three 
  // conditions discussed on page 63 is violated.   
  //===================================================================

  void VectorFieldAtSurfaceTrace ( );

  //===================================================================
  // Consider the surface given by K(u, v, 0) as described in my thesis,
  // Example 3.15 page 72. This prog do projection on the Points onto
  // that surface in three possible ways:
  //  - if prVec isn't given: Closest points are found.
  //  - if prVec is given:    The Points are projected in this direction.
  // The vector(s) in PrDir must be of unit length!  
  //===================================================================

  CATLONG32 ProjOnCRVSurf ( const CATMathPoint  *ipoint,       
                      double &r_r,  
                      double &v_v,   
                      const CATMathVector *prVec = NULL ) ;

  //===================================================================
  // Finds param. values of closest points on Bezier  curve .
  //===================================================================

  CATLONG32 ClosestOnCRV ( const CATMathPoint *Point, double &r_r ) ;  

};  

//===================================================================
// This is used in "ProjOnCRVSurf":
// Dot product between ivec1 and ivec2 after a projection of ivec1
// (and/or ivec2) on a plane with (unit-)normal vector (= projvec).
// With &projvec = NULL, we get a standard dot product, i.e. without
// projection.
//===================================================================

inline double dotProdProj(const CATMathVector &ivec1, 
                          const CATMathVector &ivec2,
                          const CATMathVector *projvec ) 
{
  return projvec ?  
                   ivec1 * ivec2 - (ivec1 * *projvec) * (ivec2 * *projvec)
                 :
                   ivec1 * ivec2 ;
}

#endif  
