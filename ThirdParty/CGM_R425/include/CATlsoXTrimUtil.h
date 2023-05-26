#ifndef CATlsoXTrimUtil_H
#define CATlsoXTrimUtil_H

// ++++ Includes ++++
#include "AdvTrimOpe.h"
#include "ListPOfCATPersistentBodies.h"

#include "CATFuzzyExtrapolOpe.h"

#include "CATVertex.h"
#include "CATEdge.h"
#include "CATFace.h"
#include "CATCell.h"
#include "CATDomain.h"
#include "CATShell.h"

#include "CATBody.h"
#include "CATListOfCATCells.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "CATlsoPersistentContext.h"
#include "CATSoftwareConfiguration.h"

#include "CATHybDef.h"
#include "CATlsoError.h"
#include "CATTopOpInError.h"

#include "CATListOfULONG32.h"
#include "CATCGMJournal.h"
#include "ListPOfCATPersistentEdges.h"
#include "ListPOfCATPersistentFaces.h"
#include "CATPersistentCellInfra.h"

// ++++ Predeclarations ++++
class CATMathOBB;
class CATSetOfSurParams;
class CATPersistentBody;
class CATMathPlane;
class CATMathAxis;

// Typedef
typedef HRESULT (*CATlsoXTrimJournalEditCallback)(ListPOfCATBody& iInputBodies, CATBody& iResultBody, CATCGMJournalList& iJournal, CATCGMJournalList& oNewJournal);

//=============================================================================
// CATlsoXTrimUtil
// 
// responsable: ZFC
// 
// Classe utilitaire pour l'operateur XTrim. Elle ne contient que des methodes
// statiques.
//=============================================================================

class ExportedByAdvTrimOpe CATlsoXTrimUtil
{
public:
  //---------------------------------------------------------------------------
  // OUTILS LISTES
  //---------------------------------------------------------------------------
  // Comparaison de deux listes de faces, renvoie TRUE si elles sont identiques
  // (i.e. elles contiennent les memes faces) et FALSE sinon
  static CATBoolean AreFaceListsIdentical(ListPOfCATFace& iList1,
                                          ListPOfCATFace& iList2);

  static CATBoolean AreEdgeListsIdentical(ListPOfCATEdge& iList1,
                                          ListPOfCATEdge& iList2);

  static CATBoolean IsFaceListAStrictSubset(ListPOfCATFace& iIncluder, ListPOfCATFace& iSubset);

  static CATBoolean IsEdgeListAStrictSubset(ListPOfCATEdge& iIncluder, ListPOfCATEdge& iSubset);

// Conversion d'une liste de faces en liste de cellules
  // Ne vide pas la liste oCellList au prealable
  static void FaceListToCellList(ListPOfCATFace& iFaceList, ListPOfCATCell& oCellList);

  // Conversion d'une liste de cellules en liste de faces
  // Ne vide pas la liste oFaceList au prealable
  // Si la liste de cellules d'entree est heterogene, on reussit silencieusement
  // en ne conservant que les cellules qui sont des faces.
  static void CellListToFaceList(ListPOfCATCell& iCellList, ListPOfCATFace& oFaceList);

  // Conversion d'une liste d'edges en liste de cellules
  // Ne vide pas la liste oCellList au prealable
  static void EdgeListToCellList(ListPOfCATEdge& iEdgeList, ListPOfCATCell& oCellList);

  // Conversion d'une liste de cellules en liste d'edges
  // Ne vide pas la liste oEdgeList au prealable
  // Si la liste de cellules d'entree est heterogene, on reussit silencieusement
  // en ne conservant que les cellules qui sont des edges.
  static void CellListToEdgeList(ListPOfCATCell& iCellList, ListPOfCATEdge& oEdgeList);

  // idem
  static void VertexListToCellList(ListPOfCATVertex& iVertexList, ListPOfCATCell& oCellList);

  // idem
  static void CellListToVertexList(ListPOfCATCell& iCellList, ListPOfCATVertex& oVertexList);

  // Conversion Geometry vers Edges
  static void GeomListToEdgeList(CATLISTP(CATGeometry)& iGeometryList, ListPOfCATEdge& oEdgeList);

  // Conversion Faces vers Geometry
  static void FaceListToGeomList(ListPOfCATFace& iFaceList, CATLISTP(CATGeometry)& oGeometryList);

  // Insertions sans duplication
  static void AppendWithoutDuplicates(ListPOfCATCell & ioCellList, const ListPOfCATCell & iAddList);
  static void AppendWithoutDuplicates(ListPOfCATEdge & ioEdgeList, const ListPOfCATEdge & iAddList);
  static void AppendWithoutDuplicates(ListPOfCATFace & ioFaceList, const ListPOfCATFace & iAddList);

