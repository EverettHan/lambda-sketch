#ifndef CATRevol_H
#define CATRevol_H

// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
// 2010-09-30 DLP Declare new methods called by ComputeExtrapolatedLimits().
// 2010-11-04 DLP Declare new methods for profile extrapolation.
// 2013-12-19 THM Add overloads of SetLimit and Run, to support change of where 
//                half radian shift is performed.
// 2015-09-14 G5S Rename SetProfile to SetProfileDynSweep so it doesn't conflict with what we want to do for the 
//                Fast Update Stress tests for Extrude.
//=============================================================================

#include "CATMathDef.h"
#include "CATSweep.h"
#include "CATMathAxis.h"
#include "CATMathLine.h"
#include "BO0SWEEP.h"

#include "CATListOfCATCells.h"
#include "CATListOfCATCrvParams.h"

class CATGeoFactory;
class CATBody;
class CATVolume;

class CATVertex;
class CATEdge;
class CATFace;
class CATDomain;
class CATEdgeCurve;
class CATMergedCurve;
class CATPCurve;
class CATPointOnEdgeCurve;
class CATMathDirection;
class CATTopData;
class CATPlane;
class CATExtrapolateBody;

//
//=============================================================================
//
class ExportedByBO0SWEEP CATRevol : public CATSweep
{
public:
  // Constructeur d'une Revolution a partir d'un Body
  CATRevol(CATGeoFactory * iGeoFactory,
           CATTopData * iData,
           CATBody * iProfBody,
           const CATMathAxis& iAxis,
           CATAngle iStartAngle,
           CATAngle iEndAngle);

  CATRevol(const CATRevol & iInitialRevol);

  // Destructeur
  ~CATRevol();

/*
 *
 */
 int  Run();

 // edition des limitantes
 void SetLimit ( CATLimit                iId,
                 CATLimitType            iType,
                 CATBoolean              iIsAxisReverted,
                 CATLength               iOffset,
                 CATGeometry          *  iLimit,
                 CATBody              *  iPropagationBody,
                 CATPropagationType      iPropagationFlag,
                 CATBoolean              iIsThickness = CATBoolean(0));
 //(same with a list of cells as limit)
 void SetLimit ( CATLimit                iId,
                 CATLimitType            iType,
                 CATBoolean              iIsAxisReverted,
                 CATLength               iOffset,
                 ListPOfCATCell        & iLimit,
                 CATBody              *  iPropagationBody,
                 CATPropagationType      iPropagationFlag,
                 CATBoolean              iIsThickness = CATBoolean(0));

 void SetExtrudeLimitAngleOffset ( CATLimit iId,
                                   CATAngle    iOffset );

 double GetExtrudeLimitAngleOffset (CATLimit iId);

 void SetMatterSide(CATSide iMatterSide);

 void GetMatterSide(CATSide &oMatterSide);

 virtual void SetProfile(CATBody * iProfBody);
 virtual void SetProfileDynSweep (CATBody * iProfBody);

 void GetAngles ( CATAngle & oStartAngle , CATAngle & oEndAngle );
 CATMathLine GetMathLine(); 

 virtual void GetRefPlane ( CATMathPlane & oRefPlane,
                            int          * oIsRefPlaneDefinedByUser = NULL );

 virtual void GetLimitBodyForAngle(CATBody*& StartLimitBodyForAngle,CATBody*& EndLimitBodyForAngle);

 void GetDegenerateCells(ListPOfCATCell &oCells);

 void                GetBottomAndTopFullCellList      ( const int                    iCurDomain                   ,
                                                        ListPOfCATCell       & oBottomCellsList             ,
                                                        ListPOfCATCell       & oTopCellsList                );

 void ApplyHalfRadShift();

 CATBoolean WasHalfRadShiftRequested();

  /**	@nodoc @nocgmitf */
 const  CATString  *GetOperatorId();

protected:

  // Methodes
  //
  CATBody * SweepCnt(CATGeoFactory * iGeoFactory);

  virtual void FixDegenerateCells();

  CATBoolean ChooseToApplyHalfRadShift();
  
  void SetLimitBodyForAngle(CATLimit iId, CATBody* iLimitBodyForAngle);
  //
  // nettoyage de l'environnement
  void Clear ();
  
  // Whether to convert the dimension limit to an until limit.
  virtual CATBoolean              ShouldConvertDimLimitToUntil();

  // The transformation of the profile required for the dimension limit. 
  virtual CATMathTransformation * GetProfileOffsetTransformation (CATLength iOffset);

  void CenterExtrapole ();

  //  Function to set the axis-reverted flag when extrapolation has been requested.
  void FindAxisReversionFlag(
    CATSweepLimit  *iLimit,
    CATBody        *iBody,
    CATEdge        *iExtremityEdge,
    CATMathVector  &iDirection  );

  //  Revol specific code used when esitmating how far to extrapolate a profile.
  virtual void ProfileExtrapoleSetOperatorOptions(
   CATSweepLimit      *iLimit,
   CATVertex          *iExtremityVertex,
   CATEdge            *iExtremityEdge,
   CATBody            *iBody,
   double              iMinimumGap,
   CATMathBox         &iSourceBox,
   CATMathBox         &iBoxSpace,
   CATMathPlane       &iPlaneSpace,
   CATMathLine        &iLineSpace,
   CATMathDirection   &iDirSpace,
   CATExtrapolateBody &ioExtraOperator
   );

  //
  //
  // Gestion de la degenerescence de cellules (portees par l'axe de revolution)
  //
  virtual void MakeSelfSafe();

  CATBody   * BuildSafeBody();

  void AddDegenerateCell(CATCell*);
  virtual int  IsDegenerate(CATCell*);
  virtual int  IsDegenerate(CATDomain*);
  virtual void PostGeoExtrude();
  CATCell *    FindAnOuterFace(CATVolume *);
  CATLONG32 FindAnOuterComponent ( CATCell         * iVolume                ,
                              CATLONG32              iNbConnectedComponents ,
                              ListPOfCATCell ** iListOfComponents      );
  void ComputeNewInternalDomains();

  // Gestion des relimitations du profile
  virtual CATBody * ProfileClose (CATBody * iBody);
  virtual CATBody * CloseTheProfile(CATBody * iBody);
  virtual CATError * ClosureOfTheProfile (
                                       const CATLONG32   ExtremityLocation[2],
                                       const CATLONG32   NbEdges_BE,
                                       const CATBoolean  ExtrapolationOnExtremity[2],
                                       const CATLONG32   ExtremityTangentCoeff[2],
                                       const double    & UnionBoxMaximumLength,
                                       const double    & DeltaBox,
                                       const double    & ExtrapolationLengthMax,
                                       const CATLONG32   ProfileAxisSide,
                                       const CATCrvLimits      ExtrapolatedPLineLimits[2],
                                       const CATCrvParam       ProfileExtremityPCurveParam_BE[2],
                                       const double            ProfileExtremityDistanceFromAxis_AE[2],
                                       const CATCrvParam       ProfileExtremityAxisParam_AE[2],
                                       const CATSurParam       ProfileExtremitySurParam_AE[2],
                                       const CATCrvParam       ProfileExtremityPCurveParam_AE[2],
                                       const CATCrvParam       UnionBoxAxisParam[2],
                                       const CATSurParam       UnionBoxSurParamOnAxis[2],
                                       const CATMathDirection  AxisBasis[3],
                                       CATMathPoint            ExtremityMathPointForSweepLimit[2],
                                       CATPCurve       * const ExtrapolatedPLine[2],
                                       CATEdge        ** const Edge_BE,
                                       CATPCurve      ** const PCurve_BE,
                                       CATCrvLimits    * const PCurveLimits_BE,
                                       short           * const PCurveOrientation_BE,
                                       CATPCurve       * const PCurveAxis,
                                       CATPlane        * const ProfilePlane,
                                       CATBody        *& OutputBody );
  void AddProfileAndExtrapolation ( const CATLONG32      NbEdges_BE,
                                    const CATBoolean     ExtrapolationOnExtremity[2],
                                    const CATCrvLimits   ExtrapolatedPLineLimits[2] ,
                                    CATPCurve    * const ExtrapolatedPLine[2],
                                    CATEdge     ** const Edge_BE,
                                    CATPCurve   ** const PCurve_BE,
                                    CATCrvLimits * const PCurveLimits_BE,
                                    short        * const PCurveOrientation_BE,
                                    CATPCurve         ** PCurve_AE ,
                                    CATCrvLimits       * PCurveLimits_AE,
                                    short              * PCurveOrientation_AE,
                                    CATLONG32          & Index);
  CATError * BuildClosure ( const CATLONG32    ExtremityLocation[2] ,
                                      const CATLONG32    NbEdges_BE,
                                      const CATBoolean   ClosureOnTheAxis,
                                      const CATLONG32    NbSurParamForClosure ,
                                      const CATLONG32    FlagForInternalLoop,
                                      const CATMathPoint ExtremityMathPointForSweepLimit[2],
                                      const CATSurParam  SurParamForClosure[7],
                                      CATEdge         ** const Edge_BE,
                                      short            * const PCurveOrientation_BE,
                                      CATPCurve       ** const PCurve_AE,
                                      CATCrvLimits     * const PCurveLimits_AE,
                                      CATPlane         * const ProfilePlane,
                                      CATLONG32        & Index ,
                                      CATBody         *& OutputBody);
  virtual CATBody * ComplementBody (CATBody * iBody);

