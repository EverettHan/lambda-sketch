//=======================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//=======================================================================================
//
// CATSmoSplitEdgesOperator.h
//
//=======================================================================================
//
// Usage notes: S�paration d'une liste d'edges, le base mesh peut devenir non connexe
//              et peut contenir des ngones.
//
//=======================================================================================
// May,   2009 : RAQ : Creation
//=======================================================================================
#ifndef CATSmoSplitEdgesOperator_H
#define CATSmoSplitEdgesOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"
#include "CATSobListOfFace.h"
#include "CATSobListOfEdge.h"
#include "CATSobListOfVertex.h"

class CATSobMesh;
class CATSmoMeshTopoModifOperator;

class ExportedByCATSmoOperators CATSmoSplitEdgesOperator
{
public:

  //Destructeur
  virtual ~CATSmoSplitEdgesOperator();

  //Set de la loop d'edge
  virtual void SetEdgesToSplit(const CATLISTP(CATSobEdge)& iEdgesToSplit) = 0;

  //Option d'update du mesh: si utilis� les pointeurs contenus dans les listes oEdgesToSplit et oVerticesToSplit
  //des m�thodes GetNewEdges et GetNewVertices d�signeront des objets d�j� d�truits
  virtual void SetMustUpdateMesh() = 0;

  //Run de l'op�rateur
  virtual CATSobDiag Run() = 0;

  //Diag de l'op�rateur
  virtual CATSobDiag GetDiag() const = 0;

  //DEPRECATED : Suivi des nouvelles edges et des nouveaux vertex
  virtual CATSobDiag GetNewEdges(CATLISTP(CATSobEdge)& oEdgesToSplit, CATLISTP(CATSobEdge)& oNewEdges) = 0;
  virtual CATSobDiag GetNewVertices(CATLISTP(CATSobVertex)& oVerticesToSplit, CATLISTP(CATSobVertex)& oNewVertices) = 0;

  //DEPRECATED : Obtention des sous-ensembles connexes de faces
  virtual CATSobDiag GetSubsetsOfFaces(CATLISTP(CATSobFace)*& oSubsetsOfFaces, int& oNbSubsets) = 0;

protected:

  //Constructeur
  CATSmoSplitEdgesOperator();
  
};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoSplitEdgesOperator* CATSmoCreateSplitEdgesOperator(CATSobMesh* iMesh, 
                                                         CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);



#endif


