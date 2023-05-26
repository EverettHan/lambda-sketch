/* -*-C++-*- */
#ifndef CATTopRibMacroTool_H
#define CATTopRibMacroTool_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRib
// Classe definissant un Macro-outil pour le ruban topologique
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June. 97    Creation                         J-M.Guillard
//===================================================================
//===================================================================
#include "ExportedByRIBLight.h"

#include "CATTopRibObject.h"
#include "CATTopRibDef.h"
#include "CATMathDef.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATTopRibNuplets.h"
#include "ListPOfCATTool.h"
#include "CATListOfInt.h"
#include "ListPOfCATTopRibs.h"
#include "CATTopOpPrevisualization.h"  // pour enum previsu
#include "ListPOfCATTopRibSupports.h"
#include "ListPOfCATBody.h"
#include "TopologicalOperatorsErrors.h"
#include "TopologicalOperatorsInternalError.h"

class CATBody;
class CATShell;
class CATFace;
class CATLoop;
class CATEdge;
class CATRibTopOp;
class CATTopRib;
class CATTopRibSupport;
class CATTopRibNuplet;
class CATTopRibTool;
class CATSupContact;
class CATParting;
class CATSoftwareConfiguration;
class CATLoopExtension;
class CATVirtualTopologicalModeling;
class CATSurface;
class CATSurLimits;
class CATIntRibNuplet;
class CATRibInit;
class CATTopData;
class CATTopologicalOperator;
class CATCrvLimits;
class CATEdgeCurve;
class CATCGMFormol;
class CATTopPropagationEdge;
class CATParallelMacroTool;
class CATNtrlDrftRibMacroTool; //DSH1 Nov 2015 OutRib Tangent Propagation Control 

#include "CATSafe.h"
CATSafeDefine(CATTopRibMacroTool);

class ExportedByRIBLight CATTopRibMacroTool  : public CATTopRibObject
{
 public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATTopRibMacroTool(CATSoftwareConfiguration* iConfig); 

  //------------------------------------------------------------------------------
  // Destructor (doit detruire les outils de _Tools)
  //------------------------------------------------------------------------------
  virtual ~CATTopRibMacroTool();

  //------------------------------------------------------------------------------
  // Initialisation (la liste des manifolds est construite a partir des cellules 
  // et des bodies)
  //------------------------------------------------------------------------------
  void Set(CATBody                 * iCreationBody,
           int                       iNbSupports,
           ListPOfCATBody          * iSupportBodies,
           ListPOfCATDomain        * iSupportDomains,
           CATListOfInt            * iOrientation=NULL,
           CATListOfInt            * iNeedToDisconnectDomains=NULL, // Default is Yes, Need To Disconnect
           CATRibTopOp             * iRibTopOp=NULL);               // Pour la mise a jour des shells


  void SetOrientationTuning( int iOriTuning);

  //------------------------------------------------------------------------------
  // Donne le nombre d'elements d'appui 
  //------------------------------------------------------------------------------ 
  virtual int GetNbRollingSupp()=0;

  //------------------------------------------------------------------------------
  // Donne le nombre d'elements guide 
  //------------------------------------------------------------------------------ 
  virtual int GetNbGuideSupp()=0;

  //------------------------------------------------------------------------------
  // Donne la position du ieme element rolling 
  //------------------------------------------------------------------------------ 
  virtual int GetPosRolling(int iRolling)=0;

  //------------------------------------------------------------------------------
  // Donne la position du ieme element guide
  //------------------------------------------------------------------------------ 
  virtual int GetPosGuide(int iGuide)=0;

  //------------------------------------------------------------------------------
  // Determination d'un outil a partir d'une liste de supports - La destruction de
  // cet outil est effectue dans le destructeur du MacroTool 
  //------------------------------------------------------------------------------
  virtual CATTopRibTool * const GetTool // Renvoie un pointeur sur l'outil 
    (
     CATTopRibSupport ** iTabSupports, // Liste des supports 
     int                 iNbSupport    // Nombre de supports
     )=0; 
  
  //------------------------------------------------------------------------------
  // Donne le type d'un appui (rolling, guide ...) 
  //------------------------------------------------------------------------------
  virtual CATTopRibSupp GetSupportType(int iNumSupp);

  //------------------------------------------------------------------------------
  // Dit si un support peut etre propage: oui par defaut 
  //------------------------------------------------------------------------------
  CATBoolean HasToPropag(int iNumSupp);

  //------------------------------------------------------------------------------
  // Specifier un support a ne pas propager  
  //------------------------------------------------------------------------------
  void UnsetPropag(int iNumSupp);

  //------------------------------------------------------------------------------
  // Lit/Ecrit le mode de propagation sur un support donne 
  // CATSmooth = seulement sur les aretes mortes (valeur par defaut)
  // autre     = propagation toujours ok
  //------------------------------------------------------------------------------
  int  GetSuppPropagType(int iNumSupp);
  void SetSuppPropagType(int iNumSupp, int iPropagType);

  //------------------------------------------------------------------------------
  // Set/Get du mode bifurcation pour autoriser ou brider les bifurcations
  // Aujourd'hui, on juste 2 valeurs: 
  // 0 - bride toutes les bifurcations
  // 1 - autorise toutes les bifurcations
  // Plus tard, on pourra affiner en fonction du type de bifurcation
  //------------------------------------------------------------------------------
  void SetJunctionMode(int iJunctionMode);
  int GetJunctionMode();
  
  //------------------------------------------------------------------------------
  // Donne le cote matiere a garder d'un support 
  //------------------------------------------------------------------------------
  virtual CATSide GetSideToKeep(int iNumSupp);

  //------------------------------------------------------------------------------
  // Indique si on s'arrete des que l'on ne trouve pas de candidats dans le sens 
  // direct
  //------------------------------------------------------------------------------
  virtual CATBoolean IsStoppedByFreeEdge(int iNumSupp);

  //------------------------------------------------------------------------------
  // Check whether candidate faces around a vertex should be skipped (see use
  // of this method in CATTopRib::GetSupportCandidates
  //------------------------------------------------------------------------------
  virtual CATBoolean SkipCandidateFacesAroundVertex(CATTopRibSupport *iLastSupport);

  //------------------------------------------------------------------------------
  // Donne le type d'une cellule  (rolling, ...)
  //------------------------------------------------------------------------------
  virtual CATTopRibSupp GetCellType(CATCell * iCell);

  //------------------------------------------------------------------------------
  // Renvoie le nombre de supports
  //------------------------------------------------------------------------------
  INLINE int GetNbSupports();

