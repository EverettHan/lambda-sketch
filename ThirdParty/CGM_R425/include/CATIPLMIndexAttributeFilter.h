#ifndef _CATIPLMIndexAttributeFilter_H__
#define _CATIPLMIndexAttributeFilter_H__

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMIndexAttributeFilter;
#else
extern "C" const IID IID_CATIPLMIndexAttributeFilter;
#endif

class CATIPLMQueryFilter;

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMIndexAttributeFilter : public CATBaseUnknown
{
    CATDeclareInterface;

  public:
    /**
	 * Initializes the attribute filter for the 3D Index query with the given PLMAdapter filter.
 	 *
	 * <ul>
	 *   <li>S_OK if the input filter will fully applied in the Index queries. May be empty if input filter was empty (no attribute filter).</li>
	 *   <li>S_FALSE if the input filter will be only partially applied in the Index queries. May be empty after simplification.</li>
	 *   <li>E_FAIL if an error occured during process </li>
	 * </ul>
	 */
	virtual HRESULT BuildFromSpec(CATIPLMQueryFilter* ipiQueryFilter) = 0;

	// build without being connected (for odt)
	virtual HRESULT Build(const CATUnicodeString &iSpecString, const CATUnicodeString &iModString, bool iIsCaseSensitive) = 0;

};

CATDeclareHandler(CATIPLMIndexAttributeFilter, CATBaseUnknown);


#endif
