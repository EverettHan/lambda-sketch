// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATFrFCoupling:
// Interface class of FrF Coupling Object.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Coupling or derived
// in order to implement specific algorithm or capabilities.
//
//==========================================================================
// May   97 tpg Creation                                          Tuan Phung
// 30 03 99 NLD Ajout SetPreviousPointMemorization
// 24 01 00 DHN Ajout Eval + FirstDeriv
// 08 02 00 CPL Ajout SecondDeriv + index
// 05 03 01 JSX Ajout SetContinuityAtImposedPoints()
// 20 03 01 NLD Ajout GetCouplingPlane()
// 15 02 02 JSX Ajout SetSoftwareConfiguration()
// 01 08 02 JSX Ajout GetSoftwareConfiguration()... A cause des CreateXXXXMultishapes
//                    qui fond un peu trop de choses
// 01 02 03 JSX Remaniement des classes dérivees
// 07 06 03 JSX Ajout SetDomains et Set/GetWorkingDomainIndex (en activant NewDomainArchi)
// 11 09 03 JSX Activation definitive de NewDomainArchi
//              Nouvelle methode GetNonC2Params Pour le C1
// 05 05 04 JSX Ajout argument de domaine a GetContinuityParams
// 06 08 04 JSX Ajout de OrderIndexAndParam
// 20 06 06 JSX Ajout de GetLaw
// 30 11 06 JSX Ajout de SetImposedPointMode
// 27/02/07 NLD Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 28/02/06 NLD Ajout des constructeurs
// 06/0+/07 JSX Ajout de SetExternalLaw
// 19/11/09 NLD Ajout d'un nouveau EvalCouplingParameters() 
//              avec index de CCV rendant un indicateur oNoSolution,
//              pour eviter la generation d'exception
// 31/05/12 NLD Le destructeur est mis en protected pour privilégier Remove()
// 14/11/12 NLD Mise au propre. Smart indent
// 06/03/14 NLD Ajout AddImposedPointsIso()
// 06/04/16 NLD Reordonnancements logiques
//              Mise au clair des notations
//              - iCurveIndex remplace iCurveNumber pour les index commencant a 0
//              - oCurveIndex remplace oCurveNumber pour les index commencant a 0
//              Un peu d'eclaircissements sur les polydomaines
// 31/03/22 JSX Ajout ComputeReparametrizedCCVs
//==========================================================================

#ifndef CATFrFCoupling_H
#define CATFrFCoupling_H

#include "FrFAdvancedObjects.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATFrFCCvParam.h"

#include "CreateFrFCoupling.h"
#include "CATCouplingType.h"

#include "CATMathDef.h"
#include "CATCGMVirtual.h"
#include "CATFrFObject.h"

class CATMathPoint;
class CATMathVector;
class CATMathPlane;
class CATMathInterval;
class CATCurve;
class CATCrvParam;
class CATFrFCompositeCurve;
class CATFrFCCvParam;
class CATFrFCCvLimits;
class CATFrFSetOfGuides;
class CATSoftwareConfiguration;
class CATLaw;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFCoupling : public CATFrFObject
{
CATCGMVirtualDeclareClass(CATFrFCoupling);
  friend ExportedByFrFAdvancedObjects void Remove(CATFrFCoupling *& ioCoupling );

  protected :

  virtual                             ~CATFrFCoupling      ();

  public :

                                       CATFrFCoupling      () ;

                                       CATFrFCoupling      (      CATFrFObject                   & iFrFObject      ) ;



          //
          // Get coupling type (see CATCouplingType.h)
          //
  virtual       void                   GetType             (      CATCouplingType                & oCouplingType   ) const = 0;

          //
          // Get number of Curve or CompositeCurve
          //
  virtual       CATLONG32              GetNumberOfCurve    ()                                                        const = 0;

          //
          //  Get One CompositeCurve 
          //
  virtual const CATFrFCompositeCurve * GetOneCompositeCurve(const CATLONG32                        iIndex          ) const = 0;

  
          //
          //  Get Curve (or CompositeCurve) Orientation 
          //
  virtual const CATLONG32              GetCurveOrientation (const CATLONG32                        iCurveIndex     ) const = 0;

          //
          //  Set Curve (or CompositeCurve) Orientation 
          //
  virtual       void                   SetCurveOrientation (const CATLONG32                        iCurveIndex     ,
                                                            const CATLONG32                        iOrientation    )       = 0;