  //------------------------------------------------------------------------------
  // Renvoie la liste des orientations des cellules supports
  //------------------------------------------------------------------------------
  INLINE const CATListOfInt& GetSupportOrientation();

  //------------------------------------------------------------------------------
  // Renvoie l'orientation globale d'un support
  //------------------------------------------------------------------------------
  int GetSupportOrientation(int iNumSupp, int iExternalDomain);

  //------------------------------------------------------------------------------
  // Peut-on inverser les orientations ?
  // rend 1 si oui, 0 sinon
  //------------------------------------------------------------------------------
  int OrientationCanBeTuned();

  //------------------------------------------------------------------------------
  // Renvoie la liste des manifolds supports 
  //------------------------------------------------------------------------------
  const ListPOfCATDomain& GetSupportDomain();

    //------------------------------------------------------------------------------
  // Renvoie la liste des bodies supports 
  //------------------------------------------------------------------------------
  const ListPOfCATBody& GetSupportBody();

  //------------------------------------------------------------------------------
  // Renvoie le domaine d'un support 
  //------------------------------------------------------------------------------
  INLINE CATDomain* GetSupportDomain(int iSupport, CATBoolean* ioNeedToDisconnectDomain=NULL);

  //------------------------------------------------------------------------------
  // Renvoie le domaine d'un support en descendant sur le Support du Support 
  //------------------------------------------------------------------------------
  virtual CATDomain* GetRecursiveSupportDomain(int iSupport, CATBoolean* ioNeedToDisconnectDomain=NULL, int iDepth=0);

  //------------------------------------------------------------------------------
  // Renvoie le body d'un support 
  //------------------------------------------------------------------------------
  INLINE CATBody* GetSupportBody(int iSupport);

  //------------------------------------------------------------------------------
  // Renvoie le body d'un support en descendant sur le Support du Support 
  //------------------------------------------------------------------------------
  virtual CATBody* GetRecursiveSupportBody(int iSupport, int iDepth=0);

  //------------------------------------------------------------------------------
  // Active la recherche recursive de support (ex: Relimitation sur Fillet HoldCurve)
  //------------------------------------------------------------------------------
  virtual void SetRecursiveSupportSearch(const CATBoolean iActivate = TRUE);
  INLINE CATBoolean GetRecursiveSupportSearch() const;

  //------------------------------------------------------------------------------
  // Specifie/Renvoie l'autre domaine autorise pour un support 
  //------------------------------------------------------------------------------
  void       SetAdditionalDomain(int iSupport, CATDomain * iAdditionalShell);
  CATDomain* GetAdditionalDomain(int iSupport);

  //------------------------------------------------------------------------------
  // Renvoie la configuration a utiliser. Ne peut pas etre NULL.
  //------------------------------------------------------------------------------
  INLINE CATSoftwareConfiguration* GetSoftwareConfiguration() const;

  //------------------------------------------------------------------------------
  // Renvoie le body de creation 
  //------------------------------------------------------------------------------
  CATBody* GetCreationBody();

  //------------------------------------------------------------------------------
  // Methode de creation par default. Sert par exemple quand on recupere une 
  // solution
  //------------------------------------------------------------------------------
  CATTopRibSol GetDefaultTypeSol();
  void         SetDefaultTypeSol(CATTopRibSol iDefaultTypeSol);

  //------------------------------------------------------------------------------
  // Renvoie le nombre de Nuplets servant pour le critere d'arret   
  //------------------------------------------------------------------------------
  virtual int GetNbSpecialNuplet();

  //------------------------------------------------------------------------------
  // Enleve des Nuplets servant pour le critere d'arret   
  //------------------------------------------------------------------------------
  virtual void RemoveSpecialNuplet(int iFirstToRemove, int iLastToRemove);

  //------------------------------------------------------------------------------
  // Lecture/Ecriture d'un Nuplet d'arret donne et la maniere dont interviennent 
  // ses vertex et la cellule trace dans le tableau TypNuplet contenant 3 
  // CATTopRibType, avec :
  //
  //   TypNuplet[0] : Maniere dont intervient le StartVertex
  //   TypNuplet[1] : Maniere dont intervient la cellule trace
  //   TypNuplet[2] : Maniere dont intervient le EndVertex
  //
  // Les champs de TypNuplet doivent prendre l'une des valeurs suivantes:
  //
  //  UnknownRibbonType: Pour specifier que l'element concerne ne joue aucun role
  //                     particulier
  // 
  //  Invalid          : Pour specifier qu'atteindre l'element concerne rend le 
  //                     ruabn invalide
  //
  //  Ended            : Pour specifier que l'element concerne "stoppe" le ruban 
  //
  // Un Nuplet d'arret devient la propriete du Macro Tool. Cela signifie qu'il est
  // detruit par le macro tool.
  //------------------------------------------------------------------------------
  virtual CATTopRibNuplet * GetSpecialNuplet(int iNum,CATTopRibType oTypNuplet[3], int *oNumScar = 0);

  virtual void SetSpecialNuplet(CATTopRibNuplet * iSpecialNuplet,
				CATTopRibType     iTypNuplet[3], int iNumScar);

  //------------------------------------------------------------------------------
  // Set du CATRibTopOp
  //------------------------------------------------------------------------------
  void SetRibTopOp(const CATRibTopOp *iRibTopOp);
  void SetRibTopOpFromOtherMacroTool(const CATTopRibMacroTool *iTopRibMacroTool);
  CATRibTopOp *ReadRibTopOp() { return _RibTopOp; }

  CATBoolean RibTopOpIsDraft();
  CATBoolean RibTopOpIsBlend();
  
