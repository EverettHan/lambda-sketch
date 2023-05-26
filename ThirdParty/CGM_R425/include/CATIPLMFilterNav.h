// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
//  May 2012  Creation: JRZ
//
//===================================================================
/**
  * @level Protected
  * @usage U4 CATPLMFilterNavAdapter
*/

#ifndef CATIPLMFilterNav_H
#define CATIPLMFilterNav_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"

class CATListPtrCATIPLMNavEntity;
class CATPLMTypeH;

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMFilterNav;

/**
 * Interface to navigate the PLM Model
 * Has to be implemented by modeler deriving from the adapter CATPLMFilterNavAdapter
 *
 */
class ExportedByCATPLMComponentInterfaces CATIPLMFilterNav: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
			
		/**
		 * Retrieves the list of children of PLMType
		 * @param oChildrenList
		 *   The returned list of children. They have to be released after use. 
     *   The list has to be empty when calling the API.
     *
     * @param iType
		 *   requested type of children.
     *
     * @return
		 *   HRESULT
		 *     S_OK
		 *      The list (Empty or Filled) is successfully returned.
     *     E_INVALIDARG
     *      Invalid argument: oChildrenList is not empty when calling
     *                        or iType is invalid. 
		 *     E_FAIL
		 *      Other error.
		 *   </dl>
		 */
		virtual HRESULT ListChildrenOfType(CATListPtrCATIPLMNavEntity & oChildrenList, const CATPLMTypeH &iType) = 0;
		
};

CATDeclareHandler(CATIPLMFilterNav, CATBaseUnknown);

#endif
