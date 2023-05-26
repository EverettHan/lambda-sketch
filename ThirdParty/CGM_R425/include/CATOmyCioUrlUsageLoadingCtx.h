// COPYRIGHT Dassault Systemes 2005
//===================================================================
/**
 * @level Protected
 * @usage U1
 */

//===================================================================
#ifndef CATOmyCioUrlUsageLoadingCtx_H_V2
#define CATOmyCioUrlUsageLoadingCtx_H_V2			// for IsLocalVaultCaching
#define CATOmyCioUrlUsageLoadingCtx_H_V3			// for EnableCommittingEachUrlInPC

#include "CATOMYCuteIO.h"
#include "CATOmyCioUrlUsageCtx.h"

//-----------------------------------------------------------------------
class CATVVSUrl;
class CATUnicodeString;
class CATOmyCioSessionManager;
class CATOmyVVSURLConnectionHolder;
class CATILockBytes2;

/**
* This class implements a context for the saving transaction in CuteIO. This context
* contains information about the stream that will be registered in the transaction.
*/
 		
class ExportedByCATOMYCuteIO CATOmyCioUrlUsageLoadingCtx: public CATOmyCioUrlUsageCtx
{
  CATDeclareClass;  

  public:
  
  /** 
    * Easy to use constructor of a context to load a stream.
    * Try to use it as often as possible
    * @param iUrl [IN]
    *    Url of the stream to load
    * @param iWaterMarkStamp [IN]
    *    The iteration of the stream.
    * @param iSDLateType [IN]
    *    The type of the stream (i.e. its extension)
    * http://osmwebdsy/wiki/index.php/Downloader_des_streams_depuis_le_server_avec_PowerIO for examples
    */
  CATOmyCioUrlUsageLoadingCtx(const CATOmyResourceReference& iStreamRef);
  CATOmyCioUrlUsageLoadingCtx(const CATVVSUrl& iUrl, int iWaterMarkStamp, const CATUnicodeString& iSDLateType):
                        CATOmyCioUrlUsageLoadingCtx(CATOmyResourceReference(iUrl, iWaterMarkStamp, iSDLateType))
                        {}
  
  // @deprecated
  CATOmyCioUrlUsageLoadingCtx(const CATVVSUrl& iUrl, int iWaterMarkStamp, const CATUnicodeString& iSDLateType, CATOmyVVSURLConnectionHolder* iConnectionHolder);

  // @deprecated
  CATOmyCioUrlUsageLoadingCtx(const CATVVSUrl& iUrl, const CATUnicodeString& iSDLateType, CATBoolean iNeedToAccessedLaterInSession,CATBoolean b,
                       CATOmyVVSURLConnectionHolder* iConnectionHolder, const int* ipWaterMarkStamp = NULL) : 
                       CATOmyCioUrlUsageLoadingCtx(iUrl,((ipWaterMarkStamp)?(*ipWaterMarkStamp):(0)),iSDLateType,iConnectionHolder)
                       {}
  // @deprecated
  CATOmyCioUrlUsageLoadingCtx(const CATVVSUrl& iUrl, int iWaterMarkStamp, const CATUnicodeString& iSDLateType, CATBoolean iNeedToAccessedLaterInSession,
                              CATBoolean b, CATOmyVVSURLConnectionHolder* iConnectionHolder) :
                       CATOmyCioUrlUsageLoadingCtx(iUrl,iWaterMarkStamp,iSDLateType,iConnectionHolder)
                       {}

  /**
    * Destructs this object.
    */
  virtual ~CATOmyCioUrlUsageLoadingCtx();

  /** 
  * Stream pointed by this context must be accessed directly on distant PDM vault.
  * <br><b>Role</b>: This call allow the caller to access stream directly on distant
  * vault, without using CuteIO cache. To succeed, this context must not need to be accessed letter in session
  * and must not need a file access. 
  * @param iDisableCaching [in]
  *   Indicates if the pointed stream must be cached or not.
  * @return
  *   <code>S_OK</code> if disable caching is allowed for this context
  *   <code>E_FAIL</code> if disable caching is not allowed for this context
  */
  HRESULT DisableCaching(CATBoolean iDisableCaching = TRUE);
  HRESULT EnableLocalVaultCaching(CATBoolean iEnableLocalVaultCaching = TRUE);
  /** 
  * Gets the status about the caching needs.
  * @return
  *   caching status.
  */
  CATBoolean IsCachingDisable();
  CATBoolean IsLocalVaultCaching();
        
private:
  
   CATOmyCioUrlUsageLoadingCtx (const CATOmyCioUrlUsageLoadingCtx &);          // NotImplemented
   CATOmyCioUrlUsageLoadingCtx& operator=(const CATOmyCioUrlUsageLoadingCtx&); // NotImplemented

  // Boolean about the needs of the cached stream.
  CATBoolean _DisableCaching;
  CATBoolean _LocalVaultCaching;
};
#endif
