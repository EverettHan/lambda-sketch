/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMStreamManagement_H
#define CATIPLMStreamManagement_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATPLMStreamDescriptor;
class CATVVSUrl;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMStreamManagement;
#else
extern "C" const IID IID_CATIPLMStreamManagement;
#endif

/**
 * Interface representing a communication protocol between the session building mediator and the factories.
 *
 * <br><b>Role</b>: Defines a protocol enabling a factory to ask for a treatment of some alternate stream by the end of the building process.
 * This protocol can only be seen by the @href CATPLMIntegrationInterfaces.CATIPLMOpenFactory behaviors implementations.
 * <p>
 * Do not use the CATIPLMStreamManagement interface for switch of representations management or mandatory streams management.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMStreamManagement: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * Entry point for stream registration.
 *
 * <br><b>Role</b>: Enables a user needing asynchronous unstreaming on its component to register the required
 * streams on the stream manager. The registered streams will be treatened by the end of the session building
 * operation.
 *
 * @param iStreamDescriptor [in]
 *   The descriptor of the registered stream.
 * @param iUrl [in]
 *   The URL the stream must be accessed from.
 *
 * @return
 *   <code>S_OK</code> if everything ran ok, otherwise...
 *
 */
  virtual HRESULT RegisterStream( const CATPLMStreamDescriptor & iStreamDescriptor, const CATVVSUrl & iUrl ) = 0;
};
CATDeclareHandler( CATIPLMStreamManagement, CATBaseUnknown );
#endif
