//==============================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//==============================================================================================
//
// CATPolyMeshProjectionOperator.cpp
//
//==============================================================================================
//
// Usage notes: Opérateur de projection sur CATIPolyMesh
//
//==============================================================================================
// 15.11.2018 : RAQ : Déplacement du code dans PolyhedralOperators
// April,   2009 : RAQ : Création
//==============================================================================================
#ifndef CATPolyMeshProjectionOperator_H
#define CATPolyMeshProjectionOperator_H

//Pour l'export
#include "CATPolyMiscellaneous.h"

//Divers
#include "CATSysErrorDef.h"
#include "CATBoolean.h"
#include "CATTolerance.h"
//#include <stddef.h>

class CATIPolyMesh;
class CATMathPoint;
class CATIPolyMeshTriangleIterator;
class CATPolyPointMeshDistanceAccelerator;
class CATPolyPointMeshDistance;


class ExportedByCATPolyMiscellaneous CATPolyMeshProjectionOperator
{
public:

  //Constructeur
  CATPolyMeshProjectionOperator(const CATIPolyMesh& iPolyMesh, CATTolerance *iTolObject=NULL);

  //Destructeur
  ~CATPolyMeshProjectionOperator();

  //Méthodes de calcul de projection
  HRESULT ComputeProjection(const CATMathPoint& iPoint, CATMathPoint& oProjectedPoint);
  HRESULT ComputeProjection(const CATMathPoint& iPoint, CATMathPoint& oProjectedPoint, int& oTriangle, double& oU, double& oV, double& oW);
  HRESULT ComputeProjection(const CATMathPoint& iPoint, int& oTriangle, double& oU, double& oV, double& oW);

private:

  //Init de la projection
  HRESULT InitProjection();
 
  //--------- Data:
  const CATIPolyMesh& _PolyMesh;
  CATBoolean _ProjectionHasBeenInitialized;
  CATIPolyMeshTriangleIterator* _TriangleIterator;
  CATPolyPointMeshDistanceAccelerator* _PolyPointMeshDistanceAccelerator;
  CATPolyPointMeshDistance* _PolyPointMeshDistanceOperator;

  CATTolerance *_TolObject ;
};



#endif





