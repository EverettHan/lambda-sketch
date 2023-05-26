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
#ifndef CATIPLMNavRepReference_H
#define CATIPLMNavRepReference_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATPLMAuthoringStreamDescriptorKind.h"


class CATListPtrCATIPLMNavRepInstance;
class CATUnicodeString;
extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavRepReference;

/**
 * Interface to navigate on a Representation Reference.
 */
class ExportedByCATPLMComponentInterfaces CATIPLMNavRepReference: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
		
		/**
		 * Retrieves the list of Representation Instances which are instance of the Representation Reference.
		 * @param ioRepInstancesList
		 *   The list of Representation Instances. Warning this list is cleaned before treatment.
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>Empty</dt>
		 *     <dd>The Representation Reference is not instanciated.</dd>
		 *     <dt>Filled</dt>
		 *     <dd>The Representation References is instanciated (in this case the order is not guaranteed).</dd>
		 *   </dl>
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The list (Empty or Filled) is successfully returned.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The RepReference is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 CATAdpIdentificationSet
		 */
		virtual HRESULT ListInstances(CATListPtrCATIPLMNavRepInstance & ioRepInstancesList) = 0;

		/**
		 * Retrieve a given container of the RepReference.
		 * @param iIdentifier
		 *   The iIdentifier of the Container we are looking for.
		 * @param iIID
		 *   The IID of the interface.
		 * @param oApplicativeContainer [out, CATBaseUnknown#Release]
		 *   The retrieved container.
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The container is successfully returned.</dd>
		 *     <dt>E_NOINTERFACE</dt>
		 *     <dd>Interface corresponding to the IID, is not implmented on the container.</dd>
		 *     <dt>E_FAIL</dt>
		 *     <dd>The RepReference is not valid or the state of the system is not correct for this operation.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT RetrieveApplicativeContainer (	const CATUnicodeString& iIdentifier, 
														const IID & iIID,
														void ** oApplicativeContainer) = 0;		
		
		/**
		 * Retrieves the kind of authoring Stream Descriptor.
		 *
		 * @param oContentKind
		 *   The authoring Content kind.
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The Kind is successfully returned.</dd>
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT GetContentKind( CATPLMAuthoringStreamDescriptorKind & oContentKind ) = 0;

	    /**
		 * Check if a representation reference is only instantiable once.
		 * @return
		 *   HRESULT
		 *   <br><b>Legal values</b>:
		 *   <dl>
		 *     <dt>S_OK</dt>
		 *     <dd>The representation reference is instantiable only once.</dd>
		 *     <dt>S_FALSE</dt>
		 *     <dd>The representation reference is not instantiable only once.</dd>
		 *     <dt>E_NOTIMPL</dt>
		 *     <dd>No answer can be provided. The behavior is not implemented.</dd>	   
		 *     <dt>E_UNEXPECTED</dt>
		 *     <dd>There is an unexpected failure.</dd>
		 *   </dl>
		 */
		virtual HRESULT IsOnceInstantiable() = 0;
		
		
};

CATDeclareHandler(CATIPLMNavRepReference, CATBaseUnknown);

#endif