  static void AppendWithoutDuplicates(ListPOfCATPersistentEdges & ioPEdgeList, const ListPOfCATPersistentEdges & iAddList);
  static void AppendWithoutDuplicates(ListPOfCATPersistentFaces & ioPFaceList, const ListPOfCATPersistentFaces & iAddList);

  //---------------------------------------------------------------------------
  // OUTILS GEOMETRIQUES ET VECTORIELS
  //---------------------------------------------------------------------------
  // CrvParam milieu d'une edge (edgecurve)
  static HRESULT GetEdgeMiddleECParam(CATEdge& iEdge, CATCrvParam& oMiddleParam);

  // SurParam milieu d'une edge
  static HRESULT GetEdgeMiddleSurParam(CATEdge& iEdge, CATSurface& iSurface, CATSurParam& oMiddleSurParam);

  // Calcul du vecteur matiere au milieu d'une edge
  static HRESULT GetInsideDirection(CATEdge& iEdge, CATFace& iBoundedFace, CATMathVector& oInsideDirection);

  //---------------------------------------------------------------------------
  // SERVICES DIVERS
  //---------------------------------------------------------------------------
  // Renvoie la liste des cellules issues d'un ordre de journal donne
  static void FilterCellsFromJournal(CATCGMJournalList&  iJournal,
                                     CATCGMJournal::Type iTypeToFilter,
                                     ListPOfCATCell&     oCells);

  // Renvoie la liste des cells issues d'un ordre de journal donne et d'un type de cell donne (edge, face, etc)
  static void GetResultCellsInJournal(CATCGMJournalList * ioCGMJournalList,
                                      CATLISTP(CATCell) & oResultCellsList,
                                      CATCGMJournal::Type iItemType = CATCGMJournal::None,
                                      CATGeometricType    iGeomType = CATCellType);

  // Renvoie la liste des faces de iWorkPBody qui sont issues d'iInitBody
  static void GetAncestorProjectionIntoBody(CATlsoPersistentContext& iContext,
                                            CATPersistentBody&       iInitPBody,
                                            CATPersistentBody&       iWorkPBody,
                                            ListPOfCATFace&          oFaces);

  // Renvoie une liste de faces ancetres, frere soeur ou descendant d'une face donnee
  static void GetRelativeFacesFromPBody(CATlsoPersistentContext & iContext,
                                        CATPersistentBody       & iPBody,
                                        CATFace                 & iFace,
                                        CATPersistentBody       & iOriginPBody,
                                        ListPOfCATFace          & oRelativeFaces);

  // Renvoie une liste de faces ancetres, frere soeur ou descendant d'une face donnee
  static void GetRelativeFacesFromPBody(CATlsoPersistentContext & iContext,
                                        CATPersistentBody       & iPBody,
                                        ListPOfCATFace          & iFaces,
                                        CATPersistentBody       & iOriginPBody,
                                        ListPOfCATFace          & oRelativeFaces);

  // Renvoie une liste de faces avec les memes parents qu'une liste de face donnée
  static void GetRelativeFacesFromPBodyWithSameParents(CATlsoPersistentContext & iContext,
                                                       CATPersistentBody       & iCurrentPBody,
                                                       CATPersistentBody       & iOriginPBody,
                                                       ListPOfCATFace          & iFaces,
                                                       ListPOfCATFace          & oRelativeFaces);

  // renvoie le vertex extremite de iEdge qui n'est pas iVertex
  static CATVertex* GetOtherVertex(CATEdge& iEdge, CATVertex& iVertex);

  // Renvoie la liste des faces bordees par une edge
  static void GetBorderedFaces(CATBody& iBody, CATEdge& iEdge, ListPOfCATFace& oFaces, CATBoolean iFilterFull = TRUE);

  // Renvoie la liste des faces bordees par une edge, version liste
  static void GetBorderedFaces(CATBody& iBody, ListPOfCATEdge& iEdges, ListPOfCATFace& oFaces, CATBoolean iFilterFull = TRUE);

  // Renvoie la liste des faces bordees par une edge, sur n bodies d'entree
  static void GetBorderedFaces(ListPOfCATBody& iBodies, CATEdge& iEdge, ListPOfCATFace& oFaces, CATBoolean iFilterFull = TRUE);

  // Renvoie la liste des faces bordees par une edge, sur n bodies d'entree, version liste
  static void GetBorderedFaces(ListPOfCATBody& iBodies, ListPOfCATEdge& iEdges, ListPOfCATFace& oFaces, CATBoolean iFilterFull = TRUE);

