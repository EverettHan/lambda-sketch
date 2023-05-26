#ifndef CATFortranCB_H
#define CATFortranCB_H
/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATFortranCB                                                             */
/*                                                                           */
/*===========================================================================*/
/*  Creation Novembre 1996                                  sgt              */
/*===========================================================================*/

extern "C" 
{
#include <stdarg.h>
}
typedef  const char  *CATFortranCBEvent;
typedef void (*CATFortranFunction)(...);
typedef  long              CATFortranCB;
#endif
