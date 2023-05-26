/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2009
#ifndef CATIPLMMinorVersionOverloadingEngine_H
#define CATIPLMMinorVersionOverloadingEngine_H

/**
 * @level Protected
 * @usage U3
 */
#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATPLMIDSet;
class CATIPLMMinorVersionOverloadingSolution_var;
class CATIAdpErrorMonitor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMMinorVersionOverloadingEngine;
#else
extern "C" const IID IID_CATIPLMMinorVersionOverloadingEngine ;
#endif

/**
 * The engine allowing to overload minor versions
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMMinorVersionOverloadingEngine: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Returns current error monitor
  * 
  * @param oErrorMonitor
  *        The error monitor
  * @return 
  *        S_OK if request succeeded.
  *        E_FAIL if request failed.
  */
  virtual HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorMonitor) const = 0;

  /**
  * Build overload solution
  *
  * @param iWaitingMinorVersions
  *        List of tagetted versions.
  * @param oSolution
  *        The overload solution.
  *        != NULL_var : if something to do.
  *        == NULL_var : if nothing to do.
  *  
  * @return 
  *        S_OK    if something to do.
  *        S_FALSE if nothing to do.
  *        E_FAIL  if internal failure.
  */
  virtual HRESULT ValidateSolution(const CATPLMIDSet & iWaitingMinorVersions, CATIPLMMinorVersionOverloadingSolution_var & oSolution) = 0;

};
CATDeclareHandler( CATIPLMMinorVersionOverloadingEngine, CATBaseUnknown );
#endif
