/**
* @quickReview ANR 19:10:07
* @fullreview ANR anr 19:10:07
*/
// --------------------------------------------------------
//====================================================================
// Copyright Dassault Systemes Provence 2010-2019, all rights reserved 
//==================================================================== 
//
// Usage notes:
//
//====================================================================
//  Nov   2020  : anr : NeedMaximumSymmetryInCuttingPoints()
//                      _NeedMaximumSymmetryInCuttingPoints
//  Oct   2019  : ANR : Correction Bug sur detection Primitive
//  26/04/2019  : anr : Ajout _LevelOfImproveQualityInClosedCases
//  17/07/2018  : NLD : XScale suppression des valeurs par défaut des arguments de FindPrimitives()
//  28/06/2018  : NLD : Ajout RunComputeListOfParamCutting()
//                      Ajout RunClearPrevious()
//                      _NbOfMultiForms remplace _NbOfMutiforms (sans l et sans majuscule)
//  22/06/2018  : anr : Ajout _NewListOfParamCutting
//                      Ajout deuxieme signature de GetParametricCuttingpoints() avec iNumCurve
//  19/06/2018  : NLD : Ajout RunPrepareCutting()
//                      Ajout Run2Points()
//                      Ajout UseRunReduceMultiForm()
//                      Suppression definitive du code inactif avec SetCoverageTest() et _ForceCoverage
//  18/06/2018  : NLD : Ajout CATFrFSmoothingOperDebug
//                      Ajout RunFindPrimitives()
//  12/06/2018  : NLD : Retroingénierie de RunOld() pour mise en conformité avec nouveau Run, avant factorisation
//                     - mise en conformité de l'interface de RunOld() avec celui de RunWithVersionning()
//                     - ajout RunImposeConstraints()
//                     - ajout RunAndRattrapInterpol()
//  06/06/2018  : NLD : Suppression par flag de precompilation des inutiles pollutions coverage
//    /05/2018  : ANR : Livraison Coverage (CATFrFSmoothingOperCx2::RunOld() en attendant que composite passe sur le nouveau)
//  18/04/2018  : NLD : Ajout _XScaleR28SP2
//                      Reordonnancement logique des données membres
//                      (et regroupement des entrées)
//  17/04/2018  : NLD : Ajout RunInterpol() pour mettre fin à la duplication
//                      RunOld() remplace OldRun()
//  16/04/2018  : NLD : RattrapResult() remplace à iso-code rattrappeResult()
//                      et perd son argument iConfig
//  12/04/2018  : NLD : Smart indent (signatures)
//  04/04/2018  : NLD : Smart indent (données)
//                      Deflaggage
//                      XScale
//                      - Suppression des faux @NumValidated
//                      - Marquages <@NLD030418_XScaleKO>
//                      - Suppression de la valeur par defaut inadequate de iTol3d dans SetTolerance()
//  Mars 2018   : ANR : ajout de FindCanonicalPrimitives--- demande pour SFE
//  26/11/2014  : NLD : RunWithVersionning() rend eventuellement une erreur
//                      Ajout _RmResultCurves
// Avril 2013   : ANR : Ajout GetResult (CATListPtrCATCurve &oResultCurves) pour SolidWorks
//  Mai 2012    : NLD : Ajout Init()
//  Mai 2010    : ANR : Creation
//====================================================================

#ifndef CATFrFSmoothingOperCx2_H
#define CATFrFSmoothingOperCx2_H

#include "CATIACGMLevel.h" // NLD "CATIAV5Level.h"

#include "CATBoolean.h"
#include "CATListOfInt.h"

#include "CATFrFSmoothingOper.h"
#include "CATFreeFormDef.h"
#include "CATFrFSmoothingDef.h" 
#include "CATFrFNurbsMultiForm.h"

#include "CATCGMOperator.h"
#include "CATCGMOperatorDebug.h"

#include "CATGetTolerance.h"
#include "CATTolerance.h"

