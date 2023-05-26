/* -*-C++-*- */

#ifndef CATDBGDefine_H
#define CATDBGDefine_H

// David Bonner doit fournir des API supplementaires pour le disconnect,
// qui permettent de recuperer les edges (resp. faces) pendantes hors
// des faces (resp. volumes) resultants.
#define ATTENTE_DBN

// Le nettoyage des faces non utilisees devrait logiquement etre fait
// par un simple Remove. Ici, il faut tout faire a la main.
#define ATTENTE_RAD

// Le logique DEBUG_THICK permet de lire la variable CATCGMDebugThickPilot qui
// indique le mode d'acces (CATGetEnv / declaratif / defaut) des constantes de
// pilotage de l'algorithme et de decoder au besoin le declaratif de debug et 
// de traces encode dans le fichier $CATCGMDebugThickFile (en general .dbglevel
// dans le $HOME de l'utilisateur).
// cf TopologicalOperators\Thick.m\LocalInterfaces\CAThkDbgPilot.h pour details
#define DEBUG_THICK

// Le logique DEBUG_THICK_SGT sert a activer les points d'arret
// #define DEBUG_THICK_SGT

// le logique DYN_DEBUG_THICK enclenche la relecture de declaratif de debug 
// dans certains constructeurs situes dans les cpp (permet de changer le niveau
// des ecritures ou des checkpoints intercatifs de maniere dynamique)
// Il ne doit pas etre active dans DEBUG_THICK
#define DYN_DEBUG_THICK

#endif

