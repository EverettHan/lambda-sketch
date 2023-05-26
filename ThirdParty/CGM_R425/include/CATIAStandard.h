/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
#ifndef CATIAStandard_H
#define CATIAStandard_H

// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// Quelques services d'acces au standard :
//
//=============================================================================
// Creation : O. GUILLAUME le 25/04/2000
//
//=============================================================================

#include "ExportedByCATIAEntity.h"

class CATIAModel ;

// --------------------------------------------------
//  Acces aux epaisseurs dans le standard de couleur
// --------------------------------------------------
// Si valeur de retour != 0, il y a eu un probleme ..
// ATTENTION : thickness est un double, MAIS en V4 c'etait un R4
// La valeur de indice est comprise entre 1 et 6
ExportedByCATIAEntity int GetThickness( CATIAModel* const &mnum, int indice, double& thickness ) ;

// -----------------------------------------------------------------------------------
//  Acces a la valeur d'indice correspondant a l'epaisseur visualisee la plus faible.
//  Pour les epaisseurs superieures, on tient compte de la couleur de l'element
// -----------------------------------------------------------------------------------
ExportedByCATIAEntity int GetFirstVisibleThickness( CATIAModel* const &mnum, int& indice ) ;

// --------------------------------------------------
//  Acces a la densite dans le Standard
// --------------------------------------------------
ExportedByCATIAEntity int GetDensity(CATIAModel* const& mnum,
				     double& Msur, double& Mvol,
				     int& ier) ;
#endif
