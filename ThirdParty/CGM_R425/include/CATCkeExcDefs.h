
/**
 * @level Private
 * @usage U1
 */
// Copyright Dassault Systemes 2000
#ifndef CATCkeExcDefs_h
#define CATCkeExcDefs_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Adapter Implementations
// 	declaration of cke exceptions used in NameSpace
//
//
//////////////////////////////////////////////////////////////////////////
/*
$Log: CATCkeExcDefs.h,v $
 * Revision 1.2  1997/06/20  07:35:13  frh
 * *** empty log message ***
 *
 * Revision 1.1  1997/04/03  15:02:59  aal
 * Initial revision
 *
 *
*/

#include "CATCkeExc.h"
#include "CATCkeAssert.h"

#define Try    	   CATTry
#define EndTry	   CATEndTry
#define Catch(X,v) CATCatch (CATCke##X,v)
#define CatchAll   CATCatchOthers
#define Raise(X)   { CATCkeRaiseExc::Locate (__FILE__, __LINE__); \
                     CATCkeRaiseExc::Raise##X; }

#define Assume(X)  if (!(X)) Raise (AssertFailed())
//#define Assume(X) {if (!(X)) assert(0);}


#endif

