/**
* @level Private
* @usage U1
*/
#ifndef CATOmbCompositeStreamer_H
#define CATOmbCompositeStreamer_H

#define CATOmbCompositeStreamer_pCache

#include "CATOmbLinkTraderForRestrictedAccess.h"

#include "CATVVSURLConnection.h"
#include "CATVVSUrl.h"
#include "CATUnicodeString.h"
#include "CATOmxSR.h"

class CATStorage;
class CATStream;
class CATBinary;
class CATComponentId;
class CATDocument;
class CATOmbComponentLinkSetStreamer;
class CATIOmxBinaryStream;
class CATOmbVirtualStorage;

/**
* class to manage writing operations on a blob
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbCompositeStreamer
{
public:

  /**
  * creates stream helper (object must be deleted by caller)
  *
  * @param iUrl
  *     The reference to the url definig the path of the blob.
  * @return
  *   S_OK   : if succeeded
  *   E_FAIL : if failed
  */
  static HRESULT Create(const CATVVSUrl & iUrl, CATOmbCompositeStreamer *& oStreamHelper);

  static HRESULT CreateFromILB2(CATILockBytes2 & iILB2, CATOmbCompositeStreamer *& oStreamHelper);

  /**
  * Stream data to storage
  *
  * @param iStorageStreamer
  *     The streaming protocol
  * @return
  *   S_OK   : if succeeded
  *   E_FAIL : if failed
  */
  HRESULT StreamLinksTable(CATOmbComponentLinkSetStreamer & iStorageStreamer, bool iWithPLMRelations);
  /**
  * Saves extra data
  *
  * @param iDataName
  *     The stream name.
  * @param iData
  *     The reference to the stream area to stream.
  * @return
  *   S_OK   : if succeeded
  *   S_FALSE : empty stream - nothing has been done
  *   E_FAIL : if failed
  */
  HRESULT StreamData(const CATUnicodeString & iDataName, const CATBinary & iData);

  /**
  * Saves extra data
  *
  * @param iDataName
  *     The stream name
  * @param iLength
  *     The reference to the stream area to stream.
  * @param iBuffer
  *     The reference to the stream area to stream.
  * @return
  *   S_OK   : if succeeded
  *   S_FALSE : empty stream - nothing has been done
  *   E_FAIL : if failed
  */
  HRESULT StreamData(const CATUnicodeString & iDataName, size_t iLength, const unsigned char * iBuffer);

  /**
  * Commits
  *
  * @return
  *   S_OK    : if succeeded
  *   E_FAIL : if failed
  */
  HRESULT Commit();

  ~CATOmbCompositeStreamer();

private:

  CATOmbCompositeStreamer();

  /* forbidden operations */
  CATOmbCompositeStreamer(CATOmbCompositeStreamer &);
  CATOmbCompositeStreamer & operator=(CATOmbCompositeStreamer &);

  CATVVSUrl _Url;
  CATOmxSR<CATILockBytes2> _ILB2;
  CATOmxSR<CATOmbVirtualStorage> _RootStorage;
};

#endif

