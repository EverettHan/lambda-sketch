/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpAccessToolbox_H
#define CATAdpAccessToolbox_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"

class CATIAdpType;
class CATPLMType;
class CATPLMID ;
class CATIAdpPLMIdentificator ;
 
/**
 * @deprecated V6R2009x.
 */
class ExportedByCATPLMIntegrationAccess CATAdpAccessToolbox
{
public:

/**
 * @deprecated V6R2009x.
 */
//#ifndef  REMOVE_USELESS_INCLUDE
  static HRESULT GetAdpTypeFromPLMType( const CATPLMType * iPLMType, CATIAdpType *& oAdpType) ;
//#else
//#pragma  message  (" BADREM : JBB 081128 "  __FILE__  " CATAdpAccessToolbox::GetAdpTypeFromPLMType must be replaced by CATPLMType::GetAdpTypeFromPLMType.")
//#endif

/**
 * @deprecated V6R2009x.
 */
//#ifndef  REMOVE_USELESS_INCLUDE
  static HRESULT GetAdpIdentificatorFromLoaded( const CATBaseUnknown *iLoaded, CATIAdpPLMIdentificator *& iAdpId );
//#else
//#pragma  message  (" BADREM : JBB 081128 "  __FILE__  " CATAdpAccessToolbox::GetAdpIdentificatorFromLoaded must be replaced by CATIPLMComponent::GetAdpID.")
//#endif

/**
 * @deprecated V6R2009x.
 */
//#ifndef  REMOVE_USELESS_INCLUDE
  static HRESULT GetAdpIdentificatorFromPLMID( const CATPLMID & iPLMID, CATIAdpPLMIdentificator *& oPLMIdentificator );
//#else
//#pragma  message  (" BADREM : JBB 081128 "  __FILE__  " CATAdpAccessToolbox::GetAdpIdentificatorFromPLMID must be replaced by CATPLMID::GetAdpIdentificatorFromPLMID.")
//#endif

/**
 * @deprecated V6R2009x.
 */
//#ifndef  REMOVE_USELESS_INCLUDE
  static HRESULT GetAdpTypeFromAdpIdentificator( const CATIAdpPLMIdentificator * iPLMIdentificator, CATIAdpType *& oAdpType );
//#else
//#pragma  message  (" BADREM : JBB 081128 "  __FILE__  " CATAdpAccessToolbox::GetAdpTypeFromAdpIdentificator must be replaced by CATIAdpPLMIdentificator::GetAdpType.")
//#endif




};
#endif
