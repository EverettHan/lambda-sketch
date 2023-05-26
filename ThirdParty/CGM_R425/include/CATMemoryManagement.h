#ifndef CATMemoryManagement_H
#define CATMemoryManagement_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0ERROR.h"

#ifdef __cplusplus
#include "CATBaseUnknown.h"
#include "CATNotification.h"

class ExportedByJS0ERROR CATMemoryNotification : public CATNotification
{
  CATDeclareClass;
};
extern "C"
{
#endif
  /**
   * makes a protected malloc
   * in case of failure, calls the "low virtual memory" manager
   */
  ExportedByJS0ERROR void *CATMemAlloc( size_t iSize );
  /**
   * makes a  free of a zone allocated with CATMemAlloc
   */
  ExportedByJS0ERROR void CATMemFree( void * );
  /**
   * makes a  realloc of a zone allocated with CATMemAlloc
   * in case of failure, calls the "low virtual memory" manager
   */
  ExportedByJS0ERROR void *CATMemRealloc( void *, size_t iSize );
  /**
   *   
   */
  ExportedByJS0ERROR void *CATMemRealloc( void *, size_t iSize );


  /**
   * makes a malloc . No control is made during the call
   * This calls permits some application to test if they may allocate
   * big zones.  
   * In case of failure, s the "low virtual memory" manager will NOT be called
   * Caller of CATUnsecuredMemAlloc MUST check the returned pointer
   */
  ExportedByJS0ERROR void *CATUnsecuredMemAlloc( size_t iSize );

  /**
   * makes a realloc . No control is made during the call
   * This calls permits some application to test if they may allocate
   * big zones.  
   * In case of failure, s the "low virtual memory" manager will NOT be called
   * Caller of CATUnsecuredMemRealloc MUST check the returned pointer
   */
   ExportedByJS0ERROR void *CATUnsecuredMemRealloc( void *, size_t iSize );

  /**
   *
   * returns 0 if no memory problem were ever detected
   * returns !=0 if a  memory problem has been detected
   */
   ExportedByJS0ERROR int CATLowMemoryDetection();

  /**
   *
   * try to reset the low memory status
   *  return 0 if OK
   *  return -1 if memory status is still low
   */
   ExportedByJS0ERROR int CATResetLowMemoryStatus();

#ifdef __cplusplus
 }
  /**
   * Returns the object which permits to add a callback to know
   * memory is low
   *
   */
  ExportedByJS0ERROR CATBaseUnknown *CATGetMemoryNotifier();
#else
#endif

#endif

