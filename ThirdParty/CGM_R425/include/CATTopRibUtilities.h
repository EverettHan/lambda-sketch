/* -*-C++-*- */

#ifndef CATTopRibUtilities_H
#define CATTopRibUtilities_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// Utilitaires de CATTopRib
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Dec. 97    Creation                         J-M.Guillard
//===================================================================
//
// 24/07/19 PKC config in StabilizeFacePropagation API 
//===================================================================

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibDef.h" 
#include "CATMathDef.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATShell.h"
#include "ListPOfCATTopRibNuplets.h"
#include "ListPOfCATSupContact.h"
#include "ListPOfCATTopRibSupports.h"
#include "ListPOfCATLoopExtensions.h"
#include "CATListOfInt.h"
#include "ListPOfCATDomain.h"
#include "CATListOfCATSurfaces.h"
#include "CATRibInit.h"
#include "CATTopRibNuplet.h"

class CATTopologicalOperator;
class CATSoftwareConfiguration;
class CATCGMJournalList;

class CATBody;
class CATEdge;
class CATVertex;
class CATPointOnCurve;
class CATCell;
class CATFace;
class CATLoop;
class CATDomain;
class CATShell;
class CATGeoFactory;
class CATTopRibMacroTool;
class CATCurve;
class CATFaceBoundaryIntersectionChecker;

class CATTopRib;
class CATTopRibTool;
class CATTopRibSupport;
class CATTopRibNupletConnexion;
class CATTopRibGeoNuplet;
class CATSupContact;
class CATArrayOfNupletsLists;

class CATSurface;
class CATSurParam;
class CATSurLimits;
class CATMathDirection;
class CATPoint;

//------------------------------------------------------------------------------
// Nettoie le support de Nuplets partageant une solution topologique avec un 
// nuplet de reference. Par nettoyage, on entend suppression des references a 
// la trace que l'on ne souhaite plus partager.
// La valeur retournee est le numero du premier support ou l'on a rencontre une
// trace differente. 
//------------------------------------------------------------------------------
/*
ExportedByRIBLight int IsolateSupport(ListPOfCATTopRibNuplets &iListOfNuplet, // Nuplets pouvant partager une trace 
				    int                      iNupletRef,    // Nuplet a isoler 
				    int                      iNumSupp,      // Support a isoler 
				    CATTopRibSign            iDirection,    // Direction d'isolation
				    int                      iPas);         // Progression dans la liste (1 ou -1) 
// a partir de iNupletRef
*/
//------------------------------------------------------------------------------
// Nettoie les liens coupants inutiles.					
//------------------------------------------------------------------------------
/*
ExportedByRIBLight void RemoveCutting(ListPOfCATTopRibNuplets &iListOfNuplet, // Nuplets  
		                    int                      iNupletRef,    // Premier Nuplet a isoler 
		                    int                      iNumSupp,      // Support a isoler 
		                    CATTopRibSign            iDirection,    // Direction dans laquelle les Nuplet sont a isoler 
		                    int                      iPas);         // Progression dans la liste (1 ou -1) 
                                                                            // a partir de iNupletRef
*/
//------------------------------------------------------------------------------
// Swap une trace d'un suport par une autre et met a jour les Nuplets la
// partageant.
//------------------------------------------------------------------------------

ExportedByRIBLight CATCell * UpdateTrack(ListPOfCATTopRibNuplets& iListOfNuplet,
                                       int                      iCurPos      ,
                                       int                      isup         ,
                                       CATCell                * iNewtrack    ,
                                       CATTopRibSign            iCurDirection);

//------------------------------------------------------------------------------
// Determine le "side" d'une cellule (edge ou face) par rapport a sa cellule
// bordee (definie par un body et un domaine). La fonction rend aussi un
// signe indiquant si la cellule est a re-orienter pour avoir la meme
// orientation qu'une cellule de reference dont le "side" par rapport a la
// meme cellule bordee est donnee
//------------------------------------------------------------------------------

ExportedByRIBLight CATTopRibSign GetGoodOrientation (CATCell   *iCell,
		                                             CATBody   *iBody,
		                                             CATDomain *iDomain,
		                                             CATSide    iRefSide,
		                                             CATSide   &oSide);

//------------------------------------------------------------------------------
// Complete les liens coupant sur les cellules liant deux nuplets.
//------------------------------------------------------------------------------

// iLeftDirection est la direction sur iLeftNuplet ou a lieu la connexion
// iRightDirection est la direction sur iRightNuplet ou a lieu la connexion
// NB : ceci est utile quand les Nuplets sont issus de 2 rubans differents (avec 
//      eventuellement 2 direction)
ExportedByRIBLight void UpdateCutting(CATTopRibNuplet * iLeftNuplet ,
                                  CATTopRibSign     iLeftDirection  ,
                                  CATTopRibNuplet * iRightNuplet,
                                  CATTopRibSign     iRightDirection  ,
	                                int               iNumSupp=0  );

