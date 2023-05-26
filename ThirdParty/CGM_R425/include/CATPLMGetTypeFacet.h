#ifndef __CATPLMGetTypeFacet_H
#define __CATPLMGetTypeFacet_H

#include "ExportedByCATPLMTos.h"
#include "CATOmxAny.h"
#include "CATPLMTypeH.h"
#include "CATOmxKeyString.h"

/**
 * Scans sessionmetadata files to retrieve the value of given facet
 * This value can be defined on a type, globally on all the types of a package or nowhere
 * It can be of any type (need to be checked by caller)
 * There is a cache, no need to add one in caller
 * @returns empty CATOmxAny if facet is not found
 */
ExportedByCATPLMTos CATOmxAny CATPLMGetTypeFacet(const CATPLMTypeH& type, const CATOmxKeyString& facet);

#endif
