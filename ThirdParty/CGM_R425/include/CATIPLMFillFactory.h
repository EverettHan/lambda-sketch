/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFillFactory_H
#define CATIPLMFillFactory_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
class CATIPLMIntegRecordRead;
class CATIPLMEngineErrorReporter;
class CATIPLMOpenMediator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMFillFactory;
#else
extern "C" const IID IID_CATIPLMFillFactory ;
#endif

/**
 * Interface defining the communication protocol between the fill mediator and the fill factories.
 * <b>Role</b>: The fill factories have to complement the representation in the workspace of the component 
 * with the data retrieved through a query on the database.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMFillFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Ask the elementary factory to fill the representation of the component.
 * The provided object implements the protocol defined by the @href CATIPLMIntegRecordRead interface.
 *
 * <br><b>Role</b>: The factory called on this protocol must complement the data representing the component in the workspace
 * with the information provided.</li>
 *
 * @param iFillInformation [in]
 *   The provided description of the element to complement.
 * @param iSwitchRegistrator [in]
 *   Entry point enabling the factory to register a component as needing to be switched by the end of the transaction (@href CATIOmiSwitchEngine).
 * @param iErrorReporter [in]
 *   The error reporter in which the factory can log the error that happened during the operation.
 *
 * @return
 *   <code>S_OK</code> if the provided object was successfully treated or an error was posted in the provided reporter.
 *   <code>E_FAIL</code> if the factory could not deal with the provided object due to system error.
 *
 */
  virtual HRESULT FillComponent( CATIPLMIntegRecordRead * iFillInformation, CATIPLMOpenMediator * iSwitchRegistrator,
                                 CATIPLMEngineErrorReporter * iErrorReporter ) = 0;
};
CATDeclareHandler( CATIPLMFillFactory, CATBaseUnknown );
#endif
