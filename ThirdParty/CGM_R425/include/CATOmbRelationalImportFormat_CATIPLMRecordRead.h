#ifndef _CATOmbRelationalImportFormat_CATIPLMRecordRead_H
#define _CATOmbRelationalImportFormat_CATIPLMRecordRead_H

/**
 * @level Private
 * @usage U1
 */

#include "IUnknown.h"
#include "CATOmbRelationalImportFormat.h"
#include "CATOmbLinkTraderForRestrictedAccess.h"

class CATIPLMRecordRead;
class CATOmbRelationImport;
class CATIPLMEngineErrorReporter;

/**
* class providing export format for relations
* Supported format : PLM record read
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbRelationalImportFormat_CATIPLMRecordRead final : public CATOmbRelationalImportFormat
{
public:
  CATOmbRelationalImportFormat_CATIPLMRecordRead(CATIPLMRecordRead & iRecordRead);
  ~CATOmbRelationalImportFormat_CATIPLMRecordRead();
  CATOmbRelationalImportFormat_CATIPLMRecordRead(const CATOmbRelationalImportFormat_CATIPLMRecordRead&) = delete;
  CATOmbRelationalImportFormat_CATIPLMRecordRead& operator=(const CATOmbRelationalImportFormat_CATIPLMRecordRead&) = delete;
private:
  HRESULT BuildSRList(const CATUnicodeString & iTypeAggr) override;
  CATIPLMRecordRead                       & _RecordRead;
};

#endif
