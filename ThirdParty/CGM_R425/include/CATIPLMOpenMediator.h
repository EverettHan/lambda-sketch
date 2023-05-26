/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
#ifndef CATIPLMOpenMediator_H
#define CATIPLMOpenMediator_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOpenMediator;
#else
extern "C" const IID IID_CATIPLMOpenMediator;
#endif

/**
 * Communication protocol between the factories and the open engine.
 * Acts as an addin in the session building mediation protocol. Can therefore be seen by the 
 * @href CATPLMIntegrationInterfaces.CATIPLMOpenFactory and
 * @href CATPLMIntegrationInterfaces.CATIPLMOpenSpecializationFactory behaviors implementations.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMOpenMediator: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
 * Restricted access: @see CATIPLMSessionBuildingMediator#OpenSingle.
 * Enables to the factories to register on the switch engine protocol a component that will have to be called back 
 * later for streaming management by the switch engine.
 *
 * <br><b>Role</b>: Registration for switch management.
 *
 * @param CATBaseUnknown * iObject [in]
 *   The provided component.
 * @return
 * 
 * <dt> <code>HRESULT</code>     <dd> Similar to @href CATIOmiSwitchEngine#AddObjectToTreat.
 *
 */
  virtual HRESULT RegisterForSwitch( CATBaseUnknown * iObject ) = 0;
};
CATDeclareHandler( CATIPLMOpenMediator, CATBaseUnknown );
#endif
