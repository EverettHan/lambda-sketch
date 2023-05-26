/**
* @level Private
* @usage U1
*/
#ifndef _CATOmbRelationalExportFormat_PLMRecord_H
#define _CATOmbRelationalExportFormat_PLMRecord_H

//================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//================================================================
//  Usage notes :
//	Feb. 2005 pbv Creation
//================================================================

#include "IUnknown.h"
#include "CATOmbLinkTraderForRestrictedAccess.h"
#include "CATOmbRelationalExportFormat.h"
#include "CATBoolean.h"
#include "CATPLMSemanticRelationLogStatus.h"
#include "CATListPtrCATPLMSemanticRelation.h"

class CATIPLMIntegRecordWrite;
class CATOmbRelationExport;
class CATIPLMEngineErrorReporter;
class CATPLMSemanticRelationData;
class CATOmbRelationInterface;
class CATPLMSemanticRelation;
class CATPLMSRIds;


/**
* class providing export format for relations
* Supported format : PLM record write
*/
class CATOmbRelationalExportFormat_PLMRecord : public CATOmbRelationalExportFormat
{
public:
  ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbRelationalExportFormat_PLMRecord(CATIPLMIntegRecordWrite & iRecordWrite, CATIPLMEngineErrorReporter * ioErrorReporter = 0);
  ExportedByCATOmbLinkTraderForRestrictedAccess ~CATOmbRelationalExportFormat_PLMRecord();

  HRESULT Open() override;
  HRESULT ExportRelations(CATOmxIter<CATOmbRelationImpl>& iRelations, CATOmbComponentTablesMediator & iMediator, const CATComponentId & iComponent) override;
  HRESULT Close() override;
  void Abort() override;

private:
  HRESULT IncrementalExport(const CATComponentId & iComponent, const CATPLMSRIds& iSRIds, CATPLMSemanticRelationLogStatus iStatus, CATOmbRelationInterface * iSRImpl);

  HRESULT GlobalExport(CATOmbComponentTablesMediator& iMediator);

  CATIPLMIntegRecordWrite & _RecordWrite;
};

#endif
