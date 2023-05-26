#ifndef _CATPLMDownloaderEntry_H
#define _CATPLMDownloaderEntry_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegration.h"
#include "CATBaseUnknown.h"

class CATPLMDownloader;
class CATPLMDownloaderFlush;
class CATIPLMRecordRead;

class ExportedByCATPLMIntegration CATPLMDownloaderEntry
{
public:

  /**
  * Gets record
  *
  * @return
  *     The record is not addRef-ed
  */
  CATIPLMRecordRead * GetRecord() { return _RecordRead; }

  CATPLMDownloaderEntry() :_RecordRead(nullptr) {};
  CATPLMDownloaderEntry(CATIPLMRecordRead * iRecordRead);
  ~CATPLMDownloaderEntry();

  CATPLMDownloaderEntry(const CATPLMDownloaderEntry&);

private:

  friend class CATPLMDownloader;
  friend class CATPLMDownloaderWithCallBack;
  friend class CATPLMDownloaderFlush;

  CATIPLMRecordRead * _RecordRead;
};

#include "CATOmxCollecManager.h"
template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMDownloaderEntry>::manager();

#endif
