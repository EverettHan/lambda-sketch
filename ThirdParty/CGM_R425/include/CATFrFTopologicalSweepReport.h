// CGMDUMPBODY sortie de la classe

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATFrFTopologicalSweepReport
// Utility for producing sweep and loft report whenever
// topology computation is similar to an extrusion of one master
// profile by one master guide, after all guides homogenization,
// and all profiles homogenization
// (report is based on a preprocessing intermediate report,
// and an extrusion intermediate report)
//                                                 Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
// 
//=============================================================================
// 22 02 00 NLD Creation (le code de RAD est isolé dans cet objet
//              dans un but de réutilisabilité)
// 07 02 00 NLD Ajout iGuidesForReport a FindBoundingGuidesNumbers()
// 17 02 00 NLD Pour debug et versionning de ce debug:
//              -  _DebugJournal170200, 
//                 _ReportCloneIntermediateVertex,
//                 _ReportInfoWhileClone,
//                 _UseFindBoundingGuidesNumber 
//              - ApplyReportVersion()
// 21 03 00 NLD _ExternalReportDerivation
// 23 03 00 NLD GetWires()
// 24 03 00 NLD - _DebugJournal170200_FirstWire
// 27 03 00 NLD - _DebugJournal270300_ProfileRank
// 17 04 00 NLD Ajout _FinalGuidesOrientations,
//              ajout iGuidesOrientations a SetFinalGuides,
//              FindFOperands et FindEOperands
//              ajout iGuidesOrientationsForReport a FindGuides
//              ajout iOrientation a GetVertexByRank et GetEdgeByRank
//              ajout iCrossBodiesOrientations,oCrossBodiesOrientations a GetList()
//              ajout _UseOrientations 
//              ajout oOri1, oOri2 a FindGuides()
//              ajout SetListOfBodies
//              ajout iProfilesOrientations a SetFinalProfiles,
//              ajout _FinalProfilesOrientations
// 25 04 00 NLD Ajout _RattrapOnBoundingGuidesNumbers
// 02 05 00 NLD Ajout _ClosureManagement
// 02 05 00 NLD Gestion de l'ordre des guides:
//              Ajout iFinalGeomOrders et oStoredGeomOrders a SetListOfBodies
//              ajout iGuidesOrders a SetFinalGuides
//              ajout _FinalGuidesOrders
//              ajout _UseGuidesOrders
//              ajout iGuidesOrdersForReport à FindEOperands, FindFOperands
//              ajout iGuidesOrdersForReport à FindBoundindGuidesNumbers
// 16 05 00 NLD ajout _RattrapBordOnBoundingGuidesNumbers
//              ajout iProfilesOrientationsForReport à FindBoundindGuidesNumbers
// 30 05 00 NLD Argument oAllCells a GetInitialCell()
//              ajout _RattrapOperands
// 30 06 00 NLD Je distingue les variables de declenchement des
//              modifications version 3:
//              ajout _WithDeleted pour ThroughCreateAndModifyWithDeleted
//              ajout _GetAllInitialCells
// 13 11 00 NLD Constructeur avec CATTopData, _TopData, Init()
// 05 03 01 NLD _SimplificationManagement activable par SetReportVersion(4)
//              pour gestion de la simplification dans l'extrusion
// 06 03 01 NLD Suppression des HashTable à la con qui n'ont aucun interet ici
//              et qui handicapent très serieusement le debug
// 29 03 01 NLD _RattrapIfUnknownParent activable par SetReportVersion(5)
// 19 03 01 NLD Argument iSigneInfo a ReportOnImplicitProfile(),
//              ReportOnImplicitBody(), ReportOnExtremityVertices()
//              _UseInfoSign activable par SetReportVersion(6)
// 27 04 01 NLD SetFunctionalGuides(), _FunctionalGuides, _FunctionalGuidesOrientations,
//              _UseFunctionalGuides activable par SetReportVersion(7)
// 30 05 01 NLD Ajout _DebugReperageGuides300501 et _GetAllInitialCellsForSharpFaces
//              activables par SetReportVersion(8)
// 01 06 01 NLD Ajout _DebugNonEdgesFaceParents pour cas des faces
//              n'heritant pas de 2 edges dans l'extrusion
//              activable par SetReportVersion(8)
// 30 05 02 NLD Ajout _GetAllInitialCellsForGuideEdges
//              ajout _GetAllInitialCellsForProfileEdges
//              ajout AddInitialCells(), PrintGeomTag()
// 25 11 02 NLD Gestion du multidomaines:
//              - argument iNumWire à GetVertexByRank()
//              - ajout _ListIntermediateBodies
//              - ajout GetMasterReportWires()
//              - argument oNumWire à GetEdgeRank() et à GetVertexRank()
//              - ajout _MultiDomain
// 26 11 02 NLD Pour facilité de debug
//              - Ajout de  _NumFaceToFollow, _NumFaceReportCall,
//                _NumEdgeToFollow, _NumEdgeReportCall,
//                ReportBreakPoint(), EdgeReportDebug(), FaceReportDebug()
// 27 11 02 NLD Argument optionnel iDomain à CGMDUMPBODY
//              Ajout DumpOperands()
// 28 11 02 NLD Ajout CellLocate()
// 29 11 02 NLD Ajout _MasterGuideWires _MasterProfileWires
// 03 12 02 NLD Ajout Warning()
// 04 12 02 NLD Ajout GetWire()
// 05 12 02 NLD Ajout _UseAllProfiles
// 10 12 02 NLD ioGuideOrProfile entree/sortie de GetVertexRank pour specifier
//              si on privilegie la recherche sur guide ou sur profil
// 11 12 02 NLD Ajout de _DebugVertexShare
// 11 12 02 NLD Ajout de _InitialCellForFaceParent
// 05 03 02 NLD Ajout ReportCutBody()
// 26 03 03 NLD Argument optionnel SegmentingVertices à ReportCutBody()
// 27 03 03 NLD Ajout _CuttingCells, où ReportCutBody() stocke les vertex de coupure.
// 24 10 03 NLD Ajout _CutReport (code ecrit le 15 04 03)
// 03 02 04 NLD Gestion des profils intermediaires dans le suivi
//              - Arguments optionnels iFinalUseForReport et oStoredUseForReport
//              à SetListOfBodies
//              - Argument optionnel iProfileNecessaryForReport à SetFinalProfiles()
//              - _ProfileNecessaryForReport
//              - _UseSelectedProfiles
// 18 03 05 NLD Ajout _PreparationReport, GetPreparationReport()
// 22 09 05 NLD Suppression du constructeur avec journal
// 28 06 06 JSX Ajoute methode ReportInBuffer ReportBuffer
// 19 12 06 NLD Argument iReadOnly à GetPreproReport()
//              Ajout _DoNotDeletePreproReport
//              Remontée de GetInitialCell() et PrintGeomTag() en public
// 02 11 07 NLD _BufferInfo devient CATListPV
// 05 11 07 NLD Preparation pour rendre disponible une methode statique equivalente a ReportCloneBody()
//              Regroupement des informations bufferisees dans _ReportBufferData
//              CATFrFTopologicalSweepReport_ReportInBuffer() remplace ReportInBuffer()
//              CATFrFTopologicalSweepReport_ReportBuffer()   remplace ReportBuffer()
// 21 07 08 NLD Facilites d'optimisation:
//              Ajout LockPreproReport() et UnlockPreproReport()
//              Ajout _InternalPreproReport, _NbInternalPreproReportLocks
//              Ajout GetInternalPreproReport()
// 03 10 08 NLD Ajout _LoftCase, SetLoftCase()
//              Ajout _PreciseReportWithProfileVertices
// 09 10 08 NLD Ajout SpecialReportWithProfileVertices()
// 15 10 10 NLD Ajout _PrefGuideNbCellsByWire et _PrefProfileNbCellsByWire
// 25 10 10 NLD Ajout _OptimGetEdgeRankAvailable
// 06 12 10 NLD Ajout _TopSweepUpgrade pour mise à niveau des sweeps PartDesign
//              si l'on y debranche le mode _OldJournal
//              Ajout FindFOperandsFaceParent() pour factorisation
// 15 03 12 NLD Ajout _UseOrientationsV2MultiDomain
// 06 12 12 NLD Ajout _DebugNonEdgesFaceParentsV2
// 23 01 13 NLD Ajout InitAllInitialCells()
//              Ajout _TassExtruderReport
//              Ajout _NumericalInfoCopy
// 11 02 13 NLD Ajout _Limits et SetLimits() en prevision d'une post-distinction eventuelle
//              des faces de relimitation debut et fin
//              Ajout argument optionnel iInfo a DumpOperands()
// 12 09 17 NLD Ajout _ReportTopBottomFaces
// 20 12 19 NLD Ajout GetVertexIfVertexInVol()
//              Ajout _ReportVertexInVol
//=============================================================================

