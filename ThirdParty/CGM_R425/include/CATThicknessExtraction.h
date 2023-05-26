// COPYRIGHT DASSAULT SYSTEMES 2020 ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  :   UF9
//
// DESCRIPTION  : 
//                
//=============================================================================
// Creation UF9 March 2021
//=============================================================================

#ifndef CATThicknessExtraction_H
#define CATThicknessExtraction_H

#include "CATMathDef.h"
#include "CATTopOperator.h"
#include "CATMathPoint.h"
#include "CATLISTP_CATMathPoint.h"
#include "CATLISTP_CATMathVector.h"
#include "CATMathVector.h"
#include "CATListOfDouble.h"
#include "CATWallAnalyzer.h"
#include "CATIPGMPositionPtVolOperator.h"
#include "CATIPGMDistancePointBody.h"
#include "CATListOfInt.h"
#include "CATTopData.h"
#include "CATThicknessComputationOpe.h"

#include "CATCleverOffset.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATString;

class CATExtCGMReplay;
class CATCGMStream;
class CATCGMOutput;

class CATThicknessExtractionImpl;


//-----------------------------------------------------------------------------
// CATThicknessExtraction
//-----------------------------------------------------------------------------
class CATThicknessExtraction : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATThicknessExtraction);

  //---------------------------------------------------------
  // CATCreateThicknessExtraction
  //---------------------------------------------------------
public:

  //---------------------------------------------------------
  // SetListOfPoints
  //---------------------------------------------------------
  void SetListOfPoints(CATLISTP(CATMathPoint) &iListOfPoints);

  //---------------------------------------------------------
  // SetListOfNormals
  //---------------------------------------------------------
  void SetListOfNormals(CATLISTP(CATMathVector) &iListOfNormals);

  //---------------------------------------------------------
  // SetMaxThickness
  //---------------------------------------------------------
  void SetMaxThickness(double iMaxThickness); 

  //---------------------------------------------------------
  // SetIndexesToIgnore
  //---------------------------------------------------------
  void SetIndexesToIgnore(CATListOfInt& iListOfIndexesToIgnore);

  //---------------------------------------------------------
  // SetMidSurfaceBody
  //---------------------------------------------------------
  void SetMidSurfaceBody(CATBody *iBody);

  //---------------------------------------------------------
  // GetListOfThickness
  //---------------------------------------------------------
  void GetListOfThickness(CATListOfDouble  oThicknessList);

  //---------------------------------------------------------
  // Constructor & Destructor
  //---------------------------------------------------------
public:
  virtual ~CATThicknessExtraction();

  friend ExportedByCATCleverOffset CATThicknessExtraction* CATCreateThicknessExtraction(CATGeoFactory* iFactory,
                                                                                 CATTopData* iData,
                                                                                 CATBody* iVolumicBody,
                                                                                 CATLISTP(CATMathPoint) iPoints,
                                                                                 CATLISTP(CATMathVector)iNormals,
                                                                                 double                 iMaxThickness,
                                                                                 CATMathTransformation  iTransfo,
                                                                                 CATListOfInt iListOfIndexesToIgnore);

protected:

  CATThicknessExtraction(
    CATGeoFactory* iFactory,
    CATTopData* iTopData,
    CATThicknessExtractionImpl* iImpl);

  //---------------------------------------------------------
  // RunOperator
  //---------------------------------------------------------
  int RunOperator();

 // int Run();

private:
  // ------------------------------------------------------------------------
// GetThicknessExtractionImpl
// ------------------------------------------------------------------------
  CATThicknessExtractionImpl* GetThicknessExtractionImpl() const;



  //-------------------------------------------------------------------
  // CGMReplay Methods
  //-------------------------------------------------------------------
public:
 CATString const* GetDefaultOperatorId();
 CATString const* GetOperatorId();

  ExportedByCATCleverOffset int SetOperators(CATThicknessComputationOpe* iWallAnalyzerOpe,
                   CATIPGMPositionPtVolOperator* iPositionPtVolOp,
                   CATIPGMDistancePointBody* iDistancePtBodyOp);

  ExportedByCATCleverOffset int GetResult(double*& ioThicknesses, double*& ioOffsets, CATListOfInt& ioListOfKOIndexes);
  ExportedByCATCleverOffset int GetResult(CATListOfDouble oThicknesses, CATListOfDouble oOffsets, CATListOfInt oListOfKOIndexes);

 CATExtCGMReplay* IsRecordable(short& oLevelOfRuntime, short& oVersionOfStream);

 void WriteInput(CATCGMStream& oStr);
 void ReadInput(CATCGMStream& ioStr, int iVersionOfStream, short iCGMReplayVersion);
 void Dump(CATCGMOutput& os);

 void RequireDefinitionOfInputAndOutputObjects();


};


ExportedByCATCleverOffset CATThicknessExtraction* CATCreateThicknessExtraction(CATGeoFactory* iFactory,
                                                                               CATTopData* iData,
                                                                               CATBody* iVolumicBody,
                                                                               CATLISTP(CATMathPoint) iPoints,
                                                                               CATLISTP(CATMathVector)iNormals,
                                                                               double                 iMaxThickness,
                                                                               CATMathTransformation  iTransfo,
                                                                               CATListOfInt iListOfIndexesToIgnore);


#endif

