/**
* @level Private
* @usage U1*/
#ifndef CATOmbCompositeUnstreamer_H
#define CATOmbCompositeUnstreamer_H

#include "CATOmbLinkTraderForRestrictedAccess.h"

#include "CATVVSURLConnection.h"
#include "CATVVSUrl.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATOmxSR.h"
#include "CATOmxArray.h"

class CATStorage;
class CATBinary;
class CATVVSURLConnection;
class CATVVSUrl;
class CATOmbComponentLinkSetUnstreamer;
class CATOmbVirtualStorage;
class CATDocument;
class CATPLMTypeH;

/**
* class to manage  reading operations on a blob dedicated to external links
* structured in three independant parts : CATDocumentProperty, feature data, applicative data
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbCompositeUnstreamer
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
  static HRESULT Create(const CATVVSUrl& iUrl, CATOmbCompositeUnstreamer*& oStreamHelper);

  /**
  * creates stream helper (object must be deleted by caller)
  *
  * @param iUrlConnection
  *     The connection to the blob.
  * @return
  *   S_OK   : if succeeded
  *   E_FAIL : if failed
  */
  static HRESULT Create(const CATVVSURLConnection& iURLConnection, CATOmbCompositeUnstreamer*& oStreamHelper);

  /**
  * Open connection for CuteIO usage
  *
  * @param iURL
  *        The resource locator
  * @param iMarkStamp
  *        The resource marskstamp
  * @param iLateType
  *        The resource latetype 'CATLnk'
  * @param oConnection
  *        The created connection
  * @return
  *        S_OK   : if succeeded
  *        E_FAIL : if failed
  * OpenConnection "ThrowCuteIO", seriously ?
  */
  static HRESULT OpenConnectionThrowCuteIO(CATVVSUrl& iURL, int iMarkStamp, const CATUnicodeString& iLateType, CATVVSURLConnection*& oConnection);

  /**
  * Unstream data from storage
  *
  * @param iStorageUnstreamer
  *     The unstreaming protocol
  * @return
  *   S_OK   : if succeeded
  *   E_FAIL : if failed
  */
  HRESULT UnstreamData(CATOmbComponentLinkSetUnstreamer& iStorageUnstreamer);

  /**
  * Load extra data
  *
  * @param iDataName
  *     The stream name.
  * @param oData
  *     The reference to the stream area.
  * @return
  *   S_OK   : if succeeded
  *   S_FALSE : empty stream - nothing has been done
  *   E_FAIL : if failed
  */
  HRESULT UnstreamData(const CATUnicodeString& iDataName, CATBinary& oData);

  ~CATOmbCompositeUnstreamer();
private:
  CATOmbCompositeUnstreamer(CATOmbVirtualStorage& iStorage) :_RootStorage(&iStorage) {}
  /* forbidden operations */
  CATOmbCompositeUnstreamer(CATOmbCompositeUnstreamer&);
  CATOmbCompositeUnstreamer& operator=(CATOmbCompositeUnstreamer&);

  CATOmxSR<CATOmbVirtualStorage> _RootStorage;
};

#endif

