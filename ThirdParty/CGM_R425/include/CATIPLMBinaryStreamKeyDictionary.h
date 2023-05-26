#ifndef __CATIPLMBinaryStreamKeyDictionary_H
#define __CATIPLMBinaryStreamKeyDictionary_H

#include "CATIOmxBinaryStreamDictionary.h"
#include "CATPLMImplAdapterItf.h"

/**
 * CATIOmxBinaryStreamDictionary derived interface allowing to stream CATOmxKeyString in a centralized separate file.
 * This can allow sharing of the keys (typically PLM attributes names) among separate streams (typically PLM attributes blocks)
 */
class CATIPLMBinaryStreamKeyDictionary: public CATIOmxBinaryStreamDictionary
{
public:
  /**
   * Open the key dictionary, if the file does not exist we consider it has not been created yet and it will be created at first write.
   */
  virtual HRESULT Open(const CATUnicodeString& iPath) = 0;

  /**
   * This must be called after a write "transaction" to ensure newly added keys are written to the disk and opened file (if opening was necessary) is Closed.
   */
  virtual HRESULT Flush() = 0;

  /**
   * Factory
   */
  static ExportedByCATPLMImplAdapterItf CATOmxSR<CATIPLMBinaryStreamKeyDictionary> Create();
};

#endif
