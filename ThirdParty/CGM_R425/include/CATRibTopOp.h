/* -*-C++-*- */

#ifndef CATRibTopOp_H
#define CATRibTopOp_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
//
// CATRibTopOp: Operator on ribs. Designed to manage several ribs on same type
//
// The specification is to allow:
//
// - To compute several ribs of the same type
//
// - Homogeneize the ribs between them
//
// - Relimit the ribs
//
// - ....
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Usage notes:
//
// Revoir les domaines a garder, detruire, ...
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Aug. 99    Creation                                   J-M.Guillard
//            Major contributors                         ASE CWM JMA RR PRL...
//
//            Responsibles                               JQS (Fillet)  
//                                                       PRL (Relim & TrimSew)
//                                                       SOU (Draft)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Other contributions
// 16/11/12 NLD Ajout DeleteFormol()
// 29/05/12 UVC Refactored CheckAndManageClosureOnFrontier
//              (Fast Update - Non Smart )
// 09/07/19 NLD Ajout Init0() et Init()
//------------------------------------------------------------------------------

#include "RibbonLight.h"
#include "CATTopRibObject.h"
#include "ListPOfCATTopRibs.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATBody.h"
#include "CATMathDef.h"
#include "CATMathInline.h"
#include "CATTopRibDef.h"
#include "ListPOfCATRibInit.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATShell.h"
#include "CATTopOpPrevisualization.h"  // pour enum previsu
#include "CATTopTools.h"
#include "GeometricUtilities.h"
#include "CATListOfCATSurfaces.h"

// Temporaire // Migration Versionning
#include "CATSoftwareConfiguration.h"

class CATBody;
class CATShell;
class CATTopRib;
class CATTopRibMacroTool;
class CATCGMJournalList;
class CATSoftwareConfiguration;
class CATRibInit;
class CATFace;
class CATLoop;
class CATLoopExtension;
class CATGeoFactory;
class CATSurface;
class CATSurLimits;
class CATIntRibNuplet;
class CATParting;
class CATFilletCrossPartingLinker;
class CATBlendRlm;
class CATCell;
class CATSewingCompl;
class CATSewingOpt;
class CATLump;
class CATBlendTopOp;
class CATRibAdvTopOp;
class CATDraft;
class CATRelimTopOp;
class CATCGMFormol;
class CATTopologicalOperator;
class CATTopFlexibleBRep;
class CATLightJournalChecker;


#include "CATSafe.h"
CATSafeDefine(CATRibTopOp);

class ExportedByRibbonLight CATRibTopOp : public CATTopRibObject
{
  public:

    //------------------------------------------------------------------------------
    // Constructor
    //------------------------------------------------------------------------------
    CATRibTopOp(CATSoftwareConfiguration * iConfig,
                CATCGMJournalList        * iJournal,
                CATBody                  * iCreationBody);
    CATCGMNewClassArrayDeclare; // Pool allocation

    //------------------------------------------------------------------------------
    // Constructor with CATTopData
    //------------------------------------------------------------------------------
    CATRibTopOp(CATTopData * iTopData,
                CATBody    * iCreationBody);

    //------------------------------------------------------------------------------
    // Destructor
    //------------------------------------------------------------------------------
    virtual ~CATRibTopOp();

    //------------------------------------------------------------------------------
    // Ajout d'une operation unitaire
    //------------------------------------------------------------------------------
    void Append (CATRibInit *SpecInit);

    //------------------------------------------------------------------------------
    // Ajout d'un ruban qui devient le ruban courant
    //------------------------------------------------------------------------------
    void Append (CATTopRib *iCurrentRib);

    //------------------------------------------------------------------------------
    // Lecture d'une operation unitaire (init)
    //------------------------------------------------------------------------------
    INLINE int   GetNbRibInits() { return _Inits.Size(); };
    CATRibInit * GetRibInit(int i); // METHODE_SAFE
    void         RemoveRibInit(int i);

    //------------------------------------------------------------------------------
    // Lecture d'un ruban
    //------------------------------------------------------------------------------
    INLINE int  GetNbRib() { return _Ribbons.Size(); };
    int         Locate(CATTopRib * iRibToLocate);
    INLINE CATTopRib * GetRib( int i) { return _Ribbons[i]; };
    CATTopRib * GetCurrentRib();
    void RemoveRibbon (CATTopRib * iRibToLocate);


    //------------------------------------------------------------------------------
    // Get factory
    //------------------------------------------------------------------------------
    CATGeoFactory * GetFactory();

    //------------------------------------------------------------------------------
    // Read SoftwareConfiguration
    //------------------------------------------------------------------------------
    CATSoftwareConfiguration* GetSoftwareConfiguration() const;

