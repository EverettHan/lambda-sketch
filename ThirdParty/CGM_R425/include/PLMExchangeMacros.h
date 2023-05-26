//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// PLMExchangeMacros.h
//
//===================================================================
//
// Usage notes:
//   Some usefull macros
//
//===================================================================
//  July 2014  Creation: JLM (Create some usefull macros to reduce code size)
//===================================================================
#ifndef PLMExchangeMacros_H
#define PLMExchangeMacros_H

#include "CATSysMacros.h"
#include "CATLISTP_Declare.h"

// Release all pointers of a list of pointers
#define CATLISTP_APPLY_RELEASE( LP ) \
  CATLISTP_FORWARD_LOOP( LP, itr )   \
    CATSysReleasePtr( (LP)[itr] )    \
  CATLISTP_END_LOOP

// AddRef all pointers in the list.
#define CATLISTP_APPLY_ADDREF( LP )   \
{                                     \
  CATLISTP_FORWARD_LOOP( LP, itr )    \
    LP[itr]->AddRef();                \
  CATLISTP_END_LOOP                   \
}

// Remove all elements from list.
#define CATLISTP_APPLY_REMOVEALL( LP ) \
  CATLISTP_APPLY_RELEASE( LP ) ;       \
  LP.RemoveAll()

// Clean a pointer on a list of pointers
#define CATLISTP_APPLY_RELEASE_P( PLP ) \
  if( PLP ) {                           \
    CATLISTP_APPLY_RELEASE( (*PLP) )    \
    delete PLP;                         \
    PLP = NULL;                         \
  }

#endif
 
