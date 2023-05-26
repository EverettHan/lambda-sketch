/* -*-C++-*- */

#ifndef CATSewing_H
#define CATSewing_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//-----------------------------------------------------------------------------
//
// CATSewing
// Definition d'une classe pour la couture
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Usage notes:
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Janv.98    Creation                                      FDN & FLT
//            Contributions majeures                        FDN ASE CWM PRL
//
//  ->2007    Responsable                                   PRL
//-----------------------------------------------------------------------------

#include "CATSewingCompl.h"

#include "RibbonLight.h"
#include "CATMathDef.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATTopologicalOperator.h"
#include "CATCGMJournalList.h"
#include "CATTopRibObject.h"
#include "CATCGMNewArray.h"
#include "CATListOfCATSurfaces.h"

class CATDomain;
class CATBody;
class CATCGMJournalList;
class CATSoftwareConfiguration;
class CATRibTopOp;
class CATSewingOpt;
class CATTopCellTrackerByCGMAttrId;

#include "CATSafe.h"
CATSafeDefine(CATSewing);

class ExportedByRibbonLight CATSewing : public CATTopRibObject
{

  public :
  //------

  //--------------------------------------------------------------------------
  // Constructor
  //---------------------------------------------------------------------------
  
  CATSewing(CATDomain * iDomToSew,  
            CATDomain * iDomSupport, 
            CATBody * iBodyCreation,
            CATBody * iBodySupport,
            CATSoftwareConfiguration * iConfig,
            CATCGMJournalList *iJournal = NULL);
  CATCGMNewClassArrayDeclare; // Pool allocation
  
  //--------------------------------------------------------------------------
  // destructor
  //---------------------------------------------------------------------------
  
  ~CATSewing();
  
  //--------------------------------------------------------------------------
  // Ajout de faces complementaires
  //---------------------------------------------------------------------------
  void SetComplement(CATSewingCompl *iFacesComplementaires, int iToCopy=1);

  //--------------------------------------------------------------------------
  // Ajout du domaine des faces complementaires
  //---------------------------------------------------------------------------
  void SetComplement(CATDomain *iDomain);

  //--------------------------------------------------------------------------
  // Run
  //---------------------------------------------------------------------------
  void Run(int iSelectionFlag=1, CATRibTopOp *iRibTopOp = NULL);
  
  //--------------------------------------------------------------------------
  // Set the optionnal data for the edges reporting
  //---------------------------------------------------------------------------
  void SetEdgeReporting ( CATCGMJournalList *iJournal);

  //--------------------------------------------------------------------------
  // Prevent any simplification
  //---------------------------------------------------------------------------
  void SetNoSimplif();

  //--------------------------------------------------------------------------
  // Pour ne pas creer des aretes a la convexites changeante.  
  //---------------------------------------------------------------------------
  void SplitEdgesForConvexityChange(CATCellHashTable*  iHTCells,
                                    CATLISTP(CATEdge)& iListEdges);

  //--------------------------------------------------------------------------
  // Pour activer la methode precedente.
  //---------------------------------------------------------------------------
  void ActivateSplitEdgesForConvexityChange();

  //--------------------------------------------------------------------------
  // Prevent deletion of covered faces (in the journal)
  //---------------------------------------------------------------------------
  void KeepCoveredFaces();

  //--------------------------------------------------------------------------
  // Ajout d'edges coupantes supllementaires (optionel) :
  //  ce sont des edges qui sont coupantes et non bords de skin
  //--------------------------------------------------------------------------
  void SetAdditionalSplittingEdges(ListPOfCATEdge * iSplittingEdges,
                                   CATListOfInt   * iSidesToKeep);

  //--------------------------------------------------------------------------
  // Set des faces a degager de toutes facons
  //--------------------------------------------------------------------------
  void SetFacesToRemove( ListPOfCATFace *iFacesToRemove);
  void SetRemoveIdCoveredFaces();

  //--------------------------------------------------------------------------
  // SetCuttingEdgesIntersection -> active ou desactive la verification des coupantes
  //--------------------------------------------------------------------------
  void SetCheckCuttingEdgesIntersections(CATBoolean iCheckCuttingEdgesIntersections);