    //------------------------------------------------------------------------------
    // Met a jour les domaines et bodies modifies lors du smart duplicate lors du
    // calcul de maniere concurente de plusieurs rubans
    //------------------------------------------------------------------------------
    void UpdateSupports(ListPOfCATBody    * iBodiesBeforeDuplic,
                        CATBody           * iBodyAfterDuplic,
                        ListPOfCATDomain  * iDomainsBeforeDuplic,
                        ListPOfCATDomain  * iDomainsAfterDuplic);
    //------------------------------------------------------------------------------
    // Mode d'execution :
    // si previsu, alors on construit un resultat <<No TRIM>> malgre le cas echeant
    // la relimitation incomplete. On genere les wires pour representer les traces
    // non disconnectees.
    //------------------------------------------------------------------------------
    void SetPrevisu(CATTopOpPrevisualization iPrevisualization);
    INLINE CATTopOpPrevisualization GetPrevisu() { return _Previsualization; };

    //------------------------------------------------------------------------------
    // Mise A jour du journal (si different de celui donne au constructeur)
    //------------------------------------------------------------------------------
    // void SetJournal (CATCGMJournalList        * iJournal);

    //------------------------------------------------------------------------------
    // Read the stored journal
    //------------------------------------------------------------------------------
    CATCGMJournalList *GetJournal();

    //------------------------------------------------------------------------------
    // Run method
    //------------------------------------------------------------------------------
    virtual void Run(int iShouldFreezeAndComplete=1);

    //------------------------------------------------------------------------------
    // Compute the ribbon
    //------------------------------------------------------------------------------
    virtual void ComputeRibbon();

    //------------------------------------------------------------------------------
    // Create the ribbon (export)
    //------------------------------------------------------------------------------
    virtual void CreateRibbon();

    //------------------------------------------------------------------------------
    // Rend l'index dans la liste _LoopExtensions de la loop extension
    // si elle existe (0 sinon)
    //------------------------------------------------------------------------------
    CATLONG32 LocateLoopExtension(const CATLoopExtension* iLoopExtension);
    CATLONG32 LocateLoopExtension(CATFace* iInitialFace, CATLoop* iInitialLoop);
    CATLONG32 LocateLoopExtension(CATFace* iComplFace, CATLoopExtension*& oLoopExtension);

    //------------------------------------------------------------------------------
    // Cree une nouvelle CATExtensionLoop
    // Ajoute une reference a la LoopExtension
    // Rend son index dans la liste (qui est est le nb de LoopExtensions presentes)
    //------------------------------------------------------------------------------
    CATLONG32 CreateLoopExtension(CATFace* iInitialFace, CATLoop* iInitialLoop,
                                  CATBoolean iCreateSingleComplLoopExtension, CATSurLimits& iExtrapolResLimits);

    //------------------------------------------------------------------------------
    // Enleve un reference sur une LoopExtension.
    // Si c'est la derniere, on detruit la LoopExtension
    //------------------------------------------------------------------------------
    CATLONG32 RemoveLoopExtension( CATLoopExtension *&ioLoopExtension);

    //------------------------------------------------------------------------------
    // Rend le nombre de CATLoopExtension dans la liste.
    //------------------------------------------------------------------------------
    CATLONG32 GetNumberOfLoopExtensions();

    //------------------------------------------------------------------------------
    // Creation du shell des faces complementaires + Vider ce shell + Recup mode
    //------------------------------------------------------------------------------
    void CreateComplementaryShell() ;
    void EmptyComplementaryShell() ;
    INLINE int GetComplementaryShellMode() { return _ComplShellMode; };

    //------------------------------------------------------------------------------
    // Active la sauvegarde des faces complementaires
    //------------------------------------------------------------------------------
    void UpdateComplementaryShell();

    //------------------------------------------------------------------------------
    // Rend la iieme LoopExtension de la liste.
    //------------------------------------------------------------------------------
    CATLoopExtension* GetLoopExtension(const CATLONG32 i);

    //------------------------------------------------------------------------------
    // Set de _CleanLoopExtensionsOnly
    //------------------------------------------------------------------------------
    void SetCleanLoopExtensionsOnly(CATBoolean iCleanLoopExtensionsOnly) ;

    //------------------------------------------------------------------------------
    // Nettoyage et destruction de la liste des complementaires
    // qui subsistent, ainsi que des faces complementaires creees
    //------------------------------------------------------------------------------
    void CleanLoopExtensions() ;

    //------------------------------------------------------------------------------
    // Gestion (mise a jour et restauration) du resultat intermediare
    //------------------------------------------------------------------------------
    //  CATDomain * SaveAsIntermediateResult (CATDomain * iDom);
    //  CATDomain * RestoreIntermediateResult (CATDomain * iDom);

