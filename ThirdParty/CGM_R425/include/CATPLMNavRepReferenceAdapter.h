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
#ifndef CATPLMNavRepReferenceAdapter_H
#define CATPLMNavRepReferenceAdapter_H

#include "CATPLMComponentInterfaces.h"

#include "CATIPLMNavRepReference.h"

class CATListPtrCATIPLMNavRepInstance;

/**
* Adapter class for @href CATPLMComponentInterfaces.CATIPLMNavRepReference interface.
*/
class ExportedByCATPLMComponentInterfaces CATPLMNavRepReferenceAdapter : public CATIPLMNavRepReference
{
	public:

		/** @nodoc */
		CATPLMNavRepReferenceAdapter();

		/** @nodoc */
		virtual ~CATPLMNavRepReferenceAdapter();

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavRepReference#ListInstances
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT ListInstances(CATListPtrCATIPLMNavRepInstance & ioRepInstancesList);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavRepReference#RetrieveContainer
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT RetrieveApplicativeContainer (	const CATUnicodeString& iIdentifier, 
														const IID & iIID,
														void ** oApplicativeContainer);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavRepReference#GetContentKind
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetContentKind( CATPLMAuthoringStreamDescriptorKind & oContentKind );

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavRepReference#IsOnceInstantiable
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT IsOnceInstantiable();

	private:

		CATPLMNavRepReferenceAdapter(const CATPLMNavRepReferenceAdapter & iObjectToCopy);
		CATPLMNavRepReferenceAdapter & operator = (const CATPLMNavRepReferenceAdapter & iObjectToCopy);
};

#endif
