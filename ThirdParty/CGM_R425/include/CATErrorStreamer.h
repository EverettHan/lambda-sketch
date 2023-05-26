#ifndef CATErrorStreamer_H
#define CATErrorStreamer_H
#include "JS0ERROR.h"
// Reserved for expert use.
class ExportedByJS0ERROR CATErrorStreamer : public CATInternalError
{
  public: 
  CATErrorStreamer( CATInternalError &iError );
  CATErrorStreamer( );
  
  /*** 
   ***  Stream the error into a transportable buffer
   ***  oBuffer : if successful a specific buffer of *oLen size is allocated
   ***            and rendered to the caller 
   ***            When no more needed this buffer must be freed using 
   ***            ReleaseStreamBuffer
   ***  oLen    : if succesful specifies the length of the buffer needed to
   ***            stream the error. (length of the buffer pointed by *oBuffer)
   *** 
   ***  Return values :
   ***       S_OK if successful
   ***       ! S_OK if failed
   *** 
   ***/
  HRESULT StreamError(void **oBuffer,int *oLen ) {return Stream(oBuffer,oLen); } ;
  /*** 
   ***  Allows to free the oBuffer buffer returned by the StreamError method
   ***/
  HRESULT ReleaseStreamBuffer( void *iBuffer) {return FreeStreamBuffer(iBuffer) ; };
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
  HRESULT CreateErrorFromStream(const void *iBuffer,int iLen , CATError **oError );
};
//=======================================================================================
#endif
