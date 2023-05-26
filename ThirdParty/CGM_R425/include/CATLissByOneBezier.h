
//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
// 26/05/16 : ANR : Correction de IR-434122-V5-6R2015
//  Avril 2003 : anr : Creation 
//====================================================================

#ifndef CATLissByOneBezier_H
#define CATLissByOneBezier_H


#include "MathCascade.h"
#include "CATCreateLissByOneBezier.h"
#include "CATMathSetOfPointsND.h"
#include "CATCGMVirtual.h"
#include "CATMathVector.h"
#include "CATSoftwareConfiguration.h"

// ==================================================================
//
//                    // iRank commence a 1
//
// ==================================================================

class ExportedByMathCascade CATLissByOneBezier : public CATCGMVirtual 
{

public :
	
  virtual ~CATLissByOneBezier(); 
	 
  virtual void Run()=0;

   // Pour le Versionning
  virtual void SetConfig (CATSoftwareConfiguration *iConfig) = 0;
  virtual void SetCleanCuttingPts(CATBoolean iCleanMode) = 0 ;
	
	virtual void SetDegree(CATLONG32 iDegree)=0;
	
  virtual void SetMaxDegree(CATLONG32 iDegree)=0;

  virtual void SetMaxArcs(CATLONG32 iMaxArcs)=0;
  
  // la taille _NumbreOfPts de iParameter doit etre  = _LastPoint - _FirstPoint + 1 ; 
	virtual void SetImposedParametrization(double *iParameter)=0; 
	
  //iTypeOfTestOfConvergence = 0 ; par erreur moyenne ;
  //iTypeOfTestOfConvergence = 1 ; par erreur max ;
	virtual void SetTolerance3D(double iTol3d, int iTestOfConvergence = 0)=0;
	
	virtual void SetTolerance2D(double iTol2d, int iTestOfConvergence = 0)=0;
	
	virtual void SetNumberOfIterations(CATLONG32 iIter)=0;
	
  virtual void SetImposedFirstDerivatives(CATMathVector **iVec) = 0 ;

  virtual void SetImposedSecondDerivatives(CATMathVector **iVec) = 0 ;

  // iRankPoint par rapport au donnees initiales ( Tableau Total des points ....)
  virtual void ResetPointConstraint   (const int iRankCurve, const int iRankPoint) = 0;

  virtual void SetPointConstraint     (const int iRankCurve, const int iRankPoint) = 0;

  virtual void SetTangentConstraint   (const int iRankCurve, const int iRankPoint, CATMathVector &iTangentVect, double iratio=1.0) = 0;

  virtual void SetCurvatureConstraint (const int iRankCurve, const int iRankPoint, CATMathVector &iCurvatureVect) = 0;

  virtual void SetTangentConstraintWithoutPoint  (const int iRankCurve, const int iRankPoint, CATMathVector &iTangentVect, double iratio=1.0) = 0;

  virtual void SetLimits(int iFirst, int iLast) = 0 ;

  virtual void SetCuttingOption(CATLONG32 iNumberOfCuttingPts, double *iTabOfKnots, CATLONG32 *iTabOfMults) = 0 ;

  virtual void SetCuttingDefault(CATLONG32 iTypeOfCutting, CATLONG32 iNumberOfCuttingPts) = 0 ;

  virtual void SetOptionByAnalysisCurvature(CATBoolean iOption = FALSE) = 0 ;

  virtual void SetForceIteration(CATBoolean iIterate_OnDegreeAndArcs = TRUE) = 0 ;

  virtual void WithGeometricConstraints(double lambda1=1.0, double lambda2=1.0) = 0 ;

  virtual void WithImposedCtrPoints(CATBoolean iStart = FALSE, CATBoolean iEnd = FALSE) = 0 ;

  virtual void ResetListOfCuttingPts() = 0 ;

	// ============ cette fonction est Non Active =========================================
	
	virtual void AddForm(CATMathSetOfPointsND *iPts, 
						           CATLONG32 *iConstraints)=0;
	
	virtual void UpdateForm(CATLONG32 iRank, CATMathSetOfPointsND *iPts, CATLONG32 *iConstraints = 0)=0;

	// ====================================================================================
    //C'est a l'appelant de detruire oPoles
	virtual void GetResults(CATLONG32 iRank, 
                          CATLONG32 &oDimension, CATLONG32 &oDegree, 
                          CATLONG32 &oNbPoles,   double *&oPoles,
                          CATLONG32 &oNbKnots,   double *&oKnots, CATLONG32 *&oMult)= 0;

	// ON REND ERREUR MOYENNE   A VOIR ....
	virtual double   GetMaxDeviation()=0;
	
  virtual double   GetAverageDeviation()=0;

	virtual CATLONG32     GetIndexMaxDeviation()=0;

  virtual void GetParametrization(double *& ioParameter)=0; 
	
};
#endif


