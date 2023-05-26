#ifndef __CATOxMemUFO_H
#define __CATOxMemUFO_H

/**
 * @level Private
 * @usage U1       
 */

#include "ExportedByCATPLMTos.h"
#include "CATBoolean.h"
#include "IUnknown.h"

class CATOmXStream;
class CATOxTransaction;
class CATUFOImageAssistant;


class ExportedByCATPLMTos CATOxMemUFO 
{
public:

  /** 
  * StoreUFOImage 
  * Streams the UFO diff log since last local save into a CATOmXStream object (which represents a binary file).
  * The purpose of this method is to offer the capability to stream the UFO diff log into a binary file
  *
  * @param oStream
  *   The CATOmXStream in which the UFO diff log is streamed
  *    
  * @return
  *   S_OK if the diff log was streamed
  *   S_FALSE if the diff log is empty
  *   E_FAIL if failure
  *   E_UNEXPECTED if unexpectactions happened
  */

  static HRESULT StoreUFOImage(CATOmXStream & oStream);

  /** 
  * StoreUFOImage 
  * Streams an UFO diff log into a CATOmXStream object (which represents a binary file).
  *
  * @param iDiffLog
  *   The diff log to stream
  *
  * @param oStream
  *   The CATOmXStream in which the UFO diff log is streamed
  *    
  * @return
  *   S_OK if the diff log was streamed
  *   S_FALSE if the diff log is empty
  *   E_FAIL if failure
  *   E_UNEXPECTED if unexpectactions happened
  */

  static HRESULT StoreUFOImage(CATUFOImageAssistant * iDiffLog, CATOmXStream & oStream);

  /** 
  * RestoreUFOImage
  * Untreams the UFO diff log from a CATOmXStream object (which represents a binary file) to
  * reconcile the current UFO log with its state at the moment of its streaming. 
  *
  * @param iStream
  *   The CATOmXStream from which the UFO diff log is unstreamed
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RestoreUFOImage(CATOmXStream & iStream);

  /**
  * Merge an UFO image into another one
  *
  * @param iStream
  *   The CATOmXStream from which the UFO diff log is unstreamed
  *
  * @param ioDiffLog
  *   The UFO log into which the stream is merged
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT MergeUFOImage(CATOmXStream & iStream, CATUFOImageAssistant * ioDiffLog);

  /**
  * Ask the UFO log if there is any information to stream since last local save
  *
  * @return 
  *   TRUE if any
  *   FALSE otherwise
  */
  static CATBoolean IsThereAnyUFOLogToStream();

  /** 
  * UpdateUFOImage 
  * Update an existing stream with the given diff log
  *
  * @param ioStream
  *   The CATOmXStream in which the UFO diff log is streamed
  *    
  * @return
  *   S_OK if the diff log was streamed
  *   S_FALSE if the diff log is empty
  *   E_FAIL if failure
  *   E_UNEXPECTED if unexpectactions happened
  */

  static HRESULT UpdateUFOImage(CATOmXStream & iWriteStream);
	
	/**
	*
	* <br><b>Role</b>: Merge the UFO log contained in the given read stream
	*	with the differential UFO log since last local save.
	*
	* @param iReadStream
	*		the read stream containing a differential UFO log
	* @param oDiffLog
	*		the differential UFO resulting of the merge
	* @return
	* <dl>
	* <dt><code>S_OK</code>everything went right <dd>
	* <dt><code>S_FALSE</code> the diff log is empty<dd>
	* <dt><code>E_FAIL</code> failure<dd>
	* <dt><code>E_UNEXPECTED</code> unexpectations happened<dd>
	* </dl>
	*/
	static HRESULT MergeStreamWithUFOImageSinceLastLocalSave(CATOmXStream & iReadStream, CATUFOImageAssistant & oDiffLog);
};

#endif
