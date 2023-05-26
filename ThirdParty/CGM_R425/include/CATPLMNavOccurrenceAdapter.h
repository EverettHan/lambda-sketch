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
#ifndef CATPLMNavOccurrenceAdapter_H
#define CATPLMNavOccurrenceAdapter_H

#include "CATPLMComponentInterfaces.h"

#include "CATIPLMNavOccurrence.h"

class CATIPLMNavReference;
class CATIPLMNavInstance;
class CATListPtrCATIPLMNavOccurrence;
class CATListPtrCATIPLMNavRepOccurrence;

/**
* Adapter class for @href CATPLMComponentInterfaces.CATIPLMNavOccurrence interface.
*/
class ExportedByCATPLMComponentInterfaces CATPLMNavOccurrenceAdapter : public CATIPLMNavOccurrence
{
	public:

		/** @nodoc */
		CATPLMNavOccurrenceAdapter();

		/** @nodoc */
		virtual ~CATPLMNavOccurrenceAdapter();

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavOccurrence#GetFather
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetFather(CATIPLMNavOccurrence *& opiOccurrence);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavOccurrence#ListChildren
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT ListChildren(CATListPtrCATIPLMNavOccurrence & ioChildrenList);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavOccurrence#ListRepChildren
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT ListRepChildren(CATListPtrCATIPLMNavRepOccurrence & ioRepChildrenList);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavOccurrence#GetRelatedInstance
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetRelatedInstance(CATIPLMNavInstance *& opiInstance);

		/**
		 * @see CATPLMComponentInterfaces.CATIPLMNavOccurrence#GetRelatedReference
		 * <br><b>Role</b>: This behavior can be implemented.
		 */
		virtual HRESULT GetRelatedReference(CATIPLMNavReference *& opiReference);

	private:

		CATPLMNavOccurrenceAdapter(const CATPLMNavOccurrenceAdapter & iObjectToCopy);
		CATPLMNavOccurrenceAdapter & operator = (const CATPLMNavOccurrenceAdapter & iObjectToCopy);
};

#endif