//------------------------------------------------------------------------------
// Get the best common link cell (if possible, otherwise return NULL) between
// two N-uplets on a given support
//------------------------------------------------------------------------------
ExportedByRIBLight CATCell *GetBestLinkCell(CATTopRibNuplet *iLeftNuplet,
                                      CATTopRibSign    iLeftDirection,
                                      CATTopRibNuplet *iRightNuplet,
                                      CATTopRibSign    iRightDirection,
                                      int              iNumSupp);
                         
//------------------------------------------------------------------------------
// Create all the N-uplets resulting from a given array of supports
//------------------------------------------------------------------------------

ExportedByRIBLight void CreateResultingNuplets (CATTopRibSign             iDirection,
                                            CATTopRibTool            *iTool,
                                            CATTopRibSupport        **iSupportArray,
                                            int                       iNbSupports,
                                            CATArrayOfNupletsLists   &ioNupletsListsArray,
                                            CATListOfInt             &oFirstNupletIn,
                                            CATListOfInt             &oLastNupletIn,
                                            CATTopRibGeoNuplet       *iGeoNuplet = NULL,
                                            CATBoolean iUseConfusedInits = FALSE);

// -----------------------------------------------------------------------------     
// Cut edge with cutting edges and update inside/outside information. 
//
// Please note: iSplitChoiceDir can be provided in order to intersect the
//              ribbon with iCuttingEdge at only one point, i.e. if more
//              than one intersection is found then only the point that is
//              located nearer the start (iSplitChoiceDir = Backward) or
//              end vertex (iSplitChoiceDir = Forward) of iCuttingEdge is
//              kept.
// -----------------------------------------------------------------------------
/*
ExportedByRIBLight void SplitWithCuttingEdges(CATBody                  *  iCreationBody,
                                          CATSoftwareConfiguration *  iConfig,
                                          CATFace                  *  iSupportFace , 
                                          CATEdge                  *  iEdgeToCut   ,
                                          CATSide                     iSideToKeep  ,
                                          CATEdge                  *  iCuttingEdge ,
                                          CATEdge                 **& oCutEdges    ,
                                          CATTopRibSol             *& oInOutInfo   ,   
                                          int                       & oNbNewEdges  ,
                                          CATTopRibSign            *  iSplitChoiceDir = NULL);
*/

// -----------------------------------------------------------------------------
// Cherche si deux faces sont adjacentes a des fonds communs via un support
// rolling (c'est a dire : surface bord d'un support edge de la surface !)
// -----------------------------------------------------------------------------
ExportedByRIBLight CATSurface * GetCommonSurfaceWithRollingSupport( CATFace * iFace [],
                                                                    CATSoftwareConfiguration * iConfig );

// -----------------------------------------------------------------------------
// Cherche si deux faces sont adjacentes a un fond commun. Se base sur l'info 
// disponible sur les surfaces a historique telle que fillet, ...  
// Si irec est a vrai, la recherche se fait sur plusieurs niveaux d'historique
// -----------------------------------------------------------------------------
ExportedByRIBLight CATSurface * GetCommonSurface(CATFace                  * iFace [],
                                             CATFace                  * iOldFace [],
                                             CATBody                  * iBody,
                                             CATSoftwareConfiguration * iConfig,
                                             CATBoolean                 iRec=0); 

//-----------------------------------------------------------------------------
// Remove de faces dans un shell a partir de listes de coupantes. Le shell
// est bien sur modifie. 
// Si on donne en entree un CATTopologicalOperator (celui qui a servi a disconnecter 
//  le shell), alors on propage les faces a enlever
//-----------------------------------------------------------------------------
ExportedByRIBLight void RemoveBadFaces(CATBody                  * iBody,
                                   CATSoftwareConfiguration * iConfig,
                                   CATShell                 * ioSkin,
                                   ListPOfCATEdge             iEdgeForSel[],// tab de taille iNbOfList
                                   CATSide                    iSideForSel[],// tab de taille iNbOfList
                                   CATLONG32                       iNbOfList,
                                   CATCGMJournalList        * iJournal=NULL,
                                   ListPOfCATEdge           * iEdgeToKeep=NULL,
                                   CATTopologicalOperator   * iTopOp=NULL,
                                   ListPOfCATFace           * iFaceToDelete=NULL,
                                   CATBoolean                 iEdgeReporting=0,
                                   CATBoolean               * ioEmptyOutputForbidden    = NULL,
                                   ListPOfCATShell          * iShellToKeep = NULL,
                                   CATShell                 * iShellForEdgeToKeep = NULL,
                                   ListPOfCATEdge           * iFreeEdges = NULL,
                                   CATListOfInt             * iFreeSides = NULL,
                                   CATListOfInt             * iExpectedSideFaceVsShell0=NULL,
                                   CATListOfInt             * iExpectedSideFaceVsShell1=NULL,
                                   CATListOfInt             * iExpectedSideFaceVsShell2=NULL,
                                   CATBoolean                 iCheckSideOfFacesInShell = FALSE,
                                   ListPOfCATFace           * iFacesDiscarded = NULL);

