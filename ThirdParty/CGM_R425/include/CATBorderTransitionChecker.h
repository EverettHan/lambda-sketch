// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATBorderTransitionChecker:
//
//==========================================================================
//
// Usage notes:: continuity check at border transition
//
// General notations/behavior:
//  PtDev         : Point deviation          (distance)
//  NormalDev     : Normal deviation         (in degree)
//  CrossTgDev    : Cross Tangency deviation (in degree)
//  CurvatureDev  : Curvature deviation 
//                  (in the perpendicular direction regarding to the border
//                   tangency)
//                  (it is a difference between curvatures)
//  RCurvatureDev : Ratio between Curvature deviation and Sum of Curvatures
//
// N.B neither CurvatureDev nor RCurvatureDev is the famous and modern DSP/MWE curvature deviation ratio
//     increasing from 0. to 1. when curvature continuity gets better (and with 0.98 as commonly used threshold)
//     NLD191222
//==========================================================================
//    06/99 TPG Creation                                                 TPG
// 13/12/21 NLD Mise au propre / smart indent
// 14/12/21 NLD Ajout CreateP1P2()
//              Ajout des deviations minimum
//              (_PtDevMin, _NormalDevMin, _CrossTgDevMin, _CurvatureDevMin, _RCurvatureDevMin)
//              (PtDevParam1, _NormalDevParam1, _CrossTgDevParam1, _CurvatureDevParam1,_RCurvatureDevParam1)
//              (PtDevParam2, _NormalDevParam2, _CrossTgDevParam2, _CurvatureDevParam2,_RCurvatureDevParam2)
//              Ajout GetMinDeviation()
// 16/12/21 NLD Reaffiliation des commentaires à leurs méthodes
//              (suite à de vieilles insertions)
//==========================================================================

#ifndef CATBorderTransitionChecker_H
#define CATBorderTransitionChecker_H

#include "FrFOpeUtil.h"

#include "CATCrvLimits.h"
#include "CATCrvParam.h"
#include "CATFrFCCvParam.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CATTransitionCheckingCommand.h"
#include "CATCGMVirtual.h"

class CATFrFCompositeCurve;
class CATCurve;
class CATSurface;
class CATGeoFactory;
class CATCartesianPoint;
class CATFrFCoupling;
class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeUtil CATBorderTransitionChecker  : public CATCGMVirtual
{
  public :
    
//-------------------  Basic Methods ------------------- 
//  constructor with CATCurve
                    CATBorderTransitionChecker(CATGeoFactory           * iFactory    ,
                                               CATSoftwareConfiguration* iConfig     ,
                                               CATCurve                * iCurve1     ,
                                               CATCurve                * iCurve2     ,
                                               CATCrvLimits            * iCrvLimits1 = 0,
                                               CATCrvLimits            * iCrvLimits2 = 0 );

//  constructor with Composite curve
                    CATBorderTransitionChecker(CATGeoFactory           * iFactory    ,
                                               CATSoftwareConfiguration* iConfig     ,
                                               CATFrFCompositeCurve    * iBorder1    ,
                                               CATFrFCompositeCurve    * iBorder2    );
//  destructor
  virtual          ~CATBorderTransitionChecker();
  
//------------------- Compute Method -------------------  
            void    Run ();
  
//------------------- Advanced settings -------------------  
//
//  Setting tolerance
//
//  Distance tolerance (model unit)
//  the default is the resolution  
            void    SetDistanceTolerance (     double iDistanceTolerance);
//  Angle tolerance (degree)
//  the default is 0.1 degree
            void    SetAngleTolerance    (     double iAngleTolerance);
//
//  Number of sample points
//  The default number is calculated from the border length
//  (the longer one)
            void    SetNumberOfSamplePoints(   CATLONG32 iNbPts);

//  Sample points => MNA
//  Only if Sampling Mode is equal to 1 
//  (the longer one)
            void    SetOfSamplePoints      (const CATListOfDouble & iListOfParam   ,
                                            const CATListOfInt    & iListOfCrvIndex);

//
//  Sampling mode
//  iMode = 0 : iso-parametric sampling (default option)
//  iMode = 1 : Based On SamplePoints given by the user : Point where user
//              want to compute the min-distance (depend on curve's complexity)(sampling based on marching algorithm)
            void    SetSamplingMode(CATLONG32 iMode = 0);
//
//  Coupling mode
//  iMode = 0 : parametric coupling
//  iMode = 1 : minimum distance coupling (default option)
            void    SetCouplingMode(CATLONG32 iMode = 1);
  
//  Compute the parametric coupling
            void    ComputeCoupling();
  
