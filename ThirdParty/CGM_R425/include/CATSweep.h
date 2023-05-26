#ifndef CATSWEEP_H
#define CATSWEEP_H

// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
// Generic topology cells sweep engine for prism/revolution/sweep operators
//=============================================================================
//          CFT Creation
// 25 05 04 NLD Ajout de _ProfBodyDuplicated
// 08 07 05 NLD Ajout HealResult()
// 11 07 05 NLD Ajout _NbTwists, _NbWraps, _TwistDiags
//              Ajout _AvailableSweepHealer
// 02 08 05 NLD Ajout IsEdgeDegenerated() et optimisation des calculs de longueurs
// 22 12 05 NLD Ajout IsCheckTopoTwistActive()
// 12 01 06 NLD Ajout GetTwistReduction()
// 01 12 06 NLD Ajout de _TwistOrWrapVertices et GetTwistOrWrapVertices()
// 16 10 09 KY1 Integration Hidden Seam Cell Services :
//              Ajout de IsHiddenSeamCellProcessingRequired()
//              Ajout de HiddenSeamCellDecoration()
//              Ajout de HiddenSeamCellPropagation(...)
// 08 12 09 NLD Definition d'une nomenclature pour les classes utilitaires du sweep, la plupart exportees
//              SpecCell  devient CATSweepSpecCell
//              Tableau   devient CATSweepArrayOfSpecCell
//              Spec      devient CATSweepSpec
//              Brep      devient CATSweepBRep
//              BrepCell  devient CATSweepBRepCell
//              Journal   devient CATSweepJournal
// 23 02 10 NLD Ajout Init()
// 23 04 10 LAY Declare ConvertDimLimitToUntil method.
// 07 07 10 NLD Ajout IsRefPlaneSetByUser()
// 19 08 10 DLP ComputeExtrapolatedLimits() becomes virtual.
// 21 09 10 NLD Ajout CATSweepSubClass
// 30 09 10 DLP Add ComputeExtrapolatedMaxLimits() which is common to Prism and Revolve.
// 04 11 10 DLP Break up some of the profile extrapolation functions.
// 22 11 10 FDS Perfo, INLINE
// 03 12 10 NLD Ajout RunDiscontinuityMode()
//              SweepProfThinSolid() recoit son journal de travail iReport
//              SweepProfDuplicateSameEdgeCurve() aussi
// 06 12 10 NLD Ajout GetPreproReport()
// 17 06 11 NLD Ajout StoreLimit()
// 23 07 11 NLD SmartHeaderEdition: Reformatage complet
// 27/06/11 NLD Ajout _PreproReport, _DeletePreproReport, SetPreproReport()
// 31/01/12 JHN Ajout GetUntilOffset() and SecondUntilOffset()
// 01/02/12 NLD SmartHeaderEdition: 2nd pass on new methods
// 02/02/12 NLD Copy constructor forbidden and declared private
// 07/02/12 JHN Copy constructor + Duplicate()
// 14/02/12 NLD Init() receives an optional pointer on the object to copy and can be used
//              both for standard constructor and for copy constructor (through Duplicate())
//              SmartHeaderEdition: 3rd pass on new methods
// 08/10/12 THM Added GetExtrapolatedLimitBody() to allow wider access
// 08/01/13 G5S Introduce new methods to set the side and intersection number for the limits instead of
//              setting them through SetLimit.
// 08/01/13 THM Add _RelimJournalMode and set method SetRelimJournalMode()
// 27/02/19 thm Add GetDefaultRelimJournalMode()
// 04/03/13 NLD Review arguments list of new ThickBody() method
// 13/03/13 THM Add argument to GetNbContextuals() to optionally ignore virtual/both result
// 23/03/13 thm Remove GetUntilOffset() and SecondUntilOffset() methods
// 19/04/13 ky1 RequireDefinitionOfInputAndOutputObjects() + RunOperator()
// 02/05/13 G5S New method IsClosed() to tell us whether we have a closed sweep path.
//   /08/14 oid Add SetNamingLimitRequested(), SetExtrudeLimitNamingRequested(), GetExtrudeLimitNamingRequested(),
//                  GetSweepReferenceWire()
// 04/11/14 FDS "GetTopCellList" and "GetBottomCellList" method inline
// 16/12/14 NLD SmartHeaderEdition: 3rd pass on new methods
// 26/01/15 NLD IsEdgeDegenerated() gives back oError for secured exception treatment
// 14/09/15 G5S Rename SetProfile to SetProfileDynSweep so it doesn't conflict with what we want to do for the 
//                Fast Update Stress tests for Extrude.
// 10/12/15 THM LimitCellLists to give access to cells involved in the limit - supports Revol GetAngles.
// 07/04/16 THM Use LimitBodies instead of LimitCellLists - so virtual method used as Revol only functionality.
// 21/04/16 THM CheckProfileClosureOption() automatically switches off the option to close already closed profiles.
//   /02/17 oid Add SetWireLimitationAccepted()
// 07/06/17 thm Add GetRefPlaneOri()
//              Add GetUserRefPlane()
//              GetRefPlane() signature change
//   /06/17 thm Add GetExtrudeLimitAngleOffset(), ChangeLimitForAngleOffset()
//              Add ClearTemporaryBodies()
//              Add RemoveProfDuplicatedFromReport()
// 31/07/17 NLD SmartHeaderEdition: 4th pass on new methods
//              Post cleanup and comment of 2014 to 2017 changes
// 12/09/17 THM Overload GetBottomAndTopFullCellList in CATRevol
// 13/09/17 NLD Add ClearFillReportDeletion() for code isolation
// 14/06/18 NLD Add GetRelimJournalMode()
// 02/08/18 ky1 Changes in attributes management methods (comments NLD261118)
//              - CGMAttributeCellDecoration()             replaces HiddenSeamCellDecoration()
//              - CGMAttributeCellPropagation()            replaces HiddenSeamCellPropagation()
//              - CGMAttributeCellPropagationInThinSolid() replaces HiddenSeamCellPropagationInThinSolid()
//              - SetCGMAttributeManagingDone()            replaces SetHiddenSeamCellProcessingDone()
//              - HasCGMAttributeManagingDone()            replaces HasHiddenSeamCellProcessingDone()
//              - _IsHiddenSeamCellProcessingRequired      suppressed
//              - _HasHiddenSeamCellProcessingDone         suppressed
// 30/08/18 G5S When we do a Revol with a contextual limit with an offset in the surfacic case, 
//              record the fact that we're converting it to a wire limit.
// 12/03/20 NLD Ajout RunDiscontinuityCreateBody()
// 13/03/20 NLD RunDiscontinuityMode() rend l'erreur
//              Ajout RunReport()
// 23/03/20 NLD Ajout RunDiscontinuityShunt()
// 27/03/20 NLD Ajout RunCheckOperands() et RunHiddenSeamCells()
//              Ajout RunTrace()
//              Ajout RunStandardMode()
//              Ajout RunCGMAttributeManagingDone()
//=============================================================================
#include "BO0SWEEP.h"
#include "CATSweepBasic.h"

