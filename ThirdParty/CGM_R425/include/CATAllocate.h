#ifndef CATAllocate_H
#define CATAllocate_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATAllocate : macro to encapsule the allocation or an array in a method.
//
// DESCRIPTION : the operator new is called only if necessary
// NOTE that this is efficient only if not default constructor of the class
// whose an array is needed must be called.
//
//=============================================================================
//
// History
//
// Sep. 97   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

//------------------------------------------------------------
// Type is the type of the variable one needs an array
// Variable is the name of the allocated array
// NeededSize is the size of the array of Type needed
// HardSize is the size that will be allocated in the heap
//------------------------------------------------------------

#define CATAllocate(Type, DataToAllocate, NeededSize, HardSize)                \
  Type   CATLocal##DataToAllocate [HardSize];                                  \
  Type * CATVAllocated##DataToAllocate = 0;                                    \
  Type * DataToAllocate;                                                       \
                                                                               \
  if (NeededSize > HardSize)                                                   \
    {                                                                          \
      CATVAllocated##DataToAllocate = new Type [NeededSize];                   \
      DataToAllocate =   CATVAllocated##DataToAllocate;                        \
    }                                                                          \
  else                                                                         \
    {                                                                          \
      DataToAllocate = CATLocal##DataToAllocate ;                              \
    };

/*
      CATVAllocated##DataToAllocate =  new Type [NeededSize];                  \ 
      DataToAllocate = CATVAllocated##DataToAllocate ;                         \
    }                                                                          \
  else                                                                         \
    {                                                                          \
      DataToAllocate = CATLocal##DataToAllocate ;                              \
    }                                                                          
*/
#define CATEndAllocate(DataToAllocate)                                         \
  if (CATVAllocated##DataToAllocate )                                          \
    {                                                                          \
      delete [] CATVAllocated##DataToAllocate ;                                \
      CATVAllocated##DataToAllocate = 0;                                       \
    } 

#endif
