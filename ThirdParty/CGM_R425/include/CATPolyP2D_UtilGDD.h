//
//============================================================================================
// Copyright Dassault Systemes Provence 2010 - 2011 All Rights Reserved
//============================================================================================
//
// CATPolyP2D_UtilGDD.cpp
//
//============================================================================================
//
// Usage notes: Utilitaires sur les PolyMesh n'existant pas dans la version officielle
//              On doit pouvoir les transferer normalement sans souci particulier a CGM
//
//============================================================================================
// 15/10/2010 : GDD : Creation
//============================================================================================
#ifndef CATPolyP2D_UtilGDD_H
#define CATPolyP2D_UtilGDD_H

class CATIPolyMesh ;
class CATIPolySurfaceVertexFacetNeighborhood ;

  // =====   DATA : Structure of Barre 2D   ========================================================
	struct StructBarresOfFreeEdges {
		int Deb ;   // Numero de sommet debut de barre
		int Fin ;   // Numero de sommet  fin  de barre
    int Tri ;   // Numero du triangle associé a la barre (cas bord libre)
    int Use ;   // 0 = Non utilise 1 = Utilise
	} ;

//#define DEBUG_A_GDD
#ifdef DEBUG_A_GDD
    #include "CATLib.h"
    #include <iostream.h>
    #include "CATStdIO.h"
#endif

#include "CATIPolyFactory.h"

#include "CATBoolean.h"
#include "CATListOfInt.h"

// Pour la geometrie
#include "CATMath.h"
#include "CATMathPlane.h"
#include "CATMathLine.h"
#include "CATMathVector.h"

// Quelque definition des erreurs standards
/*
    SANS_STATUS                           9000001
    PARTIE_A_IMPLEMENTER                  9000002
    ALLOC_MEMORY                          1000001
    POINTEUR_NULL                         1000002
    PB_SORTIE_ALGO_POLYMESH               9001001
    ITERATEUR_VERTEX_ALGO_POLYMESH        9001002
    TERATEUR_TRIANGLE_ALGO_POLYMESH       9001003
    POLYMESH_NON_COMPACT                  9001004 
    BEST_QUADRIC                          9001005
    PB_SORTIE_ALGO_POLYGEO                9001006

*/

#include "CATPolyCanonicOperators.h"

class ExportedByCATPolyCanonicOperators CATPolyP2D_UtilGDD
{

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPolyP2D_UtilGDD (CATIPolyMesh * iPolyMesh);
  virtual ~CATPolyP2D_UtilGDD ();

  // Recuperation de l'erreur
  int GetError();

  // Recuperation de la PolyFactory de creation des PolyMesh
  CATIPolyFactory * GetPolyFactory ();

  // Extraction du Polymesh a partir d'une liste de N° de Triangles et creation d'un PolyMesh compacte
  // Donner le oPolyMesh = NULL
  HRESULT ExtractPolyMesh (CATListOfInt iLstOfTri, CATIPolyMesh * &oPolyMesh);

  // Calcul de l'aire du polymesh (toujours positive, si nulle PB)
  HRESULT ComputeArea(double & oArea);

  // Estimation de l'erreur de corde
  HRESULT ChordalErrorEstimate(double & oSag);

  /**
   * Returns a description of the polygon (the removed triangles are not taken account).<br>
   * The <tt>ITri</tt>'th triangle is described by :
   * <tt><ul>
   * <li>iNoVertices[3*ITri+0]
   * <li>iNoVertices[3*ITri+1]
   * <li>iNoVertices[3*ITri+2]
   * </ul></tt>
   * Let be <tt>IVtx</tt> a relative vertex number such for instance
   * <tt>IVtx = iNoVertices[3*ITri+0]</tt>, the coordinates of this vertex
   * will be found in :
   * <tt><ul>
   * <li>ioCoords[3*IVtx+0]
   * <li>ioCoords[3*IVtx+1]
   * <li>ioCoords[3*IVtx+2]
   * </ul></tt>
   * <b>CAUTION:</b> if <tt>ioCoords</tt> (resp. <tt>ioNoVertices</tt>) is <tt>NULL</tt>,
   * its allocation is done by the method.<br>
   * Otherwise it has to be done by the calling method and
   * its size must be greater than the expected <tt>3*oNbVertices</tt>
   * (resp. <tt>3*oNbTriangles</tt>).<br>
   * But its release <b>HAS TO BE DONE</b> by the calling method
   * if it is not <tt>NULL</tt> in case of no vertices or triangles.<br>
   */     

  HRESULT GetTriangles (int              &oNbVertices,
                        double*          &ioCoords,
                        int              &oNbTriangles,
                        int*             &ioNoVertices);

