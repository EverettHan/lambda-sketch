#ifndef PLMRepStreamServices_H
#define PLMRepStreamServices_H

#include "CATPLMModelerBaseInterfaces.h"

#include "PLMRepLoadMode.h"
#include "CATUnicodeString.h"
#include "CATPLMOccurrenceWrapper.h"
#include "CATOmxQIPtr.h"

class CATBaseUnknown;
class PLMIRepReference;

//------------------------------------------------------------------

/**
 * Class providing services to access and manipulate stream of a Representation Reference or a Representation Occurrence.
 */

class ExportedByCATPLMModelerBaseInterfaces PLMRepStreamServices
{
public:

  PLMRepStreamServices(CATPLMOccurrenceWrapper & iRepOccurrenceWrap);
  PLMRepStreamServices(PLMIRepReference * iRepRef);
  virtual ~PLMRepStreamServices();

  /**
  * Retrieves the document associated to the Representation. <br>
  * No access to the document is provided if the stream associated to the Representation is
  * a CATData: the method will fail. <br>
  * For other kind of stream, the returned document will depend on the current loading mode of the Representation. <br>
  *
  *  @param opLoadedData  [CATBaseUnknown#Release]
  *      The document associated to the Representation. <br>
  *      Output parameter. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @return
  *      <code>S_OK</code> if the method succeeds. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_UNEXPECTED</code> if the stream associated to the Representation is a CATData. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT GetLoadedData(CATBaseUnknown *&opLoadedData);

  /**
  * Computes the loading mode.
  *
  * @param  oLoadMode
  *      The loading mode of the Representation. <br>
  *      Output parameter.
  * @return
  *      <code>S_OK</code> if the loading mode of the Representation has been successfully computed. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT ComputeLoadingMode(PLMRepLoadMode & oLoadMode);

  /**
  * Changes the loading mode. <br>
  * According to the Representation kind, the change of mode can succeed but the Representation
  * can be in a different loading mode than the desired one. In this case, the loading mode can be retrieved
  * with the @href #ComputeLoadingMode method.<br>
  *
  * @param  iNewMode
  *      The new loading mode to be changed to. <br>
  *      Input parameter.
  * @return
  *      <code>S_OK</code> if the loading mode of the Representation has been successfully changed. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT ChangeLoadingMode(PLMRepLoadMode iNewMode);

  /**
  * Creates an applicative container inside the stream associated to the representation.
  *
  *  @param  opApplicativeContainer  [CATBaseUnknown#Release]
  *      The new created applicative container. <br>
  *      Output parameter. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @param  iContainerType
  *      The applicative container type. <br>
  *      Input parameter.
  *  @param  iIID
  *      The interface type returned through <tt>opApplicativeContainer</tt> parameter. <br>
  *      Input parameter.
  *  @param  iContainerSuperType
  *      The supertype of the applicative container. <br>
  *      By default, the applicative container has no supertype. Otherwise it must be set to the feature container type (CATFeatCont). <br>
  *      Input parameter.
  *  @param  iIdentifier
  *      The name of the applicative container, useful to retrieve it later. <br>
  *	    By default, the name is set to the container type iContainerType. <br>
  *      Input parameter. <br>
  *      <b>Note:</b> If you want to create several applicative containers with the same type, the parameter iIdentifier
  *      becomes mandatory, because two applicative containers can not have the same name.
  *  @return
  *      <code>S_OK</code> if the method succeeds. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT CreateApplicativeContainer(CATBaseUnknown *&opApplicativeContainer, const CATIdent iContainerType, const IID & iIID, const CATIdent iContainerSuperType = "", const CATUnicodeString & iIdentifier = "");

  /**
  * Retrieves an applicative container inside the stream associated to the representation.
  *
  *  @param  iIdentifier
  *      The name of the applicative container. <br>
  *      Input parameter.
  *  @param  iIID
  *      The interface type returned through <tt>opApplicativeContainer</tt> parameter. <br>
  *      Input parameter.
  *  @param  opApplicativeContainer  [CATBaseUnknown#Release]
  *      The applicative container. <br>
  *      Output parameter. <br>
  *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise. <br>
  *      This parameter is returned to caller as NULL if method fails. <br>
  *      This parameter is valuated if method succeeds.
  *  @return
  *      <code>S_OK</code> if the method succeeds. <br>
  *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  HRESULT RetrieveApplicativeContainer(const CATUnicodeString & iIdentifier, const IID & iIID, CATBaseUnknown *&opApplicativeContainer);

private:
  CATPLMOccurrenceWrapper _occWrap;
  CATOmxQIPtr<PLMIRepReference> _repRef;
};

//------------------------------------------------------------------
#endif
