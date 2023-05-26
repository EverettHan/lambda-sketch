//============================================================================================
// Copyright Dassault Systemes Provence 2010 - 2011 All Rights Reserved
//============================================================================================
// CATPolyMesh_Clean_Check_ButtonHoles
//============================================================================================
// Usage notes: Opérateur de couture des "boutonnières" sur un maillage
//============================================================================================
// 27-Apr-2018 - JLH - Ajout de la syntaxe CheckDuplicateVertices avec la HTableOfIntToInt
//                     pour gérer les 'confused vertices' par doublon.
// 13-Feb-2012 - JLH - Erreur de compilation sous Unix... include pour HRESULT
// 07/11/2011 : GDD : Creation
//============================================================================================
#ifndef CATPolyMesh_Clean_Check_ButtonHoles_H
#define CATPolyMesh_Clean_Check_ButtonHoles_H

//#define DEBUG_A_GDD
//#ifdef DEBUG_A_GDD
    //#include "CATLib.h"
    //#include <iostream.h>
    //#include "CATStdIO.h"
    //#include "CATCGMOutput.h"
//#endif

class CATIPolyMesh;
class CATMathPoint;
class CATHTableOfIntToInt;

#include "CATBooleanDef.h"  // Pour CATBoolean et boolean
#include "CATSysErrorDef.h" // Pour HRESULT
#include "CATListOfInt.h"

#include "CATPolyMesh_GetFreeEdges_Holes.h"

#include "ExportedByPolyhedralOperatorsRvs.h"

class ExportedByPolyhedralOperatorsRvs CATPolyMesh_Clean_Check_ButtonHoles
{
public:

  // Standard constructors and destructors
  // -------------------------------------

  // iPolyMesh : Le mesh a traiter qui sera modifie en place, ne pas detruire
  CATPolyMesh_Clean_Check_ButtonHoles (CATIPolyMesh * iPolyMesh, CATBoolean iWithCompactage = TRUE);
  virtual ~CATPolyMesh_Clean_Check_ButtonHoles ();

  // Run pour le Check de l'operateur
  // iCutDistance2 : Carre de la distance maximum de fusion
  // oLstIdxBH contient les numeros de Vertices de BH a prendre par paquet de 3 correspondant aux points (P1,P2,P3)
  // Une liste vide indique qu'il n'y a pas de BH
  // Chaque depart de BH est caracterise pas le sommet P2. 
  // Pour les rendre visibles afficher les segments (P1,P2) & (P2,P3)
  HRESULT RunCheck (double iCutDistance2, CATListOfInt & oLstIdxBH);

  // Option permettant de ne pas creer de nouveaux vertices ou de modifier les coordonnees des existants
  // Par defaut, sans appel de cette methode, on peut modifier
  // On peut toutefois en faire disparaitre, le Mesh en sortie est compacte
  void SetNoModify (CATBoolean NoModify = FALSE);

  // Tolerance pour fusionner les Vertices, par defaut tolerance nulle => Egalite bit/bit
  // Permet de calculer les MAcro Points
  void SetFusionVtx (double EpsFusionVtx); 

  // Run pour le Clean de l'operateur
  // iCutDistance2 : Carre de la distance maximum de fusion.
  // iSuppressSmallEdges : = TRUE si l'on veut supprimmer les Edges (par defaut FALSE)
  // Le mesh est modifie en place, attention
  HRESULT RunClean (double iCutDistance2, CATBoolean iSuppressSmallEdges = FALSE);
                                         

	  /**
   * Detect and fix meshes where points of a free edge loop are too close from
   * an edge of this loop, or another free edge loop. It will supress small
   * gaps in a mesh by replacing points by their projection on the closest edge.
   * 
   * @param iCutDistance
   *	The minimum distance between a point and an edge (orthogonal projection).
   * @param oLstIdxToCollapse
   *	If we are performing detection only (fix=FALSE), it will contain
   *	the list of 3*n elements, Index of the point, Index of the vertex
   *	starting the edge we will project onto, and the index of the end.
   *	This list will not be significant in the fix mode.
   * @param fix
   *	TRUE if we want the algorithm to merge the detected gaps, FALSE
   *	if we only want to detect them.
   * @return 
   *	S_OK or E_FAIL if the computation was successfull or not.
   */
  HRESULT RunCheckGaps (double iCutDistance, CATListOfInt& oLstIdxToCollapse, CATBoolean fix);

