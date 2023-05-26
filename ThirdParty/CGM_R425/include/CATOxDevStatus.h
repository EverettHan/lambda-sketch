#ifndef CATOxDevStatus_H
#define CATOxDevStatus_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"

/**
* If ever you thought about adding yet another variable in that horror:
*   - first remove some variables,
*   - then think about the pertinence of adding another variable
*   - finally do not add any variable
* If ever you past this preamble and still wish to add another variable:
*   - How it is implemented here is "bad": check this article http://osmwebdsy/wiki/index.php/Environment_variables
*   - Is that meaningful to add it here ?
*     99% of the variables are used ONCE in ObjectModelerBase,
*     that does not make any sense to add them in a ProtectedInterfaces of CATPLMIdentificationAccess
*/
class CATOxDevStatus
{
public:
  static inline CATBoolean UnloadCyclicityForOpen() { return env()._bUnloadCyclicityForOpen; }
  static inline CATBoolean IGRScopeValidationForNewTyping() { return env()._bIGRScopeValidationForNewTyping; }

  /***********Life cycle dev*****************/
  static inline CATBoolean IGRNoIntegrityGroup() { return env()._bIGRNoIntegrityGroup; }
  static inline CATBoolean LinksResolutionMigration() { return env()._bLinksResolutionMigration; }
  static inline CATBoolean ChangeApplicabilityWithUFO() { return env()._bChangeApplicabilityWithUFO; }
  static inline CATBoolean UFOLogIgnoreConnexionInCCM() { return env()._bUFOLogIgnoreConnexionInCCM; }
  static inline CATBoolean NO_CHT_MultiECA_SR00561797() { return env()._bNO_CHT_MultiECA_SR00561797; }

private:
  CATOxDevStatus();
  ExportedByCATPLMIdentificationAccess static const CATOxDevStatus& env();
  static CATBoolean IsDSEnvironnement();
  CATBoolean _bUnloadCyclicityForOpen : 1;
  CATBoolean _bIGRScopeValidationForNewTyping : 1;
  CATBoolean _bEditabilityForUFO : 1;
  CATBoolean _bAssertionInCleanObsoleteLifeCycle : 1;
  CATBoolean _bIGRNoIntegrityGroup : 1;
  CATBoolean _bLinksResolutionMigration : 1;
  CATBoolean _bChangeApplicabilityWithUFO : 1;
  CATBoolean _bUFOLogIgnoreConnexionInCCM : 1;
  CATBoolean _bNO_CHT_MultiECA_SR00561797 : 1;
};

#endif