  // Avec les Normales en plus
  HRESULT GetTriangles (int              &oNbVertices,
                        double*          &ioCoords,
                        double*          &ioNormals,
                        int              &oNbTriangles,
                        int*             &ioNoVertices,
                        CATBoolean       iNormalize = FALSE);
 /**
   * Returns the neighbour vertices at a given level for a vertex given by its relative indice.
   * <pre>
   *           2       2       2
   *           +-------+-------+              On this tesselation, the levels are shown
   *          / \     / \     / \             in regards on the central vertex (level 0).
   *         /   \   /   \   /   \
   *       2/     \1/     \1/     \2
   *       +-------+-------+-------+
   *      / \     / \     / \     / \
   *     /   \   /   \   /   \   /   \
   *   2/     \1/     \0/     \1/     \2
   *   +-------+-------+-------+-------+
   *    \     / \     / \     / \     /
   *     \   /   \   /   \   /   \   /
   *      \2/     \1/     \1/     \2/
   *       +-------+-------+-------+
   *        \     / \     / \     /
   *         \   /   \   /   \   /
   *          \2/     \2/     \2/
   *           +-------+-------+
   * </pre>
   * @param iNoVertex
   * The relative indice of the vertex that we want the neighbours.
   * @param iLevel
   * The wanted level.
   * @param ioLevels
   * Array of the levels offsets.<br>
   * If <tt>NULL</tt>, the array is allocated by the method and HAS TO RELEASED by the caller.<br>
   * It size has to be greater or equal to <tt>1+iLevel+1</tt>.<br>
   * The vertices of the <tt>I</tt>'th level (<tt>I in [0,iLevel]</tt>) will be found between
   * <tt>ioNoVertices[ioLevels[I]]</tt> and <tt>ioNoVertices[ioLevels[I+1]-1]</tt>.
   * @param ioNoVertices
   * List of the neighbour vertices indices.<br>
   * <b>CAUTION:</b> The list will be cleaned at the beginning of the treatment.
   * @return
   * <tt>TRUE</tt>, if the computation has succeeded. <tt>FALSE</tt>, otherwise.<br>
   * <b>NB:</b> If this method is called several times consecutively, it is advised to call it
   * under the optimization context <tt>(OptimizeBegin,OptimizeEnd)</tt>.
   */
#ifdef NOT_USED_GDD
  // Rem : En sortie le premier element de la liste est le vertex de depart 
  HRESULT GetVertexNeighborsOfVertex(const int iIdxVertex, const int iLevel, 
                                     int* &ioLevels, CATListOfInt &ioIdxVertices);

  // Recupere les 3 triangles possibles connexes a un triangle donne
  HRESULT GetTriangleNeighborsOfTriangle(const int iIdxTriangle, CATListOfInt &oLstTriConnexe);
#endif

#ifdef NOT_USED_GDD
  // Recuperation des FreeEdges
  // Les FreeEdges constituent un ou plusieurs contours separes par un numero de sommet -1
  // oLstVerticesFreeEdges   : Liste des numeros de sommets. 
  //                         : Un sommet de numero -1 indique toujours la fin d'un Contour
  //                         : Chaque contour est fermé (premier = dernier)
  HRESULT GetFreeEdges (CATListOfInt &oLstVerticesFreeEdges);
#endif

#ifdef NOT_USED_GDD
  // Recuperation des FreeEdges et du triangle associe a chaque arete 
  // Renvoie la liste de triangle associé a chaque arrete.
  // Triangle oLstTrianglesFreeEdges[i] associé a la barre LstVerticesFreeEdges[i],LstVerticesFreeEdges[i+1]
  // Le numero du dernier triangle est null pour avoir la meme cardinalité que la liste des vertices
  // La separation des contours de triangles est toujours -1
  HRESULT GetFreeEdges (CATListOfInt &oLstVerticesFreeEdges, CATListOfInt &oLstTrianglesFreeEdges);
#endif
  // A partir d'une table de barres, calcule une liste de contour constitue des index et separees par -1
  // Si un contour est ferme, le prmier point = le dernier point.
  // On n'a pas besoin des coordonnees des points
  // Attention, la table des barres commence en position 1
  HRESULT ComputeContourOnBarres (int NbBarres, StructBarresOfFreeEdges *Barres, 
                                  CATListOfInt &oLstVertices, 
                                  CATListOfInt &oLstTriangles);

  // Function wich compare two instances of BarresOfFreeEdges.
  static int CompareBarresOfFreeEdges(const void * iP1, const void * iP2) ;

  // En retour, renvoi la position de la barre dans la table (1 ....)
  //            si <= 0, la barre n'existe pas dans la table (ANORMAL)
  //            renvoi le nombre d'occurences de numero de sommet debut NumVertex
  // REM : La numerotation commence a 1 dans cette table
  int FindPositionBarre(int NumVertex, int NbBarres, StructBarresOfFreeEdges * Barres, int & oNbOccu);

  // Enrichissement du polygone local _MyPolyMesh a un niveau donne
  // iLevelLOD : Niveau de subdivision pour enrichissement
  // oPolyMesh_LOD : Le polygone subdivise (Si NULL, pas de subdivision)
  // retour ier = 0 si OK
  int LOD_PolyMesh (int iLevelLOD, CATIPolyMesh * &oPolyMesh_LOD, CATBoolean Interpolation_PNT = TRUE);

  // Les champs de la classe

  int _Error;     // Valeur de l'erreur recuperable par GetError()

  CATIPolyMesh                            * _MyPolyMesh;
  CATIPolyFactory                         * _PolyFactory;
  CATIPolySurfaceVertexFacetNeighborhood  * _VertexFacetNeighborhood; 

private:

  // Extraction de la tables des sommets, triangles et Normales eventuellement
  // Si iWithNormals == TRUE, on extrait les normales normees ou non suivant iNormalize
  HRESULT GetTriangles (int             &oNbVertices, 
                        double*         &ioCoords, 
                        double*         &ioNormals,
                        int             &oNbTriangles, 
                        int*            &ioNoVertices,
                        CATBoolean       iWithNormals,
                        CATBoolean       iNormalize);

  // Interpolation sur milieu segment avec normale extremite
  void EvalMilieu_PNT (CATBoolean Interpolation_PNT,
                       const CATMathPoint  &PntA, const CATMathPoint  &PntB, 
                       const CATMathVector &NorA, const CATMathVector &NorB,
                             CATMathPoint  &PntM,       CATMathVector& NorM);

};

#endif
