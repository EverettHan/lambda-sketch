// COPYRIGHT Dassault Systemes 2014
//===================================================================
#ifndef CATPLMNavRepOccAdapterForRepInst_H
#define CATPLMNavRepOccAdapterForRepInst_H
/**
 * @level Protected
 * @usage U2
 */
#include "CATPLMComponentInterfaces.h"

#include "CATIPLMNavRepOccurrence.h"
#include "CATPLMAuthoringStreamDescriptorKind.h"

class CATUnicodeString;

class CATIPLMNavOccurrence;
class CATIPLMNavRepInstance;
class CATIPLMNavRepReference;

/**
* Adapter class for @href CATPLMComponentInterfaces.CATIPLMNavOccurrence interface.
* This adpater is dedicated to modeler that does'nt deploy Rep Occurrences.
* The implementation just delegates to the rep reference associated to the rep instance.
*/
class ExportedByCATPLMComponentInterfaces CATPLMNavRepOccAdapterForRepInst : public CATIPLMNavRepOccurrence
{
public :
  CATPLMNavRepOccAdapterForRepInst();
  virtual ~CATPLMNavRepOccAdapterForRepInst();
  virtual HRESULT GetFather(CATIPLMNavOccurrence*& opFather);
  /* @param opRepInstance [out, CATBaseUnknown#Release] */
  virtual HRESULT GetRelatedRepInstance(CATIPLMNavRepInstance*& opRepInstance);
  /* @param opRepReference [out, CATBaseUnknown#Release] */
  virtual HRESULT GetRelatedRepReference(CATIPLMNavRepReference*& opRepReference);
  /* @param oApplicativeContainer [out, CATBaseUnknown#Release] */
  virtual HRESULT RetrieveApplicativeContainer(const CATUnicodeString& iIdentifier, const IID & iIID, void ** oApplicativeContainer);
  virtual HRESULT GetContentKind(CATPLMAuthoringStreamDescriptorKind & oContentKind);

private:
  CATPLMNavRepOccAdapterForRepInst(const CATPLMNavRepOccAdapterForRepInst & iObjectToCopy);
  CATPLMNavRepOccAdapterForRepInst & operator = (const CATPLMNavRepOccAdapterForRepInst & iObjectToCopy);
};
#endif
