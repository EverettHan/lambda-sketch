/* -*-c++-*- */
#ifndef CATOmyV5OmcContainerTemporarily_H
#define CATOmyV5OmcContainerTemporarily_H
// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @level Protected
 * @usage U1       
  */

#include "CATOMY.h"

/**
 * Pour le projet split ObjectModelerCATIA\ObjectModelerContBase (ou OMC size Reduction), 
 * activation de la variable NEW_V5_CONTAINERS_PROJECT pour l'activation du nouveau code 
 * des containers en contexte 3DLive.
 * On n'a donc deplacé ces methodes initialement dans ObjectModelerContBase pour un
 * CATGetEnv("NEW_V5_CONTAINERS_PROJECT") oublié dans CATSession.cpp
 * 
 */

ExportedByCATOMY int OmyUseNewV5OmcContainer();
ExportedByCATOMY int OmyUseOmc3DLive();
#endif
 