	/**
	* Runs the button hole algorithm and the close gaps algorithm until a convergence.
	*
	*/
  HRESULT CloseGaps (double iCutDistance);


  // Pour recuperer les informations sur le nombre de FE restant
  void GetInformation (int &NbrFE);

	/**
	* Check and suppress duplicated vertices given a tolerance
	* 
	* @param oLstDuplicateVertex
	*	The list of vertices that are too close from another vertex
	* @param iEpsFusionVtx
	*	The tolerance of the algorithm. Under this distance, two vertices are considered as duplicated
	* @param iFreeEdgesOnly
	*	TRUE is we want to only check vertices of free edges, FALSE if we want to check all the CATIPolyMesh.
	* @param iSuppress
	*	TRUE is we want to merge duplicated vertices, FALSE if we only want to check.
	* @return 
	*	S_OK or E_FAIL if the computation was successfull or not.
	*/
	HRESULT CheckDuplicateVertices (CATListOfInt & oLstDuplicateVertex, double iEpsFusionVtx, CATBoolean iFreeEdgesOnly, CATBoolean iSuppress);
    HRESULT CheckDuplicateVertices (CATHTableOfIntToInt & oMapDuplications, const double iEpsFusionVtx, CATBoolean iFreeEdgesOnly = FALSE);

  // Recuperation de l'erreur
  int GetError();
  
#ifdef NOT_USED_GDD
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
#endif

  // Les champs de la classe

  int _Error;     // Valeur de l'erreur recuperable par GetError()

  CATIPolyMesh           * _MyPolyMesh;

  double                   _CosCutAngle;    // Arc Cosinus angle de decoupe en degre pour trouver les departs
  double                   _CutDistance2;   // Carre de la distance de confusion 
  double                   _EpsFusionVtx;   // Tolerance sur la fusion des vertices, defaut 0 (bit a bit)
                                            // On la Sette par SetFusionVertex(EpsFusionVtx)
  double                   _ColDistance2;   // Carre de la distance de collapse de 2 vertices
                                            // On le prend egal a 0.1 fois _CutDistance2
  double                   _STriDegenere;   // Aire en dessous de laquelle on considerera un triangle degenere
                                            // On le prend egal a 0.05 fois _ColDistance2
  double                   _GapMaximum2;    // Carre du gap maximum qui n'a pas permis de fermer un BH

  CATBoolean               _ModifyVtx;      // Pour modifier ou non les coordonnees d'un vertex ou en creer
                                            // Par defaut TRUE, on peut modifier

  int                      _NbrFE;          // Nombre de Free Edges
  int                      _NbrBHTotal;     // Nombre de Free Edges totalement fermes
  int                      _NbrBHPartiel;   // Nombre de Free Edges partielement fermes

  CATBoolean               _ProgressOK;     // Pour un passage de Clean passe a TRUE si une modification
                                            // quelconque du maillage a ete realisee ou iterer a nouveau

  // Au sujet des distances : Elles sont toutes au carre. Supposons que l'on veuille une toleranve de boutonniere
  // de 0.1mm. Ceci correspondrait a un "JOIN" de 0.1 et l'on cherche a coudre a cette distance d'un sommet sur
  // un Edge de frontiere.
  //   _CutDistance2 = 0.1 * 0.1 = 0.01
  //   _ColDistance2 = 0.01  / 10 = 0.001 soit 0.0032mm. 
  //                   On collapse 2 sommets consecutifs si la distance est < 0.032
  //   _STriDegenere = 0.001 : 20 = 0.00005 
  //                   On considere qu'un triangle est dégénéré si son aire est < 0.0005 soit un carré de 0.007mm de coté

private:

  // Check des vertex dupliques avec suppression eventuelle, par defaut NON
  HRESULT CheckDuplicateVertices (CATListOfInt & oLstDuplicateVertex, CATBoolean Suppress = FALSE);

  // Clean d'un Free Edges (BUTTON_HOLE)
  // LstIdxBH contient les numeros des Vertex de la loop, 
  // Si fermee, le dernier = le premier vertex
  // Si ouverte, on assure automatiquement la fermeture
  // CosCutAngle  : Cosinus le l'angle pour definir un Cap ou Needle (petit angle et cos -> 1)
  // CutDistance2 : Carre de la distance maxi en dessus de laquelle on ne fait rien.
  HRESULT Clean_Botton_Holes(CATListOfInt LstIdxBH, double CosCutAngle, double CutDistance2,
                             CATBoolean iSuppressSmallEdges);

  // Distance d'un vertex a une bar donnee par ses 2 extremites. C'est une projection.
  // IdxVtx   : Vertex a projeter
  // IdxDebb & IdxFin : Vertex extremite de la Bar
  // oPntProj : Point de projection
  // oLambda  : Coordonnees barycentrique du point projete
  //            Si [0,1] il y a projection a l'interieur sinon c'est une extremite
  // En retour, la distance carree qui existe toujours sauf si un des vertex n'existe pas (distance negative)
  double Dist2_Vertex_Bar (CATMathPoint M, CATMathPoint P1, CATMathPoint P2, CATMathPoint & oPntProj, double & oLambda);  

  // Split d'une barre [IdxDeb,IdxFin] par un sommet donne par IdxCur et gestion des connexions
  // Les coordonnees du sommet IdxCur sont remplacees par PntProj si ModifCoord = TRUE
  HRESULT SplitBar (int IdxCur, int IdxDeb, int IdxFin, CATMathPoint PntSplit);

	 /**
   * Determine the bounding box of a List of point indices.
   * 
   * @param iLstIdx
   *	The list containing indices of the points we want to examine.
   * @param oBox
   *	The bounding box, It has to be allocated before the call of
   *	the function. You will obviously have to delete if afterward.
   * @return 
   *	S_OK or E_FAIL if the computation was successfull or not.
   */

  /**
   * Determine the closest edge in a set of free edges holes from a point
   * 
   * @param iIndex
   *	The index of the point to check.
   * @param FreeEdges_GDD
   *	The structure containing the free edge loops.
   * @param iLstLoops
   *	A list containing the index of the loops to analyse.
   * @param oIndexBeginBar
   *	Output value, containing the index of the beginning of the edge
   *	we are projecting onto.
   * @param oIndexEndBar
   *	Output value, containing the index of the end of the edge
   *	we are projecting onto.
   * @return
   *	The distance between the point and the edge we found.
   *	-1 if an error occured.
   */
  double Distance_Point_FEs (int iIndex, CATPolyMesh_GetFreeEdges_Holes& FreeEdges_GDD, CATListOfInt& iLstLoops, CATMathBox** boxes, CATHTableOfIntToPtr& EdgeBoxes, double iCutDistance2,
	                         int& oIndexBeginBar, int& oIndexEndBar);

  /**
   * Given a point and a an edge, take this point and projects in onto this edge.
   * The projected point will be move between the point and the initial edge.
   * 
   * @param iIndex
   *	The index of the point to check.
   * @param oIndexBeginBar
   *	The index of the beginning of the edge we are projecting onto.
   * @param oIndexEndBar
   *	The index of the end of the edge we are projecting onto.
   * @return
   *	S_OK or E_FAIL if the computation was successfull or not.
   */
  HRESULT JoinPointEdge (int iIndex, int iIndexBeginBar, int iIndexEndBar);

  // Arrondi a une valeur +/- Eps
  double Arround(double Eps, double iVal);

  CATBoolean _withCompactage;

};

#endif