    //------------------------------------------------------------------------------
    // Set/Get pour la mise en place de la sauvegarde des MaxLimits des surfaces
    // extrapolees
    //------------------------------------------------------------------------------
    int  GetExtrSurfSize();
    CATSurface* GetExtrSurf(int i);
    CATSurLimits* GetOldMaxLim(int i);
    CATSurLimits* GetOldMaxLim(CATSurface *iSurface);
    void GetCandSurfsAndLimits(CATListPV &oCandSurfs,
                               CATListPV &oOldLims);


    //------------------------------------------------------------------------------
    // Rajoute iSurface et iOldLimits a leurs listes respectives si
    // 1) iSurface n'est pas deja presente ds la liste
    // 2) Les nouvelles MaxLimits sont superieures a iOldLimits
    // La methode renvoie 1 si l'ajout a ete fait, 0 sinon.
    //------------------------------------------------------------------------------
    int AddExtrSurfAndLimits(CATSurface    *iSurface,
                             CATSurLimits  &iOldLimits);

    //------------------------------------------------------------------------------
    // Regarde si l'une des PCurve du nuplet est posee sur la partie extrapolee
    // d'une des surfaces stockees (on procede par un PCurve->GetBoundingBox())
    // Si oui, on indique qu l'on ne peut pas ecraser l'extrapolation de la surface
    // associee a la PCurve.
    //------------------------------------------------------------------------------
    virtual void NeedExtrSurf(CATIntRibNuplet *iNuplet);

    //------------------------------------------------------------------------------
    // Rend 1 si iSurface est candidate a la "desextrapolation", 0 sinon.
    //------------------------------------------------------------------------------
    int IsCandToDesextrapol(CATSurface *iSurface);

    //------------------------------------------------------------------------------
    // Set the Parting element
    //------------------------------------------------------------------------------
    void SetPartingElement (CATBody                     *iPartingBody,
                            CATDomain                   *iPartingShell,
                            const CATTopRibSign          iPartingOrientation,
                            const int                    iSmartCrossParting=0,
                            CATFilletCrossPartingLinker *iLinker=NULL, 
                            int iLimitingCreatedFromConstructionDetails = 0,
                            int iUniqueInfo = 0);
    void SetPartingElement (CATParting      *iParting);

    //------------------------------------------------------------------------------
    // NotifyCompleteStarted : Maj de la profondeur d'appel de CATRlmRib::Complete()
    // NotifyCompleteFinished: Maj de la profondeur d'appel de CATRlmRib::Complete()
    // GetCompletionDepth    : Recuperation de cette profondeur d'appel
    // ThrowIfMaxCompletionDepthReached : Comme son nom l'indique
    //------------------------------------------------------------------------------
    void NotifyCompleteStarted();
    void NotifyCompleteFinished();
    INLINE int GetCompletionDepth() { return _CompletionDepth; };
    void ThrowIfMaxCompletionDepthReached();

    //------------------------------------------------------------------------------
    // Get/Set de _RecursiveCompletion
    //------------------------------------------------------------------------------
    CATBoolean GetRecursiveCompletionAllowed();
    void       SetRecursiveCompletionAllowed(int iRecursiveCompletion);

    //------------------------------------------------------------------------------
    // Get/Set de _HoleCreation
    //------------------------------------------------------------------------------
    INLINE CATBoolean GetHoleCreationAllowed() { return _HoleCreation; };
    void SetHoleCreationAllowed(CATBoolean iHoleCreation);

    //------------------------------------------------------------------------------
    // Get/Set de _NbSupplementaryFaces
    //------------------------------------------------------------------------------
    INLINE int GetNbSupplementaryFacesAllowed() { return _NbSupplementaryFaces; };
    void SetNbSupplementaryFacesAllowed(int iNbFaces);

    //------------------------------------------------------------------------------
    // Get/Set de _ConditionalSplitEdge
    //------------------------------------------------------------------------------
    INLINE CATBoolean GetUnconditionalSplitEdge() { return _UnconditionalSplitEdge; };
    void SetUnconditionalSplitEdge();    
    void UnsetUnconditionalSplitEdge();    

    //------------------------------------------------------------------------------
    // Get/Set pour Imprint Edges
    //------------------------------------------------------------------------------
    void     SetBodyWithImprints(CATBody* iBodyWithImprints);
    CATBody* GetBodyWithImprints();

    //------------------------------------------------------------------------------
    // Get/Reset/Add des vertex dont on ne veut pas en tant que vertex d'extrapol
    //------------------------------------------------------------------------------
    INLINE ListPOfCATVertex* GetNonExtrVertices() { return _NonExtrVertices; };
    void ResetNonExtrVertices();
    void AddNonExtrVertices(ListPOfCATVertex *iNonExtrVertices);

