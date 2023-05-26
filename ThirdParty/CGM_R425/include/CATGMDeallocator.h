//=========================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022 - ALL RIGHTS RESERVED.
//
// RESPONSIBLE  : QF2
//
// DESCRIPTION  : Desalloc tools for 
//                  CATLSOHashTable, CATLSOHashMap, CATGMList, CATGMStack, CATGMQueue
//=========================================================================================

#ifndef CATGMDeallocator_H
#define CATGMDeallocator_H

#include "CATSysErrorDef.h" // HRESULT
#include "CATMathematics.h"

// ---------------------------------------------------------------------------------
// Dealloc utilities
//
// To be used with method  HRESULT DeleteAll(T * iElement),
//   in CATLSOHashTable, CATLSOHashMap, CATGMList ...
// ---------------------------------------------------------------------------------
namespace CGM
{
  /* The DesallocFunc is a function pointer.
   * This Deallocator is called to deallocate the data passed in argument. */
  typedef void(*Deallocator)(const unsigned char * idata);

  /**
   * The classic Deallocator, it will use the "delete[]" C++ keyword to deallocate the data.
   * The data must have been allocated with the "new unsigned char[]" C++ keyword.
   */
  ExportedByCATMathematics void DeallocateData(const unsigned char * idata);

  /**
   * Another provided Deallocator, it will not deallocate the data, it will do nothing.
   */
  ExportedByCATMathematics void NoDeallocate(const unsigned char* idata);


#if __cplusplus >= 201103L // >= C++11
/**
  * The DesallocFunc is a function pointer.
  * This Deallocator is called to deallocate the data passed in argument.
  * You may want to use the "delete[]" C++ keyword, or use your own deallocator,
  * or you can do nothing if the data does not need to be deallocated.
  */
  template <class T>
  using DesallocFunc = HRESULT (*) (T * iElement);

#endif

  template <class T>
  HRESULT DeleteDesalloc(T * iElem)
  {
    HRESULT hr = S_OK;
    if (iElem)    
      delete iElem;      
    
    return hr;
  }

  template <class T>
  HRESULT ReleaseDesalloc(T * iElem)
  {
    HRESULT hr = S_OK;
    if (iElem)    
      iElem->Release();     

    return hr;
  }
  
}

#endif /*CATGMDeallocator_H*/
