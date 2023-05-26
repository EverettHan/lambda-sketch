/* -*-C++-*- */

#ifndef CATBlendTopOp_H
#define CATBlendTopOp_H

// COPYRIGHT DASSAULT SYSTEMES 1998

//------------------------------------------------------------------------------
//
// CATBlendTopOp
// Definition of a topological blend 
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// March. 98    Creation                         J-M.Guillard
//------------------------------------------------------------------------------

#include "Fillet.h"
#include "CATRibAdvTopOp.h"
#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATCellHashTable.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATDomain.h"
#include "CATMathDef.h"
#include "CATTopRibDef.h"
#include "ListPOfCATRibInit.h"
#include "CATCGMNewArray.h"
#include "CATListOfCATGeometries.h"
#include "CATListPOfCATCGMDiagnoses.h"
#include "CATTopOpInError.h"
#include "ListPOfCATBlendVertex.h"
#include "CATTopTools.h"
#include "CATTopHealPerf.h"


class CATGeometry;
class CATBody;
class CATShell;
class CATBlendRib;
class CATRlmBlend;
class CATRlmMacroTool;
class CATEdgeRibbon;
class CATEdge;
class CATSupContact;
class CATCrvParam;
class CATPCurve;
class CATTopRibNuplet;
class CATBlendMacroTool;
class CATCGMJournalList;
class CATCGMJournalFilter;
class CATRibInit;
class CATRibMultiInitManager;
class CATBlendVertex;
class CATLimitingInfoForEdge;
class CATRibbonsReorderTracker;
//struct CATLimitingForEdge;

#include "CATSafe.h"
CATSafeDefine(CATBlendTopOp);

class ExportedByFillet CATBlendTopOp : public CATRibAdvTopOp
{
 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATBlendTopOp(CATSoftwareConfiguration * iConfig,
                CATCGMJournalList        * iJournal, 
                CATBody                  * iCreationBody,
                CATEdgeRibbon            * iEdge = NULL);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATBlendTopOp();
 
  //------------------------------------------------------------------------------
  // Lecture de ruban. Le ruban en cours est le dernier ruban ajoute
  //------------------------------------------------------------------------------
  CATBlendRib * GetCurrentBlendRib ();
  CATBlendRib * GetBlendRib( int i);

  //------------------------------------------------------------------------------
  // Diagnostics d'erreur en cas d'echec de la relimitation du ruban blend
  //------------------------------------------------------------------------------
  void GetDiagnosisHelpForRelimitBlendRibbon(CATError                   *iOldError,
                                             CATLISTP(CATCGMDiagnosis)  &oDiagnosisList, 
                                             CATTopOpInError           *&oError,
                                             CATBoolean                  iDisconnectOrSewingFailure=FALSE);

  //------------------------------------------------------------------------------
  // Run method
  //------------------------------------------------------------------------------
  virtual void Run (int ShouldFreezeAndComplete=1);
 
  //------------------------------------------------------------------------------
  // Information method
  //------------------------------------------------------------------------------
  CATBoolean IsUntwistFillFunctionUsed() const ;

  //------------------------------------------------------------------------------
  // Get next blend ribbon to compute
  //------------------------------------------------------------------------------
  CATBlendRib * GetNextRibBlend();

  //------------------------------------------------------------------------------
  // Compute the ribbon 
  //------------------------------------------------------------------------------
  virtual void  ComputeBlendRibbon();

  //------------------------------------------------------------------------------
  // Create the blend skin  
  //------------------------------------------------------------------------------
  virtual CATShell * CreateBlendRibbon();

  //------------------------------------------------------------------------------
  // Extrapol the blend ribbon and update skin, and data for relimitation if
  // necessary
  //------------------------------------------------------------------------------
  CATBoolean ExtrapolBlendRibbon(CATBlendRib* iRibToExtrapol, const CATTopRibSign iDirToExtrapol, const CATBoolean iDoWhileCandidate = FALSE);

  //------------------------------------------------------------------------------
  // Relimit the blend ribbon 
  //------------------------------------------------------------------------------
  virtual CATBoolean RelimitBlendRibbon();

  //---------------------------------------------------------------------------
  // Add relimitation for features that are located inside discard region
  // For versioning purpose an enhanced version of this function was introduced
  //---------------------------------------------------------------------------
  void RelimitFeaturesInRibbon_SeasonI(); // original version
  void RelimitFeaturesInRibbon_SeasonII(); // enhanced version 

  //------------------------------------------------------------------------------
  // Disconnect the blend skin 
  //------------------------------------------------------------------------------
  CATBoolean DisconnectBlendRibbon(ListPOfCATEdge * iSplittingEdges=NULL,
                             CATListOfInt   * iSideToDel     =NULL);

  //------------------------------------------------------------------------------
  // Sew the blend ribbon 
  //------------------------------------------------------------------------------
  virtual void  SewBlendRibbon(int              iNumBrdr=0,
                               CATBoolean       iReverseSide=0,
                               ListPOfCATEdge * iSplittingEdges=NULL,
                               CATListOfInt   * iSideToDel=NULL);

  //------------------------------------------------------------------------------
  // Get the edges on a support 
  //------------------------------------------------------------------------------
  virtual void GetEdges(int iNumBrdr, CATListPV &ListPOfListPOfCATEdge);

  //------------------------------------------------------------------------------
  // Cleans shells before body is completed
  //------------------------------------------------------------------------------
  virtual void CleanUp(CATBoolean iWithError=FALSE);

  //------------------------------------------------------------------------------
  // Restore inner data
  //------------------------------------------------------------------------------
  virtual void RestoreSpecificContent(CATCGMJournalList * iEdgesJournal=NULL);
  
  //------------------------------------------------------------------------------
  // Set the optional information for the Edges reporting
  //------------------------------------------------------------------------------
  void SetEdgeReporting   (CATCGMJournalList * EdgesJournal); 

  void AppendRemainingFilletEdge( CATEdge *FilletEdge );

  void SetRibbonsReorderTracker(CATRibbonsReorderTracker* iRibbonsReorderTracker);
  CATRibbonsReorderTracker* GetRibbonsReorderTracker() const;

  CATBoolean GetNoDiagnosticInSafeMode();
  void SetNoDiagnosticInSafeMode( CATBoolean iFlag );

  //------------------------------------------------------------------------------
  // Mise a jour apres passage d'un ruban anterieur
  //------------------------------------------------------------------------------
  virtual void Update(CATBody * iNewInitialBody, 
                      CATCGMJournalList * iJournal, 
                      CATCellHashTable * iEdges=NULL,
                      CATCGMJournalList * iJournalOfficiel=NULL);

  virtual void Update(CATCGMJournalList * iJournal);

  //------------------------------------------------------------------------------
  // Record the internal edges of the fillet 
  //------------------------------------------------------------------------------
  void RecordInternalEdges(CATCGMJournalList * iJournal=NULL);

  void AddBlendVertex(CATBlendVertex *iBlendVertex);
  CATBlendVertex *GetBlendVertex(int iNum);
  int GetBlendVertexNumber();
  CATBoolean GetVertexBlending();
  CATBoolean IsNewSWCornerFillet ();
  void SetNewSWCornerFillet ();

  CATBoolean IsSpecialVertexPatchFillet();
  void SetSpecialVertexPatchFillet();


  CATBoolean NeedToCheckLumps();

  void AddSmoothEdgesForBlendVertex (CATLimitingInfoForEdge *info, CATEdge *iSmoothEdge,  CATFace *PartingFace, 
                                     CATFace *iFaceFillet);


  CATShell *GetSkinBlend();
  private :
  CATBoolean   _NewSWCornerFillet;
  CATBoolean   _SpecialVertexPatchFillet;

  CATBoolean   _HasKeepFeature;