  // Renvoie la liste des faces bordees par les edges d'entree
  static void GetBorderedFaces(CATlsoPersistentContext& iContext,
                               CATPersistentBody&       iPBody,
                               ListPOfCATEdge&          iEdges,
                               ListPOfCATCell&          oBoundedFaces,
                               CATBoolean               iOnlyFreeBorderEdges,
                               CATBoolean               iFilterFull);

  // Recherche l'edge de "connexite" minimale dans une liste d'edges
  static int GetMinBorderedEdge(CATBody&        iBody,
                                ListPOfCATEdge& iEdges,
                                CATEdge*&       oMinEdge,
                                ListPOfCATFace& oMinBorderedFaces);

  // Recherche l'edge de "connexite" minimale dans une liste d'edges
  static void GetMinBorderedEdges(CATBody&               iBody,
                                  ListPOfCATEdge&        iEdges,
                                  ListPOfCATFace&        iDeadFaces,
                                  ListPOfCATEdge&        oMinEdges,
                                  ListPOfListPOfCATFace& oMinBorderedFaces);

  // Calcul de la liste des edges internes a un paquet de faces
  static void GetInternalEdges(ListPOfCATFace& iFaces, ListPOfCATEdge& oEdgeList);

  // Calcul de la liste des vertex internes a un paquet d'edges
  static void GetInternalVertices(ListPOfCATEdge& iEdges, ListPOfCATVertex& oVertexList);

  // Calcul de la liste des edges bord libre d'un paquet de faces
  static void GetExternalEdges(ListPOfCATFace& iFaces, ListPOfCATEdge& oEdgeList);

  // Calcul de la liste des edges bord libre d'un shell
  static void GetExternalEdges(CATShell& iShell, ListPOfCATEdge& oEdgeList);

  // Calcul de la liste des edges bord libre d'un body SURFACIQUE
  static void GetExternalEdges(CATBody& iBody, ListPOfCATEdge& oEdgeList);

  // Calcul de toute les edges d'un paquet de faces
  static void GetAllEdges(ListPOfCATFace& iFaces, ListPOfCATEdge& oEdgeList);

  // Calcul de toute les edges d'un shell
  static void GetAllEdges(CATShell& iShell, ListPOfCATEdge& oEdgeList);

  // Calcul de toute les faces d'un shell
  static void GetAllFaces(CATShell& iShell, ListPOfCATFace& oFaceList);

  // Liste des edges bord (libre) dans le body 
  // ZFC TODO a migrer vers getexternal ?
  static void GetFreeBorderEdges(CATBody& iBody, ListPOfCATEdge& oEdges);

  // Version PersistentInfra
  static void GetFreeBorderPersistentEdges( CATlsoPersistentContext   & iContext,
                                            CATPersistentBody         & iPBody,
                                            ListPOfCATPersistentEdges & oPEdges,
                                            CATBoolean                  iCreateUserPersistentEdges = FALSE );

  // Conversion d'une liste de CATPersistentBodies en liste de CATBody etant donne une CATPersistentCellInfra
  static void GetBodyListFromPersistentBodyList(CATlsoPersistentContext&    iContext,
                                                ListPOfCATPersistentBodies& iPBodyList,
                                                ListPOfCATBody&             oBodyList);

  // Calcul de la liste des faces adjacentes a une liste de faces donnee
  // Elle est capable de gerer l'adjacance par vertex (churchoid) et 
  // elle peut egalement gerer la propagation en tangence des faces adjacences si 
  // necessaire
  static void FindAdjacentFacesToListOfFaces(CATlsoPersistentContext&   iContext,
                                             CATPersistentBody&         iRefPBody,
                                             ListPOfCATPersistentFaces& iPFaces,
                                             ListPOfCATPersistentFaces& oNeighbourPFaces,
                                             CATBoolean                 iIncludeVertexAdjacency,
                                             CATBoolean                 iWithTangencyPropag,
                                             CATBoolean                 iWithDeclarativePropag=FALSE);

  // Version non persistante
  static void FindAdjacentFacesToListOfFaces(CATlsoPersistentContext&   iContext,
                                             CATBody&                   iRefBody,
                                             ListPOfCATFace&            iFaces,
                                             ListPOfCATFace&            oNeighbourFaces,
                                             CATBoolean                 iIncludeVertexAdjacency,
                                             CATBoolean                 iWithTangencyPropag,
                                             CATBoolean                 iWithDeclarativePropag=FALSE);

  // Partitionnage d'une liste de faces en peaux lisses
  static HRESULT PartitionIntoSmoothSkins(CATlsoPersistentContext& iContext,
                                          CATBody&                 iRefBody,
                                          ListPOfCATFace&          iRefFaces,
                                          ListPOfListPOfCATFace&   oSmoothSkins,
                                          CATBoolean               iWithDeclarativePropag=FALSE);

  // Propagation pour l'algo de selection de la reconstruction locale
  static void PropagateUntilStoppingEdges(CATBody&        iBody,
                                          ListPOfCATCell& iFacesToPropag,
                                          ListPOfCATCell* iAuthorizedFaces,
                                          ListPOfCATEdge& iStoppingEdges,
                                          ListPOfCATCell& oPropagatedFaces,
                                          ListPOfCATEdge* oStoppingEdgesEncountered = NULL);

  static void PropagateToShell(CATBody&        iBody,
                               ListPOfCATFace& iFaces,
                               ListPOfCATCell& oPropagatedFacesCL);

  // Propagation d'une edge à ses voisines smooth
  static HRESULT PropagateBorderSmooth(CATBody& iBody, CATEdge& iEdge, ListPOfCATEdge& oPropagatedEdges);

  // Evaluation de la valeur d'extrapolation necessaire pour un complementaire
  static CATLength RoughDistanceBetweenBodyAndFaces(CATBody& iBody, ListPOfCATFace& iFaces);

  // Calcul du centre et de la diagonale de la bounding box du modele
  static HRESULT GetBoundingSphereParameters(CATBody& iBody, CATMathPoint& oOrigin, double& oDiameter);

  // Evaluation de la valeur d'extrapolation necessaire pour une skin image
  static CATLength GetExtrapolationValueForImageSkin(CATBody& iBody);

  // Le persistent body est-il compose uniquement de shell fermes ?
  static CATBoolean IsPersistentBodyClosed(CATlsoPersistentContext & iContext,
                                           CATPersistentBody       & iPBody,
                                           short                     iClosedShellsOnly = 1);

  // Calcul de masse d'un persistent body
  static HRESULT ComputePersistentBodyMass( CATlsoPersistentContext & iContext,
                                            CATPersistentBody       & iPBody,
                                            double                  & oMass );

  // Comparaison de la masse de deux persistent bodies
  // +1 : Masse(body1) > Masse(body2)
  //  0 : Masse(body1) = Masse(body2)
  // -1 : Masse(body1) < Masse(body2)
  // -2 : Echec
  static int ComparePersistentBodyMass( CATlsoPersistentContext & iContext,
                                        CATPersistentBody       & iPBody1,
                                        CATPersistentBody       & iPBody2 );

  // Calcul de l'aire d'un body volumique ou surfacique
  static HRESULT ComputePersistentBodyArea( CATlsoPersistentContext & iContext,
                                            CATPersistentBody       & iPBody,
                                            double                  & oArea );

  // Le body est-il manifold pour la dimension N ?
  // c-a-d contient-il des cellules de dimensions N-1 bordant plus de deux cellules de dimension N.
  // En dimension 2 c'est l'edge bordant plus de deux faces.
  // En dimension 3 c'est la face bordant plus de deux volumes.
  // Note : la methode GetCellsHighestDimension de CATBody fait deja une verification de ce genre, mais 
  // le probleme est qu'elle se contente de faire la verification pour la dimension max du body. Par exemple,
  // pour un body volumique, elle va uniquement verifier les faces bordant plus de deux volumes, alors 
  // qu'on peut vouloir egalement verifier les edges bordant plus de deux faces.
  // C'est le but de cette methode : fournir un service qui permet de specifier la dimension.
  static CATBoolean IsBodyManifoldForDimN(CATBody&          iBodyToCheck, 
                                          short             iDimensionToCheck,
                                          ListPOfCATCell*   oManifoldCells = NULL,
                                          ListPOfCATCell*   oNonManifoldCells = NULL,
                                          CATListOfULONG32* oNonManifoldnessDegree = NULL);

  static CATBoolean IsListOfCellManifold(CATBody&          iBodyToCheck,
                                         ListPOfCATCell&   iCellsToCheck,
                                         ListPOfCATCell*   oManifoldCells = NULL,
                                         ListPOfCATCell*   oNonManifoldCells = NULL,
                                         CATListOfULONG32* oNonManifoldnessDegree = NULL);

  // Le persistent body est-il monoshell ?
  static CATBoolean IsBodyMonoShell(CATlsoPersistentContext& iContext, CATPersistentBody& iPBody);

