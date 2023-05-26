#ifndef _CATOmbComponentOpenSaveHelper_H
#define _CATOmbComponentOpenSaveHelper_H

/**
* @level Private
* @usage U1
*/
#include "CATOmbLinkTraderForRestrictedAccess.h"
#include "IUnknown.h"
#include "CATBoolean.h"

class CATComponentId;
class CATOmbRelationalImportFormat;
class CATOmbRelationalExportFormat;

/**
* Helper necessary for import / export of the component's relational view
*/
class ExportedByCATOmbLinkTraderForRestrictedAccess CATOmbComponentOpenSaveHelper
{
public:

  /**
  * Export relational view to repository
  *
  * @param iComId [in]
  *   The component owner of the relation's table
  * @param iExportFormat [in]
  *   The associated export format. e.g. : composite stream / record read / ...
  *
  * @return
  *   <code>S_OK</code>   method succeeded.
  *   <code>E_FAIL</code> unexpected error.
  */
  static HRESULT SaveRelationalView(const CATComponentId & iComId, CATOmbRelationalExportFormat & iExportFormat);

  /**
  * Check if relationnal view of Component is dirty
  * @param iComId [in]
  *   The component owner of the relation's table
  * @return
  *   TRUE : Relationnal view is dirty
  *   FALSE : Relationnal view is not dirty or ComponentLinkTable does not exist.
  */
  static CATBoolean IsRelationalViewDirty(const CATComponentId & iComId);
};

#endif
