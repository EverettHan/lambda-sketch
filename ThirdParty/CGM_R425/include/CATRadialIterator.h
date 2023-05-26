#ifndef CATRadialIterator_H
#define CATRadialIterator_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//=========================================================================
// Iterateur radial autour d'un sommet d'un body manifold homogene de
// dimension 2 (skin) ou 3 (volume)
//=========================================================================

#include "Thick.h"
#include "CATTopDef.h"
#include "CATMathInline.h"

#ifndef NULL
#define NULL 0
#endif
class CATBody;
class CATDomain;
class CATCell;
class CATVertex;
class CATEdge;
class CATFace;
class CATBoundedCellsIterator;
class CATCGMOutput;
class CATSoftwareConfiguration;
class CATVertexIterator;

#include "CATIACGMLevel.h"
#ifdef CATIACGMV5R22
class CATRadialIterator {
#else
class ExportedByThick CATRadialIterator {
#endif
  
public:
  
  // On definit un type de fonction globale acceptant une CATEDge et un void*
  // contextuel qui rende un short = 1 si l'arete est morte, 0 sinon
  typedef short (* CATTopIsSmooth) (CATEdge * iEdge, void * iContextData);

  // UTILISER LA METHODE CATCreate avec SoftwareConfig
  // NE PAS UTILISER DIRECTEMENT LE CONSTRUCTEUR
  // Methode Safe.
  // On peut donner au constructeur un pointeur sur une fonction donnant la
  // vivicite de maniere plus performante que si elle est recalculee, cette
  // fonction (de type CATTopIsSmooth) peut prendre en argument un void*
  // qui permette d'adresser des donnees auxiliaires pour retrouver la vivicite
  // Ce void* doit alors etre donne (en dernier argument) au constructeur ci-dessous
  static CATRadialIterator * 
    CATCreateRadialIterator(CATSoftwareConfiguration * iConfig, 
                            CATVertex * iVertex, CATBody * iBody,
												    CATTopIsSmooth iIsSmoothFunction = 0, void * iContextData = 0, 
                            CATDomain *iDomain=NULL, int iStabilizeMode=0);

  // destructeur
  ~CATRadialIterator();

  // infos
  // un secteur est une sequence radiale maximale sans arete vive interne
  // les numeros de secteurs vont de 1 a GetNSectors()
  int GetNSectors(CATDomain * iDom, int iNum);
  int GetNFacesInSector(CATDomain * iDom, int iNum, int iSector);
  
  int GetNSharp(CATDomain* iDom, int iNum);

  // IsOnBorder permet de savoir si le sommet central est bord de skin ou pas
  short IsOnBorder(CATDomain * iDom, int iNum);

  CATVertex *&  GetVertex();

  // scan des sous-manifolds
  // (les numeros de sous-manifolds iNum commencent varient de 1 a oNbManif)
  CATDomain * NextDomain(CATDomain* iPrev, int& oNbManif);
  
  // Les 6 methodes qui suivent (a savoir 4 methodes de scan: NextFace, NextEdge,
  // LastEdge, NextFaceInSector, et 2 methodes d'interrogation: GetBorderEdges et
  // GetAdjFaces) ne balayent pas reellement des edges et des faces, mais des
  // demi-edges (edges + side de l'edge par rapport au sommet central) et des
  // secteurs sur les faces, caracterises par 1 face, 1 demi-edge qui la borde,
  // et le side de la face par rapport a cette demi-edge. Ces precisions permettent
  // d'etendre le champ de l'iterateur radial aux situations ou une frontiere de
  // face n'est pas 1-manifold (aretes en tenaille, plusieurs secteurs incidentes
  // au sommet sur la meme face) et aux aretes en boucle, avec un seul sommet
  // extremite "deux fois" incident a l'arete.

  // L'iterateur stocke le contexte d'iteration (dernier Next effectue), aussi il
  // suffirait d'une methode Next() sans arguments pour iterer, et de methodes Get()
  // pour recuperer les infos sur l'iteration courante, mais pour rester compatible
  // avec les signatures des methodes deja exposees, on continue a accepter des
  // arguments "iPrev" ou "iNext" qui sont senses donner en entree ce contexte, mais
  // qui sont incomplets si une face a un bord non-manifold. Cela conduit au
  // compromis suivant:

  // Il y a 2 manieres d'utiliser les methodes d'iteration:

