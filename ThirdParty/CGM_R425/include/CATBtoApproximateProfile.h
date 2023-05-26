//====================================================================
// Copyright Dassault Systemes Provence 2010-2018, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
// 02/07/2018 : NLD : Eradication des faux @ Num Validated KO XScale dans les interfaces des frameworks topologiques
//  Mars 2018    : ANR : Creation :  
//====================================================================

#ifndef CATBtoApproximateProfile_H
#define CATBtoApproximateProfile_H


#include "CATBtoSmoothing.h"
#include "CATString.h"
#include "CATTopOperator.h" 
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATTopData;
class CATMathSetOfPointsND;
class CATMathVector;
class CATCldScan;
class CATBody;


/**
* Class defining a operator that smooth a set of points to create a decomposition into arcs and segments(and Bezier!).
* <br>The CATBtoApproximateProfile operator follows the global frame of the geometric operators:
*<ul>
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method.
*<li>In both cases, the result is accessed with the <tt>Getxxx</tt> methods.
*</ul>
*/

class ExportedByCATBtoSmoothing CATBtoApproximateProfile : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATBtoApproximateProfile);
public:

  virtual ~CATBtoApproximateProfile();


  /**
  * Defines the maximum number of arcs of the created curve.
  * @param iMaxNumberOfArcs
  * The maximum number of arcs of each created curve
  * @param iInternalContinuity
  * The Internal continuity of each created curve, iInternalContinuity = 2, 3, 4.
  */
  virtual void SetMaxNumberOfArcs(int iMaxNumberOfArcs = 64, int iInternalContinuity = 3) = 0;
   
  /**
  * Defines the Smoothing Tolerance.
  * @param iTol
  * the Smoothing Tolerance ( it is used also for canonical recognition ).
  * @param iRmin, iRmax
  * The minimum and maximum Radius of Circle ( else the result will be a segment de droite or Bezier Curve)
  */
  virtual void SetParams(double iTol,  double iRmin, double iRmax) = 0; 

   /**
  * Defines Support Plane.
  * @param iPlane
  * If we are in 2D, the result will be in 2D (particularly PCircle and PLine). 
  */
  virtual void SetPlane(CATMathPlane *iPlane=NULL)=0;

  //
  virtual void CleanInputs(double iMinEdge = 0., double iCuttingAngle = 45.) = 0;

  /**
  * Runs <tt>this</tt> operator .
  */
  virtual int Run() = 0;
 
  //
  virtual CATBody *GetResult() = 0;

    
  ////---------------------------------------------------------------------------------------------
  //// CGMReplays Methods
  ////---------------------------------------------------------------------------------------------

  ///* @nocgmitf */
  //static const CATString* GetDefaultOperatorId() { return &_OperatorId; }
  ///* @nocgmitf */
  //const CATString* GetOperatorId() { return &_OperatorId; }

  ///* @nocgmitf */
  //virtual CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream) = 0;

  //// Input
  ///* @nocgmitf */
  //virtual CATCGMOperator::CATCheckDiagnostic CheckInput(CATCGMOutput & os) = 0;
  ///* @nocgmitf */
  //virtual void WriteInput(CATCGMStream &os) = 0;
  ///* @nocgmitf */
  //virtual void RequireDefinitionOfInputAndOutputObjects() = 0;
  ///* @nocgmitf */
  //virtual void Dump(CATCGMOutput& os) = 0;
  ///* @nocgmitf */
  //virtual void WriteOutput(CATCGMStream & ioStream) = 0;
  ///* @nocgmitf */
  //virtual void DumpOutput(CATCGMOutput &os) = 0; // c'est le dum apres run 

protected:
  /**
  * Virtual constructor. Cannot be used.
  */

  CATBtoApproximateProfile(CATGeoFactory * iFactory, CATTopData* iTopData);


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
* @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
* @see CATFrFSmoothingOper
*/

ExportedByCATBtoSmoothing
CATBtoApproximateProfile * CATBtoCreateApproximateProfile(CATGeoFactory         * iFactory,
  CATTopData            * iTopData,
  CATMathSetOfPointsND  * iPoints);

/**
* Creates the operator that smoothes a set of points to create a Set of curves.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iTopData
* The pointer to TopData containing configuration And Journal defining the level of code to replay.
* @param iScan
* The pointer to the CATCldScan corresponding to an ordered set of points (Its dimension=3).
* @return
* The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
* @see CATFrFSmoothingOper
*/

ExportedByCATBtoSmoothing
CATBtoApproximateProfile * CATBtoCreateApproximateProfile(CATGeoFactory * iFactory,
  CATTopData    * iTopData,
  CATCldScan    * iScan);
#endif
