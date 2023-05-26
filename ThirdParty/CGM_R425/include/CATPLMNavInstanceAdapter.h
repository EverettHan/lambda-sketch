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
#ifndef CATPLMNavInstanceAdapter_H
#define CATPLMNavInstanceAdapter_H

#include "CATPLMComponentInterfaces.h"

#include "CATIPLMNavInstance.h"

class CATIPLMNavReference;
class CATListPtrCATIPLMNavOccurrence;
class CATIPLMNavOccurrence;

/**
* Adapter class for @href CATPLMComponentInterfaces.CATIPLMNavInstance interface.
*/
class ExportedByCATPLMComponentInterfaces CATPLMNavInstanceAdapter : public CATIPLMNavInstance
{
	public:

		/** @nodoc */
		CATPLMNavInstanceAdapter();

		/** @nodoc */
		virtual ~CATPLMNavInstanceAdapter();

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavInstance#GetFather
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetFather(CATIPLMNavReference *& opiReference);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavInstance#GetReferenceInstanceOf
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetReferenceInstanceOf(CATIPLMNavReference *& opiReference);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavInstance#ListRelatedOccurrences
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT ListRelatedOccurrences(
			CATBaseUnknown * ipiContext,
			CATListPtrCATIPLMNavOccurrence & ioRelatedOccurrencesList);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavInstance#GetFirstLevelOccurrence
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetFirstLevelOccurrence(
			CATIPLMNavOccurrence * ipiContext,
			CATIPLMNavOccurrence *& opiFirstLevelOccurrence);

	private:

		CATPLMNavInstanceAdapter(const CATPLMNavInstanceAdapter & iObjectToCopy);
		CATPLMNavInstanceAdapter & operator = (const CATPLMNavInstanceAdapter & iObjectToCopy);
};

#endif
