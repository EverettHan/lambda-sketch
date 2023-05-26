/* -*-C++-*-*/
#ifndef CATComplementairesFixed_H
#define CATComplementairesFixed_H
// COPYRIGHT DASSAULT SYSTEMES 2004
//----------------------------------------------------------------------------------------------
// Complémentaires :
//   Activable par variable d'environnement
//             ou par versionning
//----------------------------------------------------------------------------------------------
#include "RibbonLight.h"
#include "CATBoolean.h"

class CATSoftwareConfiguration;

extern ExportedByRibbonLight CATBoolean CATComplementairesFixed(CATSoftwareConfiguration * iConfig);

extern ExportedByRibbonLight CATBoolean CATComplementairesFix_2(CATSoftwareConfiguration * iConfig);

#endif