  //Ajout MNA
            void    SetTabOfIndexCCVCorrespond(CATLONG32 * iCorrespond);

//
//  Transition checking order
//
//  Use CATTransitionCheckingCommand to specify the calculation,
//  by default all commands are requested
//
//  PtDev         : Point deviation          (distance)
//  NormalDev     : Normal deviation         (in degree)
//  CrossTgDev    : Cross Tangency deviation (in degree)
//  CurvatureDev  : Curvature deviation 
//                  (in the perpendicular direction regarding to the border
//                   tangency)
//                  (it is a difference between curvatures)
//  RCurvatureDev : Ratio between Curvature deviation and Sum of Curvatures
//
            void    SetTransitionCheckingOrder(CATTransitionCheckingCommand iCmd);
  
//------------------- Data Access Methods -------------------  
//
//  Getting tolerance
//
//  Distance tolerance (model unit)
          double    GetDistanceTolerance            ();

//  Angle tolerance (degree)
          double    GetAngleTolerance               ();
//
//  Number of sample points
//  The default number is calculated from the border length
//  (the longer one)
          CATLONG32 GetNumberOfSamplePoints         ();

//------------------- Result Access Methods -------------------  
//
// return -1 : the result is not available (the calculation is not ordered)
//         0 : the deviation is smaller than the tolerance
//         1 : the deviation is greater than the tolerance
//
// Maximum deviation 
  virtual CATLONG32 GetDeviation                    (double                       & oDeviation);
  virtual CATLONG32 GetNormalDeviation              (double                       & oDeviation);
  virtual CATLONG32 GetCrossTangencyDeviation       (double                       & oDeviation);
  virtual CATLONG32 GetCurvatureDeviation           (double                       & oDeviation);
  virtual CATLONG32 GetCurvatureDeviationRatio      (double                       & oDeviation);
  //
  virtual void      GetMaxDeviation                 (CATTransitionCheckingCommand   iCmd      ,
                                                     CATTransitionDeviationResult & oDeviation);

  virtual void      GetMinDeviation                 (CATTransitionCheckingCommand   iCmd      ,
                                                     CATTransitionDeviationResult & oDeviation);

  virtual void      GetMaxDeviation                 (CATTransitionCheckingCommand   iCmd      ,
                                                     CATTransitionDeviationResult & oDeviation,
                                                     CATTransitionPositionResult  & oPosition );

  virtual void      GetMinDeviation                 (CATTransitionCheckingCommand   iCmd      ,
                                                     CATTransitionDeviationResult & oDeviation,
                                                     CATTransitionPositionResult  & oPosition );

  //
  // Deviation average
  virtual CATLONG32 GetDeviationAverage              (double                       & oDeviation);
  virtual CATLONG32 GetNormalDeviationAverage        (double                       & oDeviation);
  virtual CATLONG32 GetCrossTangencyDeviationAverage (double                       & oDeviation);
  virtual CATLONG32 GetCurvatureDeviationAverage     (double                       & oDeviation);
  virtual CATLONG32 GetCurvatureDeviationRatioAverage(double                       & oDeviation);
//
  virtual void      GetDeviationAverage              (CATTransitionCheckingCommand   iCmd      ,
                                                      CATTransitionDeviationResult & oDeviation);
//
// return the maximum deviation and its location
// the command should be the single order
  virtual double    GetDeviation                     (CATTransitionCheckingCommand   iCmd      ,
                                                      CATFrFCCvParam               & oCCvParam1,
                                                      CATFrFCCvParam               & oCCvParam2);

