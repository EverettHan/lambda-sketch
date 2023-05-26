//=======================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=======================================================================================
//
// CATPolyMergeNetworkMeshesOperator.h
//
//=======================================================================================
//
// Usage notes: Op�rateur de construction d'un maillage �tanche � partir des sous mesh
//              rendus par CATPolyMCurveNetworkOperator.
//
//=======================================================================================
// July,   2009 : RAQ : Cr�ation
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

  //Run de l'op�rateur
  int Run();

  //R�cup�ration du maillage global
  CATIPolyMesh* GetResultMesh();

  //R�cup�ration des domaines
  CATPolyAttributeDomains* GetAllDomains();

  //R�cup�ration des points d'intersection si option activ�e dans l'op�rateur CATPolyMCurveNetworkOperator
  const CATListOfInt* GetIntersectionPoints() const;


private:

  //Gestion d'erreur
  int SetError(const int iError);

  //Suppression des sous maillages
  void RemoveSubMeshes();

  //Check d'un mesh
  int CheckPolyMesh(CATIPolyMesh* iPolyMesh);

  //Ajout du mesh courant dans le mesh r�sultat avec merge des vertex de bord provenant du sous mesh
  int InsertAndMergeSubMeshInOutputMesh(const CATIPolyMesh& iSubMeshToInsert, CATIPolyMesh& iOutputMesh, const CATPolyGetHolesOper& iOutputMeshHolesOperator);

  //Table de correspondance des vertex pour la recopie
  CATBoolean AllocateVerticesMap(const int iSize);
  void RemoveVerticesMap();

  //Recherche d'un point sur un bord libre � partir de ses coordonn�es
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

