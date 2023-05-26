#ifndef CATUFOUserActionInformation_H
#define CATUFOUserActionInformation_H
/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATPLMIdentification.h"
#include "CATUFOUserActionCategories.h"
#include "CATOmxSharable.h"
#include "CATPLMID.h"

class CATUFOUserActionInformationForSusbsituteInUsageContext;

typedef enum
{
  CATUFOUserActionComponent_undefined,
  CATUFOUserActionComponent_destroyed,
  CATUFOUserActionComponent_pointing,
  CATUFOUserActionComponent_readonly
}
CATUFOUserActionComponentStatus;

class ExportedByCATPLMIdentification CATUFOUserActionInformation : public CATOmxSharable
{
public:
  CATUFOUserActionInformation(const CATPLMID & iImpacted, CATUFOUserActionCategories iCategory);
  ~CATUFOUserActionInformation();

  /**
  * Get the category of the user action.
  * @return
  *  The category of the user action.
  */
  inline CATUFOUserActionCategories GetUserActionCategory() const { return _Category; }
  inline const CATPLMID &GetImpactedComponentPLMID() const { return _PLMID; }
  inline const CATUFOUserActionComponentStatus GetStatus() const { return _Status; }
  inline void SetStatus(CATUFOUserActionComponentStatus iStatus) { _Status = iStatus; }

  /**
  * Clean cast.
  * @return
  *  This object if it is an information about substitution in usage contect
  *  NULL otherwise
  */
  virtual CATUFOUserActionInformationForSusbsituteInUsageContext * GetInformationForSubstituteInUsageContext();

private:
  CATUFOUserActionCategories _Category;
  CATPLMID _PLMID;
  CATUFOUserActionComponentStatus _Status;
};

#endif
