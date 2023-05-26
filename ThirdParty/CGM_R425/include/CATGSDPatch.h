/*-*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=====================================================================
//
// GlobDef object for ANA/SYNTH :
//
//=====================================================================
// Usage notes:
//
//=====================================================================
// Feb 99   Creation                         D. Johansson
//=====================================================================

#ifndef CATGSDPatch_H  
#define CATGSDPatch_H 

#include "CATGeoFactory.h"
#include "CATGSDBase.h"
#include <stdlib.h>
#include "CATNurbsSurface.h"
#include "CATSurParam.h"  
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "FrFOpeSur.h"
#include "CATGSDSurProjections.h"
#include "CATSurLimits.h"  
class CATSoftwareConfiguration;

class  ExportedByFrFOpeSur CATGSDPatch : public CATGSDBase 

{  
public: 
  
  //===================================================================
  // Constructor:
  //===================================================================
  
  CATGSDPatch (      CATGeoFactory            *  ifactory ,
                     CATSoftwareConfiguration *  iSoftwareConfiguration,
               const CATNurbsSurface          *  iRefSurf ) ;
  
  CATGSDPatch (      CATGeoFactory            *  ifactory ,
                     CATSoftwareConfiguration *  iSoftwareConfiguration,
               const CATSurface               *  iRefSurf ,
                     CATSurLimits             *& iSurLim) ;

  //===================================================================
  // Destructor:
  //===================================================================
  
  virtual ~CATGSDPatch () ; 

  //===================================================================
  // Change the surface: 
  //===================================================================

  void      SetOtherSurface  (const CATNurbsSurface *iRefSurf ) ;
  void      SetOtherSurface  (const CATSurface      *iRefSurf , CATSurLimits *&iSurLim) ;
  //===================================================================
  // Used for differentiation by finite differences :
  //===================================================================

  void      VeryCloseAtK ( CATLONG32 yes ) ; // 0 if not

  //===================================================================
  // To initialize projection operator.
  //===================================================================

  void      InitializeK () ; 

  //===================================================================
  // Evaluation of K(u, v, w) :
  //===================================================================

  CATLONG32 EvaluateKuvw() ;

  //===================================================================
  // Projection onto K(u, v, 0) . 
  //===================================================================

  CATLONG32 ProjOnKuv0 ( ) ; 

private:
  
  const CATSurface           * _RefSurf ;
        double                 _uMin,
                               _vMin,
                               _uDiff,
                               _vDiff ;
        CATLONG32              _ProjIsDone ; 
        CATSurParam            _SurParam ;
        CATGeoFactory        * _factory ; 
        CATGSDSurProjections * _ProjOpe ;
        CATSurLimits         * _SurLim;
  //===================================================================
  //  Initialize Surface data 
  //===================================================================

  void InitializeSurface () ;

  //===================================================================
  //  Evaluation of point, derivative, normal and normal deriv. 
  //===================================================================

  void EvaluateSurfAndNormal (const double            iu, 
                              const double            iv,
                                    CATMathPoint     *Kp,
                                    CATMathVector    *Ku,
                                    CATMathVector    *Kv,
                                    CATMathDirection *No = NULL, 
                                    CATMathVector    *Nu = NULL, 
                                    CATMathVector    *Nv = NULL ) ; 

};

#endif  

