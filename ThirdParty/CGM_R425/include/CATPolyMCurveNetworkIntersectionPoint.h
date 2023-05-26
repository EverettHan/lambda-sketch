//===================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//===================================================================================
//
// CATPolyMCurveNetworkIntersectionPoint.h
//
//===================================================================================
//
// Usage notes: Point d'intersection du réseau calculé par l'opérateur
//              CATPolyMCurveNetworkOperator.
//
//===================================================================================
// July,   2009 : RAQ : Création
//===================================================================================
#ifndef CATPolyMCurveNetworkIntersectionPoint_H
#define CATPolyMCurveNetworkIntersectionPoint_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe mère
#include "CATPolyRefCounted.h"

//Divers
#include "CATListOfInt.h"



class ExportedByCATPolyTrimOperators CATPolyMCurveNetworkIntersectionPoint: public CATPolyRefCounted
{
public:
  
  //Constructeur
  CATPolyMCurveNetworkIntersectionPoint();

  //Ajout d'un couple (Indice sous maillage; Indice du vertex dans ce sous maillage)
  void AddPoint(const int iSubMeshIndex, const int iVertexIndexInSubMesh);

  //Récupération du nombre de points
  int GetNbPoints() const;

  //Récupération d'un point (1 <= iIndex <= NbPoints)
  int GetPoint(const int iIndex, int& oSubMeshIndex, int& oVertexIndexInSubMesh) const;

  //Récupération des couples (Indice sous maillage; Indice du vertex dans ce sous maillage)
  int GetAllPoints(const CATListOfInt*& oSubMeshesIndices, const CATListOfInt*& oVerticesIndicesInSubMeshes) const;

  //Récupération des indices de tous les sous maillages
  const CATListOfInt& GetSubMeshesIndices() const;

  //Récupération de l'indice de vertex pour un sous maillage donné
  int GetVertexIndexInSubMesh(const int iLocalPolyMeshIndex) const;

protected:

  //Destructeur
  virtual ~CATPolyMCurveNetworkIntersectionPoint();

private:


  //--------- Data:
  CATListOfInt _SubMeshesIndices, _VerticesIndicesInSubMeshes;
};

#endif


