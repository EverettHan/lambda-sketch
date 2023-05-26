/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
#ifndef CATIAComputeV4Toler_H_
#define CATIAComputeV4Toler_H_
// COPYRIGHT DASSAULT SYSTEMES   1996
//=============================================================================
//
// A partir d'une dimension modele, calcul des tolerances
// sur la base des valeurs recommandees en V4.
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// March. 2000   Creation       O. Siot
//=============================================================================


#include "CATIAEntity.h"

void ExportedByCATIAEntity CATIAComputeV4Toler(double    iModelDimension,
					       double*           oDToler,
					       int*              oIToler) ;

#endif

