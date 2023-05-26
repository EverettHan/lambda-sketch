/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
#ifndef CATIPLMSessionBuildingMediator_H
#define CATIPLMSessionBuildingMediator_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATIPLMIntegRecordRead;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSessionBuildingMediator;
#else
extern "C" const IID IID_CATIPLMSessionBuildingMediator;
#endif

/**
 * Communication protocol between the factories and the session builder.
 * Defines a set of protocols that are used by the factories to access to dedicated factories:
 *   - Bulk factories can access to elementary factories.
 *   - Elementary factories can access to specialization factories.
 * This protocol can only be seen by the @href CATPLMIntegrationInterfaces.CATIPLMOpenFactory and
 * @href CATPLMIntegrationInterfaces.CATIPLMOpenBulkFactory behaviors implementations.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMSessionBuildingMediator: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
 * Primary and mission critical entry point of the communication protocol. None of the other methods
 * can work if the OpenSingle method was not previously called.
 * Once a bulk factory has sequenced the calls to the elementary factories, it can trigger those on 
 * objects by calling OpenSingle. The open single mediator will match the PLM type of the element 
 * with a factory implementing the @href CATPLMIntegrationInterfaces.CATIPLMOpenFactory behavior.
 *
 * @param <tt>CATIPLMIntegRecordRead * ipRecord</tt>
 * [in] The description of the element to open.
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> Similar to @href CATIPLMOpenFactory#Open.
 * <dt> <tt>E_FAIL</tt>   <dd> Similar to @href CATIPLMOpenFactory#Open.
 * </dl>
 */
  virtual HRESULT OpenSingle( CATIPLMIntegRecordRead * ipRecord ) = 0;
};
CATDeclareHandler( CATIPLMSessionBuildingMediator, CATBaseUnknown );
#endif