  //
  // fonction membre de verification des inputs
  void  SetVerifCenter();
  //
  CATDomain * TopoMerge (CATDomain * iCntManif, CATDomain * iProfManif, CATDomain * iManifold);

  //  Methods involved in extapolating limiting faces
  void ComputeExtrusionBox(
    CATMathBox  &ioBoxToSpan );
  void ComputeExtrapolatedLimits(
    CATSurface   * iSurface,
    CATSurLimits & iFacesLimits,
    CATSurLimits & oNewSurLimits );

  // Utilitaries methods
  void ProjectPointOnPCurve ( CATGeoFactory            *  iGeoFactory            , 
                              CATSoftwareConfiguration *  iSoftwareConfiguration ,
                              const CATMathPoint       &  iPointToProject        ,
                              const CATPCurve          *  iPCurve                ,
                              CATCrvParam              &  oCurrentCrvParam       ,
                              double                   &  oDistance              ,
                              CATError                 *& oError                 );

  void ProjectPointOnPlane ( CATGeoFactory            *  iGeoFactory            , 
                             CATSoftwareConfiguration *  iSoftwareConfiguration ,
                             const CATMathPoint       &  iPointToProject        ,
                             const CATPlane           *  iPlane                 ,
                             CATSurParam              &  oCurrentSurParam       ,
                             CATError                 *& oError                 );

  void ProjectLineOnPlane ( CATGeoFactory            *  iGeoFactory            , 
                            CATSoftwareConfiguration *  iSoftwareConfiguration ,
                            const CATPlane           *  iPlane                 ,
                            CATPCurve                *& oPCurveAxis            ,
                            CATError                 *& oError                 );

 void IntersectPLinePLine ( CATGeoFactory            *  iGeoFactory              , 
                            CATSoftwareConfiguration *  iSoftwareConfiguration   ,
                            const CATPCurve          *  iExtrapolatedPLine       ,
                            const CATCrvLimits       &  iExtrapolatedPLineLimits ,
                            const CATPCurve          *  iDecisionPLine           ,
                            const CATCrvLimits       &  iDecisionPLineLimits     ,
                            CATCrvParam              &  oDecisionCrvParam        ,
                            CATError                 *& oError                   );

 /**	@nodoc @nocgmitf */ 
 static const  CATString  *GetDefaultOperatorId();

 /**	@nodoc @nocgmitf */
 static  CATString  _OperatorId;

  // Donnees membres
  //----------------
protected:
  //
  CATMathLine _MainLine;
  CATAngle    _StartAngle;
  CATAngle    _EndAngle;
  CATBoolean  _IsCntClosed;
  CATBoolean  _IsHalfRadShiftApplied;
  CATBoolean  _IsHalfRadShiftRequested;
  CATBoolean  _UsingOriginalLimits;

  double _ExtrudeLimitAngleOffset[2];
  //
  // Cellules qui renconrtent l'axe
  ListPOfCATCell        _DegenerateCells;

  // Cellules relimitees pour que la surface de revolution ne soit pas twistee
  ListPOfCATCell        _RelimitedEdges;
  CATLISTP(CATCrvParam) _StartParams, _EndParams;

  // Material side
  CATSide _MatterSide;

   CATBody           * _LimitBodyForAngle[2];
   CATBoolean          _ClearLimitBodyForAngle;
};
#endif

