// COPYRIGHT DASSAULT SYSTEMES 1998 
//===================================================================
//
// CATDistMinCcvCcv:
// distance min entre 2 CCVs
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// Juillet 98     Creation                       PRG
// 28/06/04 NLD Les méthodes codées ici vont dans le .cpp
// 08/07/09 NLD Ajout _CGMLevel et RoughPolyLineDist()
//              Distance2() est renommee DistanceBoxes()
// 09/07/09 NLD Merge phase1/phase2 par monocodage
// 22/10/09 CPT Decoupage de Run() par ajout de RunByPassVC9() pour eviter plante
//              du compilateur VC9;
//              (redescente en R20 le 13/10/10)
// 13/10/10 NLD RunByPassVC9() renommée ExtremitiesAnalysis()
//===================================================================
#ifndef CATFrFDistanceMinCcvCcv_H
#define CATFrFDistanceMinCcvCcv_H

#include "CATIACGMLevel.h"

#include "FrFAdvancedOpeCrv.h"
#include "CATFrFCompositeCurve.h"
#include "CATFrFCCvParam.h"
#include "CATDistanceMinCrvCrv.h"
#include "CATMathBox.h"

#include "CATPGMFrFDistanceMinCcvCcv.h"

class CATGeoFactory;
class CATCrvLimits;
class CATSoftwareConfiguration;

//-------------------------------------------------------------------
class ExportedByFrFAdvancedOpeCrv CATFrFDistanceMinCcvCcv : public CATPGMFrFDistanceMinCcvCcv
{
public :
  CATFrFDistanceMinCcvCcv(CATGeoFactory*        factory,
                          CATFrFCompositeCurve* CCV1,
                          CATFrFCompositeCurve* CCV2,
                          CATSoftwareConfiguration * iConfig=0);
  virtual ~CATFrFDistanceMinCcvCcv();
  void Run();
  CATFrFCCvParam* GetResultingCCVParam(CATLONG32 iNumCCV);  // iNumCCV vaut 1 ou 2

  double GetMinDist() ;
  CATLONG32 Min1IsTheStart() ;
  CATLONG32 Min1IsTheEnd() ;
  CATLONG32 Min2IsTheStart() ;
  CATLONG32 Min2IsTheEnd() ;
  void SetArcLengthTolerance(double minExtremityArcLengthTolerance) ;
   
private :
  CATBoolean IsEqualWithTolerance(CATFrFCompositeCurve* CCV,
                                  const CATFrFCCvParam& CCvParam1,
                                  const CATFrFCCvParam& CCvParam2,
                                  double Tolerance);
  
  void DistanceBoxes(const CATMathBox& iBox1, const CATMathBox& iBox2,
                 double& oDistMin, double& oDistMax ) const;

  // Distance approchee entre 2 polylines definies chacune par NbPt points
  double RoughPolyLineDist(int NbPt, CATMathPoint* P1, CATMathPoint* P2);

  CATLONG32 SpecialCaseMinDistCrvCrv(CATLONG32 indexcrv1,CATLONG32 indexcrv2,double &oDist,
                                CATCrvParam &oParam1,CATCrvParam &oParam2) const;

  void ExtremitiesAnalysis(
    CATLONG32 &min1, CATLONG32 n1,
    CATLONG32 &min2, CATLONG32 n2);

  CATGeoFactory*          _factory;
  CATFrFCompositeCurve*   _CCV1;
  CATFrFCompositeCurve*   _CCV2;
  double                  _distMin;
  CATFrFCCvParam*         _CCVParam[2];  
  CATLONG32               _min1IsTheStart, _min1IsTheEnd;
  CATLONG32               _min2IsTheStart, _min2IsTheEnd;
  double                  _minExtremityArcLengthTolerance;
  CATLONG32               _CheckExtremityLength;
  // Config
  CATSoftwareConfiguration* _Config;
  int                     _CGMLevel;
};
#endif
