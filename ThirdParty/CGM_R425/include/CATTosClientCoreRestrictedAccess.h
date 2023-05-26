#ifndef CATTosClientCoreRestrictedAccess_H
#define CATTosClientCoreRestrictedAccess_H

#define AuthorizedModule                             999
#define CATPLMEditabilityImpl               AuthorizedModule
#define CATPLMIdentification                AuthorizedModule
#define CATPCTEditabilityTests              AuthorizedModule
#define CATItgTestLib                       AuthorizedModule
#define CATPLMIntegration                   AuthorizedModule
#define CATPLMContentTracking               AuthorizedModule
#define InMemoryContentManagementTests      AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATTosClientCoreRestrictedAccess from a non PC2 module
#endif
#undef CATPLMEditabilityImpl
#undef CATPLMIdentification
#undef CATPCTEditabilityTests
#undef CATItgTestLib
#undef CATPLMIntegration
#undef CATPLMContentTracking
#undef InMemoryContentManagementTests

/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATPLMIdentification.h"
#include "CATAdpEditability.h"
#include "CATAdpReservation.h"
#include "CATComponentId.h"

class ExportedByCATPLMIdentification CATTosClientCoreRestrictedAccess
{
public:
  static HRESULT GetEditability(const CATComponentId & iCID, CATAdpEditability & oEditability);
  static HRESULT SetEditability(const CATComponentId & iCID, CATAdpEditability iEditability, CATBoolean iUnused = FALSE, CATBoolean iWithNotification = FALSE);

  static HRESULT GetReservationStatus(const CATComponentId & iCID, CATAdpReservation & oReservation);
  static HRESULT SetReservationStatus(const CATComponentId & iCID, CATAdpReservation iReservation, CATBoolean iUnused = FALSE);

  static HRESULT GetEditabilityAndReservationStatus(const CATComponentId& iCID, CATAdpEditability & oEditability, CATAdpReservation & oReservation);
  static HRESULT SetEditabilityAndReservationStatus(const CATComponentId& iCID, CATAdpEditability iEditability, CATAdpReservation iReservation, CATBoolean iUnused = FALSE, CATBoolean iWithNotification = FALSE);
};

#endif

