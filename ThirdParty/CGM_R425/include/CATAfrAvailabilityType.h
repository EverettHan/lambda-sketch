#ifndef CATAfrAvailabilityType_H
#define CATAfrAvailabilityType_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
* Command Header Availability.
* @param CATFrmUnavailable
*    The command is not accessible: the starter is disabled and its icon is greyed.
* @param CATFrmAvailable
*    The command is  accessible: the starter is available and its icon is normal. 
*
*/
enum CATFrmState { CATFrmUnavailable = 0,
                   CATFrmAvailable   = 1 };


/**
* Command Header Availabilities.
* <b>Role</b>: Command Header availability types.
* @param CATAfrNormalAvailability 
*   'Normal' availability type is always applied.
* @param CATAfrEditabilityAvailability 
*   Availability type applied when Editability mode is active.
* @param CATAfrSmallScaleAvailability 
*   Availability type applied when the edited data are in small scale display mode.
* @param CATAfrLargeScaleAvailability 
*   Availability type applied when the edited data are in large scale display mode.
* @param CATAfrExtraLargeScaleAvailability 
*   Availability type applied when the edited data are in huge scale display mode.
* @param CATAfrOffLineAvailability 
*   Availability type applied when the session is in disconnected/offline mode.
* @param CATAfrCoReviewLeaderAvailability 
*   Availability type applied when a co-review is running, on co-review leader side.
* @param CATAfrCoReviewObserverAvailability 
*   Availability type applied when a co-review is running, on co-review observer side.
*/
typedef unsigned int CATAfrAvailabilityType;

/** @nodoc */
#define CATAfrNormalAvailability           (1 << 0)
/** @nodoc */
#define CATAfrCommandSetAvailability       (1 << 1)
/** @nodoc */
#define CATAfrEditabilityAvailability      (1 << 2)
/** @nodoc */
#define CATAfrSmallScaleAvailability       (1 << 3)
/** @nodoc */
#define CATAfrLargeScaleAvailability       (1 << 4)
/** @nodoc */
#define CATAfrOffLineAvailability	         (1 << 5)
/** @nodoc */
#define CATAfrReviewModeAvailability       (1 << 6)
/** @nodoc */
#define CATAfrCoReviewLeaderAvailability   (1 << 7)
/** @nodoc */
#define CATAfrCoReviewObserverAvailability (1 << 8)
/** @nodoc */
#define CATAfrAsyncTaskAvailability        (1 << 9)
/** @nodoc */
#define CATAfrPLMTimeMachineAvailability   (1 << 10)
/** @nodoc */
#define CATAfrDebugAvailability            (1 << 11)
/** @nodoc */
#define CATAfrPlayAvailability             (1 << 12)
/** @nodoc */
#define CATAfrVPMCentralAvailability       (1 << 13)
/** @nodoc */
#define CATAfrUWPAvailability              (1 << 14)
/** @nodoc */
#define CATAfrNREAvailability              (1 << 15)
/** @nodoc */
#define CATAfrSimExpAvailability           (1 << 16)
/** @nodoc */
#define CATAfrImportPreviewAvailability    (1 << 17)
/** @nodoc */
#define CATAfrExtraLargeScaleAvailability  (1 << 18)
/** @nodoc */
#define CATAfrProductExploreAvailability   (1 << 19)
/** @nodoc */
#define CATAfrLocationPlanViewAvailability (1 << 20)
/** @nodoc */
#define CATAfrSchematicViewAvailability    (1 << 21)

#endif
