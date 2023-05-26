//
//============================================================================================
// Copyright Dassault Systemes Provence 2010 - 2011 All Rights Reserved
//============================================================================================
//
// CATPolyP2D_RecognizeFilletV_2.h
// Header definition of CATPolyP2D_RecognizeFilletV_2
//
//============================================================================================
//
// Usage notes: Utilitaires sur les PolyMesh n'existant pas dans la version officielle
//              On doit pouvoir les transferer normalement sans souci particulier a CGM
//
//============================================================================================
// 15/10/2010 : GDD : Creation
//============================================================================================
#ifndef CATPolyP2D_RecognizeFilletV_2_H
#define CATPolyP2D_RecognizeFilletV_2_H

class CATIPolyMesh ;
class CATIPolyFactory ;
class CATPolyGeometricForm ;

class CATPolyP2D_QuadricOper ;
class CATMathPoint ;
class CATMathVector ;

//#define DEBUG_A_GDD
#ifdef DEBUG_A_GDD
    #include "CATLib.h"
    #include <iostream.h>
    #include "CATStdIO.h"
#endif

#include "CATBoolean.h"
#include "CATMath.h"

// Pour l'intersecteur par un plan
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CATMathPlane.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"

// Quelque definition des erreurs standards
/*
SANS_STATUS                            9000001
PARTIE_A_IMPLEMENTER                   9000002
ALLOC_MEMORY                           1000001
POINTEUR_NULL                          1000002
POLYMESH_INCONSISTANT                  9001000
PB_SORTIE_ALGO_POLYMESH                9001001
ITERATEUR_VERTEX_ALGO_POLYMESH         9001002
ITERATEUR_TRIANGLE_ALGO_POLYMESH       9001003
POLYMESH_NON_COMPACT                   9001004
NUMERO_DE_VERTEX_INCOHERENT            9001005
PAS_ASSEZ_DE_SECTIONS_POUR_STATS       9001006  Ou ce peut etre un plan
PB_INSERT_MAP                          9001007
*/

#include "CATPolyCanonicOperators.h"
#include "CATPolyP2D_StructureSection.h"

class ExportedByCATPolyCanonicOperators CATPolyP2D_RecognizeFilletV_2

{
public:

  // Standard constructors and destructors
  // -------------------------------------
  // On passe le PolyMesh et la liste des triangles qui constituera le Sub_Mesh sur lequel on va travailler

  CATPolyP2D_RecognizeFilletV_2 (CATIPolyMesh * iPolyMesh, CATListOfInt LstIdxTri);
  virtual ~CATPolyP2D_RecognizeFilletV_2 ();

  // <GDD_1>
  // Pour imposer le rayon de reconnaissance du fillet
  // Dans ce cas on est plus restrictif que sans imposer le Rayon.
  // Sans imposer le rayon, on accepte que des points (statistiquement) soient en dehors du fillet dont on determine
  // le rayon. Ces points ne sont pas pris en compte, (sinon on ne trouverai pas beaucoup de fillet sur les zones
  // que l'on analyse). Ceci revient a dire qu'une meme zone sera donnee en fillet si le rayon n'est pas impose et 
  // refusee en imposant le meme rayon en raison meme que certains points sont abberrants.
  // Il pourrait etre envisage (a developper) de detecter les sommets (triangles) d'une zone donnee et pour un rayon donné qui ne 
  // contribuent pas ou mal a la detection du fillet.
  // Rayon : Si <= 0 => Pas d'effet (defaut = 0)
  // TolPourcen : Tolerance accecpte entre un rayon calcule et rayon vise  Q = 100 * Abs(Rc - RV) / Rv
  void SetRayon (double Rayon, double TolPourcent);
  // >GDD_1<

  // Recuperation de l'erreur
  int GetError();

  // Activation du retour des points de section
  // L'appel de cette fonction doit etre fait avant le Run(), utile uniquement pr le debug
  // Ces infos supplementaires sont mises dans la structure des resultats
  void SetReturnPointSection();

