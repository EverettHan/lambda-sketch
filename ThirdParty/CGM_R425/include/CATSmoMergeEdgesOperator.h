//=================================================================================
// Copyright Dassault Systemes Provence 2006, All Rights Reserved 
//=================================================================================
//
// CATSmoMergeEdgesOperator.h
//
//=================================================================================
//
// Usage notes:
//
//=================================================================================
// February,  2006 : RAQ : Creation
//=================================================================================
#ifndef CATSmoMergeEdgesOperator_H
#define CATSmoMergeEdgesOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Classe m�re
#include "CATSmoSubdivisionMeshOperator.h"

//Objets Subdivision
#include "CATSobListOfFace.h"

class CATSobMesh;
class CATSobEdge;


class ExportedByCATSmoOperators CATSmoMergeEdgesOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoMergeEdgesOperator();

  //Set des edges � merger
  virtual void SetEdgesToMerge(CATSobEdge* iEdge1, CATSobEdge* iEdge2, const double iRatio=0.0) = 0;

  //Obtention des faces modifi�es -> A SUPPRIMER
  virtual int GetModifications(CATLISTP(CATSobFace)*& ioToReplaceFaces,
                               CATLISTP(CATSobFace)*& ioSubstitutFaces) const = 0;

  
protected:
  
  //Constructeur
  CATSmoMergeEdgesOperator(CATSobMesh* iMesh,
                           CATSmoMeshTopoModifOperator* iTopoModifOpe);

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoMergeEdgesOperator* CATSmoCreateMergeEdgesOperator(CATSobMesh* iMesh,
                                                         CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif



