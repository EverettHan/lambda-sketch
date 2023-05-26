// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
//  Dec 2005  Creation: LJE
//
//===================================================================
/**
 * @level Protected
 * @usage U2
 */
#ifndef CATPLMNavRepInstanceAdapter_H
#define CATPLMNavRepInstanceAdapter_H

#include "CATPLMComponentInterfaces.h"

#include "CATIPLMNavRepInstance.h"

class CATIPLMNavReference;
class CATListPtrCATIPLMNavRepOccurrence;
class CATIPLMNavRepReference;

/**
* Adapter class for @href CATPLMComponentInterfaces.CATIPLMNavRepInstance interface.
*/
class ExportedByCATPLMComponentInterfaces CATPLMNavRepInstanceAdapter : public CATIPLMNavRepInstance
{
	public:

		/** @nodoc */
		CATPLMNavRepInstanceAdapter();

		/** @nodoc */
		virtual ~CATPLMNavRepInstanceAdapter();

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavRepInstance#GetFather
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetFather(CATIPLMNavReference *& opiReference);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavRepInstance#GetRepReferenceInstanceOf
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetRepReferenceInstanceOf(CATIPLMNavRepReference *& opiRepReference);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavRepInstance#ListRelatedRepOccurrences
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
    virtual HRESULT ListRelatedRepOccurrences(
      CATBaseUnknown * ipiContext,
      CATListPtrCATIPLMNavRepOccurrence & ioRelatedRepOccurrencesList);

	private:

		CATPLMNavRepInstanceAdapter(const CATPLMNavRepInstanceAdapter & iObjectToCopy);
		CATPLMNavRepInstanceAdapter & operator = (const CATPLMNavRepInstanceAdapter & iObjectToCopy);
};

#endif