  // Obtention d'une face commune aux deux bodies  
  static CATFace* FindCommonFaceBetween(CATBody& iBody, CATCellHashTable& iCHT);


  // Les surfaces sont-elles en confusion ?
  // 0 : non, 1 : surfaces identiques, 2 : surfaces confondues
  // iGeomRecogMode :
  // 0 : Comparaison des pointeurs sur GeometricReps
  // 1 : Comparaison geometrique sur canoniques uniquement (plan/cylindre/cone/tore)
  // 2 : Comparaison geometrique sur tout type de surface
  static short AreConfusedSurfaces(CATSurface * iSurf1, CATSurface * iSurf2, short iGeomRecogMode = 1, CATlsoContext * iContext = NULL);

  // Les surfaces sont-elles en confusion ?
  // 0 : non, 1 : surfaces identiques, 2 : surfaces confondues
  // iGeomRecogMode :
  // 0 : Comparaison des pointeurs sur GeometricReps
  // 1 : Comparaison geometrique sur canoniques uniquement (plan/cylindre/cone/tore)
  // 2 : Comparaison geometrique sur tout type de surface
  // 3 : Comparaison geometrique sur tout type de surface avec reconnaissance de canoniques
  static short AreConfusedSurfaces(CATlsoContext   & iContext,
                                   CATSurface     *  iSurfaces[2],
                                   CATSurLimits      iSurLimits[2],
                                   short             iGeomRecogMode=1);

  // Les faces se chevauchent-t-elles ?
  // 0 : non, 1 : oui
  // iGeomRecogMode :
  // 0 : Ne traiter que les faces ayant un fond geometrique commun
  // 1 : Reconnaissance de fonds geometriques en confusion sur canoniques uniquement (plan/cylindre/cone/tore)
  // 2 : Reconnaissance de fonds geometriques en confusion pour tout type de surface
  static short AreFacesOverlapping(CATlsoContext & iContext, CATFace & iFace1, CATFace & iFace2, short iGeomRecogMode = 0);

  // Intersecting bodies
  // 0 : non, 1 : oui
  static short AreBodiesIntersecting(CATlsoPersistentContext & iContext, CATPersistentBody * ipPBody1, CATPersistentBody * ipPBody2);

  // L'edge est-elle posee sur le body
  // 0 : non, 1 : oui
  static short ComputeConfusionEdgeBody(CATlsoPersistentContext & iContext, CATEdge & iEdge, CATBody & iBody);

  // Calcul de la box orientee oOrientedBox pour iPBody
  // iScale l'echelle appliquee a la boite initialement calculee 
  static HRESULT ComputeOrientedBoundingBox( CATlsoPersistentContext & iContext,
                                             CATPersistentBody       & iPBody,
                                             CATMathOBB              & oOrientedBox,
                                             double                    iScale = 1. );

  // Echantillonnage d'une face
  static HRESULT ComputeSamples( CATlsoContext     & iContext,
                                 CATFace           & iFace,
                                 CATSetOfSurParams & oSamples,
                                 CATLONG32           iNbSamplesUV = 5 );

  static HRESULT ComputeSamples( CATGeoFactory            & iFactory,
                                 CATSoftwareConfiguration & iConfig,
                                 CATFace                  & iFace,
                                 CATSetOfSurParams        & oSamples,
                                 CATLONG32                  iNbSamplesUV = 5 );

  // Calcul de position Point/Face 
  static CATLocation ComputePositionPtFace( CATlsoContext & iContext,
                                            CATFace       & iFace,
                                            CATSurParam   & iPoint,
                                            CATSurface    * iOriginSurface = NULL,
                                            double        * iProjTol = NULL );

  static CATLocation ComputePositionPtFace( CATGeoFactory             & iFactory,
                                            CATSoftwareConfiguration  & iConfig,
                                            CATFace                   & iFace,
                                            CATSurParam               & iPoint,
                                            CATSurface               *  iOriginSurface = NULL,
                                            double                   *  iProjTol =NULL );

  // Calcul de positions Point/Face sur une liste de points donnee
  static HRESULT ComputePositionPtFace( CATlsoContext     & iContext,
                                        CATFace           & iFace,
                                        CATSetOfSurParams & iPoints,
                                        CATSetOfSurParams & oPointsInsideFace,
                                        CATSurface        * iOriginSurface = NULL,
                                        double            * iProjTol = NULL );

  static HRESULT ComputePositionPtFace( CATGeoFactory             & iFactory,
                                        CATSoftwareConfiguration  & iConfig,
                                        CATFace                   & iFace,
                                        CATSetOfSurParams         & iPoints,
                                        CATSetOfSurParams         & oPointsInsideFace,
                                        CATSurface               *  iOriginSurface = NULL,
                                        double                   *  iProjTol = NULL );

