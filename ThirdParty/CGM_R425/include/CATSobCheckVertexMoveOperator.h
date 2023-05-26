//=========================================================================
// Copyright Dassault Systemes Provence 2005, All Rights Reserved 
//=========================================================================
//
// CATSobCheckVertexMoveOperator.h
//
//=========================================================================
//
// Usage notes: Op�rateur de check pour le d�placements de vertex locaux
//              cr��s par local cut
//
//=========================================================================
// March,     2005 : RAQ : Creation
//=========================================================================
#ifndef CATSobCheckVertexMoveOperator_H
#define CATSobCheckVertexMoveOperator_H

#include "CATSobOperators.h"

//El�ments de structure
#include "CATSobDiag.h"
#include "CATSobFace.h"

//Infos de d�coupes
#include "CATSobFaceCutInfo.h"
#include "CATSobListOfFaceCutInfo.h"

//Divers
#include "CATBoolean.h"


class CATSobVertex;


class ExportedByCATSobOperators CATSobCheckVertexMoveOperator
{
public:

  //Constructeur
  CATSobCheckVertexMoveOperator();

  //Destructeur
  ~CATSobCheckVertexMoveOperator();

  //Set du vertex � checker
  void SetVertexToCheck(CATSobVertex* iVertexToCheck);

  //Run de l'op�rateur
  CATSobDiag Run();

  //Diag de l'op�rateur
  CATSobDiag GetDiag();

  //Mise en mode automatique
  void SetAutoMode();

  //Obtention des faces � couper et des ratios de d�coupes � ajouter
  int GetFacesToCut(CATLISTP(CATSobFaceCutInfo)*& oFaceToCutList);

  //Obtention du nouveau vertex local qui remplace celui
  //donn� en entr�e si le mode automoatique est activ�
  CATSobVertex* GetNewLocalVertex();

private:

        // Copy constructor and equal operator
  CATSobCheckVertexMoveOperator (CATSobCheckVertexMoveOperator &);
  CATSobCheckVertexMoveOperator& operator=(CATSobCheckVertexMoveOperator&);

  //Gestion du diag de l'op�rateur
  CATSobDiag SetDiag(const CATSobDiag iDiag);

  //Nettoyage de la liste d'info sur les d�coupes
  void EmptyListOfFaceToCut();

  //Cr�ation de la liste des d�coupes
  CATSobDiag RunCheckVertex();

  //Check d'un point sur une edge
  CATSobDiag CheckVertexOnEdge(CATSobEdge* iMotherEdge);

  //Check d'un vertex fils ou p�re
  CATSobDiag CheckSonOrFatherVertex(CATSobVertex* iVertexToCheck);

  //Calcul du nouveau vertex local si modification des bases mesh locaux
  CATSobDiag ComputeNewLocalVertex();

  //Obtention d'un objet CATSobFaceCutInfo pour une face donn�e
  CATSobFaceCutInfo* GetCutInfoForFace(CATSobFace* iFace);





  //------- Data
  CATSobDiag _Diag;
  CATSobVertex* _VertexToCheck;
  CATLISTP(CATSobFaceCutInfo) _ListOfFaceCutInfo;
  CATBoolean _AutoMode;
  CATSobVertex* _NewLocalVertex;
  double _RatioU, _RatioV;
  CATSobFace* _MotherFace;

};


//--------------------------
// Set du vertex � checker
//--------------------------
inline void CATSobCheckVertexMoveOperator::SetVertexToCheck(CATSobVertex* iVertexToCheck)
{
  _VertexToCheck=iVertexToCheck;
  _NewLocalVertex=0;
}


//-----------------------
// Diag de l'op�rateur
//-----------------------
inline CATSobDiag CATSobCheckVertexMoveOperator::GetDiag()
{
  return _Diag;
}


inline CATSobDiag CATSobCheckVertexMoveOperator::SetDiag(const CATSobDiag iDiag)
{
  _Diag=iDiag;
  return _Diag;
}


//---------------------------
// Mise en mode automatique
//---------------------------
inline void CATSobCheckVertexMoveOperator::SetAutoMode()
{
  _AutoMode=TRUE;
}


//-------------------------------------------------------------------
// Obtention des faces � couper et des ratios de d�coupes � ajouter
//-------------------------------------------------------------------
inline int CATSobCheckVertexMoveOperator::GetFacesToCut(CATLISTP(CATSobFaceCutInfo)*& oFaceToCutList)
{
  oFaceToCutList=&_ListOfFaceCutInfo;
  return _ListOfFaceCutInfo.Size();
}


//------------------------------------
// Obtention du nouveau vertex local
//------------------------------------
inline CATSobVertex* CATSobCheckVertexMoveOperator::GetNewLocalVertex()
{
  return (_AutoMode==FALSE) ? 0 : _NewLocalVertex;
}


#endif


