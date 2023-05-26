//===================================================================================
// Copyright Dassault Systemes Provence 2005-2007, All Rights Reserved 
//===================================================================================
//
// CATSmoRemoveFacesOperator.h
//
//===================================================================================
//
// Usage notes: 
//
//===================================================================================
// 21-11-07 MMO Correction des erreurs BAD004 (headerruler)
// 01-11-05 RAQ Cr�ation
//===================================================================================
#ifndef CATSmoRemoveFacesOperator_H
#define CATSmoRemoveFacesOperator_H

//Pour l'h�ritage
#include "CATSmoSubdivisionMeshOperator.h"

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"
// #include "CATSobFace.h" // MMO BAD004
#include "CATSobListOfFace.h"

class CATSobMesh;
class CATSmoMeshTopoModifOperator;
class CATSobFace; // MMO BAD004


class ExportedByCATSmoOperators CATSmoRemoveFacesOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Constructeur
  CATSmoRemoveFacesOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

  //Destructeur
  virtual ~CATSmoRemoveFacesOperator();

  //Destruction d'une face
  virtual void SetFaceToRemove(CATSobFace* iFaceToRemove);

protected:

  //Run de l'op�rateur
  virtual CATSobDiag RunOperator();


  //----- Data:
  CATLISTP(CATSobFace) _FacesToRemove;

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoRemoveFacesOperator* CATSmoCreateRemoveFacesOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif

