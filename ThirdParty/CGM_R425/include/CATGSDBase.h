/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATGSDBase :
// Implementation class for global deformation "Black Box".
//
//=============================================================================
//
//=============================================================================
// Mars  99  Creation                          Daniel Johansson
//=============================================================================
#ifndef CATGSDBase_H
#define CATGSDBase_H

#include "FrFOpeSur.h"
#include "CATGeoFactory.h"
#include "CATNurbsSurface.h"
#include "CATShell.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "CATMath3x3Matrix.h"
#include "CATMathDirection.h"
#include "CATGSDSurProjections.h" 
#include "CATGSDModParam.h" 
#include "CATMathDef.h"
#include <stdlib.h>
#include "CATCGMVirtual.h"

class CATSoftwareConfiguration;

//
//-----------------------------------------------------------------------------
class ExportedByFrFOpeSur CATGSDBase : public CATCGMVirtual
{
public:

  CATGSDBase (CATGeoFactory  *ifactory ,CATSoftwareConfiguration  *iSoftwareConfiguration) ; 

  //  Destructor: ---------------------------------------

  virtual ~CATGSDBase () ;

  void LinkThisAnalysisTo ( CATLONG32 NrOfSynt, CATGSDBase **SyntOper ) ;

  //  =================== Set up parameters: ========================= 

  void SetNoGuideSurf () ; 
  
  void SetOneGuideSurf ( CATNurbsSurface *SurI ) ;

  void SetOneGuideSurf ( CATShell *iShellI ) ; 

  void SetOneGuideSurf ( CATSurface ** iSurfaces,     CATLONG32 iNbSurf,
                         CATFace    ** iFaces = NULL, CATLONG32 iNbFac = 0 ) ;

  void SetOneGuideSurf ( CATFace    ** iFaces ,       CATLONG32 iNbFac ) ;

  void SetOneGuideScaling ( double AddToW, double ScaleW ) ; // default = 0, 1.

  // Shells as guide surfaces may, at demands, easily be implemented also on all double guids:
  void SetTwoGuideSurf (CATNurbsSurface *SurI  , 
                        CATNurbsSurface *SurII ) ;
  
  void SetTwoGuideSurfButUseKuv0ForSurI ( CATNurbsSurface *SurII ) ;
  
  void SetTwoGuideSurfButUseKuv0ForSurII ( CATNurbsSurface *SurI ) ;
  
  void SetTwoGuideScalings (double iScaleI,  CATLONG32 iMagnitudeI, 
                            double iScaleII, CATLONG32 iMagnitudeII ) ; // default: none.

  void SetKeepAtSurI ( CATLONG32 yes ) ;  // On SYNTHESIS ONLY! ( default = 0 ).

  void SetKeepAtSurII ( CATLONG32 yes ) ; // On SYNTHESIS ONLY! ( default = 0 ).

  // Five metods related to modification direction. Default direction,  
  // denoted W, relates to the "K-functon". See page 46 in my thesis.
  // Vector or Normal, both denoted N, relates to the guide surface
  // (or first guide surface if two). See page 53, lower part.

  void SetReuseWAtSynt ( CATLONG32 yes ) ;  // On SYNTHESIS ONLY! ( default = 0 ).

  void SetReuseNAtSynt ( CATLONG32 yes ) ;  // On SYNTHESIS ONLY! ( default = 0 ).

  void SetDefaultModificationDirection () ; // DONE by default.

  // "SetReuseNAtSynt(1)" cancel the following at Synthesis:
  // Example 2.37 page 43 :
  void SetVectorAsModificationDirection ( CATMathDirection *ModDir ) ;  

  // "SetReuseNAtSynt(1)" cancel the following at Synthesis:
  // Example 2.38 page 44:  
  void SetNormalAsModificationDirection () ; // NOT done by default .

  // Use on Analysis Operator after "SetStore(?)" and all of the settings above 
  // but before "GetNeededStorage(h,W,N)" and before first call of "Run()" :  

  void Update ()          ;

  // The diagnosis is particularly interesting for CATGSDCrvWrap. 
  // See its .h file. Return values is zero or negative if not okay.
  CATLONG32 DiagnosisOfUpdate () ;

  //  ================= Transformation work: ========================= 

  void AlsoSecondDeriv ( CATLONG32 yes ) ; // set zero if not ( is default ). 

  //  Pointwise interaction :    

  inline void SetPoint ( CATMathPoint  *iPoint )
    { *_XYZ = *iPoint ; } ; 

