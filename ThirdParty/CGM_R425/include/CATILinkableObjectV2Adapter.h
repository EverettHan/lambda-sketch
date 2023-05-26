// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATILinkableObjectV2Adapter_H
#define CATILinkableObjectV2Adapter_H

/**
* @level Protected
* @usage U2 
*/

#include "CATObjectModelerBase.h"
#include "CATILinkableObjectV2.h"

/** 
* Adapter for CATILinkableObjectV2.
*/
class ExportedByCATObjectModelerBase CATILinkableObjectV2Adapter : public CATILinkableObjectV2
{
private :

  /**
   * @see CATILinkableObjectV2
   */
  HRESULT GetIdentifier (const CATOmxKeyValueBlock & iVersion, GetIdentifier_Result & oResult) ;

} ;

#endif

