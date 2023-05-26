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
#ifndef CATPLMNavReferenceAdapter_H
#define CATPLMNavReferenceAdapter_H

#include "CATPLMComponentInterfaces.h"

#include "CATIPLMNavReference.h"

#include "CATPLMCoreType.h"

class CATListPtrCATIPLMNavEntity;
class CATListPtrCATIPLMNavInstance;
class CATListPtrCATIPLMNavOccurrence;

/**
* Adapter class for @href CATPLMComponentInterfaces.CATIPLMNavReference interface.
*/
class ExportedByCATPLMComponentInterfaces CATPLMNavReferenceAdapter : public CATIPLMNavReference
{
	public:

		/** @nodoc */
		CATPLMNavReferenceAdapter();

		/** @nodoc */
		virtual ~CATPLMNavReferenceAdapter();

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavReference#ListChildren
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT ListChildren(
			CATListPtrCATIPLMNavEntity & ioChildrenList,
			const int & iiFilterSize,
			CATPLMCoreType * ipFilter);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavReference#ListInstances
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT ListInstances(CATListPtrCATIPLMNavInstance & ioInstancesList);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavReference#ListRelatedOccurrences
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT ListRelatedOccurrences(
			CATBaseUnknown * ipiContext,
			CATListPtrCATIPLMNavOccurrence & ioRelatedOccurrencesList);

	private:

		CATPLMNavReferenceAdapter(const CATPLMNavReferenceAdapter & iObjectToCopy);
		CATPLMNavReferenceAdapter & operator = (const CATPLMNavReferenceAdapter & iObjectToCopy);
};

#endif
