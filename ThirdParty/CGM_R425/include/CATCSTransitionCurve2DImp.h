// COPYRIGHT DASSAULT SYSTEMES 2016
//
//===========================================================================
// 18/12/19 NLD Ajout Init()
// 22/12/19 BF8 Ajout GetDistanceLiEndCu()
//===========================================================================

#ifndef CATCSTransitionCurve2DImp_H
#define CATCSTransitionCurve2DImp_H

#define EVALUATE_TransitionCurve

#include "CATCDSVirtual.h"
#include "CATCSCurve2D.h"
#include "CATCDSEnums.h"
#include "CATCSTransitionCurve2D.h"
#include "StreamGM.h"
#include "CATCivilCurveEvaluator.h"
#include "CATICDSClothoidAdapter.h"
#include "CATCivilCurveDef.h"
#include "CATMathPoint2D.h"
#include "CATMathLine2D.h"
#include <list>

class CATCSPoint2D;
class CATCSLine2D;
class CATCSCircle2D;
class CATMathVector2D;
class CATConstraintSolver;
class CATMathPoint2D;
class CATMathVector2D;
class CATPlane;
class CATGeoFactory;
class CATCurve;
class CATSoftwareConfiguration;


// ----------------------------------------------------------------------
// te9, creation
//-----------------------------------------------------------------------

class ExportedByStreamGM CATCSTransitionCurve2DImp CATCDSFinal : public CATCSTransitionCurve2D
{
public:

                        CATCSTransitionCurve2DImp();

                        CATCSTransitionCurve2DImp(CATCivilCurveType iTransitionType,
                                                  CATCSLine2D              *  ipInitialLine     ,
                                                  int                         iInitialOrient    ,
                                                  CATCSCircle2D            *  ipFinalCircle);

                        CATCSTransitionCurve2DImp(CATCivilCurveType iTransitionType,
                                                  CATCSCircle2D            *  ipInitialCircle   ,
                                                  int                         iInitialOrient    ,
                                                  CATCSCircle2D            *  ipFinalCircle);

                        CATCSTransitionCurve2DImp(CATCivilCurveType iTransitionType,
                                                  CATCSPoint2D             *  ipInitialPoint    ,
                                                  CATCSLine2D              *  ipInitialLine     ,
                                                  int                         iInitialOrient    ,
                                                  CATCSPoint2D             *  ipFinalPoint);

                        CATCSTransitionCurve2DImp(CATCivilCurveType iTransitionType,
                                                  CATCSPoint2D             *  ipInitialPoint    ,
                                                  CATCSLine2D              *  ipInitialLine     ,
                                                  int                         iInitialOrient    ,
                                                  int                         iSide             ,
                                                  CATCSLine2D              *  ipFinalLine       ,
                                                  int                         iFinalOrient      ,
                                                  double const             *  ipA2              ,
                                                  double const             *  ipLength          ,
                                                  double const             *  ipRadius          ,
                                                  double const             *  ipShift);

                        CATCSTransitionCurve2DImp(CATCivilCurveType iTransitionType,
                                                  CATCSPoint2D             *  ipInitialPoint    ,
                                                  CATCSLine2D              *  ipInitialLine     ,
                                                  int                         iInitialOrient    ,
                                                  int                         iSide             ,
                                                  double const             *  ipA2              ,
                                                  double const             *  ipLength          ,
                                                  double const             *  ipRadius          ,
                                                  double const             *  ipAngle           ,
                                                  double const             *  ipShift);

                        CATCSTransitionCurve2DImp(CATCivilCurveType                     iTransitionType,
                                                  CATCSPoint2D                        * ipInitialPoint,
                                                  CATCSCircle2D                       * ipInitialCircle,
                                                  double const                        * ipSecondRadius,
                                                  int                                   iInitialOrient,
                                                  CATCivilCurve_CircleCircleTransition  iCircleCircleTransition,
                                                  double const                        * ipA2,
                                                  double const                        * ipLength,
                                                  double const                        * ipAngle,
                                                  double const                        * ipShift);

                        CATCSTransitionCurve2DImp(CATCivilCurveType                     iTransitionType,
                                                  CATCSTransitionCurve2D              * ipInitialSpiral,
                                                  int                                   iInitialOrient,
                                                  double const                        * ipRadius,
                                                  double const                        * ipA2,
                                                  double const                        * ipLength,
                                                  double const                        * ipAngle,
                                                  double const                        * ipShift);

