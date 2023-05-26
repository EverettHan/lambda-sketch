#ifndef _CATTosAliasStreamReader_H
#define _CATTosAliasStreamReader_H
/**
* @level Private
* @usage U3
*/
#include "CATBaseUnknown.h"
#include "ExportedByCATPLMTos.h"
#include "CATPLMID.h"
#include "CATOmxArray.h"

class CATUnicodeString;
class CATComponentIdAliasCache;
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATComponentIdAliasCache>::manager();

/**
* To be used for extracting informations from alias stream
*/
class ExportedByCATPLMTos CATTosAliasStreamReader
{
public:
  CATTosAliasStreamReader(const CATPLMID & iPLMId);
  ~CATTosAliasStreamReader();

  /**
  * Extract stream contents
  *
  * @param iAliasStream
  * @param iAliasStreamSize
  * @return 
  *        S_OK   : if succeeded
  *        E_FAIL : if failed
  */
  HRESULT Open (char * iAliasStream, size_t iAliasStreamSize);

  /**
  * Alias access for a given position
  *
  * @param iPosition
  *        position start at 1.
  * @param iAlias
  *        The Alias.
  * @return 
  *        S_OK         : if succeeded
  *        E_INVALIDARG : if position out of bounds
  *        E_FAIL       : if failed
  */
  HRESULT GetAlias (int iPosition, CATUnicodeString & oAlias);

  HRESULT GetStoredAttributes(int iPosition,CATLISTV(CATString) &oAttributeName,CATLISTV(CATUnicodeString) &oAttributeValue);

private:
  CATOmxArray<CATPLMID_Simple> _PLMIDs; 
  CATOmxArray<CATComponentIdAliasCache> _Cache;
};

#endif
