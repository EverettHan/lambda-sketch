//=================================================================================
// Copyright Dassault Systemes Provence 2010, All Rights Reserved
//=================================================================================
//
// CATSmoNothingToDoOperator.h
//
//=================================================================================
//
// Usage notes: Op�rateur qui ne fait rien !
//
//=================================================================================
// March,  2010 : RAQ : Creation
//=================================================================================
#ifndef CATSmoNothingToDoOperator_H
#define CATSmoNothingToDoOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Classe m�re
#include "CATSmoSubdivisionMeshOperator.h"

//Divers
#include "CATBoolean.h"

class CATSobMesh;


class ExportedByCATSmoOperators CATSmoNothingToDoOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Constructeur
  CATSmoNothingToDoOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

  //Destructeur
  virtual ~CATSmoNothingToDoOperator();

  //Set tardif du base mesh ou remplacement si le run n'a pas encore �t� fait
  CATSobDiag SetOrReplaceSobMesh(CATSobMesh* ipSobMesh, const CATBoolean iModifyTOpoModifOpe = TRUE);

  //Permet de relancer une nouvelle l'op�rateur
  void SetFlagAsNotRun() { _OperatorAlreadyRun=FALSE; }

protected:

  //Run de l'op�rateur
  virtual CATSobDiag RunOperator();

};


//--------------------------------------
// M�thode de cr�ation de l'op�rateur
// iMesh peut �tre nul et dans ce cas iTopoModifOpe n'est pas pris en compte
//--------------------------------------
ExportedByCATSmoOperators
CATSmoNothingToDoOperator* CATSmoCreateNothingToDoOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);



#endif

