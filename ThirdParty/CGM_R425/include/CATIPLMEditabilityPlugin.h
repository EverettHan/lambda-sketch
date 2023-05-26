#ifndef CATIPLMEditabilityPlugin_H
#define CATIPLMEditabilityPlugin_H

#include "CATBaseUnknown.h"
#include "CATPLMComponentInterfaces.h"

ExportedByCATPLMComponentInterfaces extern const IID IID_CATIPLMEditabilityPlugin;

/**
 * this interface allows apps/modelers to make a PLM component appear read-only (CATPLMEditabilityServices::GetEditabilityStatus)
 *
 * this class must be implemented on a late type named <your plugin name>For<the name of the plm type it applies>
 * everybody can implement CATIPLMEditabilityPlugin on any plm type
 * there can be several CATIPLMEditabilityPlugin implementations for a plm type
 *
 * for example, a plugin for type VPMReference could be named 'CATXXXMyPluginForVPMReference'
 * the CATXXXMyPlugin part of the name is free, implementor is responsible for its unicity
 *
 *  class CATXXXMyPluginForVPMReference: public CATIPLMEditabilityPlugin
 *  {
 *   CATDeclareClass;
 *   bool IsReadOnly(const CATBaseUnknown& iPLMComponent) const { ... }
 *  };
 *  CATImplementClass(CATXXXMyPluginForVPMReference, Implementation, CATIPLMEditabilityPlugin, CATNull);
 *  CATImplementBOA(CATIPLMEditabilityPlugin,CATXXXMyPluginForVPMReference);
 *  CATCreateAndAddOMFactoryFunction(CATXXXMyPluginForVPMReference);
 *
 *  do not forget .dic and .func files
 *
 * this interface must not be used but only implemented
 */
class ExportedByCATPLMComponentInterfaces CATIPLMEditabilityPlugin : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
   * Override editability status of a PLM component
   * Can be overriden.
   * Must not be called directly
   *
   * @param iPLMComponent
   *  a valid PLM component (implements CATIPLMComponent for example)
   * @return
   *   true
   *      CATPLMEditabilityServices::GetEditabilityStatus will answer read-only for this component
   *      CATPLMEditabilityServices::SwitchToReadWrite will report an error for this component
   *      CATPLMEditabilityServices::CanBeSaved will report an error for this component
   *   false
   *      do not force iPLMComponent to appear read-only
   *      iPLMComponent can still be read-only due to other mechanisms
   *
   * the answer is expected to be stable
   */
  virtual bool IsReadOnly(const CATBaseUnknown& iPLMComponent) const = 0;
};

#endif