  //------------------------------------------------------------------------------
  // Les methodes qui suivent appelent les methodes du meme nom sur _RibTopOp
  //------------------------------------------------------------------------------
  CATLONG32 LocateLoopExtension(const CATLoopExtension* iLoopExtension) ;
  CATLONG32 LocateLoopExtension(CATFace* iInitialFace, CATLoop* iInitialLoop) ;
  CATLONG32 CreateLoopExtension(CATFace *iInitialFace, CATLoop *iInitialLoop, CATSurLimits& iExtrapolResLimits) ;
  CATLONG32 LocateLoopExtension(CATFace            *iComplFace,
                           CATLoopExtension  *&oLoopExtension,
                           CATBoolean          iErrorIfNoRibTopOp=TRUE);
  CATLONG32 GetNumberOfLoopExtensions() ;
  CATLoopExtension* GetLoopExtension(const CATLONG32 iIndex) ;
  void CreateComplementaryShell() ;
  void UpdateComplementaryShell() ;
  void GetNonExtrVertices(ListPOfCATVertex *oNonExtrVertices);
  void ResetNonExtrVertices();
  void AddNonExtrVertices(ListPOfCATVertex *iNonExtrVertices);
  void AddNonSharedNonExtrVertices(ListPOfCATVertex *iNonExtrVertices);
  void AddStopExtrapolVertex(CATVertex* iVertex);
  CATBoolean IsStopExtrapolVertex(CATVertex *iVertex);
  ListPOfCATFace* GetFacesToAvoidForExtrRib();
  void RemoveFaceToAvoidForExtrRib(CATFace *iFace);
  void AddFacesToAvoidForExtrRib(ListPOfCATFace *iFacesToAvoidForExtrRib);
  void LockSupportsInFormol(CATGeometry* iGeometry);
  void DeleteFormol();
  void SetHoleCreationFace(CATFace* iHoleCreationFace);
  void SetSkinHasBeenClosed();
  CATBoolean SkinHasBeenClosed();
  void SetRelaunchValue(int iVal);
  void SetClosureOnFrontierIsDetected(CATEdge* iEdge);  
  void SetRecursiveCompletionAllowed(int iRecursiveCompletion);
  void SetLimitsMode(int iMode);
  //CATBoolean ClosureOnFrontierHasBeenDetected();
  void     SetCommonEdgeForExtrRib(CATEdge* iEdge, CATTopRib* iRib);
  CATEdge* GetCommonEdgeForExtrRib(CATTopRib* iRib);
  CATBoolean ComplementairesFix_2();                    // Rend TRUE si code "Complementaires Drop2" actif
  int GetComplementaryShellMode();  
  CATBoolean GetUnconditionalSplitEdge();

  //------------------------------------------------------------------------------
  // Enregistrement des Nuplets pour destruction backup
  //------------------------------------------------------------------------------
  int LinkNuplet( CATTopRibNuplet* iNupletToLink ) ; // returns the index
  CATTopRibNuplet* UnLinkNuplet( const int iNupletToUnLinkIndex ) ; // returns the UnLinked Nuplet

  //------------------------------------------------------------------------------
  // Ajoute une coupante 
  //------------------------------------------------------------------------------
  void AddSplittingEdge(CATFace   * iSupport, 
	                      CATEdge   * iSplittingEdge,
                        CATSide     iSide,
                        CATBoolean  iFullSideAccepted = FALSE);

  //------------------------------------------------------------------------------
  // Returns candidate faces through spliting edges
  //------------------------------------------------------------------------------
  void GetAdjacentCellsThroughSplittingEdges(CATFace* iFace, CATEdge* iSplittingEdge, CATLISTP(CATFace) &oAdjFaces);

  //------------------------------------------------------------------------------
  // Donne le nombre de coupantes sur une face
  //------------------------------------------------------------------------------
  int GetNbCuttingEdges(CATFace * iFace);

  //------------------------------------------------------------------------------
  // Donne une coupante specificiee par un index (entre 1 et nombre de coupantes)
  // sur une face
  //------------------------------------------------------------------------------
  CATEdge * GetCuttingEdge(CATFace    * iFace,
                           int          iNumCutting,                             
                           CATSide    * oSideToKeep=NULL,
                           CATBoolean * oFullSideAccepted=NULL);  

  //------------------------------------------------------------------------------
  // Indique si une edge est coupante sur une face 
  //------------------------------------------------------------------------------
  CATBoolean IsACuttingEdge(CATFace * iFace,
            		            CATEdge * iEdge,
                            CATSide & oSide);

  //------------------------------------------------------------------------------
  // Indique si un vertex repose sur le parting
  //------------------------------------------------------------------------------
  CATBoolean IsTouchingParting(CATVertex  *iVertex,
                               CATFace    *iFace);

  //------------------------------------------------------------------------------
  // blanchit le tableau des coupantes  
  //------------------------------------------------------------------------------
  void CleanSplittingEdge();

  //------------------------------------------------------------------------------
  // Nettoie le tableau des coupantes  (methode a mettre en static)
  //------------------------------------------------------------------------------
  void ClearSplittingEdge(ListPOfCATFace * iFaces,
	                        CATListPV      * iEdges,
                          CATListPV      * iSides,
                          CATListPV      * iFullSideAccepted);

  //------------------------------------------------------------------------------
  // Donne la main sur les coupantes
  //------------------------------------------------------------------------------
  void ReleaseSplittingEdge(ListPOfCATFace *& oFaces,
		                        CATListPV      *& oEdges,
                            CATListPV      *& oSides,
                            CATListPV      *& oFullSideAccepted);

  //------------------------------------------------------------------------------
  // Specifie un ensemble de coupantes. Se fait em mode recopie ou replace suivant  
  // l'option choisie.
  //------------------------------------------------------------------------------
  void SetSplittingEdge(CATBoolean        iCopy,
	                      ListPOfCATFace *& ioFaces,
                        CATListPV      *& ioEdges,
                        CATListPV      *& ioSides,
                        CATListPV      *& ioFullSideAccepted );

  //------------------------------------------------------------------------------
  // Ajout d'un nuplet pour l'exit. Renvoie la position du nuplet dans la liste 
  //------------------------------------------------------------------------------
  int  SetExitNuplet(CATTopRibNuplet * iExitNuplet,
                     int               iNumRib,
                     CATTopRib       * iOriginalRib);
  void SwapExitNuplet(int               iPosExit,
                      CATTopRibNuplet * iNewExitNuplet);
  void SwapExitNuplet(CATTopRibNuplet * iNewExitNuplet,
                      int               iNumRib);

  //------------------------------------------------------------------------------
  // Acces aux nuplets exit.   
  //------------------------------------------------------------------------------
  CATTopRibNuplet * GetExitNuplet(int          iNumExitNuplet,
                                  CATTopRib ** oOriginalRib=NULL);
  int GetNbExitNuplet();

  //------------------------------------------------------------------------------
  // Acces aux indices des rubans ayant fourni les nuplets exit.
  //------------------------------------------------------------------------------
  int GetNumRibOfExit(int iNumExitNuplet);
  int GetNumRibOfExit(CATTopRib * iRibbon);

  //------------------------------------------------------------------------------
  // Vide la liste des nuplets exit.   
  //------------------------------------------------------------------------------
  virtual void ClearExitNuplet();

  //------------------------------------------------------------------------------
  // Suppression d'un nuplet exit
  //------------------------------------------------------------------------------
  void RemoveExitNuplet(CATTopRibNuplet* iNuplet);

