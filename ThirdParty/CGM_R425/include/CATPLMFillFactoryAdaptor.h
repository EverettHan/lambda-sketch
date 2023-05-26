/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
* @level Protected
* @usage U2
*/
#ifndef CATPLMFillFactoryAdaptor_H
#define CATPLMFillFactoryAdaptor_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMFillFactory.h"
class CATIPLMIntegRecordRead;
class CATIPLMOpenMediator;
class CATIPLMEngineErrorReporter;

/**
 * Implementation adapter for the @href CATPLMIntegrationInterfaces.CATIPLMFillFactory interface.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMFillFactoryAdaptor : public CATIPLMFillFactory
{
public:

  CATPLMFillFactoryAdaptor( void );
  virtual ~CATPLMFillFactoryAdaptor( void );

/**
 * @see CATPLMIntegrationInterfaces.CATIPLMFillFactory#FillComponent
 */
  virtual HRESULT FillComponent( CATIPLMIntegRecordRead * iFillInformation, CATIPLMOpenMediator * iSwitchRegistrator,
                                 CATIPLMEngineErrorReporter * iErrorReporter );

private:
  CATPLMFillFactoryAdaptor( const CATPLMFillFactoryAdaptor & );
  CATPLMFillFactoryAdaptor & operator =( const CATPLMFillFactoryAdaptor & );
};
#endif
