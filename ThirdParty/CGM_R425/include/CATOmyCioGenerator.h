// COPYRIGHT Dassault Systemes 2012
//===================================================================
/**
* @level Protected
* @usage U1
*/

#ifndef CATOmyCioGenerator_H
#define CATOmyCioGenerator_H


#include "CATOMYCuteIOAccess.h"
#include "CATOmxSharable.h"
#include "CATUnicodeString.h"
#include "CATOmyResourceReference.h"

class CATILockBytes2;
class CATVVSURLConnectionSharable;
class CATVVSURLConnection;
class CATVVSUrl;
class CATOmyCioUrlUsageCtx;

/**
* Implement this class to stream a file in the PLM_Cache
*/
class ExportedByCATOMYCuteIOAccess CATOmyFileStreamer : public CATOmxSharable
{
public:
  CATOmyFileStreamer(){};
  ~CATOmyFileStreamer(){};
  /**
  *  This method fills the provided ILB with applicative content. 
  *  To copy a file, one can use copyILB2toILB. To create a cgr file, one can call the CATWriteCgr method.   @see TSTFileStreamer::GenerateFile for a basic implementation of your own streamer
  */
  virtual HRESULT GenerateFile(CATILockBytes2& iWhereToStream){return E_NOTIMPL;};
  /**
  * @return the type of file to be generated in the cache
  */
  virtual CATUnicodeString ExtensionGenerated() {return "undefined";};
};

#include "CATOmxKernel.h"
typedef CATOmxIter< CATOmyFileStreamer > CATOmyFileStreamer_iter;

#include "CATOmxVector.h"
#include "CATUuid.h"

typedef CATOmxIter< CATVVSURLConnectionSharable > CATVVSURLConnectionSharable_iter;
typedef CATOmxIter< CATOmyCioUrlUsageCtx > CATOmyCioUrlUsageCtx_iter;

/**
* Generates files inside the cache
* @role
* This class enables applicative code to generate files directly in the cache. Those files can later be uploaded to the server. 
* For example, let's start with this scenario:
*    from an xml file, create a cgr file in a temp directory. Then import this cgr file in CATIA. Propagate in CATIA : a new cgr file is generated from memory in the cache, then this file is uploaded
*    using this service, one can have the following improvement : 
*        create entry in cache, CATOmyFileStreamer generated a file at the provided ilb from the input xml file. Import the cgr file in CATIA. Propagate ine CATIA, Save mechanism detects file is already up-to-date in cache, avoids memory stream, and directly upload
*        Technically, one file is on disk instead of two. A memory stream operation has been avoided. 
*
*/
class ExportedByCATOMYCuteIOAccess CATOmyCioGenerator
{
public:   
  /**
  *
  *
  * XXXXXX    XXXXX      XX   XX   XXXXX    XXXXXX     XX  XX   XXXXXX  XXXXXXX
  * XX  XX  XX   XX      XXX  XX  XX   XX   X XX X     XX  XX  XX    X   XX   X
  * XX  XX  XX   XX      XXXX XX  XX   XX     XX       XX  XX  XX        XX X
  * XX  XX  XX   XX      XX XXXX  XX   XX     XX       XX  XX   XXXXX    XXXX
  * XX  XX  XX   XX      XX  XXX  XX   XX     XX       XX  XX       XX   XX X
  * XX  XX  XX   XX      XX   XX  XX   XX     XX       XX  XX  X    XX   XX   X
  * XXXXXX    XXXXX       XX   XX   XXXXX     XXXX      XXXX   XXXXXX   XXXXXXX
  */
  HRESULT StreamsFilesInCache(CATOmyFileStreamer_iter& iFileStreamer, CATBoolean iCacheTransactionAlreadyExist,CATVVSURLConnectionSharable_iter& oVVSUrlConnection_iter );
  
  /**
  * Creates files inside the cache. THIS SERVICE MUST BE CALLED IN BATCH if iCacheTransactionAlreadyExist is set to FALSE
  * @role : this service performs all the cache operations to create entries and files in the cache. 
  * @param
  * [in]  iFileStreamer : iterator on files streamers. iterator can be retrieved from @see CATOmxVector
  * [in]  iCacheTransactionAlreadyExist : to be set to FALSE in most cases. Only set to TRUE, if you are working within a save/localsave/unload transaction. 
  * [out] oUrlCtx_iter : iterator of entries in cache.. CATOmyCioUrlUsageCtx is the object to be provided to OMB when calling the RepRef creation. @see CATIPLMClientCoreTransaction::CreateRepReferenceWithNonV5ContentFromFile
  *                                Beware : cache can be flushed at anytime. To avoid your file to be deleted before the propagate has been called, you must keep a copy of each CATOmyCioUrlUsageCtx (or keep the iterator)
  * @return : S_OK : all files have been treated with success and are available in cache
  *         : E_*  : treatements have failed for at least one FileStreamer. CATOmyCioUrlUsageCtx_iter will be empty. Files in cache will be removed at some points. 
  * 
  */
  HRESULT StreamsFilesInCache(CATOmyFileStreamer_iter& iFileStreamer, CATBoolean iCacheTransactionAlreadyExist,CATOmyCioUrlUsageCtx_iter& oUrlCtx_iter );

  /**
  * Start a transaction. Tells the platform to inizialized itself.
  * @return : S_OK : Inizialisation succeded.
  *         : E_*  : Inizialisation failed.
  * 
  */
  HRESULT StartTransaction();

  /**
  * Stop a transaction. Stop the transaction by uploading and flushing the cache.
  * [in]  iCancelTransaction : tell the platforn not to upload and flush the cache.
  * @return : S_OK : Transaction stopped successfully.
  *         : E_*  : Transaction stopped with error.
  * 
  */
  HRESULT StopTransaction(CATBoolean iCancelTransaction);

  /**
  * Check if the provided Url/UrlConnection exists in cache and has been generated thanks to StreamsFilesInCache
  * @param :
  * [in] iConnection/iURL : acccess to the file to check
  * @return : S_OK : stream exists in cache (in known by PowerIO index)
  *         : E_INVALIDARG : url not generated by StreamsFilesInCache
  *         : E* : unexpected error or stream unavailable in cache
  *
  */
  HRESULT CheckUrlHasBeenCorrectlyStreamedInCache(CATOmyCioUrlUsageCtx& iCacheEntry);
  HRESULT CheckUrlHasBeenCorrectlyStreamedInCache(CATVVSURLConnection& iConnection);
  HRESULT CheckUrlHasBeenCorrectlyStreamedInCache(CATVVSURLConnectionSharable& iConnection);
  
  CATOmyCioGenerator();
  ~CATOmyCioGenerator();

  static CATUuid TransactionUuid;

private :	
  
  HRESULT _CheckUrlHasBeenCorrectlyStreamedInCache(const CATOmyResourceReference & iSrcRef);
  
  static CATBoolean _internalError;
};

#endif