class CATGeoFactory;
class CATGeoFactoryProtected;
class CATSoftwareConfiguration;
class CATMathSetOfPointsND;
class CATMathVector;
class CATMathPoint;
class CATCldScan;
class CATCurve;
class CATNurbsCurve;
class CATFrFLissByOneBezier;
class CATInterpolPtToNurbsCrv;
class CATFrFSmoothingOperDebug;

/**
 * Class defining a geometric operator that smooth a set of points to create a Bezier, B-spline or CCV  result.
 * <br>The CATFrFSmoothingOperCx2 operator follows the global frame of the geometric operators: 
 *<ul>
 * <li>A CATFrFSmoothingOperCx2 operator is created with the <tt>CATFrFCreateSmoothingOper</tt> global method 
 * and must be directly <tt>delete</tt>d with the usual C++ delete operator after use.
 * It is is not streamable. 
 *<li>Options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>In both cases, the result is accessed with the <tt>Getxxx</tt> methods. 
 *</ul>
 */

class ExportedByCATFrFSmoothing CATFrFSmoothingOperCx2 : public CATFrFSmoothingOper
{
  friend class CATFrFSmoothingOperDebug;
public :
 
  CATFrFSmoothingOperCx2 (CATGeoFactory            * iFactory,
                          CATSoftwareConfiguration * iConfig ,
                          CATMathSetOfPointsND     * iPoints );
 
  CATFrFSmoothingOperCx2 (CATGeoFactory            * iFactory,
                          CATSoftwareConfiguration * iConfig ,
                          CATCldScan               * iScan   );

  ~CATFrFSmoothingOperCx2 (); 


  CATCGMOperatorDebugDeclareRun(CATFrFSmoothingOperCx2,CATFrFSmoothingOper);
  int RunOperator();
 
  /**
  * Defines the PassPoint constraint corresponding to each point of the initial set of points.
  * The point iPoints[iRankPoint-1] is a VERTEX in the result Body .
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  */
  void SetTopConstraint (const int               iRankPoint      ,
                               CATFrFContinuity  iContinuity     = CATFrFPointCont,
                               CATMathVector   * iTangentVect    = 0,
                               double            iRatio          = 1.,
                               CATMathVector   * iCurvatureVect  = 0,
                               const double      iCurvatureValue = 0.0);


  void ResetTopConstraint(const int iRankPoint) ;

  /**
  * Defines the tangency constraint corresponding to each internal point and different from LimitsCurves
  * of the initial set of points.
  * @param iContinuity
  *  iContinuity = CATFrFNoCont        -> Reset constraint,
  *  iContinuity = CATFrFPointCont     -> PassPoint constraint,
  *  iContinuity = CATFrFTangentCont   -> tangency constraint
  *  iContinuity = CATFrFCurvatureCont -> curvature constraint
  * @param iVectFirstDer
  * The array of the tangency vector ( normalized ) that correspond on the smoothed curve to
  * each point of the input set.
  * (if 0, a default value is computed)
  */

  void SetConstraint (const int               iRankPoint  ,
                            CATFrFContinuity  iContinuity = CATFrFPointCont,
                            CATMathVector   * iTangVect   = 0,
                            double            iratio      = 1.0);

   /**
  * Reset the constraint corresponding to each point of the initial set of points.
  * The point iPoints[iRankPoint-1] is not a vertex in the result Body.
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  */

  void ResetConstraint (const int iRankPoint); 


  /**
  * Defaults Options for parametrisation of set of points.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @param iParamType
  * The type of parametrization. Examples :
  *                     CATFrFSmoothingParamUniform = 0
  *                     CATFrFSmoothingParamChordal = 1
  */
  void SetParamType (CATFrFSmoothingParamType iParamType=CATFrFSmoothingParamChordal);

  /**
  * Defines the degree of the resulting curve.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @param iDegree
  * The degree value for each curve .
  */
  void SetDegree (const int iDegree=5);
  
  /**
  * Defines the Maxdegree of the resulting curve.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @param iDegree
  * The Max degree value for each curve .
  */
  void SetMaxDegree (const int iDegree=5);


  /**
  * Defines The parametrization .
  * @return
  * The array of the parameter values that correspond to each point of the input set.
  */
  void SetParametrization(int      iNbreOfPts,
                          double * iParameters); 

