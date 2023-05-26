//===================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//===================================================================================
//
// CATSmoReverseMeshOrientationOperator.h
//
//===================================================================================
//
// Usage notes: Inversion de l'orientation d'un base mesh
//
//===================================================================================
// November,    2009 : RAQ : Creation
//===================================================================================
#ifndef CATSmoReverseMeshOrientationOperator_H
#define CATSmoReverseMeshOrientationOperator_H

//Pour l'h�ritage
#include "CATSmoSubdivisionMeshOperator.h"

//Pour l'export
#include "CATSmoOperators.h"

//Divers
#include "CATSobDiag.h"

class CATSobMesh;
class CATSmoMeshTopoModifOperator;



class ExportedByCATSmoOperators CATSmoReverseMeshOrientationOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoReverseMeshOrientationOperator();

protected:

  //Constructeur
  CATSmoReverseMeshOrientationOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);
};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoReverseMeshOrientationOperator* CATSmoCreateReverseMeshOrientationOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);



#endif