//-----------------------------------------------------------------------------
// Detruit une face en netoyant les coupantes. 
//-----------------------------------------------------------------------------

ExportedByRIBLight void CleanAndRemove(CATBody                  * iBody,
                                   CATSoftwareConfiguration * iConfig,
                                   CATFace                  * iFaceToDel,		    
                                   ListPOfCATEdge           * iCuttingToKeep=NULL,
                                   ListPOfCATEdge           * iOtherEdgeToKeep=NULL,
                                   CATCGMJournalList        * iJournal=NULL,
                                   CATBoolean                 iEdgeReporting=CATBoolean(0),
                                   CATBoolean                 iFaceReporting=CATBoolean(0),
                                   ListPOfCATFace           * iFacesDiscarded = NULL);

//-----------------------------------------------------------------------------
// Detruit un shell et son contenu. 
//-----------------------------------------------------------------------------

ExportedByRIBLight void CleanAndRemove(CATBody* iBody, CATShell* iShell);

//-----------------------------------------------------------------------------
// Detruit un shell et son contenu. 
//-----------------------------------------------------------------------------
/*
ExportedByRIBLight void CleanAndRemove(CATBody* iBody, CATShell* iShell, CATCGMJournalList* iJournal);
*/
//------------------------------------------------------------------------------
// Modifie le contact dans le cas ou la cellule lien est un vertex pour eviter 
// de partir dans une mauvaise direction.
//-----------------------------------------------------------------------------

ExportedByRIBLight void FindEdgeAsLink(CATTopRibSign     iDirection,				 
                                 CATTopRibNuplet * iNuplet,
                                 int               iNumSupp,
                                 CATSide           iSideRef,
                                 CATSupContact   & ioContact,
                                 CATTopRibSign   & oRelativeOri,
                                 CATEdge        ** oBaseEdge = NULL,
                                 ListPOfCATEdge *iForbiddenLinkEdges = NULL);


//-----------------------------------------------------------------------------
// Calcul de la tangente de l'intersection de deux surfaces. Le booleen renvoye
// vaut true si le calcul s'est effectue avec succes, false sinon.
// Dans le meme temps, on calcule la convexite de l'edge.
// 
// Le booleen renvoye ne vaut 0 que si les surfaces sont confondues au deuxieme 
// ordre 
//
// Ne traite pour l'instant que le cas ou les directions de courbure principales 
// correspondent a une isopare pour au moins l'une des deux surfaces 
//-----------------------------------------------------------------------------
ExportedByRIBLight int GetInitDataOnIntersection(CATSurface           * iLeftSur,
                                            CATSurParam              & iLeftParam,
                                            CATSurface               * iRightSur,
                                            CATSurParam              & iRightParam,
                                            CATMathDirection           oTgt[2],
                                            CATTopSharpness          & oSharpness,
                                            CATSoftwareConfiguration * iConfig,
                                            int   				           * oZeroTgt = NULL );


//------------------------------------------------------------------------------
// Recherche d'une intersection entre l'edge iCurrentEdge et la liste de faces 
// iListOfFaces .
// dans les limites [iV0, iV1] sur l'edge.
//------------------------------------------------------------------------------
ExportedByRIBLight CATBoolean IntersectEdgeWithListFaces(CATSoftwareConfiguration * iConfig,
                                                    CATEdge                  * iCurrentEdge,
                                                    CATVertex                * iV0,
                                                    CATVertex                * iV1,
                                                    const ListPOfCATFace     & iListOfFaces,
                                                    CATBoolean                 iCheckConfusion);


//------------------------------------------------------------------------------
// Analyse des Nuplets inits : permet de connaitre la liste des Nuplets 
// redondants  par rapport au ruban en entree.
// 
// En effet, le ruban entre correspond au ruban apres la propagation.
// Il est possible que la propagation a permis de recouvrir toutes les 
// solutions (tous les listes Inits). On aura alors la liste des
// la liste des Nuplets redondants referencant toutes les listes Inits entrees.
// Une liste Init partiellement contenue (ou recouverte) par le ruban,
// est concideree comme non redondante.
//
//------------------------------------------------------------------------------

ExportedByRIBLight void InitialSolutionAnalysis(CATTopRib               *iRuban, 
                                          CATArrayOfNupletsLists  &iNupletsListsArray, 
                                          CATListOfInt            *iFirstNupletIn,
                                          CATListOfInt            *iLastNupletIn,
                                          CATListOfInt            &RedundantInits,
                                          ListPOfCATTopRibNuplets *DegeneratedNuplets=NULL,
                                          CATBoolean               iOnlyUsefulRibbonPart = CATFalse,
					  CATBoolean               iUseConfusedNuplets = CATFalse); //D1A: IR-212024 : 17-May-2013

