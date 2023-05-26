#ifndef CATErrThrowerDeclare_H
#define CATErrThrowerDeclare_H

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "ThickLight.h"

// fonction globale de lancement d'exception destinee a etre passee par 
// pointeur a un utilitaire de gestion d'erreur (CAThkbftier)

// CATErrThrower recoit une CATError*

void ExportedByThickLight CATErrThrower(void* iData);


#endif