    //------------------------------------------------------------------------------
    // Gestion des vertex pour arreter les completions
    //------------------------------------------------------------------------------
    void AddStopExtrapolVertex(CATVertex* iVertex);
    CATBoolean IsStopExtrapolVertex(CATVertex *iVertex);

    //------------------------------------------------------------------------------
    // Get/Remoce/Add des faces dont on ne veut pas se servir pour creer des rubans
    // d'extrapolation
    //------------------------------------------------------------------------------
    INLINE ListPOfCATFace* GetFacesToAvoidForExtrRib() { return _FacesToAvoidForExtrRib; };
    void RemoveFaceToAvoidForExtrRib(CATFace *iFace);
    void AddFacesToAvoidForExtrRib(ListPOfCATFace *iFacesToAvoidForExtrRib);

    //------------------------------------------------------------------------------
    // Perfs : pour garder les equations ouvertes
    //------------------------------------------------------------------------------
    void LockSupportsInFormol(CATGeometry* iGeometry);

    void DeleteFormol(); // detruit le formol et libere les equations

    //------------------------------------------------------------------------------
    // Lumps (skins or volumes) from original body to delete in the NoTrim case
    //------------------------------------------------------------------------------
    void AddDomainsToKeep();
    void AddDomainsToKeep(CATDomain * iDomain);

    //------------------------------------------------------------------------------
    // Ajout de created wires
    //------------------------------------------------------------------------------
    void AddCreatedWire(CATDomain * iDomain);

    //------------------------------------------------------------------------------
    // Active ou desactive le mode trim
    //------------------------------------------------------------------------------
    void SetNoTrim(CATBoolean iNoTrim);

    //------------------------------------------------------------------------------
    // AddListOfEdgeToCleanAfterDisconnect
    //------------------------------------------------------------------------------
    void AddEdgeToCleanAfterDisconnect(CATEdge * iEdge);

    //------------------------------------------------------------------------------
    // Pour generer un diagnostic specifique
    //------------------------------------------------------------------------------
    void SetErrorDiagType(int iType);

    //------------------------------------------------------------------------------
    // Communication avec le maitre sur la nature de l'erreur - actif pour TrimSew
    //------------------------------------------------------------------------------
    //virtual void SetNoResultVolume();

    //------------------------------------------------------------------------------
    // Pour disposer d'un operateur topologique sans pb de desalloc VC8
    // Attention : pas de journal donne a l'operateur pour le moment
    //------------------------------------------------------------------------------
    CATTopologicalOperator* GetCATTopologicalOperator();

  protected:

    void Init0               ();
    void Init                (CATSoftwareConfiguration * iConfig,
                              CATCGMJournalList        * iJournal,
                              CATBody                  * iCreationBody);


    //------------------------------------------------------------------------------
    // Creation des wires a partir de tous les edges d'une skin
    //------------------------------------------------------------------------------
    void CreateWiresFromSkin (CATShell * iSkin, ListPOfCATDomain &oCreatedWires);


    //------------------------------------------------------------------------------
    // Data
    //------------------------------------------------------------------------------
  protected:

    CATBody                   * _CreationBody;
    CATCGMJournalList         * _Journal;
    int                         _SegmentationMode;  // TRIM ou NOTRIM, voir CATBlendParam

    //------------------------------------------------------------------------------
    // Data for management of limiting elements
    //------------------------------------------------------------------------------
    CATParting                 *_Parting;
    CATTopRibSign               _PartingOrientation;
    ListPOfCATEdge             *_ListOfEdgesToClean,
                               *_ListOfEdgesToSimplify;
    ListPOfCATFace             *_ListOfFacesToSimplify;
    CATBoolean                  _PartingIsPrivate;
    ListPOfCATEdge              _ListOfEdgeToSimplifyAfterSewing;  // Liste de "fat" edges à simplifier après la couture
    ListPOfCATEdge              _ListOfEdgeToCleanAfterDisconnect; // Liste d'edges à nettoyer après la disconnection de la couture
    int                         _NbRelimitationLoop;


    //------------------------------------------------------------------------------
    // If _MultiOperationContext is False, no other operation is performed in the same
    // transaction (cf. : run in multiribbonfillet),
    // If _MultiOperationContext is TRUE, the operation is performed amid other operations
    // defined by the multiple selection.
    // The default is FALSE.
    //------------------------------------------------------------------------------
    CATBoolean                 _MultiOperationContext;
  public :
    virtual void SetMultiOperationContext(CATBoolean iValue);


  protected:

    //------------------------------------------------------------------------------
    // Etude des collision inter limiting/parting : a definir dans les derivees
    // Rend TRUE s'il y a collision, FALSE sinon
    //------------------------------------------------------------------------------
    virtual CATBoolean CheckPartingsCollision(ListPOfCATShell &iAllPartingShells,
                                              ListPOfCATShell &iPartingShellsToDisc);