//-----------------------------------------------------------------------------
// Cherche les cellules bordees par un vertex (edges et faces) et les rend de 
// maniere ordonnee.
// L'ordre peut etre impose en passant une edge et une face. Dans ce cas on rend
// dans la liste d'edge les edges qui servent a la transition vers de nouvelles 
// faces, et dans la liste des faces ces nouvelles faces. En premier on trouvera 
// l'edge donne et la face qui lui est directement adjacente. En second dans la 
// liste d'edge on aura l'edge adjacente au vertex sur la nouvelle face ...
// Les faces sont donnees shell par shell. Lorsque l'on passe sur un nouveau 
// shell, on retrouve juste avant la face initiale. 
// Lorsque l'on tombe sur un bord libre, et si la variable StopOnFreeEdge est a 
// false, on revient sur la face initiale et l'on itere dans l'autre sens de
// maniere a etre sur de ne rater aucune face.   
//-----------------------------------------------------------------------------
/*
ExportedByRIBLight void SortBnddCells(CATVertex      * iVertex,
				                          CATEdge        * iFirstEdge,
				                          CATFace        * iLastFace,
				                          CATBody        * iBody,
				                          CATBoolean       iStopOnFreeEdge,
				                          ListPOfCATEdge & oAdjEdges,
				                          ListPOfCATFace & oAdjFaces);
*/
//------------------------------------------------------------------------------
// Out of an array of cutting vertices (on two edges), choose the one
// that is nearest the start (VertexChoiceDir = Backward) or end vertex
// (VertexChoiceDir = Forward) of one of the two edges (iRefEdge)
//
// Please note: 1) iStartIndex & iEndIndex are optional and are used to define
//                 a sub list inside the iVertex list (if they are not provided
//                 the whole list is used)
//              2) oBestVertexIndex is an optionla output that provides the
//                 index of the best vertex in the iVertex list
//              3) if oNbBestVertices is provided then all vertices that
//                 are at the same location on iRefEdge are kept and returned in
//                 the oBestVertex (and the oBestVertexIndex) array(s)
//                 This also indicates that oBestVertexIndex and oBestVertex are
//                 arrays of the same size as iVertex, otherwise they are only
//                 addresses of scalar variables
//                 The number of confused vertices is returned in
//                 *oNbBestVertices
//------------------------------------------------------------------------------

ExportedByRIBLight void KeepOnlyBestVertexOnEdge(CATBody                  * iCreationBody,
                                           CATSoftwareConfiguration * iConfig,
                                           CATFace                  * iFace, 
                                           CATEdge                  * iRefEdge,
                                           const ListPOfCATVertex   & iVertex,
                                           CATTopRibSign              iVertexChoiceDir,
                                           CATVertex                **oBestVertex,
                                           CATLONG32                       iStartIndex         = 0,
                                           CATLONG32                       iEndIndex           = 0,
                                           CATLONG32                     * oBestVertexIndex    = NULL,
                                           CATLONG32                     * oNbBestVertices     = NULL,
                                           CATBoolean                 iDestroyVertices    = TRUE);



//------------------------------------------------------------------------------
// Verification, a partir d'une liste de gestionnaires d'initialisations
// multiples, que tous les rubans a inits multiples ont bien englobes
// tous leurs N-uplets initialisants et destructions de ces derniers
//------------------------------------------------------------------------------

ExportedByRIBLight CATBoolean CheckAndCleanMultipleInits (CATListPV  &iMultiInits,
                                                    CATBoolean  iDestroyNonRedundantInits = CATBoolean(1),
                                                    CATBoolean  iDoNotDeleteMngrs = CATBoolean(0),
						    CATBoolean iUseConfusedNuplets = CATBoolean(0)); //D1A: IR-212024 : 17-May-2013


//------------------------------------------------------------------------------
// Get adjacent faces of a track edge lying on an edge support
// iMacroTool is the macrotool of the current rib
// iNuplet is the nuplet of the track
// iNumSupp is the number of support of the track
// oFaceToKeep is the face that will be kept in final body
// oFaceToDel is the face "under" the ribbon
// oOriKeep et oOriDel sont leurs orientations en temps que support (facultatif)
//------------------------------------------------------------------------------
ExportedByRIBLight void GetAdjFacesOfEdgeSupport (CATTopRibMacroTool * iMacroTool,
                                             CATTopRibNuplet    * iNuplet,
                                             int                  iNumSupp,
                                             CATFace           *& oFaceToKeep,
                                             CATFace           *& oFaceToDel,
                                             CATTopRibSign     *  oOriKeep=NULL,
                                             CATTopRibSign     *  oOriDel=NULL);