                        CATCSTransitionCurve2DImp(CATCSTransitionCurve2DImp const  & ipTransitionCurve);


                       ~CATCSTransitionCurve2DImp();

          CATCDSBoolean IsValid()                                                  const CATCDSOverride;

          CATParamType  GetLimits(double                    & oLow              ,
                                                  double                    & oUp)         CATCDSOverride;

          CATCDSBoolean Regenerate()                                                        CATCDSOverride;

         void          GetDependencies(CATCDSLISTP(CATCSEntity)  & oNodes)    const CATCDSOverride;

         void          Evaluate2D(double                      iT                ,
                                                  double                   *  oaPoint           ,
                                                  double                   *  oaFirstDeriv      ,
                                                  double                   *  oaSecondDeriv     ,
                                                  double                   *  oaThirdDeriv = 0)       CATCDSOverride;

          int           GetNbOfDiscontinuities()                                                  const;

          void          GetDiscontinuitiesParams(double                   *  oaValues)    const;

          void          EvaluateAtDiscontinuity2D(int                         iIdx              ,
                                                  CATDiscontinuitySide        iSide             ,
                                                  double                      iT                ,
                                                  double                   *  oaPoint           ,
                                                  double                   *  oaFirstDeriv      ,
                                                  double                   *  oaSecondDeriv     ,
                                                  double                   *  oaThirdDeriv = 0)      CATCDSOverride;

          void          GetDirection2D(double                    & oX                ,
                                                  double                    & oY)          CATCDSOverride;

          void ApplyTransformation2D(double                      iMatrix[3][3])          CATCDSOverride
          {};

          CATCDSBoolean EvaluateLength(double                      iStart            ,
                                                  double                      iEnd              ,
                                                  double                    & oLength)    CATCDSOverride;

          CATCDSBoolean IsMatched(CATCSType                   iType)    const CATCDSOverride;

          void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;


          /*
                  void          CreateTransitionCurveData       (CATICDSGeometry          *  iInitialPt        ,
                                                          CATICDSGeometry          *  iInitialTgt       ,
                                                          CATICDSGeometry          *  iInitialCircle    ,
                                                          int                       & iInitialOrient    ,
                                                          int                       & iInitialSide      ,
                                                          CATICDSGeometry          *  iFinalPt          ,
                                                          CATICDSGeometry          *  iFinalTgt         ,
                                                          int                       & iFinalOrient      ,
                                                          CATICDSGeometry          *  iFinalCircle      ,
                                                          double                   *  iA2               ,
                                                          double                   *  iLength           ,
                                                          double                   *  iRadius           ,
                                                          double                   *  iAngle            ,
                                                          double                   *  iShift            )          CATCDSOverride;*/
                  void          SetClothoidAdapter(CATICDSClothoidAdapter    * ipAdapter)          CATCDSOverride;

                  void          SetTransitionCurveType(CATCivilCurveType                      iType);
                  void          SetTransitionCurveType(CATCDSTransitionCurveType              iType) CATCDSOverride;
 CATCDSTransitionCurveType      GetCDSTransitionCurveType()                                             const CATCDSOverride;

                  void          SetInitialPoint(CATCSPoint2D             *  ipInitialPoint)          CATCDSOverride;

                  void          SetInitialLine(CATCSLine2D              *  ipInitialLine     ,
                                                          int                         iOrientation)          CATCDSOverride;

                  void          SetInitialCircle(CATCSCircle2D            *  ipInitialCircle   ,
                                                          int                         iOrientation)          CATCDSOverride;

                  void          SetInitialSpiral(CATCSTransitionCurve2D* ipInitialSpiral,
                                                          int                         iOrientation)          CATCDSOverride;

                  void          SetFinalPoint(CATCSPoint2D             *  ipFinalPoint)          CATCDSOverride;

                  void          SetFinalLine(CATCSLine2D              *  ipFinalLine       ,
                                                          int                         iFinalOrient)          CATCDSOverride;

                  void          SetFinalCircle(CATCSCircle2D            *  ipFinalCircle)          CATCDSOverride;

                  void          SetSide(int const                 & iSide)          CATCDSOverride;

