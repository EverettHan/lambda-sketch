// COPYRIGHT Dassault Systemes 2005
//===================================================================
/**
 * @level Protected
 * @usage U1
 */

//===================================================================
#ifndef CATOmyCioUrlUsageSavingCtx_H
#define CATOmyCioUrlUsageSavingCtx_H

#include "CATOMYCuteIO.h"
#include "CATOmyCioUrlUsageCtx.h"
#include "CATVVSUrl.h"
#include "CATBoolean.h"

//-----------------------------------------------------------------------

/**
* This class implements a context for the saving transaction in CuteIO. This context
* contains information about the stream that will be registered in the transaction.
*/
class ExportedByCATOMYCuteIO CATOmyCioUrlUsageSavingCtx: public CATOmyCioUrlUsageCtx
{
  CATDeclareClass;  
  
public:

  // Standard constructors and destructors
  // -------------------------------------  
  CATOmyCioUrlUsageSavingCtx(const CATVVSUrl& iUrl, int iWaterMarkStamp, const CATUnicodeString& iSDtypeLate, CATOmyVVSURLConnectionHolder* iConnectionHolder); 
  CATOmyCioUrlUsageSavingCtx(const CATVVSUrl& iUrl, int iWaterMarkStamp, const CATUnicodeString& iSDtypeLate)
    : CATOmyCioUrlUsageSavingCtx(iUrl, iWaterMarkStamp, iSDtypeLate,NULL) 
    {CATOmxSR<CATOmyVVSURLConnectionHolder> spCurConnectionHolder(new CATOmyVVSURLConnectionHolder(), Steal);
     SetConnectionHolder(spCurConnectionHolder.Ref());}
    
  
  // @deprecated
  CATOmyCioUrlUsageSavingCtx(const CATVVSUrl& iUrl, int iWaterMarkStamp, const CATUnicodeString& iSDtypeLate, CATBoolean, CATOmyVVSURLConnectionHolder* iConnectionHolder)
    : CATOmyCioUrlUsageSavingCtx(iUrl, iWaterMarkStamp, iSDtypeLate,iConnectionHolder) {}
  
  // @deprecated
  CATOmyCioUrlUsageSavingCtx(const CATVVSUrl& iUrl, int iWaterMarkStamp, const CATUnicodeString& iSDtypeLate, CATBoolean, CATOmyVVSURLConnectionHolder* iConnectionHolder, 
                             const CATVVSUrl& iUrlKeyToUpdate, const int& iWS)
    : CATOmyCioUrlUsageSavingCtx(iUrl, iWaterMarkStamp, iSDtypeLate,iConnectionHolder) {SetUrlToUpdate(iUrlKeyToUpdate,iWS);}
                             
  virtual ~CATOmyCioUrlUsageSavingCtx();

  /**
    * Set the stream that will be associated with the cached file after the save transaction. 
    * Old comment : permet d'utiliser un stream deja en cache (XMM ou LV). Mettre l'url du stream a chercher dans iUrl et la nouvelle dans iUrlKeyToUpdate  
    */
  void SetUrlToUpdate(const CATVVSUrl& iUrlKeyToUpdate, const int& iWS);
  
  /** 
  * Get the prepared status of this context
  * <br><b>Role</b>: If this context is prepared, there is an Url connection corresponding with
  * this object in a local cache.
  * @retrun
  *   The status of this context;
  */
  CATBoolean IsPrepared() const ;

  /**
  * Indicates if this context must be updated.
  * @return 
  *   <UL>
  *     <LI><code>TRUE</code>: This context must be updated</LI>
  *     <LI><code>FALSE</code>: This context must be updated</LI>
  *   </UL>
  **/
  CATBoolean SupposedToBeUpdated();

  /** 
  * Get the new URL key to index the stream associated with this context
  * @return
  *   The new URL key. It could be not set.
  */
  const CATVVSUrl& GetUrlForUpdateCtx(int* oWs = NULL) const;

  
  virtual CATBoolean NeedToBeCached() {return TRUE;}

private:

  /** 
  * Sets the status of this context
  * @param iUrl [in]
  *   The URL in local cache if it is different from the one of this object.
  * @param iWaterMarkStamp
  *   The iteration of the stream associated to the URL.
  * @return
  *   S_OK if everything ran well, oterwise E_FAIL.
  */
  HRESULT SetPrepared(const CATVVSUrl* iUrl = NULL, const int* iWaterMarkStamp = NULL);

  void SetUpdatedStatus(CATBoolean Status = FALSE);

  // Replaces the old url/wms by the new (_UrlToUpdateIndex devient _Url)
  HRESULT UpdateUrl();

  virtual HRESULT GetUrlToSave(CATVVSUrl& oUrl);

  CATOmyCioUrlUsageSavingCtx (const CATOmyCioUrlUsageSavingCtx &); // NotImplemented
  CATOmyCioUrlUsageSavingCtx& operator=(const CATOmyCioUrlUsageSavingCtx&); // NotImplemented
  
  // Indicates that this context has been treated: An URL connection in the Upload cache is created.
  CATBoolean _IsPrepared;
  
  // Indicates that this context must be updated with a right distant Url.
  CATBoolean _SupposedToBeUpdated;
  CATBoolean _HasBeenUpdated;
  
  //Final URL and WaterMark to update key in transaction.
  CATVVSUrl _UrlToUpdateIndex;
  int       _WSToUpdateIndex;
  
  friend class CATOmyPowerIOSavingTransaction;
  friend class CATOmyPowerIOLocalSavingTransaction;
  friend class CATOmyPowerIOUnloadingTransaction;
  friend class CATOmyPowerIOSavingBaseTransaction;
};

//-----------------------------------------------------------------------

#endif