#include "CATMathDef.h"
#include "CATMathInline.h"
#include "CATMathPlane.h"

#include "CATCell.h"
#include "ListPOfCATCell.h"

#include "CATTopData.h"

#include "CATSweepLimit.h"

#include "CATTopOperator.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATDomain.h"
#include "CATListOfCATCrvLimits.h"
#include "CATExtrudeLimitThicknessOrOffsetType.h"
#include "CATExtTopOperator.h"
#include "CATTopCGMAttributeLabel.h"
//=============================================================================

//=============================================================================
// CLASSES
class CATGeoFactory;
//
class CATSweepSpecCell;
class CATSweepSpec;
class CATSweepBRepCell;
class CATSweepBRep;
class CATSweepJournal;
class CATSweepSubClass;
class CATSweep2;
class CATSweepGeo2Def;
class CATExtrapolateBody;
//
class CATBody;
class CATDomain;
class CATEdge;
class CATFace;
class CATLoop;
//
class CATSurface;
class CATSurParam;
class CATSurLimits;
class CATCrvLimits;
//
class CATCGMJournalList;
class CATCGMActivateDebug;
class CATCGMDiagnosis;
//
class CATMathTransformation;
class CATSweepReferenceWire;
//=============================================================================

//static CATBoolean NewUpToPlane ();

class ExportedByBO0SWEEP CATSweep : public CATSweepBasic
{
  friend class CATSweep2;
  friend class CATSweepSubClass;

  // Methodes publiques
  //-------------------
public:


  // constructeur a partir d'un CATBody
                              CATSweep                         (      CATGeoFactory        *  iGeoFactory                  ,
                                                                      CATTopData           *  iData                        ,
                                                                      CATBody              *  iProfBody                    ,
                                                                      CATBody              *  iCntContour                  );

  // constructeur a partir d'un CATBody (DEPRECATED: use constructor with CATTopData)
                              CATSweep                         (      CATGeoFactory        *  iGeoFactory                  ,
                                                                      CATBody              *  iProfBody                    ,
                                                                      CATBody              *  iCntContour                  ,
                                                                      CATCGMJournalList    *  iReport                      = NULL);

  // edition des limitantes
          void                SetLimit                         (      CATLimit                iId                          ,
                                                                      CATLimitType            iType                        ,
                                                                      CATBoolean              iIsAxisReverted              ,
                                                                      CATLength               iOffset                      ,
                                                                      CATGeometry          *  iLimit                       ,
                                                                      CATBody              *  iPropagationBody             ,
                                                                      CATPropagationType      iPropagationFlag             ,
                                                                      CATBoolean              iIsThickness                 = CATBoolean(0),
                                                                      CATBoolean              iIsConvertedFromContextualOffset = FALSE);
          //(same with a list of cells as limit)
          void                SetLimit                         (      CATLimit                iId                          ,
                                                                      CATLimitType            iType                        ,
                                                                      CATBoolean              iIsAxisReverted              ,
                                                                      CATLength               iOffset                      ,
                                                                      ListPOfCATCell        & iLimit                       ,
                                                                      CATBody              *  iPropagationBody             ,
                                                                      CATPropagationType      iPropagationFlag             ,
                                                                      CATBoolean              iIsThickness                 = CATBoolean(0),
                                                                      CATBoolean              iIsConvertedFromContextualOffset = FALSE);
          
