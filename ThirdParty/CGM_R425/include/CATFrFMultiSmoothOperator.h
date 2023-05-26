//====================================================================
// Copyright Dassault Systemes Provence 2021, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
// Juillet/Sept 2021 : ANR : Creation (pour SRT sur les fibres massive data) 
//====================================================================

#ifndef CATFrFMultiSmoothOperator_H
#define CATFrFMultiSmoothOperator_H

#include "CATFrFSmoothing.h"
#include "CATCGMVirtual.h"

#include "CATFreeFormDef.h"
#include "CATFrFSmoothingDef.h"  
#include "CATMathSetOfPointsND.h"

#include "CATGetTolerance.h"
#include "CATTolerance.h"

#include "CATSoftwareConfiguration.h"   

//-----------------------------------------------------------------------------
class ExportedByCATFrFSmoothing CATFrFMultiSmoothOperator : public CATCGMVirtual
{   
  CATCGMVirtualDeclareClass(CATFrFMultiSmoothOperator);
public:
   
  virtual ~CATFrFMultiSmoothOperator();

  //
  virtual void SetDegree(int iDegree=3) = 0;

  /**
  * Defines the Tolerance of the resulting curve.
  * @param iRankCurve
  * The Rank of the curve ( in case of Multicurve ), 1 <= iRankCurve <= iNbreCrv
  * @param iTol3d
  * The Tolerance value for each curve.
  */
  virtual void SetTolerance(double iTolerance) = 0;

  //
  virtual void SetNumberOfSubdivIterations(int iIter=5) = 0;


  //
  virtual void SetMaxNumberOfArcs(int iMaxNumberOfArcs = 64, int iInternalContinuity = 2) = 0;

  //
  virtual int Run() = 0;


  //
  virtual void GetResult(CATMathSetOfPointsND **& oresultCtrlPts) = 0; 

};

/**
* Creates the operator that smoothes a set of points to create a Set of curves.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iConfig
* The pointer to configuration defining the level of code to replay.
* @param iPoints
* The pointer to the set of points (Its dimension=3).
* @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
* @see CATFrFSmoothingOper
*/

ExportedByCATFrFSmoothing
CATFrFMultiSmoothOperator* CATFrFCreateFMultiSmoothingOper(CATSoftwareConfiguration* iConfig, 
                                                           const CATTolerance* ipTolObject, 
                                                            int iNb_scans_to_smooth,
                                                           CATMathSetOfPointsND** itab_of_scans);

#endif
