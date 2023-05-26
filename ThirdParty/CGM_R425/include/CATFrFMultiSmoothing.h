//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
// 05/04/18        ; NLD : Mise au propre. Smart indent
// 04/04/18        ; NLD : XScale suppression de l'argument iTol de CATFrFCreateMultiSmoothing()
// October,   2003 ; MMO : Ajout de CATDataType pour FILL
// September, 2003 ; JCV : ajout CATSoftwareConfiguration
// April,     2003 ; ANR : Creation 
//====================================================================

#ifndef CATFrFMultiSmoothing_H
#define CATFrFMultiSmoothing_H

#include "CATFrFSmoothing.h"

#include "CATFreeFormDef.h"
#include "CATFrFSmoothingDef.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCurve;
class CATFrFNurbsMultiForm;
class CATMathSetOfPointsND;
class CATMathVector;
class CATNurbsCurve;

/**
 * Class defining a geometric operator that smoothes a set of points to create a curve.
 * <br>The CATFrFMultiSmoothing operator follows the global frame of the geometric operators: 
 *<ul>
 * <li>A CATFrFMultiSmoothing operator is created with the <tt>CATCreateMultiSmoothing</tt> global method 
 * and must be
 * directly <tt>delete</tt>d with the usual C++ delete operator after use.
 * It is is not streamable. 
 *<li>In case of <tt>BASIC</tt>
 * mode, the operation is automatically performed at the operator creation. 
 * In case of <tt>ADVANCED</tt>
 * mode, options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>In both cases, the result is accessed with the <tt>Getxxx</tt> methods. 
 *</ul>
 */

class ExportedByCATFrFSmoothing CATFrFMultiSmoothing
{
public :
  
  virtual ~CATFrFMultiSmoothing (); 
  
  virtual void             Run () = 0;
  
  /**
  * Defines the tangency constraint corresponding to each point 
  * of the initial set of points.
  * @param iVectFirstDer
  * The array of the tangency vector that correspond on the smoothed curve to
  * each point of the input set.
  * (if 0, a default value is computed)
  * @param iVectSecondDer
  * The array of the Normal vector (normalized) that correspond on the smoothed curve to
  * each point of the input set.
  * (if 0, a default value is computed)
  * @param iCvt
  * The array of the Curvature value.
  */
// Rank -> 1 to N

  virtual void             SetConstraints               (const int                     iRankCurve          ,
                                                         const int                     iRankPoint          ,
                                                               CATFrFContinuity        iContinuity         ,
                                                               CATMathVector        *  iVectFirstDer       = 0,
                                                               double                  iratio              = 1.0,
                                                               CATMathVector        *  iVectSecondDer      = 0,
                                                         const double                  iCurvatureValue     = 0.0) = 0;

  virtual void             SetTangentByimposedCtsPoints (const int                     iRankCurve          ,
                                                         const int                     iRankPoint          ,
                                                               CATMathVector         & iTangentVect        ) = 0 ;

  virtual void             SetNormOfTgtesAtExtremities  (      double                  lambda1             ,
                                                               double                  lambda2             ) = 0 ;

  virtual void             SetNormOfTgtesAtExtremities  (const int                     iRankCurve          ,
                                                               double                  ilambda1            ,
                                                               double                  ilambda2            ,
                                                               double                  iComposant1         = 0.0,
                                                               double                  iComposant2         = 0.0) = 0 ;

  virtual CATFrFContinuity GetContinuity                (const int                     iRankCurve          ,
                                                         const int                     iRankPoint          ) = 0 ;

  virtual CATMathVector    GetFirstDerivatives          (const int                     iRankCurve          ,
                                                         const int                     iRankPoint          ) = 0 ;
  
  virtual CATMathVector    GetSecondDerivatives         (const int                     iRankCurve          ,
                                                         const int                     iRankPoint          ) = 0 ;

  virtual void             DefaultDerivatives           (const int                     iRankCurve          ,
                                                         const int                     iRankPoint          ,
                                                               CATMathVector         & oFirstDer           ,
                                                               CATMathVector         & oSecondDer          ) = 0;

  virtual void             SetExtremities               (const int                     iFirstPoint         ,
                                                         const int                     iLastPoint          ) = 0;

  /**
  * Defines the degree of the resulting curve.
  * @param iDegree
  * The degree value.
  */
  virtual void             SetDegree                    (const int                     iDegree             ) = 0;
  
  virtual void             SetMaxDegree                 (const int                     iDegree             ) = 0;

  virtual void             GetExtremities               (      int                   & oFirstPoint         ,
                                                               int                   & oLastPoint          ) = 0;

  virtual void             GetTolerance3D               (      double                & oTol                ) = 0;

  /**
  * Defines the parameters corresponding to each point of the initial set of points.
  * @param iParameter
  * The array of the parameter values that correspond on the smoothed curve to
  * each point of the input set.
  */
  virtual void             SetImposedParametrization    (const double               *  iParameter          ) = 0;
  
