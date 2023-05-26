//=============================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//=============================================================================
//
// CATSobEdgeProtected.h
//
//=============================================================================
//
// Usage notes: Services protected des CATSobEdge
//
//=============================================================================
// April,  2021 : RJY1: Modif constructeur pour CATSobMeshBase
// June,   2012 : RAQ : Cr�ation
//=============================================================================
#ifndef CATSobEdgeProtected_H
#define CATSobEdgeProtected_H

//Pour l'export
#include "CATSobObjects.h"

//Structure subdivision
#include "CATSobEdge.h"
#include "CATSobDiag.h"



class CATSobEdgeProtected : public CATSobEdge
{
public:

  //Destructeur
  virtual ~CATSobEdgeProtected() {}
  
  //Inversion de l'edge
  virtual CATSobDiag SwapDirectAndInvertFace() = 0;

  /*--------------------------- Modification de la topologie ---------------------------*/
  //Remplacement d'un vertex de l'edge par un autre
  virtual CATSobDiag ReplaceVertex(CATSobVertex* iOldVertex, CATSobVertex* iNewVertex) = 0;

protected:

  //Constructeur
  CATSobEdgeProtected(CATSobMeshBase* iMesh);

private:

  //Copy constructor and equal operator
  CATSobEdgeProtected(const CATSobEdgeProtected&);
  CATSobEdgeProtected& operator=(const CATSobEdgeProtected&);

};


#endif

