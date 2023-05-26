#ifndef CATOmbDocDirtyStatus_H
#define CATOmbDocDirtyStatus_H

// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level protected
 * @usage U1
 */

/**
 * Dirty status of a document.
 * <b>Role:</b> This type enumerates reasons why a document is dirty.
 * @param CATOmbNotModified
 *   The document is not modified in the session.
 * @param CATOmbModifiedBySynchro
 *   The document is modified because of synchronization process.
 * @param CATOmbAttachedDocModified
 *   The document is not modified itself but at least an attached document is modified.
 * @param CATOmbModified
 *   The document is modified itself.
 */

enum CATOmbDocDirtyStatus { CATOmbNotModified, CATOmbModifiedBySynchro, CATOmbAttachedDocModified, CATOmbModified };

#endif
