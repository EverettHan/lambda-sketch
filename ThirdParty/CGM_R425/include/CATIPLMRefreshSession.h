#ifndef CATIPLMRefreshSession_H
#define CATIPLMRefreshSession_H

// implementation limited to some components
#define AuthorizedModule 999
#define CATPLMClientCoreModel       AuthorizedModule
#define CATPLMIntegration           AuthorizedModule
#define CATPLMIntegrationInterfaces AuthorizedModule
#define CATPLMModelBuilder          AuthorizedModule 
#define CATPCCTestLib               AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header limited to some components. Ask JBB.
#endif

#undef CATPLMClientCoreModel
#undef CATPLMIntegration
#undef CATPLMIntegrationInterfaces
#undef CATPLMModelBuilder
#undef CATPCCTestLib
#undef AuthorizedModule

// end of checks

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATIPLMAttributesReader;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMRefreshSession;
#else
extern "C" const IID IID_CATIPLMRefreshSession;
#endif

/**
* @level Protected
* @usage U4 [CATPLMRefreshSessionAdaptor]
*/

class CATOmxKeyValueBlock;
class CATPLMTypeH;

/**
 * FORBIDDEN USE
 * internal protocol between CATPLMIntegration and CATPLMClientCore
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMRefreshSession : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * DEPRECATED
   */
  virtual HRESULT UpdateSessionAttributes(CATIPLMAttributesReader* ipAttrReader, const CATPLMTypeH& iExtensionType) = 0;

  /**
   * update PC2 attributes after a server transaction
   */
  virtual HRESULT UpdateSessionAttributes(const CATOmxKeyValueBlock& iAttrBlock, const CATPLMTypeH& iExtensionType) = 0;

  /**
   * "enrich" this object (loaded in light mode) with provided attributes
   */
  virtual HRESULT EnrichSessionAttributes(const CATOmxKeyValueBlock& iAttrBlock) = 0;

  /**
   * remove extension
   */
  virtual HRESULT RemoveExtension(const CATPLMTypeH& iExtensionType) = 0;
};

//------------------------------------------------------------------

#endif