//------------------------------------------------------------------------------
// Assurer la connexite d'un domaine
//------------------------------------------------------------------------------
ExportedByRIBLight void BuildDomains (CATBody *iCreationBody, CATSoftwareConfiguration* iConfig, 
                                  CATDomain* iDomainToSplit, ListPOfCATDomain &oCreatedDomains);


//------------------------------------------------------------------------------
// Assess internal confused nuplets and change the type if they are bracketed by the same type
//------------------------------------------------------------------------------
ExportedByRIBLight void AssessConfusionOfInternalNuplet( ListPOfCATTopRibNuplets &LNuplets );

//------------------------------------------------------------------------------
// If iIndexOfUsedList>=  0 : Clean in iInitialNuplets all the list containing
//                            clones of UsedList
// If iIndexOfUsedList== -1 : Clean all the list containing clones
// If iDestroyInits==TRUE, then also destroy N-uplets
//------------------------------------------------------------------------------
ExportedByRIBLight void RemoveCloneInits(CATArrayOfNupletsLists &iNupletsListsArray, 
                                   CATLONG32               iIndexOfUsedList,
                                   CATBoolean              iDestroyInits   = CATBoolean(1),
                                   CATListOfInt           *oDestroyedLists = NULL);

//------------------------------------------------------------------------------
// Dump les infos coupantes sur un face et/ou un edge
// si iFace seule est donnee : dump des cellules coupantes de la face
// si iEdge seule est donnee : dump des cellules coupantes de l'edge sur ses faces voisines
// sinon on donne uniquement les cellules coupantes de l'edge sur la face
//------------------------------------------------------------------------------
ExportedByRIBLight void DumpCutting(CATSoftwareConfiguration * iConfig, CATBody * iBody,
                                CATFace * iFace=NULL, 
                                CATEdge * iEdge=NULL,
                                CATVertex * iVertex=NULL);



//------------------------------------------------------------------------------
// Ordonner la liste des nuplets en paquets correspondant aux solutions possibles
// NB: Le tableau de CATFilletPaquage rendu est alloue par new[]
//------------------------------------------------------------------------------
ExportedByRIBLight CATFilletPaquage *SortInAndOutNuplets (CATListPV  &iLNuplets,
                                                    int         iStart,
                                                    int         iEnd,
                                                    int        &oNumberOfPaquages, 
                                                    int        &oNumberOfInPaquages,
                                                    int        &oLastInPaquage,
                                                    CATSoftwareConfiguration* iConfig,
                                                    CATBoolean  iInEqNotOut=FALSE,
                                                    CATTopRib * AnalyseCandidates = NULL);

//------------------------------------------------------------------------------
// Ordonner la liste des nuplets en paquets correspondant aux solutions possibles
// (Identique a la methode ci-dessus mais recoit des liste de N-uplets au lieu
// de listes de pointeurs sur void; appelle la methode ci-dessus)
// NB: Le tableau de CATFilletPaquage rendu est alloue par new[]
//------------------------------------------------------------------------------
ExportedByRIBLight CATFilletPaquage *SortInAndOutNuplets (ListPOfCATTopRibNuplets &iLNuplets,
                                                    int                      iStart,
                                                    int                      iEnd,
                                                    int                     &oNumberOfPaquages, 
                                                    int                     &oNumberOfInPaquages,
                                                    int                     &oLastInPaquage,
                                                    CATSoftwareConfiguration* iConfig,
                                                    CATBoolean               iInEqNotOut=FALSE,
                                                    CATTopRib * AnalyseCandidates = NULL);

//------------------------------------------------------------------------------
// Sort the N-uplet lists
//------------------------------------------------------------------------------
ExportedByRIBLight void SortNupletLists(CATSoftwareConfiguration * iConfig,
                                  CATArrayOfNupletsLists    &iNupletsListsArray,
                                  CATListOfInt              &iFirstNupletIn,
                                  CATListOfInt              &iLastNupletIn,
                                  CATBoolean                 iExplodeMultiInSolution,
                                  CATTopRibMacroTool *       iMacroTool = NULL);

//------------------------------------------------------------------------------
// Find out if a given set of N-uplets has reached
// a contact on a given support in a given direction
//
// Please note:
// 1) if iDirection == BothDirections, the method returns true if
//    at least one contact was found
// 2) oLinkCells is an optional output. It contains either
//    one or two cells, the latter only if iDirection is
//    equal to BothDirections and if the N-uplets have
//    reached a contact in both directions
//------------------------------------------------------------------------------
ExportedByRIBLight CATBoolean HasContacts (CATTopRibSign            iDirection,
                                      CATLONG32                     iSupportIndex,
                                      ListPOfCATTopRibNuplets &iNuplets,
                                      CATLONG32                     iStartIndex,
                                      CATLONG32                     iEndIndex,
                                      ListPOfCATCell          *oLinkCells=NULL);

