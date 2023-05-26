//=========================================================================
// Copyright Dassault Systemes Provence 2012, All rights reserved
//=========================================================================
//
// CATSmoConnexityFacesOperator.h
//
//=========================================================================
//
// Usage notes: D�coupage en composantes connexes d'une liste de faces
//
//=========================================================================
// October,    2012 : RAQ : Cr�ation
//=========================================================================
#ifndef CATSmoConnexityFacesOperator_H
#define CATSmoConnexityFacesOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Divers
#include "CATSobDiag.h"
#include "CATSobFace.h"
#include "CATSobListOfFace.h"


class ExportedByCATSmoOperators CATSmoConnexityFacesOperator
{
public:

  //Destructeur
  virtual ~CATSmoConnexityFacesOperator();

  //Run de l'op�rateur
  virtual CATSobDiag Run() = 0;

  //R�cup�ration des composantes connexes
  virtual CATSobDiag GetConnexComponents(CATLISTP(CATSobFace)*& oConnexSetOfFaces, int& oNbConnexSets) = 0;
  
  //R�cup�ration des composantes connexes
  virtual CATSobDiag GetNbConnexComponents(int& oNbConnexSets) = 0;
  

protected:

  //Constructeur
  CATSmoConnexityFacesOperator();



private:

  //No default methods
  CATSmoConnexityFacesOperator(const CATSmoConnexityFacesOperator&);
  CATSmoConnexityFacesOperator& operator=(const CATSmoConnexityFacesOperator&);

};


/**
 * Cr�ation de l'op�rateur
 **/
ExportedByCATSmoOperators
CATSmoConnexityFacesOperator* CATSmoCreateConnexityFacesOperator(const CATLISTP(CATSobFace)& iFaces);

#endif  //CATSmoConnexityFacesOperator_H


