//====================================================================
// Copyright Dassault Systemes Provence 2010-2021, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
// Fev   2021  : ANR : Ajout Option Subdiv basique pour donnees massives(projet avec la recherche sur les fibres)
// Mars 2018   : ANR : Creation : From CATBtoSmoothingOper 
//                       with CGMReplay and Journal and new Options for SFE...
// 09/04/2018  : NLD : XScale: suppression des valeurs par d�faut non compatibles XScale
//                       aux m�thodes SetTolerance() et FindCanonicalPrimitives()
//====================================================================

#ifndef CATBtoSmoothingOperAdv_H
#define CATBtoSmoothingOperAdv_H
 

#include "CATBtoSmoothing.h"
#include "CATString.h"
#include "CATTopOperator.h"
#include "CATFreeFormDef.h"
#include "CATFrFSmoothingOper.h"
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATTopData;
class CATMathSetOfPointsND;
class CATMathVector;
class CATCldScan;
class CATBody;

/**
 * Class defining a geometric operator that smooth a set of points to create a Bezier, B-spline or CCV  result.
 * <br>The CATBtoSmoothingOperAdv operator follows the global frame of the geometric operators: 
 *<ul>
 * <li>A CATBtoSmoothingOperAdv operator is created with the <tt>CATCbtCreateWireSmoothing</tt> global method 
 * and must be directly <tt>delete</tt>d with the usual C++ delete operator after use.
 * It is is not streamable. 
 *<li>Options can be precised with the <tt>SetXxx</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>In both cases, the result is accessed with the <tt>Getxxx</tt> methods. 
 *</ul>
 */

class ExportedByCATBtoSmoothing CATBtoSmoothingOperAdv: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATBtoSmoothingOperAdv);
public :
  
  virtual ~CATBtoSmoothingOperAdv (); 

  /**
  * Runs <tt>this</tt> operator .
  */ 
  virtual int Run() = 0;
 
  /**
  * Propose some Topological PassPoint constraints. Each point of the list becomes an Extremity of curve in the SetOfCurves result.
  * For each point, if "OK for you" ---> call SetTopConstraint(oAutoTopList[i], ...)
  * We propose also estimate of first end second derivatives 
  * 
  */
   virtual void ComputeAutoTopConstr(CATListOfInt   & oAutoTopList   ,
                                     CATMathVector *& oTangentVect   ,
                                     CATMathVector *& oCurvatureVect ,
                                     double        *& oCurvatureValue) = 0; 

   // for decomposition
   virtual void ComputeAutoTopConstr(double iCuttingAngle, CATListOfInt & oAutoTopList) = 0;

  /**
  * Defines the Topological PassPoint constraint corresponding to each internal point of the initial set of points.
  * The point iPoints[iRankPoint-1] is an Extremity of curve in the SetOfCurves result.
  * Size of SetOfCurves increase by one.
  * The final size of SetOfCurves is equal to Number of Internal Topological PassPoint Constraint + 1 .
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 < iRankPoint < iNbrePts
  * @param iContinuity
  *  iContinuity = CATFrFNoCont        -> Reset Geometrical constraint,
  *  iContinuity = CATFrFPointCont     -> SetOfCurves is G0 at this point,
  *  iContinuity = CATFrFTangentCont   -> SetOfCurves is G1 at this point,
  *  iContinuity = CATFrFCurvatureCont -> SetOfCurves is G2 at this point.
  * @param iTangentVect
  * The Tangency vector (normalized) corresponding to each point of the initial set of points.
  * (if 0, a default value is computed)
  * @param iratio
  * parameter to increase or decrease the norm of tangency vector (which is computed automatically)
  * @param iCurvatureVect
  * The Normal vector (normalized) corresponding to each point of the initial set of points.
  * (if 0, a default value is computed)
  * @param iCurvatureValue
  * Imposed curvature value at the iRankPoint point 
  */
  virtual void SetTopConstraint (const int               iRankPoint      ,
                                       CATFrFContinuity  iContinuity     = CATFrFPointCont,
                                       CATMathVector   * iTangentVect    = 0,
                                       double            iRatio          = 1.,
                                       CATMathVector   * iCurvatureVect  = 0,
                                 const double            iCurvatureValue = 0.0) = 0;

  /**
  * Reset the Topological constraint corresponding to each point of the initial set of points.
  * The point iPoints[iRankPoint-1] is not a limitCurve in the result SetOfCurves.
  * Size of SetOfCurves decrease by one.
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 < iRankPoint < iNbrePts
  */

  virtual void ResetTopConstraint (const int iRankPoint) = 0;


  /**
  * Defines the PassPoint constraint corresponding to each point of the initial set of points.
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  * @param iContinuity
  *  iContinuity = CATFrFNoCont        -> Reset constraint,
  *  iContinuity = CATFrFPointCont     -> PassPoint constraint,
  *  iContinuity = CATFrFTangentCont   -> tangency constraint
  *  iContinuity = CATFrFCurvatureCont -> curvature constraint
  * @param iTangVect
  * The Tangency vector (normalized) corresponding to each point of the initial set of points.
  * (if 0, a default value is computed)
  * @param iratio
  * parameter to increase or decrease the norm of tangency vector (which is computed automatically)
  */

  virtual void SetConstraint (const int               iRankPoint  ,
                                    CATFrFContinuity  iContinuity = CATFrFPointCont,
                                    CATMathVector   * iTangVect   = 0,
                                    double            iratio      = 1.0) = 0;

  /**
  * Reset the constraint corresponding to each point of the initial set of points.
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  */

  virtual void ResetConstraint (const int iRankPoint) = 0; 


  /**
  * Defaults Options for parametrisation of set of points.
  * @param iParamType
  * The type of parametrization. Examples :
  *                     CATFrFSmoothingParamUniform = 0
  *                     CATFrFSmoothingParamChordal = 1
  */
  virtual void SetParamType (CATFrFSmoothingParamType iParamType = CATFrFSmoothingParamChordal) = 0;

  /**
  * Defines the degree of the resulting curve.
  * @param iDegree
  * The degree value for each curve .
  */
  virtual void SetDegree    (const int iDegree = 5) = 0;
  
  /**
  * Defines the Maxdegree of the resulting curve.
  * @param iDegree
  * The Max degree value for each curve .
  */
  virtual void SetMaxDegree (const int iDegree = 5) = 0;

 
  /**
  * Defines the parameters corresponding to each point of the initial set of points.
  * @param iNbreOfPts
  * Number of initial set of points.
  * @param iParameters
  * The array of the parameter values that correspond on the smoothed curve to
  * each point of the input set.
  */
  virtual void SetParametrization(int iNbreOfPts, double *iParameters)=0; 

  /**
  * Defines List of Parametric Cutting points corresponding to list of points of the initial set of points.
  * The point iListOfPoints[index] is an Arc limit in the result SetOfCurves .
  * @param iListOfPoints
  * List of Parametric Cutting points,  1 < iListOfPoints[index] < iNbrePts
  * @param iWithImposedPoint
  * if (TRUE) each cutting point is imposed by passpoint constraint; else No Constraint.
  */
  virtual void ImposedCuttingPoints (CATListOfInt &iListOfPoints, CATBoolean iWithImposedPoint=FALSE) = 0;

  
  /**
  * Defines the maximum number of arcs of the created curve.
  * @param iMaxNumberOfArcs
  * The maximum number of arcs of each created curve
  * @param iInternalContinuity
  * The Internal continuity of each created curve, iInternalContinuity = 2, 3, 4.
  */
  virtual void SetMaxNumberOfArcs (int iMaxNumberOfArcs    = 64,
                                   int iInternalContinuity = 3) = 0;

  /**
  * Set option if we need symmetry in default cutting points
  * Incompatible with SetCuttingOption(CATLONG32 iNumberOfCuttingPts, double * iTabOfKnots, CATLONG32 * iTabOfMults);
  * activate if default cutting
  */
  virtual void NeedMaximumSymmetryInCuttingPoints() = 0;

  /**
  * Defines automatically the maximum number of arcs of the created curve.
  * @param iRespectTolerance
  * if (TRUE), we imposed automatically cutting points until that tolerance is reached.
  */
  virtual void CuttingUntilReachTolerance(CATBoolean iRespectTolerance=TRUE) = 0 ;


  /**
  * Compute automatically the number of Arcs by CurvatureAnalysis.
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
  virtual void SetCuttingByCurvatureAnalysis (const double                   iCurvatureVariationThreshold = 5.0,
                                              const double                   iCurvatureRatio              = 0.5,
                                                    CATFrFInflexionTreatment iCase                        = CATFrFSurroundingInflexion,
                                                    CATBoolean               iWithImposedPoint            = FALSE) = 0;

  /**
  * Defines CuttingDefault Option.
  * @param iCuttingType
  * The type of Cutting Option :
  *                     CATFrFCuttingAutoLength  = 1
  *                     CATFrFCuttingAutoAreaCurvatr = 2
  *                     CATFrFCuttingAutoLengthCurvatr = 3
  */
  virtual void SetCuttingDefault(CATFrFCuttingOption iCuttingType) = 0;

  /**
  * Defines the Tolerance of the result. 
  * @param iTol3d
  * The maximum distance between the input points and the SetOfCurves.
  * @param iTest
  *    iTest = CATFrFTestByAverageDeviation : Average Deviation is satisfied
  *    iTest = CATFrFTestByMaxDeviation     : Max Deviation is satisfied
  */
  virtual void SetTolerance (const double                  iTol3d  ,  // NLD060418= 0.001, // @NumValidated
                                   CATFrFTestOfConvergence iTest      // NLD060418= CATFrFTestByAverageDeviation
                            )                                 = 0;
  
  /**
  * Defines the number of iterations necessary to obtain the best resulting curve.
  * Each iteration gives a different result.
  * @param iIterations
  * The Iteration value for each curve.
  */
  virtual void SetSlideIterations (const int iIterations = 5) = 0;

  // for subdiv mode
  virtual void SetNumberOfSubdivIterations(const int iMaxIterations = 5) = 0 ;


  /**
  * Option for Reverse Use
  */
  virtual void SetModeReverse(CATBoolean iMode = FALSE)  = 0 ;
    
  /**
  * Option for Body_PH : Civil
  */
  virtual void SetParamsForBody_PH(CATBoolean iIsoTopo      = TRUE,
                                   double     iMinEdge      = 0.,
                                   double     iCuttingAngle = 60.) = 0;

  /**
  * Options for SFE and can be useful in general (limited for Line and circle...)
  */
  virtual void FindCanonicalPrimitives(double iTol  ,  // NLD060418 = 0.05,
                                       double iRmin ,  // NLD060418 = 1.  ,
                                       double iRmax ) = 0; // NLD060418 = 100.) = 0;

  // ===========================================================================================
  //
  // ***************************** Les Fonctions Get ***************************** 
  //
  // ===========================================================================================

  /**
  * Returns the SetOfCurves Result. 
  * @return
  * oNbreOfCurve : The Number of curves of the Result 
  * @return
  * Array of oNbreOfCurve curves result according to SetTopConstraint option
  */

  virtual CATBody *GetResult () = 0 ;
 
  /**
  * Returns the maximum deviation between set of points and the SetOfCurves Result. 
  * @return
  * The maximum deviation value.
  * @return
  * Index of point with max deviation.
  */
  virtual int GetIndexMaxDeviation (double &oMaxdeviation) = 0;

  /**
  * Returns the deviation at each point of the initial set of points. 
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  * @return
  * The deviation at each point.
  */
  virtual double GetDeviation (const int iRankPoint) = 0;

  /**
  * Returns the Average deviation between set of points and the SetOfCurves Result. 
  * @return
  * The Mean deviation value.
  */
  virtual double GetAverageDeviation () = 0;
 
  /**
  * Returns the point constraint corresponding to each point of the initial set of points.
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  * @return
  * the Point at the current point,  1 <= iRankPoint <= iNbrePts.
  */
  virtual void GetPointOnResult(const int  iRankPoint, CATMathPoint& oPoint) = 0;

  /**
  * Returns the tangency constraint corresponding to each point of the initial set of points.
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  * @return
  * the tangent vector at the current point,  1 <= iRankPoint <= iNbrePts.
  */
  virtual void GetTangentVect (const int             iRankPoint  ,
                                     CATMathVector & oTangentVect) = 0 ;
  
  /**
  * Returns the curvature constraint corresponding to each point of the initial set of points.
  * @param iRankPoint
  * The Rank of the point in iPoints,  1 <= iRankPoint <= iNbrePts
  * @return
  * the curvature value and Normal vector at the current point,  1 <= iRankPoint <= iNbrePts.
  */
  virtual void GetCurvatureVect (const int             iRankPoint,
                                       double        & oCvt      ,
                                       CATMathVector & oNormale  ) = 0 ;

  /**
  * Returns The parametrization .
  * @return
  * The array of the parameter values that correspond on the SetOfCurves to
  * each point of the input set.
  */
  virtual void GetParametrization(int &oNbreOfPts, double *& oParameters)=0; 


  /**
  * Returns List of indexes corresponding to Vertex of the SetOfCurves result
  */
  virtual void GetGeometricCuttingpoints(CATListOfInt &oGeomList) = 0; 

  /**
  * Returns List of indexes corresponding to internal Arc limit of the SetOfCurves result ( One curve )
  * used the next get
  */
  virtual void GetParametricCuttingpoints(CATListOfInt &oParamList) = 0; 

  /**
  * Returns List of indexes corresponding to internal Arc limit of the SetOfCurves result ( Imposed some TopConstraints )
  */
  virtual void GetParametricCuttingpoints(int iNumCurve, CATListOfInt &oParamList) = 0;
   

  //---------------------------------------------------------------------------------------------
  // CGMReplays Methods
  //---------------------------------------------------------------------------------------------

  /* @nocgmitf */
  static const CATString* GetDefaultOperatorId() { return &_OperatorId; }
  /* @nocgmitf */
  const CATString* GetOperatorId() { return &_OperatorId; }

  /* @nocgmitf */
  virtual CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream) = 0;

  // Input
  /* @nocgmitf */
  virtual CATCGMOperator::CATCheckDiagnostic CheckInput(CATCGMOutput & os) = 0;
  /* @nocgmitf */
  virtual void WriteInput(CATCGMStream &os) = 0;
  /* @nocgmitf */
  virtual void RequireDefinitionOfInputAndOutputObjects() = 0;
  /* @nocgmitf */
  virtual void Dump(CATCGMOutput& os) = 0;
  /* @nocgmitf */
  virtual void WriteOutput(CATCGMStream & ioStream) = 0;
  /* @nocgmitf */
  virtual void DumpOutput(CATCGMOutput &os) = 0; // c'est le dum apres run 

protected :  
 /** 
  * Virtual constructor. Cannot be used.
  */ 

  CATBtoSmoothingOperAdv(CATGeoFactory * iFactory, CATTopData* iTopData);


  //-------- Data :
  static CATString _OperatorId;

};

/**
* Creates the operator that smoothes a set of points to create a Set of curves.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iTopData
* The pointer to TopData containing configuration And Journal defining the level of code to replay.
* @param iPoints
* The pointer to the set of points (Its dimension=3).
* @param iSubdivMode
* Warning :particular development - If the subdiv mode is activated only the getResult is accessible. The other Gets are not yet implemented
* @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
* @see CATFrFSmoothingOper
*/

ExportedByCATBtoSmoothing 
CATBtoSmoothingOperAdv * CATBtoCreateSmoothingOperAdv (CATGeoFactory         * iFactory, 
                                                       CATTopData            * iTopData,
                                                       CATMathSetOfPointsND  * iPoints,
                                                       CATBoolean iSubdivMode = FALSE);

/**
* Creates the operator that smoothes a set of points to create a Set of curves.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iTopData
* The pointer to TopData containing configuration And Journal defining the level of code to replay.
* @param iScan
* The pointer to the CATCldScan corresponding to an ordered set of points (Its dimension=3). 
* @param iSubdivMode
* Warning :particular development - If the subdiv mode is activated only the getResult is accessible. The other Gets are not yet implemented
* @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
* @see CATFrFSmoothingOper
*/

ExportedByCATBtoSmoothing 
CATBtoSmoothingOperAdv * CATBtoCreateSmoothingOperAdv (CATGeoFactory * iFactory, 
                                                       CATTopData    * iTopData,
                                                       CATCldScan    * iScan,
                                                       CATBoolean iSubdivMode = FALSE);

/**
* Creates the operator that smoothes a BodyPH to create a Set of curves.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iTopData
* The pointer to TopData containing configuration And Journal defining the level of code to replay.
* @param iBody
* The pointer to the iBody corresponding to BodyPH (if Classic Body, return???).
* @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
* @see CATFrFSmoothingOper
*/

ExportedByCATBtoSmoothing
CATBtoSmoothingOperAdv * CATBtoCreateSmoothingOperAdv(CATGeoFactory * iFactory,
                                                      CATTopData    * iTopData,
                                                      CATBody       * iBody);
#endif