//------------------------------------------------------------------------------
// Destroy a track cell
//------------------------------------------------------------------------------
/*
ExportedByRIBLight void DestroyTrackCell (CATBody *iCreationBody,
                                    CATCell       *iTrackCell,
                                    CATCell       *iSupportCell = NULL);
*/

//------------------------------------------------------------------------------
// Recupere le point on curve d'un vertex sur une edge
//------------------------------------------------------------------------------
ExportedByRIBLight CATPointOnCurve *GetVertexPointOnCurve(CATVertex *iVertex, CATEdge *iEdge);

//------------------------------------------------------------------------------
// compare la position de 2 vertex sur une edge
// renvoie  1 si iA > iB
//         -1    iA < iB
//          0    iA = iB
//------------------------------------------------------------------------------
// ExportedByRIBLight int CompareVerticesOnEdge(CATVertex *iA, CATVertex *iB, CATEdge *iEdge);

//------------------------------------------------------------------------------
// Ajoute une face dans un shell avec la bonne orientation
//------------------------------------------------------------------------------
ExportedByRIBLight CATBoolean AddFaceIntoShellWithCorrectOri(CATCell *iFace, CATShell *iShell, CATBody *iBody);

//------------------------------------------------------------------------------
// Utilise le journal apres decoupe pour savoir ce 
// que sont devenues les entrees utilsateur
//------------------------------------------------------------------------------

ExportedByRIBLight void FollowEdgeAndRatio(const CATTopData *iTopData, CATEdge *iEdgeToFollow, double iRatio,
                                       CATCGMJournalList& iPrivateEdgesJournal,
                                       CATEdge *&oEdge, double &oRatio);

//------------------------------------------------------------------------------
// Verifie les autointersection des loop des faces du shell passe entree
// iCheckLevel specifie le niveau d'exigence du check :
// -> 0 = automatique
//    1 = gamma entre edges ne partageant pas de vertex est invalide
//    2 = gamma invalide
//    3 = gamma et P invalides
//    4 = gamma, P et r invalides (est-ce bien utile ?)
//------------------------------------------------------------------------------
ExportedByRIBLight CATBoolean CheckShellValidity(CATSoftwareConfiguration * iConfig, CATBody * iBody,
                                            CATShell * iShell, int iCheckLevel = 0, CATError **oError = NULL);

ExportedByRIBLight CATBoolean CheckFaceValidity(CATSoftwareConfiguration * iConfig, CATBody * iBody,
                                          CATFace * iFace, int iCheckLevel = 0, CATError **oError = NULL);

ExportedByRIBLight CATBoolean AnalyzeFaceBoundaryIntersectionCheckerDiag(CATFaceBoundaryIntersectionChecker *iChecker, int iCheckLevel,
                                                                   ListPOfCATEdge &oErrorEdges);


ExportedByRIBLight void GetShellEdges(CATShell *iShell, ListPOfCATEdge &oEdges);

ExportedByRIBLight void GetFaceEdges(CATFace *iFace, ListPOfCATEdge &oEdges);

ExportedByRIBLight CATBody *CreateBodyFromVertices(CATGeoFactory *iFactory, ListPOfCATVertex &iVertices);

//------------------------------------------------------------------------------
// compare la distance qui separe 2 parametres par rapport a une valeur d'entree
//  1 -> length > longueur de l'arc
//  0 -> length = longueur de l'arc
// -1 -> length < longueur de l'arc
//------------------------------------------------------------------------------
ExportedByRIBLight  int CheckCurveLength(CATSoftwareConfiguration* iConfig, CATCurve *iCurve, CATCrvParam &iStartParam, CATCrvParam &iEndParam, double iLength);

//------------------------------------------------------------------------------
// Compute the length of a track.
//------------------------------------------------------------------------------
ExportedByRIBLight CATPositiveLength GetLengthOfATrack(CATTopRibNuplet* iNuplet,const int iNumSupport);
ExportedByRIBLight CATPositiveLength GetLengthOfATrack(CATTopRib& iRib, const int iNupletStart, const int iNupletEnd, const int iNumSupport);

//-----------------------------------------------------------------
// Renvoie le level d'encoche multiface 
//-----------------------------------------------------------------
ExportedByRIBLight int IsMultiFaceNotchActivated(CATSoftwareConfiguration* iConfig);

//-----------------------------------------------------------------
// Renvoie vrai si le mode test en mode min est desactive dans parttoexport 
//-----------------------------------------------------------------
// CATBoolean IsAutomaticMinPropagDisabled(CATTopData *iTopData);

//-----------------------------------------------------------------
// essaie d'augmenter la taille et ioNewLimits pour inclure iParamToInclude
//-----------------------------------------------------------------
ExportedByRIBLight  CATBoolean IncludeParamAndTestUVSwitch(CATSurParam *iParamToInclude, int *oNeedUVSwitch,
                                                     const CATSurLimits *iInitialLimits, const CATSurLimits &iSurfaceMaxLimits,
                                                     CATSurface *iSuppSurface, CATSurLimits &ioNewLimits);

//-----------------------------------------------------------------
//  Trouve l'edge couverte par la skin
//-----------------------------------------------------------------
ExportedByRIBLight  CATBoolean  FindEdgeCoveredBySkin(CATTopRibSign   iDirection,
                                                  CATFace       * iOldFace,
                                                  CATFace       * iBaseFaces[2],
                                                  int             inbfac,
                                                  CATEdge       * iBaseEdge,
                                                  CATVertex     * iLinkVertex,
                                                  CATSide         iSideRef,
                                                  CATTopRibSign & ioLocOri,
                                                  CATTopRibSign   iSuppSign,
                                                  CATFace       *& oFace,
                                                  CATEdge       *& oEdge,
                                                  CATTopRibSign & oRelativeOri);

//-------------------------------------------------------------------------
// Comparaison de 2 Nuplets au moyen de leurs supports. 
// Retourne TRUE si supports identiques ou equivalents
//-------------------------------------------------------------------------
ExportedByRIBLight CATBoolean NupletSupportsAreIdentical(CATTopRibNuplet *iNuplet1,
                                                     CATTopRibNuplet *iNuplet2,
                                                     CATBoolean IgnoreConfusion=FALSE,
                                                     int SupportFilter=0);
//-------------------------------------------------------------------------
// Comparaison de 2 Nuplets au moyen de leurs supports. 
// Retourne TRUE si supports identiques ou equivalents
//-------------------------------------------------------------------------
ExportedByRIBLight CATBoolean NupletSupportsAreAlmostIdentical(CATTopRibNuplet *iNuplet1,
                                                           CATTopRibNuplet *iNuplet2,
                                                           CATBoolean IgnoreConfusion=FALSE,
                                                           int SupportFilter=0);

//-------------------------------------------------------------------------
// Comparaison de 2 Nuplets au moyen de leurs supports. 
// Retourne TRUE si loop extension identiques ou cell supports identiques
// et si au moins un des supports est sur une loop extension
// Renvoie les supports et les loops des deux nuplets.
//-------------------------------------------------------------------------
ExportedByRIBLight CATBoolean NupletSuppOnSameLoopWithAtLeastOneMultiComplLoop(CATTopRibNuplet *iNuplet1,
                                                                           CATTopRibNuplet *iNuplet2,
                                                                           ListPOfCATTopRibSupports &oSupp1,
                                                                           ListPOfCATTopRibSupports &oSupp2,
                                                                           ListPOfCATLoopExtensions &oLoop1,
                                                                           ListPOfCATLoopExtensions &oLoop2);
  


ExportedByRIBLight int FindSuppFromLinkCell(CATTopRib *iRib, int iNupletIndex, CATCell *iLinkCell);

//-------------------------------------------------------------------------------------------------------------
//
// Clone iTrackEdge, iStartVertex, iEndVertex et renvoie le tout dans *oTrackEdge, *oStartVertex, oEndVertex.
//
//-------------------------------------------------------------------------------------------------------------
ExportedByRIBLight void CreateTrackAndVertices(CATBody *iBody, 
                                          CATEdge *iTrackEdge, CATVertex *iStartVertex, CATVertex *iEndVertex,
                                          CATEdge **oTrackEdge, CATVertex **oStartVertex, CATVertex **oEndVertex);


ExportedByRIBLight CATBoolean ComputeSharpnessBetweenNupletWithCommonLinkCell(CATTopRibNuplet *iLeftNuplet, CATTopRibNuplet *iRightNuplet,
                                                                         int iLeftSupportIndex, int iRightSupportIndex, CATTopSharpness &oSharpness,
                                                                         CATAngle iTolAngle, CATAngle *oAngle = NULL);

// ExportedByRIBLight CATBoolean EvalEdgeInShellSharpness(CATSoftwareConfiguration* iConfig, CATEdge *iEdge, CATShell *iShell, CATTopSharpness &oSharpness);

// if no param can be found, if oSuccess == NULL, an error is thrown
// otherwise *oSuccess is filled with success status
ExportedByRIBLight void GetVertexGeometryOnFace(CATVertex *iVertex, CATFace *iFace,
                                            CATSurParam &oSurParam, CATSurface **oSurface,
                                            CATBoolean *oSuccess = NULL);

//ExportedByRIBLight CATWire *ExtrapolateEdgeG1AndCreateWire(CATBody *iBody, CATEdge *iEdgeToExtrapolate, CATVertex *iVertexToExtrapolate, double iDist);