 protected:

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  CATShell           * _SkinBlend; 
  CATShell           * _DomToSew;
  CATTopRibPropagation _Mode;

                                      
  // FDN int _SegmentationMode;  //TRIM/NOTRIM 
  int _SewingOption;      //
 
 private:
  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  // donnees generales
  CATListPV             _MToolRlm;
  CATListPV             _DomainRlm;
  CATListOfInt          _DirsToKeep;           // pour le fill de vertex
  CATListOfInt          _DirPro;               // pour le fill de vertex 
  CATRlmBlend         * _RlmBlend;
  CATCGMJournalList   * _EdgesJournal;         // edges reporting
  CATBoolean            _WasUnTwistFunctionUsed; // traitement informatif
  CATBlendRib         * _RibRef;               // pour le fill de vertex
  CATSide               _SideForFV;            // pour le fill de vertex 
  int                   _FlagSelect;
  CATBoolean            _NoDiagnosticInSafeMode;  // To indicate that operator is in safe mode and no diagnostic should be created

  CATRibMultiInitManager * _MultiInitManager;

  CATCGMJournalFilter *     _ObjectsToWatch;     // fillet avec parting a besoins de suivre les edges
  CATRibbonsReorderTracker* _RibbonsReorderTracker; // Trigger FilletFaceSpec assignment to created faces

  void AppendObjectToWatch(CATGeometry* iObjectToWatch);
  void ClearObjectsToWatch();

  CATLISTP(CATBlendVertex) _BlendVertices;

  void                 RemoveIncompleteTracks();
  void                 UpdateEdgesJournal();   // mise a jour du journal d edges
  void                 GetRlmMacroTool(CATListPV & oMToolRlm, int NumRib=0);
  CATBoolean           IsTwisted();
  
  ListPOfCATEdge     _ListOfFatEdgeNoSimplif;  // liste d'edges à ne pas simplifier dans la simplif de "FatEdge" 

  ListPOfCATEdge     _ListOfEdgeForSimplifyInSmartEnv;
  //------------------------------------------------------------------------------
  // Traitement du journal pour les edges crees par fillet
  //------------------------------------------------------------------------------
  ListPOfCATEdge        _RecordedEdges;        // edges enregistres dans le
                                               // journal avec l'ordre Create
                                               // cf. DisconnectBlendRibbon
  void RecordCreatedTransversalEdges(CATCGMJournalList *Journal, ListPOfCATEdge& oListeEdges);
  void CompleteEdgeReporting (CATDomain* Skin, CATBody *CreationBody, CATBoolean iRecordInEdges=FALSE);

  ListPOfCATEdge        _RemainingFilletEdge;
  //------------------------------------------------------------------------------
  // Exporte un ruban Blend
  //------------------------------------------------------------------------------
  CATBoolean ExportBlendRib( CATBlendRib* iRibToExport,
                             CATBoolean   iDoUnTwist = TRUE,
                             CATTopRibPropagation iMode=PropagStandard );
  //------------------------------------------------------------------------------
  // Traitements du Parting 
  //------------------------------------------------------------------------------

  void SetupParting ();
/*                               
  //------------------------------------------------------------------------------
  // Mise A jour d'une liste d'edges avec les infos du journal
  //------------------------------------------------------------------------------
  void UpdateEdgesListWithJournal (ListPOfCATEdge *ioOldCells, CATCGMJournalList * iJournal);*/
  //------------------------------------------------------------------------------
  // Mise A jour d'une liste des cellules avec les infos du journal
  //------------------------------------------------------------------------------
  void UpdateCellsListWithJournal (ListPOfCATCell *ioOldCells, CATCGMJournalList * iJournal,
                                                CATBoolean OneToOneUpdate=FALSE);

  //------------------------------------------------------------------------------
  // Lecture des edges a suivre 
  //------------------------------------------------------------------------------
  void GetAllCellsToWatch (ListPOfCATCell &oCellsToWatch, CATBody *iInitialBodyToUse);