          //
          // Get Curve (or CompositeCurve) Orientation respecting MovingFrame
          //
  virtual       CATLONG32              GetOrientationOfCcv (      CATLONG32                        iIndex          ) const = 0;

          //
          // Set Curve (or CompositeCurve) Orientation respecting MovingFrame
          //
  virtual       void                   SetOrientationOfCcv (      CATLONG32                        iIndex          ,
                                                                  CATLONG32                        iComputedOrientationBetweenGuideAndMv
                                                           )                                                         const = 0;


          //
          // SetImposedPointMode (only for IMPOSED_POINTS Coupling)
          // iMode : = 0 CouplingPoint classique
          // iMode : = 1 couplingDevelop
          // iMode   = 2 couplingNoTwist
          // iRelimMode[2] : On each extremity
          //       : = 0 : until First(Last) vertices
          //         = 1 : Until First(Last) iCurve[] vertices
          //         = 2 : Best solution (Automatic selection of the curve to reduce)
  virtual       void                   SetImposedPointMode (      CATLONG32                        iMode           ,
                                                                  CATLONG32                        iRelimMode[2]   ,
                                                                  CATLONG32                        iCurve    [2]   )       = 0;


          //
          // Get Total Length
          //
  virtual       double                 GetTotalLength      ()                                                        const = 0;


          //
          // Domains 
          // -------

          //
          //  Get Coupling Domain 
          //
  virtual const CATMathInterval      * GetCouplingDomain   ()                                                        const = 0;

          // Set for each domain and each guide the index of curves to use  
          // { D1G1Index1, D1G2Index2,      DnG1Index1, ../.. DnGmIndexm} 
          // 
  virtual       void                   SetDomains          (      CATMathInterval               *  iDomains        ,
                                                                  CATLONG32                        iNbDomains      ,
                                                                  CATListOfInt                   & iCrvIndexLow    ,
                                                                  CATListOfInt                   & iCrvIndexHigh   )       = 0;
          //
          // To use after SetDomains
          //
  virtual       void                   SetWorkingDomainIndex(     CATLONG32                        iDomainIndex    )       = 0;
  virtual       CATLONG32              GetWorkingDomainIndex()                                                       const = 0;
 
          //
          // Polydomains management (????)
          //
          // on pourra se referer a CATCanonicProfileSweepCx2::G1ShapesConstruction()
          // pour quelques commentaires
          // (introduction des polydomaines, qui sont des regroupements de domaines, par JSX120405, pour le blend). NLD060416
          // (le blend utilise des lois C2 sur chaque polydomaine)
  virtual       void                   SetPolydomains        (    CATListOfInt                   & iPolydom        ,
                                                                  CATBoolean                       iClosed         )       = 0;

  virtual       void                   GetPolydomains        (    CATListOfInt                   & iPolydom        ,
                                                                  int                            & isClosed        )       = 0;

          // To use after SetPolydomains
  virtual       void                   SetWorkingPolydomainIndex( CATLONG32                        iDomainIndex    )       = 0;

  virtual       CATLONG32              GetWorkingPolydomainIndex(                                                  ) const = 0;


          // Continuity
          // ----------
  virtual       void                   GetContinuityParams   (    int                              iContinuity     ,
                                                                  CATListOfDouble                & ioParams        ,
                                                                  CATListOfInt                   & ioDomains       ,
                                                                  CATLONG32                        iIndexCCV       = -1,
                                                                  CATLONG32                        iIndexDom       = -1)   = 0;

  virtual       void                   OrderIndexAndParam    (    int                              sens            ,
                                                                  double                           TolW            ,
                                                                  CATListOfInt                   & ioDomains       ,
                                                                  CATListOfDouble                & ioParams        ) const = 0;

  
//
//  G E T   C O U P L I N G   P A R A M E T E R S   O N   C O M P O S I T E  C U R V E S
//

          // global numbering never to be changed               (global and stable numbering for generic class anc child classes)
          //                          EvalCouplingParameters_01 (global and stable numbering for generic class anc child classes)
  virtual      void                   EvalCouplingParameters(     double                           iT              ,
                                                                  CATLONG32                     *  oCurveIndex    ,
                                                                  CATCrvParam                   *  oCurveParam     ) const = 0;
  
          //                          EvalCouplingParameters_02 (global and stable numbering for generic class anc child classes)
  virtual      void                   EvalCouplingParameters(     double                           iT              ,
                                                                  CATFrFCCvParam                *  oCCvParam       ) const = 0;

          //
          //    On one CompositeCurve
          //
          //                          EvalCouplingParameters_03 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(     double                           iT              ,
                                                                  CATLONG32                        iCCvIndex       ,
                                                                  CATLONG32                      & oCurveIndex    ,
                                                                  CATCrvParam                    & oCurveParam     ) const = 0;

          // le meme sans generation d'exception
          //                          EvalCouplingParameters_04 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(     double                           iT              ,
                                                                  CATLONG32                        iCCvIndex       ,
                                                                  CATBoolean                     & oNoSolution     ,
                                                                  CATLONG32                      & oCurveIndex    ,
                                                                  CATCrvParam                    & oCurveParam     ) const = 0;
//
//
//    For INTERSECT coupling only ( more than one solution )
//

          //                          EvalCouplingParameters_05 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(     double                           iT              ,
                                                                  CATLONG32                        iCCvIndex       ,
                                                                  CATFrFCCvParam                 & oCCvParam       ,
                                                                  CATMathPoint                  *  iInitPt         ) const = 0;

          //                          EvalCouplingParameters_06 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(     double                           iT              ,
                                                                  CATLONG32                        iCCvIndex       ,
                                                                  CATLISTP(CATFrFCCvParam)       & oCCvParams      ) const = 0;

          //
          //    + Get Derivatives on CompositeCurves
          //
          //                          EvalCouplingParameters_07 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(     double                           iT              ,
                                                                  CATFrFCCvParam                *  oCCvParam       ,
                                                                  CATMathVector                 *  oFirstDers      ,
                                                                  CATMathVector                 *  oSecondDers     = 0
                                                                                                                   ) const = 0;

          //                          EvalCouplingParameters_08 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(     double                           iT              ,
                                                                  CATLONG32                        iCCvIndex       ,
                                                                  CATFrFCCvParam                 & oCCvParam       ,
                                                                  CATMathVector                 *  oFirstDers      ,
                                                                  CATMathVector                 *  oSecondDers     = 0
                                                                                                                   ) const = 0;
//
//
//    For IMPOSED_POINTS coupling
//

          //                          EvalCouplingParameters_09 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(const CATFrFCCvParam                & iCCvParam       ,
                                                                   CATLONG32                       iCCvIndex       ,
                                                                   CATFrFCCvParam                & oCCvParam       ) const = 0;

          //                          EvalCouplingParameters_10 (global and stable numbering for generic class anc child classes)
  virtual      CATBoolean             EvalCouplingParameters(const CATFrFCCvParam                & iCCvParam       ,
                                                                   CATFrFCCvParam               *  oCCvParams      ) const = 0;
  
//
//  INV EVAL  
//  
          //
          //  Get coupling parameter on one Curve of a CompositeCurve
          //
  virtual      CATBoolean          InvEvalCouplingParameters(      CATLONG32                       iCCvIndex       ,
                                                                   CATLONG32                       iCurveIndex     ,
                                                             const CATCrvParam                   * iCurveParam     ,
                                                                   double                       &  oT              ) const = 0;

          //  The result is given by the parameter of the CATFrFCCvParam
          //
 //////virtual CATBoolean          InvEvalCouplingParameters(      CATLONG32                       iCCvIndex,      
 //////                                                            CATFrFCCvParam                & ioCCvParam      ) const = 0;
//
//================================================================================================================  
//
// Specific method : do not use them on unknown type coupling  
//
//================================================================================================================  
//
//  CAUTION: All these methods are for INTERSECT coupling only
//  -------
          //
          //  GetCouplingPlane 
          //
  virtual      void                   GetCouplingPlane      (      CATMathPlane                  & oCouplingPlane  ) const = 0 ;

          //  Enables/disables previous point memorization when calling
          // several time same coupling; memorization should be enabled (default)
          // when a marching operator is used, and enabled when coupling is
          // called for isolated points
  virtual      void             SetPreviousPointMemorization(      CATBoolean                      iActive         )       = 0 ;

//
//  CAUTION: All these methods are for IMPOSED_POINTS COUPLING and CCV_PARAMETRIC coupling only
//  -------
          // GetLimits of the composite curves
          // 
  virtual      CATFrFCCvLimits*       GetLimits             ()                                                       const = 0;