  // Recherche d'un fillet
  HRESULT Run();

  // Pour recuperer les resultats
  // LstTriKO si non vide contient la liste des triangles a mettre ailleurs pour avoir un meilleur resultat
  // Elle est en relation etroite avec la liste des triangles constituant le Sub_Mesh LstIdxTri du constructeur
  // EX : LstTriKO contient 2 valeurs LstTriKO[1] = 12 et LstTriKO[2] = 17 
  //      Ceci veut dire que les triangles a enlever sont LstIdxTri[12] et LstIdxTri[17]
  HRESULT GetInfoFillet(CATPolyGeometricForm * &FormResul);
  HRESULT GetInfoFillet(CATPolyGeometricForm * &FormResul, CATListOfInt &LstTriKO);
  HRESULT GetInfoFillet(double &Rayon, double &ErrQua, double &RayMin, double &RayMax);

  // Pour recuperer l'angle max du Fillet (en radian)
  // Si angle negatif, pas de calcul effectue
  HRESULT GetAngleFillet(double &oAngle);

  // Recuperation d'un pointeur vers la structure des resultats, ne pas detruire
  //HRESULT GetPtrStructureSection (int &NbrSection, SectionOnVertex * &ResultSection, int &NbOnlyComputed);
  HRESULT GetPtrStructureSection (int &NbrSection, SectionOnVertex * &ResultSection);

private:

  // Qualification d'un Fillet en fonction du rayon / Longueur MinMax des aretes des triangles
  // LstTriKO est une liste de triangles qui sont a supprimer pour avoir un meilleur fillet
  // Si cette liste est vide, le fillet est OK
  // En retour si FLASE le fillet n'est pas bon
  CATBoolean QualificationFillet (double Rayon, CATListOfInt & LstTriKO);

  // Calcul de la distance carree d'un point a un segment
  // si la projection ne tombe pas a l'interieur du segment, 
  // renvoi la distance du point a une extremite (la + pres)
  // ---------------------------------------------------------------------------
  // Projection orthogonale du point M sur le segment oriente [P1P2]
  // H = Projete orthogonal de M sur [P1P2]
  // MH = vecteur MH
  // lambda = P1M/P1P2  =>      lambda < 0  H est a gauche de [P1P2]
  //                                  0 <  lambda < 1  H est a l'interieur de [P1P2] 
  //                                          lambda > 1    H est a droite de [P1P2]
  //                                          lambda = 0      H = P1
  //                                          lambda = 1      H = P2
  // ---------------------------------------------------------------------------
  double Dist2_Pnt_Seg (const CATMathPoint & M, const CATMathPoint & P1, const CATMathPoint & P2, CATMathPoint & H, double & Lambda);

  // Cherche la canonique satisfaisant une erreur quadratique inferieure a une tolerance donnee
  // QualiteResult : comprise de 0 a 100 indique la qualite du resultat 
  // TypeCanon : Indicateur de typre de resultat
  //          =  0  Pas de resultat trouve
  //          = 10 --> plan, 11 --> sphere, 12 --> cylindre regulier, 13 --> cone regulier 
  // Error[0] : ErreurMax
  // Error[1] : ErreurMoyenne
  // Error[2] : ErreurQuadratique
  // Error[3] : EcartType
  // Retour   =  0 : Resultat OK satisfaisant la critere
  //          = -1 : Pas de resultat satisfaisant le critere mais on rend le meilleur. La qualite peut etre OK
/*
           +----------+------------+--------------+------------+
           | Plan 10  |  Sphere 11 |  Cylindre 12 |   Cone 13  |
   +-------+----------|------------|--------------|------------|
   |Rayon1 |          |  ******    |    ********  |   ****     |          
   +-------+----------|------------|--------------|------------|
   |Rayon2 |          |            |              |   ****     |
   +-------+----------|------------|--------------|------------|
   |Hauteur|          |            |  ********    |   ****     |
   +-------+----------|------------|--------------|------------|
   |Centre |          |  ******    |  ********    |   ****     |
   +-------+----------|------------|--------------|------------|
   |Normale| *******  |            |  ********    |   ****     |
   +-------+----------+------------+--------------+------------+
   |Angle/2|          |            |              |   ****     |
   +-------+----------+------------+--------------+------------+
*/