  /**
  * We can define Cutting point by some index of Scan ...
  * The point iPoints[iRankPoint-1] is a Arc limit in the result Body .
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  */
  void ImposedCuttingPoints (CATListOfInt & iListOfPoints     ,
                             CATBoolean     iWithImposedPoint = FALSE);

  /**
  * Defines the maximum number of arcs of the created curve.
  * @param iMaxNumberOfArcs
  * The maximum number of arcs of each created curve
  * @param iInternalContinuity
  * The Internal continuity of each created curve, iInternalContinuity = 2, 3, 4.
  */
  void SetMaxNumberOfArcs (int iMaxNumberOfArcs    = 64,
                           int iInternalContinuity =  3);

  /**
  * incompatible with SetCuttingOption();
  * activate if default cutting
  */ 
  void NeedMaximumSymmetryInCuttingPoints();


  // on decoupe jusqu;a ce que la tolerance soit respectee.
  void CuttingUntilReachTolerance(CATBoolean iRespectTolerance = TRUE) ;


  /**
  * Compute automatically the number of Arcs by CurvatureAnalysis .
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @param iCurvatureVariationThreshold
  * Criteria used to decide to insert arc limit is based on a factor of curvature variation 
  * between the beginning and the end of the curve, for example 5.
  * @param iCurvatureRatio
  * The position of the arc limit is computed at best using area repartition criteria. 
  * A parameter defining the ratio between the surfaces is then used to compute this position.
  * @param iCase : CATFrFInflexionTreatment
  * The type of Inflexion Treatment :
  *                     CATFrFNone  = 0
  *                     CATFrFInsertAtInflexion = 1
  *                     CATFrFSurroundingInflexion = 2
  * @param iWithImposedPoint
  * if ( TRUE ) each cutting point computed is imposed by passpoint constraint; else No Constraint
  */
  void SetCuttingByCurvatureAnalysis (const double                   iCurvatureVariationThreshold = 5,
                                      const double                   iCurvatureRatio              = 0.5,
                                            CATFrFInflexionTreatment iCase                        = CATFrFSurroundingInflexion,
                                            CATBoolean               iWithImposedPoint            = FALSE);

  /**
  * Defines the Max number of Arcs of the resulting curve ( In case Of B-spline Result) .
  * @param iMaxNumberOfArcs
  * The max number of arc (cutting points)
  * @param iCuttingType
  * The type of parametrization :
  *                     CATFrFCuttingAutoLength  = 1
  *                     CATFrFCuttingAutoAreaCurvatr = 2
  *                     CATFrFCuttingAutoLengthCurvatr = 3
  */
  void SetCuttingDefault(CATFrFCuttingOption iCuttingType);

  /**
  * Defines the Tolerance of the resulting curve.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @param iTol3d
  * The Tolerance value for each curve.
  * @param iTest
  *    iTest = CATFrFTestByAverageDeviation : Average Deviation is satisfied
  *    iTest = CATFrFTestByMaxDeviation     : Max Deviation is satisfied
  */
  void SetTolerance (const double                  iTol3d ,
                           CATFrFTestOfConvergence iTest  = CATFrFTestByAverageDeviation);
  
  /**
  * Defines the number of iterations necessary to obtain the best resulting curve.
  * Each iteration gives a different result.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @param iIterations
  * The Iteration value for each curve.
  */
  void SetSlideIterations (const int iIterations = 5);

  /**
  * Option for Reverse Use
  */
  void SetModeReverse(CATBoolean iMode = FALSE);

  /**
  * Options for SFE and can be useful in general (limited for Line and circle...)
  */
  void FindCanonicalPrimitives(double iTol  , // = 0.05,   // <@NLD030418_XScaleKO>
                               double iRmin , // = 1.  ,   // <@NLD030418_XScaleKO>
                               double iRmax );//  = 100.);  // <@NLD030418_XScaleKO>



  // ===========================================================================================
  //
  // ***************************** Les Fonctions Get ***************************** 
  //
  // ===========================================================================================

  /**
  * Returns the Number of curves of the Result body .
  * Returns the created smoothed Body.
  * @return
  * Array of oNbreOfBody body result according to iTypeOfOutput option
  *
  */

