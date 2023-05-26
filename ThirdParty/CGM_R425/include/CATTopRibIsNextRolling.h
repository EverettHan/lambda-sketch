/* -*-C++-*- */
#ifndef CATTopRibIsNextRolling_H
#define CATTopRibIsNextRolling_H
// COPYRIGHT DASSAULT SYSTEMES 2002

//===================================================================
//
// Utilitaire de CATTopRib 
//
//===================================================================

//===================================================================
// Usage notes:
//-------------------------------------------------------------------------
// Determine si une cellule peut etre un nouveau suppport. 
//
// Warning: Dans certains cas, le EndVertex peut etre nul. Cela correspond 
// -------  a des cas ou l'on ne sait pas encore sur la cellule Link ou va 
//          se faire la transition. IsNextRolling doit etudier la cellule 
//          link de maniere globale dans de tel cas. 
//
// SameDomain est non utilise pour l'instant mais est necessaire si l'on 
// utiliser les orientatiions des faces dans le shell. Peut etre 
// faudra t'il stocker une oriention relative des shells. 
//
// la sortie oOrientation doit contenir:
//
//   - L'orientation relative entre la cellule d'ou l'on vient 
//     (iContact->_BaseCell) et la cellule candidate (Candidate) si elles
//     sont de meme dimensions
//
//   - L'orientation "absolue" de la cellule candidate (Candidate) si elles
//     sont de dimension differentes.
//===================================================================

//===================================================================
// Feb. 02    Creation                         R. Rorato
//===================================================================

#include "CATTopRibDef.h"
#include "ExportedByRIBLight.h"
class CATTopRib;
class CATTopRibNuplet;
class CATSupContact;
class CATVertex;
class CATCell;

ExportedByRIBLight CATBoolean CATTopRibIsNextRolling ( CATTopRib       *iRib,
                                   CATTopRibSign    iDirection, 
                                   CATTopRibNuplet *iNuplet,
                                   const int        iSupp,
                                   CATSupContact   *iContact,				  
                                   CATCell         *iCandidate,
                                   CATBoolean       iSameDomain,
                                   CATTopRibSign   &oOrientation);

// Interne a la methode precedente
ExportedByRIBLight CATBoolean CATTopRibIsNextRollingSmooth ( CATTopRib     *iRib,
                                         CATCell       * iCellSup,
                                         CATCell       * iCandidate,
                                         CATCell       * iLink,
                                         CATVertex     * iEndVertex,
                                         CATTopRibSign & oOrientation);
#endif
