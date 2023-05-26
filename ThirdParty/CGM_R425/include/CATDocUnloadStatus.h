// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef CATDocUnloadStatus_h
#define CATDocUnloadStatus_h

/**
 * @level Private
 * @usage U1
 */

/**
 * Document unloading status.
 * @param CATDocUnloadSuccessful
 *   The documents are unloaded.
 * @param CATDocUnloadRefused
 *   A subscriber refused the documents to be unloaded.
 * @param CATDocUnloadPrepareFailed
 *   A subscriber raised an error during preparing.
 * @param CATDocUnloadFailed
 *   An error occured during the effective unloading. Some documents may have been unloaded.
 */
enum CATDocUnloadStatus {CATDocUnloadSuccessful, CATDocUnloadRefused, CATDocUnloadPrepareFailed, CATDocUnloadFailed};

#endif
