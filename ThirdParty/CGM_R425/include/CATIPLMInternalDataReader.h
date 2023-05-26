/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2010
/**
 * @level Private
 * @usage U5
 */
#ifndef CATIPLMInternalDataReader_H
#define CATIPLMInternalDataReader_H

#include "CATPLMServicesRestrictedIntegrationUse.h"
#include "CATBaseUnknown.h"
class CATBinary;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMInternalDataReader;
#else
extern "C" const IID IID_CATIPLMInternalDataReader;
#endif

/**
 * This interface defines a protocol to read specific data from an internal provider.
 */
class ExportedByCATPLMServicesItf CATIPLMInternalDataReader: public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT ReadMemoryState( CATBinary & oMemoryState )=0;
  virtual HRESULT ReadDataSourceStatus( CATUnicodeString & oStatus )=0;
};
CATDeclareHandler(CATIPLMInternalDataReader, CATBaseUnknown);
#endif