  CATLONG32 Run () ;  // returns 1 if OK, else zero.
  
  inline void GetPoint ( CATMathPoint  *oPoint )
    { *oPoint = _OutXYZ ; } ; 

  inline void TransformDeriv (CATMathVector *inDeriv, 
                              CATMathVector *outDeriv )  
    { *outDeriv = _ModMatrix * *inDeriv ; } ; 

  void TransformNormal (CATMathDirection *inNormal, 
                        CATMathDirection *outNormal ) ; 
  
  inline CATMath3x3Matrix * GetModMatrix() 
        { return & _ModMatrix ; } ;

  void TransformSecondDeriv (CATMathVector *inFirstDeriv, // Derivative BEFORE transform!
                             CATMathVector *inSecDeriv, 
                             CATMathVector *outSecDeriv ) ; 

  void TransformCrossDeriv (CATMathVector *inDerivU,      // Derivative BEFORE transform!
                            CATMathVector *inDerivV,      // Derivative BEFORE transform!
                            CATMathVector *inCrossUV, 
                            CATMathVector *outCrossUV ) ;

  // For offset work
  const CATMathDirection * GetWDirection()
        { return _W ; } ;
 
  //  ================= For intermediate storing: ==================== 

  // All these storage methods are EXCLUSIVELY USED AT THE ANALYSIS
  // OPERATOR. (The adresses are read by the Synthesis Operators.)

  void SetStore ( CATLONG32 yes ) // ( default = zero ). Of course, "zero" make 
    { _Store = yes ; } ;     // all the following obsolete!!

  // To see if and what storage must be handled (a, b, c and d (e)). 
  // Run "Update()" first!! :
  
  // a.
  inline CATLONG32 GetIfStorage ()
    { return _Store ; } ;

  // b.
  inline CATLONG32 GetIfStoreH ()
    { return _ExternH ; } ;
  
  // c.
  inline CATLONG32 GetIfStoreW ()
    { return _ExternW ; } ;

  // d. (and e.)
  inline CATLONG32 GetIfStoreN ()
    { return _ExternN ; } ;

  // a. If storage, allways: 

 inline void SetPointInLocalCoord ( CATMathPoint *ioUVW )
    { _UVW = ioUVW ; } ;

  inline void SetLocalAnalysis ( CATMath3x3Matrix *ioMatrix )
    { _AnaMatrix = ioMatrix ; } ; 

  // b. If storage and two guides:

  inline void SetDistSurISurII ( double *iohAII )
    { _hAII = iohAII ; } ; 

  inline void SetDuOfDist ( double *iohAu )
    { _hAu = iohAu ; } ; 

  inline void SetDvOfDist ( double *iohAv )
    { _hAv = iohAv; } ; 

  // c. If storage and reused W-direction: 
  //    First (and only once) at synthesis, use SetReuseWAtSynt (1).
 
  inline void SetWDirection ( CATMathDirection *ioWA )
    { _W = ioWA ; } ;
  
  inline void SetDuOfWDir ( CATMathVector *ioWAu )
    { _Wu = ioWAu ; } ; 
  
  inline void SetDvOfWDir ( CATMathVector *ioWAv )
    { _Wv = ioWAv ; } ;
 
  // d. If storage and reused N-direction:
  //    First (and only once) at synthesis, use SetReuseNAtSynt (1).
  //    Generally, at analysis, use SetNormalAsModificationDirection(). 

  inline void SetNDirection ( CATMathDirection *ioNA )
    { _N = ioNA ; } ;
  
  inline void SetDuOfNDir ( CATMathVector *ioNAu )
    { _Nu = ioNAu ; } ; 
  
  inline void SetDvOfNDir ( CATMathVector *ioNAv )
    { _Nv = ioNAv ; } ; 

  // e. If scalings differ from one and if KeepAtSurI or KeepAtSurII,
  //    the three "N-metods" above are also used.

  //  ======================= End of storage ========================= 
  virtual int  GetMultipleProjections() ;  
   
  virtual void  SetMultipleProjections(int &iMultipleProjection) ;
   
private: 
  int _MultipleProjection;

  CATGeoFactory * _factory  ; 
  
  CATLONG32 RunAnalysis  ()     ; 
  
  CATLONG32 RunSynthesis ( CATMathPoint *oXYZ, CATMath3x3Matrix *odXYZ ) ; 