  //---------------------------------------------------------------------------
  // APPEL D'OPERATEURS ET CREATION DE BODIES PERSISTANTS
  //----------------------------------------------------------------------------

  // Appel d'un operateur par le PersistentInfra avec edition du journal avant la creation des
  // persistent cells
  static CATPersistentBody* RunThroughInfraWithJournalEdition(CATlsoPersistentContext&       iContext,
                                                              CATTopOperator&                iOpeToBeRun,
                                                              CATlsoXTrimJournalEditCallback iCallback,
                                                              ListPOfCATPersistentBodies&    iInputPBodies,
                                                              CATCGMJournalList&             ioNewJournal);

  // Creation d'un Persistent Body a partir d'une liste de cellules (et d'un journal vide)
  static CATPersistentBody* CreatePersistentBodyFromCellPack( CATlsoPersistentContext & iContext,
                                                              CATPersistentBody       & iPBody,
                                                              ListPOfCATCell          & iCells,
                                                              int                       iCreateUserPEdgesMode = CATPersistentCellInfra::CreateNoUserPEdges );

  // Creation d'un Persistent Body a partir d'une liste de persistent faces
  // iCreateUserPEdgesMode : Creation des PEdges sur l'ensemble du body pour un meilleur suivi
  static CATPersistentBody* CreateExtractPersistentBody( CATlsoPersistentContext           & iContext,
                                                         CATPersistentBody                 & iPBody,
                                                         const CATLISTP(CATPersistentFace) & iListOfPersistentFaces,
                                                         int                                 iCreateUserPEdgesMode = CATPersistentCellInfra::CreateNoUserPEdges,
                                                         CATBoolean                          iRunCreateManifolds = FALSE );

  // Creation d'un Persistent Body a partir d'une liste de cellules a ENLEVER (et d'un journal vide)
  static CATPersistentBody* CreatePersistentBodyByRemovingCells( CATlsoPersistentContext & iContext,
                                                                 CATPersistentBody       & iInputPBody,
                                                                 ListPOfCATCell          & iFacesToRemoveCells,
                                                                 int                       iCreateUserPEdgesMode = CATPersistentCellInfra::CreateNoUserPEdges );

  // Creation d'un Persistent Body a partir d'un body existant
  static CATPersistentBody* CreatePersistentBodyFromBody(CATlsoPersistentContext& iContext,
                                                         CATPersistentBody&       iPBody,
                                                         CATBody&                 iExistingBody);

  // Creation d'une liste de bodies wire a partir d'une liste de persistent edges
  // NB: la liste oBodies est videe
  static HRESULT CreateWireFromPersistentEdgeList(CATlsoPersistentContext&    iContext,
                                                  CATPersistentBody&          iRefPBody,
                                                  ListPOfCATPersistentEdges&  iPEdges,
                                                  ListPOfCATPersistentBodies& oBodies);

  // Appel simplifie du MultiBodyMerger avec un PersistentContext
  // ATTENTION: Le compatible est appele en mode CVM (avec aretes FULL!!)
  static CATPersistentBody* MultiMergePersistentBodies(CATlsoPersistentContext&    iContext,
                                                       ListPOfCATPersistentBodies& iPBodies,
                                                       CATCGMJournalList*          oJournalToInsertInto = 0);

  // Appel simplifie du TopCompatible avec un PersistentContext
  static CATPersistentBody* CompatiblePersistentBodies(CATlsoPersistentContext&    iContext,
                                                       CATPersistentBody&          iPBody1,
                                                       CATPersistentBody&          iPBody2,
                                                       CATBoolean                  iUseCVMMode = TRUE,
                                                       CATCGMJournalList*          oJournalToInsertInto = 0,
                                                       CATBoolean                  iTryReverseCompatibleIfFailed = TRUE,
                                                       CATBoolean                  iUseCellTracker = FALSE);

  // Boucle de CompatiblePersistentBodies
  static CATPersistentBody* MultipleCompatiblePersistentBodies(CATlsoPersistentContext&    iContext,
                                                               ListPOfCATPersistentBodies& iPBodies,
                                                               CATCGMJournalList*          oJournalToInsertInto = 0,
                                                               CATBoolean                  iTryReverseCompatibleIfFailed = TRUE,
                                                               CATBoolean                  iUseCellTracker = FALSE);

