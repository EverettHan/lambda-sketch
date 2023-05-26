/*-*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
//==========================================================================
//  Mar. 02 NDN Creation
// 13/03/15 NLD Smart indent
//========================================================================

#ifndef CATSmoothCurve_H
#define CATSmoothCurve_H

#include "FrFOpeCrv.h"
#include "CATDataType.h"
#include "CATCGMOperator.h"
#include "CATLISTV_CATMathPoint.h"
class CATCurve;
class CATGeoFactory;
class CATCrvLimits;
class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATSmoothCurve : public CATCGMOperator
{
public:
    
   virtual                             ~CATSmoothCurve()
   {};

   // Do not use directly. Use the CATCreateSmoothCurve function instead.
                                        CATSmoothCurve              (      CATGeoFactory             * iFactory         );

   // Permet de basculer sur le mode FreeStyle (on impose un smoothing sans controle de l'erreur).
   //                        (XScaleRules) iSmoothValue must be independent from factory scale. NLD130315
   virtual  void                        SetSmoothingFactor          (      double                      iSmoothValue     )         = 0;

   // Possible values are 0,1,2 and 3 for corresponding continuity.
   // If not enough freedom degrees remain to make a smooth, nothing
   // will be done. Default is 0 (i.e. point continuity). 
   virtual void                         SetContinuityOnSides        (      CATLONG32                   iContinuityStart = 0,
                                                                           CATLONG32                   iContinuityEnd   = 0)      = 0;

   // Doit-on garder la segmentation initiale.(//FALSE par defaut.)
   virtual void                         SetKeepSegmentation         (      CATLONG32                   iKeep            = 1)      = 0;

   // Possible value for iContinuity are 1 or 2 (2 is default).
   virtual void                         SetInternalContinuity       (      CATLONG32                   iContinuity      )         = 0;

   // To compute error in radian considering curve like a vector field. Default is NO.
   // CAUTION: not really in radian (see GetMaxDeviation()). angle multiplied by factory scale    NLD180315
   virtual void                         SetAngleMode                (      CATLONG32                   iAngleMode       )         = 0;

// virtual int                          GetPtsDeformOnInputCurve    (      CATLISTV(CATMathPoint)    & oPtsDeformOnInputCurve   ) = 0;
// virtual int                          GetPtsDeformOnSmoothedCurve (      CATLISTV(CATMathPoint)    & oPtsDeformOnSmoothedCurve) = 0;

   // N.B output deviation is always behaving like power 1 of factory scale (like a distance)
   //     even in angle mode (see SetAngleMode()), result is n angle multiplied by factory scale. NLD180315
   virtual double                       GetMaxDeviation             ()                                                            = 0;

   virtual CATCurve                   * GetResult                   ()                                                            = 0;

};

//-----------------------------------------------------------------------------
// Creation function :
ExportedByFrFOpeCrv  
         CATSmoothCurve               * CATCreateSmoothCurve        (      CATGeoFactory            *  iFactory         ,
                                                                     const CATCurve                 *  iCurve           ,
                                                                     const CATCrvLimits              & iCrvUsefullLimits,
                                                                           CATLONG32                   iDimSmooth       ,
                                                                           double                      iTolerance       ,
                                                                           CATSoftwareConfiguration *  iConfig          = 0);
#endif

