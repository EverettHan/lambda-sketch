#ifndef CATCreateMARSManyPointsToMeshDistanceOpe_H
#define CATCreateMARSManyPointsToMeshDistanceOpe_H

//====================================================================
// Copyright Dassault Systemes Provence 2011-2016, All Rights Reserved 
//====================================================================
// DESCRIPTION : Cerateurs de l'operateur Projection/Distance de plein de points sur un bon gros maillage
//
//=============================================================================
// HISTORIQUE :
// 05.02.2018 : RAQ : Désactivation code GPU, CATPolyComparCreateGPGPUDistanceOpe redirigée sur CPU
//  07/04/2016 : RNO : Remise au gout du jour 
//=============================================================================


#include "ExportedByCATPolyComparOperators.h"
#include "CATTolerance.h"
#include <vector>
class CATPolyComparKernelManager;
class CATPolyComparDeviceContext;
class CATPolyComparManyPointsToMeshDistanceOpe;

//Note see CATPolyComparManyPointsToMeshDistanceOpeImpl for the implementation
ExportedByCATPolyComparOperators
CATPolyComparManyPointsToMeshDistanceOpe * CATPolyComparCreateGPGPUDistanceOpe(const std::vector<CATPolyComparDeviceContext *> & iAllDevicesContext,  const CATPolyComparKernelManager * iKernelManager);

//Note see CATPolyComparManyPointsToMeshCPUDistanceOpeImpl for the implementation
ExportedByCATPolyComparOperators
CATPolyComparManyPointsToMeshDistanceOpe * CATPolyComparCreateCPUDistanceOpe(const CATTolerance & iTolerance=CATGetDefaultTolerance());
#endif // CATCreateMARSManyPointsToMeshDistanceOpe_H
