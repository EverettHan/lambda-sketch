/* -*-C++-*- */

#ifndef CATTopRibC1Utilities_H
#define CATTopRibC1Utilities_H

// COPYRIGHT DASSAULT SYSTEMES 2001

//=============================================================================
//=============================================================================
//
// CATTopRibC1Utilities : Utilitaires pour traiter le C1
//
//=============================================================================

//=============================================================================
// Juil  2002  Creation                               P. Rossignol
//             Responsable                            P. Rossignol
//=============================================================================
//=============================================================================


//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"

// List
#include "ListPOfCATTopRibNuplets.h"

// Autres
#include "CATTopRibDef.h"
#include "ListVOfLong.h"

class CATConnect;
class CATArrayOfNupletsLists;


//
//===========================================================================================================
// Merge les vertex et les listes de nuplets decoupes pour discontinuites C1
// - Service qui fait le vrai boulot
//===========================================================================================================
//
/** @nodoc @nocgmitf */
ExportedByRIBLight void MergeC1CutNuplets2(CATArrayOfNupletsLists &ioNupletsListsArray,
                                      CATTopRibSign           iDirection);

//
//===========================================================================================================
// Detruit les liens entre geonuplets
//===========================================================================================================
//
/** @nodoc @nocgmitf */
ExportedByRIBLight void DestroyGeoLinks(CATArrayOfNupletsLists &ioNupletsListsArray); 

//===========================================================================================================
// Renseignement dans les geonuplets des decoupages geometriques effectues 
// Pour le twist, l'autointersection et bientot le C1
//===========================================================================================================
//ExportedByCATFDGImpl void ManageConnexity(CATConnect * Connect, ListPOfCATTopRibNuplets  *&iNuplet);  
/** @nodoc @nocgmitf */
ExportedByRIBLight void GetGeometryCuttingInfoFromConnect(CATConnect * Connect, CATListOfLong & ioStartInfo, CATListOfLong & ioEndInfo);

//===========================================================================================================
// Renseignement dans les geonuplets des decoupages geometriques effectues 
// Pour le twist, l'autointersection et bientot le C1
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRIBLight void ManageConnexity(CATListOfLong & ioStartInfo, CATListOfLong & ioEndInfo, 
                                   ListPOfCATTopRibNuplets  *&ioNuplet);                         

#endif