//
//  CAUTION: All these methods are for IMPOSED_POINTS coupling only
//  -------
          //  Add imposed coupling points
          //  This methods adds a new set of imposed coupling points, checks their 
          //  order and replace (if  any) the old ones by the new ones.
          //  iCurveIndex and ICurveParam are [NbImposedPoints][NbCCv] arrays 
          //
  virtual      void                   AddImposedPoints      (const CATLONG32                       iNumberOfImposedPoints, 
                                                             const CATLONG32                    ** iCurveIndex     ,
                                                             const CATCrvParam                  ** iCurveParam     )       = 0;

  virtual      void                   AddImposedPoints      (const CATLONG32                       iNumberOfImposedPoints, 
                                                             const CATFrFCCvParam               ** iCCvParam       )       = 0;

          // Add imposed points at each composite curve limit, with isotopology hypothesis
  virtual      void                   AddImposedPointsIso   ()                                                             = 0;

          //
          //  Add one imposed coupling point (for ImposedPointsCoupling only)
          //  This methods add a new coupling point, in the right place in 
          //  the existing set of coupling points. An error is generated if
          //  the evaluated index for the new imposed point is not the same for
          //  all the CCvs (if there are crossing points).
          //
  virtual      void                   AddOneImposedPoint    (const CATFrFCCvParam               *  iCCvParam       )       = 0;

          //
          //  Get one coupling point
          //
  virtual      CATFrFCCvParam *       GetOneCouplingPoint   (const CATLONG32                       iIndex          ) const = 0;

          //
          //  Get all the coupling points - but the CCvLimits
          //
  virtual      CATFrFCCvParam**       GetCouplingPoints     ()                                                       const = 0 ;

          //
          //  Remove all the coupling points - but the CCvLimits
          //  
  virtual      void                   RemoveCouplingPoints  ()                                                             = 0 ;

          //
          //  Remove one coupling point
          //  
  virtual      void                   RemoveOneCouplingPoint(const CATLONG32                       iIndex      )           = 0;

          //
          //  Replace a coupling point in the set of existing coupling points
          //
  virtual      void                   ReplaceCouplingPoint  (const CATLONG32                       iIndex      ,
                                                             const CATFrFCCvParam               *  iCCvParam   )           = 0 ;

          //
          //  Get number of coupling points 
          //  (without the ccv limits, considered as coupling points)
          //
  virtual      CATLONG32              GetNumberOfCouplingPoints()                                                    const = 0;

          //
          //  Get Imposed Point Parameters
          //
  virtual      void                   GetImposedPointParameters(   CATLONG32                      & oNumberOfCouplingPoints,
                                                                   double                        *& oParams     )    const = 0;

          //
          //  Get the mappings
          //
  virtual      CATFrFCompositeCurveMapping ** GetMappings   ()                                                       const = 0;

          //
          //  SetLimits of the composite curves
          // 
  virtual      void                   SetLimits             (const CATFrFCCvLimits               *  iCCvLimits  )          = 0;

          //
          //  Set one limit on one composite curve
          //
  virtual      void                   SetOneLimit           (const CATLONG32                        iIndex      ,
                                                             const CATLONG32                        iExtremity  ,
                                                             const CATFrFCCvParam                 & iCCvParam   )          = 0;
          //
          //  Set Continuity
          //
          // Blend en Pointe            ==> iContinuityConf = 0
          // Coupling Sweep (pour nld)  ==> iContinuity     = 0
  virtual      void                   SetContinuityAtImposedPoints(CATLONG32                        iContinuity = 2,
                                                                   CATLONG32                        iContinuityConf = 1)   = 0;

          //
          //  Set Continuity at closure
  virtual      void                   SetContinuityAtClosure(      CATLONG32                        iContinuity = 2)       = 0;

          //
          //  Suppression des points de coupling SANS modification des lois de progression
          //  utilise pour le coupling develop = ne plus faire de set sur le coupling ensuite
          //
  virtual      void                   CleanCouplingPoints   ()                                                             = 0;

          //  On recupere le coupling sous la forme de lois : wMapping = Law( wCoupling) 
          //  Uniquement pour le couping en point imposé pour l'instant
  virtual      CATLaw**               GetLaw                (                                    )                         = 0;

          //  Opération Inverse
  virtual      void                   SetExternalLaw        (       CATLaw                       ** iLaw        )          = 0;


          //  Creation par fitting des ccv equivalentes composées de nurbs parametrées par le coupling
          //  Uniquement pour le couping en point imposé pour l'instant
  virtual      void                   ComputeReparametrizedCCVs(CATFrFCompositeCurve**& HomoCCV                  )         = 0;


};

#endif
