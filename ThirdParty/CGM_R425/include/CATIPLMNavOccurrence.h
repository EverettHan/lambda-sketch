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
#ifndef CATIPLMNavOccurrence_H
#define CATIPLMNavOccurrence_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"

class CATIPLMNavReference;
class CATIPLMNavInstance;
class CATListPtrCATIPLMNavOccurrence;
class CATListPtrCATIPLMNavRepOccurrence;

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavOccurrence;

/**
 * Interface to navigate on an Occurrence.
 * <p>
 * An Occurrence is a projection of contextual Instance-Reference pair.
 * </p>
 * <ul>
 * <li>The context being the root is also projected</li>
 * <li>It is however the sole occurrence with no target instance, and no aggregating parent occurrence</li>
 * </ul>
 * <p>
 * An Occurrence carries conceptually:
 * </p>
 * <ul>
 * <li>The id of the corresponding target Reuse Model object (Reference or Representation)</li>
 * <li>The id of the Path of the corresponding Reuse Model object, including the target Instance</li>
 * <li>All static (i.e: non-computed) attributes of represented Instance and Reference(including those from customization)</li>
 * <li>The projection of (i.e: absolute) computed attributes of represented Instance-Reference pair</li>
 * </ul>
 * <p>
 * An occurrence has no attributes on its own
 * </p>
 * <ul>
 * <li>Any edition can and must be fully delegated to the projected Instance-Reference pair</li>
 * <li>Update of projection will then reflect this change</li>
 * <li>No overloading of attribute is supported by Occurrence</li>
 * </ul>
 * <p>
 * The projection is not done automatically during navigation. Only few operations creates the occurrences:
 * </p>
 * <ul>
 * <li>Expand all with a filter
 * <li>Expand Step by step
 * <li>Direct Open of an Occurrence
 * </ul>
 * <p>
 * This means that the ListRelatedOccurrences method returns no occurrence for a given Reference or Instance in a given context
 * if, at least, one occurrence was not cretated before using one of these operations.
 * </p>
 */
class ExportedByCATPLMComponentInterfaces CATIPLMNavOccurrence: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
		
		/**
		 * Retrieves the Occurrence which aggregates the Occurrence.
		 * @param opiOccurrence [out, CATBaseUnknown#Release]
		 *   The father.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>NULL</dt>
		 *     <dd>An error is detected.</dd>
		 *     <dt>Valid</dt>
		 *     <dd>Usable Occurrence.</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The father is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Occurrence is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetFather(CATIPLMNavOccurrence *& opiOccurrence) = 0;
		
		/**
		 * Retrieves the list of direct child Occurrences of the Occurrence.
		 * @param ioChildrenList
		 *   The list of children. Warning this list is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>The Occurrence has no child.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>The Occurrence has children (in this case the order is not guaranteed).</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The list (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Occurrence is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT ListChildren(CATListPtrCATIPLMNavOccurrence & ioChildrenList) = 0;

		/**
		 * Retrieves the related Instance (which is related to the Occurrence in a given context).
		 * @param opiInstance [out, CATBaseUnknown#Release]
		 *   The related Instance.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>NULL</dt>
		 *     <dd>An error is detected or the Occurrence is a root.</dd>
		 *     <dt>Valid</dt>
		 *     <dd>Usable Instance.</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The related Instance is successfully returned.</dd>
		 *     <dt>S_FALSE</dt>
		 *     <dd>The Occurrence is a root.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Occurrence is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetRelatedInstance(CATIPLMNavInstance *& opiInstance) = 0;
		
		/**
		 * Retrieves the related Reference (which is related to the Occurrence in a given context).
		 * @param opiReference [out, CATBaseUnknown#Release]
		 *   The related Reference.
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
		 *     <dd>The related Reference is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Occurrence is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetRelatedReference(CATIPLMNavReference *& opiReference) = 0;
				
		/**
		 * Retrieves the list of direct child RepOccurrences of the Occurrence.
		 * @param ioRepChildrenList
		 *   The list of rep children. Warning this list is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>The Occurrence has no rep child.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>The Occurrence has rep children (in this case the order is not guaranteed).</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The list (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The Occurrence is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT ListRepChildren(CATListPtrCATIPLMNavRepOccurrence & ioRepChildrenList) = 0;
		
};

CATDeclareHandler(CATIPLMNavOccurrence, CATBaseUnknown);

#endif