  virtual double    GetDeviation                     (CATTransitionCheckingCommand   iCmd      ,
                                                      CATLONG32                    & oIndexCrv1,
                                                      CATCrvParam                  & oCrvParam1,
                                                      CATLONG32                    & oIndexCrv2,
                                                      CATCrvParam                  & oCrvParam2);

  private :

//-------------------PrivateMethods-----------------------------

//
//  set data
          void      SetData                    (      CATGeoFactory               *  iFactory  ,
                                                      CATFrFCompositeCurve        *  iBorder1  ,
                                                      CATFrFCompositeCurve        *  iBorder2  );

          void      CreateP1P2                 (const CATFrFCCvParam               & CCvParam1 ,
                                                const CATFrFCCvParam               & CCvParam2 ,
                                                      CATPoint                    *& oP1       ,
                                                      CATPoint                    *& oP2       );


//------------------- Datas -------------------  
  private :

  CATGeoFactory               *_Factory;
  CATSoftwareConfiguration    *_SoftwareConfig;

  CATFrFCompositeCurve        *_CCv1;
  CATFrFCompositeCurve        *_CCv2;
  CATFrFCCvParam               _CCvStart1;
  CATFrFCCvParam               _CCvEnd1;
  CATFrFCCvParam               _CCvStart2;
  CATFrFCCvParam               _CCvEnd2;

  CATLONG32                    _CCvMode;
  CATLONG32 *                  _Correspond;

  int                          _NbOfPtsSetByUser; //0 : n'a pas ete precise par le user
                                                  //1 : a ete precise par le user

  CATFrFCoupling              *_Coupling;

  CATLONG32                    _Cmd[10];
  CATLONG32                    _Orientation;

  CATLONG32                    _Run;

  CATLONG32                    _NbOfPts;
  CATLONG32                    _SamplingMode;
  CATListOfDouble              _ListOfParamOnFirstCcv;
  CATListOfInt                 _ListOfCrvIndexOnFirstCcv; 
  CATLONG32                    _CouplingMode;

  double                       _DistanceTolerance;
  double                       _AngleTolerance;

  double                       _PtDevAv;
  double                       _NormalDevAv;
  double                       _CrossTgDevAv;
  double                       _CurvatureDevAv;
  double                       _RCurvatureDevAv;

  double                       _PtDev;
  double                       _NormalDev;
  double                       _CrossTgDev;
  double                       _CurvatureDev;
  double                       _RCurvatureDev;

  // Ajouts NLD141221
  double                       _PtDevMin;
  double                       _NormalDevMin;
  double                       _CrossTgDevMin;
  double                       _CurvatureDevMin;
  double                       _RCurvatureDevMin;

  CATFrFCCvParam               _PtDevParam1;
  CATFrFCCvParam               _PtDevParam2;

  CATFrFCCvParam               _NormalDevParam1;
  CATFrFCCvParam               _NormalDevParam2;

  CATFrFCCvParam               _CrossTgDevParam1;
  CATFrFCCvParam               _CrossTgDevParam2;

  CATFrFCCvParam               _CurvatureDevParam1;
  CATFrFCCvParam               _CurvatureDevParam2;

  CATFrFCCvParam               _RCurvatureDevParam1;
  CATFrFCCvParam               _RCurvatureDevParam2;

  // Ajouts NLD141221
  CATFrFCCvParam               _PtDevMinParam1;
  CATFrFCCvParam               _PtDevMinParam2;

  CATFrFCCvParam               _NormalDevMinParam1;
  CATFrFCCvParam               _NormalDevMinParam2;

  CATFrFCCvParam               _CrossTgDevMinParam1;
  CATFrFCCvParam               _CrossTgDevMinParam2;

  CATFrFCCvParam               _CurvatureDevMinParam1;
  CATFrFCCvParam               _CurvatureDevMinParam2;

  CATFrFCCvParam               _RCurvatureDevMinParam1;
  CATFrFCCvParam               _RCurvatureDevMinParam2;

};

#endif


