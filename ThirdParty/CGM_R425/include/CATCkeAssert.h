
/**
 * @level Private
 * @usage U1
 */
// Copyright Dassault Systemes 1994 2000
#ifndef _CATCkeAssert_
#define _CATCkeAssert_

#include "CATAssert.h"
#include "CATtraproto.h"

#ifndef _IRIX_SOURCE
#include "CATStackTrace.h"
#endif

#define CkeAssert(assertion) CATAssert(!!(assertion));


/*#ifndef _IRIX_SOURCE
 #ifndef CNEXT_CLIENT
  #define CkeErrorMsg(message)  \
	if (CATDevelopmentStage()) \
	{ \
		printf("\nERREUR KNOWLEDGE : %s\n", message); \
		CATStackTrace pile; \
		pile.GetTrace(); \
		pile.Print(); \
		fflush(0); \
	}
 #else
  #define CkeErrorMsg(message)
 #endif
#else
 #define CkeErrorMsg(message)
#endif
*/
#endif
