//=======================================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//=======================================================================================
//
// CATSobNewFaceOrientationChecker.h
//
//=======================================================================================
//
// Usage notes : Check des de la compatibilit� des orientations des parties connexes
//               d'un mesh lors de l'ajout d'une face entre plusieurs parties connexes.
//
//=======================================================================================
// 18.06.2012 : RAQ : Cr�ation
//=======================================================================================
#ifndef CATSobNewFaceOrientationChecker_H
#define CATSobNewFaceOrientationChecker_H

//Pour l'export
#include "CATSobOperators.h"

//Structure subdivision
#include "CATSobDiag.h"
#include "CATSobListOfEdge.h"

//Divers
#include "CATBoolean.h"

class CATSobMesh;


class ExportedByCATSobOperators CATSobNewFaceOrientationChecker
{
public:

  //Constructeur
  CATSobNewFaceOrientationChecker(const CATSobMesh* iMesh);

  //Destructeurs
  virtual ~CATSobNewFaceOrientationChecker();

  //Run de l'op�rateur :
  //iEdgesOfNewFace : edges de la face que l'on veut cr�er
  //ioEdgesHaveValidOrientation : validit� de l'orientation des edges d�j� r�f�renc�es, TRUE si l'orientation est valide, FALSE sinon.
  //oMustReverseConnexOrientations : renvoie TRUE si l'une des orientation des edges n'est pas compatible
  CATSobDiag Run(const CATLISTP(CATSobEdge)& iEdgesOfNewFace, CATBoolean* ioEdgesHaveValidOrientation, CATBoolean& oMustReverseConnexOrientations) const;

private:


  //--------- Data :
  CATSobDiag _Diag;
  const CATSobMesh* _CurrentMesh;

};

#endif  //CATSobNewFaceOrientationChecker_H

