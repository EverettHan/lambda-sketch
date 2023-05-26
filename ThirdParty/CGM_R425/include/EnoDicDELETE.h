//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef EnoDicDELETE_H
#define EnoDicDELETE_H

#include "CATLib.h"

//Delete Logical

#undef DELETE_CODE_LOGICAL_1
//Dans un premier temps on efface seulement les Interfaces
#undef DELETE_CODE_LOGICAL_2
//Dans un second temps on efface le code qui interprete l'info
#undef DELETE_CODE_LOGICAL_3  //-- [chd:13.12.2012] on devrait pas passer undef en define, la ?
//Enfin, on l' efface completement du Content Handler

//Dependencies

#ifdef DELETE_CODE_LOGICAL_3
#define DELETE_CODE_LOGICAL_2
#endif

#ifdef DELETE_CODE_LOGICAL_2
#define DELETE_CODE_LOGICAL_1
#endif


//Delete PLMCoreType="Yes" or "No"

#undef DELETE_CODE_PLMCORETYPE_1
//Dans un premier temps on efface seulement l' interface (GetPLMCoreType)
    //ATTENTION ETAPE 1 empeche la compilation
#undef DELETE_CODE_PLMCORETYPE_2
//Dans un second temps on efface le code qui interprete l'info dans le Dico (et on enleve SetPLMCoreType de l'interface)
#undef DELETE_CODE_PLMCORETYPE_3
//Enfin, on l' efface completement du Content Handler

//Dependencies

#ifdef DELETE_CODE_PLMCORETYPE_3
#define DELETE_CODE_PLMCORETYPE_2
#endif

#ifdef DELETE_CODE_PLMCORETYPE_2
#define DELETE_CODE_PLMCORETYPE_1
#endif

#endif /*EnoDicDELETE_H*/
