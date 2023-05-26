/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmyAsyncSupport_h__
#define __CATOmyAsyncSupport_h__

#ifndef _MOBILE_SOURCE
#define  CATOMY_SUPPORT_ASYNC
// Prevent using this macro in your code... You shall always build. 
#define CATOMY_MP_ASYNC_BUILD

#define  CATOMY_MP_ASYNC_RUNTIME
#endif

#ifdef CATOMY_MP_ASYNC_RUNTIME
#include "CATOmyAsyncServices.h"
#define CATOMY_ASYNC_MASTER CATOmyAsyncServices::IsAsyncMaster()
#else
/** ! CATOMY_SUPPORT_ASYNC ther is no slave process */
#define CATOMY_ASYNC_MASTER 1
#endif

#endif
