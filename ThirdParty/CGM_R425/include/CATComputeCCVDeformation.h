/**
 * @quickReview MMO 04:07:22
 */
/**
 * @fullreview MMO rno 02:05:29
 * @error MISC Y err_1 Intialiser les Champs par compilation (perfo)
 * @error MISC y err_2 Tester ResCur
 */

//===============================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved
// 
//
//---------------------------------------------------------------
// April 2005, RNO : Creation
//===============================================================



#ifndef CATComputeCCVDeformation_H
#define CATComputeCCVDeformation_H


#include "FrFAdvancedOpeCrv.h"
#include "CATDataType.h"
#include "CATCrvLimits.h"
#include "CATCrvParam.h"
#include "CATLISTP_CATMathPoint.h"
#include "CATMathPoint.h"
#include "CATListOfCATFrFCCvParam.h"
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATMathSetOfPoints;
class CATDistanceMinPtCrv;
class CATFrFCCvParam;


class ExportedByFrFAdvancedOpeCrv CATComputeCCVDeformation 
{
public:
  
  
  
  // Constructor
  // iHighTotalDeformation : tolerance admise pour le calcul des boites d'encombrement des courbes 
  CATComputeCCVDeformation(CATSoftwareConfiguration * iconfig,
    CATGeoFactory          * iFactory,
    CATFrFCompositeCurve  * iInputCCV,
    double iHighTotalDeformation);
  // Destructor
  ~CATComputeCCVDeformation (); 
  
  //Add points for the computation
  void SetPtsDeformOnInputCCV(CATLISTP(CATMathPoint) * Points); 
  //Set the Modified CCV
  void SetDeformedCCV(CATFrFCompositeCurve  * iBendCCV);
  //Option for digitalization
  void SetMinNumberOfPointsForDigit(int iForTotalCCV, int iAbsoluteMinForOneCrv);
  
  //Pour conserver les donnees de calcul
  void SetKeepPoints(CATBoolean iKeep);

  //Tell the operator which curve it can skip (Histo[i]=0 to skip i=0..NbInputCurve-1 )
  void SetHisto(const int * Histo);

  //Run :(Optimised For MultiRun)
  int Run();
  
  double GetMaxDeformation(CATMathSetOfPoints * & oMaxDefLocation);
  // A utiliser avec SetKeep Point
  void GetKeptPoints(CATLISTP(CATFrFCCvParam) & oDigitilizedParams, 
                     CATLISTP(CATFrFCCvParam) & oProjectedParams);
  
private:
  int Init();
  int UpdateDistanceMin();
  double ComputeMaxDistForPoint(CATMathPoint & pt,CATMathPoint &  oPoint, int Init, 
                                CATFrFCCvParam * & oParam);
  
  
  CATSoftwareConfiguration  * _Config;
  CATLONG32                   _CGMLevel;
  CATGeoFactory             * _Factory;
  CATFrFCompositeCurve      * _InputCCV,
                            * _BendCVV;

  int                         _MinCCVDigit;
  int                         _MinCrvDigit;
  CATLISTP(CATMathPoint)    * _ListPtsDeformOnCCVToClean;
  CATMathSetOfPoints        * _PointsFromDigit;

  double                      _MaxDeformation;
  CATMathSetOfPoints *        _MaxDefLocations;
  


  struct StructMinDist
  {
    CATULONG32            Tag;
    CATCrvLimits          Limit;
    
    CATDistanceMinPtCrv * Ope;
    
    CATCrvParam           LastSolution;

    //3D Bounding Box
    double      XBoxMin;
    double      XBoxMax;
    double      YBoxMin;
    double      YBoxMax;
    double      ZBoxMin;
    double      ZBoxMax;
  };
  CATLONG32       _OldNbBendCurves;
  StructMinDist * _StrMinDistOnBendCVV;
  
  double *      _InputCrvLength; 
  double        _TotalLength;
  int           _FirstRun;
  int           _IsClose;
  double        _HTDef;
  int *         _NbPointsFromCurve;
  const int *         _Histo;
  //Pour le Keep
  CATBoolean  _KeepPoints;
  CATLISTP(CATFrFCCvParam) _DigitilizedParams;
  CATLISTP(CATFrFCCvParam) _ProjectedParams;

};

#endif


