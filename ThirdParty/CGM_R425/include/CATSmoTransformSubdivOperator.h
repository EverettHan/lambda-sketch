//=================================================================================
// Copyright Dassault Systemes Provence 2011, All Rights Reserved
//=================================================================================
//
// CATSmoTransformSubdivOperator.h
//
//=================================================================================
//
// Usage notes: Application d'une transfo 3D � une subdiv.
//
//=================================================================================
// December,  2011 : RAQ : Creation
//=================================================================================
#ifndef CATSmoTransformSubdivOperator_H
#define CATSmoTransformSubdivOperator_H

//Pour l'h�ritage
#include "CATSmoSubdivisionMeshOperator.h"

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"

class CATSobMesh;
class CATSmoMeshTopoModifOperator;
class CATMathTransformation;



class ExportedByCATSmoOperators CATSmoTransformSubdivOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoTransformSubdivOperator();


protected:

  //Constructeur
  CATSmoTransformSubdivOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

private:

  //No default m�thods
  CATSmoTransformSubdivOperator(const CATSmoTransformSubdivOperator&);
  CATSmoTransformSubdivOperator& operator=(const CATSmoTransformSubdivOperator&);

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoTransformSubdivOperator* CATSmoCreateTransformSubdivOperator(CATSobMesh* iMesh, const CATMathTransformation& iTransfo3D, CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif  //CATSmoTransformSubdivOperator_H