          void                SetLimitThickness                (      CATLimit                iId,
                                                                      CATLength               iThickness,
                                                                      CATExtrudeLimitThicknessOrOffsetType iThicknessOrOffsetType );

          CATSweepLimit     * GetLimit                         (      CATLimit                iId                          );

          void                SetExtrudeLimitSide              (      CATLimit                iId                          ,
                                                                      CATExtrudeLimitSide     iSide                        );

          void                SetExtrudeLimitIntersectionNumber(      CATLimit                iId                          ,
                                                                      int                   * iIntersectionNumber          );

          void                SetNamingLimitRequested          (      CATBoolean              iRequested                   );

          void                SetExtrudeLimitNamingRequested   (      CATLimit                iId                          ,
                                                                      CATBoolean              iRequested                   );

          CATBoolean          GetExtrudeLimitNamingRequested   (      CATLimit                iId                          );

          CATBoolean          GetExtrudeLimitNamingRequested   ( );

          CATSweepReferenceWire * GetSweepReferenceWire        (      CATLimit                iId                          );

          void                GetExtrudeLimitNaming            (      CATLimit                iId                          ,
                                                                      CATLISTP(CATExtrudeLimitName)
                                                                                            * oPossibleLimits              );

          void                GetExtrudeLimitNaming            (      CATLimit                iId                          ,
                                                                      CATListPV             * oPossibleLimits              );


  virtual double              GetExtrudeLimitAngleOffset       (      CATLimit                iId                          );

  virtual void                ApplyAngleOffsetToLimit          (      CATLimit                iId                          ) {};

  // Find out whether the extrusion direction was automatically inverted.
          CATBoolean          GetAxisWasAutoInverted           ();

  // avec extrapolation et fermeture du profile
  virtual void                SetProfile                       (      CATBody              *  iProfBody                    );

  virtual void                SetProfileDynSweep               (      CATBody              *  iProfBody                    );

          void                SetProfileClosure                (      CATBoolean              iToClose                     ,
                                                                      CATBody              *  iTrimBody                    );

  INLINE  CATBoolean          GetProfileClosure                ();

  INLINE  CATBoolean          IsSelfClosedProfileInversionCase ();

  // avec operation booleenne
          void                SetBoolean                       (      CATBoolType             iBoolType                    ,
                                                                      CATBody              *  iTrimBody                    );

  INLINE  void                SetVirtualBoolean                ();

  INLINE  void                SetBothResult                    ();

  virtual void                SetOldShapeRequested             ();

  virtual void                SetRelimitationMode              (      short                   iMode                        ,
                                                                      short                   iAutomaticDirectionInversion = 1);

  virtual short               GetRelimitationMode              ();

  static  short               GetDefaultRelimitationMode       (      short                   iCGMLevel                    );

  static  short               GetDefaultRelimJournalMode       (      short                   iCGMLevel                    );

          void                SetDiscontinuityTreatment        (      CATLONG32               iMode                        = 0);

          void                SetCuspTreatment                 (      CATLONG32               iMode                        = 0);

  INLINE  void                SetReversePolarity               (      CATBoolean              iPolarity                    );

  INLINE  void                GetReversePolarity               (      CATBoolean            & oPolarity                    );

  INLINE  CATBoolean          IsClosed                         ();

          void                UnsetCheckTopoTwist              (      CATBoolean              iUnsetCheckTopoTwist         = CATBoolean(1));

          CATBoolean          IsCheckTopoTwistActive           () ;

          void                SetSimplification                (      CATBoolean              iSimplify                    = CATBoolean(1));

  INLINE  void                SetFreezeMode                    (      CATBoolean              iFreezeMode                  = CATBoolean(1));

          CATBody           * GetBoolean                       (      CATBoolType           & oBoolType                    );

  INLINE  CATBoolean          IsOperationVirtual               ();

  INLINE  CATBoolean          IsBothResult                     ();

  // destructeur
  virtual                    ~CATSweep                         ();

  // fonction membre de construction du Brep
          int                 Run                              () ;

          int                 RunDiscontinuityMode             (      CATBoolean            & oDiscontinuityTreatmentModeAvailable,
                                                                      CATError             *& oError                       );

          int                 RunStandardMode                  (      CATBoolean              HasRealContextual            ,
                                                                      CATError             *& oError                       );

          void                RunDiscontinuityShunt            (const CATListPV             & C0Vertices                   ,
                                                                      CATBoolean            & oDiscontinuityTreatmentModeAvailable);

          void                RunReport                        (      CATBoolean              iHasContextualLimits         );

  // fonction membre de verification des inputs
  virtual void                GetProfileCell                   (      ListPOfCATCell        & ListNewCell                  ,
                                                                      ListPOfCATCell        & ListOldCell                  );

  // Gestion du plan de reference necessaire au positionnement du profil pour la relimitation
  // ( par default c'est la position du profil )
          void                SetRefPlane                      (      CATMathPlane          & iRefPlane                    );

          int                 IsRefPlaneSetByUser              ();

          int                 GetUserRefPlane                  (      CATMathPlane          & oRefPlane                    );

  virtual void                GetRefPlane                      (      CATMathPlane          & oRefPlane                    ,
                                                                      int                  *  oIsRefPlaneDefinedByUser     = NULL );

  virtual void                SetVerifCenter                   ();

  virtual void                SetVerifProfile                  ();

  // Gestion solide mince
  // - si IsNeutralFiber est vrai , seul ThinSolidThickness[0] compte.
  // - si IsNeutralFiber est faux , les 2 epaisseurs comptent.
  // ( 1er epaisseur suivant MatterSide , 2e epaisseur a l'oppose )
  // - ThinSolidMode vrai associe a SetProfileClosure() permet de relimiter un profil ouvert
  // sur les bords ( relimitation des nervures au bord et entre elles )
          CATBoolean          GetThinSolidMode                 (      CATBoolean            & oIsNeutralFiber              ,
                                                                      double                  oThinSolidThickness[2]      ,
                                                                      ListPOfCATDomain     *  oWireListWithReverseThinSolidSide = NULL
                                                               ) const;

          void                SetThinSolidMode                 ( const CATBoolean             iThinSolidMode               ,
                                                                 const CATBoolean             iIsNeutralFiber              ,
                                                                 const double                 iThinSolidThickness[2]       ,
                                                                       ListPOfCATDomain    *  iWireListWithReverseThinSolidSide = NULL );

  // fonction membre de verification du Brep
          void                SetVerifOutput                   () ;

          void                SetTwistReduction                (       CATBoolean             iTwistReduction              = 0);

          void                GetTwistReduction                (       CATBoolean           & oTwistReduction              ) ;

          void                TwistReduction();

  // fonction membre de recuperation du journal topologique
          CATCGMJournalList * GetTopReport                     ();

          CATCGMJournalList * GetBooleanTopReport              ();

  // Obtention du journal topologique pour les ordres de preprocessing
          CATCGMJournalList * GetPreproReport                  ();

  // Définition du journal topologique pour les ordres de preprocessing
          void                SetPreproReport                  (      CATCGMJournalList    *  iPreproReport                );

  // fonction membre de recuperation du resultat
          CATBody           * GetBooleanResult                 () ;

  INLINE  CATBoolean          InvariantResult                  ();

  // reperage (hors journal) d'une cellule Top, d'une cellule Bottom
  // sur le Brep genere par domaine
  INLINE  ListPOfCATCell      GetTopCellList                   ();

  INLINE  ListPOfCATCell      GetBottomCellList                ();

  virtual void                GetBottomAndTopFullCellList      ( const int                    iCurDomain                   ,
                                                                       ListPOfCATCell       & oBottomCellsList             ,
                                                                       ListPOfCATCell       & oTopCellsList                );

          void                GetBodyExtremities               (       CATBody             *  iBody                        ,
                                                                       CATVertex           *& oStartVertex                 ,
                                                                       CATEdge             *& oStartEdge                   ,
                                                                       CATSide              & oStartSide                   ,
                                                                       CATVertex           *& oEndVertex                   ,
                                                                       CATEdge             *& oEndEdge                     ,
                                                                       CATSide              & oEndSide                     );

          void                GetLength                        ( const CATMathPoint         & iOrigin                      ,
                                                                 const CATMathDirection     & iDirection                   ,
                                                                       double               & oLengthMin                   ,
                                                                       double               & oLengthMax                   );

  // Obtention des vertex de la guide correspondant aux twists ou rebroussements topologiques
          void                GetTwistOrWrapVertices           (       ListPOfCATVertex     & oTwistOrWrapVertices         ) ;

  // CGM Atribute Management : Hidden Seam & Imprint
  // Check if Hidden Seam Cell Processing is necessary or not (KY1)
          CATTopCGMAttributeLabel
                              GetCGMAttributeCellManagingRequired();

  // Decoration of Result Body by Hidden Seam Cell attributes  in the case of Revol 0-360 without Boolean Operation (KY1)
          void                CGMAttributeCellDecoration       (      CATTopCGMAttributeLabel iCGMAttributeLabel);

  // Propagation of Hidden Seam Cell attributes in Result Body in the case of Revol 0-360 with    Boolean Operation if 1st Arg= FALSE
  // otherwise propagation of Hidden Seam Cell attributes in Boolean Result Body (KY1)
          void                CGMAttributeCellPropagation      (      CATTopCGMAttributeLabel iCGMAttributeLabel,
                                                                      CATBoolean              IsHSPropagationAlsoInResultBody);

          void                CGMAttributeCellPropagationInThinSolid( CATTopCGMAttributeLabel iCGMAttributeLabel);
  //
          void                SetCGMAttributeManagingDone      (      CATTopCGMAttributeLabel iCGMAttributeLabel);

  INLINE  int                 HasCGMAttributeManagingDone      (      CATTopCGMAttributeLabel iCGMAttributeLabel);
  //
          void                SetNoRelimitationByBooleanBody   (       CATBoolean             iNoRelimitationByBooleanBody );

  // For CATTopRevol, the deprecated SetLimit() does not provide a way of setting 'IsAxisReverted'.
  // If this is called, we must deduce the correct setting to retain the old behaviour. Do not use.
  INLINE  void                SetInferLimitAxisDirection       (       CATBoolean             iInferLimitAxisDirection     );

          CATBody           * GetExtrapolatedLimitBody         (       CATLimit               iLimit                       );

  static  CATBody           * DuplicateBodyForSweepOp          (       CATTopOperator      *  iTopOperator                 ,
                                                                       CATBody             *  iBodyToDuplicate             );

          void                SetRelimJournalMode              (       short                  iRelimJournalMode            );

          short               GetRelimJournalMode              ();


          void                GetLimitCellList                 (       CATLimit               iId,
                                                                       CATLISTP(CATCell)    & oLimitCellList               );

  // Wether we authorize to have a wire as limiting geometry in surfacic cases
          void                SetWireLimitationAccepted        (      CATBoolean              iWireLimitationAccepted      );

  // Donnees membres
  //----------------
protected:

// Donnees membres
//----------------
  CATBoolean                    _DeleteBooleanReport;
  CATCGMJournalList           * _BooleanReport;
  CATBoolean                    _DeletePreproReport;
  CATCGMJournalList           * _PreproReport;

  CATGeoFactory               * _ImplFactory;

  CATBody                     * _ProfBodyDuplicated;

  // limitante du profile
  CATBoolean                    _ToClose;
  CATBoolean                    _SelfClosedProfileInversionCase;
  CATSweepLimit               * _LimitProfile[4];

  // limitantes dy sweep
  CATSweepLimit               * _Limit[4];

  // operation booleenne associee
  SweepOper                   * _Operation;
  CATBoolean                    _OperationVirtual;
  CATBoolean                    _BothResult;

  // reperage d'une cellule Top et d'une cellule Bottom
  ListPOfCATCell                _TopBCellList;
  ListPOfCATCell                _BottomBCellList;

  // body resultat
  CATBody                     * _BooleanResultBody;
  CATBoolean                    _InvariantResult;
  CATBoolean                    _OldShapeRequested;
  CATBoolean                    _UnsetCheckTopoTwist;
  CATBoolean                    _Simplify;

  // donnees pour thin solid
  CATBoolean                    _IsNeutralFiber;
  double                        _ThinSolidThickness[2];
  ListPOfCATDomain              _WireListWithReverseThinSolidSide;

  // gestion du nouveau mode d'extrude
  //  CATBoolean               _OldExtrusionMode; // variable obsolete
  // N.B #define pour analyseur de syntaxe de Sniff
  short                         _RelimitationMode;
  short                         _AutomaticDirectionInversion;
  CATBoolean                    _ReversePolarity;

  short                         _RelimJournalMode;
  
  // memorisation des cellules originelles et des cellules d'extrapolation
  ListPOfCATCell                _ListOriginalCell;
  ListPOfCATCell                _ListExtrapolationCell;

  // Mode de traitement des rebroussements
  CATLONG32                     _CuspTreatmentMode;

  // Mode de traitement des twists pour Electrical
  CATBoolean                    _TwistReduction;

  // Variable pour forcer le plan de reference ( pour definir une origine et un sens a la relimitation )
  int                           _IsRefPlaneDefinedByUser;
  CATMathPlane                  _RefMathPlane;

  // Diagnostics
  int                           _NbTwists ;
  int                           _NbWraps ;
  // N.B #define pour analyseur de syntaxe de Sniff
  #define CATSweep_ListPOfCATCGMDiagnosis  CATLISTP(CATCGMDiagnosis)
  CATSweep_ListPOfCATCGMDiagnosis  _TwistDiags ;
  CATBoolean                    _AvailableSweepHealer ;

  ListPOfCATVertex              _TwistOrWrapVertices ;

  // Variables pour le nouveau mode de traitement des discontinuites
  CATListOfInt                  _CuspIndices;
  ListPOfCATEdge                _MyListCntEdge;
  // N.B #define pour analyseur de syntaxe de Sniff
  #define CATSweep_ListPOfCATCrvLimits CATLISTP(CATCrvLimits)
  CATSweep_ListPOfCATCrvLimits  _MyListCntCrvLimits;
  CATListOfInt                  _ClosedWADOC;

  CATBoolean                    _InferLimitAxisDirection;

  CATBoolean                    _NoRelimitationByBooleanBody;

  CATBoolean                   _ConvertDimLimitToUntil;
  CATBoolean                   _IsWireLimitationAccepted;

  // Méthodes internes
  // -----------------

  /**  @nodoc @nocgmitf */
  void                        RequireDefinitionOfInputAndOutputObjects();


protected:

          void                Init                             (const CATSweep             *  iInitialSweep                = NULL);

  // nettoyage de l'environnement
  virtual void                Clear                            ();

          void                ClearTemporaryBodies             ();

          void                ClearFillReportDeletion          (      CATCGMJournalList    * RemoveJournal                 );

  // Creation d'une center curve bidon
  virtual CATBody           * SweepCnt                         (      CATGeoFactory        *  iGeoFactory                  );

  virtual CATBody           * SweepProf                        (      CATGeoFactory        *  iGeoFactory                  );

          CATBody           * SweepProfThinSolid               (      CATGeoFactory        *  iGeoFactory                  ,
                                                                      CATCGMJournalList    *  iReport                      );

          void                SweepProfDuplicateSameEdgeCurve  (      CATGeoFactory        *  iGeoFactory                  ,
                                                                      CATCGMJournalList    *  iReport                      ,
                                                                      CATBody              *& Result                       );

          void                RemoveProfDuplicatedFromReport   ();

  // methodes de gestion
          CATCell           * GetAssociateCntBrep              (      CATDomain            *  iProfDom                     ,
                                                                      CATCell              *  iCntCell                     );

          CATCell           * GetAssociateProfBrep             (      CATCell              *  iProfCell                    );

          void                SetLimitBrep                     (      CATCGMJournalList    *  iReport                      = NULL);

          void                GetCenterExtremities             (      CATVertex            *& oStartVertex                 ,
                                                                      CATVertex            *& oEndVertex                   );

          void                GetProfileExtremities            (      CATVertex            *& oStartVertex                 ,
                                                                      CATEdge              *& oStartEdge                   ,
                                                                      CATSide               & oStartSide                   ,
                                                                      CATVertex            *& oEndVertex                   ,
                                                                      CATEdge              *& oEndEdge                     ,
                                                                      CATSide               & oEndSide                     );

          CATSurface        * GetBodyCommonSupport             (      CATBody              *  iBody                        );

  virtual int                 GetRefPlaneOri                   (      CATMathPoint         &  ioOrigin,
                                                                      CATMathDirection     &  iNormal                      );

 // Gestion des degenerescences du profile
  virtual void                PostGeoExtrude                   ();

  // Gestion de la non-isotopologie
  virtual void                NonIsoExtrude                    ();

  virtual void                GetCenterEdgeLimits              (      CATEdge              *  iCntEdge                     ,
                                                                      CATCrvLimits          & ioCenterEdgeLimits           );

  // methodes pour extrapoler le center contour
  virtual void                CenterExtrapole                  ();

  // methodes pour extrapoler le profile body
  virtual CATBody           * ProfileExtrapole                 (      CATBody              *  iBody                        );

          CATBody           * ProfileExtrapoleBasic            (      CATBody              *  iBody                        ,
                                                                      double                  iExtraLength                 = 0.0);

  virtual void                ProfileExtrapoleSetOperatorOptions(     CATSweepLimit        *  iLimit                       ,
                                                                      CATVertex            *  iExtremityVertex             ,
                                                                      CATEdge              *  iExtremityEdge               ,
                                                                      CATBody              *  iBody                        ,
                                                                      double                  iMinimumGap                  ,
                                                                      CATMathBox            & iSourceBox                   ,
                                                                      CATMathBox            & iBoxSpace                    ,
                                                                      CATMathPlane          & iPlaneSpace                  ,
                                                                      CATMathLine           & iLineSpace                   ,
                                                                      CATMathDirection      & iDirSpace                    ,
                                                                      CATExtrapolateBody    & ioExtraOperator              );

          int                 GetLimitGeometryAndPlane         (      CATSweepLimit        *  iLimit                       ,
                                                                      CATGeometry          *& oGeometry                    ,
                                                                      CATMathPlane          & oPlane                       );

  // method to close profile body
  virtual CATBody           * ProfileClose                     (      CATBody              *  iBody                        );

  // method to prevent attempting to close an already closed profile
          void                CheckProfileClosureOption();

  // methode pour prendre le body complémentaire
  virtual CATBody           * ComplementBody                   (      CATBody              *  iBody                        );

  // methodes pour relimiter le sweep
          void                ConvertGeoLimitIntoTopo          (      CATCGMJournalList    *  iReport                      );

          CATLONG32           GetNbContextuals                 (      CATBoolean              iAddForVirtual               = TRUE);

          CATLONG32           GetRelimitationLevel             ();

  // For CATTopRevol case, if the deprecated SetLimit is used we must deduce the axis direction.
  INLINE  CATBoolean          GetInferLimitAxisDirection       ();

          void                InferLimitAxisDirection          ();

  //      void                Boolean ();

          void                NewBoolean                       (      CATCGMJournalList    *  iReport                      );

          int                 RelimitAnalyse                   ();

