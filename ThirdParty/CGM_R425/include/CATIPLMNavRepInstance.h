// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
//  Nov 2005  Creation: LJE
//
//===================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIPLMNavRepInstance_H
#define CATIPLMNavRepInstance_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"

class CATIPLMNavReference;
class CATIPLMNavRepReference;
class CATListPtrCATIPLMNavRepOccurrence;

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavRepInstance;

/**
 * Interface to navigate on a Representation Instance.
 */
class ExportedByCATPLMComponentInterfaces CATIPLMNavRepInstance: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
		
		/**
		 * Retrieves the Reference which aggregates the Representation Instance.
		 * @param opiReference [out, CATBaseUnknown#Release]
		 *   The father.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>NULL</dt>
		 *     <dd>An error is detected.</dd>
		 *     <dt>Valid</dt>
		 *     <dd>Usable Reference.</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The father is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The RepInstance is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetFather(CATIPLMNavReference *& opiReference) = 0;
		
		/**
		 * Retrieves the instanciated Representation Reference.
		 * @param opiRepReference [out, CATBaseUnknown#Release]
		 *   The Representation Reference.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>NULL</dt>
		 *     <dd>An error is detected.</dd>
		 *     <dt>Valid</dt>
		 *     <dd>Usable Representation Reference.</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The instanciated Representation Reference is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The RepInstance is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetRepReferenceInstanceOf(CATIPLMNavRepReference *& opiRepReference) = 0;
		
		/**
		 * Retrieves the RepOccurrences related to the RepInstance in a given context.
		 * @param ipiContext
		 *   The context of navigation.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Object implementing CATIPLMNavReference</dt>
		 *     <dd>To navigate under the root Occurrence which corresponds to the Reference.</dd>
		 *     <dt>Object implementing CATIPLMNavOccurrence</dt>
		 *     <dd>To navigate under the given Occurrence.</dd>
		 *   </dl>
		 * @param ioRelatedRepOccurrencesList
		 *   The list of related RepOccurrences. Warning this list is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>There is no ReoOccurrences in the context.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>There are RepOccurrences in the context (in this case the order is not guaranteed).</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The list (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_INVALIDARG</dt>
		 *     <dd>The context is not correct.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Rep Instance is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT ListRelatedRepOccurrences(
			CATBaseUnknown * ipiContext,
			CATListPtrCATIPLMNavRepOccurrence & ioRelatedRepOccurrencesList) = 0;
		
};

CATDeclareHandler(CATIPLMNavRepInstance, CATBaseUnknown);

#endif
