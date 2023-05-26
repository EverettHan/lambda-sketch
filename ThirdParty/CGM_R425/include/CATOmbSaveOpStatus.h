#ifndef CATOmbSaveOpStatus_H
#define CATOmbSaveOpStatus_H

// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Private
 * @usage U1
 */
/**
 * Status for a save operation.
 * <b>Role:</b> This type enumerates how a save operation behaves.
 * @param CATOmbWriteOnlyIfNeeded
 *   The unit will be written only<ul>
 *   <li>If at least one document has never been saved (new document)</li>
 *   <li>Or if a pointed unit will be written</li>
 *   <li>Or if the document is dirty</li>
 *   </ul>
 * @param CATOmbWriteAnyway
 *   The unit will be written anyway.
 */

enum CATOmbSaveOpStatus { CATOmbWriteOnlyIfNeeded, CATOmbWriteAnyway };

#endif
