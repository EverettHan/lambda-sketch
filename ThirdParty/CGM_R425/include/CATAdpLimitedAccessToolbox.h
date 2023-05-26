/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpLimitedAccessToolbox_H
#define CATAdpLimitedAccessToolbox_H

#include "CATPLMIntegrationLimitedAccess.h"
#include "CATAdpAccessToolbox.h"
#include "IUnknown.h"

class CATIAdpType;
class CATIAdpExtType;
class CATPLMType;
class CATPLMID ;
class CATIAdpPLMIdentificator ;

/**
 * @deprecated V6R2009x
 */
class ExportedByCATPLMIntegrationLimitedAccess CATAdpLimitedAccessToolbox : public CATAdpAccessToolbox
{
public:

/**
 * @deprecated V6R2009x
 */
//#ifndef  REMOVE_USELESS_INCLUDE
  static HRESULT GetPLMTypeFromAdpType( CATIAdpType * iAdpType, CATPLMType *& oPLMType );
//#else
//#pragma  message  (" BADREM : JBB 081128 "  __FILE__  " CATAdpLimitedAccessToolbox::GetPLMTypeFromAdpType must be replaced by CATPLMType::GetPLMTypeFromAdpType.")
//#endif

/**
 * @deprecated V6R2009x
 */
//#ifndef  REMOVE_USELESS_INCLUDE
  static HRESULT GetPLMTypeFromAdpExtType( CATIAdpExtType * iAdpExtType, CATPLMType *& oPLMType );
//#else
//#pragma  message  (" BADREM : JBB 081128 "  __FILE__  " CATAdpLimitedAccessToolbox::GetPLMTypeFromAdpExtType must be replaced by CATPLMType::GetPLMTypeFromAdpExtType.")
//#endif

/**
 * @deprecated V6R2009x
 */
//#ifndef  REMOVE_USELESS_INCLUDE
  static HRESULT GetPLMIDFromAdpIdentificator( CATIAdpPLMIdentificator * iAdpId, CATPLMID & oPLMID );
//#else
//#pragma  message  (" BADREM : JBB 081128 "  __FILE__  " CATAdpLimitedAccessToolbox::GetPLMIDFromAdpIdentificator must be replaced by CATPLMID::GetPLMIDFromAdpIdentificator.")
//#endif
};
#endif