  //------------------------------------------------------------------------------
  // Vide la liste des nuplets exit provenant d'un ruban donne
  //------------------------------------------------------------------------------
  void ClearExitNupletsFromRibbon (int iNumRib);

  //------------------------------------------------------------------------------
  // Specifie un tableau de contact exit (Le tableau devient propriete de this).
  //------------------------------------------------------------------------------
  void SetExitContact(CATSupContact iExitContact[]);

  //------------------------------------------------------------------------------
  // Acces aux contacts exit.   
  //------------------------------------------------------------------------------
  CATSupContact * GetExitContact(int iNumExitContact);
  int GetNbExitContact();

  //------------------------------------------------------------------------------
  // ClearExitContact(0) : Supprime la specification de tous les Exits
  // ClearExitContact(i) : Supprime la specification de l'Exit numero i
  //                       (attention a la renumerotation des exits qui suivent)
  //------------------------------------------------------------------------------
  void ClearExitContact(const int iNumExitContact);

  //------------------------------------------------------------------------------
  // Meme methode que ClearExitContact masi sans deallocation memoire pour
  // les SupContacts
  //------------------------------------------------------------------------------
  void ReleaseExitContact(const int iNumExitContact);

  //------------------------------------------------------------------------------
  // Set a CATParting object
  //
  // Please note: iPartingSolType indicates whether the faces that are contained
  //              in one of the two Parting shells can be used as candidates in
  //              the Ribbon propagation
  //              SolTypeIn            - Only Parting faces that are INside
  //                                     the initial Body can be used
  //              SolTypeOut           - Only Parting faces that are OUTside
  //                                     the initial body can be used
  //              SolTypeIn+SolTypeOut - All Parting faces can be propagation
  //                                     candidates
  //              0                    - Parting faces cannot be propagation
  //                                     candidates (they will however split
  //                                     the Ribbon's N-uplets)
  //
  //              iPriorityType indicates which type of faces has the highest
  //              priority
  //------------------------------------------------------------------------------
  virtual void SetPartingElement(CATParting   *iParting,
                                 CATTopRibSol  iPartingSolType,
                                 CATTopRibSol  iPriorityType);

  //------------------------------------------------------------------------------
  // Lecture du pointeur parting
  //------------------------------------------------------------------------------ 
  INLINE CATParting * GetPartingElement ();

  //------------------------------------------------------------------------------
  // Donne le modele topologique virtuel 
  //------------------------------------------------------------------------------ 
  virtual CATVirtualTopologicalModeling * GetVirtualTopologicalModeling();
  virtual void SetVirtualTopologicalModeling(CATVirtualTopologicalModeling *iVTM);
  
  //------------------------------------------------------------------------------
  // Test si la cellule que l'on pressent comme candidate est dans le bon shell 
  //------------------------------------------------------------------------------
  virtual CATBoolean IsInGoodDomain(int                iNumSupp,
                                    CATCell          * iNextCell,
                                    CATCell          * iOldCell,
                                    CATCell          * iLinkCell,
                                    CATBoolean       & oOldDomain,
                                    CATLoopExtension * iLoopExtension      = NULL,
                                    CATBoolean       * oReUseLoopExtension = NULL);

  //------------------------------------------------------------------------------
  // Determine le side d'une cellule par rapport a sa cellule bordee
  //------------------------------------------------------------------------------
  CATTopRibSign CalculateGoodOrientation(int               iSuppIndex,
				                                 CATTopRibNuplet * iNuplet,
                                         CATCell         * iSupportCell,
                                         CATCell         * iCandidateCell,
                                         CATCell         * iBorderCell,
                                         CATBoolean        iSameDomain);

  //------------------------------------------------------------------------------
  //
  //------------------------------------------------------------------------------
  void GetSupportCandidatesOfInitialShell(CATCell        * iCell,
                                          CATFace        * iSuppFace,
                                          ListPOfCATEdge & oAdjEdges,
                                          ListPOfCATFace & oAdjFaces);
  //------------------------------------------------------------------------------
  // Rend la face parting OUT/IN bordee par iBorderEdge et
  // adjacente a iFace (qui est IN/OUT)
  //
  // NB: Si iCheckInputFaceLocation vaut FALSE, la method suppose que iFace est
  //     IN ou CONFUSED, ce qui a pour consequence que le resultat vaudra NULL
  //     si en fait elle est OUT
  //------------------------------------------------------------------------------
  CATFace* GetOutFace(CATFace     *iFace,
                      CATEdge     *iBorderEdge,
                      CATShell   **oOwningShell            = NULL,
                      CATBoolean   iCheckInputFaceLocation = FALSE);

  //------------------------------------------------------------------------------
  // Detecte si une edge est sur le bord d'une Parting (iFace) ET posee
  // sur le body initial
  //------------------------------------------------------------------------------
  CATBoolean IsEdgeCuttingOnInitialBody(CATEdge *iEdge,
                                        CATFace *iFace);

  //------------------------------------------------------------------------------
  // Service qui rend la liste des positions des differents nuplets de iRib
  // (de iFirstIndex a iLastIndex) par rapport au parting
  // Les elements de cette liste peuvent prendre les 3 valeurs suivantes:
  // - SolTypeIn        : le nuplet est situe au-dessus  du parting
  // - SolTypeOut       : le nuplet est situe au-dessous du parting
  // - SolTypeConfused  : le nuplet est en confusion avec le parting
  // NB : si'il n'y a pas de parting, tous les elts de la liste valent SolTypeIn
  //      (i.e. tous les nuplets sont consideres "au-dessus du parting").
  //------------------------------------------------------------------------------
  virtual void GetPartingTypesOfNuplets(CATLONG32       iFirstIndex, 
                                        CATLONG32       iLastIndex,
                                        int        iNumSupp,
                                        CATTopRib *iRib,
                                        CATListOfInt & oPartingTypesList);
  //------------------------------------------------------------------------------
  // Marquage des nuplets du ruban iRib avec leur position par rapport au parting
  //------------------------------------------------------------------------------
  void UpdatePartingTypesOfNuplets(CATTopRib *iRib, CATBoolean *ioRattrap = NULL, CATTopPropagationEdge *iSA=NULL, CATBoolean iSaveVerticesForSimplification=FALSE,
	                                void * iSpec = NULL); 
  //------------------------------------------------------------------------------
  // Service qui type les aretes de la face iFace lorsqu'elle est intersectee
  // par le parting (si la face est non intersectee, on rend la PseudoLoop
  // constituee de la concatenation de toutes les aretes de la face, mais
  // la liste parallele oPseudoLoopTypes est mise a SolTypeUnknown).
  // Les types possibles sont les suivants:
  // - SolTypeIn        : l'edge est situee au-dessus  du parting
  // - SolTypeOut       : l'edge est situee au-dessous du parting
  // - SolTypeConfused  : l'edge est en confusion avec le parting
  // Si iFace n'est pas intersectee par le parting, mais qu'une (ou plusieurs)
  // des edges de iFace sont en confusion avec des edges du parting,
  // on met oFaceIsJustConfused a VRAI, oFaceIsNotIntersected a VRAI et
  // les autres listes sont remplies de la meme facon que dans le cas ou 
  // iFace n'est pas intersectee par le parting.
  //------------------------------------------------------------------------------
  void GetEdgesPositionVsParting(CATFace        *iFace, 
                                 CATBoolean     &oFaceIsNotIntersected,
                                 CATBoolean     &oFaceIsJustConfused,
                                 ListPOfCATEdge &oPseudoLoop,
                                 CATListOfInt   &oPseudoLoopTypes,
                                 CATListOfInt   *oNumLoop = NULL,
                                 int            *oNbLoops = NULL);