    //------------------------------------------------------------------------------
    // Remove info
    //------------------------------------------------------------------------------
    virtual void RemoveInfo(CATShell* iInitialShell);

    //------------------------------------------------------------------------------
    // Simplify Faces and Edges
    //------------------------------------------------------------------------------
    virtual void Simplify(CATShell * iShell, CATCGMJournalList  * iJournalForEdges=NULL, CATBoolean iKeepListOfEdgesToSimplify=FALSE);

  protected:
    CATSoftwareConfiguration *_SoftwareConfiguration;

    //------------------------------------------------------------------------------
    // Create MultiRib Error
    //------------------------------------------------------------------------------
  protected:
    CATError * CreateMultiRibbonError();

  protected:
    //------------------------------------------------------------------------------
    // Decomposition en composantes connexes
    // CheckTwist Indique si on veut eliminer les domaines twistes
    //            Par defaut, ce test est inutile car la detection de twist a deja ete faite en amont
    //            A n'utiliser donc que dans des derivations specifiques !
    //------------------------------------------------------------------------------
    void BuildDomains(CATDomain* iDomainToSplit,
                      CATBoolean iCheckTwist=FALSE,
                      ListPOfCATDomain* ioListOfCreatedDomain=NULL);



    //------------------------------------------------------------------------------
    // Shell to delete
    //------------------------------------------------------------------------------
    void AddShellToDelete   (CATDomain * iShellToDelete);
    void RemoveShellToDelete(CATDomain * iShellToDelete);

    //------------------------------------------------------------------------------
    // Cleans body before it is completed
    //------------------------------------------------------------------------------
    virtual void CleanUp(CATBoolean iWithError=FALSE);

    //------------------------------------------------------------------------------
    // IZE wk. 30 2010 Restore some internal data which would otherwise be destroyed
    // leading to potential core dumps
    //------------------------------------------------------------------------------
    virtual void RestoreSpecificContent(CATCGMJournalList * iEdgesJournal=NULL);

    //------------------------------------------------------------------------------
    // Update the DraftInits after disconnecting the Parting element
    //------------------------------------------------------------------------------
    virtual void UpdateInitsWithParting (CATCGMJournalList *iEdgesJournal=NULL,CATBoolean iNeedEdgesJournal=FALSE);

    //------------------------------------------------------------------------------
    // Maj des Inits dans le cadre des complementaires drop2
    // A deriver sans doute pour avoir un journal d'edge
    //   comme ds UpdateInitsWithParting (cf. keep edges)
    //------------------------------------------------------------------------------
    void UpdateInitsForClosure(CATShell* iUpdatedShell,
                               CATBody*  iUpdatedBody );

    //------------------------------------------------------------------------------
    // recherche le body auquel appartient la cell : la recherche se fait uniquement
    // parmis les body initiaux.
    //------------------------------------------------------------------------------
    CATBody * GetInitialBodyOfCell (CATCell *cell);


    //------------------------------------------------------------------------------
    // recherche de tous les body initiaux
    //------------------------------------------------------------------------------
    void GetAllInitialBodies (ListPOfCATBody &Liste);


  protected:
    //------------------------------------------------------------------------------
    // Check For MaxGap in order to Create Warning
    //------------------------------------------------------------------------------
    CATBoolean WarningMaxGapOnShell(CATShell                  * iShell,
                                    CATTopTools::GapCheckMode   iGapCheckMode = CATTopTools::G0GapCheckMode);

    CATBoolean WarningMaxGapOnShell(CATShell                  * iShell,
                                    CATTopTools::GapCheckMode   iGapCheckMode,
                                    const ListPOfCATEdge &ListeTransEdgeToCheck);

    CATBoolean WarningMaxGapOnListOfDomain (const ListPOfCATDomain & iDomain);


    //------------------------------------------------------------------------------
    // Store the faces of the skin (after disconnection and before sewing)
    // in order to update and identify them later on in the resulting body
    //------------------------------------------------------------------------------
    void StoreSkinFaces(CATShell           *iSkin,
                        CATTopRibMacroTool *iMacroTool);