  int GetResult (CATCurve **& oResultCurves) ;
 
#if defined CATIACGMR215CAA
   /**
  * Returns the set of result curves.
  * @return
  * The list of result curves.
  */
  void GetResult (CATListPtrCATCurve & oResultCurves);
#endif


  /**
  * Returns the maximum deviation between set of points and the smoothed curve.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @return
  * The maximum deviation value.
  */
  int GetIndexMaxDeviation (double & oMaxdeviation);

  /**
  * Returns the maximum deviation between set of points and the smoothed curve.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @return
  * The maximum deviation value.
  */
  double GetDeviation (const int iRankPoint);

  /**
  * Returns the Average deviation between set of points and the smoothed curve.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @return
  * The Mean deviation value.
  */
  double GetAverageDeviation ();
 

  /**
  * Returns the tangency constraint corresponding to each point of the initial set of points.
  * @return
  * the tangent vector at the current point.
  */
  void GetTangentVect (const int             iRankPoint  ,
                             CATMathVector & oTangentVect) ;
  
  /**
  * Returns the curvature constraint corresponding to each point of the initial set of points.
  * @return
  * the Normal vector at the current point.
  */
  void GetCurvatureVect (const int             iRankPoint,
                               double        & oCvt,
                               CATMathVector & oNormale) ;

  /**
  * Returns The parametrization .
  * @return
  * The array of the parameter values that correspond on the smoothed curve to
  * each point of the input set.
  */
  void GetParametrization(int & oNbreOfPts, double *& oParameters); 


  /**
  * Returns List of indexes corresponding to Vertex of the body result
  */
  void GetGeometricCuttingpoints(CATListOfInt & oGeomList); 

  /**
  * Returns List of indexes corresponding to internal Arc limit of the SetOfCurves result ( pas de decoupes topo : erreur de ma part
  * call next GetParametricCuttingpoints
  */
  void GetParametricCuttingpoints(CATListOfInt &oParamList);

  /**
  * Returns List of indexes corresponding to internal Arc limit of the SetOfCurves result ( Imposed some TopConstraints )
  */
  void GetParametricCuttingpoints(int iNumCurve, CATListOfInt &oParamList);
   
private :

  int        RunOld                            (      CATError                 *& oError        );

  int        RunWithVersionning                (      CATError                 *& oError        ) ;

  void       Init                              ();

  void       InitDerivatives                   () ;

  void ComputeCuttingPointsByCurvatureAnalysis (const double                      iCurvatureVariationThreshold,
                                                const double                      iCurvatureRatio,
                                                      CATFrFInflexionTreatment    iCase,
                                                const int                         iMaxNumberOfArcs, 
                                                      CATBoolean                  iWithImposedPoint) ;

  void       ComputeDefaultParameters          () ;

  void       ComputeKnotsAndMultiplicities     (      CATListOfInt              & ioCuttingList,
                                                      int                         iCurrentNbPoints,
                                                      double                   *  iCurrentParameters,
                                                      int                       & oCurrentNumberOfCuttingPts,
                                                      double                   *& oCurrentTabOfKnots,
                                                      CATLONG32                *& oCurrentTabOfMults) ;

  void       GetMultiformSolution              (      CATFrFLissByOneBezier    *  iOperator         ,
                                                      CATFrFNurbsMultiForm     *& oMultiformResult  ) ;

  CATBoolean RattrapResult                     (//    CATSoftwareConfiguration *  iConfig           ,
                                                      CATMathSetOfPointsND     *  ipCurSet          ,
                                                      double                   *  iParamInterpol    ,
                                                      CATMathVector            *  iFirstDerivatives ,
                                                      CATMathVector            *  iSecondDerivatives,
                                                      CATFrFContinuity         *  iConstraints      ,
                                                      CATFrFNurbsMultiForm     *& ioMultiform       ) ;

