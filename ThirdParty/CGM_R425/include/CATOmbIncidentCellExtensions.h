#ifndef CATOmbIncidentCellExtensions_H
#define CATOmbIncidentCellExtensions_H

#include "CATObjectModelerBase.h"
#include "CATIOmyIncidentCell.h"
#include "CATPLMID.h"

namespace CATOmbIncidentCellExtensions
{
  /**
   * associate a PLMID to a CATIOmyIncidentCell
   * (actually a wrapper on "IdEntity" mess of "incident cells")
   */
  ExportedByCATObjectModelerBase CATPLMID GetAssociatedComponent(const CATIOmyIncidentCell& cell);
  ExportedByCATObjectModelerBase void SetAssociatedComponent(CATIOmyIncidentCell& cell, const CATPLMID& id);

  /**
   * return true if last error in "incident collector" concerns this id
   */
  ExportedByCATObjectModelerBase bool CheckLastErrorAssociatedComponent(const CATPLMID& id);
}

#endif