  //------------------------------------------------------------------------------
  // Set switch Ribbon
  //------------------------------------------------------------------------------
  void SetSwitchRibbon(CATTopRib    * iSwitchRib,
                       CATTopRibSign  iSwitchDirection);

  //------------------------------------------------------------------------------
  // Get number of switch Ribbons
  //------------------------------------------------------------------------------
  int GetNbSwitchRibbons();

  //------------------------------------------------------------------------------
  // Get switch Ribbon
  //------------------------------------------------------------------------------
  CATTopRib * GetSwitchRibbon(int             iIndex,
                              CATTopRibSign * oSwitchDirection = NULL);

  //------------------------------------------------------------------------------
  // Returns 1 if Ribbon is a switch Ribbon
  //------------------------------------------------------------------------------
  CATBoolean IsASwitchRibbon(CATTopRib * iRib);

  //------------------------------------------------------------------------------
  // Set/Get pour la mise en place de la sauvegarde des MaxLimits des surfaces
  // extrapolees
  //------------------------------------------------------------------------------
  void SetSaveExtrSurf(int iSaveExtrSurf);
  int  GetSaveExtrSurf();
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
  void NeedExtrSurf(CATIntRibNuplet *iNuplet);  

  //------------------------------------------------------------------------------
  // Rend 1 si iSurface est candidate a la "desextrapolation", 0 sinon.
  //------------------------------------------------------------------------------
  int IsCandToDesextrapol(CATSurface *iSurface);

  //------------------------------------------------------------------------------  
  // NotifyCompleteStarted : Maj de la profondeur d'appel de CATRlmRib::Complete()
  // NotifyCompleteFinished: Maj de la profondeur d'appel de CATRlmRib::Complete()
  // GetCompletionDepth    : Recuperation de cette profondeur d'appel
  // ThrowIfMaxCompletionDepthReached : Comme son nom l'indique
  // NB: methodes placees ds le CATTopRibMacroTool et pas dans le CATRlmMacroTool
  //     en prevision d'evolution (ex : on pourra vouloir tracker 
  //     CATTopRib::GetNewNuplets()...)
  //------------------------------------------------------------------------------
  void NotifyCompleteStarted();
  void NotifyCompleteFinished();
  int GetCompletionDepth();
  void ThrowIfMaxCompletionDepthReached();

  //------------------------------------------------------------------------------
  // Indique si la completion recursive est autorisee ou non
  //------------------------------------------------------------------------------
  CATBoolean GetRecursiveCompletionAllowed();

  //------------------------------------------------------------------------------
  // Indique si la creation de trou est autorisee ou non
  //------------------------------------------------------------------------------
  CATBoolean GetHoleCreationAllowed();

  //------------------------------------------------------------------------------
  // Indique si la creation de 'n' face(s) supplementaire(s) est autorisee ou non
  //------------------------------------------------------------------------------
  int GetNbSupplementaryFacesAllowed();

  //------------------------------------------------------------------------------
  // Debug methods
  //------------------------------------------------------------------------------
  virtual void Dump( CATCGMOutput& ioOS );
  virtual void Check();

  //------------------------------------------------------------------------------
  // Retrieve the side of the cell in the appropriate domain :
  // if none of the SupportDomains contains the cell, 
  // search on PartingDomains if any
  // otherwise, returns CATSideUnknown
  //------------------------------------------------------------------------------
  virtual CATSide GetSideInOwningDomain(int       iSuppIndex,
                                        CATCell * iCell);

  //------------------------------------------------------------------------------
  // Returns 1 if current mode is Previsualization
  // Returns 0 otherwise
  //------------------------------------------------------------------------------
  CATTopOpPrevisualization GetPrevisu();

  //------------------------------------------------------------------------------
  // Donne la positon du support de reference - par defaut c'est le premier
  // (Voir les classes derivees pour les autres cas)
  //------------------------------------------------------------------------------ 
  virtual int GetRefSupport();

  //------------------------------------------------------------------------------
  // This method only makes sense for non-relimitation MacroTools!
  // It permits to define whether a given support is to be used as a relimitation
  // support (otherwise, it can be considered as a "No-Trim" support)
  // Per default, all supports are used as relimitation supports (e.g. the
  // tritangent fillet)
  //------------------------------------------------------------------------------
  void SetSupportRelimMode (int                       iSuppIndex,
                            CATTopRibSupportRelimMode iSupportRelimMode);

  //------------------------------------------------------------------------------
  // This method only makes sense for non-relimitation MacroTools!
  // It determines whether a given support is to be used as a relimitation
  // support (otherwise, it can be considered as a "No-Trim" support)
  // Per default, all supports are used as relimitation supports (e.g. the
  // tritangent fillet)
  //------------------------------------------------------------------------------
  CATTopRibSupportRelimMode GetSupportRelimMode (int iSuppIndex);

  //------------------------------------------------------------------------------
  // Return true for track intersection with faces on the same surface as the support
  // orginal face activation
  //
  // default return value : FALSE
  //------------------------------------------------------------------------------

  virtual CATBoolean GetLookForEdgesOnFacesOnSupportSurfaceActivated(CATFace* iFace = NULL);
  virtual CATBoolean ShouldBeLongPropagated();

  //------------------------------------------------------------------------------
  // Indique si la cellule fournie en entree est un candidat admissible comme
  // LinkCell dans des cas de bifurcations.
  //------------------------------------------------------------------------------
  CATBoolean IsJunctionLinkCell(CATCell *iCell);