  virtual void             SetParamType                 (CATFrFSmoothingParamType      iParamType          ,
                                                         const double                  iParamValue         = 0.25) = 0;
  
  virtual void             SetTypeOfDefaultCutting      (     CATFrFCuttingOption      iCuttingType        ) = 0;

  virtual void             SetCuttingOption             (      CATBoolean              iCutting            ,
                                                         const CATLONG32               iNumberOfCuttingPts = 0,
                                                         const double               *  iTabOfKnots         = 0,
                                                         const CATLONG32            *  iTabOfMults         = 0,
                                                         const double               *  iExtrKnots          = 0,
                                                         const CATLONG32            *  iExtrMults          = 0) = 0 ;

  virtual void             SetCuttingOption             (      CATBoolean              iCutting            ,
                                                               CATListOfInt          & iList               ,
                                                               CATBoolean              iOptionByCurvatureAnalysis = FALSE) = 0 ;

  virtual void             SetCuttingOption             (const CATNurbsCurve        *  iCurve              ,
                                                         const int                     iOrien              = 1    ) = 0 ;

  virtual void             CuttingUntilReachTolerance   (      CATBoolean              iRespectTolerance   = FALSE) = 0 ;

  virtual void             SetForceIteration            (      CATBoolean              iIterate_OnDegreeAndArcs = TRUE) = 0 ;

  /**
  * Defines the Tolerance of the resulting curve.
  * @param iTol3d
  * The Tolerance value.
  */
  virtual void             SetTolerance3D               (const double                  iTol3d              ,
                                                               CATFrFTestOfConvergence iTest               = CATFrFTestByAverageDeviation) = 0;
  
  /**
  * Defines the Tolerance of the resulting curve.
  * @param iTol3d
  * The Tolerance value.
  */
  virtual void             SetTolerance2D               (const double                  iTol2d              ,
                                                               CATFrFTestOfConvergence iTest               = CATFrFTestByAverageDeviation) = 0;
  
  /**
  * Defines the Tolerance of the resulting curve.
  * @param iTol3d
  * The Tolerance value.
  */
  virtual void             SetNumberOfIterations        (const int                     iIterations         ) = 0;
  

  virtual void             SetClosure                   (const int                     iRankCurve          ,
                                                               CATBoolean              IsClosedG2          ) = 0 ;


  /**
  * @nodoc ============ cette fonction est Non Active =============================
  */

//  virtual void             AddForm (CATMathSetOfPointsND * iPts)=0;

  /**
  * Defines a new set of points to be taken into account (<tt>ADVANCED</tt> mode).
  * @param iPts
  * The pointer to the new set of points. 
  */
  
  virtual void             UpdateForm                   (const int                     iRank               ,
                                                               CATMathSetOfPointsND *  iPts                ,
                                                               CATFrFContinuity     *  Continuities        = 0,
                                                               CATMathVector        *  FirstDerivatives    = 0,
                                                               CATMathVector        *  SecondDerivatives   = 0) = 0;

  /**
  * Returns the created smoothed curve.
  * @return
  * The pointer to the created smoothed curve. If you do not want to keep it, use
  * the @href CATICGMContainer#Remove method.
  */
  virtual CATCurve       * GetCrvResult                 (const int                     iRank                ) = 0;

  virtual CATFrFNurbsMultiForm * GetDefaultMult         (const int                     iRank                ) = 0;

  /**
  * Returns the maximum deviation between a point and the smoothed curve.
  * @return
  * The maximum deviation value.
  */
  
  // ON REND ERREUR MOYENNE   A VOIR ....
  virtual double           GetMaxDeviation              ()                                                    = 0;
  virtual double           GetAverageDeviation          ()                                                    = 0;
  virtual int              GetIndexMaxDeviation         ()                                                    = 0;

  virtual void             GetParametrization           (      double               *& ioParameter          ) = 0; 
  

  // iOption = 0 --> Lissage V5
  // iOption = 1 --> Lissage BeamFE
  virtual void             SetDebugOption               (const int                     iMaxArcs             ,
                                                         const int                     iOption              = 0) = 0;

};

//====================================================================
// Rank -> 1 to N
ExportedByCATFrFSmoothing 
CATFrFMultiSmoothing    * CATFrFCreateMultiSmoothing (      CATGeoFactory            * iFactory    ,
                                                            CATSoftwareConfiguration * iConfig     ,
                                                      const int                        iNbCrv3d    ,
                                                      const int                        iNbCrv2d    ,
                                                      CATMathSetOfPointsND          ** iPoints     ,
                                                      const int                        iFirstPoint = -1,
                                                      const int                        iLastPoint  = -1,
                                                      CATFrFSmoothingParamType         iParamType  = CATFrFSmoothingParamChordal,
                                                      const int                        iDegree     = 5,
//  NLD040418 suppression                             const double                     iTol        = 0.1, // N.B XScaleKO
                                                      const int                        iIterations = 50
                                                     );

#endif


