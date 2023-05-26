//=============================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 1998
//
// DESCRIPTION :  
//               
//		  
// Code History : 25/08/98 : ATE  - Creation  
// =============	 
//
//=============================================================================

#ifndef CATELFBASTrace_H
#define CATELFBASTrace_H
#include <CATTrace.h>

static CATTrace& ELFBASTrace()
{
  static CATTrace TheTrace("ELFBAS", "[ELFBAS] ",CATTraUnActivated,"STDOUT");
  return TheTrace;
}

#endif