  //------------------------------------------------------------------------------
  // Ajout de la cellule fournie a la liste _JunctionLinkCell
  //------------------------------------------------------------------------------
  void SetJunctionLinkCell(CATCell *iCell);

  //------------------------------------------------------------------------------
  // Returns true when we are performing ribbon init
  //------------------------------------------------------------------------------
  CATBoolean GetLookingForRibbonInit();

  
  //------------------------------------------------------------------------------
  // sets if we are performing ribbon init or not
  //------------------------------------------------------------------------------
  void AddRefLookingForRibbonInit();
  void ReleaseLookingForRibbonInit();

  //------------------------------------------------------------------------------
  // Indicates if the support-orientation can be inverted for initialization
  // (TRUE  if inverting the support-orientation can modify the geometric solution,
  //  FALSE if inverting does not modify the geometric solution, or is forbidden)
  //------------------------------------------------------------------------------
  virtual CATBoolean IndividualSwitchOfSupportOriAllowed(int iNumSupport);

  //------------------------------------------------------------------------------
  // Compute the bumpers of a support cell (edge only, at the moment)
  // iProf = 0 : Standard search
  //         1 : Extended search : if standard search fails, search in "external" bodies
  // Return the number of bumpers computed
  // ATTENTION : size of oBumpers and oOriBumpers should be 2
  //------------------------------------------------------------------------------
  virtual int ComputeBumpers(int iNumSupport, CATCell * iCellSupp, int iProf,
                             CATCell * oBumpers[2], int oOriBumpers[2]=NULL,
                             CATBody ** oBumperBody=NULL, CATDomain ** oBumperDomain=NULL);

  //------------------------------------------------------------------------------
  // Indique si on peut considerer iCandEdge comme candidat rolling a partir
  // de CurEdge a travers SharedVertex
  //------------------------------------------------------------------------------
  virtual CATBoolean IsRollingAuthorised(CATVertex *iSharedVertex,
                                         CATEdge   *iCurEdge,
                                         CATCell   *iCurSupport,
                                         CATEdge   *iCandEdge,
                                         CATCell   *iCandSupport);

  //------------------------------------------------------------------------------
  // Specifie la bad face (utilise pour un ruban de relimitation)
  //------------------------------------------------------------------------------
  virtual void SetBadFacesAtEnd();

  //------------------------------------------------------------------------------
  // Renvoie la bad face (utilise pour un ruban de relimitation)
  //------------------------------------------------------------------------------
  virtual CATBoolean GetBadFacesAtEnd();

  //------------------------------------------------------------------------------
  // Specifie que l'on ne fera aucune completion (utilise dans CATRelimTopOp)
  //------------------------------------------------------------------------------
  void SetNoCompletionAllowed();

  //------------------------------------------------------------------------------
  // Renvoie FALSE si la completion est debranchee (utilise dans CATRelimTopOp)
  //------------------------------------------------------------------------------
  INLINE CATBoolean IsCompletionAllowed();


  // Start : AJD : 2002:12:23
  //------------------------------------------------------------------------------
  // check if confused inits should be allowed in CATTopRibDetermineInitNupletList
  //------------------------------------------------------------------------------
  virtual CATBoolean UseConfusedInits();
  // End : AJD : 2002:12:23

  
  //------------------------------------------------------------------------------
  // Get/Set du CurrentRibDepthLevel
  //------------------------------------------------------------------------------
  int GetCurrentRibDepthLevel();  
  void SetCurrentRibDepthLevel(int iCurrentRibDepthLevel);

  //------------------------------------------------------------------------------
  // Set de la derniere edge confused generee par SplitEdge - sur le RlmTool only
  //------------------------------------------------------------------------------  
  virtual void SetLastConfusedEdge(CATEdge* iEdge, int iSupp);

  //------------------------------------------------------------------------------
  // Rempli l operation blend qui contient les spec necessaires (Super Arete, etc)
  //------------------------------------------------------------------------------ 
  void SetRibInit(CATRibInit  * iOp);
  //------------------------------------------------------------------------------
  // Donne l operation qui contient les spec user 
  //------------------------------------------------------------------------------ 
  INLINE  CATRibInit  *ReadRibInit() const;
  //------------------------------------------------------------------------------
  // Recupere un support candidat prioritaire a partir des nuplets suivants d'un
  // ruban fourni, dans une direction donnee, pour un nuplet de depart donne, et
  // pour un index de support donne
  //------------------------------------------------------------------------------
  public:
  CATTopRibSupport *GetPrioritySupportFromNextNuplet(CATTopRibSign    iDirection,
                                                     CATTopRib       *iRibbon,
                                                     CATTopRibNuplet *iNuplet,
                                                     int              iSupportIndex);

  //------------------------------------------------------------------------------
  // Get the shell that must be crossed by the support identified with
  // iSupportIndex
  //
  // Please note: this method returns NULL and can be implemented in the child
  //              classes
  //------------------------------------------------------------------------------
  public:
  virtual CATShell *GetShellToCross(int iSupportIndex);

  virtual CATBoolean IsVariable() const; // SOU : 2003:5:15

  //------------------------------------------------------------------------------
  // Identify the domain that was duplicated from another given domain
  //
  // Please note: Use this method with extreme caution.
  //              It only returns the address of the domain that was obtained at
  //              the time of the smart duplication in the object's constructor.
  //              There is NO guarantee that the address hasn't changed in the
  //              meantime (i.e. this should only be called right after creating
  //              a MacroTool and before launching any other treatment.
  //------------------------------------------------------------------------------
  public:
  CATDomain* GetDuplicatedDomain(CATDomain* iInitialDomain);
  CATDomain* GetInitialDomain(CATDomain* iDuplicatedDomain);

  //------------------------------------------------------------------------------
  // Check if one of the supports is a parting element
  //------------------------------------------------------------------------------
  public:
  virtual int GetPartingSupportIndex();

  //------------------------------------------------------------------------------
  // Store an exported face and its location with respect to a potential parting
  // element
  //------------------------------------------------------------------------------
  public:
  /*
  void StoreCreatedFace(CATFace        *iFace,
                        CATOrientation  iFaceOrientation,
                        CATOrientation  iOrientationVsParting = CATOrientationPositive);
  */
  //------------------------------------------------------------------------------
  // Get the domains to delete from the CATtibTopOp operator
  //------------------------------------------------------------------------------
  public:
    CATLONG32 GetNumberOfDomsToDelete();
    CATDomain * GetDomToDelete(CATLONG32 iDomToDeleteNumber);

