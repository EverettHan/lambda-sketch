/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
 * @level Private
 * @usage U1
 */
#ifndef CATPLMItgLimitedToolbox_H
#define CATPLMItgLimitedToolbox_H

#include "CATPLMIntegrationRestrictedUse.h"
#include "CATErrorDef.h"
class CATUnicodeString;
class CATIPLMRecordRead;
class CATIPLMIntegRecordRead;
class CATProxySpace;

/**
 * Helpers for integration processes.
 */
class ExportedByCATPLMIntegration CATPLMItgLimitedToolbox
{
public:

/**
 * @nodoc
 */
  static HRESULT GetIntegrationRecordRead( const CATUnicodeString & iWorkspaceId, CATIPLMRecordRead * iRecord, 
                                           CATIPLMIntegRecordRead *& oRecord );

/**
 * @nodoc
 */
static HRESULT GetIntegrationRecordRead( const CATProxySpace & iWorkspace, CATIPLMRecordRead * iRecord, 
                                           CATIPLMIntegRecordRead *& oRecord );
};
#endif
