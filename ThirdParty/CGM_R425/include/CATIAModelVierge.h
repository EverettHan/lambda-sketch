/**
 * @level Protected
 * @usage U1
 */
//-----------------------------------------
// _  scz - juillet 2000  _
// Routine de Creation d'un model vierge
// NB : penser a faire le menage apres
//      l'appel de cette routine a l'aide
//      de gimdel
//-----------------------------------------

#ifndef CATIAModelVierge_h
#define CATIAModelVierge_h

#include "ExportedByCATIAEntity.h"

class CATIAModel ;

#ifndef L1FALSE
#define L1FALSE 0x00
#endif

ExportedByCATIAEntity CATIAModel* CreateNewModel() ;
ExportedByCATIAEntity void        AddHistoric( CATIAModel* ) ;

#endif
