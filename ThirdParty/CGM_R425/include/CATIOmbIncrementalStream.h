#ifndef __CATIOmbIncrementalStream_H
#define __CATIOmbIncrementalStream_H 1

/**
 * @level Protected 
 * @usage U1
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATUuid.h"
#include "CATOmxOMap.h"
#include "CATOmxKeyString.h"
#include "CATOmxAny.h"
#include "CATIOmxBinaryStream.h"
#include "CATIAV5Level.h"

#ifdef CATIAR420
#define CATIOmbIncrementalStreamMigratedForFail
#endif

extern ExportedByAD0XXBAS IID IID_CATIOmbIncrementalStream;

class ExportedByAD0XXBAS CATIOmbIncrementalStream: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /*
   * enum representing streaming mode
   *   Full: container must be fully streamed
   *   Incremental: only an increment must be streamed
   *   NoStream: No stream is required
   */
  enum StreamMode {Full,Incremental,NoStream};

  /**
  * Check if incremental streaming can be used on this container.
  * @param iLastStreamStamp
  *    Stamp of the last stream of this container.
  *    Notice that if stamp does not have expected value incremental save must be refused (see next parameter).
  * @param ioIncrementalMode
  *    in input:  if Full, container will not be saved incrementally, value must not be changed.
  *    in output: if Incremental in input, application can set it to Full meaning container cannot be saved incrementally or to NoStream meaning no stream is required at all.
  *    Notice that even if ioIncrementalMode is TRUE in output of the method container may be streamed fully.
  * @param ioInfos
  *    Statistics on container and increment content.
  *    Legal attributes:
  *      "NumberOfObject": (output) a positive integer representing the number objects in the container
  *      "NumberOfStreamedObject": (output) a positive integer representing the number of object that will be streamed in next increment.
  *    (Object is here an application specific concept that may not represent the number of "members" in container.)
  *    Attributes "ObjectCount" and "StreamedObjectCount" if filled will be used by infrastructure.
  *      "Version": (ouput) positive integer representing version of the application counters.
  *      "NumberOfIncrements": (input) The number of increments yet present in the stream
  *    
  * @return
  *   S_OK
  *   E_NOTIMPL: incremental stream is not implemented for this container. CATI[New]Stream implementation will be used.
  *   E_XXX: an error occured, stream process will be aborted
  * Notes: 
  *    Implementation of this method should take a negligible amount of time compared to full stream.
  *  This method will always be called before following one.
  *  It may be called twice (first time with ioStreamMode=Incremental, second ioStreamMode=Full) if incremental save cannot be performed.
  */
  virtual HRESULT QueryContainerForIncrementalStream(const CATUuid& iLastStreamStamp,StreamMode& ioStreamMode,CATOmxOMap<CATOmxKeyString,CATOmxAny>& ioInfos) = 0;

  /**
  * Stream container content.
  * @param iNewStreamStamp
  *   Identifier for the new version of the stream.
  * @param iStreamMode
  *   if Incremental, only new increment of the container must be streamed
  *   Else if Full, content of container must be fully streamed.
  *   NoStream value cannot be passed
  * @param iStream
  *   Binary stream.
  * @return 
  *   S_OK: success
  *   E_XXX: an error occured, stream process will be aborted (E_NOTIMPL is forbidden)
  */
  virtual HRESULT IncrementalContainerStream(const CATUuid& iNewStreamStamp,StreamMode iStreamMode,CATIOmxBinaryStream& iStream) = 0;

  /**
  * Unstream container content.
  * @param iStreamStamp
  *   Identifier for this version of the stream.
  * @param iIndex
  *   Increment index [1,iLastIndex]
  *   If index is 1 then iStream contains a full stream
  *   Else it contains a stream increment.
  *    iIndex increases with increments date.
  * @param iLastIndex
  *    Increment last index [1,+inf[
  * @param iStream
  *   Binary stream.
  * @param iStreamLength
  *   Length in bytes of the binary stream.
  * @return 
  *   S_OK: success
  *   E_XXX: failure (E_NOTIMPL is forbidden)
  * Notes:
  *  Interface implementation will be called sequentially with a constant iStreamStamp/iLastIndex and iIndex being incremented from 1 up to iLastIndex
  */
  virtual HRESULT IncrementalContainerUnstream(const CATUuid& iStreamStamp,CATIOmxBinaryStream& iStream,CATLONG64 iStreamLength,int iIndex,int iLastIndex) = 0;

  /**
  * Callback method when CATDocument has ended its streaming.
  * @param iRollbackNecessary
  *   if set to TRUE, it means the stream failed, and a session rollback of the incremental stream container is needed. Else incoherency will might occur during next stream of this container.
  *   if set to FALSE, the stream has been successful and no special action is required
  * @return
  *   S_OK : everything ran well
  *   E_FAIL : error occured
  */
#ifdef CATIAR420
  virtual HRESULT OnDocumentStreamCompleted(CATBoolean iRollbackNecessary) = 0;
#endif
};

#endif