  //--------------------------------------------------------------------------
  // Set AlignMode 
  //--------------------------------------------------------------------------
  void SetAlignMode();

  //--------------------------------------------------------------------------
  //  Gestion d'edges sur lesquelles on appelle en CleanDisconnectInfo
  // avec simplification des FatEdges
  //--------------------------------------------------------------------------
  void AddListOfEdgeToCleanAndDisconnect(const ListPOfCATEdge & ListOfEdgeToSimplifyAfterSewing);

  //----------------------------------------------------------------------
  // Gestion d'edges sur lesquelles on appelle CleanDisconnectInfo
  // apres la disconnection (cas de FlatVertex)
  //----------------------------------------------------------------------
  void AddListOfEdgeToCleanAfterDisconnect(const ListPOfCATEdge & iListOfEdgeToCleanAfterDisconnect);
  
  //---------------------------------------------------------------------
  // Dans le cas de plusieurs appels à la couture successifs
  // cette méthode permet de gérer quand on veut simplifier les FatEdges
  //---------------------------------------------------------------------
  void SetDoSimplifFatEdge(CATBoolean iDoSimplifyFatEdge);

  //---------------------------------------------------------------------
  // Dans le cas du draft et du tweaking
  // La simplif de la skin est appelee dans la couture (un appel unique)
  //---------------------------------------------------------------------
  void SetSimplifOfSkin();

  //---------------------------------------------------------------------
  // Restreint la simplification des faces de la skin cousue a la
  // liste en entree - permet la sauvegarde des drawings sur la skin
  //---------------------------------------------------------------------
  void SetSkinEdgesToSimplify(ListPOfCATEdge*  iSkinEdgesToSimplify);

  //---------------------------------------------------------------------
  // Ajoute des edges a simplifier sur le shell relimitant - utilise
  // pour le cas NoTangencyPropag de CLS
  //---------------------------------------------------------------------
  void SetRlmBodyEdgesToSimplify(ListPOfCATEdge*  iRlmBodyEdgesToSimplify);
  
  //---------------------------------------------------------------------
  // Ajoute des edges presentes dans les listes convexe et concave
  // du TrimSew pour qu'elles soient vues comme des splitting edges
  // avec les 2 faces a enlever dans le resultat
  //---------------------------------------------------------------------
  void SetSplittingEdgesOnCoveredFaces(ListPOfCATEdge*  iSplittingEdgesOnCoveredFaces);

  //---------------------------------------------------------------------
  // Ajoute les faces init du Draft
  //---------------------------------------------------------------------
  void SetDrftInitFaces(ListPOfCATFace  *iDrftInitFaces);

  //---------------------------------------------------------------------
  // Specifie les modes AddG1Only (Draft)
  //---------------------------------------------------------------------
  void SetAddG1FreeCase();
  void SetAddG1ConfCase();

  //---------------------------------------------------------------------
  // Options specifiques
  //---------------------------------------------------------------------
  void SetOptions(CATSewingOpt* iSewOpt);

  //---------------------------------------------------------------------
  // IZE wk. 01 2010 IR 021460 Some checks are too restrictive for SheetMetal configurations
  //---------------------------------------------------------------------
  void SetUnplugChecksForSheetMetal(CATBoolean iUnplugChecksForSheetMetal);

  private :
  //-------

  //RAD : pour laisser des cellules de travail accroche au body
  CATDomain*  _WorkDom;
  void StoreFacesInWorkDom(ListPOfCATFace&);
  //RAD

  // Enleve la face du domaine de travail et de la liste de faces a effacer
  void RemoveFacesInWorkDom(CATFace * iFaceToRemove);

  // Gestion du journal
  void Journal (CATCGMJournal::Type TypeJournal, CATFace * AncienneFace,
                           ListPOfCATFace & NouvellesFaces);
  void Journal (CATCGMJournal::Type TypeJournal, ListPOfCATFace & Anciennes,
                           ListPOfCATFace & Nouvelles);

  // Mise a jour d'une face et de sa loop dans les listes de complementaires
  // void IniFacesMAJ (CATFace * OldFace, CATFace * NouvFace);