          CATBody           * RelimitSplit                     (      CATCGMJournalList    *  iReport                      );

          CATBody           * RelimitThickness                 (      CATCGMJournalList    *  iReport                      );

          CATBody           * RelimitBoolean                   (      CATCGMJournalList    *  iReport                      );

          void                CreateSweepRefWires              (      CATTopData           &  iTopData                     );

          void                CreateSweepRefWire               (      CATTopData           &  iTopData                     ,
                                                                      CATSweepLimit        *  iLimit                       ,
                                                                      CATLimit                iLimitType                   );
          
  // If mixed dimension/contextual extrusion limits are supplied, it is sometimes
  // convenient to convert the dimension limit to an internal until limit.
          void                ConvertDimLimitToUntil           ();

  // Whether to convert the dimension limit to an until limit.
  virtual CATBoolean          ShouldConvertDimLimitToUntil     ();
  
  // Set the option to convert the dimension limit to an until limit.
           void               SetConvertDimLimitToUntil        (       CATBoolean             iConvertDimLimitToUntil      );

   virtual void               SetLimitBodyForAngle             (       CATLimit               iId                          ,
                                                                       CATBody              * iLimitBodyForAngle           );

  virtual CATMathTransformation*
                              GetProfileOffsetTransformation   (      CATLength               iOffset                      );

          void                CorrectJournalsFromConvertedLimit(      CATCGMJournalList    *  iReport                      );

  // methodes pour propagation extrapolee
          void                StoreLimit                       (      CATSweepLimit        *  iLimit                       ,
                                                                      CATLimit                iId                          );

          CATBoolean          HasExtrapolUntilLimit            ();

          void                ExtrapolUntilLimit               ();

          CATBody           * GetExtrapolatedLimitBody         (      CATLimit                iLimit                       ,
                                                                      CATGeometry           * iLastLimitExtrapolated       ,
                                                                      CATBody               * iLastLimitExtrapolBody       ,
                                                                      CATLISTP(CATGeometry) & oInput                       );

          void                ComputeExtrusionBoxSweep         (      CATMathBox            & ioBoxToSpan                  );

  virtual void                ComputeExtrapolatedLimits        (      CATSurface           *  iSurface                     ,
                                                                      CATSurLimits          & iFacesLimits                 ,
                                                                      CATSurLimits          & oNewSurLimits                );

          void                ComputeExtrapolatedLimitsFromBox (      CATSurface           *  iSurface                     ,
                                                                      CATSurLimits          & iFacesLimits                 ,
                                                                const CATMathBox            & iBoxToSpan                   ,
                                                                      CATSurLimits          & oNewSurLimits                );

          void                ComputeExtrapolatedMaxLimits     (      CATSurface           *  iSurface                     ,
                                                                      CATSurLimits          & iFacesLimits                 ,
                                                                      CATSurLimits          & oNewSurLimits                );

  // ramassage des surfaces
          void                CoOperandsSurface                (      CATLISTP(CATSurface)  & ioListSurface                );

  // InitLimitForTopoExtrude
          void                InitLimitForTopoExtrude          ();

  // Check de twist topo
          void                CheckTopoTwist                   ();

  // Nettoyage topologique du resultat
          void                HealResult                       ();

  // Indique si une edge est degeneree
          CATBoolean          IsEdgeDegenerated                (      CATEdge              *  iEdge                        ,
                                                                      double                  iTolerance                   ,
                                                                      CATError             *& oError                       );
  /**  @nodoc @nocgmitf */
          int                 RunOperator                      ();

          void                RunTrace                         (      int                    iRunState                     );

          CATBody           * RunDiscontinuityCreateBody       (const CATBoolean              ManifoldWireIsClosed         ,
                                                                const CATBoolean              ExtrapolationOnClosure       ,
                                                                const int                     SpecialClosedCase            ,
                                                                const CATLONG32               NbEdges                      ,
                                                                const CATLISTP(CATEdge)     & EdgesList                    ,
                                                                const CATListOfInt          & OrientList                   ,
                                                                const CATLONG32               NbC1WiresByManifoldWire      ,
                                                                      CATCGMJournalList    *  GlobalReport                 ,
                                                                      CATVertex            *& oStartVertex                 ,
                                                                      CATVertex            *& oEndVertex                   );

          void                RunCheckOperands                 ();

          void                RunHiddenSeamCells               (      CATBody              *  ResultBodyBeforeRelimit      );

          void                RunCGMAttributeManagingDone      ();

          CATBody           * ThickenBody                      (      CATBody              *  iBodyToThicken               ,
                                                                      CATLength               iOffsetValue                 ,
                                                                      CATCGMJournalList   **  oReport                      = NULL);

          void                ChangeThicknessLimitForSurfacic  (      CATSweepLimit        *  iLimit                       );

          void                ChangeLimitForAngleOffset        (      CATSweepLimit        *  iLimit                       ,
                                                                      double                  iAngleOffset                 );

