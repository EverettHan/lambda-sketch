//=================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=================================================================
//
// CATPolyFixNonManifoldVerticesOperator.h
//
//=================================================================
//
// Usage notes: Détection et correction de vertex non manifold
//              (par éclatement du vertex).
//
//=================================================================
// March,   2009 : RAQ : Création
//=================================================================
#ifndef CATPolyFixNonManifoldVerticesOperator_H
#define CATPolyFixNonManifoldVerticesOperator_H

//Pour l'export
#include "CATPolyRegularizeOperators.h"

//Divers
#include "CATListOfInt.h"
#include "IUnknown.h"

class CATIPolyMesh;


class ExportedByCATPolyRegularizeOperators CATPolyFixNonManifoldVerticesOperator
{
public:

  //Constructeur
  CATPolyFixNonManifoldVerticesOperator(CATIPolyMesh& iPolyMesh);

  //Destructeur
  ~CATPolyFixNonManifoldVerticesOperator();

  //Run de l'opérateur
  HRESULT Run();

private:

  //Détection des vertex non-manifold
  HRESULT DetectNonManifoldVertices(CATListOfInt& oNonManifoldVertices);

  //Correction des vertex non-manifold
  HRESULT FixNonManifoldVertices(const CATListOfInt& iNonManifoldVertices);

  //-------- Data:
  HRESULT _HRes;
  CATIPolyMesh& _PolyMesh;

};


#endif