  // du classique :
  int        ComputeFirstDerivatives           (      CATGeoFactory            *  iFactory              ,
                                                      CATFrFNurbsMultiForm     *  iMultiform            ,
                                                      CATMathVector             & oStartFirstDerivative ,
                                                      CATMathVector             & oStartSecondDerivative,
                                                      CATMathVector             & oEndFirstDerivative   ,
                                                      CATMathVector             & oEndSecondDerivative  ) ;

  void       ComputeNormaleAndCurvature        (      CATMathVector             & iFirstDer           ,
                                                      CATMathVector             & iSecondDer          ,
                                                      double                    & oCurvature          ,
                                                      CATMathVector             & oNormale            ) ;

  void       ComputeDefaultDerivatives         (      int                         iRankPoint          ,
                                                      double                      iparameter          ,
                                                      CATMathVector             & oFirstDerivative    ,
                                                      CATMathVector             & oSecondDerivative   ) ;

  void       ComputePolynomialBezier           (      double                   *  Interv              ,
                                                      CATLONG32                   iStartCond          ,
                                                      CATLONG32                   iEndCond            ,
                                                      CATMathPoint              & iF1                 ,
                                                      CATMathVector             & iDF1                ,
                                                      CATMathVector             & iD2F1               ,
                                                      CATMathPoint              & iF2                 ,
                                                      CATMathVector             & iDF2                ,
                                                      CATMathVector             & iD2F2               ,
                                                      CATFrFNurbsMultiForm     *& oMF                 ) ;

  void       ModifyCurrentCurve                (      CATFrFNurbsMultiForm     *& ioMultiform         ,
                                                      int                         iFirstPoint         ,
                                                      int                         iLastPoint          ,
                                                      CATFrFContinuity            iStartConstraint    ,
                                                      CATFrFContinuity            iEndConstraint      ) ;

  CATBoolean ModifyPoints                      (      int                       & ioCurrentNbPoints   ,
                                                      double                   *& ioCurrentParameters ,
                                                      CATMathSetOfPointsND     *& ioCurSet            ,
                                                      CATFrFContinuity         *& ioCurrentConstraints,
                                                      CATMathVector            *& ioFirstDerivatives  ,
                                                      CATMathVector            *& ioSecondDerivatives ,
                                                      int                       & ioTargetNbPoints    ,
                                                      CATListOfInt              & oTabOldToNew        ,
                                                      CATListOfInt              & oTabNewToOld        ) ;

  void       CallImposedCuttingPoints          (      CATFrFLissByOneBezier    *  iOperator           ,
                                                      int                         iCurrentFirstPoint  ,
                                                      int                         iCurrentLastPoint   ,
                                                const CATListOfInt              & iTabOldToNew        ,
                                                      int                         iCurrentNbPoints    ,
                                                      double                   *  iCurrentParameters  ,
                                                      CATBoolean                  InsertPts           ,
                                                      int                       & ioCurrentNumberOfCuttingPts,
                                                      double                   *& ioCurrentTabOfKnots ,
                                                      CATLONG32                *& ioCurrentTabOfMults ) ;

  CATBoolean IsLinear                          (      int                         iNbOfPoints         ,
                                                      double                   *  iParams             ,
                                                      CATMathSetOfPointsND     *  pCurSet             ,
                                                      CATFrFNurbsMultiForm     *& oMultiformResult    ,
                                                      CATCurve                 *& oLine               );

  CATBoolean IsCircle                          (      int                         iNbOfPoints         ,
                                                      double                   *  iParams             ,
                                                      CATMathSetOfPointsND     *  pCurSet             ,
                                                      CATFrFNurbsMultiForm     *& oMultiformResult    ,
                                                      CATCurve                 *& oCircle             );

  void       CreateLineOrCircle                (      int                         TypeOfCanonic       ,
                                                      CATFrFNurbsMultiForm     *  iMultiform          ,
                                                      CATCurve                 *  iCurveToLimite      ,
                                                      CATMathPoint              & iStartPoint         ,
                                                      CATMathPoint              & iEndPoint           ,
                                                      CATMathPoint              & iRefPoint           ,
                                                      CATCurve                 *& oResultCurve        );

  void       MergeTwoCATLines                  ();
  void       MergeTwoCATCircles                ();

  CATError * RunInterpol                       (      CATInterpolPtToNurbsCrv  *  Interpol             );

