/* -*-C++-*- */

#ifndef CATWireAnalysis_H
#define CATWireAnalysis_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//===================================================================
//===================================================================
//
// CATWireAnalysis: Class to analyze the continuity of a wire 
// ------------
//
//===================================================================

//===================================================================
// Usage notes:
// -----------
//
//   
//===================================================================

//===================================================================
// March. 99    Creation                              E.Bartholomot
// Avr.   02    Migration de IsG1() et IsEdgesG1(...)
//              vers CATVertex::EvalSharpness         HCN
// March  03    Extract G2                            AOV/ALV
//              _CurvatureThreshold: seuil de courbure modulable.
// Aug.   05    Supression de OldIsG1 & OldIsEdgesG1  ALV
// 27/10/11 NLD Ajout argument iSoftwareConfiguration au constructeur
//              Ajout _SoftwareConfiguration
//===================================================================
//===================================================================

#include "AnalysisToolsLight.h"
#include "CATEdge.h"
#include "CATPGMWireAnalysis.h"

class CATWire;
class CATBody;
class CATLaw;
class CATCompositeLaw;
class CATGeoFactory;
class CATVariableParallelLaw;
class CATSoftwareConfiguration;


// Start : SUH : 2003:2:10
#define GEOM_REP_CHANGES
#ifdef GEOM_REP_CHANGES
class CATSelectCurveTool;
#endif
// End : SUH : 2003:2:10


class ExportedByAnalysisToolsLight CATWireAnalysis: public CATPGMWireAnalysis
{

 private:

  CATWire *_Wire;
  CATWire *_WireToSplit;
  CATBody *_G1WiresBody;
  CATLaw *_Offset;
  CATLaw ** _Mappings;
  CATLONG32 _ContinuousCellNumber;
  CATVariableParallelLaw  * _CurLaw;
  //aov wk 10 2003
  CATLONG32 _G2Continuity;
  double _CurvatureThreshold;//Seuil de courbure 0.98 par defaut
  CATCompositeLaw* _CompLaw;
  CATSoftwareConfiguration* _SoftwareConfiguration;

  // Start : SUH : 2003:2:10
#ifdef GEOM_REP_CHANGES
  CATSelectCurveTool * _SelectCrvTool;
#endif
  // End : SUH : 2003:2:10

  // Start : SUH : 2003:5:21
  CATBoolean _AcceptSmoothVtx;
  // End : SUH : 2003:5:21  
  
 public:

  //---------------------------------------------------------------------------
  // Constructor 
  //---------------------------------------------------------------------------
  CATWireAnalysis( CATWire                  * iWire,
                   CATLaw                   * iOffset = NULL ,
                   CATLONG32                  ilevel                 = 0,
                   CATSoftwareConfiguration * iSoftwareConfiguration = NULL
                  ); 

  //---------------------------------------------------------------------------
  // Destructor ( default) 
  //---------------------------------------------------------------------------
  ~CATWireAnalysis(); 
  
  //---------------------------------------------------------------------------
  // Check wire is G1 continuous ( after offset if option law activated ) 
  //---------------------------------------------------------------------------
  int IsG1(const double iTolAngle = CATTopSharpAngle);
  
  //---------------------------------------------------------------------------
  // Check 2 Edges is G1 continuous 
  //---------------------------------------------------------------------------
  int IsEdgesG1(CATEdge* EdgePrec, CATOrientation OriPrec, int iNum1, 
                CATEdge* EdgeSuiv, CATOrientation OriSuiv, int iNum2,
                const double iTolAngle = CATTopSharpAngle);

  //---------------------------------------------------------------------------
  // Split G0 Wire into G1 wire   
  //---------------------------------------------------------------------------
  CATBody * SplitToG1Wires(CATGeoFactory * iFactory, const double iTolAngle = CATTopSharpAngle);
  
  //OU :
  
  CATBody * SplitWireToG1Wires(CATGeoFactory *iFactory, const double iTolAngle = CATTopSharpAngle);
  //---------------------------------------------------------------------------
  // Extract One G1 Wire From one edge int the wire 
  //---------------------------------------------------------------------------
  CATBody * ExtractG1WireFromEdge(CATGeoFactory * iFactory, CATEdge * iEdge, const double iTolAngle = CATTopSharpAngle);
  
  //---------------------------------------------------------------------------
  // aov wk 10 2003
  // Extract One G2 Wire From one edge int the wire 
  //---------------------------------------------------------------------------
  CATBody * ExtractG2WireFromEdge(CATGeoFactory * iFactory, CATEdge * iEdge , double iCurvatureThreshold=0.98);

  //---------------------------------------------------------------------------
  // alv wk 13 2003
  // Check wire is G2 continuous ( after offset if option law activated ) 
  //---------------------------------------------------------------------------
  int IsG2(double iCurvatureThreshold=0.98);


  // Start : SUH : 2003:2:10
#ifdef GEOM_REP_CHANGES
  //---------------------------------------------------------------------------
  // Initialize SelectCurveTool
  //---------------------------------------------------------------------------
  void SetSelectTool(CATSelectCurveTool * iTool);
#endif
  // End : SUH : 2003:2:10

  // Start : SUH : 2003:5:21
  void AcceptSmoothVertices(CATBoolean iAccept);
  // End : SUH : 2003:5:21
  
  void SetCircleTreatmentOn(CATCompositeLaw* iLaw);
  
 private :

  //int OldIsG1();

  int NewIsG1(const double iTolAngle = CATTopSharpAngle);

  /*int OldIsEdgesG1(CATEdge* EdgePrec, CATOrientation OriPrec, int iNum1, 
                          CATEdge* EdgeSuiv, CATOrientation OriSuiv, int iNum2);*/

  int NewIsEdgesG1(CATEdge* EdgePrec, CATOrientation OriPrec, int iNum1,
                   CATEdge* EdgeSuiv, CATOrientation OriSuiv, int iNum2,
                   const double iTolAngle = CATTopSharpAngle);

  CATBoolean GoodCurvatureThreshold();

  CATBoolean CheckForCircle(CATEdge* iEdge);

};
#endif