  int Eval_Canonic_On_Polygon(CATIPolyMesh * MyPolyMesh, 
                          int &QualiteResult, int &TypeCanonic, 
                          double Error[4],
                          double &Rayon1, double &Rayon2, double &Hauteur, 
                          CATMathPoint &Centre, CATMathVector &Normale, double &DemiAngle);
  
  // Fonction permettant d'associer une section deja calcule a iVtx lorsque 
  // l'on considere celui-ci comme assez proche afin d'optimiser les temps de calculs
  // Retourne TRUE si une section a ete attribue au vertex FALSE sinon
  CATBoolean IsSectionComputed(int iVtx, double &oRayon);

  // -----------------------
  // Les champs de la classe
  // -----------------------

  CATIPolyFactory       * _MyPolyFactory;           // La polyFactory de creation
  CATIPolyMesh          * _MyPolyMesh;              // Il est compacte, plus besoin d'iterateur pour le defiler
 
  CATBoolean              _MeshOK;                  // Indicateur si l'on peut travailler
  int                     _Error;                   // La valeur de l'erreur    (GerError)
  int                     _NbrVtx, _NbrTri;         // Nb Vertex et Nb Triangles de _MyPolyMesh

  CATIPolyMesh          * _MyPolyMeshOrig;          // Il est compacte, le PolyMesh d'origine
  int                     _NbrVtxOrig, _NbrTriOrig; // Nb Vertex et Nb Triangles du PolyMesh d'origine

  CATPolyGeometricForm   * _FormResul;            // Contient la forme des resultats
  // <GDD_1>
  double                   _RayonImpose;       
  double                   _TolPourcent;
  double                   _LgnMaxMin;            // Maximun des minimum des longueurs d'arete des triangles
  double                 * _TabLngMax;            // Table associee a chaque triangle donnant le min d'arete
  CATListOfInt             _LstTriangleKO;        // Liste des triangles KO pour un fillet declare OK
  // >GDD_1<

  double                   _RayonFillet;
  double                   _ErrQuaFillet;
  double                   _RayonMin, _RayonMax;
  double                   _SeuilEcartType;       // Pour invalider les cercles de rayon abberrants
  double                   _SeuilRayon;           // Pour invalider tout si le rapport Q=(Rmax-Rmin)/Rmoy > Seuil
  double                   _PourSelect;           // Pourcentage de selection d'une classe (75%)
  double                   _QuoEvolution;         // Facteur de multiplcation pour resserrer les contraintes

  // Pour continuer 
  int                      _MinTrianglesInMesh;   // Nombre min de triangles pour travailler (6)
  //int                      _MinVerticesInMesh;    // Nombre min de triangles pour travailler (6)
  double                   _MinArea;              // Minimum de surface pour travailler (0.01)
  double                   _AreaPolyMesh;         // Aire du PolyMesh
  int                      _MaxGlobalVertex;      // Au dela, on en prend un sur ...
  CATBoolean               _Interpolation_PNT;    // On interpole avec les normales ou Lineairement

  // La table des structures des sections. Il ne pourra y en avoir que le nombre de sommets au maximum.
  // Rem : La numerotation va de 1 a ..., la position 0 n'est pas utilisée volontairement
  SectionOnVertex        * _TabSectionOnVertex;  
  int                      _NbrOK;                // Nombre de section OK
  CATBoolean               _ReturnLstPoint;       // Retour ou non des points de section pour le debug
  double                   _AngleMax;             // Angle maximum du fillet
  CATBoolean               _AllSectionComputed;   // Si TRUE, on regarde si une section pres existe deja
};

#endif
