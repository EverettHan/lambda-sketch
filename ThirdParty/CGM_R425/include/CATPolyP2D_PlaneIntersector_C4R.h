//
//============================================================================================
// Copyright Dassault Systemes Provence 2010, All Rights Reserved
//============================================================================================
//
// CATPolyP2D_PlaneIntersector_C4R.h
// Header definition of CATP2DPoly_IntersectorPlane
//
//============================================================================================
//
// Usage notes: Utilitaires sur les PolyMesh n'existant pas dans la version officielle
//              On doit pouvoir les transferer normalement sans souci particulier a CGM
//
//============================================================================================
// 15/10/2010 : GDD : Creation
//============================================================================================
#ifndef CATPolyP2D_PlaneIntersector_C4R_H
#define CATPolyP2D_PlaneIntersector_C4R_H

class CATIPolyMesh ;

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
*/

#include "CATPolyCanonicOperators.h"

class ExportedByCATPolyCanonicOperators CATPolyP2D_PlaneIntersector_C4R
{

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPolyP2D_PlaneIntersector_C4R (CATIPolyMesh * iPolyMesh);
  virtual ~CATPolyP2D_PlaneIntersector_C4R ();

  // Recuperation de l'erreur
  int GetError();

  // Pour setter la tolerance, par defaut 0.2
  // A faire avant un RunOnVertex pour le reconnaissance des Cercles de section
  void SetTolerance(double iTolerance);

  // Maj de la tolerance a partir de la sag dynamique (par defaut 0.2)
  void SetDynamicTolerance();

  // Section du mesh par un plan, 
  // Les segments ou PolyLines sont recuperes ailleurs par GetResult
  // iIdxVertexDeb : Numero du vertex de depart de la recherche. 
  //                 Si 0, on envisage tous les triangles donc toutes les intersections
  //                 Si non, la recherche debute par les triangles autour de ce vertex et l'on s'arrete
  //                 sur la premiere section. Par exemple cas de la coupe d'un tore qui donne souvent 2 sections
  HRESULT Run (CATMathPlane &iPlane, CATListOfInt &LstOfTri, int iIdxVertexDeb = 0);

  // Recuperation des resultats temporairement (6 valeurs par segment)
  HRESULT GetResultSegments (CATListOfDouble &LstSegmentResult);

  // Recuperation des resultats sous forme de points non dupliques (3 valeurs par point)
  HRESULT GetResultPoints (CATListOfDouble &LstPointResult);

  // Recuperation des resultats sous forme de points non dupliques (3 valeurs par point)
  // et de contour sur ces points
  // oLstPointResult         : Liste des points à raison de 3 valeurs par point
  // oLstNumVertices         : Liste des numeros de sommets constituant les contours. 
  //                         : Un sommet de numero -1 indique toujours la fin d'un Contour
  //                         : Si le contour est fermé (premier = dernier)
  HRESULT GetResultContours (CATListOfDouble &LstPointResult, CATListOfInt &oLstNumVertices);

  // Section du mesh sur un vertex par plusieurs plans tournant autour de la normale
  // On garde celui donnant le meilleur cercle sur la section et on renvoi
  // La direction, le centre du cercle et son rayon et l'erreur quadratique moyenne
  // On renvoi la liste des points d'intersection a raison de 3 valeurs par point
  // On renvoi l'angle d'ouverture du meilleur cercle sur la section
  // Cette Methode appelle le Run standard
  // Si oErrQuadra < 0, aucun cercle de trouve TRES IMPORTANT
  HRESULT RunOnVertex (int iIdxVertex, CATMathPoint &oCentreCercle, double &oRayonCercle,              
    CATMathVector &oDirection, double &oErrQuadra, CATListOfDouble &LstPntCut, double &oAngleOuverture, CATListOfInt &LstOfTri);


  // Les champs de la classe
  CATBoolean           _MeshOK;         // Indique que le constructeur s'est bien passe, on peut continuer
  int _Error;                           // Valeur de l'erreur recuperable par GetError()
  CATIPolyMesh       * _MyPolyMesh;     // Le mesh sur lequel on travaille 
  int                  _NbrVtx, _NbrTri;

  double               _Tolerance;      // Tolerance pour la reconnaissance de cercle
  double               _SeuilAffinite;  // Seuil en dessous duquel une ellipse est un cercle
                                        // En fait c'est 1 moins le rapport entre les 2 rayons (Max/Min)
  double               _SeuilQuotient;  // A donner exactement
  int                  _NbrMinTriOnVtx; // Nombre de triangles minimum autrour d'un sommet pour calculer une section
  CATMathVector      * _CutVector;      // La normale aux plans de coupe
  CATMathVector      * _NormOnVertex;   // La normale aux Vertex
  int                  _NbPlaneMax;     // Nombre maximum de plans de coupes
  int                  _NbPntMinCercle; // Nombre min de points sur une section pour calcul cercle
  double             * _Poids;          // Le scalaire associe à chaque sommet fonction du plan  (initialise a 1.e30)
	int                * _TriTraite;      // Table des triangles traités
  CATBoolean           _ConicCercle;    // Si TRUE, on recherche le meilleur cercle sur une section
  double               _dTetaMinDeg;    // Dans la recherche du meilleure cercle, pour terminer les iterations
  int                  _MinTrianglesInMesh;   // Nombre min de triangles pour travailler (6)
  int                  _MinVerticesInMesh;    // Nombre min de triangles pour travailler (6)

  void SetTypeOutput(); 

  CATListOfDouble      _LstOfResult;  // La liste des segments a raison de 6 valeurs par segment (2 points)

  double               _DynamicSqSAG; // SAG dynamique (au carre) pour la segmentation

private:

  void Segment_Driver (const int iSomI, const int iSomJ, const int iSomK, 
											 const double BarIJ, const double BarIK);

  //Correction par interpolation cubique sur 2 points et 2 normales et coordonnee barycentrique
  void CorrectionPointOnSegment(const CATMathPoint & iPntA, const CATMathPoint & iPntB,
								           const CATMathVector & iNorA, const CATMathVector & iNorB,
								           const double iLambda, 
								           CATMathPoint &oCorrect);
 };

#endif
