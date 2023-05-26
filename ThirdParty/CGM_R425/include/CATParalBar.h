// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATParalBar: Bar du graphe representant l'ensemble des Wires a offseter
//
//=============================================================================
// Oct. 00  Creation                          LVL (MDTV)
//=============================================================================
#ifndef CATParalBar_H
#define CATParalBar_H

#include "CATWire.h"

//-----------------------------------------------------------------------------
class CATParalBar
{
 public:

   //----------------------------
   // constructeurs, destructeurs
   //----------------------------
	 CATParalBar();

   CATParalBar( CATULONG32 BarTag, CATLONG32 IndexFirstNode, CATLONG32 IndexLastNode, 
								CATWire * Wire = NULL);

   virtual ~CATParalBar();

	//Requete
   int GetParam(CATLONG32 & IndexFirstNode, CATLONG32 & IndexLastNode, int & BarMode) const;
	 CATULONG32 GetBarTag() const;
	 int GetMode () const;
	 int IsValid() const;
	 CATEdge * GetFirstEdge() const;
	 CATEdge * GetLastEdge() const;
	 CATWire * GetWire() const;

	 //Modification
	 int ChangeMode(int NewBarMode);
	 int ChangeIndex(CATLONG32 IndexFirstNode, CATLONG32 IndexLastNode);
	 void BecomeNonValide();
	 void SetWire(CATWire * Wire);


 private:
	//Champs
	 CATULONG32		_BarTag;					//Id du Wire Geo
	 CATLONG32		_IndexFirstNode;	//Index du premier Node qui compose le Wire
	 CATLONG32		_IndexLastNode;		//Index du dernier Node qui compose le Wire
	 CATWire * _Wire;					//Wire associe a la Barre
	 int		_BarMode;					//Mode de traitement de la Bar :
														//0 : Bar jamais Traite
														//1 : Bar traite dans son sens propre
														//-1 : Bar traite dans son sens inverse
														//2 : Bar Entierement traite.
	 int		_Valide;
};
#endif
