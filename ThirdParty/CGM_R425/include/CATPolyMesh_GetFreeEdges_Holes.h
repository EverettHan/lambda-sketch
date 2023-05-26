//============================================================================================
// Copyright Dassault Systemes Provence 2010 - 2011 All Rights Reserved
//============================================================================================
// CATPolyMesh_GetFreeEdges_Holes
//============================================================================================
// Usage notes: Operateur de calcul des Free Edge des trous
//============================================================================================
// 21-Feb-2012 - GDD - Modif profonde pour la gestion des NMT en priorite
// 13-Feb-2012 - JLH - Erreur de compilation sous Unix... include pour HRESULT
// 15/10/2011 : GDD : Creation (Reprise d'un existant de GDD)
//============================================================================================
#ifndef CATPolyMesh_GetFreeEdges_Holes_H
#define CATPolyMesh_GetFreeEdges_Holes_H

// Cet operateur existe deja sur les CATIPolymesh : CATPolyGetHolesOper mais pose probleme
// car sort en erreur (E_FAIL) dans le cas ou il y a des barres NMT ce qui arrive assez souvent sur
// des modeles rencontres dans 3DVia pour P2D.

// Meme utilisation que CATPolyGetHolesOper

class CATIPolyMesh ;

//#define DEBUG_A_GDD
//#ifdef DEBUG_A_GDD
//    #include "CATLib.h"
//    #include <iostream.h>
//    #include "CATStdIO.h"
//    #include "CATCGMOutput.h"
//#endif

#include "CATBooleanDef.h"  // Pour CATBoolean et boolean
#include "CATSysErrorDef.h" // Pour HRESULT
#include "CATListOfInt.h"

#include "CATMathBox.h"
#include "CATHTableOfIntToPtr.h"

//#include "CATPolyCanonicOperators.h"
class CATPolyMesh_GetFreeEdges_Holes
{

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPolyMesh_GetFreeEdges_Holes (CATIPolyMesh * iPolyMesh);
  virtual ~CATPolyMesh_GetFreeEdges_Holes ();

  // Run de l'operateur 
  HRESULT Run ();

  // Recuperation du nombre de Loops
  int GetNbHoles ();

  // Recuperation d'une Loop donnee par son numero dans une liste des Numeros de sommets
  CATListOfInt & GetHole (int iHole);
  HRESULT GetHole (int iHole, CATListOfInt& oLstIdxLoop);

  // Computation of the AABB of a loop
  HRESULT GetHoleBoundingBox(int iHole, CATMathBox& oBox, CATHTableOfIntToPtr& ioEdgeBoxes);

  // Recuperation du nombre de NMT
  int GetNbVtxNMT ();

  // Recuperation des Vertex NBP
  CATListOfInt & GetVtxNMT ();

  // Recuperation de l'erreur
  int GetError();

  // Les champs de la classe
  int _Error;

  // Le Mesh de travail
  CATIPolyMesh * _MyPolyMesh;
  // Liste des Index, et pour chaque Loop le numero de deb et de Fin
  CATListOfInt _LstIdxLoopALL, _LstDebLoop, _LstFinLoop;
  // Liste des INDEX des vertex NMT
  CATListOfInt _LstIdxVtxNMT;

  // Liste pour rendre les resultats
  CATListOfInt _LstIdxLoop;

private:

// =====   DATA : Structure of Barre 2D   ========================================================
struct StructBarresOfFreeEdges {
	int Deb ;   // Numero de sommet debut de barre
	int Fin ;   // Numero de sommet  fin  de barre
    int Use ;   // 0 = Non utilise 1 = Utilise
    int NMT ;   // 0 = xxx.DEB Valence 1 ou 2, vertex Standard d'ou arrive 1 barre et en part 1
                // 1 = xxx.DEB Valence > 2 est un vertex NMT d'ou part plus de 2 barres (un nombre pair)
    int Ang ;   // Angle*1000 en degre. A chaque vertex est associe plusieurs barres. C'et l'angle par rapport
                // a la premiere barre (qui vaut 0). Les barres sont ordonnees sur cet angle et non plus sur Fin
                // Ceci permet, pour les NMT de proceder a un autre type de poursuite de branche basee sur l'angle
                // pour creer les boutonnieres avec extremite ces fameux NMT.   
} ;

  // A partir d'une table de barres, calcule une liste de contour constitue des index et separees par -1
  // Si un contour est ferme, le prmier point = le dernier point.
  // On n'a pas besoin des coordonnees des points
  // Attention, la table des barres commence en position 1
  HRESULT ComputeContourOnBarres (int NbBars, StructBarresOfFreeEdges *Barres); 

  // A partir de la barre de Vertex Deb donne calcule tous les angles de toutes les barres qui rayonnent 
  // et les tri en croissant sur ces angles. On calcule sur le plan defini par la normale au sommet NumVtx
  HRESULT Angle_Arround_NMT (int NumVtx, int NbBars, StructBarresOfFreeEdges *Barres);

  // Function wich compare two instances of BarresOfFreeEdges.
  static int CompareBarresOfFreeEdges(const void * iP1, const void * iP2) ;

  // En retour, renvoi la position de la barre dans la table (1 ....)
  //            si <= 0, la barre n'existe pas dans la table (ANORMAL)
  //            renvoi le nombre d'occurences de numero de sommet debut NumVertex
  // REM : La numerotation commence a 1 dans cette table
  int FindPositionBarre(int NumVertex, int NbBars, StructBarresOfFreeEdges * Barres, int & oNbOccu);

};

#endif
