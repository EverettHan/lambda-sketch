//===================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//===================================================================================
//
// CATPolyMCurveNetworkIntersectionPoint.h
//
//===================================================================================
//
// Usage notes: Point d'intersection du r�seau calcul� par l'op�rateur
//              CATPolyMCurveNetworkOperator.
//
//===================================================================================
// July,   2009 : RAQ : Cr�ation
//===================================================================================
#ifndef CATPolyMCurveNetworkIntersectionPoint_H
#define CATPolyMCurveNetworkIntersectionPoint_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe m�re
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

  //R�cup�ration du nombre de points
  int GetNbPoints() const;

  //R�cup�ration d'un point (1 <= iIndex <= NbPoints)
  int GetPoint(const int iIndex, int& oSubMeshIndex, int& oVertexIndexInSubMesh) const;

  //R�cup�ration des couples (Indice sous maillage; Indice du vertex dans ce sous maillage)
  int GetAllPoints(const CATListOfInt*& oSubMeshesIndices, const CATListOfInt*& oVerticesIndicesInSubMeshes) const;

  //R�cup�ration des indices de tous les sous maillages
  const CATListOfInt& GetSubMeshesIndices() const;

  //R�cup�ration de l'indice de vertex pour un sous maillage donn�
  int GetVertexIndexInSubMesh(const int iLocalPolyMeshIndex) const;

protected:

  //Destructeur
  virtual ~CATPolyMCurveNetworkIntersectionPoint();

private:


  //--------- Data:
  CATListOfInt _SubMeshesIndices, _VerticesIndicesInSubMeshes;
};

#endif


