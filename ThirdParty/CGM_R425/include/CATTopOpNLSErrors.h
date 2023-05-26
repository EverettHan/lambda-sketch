#ifndef CATTOPOPNLSERRORS_H
#define CATTOPOPNLSERRORS_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATTopOpErrorConverter.h"
#include "CATErrorMacros.h"
#include "CATErrorMacrosCGM.h" // for CATCatchSecured

// NLD011010: ce Catch est forcement securise dans la mesure
// ou il reemet une erreur sans acceder a aucune donnee locale non volatile
// on remplace donc CATCatch par CATCatchSecured
// NLD300112: remplacement de CATCatchSecured par CATCatchAlwaysSecured
// pour compatibilite avec nouvelle implementation des macros,
// sachant que l'on n'est pas forcement passe par CATTrySecured
#define CATTopOpNLSErrors  CATCatchAlwaysSecured(CATError,error) \
  {CATTopOpErrorConverter(error);\
CATRethrow;}                                                  
                                                   

#endif 
