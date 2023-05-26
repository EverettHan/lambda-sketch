// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATParalNode: Connector du graphe representant l'ensemble des Wires a offseter
//
//=============================================================================
// Oct. 00  Creation                          LVL (MDTV)
//=============================================================================
#ifndef CATParalNode_H
#define CATParalNode_H


#include "CATVertex.h"


//-----------------------------------------------------------------------------
class CATParalNode
{
 public:

   //----------------------------
   // constructeurs, destructeurs
   //----------------------------
	 CATParalNode();
   CATParalNode( CATULONG32 NodeTag,CATLONG32 NbBar, CATVertex * Vertex = NULL, int Extremite = 0);
   virtual ~CATParalNode();

//Requete
   CATLONG32 GetNbBar() const;
	 CATULONG32 GetNodeTag() const;
   int GetIndexBar( CATLONG32 Numero, CATLONG32 & IndexBar) const;
	 CATLONG32 GetIndexBarBis(CATLONG32 Numero) const;
	 int IsValid() const;
	 int IsBloque() const;
	 int IsTraite() const;
	 CATVertex * GetVertex() const;
	 int IsExtremite() const;

//Modif
	 int SetIndexBar( CATLONG32 Numero, CATLONG32 NewIndexBar);
	 void BecomeNonValide();
	 void BecomeBloque();
	 void BecomeDeBloque();
	 void SetVertex (CATVertex * Vertex);
	 void BecomeTraite();
	 void BecomeDeTraite();

 private:
	//Champs
	 CATULONG32		_NodeTag;		//Id du Vertex Geo
	 CATVertex * _Vertex;
	 CATLONG32		_NbBar;			//Nombre de CATParalBar connecte au CATParalNode
	 CATLONG32 *	_ListOfIndexBar;	//Tableau des index des CATParalBar connectes.
	 int		_Bloque;
	 int		_Valide;
	 int		_Traite;
	 int		_Extremite;				//Est-il l'extremite d'un offset simple de wire ouvert?

};

#endif