  //------------------------------------------------------------------------------
  // Update creation body
  //------------------------------------------------------------------------------
  public:
  virtual void UpdateWithNewBody(CATBody *iOldBody, CATBody *iNewBody);


  //------------------------------------------------------------------------------
  // Donne les coupantes explicites sur une face (i.e. qui ne sont pas issues du Parting)
  //------------------------------------------------------------------------------
  private:
  CATBoolean GetExplicitCuttingEdges(CATFace        *   iFace,
                                     ListPOfCATEdge *& oCuttingEdges,
                                     CATListOfInt   ** oSides            = NULL,
                                     CATListOfInt   ** oFullSideAccepted = NULL);

  //------------------------------------------------------------------------------
  // Public methods
  //------------------------------------------------------------------------------
 public:
  //-----------------------------------------------------------------------------
  // Enleve la SuppCell du ioSupport : derivee dans le MacroTool du DraftBothSides
  //------------------------------------------------------------------------------
  virtual void ForgetSupCell(CATTopRibSupport * ioSupport) const;

  //-----------------------------------------------------------------------------
  // Lecture/ecriture du ratio indiquant a combien on peut extrapoler une face
  // par rapport a la boite volumique de la piece initiale
  //-----------------------------------------------------------------------------
  public:
  double GetFaceExtrapolRatioVsVolumeBox();
  void   SetFaceExtrapolRatioVsVolumeBox(double iFaceExtrapolRatioVsVolumeBox);

  //-----------------------------------------------------------------------------
  // Méthodes pour brider la création de loopextension
  // à plusieurs faces complémentaires
  //-----------------------------------------------------------------------------
  public:
    void SetCreateSingleComplLoopExtension(CATBoolean iCreateSingleComplLoopExtension);
    CATBoolean GetCreateSingleComplLoopExtension();

  //------------------------------------------------------------------------------
  // Compute the on which side of the parting element the provided skin face
  // is located
  //------------------------------------------------------------------------------
  public:
  virtual CATOrientation ComputeSkinFaceOrientation(CATFace *iFace);

  //------------------------------------------------------------------------------
  // Find out if the touch flags of the supports shoould be modified
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean QueryDoTouch();

  //------------------------------------------------------------------------------
  // Find out if the macro tool is already set
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean QueryIsSet();

  //------------------------------------------------------------------------------
  // Set the need for updating the touch flags on the shells
  //------------------------------------------------------------------------------
  public:
  void SetNeedForUpdateTouchOnShells(CATBoolean iUpdateTouchOnShellsIsNeeded);

  //------------------------------------------------------------------------------
  // Is it necessary to update the touchg flags on the shells?
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsUpdateTouchOnShellsNeeded();
  //------------------------------------------------------------------------------
  // Is it necessary to consider the internal exits inside the ribbon
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean ShouldConsiderInternalExits ();
  //------------------------------------------------------------------------------
  // If you need a temporary CATTopologicalOperator whitout having to deal with its destruction in case of throw
  //------------------------------------------------------------------------------
  public :
  CATTopologicalOperator & GetTopologicalOperator(CATBody* iCreationBody=NULL, CATCGMJournalList* iJournal=NULL);
  //------------------------------------------------------------------------------
  // Pilotage de la duplication pour la couture
  //------------------------------------------------------------------------------
  public :
  void SetUseFullDuplication(CATBoolean iUseFullDupl);
  CATBoolean UseFullDuplication();

  public:
  void SetExtrapolRibbonInProgress( CATBoolean iState) {_ExtrapolRibbonInProgress = iState;}
  CATBoolean IsExtrapolRibbonInProgress() const {return _ExtrapolRibbonInProgress; } 

  virtual void SwitchToLoopExtension (CATTopRibSupport * iSupport,
                                      ListPOfCATTopRibSupports &oLoopExtensionSupports,
                                      CATLONG32           iSupportIndex,
                                      CATCell            *iBorderCell,
                                      CATEdgeCurve       *iCrossEdgeCurve = NULL,
                                      CATCrvLimits       *iCrossLimits    = NULL);

    
  virtual void SwitchToLoopExtension (CATTopRibSupport * iSupport,
                                      ListPOfCATTopRibSupports &oLoopExtensionSupports,
                                      CATLoopExtension   *iLoopExtension,
                                      CATCell            *iBorderCell,
                                      CATCell            *iBestComplCell = NULL);

  void SetSupportDomain(const int iNumSupp, CATDomain* iDomain);

  virtual CATBoolean GetFreeBorderCompletion();

  //------------------------------------------------------------------------------
  // ST5 Wk7-2011: Methode de cast, NULL si cast impossible
  //------------------------------------------------------------------------------
  public:
  virtual CATParallelMacroTool * GetAsParallelMacroTool(); 

  virtual CATNtrlDrftRibMacroTool * GetAsNtrlDrftRibMacroTool();   //DSH1 Nov 2015 OutRib Tangent Propagation Control 

  //REN Wk 8, 2013. To be used in TopologicalOperatorsLight
  void SetFilletG2SectionType();    //For G2 Fillet
  CATBoolean IsFilletG2SectionType();
  void SetFilletIsoparCircularSectionType();   //For Styling Fillet
  CATBoolean IsFilletIsoparCircularSectionType(); 

 //------------------------------------------------------------------------------
  // Class Data
  //------------------------------------------------------------------------------
  private:
  ListPOfCATDomain          _SupportDomains;          // Domaine de chacune des cellules d'init 
  ListPOfCATFace          * _FacesWithSplittingEdges; // Faces ayant des coupantes a prendre en compte
  CATListPV               * _SplittingEdges;          // liste de coupantes sur chacune des faces 
  CATListPV               * _SideOfEdges;             // side pour chacune des edges 
  CATListPV               * _FullSideAccepted;        // Full side est-il accepte 
                                                      //  (pour chacune des edges) 

  CATListOfInt              _NumRibOfExit;            // Ruban ayant fourni le nuplet d'exit
  CATListPV                 _RibsForExit;             // Ruban d'ou proviennent les nuplets exit
  ListPOfCATTopRibNuplets   _NupletForExit;           // Nuplet pouvant servant pour l'exit
  CATListPV                 _ExitContacts;            // Liste de contacts servant pour l'exit 
  ListPOfCATTopRibNuplets   _LinkedNuplets;           // Nuplet devant etre detruits (backup)

  CATListOfInt              _SuppWithoutPropag;       // Numero des supports sans propag
  CATListOfInt              _SupportPropagType;       // Type de propagation sur support
                                                      // Par defaut : propagation "Smooth"
  
