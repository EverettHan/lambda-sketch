#ifndef CATOmbDocEnvTargetDocIdStatus_H
#define CATOmbDocEnvTargetDocIdStatus_H

// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Private
 * @usage U1
 */
/**
 * Status of the target persistency unit's Id set by the environment.
 * @param CATOmbDocEnvTargetDocIdNoStatus
 *   The status is unknown. The environment is supposed to set a new status.
 * @param CATOmbDocEnvTargetDocIdFixed
 *   The target identifier doesn't need to be changed.
 * @param CATOmbDocEnvTargetDocIdTempo
 *   The target identifier must be changed by the environment before executing operations: the manager @href CATOmbSessionPersistMngr
 *   will call @href CATIDocEnvPersistMngr#ProvideTargetDocId in order to let the environment set the correct identifier.
 * @param CATOmbDocEnvTargetDocIdClient
 *   The target identifier must be managed by the client.
 */
enum CATOmbDocEnvTargetDocIdStatus { CATOmbDocEnvTargetDocIdNoStatus, CATOmbDocEnvTargetDocIdFixed, CATOmbDocEnvTargetDocIdTempo, CATOmbDocEnvTargetDocIdClient };

#endif