  // Ajout d'une edge coupante a une face, si elle n'y est pas
  void AddCuttingEdge(CATEdge * arete);
  
  // Report des informations de decoupe des faces initiales vers les 
  // complementaires
  void ReportCutting(CATFace*        iFaceFrom,
                     CATFace*        iFaceTo,
                     ListPOfCATEdge* iCoupantes,
                     CATBoolean      iReportEdges=CATBoolean(1));
  
  // smart duplicate du domaine et de sa famille, avec suivi des faces initiales complementaires
  // *** ATTENTION *** ne gere pas le cas lump multi-volume ... ***
  void DupliSmartMAJ (CATRibTopOp* iRibTopOp);

  void GetSpeFac();

  // Ajout au resultat d'un paquet de faces
  void AjouteFaces(ListPOfCATFace & iListeFaces,
			     CATSide iCote);

  // Ajout des faces resultantes de la decoupe des complementaires- Renvoie 0 si ajout impossible
  CATBoolean AjouteFacesCompl(ListPOfCATFace & TableauKeepCompl, 
                              int              iNumCompl,
                              ListPOfCATFace * iFacesSimplifiables=NULL,
                              ListPOfCATFace * iFacesSimplifiablesAvecCoupantes=NULL);
 
  // Retrait du resultat d'un paquet de faces
  void EnleveFaces(ListPOfCATFace & iListeFaces);

  // trouver la liste des faces a decouper
  void FindListPOfFace();

  // ajout d'une face a decouper a la liste des faces a decouper
  void AddFaceToSplitCand (CATEdge *curSplittingEdge, 
                           CATFace *curCellSupport, 
                           int verif=0);

  //decoupe d'une face et selection (iFaceIni indique un split de face complementaire)
  void SplitFace (CATFace        * iFaceToSplit,
                  ListPOfCATFace & oResuKeep,
                  ListPOfCATFace & oResuRemove,
                  CATFace        * iFacesIni=NULL);

  // effacement des elements inutiles
  void Clean();

  // UpdateComplement
  void UpdateComplement();
  
  // GetCoveredFaces (Modification + Info in _Journal)
  void GetCoveredFaces(CATLISTP(CATGeometry) & oCoveredFaces);

  // Debug
  void WriteInformation(CATDomain * iDomain);

  // verifie que les coupantes passees en entree ne s'intersectent pas (support : iFaceToSplit)
  void CheckSplittingEdges(ListPOfCATEdge *SplittingEdges, CATFace *iFaceToSplit);

  //--------------------------------------------------------------------------
  // Appel à la simplif de Fat Edge ou CleanDisconnectInfo (selon iFatMode)
  // en sortie de couture
  //--------------------------------------------------------------------------
  void CleanEdges(ListPOfCATEdge &iOldEdgesToClean,
                  CATBoolean      iFatMode);

  //--------------------------------------------------------------------------
  // Gestion de la simplification pour les fermetures
  //--------------------------------------------------------------------------
  void CheckSimplifClosure();

  //--------------------------------------------------------------------------
  // Gestion des liens pour les complementaires atypiques
  //--------------------------------------------------------------------------
  void UpdateLinkForCompl(CATBoolean&       ioLinkIniCpl,
                          CATFace*           iFaceIni,
                          CATFace*           iFaceCpl);

  //---------------------------------------------------------------------
  // Logical check for flat body generation
  //---------------------------------------------------------------------
  private:
  CATBoolean CheckFlatBody(      CATBody        *iBody,
                                 CATShell       *iShell,
                                 ListPOfCATEdge &iEdges);
  CATBoolean CheckForSpecConfig( CATBody        *iBody,
                                 CATEdge        *iEdge);

  CATBoolean CheckNMF(CATBody* iBody, CATDomain* iDomain);
                                    
  public:
    void DoNotSimplifyFaces(ListPOfCATFace * Faces) {_FacesNotToSimplify = Faces;} //d1a
  //--------------------------------------------------------------------------
  // Data
  //--------------------------------------------------------------------------
  private:

  ListPOfCATFace * _FacesNotToSimplify;   //d1a
  int _FlagSelection;                     // indique si on doit inverser la peau a coudre
  int _KeyAttOfSplittingEdgesOnFace;      // key d'attribut sur les faces pour les 
                                          //  edges coupantes
  int _KeyAttOnSplittingEdges;            // key d'attribut sur les edges coupantes
  int _KeyAttPropag;                      // key d'attribut pour les propagations
  ListPOfCATFace   _LesFaces ;            // liste des faces a couper
  //CATSewingCompl _LesCompl;             // structure des complementaires
  CATSewingCompl * _LesCompl;             // structure des complementaires
  CATBoolean       _LesComplIsPrivate;    // besoin de nettoyage
  CATListOfInt     _SideFaceIni;          // side des faces d'origine du complementaire (jgd) 
  ListPOfCATEdge   _LesSplittingEdges ;   // Liste des Edges coupantes. Ce sont :
                                          //  - soit les edges bords de la skin a coudre
                                          //     (celles-ci doivent etre toutes coupnates)
                                          //  - soit certaines edges a l'interieur
                                          //     de la skin a coudre. Ces derniere
                                          //     sont donnes a la couture par 
                                          //     SetAdditionalSplittingEdges avec le side
                                          //     a garder car sur ces edges on ne peut
                                          //     connaitre leur side Vs Shell !
                                          //  Remarque : ces edges (quand il y en a)
                                          //  sont en debut de liste et la liste de leur
                                          //  side est en phase avec ces edges
  ListPOfCATEdge  _SplitWithAddRefEdgs;
  ListPOfCATEdge  _LesSplittingEdgeNoSimplif;
  CATLONG32       _NbOfAdditionalSplittingEdges;
  CATListOfInt _SideToKeepOfAddtionalSplittingEdges; // Comme son nom l'indique...
  CATListOfInt _RefSidesForAdditionalEdges; // ici pr MLK
  CATListOfInt _ListOfSideToKeep;           // ici pr MLK
  ListPOfCATFace   _FacesComplToDel ;     // Faces complementaires a detruire 
  ListPOfCATFace   _FacesToDel ;          // Faces a detruire 
  ListPOfCATFace   _TrueKeepFaces;        // Faces identifiees a garder
  CATDomain * _DomToSew ;                 // domaine a coudre
  CATDomain * _DomSupport;                // domaine sur lequel on realise la couture
  CATDomain * _DomCompl;                  // domaine faces complementaires
  CATBoolean  _KeepDomCompl;              // 
  CATBody * _BodyCreation ;               // body resultat
  CATBody * _BodySupport;                 // body initial
  CATSoftwareConfiguration * _Config;
  CATVolume * _NewVolume;                 // nouveau volume (apres duplicate)
  CATTopologicalOperator*  _TopOp;        // operateur topologique pour disconnect
  CATTopData*              _TopOpData;
  CATRibTopOp*             _RibTopOp;
  int _AttSplittingEdgeTraiteCompl;       // indicateur arete complementaire traitee
  int _AttSplittingEdgeTraite;            // indicateur arete bord traitee
  CATCGMJournalList * _Journal;           // pour journaling
  CATCGMJournalList * _EdgesJournal;
  CATListPV _AllocatedEdgeListes;         // pour eviter les memory leak suite aux
                                          // attributs

