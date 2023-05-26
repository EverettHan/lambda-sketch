/**
 * @level Private
 * @usage U3
 */
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIVVSVaultQuery.h
// Define the CATIVVSVaultQuery interface
//
//===================================================================
//
// Usage notes:
//   Interface to search streams identified (by URL), in a vault site.
#ifndef CATIVVSVaultQuery_H
#define CATIVVSVaultQuery_H

#include "VVSVaultSiteProtocol.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVVSVaultSiteProtocol IID IID_CATIVVSVaultQuery;
#else
extern "C" const IID IID_CATIVVSVaultQuery;
#endif

//------------------------------------------------------------------

class CATVVSTransaction;
class CATVVSUrl;

/**
 *  This interface could be implementing by a VVS Vault site component. It is designed
 *  to research an URL managed by the component. It is optional.
 */
class ExportedByVVSVaultSiteProtocol CATIVVSVaultQuery: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /** 
     * Finds an url in Vault site
     * @param iUrl
     *  The url to find
     * @param iTransaction   
     *  Will be used in a later release
     * @return
     *  <UL>
     *    <LI><code>S_OK</code>:if the url has been found.</LI>
     *    <LI><code>S_FALSE</code>:if the url has not been found.</LI>
     *    <LI><code>S_OK</code>:if an error occurs.</LI>
     *  </UL>
    */
	 virtual HRESULT QueryUrl(const CATVVSUrl& iUrl, CATVVSTransaction* iTransaction = NULL) = 0;
};
//------------------------------------------------------------------

#endif
