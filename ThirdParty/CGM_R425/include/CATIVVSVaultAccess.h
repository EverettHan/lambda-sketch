/**
 * @level Private
 * @usage U3
 */
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIVVSVaultAccess.h
// Define the CATIVVSVaultAccess interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Mar 2004  Creation: Code generated by the CAA wizard  fle
//===================================================================
#ifndef CATIVVSVaultAccess_H
#define CATIVVSVaultAccess_H

#include "CATIAV5Level.h"

#include "VVSVaultSiteProtocol.h"
#include "CATBaseUnknown.h"

#include "CATVVSUrl.h"
#include "CATVVSURLConnection.h"
#include "CATListOfCATVVSUrl.h"
#include "CATMD5.h"

class CATUuid;
class CATIVVSMassiveCopy;
class CATIVVSMassiveCopyAsync;
class CATVVSStreamSizes;
class CATVVSTransaction;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVVSVaultSiteProtocol IID IID_CATIVVSVaultAccess;
#else
extern "C" const IID IID_CATIVVSVaultAccess ;
#endif

//------------------------------------------------------------------

/**
 * This represents the interface the component 
 * declared in DeclareComponentImplementingVaultBehavior
 * has to implement to give access to streams
 * This interface is mandatory
 */
class ExportedByVVSVaultSiteProtocol CATIVVSVaultAccess: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** 
   * Returns an object that represents the connection to the stream identified by the url
   * @param iUrl 
   * The retrieved connection
   * @param oConnection 
   * The retrieved connection .
   * The responsible of the lifecycle of this connection is the caller of this method.
   * This object is not managed by AddRef/Release.
   * The lifecycle of the connection is done by the caller of this method.
   * @return
   * S_OK if the connection was succesfully created, or E_FAIL otherwise
  */  
   virtual HRESULT OpenConnection(const CATVVSUrl& iUrl,CATVVSURLConnection& oConnection,CATVVSTransaction* iTransaction=NULL) = 0;
  
   /** 
   * Create a massive copy
   * @param opMassiveCopy [out, IUnknown#Release] 
   * The massive copy.
   * @param iTransaction [in]
   * The transaction.
   * @return
   * S_OK if the copy was succesfully created, or E_FAIL otherwise
  */  
   virtual HRESULT CreateCopy(CATIVVSMassiveCopy *&opMassiveCopy,CATVVSTransaction* iTransaction=NULL) const = 0;

   /** 
   * Create a massive copy async
   * @param opMassiveCopy [out, IUnknown#Release] 
   * The massive copy.
   * @param iTransaction [in]
   * The transaction.
   * @return
   * S_OK if the copy was succesfully created, or E_FAIL otherwise
  */  
   virtual HRESULT CreateCopyAsync(CATIVVSMassiveCopyAsync *&opMassiveCopy, CATUuid& iTransactionId) const = 0;  

   /** 
   * Get sizes of streams identified by their URL.
   * @param iUrls [in]
   *   The Urls of streams .
   * @param oStreamSizes [out]
   *   The hash table that contains the couple (Url, size).
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
   virtual HRESULT GetSizeOfStreams(CATListOfCATVVSUrl& iUrls, CATVVSStreamSizes& oStreamSizes) const = 0;
   
   /** 
   * Get the stream MD5. MD5 has been computed at insertion in the vault site
   * @param iUrl [in]
   *   The Url of stream
   * @param oMD5 [out]
   *   The MD5 Value
   * @return
   *   <code>S_OK</code> if everything ran ok, 
   *   <code>E_NOTIMPL</code> Vault site does not support MD5 Computation
   *   <code>E_INVALIDARG</code> MD5 is not activated for the vaultsite
   *   <code>E*> unexepcted error
   */
   virtual HRESULT GetStreamMD5(const CATVVSUrl& iUrl,CATMD5& oMD5) const = 0;

     /** 
   * Compute the MD5 of a file and check its value matches the one it had when createds
   * @param iUrl [in]
   *   The Url of stream
   * @return
   *   <code>S_OK</code> if everything ran ok, 
   *   <code>E_NOTIMPL</code> Vault site does not support MD5 Computation
   *   <code>E_INVALIDARG</code> MD5 is not activated for the vaultsite
   *   <code>E*</code> Stream is corrupted
   */
  virtual HRESULT CheckStreamIntegrity(const CATVVSUrl& iUrl) const = 0;
};

//------------------------------------------------------------------

#endif
