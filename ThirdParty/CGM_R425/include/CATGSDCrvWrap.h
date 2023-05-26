 
// =======================================================================================
//  COPYRIGHT DASSAULT SYSTEMES 2000
// =======================================================================================
// 
//  CATGSDCrvWrap :
// 
// =======================================================================================
//  Usage notes:
// 
//  All settings, after creation, sould be done after the linking Analysis <-> Synthesis
//  as understood by the method "LinkThisAnalysisTo(...)" in mother class CATGSDBase. 
// 
//  Return code given by "DiagnosisOfUpdate()" (in mother class CATGSDBase) is given by
//   1 if everything is okay.
//   0 if a spine derivative is (allmost) zero .
//  for reference or target curves we get:
//  -1 if extrapolation is needed but fails.
//  -2 if the a derivative projected on the spine is too short or reversed, i.e.
//        a violation of strict monotony parameter relation.
//  -3 if the curves, in v-direction, are crossing, are too close or are badly ordered. 
//  -4 if direction curve and spine are too close or coinciding
//  -9 if som other odd cases like som zero length curve.
// 
//  The codes -3 and -4 may be ignored at creation by using "IgnoreError(1)" but later 
//  retreived at the use of the transform, if it fails.
// 
//  The non positive error code is as above if it is found in the analysis operator. 
// 
//  If the error is found in the first synthesis operator -10 is added and in the second
//  -20 is added ... For instance errors in the first syntehsis operator might be -10, -11
//  -12, -13, -14, or -19.
// 
// =======================================================================================
//       00 DJn Creation                                                      D. Johansson
// 12/03/18 NLD Suppression ancien constructeur sans iDirKind
// =======================================================================================
#ifndef CATGSDCrvWrap_H  
#define CATGSDCrvWrap_H 

#include "CATGSDBase.h"
#include "CATGSDModParam.h"
#include "CATCrvLengths.h"
#include "FrFOpeSur.h"
#include "CATNurbsCurve.h"
#include <stdlib.h>
#include "CreateDistanceMinPtCrv.h"
#include "CATDistanceMinPtCrv.h"
#include "CATGeoFactory.h"
#include "CATIntersectionCrvSur.h" 
#include "CreateIntersection.h"
#include "CATMathPlane.h"
#include "CATPlane.h" 
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATExtrapolCurve.h"
#include "CATCrvParam.h"
#include "CATDistanceMinPtCrv.h"
#include "CATProjectionPtCrv.h"
#include "CATSoftwareConfiguration.h"
class ExportedByFrFOpeSur CATGSDCrvWrap : public CATGSDBase 

{    
public:
   
   /**
   *=======================================================================================   
   *  Constructor 
   */
        
   CATGSDCrvWrap (      CATGeoFactory            * iFactory ,
                        CATSoftwareConfiguration * iSoftwareConfiguration,
                  const CATNurbsCurve            * iSpine   ,
                  const CATLONG32                  iDirKind , // == 1 for old default
                  const CATNurbsCurve            * iDirCurve,
                  const CATLONG32                  iNbRefC  ,
                        CATNurbsCurve           ** iRefCurves,
                  const CATLONG32                  iNbDiscr = 1000 ) ;
   
   /* shunt NLD120318
   CATGSDCrvWrap (CATGeoFactory  *iFactory ,
               CATSoftwareConfiguration *iSoftwareConfiguration,
      const CATNurbsCurve  *iSpine, 
      const CATNurbsCurve  *iDirCurve, 
      const CATLONG32            iNbRefC,
      CATNurbsCurve       **iRefCurves, 
      const CATLONG32            iNbDiscr = 1000) ;
    */
   
   /**
   *=======================================================================================   
   *  Destructor
   */
   
   virtual ~CATGSDCrvWrap () ;
   
   /**
   *=======================================================================================   
   *  Set other curve. 0 <= iInd < iNbRefC.  
   */
   CATLONG32 SetOtherCurve ( const CATNurbsCurve *iRefCurve, const CATLONG32 iInd ) ;
   CATLONG32 SetOtherSpine ( const CATNurbsCurve *iSpine ) ;

   /**
   *=======================================================================================   
   *  Set C2 continuities at first and/or last ref-curve.  
   */
   void SetC2ContAtFirstRef( CATLONG32 yes ) ;
   void SetC2ContAtLastRef ( CATLONG32 yes ) ;

   /**
   *=======================================================================================   
   *  If curve parametrization should be replaced by length parametrization.  
   */
   void UseLengthParam( CATLONG32 yes ) ;
   /**
   *=======================================================================================   
   *  Set  continuities at first and/or last ref-curve.  
   */
   void SetContAtFirstRef( CATLONG32 iCont ) ;
   void SetContAtLastRef ( CATLONG32 iCont ) ;
   /**
   *=======================================================================================   
   *  Update:
   */
    void InitializeK () ;
   
   /**
   *=======================================================================================   
   *  May be later ... 
   */
    void VeryCloseAtK ( CATLONG32 yes ) {} ; 
    CATLONG32 ProjOnKuv0() { return 0 ; } ;
   
   /**
   *=======================================================================================   
   *  The working function: 
   */
   CATLONG32 EvaluateKuvw()  ;

