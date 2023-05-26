//====================================================================================
// Copyright Dassault Systemes Provence 2008, All Rights Reserved
//====================================================================================
//
// CATSmoAdvancedMeshFromSubdivisionOperator.h
//
//====================================================================================
//
// Usage notes: Cr�ation d'un base mesh � partir de la subdivision d'une sous partie
//              d'un maillage et fonctionnalit� d'identification des vertex en tant
//              que points de subdivision.
//
//====================================================================================
// October,  2008 : RAQ : Creation
//====================================================================================
#ifndef CATSmoAdvancedMeshFromSubdivisionOperator_H
#define CATSmoAdvancedMeshFromSubdivisionOperator_H

//Pour l'h�ritage
#include "CATSmoSubdivisionMeshOperator.h"

//Pour l'export
#include "CATSmoOperators.h"

class CATSobMesh;


class ExportedByCATSmoOperators CATSmoAdvancedMeshFromSubdivisionOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoAdvancedMeshFromSubdivisionOperator();

  //Check de la connexit� de la working zone, par d�faut pas de check
  virtual void SetCheckConnexity() = 0;

  //Option d'ajout d'un attribut sur chacun des sous-vertex pour indiquer la cellule de provenance, par d�faut pas d'attribut
  virtual void SetPutAttributesOnVertices() = 0;
 
  //Suivi de l'arbre de d�tails pour la sous partie, par d�faut pas de suivi
  virtual void SetAddDetailsInWorkingZone() = 0;

protected:

  //Constructeur
  CATSmoAdvancedMeshFromSubdivisionOperator(CATSobMesh* iInputMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoAdvancedMeshFromSubdivisionOperator* CATSmoCreateAdvancedMeshFromSubdivisionOperator(CATSobMesh* iInputMesh, const int iLevel, const CATLISTP(CATSobFace)* iWorkingZone,
                                                                                           CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif


