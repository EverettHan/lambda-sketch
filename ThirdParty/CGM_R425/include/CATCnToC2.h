
//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
//
/**
 * Class defining a geometric operator that make C2 a C1 Curve with a controled deformatiom.
 * A CATCnToC2 operator is created with the CreateCnToC2 global method 
 * and must be directly deleted with the usual C++ delete operator after use.
 * The result is accessed with the GetResult methods. 
 *
**/




//==========================================================================
// 27/09/17  : NLD : SetForceLocalOpti3()
// 07/04/03  : RNO : Creation 
//==========================================================================
#ifndef CATCnToC2_H
#define CATCnToC2_H


#include "FrFAdvancedOpeCrv.h"
#include "CATDataType.h"
#include "CATCGMVirtual.h"
#include "CATListOfCATCrvLimits.h"
#include "CATListOfCATCurves.h"
class CATCurve;
class CATGeoFactory;
class CATCrvLimits;
class CATSoftwareConfiguration;
class CATSurface;

//----------------------------------------------------------------------
class  ExportedByFrFAdvancedOpeCrv CATCnToC2 : public CATCGMVirtual
 
{
public:
  virtual ~CATCnToC2() {};
  
  // Run Operator.
  // return 0 if OK ; !=0 else
  virtual int Run()=0;
  
  // Allowed maximum deformation. 
  // It corresponds to the maximum 3D deformation on the list of curves.
  // Default value : G0 resolution of the Factory 
  // return 0 if OK ; !=0 else
  virtual int SetMaxDeformationTol(double iMaxDeformation)=0;
  
  // To use global optimization.
  // The aim is to improve the general look of the curves.
  // iOptimization = 1 = ON, iOptimization = 0 = OFF;
  //
  // Default Mode : Global optimization : ON
  // The GlobalOptimization starts working with a MaxDeformationThreshold higher than 0.005
  // and gives better results with a MaxDeformationThreshold higher than 0.01
  // return 0 if OK ; !=0 else
  virtual int SetGlobalOptimisation(int iApplyGlobalOpti)=0;
  
  
  // Set2Representation : In case of "curves on surfaces", to indicate if geometry to correct is 2D
  // representation or 3D representation.
  // The 2D Representation is taken on the underlying surface of the PCurve
  // if not a PCurve then 3Drepresentation is assumed
  // Default : 3D Representation (even if input curve is a CATPCurve)

  virtual int Set2Representation()=0; 

  //SetHybridMode2D3D : In case of "curves on surfaces", 
  // both representation 2D and 3D are assumed at the same time !!!
  //
  virtual int SetHybridMode2D3D()=0;
  
  // Restricted and temporary use. Forbidden. Linked to SetLocalOptimization()
  virtual void SetForceLocalOpti3   (int iForceLocalOpti3Level) = 0;

  
  // GetResult : Return Same Pointer as InputCurve if any trouble
  // return 0 if OK ; !=0 else
  virtual int GetResult(CATCurve *& oC2Curve, CATCrvLimits *& oLimits)=0;
  
  // GetMaxDeformation : Return the computed Max Deformation
  // return 0 if OK ; !=0 else
  virtual int GetMaxDeformation(double & oMaxDeformation) = 0;

  virtual int GetNbC2InputDiscontinuities(CATLONG32 & oNBC2Dis)=0;

  virtual int GetG0G1G2InputContinuities(double & oMaxG0, double & oMaxG1, double & oMinG2)=0;
  

  // GetPartialResult : OPTIONAL GET
  // In case of Run Error Code 6 on could use Partial Result To get the list of C2 curves....
  // (Same Orientations for all curves ...
  // If used the resulting curves and Limits must be managed (remove/delete) by the caller 
  virtual int GetPartialResult(CATLISTP(CATCurve) & oListCurve, CATLISTP(CATCrvLimits) &oListOfLimits)=0;
  
  // Warning Not Implemented Yet
  virtual int ForceCleaning() = 0;
    
};

//==================================================================
//Create Function
ExportedByFrFAdvancedOpeCrv 
CATCnToC2* CATCreateCnToC2 (      CATSoftwareConfiguration * iSoftConfig,
                                  CATGeoFactory            * iFactory   ,
                            const CATCurve                 * iCnCurve   ,
                            const CATCrvLimits             * iSplit     );


#endif

