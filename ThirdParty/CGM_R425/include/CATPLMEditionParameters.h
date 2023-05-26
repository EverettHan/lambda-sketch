// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATPLMEditionParameters.h
// Define CATPLMEditionParameters Class
//
//===================================================================
//
// Usage notes:
//   CATPLMEditionParameters : the class allows to specify parameters
//   applied on PLM Component Edition Operations
//
// Copy of CATPrdEditionParameters.h
//
//===================================================================
//
//  Oct 2007  Creation:
//===================================================================
/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMEditionParameters_H
#define CATPLMEditionParameters_H

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"

/**
 * yet another ridiculous and absolutely useless class
 * replace it by...a pointer
 */
class ExportedByCATPLMModelerBaseInterfaces CATPLMEditionParameters
{
public:
  CATPLMEditionParameters();
  virtual ~CATPLMEditionParameters();
  HRESULT SetConfigOperationsInput(CATBaseUnknown *iInputForCfgOperations);
  HRESULT GetConfigOperationsInput(const IID& iIID, void **oInputForCfgOperations);
private:
  CATOmxSR<CATBaseUnknown> _pInputForCfgOperations;
};

#endif
