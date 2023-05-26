/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
#ifndef AdpDWSHelper_H
#define AdpDWSHelper_H

#include "CATPLMIntegrationBase.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"
#include "CATPLMItgQueryHelper.h"
class CATIAdpPLMIdentificator;
class CATBinary;
class CATUuid;
class CATPLMItgQueryFilterCondition;
class CATPLMID_Any;
class CATString;
class CATIPLMAttributeSet;

class ExportedByCATPLMIntegrationBase AdpDWSHelper : public CATPLMItgQueryHelper
{
public:
  AdpDWSHelper( const CATPLMID & iWorkspace );
  AdpDWSHelper( CATIAdpPLMIdentificator * iWorkspaceIdentificator );
  virtual ~AdpDWSHelper();

  HRESULT CheckWorkspaceValidity();
  HRESULT GetWorkspaceIdAsBinary( CATBinary & oWorkspaceIdBinary );
  HRESULT GetWorkspaceIdAsUuid( CATUuid & oWorkspaceIdUuid );

  HRESULT AddFilterOnWSID( CATPLMItgQueryFilterCondition & iCondition);
  HRESULT AddFilterOnObjectId( CATPLMItgQueryFilterCondition & iCondition,
                               CATIAdpPLMIdentificator * iObjectId);
  HRESULT AddFilterOnObjectId( CATPLMItgQueryFilterCondition & iCondition,
                               CATPLMID & iObjectId);
  HRESULT AddFilterOnParentObjectId( CATPLMItgQueryFilterCondition & iCondition,
                                     CATIAdpPLMIdentificator * iParentObjectId);
  HRESULT AddFilterOnParentObjectId( CATPLMItgQueryFilterCondition & iCondition,
                                     CATPLMID & iParentObjectId);
  HRESULT EnrichAttributeSetWithWorkspaceId( CATIPLMAttributeSet & iAttributeSet );

private:

  HRESULT AddFilterOnPLMID( CATPLMItgQueryFilterCondition & iCondition,
                            CATPLMID & iPLMID,
                            CATString & iAttrPhy );

  AdpDWSHelper( const AdpDWSHelper & );
  AdpDWSHelper & operator =( const AdpDWSHelper & );
  
private:
  CATPLMID _Workspace;
};
#endif
