//===================================================================================
// Copyright Dassault Systemes Provence 2006, All Rights Reserved 
//===================================================================================
//
// CATSmoChangeGeometryOperator.h
//
//===================================================================================
//
// Usage notes: 
//
//===================================================================================
// January,   2023 : RBD : Appel SetEdgeWeight() : _AutoWeight prend maintenant les valeurs 0 � 3 inclus.
//                         Nouvelle m�thode SetAutoWeightOnVertices()
// July,      2009 : RBD : Ajout SetAutoWeight sur les vertex
// October,   2008 : RAQ : Ajout gestion d�tails
// February,  2006 : RAQ : Cr�ation
//===================================================================================
#ifndef CATSmoChangeGeometryOperator_H
#define CATSmoChangeGeometryOperator_H

//Pour l'h�ritage
#include "CATSmoSubdivisionMeshOperator.h"

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"

class CATSobMesh;
class CATSobFace;
class CATSobEdge;
class CATSobVertex;
class CATSmoMeshTopoModifOperator;


class ExportedByCATSmoOperators CATSmoChangeGeometryOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Constructeur
  CATSmoChangeGeometryOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

  //Destructeur
  virtual ~CATSmoChangeGeometryOperator();

  //Changement des coordonn�es d'un vertex
  virtual CATSobDiag SetVertexCoordinates(CATSobVertex* iVertex, const double* iCoords);
  virtual CATSobDiag SetVertexCoordinates(CATSobVertex* iVertex, const double iX, const double iY, const double iZ);

  //Changement du poids d'un vertex
  virtual CATSobDiag SetVertexWeight(CATSobVertex* iVertex, const double iWeight);

  //Set d'un poids pour tous les vertex de bord
  virtual CATSobDiag SetWeightOnAllBoundaryVertices(const double iWeight);

  //Changement du Sharpness d'une edge
  CATSobDiag SetSharpnessOnEdge(CATSobEdge* iEdge, const short iSharpness);
  CATSobDiag SetSharpnessOnEdge(CATSobEdge* iEdge, const short iSharpness, const CATBoolean iSmoothEdge);

  //Type de raccord � effectuer le long de l'edge: G0 (FALSE) / G1 (TRUE)
  CATSobDiag SetSmoothingOnEdge(CATSobEdge* iEdge, const CATBoolean iSmoothEdge);
  
  // **** DEPRECATED DO NOT USE **** : Utiliser la m�thode SetAutoWeight(const int& iAutoWeight = 0)
  // Activation du poid automatique sur les vertex.
  // Pour activer le report automatique du poids des edges vers les vertex commun, mettre iAutoWeight � 1.
  // Il faut qu'il y ai au moins 3 edges de poids > 0 pour que le poids du vertex commun soit modifi�.
  // PUIS utiliser les m�thodes SetSharpnessOnEdge ou SetSmoothingOnEdge.
  // Pour d�sactiver le poids automatique, remettre iAutoWeight � 0.
  virtual void SetAutoWeightOnVertices(const CATBoolean iAutoWeight = 0);

  // Activation du poid automatique sur les vertex.
  // Pour activer le report automatique du poids des edges vers les vertex commun, mettre iAutoWeight > 0.
  // Il faut qu'il y ai au moins 3 edges de poids > 0 pour que le poids du vertex commun soit modifi�.
  // Si iAutoWeight == 1, on prend le max du poids des ar�tes et on l'impose au vertex
  // Si iAutoWeight == n <= 3, on prend le n-i�me poids. Valeur conseill�e : 3.
  // PUIS utiliser les m�thodes SetSharpnessOnEdge ou SetSmoothingOnEdge.
  // Pour d�sactiver le poids automatique, remettre iAutoWeight � 0.
  virtual void SetAutoWeight(const int& iAutoWeight);

  //////////////////////// Gestion des d�tails ////////////////////////
  //Set de d�tails
  virtual CATSobDiag SetDetail(CATSobFace* iFace, const int iU, const int iV, const int iLevel, const double* iDetail, const int iDaughterFaceIndex = 0);
  virtual CATSobDiag SetDetail(CATSobEdge* iEdge, const int iU, const int iLevel, const double* iDetail);
  virtual CATSobDiag SetDetail(CATSobVertex* iVertex, const int iLevel, const double* iDetail);

  //Ajout de d�tails
  virtual CATSobDiag AddDetail(CATSobFace* iFace, const int iU, const int iV, const int iLevel, const double* iDetail, const int iDaughterFaceIndex = 0);
  virtual CATSobDiag AddDetail(CATSobEdge* iEdge, const int iU, const int iLevel, const double* iDetail);
  virtual CATSobDiag AddDetail(CATSobVertex* iVertex, const int iLevel, const double* iDetail);

  //Suppression de d�tails
  virtual CATSobDiag RemoveDetail(CATSobFace* iFace, const int iU, const int iV, const int iLevel, const int iDaughterFaceIndex = 0);
  virtual CATSobDiag RemoveDetail(CATSobEdge* iEdge, const int iU, const int iLevel);
  virtual CATSobDiag RemoveDetail(CATSobVertex* iVertex, const int iLevel);

  //Suppression d'un niveau de d�tails
  virtual CATSobDiag RemoveLOD(CATSobFace* iFace, const int iLevel);
  virtual CATSobDiag RemoveLOD(CATSobEdge* iEdge, const int iLevel);

  //Suppression de tous les d�tails
  virtual CATSobDiag RemoveAllDetails();

  //Conversion des d�tails en local frame
  virtual CATSobDiag ConvertDetailsToLocalFrame();
  
  //Conversion des d�tails en global frame
  virtual CATSobDiag ConvertDetailsToGlobalFrame();


protected:

  //Run de l'op�rateur
  virtual CATSobDiag RunOperator();

private:
  int _AutoWeight;

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoChangeGeometryOperator* CATSmoCreateChangeGeometryOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif

