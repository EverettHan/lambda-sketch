/**
* @level Private
* @usage U1
*/
#ifndef CATOmbErrorDef_H
#define CATOmbErrorDef_H

#include "CATErrorDef.h"

/**
 * @nodoc
 * Base for ObjectModelerBase error codes.<br>
 * 256 codes may be created.
 * <ul>
 * <li>Base + 0x00 -> Base + 0x39: links errors</li>
 * <li>Base + 0x40 -> Base + 0x69: persistency errors</li>
 * <li>Base + 0x70 -> Base + 0x79: DocId-PLMId conversion errors</li>
 * <li>Base + 0x80 -> Base + 0x8f: Converter/Importer/Exporter errors</li>
 * </ul>
 * Note that only errors that can be retreated must be associated with a specific error code.
 * Otherwize, use <tt>S_OK</tt>, <tt>S_FALSE</tt>, <tt>E_FAIL</tt>...
 * Use the facility <tt>FACILITY_ITF</tt> to create your error code.
 */
#define CATOmb_ERR_BASE 0x0A00

/**
 * @nodoc
 * Determines if a return code if an ObjectModelerBase error.<br>
 * If a non ObjectModelerBase method call returns an ObjectModelerBase error, you must change the return code.<pre>
 *    hr = <non ObjectModelerBase call>;
 *    if (IsOmbErrorCode(hr))
 *      hr = E_FAIL;
 * </pre>
 * @param iHr [in]
 *   The return code.
 */

#define IsOmbErrorCode(iHr) (HRESULT_FACILITY(iHr) == FACILITY_ITF && (iHr & 0xFF00) == CATOmb_ERR_BASE)

#endif
