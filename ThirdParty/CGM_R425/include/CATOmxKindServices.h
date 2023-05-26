#ifndef __CATOmxKindServices_H
#define __CATOmxKindServices_H

#include "CATOmxKernel.h"
#include "CATOmxKind.h"
#include "CATJHNTypeLib.h"

/**
 * Returns TCKind equivalent of CATOmxKind iKind.
 * If iKind has no TCKind equivalent, tk_null will be returned.
 */
ExportedByCATOmxKernel TCKind OmxKindToTCKind(CATOmxKind iOmxKind);

/**
 * Returns CATOmxKind equivalent of TCKind iKind.
 * If iKind has no CATOmxKind equivalent, omx_void will be returned.
 */
ExportedByCATOmxKernel CATOmxKind TCKindToOmxKind(TCKind iTCKind);

#endif