  // Appel simplifie du HybAssemble avec un PersistentContext
  static CATPersistentBody* AssemblePersistentBodies(CATlsoPersistentContext    & iContext,
                                                     ListPOfCATPersistentBodies & iPBodies,
                                                     double                     * ipTolerance=NULL,
                                                     CATBoolean                   iVolumeCreation=FALSE);

  static CATPersistentBody* AssemblePersistentBodies(CATlsoPersistentContext  & iContext,
                                                     CATPersistentBody        & iPBody1,
                                                     CATPersistentBody        & iPBody2,
                                                     double                   * ipTolerance=NULL,
                                                     CATBoolean                 iVolumeCreation=FALSE);

  // Appel simplifie du RemoveFacesInShell avec un PersistentContext
  static CATPersistentBody* RemoveFacesInShellPersistent(CATlsoPersistentContext& iContext,
                                                         CATPersistentBody&       iInputPBody,
                                                         ListPOfCATCell&          iFacesToRemoveCells);

  // Appel simplifie du RemoveEdge avec un PersistentContext
  static CATPersistentBody * RemoveEdgePersistent(CATlsoPersistentContext & iContext,
                                                  CATPersistentBody       & iInputPBody,
                                                  ListPOfCATEdge          & iEdgesToRemove,
                                                  CATBoolean                iPartialResultAllowed=FALSE,
                                                  ListPOfCATEdge          * oTrickyEdges=NULL);

  // Appel simplifie du FuzzyExtrapol avec un PersistentContext
  static CATPersistentBody* FuzzyExtrapolatePersistentBody(CATlsoPersistentContext& iContext,
                                                           CATPersistentBody&       iInputPBody,
                                                           CATLength                iDefaultExtrapolationValue,
                                                           ListPOfCATEdge&          oCreatedEdges,
                                                           short                    iExtremitiesMode=0,
                                                           short                    iRemoveHoles=2);

  // Appel simplifie du FuzzyExtrapol avec un PersistentContext et edition du journal
  static CATPersistentBody* FuzzyExtrapolatePersistentBody2(CATlsoPersistentContext&       iContext,
                                                            CATPersistentBody&             iInputPBody,
                                                            CATLength                      iDefaultExtrapolationValue,
                                                            CATlsoXTrimJournalEditCallback iCallback,
                                                            ListPOfCATEdge&                oCreatedEdges,
                                                            ListPOfCATEdge*                oTrickyEdges=NULL,
                                                            CATBoolean                     iPartialAllowed=FALSE,
                                                            short                          iExtremitiesMode=0,
                                                            short                          iRemoveHoles=2);

  // Appel simplifie du FuzzyExtrapol avec un PersistentContext en specifiant les edges a extrapoler
  // et en recuperant les eventuelles edges bord qui ont ete crees
  static CATPersistentBody* FuzzyExtrapolatePersistentBody(CATlsoPersistentContext&   iContext,
                                                           CATPersistentBody&         iInputPBody,
                                                           ListPOfCATEdge&            iEdgesToExtrapolate,
                                                           CATListOfDouble&           iExtrapolationValues,
                                                           ListPOfCATEdge&            oCreatedEdges,
                                                           short                      iExtremitiesMode=0,
                                                           short                      iRemoveHoles=2);

  // Appel simplifie du FuzzyExtrapol avec un PersistentContext et edition du journal
  static CATPersistentBody* FuzzyExtrapolatePersistentBody2(CATlsoPersistentContext&       iContext,
                                                            CATPersistentBody&             iInputPBody,
                                                            ListPOfCATEdge&                iEdgesToExtrapolate,
                                                            CATListOfDouble&               iExtrapolationValues,
                                                            CATlsoXTrimJournalEditCallback iCallback,
                                                            ListPOfCATEdge&                oCreatedEdges,
                                                            ListPOfCATEdge*                oTrickyEdges=NULL,
                                                            CATBoolean                     iPartialAllowed=FALSE,
                                                            short                          iExtremitiesMode=0,
                                                            short                          iRemoveHoles=2);

  // Appel simplifie du HybSplit en mode shell avec un PersistentContext
  static CATPersistentBody* SplitPersistentBodies(CATlsoPersistentContext& iContext,
                                                  CATPersistentBody&       iPBodyToSplit,
                                                  CATPersistentBody&       iSplittingPBody,
                                                  CATHybSelectionMode      iSelectionMode);

  // Appel simplifie du HybSplit en mode shell with Keep/Remove avec un PersistentContext
  static CATPersistentBody* SplitPersistentBodiesWithKeepRemove(CATlsoPersistentContext & iContext,
                                                                CATPersistentBody       & iPBodyToSplit,
                                                                CATPersistentBody       & iSplittingPBody,
                                                                ListPOfCATCell          & iListOfCellsToKeep,
                                                                ListPOfCATCell          & iListOfCellsToRemove);

