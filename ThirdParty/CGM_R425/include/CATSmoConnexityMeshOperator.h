//======================================================================
// Copyright Dassault Systemes Provence 2009, All rights reserved
//======================================================================
//
// CATSmoConnexityMeshOperator.h
//
//======================================================================
//
// Usage notes: Extraction des parties connexes d'un base mesh.
//
//======================================================================
// November,    2009 : RAQ : Cr�ation
//======================================================================
#ifndef CATSmoConnexityMeshOperator_H
#define CATSmoConnexityMeshOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Structure subdivision
#include "CATSobDiag.h"
#include "CATSobMesh.h"
#include "CATSobListOfMesh.h"

//Divers
#include "CATBoolean.h"

class CATSobCell;


class ExportedByCATSmoOperators CATSmoConnexityMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoConnexityMeshOperator() {}

  //Option de d�sactivation de la g�n�ration des sous-mesh
  virtual void SetDontBuildConnexSubMeshes() = 0;

  //Report des attributs sur les faces
  virtual void SetReportFacesAttributes() = 0;

  //Run de l'op�rateur
  virtual CATSobDiag Run() = 0;

  //Etat de la connexit� du mesh d'entr�e
  virtual CATBoolean IsConnex() const = 0;

  //R�cup�ration des parties connexes du mesh d'entr�e
  virtual CATSobDiag GetConnexPartsOnInputMesh(int& oNbConnexParts, CATLISTP(CATSobFace)*& oConnexParts) const = 0;

  //Obtention des mesh
  virtual CATSobDiag GetConnexMeshes(CATSobListOfMesh& oConnexMeshes) = 0;


protected:

  //Constructeur
  CATSmoConnexityMeshOperator() {}

};


/**
 * Creates the operator.
 *
 * @param iMesh
 * The mesh from which connex parts have to be extracted.
 * @param iSeedCell
 * A seed cell. If iSeedCell is NULL all connex parts will be extracted,
 * else only the connex component containning the cell will be retreived.
 *
 * @return
 * The operator.
 **/
ExportedByCATSmoOperators
CATSmoConnexityMeshOperator* CATSmoCreateConnexityMeshOperator(CATSobMesh* iMesh, CATSobCell* iSeedCell = 0);


#endif


