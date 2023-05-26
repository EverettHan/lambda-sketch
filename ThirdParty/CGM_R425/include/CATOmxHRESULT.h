#ifndef __CATOmxHRESULT_h__
#define __CATOmxHRESULT_h__

/**
 * @CAA2Required
 * COPYRIGHT DASSAULT SYSTEMES 2008
 */

// System
#include "CATErrorDef.h"

/** @nodoc Encode error. */
#define CATOM_INPUT_ERROR(a)  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, (0xAF00 | ((a) &0xFF)))
/** @nodoc Encode error. */
#define CATOM_ERROR(a)  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, (0xAE00 | ((a) &0xFF)))


/** There is no local value associated to this key. */
#define E_NOLOCALVALUE    CATOM_ERROR(1)
/** Key does not exist for this item. */
#define E_KEYNOTFOUND     CATOM_INPUT_ERROR(2)
/** Access outside the bound of the list. */
#define E_OUTOFBOUND      CATOM_INPUT_ERROR(3)
/** Invalid list operation. */
#define E_NOTALIST        CATOM_INPUT_ERROR(4)
/** Incorrect type for this operation. */
#define E_TYPEMISMATCH    CATOM_INPUT_ERROR(5)

#endif
