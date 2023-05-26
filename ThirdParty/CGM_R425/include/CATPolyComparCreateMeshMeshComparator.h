#ifndef  CATCreateMARSMeshMeshComparator_H
#define  CATCreateMARSMeshMeshComparator_H

//====================================================================
// Copyright Dassault Systemes Provence 2011-2016, All Rights Reserved 
//====================================================================
// DESCRIPTION : Cerateurs de l'operateur Projection/Distance de plein de points sur un bon gros maillage
//
//=============================================================================
// HISTORIQUE :
// 05.02.2018 : RAQ : Suppression GPU et Device des signatures
//  07/04/2016 : RNO : Remise au gout du jour 
//=============================================================================

#include "ExportedByCATPolyComparOperators.h"

//STL
#include <array>
#include "CATTolerance.h"

class CATPolyComparMeshMeshComparator;
class CATIPolyMesh;


ExportedByCATPolyComparOperators 
  CATPolyComparMeshMeshComparator * CATPolyComparCreateMeshMeshComparator(const CATIPolyMesh * iFirstMesh, const CATIPolyMesh * iSecondMesh,
                                                              const std::array<double,2> & SamplingTolOnMeshes,  const CATTolerance & iTolObj=CATGetDefaultTolerance());


// [30/1/2017 RNO] : PRIVATE USE ONLY DO NOT USE (UNDER CONSTRUCTION)
ExportedByCATPolyComparOperators
  CATPolyComparMeshMeshComparator * CATPolyComparCreateFastMeshMeshComparator(const CATIPolyMesh * iFirstMesh, const CATIPolyMesh * iSecondMesh, 
                                                                  const std::array<double,2> & SamplingTolOnMeshes);




#endif // CATCreateMARSManyPointsToMeshDistanceOpe_H