#ifndef CATFrFTopologicalSweepReport_H
#define CATFrFTopologicalSweepReport_H
#include <FrFTopologicalOpe.h>     // Module definition for Windows

// Necessary classes for data definition
//
// ces deux includes pour le seul CATBoolean, NLD 220200 directives TCX
#include <CATMathDef.h>
#include <CATBooleanDef.h>
//
class CATCGMJournalList ;
class CATCGMJournalInfo ;
class CATBody ;
class CATFace ;
class CATWire ;
class CATDomain ;
class CATVertex ;
class CATCell ;
class CATEdge ;
#include <CATTopData.h>
#include <ListPOfCATBody.h>
#include <ListPOfCATWire.h>
#include <ListPOfCATVertex.h>
#include <CATListOfCATGeometries.h>
#include <CATCellHashTable.h>
#include <ListPOfCATCell.h>
#include <CATListOfInt.h>
#include <CATListPV.h> // pour CATListPV
  // Je passe par des macros car l'analyseur de syntaxe de Sniff a du mal
  // sur CATLISTP
  #define CATFrFTopologicalSweepReport_ListPOfCATBody     CATLISTP(CATBody)
  #define CATFrFTopologicalSweepReport_ListPOfCATCell     CATLISTP(CATCell)
  #define CATFrFTopologicalSweepReport_ListPOfCATGeometry CATLISTP(CATGeometry)
