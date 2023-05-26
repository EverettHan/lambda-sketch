//===============================================================================
// Copyright Dassault Systemes Provence 2011, All Rights Reserved
//===============================================================================
//
// CATSmoDualMeshOperator.h
//
//===============================================================================
//
// Usage notes: Op�rateur de cr�ation d'un mesh dual
//
//===============================================================================
// March,  2011 : RAQ : Cr�ation
//===============================================================================
#ifndef CATSmoDualMeshOperator_H
#define CATSmoDualMeshOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Divers
#include "CATSobDiag.h"

class CATSobMesh;


class ExportedByCATSmoOperators CATSmoDualMeshOperator
{
public:

  //Constructeur
  CATSmoDualMeshOperator(const CATSobMesh* iMesh);

  //Destructeur
  virtual ~CATSmoDualMeshOperator();

  //Run de l'op�rateur
  CATSobDiag Run();

  //Obtention du mesh dual
  CATSobMesh* GetDualMesh();


private:

  //Construction du mesh dual
  CATSobDiag BuildDualMesh();
  

  //--------- Data :
  CATSobDiag _Diag;
  const CATSobMesh* _InputMesh;
  CATSobMesh* _DualMesh;

};


#endif  //CATSmoDualMeshOperator_H