  // Methods for the different algorithms used for GetLength() - Extremum is the only one to be used
          void                GetLengthByExtremum              (const CATMathPoint          & iOrigin                      ,
                                                                const CATMathDirection      & iDirection                   ,
                                                                      double                & oLengthMin                   ,
                                                                      double                & oLengthMax                   );
         // 
          void                GetLengthCanonic                 (const CATMathPoint          & iOrigin                      ,
                                                                const CATMathDirection      & iDirection                   ,
                                                                      double                & oLengthMin                   ,
                                                                      double                & oLengthMax                   ,
                                                                      int                     iIsCanonic                   );

          void                GetLengthNonCanonic              (const CATMathPoint          & iOrigin                      ,
                                                                const CATMathDirection      & iDirection                   ,
                                                                      double                & oLengthMin                   ,
                                                                      double                & oLengthMax                   );
  // Debug
  //      void                Debug     (CATBody * iBody);
  //      void                Debug     (CATDomain * iDomain);
  //      void                Debug     (CATCell * iCell);
  //      void                DebugSide (CATFace * iFace, CATSide iSide);
  //      void                DebugSide (CATEdge * iEdge, CATSide iSide, CATFace * iFace);

protected :
          void                Duplicate                        (const CATSweep              & iSweep                       );

private :
  // constructeur a partir d'un autre opérateur CATSweep: INGERABLE ET DEFINITIVEMENT INTERDIT; C'EST CLAIR?
  // (dangerous and forever forbidden)                                                                       NLD020212
                              CATSweep                         (const CATSweep              & iSweep                       );


};

//----------------------------------------------------------------------------
//                              INLINE
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
INLINE void           CATSweep::SetVirtualBoolean ()
{
   _OperationVirtual = CATBoolean (1);
}

//----------------------------------------------------------------------------
INLINE void           CATSweep::SetReversePolarity(CATBoolean iPolarity)
{
   _ReversePolarity = iPolarity;
}

//----------------------------------------------------------------------------
INLINE void           CATSweep::SetFreezeMode(CATBoolean iFreezeMode)
{
   _freezemode      = iFreezeMode;
}

//----------------------------------------------------------------------------
INLINE void           CATSweep::SetInferLimitAxisDirection(CATBoolean iInferLimitAxisDirection)
{
   _InferLimitAxisDirection = iInferLimitAxisDirection;
}

//----------------------------------------------------------------------------
INLINE void           CATSweep::SetBothResult ()
{
   _BothResult = CATBoolean (1);
}

//----------------------------------------------------------------------------
INLINE CATBoolean     CATSweep::InvariantResult()
{
   return _InvariantResult;
}

//----------------------------------------------------------------------------
INLINE CATBoolean     CATSweep::IsBothResult ()
{
   return _BothResult;
}

//----------------------------------------------------------------------------
INLINE double         CATSweep::GetExtrudeLimitAngleOffset (CATLimit iId)
{
   return 0.;
}

//----------------------------------------------------------------------------
INLINE CATBoolean     CATSweep::GetInferLimitAxisDirection()
{
   return _InferLimitAxisDirection;
}

//----------------------------------------------------------------------------
INLINE CATBoolean     CATSweep::IsOperationVirtual ()
{
   return _OperationVirtual;
}

//----------------------------------------------------------------------------
INLINE int            CATSweep::HasCGMAttributeManagingDone(CATTopCGMAttributeLabel iCGMAttributeLabel)
{
   CATExtTopOperator* pExtTopOp = NULL;
   pExtTopOp = GetTopExtensible();
   return pExtTopOp ? pExtTopOp->HasCGMAttributeManagingDone(iCGMAttributeLabel) : FALSE;
}

//----------------------------------------------------------------------------
INLINE CATBoolean     CATSweep::GetProfileClosure ()
{
   return  _ToClose;
}

//----------------------------------------------------------------------------
INLINE CATBoolean     CATSweep::IsSelfClosedProfileInversionCase ()
{
   return  _SelfClosedProfileInversionCase;
}

//----------------------------------------------------------------------------
INLINE void           CATSweep::GetReversePolarity(CATBoolean & oPolarity)
{
   oPolarity = _ReversePolarity;
}

//----------------------------------------------------------------------------
INLINE CATBoolean     CATSweep::IsClosed()
{
  if (GetSweepType() == RevolType)
     return TRUE;
  else 
     return FALSE;
}

//----------------------------------------------------------------------------
INLINE void           CATSweep::SetRelimJournalMode(short iRelimJournalMode)
{
   if (iRelimJournalMode < 0 || iRelimJournalMode > 1) CATThrowForNullPointer();
   _RelimJournalMode = iRelimJournalMode;
}

//----------------------------------------------------------------------------
INLINE short          CATSweep::GetRelimJournalMode()
{
   return _RelimJournalMode;
}

//----------------------------------------------------------------------------
INLINE ListPOfCATCell CATSweep::GetTopCellList ()
{
   return  _TopBCellList;
}

//----------------------------------------------------------------------------
INLINE ListPOfCATCell CATSweep::GetBottomCellList ()
{
   return _BottomBCellList;
}

#endif
