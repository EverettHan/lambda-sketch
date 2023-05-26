#ifndef __CATIOmxBinaryStreamDictionary_H
#define __CATIOmxBinaryStreamDictionary_H

#include "CATOmxSharable.h"
#include "CATOmxArray.h"
class CATWOmxBinaryStream;
class CATOmxKeyString;

/**
 * This interface allows to override the way CATOmxKeyString and CATUuid are written in CATWOmxBinaryStream
 * Default implementation uses CATWOmxBinaryStream format.
 */
class ExportedByCATOmxKernel CATIOmxBinaryStreamDictionary: public CATOmxSharable
{
public:
  virtual void WriteKeyString(CATWOmxBinaryStream& w,const CATOmxKeyString& iKey);
  virtual void ReadKeyString(CATWOmxBinaryStream& w,CATOmxKeyString& oKey);
  virtual HRESULT GetKeys(CATOmxArray<CATOmxKeyString>& oDictionary) const;
  virtual void WriteUuid(CATWOmxBinaryStream& w,const CATUuid& iUuid);
  virtual void ReadUuid(CATWOmxBinaryStream& w,CATUuid& oUuid);
  virtual ~CATIOmxBinaryStreamDictionary();

  /**
   * Returns an object which optimizes writing of CATOmxKeyString and CATUuid by using history.
   * @param iInherited:
   *   Another dictionary (should be a constant loaded from a resource file).
   */
  static CATOmxSR<CATIOmxBinaryStreamDictionary> Create(const CATIOmxBinaryStreamDictionary* iInherited = NULL);
  /**
   * The same but with predefined set of "known" keys.
   */
  static CATOmxSR<CATIOmxBinaryStreamDictionary> CreateWithKnownKeys(const CATOmxArray<CATOmxKeyString>& iKnownKeys);
};

#endif
