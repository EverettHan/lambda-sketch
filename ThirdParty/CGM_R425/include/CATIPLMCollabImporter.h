/* -*-c++-*- */

/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMCollabImporter_h
#define CATIPLMCollabImporter_h

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATIBBStreamer;
class CATComponentId;

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule     999
#define CATPLMIntegrationInterfaces AuthorizedModule
#define CATPLMItgTests AuthorizedModule
#define CATPLMIntegrationAccess AuthorizedModule
#define CATPLMIntegration AuthorizedModule
#define CATPLMCollabMgt AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
      #error Forbidden Access to CATIPLMCollabImporter Interface
      @error
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMItgTests
#undef CATPLMIntegrationAccess
#undef CATPLMIntegration
#undef CATPLMCollabMgt
// ----------------------------------------------------------------------------------------------------------------------

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMCollabImporter;
#else
extern "C" const IID IID_CATIPLMCollabImporter ;
#endif

/**
 * Interface defining the communication protocol between a user and collaboration processors.
 * <b>Role</b>: This protocol enables a user to marshall a set of components available in the session into
 * a @href CATIBBStreamer protocol.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMCollabImporter : public CATBaseUnknown
{
  CATDeclareInterface;

public :

/** 
 * Trigger an Import operation.
 * <br><b>Role</b>: All the components available in the provided flow will be unmarshalled into the target resolution space (@href CATPLMComponentCollabBuilder#GetCollabImporter).</li>
 *
 * @param iUnstreamer [in]
 *   The unstreamer the components will be unmarshalled from.
 *
 * @return
 *   <code>S_OK</code> if the operation ran succesfully.
 *   <code>E_FAIL</code> if an unexpected error occured.
 *   <code>E_INVALIDARG</code> if the provided unstreamer is invalid.
 *
 */
  virtual HRESULT ImportComponents( CATIBBStreamer * iUnstreamer )=0;

/** 
 * Enumerates the components unmarshalled into the resolution space.
 * <br><b>Role</b>: Enables the user to get a sum-up of the unmarshalled components.</li>
 *
 * @param ioPosition [inout]
 *   The index of the component to retrieve. Start with 0 for the first component. It is self incremented.
 * @param oComponent [out]
 *   The next unmarshalled component.
 *
 * @return
 *   <code>S_OK</code> if the component was successfully retrieved.
 *   <code>S_FALSE</code> if no more component is available, end of the enumeration.
 *   <code>E_FAIL</code> if an unexpected error occured.
 *   <code>E_INVALIDARG</code> if the index is invalid.
 *
 */
  virtual HRESULT NextTreatedComponent( unsigned int & ioPosition, CATComponentId & oComponent )=0;
};
CATDeclareHandler(CATIPLMCollabImporter, CATBaseUnknown);
#endif
