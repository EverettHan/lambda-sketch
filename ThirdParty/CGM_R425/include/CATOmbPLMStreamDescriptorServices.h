#ifndef __CATOmbPLMStreamDescriptorServices_H
#define __CATOmbPLMStreamDescriptorServices_H

/**
 * Ad-hoc services for CATPLMStreamDescriptor framework, do not use outside
 */

#include "CATOmbSelectiveLoading.h"
#include "CATOmxIter.h"
#include "CATBooleanDef.h"

enum CATOmbTransactionType
{
  CATOmbSave,
  CATOmbLocalSave,
  CATOmbCollab,
  CATOmbUnload,
  CATOmbExportForCloning
};

ExportedByCATOmbSelectiveLoading void CATOmbTransactionIsCompleted(const CATComponentId& iRepRef,CATOmbTransactionType iTransactionType,CATBoolean iSuccessful);

ExportedByCATOmbSelectiveLoading CATBoolean CATOmbPrepareStreamDeletion(CATBaseUnknown* iSD);

ExportedByCATOmbSelectiveLoading  CATOmxIter<CATBaseUnknown> CATOmbGetSDsUnderDeletion(const CATComponentId& iRepRef);

#endif
