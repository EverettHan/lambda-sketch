// COPYRIGHT Dassault Systemes 2014
//===================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
*/
#ifndef CATIPLMNavRepOccurrence_H
#define CATIPLMNavRepOccurrence_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATPLMAuthoringStreamDescriptorKind.h"

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavRepOccurrence;

class CATUnicodeString;
class CATIPLMNavOccurrence;
class CATIPLMNavRepInstance;
class CATIPLMNavRepReference;

/**
 * Interface to navigate on a Representation Occurrence.
 * <p>
 * A RepresentationOccurrence is a projection of contextual RepInstance-RepReference pair.
 * </p>
 * <p>
 * A Representation Occurrence carries conceptually:
 * </p>
 * <ul>
 * <li>The id of the corresponding target Reuse Model Representation object</li>
 * <li>The id of the Path of the corresponding Reuse Model object, including the target Representation Instance</li>
 * <li>All static (i.e: non-computed) attributes of represented Representation Instance and Representation Reference(including those from customization)</li>
 * <li>The projection of (i.e: absolute) computed attributes of represented RepInstance-RepReference pair</li>
 * </ul>
 * <p>
 * A Representation Occurrence has no attributes on its own.
 * </p>
 * <ul>
 * <li>Any edition can and must be fully delegated to the projected RepInstance-RepReference pair</li>
 * <li>Update of projection will then reflect this change</li>
 * <li>No overloading of attribute is supported by Occurrence</li>
 * </ul>
 * <p>
 * A Representation Occurrence can hold an overloaded stream.
 * </p>
 * <p>
 * The projection is not done automatically during navigation. Only few operations creates the Representation Occurrences:
 * </p>
 * <ul>
 * <li>Expand all with a filter
 * <li>Expand Step by step
 * <li>Direct Open of an Representation Occurrence
 * </ul>
 */

class ExportedByCATPLMComponentInterfaces CATIPLMNavRepOccurrence : public CATBaseUnknown
{
  CATDeclareInterface;

public :

  /**
  * Retrieves the Occurrence which aggregates the Representation Occurrence.
  * @param opFather [out, CATBaseUnknown#Release]
  *   The father.
  * @return
  *   <code>S_OK</code>The father is successfully retrieved. <br>
  *   <code>E_FAIL</code>otherwise.<br>
  */
  virtual HRESULT GetFather(CATIPLMNavOccurrence*& opFather) = 0;

  /**
  * Retrieves the related Representation Instance related to the Representation Occurrence.
  * @param opRepInstance [out, CATBaseUnknown#Release]
  *   The related Representation Instance.
  * @return
  *   <code>S_OK</code>The related Representation Instance is successfully retrieved. <br>
  *   <code>E_FAIL</code>otherwise.<br>
  */
  virtual HRESULT GetRelatedRepInstance(CATIPLMNavRepInstance*& opRepInstance) = 0;

  /**
  * Retrieves the related Representation Reference related to the Representation Occurrence.
  * @param opRepReference [out, CATBaseUnknown#Release]
  *   The related Representation Reference.
  * @return
  *   <code>S_OK</code>The related Representation Reference is successfully retrieved. <br>
  *   <code>E_FAIL</code>otherwise.<br>
  */
  virtual HRESULT GetRelatedRepReference(CATIPLMNavRepReference*& opRepReference) = 0;

  /**
  * Retrieve a given container of the Representation occurrence.
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
};

CATDeclareHandler(CATIPLMNavRepOccurrence, CATBaseUnknown);

#endif