  CATLONG32 RunAnalysisII  ()   ; // for second derivatives
  
  CATLONG32 RunSynthesisII ()   ; //    - " -
  
  // To calculate derivatives by finite diff. ------------
  void VeryClosePoint ( CATLONG32 yes ) ; // 0 if not.

  //  =========== Evaluation on SurI or II: ============== 
  
  CATLONG32 EvalNor(CATGSDSurProjections *projOper,
                 CATMathDirection *No ) ; 

  //  ==== Evaluation on SurI (Use global objects) : ===== 
  
  CATLONG32 DerivativesOfNor(CATMathDirection *iN ,
                             CATMathVector    *oNu , 
                             CATMathVector    *oNv ) ;
  

  //  ======== Evaluation of the "K-function" : ========== 

public:

  CATLONG32 K_IS_OK () { return _K_IS_OK ; } ;

protected:

  CATLONG32 _K_IS_OK ; // diagnisis from "InitializeK ()". 

  virtual void      InitializeK () = 0 ;  

  virtual void      VeryCloseAtK ( CATLONG32 yes ) = 0 ; // 0 if not.

  virtual CATLONG32 EvaluateKuvw() = 0 ;
  
  virtual CATLONG32 ProjOnKuv0() = 0 ;

  virtual void      Dump (CATLONG32 iDiag);
  
  // We allways need: 
  CATGSDBase       * _AnalysisOpe, ** _SyntOper; 
  CATLONG32          _Analyze, _Synthesize, _AlsoSecondDeriv ;  
  CATLONG32          _NrOfSynt, _Updated, _Store ;
  CATLONG32          _ExternU, _ExternH, _ExternW, _ExternN, _ReuseN ;  
  CATLONG32          _ProperU, _ProperH, _ProperW, _ProperN ;  

  CATMathPoint     * _XYZ,
                   * _xyz       ;   // input point & copy.
  CATMathPoint     * _UVW              ;   // K or C coordinates of _XYZ. 
  CATMathPoint       _OutXYZ           ;   // Fully transformed _XYZ. 
  CATMath3x3Matrix * _AnaMatrix     ;   // Local transformation will be
  CATMath3x3Matrix   _ModMatrix     ;   // _DiffMatrix * (*_AnaMatrix).
  CATMath3x3Matrix   _matrix        ;   // Intermediate use.

  CATMathPoint       _K0        ; 
  CATMathVector      _Ku0, _Kv0 ;
  CATMathDirection * _W     ; 
  CATMathVector    * _Wu, * _Wv ;

  // ---- If also second derivatives: ----------

  double             _del4, _del8  ;
  CATMathVector      _Cxx, _Cyy, _Czz, _Cxy, _Cxz, _Cyz ;
  CATMathVector    * _Delta, * _Fx, * _Fy, * _Fz ;

  // ----------- one guide surf: ---------------    

  CATNurbsSurface  * _SurI ;
  CATShell         * _ShellI      ;
  CATLONG32          _ExternalGuide_I  ; 
  CATGSDSurProjections * _ProjOnSurI ;
  CATMathPoint       _PI       ;
  CATMathDirection * _N   ;
  double _Ln             ;
  CATMathDirection   _NI   ; 

  // Used for linear scaling. : 
  double             _ScaleW, _AddToW ;
  
  // ----------- two guide surf: ---------------
  CATLONG32          _CaseDouble      ;    
  CATLONG32          _Kuv0IsSurII     ;
  CATNurbsSurface  * _SurII ;
  CATGSDSurProjections * _ProjOnSurII ;
  CATMathPoint       _PII       ;
  CATMathDirection   _NII   ; 

  // Two guide scaling :  
  CATGSDModParam     _ModW, _ModW0 ; 
  double           * _hAII, * _hAu, * _hAv ;  

  // ---- Projection direction onto SurI. ------
  // Default direction. Projection in _W direction. 
  CATLONG32          _DefaultDir       ;
  
  // exernally given proj direction.
  CATLONG32          _SpecifiedDir       ;
  CATMathDirection * _R   ; 

  // normal proj direction
  CATLONG32          _NormalDir   ;
  CATMathVector    * _Nu, * _Nv     ; // Normal  derivatives in u, v - coordinates.

  // if locally keeped model at SurI or SurII.
  CATLONG32         _KeepAtSurI,  _KeepAtSurII, _KeepIsScaled, _KeepMethod;

  CATSoftwareConfiguration  * _SoftwareConfiguration;

};

#endif
