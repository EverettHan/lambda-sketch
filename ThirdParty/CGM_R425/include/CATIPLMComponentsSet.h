/// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
//  Sep 2005  Creation: LJE
//
//===================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIPLMComponentsSet_H
#define CATIPLMComponentsSet_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"

class CATListPtrCATIPLMComponent;

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMComponentsSet;

/**
 * Interface to manage a set of components.
 * <b>role</b> This interface returns the root PLM Components edited by an editor ( CATFrmEditor class instance ).
 */
class ExportedByCATPLMComponentInterfaces CATIPLMComponentsSet: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	 * Retrieves the root components.
	 * @param oListOfRoots
	 *   The list of roots. It should be empty before call. 
	 * @return
	 *   <br><b>Legal values</b>:
	 *   <dl>
	 *     <dt>S_OK</dt>
	 *     <dd>The components are found.</dd>
	 *     <dt>S_FALSE</dt>
	 *     <dd>The method is correctly executed, however output list is empty.</dd>
	 *     <dt>E_FAIL</dt>
	 *     <dd>Internal error.</dd>
	 *     <dt>E_INVALIDARG</dt>
	 *     <dd>The method is called with non-empty output argument list.</dd>
	 *   </dl>
	 */
	virtual HRESULT GetRoots(CATListPtrCATIPLMComponent & oListOfRoots) = 0;

};

CATDeclareHandler(CATIPLMComponentsSet, CATBaseUnknown);

#endif