  // Soit au sein d'une iteration globale, et les arguments d'entree (iPrev, ou
  // iNext) de ces methodes sont en fait inutiles. Les methodes en question se
  // contentent de verifier qu'ils sont conformes a ce qu'a rendu l'iteration
  // precedente. On a rendu ces arguments optionnels (sauf pour NextFaceInSector
  // car on ne saurait alors pas distinguer un debut de scan de nouveau secteur)

  // Soit pour explorer de maniere anarchique les voisins d'une face ou arete, avec
  // un iterateur vierge (ou un iterateur dont le contexte intrinseque ne correspond
  // pas aux faces ou aretes injectees en entree). Les iPrev ou iNext donnes en
  // entree sont alors utilisees, mais l'iterateur s'arrete a la 1e occurrence de
  // la face ou arete incriminee, ce qui rend impossible toute recherche autour d'une
  // occurrence qui ne serait pas la 1ere, dans un contexte non manifold (une bonne
  // solution consiste a toujours modeliser la face ou arete qui delimite le secteur
  // concerne par son numero d'iteration et non pas par la face ou arete elle-meme)

  // Remise a zero de l'iterateur: on garde le meme sommet central, mais on
  // s'apprete a re-iterer sur tous les secteurs
  void Reset();

  void ResetAll();

  // Scan des faces : iPrev=NULL si 1ere, face rendue = NULL si derniere
  // Les 2 edges rendues a la fin (si oBorders non nul en entree) sont les
  // edges qui encadrent radialement la face rendue
  // si iSharpOnly, on ne s'arrete que sur les faces qui suivent des aretes vives
  CATFace * NextFace(CATDomain* iRef, int iNum, CATFace* iPrev=0,
		     short iSharpOnly=0, int iNbSkips=0, CATEdge ** oBorders=NULL);

  // Scan des demi-edges: iPrev=NULL si 1ere, edge rendue = NULL si derniere
  // si iSharpOnly, on ne s'arrete que sur les aretes vives
  // On considere toujours que le secteur "courant" est celui qui suit, dans
  // l'ordre d'Ampere, la demi-edge courante
  CATEdge * NextEdge(CATDomain* iRef, int iNum, CATFace *iPrev = 0,
                     short iSharpOnly = 0, int iNbSkips = 0,
                     CATSide * oEdgeSideVsVertex = 0,
                     CATFace * iOtherFace=0);

  // scan d'un secteur mort d'un sous manifold (iSector va de 1 a n)
  // memes remarques que pour NextFace, mais iPrev doit obligatoirement etre
  // fourni si on ne commence pas a iterer sur un secteur mort
  CATFace * NextFaceInSector(CATDomain* iRef, int iNum, int iSector,
                             CATFace* iPrev, CATEdge ** oBorders = NULL);

  // Lecture du CATSide de la demi-arete courante (precedant la face du
  // secteur courant) par rapport au sommet central
  CATSide GetSideVsCentralVertex();

  // Lecture de la demi-arete courante (precedant le secteur courant), et
  // eventuellement du side de la face courante par rapport a elle (si le
  // pointeur oFaceSideVsEdge est non nul).
  // Si la face iNext est specifiee et que ce n'est pas la face courante, on
  // va lire l'arete precedant la 1ere occurrence trouvee de iNext, qui devient
  // le secteur courant
  CATEdge * LastEdge(CATDomain* iRef, int iNum, CATFace *iNext=0,
                     CATSide * oFaceSideVsEdge=0,
                     CATSide * oEdgeSideVsVertex=0);

  // Lecture des 2 aretes encadrant la face du secteur courant (ou la 1ere
  // occurrence d'une face donnee si elle est differente de la face courante).
  // On rend les CATSides des aretes oBorders vis a vis de la face iCurFac
  // oBorders[] est ordonne dans le sens d'Ampere ([0] avant [1])
  void GetBorderEdges(CATDomain* iRef, int iNum, CATFace* iCurFac, 
                      CATEdge * oBorders[2], CATSide oEdgFacSides[2]);

  // Lecture des faces bordant la demi-arete courante (celle qui precede le
  // secteur courant), ou la 1e occurence d'une arete donnee si elle est
  // differente de la demi-arete courante.
  // oBorders[] est ordonne dans le sens d'Ampere ([0] avant [1])
  // oEdgFacSides[k] = side de iCurEdge sur oBorders[k]
  // si iCurEdge est bord de skin (lame de rasoir), l'une des 2 faces
  //    rendues est NULL et le side associe sera CATSideUnknown
  void GetAdjFaces(CATDomain* iRef, int iNum, CATEdge * iCurEdge,
                   CATFace * oBorders[2], CATSide oEdgFacSides[2]);