  ListPOfCATTopRibs         _SwitchRibs;              // Switch ribbons
  CATListOfInt              _SwitchDirections;        // Switch ribbon directions

  CATSoftwareConfiguration* _SoftwareConfiguration; // Config a utiliser
  
  CATVirtualTopologicalModeling *_Vtm;

  CATListOfInt              _SupportRelimMode;
  CATListPV                 _JunctionLinkCell;        // Cellules candidates a etre linkcell si bifurcation
  ListPOfCATVertex          _NonSharedNonExtrVertices; // vertices ne pouvant servir a la completion

  ListPOfCATDomain          _InitDomains;
  ListPOfCATDomain          _DuplDomains;
  CATRibInit *_Operation;
  double                    _FaceExtrapolRatioVsVolumeBox;

  CATBoolean                _CreateSingleComplLoopExtension;
  CATBoolean                _IsSet;
  CATBoolean                _RecursiveSupportSearch;// Active la recherche recursive de support (ex: Relimitation sur Fillet HoldCurve)

  CATBoolean               _IsFilletG2SectionType, _IsFilletIsoparCircularSectionType;

 protected: 
  CATBody *               _CreationBody;            // Body dans lequel on cree les elements 
  int                     _NbSupports;              // Nombre de supports
  ListPOfCATBody          _SupportBodies;           // Body de chacun des appuis 
  CATListOfInt            _Orientation;             // Orientation des Cellules d'init
  int                     _OrientationTuning;
  CATListOfInt            _NeedToDisconnectDomains; // Need To Disconnect the Domain
  ListPOfCATDomain        _AdditionalDomains;       // Domaines authorises 
  ListPOfCATTool          _Tools;                   // Liste des outils crees 
  ListPOfCATTopRibNuplets _SpecialNuplets;          // Liste de Nuplets d'arret
  CATListOfInt            _SpecialNupletsNumScar;   // NumScar des nuplets speciaux
  CATListOfInt            _TypeSpecialNuplet;       // Type des Nuplets d'arret 
  CATTopRibSol            _DefaultTypeSol;          // Resultat par defaut de GetTypeSol
  CATTopologicalOperator* _TopOpServices;           // TopOp for Safe usage
  CATTopData*             _TopDataServices;         // TopData for _TopOpServices
  CATParting             *_Parting;                 // Gestion du Parting element (objet a ne pas detruire!)
  CATTopRibSol            _PartingSolType;          // SolTypeIn, SolTypeOut, SolTypeIn&SolTypeOut ou 0 
  CATTopRibSol            _PriorityPartingType;     // Specifie le type de face parting prioritaire
  CATRibTopOp            *_RibTopOp;                // Pour partager les complementaires
  int                     _ComplFix2;               // Pour activation des "complementaires drop2"
  int                     _SaveExtrSurf;            // 0 - pas de sauvegarde a faire 
                                                    // 1 - sauvegarde a faire (on utilise les 2 listes ci-dessus)
  int                     _JunctionMode;            // 0 - bride les bifurcations
                                                    // 1 - autorise les bifurcations
  int                     _LookingForRibbonInitCounter; // used to know if we are performing ribbon initialization
  CATBoolean              _CompletionAllowed;       // Completion debranchee dans certains cas (CATRelimTopOp)
  int                     _CurrentRibDepthLevel;    // Niveau de profondeur du ruban
  CATBoolean              _ExtrapolRibbonInProgress;//status of ribbon
  CATCGMFormol           *_Formol;                  // Gestion lock/unlock geometries
};

//======================================================================
// INLINE IMPLEMENTATIONS
//======================================================================
 //------------------------------------------------------------------------------
 // Renvoie la configuration a utiliser 
 //------------------------------------------------------------------------------
 INLINE CATSoftwareConfiguration* CATTopRibMacroTool::GetSoftwareConfiguration() const
 {
   return _SoftwareConfiguration; 
 }
 //------------------------------------------------------------------------------
 // Lecture du pointeur parting
 //------------------------------------------------------------------------------ 
 INLINE CATParting * CATTopRibMacroTool::GetPartingElement ()
 {
   return _Parting;
 }
 //------------------------------------------------------------------------------
 // Donne l operation qui contient les spec user 
 //------------------------------------------------------------------------------ 
 INLINE CATRibInit  *CATTopRibMacroTool::ReadRibInit() const
 {
   return _Operation;
 }
//------------------------------------------------------------------------------
// Renvoie le domaine d'un support
//------------------------------------------------------------------------------
INLINE CATDomain * CATTopRibMacroTool::GetSupportDomain(int iSupport, CATBoolean* ioNeedToDisconnectDomain)
{
  if (iSupport<1 || iSupport>_SupportDomains.Size())
    CATThrow (new TopologicalOperatorsInternalError(GBIntEFilletBadIndex));
  if ( ioNeedToDisconnectDomain ) 
    *ioNeedToDisconnectDomain = _NeedToDisconnectDomains[iSupport];
  return _SupportDomains[iSupport];
}
//------------------------------------------------------------------------------
// Renvoie le body d'un support
//------------------------------------------------------------------------------
INLINE CATBody * CATTopRibMacroTool::GetSupportBody(int iSupport)
{
  CATBody * ToReturn = NULL;
  if (iSupport<1 || iSupport>_SupportBodies.Size())
    CATThrow (new TopologicalOperatorsInternalError(GBIntEFilletBadIndex));
  ToReturn = _SupportBodies[iSupport];
  return ToReturn;
}

//------------------------------------------------------------------------------
// Renvoie le nombre de supports
//------------------------------------------------------------------------------
INLINE int CATTopRibMacroTool::GetNbSupports()
{
  return _NbSupports;
}

//------------------------------------------------------------------------------
// Renvoie FALSE si la completion est debranchee (utilise dans CATRelimTopOp)
//------------------------------------------------------------------------------
INLINE CATBoolean CATTopRibMacroTool::IsCompletionAllowed()
{
  return _CompletionAllowed;
}

//------------------------------------------------------------------------------
INLINE CATBoolean CATTopRibMacroTool::GetRecursiveSupportSearch() const
//------------------------------------------------------------------------------
{
  return _RecursiveSupportSearch;
}

//------------------------------------------------------------------------------
// Renvoie la liste des orientations des cellules supports
//------------------------------------------------------------------------------
INLINE const CATListOfInt& CATTopRibMacroTool::GetSupportOrientation()
{
  return _Orientation;
}

//------------------------------------------------------------------------------


#endif