  void       RunImposeConstraints              (
                                                      int                         RunNew               ,
                                                      int                         CurrentNbPoints      ,
                                                      int                         CurrentFirstPoint    ,
                                                      int                         CurrentLastPoint     ,
                                                      CATFrFContinuity         *  CurrentConstraints   ,
                                                      CATMathVector            *  TempFirstDerivatives ,
                                                      CATMathVector            *  TempSecondDerivatives,
                                                      int                         InsertPts            ,
                                                const CATListOfInt              & oTabNewToOld         ,
                                                      CATFrFLissByOneBezier    *  Operator             ,
                                                      int                       & ComputeNbOfImposedConstraints);

  int        RunAndRattrapInterpol             (
                                                      int                         RunNew               ,
                                                      int                         CurrentNbPoints      ,
                                                      int                         CurrentFirstPoint    ,
                                                      int                         CurrentLastPoint     ,
                                                      int                         CurrentNumberOfCuttingPts,
                                                      CATFrFContinuity         *  CurrentConstraints   ,
                                                const CATListOfInt              & iTabOldToNew         ,
                                                      CATMathSetOfPointsND     *  pCurSet              ,
                                                      double                   *  iCurrentParameters,
                                                      CATMathVector            *  TempFirstDerivatives ,
                                                      CATMathVector            *  TempSecondDerivatives,
                                                      int                         InsertPts            ,
                                                      int                         SlideCondition       ,
                                                      CATFrFLissByOneBezier    *& Operator             ,
                                                      double                   *& ioCurrentTabOfKnots ,
                                                      CATLONG32                *& ioCurrentTabOfMults,
                                                      CATBoolean                & InterpolIsOK         ,
                                                      CATBoolean                & SmoothOperIsOK       ,
                                                      CATFrFNurbsMultiForm     *& oMF                  ,
                                                      CATError                 *& oError
                                               );

  void       RunFindPrimitives                 (      int                         CurrentNbPoints      ,
                                                      int                         CurrentFirstPoint    ,
                                                      CATMathPoint              & StartPt              ,
                                                      CATMathPoint              & MiddlePt             ,
                                                      CATMathPoint              & EndPt                ,
                                                      int                       & CurveIsACanonical    ,
                                                      CATCurve                 *& CanonicalCurve       ,
                                                      CATFrFNurbsMultiForm     *& FinalMfResult        );

  void       RunPrepareCutting                 ();

  void       Run2Points                        (      int                         RunNew               ,
                                                      int                         CurrentNbPoints      ,
                                                      int                         CurrentFirstPoint    ,
                                                      int                         CurrentLastPoint     ,
                                                      CATMathSetOfPointsND     *  pCurSet              ,
                                                      double                   *  CurrentParameters    ,
                                                      CATMathVector            *  TempFirstDerivatives ,
                                                      CATMathVector            *  TempSecondDerivatives,
                                                      CATFrFNurbsMultiForm     *& FinalMfResult        ,
                                                      CATBoolean                & NoConstraint         );

  void       RunReduceMultiForm                (      int                         ComputeNbOfImposedConstraints,
                                                      CATFrFNurbsMultiForm     *& FinalMfResult        ,
                                                      CATBoolean                & ReduceMultiform      );

  void       RunComputeListOfParamCutting      (      CATFrFNurbsMultiForm     *  FinalMfResult        ,
                                                      int                         CurrentFirstPoint    ,
                                                      int                         CurrentLastPoint     ,
                                                      CATListOfInt             &  ioListOfParamCutting );

  void       RunClearPrevious                  ();

  // Champs prives :

  // Données générales
  CATGeoFactory            * _Factory            ;
  CATGeoFactoryProtected   * _ProtectedFactory   ;
  const CATTolerance       * _pTolObject         ;

  // variables liées au versionning
  int                        _LevelOfCuttingWithMaxArcs,
                             _LevelOfImposedInternalConstr,
                             _LevelOfImproveQualityInClosedCases,
                             _levelOfconstraintscompatibility_v2;
  CATBoolean                 _activate_last_level; //debug en attendant l'activation du versionning
  CATBoolean                 _WithVersionning    ;
  CATSoftwareConfiguration * _Config             ;
  int                        _CGMLevel           ;
  int                        _XScaleR28SP2       ;