                  void          SetInitialParameters(double const             *  ipA2              ,
                                                          double const             *  ipLength          ,
                                                          double const             *  ipRadius          ,
                                                          double const             *  ipAngle           ,
                                                          double const             *  ipShift)          CATCDSOverride;

                  CATCivilCurveType GetTransitionCurveType()                                                    const;


                  CATCSPoint2D* GetInitialPoint()                                                  const CATCDSOverride;

                  CATCSLine2D * GetInitialLine()                                                  const CATCDSOverride;

                  int           GetInitialOrient()                                                  const CATCDSOverride;

                  CATCSPoint2D* GetFinalPoint()                                                  const CATCDSOverride;

                  CATCSLine2D * GetFinalLine()                                                  const CATCDSOverride;

                  int           GetFinalOrient()                                                  const CATCDSOverride;

                  CATCSCircle2D* GetInitialCircle()                                                  const CATCDSOverride;


                  CATCSCircle2D* GetFinalCircle()                                                  const CATCDSOverride;

                  int            GetSide()                                                  const CATCDSOverride;

                  void          GetInitialParameters(double const             *& opA2              ,
                                                          double const             *& opLength          ,
                                                          double const             *& opRadius          ,
                                                          double const             *& opAngle           ,
                                                          double const             *& opShift)          CATCDSOverride;

                  void          GetInitialParameters(double                   *& opA2              ,
                                                          double                   *& opLength          ,
                                                          double                   *& opRadius          ,
                                                          double                   *& opAngle           ,
                                                          double                   *& opShift) CATCDSOverride;

                  void GetParameters(double &oA2, double  &oLength, double  &oRadius, double  &oAngle, double &oShift) CATCDSOverride;

                  CATCDSBoolean CreateCurve(CATPlane                  & iPlane            ,
                                                          CATCurve                 *& opTransitionCurve        ,
                                                          double                      oaPoint[2])    const;

                  CATCDSBoolean CreateCurve(CATPlane                  & iPlane,
                                                          CATCurve                 *& opTransitionCurve,
                                                          double                      oaPoint[2], 
                                                          double                   *& opA2,
                                                          double                   *& opLength,
                                                          double                   *& opRadius,
                                                          double                   *& opAngle,
                                                          double                   *& opShift) const;


          void          SetGeoFactory            (CATGeoFactory            *  ipGeoFactory      )
          { _pFactory = ipGeoFactory; };

          CATGeoFactory* GetGeoFactory           () const
          { return _pFactory; };

          void             SetSoftwareConfiguration(CATSoftwareConfiguration* ipConfig);


         void          SetScale                 (CATCDSScale                 iScale            )          CATCDSOverride;


         CATICDSClothoidAdapter* const GetClothoidAdapter()                                         const CATCDSOverride
          { return _pClothoidAdapter; };

         void          Write                    (CATCDSStream              & ioStream          )          CATCDSOverride;

          CATCDSBoolean GetDepsDistWithFixLength(double const                 iLength           ,
                                                 double const               * iParams           , 
                                                 double                     & oDistance         )          CATCDSOverride;
          CATCDSBoolean GetDistanceEndObjStartCu(double const                 iLength            ,
                                                 double const               * iParams,
                                                 double                     & oDistance          ,
                                                 CATCDSBoolean                iProjectOnLine = FALSE)          CATCDSOverride;

          CATCDSBoolean GetDistanceStartObjEndCu(double const                iLength           ,
                                                  double const              * iParams           ,
                                                  double                    & oDistance         )          CATCDSOverride;
          CATCDSBoolean GetDistanceStartEndCu   (double const                iLength,
                                                 double const              * iParams,
                                                 double                    & oDistance          )          CATCDSOverride;
          CATCDSBoolean GetLengthWithDepsDistance(double const                iDistance,
            double const            *   iParams,
            double                  &   oLength)         CATCDSOverride;

          CATCDSBoolean GetTSCSTFromPositionFromLnPositionsAndParams(double const* aLine1Coords,
                                                                     double const* aLine2Coords,
                                                                     int const iInitOrient1,
                                                                     int const iInitOrient2,
                                                                     int const iSide1,
                                                                     int const iSide2,
                                                                     double const iLength1,
                                                                     double const iLength2,
                                                                     double& iRadius,
                                                                     double* oaPoint1,
                                                                     double* oaPoint2,
                                                                     double* oaCenterCircle) CATCDSOverride;

