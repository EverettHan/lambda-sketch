/* -*-C++-*- */

#ifndef CATlsoUtilDebugCheck_H
#define CATlsoUtilDebugCheck_H
/*  
=============================================================================

RESPONSABLE  : L Marini

DESCRIPTION  : Class for debug only:
               - Check body quality G0, G1, MicroEdge
               
=============================================================================
*/
#include "PersistentCell.h"
#include "CATBoolean.h"
#include "CATLISTV_CATMathPoint.h"
#include "ListPOfCATCell.h"
#include "CATGeoFactory.h"
class CATCGMOutput;
class CATBody;
class CATUnicodeString;
class CATExtTopOperator;
class CATPolyMorphingAdaptiveSampler;

class ExportedByPersistentCell CATlsoUtilDebugCheck
{

public:

  //-----------------------------------------------------------------------------
  //   Check of Topological Quality G0, G1
  //-----------------------------------------------------------------------------

  static void DetectWavyFaces(CATBody *iBody, const CATUnicodeString & ipAdditionalName);

  // DetectMaxGapG0G1WithTrace
  //     grep CheckG0G1 ODTName.* > e:\tmp\CheckG0G1.csv
  static void DetectMaxGapG0G1WithTrace(CATExtTopOperator      * ipExtTopOpe,
                                        const CATUnicodeString & ipAdditionalName,
                                        CATBody                * ipInputBody,
                                        CATBody                * ipResultBody,
                                        CATCGMOutput           & ioDump,
                                        double                   iNumberOfTimeTheResolution=1.0,
                                        double                   iMaxAngle=5.0);
  static void DetectMaxGapG0G1WithTrace(CATBody      * ipBody,
                                        const CATUnicodeString & ipAdditionalName,
                                        double       & oMaxGapG0,
                                        double       & oMaxAgnleG1,
                                        double         iNumberOfTimeTheResolution=1.0,
                                        double         iMaxAngle=5.0);


  static int GetNumberOfCrackEdgesForDebug(CATBody * ipBody,
                                           const CATUnicodeString & ipAdditionalName,
                                           ListPOfCATCell *oCrackEdgeCellList=NULL,
                                           CATBoolean bCreateDebugBody=TRUE);
  
  // DetectMicroEdge : shorter than 1000 times the resolution
  //     grep CheckMicroEdge ODTName.* > e:\tmp\CheckMicroEdge.csv
  static int DetectMicroEdge(CATBody      * ipBody,
                             const CATUnicodeString & ipAdditionalName,
                             double       & oShortestEdgeLength,
                             CATCGMOutput * ipDump=NULL,
                             double         iNumberOfTimeTheResolution=1000.0);

  // DetectMicroFace : shorter than 1000 times the resolution
  //     grep CheckMicroFace ODTName.* > e:\tmp\CheckMicroFace.csv
  static int DetectMicroFace(CATBody      * ipBody,
                             const CATUnicodeString & ipAdditionalName,
                             double       & oThinestFaceWidth,
                             CATCGMOutput * ipDump=NULL,
                             double         iNumberOfTimeTheResolution=1000.0);

  // DetectBigSlope
  //     grep CheckBigSlope ODTName.* > e:\tmp\CheckBigSlope.csv
  static void DetectBigSlope(CATBody                      * ipBody,
                             const CATUnicodeString       & ipAdditionalName,
                             const CATLISTV(CATMathPoint) & iSourceMathPointList,
                             const CATLISTV(CATMathPoint) & iTargetMathPointList,
                             CATCGMOutput                 & ioDump,
                             double                         iSlopeThreshold=4.0);
  // Detect BigSlope bet. two points (internal method)
  static void DetectBigSlopeForOneCouple(const CATLISTV(CATMathPoint) & iSourceMathPointList,
                                         const CATLISTV(CATMathPoint) & iTargetMathPointList,
                                         double & iSlopeThreshold,
                                         int                            iNumPoint1,
                                         int                            iNumPoint2,
                                         double & ioMaxSlope,
                                         CATLISTV(CATMathPoint) & ioErrorPointList,
                                         CATListOfInt & ioErrorPtIndexList);
  //Sampling Internship Context
  // Outputs the size of each corner edge of an ODT file
  static void OutputEdgeSizeDistribution(CATBody* pSkinBody, CATCGMOutput& ioDump);

  // CreateDebugBody
  static CATBody* CreateDebugBody(CATGeoFactory & iFactory, 
                              const CATLISTP(CATCell) & iCellList, 
                              const CATUnicodeString & ipAdditionalName, 
                              char * iNameBody);
};


#endif
