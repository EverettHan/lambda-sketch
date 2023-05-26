//=============================================================================================
// Copyright Dassault Systemes Provence 2005, All Rights Reserved 
//=============================================================================================
//
// CATSobDetailsToLocalCutConverter.h
//
//=============================================================================================
//
// Usage notes: Convertisseur D�tails -> LocalCut
//
//=============================================================================================
// April,  2005 : RAQ : Creation
//=============================================================================================
#ifndef CATSobDetailsToLocalCutConverter_H
#define CATSobDetailsToLocalCutConverter_H

#include "CATSobOperators.h"

//El�ments de structure subdivision
#include "CATSobDiag.h"


class CATSobMesh;
class CATSobFace;


class ExportedByCATSobOperators CATSobDetailsToLocalCutConverter
{
public:

  //Constructeur
  CATSobDetailsToLocalCutConverter(CATSobMesh* iMeshWithDetails,
                                   const int   iLevelToUse = -1);

  //Destructeur
  ~CATSobDetailsToLocalCutConverter();

  //Obtention du mesh LocalCut
  CATSobMesh* GetLocalCutMesh();

  //Obtention du niveau de subdivision utilis�
  int GetLevelUsed();

  //Diag de l'op�rateur
  CATSobDiag GetDiag();

  //Run de l'op�rateur
  CATSobDiag Run();






private:

  // Copy constructor and equal operator
  CATSobDetailsToLocalCutConverter (CATSobDetailsToLocalCutConverter &);
  CATSobDetailsToLocalCutConverter& operator=(CATSobDetailsToLocalCutConverter&);

  //Diag de l'op�rateur
  CATSobDiag SetDiag(const CATSobDiag iDiag);

  //Identificateur des faces triangulaires et de leur OneRing
  CATSobDiag IdentifyFacesJustDetails(CATSobMesh* iMesh);

  //Suppression du tag sur les faces tri + OneRing
  CATSobDiag RemoveTagOnFacesJustDetails(CATSobMesh* iMesh);

  //Recherche de Tag
  int IsFaceFlagged(CATSobFace * iFace);

  //Data
  CATSobMesh *_MeshWithDetails, *_MeshLocalCut;
  int _LevelToUse, _LevelUsed;
  CATSobDiag _Diag;



};



//-----------------------------
// Obtention du mesh LocalCut
//-----------------------------
inline CATSobMesh* CATSobDetailsToLocalCutConverter::GetLocalCutMesh()
{
  return _MeshLocalCut;
}


//---------------------------------------------
// Obtention du niveau de subdivision utilis�
//---------------------------------------------
inline int CATSobDetailsToLocalCutConverter::GetLevelUsed()
{
  return _LevelUsed;
}


//-----------------------
// Diag de l'op�rateur
//-----------------------
inline CATSobDiag CATSobDetailsToLocalCutConverter::SetDiag(const CATSobDiag iDiag)
{
  _Diag=iDiag;
  return _Diag;
}


inline CATSobDiag CATSobDetailsToLocalCutConverter::GetDiag()
{
  return _Diag;
}





#endif