//=============================================================================
// 
//=============================================================================
  // DO NOT USE OUTSIDE THIS FRAMEWORK; SUBJECT TO CHANGE OR DELETION
  void       CGMDumpList(const CATLISTP(CATCell)& lst,CATCGMOutput& os , const char * message) ;
  // DO NOT USE OUTSIDE THIS FRAMEWORK; SUBJECT TO CHANGE OR DELETION
  void       CGMDumpBody(      CATBody     * iBody   ,
                               CATCGMOutput& os      ,
                         const char        * message ,
                               CATDomain   * iDomain = NULL);

  //-------------------------------------------------------------------------
  // Reports events for body cloning
  // AuthorizeDomainMisMatch=1 to handle non isotopological case with different number of domains
  // between BodyIn and BodyOut, but with same number of edges
  // for instance open body transformed in closed body,
  // or body splitted because of geometrical gap between POECs of a vertex
  //-------------------------------------------------------------------------
  void CATFrFTopologicalSweepReport_ReportCloneBody
                          (CATCGMJournalList* ReportIn,
                           CATCGMJournalList* ReportOut,
                           CATBody          * BodyIn,
                           CATBody          * BodyOut,
                           int                ReportCloneIntermediateVertex,
                           int                ReportInfoWhileClone,
                           int                AuthorizeDomainMisMatch
                          ) ;

//=============================================================================
// Class Definition
//=============================================================================

class ExportedByFrFTopologicalOpe
 CATFrFTopologicalSweepReport 

