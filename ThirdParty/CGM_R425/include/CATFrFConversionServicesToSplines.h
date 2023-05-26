//====================================================================
// Copyright Dassault Systemes Provence 2020-2021, all rights reserved 
//====================================================================
//
// services pour Tooling ... a enrichir avec les demandes
//
//======================================================================
// Fev,      12 th 2021 : ANR : Creation  : remplacera CATFrFUtilitiesForConversion
//                                           (a supprimer des que Tooling migre)  
//======================================================================

#ifndef CATFrFConversionServicesToSplines_H
#define CATFrFConversionServicesToSplines_H
 
#include "FrFAdvancedOpeCrv.h"   
#include "CATTopOperator.h" 

#include "CATGeoFactory.h" 
#include "CATFreeFormDef.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATFrFNurbsMultiForm.h"
#include "CATEdge.h"
#include "CATBody.h"
#include "CATMathSetOfPoints.h"
#include "CATListOfInt.h" 
#include "CATMathPlane.h"

#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATString.h"
#include "CATSoftwareConfiguration.h" 
#include "CATTopData.h"   
 
   
class ExportedByFrFAdvancedOpeCrv CATFrFConversionServicesToSplines : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATFrFConversionServicesToSplines);
public :
   
  virtual ~CATFrFConversionServicesToSplines();    
   
  // comment to do ...
  virtual void SetConversioParams(double ideviation, int iNbMaxArcs, int iMaxDegree) = 0;

  virtual void ConstraintsExtremities(CATFrFContinuity iSideContinuity = CATFrFPointCont) = 0;

  // comment to do ... //sharpness_tolerance = 60 ?
  virtual void SetSharpnessAngle(double isharpness_angle) = 0;

  // comment to do
  virtual void SetDistributionOfPoints(double imin_dist) = 0;
    
  virtual int RunOperator() = 0;

  virtual CATBody *GetBody() = 0;

  virtual void GetResult(CATEdge *&oEdge) = 0;

  virtual void GetResult(CATFrFNurbsMultiForm *&ioNurbsMultiForm) = 0;
  
  virtual void GetResult(CATLISTV(CATMathPoint) &oListOfPtsFoSpline) = 0;
   

  //---------------------------------------------------------------------------------------------
  // CGMReplays Methods
  //---------------------------------------------------------------------------------------------

  static const CATString* GetDefaultOperatorId() { return &_OperatorId; }
  const CATString* GetOperatorId() { return &_OperatorId; }

  virtual CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream) = 0;

  // Input
  virtual void WriteInput(CATCGMStream &os) = 0;
  virtual void RequireDefinitionOfInputAndOutputObjects() = 0;
  virtual void Dump(CATCGMOutput& os) = 0;
  virtual void DumpOutput(CATCGMOutput &os) = 0; // c'est le dum apres run 
  // Input 
  virtual CATCGMOperator::CATCheckDiagnostic CheckInput(CATCGMOutput & os) = 0;

protected:
  /**
  * @nodoc
  */
  CATFrFConversionServicesToSplines(CATGeoFactory* iFactory, CATTopData* iTopData);


  //-------- Data :
  static CATString _OperatorId;
};
 
//
ExportedByFrFAdvancedOpeCrv  CATFrFConversionServicesToSplines *CATCreateConversionServicesToSplines(CATGeoFactory *iFactory, CATTopData *iTopData, CATEdge *iEdge);

//
ExportedByFrFAdvancedOpeCrv  CATFrFConversionServicesToSplines *CATCreateConversionServicesToSplines(CATGeoFactory *iFactory, CATTopData *iTopData, CATBody *iBody);
 
#endif
