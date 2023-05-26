#ifndef CATAfrCommandHeaderServices_H
#define CATAfrCommandHeaderServices_H
#include "CATAfrFoundation.h"
#include "CATAfrCommandHeader.h"
#include "CATAfrAvailabilityType.h"

// COPYRIGHT DASSAULT SYSTEMES 2005

class CATString;
class CATCommandHeader;

//---------------------------------------------------------------------------
/**
 * Gets a pointer to a command header.
 * <br><b>Role</b>: This function looks for a @href CATCommandHeader identifier and returns a pointer 
 * to this command header.
 * @param iCommandHeaderId
 *  The identifier of the CATCommandHeader.
 * @param oCommand
 *  The CATCommand.
 * @return
 * Returns S_OK on success. Returns E_FAIL if the identifier is not an existing CATCommandHeader identifier.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetCommandHeader (CATString iCommandHeaderId,
                                CATCommandHeader *& oCommandHeader);
/**
 * Define a command header availability.
 * <br><b>Role</b>: This function looks for a @href CATCommandHeader identifier and sets 
 * its availability regarding to iState.
 * @param iCommandHeaderId
 *  The identifier of the CATCommandHeader.
 * @param iState
 *  CATFrmAvailable or CATFrmUnavailable.
 * @return
 * Returns S_OK on success. Returns E_FAIL if the identifier is not an existing CATCommandHeader identifier.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrSetCHAvailability (CATString iCommandHeaderId,
                                 int iState);

/**
 * Define a command header availability regarding the availability type.
 * <br><b>Role</b>: This function looks for a @href CATCommandHeader identifier and sets 
 * its availability regarding to iState and the availability type.
 * @param iCommandHeaderId
 *  The identifier of the CATCommandHeader.
 * @param iState
 *  CATFrmAvailable or CATFrmUnavailable.
 * @param AvailabilityType
 *   CATAfrNormalAvailability, CATAfrCommandSetAvailability, CATAfrEditabilityAvailability, 
 *   CATAfrSmallScaleAvailability, CATAfrLargeScaleAvailability, CATAfrExtraLargeScaleAvailability, CATAfrOffLineAvailability,	
 *   CATAfrReviewModeAvailability, CATAfrCoReviewLeaderAvailability, CATAfrCoReviewObserverAvailability,
 *   CATAfrAsyncTaskAvailability, CATAfrPLMTimeMachineAvailability, CATAfrDebugAvailability,
 *   CATAfrPlayAvailability, CATAfrVPMCentralAvailability, CATAfrUWPAvailability,
 *   CATAfrNREAvailability, CATAfrSimExpAvailability, CATAfrImportPreviewAvailability, CATAfrProductExploreAvailability,
 *   CATAfrLocationPlanViewAvailability, CATAfrSchematicViewAvailability.
 * @return
 * Returns S_OK on success. Returns E_FAIL if the identifier is not an existing CATCommandHeader identifier.
 */
ExportedByCATAfrFoundation
HRESULT CATAfrSetCHAvailability (CATString iCommandHeaderId,
                                 CATFrmState Availability, CATAfrAvailabilityType AvailabilityType );

#endif
