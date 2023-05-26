//==============================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//==============================================================================
//
// CATSmoSplitVertexOperator.h
//
//==============================================================================
//
// Usage notes: S�paration d'un vertex.
//
//==============================================================================
// May,   2009 : RAQ : Creation
//==============================================================================
#ifndef CATSmoSplitVertexOperator_H
#define CATSmoSplitVertexOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"

class CATSobVertex;
class CATSmoMeshTopoModifOperator;


class ExportedByCATSmoOperators CATSmoSplitVertexOperator
{
public:

  //Destructeur
  virtual ~CATSmoSplitVertexOperator();

  //Option d'update du mesh: si utilis� les pointeurs contenus dans les listes oEdgesToSplit et oVerticesToSplit
  //des m�thodes GetNewEdges et GetNewVertices d�signeront des objets d�j� d�truits
  virtual void SetMustUpdateMesh() = 0;

  //Run de l'op�rateur
  virtual CATSobDiag Run() = 0;

  //Diag de l'op�rateur
  virtual CATSobDiag GetDiag() const = 0;




protected:

  //Constructeur
  CATSmoSplitVertexOperator();

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoSplitVertexOperator* CATSmoCreateSplitVertexOperator(CATSobVertex* iVertexToSplit, 
                                                           CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);




#endif

