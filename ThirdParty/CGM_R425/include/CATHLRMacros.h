#ifndef CATHLRMacros_H
#define CATHLRMacros_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRMacros : macros useful for the developper
//
// DESCRIPTION : 
//   - HLRDELETE delete a pointed object only if the pointer is non NULL
//   - HLRDELETEARRAY  does the same, but assumes the pointer is an array
//
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================


#define HLRDELETE(Pointer)                 \
if (Pointer)                               \
  {                                        \
    delete Pointer;                        \
    Pointer = 0L;                          \
  }

#define HLRDELETEARRAY(Pointer)            \
if (Pointer)                               \
  {                                        \
    delete [] Pointer;                     \
    Pointer = 0L;                          \
  }

#define HLRFREE(Pointer)   \
if (Pointer)               \
  {                        \
    free(Pointer);         \
    Pointer = NULL;        \
  }

#endif
