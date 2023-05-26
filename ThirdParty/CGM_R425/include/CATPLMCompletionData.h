#ifndef CATPLMCompletionData_h
#define CATPLMCompletionData_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATPLMID.h"
#include "CATOmxOSet.h"
#include "CATPLMCompletionDatum.h" //Legacy
#include "CATPLMCompletionDataCplxMode.h" //Legacy

class CATPLMIDSet;
/**
* Represents a group of CATPLMIDs to complete
*/
typedef CATOmxOSet<CATPLMCompletionDatum> CATPLMCompletionDatumSet;
class ExportedByCATPLMIntegrationAccess CATPLMCompletionData : public CATPLMCompletionDatumSet
{
public:
  CATPLMCompletionData();
  CATPLMCompletionData(const CATPLMID  & iPid);
  CATPLMCompletionData(const CATPLMID  & iPid, const CATUnicodeString & iDisc);

  void Append(const CATPLMCompletionDatum  & iDatum);
  inline void UpdateOrInsert(const CATPLMCompletionDatum  & iDatum) { Insert(iDatum); }
  void UpdateOrInsert(const CATPLMIDs  & iPLMIDs, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  void UpdateOrInsert(const CATPLMIDSet& iPLMIDs, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  void UpdateOrInsert(const CATPLMID  & iPid, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif);
  void UpdateOrInsert(const CATPLMCompletionData  & iData);
  /**
   * Adds the contained PLMIDs to the PLMIDList/PLMIDSet
   */
  HRESULT AddToPLMIDs(CATPLMIDs & oPLMIDs, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif) const;
  HRESULT AddToPLMIDSet(CATPLMIDSet & oPLMIDs, CATPLMCompletionDataCplxMode::Mode iCplxMode = CATPLMCompletionDataCplxMode::NoModif) const;

  using CATPLMCompletionDatumSet::Remove;
  void Remove(const CATPLMCompletionData & iData);

  CATPLMIDs GetPLMIDs() const;
};
#endif
