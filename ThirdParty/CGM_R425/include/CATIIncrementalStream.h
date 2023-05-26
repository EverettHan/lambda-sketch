// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATIIncrementalStream.h
// Define the CATIIncrementalStream interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2002  Creation: Code generated by the CAA wizard  NHN
//  Aug 2009  Full Redesign for CGM Incremental Streaming
//===================================================================
/**
* @level Protected
* @usage U4 @see CATOmbIncrementalStreamAdpator
*/

#ifndef CATIIncrementalStream_H_v1
#define CATIIncrementalStream_H_v1

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"

class CATOmbIncStream;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAD0XXBAS IID IID_CATIIncrementalStream;
#else
extern "C" const IID IID_CATIIncrementalStream ;
#endif

/**
* This interface allows a container of a FeatureDocument (CATPart, CATDrawing...) to be persisted incremmentally 
* within a composite file
* 
*/
class ExportedByAD0XXBAS CATIIncrementalStream: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Enumeration to describe how the container will be persisted
  * @param FULL
  *     All the content of the container has to be streamed. 
  * @param DELTA
  *     Only modified part from the last unstream/stream transaction of the container has to be streamed
  * @param NOTHING
  *     The container has not been modified since last save. Nothing to stream
  */
  enum OmbStreamMethod
  {
    FULL =0,
    DELTA =1,
    NOTHING =2
  } ;

  /**
  * This service allows the stream layer to ask the implementation of the container the best 
  * way to stream the content to determine if it worth to stream incrementally. 
  * @param iOmbAdvice
  *   <code>
  *     <li/> FULL : Streaming is performed in Propagate Context
  *     <li/> DELTA : Streaming is performed in Warmstart Context
  *   </code>
  * @return 
  *   the applicative implementation choice  
  */  
  virtual CATIIncrementalStream::OmbStreamMethod PreferredMethodToStream(CATIIncrementalStream::OmbStreamMethod& iOmbAdvice)=0 ;

  /**
  * Method used to stream containers.
  * @param ioStream 
  *   pointer to a CATStream created during save operations and used to stream on disk.
  * @param iMethodToStream 
  *   how the the container will be streamed.
  *   Note : 
  *       In FULL Stream, the provided CATStream will be emptied
  *       In Incremental Stream, the provided CATStream will contain the previous content of the stream. 
  *       New data will be appened to this previous content
  * @param oWriteError
  *       It should be true if the error is due to a writing problem (error generated by CATStream write problem).
  *
  * It is forbidden to perform seek within the catstream in Incremental Mode !
  */
  virtual HRESULT Stream(CATOmbIncStream& ioStream, CATIIncrementalStream::OmbStreamMethod iMethodToStream, CATBoolean& oWriteError) =0 ;

  /**
  * Method used to unstream containers.
  * @param iStream
  *        The persisted content of the container. Note iStream starts with the full persisted stream of the container 
  *        and may be followed by DELTA stream of the container in the chronological order  
  * @param oModelError
  *    In case of inconsistency of the data read, oModelError should be valuated at true and return E_FAIL. Consider raising a CATSaveLoadError 
  *    In case of an system error (i.e read error ) HRESULT should return an "FAILED" rc. 
  * @return 
  * <code>S_OK</code> Container has been streamed with no error
  * <code>E_*</code> Error has been raised while streaming the container. Check oModelError to determine the nature of the error
  * 
  */
  virtual HRESULT UnStreamContainer (CATOmbIncStream& iStream, CATBoolean& oModelError) =0 ;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIIncrementalStream , CATBaseUnknown ) ;

#endif
