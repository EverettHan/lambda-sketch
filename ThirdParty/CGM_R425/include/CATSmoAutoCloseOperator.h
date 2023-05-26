//=================================================================================
// Copyright Dassault Systemes Provence 2006, All Rights Reserved 
//=================================================================================
//
// CATSmoAutoCloseOperator.h
//
//=================================================================================
//
// Usage notes:
//
//=================================================================================
// February,  2006 : RAQ : Creation
//=================================================================================
#ifndef CATSmoAutoCloseOperator_H
#define CATSmoAutoCloseOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Classe m�re
#include "CATSmoSubdivisionMeshOperator.h"


class ExportedByCATSmoOperators CATSmoAutoCloseOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoAutoCloseOperator();

  
protected:
  
  //Constructeur
  CATSmoAutoCloseOperator(CATSobMesh*                  iMesh,
                          CATSmoMeshTopoModifOperator* iTopoModifOpe);

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoAutoCloseOperator* CATSmoCreateAutoCloseOperator(CATSobMesh* iMesh,
                                                       CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif



