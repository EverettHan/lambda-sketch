/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2003
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMOpenFactory_H
#define CATIPLMOpenFactory_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
class CATIPLMIntegRecordRead;
class CATIPLMEngineErrorReporter;
class CATIPLMSpecializationBuilder;

// On deprecation
class CATIPLMOpenEngineMediator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOpenFactory;
#else
extern "C" const IID IID_CATIPLMOpenFactory ;
#endif

/**
 * Interface defining the communication protocol between the session building mediator and the elementary factories.
 * <b>Role</b>: The elementary factories are assessed to create the component related to the provided element and
 * manage the creation of the related extensions (thanks to the @href CATIPLMSpecializationBuilder). 
 * The registering operation on the TOS will be done by the mediator itself thanks to the component returned by the
 * factory.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMOpenFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
 * @deprecated V5R202
 * @use CATIPLMOpenFactory#OpenComponent
 */
  virtual HRESULT Open( CATIPLMIntegRecordRead * iRecord, CATIPLMOpenEngineMediator * iMediator,
                        CATIPLMEngineErrorReporter * ioErrorReporter=NULL ) = 0;

/** 
 * Ask the elementary factory to open in CATIA the component associated to the provided element.
 * The provided object implements the protocol defined by the @href CATIPLMIntegRecordRead interface.
 *
 * <br><b>Role</b>: This method is assessed to:
 * <li> Create the elementary component in session.</li>
 * <li> If needed, enhance the component with specialization extension through @href CATIPLMSpecializationBuilder protocol.</li>
 *
 * @param iRecord [in]
 *   The provided description of the element to create.
 * @param iSpcBuilder [in]
 *   The communication protocol enabling the factory to deal with its specializing extension.
 * @param iMediationAddin [in]
 *   A possible entry point for special treatment during the transaction such as @href CATIPLMOpenMediator for instance. Can be nul.
 * @param iErrorReporter [in]
 *   The error reporter in which the factory can log the error that happened during the operation.
 * @param oComponent [out, CATBaseUnknown#Release]
 *   The created component. Will be used by the session builder for registration on the TOS.
 *
 * @return
 *   <code>S_OK</code> if the provided object was successfully treated or an error was posted in the provided reporter.
 *   <code>E_FAIL</code> if the factory could not deal with the provided object due to system error.
 *
 */
  virtual HRESULT OpenComponent( CATIPLMIntegRecordRead * iRecord, CATIPLMSpecializationBuilder * iSpcBuilder,
                                 IUnknown * iMediationAddin, CATIPLMEngineErrorReporter * iErrorReporter,
                                 CATBaseUnknown *& oComponent ) = 0;

/** 
 * Enables the session builder to ask the component factory if the created component can be enriched with auxiliary
 * extensions.
 *
 * <br><b>Role</b>: If the component is extendable, the session builder will call the auxiliary factories for all
 * the extensions available in the message for this component.
 *
 * @param iComponent [in]
 *   The component which could be enriched with extensions.
 * @param oIsExtendable [out]
 *   The choice.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok, otherwise...
 *
 */
  virtual HRESULT IsExtendable( CATBaseUnknown * iComponent, CATBoolean & oIsExtendable ) = 0;
};
CATDeclareHandler( CATIPLMOpenFactory, CATBaseUnknown );
#endif
