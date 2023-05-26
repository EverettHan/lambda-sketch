#include "CATV4System.h"

/*Modified by NPM, 23.08.2002. Changes as required by [iaddr] in [iaddr.c_] in [V4SysUTIL] in [CATV4System] */
/*IA64C  Old Code Below
extern "C" ExportedByCATV4System 
        int iaddr(void *x_);
*/
/*IA64+*/
#if defined(PLATEFORME_DS64)
extern "C" ExportedByCATV4System 
        CATINTPTR iaddr(void *x_);

#else
extern "C" ExportedByCATV4System 
        int iaddr(void *x_);

#endif
/*IA64-*/