//ExportedByRIBLight CATWire *ExtrapolateEdgeAndCreateWire(CATSoftwareConfiguration *iConfig, CATBody *iBody, CATEdge *iEdgeToExtrapolate, CATVertex *iVertexToExtrapolate, CATFace *iSupportFace, double iDist);

ExportedByRIBLight CATEdge *CreateEdgeFromGeometry(CATBody *iBody, CATCurve *iCurve, CATCrvParam &iStartParam, CATCrvParam &iEndParam);

ExportedByRIBLight CATBoolean MergeVerticesIfYouCan(CATTopologicalOperator *iTopOp, CATVertex *iSurvivingVertex, CATVertex *iDestroyedVertex, double iTol, int iKeepAllPoecs = 0);

//ExportedByRIBLight CATPoint *CreateVertexShellInclusionPoint(CATGeoFactory *iFactory, CATShell *iShell, CATVertex *iVertex,CATSoftwareConfiguration *iConfig);

ExportedByRIBLight CATBoolean HasConnexIn(ListPOfCATTopRibNuplets  &iLNuplets, int iStart, int iEnd);

ExportedByRIBLight CATBoolean HasIsotopoMatchingSet(ListPOfCATTopRibNuplets &iLNuplets,int iStart, int iEnd);


//ExportedByRIBLight void GetVertexGeometryOnPCurve(CATVertex *iVertex,  CATFace *iFace,
//                                                    CATCrvParam &oParamOnPCurve, CATPCurve **oPCurve,
//                                                    CATEdgeCurve **oEdgeCurve);

ExportedByRIBLight  void CutInitIfNecessary(CATFilletPaquage* ListOfPaquages,
                                      CATListPV  &iLNuplets,
                                      int         iStart,
                                      int         iEnd, 
                                      int         iCurrent,
                                      int        &oNumberOfPaquages,
                                      int        &FirstIn,
                                      int        &FirstUnknown,
                                      int        &SupportIn,
                                      CATSoftwareConfiguration* iConfig,
                                      CATBoolean  iInEqNotOut,
                                      CATBoolean  iDefaultBehavior,
                                      CATTopRib * AnalyseCandidates);

//
// GetNextIndexInList : 
// Given a limited list of nuplet, get next index in the iDirection, start counting from the begining/end
// if closure.
//
ExportedByRIBLight int GetNextIndexInList(ListPOfCATTopRibNuplets *iLNuplets, int iStart, int iEnd, 
                                          CATBoolean iClosed, CATTopRibSign iDirection,
                                          int        iCurrentIndex);

ExportedByRIBLight void ConnectThisRib(CATTopRib * iLeftRib , int &ioLeftNuplet , CATTopRibSign iLeftDirection,
                                       CATTopRib * iRightRib, int &ioRightNuplet, CATTopRibSign iRightDirection,
                                       CATTopRibNupletConnexion * iConnexion); 

// S9L : Stabilize Face Propagation : Start
//-------------------------------------------------------------------------------------------------------------
// Selects unique face among the list  on a certain criteria independent of the order of faces in the list
//
// Criteria:
//
// 1. if list contains only a single face, return the face
// 2. if list contains only a single face with maximum number of edges, return the face
// Among the faces with maximum number of edges...
// 3. if the list contains only a single face of PlaneType (or in type order given in method), return th face
// Among the non-empty face list with the given type of highest priority...
// 4. Get all the outer boundary edges of the faces in the list not shared by other faces in the list
// Among the list of edges so obatined...
// 5. if the list contains only a single edge, return the corresponfing face
// 6. if the list contains only a single edge of PLine type (or type order givem in method, return the face
// Among the non-empty edge list with the given type of highest priority...
// 7. Keep those with the maximum length (within the standard resolution) 
// 8. Keep those with the center located at the maximum X(within the standard resolution) 
// 9. Keep those with the center located at the maximum Y(within the standard resolution)
// 10. Keep those with the center located at the maximum Z(within the standard resolution)
// Return the face corresponding to the edge so obtained
//
//-------------------------------------------------------------------------------------------------------------
ExportedByRIBLight void StabilizeFacePropagation(CATSoftwareConfiguration *  iConfig,
                                                 CATBody                  *  ipInputBody,
                                                 const ListPOfCATFace      & iListOfFaces,
                                                 CATFace                  *&  opUniqueFace);
// S9L : Stabilize Face Propagation : End

/*
// Idem a IsPointInsideSplitNupFace, mais pour le cas ou l'on a plusieurs nuplets
// qui splittent la face
ExportedByCATFDGImpl int IsPointInsideMultiSplitNupFace(CATSurParam&              iPtSurPar,                                              
                                                        ListPOfCATTopRibNuplets&  iLSplitRlmNuplet,
                                                        CATFace*                  iRlmFace,
                                                        CATListOfInt&             iLSideToKeep,
                                                        double                    iTol);
*/

#endif
