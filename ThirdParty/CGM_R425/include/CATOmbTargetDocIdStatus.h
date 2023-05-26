#ifndef CATOmbTargetDocIdStatus_H
#define CATOmbTargetDocIdStatus_H

// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Private
 * @usage U1
 */
/**
 * Status of the target persistency unit's Id.
 * @param CATOmbTargetDocIdUnknownStatus
 *   The status is unknown.
 * @param CATOmbTargetDocIdFixed
 *   The target identifier can't be changed.
 * @param CATOmbTargetDocIdChangeable
 *   The target identifier may be changed.
 * @param CATOmbTargetDocIdToBeChanged
 *   The target identifier must be changed: the client of the manager has to call @href CATOmbSessionPersistMngr#RegisterTargetUnitId .
 */
enum CATOmbTargetDocIdStatus { CATOmbTargetDocIdUnknownStatus, CATOmbTargetDocIdFixed, CATOmbTargetDocIdChangeable, CATOmbTargetDocIdToBeChanged };

#endif
