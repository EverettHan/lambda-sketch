//=======================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=======================================================================================
//
// CATPolyMergeNetworkMeshesOperator.h
//
//=======================================================================================
//
// Usage notes: Opérateur de construction d'un maillage étanche à partir des sous mesh
//              rendus par CATPolyMCurveNetworkOperator.
//
//=======================================================================================
// July,   2009 : RAQ : Création
//=======================================================================================
#ifndef CATPolyMergeNetworkMeshesOperator_H
#define CATPolyMergeNetworkMeshesOperator_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Divers
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATIPolyMesh;
class CATPolyMCurveNetworkOperator;
class CATPolyGetHolesOper;
class CATPolyMeshCopyOper;
class CATPolyAttributeDomains;

class CATMathPoint;


class ExportedByCATPolyTrimOperators CATPolyMergeNetworkMeshesOperator
{
public:

  //Constructeur
  CATPolyMergeNetworkMeshesOperator(CATPolyMCurveNetworkOperator* iMCurveNetworkOperator);

  //Destructeur
  ~CATPolyMergeNetworkMeshesOperator();

  //Run de l'opérateur
  int Run();

  //Récupération du maillage global
  CATIPolyMesh* GetResultMesh();

  //Récupération des domaines
  CATPolyAttributeDomains* GetAllDomains();

  //Récupération des points d'intersection si option activée dans l'opérateur CATPolyMCurveNetworkOperator
  const CATListOfInt* GetIntersectionPoints() const;


private:

  //Gestion d'erreur
  int SetError(const int iError);

  //Suppression des sous maillages
  void RemoveSubMeshes();

  //Check d'un mesh
  int CheckPolyMesh(CATIPolyMesh* iPolyMesh);

  //Ajout du mesh courant dans le mesh résultat avec merge des vertex de bord provenant du sous mesh
  int InsertAndMergeSubMeshInOutputMesh(const CATIPolyMesh& iSubMeshToInsert, CATIPolyMesh& iOutputMesh, const CATPolyGetHolesOper& iOutputMeshHolesOperator);

  //Table de correspondance des vertex pour la recopie
  CATBoolean AllocateVerticesMap(const int iSize);
  void RemoveVerticesMap();

  //Recherche d'un point sur un bord libre à partir de ses coordonnées
  int FindPointOnBorder(const CATMathPoint& iPointToFind, const CATIPolyMesh& iPolyMesh, const CATPolyGetHolesOper& iMeshHolesOperator) const;

  //Calcul des points d'intersection
  int RetrieveIntersectionPoints();



  //--------- Data:
  int _Error;
  CATPolyMCurveNetworkOperator* _MCurveNetworkOperator;
  CATIPolyMesh* _OutputMesh;
  CATIPolyMesh** _SubMeshes;
  CATPolyAttributeDomains* _PolyDomains;
  int* _VerticesMap;
  int _NbSubMeshes, _VerticesMapUsedSize, _VerticesMapMaxSize;
  CATListOfInt _IntersectionPoints;

};


#endif

