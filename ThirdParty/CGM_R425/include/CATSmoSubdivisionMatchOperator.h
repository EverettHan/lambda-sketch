//===================================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved 
//===================================================================================
//
// CATSmoSubdivisionMatchOperator.h
//
//===================================================================================
//
// Usage notes: Op�rateur de modification du base mesh utilis� dans l'op�rateur
//              CATSttSubdivisionMatchOperator
//
//===================================================================================
// March,    2012 : G7S : Cr�ation
//===================================================================================
#ifndef CATSmoSubdivisionMatchOperator_H
#define CATSmoSubdivisionMatchOperator_H

//Pour l'h�ritage
#include "CATSmoSubdivisionMeshOperator.h"

//Pour l'export
#include "CATSmoOperators.h"

#include "CATSobListOfVertex.h"

class CATSobMesh;
class CATSmoMeshTopoModifOperator;


class ExportedByCATSmoOperators CATSmoSubdivisionMatchParameter
{
public:

  // Activation la diffusion
  virtual void SetDiffusion(const double iRatio) = 0;

  // Activation de l'insertion de d�coupes
  virtual void SetCut(const int iNbCut) = 0;

  // Interdiction de modifier la premi�re rang�e
  virtual void DoNotMoveFirstLine() = 0;

  //Recopie de d�tails sur les edges support du match
  virtual void SetCopyDetailsOnEdges(const CATLISTP(CATSobEdge)* ipEdgesWithDetailsToCopy) = 0;

protected:

  //Constructeur
  CATSmoSubdivisionMatchParameter() {}

  //Destructeur
  virtual ~CATSmoSubdivisionMatchParameter() {}

private:

  //No default copy
  CATSmoSubdivisionMatchParameter(const CATSmoSubdivisionMatchParameter&);
  CATSmoSubdivisionMatchParameter& operator=(const CATSmoSubdivisionMatchParameter&);
};


class ExportedByCATSmoOperators CATSmoSubdivisionMatchOperator: public CATSmoSubdivisionMeshOperator
{
public:

  // Destructeur
  virtual ~CATSmoSubdivisionMatchOperator();

  //Ajout de param�tres : le param�tre appartient � l'op�rateur, il ne doit pas �tre d�truit par l'appelant
  virtual CATSmoSubdivisionMatchParameter* AddParameter(const CATLISTP(CATSobEdge)& iListOfEdge,
                                                        const CATBoolean iEdgesAreLinkedForward, const double* iCoordOfVertex, 
                                                        const CATLISTP(CATSobEdge)* ipEdgesWithDetailsToCopy = 0) = 0;

  //Renvoie la liste de vertex sur le bord match�. Ce ne sont pas forc�ment les vertex des edges de iListOfEdge si des faces ont �t� ins�r�es.
  //Les vertex sont ordonn�s de la m�me mani�re que iListOfEdge
  virtual CATSobDiag GetListOfVertexDisplaced(const CATSmoSubdivisionMatchParameter* ipParameter, CATLISTP(CATSobVertex)& oListOfVertex) const = 0;


protected : 

  // Constructeur
  CATSmoSubdivisionMatchOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

private:

  //No default copy
  CATSmoSubdivisionMatchOperator(const CATSmoSubdivisionMatchOperator&);
  CATSmoSubdivisionMatchOperator& operator=(const CATSmoSubdivisionMatchOperator&);
};

ExportedByCATSmoOperators
  CATSmoSubdivisionMatchOperator* CATSmoCreateSubdivisionMatchOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);

#endif





