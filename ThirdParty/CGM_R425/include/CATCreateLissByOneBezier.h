//====================================================================
// Copyright Dassault Systemes Provence 2003-2015, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
//    28/07/15 : MMO : Mini-migration Xscale (operateur obsolette) ajout de iTolObject
//  Avril 2003 : anr : Creation 
//====================================================================

#ifndef CATCreateLissByOneBezier_H 
#define CATCreateLissByOneBezier_H
 
#include "MathCascade.h"

#include "CATDataType.h"
#include "CATSkillValue.h"

#include "CATTolerance.h"

class CATMathSetOfPointsND;
class CATLissByOneBezier ;

//====================================================================
//
//====================================================================
ExportedByMathCascade 
CATLissByOneBezier * CATCreateLissByOneBezier( const CATTolerance & iTolObject,
                        CATLONG32                  iNbCrv3d,
											  CATLONG32                  iNbCrv2d,
											  CATMathSetOfPointsND **iPoints,
											  CATLONG32                  iFirstPoint,
											  CATLONG32                  iLastPoint,
											  CATLONG32                 **iConstraints,
											  double               *iParameters,
											  CATLONG32                  iDegree,
											  double                iTol,
											  CATLONG32                  iIterations,
											  CATSkillValue         iMode=BASIC);


//====================================================================
//
//====================================================================
ExportedByMathCascade void Remove( CATLissByOneBezier *&iLissByOneBezier);

#endif
