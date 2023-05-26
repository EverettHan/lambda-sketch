//
//============================================================================================
// Copyright Dassault Systemes Provence 2011, All Rights Reserved
//============================================================================================
//
// CATPolyP2D_FilletSegmentation_C4R.h
// Header definition of CATPolyP2D_FilletSegmentation_C4R
//
//============================================================================================
//
// Usage notes: Utilitaires sur les PolyMesh n'existant pas dans la version officielle
//              On doit pouvoir les transferer normalement sans souci particulier a CGM
//
//============================================================================================
// 15/10/2010 : C4R : Creation
//============================================================================================
#ifndef CATPolyP2D_FilletSegmentation_C4R_H
#define CATPolyP2D_FilletSegmentation_C4R_H

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
#include "CATHTableOfIntToInt.h"
#include "CATMapOfIntToInt.h"

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
NUMERO_DE_TRIANGLE_INCOHERENT          9001008
*/

#include "CATPolyCanonicOperators.h"
#include "CATPolyP2D_RecognizeFilletV_2.h"
#include "CATPolyP2D_StructureSection.h"

// -------------------------------------------------------------
// Definition de la structure de donnees pour un section du Mesh
// On recupere un pointeur vers la table des structures avec un 
//                 GetPtrStructureSection
// -------------------------------------------------------------

class ExportedByCATPolyCanonicOperators CATPolyP2D_FilletSegmentation_C4R

{

public:

  // Standard constructors and destructors
  // -------------------------------------
  // On passe le PolyMesh et la liste des triangles qui constituera le Sub_Mesh sur lequel on va travailler

  CATPolyP2D_FilletSegmentation_C4R (CATIPolyMesh * iPolyMesh, CATListOfInt LstIdxTri, int IdxTriSeed);
  virtual ~CATPolyP2D_FilletSegmentation_C4R ();

  // Recuperation de l'erreur
  int GetError();

  // L'appel de cette fonction doit etre fait avant le Run(), utile uniquement pr le debug
  // Ces infos supplementaires sont mises dans la structure des resultats
  void SetReturnPointSection();

  // Recherche d'un fillet
  HRESULT Run();

  // Pour recuperer les resultats
  HRESULT GetInfoFillet(CATPolyGeometricForm * &FormResul);
  HRESULT GetInfoFillet(double &Rayon, double &ErrQua, double &RayMin, double &RayMax);

  // Pour recuperer l'angle max du Fillet (en radian)
  // Si angle negatif, pas de calcul effectue
  HRESULT GetAngleFillet(double &oAngle);

  // Test si un triangle peut etre utilise pour le calcul selon different criteres
  // CodeRet = 0 : OK
  // CodeRet = 1 : triangle sans information
  // CodeRet = 2 : angle entre les normales des triangles > _MinAngleTri
  // CodeRet = 3 : deviation entre les triangles > _MaxAngleDev
  // ----------------------------
  // IdxTriRef : triangle de reference et sa normale Nor1 
  // IdxTriTest : triangle de test et sa normale Nor2
  HRESULT UseToCompute(int IdxTriRef, CATMathVector &Nor1, int IdxTriTest, CATMathVector &Nor2, int &CodeRet);

  // Test si un vertex peut etre mis en attente
  // CodeRet = 0 : NON
  // CodeRet = 1 : OUI
  // CodeRet = 2 : OUI et on peut en plus l utiliser pour propager car testMiniDeviation OK
  // -----------------------------
  // NumVtx : vertex a tester
  // NumVtxBase1 et NumVtxBase2 constitue la bar de propagation
  // testMiniDeviation : permet de tester une deviation mini
  HRESULT UseToWait(int NumVtx, int NumVtxBase1, int NumVtxBase2, CATBoolean testMiniDeviation, int &CodeRet);

  // Recuperation d'un pointeur vers la structure des resultats, ne pas detruire
  //HRESULT GetPtrStructureSection (int &NbrSection, SectionOnVertex * &ResultSection, int &NbOnlyComputed);
  HRESULT GetPtrStructureSection (int &NbrSection, SectionOnVertex * &ResultSection);

  // Creation de la liste contenant les indices des triangles segmente
  void GetSegmentedTriangle (CATListOfInt &LstOfTri);


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
  CATBoolean               _ReturnLstPoint;       // Retour des points de section pour le debug
  double                   _AngleMax;             // Angle maximum du fillet

  // ------------ Nouveaux champs pour la propagation -------------- //

  int                      _IdxTriSeed;               // Indice du triangle pour la propagation

  CATHTableOfIntToInt      _HTableVtx;  
  // 1 : vtx OK
  // 2 : vtx KO
  // 3 a 6, en attente
  CATHTableOfIntToInt      _HTableTri;  
  // 0 : en cours d'utilisation
  // 1 : vtx OK
  // 2 : vtx KO
  // 3 : en attente
  double                   _MinAngleTri;          // Angle min entre deux triangles voisins
  double                   _MaxAngleDev;          // Angle maximum de deviation entre deux triangle voisins

  CATHTableOfIntToInt      _MapVtxToSec;          // Map qui associe un vtx a son numero de section
  double                   _ToleranceRayon;       // % d ecart de rayon
  double                   _DomaineRayon;         // Domaine de validite du rayon (RayMoy * _ToleranceRayon)
};

#endif
