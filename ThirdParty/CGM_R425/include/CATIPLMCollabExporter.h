 /* -*-c++-*- */

/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMCollabExporter_h
#define CATIPLMCollabExporter_h

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATPLMID;
class CATIBBStreamer;

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule     999
#define CATPLMIntegrationInterfaces AuthorizedModule
#define CATPLMItgTests AuthorizedModule
#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMIntegration AuthorizedModule
#define CATPLMCollabMgt AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
      #error Forbidden Access to CATIPLMCollabExporter Interface
      @error
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMItgTests
#undef CATPLMIntegrationAccess
#undef CATPLMIntegration
#undef CATPLMCollabMgt
// ----------------------------------------------------------------------------------------------------------------------

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMCollabExporter;
#else
extern "C" const IID IID_CATIPLMCollabExporter ;
#endif

/**
 * Interface defining the communication protocol between a user and collaboration processors.
 * <b>Role</b>: This protocol enables a user to marshall a set of components available in the session into
 * a @href CATIBBStreamer protocol.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMCollabExporter : public CATBaseUnknown
{
  CATDeclareInterface;

public :

/** 
 * Add a component for next marshalling operation.
 * <br><b>Role</b>: A component can be added for treatment into the marshalling process.</li>
 *
 * @param iComponent [in]
 *   The provided component. It must be fully defined in the provided dataspace 
 * (@href CATPLMComponentCollabBuilder#GetCollabExporter), else a <code>E_INVALIDARG</code> return can be expected.
 *
 * @return
 *   <code>S_OK</code> if the component was successfully added into the set of components to treat.
 *   <code>E_FAIL</code> if an unexpected error occured.
 *   <code>E_INVALIDARG</code> if the provided component is invalid for marshalling.
 *
 */
  virtual HRESULT AddComponent( const CATPLMID & iComponent )=0;

/** 
 * Trigger an Export operation.
 * <br><b>Role</b>: All the components provided will be marshalled into the @href CATIBBStreamer protocol.</li>
 * <ul>
 * <li> No completion protocol is called on the provided set of components.</li>
 * <li> The provided set must respect the integrity rules. An invalid set will result in a <code>ERR_02</code> error.</li>
 * </ul>
 *
 * @param iStreamer [in]
 *   The streamer the components will be marshalled into.
 *
 * @return
 *   <code>S_OK</code> if the operation ran succesfully.
 *   <code>E_FAIL</code> if an unexpected error occured.
 *   <code>E_INVALIDARG</code> if the provided streamed is invalid.
 *
 */
  virtual HRESULT ExportComponents( CATIBBStreamer * iStreamer )=0;
};
CATDeclareHandler(CATIPLMCollabExporter, CATBaseUnknown);
#endif