{
  public :
  // Usage notes:
  //  valid calling sequence is:
  //  CATFrFTopologicalSweepReport *SweepReport
  //     = new CATFrFTopologicalSweepReport(ExternalReport) ;
  //  CATCGMJournalList* PreproReport = SweepReport->GetPreproReport();
  //  CATCGMJournalList* ExtruderReport = SweepReport->GetExtruderReport();
  //  all preprocessing using PreproReport ;
  //  extrusion using ExtruderReport ;
  //  SweepReport->SetInitialGuides(...);  
  //  SweepReport->SetInitialProfiles(...);
  //  SweepReport->SetFinalGuides(...);  
  //  SweepReport->SetFinalProfiles(...);
  //  SweepReport->SetMasterGuide();
  //  SweepReport->SetMasterProfile();
  //  SweepReport->SetResult();
  //  SweepReport->BuildExternalReport();
  //  SweepReport->Check() ;
  //  delete SweepReport ;
  
  // Constructor (DO NOT USE)
//NLD220905  CATFrFTopologicalSweepReport (
//NLD220905                             CATCGMJournalList * iExternalReport=NULL) ;

  // Constructor
  CATFrFTopologicalSweepReport (
                             CATTopData * iTopData) ;
  // Destructor
  virtual            ~CATFrFTopologicalSweepReport () ;
  
  // builds external report (given in input to constructor)
  void                BuildExternalReport();

  // gets local report to use for all preparation
  // (before preprocessing)
  // this report will be directly inserted into final report
  CATCGMJournalList*  GetPreparationReport();

  // gets local report to use for all preprocessing 
  // this report will be combined with extruder report to generate final report
  CATCGMJournalList*  GetPreproReport(CATBoolean iReadOnly = TRUE);

  // gets local report to use for topology extrusion 
  // this report will be combined with preprocessing report to generate final report
  CATCGMJournalList*  GetExtruderReport();

  // (Restricted use) Lock prepro report:
  // will be considered until Unlock; All new prepro orders will be put in a buffer
  void LockPreproReport();

  // (Restricted use) Unlock prepro report:
  // all buffer data is inserted in prepro report
  void UnlockPreproReport();

  // Report versionning
  // 0 : old report (before 12/99)
  // 1 : report since 12/99 (default value)
  // 2 : same as 1 with debug 02/00 et 05/00
  // 3 : same as 2 with debug 06/00
  // 4 : same as 3 with multiple parents management in extrusion (if simplification) 03/01
  // 5 : same as 4 with unknown extrusion parent management 03/01
  // 6 : same as 5 with info sign management in implicit bodies report
  // 7 : same as 6 with use of all functional guides in report
  // 8 : same as 7 with precise sharp faces report (according informations
  //     set in intermediaire report by wire homogenization)
  void SetReportVersion(int iVersion=1);
  //
  // Useful methods for prepro report build 
  // iSigneInfo may be useful for special extremity vertices report
  void ReportOnImplicitProfile   (CATBody* iProfile, int iSigneInfo=1) ;
  void ReportOnImplicitSpine     (CATBody* iSpine) ;
  // Report creation for a cloned body (BodyOut having same 
  // topology as BodyIn)
  void ReportCloneBody           (CATBody* BodyIn, CATBody* BodyOut ) ;
  // Report creation for a cut body, with edges issued from edges
  // from BodyIn, except for edges eliminated in BodyIn,
  // ((*KeptEdges)[i] set to 0)
// L'argument optionnel SegmentingVertices donne des vertex coupants eventuels
// ayant permis de generer BodyIn à partir d'un body initial
// Ces vertex seront utilises pour le suivi
// Exemple:
//  *----------------*-------*------*--------* Body initial
//  0    x      x    0       0   x  x        0 SegmentingVertices
//  *----x------x----*-------*---x--x--------* BodyIn
//     1     0    1      1     1   0     1     KeptEdges
//  *----x      x----*-------*---x  x--------* BodyOut
  void ReportCutBody             (CATBody         * BodyIn             ,
                                  CATBody         * BodyOut            ,
                                  CATListOfInt    * KeptEdges          = NULL,
                                  ListPOfCATVertex* SegmentingVertices = NULL) ;
  //
  // Initial data definition (mandatory)
  //
  void SetInitialGuides  (const CATLISTP(CATBody)& iGuides  ) ;
  void SetInitialProfiles(const CATLISTP(CATBody)& iProfiles) ;
  //
  // Final data definition (mandatory)
  // (homogenized guides and profiles)
  // optional list of guides/profiles orientations may be provided
  // iGuidesOrientations[i] must be set to -1 if guide is inverted
  // optional list of guides orders may be provided
  // iGuidesOrders[i] must be set to j j>=1 (order of
  // guide i along master profile)
  void SetFinalGuides  (const CATLISTP(CATBody)& iGuides,
                              CATListOfInt*      iGuidesOrientations        = NULL,
                              CATListOfInt*      iGuidesOrders              = NULL) ;
  // iProfileNecessaryForReport[i]=1 to impose use of 
  // intermediate profile number i for report
  void SetFinalProfiles(const CATLISTP(CATBody)& iProfiles,
                              CATListOfInt*      iProfilesOrientations      = NULL,
                              CATListOfInt*      iProfileNecessaryForReport = NULL) ;
  // Master data definition: guide and profile used for extrusion
  void SetMasterGuide  (CATBody*   iGuide,
                        CATBoolean iMasterGuideHasBeenInverted = FALSE) ;
  void SetMasterProfile(CATBody* iProfile) ;
  // Functional guides definition 
  // (homogenized guides)
  // optional list of functional guides orientations may be provided
  // iGuidesOrientations[i] must be set to -1 if guide is inverted
  void SetFunctionalGuides(const CATLISTP(CATBody)& iFunctionalGuides,
                                 CATListOfInt*      iFunctionalGuidesOrientations = NULL) ;
  //
  // Result definition (mandatory; if none, report will be empty)
  //
  void SetResult(CATBody* iResult) ;
  // Asks for report check
  // iForceCheck = FALSE : report check is conditionned by 
  //   execution environment
  // iForceCheck = TRUE  : report check will be done unconditionnaly
  void Check(CATBoolean iForceCheck = FALSE) ;
  
  // obtention de la cellule initiale d'une cellule
  // et eventuellement (30/05/00) de toutes les cellules initiales
  // on les ajoute alors à la liste fournie en argument, qui n'est pas
  // reinitialisee
  // iOneForGuideTwoForProfile
  // = 0 recherche simple d'apres le journal prepro
  // = 1 recherche d'apres le journal prepro et les guides initiales
  // = 2 recherche d'apres le journal prepro et les profils initiaux
  // = 3 recherche d'apres le journal prepro et les guides et profils initiaux
  CATCell*   GetInitialCell   (int             iOneForGuideTwoForProfile,
                               CATCell       * iCell                    ,
                               ListPOfCATCell* oAllInitialCells         = NULL);
  // Definition de cas loft
  void       SetLoftCase      (int iLoftCase) ;

  // Definition des limites en debut/fin de guide pour les cas d'extrapolation/relimitation
  // Cas tres particulier... NLD110213
  void       SetLimits        (CATGeometry* iLimits[2]); 

  private :
  //-------------------------------------------------------------------------
  // private data
  //-------------------------------------------------------------------------
  CATTopData                                       _TopData ;
  //  le journal vu de l'exterieur (ExternalReport)
  CATCGMJournalList                              * _ExternalReport ;
  // report for preparation
  CATCGMJournalList                              * _PreparationReport ;
  // report for preprocessing
  CATCGMJournalList                              * _PreproReport   ;
  // report for extrusion
  CATCGMJournalList                              * _ExtruderReport ;
  // report for extrusion (tassed)
  CATCGMJournalList                              * _TassExtruderReport ;
  // report for cut
  CATCGMJournalList                              * _CutReport ;
  // internal report for preprocessing
  CATCGMJournalList                              * _InternalPreproReport ;
  // 
  int                                              _NbInternalPreproReportLocks ;

  //---------------------------------------------------------------------
  //     Variables de gestion du niveau de suivi
  //---------------------------------------------------------------------
  // le debug du journal doit obeir a du versionning, sauf si
  // on sait qu'il n'y a pas de risque

  // report version
  // for compatibility
  // (set to 0 in PART DESIGN by CATTopSweepImp)
  int                                              _Version    ;

  int                                              _DebugJournal170200 ;
  int                                              _DebugJournal170200_FirstWire ;
  int                                              _DebugJournal270300_ProfileRank ;
  int                                              _OldJournal ;// 1 for version <= Dec99
  int                                              _ReportCloneIntermediateVertex ;
  int                                              _ReportInfoWhileClone ;
  int                                              _UseFindBoundingGuidesNumber ;
  int                                              _UseOrientations ;
  int                                              _RattrapOnBoundingGuidesNumbers ;
  int                                              _RattrapBordOnBoundingGuidesNumbers ;
  int                                              _RattrapOperands ;
  int                                              _WithDeleted ;
  int                                              _GetAllInitialCells ;
  int                                              _ClosureManagement ;
  int                                              _UseGuidesOrders ;
  int                                              _SimplificationManagement ;
  int                                              _RattrapIfUnknownParent ;
  int                                              _UseInfoSign ;
  int                                              _UseFunctionalGuides ;
  int                                              _DebugReperageGuides300501 ;
  int                                              _GetAllInitialCellsForSharpFaces ;
  int                                              _GetAllInitialCellsForGuideEdges ;
  int                                              _GetAllInitialCellsForProfileEdges ;
  int                                              _DebugNonEdgesFaceParents ;
  int                                              _DebugNonEdgesFaceParentsV2 ;
  int                                              _MultiDomain ;
  int                                              _UseSelectedProfiles ;
  int                                              _UseAllProfiles ;
  int                                              _DebugVertexShare ;
  int                                              _InitialCellForFaceParent ;
  int                                              _NumFaceToFollow ;
  int                                              _NumFaceReportCall ;
  int                                              _NumEdgeToFollow ;
  int                                              _NumEdgeReportCall ;
  int                                              _LoftCase ;
  int                                              _PreciseReportWithProfileVertices ;
  int                                              _OptimGetEdgeRankAvailable;
  int                                              _TopSweepUpgrade;
  int                                              _UseOrientationsV2MultiDomain;
  int                                              _NumericalInfoCopy;
  int                                              _ReportTopBottomFaces;
  int                                              _ReportVertexInVol;
  //---------------------------------------------------------------------

  CATFrFTopologicalSweepReport_ListPOfCATBody      _InitialGuides ;
  CATFrFTopologicalSweepReport_ListPOfCATBody      _InitialProfiles ;
  CATFrFTopologicalSweepReport_ListPOfCATBody      _FinalGuides ;
  CATFrFTopologicalSweepReport_ListPOfCATBody      _ListIntermediateBodies ;
  CATListOfInt                                     _FinalGuidesOrientations ;
  CATListOfInt                                     _FinalGuidesOrders ;
  CATFrFTopologicalSweepReport_ListPOfCATBody      _FinalProfiles ;
  CATListOfInt                                     _FinalProfilesOrientations ;
  CATListOfInt                                     _ProfileNecessaryForReport ;
  CATFrFTopologicalSweepReport_ListPOfCATBody      _FunctionalGuides ;
  CATListOfInt                                     _FunctionalGuidesOrientations ;
  ListPOfCATWire                                   _MasterProfileWires ;
  ListPOfCATWire                                   _MasterGuideWires ;
  CATBody*                                         _MasterProfile ;
  CATBody*                                         _MasterGuide ;
  CATBody*                                         _ImplicitProfile ;
  CATBody*                                         _Result ;
  CATBoolean                                       _MasterGuideHasBeenInverted ;
  CATBoolean                                       _ExternalReportDerivation ;
  CATBoolean                                       _DoNotDeletePreproReport ;

  CATFrFTopologicalSweepReport_ListPOfCATCell      _PrefGuideCells ;
  CATFrFTopologicalSweepReport_ListPOfCATCell      _PrefProfileCells ;
  CATListOfInt                                     _PrefGuideNbCellsByWire;
  CATListOfInt                                     _PrefProfileNbCellsByWire;

  CATFrFTopologicalSweepReport_ListPOfCATCell      _AllInitialProfileCells;
  CATFrFTopologicalSweepReport_ListPOfCATCell      _AllInitialGuideCells;
  CATFrFTopologicalSweepReport_ListPOfCATCell      _CuttingCells;

  CATGeometry*                                     _Limits[2];

  void Init            () ;
  void Warning         () ; // Pour faciliter pose de point d'arret si probleme
  void ReportBreakPoint() ;
  void EdgeReportDebug () ;
  void FaceReportDebug () ;

  // journal de creation sur iWire
  // dans ces 2 methodes iSigneInfo pris en compte en version>=6 seulement
  void ReportOnImplicitBody      (CATBody* iImplicitBody, int iSigneInfo=1) ;
  void ReportOnExtremityVertices (CATWire* iWire        , int iSigneInfo=1) ;

  // Impression du tag d'un element geometrique suivi d'un blanc eventuel
  void PrintGeomTag(CATGeometry* iGeom, 
                    int iBlank) ;

  void                InitInternalReports();
  void                ApplyReportVersion();
  void                SetListOfBodies
                       (const CATLISTP(CATBody)&  iFinalGeom,
                        CATListOfInt*      iFinalGeomOrientations,
                        CATListOfInt*      iFinalGeomOrders,
                        CATListOfInt*      iFinalUseForReport,
                        CATLISTP(CATBody)* oStoredGeom,
                        CATListOfInt*      oStoredGeomOri,
                        CATListOfInt*      oStoredGeomOrders,
                        CATListOfInt*      oStoredUseForReport
                        ) ;

  void                InitPrefCells();
  void                InitAllInitialCells();

  CATWire*            GetMasterReportWire (int             iGuideOrProfile);
  void                GetMasterReportWires(int             i              ,
                                           ListPOfCATWire& oListOfWires   ) ;
  // int                 Inclusion(CATVertex* , CATBody*);
  void                GetList(CATBody*                 iRefBody,
                        const CATLISTP(CATBody)&       iCrossBodies,
                        const CATListOfInt&            iCrossBodiesOrientations,
                              CATLISTP(CATBody)&       oCrossBodies,
                              CATListOfInt&            oCrossBodiesOrientations);

  // returns 0 if iEdge(resp. iVertex) is nor in the Master Profile nor in the Master Guide
  // returns 1 otherwise , then :
  //         oEdgeRank est dans {1,N} (resp. oVtxRank dans {1,N+1}
  //         oGuideOrProfile = 1 si Guide
  //                         = 2 si Profile
  //         iNumWire (oNumWire) from 1 to number of wires in profile/guide or
  //           limiting profile/guide if CATFace
  int        GetEdgeRank      (CATEdge*   iEdge,
                               int&       oNumWire,
                               int&       oEdgeRank,
                               int&       oGuideOrProfile);
  // Ici ioGuideOrProfile est une entree/sortie pour la gestion des modeles
  // vérolés où guide et profil partagent un vertex
  // en entree:
  // 0 : standard
  // 1 : privilegier la guide en cas de vertex partagé guide/profil
  // 2 : privilegier le profil en cas de vertex partagé guide/profil
  int        GetVertexRank    (CATVertex* iVtx, 
                               int&       oNumWire,
                               int& oVtxRank,
                               int& ioGuideOrProfile);
  CATEdge*   GetEdgeByRank    (int iNumWire, 
                               int iEdgeRank,       CATBody*    iBody,
                               int iOrientation=1);
  CATVertex* GetVertexByRank  (int iNumWire,
                               int  iVtxRank,        CATBody*    iBody,
                               int iOrientation=1);
  // recherche de la cellule initiale d'une cellule et ajout
  // à la liste oResult, qui n'est pas reinitialisee
  // meme fonctionnement que GetInitialCell
  // et gestion des traces
  // iAllInitailCells: 0 ppur une seule cellule, 1 pour toutes
  void AddInitialCells        (CATCell* iCell,
                               int      iAllInitialCells,
                               int      iOneForGuideTwoForProfile,
                               CATLISTP(CATGeometry)& oResult) ;
  CATWire*   GetFirstWire     (CATBody* iBody);

  // Recherche d'un wire du body par son numéro
  CATWire*   GetWire          (      CATBody                *  iBody           ,
                                     int                       iNumWire        ) ;

  // rend les wires correspondant aux domaines du body
  void       GetWires         (      CATBody                *  iBody           ,
                                     ListPOfCATWire          & oListOfWires    ) ;

  void       FindGuides       (const CATLISTP(CATBody)       & iGuidesForReport,
                               const CATListOfInt            & iGuidesOrientationsForReport,
                                     int                       rk1             ,
                                     int                       rk2             ,
                                     CATBody                *& guide1          ,
                                     CATBody                *& guide2          ,
                                     int                     & oOri1           ,
                                     int                     & oOri2           );

  // pour retrouver les operandes de construction
  // etant donne un numero d'edge ou de vertex 
  void FindBoundingGuidesNumbers
     ( CATLISTP(CATBody)& iGuidesForReport,
       CATListOfInt     & iGuidesOrdersForReport,
       CATLISTP(CATBody)& iProfilesForReport,
       CATListOfInt     & iProfilesOrientationsForReport,
       int                iNumEdgeInProfile,
       int                iNumVertexInProfile,
       int              & oPreviousGuideNumber,
       int              & oNextGuideNumber) ;
  // Dump des operandes d'une cellule, en mode debug
  void DumpOperands(CATGeometry          * iFinalCell, 
                    CATLISTP(CATGeometry)& iResult   ,
                    CATCGMJournalInfo    * iInfo     = NULL) ;
  // recherche les operandes de création d'une edge
  void       FindEOperands(CATEdge             *  iEdge,
                           CATLISTP(CATGeometry)& oEdgeOperands, 
                           CATLISTP(CATBody)    & iGuidesForReport,
                           CATListOfInt         & iGuidesOrientationsForReport,
                           CATListOfInt         & iGuidesOrdersForReport,
                           CATLISTP(CATBody)    & iProfilesForReport,
                           CATListOfInt         & iProfilesOrientationsForReport,
                           CATCGMJournalInfo   *& info);
  // recherche les operandes de création d'une face
  void       FindFOperands(CATFace             *  iFace,
                           CATLISTP(CATGeometry)& oFaceOperands,
                           CATLISTP(CATBody)    & iGuidesForReport,
                           CATListOfInt         & iGuidesOrientationsForReport,
                           CATListOfInt         & iGuidesOrdersForReport,
                           CATLISTP(CATBody)    & iProfilesForReport,
                           CATListOfInt         & iProfilesOrientationsForReport,
                           CATCGMJournalInfo   *& info);

  // Recherche des parents d'une face: cas particulier de la remontée depuis un parent de type face
  void       FindFOperandsFaceParent(CATCGMJournalList* iPreproJ, CATFace* iFaceCell, CATLISTP(CATGeometry)& oResult);

  // localisation dans une liste de cellules
  int        CellLocate(CATLISTP(CATCell)& ListCell, CATCell* iCell) ;

  // nettoyage des donnees necessaires au suivi
  void       ClearReportData();



  //CATFrFTopologicalSweepReport_ReportBufferDataStruct _ReportBufferData ;
  //CATCGMJournalInfo** _BufferInfo;
  //CATListPV             _BufferInfo;
  //CATFrFTopologicalSweepReport_ListPOfCATGeometry _BufferBefore;
  //CATFrFTopologicalSweepReport_ListPOfCATGeometry _BufferAfter;

  // gets local report to use for all preprocessing 
  // this report will be combined with extruder report to generate final report
  CATCGMJournalList*  GetInternalPreproReport();

  // Rend la cellule vertex si body de type CATVertexInVolume
  CATCell          *  GetVertexIfVertexInVol(CATBody* iBody);

  void SpecialReportWithProfileVertices(
                                      CATLISTP(CATBody)     & iGuidesForReport,
                                      CATListOfInt          & iGuidesOrientationsForReport,
                                      CATListOfInt          & iGuidesOrdersForReport,
                                      CATLISTP(CATBody)     & iProfilesForReport,
                                      CATListOfInt          & iProfilesOrientationsForReport,
                                      int                     AllCells,
                                      CATBody              *  CurrentProfile,
                                      int                     rkp,
                                      int                     oriprofile,
                                      int                     BeforeFirstGuide,
                                      int                     AfterLastGuide,
                                      int                     BetweenGuides,
                                      int                     NumProfileWire,
                                      // Resultat en entree/sortie
                                      CATLISTP(CATGeometry) & TotalInitialCells 
//CATLISTP(CATGeometry)& oResult
                                     ) ;


} ;
#endif