  //------------------------------------------------------------------------------
  // Checks that curvature along fillet tracks is sufficient for relimitation 
  // (conical fillet cases)
  // Return True if curvature is ok for relimitation.
  //------------------------------------------------------------------------------
  CATBoolean CheckCurvatureAlongTracks(CATLISTP(CATEdge) * ioListKOEdge=NULL);

  CATBoolean RemoveCrossingSkinRibbons();

  //------------------------------------------------------------------------------
  // Ttmt des fermetures : remplacement des courbes
  //------------------------------------------------------------------------------
  void ReplaceClosureOnFrontier();

  ////------------------------------------------------------------------------------
  //// Ttmt des fermetures : maj du journal d'edges
  ////------------------------------------------------------------------------------
  //void UpdateEdgeJournal(CATCGMJournalList* iJournal);

   private :
  //------------------------------------------------------------------------------
  // Donnees necessaires aux traitements <<With Traces>> sur les supports
  // du blend : Ces supports ne participent pas dans la couture.
  //------------------------------------------------------------------------------
   ListPOfCATDomain        _SupportDomains; 
   ListPOfCATCell          _SplitCell;
   CATListOfInt            _SideKeep;
   CATListOfInt            _NuSupportForSplitCell;

   CATBoolean              _CollisionCheckMode;

   CATBoolean              _IsFirstAndLastTwisted;
   CATBoolean              _ARibIsClosed;
 
   void AddCuttingInfosOnSupport( CATDomain * iDomain,
                                  const     ListPOfCATCell & iSplitCell,
                                  const     CATListOfInt   & iSideKeep,
                                  const int iSupport=0);
   void Desactivate(ListPOfCATCell & iSplitCell);
   void ReplaceCuttingInfosOnSupports (const int iSupport,
                                       ListPOfCATCell & iSplitCell,
                                       CATListOfInt   & iSideKeep);
   void RemoveCuttingInfosOnSupports (const int iSupport);
   void DesactivateCellsOnSupport ();

   public :
  //------------------------------------------------------------------------------
  // Requettes sur les cellules posees sur les supports <<With Traces>>
  //------------------------------------------------------------------------------
   void GetCuttingInfosOnSupport(const CATDomain * iDomain,
                                 ListPOfCATCell & oSplitCell,
                                 CATListOfInt   & oSideKeep );
   void GetCuttingInfosOnSupport(const int iSupport,
                                 ListPOfCATCell & oSplitCell,
                                 CATListOfInt   & oSideKeep );
   private :
   void UpdateCuttingInfosOnSupport (int iDom,CATCGMJournalList * iJournal);

   private :
   void GetBlendvertexEdgesToSimplify (CATBody *iBody, CATSoftwareConfiguration *iConfig, CATCellHashTable *& EdgesToSimplify);

   public :
   //------------------------------------------------------------------------------
   // IsNULLBecauseOfParting
   // -----------------------------------------------------------------------------
   CATBoolean IsNULLBecauseOfParting();
   //------------------------------------------------------------------------------
   // SetIsNULLBecauseOfParting
   // -----------------------------------------------------------------------------
   void SetIsNULLBecauseOfParting();
   //------------------------------------------------------------------------------
   // IsASkinSkinMultipleOperation : pour restraindre le multi solution face face
   // -----------------------------------------------------------------------------
   CATBoolean IsASkinSkinMultipleOperation();

   CATBoolean GetIsFilletIgnoreSharpEdgeActivated();
   //CATBoolean GetIsAutoFilletSpecialNoTrimActivated();

   //BQJ: To avoid relimitation problem in BSD
   void SetFirstAndLastTwisted(CATBoolean iIsFirstAndLastTwisted);

   //------------------------------------------------------------------------------
   // Set the collision check mode
   //------------------------------------------------------------------------------
   public:
   void SetCollisionCheckMode(CATBoolean iCollisionCheckMode);

   private :
   CATBoolean _NULLBecauseOfParting;

   private :
     
   CATBoolean MultipleRibbonsAllowed();

   //------------------------------------------------------------------------------
   // Get G1 check mode
   //------------------------------------------------------------------------------
   private:
   CATTopTools::GapCheckMode GetG1CheckMode();

