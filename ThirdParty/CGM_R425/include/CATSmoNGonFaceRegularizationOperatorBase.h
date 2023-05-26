//================================================================================
// Copyright Dassault Systemes Provence 2011, All Rights Reserved
//================================================================================
//
// CATSmoNGonFaceRegularizationOperatorBase.h
//
//================================================================================
//
// Usage notes: Interface pour les op�rateurs de r�gularisation de face ngones.
//      Le mesh N'EST PAS mis � jour.
//
//================================================================================
// June,  2011 : RAQ : Creation
//================================================================================
#ifndef CATSmoNGonFaceRegularizationOperatorBase_H
#define CATSmoNGonFaceRegularizationOperatorBase_H

//Pour l'export
#include "CATSmoOperators.h"

//Structure subdivision
#include "CATSobDiag.h"
#include "CATSobListOfFace.h"
#include "CATBoolean.h"

class CATSobMesh;
class CATSmoMeshTopoModifOperator;


class ExportedByCATSmoOperators CATSmoNGonFaceRegularizationOperatorBase
{
public:

  //Run de l'op�rateur
  virtual CATSobDiag Run() = 0;
  
  //Obtention du diag
  CATSobDiag GetDiag() const;

  //R�cup�ration des nouvelles faces
  const CATLISTP(CATSobFace)& GetNewFaces() const;

  //Teste si la face d'entr�e a �t� supprim�e du mesh
  CATBoolean CheckIfInputFaceHasBeenDeleted() const;


protected:

  //Constructeur
  CATSmoNGonFaceRegularizationOperatorBase(CATSobFace* iNGonFace, CATSmoMeshTopoModifOperator* iTopoModifOperator);

  //Destructeur
  virtual ~CATSmoNGonFaceRegularizationOperatorBase();

  //Set du diag
  CATSobDiag SetDiag(const CATSobDiag iDiag);

  //---------- Data :
  CATSobDiag _Diag;
  CATSobFace* _InputSobFace;
  CATSmoMeshTopoModifOperator* _TopoModifOpe;
  CATLISTP(CATSobFace) _NewFaces;
  CATBoolean _InputFaceHasBeenDeleted;
};


#endif  //CATSmoNGonFaceRegularizationOperatorBase_H


