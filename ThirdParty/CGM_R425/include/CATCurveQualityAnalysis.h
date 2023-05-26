
//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
//
/**
 * Class defining a geometric operator that compute differents criteria 
 * for Curve fairness analysis.
 *
**/
//==========================================================================
// 23/06/03  : RNO : Ajout NbInflexions
// 17/06/03  : RNO : Modification du nom des methodes
//                    + Ajout Nvlles Methodes
// 19/05/03  : AVC :  Creation                       
//==========================================================================
#ifndef CATCurveQualityAnalysis_H
#define CATCurveQualityAnalysis_H

#include "CATCGMVirtual.h"
#include "FrFAdvancedOpeCrv.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATCrvLimits.h"
#include "CATFrFCompositeCurve.h"
class CATSoftwareConfiguration;

//----------------------------------------------------------------------
class  ExportedByFrFAdvancedOpeCrv CATCurveQualityAnalysis : public CATCGMVirtual
 
{
public:
  virtual ~CATCurveQualityAnalysis() {};
  
  // Run Operator.
  // return 0 if OK ; !=0 else
  virtual int Run()=0;

  // GetCurveLength : Return the computed Length of the Curve.
  // return 0 if OK ; !=0 else
  virtual int GetTotalCCVLength(double & oCrvLength)=0;  

  //To get the number of Curve Smaller than this tol (default 10-2)
  virtual int SetSmallCrvLength(double iSmallLength)=0;

  //To get the number of Arc Smaller than this tol (default 10-3)
  virtual int SetMicroArcLength(double iMicroArcLength)=0;

  // GetNumberOfEdges : Return the number of element (curves) in the CCV
  // return 0 if OK ; !=0 else
  virtual int GetNumberOfCrv(int & oNbEdges)=0;

  // GetNumberOfEdges : Return the number of curves in the CCV that are smaller than iSmallLength
  // return 0 if OK ; !=0 else
  virtual int GetNumberOfSmallCrv(int & oNbSmallCrv)=0;


  // GetNumberOfArcs : Return the total number of arcs in the CCV
  // return 0 if OK ; !=0 else
  virtual int GetNumberOfArcs(int & oNbArcs) =0;


  // GetNumberOfArcs : Return the total number of arcs in the CCV that are smaller than iMicroArcLength
  // return 0 if OK ; !=0 else
  virtual int GetNumberOfMicroArcs(int & oNbMicroArcs) =0;


  // GetMinArcLength : Return the computed minimum arc length in the CCV
  // return 0 if OK ; !=0 else
  virtual int GetMinArcLength(double & oMinArcLength)=0;

  // GetMaxArcLength : Return the computed maximum arc length in the CCV
  // return 0 if OK ; !=0 else
  virtual int GetMaxArcLength(double & oMinCrvLength) =0;

  // GetConditionnementArc : Return the computed (maximum arc length)/(minimum arc length)  in the CCV
  // return 0 if OK ; !=0 else
  virtual int GetConditionnementArc(double & oMinCrvLength) =0;

  // GetMeanArcLength : Return the computed mean arc length in the CCV
  // return 0 if OK ; !=0 else
  virtual int GetMeanArcLength(double & oMinCrvLength) =0;

  //Give the Min and Max Average parametric speed (ie (EndParam-StartParam)/Length) in the CCV 
  // return 0 if OK ; !=0 else
  virtual int GetMinMaxParamSpeed(double & oMinSpeed,double & oMaxSpeed)=0;

  // GetStdDevArc : Return the computed Standard Deviation of Arcs in the CCV
  // return 0 if OK ; !=0 else
  virtual int GetStdDevArc(double & oMinCrvLength) =0;

  // GetMinCrvLength : Return the computes min length of curve.
  // return 0 if OK ; !=0 else
  virtual int GetMinCrvLength(double & oMinEdgeLength)=0;
  
  // GetMinMaxCurvature : Return the computed min and max Curvature.
  // return 0 if OK ; !=0 else
  virtual int GetMinMaxCurvature(double & oMinCurvature, double & oMaxCurvature)=0;

  // An Inflexions is added when after discretizations of CCV 
  // we have Curvature(x)*Curvature(x+dx)<-CATEpsg ...
  // ....
  virtual int GetNbInflexions(int &oNbInflexions)=0;
};

//==================================================================
//Create Functions
ExportedByFrFAdvancedOpeCrv 
CATCurveQualityAnalysis* CATCreateCurveQualityAnalysis (CATSoftwareConfiguration * iSoftConfig,
                                                        CATGeoFactory * Factory,
                                                        CATLISTP(CATCurve)       * iListOfCurve,
                                                        CATLISTP(CATCrvLimits)   * iListOfLimits,
                                                        CATListOfInt             * iListOfOrientations);

ExportedByFrFAdvancedOpeCrv
CATCurveQualityAnalysis* CATCreateCurveQualityAnalysis(CATSoftwareConfiguration * iSoftConfig,
                                                        CATGeoFactory * Factory,
                                                       CATCurve * iCurve, const CATCrvLimits & iLimits);
ExportedByFrFAdvancedOpeCrv
CATCurveQualityAnalysis* CATCreateCurveQualityAnalysis(CATSoftwareConfiguration * iSoftConfig,
                                                        CATGeoFactory * Factory,
                                                        CATFrFCompositeCurve     * iCCV);
#endif