   /**
   *=======================================================================================   
   *  Desperate, ugly and temporary: Ignore error messages 2, 3 and 4 and ignores jump-out
   *  at updates. To be set before "Update()" 
   */

   void IgnoreError ( CATLONG32 yes ) ;
   
   // private:

   /**
   *=======================================================================================   
   *  Extrapolate curve: 
   */
   CATLONG32 Extrapolate ( CATNurbsCurve *&ioCurve, CATLONG32 &ioChanged, CATCrvParam &iCrvParam, double iSize ) ;

   /**
   *=======================================================================================   
   * Find curve ordering  
   */
   CATLONG32 CrvOrdering ( CATNurbsCurve **ioCRV ) ;
   
   /**
   *=======================================================================================   
   * Initialize curves: extend if needed and find end points.
   */
   CATLONG32 InitializeCurves ( CATNurbsCurve **ioCRV, CATLONG32 iNbCRV, double *ioStartT, double *ioEndT ) ;

   /**
   *=======================================================================================   
   * Initialize interpolation table 
   */
   CATLONG32 InitializeTable ( double *iStartT, double *iEndT, CATLONG32 * iSameDir ) ;
            
   /**
   *=======================================================================================   
   * Evaluate points & derivatives at iU.
   */
   
   void CurvePointsAndDerivatives ( const double iU, CATMathPoint * oPTS, CATMathVector * oDERIV ) ;
   
   /**
   *  Evaluation of reference curve distances at iU and along v-direction.
   */
   
   CATLONG32 CurveV_DistancesAtiU () ;
   void CurveV_DistancesAtiU ( const double iU ) ;// for debug only
      
   /**
   *=======================================================================================   
   * Complete local axis system consistig of Su, V and W and their u-derivatives  Suu, Vu and Wu : 
   */
   
   CATLONG32 GetV_Vu_W_Wu (
      const CATMathPoint  &S, 
      const CATMathVector &Su, 
      const CATMathVector &Suu,
      const CATMathPoint  &D, // From the direction curve
      const CATMathVector &Du, 
      CATMathVector &V, 
      CATMathVector &Vu,
      CATMathVector &W, 
      CATMathVector &Wu ) ;
   
   /**
   *=======================================================================================   
   * Evaluate  at analysis: 
   */
   
   CATLONG32 EvaluateAnalysisAtXYZ(const CATMathPoint   &iXYZ,
      CATMathPoint   &oUVW,
      CATMathPoint   &oKUV0,
      CATMathVector  &oKu0, 
      CATMathVector  &oKv0, 
      CATMathVector  &oW, 
      CATMathVector  &oWu, 
      CATMathVector  &oWv ) ;
   
   /**
   *=======================================================================================   
   * Evaluate  at synthesis: 
   */
   CATLONG32 EvaluateSynthesisAtUVW(const CATMathPoint   &iUVW,
      CATMathPoint   &oKUV0,
      CATMathVector  &oKu0, 
      CATMathVector  &oKv0, 
      CATMathVector  &oW, 
      CATMathVector  &oWu, 
      CATMathVector  &oWv ) ;
   
   /**
   *=======================================================================================   
   * Make a curve traverse the reference curves: 
   */   
   CATLONG32 MakeTraversalCurve (const double iPar, CATMathVector &iW, CATMathVector &iWu, CATLONG32 iArc ) ;
   
   /**
   *=======================================================================================   
   * G2-adjustment at inner nodes on the traversal curve: 
   */   
   CATLONG32 G2_Adjustment( CATMathVector &iW, CATMathVector &iWu, const CATLONG32 iInd ) ;
   
   /**
   *=======================================================================================   
   * Evaluate the traversal curve: 
   */   
   void EvalArc (const double iPar,
      const CATLONG32 iIndArc,
      const CATLONG32 iDegree,
      CATMathPoint  *oC,
      CATMathVector *oCu,
      CATMathVector *oCv ) ;
   // ---

protected :
  virtual void Dump (CATLONG32 Diag);

//private :
  public :
   
   CATGeoFactory *_Factory ;
   CATNurbsCurve *_Spine, *_DirCRV, **_RefCRV ;
   CATLONG32 _NbRef, _NbDiscr, _LnRow, _LeftC2, _RightC2, _ReversedOrder ;
   double *_Inter, *_DV, *_DVu ;
   CATMathPoint _StartP, _EndP, *_PTS, _SpineP, *_vC ;
   CATMathVector  *_DERIV, _SpineD, _SpineD2, _V, _Vu, *_vCu ;
   CATMathDirection _StartTg, _EndTg ;
   CATCrvParam _SpineParam ;
   CATDistanceMinPtCrv *_DistOpe ;
   CATLONG32 _InitializeK, _DirKind, *_Changed, _UseLengthParam, _NewCurve, _NewSpine ;
   CATGSDModParam *_Mod_0, *_Mod_i, *_Mod_n ;
   CATCrvLengths *_Lengths ;
   double _StartU, _EndU, _DeltaU, _LengthU, _LengthAna, _Length, _TOL, _TOL_6 ; 
   CATProjectionPtCrv *_ProjOpe ;
   CATLONG32 _DoNotIgnore ; // Ugly! 
    CATLONG32 _RightCont,_LeftCont;
};
#endif  