  // Données d'entrée
  CATMathSetOfPointsND     * _InputPoints        ;
  CATCldScan               * _InputScan          ;

  // Autres données d'entrée
  CATFrFSmoothingParamType   _ParamType          ;

  // Données déduites des données d'entrée
  int                        _NumberOfPts        ,
                             _FirstPoint         ,
                             _LastPoint          ;
  CATMathPoint             * _TabOfPoints        ;
  CATFrFContinuity         * _ConstraintsPoints  ;
  double                   * _TabOfParameters    ;
  CATBoolean                 _ImposedParameters  ;
  CATMathVector           ** _TangentVect        ,
                          ** _CurvatureVect      ;
  double                   * _TangentRatio       ,
                           * _CurvatureValue     ;
  CATBoolean               * _FixedG2Constr      ; // l'appelant a fixé le vecteur normal ainsi que la courbure

  CATFrFNurbsMultiForm     * _MfInit             ;
  CATNurbsCurve            * _CrvInit            ;


  // Autres données d'entrée
  int                        _Degree             ,
                             _MaxDegree          ;
  CATBoolean                 _FixedDegree        ;

  double                     _TolSmoothing       ;
  CATFrFTestOfConvergence    _ConvergenceTest    ;

  int                        _SlideIteration     ;

  int                        _MaxNumberOfArcs    ,
                             _InternalContinuity ;
  CATBoolean                 _FixedMaxOfArcs     ;
  CATBoolean                 _NeedMaximumSymmetryInCuttingPoints ;

  CATBoolean                 _RvsMode            ;
  CATBoolean                 _WithFindPrimitives ;
  double                     _TolForCanonicDetection;
  double                     _Rmin               ,
                             _Rmax               ;

  CATBoolean                 _ImposedCuttingPoints,
                             _ReachTolerance     ,
                             _CuttingByCurvatureAnalysis;
  CATFrFCuttingOption        _CuttingType        ;

  CATListOfInt               _ListOfParamCutting ,
                             _ListOfGeomCutting  ;

  CATListOfInt             * _NewListOfParamCutting;

  CATListOfInt               _ImposedConstrList  ; //  les points imposes par l'appelant et non en interne par malek dans certains cas.

  // Données de sortie
  int                        _Error              ;

  int                        _NbResultCurves     ;
  CATBoolean                 _RmResultCurves     ;
  CATCurve                ** _ResultCurves       ;

  int                        _NbOfMultiForms     ;
  CATFrFNurbsMultiForm    ** _FinalMfResult      ;

  double                     _Maxdeviation       ,
                             _Meandeviation      ;
  int                        _IndexOfMaxdeviation;
  double                   * _TabOfdeviation     ;


  // CATCGMOperator infrastructure
  public:
    const CATString                        * GetOperatorId           ();
          CATSoftwareConfiguration         * GetSoftwareConfiguration() const;
          void                               Dump                    (CATCGMOutput  & os             );
          CATCGMOperator::CATCheckDiagnostic CheckInput              (CATCGMOutput  & os             );
          void                               WriteInput              (CATCGMStream  & ioStream       );
          void                               DumpOutput              (CATCGMOutput  & os             );
        //CATCGMOperator::CATCheckDiagnostic CheckOutput             (CATCGMOutput  & os             );
          void                               WriteOutput             (CATCGMStream  & ioStream       );
          void                               DumpOutput              (CATCGMStream  & ioStream       ,
                                                                      CATCGMOutput  & os             ,
                                                                      int             VersionNumber  );
          CATBoolean                         ValidateOutput          (CATCGMStream  & ioStream       ,
                                                                      CATCGMOutput  & os             ,
                                                                      int             VersionNumber  );

  protected:
          CATExtCGMReplay                  * IsRecordable            (short         & LevelOfRuntime ,
                                                                      short         & VersionOfStream);


}; 


const CATString *GetCATFrFSmoothingOperCx2OperatorId();


#endif


