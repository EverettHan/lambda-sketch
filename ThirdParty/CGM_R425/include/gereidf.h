#include "CATV4System.h"

/*Modified by GTG, 12.09.2002. Safe Pointer Typecast */
/*IA64C  Old Code Below
extern "C" ExportedByCATV4System 
        int gereidf(char *adresse_ref_, int *long_ident_don_, int *code_retour_);*/
/*IA64+*/
%IF (PROJECT64) THEN
#if defined(PLATEFORME_DS64)
extern "C" ExportedByCATV4System 
        CATINTPTR gereidf(char *adresse_ref_, int *long_ident_don_, int *code_retour_);
#else
extern "C" ExportedByCATV4System 
        int gereidf(char *adresse_ref_, int *long_ident_don_, int *code_retour_);
#endif
%ELSE
extern "C" ExportedByCATV4System 
        int gereidf(char *adresse_ref_, int *long_ident_don_, int *code_retour_);
%ENDIF
/*IA64-*/