          CATCDSBoolean SwitchObjectsTCToParamsTC(CATCDSBoolean const iSwap, CATCSPoint2D* iStartPoint, double const& iLength) CATCDSOverride;
          CATCDSBoolean SwapCircles() CATCDSOverride;
private:
  enum Type {
             NONE,
             LINE_CIRCLE,
             CIRCLE_CIRCLE,
             POINT_LINE_POINT,
             POINT_LINE_LINE_PARAMETER,
             POINT_LINE_PARAMETERS,
             POINT_CIRCLE_PARAMETERS,
             POINT_CIRCLE_PARAMETER,
             POINT_SPIRAL_PARAMETERS,
             POINT_SPIRAL_PARAMETER
  };

          CATConstraintSolver * GetConstraintSolver() const;
          int GetCDSLevel() const;

          void          CreateFactoryFromScale   ();

          CATCDSBoolean CompareScale             (double                      iScale            );

          void          GetPointCoordinates      (CATCSPoint2D              & iPoint            ,
                                                  CATMathPoint2D            & oPoint            ) const;

          void          GetLineCoordinates       (CATCSLine2D               & iLine             ,
                                                  CATMathPoint2D            & oOrigin           ,
                                                  CATMathVector2D           & oDirection        ) const;

          void          GetCircleCenter          (CATCSCircle2D             & iCircle           ,
                                                  CATMathPoint2D            & oCenter           ) const;
          void          UpdateType               ();

          void          Init                     ();

          CATCDSBoolean IsDefine                 ()                                               const;


          void          GetParameters            (double                    & oA2, 
                                                  double                    & oLength, 
                                                  double                    & oRadius, 
                                                  double                    & oAngle, 
                                                  double                    & oShift, 
                                                  CATCDSBoolean               iRegenerate);

  CATCivilCurveType                _TransitionType;
  CATCivilCurve_CircleCircleTransition _CircleCircleTransition;
  struct TC_Data
  {
    CATCivilCurveType                _TransitionType;
    Type                             _type ;
    CATCDSBoolean  _isInitPointSet, _isFinalPointSet ;
    CATMathPoint2D   _InitialPoint, _FinalPoint;
    CATCDSBoolean  _isInitLineSet, _isFinalLineSet;
    CATMathLine2D    _InitialLine, _FinalLine;
    CATCDSBoolean  _isInitCircleSet, _isFinalCircleSet;
    CATMathPoint2D  _InitialCircleCenter, _FinalCircleCenter;
    double          _initialRadius, _finalRadius;
    int            _initialOrient, _finalOrient, _side;
    CATCDSBoolean  _isA2Set, _isLengthSet, _isRadiusSet, _isAngleSet, _isShiftSet;
    double          _A2, _Length, _Radius, _Angle, _Shift;
    // output
    int             _regenerate_status;
    CATCivilCurveEvaluator* _pTransitionCurve;
    CATMathPoint2D _point; // point d'inflexion

    // ne compare que les inputs
    TC_Data();
    virtual ~TC_Data();

    CATCDSBoolean operator==(TC_Data const& idata) const;
    double DistanceTo(TC_Data const& idata) const;
  

  };

  std::list<TC_Data> _data;

  Type                             _type;

  CATCSPoint2D             *       _pInitialPoint,
                           *       _pFinalPoint;
  CATCSLine2D              *       _pInitialLine,
                           *       _pFinalLine;
  CATCSCircle2D            *       _pInitialCircle,
                           *       _pFinalCircle;
  CATCSTransitionCurve2DImp*       _pInitialSpiral;
  int                              _initialOrient,
                                   _finalOrient,
                                   _side;
  double                   *       _pA2,
                           *       _pLength,
                           *       _pRadius,
                           *       _pAngle,
                           *       _pShift;
  CATCDSScale                      _scale;

  CATGeoFactory            *       _pFactory;
  CATPlane                 *       _pPlane;
  CATCDSBoolean                    _isAPoint;
  double                           _point[2];
  CATICDSClothoidAdapter   *       _pClothoidAdapter;
  CATSoftwareConfiguration *       _pConfig;

  CATCDSBoolean                    _Swap;

#ifdef EVALUATE_TransitionCurve
  CATCivilCurveEvaluator      *       _pTransitionCurve;
#else
  CATCurve                 *       _pTransitionCurve;
#endif

};

//-----------------------------------------------------------------------

#endif
