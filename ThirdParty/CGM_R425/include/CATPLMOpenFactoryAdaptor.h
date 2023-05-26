/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
* @level Protected
* @usage U2
*/
#ifndef CATPLMOpenFactoryAdaptor_H
#define CATPLMOpenFactoryAdaptor_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMOpenFactory.h"
class CATIPLMIntegRecordRead;
class CATIPLMEngineErrorReporter;

/**
 * Implementation adapter for the @href CATPLMIntegrationInterfaces.CATIPLMOpenFactory interface.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMOpenFactoryAdaptor : public CATIPLMOpenFactory
{
public:

  CATPLMOpenFactoryAdaptor( void );
  virtual ~CATPLMOpenFactoryAdaptor( void );

/**
 * @see CATPLMIntegrationInterfaces.CATIPLMOpenFactory#Open
 */
  virtual HRESULT Open( CATIPLMIntegRecordRead * iRecord, CATIPLMOpenEngineMediator * iMediator,
                        CATIPLMEngineErrorReporter * ioErrorReporter=NULL );

/**
 * @see CATPLMIntegrationInterfaces.CATIPLMOpenFactory#OpenComponent
 */
  virtual HRESULT OpenComponent( CATIPLMIntegRecordRead * iRecord, CATIPLMSpecializationBuilder * iSpcBuilder,
                                 IUnknown * iMediationAddin, CATIPLMEngineErrorReporter * iErrorReporter,
                                 CATBaseUnknown *& oComponent );

/**
 * @see CATPLMIntegrationInterfaces.CATIPLMOpenFactory#IsExtendable
 */
  virtual HRESULT IsExtendable( CATBaseUnknown * iComponent, CATBoolean & oIsExtendable );

private:

  CATPLMOpenFactoryAdaptor( const CATPLMOpenFactoryAdaptor & );
  CATPLMOpenFactoryAdaptor & operator =( const CATPLMOpenFactoryAdaptor & );
};
#endif
