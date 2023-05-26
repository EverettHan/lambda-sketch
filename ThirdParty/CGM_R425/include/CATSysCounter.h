
// COPYRIGHT DASSAULT SYSTEMES 2002



/****************************************************
 * Definition de la classe CATSysCounter            *
 ****************************************************/

/*
 * Definition des macros utilisant la classe CATSysCounter
 */

# ifndef CATSYSCOUNTERCLASS_H
# define CATSYSCOUNTERCLASS_H

#include "CATSysCounterInfra.h"

/*
 * Definition de la macro CATSysCounterStandard
 */
#define CATSysCounterStandard(iKey,iFamily)                             \
{                                                                       \
    static CATSysCounter lMyCounter##iKey;                              \
    if (! lMyCounter##iKey.GetRef())                                    \
        CATSysCounterInfra::Get(#iKey ,&lMyCounter##iKey, #iFamily,1);  \
    else                                                                \
        CATSysCounterInfra::Modify(lMyCounter##iKey.GetRef(), 1);       \
}                                                                       \

  //flag du compteur mis a 1 parce que standard


/*
 * Definition de la macro CATSysAdvCounterDelta
 */
#define CATSysAdvCounterDelta(lACHandle,iKey, iFamily,iDeltaValue)      \
{                                                                       \
    if( 0 == lACHandle.GetRef())                                        \
        CATSysCounterInfra::Get(#iKey,&lACHandle,#iFamily,0);           \
    else                                                                \
        CATSysCounterInfra::Modify(lACHandle.GetRef(),iDeltaValue);     \
}                                                                       \

  //flag du compteur mis a 0 parce que advanced


/*
 * Definition de la macro CATSysAdvCounterModify
 */
#define CATSysAdvCounterModify( lACHandle, iDeltaValue)                 \
    CATSysCounterInfra::Modify( lACHandle.GetRef(),iDeltaValue);        \


/*
 * Definition de la macro CATSysAdvCounterAdd1
 */
#define CATSysAdvCounterAdd1( lACHandle )                               \
    CATSysCounterInfra::Modify(lACHandle.GetRef(), 1);                  \


/*
 * Definition de la macro CATSysAdvCounterSet
 */
#define CATSysAdvCounterSet( lACHandle, lValue )                        \
    CATSysCounterInfra::Set( lACHandle.GetRef(), lValue);               \



# endif /* CATSYSCOUNTERCLASS_H */




