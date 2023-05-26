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
#ifndef CATIPLMNavReference_H
#define CATIPLMNavReference_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"

#include "CATPLMCoreType.h"

class CATListPtrCATIPLMNavEntity;
class CATListPtrCATIPLMNavInstance;
class CATListPtrCATIPLMNavOccurrence;

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavReference;

/**
 * Interface to navigate on a Reference.
 */
class ExportedByCATPLMComponentInterfaces CATIPLMNavReference: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
		
		/**
		 * Retrieves the list of direct children (Instance or Representation Instance for this version) of the Reference.
		 * @param ioChildrenList
		 *   The list of direct children. Warning this list is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>The Reference has no child.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>The Reference has children (in this case the order is not guaranteed).</dd>
		 *   </dl>
		 * @param iiFilterSize
		 *   The size of the array of types to filter.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>0</dt>
		 *     <dd>All children are listed.</dd>
		 *     <dt>&gt 0</dt>
		 *     <dd>Only the children of the given types are listed.</dd>
		 *   </dl>
		 * @param ipFilter
		 *   The array of types to filter.
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The list (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_INVALIDARG</dt>
		 *     <dd>One of the arguments is incorrect (iiFilterSize &lt 0).</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Reference is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 * @example
		 *   <pre>
		 *   CATIPLMNavReference * piReference = ...;
		 *   CATListPtrCATIPLMNavEntity allChildrenList;
		 *   HR = piReference->ListChildren(allChildrenList, 0, NULL);
		 *   CATListPtrCATIPLMNavEntity oneTypeChildrenList;
		 *   CATPLMCoreType coreType = PLMCoreRepInstance;
		 *   HR = piReference->ListChildren(oneTypeChildrenList,  1, &coreType);
		 *   </pre>
		 */
		virtual HRESULT ListChildren(
			CATListPtrCATIPLMNavEntity & ioChildrenList,
			const int & iiFilterSize,
			CATPLMCoreType * ipFilter) = 0;
		
		/**
		 * Retrieves the list of Instances which are instance of the Reference.
		 * @param ioInstancesList
		 *   The list of Instances. Warning this list is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>The Reference is not instanciated.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>The References is instanciated (in this case the order is not guaranteed).</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The list (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Reference is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT ListInstances(CATListPtrCATIPLMNavInstance & ioInstancesList) = 0;
		
		/**
		 * Retrieves the Occurrences related to the Reference in a given context.
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
		 *     <dd>The Reference is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT ListRelatedOccurrences(
			CATBaseUnknown * ipiContext,
			CATListPtrCATIPLMNavOccurrence & ioRelatedOccurrencesList) = 0;
		
};

CATDeclareHandler(CATIPLMNavReference, CATBaseUnknown);

#endif
