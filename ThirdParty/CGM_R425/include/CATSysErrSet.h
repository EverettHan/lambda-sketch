#ifndef CATSysErrSet_H
#define CATSysErrSet_H

#include "JS0ERROR.h"
#include "CATErrorDef.h"
class CATError;
class CATSysErrContext;
class CATSysErrChecker;
class ExportedByJS0ERROR CATSysErrSet
{

  friend class CATSysErrContext;
  friend class CATSysErrChecker;

  static HRESULT Add(CATError *);

  static HRESULT StreamAllErrors(int *oNeededSize, int  *oCount, void **oBuffersArray[],int *oLengthsArray[] );

   /**
   ***  Stream the first error into a transportable buffer
   ***  oBuffer : if successful a specific buffer of *oLen size is allocated
   ***            and rendered to the caller 
   ***            When no more needed this buffer must be freed using 
   ***            ReleaseStreamBuffer
   ***  oLen    : if succesful specifies the length of the buffer needed to
   ***            stream the error. (length of the buffer pointed by *oBuffer)
   *** 
   ***  Return values :
   ***       S_OK if successful
   ***       S_FALSE if successful and LAST error of the set
   ***       ! S_OK  and ! S_FALSE if failed
   *** 
   ***/
  static HRESULT StreamNextError(void **oBuffer,int *oLen );

  /*** 
   ***  Allows to free the oBuffer buffer returned by the StreamError method
   ***/

  static HRESULT ReleaseStreamBuffer( void *iBuffer);
  /***
   ***  Create an error initialising with the iBuffer information
   ***  iBuffer : input stream buffer 
   ***  iLen    : length of iBuffer
   ***  oError  : created error if successful 
   *** 
   ***  Return values :
   ***       S_OK if successful
   ***       ! S_OK if failed
   *** 
   ***/
   static HRESULT CreateErrorFromStream(const void *iBuffer,int iLen , CATError **oError );

   static int GetCount() {return S_Count;} ;

   private:
   static CATError *S_First; // first error in the set
   static CATError *S_Last ; // last error in the set
   static int S_Count ; // nb of errors currently in the set
};
#endif
