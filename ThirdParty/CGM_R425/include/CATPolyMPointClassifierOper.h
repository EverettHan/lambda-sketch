//====================================================================
// Copyright Dassault Systemes Provence 2008, all rights reserved 
//====================================================================
//
//======================================================================
// 22 Juillet  2008 : Creation (Migration Cld To Poly Code de NDO)    ANR
//======================================================================
#ifndef CATPolyMPointClassifierOper_h
#define CATPolyMPointClassifierOper_h

//Pour l'export
#include "CATPolyTrimOperators.h"

//Divers
#include "CATBoolean.h" 
#include "CATMathPoint.h" 
#include "CATTolerance.h"

class CATIPolyMesh; 
class CATPolyMPoint;

class ExportedByCATPolyTrimOperators CATPolyMPointClassifierOper
{
public:

  CATPolyMPointClassifierOper(CATTolerance *iTolObject=NULL);
  ~CATPolyMPointClassifierOper();

  CATBoolean Classify(CATIPolyMesh* iPolyMesh, int iFaceIndex, const CATMathPoint& iPoint, CATPolyMPoint& oMeshPoint) const;

  CATBoolean Classify( CATIPolyMesh* iPolyMesh, const int iNoVertex1, const int iNoVertex2, const CATMathPoint& iPoint, CATPolyMPoint& oMeshPoint) const;

private:

  CATTolerance *_TolObject ;
};

#endif