  // Appel simplifie du HybTrim en mode shell with Keep/Remove avec un PersistentContext
  static CATPersistentBody* TrimPersistentBodiesWithKeepRemove(CATlsoPersistentContext & iContext,
                                                               CATPersistentBody       & iPBodyToTrim1,
                                                               CATPersistentBody       & iPBodyToTrim2,
                                                               ListPOfCATCell          & iListOfCellsToKeep,
                                                               ListPOfCATCell          & iListOfCellsToRemove);

  // Appel simplifie du TopSimplify avec un PersistentContext
  static CATPersistentBody* SimplifyPersistentBody(CATlsoPersistentContext & iContext,
                                                   CATPersistentBody       & iInputPBody,
                                                   ListPOfCATCell          * iCellsToSimplify   = NULL,
                                                   ListPOfCATCell          * iCellsToRemove     = NULL,
                                                   CATBoolean                iMaxSimplification = FALSE);

  // Appel simplifie du CATTopXSimplif avec un PersistentContext
  static CATPersistentBody* SimplifySharpVertices(CATlsoPersistentContext & iContext,
                                                  CATPersistentBody       & iInputPBody,
                                                  ListPOfCATCell          & iVerticesToSimplify);

  // Appel simplifie du CloseOperator avec un PersistentContext
  static CATPersistentBody* ClosePersistentBody(CATlsoPersistentContext& iContext,
                                                CATPersistentBody&       iInputPBody);

  // Appel simplifie du CATHybConfusion avec un PersistentContext
  static CATHybConfusionDiagnostic ArePersistentBodiesConfused(CATlsoPersistentContext& iContext,
                                                               CATPersistentBody&       iPBody1,
                                                               CATPersistentBody&       iPBody2);

  // Appel simplifie du CATLayDownOperator avec un PersistentContext
  static HRESULT ComputeLayDown( CATlsoPersistentContext &  iContext,
                                 CATPersistentBody       &  iPBodyToLayDown,
                                 CATPersistentBody       &  iPBodySupport,
                                 CATPersistentBody       *& oLaidDownPBody );

  // Appel simplifie du CATTopClashOperator avec un PersistentContext
  static HRESULT ComputeClash( CATlsoPersistentContext &  iContext,
                               CATPersistentBody       &  iPBody1,
                               CATPersistentBody       &  iPBody2,
                               CATBoolean              &  oClashFound,
                               CATPersistentBody       ** oClashPBody = NULL );

  // Comparaison de l'evolution du cote matiere d'une face par rapport a son ancetre
  // Renvoie 1 si cotes matiere identiques, -1 si opposes, 0 si impossible a determiner
  static int CompareMatterSide(CATFace & iCurrentFace, CATBody & iCurrentBody, CATFace & iPreviousFace, CATBody & iPreviousBody);

  // -----------
  // AutoCheck
  // -----------
  // Return isValid
  static CATBoolean CheckAutoIntersections(CATPersistentBody       * iResultPersistentBody,
                                           CATPersistentBody       * iInputPersistentBody,
                                           CATlsoPersistentContext & iContext,
                                           ListPOfCATCell          * oInvalidIntersectionCells = NULL,
                                           CATBoolean                iExhaustiveCheck = FALSE,
                                           ListPOfCATFace          * iResultFaceListFilter = NULL);

private:
  static HRESULT PropagateHelper(CATBody& iBody, CATEdge& iEdge, CATVertex& iVertex, ListPOfCATEdge& oPropagatedEdges);

  // Creation d'un operateur fuzzy extrapol avec les options communes pour XTrim
  static CATFuzzyExtrapolOpe* CreateFuzzyExtrapolOpeForXTrim(CATlsoPersistentContext& iContext,
                                                             CATPersistentBody&       iInputPBody,
                                                             CATTopData&              iTopData,
                                                             CATBoolean               iPartialAllowed,
                                                             short                    iExtremitiesMode,
                                                             short                    iRemoveHoles);

  static CATBoolean IsAPlane( CATlsoContext & iContext, CATSurface * iSurface, const CATSurLimits & iSurlimits, CATMathPlane * oPlaneData = NULL );

  static CATBoolean IsACone( CATlsoContext & iContext, CATSurface * iSurface, const CATSurLimits & iSurlimits, double * oAngle = NULL, CATMathAxis * oAxis = NULL );
};

#endif /* CATlsoXTrimUtil_H */
