/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMCloningEngineAbstract_H
#define CATPLMCloningEngineAbstract_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class ExportedByCATPLMIntegrationInterfaces CATPLMCloningEngineAbstract : public CATBaseUnknown
{
public:
/** 
 * Ask the Engine to reset the Configuration.
 *
 * <br><b>Role</b>: Enables the user to reset the Configuration on the cloned structure. 
 * <ul>
 * <li>This cannot be used together with @href CATPLMCloningMode#Classical_WithSessionModification or @href CATPLMCloningMode#KeepFamily_WithSessionModification cloning modes.</li>
 * <li>If Configuration Reset fails by the end on the duplication operation, <code>ERR_05</code> error is raised through the @href CATIAdpErrorMonitor.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the parameter is set on the Engine.</li> 
 *   <li><tt>E_FAIL</tt> if the operation failed.</li>
 *   <li><tt>E_UNEXPECTED</tt> if the cloning mode is dealing with Session modification.</li>
 *   </ul>
 */
  virtual HRESULT ResetConfig()=0;
};
#endif
