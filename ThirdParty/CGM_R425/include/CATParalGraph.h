// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATParal: Graphe representant l'ensemble des Wires a offseter
//
//=============================================================================
// Oct. 00  Creation                          LVL (MDTV)
//=============================================================================
#ifndef CATParalGraph_H
#define CATParalGraph_H

#include "CATListOfCATParalNode.h"
#include "CATListOfCATParalBar.h"
#include "CATListOfCATGeometries.h"
#include "CATEdge.h"
#include "CATVertex.h"
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByPARLight.h"
#include "CATCGMVirtual.h"
#include "CATListOfULONG32.h"

class CATWire;
class CATParalNode;
class CATParalBar;
class CATGeoFactory;
class CATTopData;

//-----------------------------------------------------------------------------
class ExportedByPARLight CATParalGraph  : public CATCGMVirtual   
{
 public:

	 //PART I Dans le cadre du tri des Wires A OFFSETER
   //----------------------------
   // constructeurs, destructeurs
   //----------------------------
   CATParalGraph();
	 CATParalGraph (CATLONG32 NbNode,  CATLONG32 NbBar);
   virtual ~CATParalGraph();

  //----------------------------
	//  Initialize:
	//	INITIALISATION
	//----------------------------

	 int Initialize ( CATLONG32 NbNode, CATLONG32 NbBar);
  //----------------------------
	//InsertNode :
	//Insertion de Noeuds
	//----------------------------
   CATLONG32 InsertNode( CATULONG32 NewNodeTag, CATLONG32 NbBar, CATVertex * Vertex = NULL, int Extremite = 0);

	//----------------------------
	//InsertBar :
	//Insertion des Bars
	//----------------------------
	 int InsertBar (CATULONG32 NewBarTag,  CATLONG32 IndexFirstNode,CATLONG32 IndexLastNode, CATWire * Wire = NULL);


 	//----------------------------
	// FindNextExtremite:
	//Recherche d'un noeud du graphe a etre une extremite dans le sens avec une seule barre
	//----------------------------

	 CATLONG32 FindNextExtremite() const;


 	//----------------------------
	// UpdateMode :
	//Signifie a une barre qu'on l'a traite dans un sens
	//----------------------------

	 int UpdateMode( CATLONG32 CurrentIndexBar, CATLONG32 CurrentIndexNode, CATLONG32  & NextIndexNode);


 	//----------------------------
	// Compute:
	// Lance la resolution pour le graphe deswires a offseter
	//----------------------------

	 int Compute();


 	//----------------------------
	// FindNextRightBar:
	//	Renvoie l'index de la barre suivant une autre bar (a droite) sur un noeud
	//----------------------------

	 CATLONG32 FindNextRightBar( CATLONG32 CurrentIndexNode,  CATLONG32 OldIndexBar) const;


 	//----------------------------
	// FindValidBar
	//	Renvoie un index de barre restant a traiter
	//----------------------------

	 int FindValidBar(CATLONG32 & ValidIndexBar) const;


 	//----------------------------
	// GetNbSolution
	//	Donne le nombre de Domaines du body a offseter
	//----------------------------

	 CATLONG32 GetNbSolution() const;


 	//----------------------------
	// GetNbSubSolution
	//	Donne le nombre d'element d'un domaine i
	//----------------------------

	 CATLONG32 GetNbSubElement( int i) const;


 	//----------------------------
	// GetSubElement
	//	Donne l'index du wire a concatener pour la ieme solution
	//----------------------------

	 CATULONG32 GetSubElement( int i,  int j,int & InCornerLoop) const;


 	//----------------------------
	// GetResult :
	//	Donne les tablo resultats
	//----------------------------

	 int GetResult(CATULONG32 * TagResult, CATLONG32 * NbResult) const;


   //------------------------------
   //Parcours de Graphe AOV
   //------------------------------
   int ParcoursDeGraphe(CATListOfULONG32 *& ListCC);
   void VisiteDeBar(int indexbar,CATListOfInt & ListWire);
   int RechercheAdjacents(int indexbar,CATListOfInt & ListWire);

	 //PART II Dans le cadre du tri des PARALLELES

 	//----------------------------
	// ParalSolver:
	//	
	//----------------------------
	 void ParallelGraphSolver(CATGeoFactory * MyFacto, CATTopData * MyData, CATBody * iMyShell, CATSide iParalSide, CATBody * ioMyResult);
	 void ParallelGraphSolver_ThickWire(CATGeoFactory * MyFacto, CATTopData * MyData, CATBody * iMyShell, CATSide iParalSide, CATBody * ioMyResult);

	 const CATLISTP(CATGeometry) * GetListEdgeToRemove();
	//Champs
 private:

   // IZE wk. 09 2009 IR 0650283
   // One edge may be a art of two bars, one valid and one discarded. 
   // Edges seen at least once as valid should be excluded from this list.
   void CheckListEdgeToRemove(CATBody * iSolverResult);
   // Create and build result wire body
   void BuildWire(ListPOfCATParalNode & iListNode, short iLevel, CATBody * ioMyResult);
   // Return number of valid bars associated with the node
   CATLONG32 GetNbValidBar(CATParalNode * iNode) const;

	 ListPOfCATParalNode      _TabNode;
	 CATLONG32						    _NbItemNode;
	 ListPOfCATParalBar		    _TabBar;
	 CATLONG32						    _NbItemBar;
	 CATULONG32	 				   *	_TabTagResult;
	 CATLONG32					   *	_TabNbResult;
	 CATLONG32						   _NumberOfSolution;
	 CATLONG32						   _TotalNumber;
	 CATLISTP(CATGeometry) * _ListEdgeToRemove;
   int                     _DebugGraph;
};

#endif