  // dump (pour debug)
  friend ExportedByThick CATCGMOutput& operator<< (CATCGMOutput& s, const CATRadialIterator& iter);

private:

  // constructeur (a remplacer par un CreateVertexIterator dans CATVertex.h)
  // en private, pour forcer le passage par la methode statique CreateRadialIterator()
  // On peut donner au constructeur un pointeur sur une fonction donnant la
  // vivicite de maniere plus performante que si elle est recalculee, cette
  // fonction (de type CATTopIsSmooth) peut prendre en argument un void*
  // qui permette d'adresser des donnees auxiliaires pour retrouver la vivicite
  // Ce void* doit alors etre donne (en dernier argument) au constructeur ci-dessous
  CATRadialIterator(CATSoftwareConfiguration * iConfig, CATVertex * iVertex, CATBody * iBody,
                    CATTopIsSmooth iIsSmoothFunction = 0, void * iContextData = 0, CATDomain *iDomain = NULL, int iStabilizeMode=0);


  // sous-programme de CreateRadialIterator()
  // Initialize() prepare tout le travail en construisant une liste de cellules alternees
  // (_List) de types edge, face, edge, face, .. en commencant par edge
  // et en finissant par edge si 2 bords libres, par face si aucun.
  // La liste _SideList[] est parallele a _List :
  //       edge 0   side 0/1
  //       face 1   side 2/1
  //       edge 2   side 2/3
  //       face 3   side 4/3 
  //       edge 4   side 4/5
  //         etc..  etc..
  //
  //  Renvoie 1 si OK, 0 si KO
  short Initialize(short icheckNonManifold=0);

  // Nettoyage memoire
  void Clean();

  // scan radial direct sur le tableau _List (les rangs commencent en 1)
  int NextEdgeRange(int initRange, short iSharpOnly=0);

  // Utilitaire diagnostiquant l'appartenance d'une cellule a un domaine dont
  // la dimension n'est pas forcement celle de la cellule (en attendant que RAD
  // rende CATDomain::Owns() recursif. Rend 1 si iCell est dans iDom, 0 sinon
  int IsCellInDomain(CATCell * iCell, CATDomain * iDom, CATBody * iBody=NULL);

  // ----------------------------------------------------------------------------
  // Donnees
  CATSoftwareConfiguration * _Config;
  CATBody     * _Body;
  CATDomain   * _Domain;
  CATVertex   * _Vertex;
  CATBoundedCellsIterator * _edgIter;
  CATVertexIterator *_newEdgIter;

  int          _StabilizedMode;
  
  // _List alterne: edge, face, edge, face.. et se termine par une edge si le
  // sommet est bord de skin (_Ncells impair), ou une face sinon (_Ncells pair)
  CATCell    ** _List;

  // _SideList[2*k et 2*k+1] = sides de la face _List[2*k+1] par rapport aux
  // aretes qui la bordent : _List[2*k] et _List[2*k+2 modulo _Ncells]
  // L'ultime valeur _SideList[_Ncells-1] n'a pas de signif. si _Ncells impair
  CATSide     * _SideList;

  int           _Ncells; // nb cellules incidentes =taille de _List & _SideList

  // _Viv[k] = vivicite de l'arete _List[2*k] = 0(mort), 1(vif), 2(bdskin)
  int         * _Viv;

  // _VtxSideList[k] = side de l'arete _List[2*k] par rapport au sommet concerne
  // par l'iterateur (sert a discriminer les 2 occurences d'une arete en boucle)
  // La taille commune a _VtxSideList et a _Viv est (1+_NCells)/2
  CATSide     * _VtxSideList;

  short         _Full; // 0 si secteur delimite par 2 bords libres, 1 sinon
  
  int           _NSharp;   // nb total d'aretes vives, bords libres exclus
  int           _NSectors; // nb de secteurs radiaux G1 entre 2 vives/ b.libres

  // Contexte de la derniere iteration effectuee (-1 apres construction ou Reset())
  int           _CurEdgeIndex;

  // On stocke la fonction de calcul rapide de vivicite et son contexte,
  // s'il y en a une
  CATTopIsSmooth _IsSmoothFunction;
  void        *  _IsSmoothContext;

};

#endif