   //------------------------------------------------------------------------------
   // Check if a Volume remains closed
   //------------------------------------------------------------------------------
   CATBoolean CheckThatResultShellIsAVolume(CATShell* iShellToTest);

   //------------------------------------------------------------------------------
   // RI 0392747
   // SearchForRedundantRibs :
   // JMA : iRibBlend is created and the initial ribbons can be contained inside iRibBlend.
   // This happens when the initial ribbons are not propagated inside their notches
   // (fillet face face). The new ribbon, iRibBlend, if initialised within this area,
   // can contain the initial ribbons in their In/In part. 
   // In that case the initial ribbons are to be considered as redundant.  
   //------------------------------------------------------------------------------
   private :
   void SearchForRedundantRibs (CATBlendRib      *iRibBlend, 
                                ListPOfCATTopRibs& oRedundantRibs,
                                ListPOfCATTopRibs& oPartiallyRedundantRibs);
   //------------------------------------------------------------------------------
   // RI 0392749
   // PartiallyRedundantRibsRemoval :
   // JMA :   Try to find out which ribbons are entirelly redundant (all <<in>>parts are
   //         containes in non redundant but different ribbons)
   //------------------------------------------------------------------------------
   void PartiallyRedundantRibsRemoval (ListPOfCATTopRibs& iPartiallyRedundantRibs, 
                                       ListPOfCATTopRibs& oRedundantRibs);
   void CleanPartiallyRedundantRibs (ListPOfCATTopRibs& iPartiallyRedundantRibs, 
                                                 CATBlendRib      *iRibBlend);

   //------------------------------------------------------------------------------
   // Mark Nuplets which give twisted surfaces
   //------------------------------------------------------------------------------
   void MarkTwistedNuplet(CATLISTP(CATFace) &iListOfTwistedFaces);

   //------------------------------------------------------------------------------
   // Management of confusions between relimitation ribbons
   //------------------------------------------------------------------------------
   CATBoolean _RestoreConfusionsAfterRelim;
   public :
   void SetRestoreConfusionsAfterRelim(CATBoolean iRestore);
   CATBoolean GetRestoreConfusionsAfterRelim () const;

   private:
     void CleanJournal(CATCGMJournalList *Journal, CATBody *iCreationBody, 
                       CATBoolean RecordInnerEdges, ListPOfCATEdge *iForbidenEdges=NULL);

     CATBoolean _ReplacedBorderForSkin;
   public :
     void CleanExtraNuplets();

  //------------------------------------------------------------------------------
  // Methodes de cast 
  //------------------------------------------------------------------------------
  public :
    CATBlendTopOp* GetAsBlendTopOp() {return this;};
  
  //------------------------------------------------------------------------------
  // Help Point option
  //------------------------------------------------------------------------------
  public :
    CATBoolean HelpPointUsedToSelectSolution(); 
    void SelectRibbonWithHelpPoint();

  public :
    void SetLimitingInfoForEdge(CATListPV & LimitingInfo);

  //---------------------------------------------------------------------
  // IZE wk. 01 2010 IR 021460 Some checks are too restrictive for SheetMetal configurations
  //---------------------------------------------------------------------
    CATBoolean _UnplugChecksForSheetMetal;
  public :
    void SetUnplugChecksForSheetMetal(CATBoolean iUnplugChecksForSheetMetal);

  private:
  // Mesures perfs
  CATBoolean                  _DbgPerf;
  CATTopHealPerf              p_Total;
  CATTopHealPerf              p_Run;  
  CATTopHealPerf              p_Parting;
  CATTopHealPerf              p_ComputeBRib;
  CATTopHealPerf              p_CreateBRib;
  CATTopHealPerf              p_RelimitBRib;
  CATTopHealPerf              p_DiscBRib;
  CATTopHealPerf              p_SewBRib;
  CATTopHealPerf              p_Error;
  CATTopHealPerf              p_Clean;

};
#endif