    //------------------------------------------------------------------------------
    // Couture
    //------------------------------------------------------------------------------
  protected:
    void Sewing(CATShell        *iSkinToSew,
                CATShell        *iInitialShell,
                CATTopRibSign    iSewingOrientation,         // Orientation pour que la skin pointe vers le shell initial
                CATLump        **oLump               = NULL,
                CATSewingCompl  *iConvexSewingCompl  = NULL,
                CATSewingCompl  *iConcavSewingCompl  = NULL,
                ListPOfCATFace  *iInitSpecFaces      = NULL,
                CATBoolean       iDoKeepCoveredFaces = FALSE,
                CATBoolean       iAlignMode          = FALSE,
                CATBoolean       iNoSimplif          = FALSE,
                CATBoolean       iNoSimplifOfSkin    = FALSE,
                CATBoolean       iEdgeReporting      = FALSE,
                CATBoolean       iSplitCvEdges       = FALSE,
                CATBoolean       iRmIdCovFaces       = FALSE,
                CATBoolean       iAddG1FreeCase      = FALSE,
                CATBoolean       iAddG1ConfCase      = FALSE,
                ListPOfCATEdge  *iSkinEdgesToSimplify          = NULL,
                ListPOfCATEdge  *iRlmBodyEdgesToSimplify       = NULL,
                ListPOfCATEdge  *iSplittingEdgesOnCoveredFaces = NULL,
                ListPOfCATFace  *iFacesNotToSimplify           = NULL, //d1a : FacesNotToSimplify                
                ListPOfCATFace  *iDrftInitFaces                = NULL);

    virtual void AdvSewing(CATShell        *iSkinToSew,
                           CATShell        *iInitialShell,
                           ListPOfCATFace  *iDrftInitFaces,
                           CATTopRibSign    iSewingOrientation);

    void CreateSewingOpt();

#ifdef PRL_TestForTweaking
    virtual CATBoolean IsGoodCandidateForFinalRemove(CATFace* iFaceToRm);
#endif

    //------------------------------------------------------------------------------
    // Simplification des faces de la skin a coudre
    //------------------------------------------------------------------------------
  protected:
    void SimplifySkinFacesAndEdges(ListPOfCATFace &iSkinFaces,
                                   CATShell       *iInitialShell);

    //------------------------------------------------------------------------------
    // Isolation de la skin (a utiliser en mode NOTRIM)
    //------------------------------------------------------------------------------
  protected:
    void IsolateSkin(CATShell *iSkinShell,
                     CATShell *iInitialShell);


    //------------------------------------------------------------------------------
    // Add a skin face
    //------------------------------------------------------------------------------
  public:
    void AddSkinFace(CATFace        *iSkinFace,
                     CATOrientation  iSkinFaceOrientation,
                     CATOrientation  iOrientationVsParting);

    //------------------------------------------------------------------------------
    // Get the skin faces
    //
    // Please note: this method clears the provided oSkinFaces list and appends
    //              the contents of the _SkinFaces to it
    //------------------------------------------------------------------------------
  public:
    void GetStoredSkinFaces(ListPOfCATFace &oSkinFaces,
                            CATListOfInt   &oSkinFacesOrientations,
                            CATOrientation  iOrientationVsParting);

    //------------------------------------------------------------------------------
    // pfv 2004.01.22
    // Isolate all the CATRibInit from this CATRipTopOp operator
    // in order to delay the CleanUp of the CATRibInit
    //------------------------------------------------------------------------------
  public :
    void         Isolate      (CATBoolean iOperationIsOK=FALSE);
    //virtual void RememberBody ();

    //------------------------------------------------------------------------------
    // Get the domains to delete
    //------------------------------------------------------------------------------
  public:
    INLINE CATLONG32 GetNumberOfDomsToDelete() { return _DomsToDelete.Size(); };
    CATDomain * GetDomToDelete(CATLONG32 iDomToDeleteNumber);


    //-------------------------------------------------------------------------------
    // Get the number of relimitation loops
    //-------------------------------------------------------------------------------
  public:
    virtual void GetNbRelimitationLoops(int &oNbRelimitationLoops);

  protected:
    //private: a remettre en prive tres vite
    //------------------------------------------------------------------------------
    // Data
    //------------------------------------------------------------------------------
    // donnees generales
    int                  _ShouldFreezeAndComplete;
    ListPOfCATDomain     _CreatedWires;            // Stockees pour pouvoir nettoyer les liens coupants?
    int                  _NumberOfComputedInits;
    int                  _ErrorType;

    //------------------------------------------------------------------------------
    // Requettes sur les cellules posees sur les supports <<With Traces>>
    //------------------------------------------------------------------------------
  public:
    virtual void GetCuttingInfosOnSupport(const int iSupport,
                                          ListPOfCATCell & oSplitCell,
                                          CATListOfInt   & oSideKeep );

    // Start : SOU : 2004:5:31
  public:
    void GetDomainsToKeep(ListPOfCATDomain &oDomainsToKeep);

    //we will use _DomsToKeep as reference and update _DomsToDelete
    void UpdateDomainsToDelete();
    // End : SOU : 2004:5:31

    //------------------------------------------------------------------------------
    // Set the need for updating the touch flags on the shells
    //------------------------------------------------------------------------------
  public:
    INLINE void SetNeedForUpdateTouchOnShells(CATBoolean iUpdateTouchOnShellsIsNeeded) { _UpdateTouchOnShellsIsNeeded = iUpdateTouchOnShellsIsNeeded; };