  int _KeepCoveredFaces;                  // flag qui conditionnne la non destruction des
                                          // faces couvertes
  CATBoolean _NoSimplif;                  // CATSewing ne declenche aucune simplification 
  ListPOfCATFace  *_FacesToRemove_SFS;    // Faces a degager dans le SplitFaceAndSort
  ListPOfCATEdge   _ConfusedEdges;        // SplittingEdges en confusion avec une arete
  CATBoolean _CheckCuttingEdgesIntersections; // Verifie que les edges coupantes ne s'intersectent pas
  CATBoolean _AlignMode;                  // mode de relimitation pour lequel on simplifie les EC de la cicatrice
  CATBoolean _FaceCheckError;             // Un check de face à garder a trouvé une erreur
  ListPOfCATCell _ListOfCellForBodyError; // Liste des bodies d'erreur 
  ListPOfCATEdge _ListOfFatEdgeToSimplifyAfterSewing; // Liste d'edge sur lesquelles on appelle clean disconnect + simplif
                                                      // en fin de couture
  ListPOfCATEdge _ListOfFatEdgeToSimplifyAfterSewing_Ref; // Gestion cycle de vie
  ListPOfCATEdge _ListOfFlattenedEdge;
  ListPOfCATEdge _ListOfEdgeToCleanAfterDisconnect;   // Liste d'edges qu'on doit nettoyer apres la disconnection des faces
                                                      // et avant la selection des faces remove
  ListPOfCATCell _ListOfPbDiscFace;       // Liste de faces sur lesquelles on a un pb de disconnection
  CATBoolean _DoSimplifyFatEdge;
  ListPOfCATEdge _ListOfEdgeOnComplFaceToSimplify;
  CATBoolean     _SimplifOfSkin;          
  ListPOfCATEdge* _SkinEdgesToSimplify;          // Liste pour la simplification restreinte de la skin a coudre
  ListPOfCATEdge* _RlmBodyEdgesToSimplify;       // Liste pour la simplification dans le cas CLS 'NoTangencyPropag'
  ListPOfCATEdge* _SplittingEdgesOnCoveredFaces; // Liste d'edges a ajouter aux splitting edges, pour TrimSew
  ListPOfCATFace*      _DrftInitFaces;           // Listes des faces init du Draft
  CATLISTP(CATSurface) _DrftInitSurfs;           // Liste des surfaces des faces _DrftInitFaces (sans doublon)
  CATBoolean     _SplitCvEdges;           // Activation de la decoupe d'edges presentant des chnagements de convexite
  CATBoolean     _RmIdCovFaces;           // Pour piloter la couture
  CATBoolean     _AddG1FreeCase;          // Pour couture specifique bords libres Draft
  CATBoolean     _AddG1ConfCase;          // Pour couture specifique avec confusions HFV
  ListPOfCATFace _LFacesOld_ChangeForRemoveAndAdd; // Pour la maj des faces qd on cree une complementaire en cours de couture
  ListPOfCATFace _LFacesNew_ChangeForRemoveAndAdd; // Liste des faces nelles [non synchro avec la liste Old]
  CATListOfInt   _LFacesNew_Indices;               // Liste des indices pour relier les faces old et new
  CATBoolean     _UnplugChecksForSheetMetal;           // IZE wk. 01 2010 IR 021460 Some checks are too restrictive for SheetMetal configurations

  ListPOfCATFace _FacesPropagToRemove;             // Gestion memoire
  ListPOfCATEdge _LEdgToSimplif_Cln;               // Gestion memoire
  ListPOfCATEdge _LEdgNew_Cln;                     // Gestion memoire
  ListPOfCATFace _FacesToRemove;                   // Gestion memoire
  ListPOfCATFace _FacesComplToRemove;              // Gestion memoire
  ListPOfCATFace _FacesSimplifiables;              // Gestion memoire
  ListPOfCATFace _FacesSimplifiablesAvecCoupantes; // Gestion memoire
  //ListPOfCATFace FacesPropagToRemove;
  ListPOfCATFace _InitFacesRemoveThenAdd;          // Gestion memoire
  CATListOfInt   _SideInitFacesRemoveThenAdd;      // Gestion memoire
  ListPOfCATFace _SmallFacesToKeep;                // Gestion memoire
  CATListOfInt   _SideSmallFacesToKeep;            // Gestion memoire

  CATTopCellTrackerByCGMAttrId* _ImpTracker;       // Imprint
  ListPOfCATBody                _ImpLInputBody;    // Imprint
  ListPOfCATBody                _ImpLOutputBody;   // Imprint
  CATLISTP(CATCGMJournal)       _ImpLCGMJournal;   // Imprint
  CATBody*                      _ImpBodyInit;      // Imprint
  CATFace*                      _SpeFac;
  int                           _NumLoo;
  
  CATSewingOpt*                 _SewOpt;           // Options particulieres
};


#endif


