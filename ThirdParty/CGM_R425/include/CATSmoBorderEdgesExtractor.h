//=========================================================================
// Copyright Dassault Systemes Provence 2012, All rights reserved
//=========================================================================
//
// CATSmoBorderEdgesExtractor.h
//
//=========================================================================
//
// Usage notes: Extraction des edges fronti�res d'un ensemble de faces
//
//=========================================================================
// October,    2012 : RAQ : Cr�ation
//=========================================================================
#ifndef CATSmoBorderEdgesExtractor_H
#define CATSmoBorderEdgesExtractor_H

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"
#include "CATSobListOfFace.h"
#include "CATSobListOfEdge.h"


class ExportedByCATSmoOperators CATSmoBorderEdgesExtractor
{
public:

  //Destructeur
  virtual ~CATSmoBorderEdgesExtractor();

  //Run de l'op�rateur
  virtual CATSobDiag Run() = 0;

  //R�cup�ration de la fronti�re
  virtual const CATLISTP(CATSobEdge)& GetBorder() const = 0;


protected:

  //Constructeur
  CATSmoBorderEdgesExtractor();


private:

  //No default copy methods
  CATSmoBorderEdgesExtractor(const CATSmoBorderEdgesExtractor&);
  CATSmoBorderEdgesExtractor& operator=(const CATSmoBorderEdgesExtractor&);

};


/**
 * Creates the operator
 **/
ExportedByCATSmoOperators
CATSmoBorderEdgesExtractor* CATSmoCreateBorderEdgesExtractor(const CATLISTP(CATSobFace)& iFaces);


#endif  //CATSmoBorderEdgesExtractor_H