    //------------------------------------------------------------------------------
    // Is it necessary to update the touchg flags on the shells?
    //------------------------------------------------------------------------------
  public:
    INLINE CATBoolean IsUpdateTouchOnShellsNeeded() { return _UpdateTouchOnShellsIsNeeded; };

    //------------------------------------------------------------------------------
    // Pilotage de la duplication pour la couture
    //------------------------------------------------------------------------------
  public :
    INLINE void SetUseFullDuplication(CATBoolean iUseFullDupl) { _UseFullDuplication = iUseFullDupl; };
    INLINE CATBoolean UseFullDuplication() { return _UseFullDuplication; };

    //------------------------------------------------------------------------------
    // Methode de cast - rendent NULL sur la classe mere, a deriver dans les
    // classe adhoc
    //------------------------------------------------------------------------------
  public :
    virtual CATBlendTopOp*  GetAsBlendTopOp()  {return NULL;};
    virtual CATRibAdvTopOp* GetAsRibAdvTopOp() {return NULL;};
    virtual CATDraft*       GetAsDraft()       {return NULL;};
    virtual CATRelimTopOp*  GetAsRelimTopOp()  {return NULL;};

    //------------------------------------------------------------------------------
    // Percement de trous (specifique Draft)
    //------------------------------------------------------------------------------
  public :
    CATFace* GetHoleCreationFace();
    void SetHoleCreationFace(CATFace* iHoleCreationFace);
    void SetSkinHasBeenClosed();
    CATBoolean SkinHasBeenClosed();
    virtual void SetReLaunchValue(int iVal);

  protected:
    CATListPV            _LoopExtensions;          // Liste de references vers des loopextensions
    CATListPV            _ExtrSurf;                // Liste des surfaces extrapolees ds CATIntRibNuplet
    CATListOfInt         _IsCandToDesextr;         // Liste parallele a la precedente indiquant si on peut
    // ecraser l'extrapolation de la surface ou pas
    CATLISTP(CATSurface) _Compl2Surfs;             // Liste des surfaces des faces ayant une edge "remplacee/deja remplacee"

    //------------------------------------------------------------------------------
    // Methodes pour le traitement des complementaires "Drop2"
    //------------------------------------------------------------------------------
  public :
    enum ReplaceEdgCrvType {
      Unknown = 0,          // Non calcule
      NoFrontier,           // Pas de frontiere
      MCrvAlreadyOK,        // MergedCurve avec toutes les composantes deja presentes
      Failed,               // Remplacement necessaire, mais echec
      Done                  // Remplacement effectue avec succes
    };
    void                 SetComplementairesFix_2(CATBoolean iActivate);
    INLINE CATBoolean    GetComplementairesFix_2() { return _ComplFixed2; };
    void                 SetLimitsMode(int iMode);
    INLINE int           GetLimitsMode() { return _LimitsMode; };
    void                 SetClosureOnFrontierIsDetected(CATEdge* iEdge);
    CATBoolean           ClosureOnFrontierHasBeenDetected();
    void                 SetReplaceECrvOnFrontier();
    INLINE CATBoolean    GetReplaceECrvOnFrontier() { return _ReplaceFrontier; };
    void                 SetRelaunchMode();
    void                 SetCommonEdgeForExtrRib(CATEdge* iEdge, CATTopRib* iRib);
    CATEdge*             GetCommonEdgeForExtrRib(CATTopRib* iRib);
    void                 AddLyingOnCompl2Surface(CATSurface* iSurf);
    CATBoolean           IsLyingOnCompl2Surface (CATSurface* iSurf);
    ReplaceEdgCrvType    CheckAndManageClosureOnFrontier(CATShell*           iInitialShell,
                                                         CATBody*            iInitialBody,
                                                         CATBody*            iCreationBody,
                                                         CATCGMJournalList*  iEdgesJournal,
                                                         CATShell*&          oModifiedShell);
    //virtual void         UpdateEdgeJournal(CATCGMJournalList* iJournal);

  protected:
    //------------------------------------------------------------------------------
    // Data
    //------------------------------------------------------------------------------
    CATBoolean               _ComplFixed2;             // TRUE si on est dans un mode "Complementaire Drop2 actif"
    CATBoolean               _ClosureOnFrontier;       // TRUE si on a detecte une config "Drop2" necessitant un remplacement d'EC
    CATEdge*                 _ClosureEdgeOnFrtr;       // L'edge sur laquelle on a trouve le pb de fermeture
    CATBoolean               _ReplaceFrontier;         // Complementaires Drop2
    CATBoolean               _RelaunchMode;            // TRUE si run en mode Relaunch
    CATEdge*                 _CEdgeForExtr;            // L'edge du contact commun
    CATTopRib*               _CERibForExtr;            // Le ruban pour lequel on a renseigne _CEdgeForExtr
    CATTopFlexibleBRep*      _FlexBRep;                // Operateur flexible
    CATCGMJournalList*       _PrivFlexJournal;         // Journal pour l'uto du Flexible

    CATShell                *_ComplementaryShell;      // Enregistrement des faces complementaires dans un shell
    int                      _ComplShellMode;          // Differentes modes d'utilisation de ce shell (0 - mode par defaut / 1 - mode specifique pour le fillet G2)
    int                      _LimitsMode;              // Differents modes de definition des limites

    ListPOfCATDomain         _ListOfNoTrimDoms;        // Domaines avec l'attribut NoTrim

    CATLightJournalChecker  *_LightJChecker;           // Verif de journal 'legere' 

    CATSewingOpt            *_SewOpt;                  // Les options particulieres de la couture


  private:
    //------------------------------------------------------------------------------
    // Data
    //------------------------------------------------------------------------------

    ListPOfCATDomain     _DomsToDelete;
    ListPOfCATDomain     _DomsToKeep;

    int                  _CleanedBody;             // Indique si le body a ete nettoye ou non
    ListPOfCATRibInit    _Inits;                   // pointeurs vers les operateurs unitaires initialisantles rubans
    ListPOfCATTopRibs    _Ribbons;
    CATTopRib           *_CurrentRib;              // Ruban courant    
    CATBoolean           _CleanLoopExtensionsOnly; // Indique si le destructeur doit nettoyer tout le body ou simplement _LoopExtensions

    CATListPV            _OldMaxLim;               // Liste parallele a la precedente contenant les maxLimits avant l'extrapolation.

    int                  _CompletionDepth;         // Pour sortie en erreur si on fait de la completion de completion de completion de ...
    int                  _RecursiveCompletion;     // Indique si on autorise la completion des rubans d'extrapolation ou non (-1 pour une interdiction definitive)
    CATBoolean           _HoleCreation;            // Indique si on autorise la creation de "trous"
    ListPOfCATVertex    *_NonExtrVertices;         // Liste des vertex dont on ne veut pas en tant que vertex d'extrapolation
    ListPOfCATVertex     _StopExtrapolVertices;    // Liste des vertex pour stopper les completions
    ListPOfCATFace      *_FacesToAvoidForExtrRib;  // Liste des faces dont on ne veut pas se servir pour creer des rubans d'extrapolation
    CATBody             *_BodyWithImprints;        // Pour Imprint edges
    int                  _NbSupplementaryFaces;    // Pour complementaires
    int                  _UnconditionalSplitEdge;  // Pour piloter SplitEdge


    CATTopOpPrevisualization _Previsualization;    // Mode de creation du resultat :

    ListPOfCATFace       _SkinFaces[2];
    CATListOfInt         _SkinFacesOrientations[2];

    CATBoolean           _UpdateTouchOnShellsIsNeeded;
    CATBoolean           _UseFullDuplication;      // Pilotage couture

    //CATBoolean           _CreationBodyIsLive;      // Gestion body live
    //CATBoolean           _LiveChecked;             // Gestion body live
    CATCGMFormol        *_Formol;                  // Gestion lock/unlock geometries

    CATTopologicalOperator* _TopOper;              // Pour disposer d'un operateur topologique sans pb de desalloc VC8
    CATBody*                _TopOperBody;          // Au cas ou on aurait changer de body de creation entre 2 appels
                                                   // a GetCATTopologicalOperator
    CATFace*             _HoleCreationFace;        // pour percer des trous (cas du cylindre debouchant qui se bouche)
    CATBoolean           _SkinClosed;              // TRUE si l'on a ferme la skin    

};

// UVC 29-May-2013: Fast Update needs to produce some non-smart topology.
#include "ExportedByRIBLight.h"
ExportedByRIBLight
CATRibTopOp::ReplaceEdgCrvType CheckAndManageClosureOnFrontierImp( CATBody                  * iInitialBody,
                                                                   CATBody                  * iCreationBody,
                                                                   CATBody                  * iWorkingBody,
                                                                   CATCGMJournalList        * iJournal,
                                                                   CATSoftwareConfiguration * iConfig,
                                                                   CATGeoFactory            * iFactory,
                                                                   ListPOfCATFace           & iFaces,
                                                                   CATShell                ** oModifiedShell = 0,
                                                                   CATTopFlexibleBRep      ** oFlexOp = 0,
                                                                   CATCGMJournalList       ** oFlexJ = 0,
                                                                   CATLISTP(CATSurface)     * ioCompl2Surfs = 0,
                                                                   CATCGMJournalList        * iEdgesJournal = 0,
                                                                   CATBoolean                 iGetAsBlendTopOp = FALSE );
#endif
