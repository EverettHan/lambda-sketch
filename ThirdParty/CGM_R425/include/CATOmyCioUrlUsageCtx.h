/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmyCioUrlUsageCtx_H
#define CATOmyCioUrlUsageCtx_H

#include "CATOMYCuteIO.h"
#include "CATUuid.h"
#include "CATVVSUrl.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATOmyVVSURLConnectionHolder.h"
#include "CATOmyResourceReference.h"
#include "CATMD5.h"

class CATOmyCioURLCachedConnection;
class CATOmyPowerIOURLCachedConnection;
class CATOmyVVSURLConnectionHolder;

/**
 * This Object is the context of the original stream to open.<br>
 * It contains all informations and needs about the future cached stream.
 */
class ExportedByCATOMYCuteIO CATOmyCioUrlUsageCtx : public CATBaseUnknown
{
public:

  /** 
   * Destructor
  */  
  virtual ~CATOmyCioUrlUsageCtx();   
  
  /** 
    * Methods to get the identifiers of the future cached stream.
    */
  CATOmyResourceReference GetSDRefToOpen() const   {return _SDToBeOpened;}
  CATVVSUrl               GetUrlOfSDToOpen() const {return _SDToBeOpened.GetVVSUrl();}
  int                     GetWSOfSDToOpen() const  {return _SDToBeOpened.GetWMStamp();}
  CATUnicodeString        GetLTOfSDToOpen() const  {return _SDToBeOpened.GetLateType();}
  
  // Deprecated. Use instead GetxxxToOpen
  void GetUrlToBeOpened(CATVVSUrl& oUrl, int& oWaterMarkStamp) const;
  void GetStreamDescriptorLateType(CATUnicodeString& oLateType) const;

  /** 
    * Get the URL Connection holder of this object.
    */
  void GetURLConnectionHolder(CATOmyVVSURLConnectionHolder*& oConnectionHolder) const;

  /** 
   * Returns an ILB to the stream within the cache
   * @param oStream
   * The Stream (this pointer is AddRef-ed)
   * @return
   * S_OK if the connection was succesfully initialised, or E_FAIL otherwise
   */
  HRESULT GetILockBytes2(CATILockBytes2*& oStream) const ;
  
  /** 
   * Returns the CATVVSURLConnection hold by this object
   */
  HRESULT GetConnection(CATVVSURLConnection*& oConnection) const ;
  
  /** 
   * Returns the CATVVSURLConnection hold by this object
   */
  CATVVSURLConnection* GetConnection() const ;

  /** 
    * Get the Uuid of the transaction that hold this context.
    */
  HRESULT GetUuid(CATUuid& oUuid) const;

  /** 
    * Set and Get the expected MD5 of the stream to load
    */
  void GetExpectedMD5(CATMD5& oExpectedMD5) const;
  void SetExpectedMD5(CATMD5& iExpectedMD5);    

  // Set & Get Size of stream in bytes. Value -1 should be used if size is unknown.
  void SetStreamSize(CATLONG64 iSize);
  CATLONG64 GetStreamSize() const;

  // if returns true, means this operation has been canceled within the whole transaction
  enum TransactionStatus { Unknown = 0, TransactionOK = 1, CanceledWithFallbackNeeded = 2, CompletelyCanceled = 3 };
  TransactionStatus GetTransactionStatus() const;
  
protected:
    
  CATOmyCioUrlUsageCtx();  

  /**
    * Set the connection holder.
    * This method is useless as a connection holder is internaly created in the recommended constructors
    */
  void SetConnectionHolder(CATOmyVVSURLConnectionHolder* iConnectionHolder);
    
  /** 
    * Sets the Uuid of this context
    */
  void SetSDToBeOpened(const CATOmyResourceReference& iSD) {_SDToBeOpened=iSD;};

  /** 
    * Sets the Uuid of this context
    */
  void SetUuid(const CATUuid& iUuid);

  /** 
    * Initializes the Connection Holder contained in this object by setting the given CATVVSURLConnection
    *
    * <br><b>Role</b>: This method initializes the CATVVSUrlConnection. It sets its CATVVVSURLConnection field to 
    * the given url connection. 
    * @param iConnection [in]
    *   The CATVVSURLCOnnection to set inside the connection holder. 
    */
  HRESULT InitializeConnectionHolder(CATOmyPowerIOURLCachedConnection* iConnection, CATBoolean iMustDelete=TRUE) const;
    
  // Data accessible to derived classes
  CATOmyResourceReference                _SDToBeOpened;
  CATOmxSR<CATOmyVVSURLConnectionHolder> _spConnectionHolder; // Holder that will keep the connection
  CATLONG64  _streamSize;         // size of stream in bytes, -1 if unknown
  
private:
  
  CATOmyCioUrlUsageCtx (const CATOmyCioUrlUsageCtx& iUsageCtx); // NotImplemented
  CATOmyCioUrlUsageCtx& operator=(const CATOmyCioUrlUsageCtx&); // NotImplemented
  
  CATMD5     _MD5Expected;
  CATUuid    _Uuid;         // Uuid of the transaction that holds this context
  CATBoolean _UuidIsSet;    // flag to indicate if a transaction has registered this context
  TransactionStatus _transactionStatus = Unknown;
  
  friend class CATOmyPowerIOLoadingTransaction;
  friend class CATOmyPowerIOAsyncLoadingTransaction;
  friend class CATOmyPowerIOCachingBusinessLogic;
  friend class CATOmyPowerIOLocalSavingTransaction;
  friend class CATOmyPowerIOSavingTransaction;
  friend class CATOmyPowerIOSavingBaseTransaction;
  friend class CATOmyPowerIOLoadingBaseTransaction;
  friend class CATAsyncMTVVSTasksFactory;
  friend class CATOmySharedFileDico;
};

#endif
