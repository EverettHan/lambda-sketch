/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2010
/**
 * @level Private
 * @usage U5
 */
#ifndef CATIPLMInternalDataWriter_H
#define CATIPLMInternalDataWriter_H

#include "CATPLMServicesRestrictedIntegrationUse.h"
#include "CATBaseUnknown.h"
class CATBinary;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMInternalDataWriter;
#else
extern "C" const IID IID_CATIPLMInternalDataWriter;
#endif

/**
 * This interface defines a protocol to write specific data into an internal provider.
 */
class ExportedByCATPLMServicesItf CATIPLMInternalDataWriter: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT WriteMemoryState( const CATBinary & iMemoryState )=0;
  virtual HRESULT WriteDataSourceStatus( const CATUnicodeString & iStatus )=0;
};
CATDeclareHandler(CATIPLMInternalDataWriter, CATBaseUnknown);
#endif
