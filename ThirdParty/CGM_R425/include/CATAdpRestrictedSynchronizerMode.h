// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATAdpRestrictedSynchronizerMode.h
// Header definition of CompletionMode enum
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2010  Creation: ECN
//===================================================================
/**
* @level Protected
* @usage U2
*/
#ifndef CATAdpRestrictedSynchronizerMode_H
#define CATAdpRestrictedSynchronizerMode_H

/**
 * Defines a mode of refresh for synchronization services.
 * <br><b>Role:</b>Description of the available modes.
 *
 * <dt> <code><b>SynchronizeOrForgetConcurrentModifications</b></code> 
 * <dd> Session is impacted only if components are impacted by CUNCURRENT MODIFICATIONS.
 *      If component is CONCURRENTLY DELETED, operation is globally rejected.
 */
enum CATAdpRestrictedSynchronizerMode { SynchronizeOrForgetConcurrentModifications=1 };

#endif
