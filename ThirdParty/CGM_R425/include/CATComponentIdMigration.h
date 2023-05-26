#ifndef CATComponentIdMigration_H
#define CATComponentIdMigration_H

/**
 * @level Private
 * @usage U1       
 */

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

class CATComponentId;
class CATPLMID;

class ExportedByCATPLMTos CATComponentIdMigration
{
public:

	/**
	*	MigrateLogicalId
	* <br><b>Role</b>: Migrate logical id, to be used for coexistence on revisions,
	*	with mixed DBDI/FBDI.
	*	WARNING: do not use this if you don't know what you are doing.
	* @param iCID
	*		the component id to migrate
	* @param iPLMID
	*		the plmid for migration
	* @return
	* <dl>
	* <dt><code>S_OK</code>if succeeded<dd>
	* <dt><code>E_FAIL</code>if failure<dd>
	* </dl>
	*/
	static HRESULT MigrateLogicalId(CATComponentId & iCID, const CATPLMID & iPLMID);

  /**
   * Assign iLogicalIdReference's logicalid to input component
   * Input component must be in "new" state and must have its default logicalid (equal to physicalid).
   * (same as MigrateLogicalId but input component CAN be pointed)
   * Usage is abolutely forbidden unless granted by CATPLMIdentification team (not kidding).
   */
  static HRESULT ForceLogicalIdAtCreation(CATComponentId & iCID, const CATPLMID & iLogicalIdReference);
};

#endif
