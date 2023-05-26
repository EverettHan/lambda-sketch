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
#ifndef CATIPLMNavInstance_H
#define CATIPLMNavInstance_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"

class CATIPLMNavReference;
class CATListPtrCATIPLMNavOccurrence;
class CATIPLMNavOccurrence;

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavInstance;

/**
 * Interface to navigate on an Instance.
 */
class ExportedByCATPLMComponentInterfaces CATIPLMNavInstance: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
		
		/**
		 * Retrieves the Reference which aggregates the Instance.
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
		 *     <dd>The Instance is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetFather(CATIPLMNavReference *& opiReference) = 0;
		
		/**
		 * Retrieves the instanciated Reference.
		 * @param opiReference [out, CATBaseUnknown#Release]
		 *   The Reference.
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
		 *     <dd>The instanciated Reference is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Instance is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetReferenceInstanceOf(CATIPLMNavReference *& opiReference) = 0;
		
		/**
		 * Retrieves the Occurrences related to the Instance in a given context.
		 * @param ipiContext
		 *   The context of navigation.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Object implementing CATIPLMNavReference</dt>
		 *     <dd>To navigate under the root Occurrence which corresponds to the Reference.</dd>
		 *     <dt>Object implementing CATIPLMNavOccurrence</dt>
		 *     <dd>To navigate under the given Occurrence.</dd>
		 *   </dl>
		 * @param ioRelatedOccurrencesList
		 *   The list of related Occurrences. Warning this list is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>There is no Occurrences in the context.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>There are Occurrences in the context (in this case the order is not guaranteed).</dd>
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
		 *     <dd>The Instance is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT ListRelatedOccurrences(
			CATBaseUnknown * ipiContext,
			CATListPtrCATIPLMNavOccurrence & ioRelatedOccurrencesList) = 0;

		/**
		 * Gets the First level Occurrence in a given context.
		 * <br> <b>Role:</b>
		 * This methode, retrieves the first level occurrence correponding to "this" which is an instance.
		 * <pre> For example this reference model:
		 * Ref0
		 *  |
		 *  +- Instance of ref1
		 *          |
		 *          +-Ref1
		 *              |
		 *              +- Instance of ref2
		 *                          |
		 *                          +-Ref2
		 * </pre>
		 * Correspond to this occurrence view:
		 * <pre> 
		 * Occurrence of Ref0
		 *         |
		 *         +- Occurrence of Ref1
		 *                     |
		 *                     +- Occurrence of Ref2
		 * </pre>
		 * So in the context of Occurrence of Ref0, if we ask on Instance of Ref1 to getting the first level occurence, 
		 * we will get the Occurrence of Ref1.
		 * Conversely, if we ask with the same context, on Instance of Ref2 to getting the first level occurrence, we will get an error as, 
		 * there is no first level occurrence, corresponding to this instance.
		 * Also, if we ask in the context of OccurrenceOfRef1, on instance of Ref2 to getting the first level occurrence, 
		 * we will get an error: This is not the right occurrence tree to get a first level occurrence of this instance.
		 * @param ipiContext
		 *   The context of navigation.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Object implementing CATIPLMNavOccurrence</dt>
		 *     <dd>To navigate under the given Occurrence. 
		 *		   It should be an occurence corresponding to the father reference of this instance.
		 *		   If null, we get the default context corresponding to the father of this instance.
		 *	   </dd>
		 *   </dl>
		 * @param opiFirstLevelOccurrence [out, CATBaseUnknown#Release]
		 *   The First level Occurrence.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>NULL</dt>
		 *     <dd>There is no First level Occurrence in the context.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>There is a first level Occurrence in the context.</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The output (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_INVALIDARG</dt>
		 *     <dd>The context is not correct.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Instance is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetFirstLevelOccurrence(
			CATIPLMNavOccurrence * ipiContext,
			CATIPLMNavOccurrence *& opiFirstLevelOccurrence) = 0;
		
};

CATDeclareHandler(CATIPLMNavInstance, CATBaseUnknown);

#endif
