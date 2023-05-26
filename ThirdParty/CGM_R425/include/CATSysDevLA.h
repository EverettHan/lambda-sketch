#ifndef CATSysDEVLA_H
#define CATSysDEVLA_H


#include "CATIAV5Level.h"
#include "CATLib.h"
#include "CATSysDefineLAPRJ.h"


// To be used in source file 
// project##active ==2 signifie que le projet etait de la release precedente 
#define USE_LA_VAR(project,var)   static int DSY_DEV_LA_ISACTIVE_##project##_##var ();\
int DSY_DEV_LA_ISACTIVE_##project##_##var ()                        \
{                                                                   \
  static int var##project##active =-2;                              \
  static int project##active = DSY_PRJ_LA_ISACTIVE_##project() ;    \
  /*printf ("PRJ %d \n", project##active);  */                      \
  if (var##project##active ==-2)                                    \
    {                                                               \
       const char *ptr =CATGetEnv((char*) #var);                    \
       if ( ptr==NULL)                                              \
         var##project##active = -1 ;                                \
        else if (atoi(ptr) ==1)                                     \
	 var##project##active = 1;                                  \
        else                                                        \
         var##project##active = 0 ;                                 \
	}                                                           \
  /*printf ("VAR %d \n", var##project##active);  */                 \
   if ((var##project##active ==1) ||  ( project##active ==2) ||     \
       (( project##active ==1) && (var##project##active !=0)))      \
    return 1;                                                       \
  else                                                              \
    return 0;                                                       \
}                                                                   

#define DEV_LA_ISACTIVE(project, var)    DSY_DEV_LA_ISACTIVE_##project##_##var ()




#endif
